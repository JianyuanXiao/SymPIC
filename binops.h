#ifndef CSCHEME_BIN_OPS
#define CSCHEME_BIN_OPS
typedef long MINT;
typedef double MFLOAT;
int bin_write_to_file(element * ele,FILE * out , int flag){
	if(ele==NULL){
		return 0;
	}
	switch(ele->type){
		case INTNUM:
			if(flag==0){
				return sizeof(MINT)*fwrite(&ele->data.intnum,sizeof(MINT),1,out);
			}else if(flag==1){
				int dat=ele->data.intnum;
				return sizeof(int)*fwrite(&dat,sizeof(int),1,out);
			}else{
				fprintf(out,"%lx",ele->data.intnum);
			}
			return sizeof(MINT);
			break;
		case MFLOATNUM:
			fwrite(&ele->data.floatnum,sizeof(MFLOAT),1,out);
			return sizeof(MFLOAT);
			break;
		case MCHAR:
			if(flag==0){
				fwrite(&ele->data.char_var,sizeof(char),1,out);
			}else{
				fprintf(out,"%x",ele->data.char_var);
			}
			return sizeof(char);
			break;
		default:
			break;
	}
	return 0;
}
element * internal_bin_write(element * input){
	element * ele=car(input);
	input=cdr(input);
	FILE * out_port=(input==empty_list_process) ? stdout:car(input)->data.in_port.in_port;
	if(out_port!=stdout && car(input)->data.in_port.isclose){
		fprintf(stderr,"Error in write: output-port 0x%lx closed\n",car(input)->data.in_port.in_port);
		ERR_REPORT(1);
		//exit(1);
	}
	int ret=bin_write_to_file(ele,out_port,0);
	return makeint(ret);
}
element * internal_bin_write32(element * input){
	element * ele=car(input);
	input=cdr(input);
	FILE * out_port=(input==empty_list_process) ? stdout:car(input)->data.in_port.in_port;
	if(out_port!=stdout && car(input)->data.in_port.isclose){
		fprintf(stderr,"Error in write: output-port 0x%lx closed\n",car(input)->data.in_port.in_port);
		ERR_REPORT(1);
		//exit(1);
	}
	int ret=bin_write_to_file(ele,out_port,1);
	return makeint(ret);
}
element * internal_hex_write(element * input){
	element * ele=car(input);
	input=cdr(input);
	FILE * out_port=(input==empty_list_process) ? stdout:car(input)->data.in_port.in_port;
	if(out_port!=stdout && car(input)->data.in_port.isclose){
		fprintf(stderr,"Error in write: output-port 0x%lx closed\n",car(input)->data.in_port.in_port);
		ERR_REPORT(1);
		//exit(1);
	}
	int ret=bin_write_to_file(ele,out_port,2);
	return makeint(ret);
}
element * internal_int2char(element * input){
	element * ele=car(input);
	if(ele->type==INTNUM){
		element * ans=makechar(ele->data.intnum);
		return  ans;
	}else{
		fprintf(stderr,"Error in int2char: not a integer\n");
		ERR_REPORT(1);
	}
	return ele;
}
element * internal_char2int(element * input){
	element * ele=car(input);
	if(ele->type==MCHAR){
		element * ans=makeint(ele->data.char_var);
		return  ans;
	}else{
		fprintf(stderr,"Error in char2int: not a character\n");
		ERR_REPORT(1);
	}
	return ele;
}
element * internal_float2int(element * input){
	element * ele=car(input);
	if(ele->type==MFLOATNUM){
		element * ans=makeint(ele->data.intnum);
		return  ans;
	}else{
		fprintf(stderr,"Error in float2int: not a float num\n");
		ERR_REPORT(1);
	}
	return ele;
}
element * internal_integer_floor(element * input){
	element * ele=car(input);
	if(ele->type==MFLOATNUM){
		element * ans=makeint(floor(ele->data.floatnum));
		return  ans;
	}else{
		fprintf(stderr,"Error in float2int: not a float num\n");
		ERR_REPORT(1);
	}
	return ele;
}
void init_binops(element * global_env){
	define_var_in_env(makesymbol("bin-write"),makeproc(internal_bin_write),global_env);
	define_var_in_env(makesymbol("bin-write32"),makeproc(internal_bin_write32),global_env);
	define_var_in_env(makesymbol("hex-write"),makeproc(internal_hex_write),global_env);
	define_var_in_env(makesymbol("float2int"),makeproc(internal_float2int),global_env);
	define_var_in_env(makesymbol("char2int"),makeproc(internal_char2int),global_env);
	define_var_in_env(makesymbol("int2char"),makeproc(internal_int2char),global_env);
	define_var_in_env(makesymbol("integer-floor"),makeproc(internal_integer_floor),global_env);
}
#endif
