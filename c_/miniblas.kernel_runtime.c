#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "c_pscmc_inc.h"
#include "miniblas.kernel_inc.h"
int  c_blas_sum_init (c_pscmc_env *  pe ,c_blas_sum_struct *  kerstr ){
	return  0 ;}
void  c_blas_sum_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_blas_sum_struct ));
}
int  c_blas_sum_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_blas_sum_get_num_compute_units (c_blas_sum_struct *  kerstr ){
	return  1 ;}
int  c_blas_sum_exec (c_blas_sum_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_blas_sum_scmc_kernel ( 	( kerstr )->y , 	( kerstr )->rdcd , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_blas_sum_scmc_set_parameter_y (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  c_blas_sum_scmc_set_parameter_rdcd (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->rdcd = pm->d_data);
}
int  c_blas_sum_scmc_set_parameter_y_cpu_core (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_blas_sum_scmc_set_parameter_numvec (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_blas_sum_scmc_set_parameter_XLEN (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_blas_sum_scmc_set_parameter_YLEN (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_blas_sum_scmc_set_parameter_ZLEN (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_blas_sum_scmc_set_parameter_ovlp (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_blas_sum_scmc_set_parameter_xblock (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_blas_sum_scmc_set_parameter_yblock (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_blas_sum_scmc_set_parameter_zblock (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_blas_sum_scmc_set_parameter_num_ele (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_blas_dot_init (c_pscmc_env *  pe ,c_blas_dot_struct *  kerstr ){
	return  0 ;}
void  c_blas_dot_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_blas_dot_struct ));
}
int  c_blas_dot_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_blas_dot_get_num_compute_units (c_blas_dot_struct *  kerstr ){
	return  1 ;}
int  c_blas_dot_exec (c_blas_dot_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_blas_dot_scmc_kernel ( 	( kerstr )->y , 	( kerstr )->x , 	( kerstr )->rdcd , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_blas_dot_scmc_set_parameter_y (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  c_blas_dot_scmc_set_parameter_x (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->x = pm->d_data);
}
int  c_blas_dot_scmc_set_parameter_rdcd (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->rdcd = pm->d_data);
}
int  c_blas_dot_scmc_set_parameter_y_cpu_core (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_blas_dot_scmc_set_parameter_numvec (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_blas_dot_scmc_set_parameter_XLEN (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_blas_dot_scmc_set_parameter_YLEN (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_blas_dot_scmc_set_parameter_ZLEN (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_blas_dot_scmc_set_parameter_ovlp (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_blas_dot_scmc_set_parameter_xblock (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_blas_dot_scmc_set_parameter_yblock (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_blas_dot_scmc_set_parameter_zblock (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_blas_dot_scmc_set_parameter_num_ele (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_blas_findmax_init (c_pscmc_env *  pe ,c_blas_findmax_struct *  kerstr ){
	return  0 ;}
void  c_blas_findmax_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_blas_findmax_struct ));
}
int  c_blas_findmax_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_blas_findmax_get_num_compute_units (c_blas_findmax_struct *  kerstr ){
	return  1 ;}
int  c_blas_findmax_exec (c_blas_findmax_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_blas_findmax_scmc_kernel ( 	( kerstr )->y , 	( kerstr )->rdcd , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_blas_findmax_scmc_set_parameter_y (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  c_blas_findmax_scmc_set_parameter_rdcd (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->rdcd = pm->d_data);
}
int  c_blas_findmax_scmc_set_parameter_y_cpu_core (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_blas_findmax_scmc_set_parameter_numvec (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_blas_findmax_scmc_set_parameter_XLEN (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_blas_findmax_scmc_set_parameter_YLEN (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_blas_findmax_scmc_set_parameter_ZLEN (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_blas_findmax_scmc_set_parameter_ovlp (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_blas_findmax_scmc_set_parameter_xblock (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_blas_findmax_scmc_set_parameter_yblock (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_blas_findmax_scmc_set_parameter_zblock (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_blas_findmax_scmc_set_parameter_num_ele (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_blas_mulxy_init (c_pscmc_env *  pe ,c_blas_mulxy_struct *  kerstr ){
	return  0 ;}
void  c_blas_mulxy_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_blas_mulxy_struct ));
}
int  c_blas_mulxy_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_blas_mulxy_get_num_compute_units (c_blas_mulxy_struct *  kerstr ){
	return  1 ;}
int  c_blas_mulxy_exec (c_blas_mulxy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_blas_mulxy_scmc_kernel ( 	( kerstr )->y , 	( kerstr )->x , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_blas_mulxy_scmc_set_parameter_y (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  c_blas_mulxy_scmc_set_parameter_x (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->x = pm->d_data);
}
int  c_blas_mulxy_scmc_set_parameter_y_cpu_core (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_blas_mulxy_scmc_set_parameter_numvec (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_blas_mulxy_scmc_set_parameter_XLEN (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_blas_mulxy_scmc_set_parameter_YLEN (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_blas_mulxy_scmc_set_parameter_ZLEN (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_blas_mulxy_scmc_set_parameter_ovlp (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_blas_mulxy_scmc_set_parameter_xblock (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_blas_mulxy_scmc_set_parameter_yblock (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_blas_mulxy_scmc_set_parameter_zblock (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_blas_mulxy_scmc_set_parameter_num_ele (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_blas_axpby_init (c_pscmc_env *  pe ,c_blas_axpby_struct *  kerstr ){
	return  0 ;}
void  c_blas_axpby_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_blas_axpby_struct ));
}
int  c_blas_axpby_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_blas_axpby_get_num_compute_units (c_blas_axpby_struct *  kerstr ){
	return  1 ;}
int  c_blas_axpby_exec (c_blas_axpby_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_blas_axpby_scmc_kernel ( 	( kerstr )->y , 	( kerstr )->x , (	( kerstr )->a)[0] , (	( kerstr )->b)[0] , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_blas_axpby_scmc_set_parameter_y (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  c_blas_axpby_scmc_set_parameter_x (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->x = pm->d_data);
}
int  c_blas_axpby_scmc_set_parameter_a (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->a = pm->d_data);
}
int  c_blas_axpby_scmc_set_parameter_b (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->b = pm->d_data);
}
int  c_blas_axpby_scmc_set_parameter_y_cpu_core (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_blas_axpby_scmc_set_parameter_numvec (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_blas_axpby_scmc_set_parameter_XLEN (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_blas_axpby_scmc_set_parameter_YLEN (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_blas_axpby_scmc_set_parameter_ZLEN (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_blas_axpby_scmc_set_parameter_ovlp (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_blas_axpby_scmc_set_parameter_xblock (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_blas_axpby_scmc_set_parameter_yblock (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_blas_axpby_scmc_set_parameter_zblock (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_blas_axpby_scmc_set_parameter_num_ele (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_blas_axpy_init (c_pscmc_env *  pe ,c_blas_axpy_struct *  kerstr ){
	return  0 ;}
void  c_blas_axpy_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_blas_axpy_struct ));
}
int  c_blas_axpy_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_blas_axpy_get_num_compute_units (c_blas_axpy_struct *  kerstr ){
	return  1 ;}
int  c_blas_axpy_exec (c_blas_axpy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_blas_axpy_scmc_kernel ( 	( kerstr )->y , 	( kerstr )->x , (	( kerstr )->a)[0] , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_blas_axpy_scmc_set_parameter_y (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  c_blas_axpy_scmc_set_parameter_x (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->x = pm->d_data);
}
int  c_blas_axpy_scmc_set_parameter_a (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->a = pm->d_data);
}
int  c_blas_axpy_scmc_set_parameter_y_cpu_core (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_blas_axpy_scmc_set_parameter_numvec (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_blas_axpy_scmc_set_parameter_XLEN (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_blas_axpy_scmc_set_parameter_YLEN (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_blas_axpy_scmc_set_parameter_ZLEN (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_blas_axpy_scmc_set_parameter_ovlp (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_blas_axpy_scmc_set_parameter_xblock (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_blas_axpy_scmc_set_parameter_yblock (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_blas_axpy_scmc_set_parameter_zblock (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_blas_axpy_scmc_set_parameter_num_ele (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_blas_yisax_init (c_pscmc_env *  pe ,c_blas_yisax_struct *  kerstr ){
	return  0 ;}
void  c_blas_yisax_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_blas_yisax_struct ));
}
int  c_blas_yisax_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_blas_yisax_get_num_compute_units (c_blas_yisax_struct *  kerstr ){
	return  1 ;}
int  c_blas_yisax_exec (c_blas_yisax_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_blas_yisax_scmc_kernel ( 	( kerstr )->y , 	( kerstr )->x , (	( kerstr )->a)[0] , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_blas_yisax_scmc_set_parameter_y (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  c_blas_yisax_scmc_set_parameter_x (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->x = pm->d_data);
}
int  c_blas_yisax_scmc_set_parameter_a (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->a = pm->d_data);
}
int  c_blas_yisax_scmc_set_parameter_y_cpu_core (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_blas_yisax_scmc_set_parameter_numvec (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_blas_yisax_scmc_set_parameter_XLEN (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_blas_yisax_scmc_set_parameter_YLEN (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_blas_yisax_scmc_set_parameter_ZLEN (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_blas_yisax_scmc_set_parameter_ovlp (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_blas_yisax_scmc_set_parameter_xblock (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_blas_yisax_scmc_set_parameter_yblock (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_blas_yisax_scmc_set_parameter_zblock (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_blas_yisax_scmc_set_parameter_num_ele (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_blas_invy_init (c_pscmc_env *  pe ,c_blas_invy_struct *  kerstr ){
	return  0 ;}
void  c_blas_invy_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_blas_invy_struct ));
}
int  c_blas_invy_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_blas_invy_get_num_compute_units (c_blas_invy_struct *  kerstr ){
	return  1 ;}
int  c_blas_invy_exec (c_blas_invy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_blas_invy_scmc_kernel ( 	( kerstr )->y , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_blas_invy_scmc_set_parameter_y (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  c_blas_invy_scmc_set_parameter_y_cpu_core (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_blas_invy_scmc_set_parameter_numvec (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_blas_invy_scmc_set_parameter_XLEN (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_blas_invy_scmc_set_parameter_YLEN (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_blas_invy_scmc_set_parameter_ZLEN (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_blas_invy_scmc_set_parameter_ovlp (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_blas_invy_scmc_set_parameter_xblock (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_blas_invy_scmc_set_parameter_yblock (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_blas_invy_scmc_set_parameter_zblock (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_blas_invy_scmc_set_parameter_num_ele (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_blas_get_ITG_Potential_init (c_pscmc_env *  pe ,c_blas_get_ITG_Potential_struct *  kerstr ){
	return  0 ;}
void  c_blas_get_ITG_Potential_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_blas_get_ITG_Potential_struct ));
}
int  c_blas_get_ITG_Potential_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_blas_get_ITG_Potential_get_num_compute_units (c_blas_get_ITG_Potential_struct *  kerstr ){
	return  1 ;}
int  c_blas_get_ITG_Potential_exec (c_blas_get_ITG_Potential_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_blas_get_ITG_Potential_scmc_kernel ( 	( kerstr )->y , 	( kerstr )->x , 	( kerstr )->u , (	( kerstr )->minus_over_q_e)[0] , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_blas_get_ITG_Potential_scmc_set_parameter_y (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  c_blas_get_ITG_Potential_scmc_set_parameter_x (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->x = pm->d_data);
}
int  c_blas_get_ITG_Potential_scmc_set_parameter_u (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->u = pm->d_data);
}
int  c_blas_get_ITG_Potential_scmc_set_parameter_minus_over_q_e (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->minus_over_q_e = pm->d_data);
}
int  c_blas_get_ITG_Potential_scmc_set_parameter_y_cpu_core (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_blas_get_ITG_Potential_scmc_set_parameter_numvec (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_blas_get_ITG_Potential_scmc_set_parameter_XLEN (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_blas_get_ITG_Potential_scmc_set_parameter_YLEN (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_blas_get_ITG_Potential_scmc_set_parameter_ZLEN (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_blas_get_ITG_Potential_scmc_set_parameter_ovlp (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_blas_get_ITG_Potential_scmc_set_parameter_xblock (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_blas_get_ITG_Potential_scmc_set_parameter_yblock (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_blas_get_ITG_Potential_scmc_set_parameter_zblock (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_blas_get_ITG_Potential_scmc_set_parameter_num_ele (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_blas_yisconst_init (c_pscmc_env *  pe ,c_blas_yisconst_struct *  kerstr ){
	return  0 ;}
void  c_blas_yisconst_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_blas_yisconst_struct ));
}
int  c_blas_yisconst_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_blas_yisconst_get_num_compute_units (c_blas_yisconst_struct *  kerstr ){
	return  1 ;}
int  c_blas_yisconst_exec (c_blas_yisconst_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_blas_yisconst_scmc_kernel ( 	( kerstr )->y , (	( kerstr )->a)[0] , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_blas_yisconst_scmc_set_parameter_y (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  c_blas_yisconst_scmc_set_parameter_a (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->a = pm->d_data);
}
int  c_blas_yisconst_scmc_set_parameter_y_cpu_core (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_blas_yisconst_scmc_set_parameter_numvec (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_blas_yisconst_scmc_set_parameter_XLEN (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_blas_yisconst_scmc_set_parameter_YLEN (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_blas_yisconst_scmc_set_parameter_ZLEN (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_blas_yisconst_scmc_set_parameter_ovlp (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_blas_yisconst_scmc_set_parameter_xblock (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_blas_yisconst_scmc_set_parameter_yblock (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_blas_yisconst_scmc_set_parameter_zblock (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_blas_yisconst_scmc_set_parameter_num_ele (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_blas_yiszero_init (c_pscmc_env *  pe ,c_blas_yiszero_struct *  kerstr ){
	return  0 ;}
void  c_blas_yiszero_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_blas_yiszero_struct ));
}
int  c_blas_yiszero_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_blas_yiszero_get_num_compute_units (c_blas_yiszero_struct *  kerstr ){
	return  1 ;}
int  c_blas_yiszero_exec (c_blas_yiszero_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_blas_yiszero_scmc_kernel ( 	( kerstr )->y , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_blas_yiszero_scmc_set_parameter_y (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  c_blas_yiszero_scmc_set_parameter_y_cpu_core (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_blas_yiszero_scmc_set_parameter_numvec (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_blas_yiszero_scmc_set_parameter_XLEN (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_blas_yiszero_scmc_set_parameter_YLEN (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_blas_yiszero_scmc_set_parameter_ZLEN (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_blas_yiszero_scmc_set_parameter_ovlp (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_blas_yiszero_scmc_set_parameter_xblock (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_blas_yiszero_scmc_set_parameter_yblock (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_blas_yiszero_scmc_set_parameter_zblock (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_blas_yiszero_scmc_set_parameter_num_ele (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_blas_yiszero_synced_init (c_pscmc_env *  pe ,c_blas_yiszero_synced_struct *  kerstr ){
	return  0 ;}
void  c_blas_yiszero_synced_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_blas_yiszero_synced_struct ));
}
int  c_blas_yiszero_synced_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_blas_yiszero_synced_get_num_compute_units (c_blas_yiszero_synced_struct *  kerstr ){
	return  1 ;}
int  c_blas_yiszero_synced_exec (c_blas_yiszero_synced_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_blas_yiszero_synced_scmc_kernel ( 	( kerstr )->y , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_blas_yiszero_synced_scmc_set_parameter_y (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  c_blas_yiszero_synced_scmc_set_parameter_y_cpu_core (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_blas_yiszero_synced_scmc_set_parameter_numvec (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_blas_yiszero_synced_scmc_set_parameter_XLEN (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_blas_yiszero_synced_scmc_set_parameter_YLEN (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_blas_yiszero_synced_scmc_set_parameter_ZLEN (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_blas_yiszero_synced_scmc_set_parameter_ovlp (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_blas_yiszero_synced_scmc_set_parameter_xblock (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_blas_yiszero_synced_scmc_set_parameter_yblock (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_blas_yiszero_synced_scmc_set_parameter_zblock (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_blas_yiszero_synced_scmc_set_parameter_num_ele (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
