#ifndef CSCHEME_HEAD
#define CSCHEME_HEAD
typedef enum {INTNUM,FLOATNUM,BOOLEAN,CHAR,STRING,EMPTYLIST,ELSE,PAIR,SYMBOL,PROC,LAMBDA_PROC,INPUT_PORT,OUTPUT_PORT,EOF_OBJECT,MACRO,VECTOR,GC_STACK,USER_DEFINED0} ele_type;
typedef enum {INTVEC,FLOATVEC,GENERALVEC,NULLVEC} vec_type;

typedef struct element
{
	ele_type type;
	union{
		long intnum;
		double floatnum;
		char boolean;
		char char_var;
		char * string_var;
		void * else_var;
		struct {
			char * symbolname;
			long symbol_id;
		}symbol;
		struct{
			struct element * car;
			struct element * cdr;
			char istail;
		}pair;
		long var_name_hashed;
		struct{
			struct element * paras;
			struct element * body;
			struct element * env;
		}lambda_proc;
		struct{
			struct element * paras;
			struct element * body;
			struct element * env;
		}macro;
		struct{
			vec_type type;
			long vec_len;
			union{
				struct element ** p_general;
				long * p_int;
				double * p_float;
			}vector_data;
		}vector;
		struct {
			struct element ** tmpele;
		}gc_stack;
		struct element * (*proc)(struct element *);
		struct{
			FILE * in_port;
			char isclose;
		}in_port;
		struct{
			void * user_data;
		}user_defined;
		struct{
			FILE * out_port;
			char isclose;
		}out_port;
	}data;
	void * p_al;
}element;

typedef struct allocated_list{
	struct allocated_list * prev;
	element * curr;
	struct allocated_list * next;
	char using;
}allocated_list;

typedef struct {
	long symbol_id;
	//char * symbolname;
	//element * symbol;
	element * value;
	UT_hash_handle hh;
}symbol_var_pair;

void free_hashtable(symbol_var_pair * hashtable)
;
void remove_hashtable(symbol_var_pair * hashtable)
;
void write_element(element * ele,FILE *out);
;
void del_element(element * ele)
;
void cal_dependency(element * ele);
;
void cal_dependency_hashtable(symbol_var_pair * hashtable)
;
void cal_dependency(element * ele)
;
void remove_element(element * ele)
;
void clean_gc()
;
void dump_debug(allocated_list * p_al)
;
void gc_env(element * env)
;
void gc()
;
int isdelimiter(int c)
;
int delete_void_char(FILE * in)
;
int first_char(FILE * in)
;
void read_buf(FILE * in)
;
int isint_or_float(const char * buf) //int=1, float=2, other=0
;
int isempty(element * ele)
;
int islist(element * ele)
;
int isfalse(element * ele)
;
int issymbol_char(int c)
;
int escape_char(int in)
;
int string_escape_copy(char * dst,char * src,size_t n)
;
int dec_is_slash(char * str,int cur_i)
;
void write_pair(element * ele,FILE * out)
;
void write_string_to_file(char * str , FILE * out)
;
void write_element(element * ele,FILE *out)
;
int is_self_eval(element * ele)
;
int is_tag(element * ele,element * tag)
;
void set_var_in_env(element * var,element *val,element *env)
;
void define_var_in_env(element * var,element *val, element *env)
;
long length_of_list(element * input)
;
void internal_vec_expand_float(element * ele)
;
void internal_vec_expand_int(element * ele)
;
void push_gc_stack(element ** input);
;
void pop_gc_stack();
;
vec_type get_list_vector_element_type(element * input)
;
vec_type get_list_vector_type(vec_type currenttype,element * input)
;
void push_gc_stack(element ** input)
;
void push_caller_stack(element ** input)
;
void pop_gc_stack()
;
void pop_caller_stack()
;
void init_environment(element * global_environment)
;
void init()
;
int repl_proc()
;
int main_proc(int argc,char * argv[])
;
#endif
