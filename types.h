typedef enum {INTNUM,MFLOATNUM,MBOOLEAN,MCHAR,STRING,EMPTYLIST,ELSE,PAIR,SYMBOL,MPROC,LAMBDA_PROC,INPUT_PORT,OUTPUT_PORT,EOF_OBJECT,MACRO,VECTOR,GC_STACK,USER_DEFINED0} ele_type;
typedef enum {INTVEC,MFLOATVEC,GENERALVEC,NULLVEC} vec_type;

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

