	#ifndef   openmp_PSCMC_OMP_INC    
		
#define openmp_PSCMC_OMP_INC
	#ifndef   PSCMC_TYPES    
		
#define PSCMC_TYPES

typedef enum {PS_INT_NUM,PS_LONG_NUM,PS_FLOAT_NUM,PS_DOUBLE_NUM,PS_CHAR,PS_SHORT_NUM} pscmc_data_types;

	#else
		
	 #endif
typedef struct { 	int  num_threads ;
} openmp_pscmc_env;typedef struct { 	char *  d_data ;
	char *  h_data ;
	int  type ;
	size_t  len ;
} openmp_pscmc_mem;
	#else
		
	 #endif
