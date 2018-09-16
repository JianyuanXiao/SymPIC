#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "local_header.h"
	#ifndef   c_PSCMC_C_INC    
		
#define c_PSCMC_C_INC
	#ifndef   PSCMC_TYPES    
		
#define PSCMC_TYPES

typedef enum {PS_INT_NUM,PS_LONG_NUM,PS_FLOAT_NUM,PS_DOUBLE_NUM,PS_CHAR,PS_SHORT_NUM} pscmc_data_types;

	#else
		
	 #endif
typedef struct { 	int  num_threads ;
} c_pscmc_env;typedef struct { 	char *  d_data ;
	char *  h_data ;
	int  type ;
	size_t  len ;
} c_pscmc_mem;
	#else
		
	 #endif
int  c_pscmc_mem_init (c_pscmc_env *  pe ,c_pscmc_mem *  pm ,int  type ,size_t  len ){
(pm->len = len);
	if (  	(  len == 0 )  ){  
		(len = 1);

	}else{
		0;

	 }
	size_t  datasize ;
	if (  	(  type == PS_INT_NUM )  ){  
		(datasize = 	(  len * sizeof(int ) ));

	}else{
			if (  	(  type == PS_LONG_NUM )  ){  
		(datasize = 	(  len * sizeof(long ) ));

	}else{
			if (  	(  type == PS_FLOAT_NUM )  ){  
		(datasize = 	(  len * sizeof(float ) ));

	}else{
			if (  	(  type == PS_DOUBLE_NUM )  ){  
		(datasize = 	(  len * sizeof(double ) ));

	}else{
			if (  	(  type == PS_SHORT_NUM )  ){  
		(datasize = 	(  len * sizeof(short ) ));

	}else{
			if (  	(  type == PS_CHAR )  ){  
		(datasize = 	(  len * sizeof(char ) ));

	}else{
			fprintf ( stderr , "Error: unknown type in init_pscmc_mem: type=%d\n" , type );

	 }

	 }

	 }

	 }

	 }

	 }
(pm->d_data = 	malloc ( datasize ));
(pm->h_data = pm->d_data);
	return  0 ;}
int  c_pscmc_flush (c_pscmc_env *  pe ){
	return  0 ;}
void *  c_pscmc_get_h_data (c_pscmc_mem *  pm ,void * *  h_data ){
	if (  	(  h_data != NULL )  ){  
		((h_data)[0] = pm->h_data);

	}else{
		0;

	 }
	return  pm->h_data ;}
int  c_pscmc_get_env_len (size_t *  l ){
((l)[0] = sizeof(c_pscmc_env ));
	return  0 ;}
int  c_pscmc_get_local_len (){
	return  1 ;}
int  c_pscmc_mem_destroy (c_pscmc_mem *  pm ){
	free ( pm->d_data );
	return  0 ;}
int  c_pscmc_mem_sync_d2h (c_pscmc_mem *  pm ){
	return  0 ;}
int  c_pscmc_mem_sync_h2d (c_pscmc_mem *  pm ){
	return  0 ;}
int  c_pscmc_env_init (c_pscmc_env *  pe ,int  dev_num ,void *  fv ){
	return  0 ;}
size_t  c_pscmc_mem_get_num (c_pscmc_mem *  pm ){
	return  pm->len ;}
