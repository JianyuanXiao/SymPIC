#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <unistd.h>
#include <setjmp.h>
#include "uthash.h"
#include "types.h"
#ifdef USE_WINDOWS
#include <windows.h>
#endif

jmp_buf global_jump_env;
#if SCHEME_DEBUG
#define ERR_REPORT(errornum) {long i=0; while(global_caller!=empty_list_process && i<100){fprintf(stderr,"\n#%ld ",i);write_element(car(global_caller)->data.gc_stack.tmpele[0],stderr);global_caller=cdr(global_caller);i++;} fprintf(stderr,"\n");longjmp(global_jump_env,errornum);}
#else
#define ERR_REPORT(errornum) {longjmp(global_jump_env,errornum);}
#endif//SCHEME_DEBUG

element * empty_list_process;
element * quote_symbol;
element * quasiquote_symbol;
element * unquote_symbol;
element * define_symbol;
element * lambda_symbol;
element * macro_symbol;
element * quote_vector_symbol;
element * done_symbol;
element * if_symbol;
element * set_symbol;
element * and_symbol;
element * or_symbol;
element * begin_symbol;
element * cond_symbol;
element * else_symbol;
element * let_symbol;
element * eof_object_symbol;

element * global_environment;
element * empty_environment;
element * global_false;
element * global_true;
element * global_eof;
element * global_gc;
element * global_caller;

allocated_list * root_dependency=NULL;
//long root_dependency_num=0;


element * symbol_table;
int symbol_table_len;
int inner_loop=0;

element * alloc_element(){
	element * ele=malloc(sizeof(element));
	/*if(0 && ele==0x54461b0){
		fprintf(stderr,"malloc called here\n");
		//memset(root_dependency-1,0,1);
		//alloc_element[0]=1;
	}*/
	ele->type=INTNUM;
	ele->data.intnum=0;

	allocated_list * tmp=root_dependency;
	root_dependency=malloc(sizeof(root_dependency[0]));
	root_dependency[0].next=tmp;
	root_dependency[0].prev=NULL;
	root_dependency[0].curr=ele;
	root_dependency[0].using=0;
	if(tmp){
		tmp[0].prev=root_dependency;
	}
	ele->p_al=root_dependency;

	return ele;
}

#define car(ele) ((ele)->data.pair.car)
#define cdr(ele) ((ele)->data.pair.cdr)
element * cons(element * a,element * b){
	element * ans=alloc_element();
	ans->type=PAIR;
	car(ans)=a;
	cdr(ans)=b;
	ans->data.pair.istail=0;
	return ans;
}

void free_hashtable(symbol_var_pair * hashtable){
	symbol_var_pair * svp;
	symbol_var_pair * tmp;
	HASH_ITER(hh,hashtable,svp,tmp){
		HASH_DEL(hashtable,svp);
		free(svp);
	}
}

/*
void remove_hashtable(symbol_var_pair * hashtable){
	symbol_var_pair * svp;
	symbol_var_pair * tmp;
	HASH_ITER(hh,hashtable,svp,tmp){
		HASH_DEL(hashtable,svp);
		del_element(svp->value);
		free(svp);
	}
}
*/
element * internal_close_output_port(element * ele);
element * internal_close_input_port(element * ele);
void write_element(element * ele,FILE *out);


void del_element(element * ele){
	if(ele){
		switch (ele->type){
			case STRING:
				free(ele->data.string_var);
				break;
			case SYMBOL:
				free(ele->data.symbol.symbolname);
				break;
			case ELSE:
				free_hashtable(ele->data.else_var);
				break;
			case INPUT_PORT:
				//write_element(ele,stderr);
				//fprintf(stderr,"\n");
				internal_close_input_port(cons(ele,empty_list_process));
				//fprintf(stderr,"done\n");
				break;
			case OUTPUT_PORT:
				internal_close_output_port(cons(ele,empty_list_process));
				break;
			case VECTOR:
				switch(ele->data.vector.type){
					case INTVEC:
					      free(ele->data.vector.vector_data.p_int);
					      break;
					case MFLOATVEC:
					      free(ele->data.vector.vector_data.p_float);
					      break;
					default:
					      free(ele->data.vector.vector_data.p_general);
					      break;
				}
				break;
			default:
				break;
		}
		/*if(0 && ele==0x54461b0){
			write_element(ele,stderr);
			//fprintf(stderr,":delete called here\n");
		}*/
		free(ele);
	}
}

void cal_dependency(element * ele);
void cal_dependency_hashtable(symbol_var_pair * hashtable){
	//int num=0;
	while(hashtable){
		//fprintf(stdout,"CALING_HASHTABLE %d\n",num);
		//num++;
		cal_dependency(hashtable->value);
		hashtable=hashtable->hh.next;
	}
}

void cal_dependency(element * ele){
	if(ele==NULL)return;
	if(((allocated_list*)(ele->p_al))->using)return;
	((allocated_list*)(ele->p_al))->using=1;
	//fprintf(stdout,"CALING:");
	//write_element(ele,stdout);
	//fprintf(stdout,"\n");
	switch (ele->type){
		case PAIR:
			cal_dependency(car(ele));
			cal_dependency(cdr(ele));
			break;
		case MACRO:
			cal_dependency(ele->data.macro.paras);
			cal_dependency(ele->data.macro.body);
			cal_dependency(ele->data.macro.env);
			break;
		case LAMBDA_PROC:
			cal_dependency(ele->data.lambda_proc.paras);
			cal_dependency(ele->data.lambda_proc.body);
			cal_dependency(ele->data.lambda_proc.env);
			break;
		case VECTOR:
			switch (ele->data.vector.type){
				case INTVEC:
					break;
				case MFLOATVEC:
					break;
				case GENERALVEC:
					{long i;
					for(i=0;i<ele->data.vector.vec_len;i++){
						cal_dependency(ele->data.vector.vector_data.p_general[i]);
					}}
					break;
				default:
					break;
			}
			break;

		case ELSE:
			cal_dependency_hashtable(ele->data.else_var);
			break;
		case GC_STACK:
			//fprintf(stderr,"ok here\n");
			//write_element(ele->data.gc_stack.tmpele[0],stderr);
			//fprintf(stderr,"\n");
			cal_dependency(*(ele->data.gc_stack.tmpele));
			break;	
		default:
			break;
	}
}

void remove_element(element * ele){
	allocated_list * al=ele->p_al;
	del_element(al->curr);
	if(al->prev){
		al->prev->next=al->next;
	}
	if(al->next){
		al->next->prev=al->prev;
	}
	if(al==root_dependency){
		root_dependency=al->next;
	}
	free(al);
}

void clean_gc(){
	allocated_list * al=root_dependency;
	//fprintf(stderr,":");
	while(al){
		allocated_list *tmp=al->next;
		if(al->using){
			al->using=0;
		}else{
			//assert(al->curr->p_al == al);
			/*
			del_element(al->curr);
			if(al->prev){
				al->prev->next=al->next;
			}
			if(al->next){
				al->next->prev=al->prev;
			}
			if(al==root_dependency){
				root_dependency=al->next;
			}
			free(al);
			if(al->curr->type!=GC_STACK){
				if(al->curr->type==PAIR && car(al->curr)->type!=GC_STACK){
					//write_element(al->curr,stderr);
				}
			}
			*/
			remove_element(al->curr);
		}
		al=tmp;
	}
	//fprintf(stderr,"cleaned\n");
}

element * make_o_port(FILE * fp){
	element * ans=alloc_element();
	ans->type=OUTPUT_PORT;
	ans->data.out_port.out_port=fp;
	ans->data.out_port.isclose=0;
	return ans;
}
element * make_i_port(FILE * fp){
	element * ans=alloc_element();
	ans->type=INPUT_PORT;
	ans->data.in_port.in_port=fp;
	ans->data.in_port.isclose=0;
	return ans;
}

void dump_debug(allocated_list * p_al){
	while(p_al){
		//fprintf(stderr,"al:\n");
		element * ele=p_al->curr;
		/*
		write_element(ele,stdout);
		fprintf(stdout,"\n");
		*/
		fprintf(stderr,"0x%lx ",ele);
		switch(ele->type){
			case INTNUM:
				fprintf(stderr,"int: %ld\n",ele->data.intnum);
				break;
			case MFLOATNUM:
				fprintf(stderr,"float: %e\n",ele->data.floatnum);
				break;
			case MCHAR:
				fprintf(stderr,"char: %c\n",ele->data.char_var);
				break;
			case STRING:
				fprintf(stderr,"string: %s\n",ele->data.string_var);
				break;
			case SYMBOL:
				fprintf(stderr,"symbol: %s\n",ele->data.symbol.symbolname);
				break;
			case EMPTYLIST:
				fprintf(stderr,"()\n");
				break;
			case PAIR:
				fprintf(stderr,"pair: car=%lx cdr=%lx\n",car(ele),cdr(ele));
				break;
			case ELSE:
				fprintf(stderr,"else: %lx\n",ele->data.else_var);
				break;
			case MBOOLEAN:
				fprintf(stderr,"bool: %d\n",ele->data.boolean);
				break;
			case MPROC:
				fprintf(stderr,"proc\n");
				break;
			case LAMBDA_PROC:
				fprintf(stderr,"lambda_proc\n");
				break;
			default:
				fprintf(stderr,"other:\n");
				break;
		}
		p_al=p_al->next;
	}
}

void gc_env(element * env){
	//fprintf(stderr,"gc_begin\n");
	cal_dependency(global_gc);
	cal_dependency(global_caller);
	cal_dependency(env);
	cal_dependency(global_false);
	cal_dependency(global_true);
	cal_dependency(symbol_table);
	cal_dependency(global_eof);
	clean_gc();
	//fprintf(stderr,"gc_end\n");
}

void gc(){
	global_gc=empty_list_process;
	global_caller=empty_list_process;
	gc_env(global_environment);
}

element * makesymbol(char * name){
	element * tmp=symbol_table;
	while(tmp->type!=EMPTYLIST){
		if(strcmp(car(tmp)->data.symbol.symbolname,name)==0){
			return car(tmp);
		}
		tmp=cdr(tmp);
	}
	tmp=alloc_element();
	tmp->type=SYMBOL;
	tmp->data.symbol.symbolname=malloc(strlen(name)+1);
	if(!tmp->data.symbol.symbolname){
		fprintf(stderr,"internal error: string pointer in makesymbol is null\n");
		ERR_REPORT(1);
	}
	strcpy(tmp->data.symbol.symbolname,name);
	tmp->data.symbol.symbol_id=symbol_table_len;
	symbol_table=cons(tmp,symbol_table);
	symbol_table_len++;
	return tmp;
}


int isdelimiter(int c){
	//fprintf(stderr,"%c\n",c);
	return isspace(c)||c=='('||c==')'||c==EOF||c=='"'||c==';'||c=='['||c==']';
}

int delete_void_char(FILE * in){
	int c;
beg:
	c=getc(in);
	if(c==EOF){
		return EOF;
	}
	if(isspace(c))goto beg;
	if(c==';'){
		while(((c=getc(in))!=EOF) && (c != '\n'));
		goto beg;
	}
	ungetc(c,in);
	return c;
}

int first_char(FILE * in){
	int c;
	c=getc(in);
	ungetc(c,in);
	return c;
}
#define BUFMAX 4096
char buffer[BUFMAX];

void read_buf(FILE * in){
	int i=0;
	while(i<BUFMAX){
		char c=getc(in);
		if(isdelimiter(c)){
			if(!(i>1&&buffer[i-2]=='#' && buffer[i-1]=='\\')){
				ungetc(c,in);
				break;
			}
		}
		buffer[i]=c;
		i++;
	}
	if(i>=BUFMAX){
		fprintf(stderr,"Error: read buffer over flow\n");
		ERR_REPORT(1);
	}
	buffer[i]=0;
}

int isint_or_float(const char * buf){ //int=1, float=2, other=0
	int fstc=buf[0];
	if('0' == buf[0]  &&  'x'==buf[1])return 1;
	if(isdigit(fstc)||fstc=='.'||fstc=='-'){
		if(fstc=='-'&& buf[1]!='.' && !isdigit(buf[1]))return 0;
		if(strstr(buf,"e")||strstr(buf,"E") || strstr(buf,"."))return 2;
		else return 1;
	}else{
		return 0;
	}
}

int isempty(element * ele){
	return (ele->type==EMPTYLIST);
}

int islist(element * ele){
	return (ele->type==EMPTYLIST)||(ele->type==PAIR) ;
}

int isfalse(element * ele){
	return (ele->type==MBOOLEAN && ele->data.boolean==0);
}

element * read_element(FILE * in);

element * read_pair(FILE * in){
	element * ans=alloc_element();	
	int jdg=delete_void_char(in);
	if(jdg==EOF)return global_eof;
	char c=getc(in);
	if(c==')'||c==']'){
		//ans->type=EMPTYLIST;
		return empty_list_process;
	}
	ungetc(c,in);
	ans->type=PAIR;
	ans->data.pair.istail=0;
	car(ans)=read_element(in);
	//fprintf(stderr,"pair detected, %ld\n",ans->data.pair.car->data.intnum);
	delete_void_char(in);
	c=getc(in);
	if(c == '.'){
		cdr(ans)=read_element(in);
		delete_void_char(in);
		c=getc(in);
		//assert(c==')'||c==']');
		if(!(c==')'||c==']')){
			fprintf(stderr,"Error: ) or ] not matched\n");
			ERR_REPORT(1);
		}
		return ans;
	}
	if(c == ')' || c==']'){
		cdr(ans)=empty_list_process;
		return ans;
	}
	ungetc(c,in);
	cdr(ans)=read_pair(in);
	return ans;
}

int issymbol_char(int c){
	return isalpha(c)||c=='+'||c=='-'||c=='*'||c=='/'||c=='>'||c=='<'||c=='_'||c=='='||c=='$'||c=='%'||c=='\\'||c=='&'||c=='^'||c=='!'||c=='?'||c=='@'||c>127;
}

element * make_lambda_proc(element * paras,element * body,element * env){
	element * ans=alloc_element();
	ans->type=LAMBDA_PROC;
	ans->data.lambda_proc.paras=paras;
	ans->data.lambda_proc.body=body;
	ans->data.lambda_proc.env=env;
	return ans;
}
element * make_macro(element * paras,element * body,element * env){
	element * ans=alloc_element();
	ans->type=MACRO;
	ans->data.macro.paras=paras;
	//write_element(paras,stdout);
	//printf("%lx\n",paras);
	ans->data.macro.body=body;
	ans->data.macro.env=env;
	return ans;
}

int escape_char(int in){
	int out;
	switch(in){
		case 't':
			out='\t';
			break;
		case 'r':
			out='\r';
			break;
		case 'v':
			out='\v';
			break;
		case 'n':
			out='\n';
			break;
		case '"':
			out='"';
			break;
		default:
			out=in;
			break;
	}
	return out;
}
int string_escape_copy(char * dst,char * src,size_t n){
	int i=0;
	int j=0;
	while(i<n-1 && src[j]){
		if(src[j]=='\\'){
			j++;
			dst[i]=escape_char(src[j]);
		}else{
			dst[i]=src[j];
		}
		i++;
		j++;
	}
	dst[i]=0;
	return i;
}

int dec_is_slash(char * str,int cur_i){
	int ret=1;
	cur_i--;
	while(cur_i>=0 && str[cur_i]=='\\'){
		ret=!ret;
		cur_i--;
	}
	return ret;
}

element * read_element(FILE * in){
	int ret=delete_void_char(in);
	if(ret==EOF)return global_eof;
	int fstc=first_char(in);
	if(fstc=='('||fstc=='['){
		getc(in);
		return read_pair(in);
	}
	if(fstc==')'){
		fprintf(stderr,"Error: unmatched parentheses )\n");
		getc(in);
		ERR_REPORT(1);
	}
	if(fstc=='\''){
		getc(in);
		return cons(quote_symbol,cons(read_element(in),empty_list_process));
	}
	if(fstc=='`'){
		getc(in);
		return cons(quasiquote_symbol,cons(read_element(in),empty_list_process));
	}
	if(fstc==','){
		getc(in);
		return cons(unquote_symbol,cons(read_element(in),empty_list_process));
	}
	element * ans=alloc_element();
	if(fstc=='"'){
		int i=0;
		char c=getc(in);
		while((c=getc(in))!=EOF && i<BUFMAX){
			if(c=='"'){
				if(dec_is_slash(buffer,i)){
					buffer[i]=0;
					ans->data.string_var=malloc(sizeof(char)*(i+1));
					ans->type=STRING;
					string_escape_copy(ans->data.string_var,buffer,sizeof(char)*(i+1));
					return ans;
				}
			}
			buffer[i]=c;
			i++;
		}
		if(i>=BUFMAX){
			fprintf(stderr,"Error: reading buffer over flow in read_element\n");
			ERR_REPORT(1);
		}
		if(c==EOF){
			fprintf(stderr,"Error: unexpected EOF\n");
			ERR_REPORT(1);
		}
		//assert(i<BUFMAX);
		//assert(c!=EOF);
	}
	read_buf(in);


	int intorfloat=isint_or_float(buffer);
	if(intorfloat==1){
		sscanf(buffer,"%ld",&ans->data.intnum);
		ans->type=INTNUM;
		return ans;
	}
	if(intorfloat==2){
		sscanf(buffer,"%lf",&ans->data.floatnum);
		ans->type=MFLOATNUM;
		return ans;
	}
	if(fstc=='#'){
		if(buffer[1]=='f'){
			/*
			ans->data.boolean=0;
			ans->type=MBOOLEAN;*/
			return global_false;
		}else if(buffer[1]=='t'){
			/*
			ans->data.boolean=1;
			ans->type=MBOOLEAN;*/
			return global_true;
		}else if(buffer[1]=='\\'){
			char curchar=buffer[2];
			//printf("curchar=%c\n",curchar);
			ans->type=MCHAR;
			switch(curchar){
				case 's':
					if(strcmp(buffer+2,"space")==0){
						ans->data.char_var=' ';
						return ans;
					}
					break;
				case 'n':
					if(strcmp(buffer+2,"newline")==0){
						ans->data.char_var='\n';
						return ans;
					}
					break;
				default :
					break;
			}
			ans->data.char_var=curchar;
			return ans;
		}else{
			int m=getc(in);
			if(m=='(' || m=='['){
				return cons(quote_vector_symbol,read_pair(in));
			}else{
				fprintf(stderr,"Error: unknown expression in read_element;m=%c\n",m);
				ERR_REPORT(1);
			}
		}
	}
	if(issymbol_char(fstc)){
		return makesymbol(buffer);
	}
	fprintf(stderr,"Error: unknown expression: m=%c\n",fstc);
	ERR_REPORT(1);
	return NULL;
}


void write_pair(element * ele,FILE * out){
	
	write_element(car(ele),out);
	if(cdr(ele)==NULL){
		fprintf(out," #<undefined>");
		return;
	}
	if(cdr(ele)->type==PAIR){
		fprintf(out," ");
		write_pair(cdr(ele),out);
	}else if(isempty(cdr(ele))){
		return;
	}else{
		fprintf(out ," . ");
		write_element(cdr(ele),out);
	}
}

long float_dump_mode=0; //0-> sci exp 1-> norm float
element * internal_set_float_mode (element * ele){
	ele=car(ele);
	if(ele->type!=INTNUM || ele->data.intnum>1){
		fprintf(stderr,"arg of set-float-mode must be an integer, and 0->sci 1->float\n");
		ERR_REPORT(1);
	}
	float_dump_mode=ele->data.intnum;
	return done_symbol;
}

void write_string_to_file(char * str , FILE * out){
	fprintf(out,"\"");
	while(*str){
		switch(*str){
			case '\n':
				fprintf(out,"\\n");
				break;
			case '\t':
				fprintf(out,"\\t");
				break;
			case '\\':
				fprintf(out,"\\\\");
				break;
			case '"':
				fprintf(out,"\\\"");
				break;
			default:
				fprintf(out,"%c",*str);
				break;
		}
		str++;
	}
	fprintf(out,"\"");
}

void write_element(element * ele,FILE *out){
	if(ele==NULL){
		fprintf(out,"#<undefined>");
		return;
	}
	switch (ele->type){
		case GC_STACK:
			fprintf(out,"#<gc_stack>");
			break;
		case INTNUM:
			fprintf(out,"%ld",ele->data.intnum);
			break;
		case MFLOATNUM:
			if(float_dump_mode==0){ 
				fprintf(out,"%.17e",ele->data.floatnum);
			}else if(float_dump_mode==1){
				fprintf(out,"%.17f",ele->data.floatnum);
			}
			break;
		case MBOOLEAN:
			fprintf(out,"#%c",ele->data.boolean*'t'+(!ele->data.boolean)*'f');
			break;
		case STRING:
			//fprintf(out,"\"%s\"",ele->data.string_var);
			write_string_to_file(ele->data.string_var,out);
			break;
		case VECTOR:
			fprintf(out,"#(");
			switch (ele->data.vector.type){
				long i;
				case INTVEC:
					for(i=0;i<ele->data.vector.vec_len;i++){
						fprintf(out,"%ld ",ele->data.vector.vector_data.p_int[i]);
					}
					break;
				case MFLOATVEC:
					for(i=0;i<ele->data.vector.vec_len;i++){
						if(float_dump_mode==0){ 
							fprintf(out,"%.17e ",ele->data.vector.vector_data.p_float[i]);
						}else if(float_dump_mode==1){
							fprintf(out,"%.17f ",ele->data.vector.vector_data.p_float[i]);
						}
					}
					fprintf(out,")");
					break;
				default:
					for(i=0;i<ele->data.vector.vec_len;i++){
						write_element(ele->data.vector.vector_data.p_general[i],out);
						fprintf(out," ");
					}
					break; 
			} 
			fprintf(out,")");
			break;
		case MCHAR:
			if(ele->data.char_var==' '){
				fprintf(out,"#\\space");
			}else 
			if(ele->data.char_var=='\n'){
				fprintf(out,"#\\newline");
			}else{
				fprintf(out,"#\\%c",ele->data.char_var);
			}
			break;
		case SYMBOL:
			fprintf(out,"%s",ele->data.symbol.symbolname);
			break;
		case PAIR:
			fprintf(out,"(");
			write_pair(ele,out);
			fprintf(out,")");
			break;
		case EMPTYLIST:
			fprintf(out,"()");
			break;
		case LAMBDA_PROC:
			fprintf(out,"#<procedure>");
			break;
		case MPROC:
			fprintf(out,"#<procedure>");
			break;
		case MACRO:
			fprintf(out,"#<macro>");
			break;
		case INPUT_PORT:
			fprintf(out,"#<input-port:0x%lx>",ele->data.in_port.in_port);
			break;
		case OUTPUT_PORT:
			fprintf(out,"#<output-port:0x%lx>",ele->data.out_port.out_port);
			break;
		case ELSE:
			fprintf(out,"#<else>");
			break;
		default:
			break;
	}
}

int is_self_eval(element * ele){
	return ele->type==INTNUM||ele->type==MFLOATNUM||ele->type==MCHAR ||ele->type==MBOOLEAN||ele->type==STRING;
}
int is_tag(element * ele,element * tag){
	if(ele->type==PAIR){
		return (car(ele)->type==SYMBOL) && car(ele)==tag;
	}
	return 0;
}


element * add_binding_in_hashtable(element * var, element * val, symbol_var_pair ** hashtable){
	symbol_var_pair * varpair;
	if(var->type!=SYMBOL){
		fprintf(stderr,"Error: var type is not symbol :var=");
		write_element(var,stderr);
		fprintf(stderr,"val=");
		write_element(val,stderr);
		fprintf(stderr,"\n");
		ERR_REPORT(1);
	}
	HASH_FIND_INT(hashtable[0],&var->data.symbol.symbol_id,varpair);
	if(varpair){
		if(varpair->symbol_id!=var->data.symbol.symbol_id){ 
			fprintf(stderr,"Error: internal error: symbol_id constructer has bug!\n");
			ERR_REPORT(1);
		}
		//assert(varpair->symbol_id==var->data.symbol.symbol_id);
		//assert(strcmp(varpair->symbolname,var->data.symbol.symbolname)==0);
		element * oldvar=varpair->value;
		varpair->value=val;
		return oldvar;
	}
	varpair=malloc(sizeof(symbol_var_pair));
	varpair->symbol_id=var->data.symbol.symbol_id;
	//varpair->symbolname=NULL;
	//varpair->symbolname=var->data.symbol.symbolname;
	varpair->value=val;
	HASH_ADD_INT(hashtable[0],symbol_id,varpair);

	return NULL;
}
element * generate_subenv(symbol_var_pair * hashtable){
	element * ans=alloc_element();
	ans->type=ELSE;
	ans->data.else_var=hashtable;
	return ans;
}


element * building_subenv_from_var_and_val(element * var,element *val){
	element * subenv=generate_subenv(NULL);
	while(!isempty(var) /*&& !isempty(val)*/){
		if(var->type==PAIR && val->type==PAIR){
			add_binding_in_hashtable(car(var),car(val),(symbol_var_pair**)&subenv->data.else_var);
		}else if(var->type==SYMBOL){
			add_binding_in_hashtable(var,val,(symbol_var_pair**)&subenv->data.else_var);
			break;
		}else{
			fprintf(stderr,"building env: syntax error: var=");
			write_element(var,stderr);
			fprintf(stderr,",val=");
			write_element(val,stderr);
			fprintf(stderr,"\n");
			ERR_REPORT(1);
			//exit(1);
		}
		var=cdr(var);
		val=cdr(val);
	}
	return subenv;
}
element * make_single_env_from_var_and_val(element * args){
	return building_subenv_from_var_and_val(car(args),car(cdr(args)));
}

symbol_var_pair * find_var_in_hashtable(element * var,symbol_var_pair * hashtable){
	symbol_var_pair * varpair;
	//fprintf(stderr,"find:%d\n",hashtable);
	//assert(var->type==SYMBOL);
	if(var->type!=SYMBOL){
		fprintf(stderr,"can not find binding of :");
		write_element(var,stderr);
		fprintf(stderr,"\n");
		ERR_REPORT(1);
	}
	HASH_FIND_INT(hashtable,&var->data.symbol.symbol_id,varpair);
	return varpair;
}



element * extend_env(element * ext,element * base){
	return cons(ext,base);
}
element * find_var_in_env(element * var,element * env,int errable){
	if(var->type!=SYMBOL && errable) {
		return NULL;
	}
	symbol_var_pair * ans;
	symbol_var_pair * hashtable;
	while(env->type!= EMPTYLIST){
		if(car(env)->type!=ELSE){
			fprintf(stderr,"env is not a valid env data structure\n");
			ERR_REPORT(1);
		}
		hashtable=(symbol_var_pair*)(car(env)->data.else_var);
		//fprintf(stderr,"%d id=%ld\n",hashtable,var->data.symbol.symbol_id);
		ans=find_var_in_hashtable(var,hashtable);
		if(ans)return ans->value;
		env=cdr(env);
	}
	if(errable){
		return NULL;
	}
	fprintf(stderr,"%s :",var->data.symbol.symbolname);
	fprintf(stderr,"unbounded variable");
	ERR_REPORT(1);
	return NULL;
}

element * internal_find_var_in_single_env(element * args){ //(internal_find_var_in_single_env var env error)
	element * ans=find_var_in_env(car(args),car(cdr(args)),1);
	if(ans){
		return ans;
	}else{
		return car(cdr(cdr(args)));
	}
}
element * init_env(void){
	return extend_env(generate_subenv(NULL),empty_environment);
}
void set_var_in_env(element * var,element *val,element *env){
	while(env->type!=EMPTYLIST){
		if(car(env)->type!=ELSE){
			fprintf(stderr,"env is not a valid env data structure\n");
			ERR_REPORT(1);
		}
		symbol_var_pair * hashtable=(symbol_var_pair*)(car(env)->data.else_var);
		symbol_var_pair * svp=find_var_in_hashtable(var,hashtable);
		if(svp){
			svp->value=val;
			return;
		}
		env=cdr(env);
	}
	fprintf(stderr,"%s :",var->data.symbol.symbolname);
	fprintf(stderr,"unbounded variable");
	ERR_REPORT(1);
}
void define_var_in_env(element * var,element *val, element *env){
	if(car(env)->type!=ELSE){
		fprintf(stderr,"env is not a valid env data structure\n");
		ERR_REPORT(1);
	}
	add_binding_in_hashtable(var,val,(symbol_var_pair**)&(car(env)->data.else_var));
}
element * add_binding_in_single_env(element * args){ //(add_binding_in_single_env (cons var val) env)
	define_var_in_env(car(car(args)),cdr(car(args)),cdr(args));
	return NULL;
}
element * makechar(char c){
	element * ans=alloc_element();
	ans->type=MCHAR;
	ans->data.char_var=c;
	return ans;
}
element * makestring(char * str){
	element * ans=alloc_element();
	ans->type=STRING;
	ans->data.string_var=malloc(strlen(str)+1);
	strcpy(ans->data.string_var,str);
	return ans;
}


element * internal_symbol2str(element * ele){
	ele=car(ele);
	if(ele->type!=SYMBOL){
		fprintf(stderr,"variable is not a symbol in symbol->string: SYMBOL=%d, current=%d, ",SYMBOL,ele->type);
		write_element(ele,stderr);
		fprintf(stderr,"\n");
		ERR_REPORT(1);
	}
	return makestring(ele->data.symbol.symbolname);
}

long pub_gensym_int=0;
element * internal_gensym(element * ele){
	char str[128];
	sprintf(str,"#GEN%ld",pub_gensym_int);
	pub_gensym_int++;
	return makesymbol(str);
}

element * internal_str2symbol(element * ele){
	ele=car(ele);
	if(!(ele->type==STRING && issymbol_char(ele->data.string_var[0]))){
		fprintf(stderr,"variable of string->symbol is not a valid symbol string\n");
		write_element(ele,stderr);
		ERR_REPORT(1);
	}
	return makesymbol(ele->data.string_var);
}

long length_of_list(element * input){
	long ans=0;
	while(input!=empty_list_process){
		ans++;
		input=cdr(input);
	}
	return ans;
}

element * internal_num2str(element * input){
	input=car(input);
	char str[128];
	if(input->type==INTNUM){
		sprintf(str,"%ld",input->data.intnum);
	}else if(input->type==MFLOATNUM){
		sprintf(str,"%.16e",input->data.floatnum);
	}else{
		str[0]=0;
	}
	element * ans=makestring(str);
	return ans;
}
element * internal_list2str(element * input){
	input=car(input);
	long len=length_of_list(input);
	char * str=malloc(sizeof(char)*(len+1));
	long i=0;
	while(input!=empty_list_process){
		str[i]=car(input)->data.char_var;
		i++;
		input=cdr(input);
	}
	str[i]=0;
	element * ans=makestring(str);
	free(str);
	return ans;
}
element * internal_body_of_lambda(element * ele){
	ele=car(ele);
	if(ele->type!=LAMBDA_PROC){
		fprintf(stderr,"type is not lambda: ");
		write_element(ele,stderr);
		fprintf(stderr,"\n");
	}else{
		return ele->data.lambda_proc.body;
	}
	return global_false;
}
element * internal_args_of_lambda(element * ele){
	ele=car(ele);
	if(ele->type!=LAMBDA_PROC){
		fprintf(stderr,"type is not lambda: ");
		write_element(ele,stderr);
		fprintf(stderr,"\n");
	}else{
		return ele->data.lambda_proc.paras;
	}
	return global_false;
}

element * internal_str2list(element * input){
	input=car(input);
	if(input->type!=STRING){
		fprintf(stderr,"variable of string->list is not a string");
		ERR_REPORT(1);
	}
	element * ans=empty_list_process;
	char * str=input->data.string_var;
	char * endc=str+strlen(str)-1;
	while(endc>=str){
		ans=cons(makechar(endc[0]),ans);
		endc--;
	}
	return ans;
}
element * internal_str2num(element * input){
	input=car(input);
	char * str=input->data.string_var;
	//fprintf(stderr,"%s\n",str);
	int iof=isint_or_float(str);
	element * ans=alloc_element();
	if(iof==1){
		long rt;
		sscanf(str,"%ld",&rt);
		ans->type=INTNUM;
		ans->data.intnum=rt;
	}else if(iof==2){
		double rt;
		sscanf(str,"%lf",&rt);
		ans->type=MFLOATNUM;
		ans->data.floatnum=rt;
	}else{
		return NULL;
	}
	return ans;
}

element * internal_is_alpha(element * ele){
	ele=car(ele);
	if(ele->type==MCHAR && isalpha(ele->data.char_var)){
		return global_true;
	}
	return global_false;
}
element * internal_is_vector(element * ele){
	ele=car(ele);
	if(ele->type==VECTOR){
		return global_true;
	}
	return global_false;
}
element * makefloat(double i){
	element * ele=alloc_element();
	ele->type=MFLOATNUM;
	ele->data.floatnum=i;
	return ele;
}
element * makeint(long i){
	element * ele=alloc_element();
	ele->type=INTNUM;
	ele->data.intnum=i;
	return ele;
}
#define SWITCHVECTOR(ele,intp,floatp,generalp) switch(ele){case INTVEC: intp ; break; case MFLOATVEC: floatp ;break;case GENERALVEC: generalp;break;default: break;}
element * internal_vec_ref(element * ele){
	if(car(ele)->type!=VECTOR){
		fprintf(stderr,"Error: 1st arg of vector-ref must be a vector\n");
		ERR_REPORT(1);
	}
	element * self=car(ele);
	if(car(cdr(ele))->type!=INTNUM){
		fprintf(stderr,"Error: 2nd arg of vector-ref must be a int\n");
		ERR_REPORT(1);
	}
	long k=car(cdr(ele))->data.intnum;
	if(k<0||k>=self->data.vector.vec_len){
		fprintf(stderr,"Error: vector-ref index out of range: %ld",k);
		ERR_REPORT(1);
	}
	SWITCHVECTOR(self->data.vector.type,return makeint(self->data.vector.vector_data.p_int[k]),return makefloat(self->data.vector.vector_data.p_float[k]),return self->data.vector.vector_data.p_general[k]);
	fprintf(stderr,"Error: internal error: unknown vector type: %d\n",self->data.vector.type);
	ERR_REPORT(1);
	return NULL;
}
void internal_vec_expand_float(element * ele){
	long len=ele->data.vector.vec_len;
	double * vdata=ele->data.vector.vector_data.p_float;
	ele->data.vector.vector_data.p_general=malloc(sizeof(element*)*len);
	long i;
	for(i=0;i<len;i++){
		ele->data.vector.vector_data.p_general[i]=makefloat(vdata[i]);
	}
	free(vdata);
	ele->data.vector.type=GENERALVEC;
}
void internal_vec_expand_int(element * ele){
	long len=ele->data.vector.vec_len;
	long * vdata=ele->data.vector.vector_data.p_int;
	ele->data.vector.vector_data.p_general=malloc(sizeof(element*)*len);
	long i;
	for(i=0;i<len;i++){
		ele->data.vector.vector_data.p_general[i]=makeint(vdata[i]);
	}
	free(vdata);
	ele->data.vector.type=GENERALVEC;
}
element * internal_vec_set(element * ele){
	if(car(ele)->type!=VECTOR){
		fprintf(stderr,"Error: 1st arg of vector-ref must be a vector\n");
		ERR_REPORT(1);
	}
	element * self=car(ele);
	if(car(cdr(ele))->type!=INTNUM){
		fprintf(stderr,"Error: 2nd arg of vector-ref must be an integer\n");
		ERR_REPORT(1);
	}
	long k=car(cdr(ele))->data.intnum;
	if(k<0||k>=self->data.vector.vec_len){
		fprintf(stderr,"Error: vector-set! index out of range: %ld",k);
		ERR_REPORT(1);
	}
	element * val=car(cdr(cdr(ele)));
	SWITCHVECTOR(self->data.vector.type,if(val->type!=INTNUM){internal_vec_expand_int(self);},if(val->type!=MFLOATNUM){internal_vec_expand_int(self);},break);
	SWITCHVECTOR(self->data.vector.type,self->data.vector.vector_data.p_int[k]=val->data.intnum,self->data.vector.vector_data.p_float[k]=val->data.floatnum,self->data.vector.vector_data.p_general[k]=val);
	return done_symbol;
}
element * internal_vector_length(element * ele){
	if(car(ele)->type!=VECTOR){
		fprintf(stderr,"Error: 1st arg of vector-ref must be a vector\n");
		ERR_REPORT(1);
	}
	ele=car(ele);
	return makeint(ele->data.vector.vec_len);
}
element * internal_make_vector(element * ele){
	if(car(ele)->type!=INTNUM){
		fprintf(stderr,"Error: 1st arg of make-vector must be an integer\n");
		ERR_REPORT(1);
	}
	element * self=car(ele);
	long len=self->data.intnum;
	element * ans=alloc_element();
	ans->type=VECTOR;
	ans->data.vector.vec_len=len;
	if(cdr(ele)==empty_list_process){
		ans->data.vector.type=GENERALVEC;
		ans->data.vector.vector_data.p_general=malloc(sizeof(element*)*len);
		memset(ans->data.vector.vector_data.p_general,0,sizeof(element*)*len);
	}else if(car(cdr(ele))->type==INTNUM){
		ans->data.vector.type=INTVEC;
		ans->data.vector.vector_data.p_int=malloc(sizeof(long)*len);
		long i;
		for(i=0;i<len;i++){
			ans->data.vector.vector_data.p_int[i]=car(cdr(ele))->data.intnum;
		}
	}else if(car(cdr(ele))->type==MFLOATNUM){
		ans->data.vector.type=MFLOATVEC;
		ans->data.vector.vector_data.p_float=malloc(sizeof(double)*len);
		long i;
		for(i=0;i<len;i++){
			ans->data.vector.vector_data.p_float[i]=car(cdr(ele))->data.floatnum;
		}
	}else{
		ans->data.vector.type=GENERALVEC;
		ans->data.vector.vector_data.p_general=malloc(sizeof(element*)*len);
		memset(ans->data.vector.vector_data.p_general,0,sizeof(element*)*len);
		long i;
		for(i=0;i<len;i++){
			ans->data.vector.vector_data.p_general[i]=car(cdr(ele));
		}
	}
	return ans;
}
element * internal_is_string(element * ele){
	ele=car(ele);
	if(ele->type==STRING){
		return global_true;
	}
	return global_false;
}
element * internal_is_symbol(element * ele){
	ele=car(ele);
	if(ele->type==SYMBOL){
		return global_true;
	}
	return global_false;
}

element * internal_is_pair(element * ele){
	ele=car(ele);
	if(ele->type==PAIR){
		return global_true;
	}else{
		return global_false;
	}
}
element * internal_is_empty(element * ele){
	ele=car(ele);
	if(ele->type==EMPTYLIST){
		return global_true;
	}else{
		return global_false;
	}
}
element * internal_is_even(element * arg){
	arg=car(arg);
	int ans;
	if(arg->type==MFLOATNUM){
		ans=arg->data.floatnum+.5;
	}else{
		ans=arg->data.intnum;
	}
	if((ans & 1) == 0){
		return global_true;
	}else{
		return global_false;
	}
}
element * internal_is_odd(element * arg){
	arg=car(arg);
	int ans;
	if(arg->type==MFLOATNUM){
		ans=arg->data.floatnum+.5;
	}else{
		ans=arg->data.intnum;
	}
	if((ans & 1) == 0){
		return global_false;
	}else{
		return global_true;
	}
}
element * internal_is_binded(element * arg){
	fprintf(stderr,"Error: macroexpand should never be called!\n");
	ERR_REPORT(1);
	//exit(1);
	//return arg->type==MACRO ? global_true:global_false;
}
element * internal_is_primitive(element * arg){
	arg=car(arg);
	return arg->type==MPROC? global_true:global_false;
}
element * internal_is_lambda(element * arg){
	arg=car(arg);
	return arg->type==LAMBDA_PROC? global_true:global_false;
}
element * internal_is_macro(element * arg){
	arg=car(arg);
	return arg->type==MACRO ? global_true:global_false;
}
element * internal_is_char(element * arg){
	arg=car(arg);
	return arg->type==MCHAR ? global_true:global_false;
}
element * internal_is_bool(element * arg){
	arg=car(arg);
	return arg->type==MBOOLEAN? global_true:global_false;
}
element * internal_is_fixnum(element * arg){
	arg=car(arg);
	if(arg->type==INTNUM){
		return global_true;
	}else{
		return global_false;
	}
}
element * internal_is_float(element * arg){
	arg=car(arg);
	if(arg->type==MFLOATNUM){
		return global_true;
	}else{
		return global_false;
	}
}
element * internal_is_number(element * arg){
	arg=car(arg);
	if(arg->type==INTNUM || arg->type==MFLOATNUM){
		return global_true;
	}else{
		return global_false;
	}
}
element * internal_add(element * arg){
	element * ans=alloc_element();
	ans->type=INTNUM;
	ans->data.intnum=0;
	while(!isempty(arg)){
		if(car(arg)->type==MFLOATNUM){
			if(ans->type==INTNUM){
				ans->data.floatnum=ans->data.intnum;
				ans->type=MFLOATNUM;
			}
			ans->data.floatnum+=(car(arg))->data.floatnum;
		}else
		if(car(arg)->type==INTNUM){
			if(ans->type==MFLOATNUM){
				ans->data.floatnum+=(car(arg))->data.intnum;
			}else{
				ans->data.intnum+=(car(arg))->data.intnum;
			}
		}else{
			fprintf(stderr,"arg of + is not number: ");
			write_element(arg,stderr);
			
			ERR_REPORT(0);
		}
		arg=cdr(arg);
	}
	return ans;
}
element * internal_mul(element * arg){
	element * ans=alloc_element();
	ans->type=INTNUM;
	ans->data.intnum=1;
	while(!isempty(arg)){
		if(car(arg)->type==MFLOATNUM){
			if(ans->type==INTNUM){
				ans->data.floatnum=ans->data.intnum;
				ans->type=MFLOATNUM;
			}
			ans->data.floatnum*=(car(arg))->data.floatnum;
		}else
		if(car(arg)->type==INTNUM){
			if(ans->type==MFLOATNUM){
				ans->data.floatnum*=(car(arg))->data.intnum;
			}else{
				ans->data.intnum*=(car(arg))->data.intnum;
			}
		}else{
			fprintf(stderr,"arg of * is not number: ");
			write_element(arg,stderr);
			
			ERR_REPORT(0);
		}
		arg=cdr(arg);
	}
	return ans;
}
element * internal_div(element * arg);
element * internal_quotient(element * arg){
	if(isempty(arg) || isempty(cdr(arg))){
		fprintf(stderr,"not enough arg in quotient\n");
		ERR_REPORT(1);
	}
	element * ans=alloc_element();
	if(car(arg)->type==INTNUM && car(cdr(arg))->type==INTNUM){
		ans->type=INTNUM;
		ans->data.intnum=car(arg)->data.intnum/car(cdr(arg))->data.intnum;
		return ans;
	}else{
		return internal_div(arg);
	}
}
element * internal_bitwise_and(element * arg){
	if(isempty(arg) || isempty(cdr(arg))){
		fprintf(stderr,"not enough arg in bitwise-and\n");
		ERR_REPORT(1);
	}
	element * ans=alloc_element();
	if(car(arg)->type==INTNUM && car(cdr(arg))->type==INTNUM){
		ans->type=INTNUM;
		ans->data.intnum=car(arg)->data.intnum & car(cdr(arg))->data.intnum;
		return ans;
	}else{
		fprintf(stderr,"bitwise-and only accepts 2 integer numbers as its arguments\n");
		ERR_REPORT(1);
		return ans;
	}
}
element * internal_arithmetic_shift(element * arg){
	if(isempty(arg) || isempty(cdr(arg))){
		fprintf(stderr,"not enough arg in arithemetic-shift\n");
		ERR_REPORT(1);
	}
	element * ans=alloc_element();
	if(car(arg)->type==INTNUM && car(cdr(arg))->type==INTNUM){
		ans->type=INTNUM;
		long tmp=car(cdr(arg))->data.intnum;
		ans->data.intnum=tmp>0?car(arg)->data.intnum<<tmp:car(arg)->data.intnum>>(-tmp);
		return ans;
	}else{
		fprintf(stderr,"arithemetic-shift only accepts 2 integer numbers as its arguments\n");
		ERR_REPORT(1);
		return ans;
	}
}
element * internal_remainder(element * arg){
	if(isempty(arg) || isempty(cdr(arg))){
		fprintf(stderr,"not enough arg in remainder\n");
		ERR_REPORT(1);
	}
	element * ans=alloc_element();
	if(car(arg)->type==INTNUM && car(cdr(arg))->type==INTNUM){
		ans->type=INTNUM;
		ans->data.intnum=car(arg)->data.intnum%car(cdr(arg))->data.intnum;
		return ans;
	}else{
		fprintf(stderr,"remainder only accepts 2 integer numbers as its arguments\n");
		ERR_REPORT(1);
		return ans;
	}
}
element * internal_div(element * arg){
	element * ans=alloc_element();
	if(isempty(arg)){
		fprintf(stderr,"empty arg in /\n");
		ERR_REPORT(1);
	}
	if(isempty(cdr(arg))){
		if(car(arg)->type==INTNUM){
			ans->data.floatnum=1./car(arg)->data.intnum;
		}else{
			ans->data.floatnum=1./car(arg)->data.floatnum;
		}
		ans->type=MFLOATNUM;
		return ans;
	}else{
		if(car(arg)->type==INTNUM){
			ans->data.floatnum=car(arg)->data.intnum;
		}else{
			ans->data.floatnum=car(arg)->data.floatnum;
		}
		ans->type=MFLOATNUM;
		arg=cdr(arg);
	}
	
	while(!isempty(arg)){
		if(car(arg)->type==MFLOATNUM){
			if(ans->type==INTNUM){
				ans->data.floatnum=ans->data.intnum;
				ans->type=MFLOATNUM;
			}
			ans->data.floatnum/=(car(arg))->data.floatnum;
		}
		if(car(arg)->type==INTNUM){
			if(ans->type==MFLOATNUM){
				ans->data.floatnum/=(car(arg))->data.intnum;
			}else{
				ans->data.intnum/=(car(arg))->data.intnum;
			}
		}
		arg=cdr(arg);
	}
	return ans;
}
element * internal_sub(element * arg){
	element * ans=alloc_element();
	if(isempty(arg)){
		fprintf(stderr,"empty arg in -\n");
		ERR_REPORT(1);
	}
	if(isempty(cdr(arg))){
		if(car(arg)->type==INTNUM){
			ans->data.intnum=-car(arg)->data.intnum;
			ans->type=INTNUM;
		}else{
			ans->data.floatnum=-car(arg)->data.floatnum;
			ans->type=MFLOATNUM;
		}
		return ans;
	}else{
		if(car(arg)->type==INTNUM){
			ans->data.intnum=car(arg)->data.intnum;
			ans->type=INTNUM;
		}else{
			ans->data.floatnum=car(arg)->data.floatnum;
			ans->type=MFLOATNUM;
		}
		arg=cdr(arg);
	}
	
	while(!isempty(arg)){
		if(car(arg)->type==MFLOATNUM){
			if(ans->type==INTNUM){
				ans->data.floatnum=ans->data.intnum;
				ans->type=MFLOATNUM;
			}
			ans->data.floatnum-=(car(arg))->data.floatnum;
		}
		if(car(arg)->type==INTNUM){
			if(ans->type==MFLOATNUM){
				ans->data.floatnum-=(car(arg))->data.intnum;
			}else{
				ans->data.intnum-=(car(arg))->data.intnum;
			}
		}
		arg=cdr(arg);
	}
	return ans;
}
element * internal_set_car(element * arg){
    car(car(arg))=car(cdr(arg));
    return done_symbol;
}
element * internal_set_cdr(element * arg){
    cdr(car(arg))=car(cdr(arg));
    return done_symbol;
}
element * internal_car(element * arg){
	if(arg->type!=PAIR || car(arg)->type!=PAIR){
		fprintf(stderr,"arg of car is not pair\n");
		write_element(arg,stderr);
		ERR_REPORT(1);
	}
	return car(car(arg));
}
element * internal_cdr(element * arg){
	if(arg->type!=PAIR || car(arg)->type!=PAIR){
		fprintf(stderr,"arg of cdr is not pair\n");
		write_element(arg,stderr);
		ERR_REPORT(1);
	}
	return cdr(car(arg));
}
element * internal_cons(element * arg){
	element * ca=car(arg);
	element * cd=car(cdr(arg));
	return cons(ca,cd);
}
element * internal_is_output_port(element * arg){
	return car(arg)->type==OUTPUT_PORT ? global_true:global_false;
}
element * internal_is_input_port(element * arg){
	return car(arg)->type==INPUT_PORT ? global_true:global_false;
}
element * internal_is_eof_object(element * arg){
	return car(arg)==global_eof ? global_true:global_false;
}
element * is_less_than_or_eq(element * arg1,element * arg2){
	if(arg1->type==INTNUM){
		long ag1=arg1->data.intnum;
		if(arg2->type==INTNUM){
			//fprintf(stderr,"i_internal ok here\n");
			return ag1 <= arg2->data.intnum ? global_true:global_false;
		}else{
			return ag1 <= arg2->data.floatnum ? global_true:global_false;
		}
	}
	if(arg1->type==MFLOATNUM){
		double ag1=arg1->data.floatnum;
		if(arg2->type==INTNUM){
			return ag1 <= arg2->data.intnum ? global_true:global_false;
		}else{
			return ag1 <= arg2->data.floatnum ? global_true:global_false;
		}
	}
	fprintf(stderr,"args must be float or int");
	ERR_REPORT(1);
	return global_false;
}
element * is_less_than(element * arg1,element * arg2){
	if(arg1->type==INTNUM){
		long ag1=arg1->data.intnum;
		if(arg2->type==INTNUM){
			//fprintf(stderr,"i_internal ok here\n");
			return ag1 < arg2->data.intnum ? global_true:global_false;
		}else{
			return ag1 < arg2->data.floatnum ? global_true:global_false;
		}
	}
	if(arg1->type==MFLOATNUM){
		double ag1=arg1->data.floatnum;
		if(arg2->type==INTNUM){
			return ag1 < arg2->data.intnum ? global_true:global_false;
		}else{
			return ag1 < arg2->data.floatnum ? global_true:global_false;
		}
	}
	fprintf(stderr,"args must be float or int");
	ERR_REPORT(1);
	return global_false;
}
element * is_eq(element * arg1,element * arg2){
	if(arg1->type==INTNUM){
		long ag1=arg1->data.intnum;
		if(arg2->type==INTNUM){
			//fprintf(stderr,"i_internal ok here\n");
			return ag1 == arg2->data.intnum ? global_true:global_false;
		}else if(arg2->type==MFLOATNUM){
			return ag1 == arg2->data.floatnum ? global_true:global_false;
		}
	}
	if(arg1->type==MFLOATNUM){
		double ag1=arg1->data.floatnum;
		if(arg2->type==INTNUM){
			return ag1 == arg2->data.intnum ? global_true:global_false;
		}else if(arg2->type==MFLOATNUM){
			return ag1 == arg2->data.floatnum ? global_true:global_false;
		}
	}
	if(arg1->type==MCHAR && arg2->type==MCHAR){
		return arg1->data.char_var==arg2->data.char_var ? global_true:global_false;
	}
	if(arg1->type==STRING && arg2->type==STRING){
		return strcmp(arg1->data.string_var,arg2->data.string_var)==0 ? global_true:global_false;
	}
	return arg1==arg2 ? global_true:global_false;
	//assert(!"args must be float or int");
	return global_false;
}
element * is_greater_than_or_eq(element * arg1,element * arg2){
	if(arg1->type==INTNUM){
		long ag1=arg1->data.intnum;
		if(arg2->type==INTNUM){
			//fprintf(stderr,"i_internal ok here\n");
			return ag1 >= arg2->data.intnum ? global_true:global_false;
		}else{
			return ag1 >= arg2->data.floatnum ? global_true:global_false;
		}
	}
	if(arg1->type==MFLOATNUM){
		double ag1=arg1->data.floatnum;
		if(arg2->type==INTNUM){
			return ag1 >= arg2->data.intnum ? global_true:global_false;
		}else{
			return ag1 >= arg2->data.floatnum ? global_true:global_false;
		}
	}
	//assert(!"args must be float or int");
	return global_false;
}
element * is_greater_than(element * arg1,element * arg2){
	if(arg1->type==INTNUM){
		long ag1=arg1->data.intnum;
		if(arg2->type==INTNUM){
			//fprintf(stderr,"i_internal ok here\n");
			return ag1 > arg2->data.intnum ? global_true:global_false;
		}else{
			return ag1 > arg2->data.floatnum ? global_true:global_false;
		}
	}
	if(arg1->type==MFLOATNUM){
		double ag1=arg1->data.floatnum;
		if(arg2->type==INTNUM){
			return ag1 > arg2->data.intnum ? global_true:global_false;
		}else{
			return ag1 > arg2->data.floatnum ? global_true:global_false;
		}
	}
	//assert(!"args must be float or int");
	return global_false;
}

element * internal_is_greater_than_or_eq(element * arg){
	element * prev;
	element * next;
	prev=car(arg);
	while(!isempty(cdr(arg))){
		next=(car(cdr(arg)));
		//fprintf(stderr,"%d %d\n",prev->data.intnum,next->data.intnum);
		if(is_greater_than_or_eq(prev,next)==global_true){
			//fprintf(stderr,"internal ok here\n");
			prev=next;
		}else{
			return global_false;
		}
		arg=cdr(arg);
	}
	//fprintf(stderr,"ok here\n");
	return global_true;
}
element * internal_is_greater_than(element * arg){
	element * prev;
	element * next;
	prev=car(arg);
	while(!isempty(cdr(arg))){
		next=(car(cdr(arg)));
		//fprintf(stderr,"%d %d\n",prev->data.intnum,next->data.intnum);
		if(is_greater_than(prev,next)==global_true){
			//fprintf(stderr,"internal ok here\n");
			prev=next;
		}else{
			return global_false;
		}
		arg=cdr(arg);
	}
	//fprintf(stderr,"ok here\n");
	return global_true;
}
element * internal_is_less_than_or_eq(element * arg){
	element * prev;
	element * next;
	prev=car(arg);
	while(!isempty(cdr(arg))){
		next=(car(cdr(arg)));
		//fprintf(stderr,"%d %d\n",prev->data.intnum,next->data.intnum);
		if(is_less_than_or_eq(prev,next)==global_true){
			//fprintf(stderr,"internal ok here\n");
			prev=next;
		}else{
			return global_false;
		}
		arg=cdr(arg);
	}
	//fprintf(stderr,"ok here\n");
	return global_true;
}
element * internal_is_less_than(element * arg){
	element * prev;
	element * next;
	prev=car(arg);
	while(!isempty(cdr(arg))){
		next=(car(cdr(arg)));
		//fprintf(stderr,"%d %d\n",prev->data.intnum,next->data.intnum);
		if(is_less_than(prev,next)==global_true){
			//fprintf(stderr,"internal ok here\n");
			prev=next;
		}else{
			return global_false;
		}
		arg=cdr(arg);
	}
	//fprintf(stderr,"ok here\n");
	return global_true;
}
element * internal_is_eq(element * arg){
	element * prev;
	element * next;
	prev=car(arg);
	while(!isempty(cdr(arg))){
		next=(car(cdr(arg)));
		//fprintf(stderr,"%d %d\n",prev->data.intnum,next->data.intnum);
		if(is_eq(prev,next)==global_true){
			//fprintf(stderr,"internal ok here\n");
			prev=next;
		}else{
			return global_false;
		}
		arg=cdr(arg);
	}
	//fprintf(stderr,"ok here\n");
	return global_true;
}
element * internal_fflush_port(element * ele){
	ele=car(ele);
	if(ele->type!=OUTPUT_PORT){
		fprintf(stderr,"fflush-port: arg type not a output-port");
		ERR_REPORT(1);
	}
	fflush(ele->data.out_port.out_port);
	return done_symbol;
}
element * internal_close_input_port(element * ele){
	ele=car(ele);
	if(ele->type!=INPUT_PORT){
		fprintf(stderr,"close-input-port: arg type not a input-port");
		ERR_REPORT(1);
	}
	if(!ele->data.in_port.isclose && ele->data.in_port.in_port!=stdin){
		fclose(ele->data.in_port.in_port);
		ele->data.in_port.isclose=1;
	}
	return done_symbol;
}
element * internal_close_output_port(element * ele){
	ele=car(ele);
	if(ele->type!=OUTPUT_PORT){
		fprintf(stderr,"close-output-port: arg type not a output-port");
		ERR_REPORT(1);
	}
	if(!ele->data.out_port.isclose && ele->data.out_port.out_port!=stdout && ele->data.out_port.out_port!=stderr){
		fclose(ele->data.out_port.out_port);
		ele->data.out_port.isclose=1;
	}
	return done_symbol;
}
element * internal_open_input_file(element * ele){
	if(car(ele)->type!=STRING){
		fprintf(stderr,"arg of open-input-file is not a string!\n");
		ERR_REPORT(1);
	}
	
	char * filename=car(ele)->data.string_var;
	FILE * in_port=fopen(filename,"r");
	if(in_port==NULL) {
		fprintf(stderr, "Error: could not open file \"%s\"\n", filename);
		return global_false;
		//exit(1);
	}
	return make_i_port(in_port);
}
element * internal_open_output_file(element * ele){
	if(car(ele)->type!=STRING){
		fprintf(stderr,"arg of open-output-file is not a string!\n");
		ERR_REPORT(1);
	}
	char * filename=car(ele)->data.string_var;
	FILE * out_port=fopen(filename,"w");
	if(out_port==NULL) {
		fprintf(stderr, "Error: could not open file \"%s\"\n", filename);
		ERR_REPORT(1);
		//exit(1);
	}
	return make_o_port(out_port);
}
element * makeproc(element * (*fn)(element *)){
	element * ans=alloc_element();
	ans->type=MPROC;
	ans->data.proc=fn;
	return ans;
}

element * get_var_list(element * lst,element * env);
element * get_macro_var_list(element * lst,element * env);
element * eval(element * input,element * env);

//void write_element(element * ele,FILE *out);


void push_gc_stack(element ** input);
void pop_gc_stack();
/*
element * quasiquote_eval(element * input,element * env){
	//write_element(input,stdout);
	if(is_tag(input,unquote_symbol)){
		return eval(car(cdr(input)),env);
	}
	if(input->type==PAIR){
		element * fst=quasiquote_eval(car(input),env);
		push_gc_stack(&fst);
		element * lst=quasiquote_eval(cdr(input),env);
		pop_gc_stack();
		return cons(fst,lst);
	}
	return input;
}
*/

element * expand_cond(element * input){
	if(isempty(input)){
		return global_false;
	}else{
		if(is_tag(car(input),else_symbol)){
			if(isempty(cdr(input))){
				return cons(begin_symbol,cdr(car(input)));
			}else{
				fprintf(stderr,"else clause is not the last cond->if\n");
				ERR_REPORT(1);
				//exit(1);
				return empty_list_process;
			}
		}
		else{
			return cons(if_symbol,cons(car(car(input)),cons(cons(begin_symbol,cdr(car(input))),cons(expand_cond(cdr(input)),empty_list_process))));
		}
	}
}

element * make_let_var_list(element * input){
	element * paras=empty_list_process;
	while(!isempty(input)){
		paras=cons(car(car(input)),paras);
		input=cdr(input);
	}
	return paras;
}
element * make_let_val_list(element * input){
	element * paras=empty_list_process;
	while(!isempty(input)){
		paras=cons(car(cdr(car(input))),paras);
		input=cdr(input);
	}
	return paras;
}

element * define2lambda(element * input){
	return cons(car(car(input)),cons(cons(lambda_symbol,cons(cdr(car(input)),cdr(input))),empty_list_process));
}

/*
element * internal_environment(element * input){
	
}*/
element * internal_macro_expand(element * input){
	fprintf(stderr,"Error: macroexpand should never be called!\n");
	ERR_REPORT(1);
	//exit(1);
}
element * internal_eval(element * input){
	fprintf(stderr,"Error: eval should never be called!\n");
	ERR_REPORT(1);
	//exit(1);
}
element * internal_apply(element * input){
	fprintf(stderr,"Error: apply should never be called!\n");
	ERR_REPORT(1);
	//exit(1);
}
element * internal_list_to_vector(element * arg);
element * internal_vector(element * arg){
	return internal_list_to_vector(arg);
	//fprintf(stderr,"Error: list should never be called!\n");
	//exit(1);
}
element * internal_list(element * arg){
	return arg;
	//fprintf(stderr,"Error: list should never be called!\n");
	//exit(1);
}
element * internal_load(element * input){
	char * filename=car(input)->data.string_var;
	//fprintf(stdout,"%lx %s\n",filename,filename);
	FILE * infile=fopen(filename,"r");
	if(!infile){
		fprintf(stderr, "Error: could not load file \"%s\"", filename);
		ERR_REPORT(1);
		//exit(1);
	}
	element * expr;
	element * ans=NULL;
	while((expr=read_element(infile))!=global_eof){
		//global_gc=cons(expr,global_gc);
		//fprintf(stderr,": load:");
		//write_element(expr,stderr);
		//fprintf(stderr,"\n");
		ans=eval(expr,global_environment);
		//global_gc=cdr(global_gc);
	}
	fclose(infile);
	return ans;
}
element * list2apply_args(element * input,element * env){
	if(cdr(input)==empty_list_process){
		return eval(car(input),env);
	}else{
		element * ca=eval(car(input),env);
		push_gc_stack(&ca);
		element * cd=list2apply_args(cdr(input),env);
		pop_gc_stack();
		return cons(ca,cd);
	}
}

element * internal_read(element * input){
	FILE * in_port= input==empty_list_process ? stdin:car(input)->data.out_port.out_port;
	if(in_port != stdin && car(input)->data.out_port.isclose){
		fprintf(stderr,"Error in read: input-port 0x%lx closed\n",car(input)->data.out_port.out_port);
		ERR_REPORT(1);
		//exit(1);
	}
	input=read_element(in_port);
	if(input==NULL){
		return global_eof;
	}else{
		return input;
	}
}
element * internal_read_char(element * input){
	FILE * in_port= input==empty_list_process ? stdin:car(input)->data.out_port.out_port;
	if(in_port != stdin && car(input)->data.out_port.isclose){
		fprintf(stderr,"Error in read-char: input-port 0x%lx closed\n",car(input)->data.out_port.out_port);
		ERR_REPORT(1);
		//exit(1);
	}
	input=alloc_element();
	input->type=MCHAR;
	int ans=fgetc(in_port);
	if(ans==EOF){
		return global_eof;
	}else{
		input->data.char_var=ans;
		return input;
	}
}
element * internal_peek_char(element * input){
	FILE * in_port= input==empty_list_process ? stdin:car(input)->data.out_port.out_port;
	if(in_port != stdin && car(input)->data.out_port.isclose){
		fprintf(stderr,"Error in peek-char: input-port 0x%lx closed\n",car(input)->data.out_port.out_port);
		ERR_REPORT(1);
	}
	input=alloc_element();
	input->type=MCHAR;
	int ans=fgetc(in_port);
	if(ans==EOF){
		return global_eof;
	}else{
		input->data.char_var=ans;
		ungetc(ans,in_port);
		return input;
	}
}
element * internal_write(element * input){
	element * etw=car(input); 
	input=cdr(input);
	FILE * out_port= (input==empty_list_process) ? stdout:car(input)->data.in_port.in_port;
	if(out_port!=stdout && car(input)->data.in_port.isclose){
		fprintf(stderr,"Error in write: output-port 0x%lx closed\n",car(input)->data.in_port.in_port);
		ERR_REPORT(1);
		//exit(1);
	}
	write_element(etw,out_port);
	return done_symbol;
}
element * internal_write_string(element * input){
	element * etw=car(input);
	input=cdr(input);
	FILE * out_port= (input==empty_list_process) ? stdout:car(input)->data.in_port.in_port;
	if(out_port!=stdout && car(input)->data.in_port.isclose){
		fprintf(stderr,"Error in write-string: output-port 0x%lx closed\n",car(input)->data.in_port.in_port);
		ERR_REPORT(1);
	}
	//write_element(etw,out_port);
	if(etw->type!=STRING){
		fprintf(stderr,"arg of write-string is not string\n");
		ERR_REPORT(1);
	}
	//fputs(etw->data.string_var,out_port);
	fprintf(out_port,"%s",etw->data.string_var);
	//write_string_to_file(etw->data.string_var,out_port);
	return done_symbol;
}
element * internal_write_char(element * input){
	element * etw=car(input);
	input=cdr(input);
	FILE * out_port= (input==empty_list_process) ? stdout:car(input)->data.in_port.in_port;
	if(out_port!=stdout && car(input)->data.in_port.isclose){
		fprintf(stderr,"Error: port closed\n");
		ERR_REPORT(1);
		//exit(1);
	}
	//write_element(etw,out_port);
	if(etw->type!=MCHAR){
		fprintf(stderr,"arg of write-char is not char\n");
		ERR_REPORT(1);
	}
	fputc(etw->data.char_var,out_port);
	return done_symbol;
}

/*
char * concat_string(char * input1,char * input2){
	long len=strlen(input1)+strlen(input2)+1;
	char * ans=malloc(len*sizeof(char));
	strcpy(ans,input1);
	strcpy(ans+strlen(ans),input2);
	return ans;
}*/

vec_type get_list_vector_element_type(element * input){
	switch (input->type){
		case INTNUM:
			return INTVEC;
			break;
		case MFLOATNUM:
			return MFLOATVEC;
			break;
		default :
			return GENERALVEC;
			break;
	}
}

vec_type get_list_vector_type(vec_type currenttype,element * input){
	if(cdr(input)==empty_list_process){
		return get_list_vector_element_type(car(input));
	}else{
		if(input->type!=PAIR){
			fprintf(stderr,"Error: only list can be converted to vector\n");
			ERR_REPORT(1);
		}
		vec_type tmp=get_list_vector_element_type(car(input));
		if(tmp==GENERALVEC||tmp!=currenttype){
			return GENERALVEC;
		}
		return get_list_vector_type(tmp,cdr(input));
	}
}

element * internal_list_to_vector(element * input){
	long len=length_of_list(input);
	element * ans=alloc_element();
	ans->type=VECTOR;
	ans->data.vector.vec_len=len;
	vec_type vt=get_list_vector_type(NULLVEC,input);
	//fprintf(stderr,"vt=%d\n",vt);
	long curl=0;
	switch (vt){
		case INTVEC:
			ans->data.vector.type=INTVEC;
			ans->data.vector.vector_data.p_int=malloc(sizeof(long)*len);
			while(input != empty_list_process){
				//fprintf(stderr,"%d\n",curl);
				ans->data.vector.vector_data.p_int[curl]=car(input)->data.intnum;
				curl++;
				input=cdr(input);
			}
			return ans;
			break;
		case MFLOATVEC:
			ans->data.vector.type=MFLOATVEC;
			ans->data.vector.vector_data.p_float=malloc(sizeof(double)*len);
			while(input != empty_list_process){
				ans->data.vector.vector_data.p_float[curl]=car(input)->data.floatnum;
				curl++;
				input=cdr(input);
			}
			return ans;
			break;
		default:
			ans->data.vector.type=GENERALVEC;
			ans->data.vector.vector_data.p_general=malloc(sizeof(element*)*len);
			while(input != empty_list_process){
				ans->data.vector.vector_data.p_general[curl]=car(input);
				curl++;
				input=cdr(input);
			}
			return ans;
			break;
	}
}

element * internal_system(element * input){
	if(car(input)==empty_list_process){
		fprintf(stderr,"Error: system must take 1 argument\n");
		ERR_REPORT(1);
		//exit(1);
	}
	if(car(input)->type == STRING){
		element * ret=alloc_element();
		ret->type=INTNUM;
		ret->data.intnum=system(car(input)->data.string_var);
		return ret;
	}else{
		fprintf(stderr,"Error: system must take string as its argument\n");
		ERR_REPORT(1);
		return done_symbol;
	}
}

element * internal_concat(element * input){
	if(car(input)==empty_list_process){
		fprintf(stderr,"Error: concat must at least take 1 argument\n");
		ERR_REPORT(1);
		//exit(1);
	}
	char * tmpstring=malloc(BUFMAX);
	long nnow=BUFMAX-1;
	tmpstring[0]=0;
	strncat(tmpstring,car(input)->data.symbol.symbolname,nnow);
	nnow=BUFMAX-strlen(tmpstring);
	input=cdr(input);
	while(input!=empty_list_process){
		if(car(input)->type != SYMBOL){
			fprintf(stderr,"arg of concat is not a symbol:");
			write_element(input,stderr);
			fprintf(stderr,"\n");
			ERR_REPORT(1);
		}
		//char * innertmp=concat_string(tmpstring,car(input)->symbol.symbolname);
		strncat(tmpstring,car(input)->data.symbol.symbolname,nnow);
		//fprintf(stderr,"DBG:%s\n",tmpstring);
		nnow=BUFMAX-strlen(tmpstring);
		input=cdr(input);
	}
	element * ans=makesymbol(tmpstring);
	free(tmpstring);
	return ans;
}
element * macro_expand(element * macro_proc,element * input,element * env){
	element * args=get_macro_var_list(cdr(input),env);
	element * proc=macro_proc;
	input=proc->data.macro.body;
	//write_element(proc->data.macro.paras,stdout);
	//printf("\n%lx\n",proc->data.macro.paras);
	element * subenv=building_subenv_from_var_and_val(proc->data.macro.paras,args);
	env=extend_env(subenv,proc->data.macro.env);
	element * newinput=cons(begin_symbol,input);
	/*
	push_gc_stack(&newinput);
	push_gc_stack(&args);
	push_gc_stack(&proc);*/
	element * ret=eval(newinput,env);
	//write_element(input,stderr);
	//printf(stderr,"\n");
	/*
	pop_gc_stack();
	pop_gc_stack();
	pop_gc_stack();*/
	return ret;
}

void push_gc_stack(element ** input){
	element * ele=alloc_element();
	ele->type=GC_STACK;
	ele->data.gc_stack.tmpele=input;
	global_gc=cons(ele,global_gc);
}
void push_caller_stack(element ** input){
	element * ele=alloc_element();
	ele->type=GC_STACK;
	ele->data.gc_stack.tmpele=input;
	global_caller=cons(ele,global_caller);
}
void pop_gc_stack(){
	global_gc=cdr(global_gc);
}
void pop_caller_stack(){
	if(global_caller==empty_list_process){
		global_caller=cdr(cdr(global_caller));
	}else{
		global_caller=cdr(global_caller);
	}
}

element * copy_pair(element * lst){
	if(lst->type==PAIR){
		element * pr1=copy_pair(car(lst));
		element * pr2=copy_pair(cdr(lst));
		return cons(pr1,pr2);
	}else{
		return lst;
	}
}

#ifdef USE_WINDOWS
#include "winop.h"
#endif

element * eval(element * input,element * env){
	element * proc=NULL;
	element * args=NULL;
	element * ret=NULL;
	//write_element(input,stderr);
	//fprintf(stderr,"pushed\n");
	push_gc_stack(&input);
	push_gc_stack(&env);
tailcall_opt:
				if(inner_loop>300000){
					gc_env(env);
					inner_loop=0;
				}else{
					inner_loop++;
				}
	//write_element(input,stdout);
	//printf("\n%lx\n",proc);
	if(is_self_eval(input)){ret=input;goto ret_mark;}
	if(is_tag(input,quote_symbol)) {
		ret=copy_pair(car(cdr(input)));
		goto ret_mark;
	}
	/*
	if(is_tag(input,quasiquote_symbol)){
		//fprintf(stderr,"quasi\n");

		ret=quasiquote_eval(car(cdr(input)),env);
		goto ret_mark;
	}*/
	if(is_tag(input,define_symbol)) {
		if(car(cdr(input))->type==PAIR){
			//write_element(cdr(input),stdout);
			//printf("\n");
			cdr(input)=define2lambda(cdr(input));
			//write_element(input,stdout);
			//printf("\nOK\n");
			//exit(0);

		}
		define_var_in_env(car(cdr(input)),eval(car(cdr(cdr(input))),env),env);
		ret=done_symbol;
		goto ret_mark;
	}
	if(is_tag(input,if_symbol)) {
		if(cdr(input)==empty_list_process || cdr(cdr(input))==empty_list_process||cdr(cdr(cdr(input)))==empty_list_process){
			fprintf(stderr,"Error: if should take 3 expressions!\n");
			write_element(input,stderr);
			
			ERR_REPORT(1);
		}
		if(isfalse(eval(car(cdr(input)),env))){
			input=car(cdr(cdr(cdr(input))));
		}else{
			input=car(cdr(cdr(input)));
			/*
			fprintf(stderr,"ifdebug:");
			write_element(input,stderr);
			fprintf(stderr,"\n");
			*/
		}
		goto tailcall_opt;
	}
	if(is_tag(input,quote_vector_symbol)){
		ret=internal_list_to_vector(cdr(input));
		goto ret_mark;
	}
	if(is_tag(input,macro_symbol)){
		//printf("ok here\n");
		ret=make_macro(car(cdr(input)),cdr(cdr(input)),env);
		goto ret_mark;
	}
	if(is_tag(input,lambda_symbol)){
		ret=make_lambda_proc(car(cdr(input)),cdr(cdr(input)),env);goto ret_mark;
	}
	if(is_tag(input,set_symbol)){
		set_var_in_env(car(cdr(input)),eval(car(cdr(cdr(input))),env),env);
		ret=done_symbol;goto ret_mark;
	}
	if(is_tag(input,cond_symbol)){
		input=expand_cond(cdr(input));
		goto tailcall_opt;
	}
	if(is_tag(input,or_symbol)){
		input=cdr(input);
		if(isempty(input)){
			ret=global_false;goto ret_mark;
		}
		while(!isempty(cdr(input))){
			element * ans=eval(car(input),env);
			if(ans!=global_false){
				ret=ans;goto ret_mark;
			}
			input=cdr(input);
		}
		input=car(input);
		goto tailcall_opt;
	}
	if(is_tag(input,and_symbol)){
		input=cdr(input);
		if(isempty(input)){
			ret=global_true;goto ret_mark;
		}
		while(!isempty(cdr(input))){
			element * res=eval(car(input),env);
			if(res==global_false){
				ret=res;goto ret_mark;
			}
			input=(cdr(input));
		}
		input=car(input);
		goto tailcall_opt;
	}
	/*
	if(is_tag(input,let_symbol)){
		input=cons(cons(lambda_symbol,cons(make_let_var_list(car(cdr(input))),cdr(cdr(input)))),make_let_val_list(car(cdr(input))));
		goto tailcall_opt;
	}*/
	if(is_tag(input,begin_symbol)){
		input=cdr(input);
		while(!isempty(cdr(input))){
			//write_element(car(input),stderr);
			//fprintf(stderr,"\n");
			eval(car(input),env);
			input=cdr(input);
		}
		input=car(input);
		goto tailcall_opt;
	}
	if(input->type==PAIR){
#if SCHEME_DEBUG
			push_caller_stack(&input);
#endif
		{
			element * new_proc=eval(car(input),env);
			push_gc_stack(&new_proc);
			if(new_proc->type==MPROC && new_proc->data.proc==internal_apply){
				new_proc=eval(car(cdr(input)),env);
				//if(new_proc->type==MPROC && new_proc-> data.proc==internal_list)
				args=list2apply_args(cdr(cdr(input)),env);
				if(new_proc->type==MPROC){
					if(new_proc->data.proc==internal_eval){
						input=args;
						goto evalmark;
					}else if(new_proc->data.proc==internal_is_binded){
						input=args;
						goto isbindedmark;
					}else if(new_proc->data.proc==internal_macro_expand){
						input=args;
						goto macroexpandmark;
					}
				}
			}else if(new_proc->type==MPROC && new_proc->data.proc==internal_eval){
				input=eval(car(cdr(input)),env);
evalmark:
				pop_gc_stack();
#if SCHEME_DEBUG
				pop_caller_stack();
#endif
				goto tailcall_opt;
			}else if(new_proc->type==MPROC && new_proc->data.proc==internal_macro_expand){
				input=eval(car(cdr(input)),env);
macroexpandmark:
				new_proc=eval(car(input),env);
				//input=cdr(input);
				//write_element(input,stdout);
				//printf("\n");
				ret=macro_expand(new_proc,input,env);
				pop_gc_stack();
#if SCHEME_DEBUG
				pop_caller_stack();
#endif
				goto ret_mark;
			}else if(new_proc->type==MPROC && new_proc->data.proc==internal_is_binded){
				input=eval(car(cdr(input)),env);
isbindedmark:
				if(find_var_in_env(input,env,1)){
					ret=global_true;
				}else{
					ret=global_false;
				}
				pop_gc_stack();
#if SCHEME_DEBUG
				pop_caller_stack();
#endif
				goto ret_mark;
			}else if(new_proc->type==MACRO){
				//write_element(new_proc->data.macro.paras,stdout);
				//printf("\n");
				//printf("ok here\n");

#if SCHEME_MACRO_DEBUG
				ret=eval(macro_expand(new_proc,input,env),env);
				pop_gc_stack();
				pop_caller_stack();
				goto ret_mark;
#else//SCHEME_MACRO_DEBUG
				input=macro_expand(new_proc,input,env);
				//write_element(input,stdout);
				//printf("\n");
				//exit(1);
				pop_gc_stack();
#if SCHEME_DEBUG
				pop_caller_stack();
#endif//SCHEME_DEBUG

				goto tailcall_opt;
#endif //SCHEME_MACRO_DEBUG
			}else{
				args=get_var_list(cdr(input),env);
				/*
				fprintf(stderr,"dbg:");
				write_element(args,stderr);
				fprintf(stderr,", input=");
				write_element(input,stderr);
				fprintf(stderr,"\n");
				*/
			}
			if(new_proc==proc && proc->type==LAMBDA_PROC && 1)
			{

				element * fstenv=car(env);
				input = proc->data.lambda_proc.body;
				{
					element * var=proc->data.lambda_proc.paras;
					element * val=args;
					element * subenv=fstenv;
					if(0){
						fprintf(stderr,"dbg_tail_rec_opt:");
						fprintf(stderr,", var=");
						write_element(var,stderr);
						fprintf(stderr,", val=");
						write_element(val,stderr);
						fprintf(stderr,", input=");
						write_element(input,stderr);
						fprintf(stderr,"\n");
					}
					while(!isempty(var)){
						if(var->type==PAIR && val->type==PAIR){
							add_binding_in_hashtable(car(var),car(val),(symbol_var_pair**)&subenv->data.else_var);
						}else if(var->type==SYMBOL){
							add_binding_in_hashtable(var,val,(symbol_var_pair**)&subenv->data.else_var);
							break;
						}else{
							fprintf(stderr,"syntax error: var=");
							write_element(var,stderr);
							fprintf(stderr,",val=");
							write_element(val,stderr);
							fprintf(stderr,"\n");
							ERR_REPORT(1);
							//exit(1);
						}
						var=cdr(var);
						val=cdr(val);
					}
				}
				while(!isempty(cdr(input))){
					eval(car(input),env);
					input=cdr(input);
				}
				input=car(input);
				pop_gc_stack();
#if SCHEME_DEBUG
				pop_caller_stack();
#endif
				goto tailcall_opt;
			}
			pop_gc_stack();
			/*
#if SCHEME_DEBUG
			pop_caller_stack();
#endif*/
			proc=new_proc;
		}
		if(proc->type==MPROC){
			ret=proc->data.proc(args);
			//write_element(ret,stdout);
			//fprintf(stdout,"\n");
#if SCHEME_DEBUG
				pop_caller_stack();
#endif
			goto ret_mark;
		}else if(proc->type==LAMBDA_PROC){
			/*
			fprintf(stderr,"dbg_lambda:input=");
			write_element(input,stderr);
			fprintf(stderr,"vars=");
			write_element(proc->data.lambda_proc.paras,stderr);
			fprintf(stderr,"vals=");
			write_element(args,stderr);
			fprintf(stderr,"\n");
			*/
			
			element * subenv=building_subenv_from_var_and_val(proc->data.lambda_proc.paras,args);
			env=extend_env(subenv,proc->data.lambda_proc.env);
			input=proc->data.lambda_proc.body;
			while(!isempty(cdr(input))){
				eval(car(input),env);
				input=cdr(input);
			}
			input=car(input);
			//write_element(input,stdout);
			//printf("\n %lx \n",proc);
#if SCHEME_DEBUG
				pop_caller_stack();
#endif
			goto tailcall_opt;
		}else{
			write_element(input,stderr);
			fprintf(stderr,"\ntype=%d\nproc=",proc->type);
			write_element(proc,stderr);
			fprintf(stderr,"\nInvalid procedure\n");
			ERR_REPORT(1);
			//exit(1);
		}
	}
	if(input->type==SYMBOL){
		ret=find_var_in_env(input,env,0);goto ret_mark;
	}
	write_element(input,stderr);
	fprintf(stderr,"\nunknown expression\n");
	ERR_REPORT(1);
	//exit(1);//assert(!"unknown expression\n");
	//element * newele=alloc_element();
	//printf("eval_input:%lx\n",(long unsigned int)input);
ret_mark:
	pop_gc_stack();
	pop_gc_stack();
	//write_element(input,stderr);
	//fprintf(stderr,"poped\n");
	return ret;
}
element * internal_eval_global(element * input){
	element * var = car (input);
	return eval(var,global_environment);
}

element * get_var_list(element * lst,element * env){
	if(isempty(lst)){
		return empty_list_process;
	}else{
		element * ca=eval(car(lst),env);
		push_gc_stack(&ca);
		element * cd=get_var_list(cdr(lst),env);
		pop_gc_stack();
		return cons(ca,cd);
	}
}
element * get_macro_var_list(element * lst,element * env){
	return lst;
}
/*
element * get_macro_var_list(element * lst,element * env){
	if(isempty(lst)){
		return empty_list_process;
	}else{
		element * ca=quasiquote_eval(car(lst),env);
		push_gc_stack(&ca);
		element * cd=get_macro_var_list(cdr(lst),env);
		pop_gc_stack();
		return cons(ca,cd);
	}
}*/

#include "singlemath.h"
#include "binops.h"
void init_environment(element * global_environment){
#ifdef CSHEME_SINGLEMATH
	init_singlemath(global_environment);
#endif //CSHEME_SINGLEMATH
#ifdef CSCHEME_BIN_OPS
	init_binops(global_environment);
#endif
#ifdef USE_WINDOWS
	init_winop(global_environment);
#endif
	define_var_in_env(makesymbol("+"),makeproc(internal_add),global_environment);
	define_var_in_env(makesymbol("*"),makeproc(internal_mul),global_environment);
	define_var_in_env(makesymbol("-"),makeproc(internal_sub),global_environment);
	define_var_in_env(makesymbol("/"),makeproc(internal_div),global_environment);
	define_var_in_env(makesymbol("quotient"),makeproc(internal_quotient),global_environment);
	define_var_in_env(makesymbol("remainder"),makeproc(internal_remainder),global_environment);
	define_var_in_env(makesymbol("bitwise-and"),makeproc(internal_bitwise_and),global_environment);
	define_var_in_env(makesymbol("arithmetic-shift"),makeproc(internal_arithmetic_shift),global_environment);
	define_var_in_env(makesymbol("car"),makeproc(internal_car),global_environment);
	define_var_in_env(makesymbol("set-car!"),makeproc(internal_set_car),global_environment);
	define_var_in_env(makesymbol("set-cdr!"),makeproc(internal_set_cdr),global_environment);
	define_var_in_env(makesymbol("cdr"),makeproc(internal_cdr),global_environment);
	define_var_in_env(makesymbol("cons"),makeproc(internal_cons),global_environment);
	define_var_in_env(makesymbol(">="),makeproc(internal_is_greater_than_or_eq),global_environment);
	define_var_in_env(makesymbol("<="),makeproc(internal_is_less_than_or_eq),global_environment);
	define_var_in_env(makesymbol(">"),makeproc(internal_is_greater_than),global_environment);
	define_var_in_env(makesymbol("<"),makeproc(internal_is_less_than),global_environment);
	define_var_in_env(makesymbol("eq?"),makeproc(internal_is_eq),global_environment);
	define_var_in_env(makesymbol("="),makeproc(internal_is_eq),global_environment);
	define_var_in_env(makesymbol("number?"),makeproc(internal_is_number),global_environment);
	define_var_in_env(makesymbol("vector?"),makeproc(internal_is_vector),global_environment);
	define_var_in_env(makesymbol("fixnum?"),makeproc(internal_is_fixnum),global_environment);
	define_var_in_env(makesymbol("float?"),makeproc(internal_is_float),global_environment);
	define_var_in_env(makesymbol("macro?"),makeproc(internal_is_macro),global_environment);
	define_var_in_env(makesymbol("lambda?"),makeproc(internal_is_lambda),global_environment);
	define_var_in_env(makesymbol("primitive-proc?"),makeproc(internal_is_primitive),global_environment);
	define_var_in_env(makesymbol("even?"),makeproc(internal_is_even),global_environment);
	define_var_in_env(makesymbol("odd?"),makeproc(internal_is_odd),global_environment);
	define_var_in_env(makesymbol("null?"),makeproc(internal_is_empty),global_environment);
	define_var_in_env(makesymbol("symbol-binded?"),makeproc(internal_is_binded),global_environment);
	define_var_in_env(makesymbol("pair?"),makeproc(internal_is_pair),global_environment);
	define_var_in_env(makesymbol("apply"),makeproc(internal_apply),global_environment);
	define_var_in_env(makesymbol("eval"),makeproc(internal_eval),global_environment);
	define_var_in_env(makesymbol("eval-global"),makeproc(internal_eval_global),global_environment);
	define_var_in_env(makesymbol("macroexpand"),makeproc(internal_macro_expand),global_environment);
	define_var_in_env(makesymbol("list"),makeproc(internal_list),global_environment);
	define_var_in_env(makesymbol("system"),makeproc(internal_system),global_environment);
	define_var_in_env(makesymbol("close-input-port"),makeproc(internal_close_input_port),global_environment);
	define_var_in_env(makesymbol("close-output-port"),makeproc(internal_close_output_port),global_environment);
	define_var_in_env(makesymbol("internal-fflush-port"),makeproc(internal_fflush_port),global_environment);
	define_var_in_env(makesymbol("open-input-file"),makeproc(internal_open_input_file),global_environment);
	define_var_in_env(makesymbol("open-output-file"),makeproc(internal_open_output_file),global_environment);
	define_var_in_env(makesymbol("input-port?"),makeproc(internal_is_input_port),global_environment);
	define_var_in_env(makesymbol("output-port?"),makeproc(internal_is_output_port),global_environment);
	define_var_in_env(makesymbol("eof-object?"),makeproc(internal_is_eof_object),global_environment);
	define_var_in_env(makesymbol("alpha?"),makeproc(internal_is_alpha),global_environment);
	define_var_in_env(makesymbol("boolean?"),makeproc(internal_is_bool),global_environment);
	define_var_in_env(makesymbol("char?"),makeproc(internal_is_char),global_environment);
	define_var_in_env(makesymbol("symbol?"),makeproc(internal_is_symbol),global_environment);
	define_var_in_env(makesymbol("string?"),makeproc(internal_is_string),global_environment);
	define_var_in_env(makesymbol("string->symbol"),makeproc(internal_str2symbol),global_environment);
	define_var_in_env(makesymbol("gensym"),makeproc(internal_gensym),global_environment);
	define_var_in_env(makesymbol("args-of-lambda"),makeproc(internal_args_of_lambda),global_environment);
	define_var_in_env(makesymbol("body-of-lambda"),makeproc(internal_body_of_lambda),global_environment);
	define_var_in_env(makesymbol("symbol->string"),makeproc(internal_symbol2str),global_environment);
	define_var_in_env(makesymbol("string->list"),makeproc(internal_str2list),global_environment);
	define_var_in_env(makesymbol("list->string"),makeproc(internal_list2str),global_environment);
	define_var_in_env(makesymbol("string->number"),makeproc(internal_str2num),global_environment);
	define_var_in_env(makesymbol("number->string"),makeproc(internal_num2str),global_environment);
	define_var_in_env(makesymbol("load"),makeproc(internal_load),global_environment);
	define_var_in_env(makesymbol("iread"),makeproc(internal_read),global_environment);
	define_var_in_env(makesymbol("iread-char"),makeproc(internal_read_char),global_environment);
	define_var_in_env(makesymbol("ipeek-char"),makeproc(internal_peek_char),global_environment);
	define_var_in_env(makesymbol("iwrite"),makeproc(internal_write),global_environment);
	define_var_in_env(makesymbol("set-float-mode"),makeproc(internal_set_float_mode),global_environment);
	define_var_in_env(makesymbol("iwrite-char"),makeproc(internal_write_char),global_environment);
	define_var_in_env(makesymbol("iwrite-string"),makeproc(internal_write_string),global_environment);
	define_var_in_env(makesymbol("concat"),makeproc(internal_concat),global_environment);
	define_var_in_env(makesymbol("vector-ref"),makeproc(internal_vec_ref),global_environment);
	define_var_in_env(makesymbol("vector-set!"),makeproc(internal_vec_set),global_environment);
	define_var_in_env(makesymbol("make-vector"),makeproc(internal_make_vector),global_environment);
	define_var_in_env(makesymbol("vector-length"),makeproc(internal_vector_length),global_environment);
	define_var_in_env(makesymbol("vector"),makeproc(internal_vector),global_environment);
	define_var_in_env(makesymbol("internal-make-single-env-from-var-and-val"),makeproc(make_single_env_from_var_and_val),global_environment);
	define_var_in_env(makesymbol("add-binding-in-single-env"),makeproc(add_binding_in_single_env),global_environment);
	define_var_in_env(makesymbol("internal-find-var-in-single-env"),makeproc(internal_find_var_in_single_env),global_environment);
	define_var_in_env(makesymbol("icurrent-input-port"),make_i_port(stdin),global_environment);
	define_var_in_env(makesymbol("icurrent-output-port"),make_o_port(stdout),global_environment);
	define_var_in_env(makesymbol("icurrent-error-port"),make_o_port(stderr),global_environment);
}

void init(){
	empty_list_process=alloc_element();
	empty_list_process->type=EMPTYLIST;
	symbol_table=empty_list_process;
	symbol_table_len=0;
	quote_symbol=makesymbol("quote");
	quasiquote_symbol=makesymbol("quasiquote");
	unquote_symbol=makesymbol("unquote");
	quote_vector_symbol=makesymbol("quote-vector");
	define_symbol=makesymbol("define");
	done_symbol=makesymbol("done");
	if_symbol=makesymbol("if");
	begin_symbol=makesymbol("begin");
	cond_symbol=makesymbol("cond");
	else_symbol=makesymbol("else");
	lambda_symbol=makesymbol("lambda");
	macro_symbol=makesymbol("macro");
	//lispmacro_symbol=makesymbol("lispmacro");
	//eof_object_symbol=makesymbol("eof-object");
	set_symbol=makesymbol("set!");
	let_symbol=makesymbol("let");
	and_symbol=makesymbol("and");
	or_symbol=makesymbol("or");

	global_gc=empty_list_process;
	global_caller=empty_list_process;
	global_true=alloc_element();
	global_true->type=MBOOLEAN;
	global_true->data.boolean=1;
	global_false=alloc_element();
	global_false->type=MBOOLEAN;
	global_false->data.boolean=0;
	global_eof=alloc_element();
	global_eof->type=EOF_OBJECT;
	//push_gc_stack(global_eof

	empty_environment=empty_list_process;
	global_environment=init_env();
	init_environment(global_environment);
}

//const char initfile[]="/home/xiaojianyuan/cxx/cscheme/usable/stdlib.scm";

int repl_proc(){
	while (1){
		int err=setjmp(global_jump_env);
		gc();
		fprintf(stderr,"\n> ");
		element * input=read_element(stdin);
		//global_gc=cons(input,global_gc);
		if(input==global_eof)break;
		write_element(eval(input,global_environment),stderr);
		//global_gc=cdr(global_gc);
		//sleep(1);
		//dump_debug(root_dependency);
		//fprintf(stderr,"\ndumped\n\n");
		//write_element(global_gc,stderr);
		//fprintf(stderr,"\n");
		//write_element(global_gc,stderr);
		//fprintf(stderr,"\n");
		//dump_debug(root_dependency);
		//del_element(input);
	}
}


#ifdef CSCHEME_MAIN_PROC
int main_proc(int argc,char * argv[]){
#else
int main(int argc,char * argv[]){
#endif
	if(argc<2){
		fprintf(stderr,"This is a simple scheme interpreter");
	}
	init();
	{
		char * initfile=getenv("STDLIB");
		//puts(initfile);
		FILE * fp=fopen(initfile,"r");
		if(fp){
			element * expr;
			while((expr=read_element(fp))!=global_eof){
				eval(expr,global_environment); 
				int err=setjmp(global_jump_env);
			}
			fclose(fp);
		}else{
			fprintf(stderr,"Unable to open %s\n",initfile);
		}
	}
	//return 0;
	//dump_debug(root_dependency);
	//fprintf(stderr,"dumped\n\n");
	if(argc>=2){
		int ac=1;
		for(ac=1;ac<argc;ac++){
			FILE * fp=fopen(argv[ac],"r");
			if(fp){
				element * expr;
				while((expr=read_element(fp))!=global_eof){
					eval(expr,global_environment); 
					int err=setjmp(global_jump_env);
					if (err){
						exit(err);
					}
				}
				fclose(fp);
			}else{
				fprintf(stderr,"Unable to open %s\n",argv[ac]);
			}
		}
	}else{
		repl_proc();
	}
	return 0;
}

