#ifndef CSHEME_SINGLEMATH
#define CSHEME_SINGLEMATH
element * internal_sin(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=sin(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=sin(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_cos(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=cos(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=cos(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_tan(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=tan(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=tan(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_asin(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=asin(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=asin(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_acos(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=acos(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=acos(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_atan(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=atan(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=atan(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_sqrt(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=sqrt(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=sqrt(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_cbrt(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=cbrt(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=cbrt(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_erf(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=erf(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=erf(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_erfc(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=erfc(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=erfc(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_fabs(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=fabs(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=fabs(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_j0(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=j0(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=j0(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_j1(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=j1(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=j1(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_exp(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=exp(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=exp(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_sinh(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=sinh(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=sinh(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_cosh(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=cosh(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=cosh(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_tanh(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=tanh(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=tanh(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_asinh(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=asinh(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=asinh(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_acosh(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=acosh(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=acosh(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_atanh(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=atanh(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=atanh(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_y0(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=y0(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=y0(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_y1(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=y1(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=y1(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_expm1(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=expm1(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=expm1(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_exp2(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=exp2(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=exp2(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_floor(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=floor(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=floor(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_ceil(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=ceil(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=ceil(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_log(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=log(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=log(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_log10(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	if(car(ele)->type==MFLOATNUM){
		ans->data.floatnum=log10(car(ele)->data.floatnum);
	}
	if(car(ele)->type==INTNUM){
		ans->data.floatnum=log10(car(ele)->data.intnum);
	}
	return ans;
}
element * internal_pow(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	element * in1=car(ele);
	element * in2=car(cdr(ele));
	if(in1->type==MFLOATNUM){
		if(in2->type==MFLOATNUM){
			ans->data.floatnum=pow(in1->data.floatnum,in2->data.floatnum);
		}
		else if(in2->type==INTNUM){
			ans->data.floatnum=pow(in1->data.floatnum,in2->data.intnum);
		}
	}
	else if(in1->type==INTNUM){
		if(in2->type==MFLOATNUM){
			ans->data.floatnum=pow(in1->data.intnum,in2->data.floatnum);
		}else if(in2->type==INTNUM){
			ans->data.floatnum=pow(in1->data.intnum,in2->data.intnum);
		}
	}
	return ans;
}
element * internal_atan2(element * ele){
	element * ans=alloc_element();
	ans->type=MFLOATNUM;
	element * in1=car(ele);
	element * in2=car(cdr(ele));
	if(in1->type==MFLOATNUM){
		if(in2->type==MFLOATNUM){
			ans->data.floatnum=atan2(in1->data.floatnum,in2->data.floatnum);
		}
		else if(in2->type==INTNUM){
			ans->data.floatnum=atan2(in1->data.floatnum,in2->data.intnum);
		}
	}
	else if(in1->type==INTNUM){
		if(in2->type==MFLOATNUM){
			ans->data.floatnum=atan2(in1->data.intnum,in2->data.floatnum);
		}else if(in2->type==INTNUM){
			ans->data.floatnum=atan2(in1->data.intnum,in2->data.intnum);
		}
	}
	return ans;
}
void init_singlemath(element * global_environment){
define_var_in_env(makesymbol("sin"),makeproc(internal_sin),global_environment);
define_var_in_env(makesymbol("cos"),makeproc(internal_cos),global_environment);
define_var_in_env(makesymbol("tan"),makeproc(internal_tan),global_environment);
define_var_in_env(makesymbol("asin"),makeproc(internal_asin),global_environment);
define_var_in_env(makesymbol("acos"),makeproc(internal_acos),global_environment);
define_var_in_env(makesymbol("atan"),makeproc(internal_atan),global_environment);
define_var_in_env(makesymbol("sqrt"),makeproc(internal_sqrt),global_environment);
define_var_in_env(makesymbol("cbrt"),makeproc(internal_cbrt),global_environment);
define_var_in_env(makesymbol("erf"),makeproc(internal_erf),global_environment);
define_var_in_env(makesymbol("erfc"),makeproc(internal_erfc),global_environment);
define_var_in_env(makesymbol("fabs"),makeproc(internal_fabs),global_environment);
define_var_in_env(makesymbol("j0"),makeproc(internal_j0),global_environment);
define_var_in_env(makesymbol("j1"),makeproc(internal_j1),global_environment);
define_var_in_env(makesymbol("exp"),makeproc(internal_exp),global_environment);
define_var_in_env(makesymbol("sinh"),makeproc(internal_sinh),global_environment);
define_var_in_env(makesymbol("cosh"),makeproc(internal_cosh),global_environment);
define_var_in_env(makesymbol("tanh"),makeproc(internal_tanh),global_environment);
define_var_in_env(makesymbol("asinh"),makeproc(internal_asinh),global_environment);
define_var_in_env(makesymbol("acosh"),makeproc(internal_acosh),global_environment);
define_var_in_env(makesymbol("atanh"),makeproc(internal_atanh),global_environment);
define_var_in_env(makesymbol("y0"),makeproc(internal_y0),global_environment);
define_var_in_env(makesymbol("y1"),makeproc(internal_y1),global_environment);
define_var_in_env(makesymbol("expm1"),makeproc(internal_expm1),global_environment);
define_var_in_env(makesymbol("exp2"),makeproc(internal_exp2),global_environment);
define_var_in_env(makesymbol("floor"),makeproc(internal_floor),global_environment);
define_var_in_env(makesymbol("ceil"),makeproc(internal_ceil),global_environment);
define_var_in_env(makesymbol("log"),makeproc(internal_log),global_environment);
define_var_in_env(makesymbol("log10"),makeproc(internal_log10),global_environment);
define_var_in_env(makesymbol("pow"),makeproc(internal_pow),global_environment);
define_var_in_env(makesymbol("atan2"),makeproc(internal_atan2),global_environment);
}
#endif //CSHEME_SINGLEMATH
