#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "openmp_pscmc_inc.h"
#include "miniblas.kernel_inc.h"
int  openmp_blas_sum_init (openmp_pscmc_env *  pe ,openmp_blas_sum_struct *  kerstr ){
	return  0 ;}
void  openmp_blas_sum_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_blas_sum_struct ));
}
int  openmp_blas_sum_get_num_compute_units (openmp_blas_sum_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_blas_sum_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_blas_sum_exec (openmp_blas_sum_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

#pragma omp parallel
{
	int  xid ;
	int  yid ;
	int  numt = 	omp_get_num_threads (  ) ;
	int  tid = 	omp_get_thread_num (  ) ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = tid) ; 	(  yid < scmc_internal_g_ylen ) ; (yid = 	(  yid + numt )))
	{
	for ((xid = 0) ; 	(  xid < scmc_internal_g_xlen ) ; (xid = 	(  xid + 1 )))
	{
	openmp_blas_sum_scmc_kernel ( 	( kerstr )->y , 	( kerstr )->rdcd , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_blas_sum_scmc_set_parameter_y (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  openmp_blas_sum_scmc_set_parameter_rdcd (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->rdcd = pm->d_data);
}
int  openmp_blas_sum_scmc_set_parameter_y_cpu_core (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_blas_sum_scmc_set_parameter_numvec (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_blas_sum_scmc_set_parameter_XLEN (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_blas_sum_scmc_set_parameter_YLEN (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_blas_sum_scmc_set_parameter_ZLEN (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_blas_sum_scmc_set_parameter_ovlp (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_blas_sum_scmc_set_parameter_xblock (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_blas_sum_scmc_set_parameter_yblock (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_blas_sum_scmc_set_parameter_zblock (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_blas_sum_scmc_set_parameter_num_ele (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_blas_dot_init (openmp_pscmc_env *  pe ,openmp_blas_dot_struct *  kerstr ){
	return  0 ;}
void  openmp_blas_dot_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_blas_dot_struct ));
}
int  openmp_blas_dot_get_num_compute_units (openmp_blas_dot_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_blas_dot_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_blas_dot_exec (openmp_blas_dot_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

#pragma omp parallel
{
	int  xid ;
	int  yid ;
	int  numt = 	omp_get_num_threads (  ) ;
	int  tid = 	omp_get_thread_num (  ) ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = tid) ; 	(  yid < scmc_internal_g_ylen ) ; (yid = 	(  yid + numt )))
	{
	for ((xid = 0) ; 	(  xid < scmc_internal_g_xlen ) ; (xid = 	(  xid + 1 )))
	{
	openmp_blas_dot_scmc_kernel ( 	( kerstr )->y , 	( kerstr )->x , 	( kerstr )->rdcd , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_blas_dot_scmc_set_parameter_y (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  openmp_blas_dot_scmc_set_parameter_x (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->x = pm->d_data);
}
int  openmp_blas_dot_scmc_set_parameter_rdcd (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->rdcd = pm->d_data);
}
int  openmp_blas_dot_scmc_set_parameter_y_cpu_core (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_blas_dot_scmc_set_parameter_numvec (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_blas_dot_scmc_set_parameter_XLEN (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_blas_dot_scmc_set_parameter_YLEN (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_blas_dot_scmc_set_parameter_ZLEN (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_blas_dot_scmc_set_parameter_ovlp (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_blas_dot_scmc_set_parameter_xblock (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_blas_dot_scmc_set_parameter_yblock (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_blas_dot_scmc_set_parameter_zblock (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_blas_dot_scmc_set_parameter_num_ele (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_blas_findmax_init (openmp_pscmc_env *  pe ,openmp_blas_findmax_struct *  kerstr ){
	return  0 ;}
void  openmp_blas_findmax_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_blas_findmax_struct ));
}
int  openmp_blas_findmax_get_num_compute_units (openmp_blas_findmax_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_blas_findmax_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_blas_findmax_exec (openmp_blas_findmax_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

#pragma omp parallel
{
	int  xid ;
	int  yid ;
	int  numt = 	omp_get_num_threads (  ) ;
	int  tid = 	omp_get_thread_num (  ) ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = tid) ; 	(  yid < scmc_internal_g_ylen ) ; (yid = 	(  yid + numt )))
	{
	for ((xid = 0) ; 	(  xid < scmc_internal_g_xlen ) ; (xid = 	(  xid + 1 )))
	{
	openmp_blas_findmax_scmc_kernel ( 	( kerstr )->y , 	( kerstr )->rdcd , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_blas_findmax_scmc_set_parameter_y (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  openmp_blas_findmax_scmc_set_parameter_rdcd (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->rdcd = pm->d_data);
}
int  openmp_blas_findmax_scmc_set_parameter_y_cpu_core (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_blas_findmax_scmc_set_parameter_numvec (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_blas_findmax_scmc_set_parameter_XLEN (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_blas_findmax_scmc_set_parameter_YLEN (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_blas_findmax_scmc_set_parameter_ZLEN (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_blas_findmax_scmc_set_parameter_ovlp (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_blas_findmax_scmc_set_parameter_xblock (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_blas_findmax_scmc_set_parameter_yblock (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_blas_findmax_scmc_set_parameter_zblock (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_blas_findmax_scmc_set_parameter_num_ele (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_blas_mulxy_init (openmp_pscmc_env *  pe ,openmp_blas_mulxy_struct *  kerstr ){
	return  0 ;}
void  openmp_blas_mulxy_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_blas_mulxy_struct ));
}
int  openmp_blas_mulxy_get_num_compute_units (openmp_blas_mulxy_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_blas_mulxy_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_blas_mulxy_exec (openmp_blas_mulxy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

#pragma omp parallel
{
	int  xid ;
	int  yid ;
	int  numt = 	omp_get_num_threads (  ) ;
	int  tid = 	omp_get_thread_num (  ) ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = tid) ; 	(  yid < scmc_internal_g_ylen ) ; (yid = 	(  yid + numt )))
	{
	for ((xid = 0) ; 	(  xid < scmc_internal_g_xlen ) ; (xid = 	(  xid + 1 )))
	{
	openmp_blas_mulxy_scmc_kernel ( 	( kerstr )->y , 	( kerstr )->x , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_blas_mulxy_scmc_set_parameter_y (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  openmp_blas_mulxy_scmc_set_parameter_x (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->x = pm->d_data);
}
int  openmp_blas_mulxy_scmc_set_parameter_y_cpu_core (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_blas_mulxy_scmc_set_parameter_numvec (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_blas_mulxy_scmc_set_parameter_XLEN (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_blas_mulxy_scmc_set_parameter_YLEN (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_blas_mulxy_scmc_set_parameter_ZLEN (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_blas_mulxy_scmc_set_parameter_ovlp (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_blas_mulxy_scmc_set_parameter_xblock (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_blas_mulxy_scmc_set_parameter_yblock (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_blas_mulxy_scmc_set_parameter_zblock (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_blas_mulxy_scmc_set_parameter_num_ele (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_blas_axpby_init (openmp_pscmc_env *  pe ,openmp_blas_axpby_struct *  kerstr ){
	return  0 ;}
void  openmp_blas_axpby_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_blas_axpby_struct ));
}
int  openmp_blas_axpby_get_num_compute_units (openmp_blas_axpby_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_blas_axpby_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_blas_axpby_exec (openmp_blas_axpby_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

#pragma omp parallel
{
	int  xid ;
	int  yid ;
	int  numt = 	omp_get_num_threads (  ) ;
	int  tid = 	omp_get_thread_num (  ) ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = tid) ; 	(  yid < scmc_internal_g_ylen ) ; (yid = 	(  yid + numt )))
	{
	for ((xid = 0) ; 	(  xid < scmc_internal_g_xlen ) ; (xid = 	(  xid + 1 )))
	{
	openmp_blas_axpby_scmc_kernel ( 	( kerstr )->y , 	( kerstr )->x , (	( kerstr )->a)[0] , (	( kerstr )->b)[0] , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_blas_axpby_scmc_set_parameter_y (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  openmp_blas_axpby_scmc_set_parameter_x (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->x = pm->d_data);
}
int  openmp_blas_axpby_scmc_set_parameter_a (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->a = pm->d_data);
}
int  openmp_blas_axpby_scmc_set_parameter_b (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->b = pm->d_data);
}
int  openmp_blas_axpby_scmc_set_parameter_y_cpu_core (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_blas_axpby_scmc_set_parameter_numvec (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_blas_axpby_scmc_set_parameter_XLEN (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_blas_axpby_scmc_set_parameter_YLEN (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_blas_axpby_scmc_set_parameter_ZLEN (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_blas_axpby_scmc_set_parameter_ovlp (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_blas_axpby_scmc_set_parameter_xblock (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_blas_axpby_scmc_set_parameter_yblock (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_blas_axpby_scmc_set_parameter_zblock (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_blas_axpby_scmc_set_parameter_num_ele (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_blas_axpy_init (openmp_pscmc_env *  pe ,openmp_blas_axpy_struct *  kerstr ){
	return  0 ;}
void  openmp_blas_axpy_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_blas_axpy_struct ));
}
int  openmp_blas_axpy_get_num_compute_units (openmp_blas_axpy_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_blas_axpy_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_blas_axpy_exec (openmp_blas_axpy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

#pragma omp parallel
{
	int  xid ;
	int  yid ;
	int  numt = 	omp_get_num_threads (  ) ;
	int  tid = 	omp_get_thread_num (  ) ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = tid) ; 	(  yid < scmc_internal_g_ylen ) ; (yid = 	(  yid + numt )))
	{
	for ((xid = 0) ; 	(  xid < scmc_internal_g_xlen ) ; (xid = 	(  xid + 1 )))
	{
	openmp_blas_axpy_scmc_kernel ( 	( kerstr )->y , 	( kerstr )->x , (	( kerstr )->a)[0] , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_blas_axpy_scmc_set_parameter_y (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  openmp_blas_axpy_scmc_set_parameter_x (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->x = pm->d_data);
}
int  openmp_blas_axpy_scmc_set_parameter_a (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->a = pm->d_data);
}
int  openmp_blas_axpy_scmc_set_parameter_y_cpu_core (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_blas_axpy_scmc_set_parameter_numvec (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_blas_axpy_scmc_set_parameter_XLEN (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_blas_axpy_scmc_set_parameter_YLEN (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_blas_axpy_scmc_set_parameter_ZLEN (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_blas_axpy_scmc_set_parameter_ovlp (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_blas_axpy_scmc_set_parameter_xblock (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_blas_axpy_scmc_set_parameter_yblock (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_blas_axpy_scmc_set_parameter_zblock (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_blas_axpy_scmc_set_parameter_num_ele (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_blas_yisax_init (openmp_pscmc_env *  pe ,openmp_blas_yisax_struct *  kerstr ){
	return  0 ;}
void  openmp_blas_yisax_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_blas_yisax_struct ));
}
int  openmp_blas_yisax_get_num_compute_units (openmp_blas_yisax_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_blas_yisax_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_blas_yisax_exec (openmp_blas_yisax_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

#pragma omp parallel
{
	int  xid ;
	int  yid ;
	int  numt = 	omp_get_num_threads (  ) ;
	int  tid = 	omp_get_thread_num (  ) ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = tid) ; 	(  yid < scmc_internal_g_ylen ) ; (yid = 	(  yid + numt )))
	{
	for ((xid = 0) ; 	(  xid < scmc_internal_g_xlen ) ; (xid = 	(  xid + 1 )))
	{
	openmp_blas_yisax_scmc_kernel ( 	( kerstr )->y , 	( kerstr )->x , (	( kerstr )->a)[0] , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_blas_yisax_scmc_set_parameter_y (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  openmp_blas_yisax_scmc_set_parameter_x (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->x = pm->d_data);
}
int  openmp_blas_yisax_scmc_set_parameter_a (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->a = pm->d_data);
}
int  openmp_blas_yisax_scmc_set_parameter_y_cpu_core (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_blas_yisax_scmc_set_parameter_numvec (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_blas_yisax_scmc_set_parameter_XLEN (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_blas_yisax_scmc_set_parameter_YLEN (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_blas_yisax_scmc_set_parameter_ZLEN (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_blas_yisax_scmc_set_parameter_ovlp (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_blas_yisax_scmc_set_parameter_xblock (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_blas_yisax_scmc_set_parameter_yblock (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_blas_yisax_scmc_set_parameter_zblock (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_blas_yisax_scmc_set_parameter_num_ele (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_blas_invy_init (openmp_pscmc_env *  pe ,openmp_blas_invy_struct *  kerstr ){
	return  0 ;}
void  openmp_blas_invy_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_blas_invy_struct ));
}
int  openmp_blas_invy_get_num_compute_units (openmp_blas_invy_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_blas_invy_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_blas_invy_exec (openmp_blas_invy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

#pragma omp parallel
{
	int  xid ;
	int  yid ;
	int  numt = 	omp_get_num_threads (  ) ;
	int  tid = 	omp_get_thread_num (  ) ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = tid) ; 	(  yid < scmc_internal_g_ylen ) ; (yid = 	(  yid + numt )))
	{
	for ((xid = 0) ; 	(  xid < scmc_internal_g_xlen ) ; (xid = 	(  xid + 1 )))
	{
	openmp_blas_invy_scmc_kernel ( 	( kerstr )->y , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_blas_invy_scmc_set_parameter_y (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  openmp_blas_invy_scmc_set_parameter_y_cpu_core (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_blas_invy_scmc_set_parameter_numvec (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_blas_invy_scmc_set_parameter_XLEN (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_blas_invy_scmc_set_parameter_YLEN (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_blas_invy_scmc_set_parameter_ZLEN (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_blas_invy_scmc_set_parameter_ovlp (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_blas_invy_scmc_set_parameter_xblock (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_blas_invy_scmc_set_parameter_yblock (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_blas_invy_scmc_set_parameter_zblock (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_blas_invy_scmc_set_parameter_num_ele (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_blas_get_ITG_Potential_init (openmp_pscmc_env *  pe ,openmp_blas_get_ITG_Potential_struct *  kerstr ){
	return  0 ;}
void  openmp_blas_get_ITG_Potential_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_blas_get_ITG_Potential_struct ));
}
int  openmp_blas_get_ITG_Potential_get_num_compute_units (openmp_blas_get_ITG_Potential_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_blas_get_ITG_Potential_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_blas_get_ITG_Potential_exec (openmp_blas_get_ITG_Potential_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

#pragma omp parallel
{
	int  xid ;
	int  yid ;
	int  numt = 	omp_get_num_threads (  ) ;
	int  tid = 	omp_get_thread_num (  ) ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = tid) ; 	(  yid < scmc_internal_g_ylen ) ; (yid = 	(  yid + numt )))
	{
	for ((xid = 0) ; 	(  xid < scmc_internal_g_xlen ) ; (xid = 	(  xid + 1 )))
	{
	openmp_blas_get_ITG_Potential_scmc_kernel ( 	( kerstr )->y , 	( kerstr )->x , 	( kerstr )->u , (	( kerstr )->minus_over_q_e)[0] , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_y (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_x (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->x = pm->d_data);
}
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_u (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->u = pm->d_data);
}
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_minus_over_q_e (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->minus_over_q_e = pm->d_data);
}
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_y_cpu_core (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_numvec (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_XLEN (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_YLEN (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_ZLEN (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_ovlp (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_xblock (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_yblock (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_zblock (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_num_ele (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_blas_yisconst_init (openmp_pscmc_env *  pe ,openmp_blas_yisconst_struct *  kerstr ){
	return  0 ;}
void  openmp_blas_yisconst_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_blas_yisconst_struct ));
}
int  openmp_blas_yisconst_get_num_compute_units (openmp_blas_yisconst_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_blas_yisconst_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_blas_yisconst_exec (openmp_blas_yisconst_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

#pragma omp parallel
{
	int  xid ;
	int  yid ;
	int  numt = 	omp_get_num_threads (  ) ;
	int  tid = 	omp_get_thread_num (  ) ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = tid) ; 	(  yid < scmc_internal_g_ylen ) ; (yid = 	(  yid + numt )))
	{
	for ((xid = 0) ; 	(  xid < scmc_internal_g_xlen ) ; (xid = 	(  xid + 1 )))
	{
	openmp_blas_yisconst_scmc_kernel ( 	( kerstr )->y , (	( kerstr )->a)[0] , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_blas_yisconst_scmc_set_parameter_y (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  openmp_blas_yisconst_scmc_set_parameter_a (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->a = pm->d_data);
}
int  openmp_blas_yisconst_scmc_set_parameter_y_cpu_core (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_blas_yisconst_scmc_set_parameter_numvec (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_blas_yisconst_scmc_set_parameter_XLEN (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_blas_yisconst_scmc_set_parameter_YLEN (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_blas_yisconst_scmc_set_parameter_ZLEN (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_blas_yisconst_scmc_set_parameter_ovlp (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_blas_yisconst_scmc_set_parameter_xblock (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_blas_yisconst_scmc_set_parameter_yblock (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_blas_yisconst_scmc_set_parameter_zblock (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_blas_yisconst_scmc_set_parameter_num_ele (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_blas_yiszero_init (openmp_pscmc_env *  pe ,openmp_blas_yiszero_struct *  kerstr ){
	return  0 ;}
void  openmp_blas_yiszero_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_blas_yiszero_struct ));
}
int  openmp_blas_yiszero_get_num_compute_units (openmp_blas_yiszero_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_blas_yiszero_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_blas_yiszero_exec (openmp_blas_yiszero_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

#pragma omp parallel
{
	int  xid ;
	int  yid ;
	int  numt = 	omp_get_num_threads (  ) ;
	int  tid = 	omp_get_thread_num (  ) ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = tid) ; 	(  yid < scmc_internal_g_ylen ) ; (yid = 	(  yid + numt )))
	{
	for ((xid = 0) ; 	(  xid < scmc_internal_g_xlen ) ; (xid = 	(  xid + 1 )))
	{
	openmp_blas_yiszero_scmc_kernel ( 	( kerstr )->y , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_blas_yiszero_scmc_set_parameter_y (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  openmp_blas_yiszero_scmc_set_parameter_y_cpu_core (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_blas_yiszero_scmc_set_parameter_numvec (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_blas_yiszero_scmc_set_parameter_XLEN (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_blas_yiszero_scmc_set_parameter_YLEN (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_blas_yiszero_scmc_set_parameter_ZLEN (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_blas_yiszero_scmc_set_parameter_ovlp (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_blas_yiszero_scmc_set_parameter_xblock (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_blas_yiszero_scmc_set_parameter_yblock (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_blas_yiszero_scmc_set_parameter_zblock (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_blas_yiszero_scmc_set_parameter_num_ele (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_blas_mulxy_numele3_init (openmp_pscmc_env *  pe ,openmp_blas_mulxy_numele3_struct *  kerstr ){
	return  0 ;}
void  openmp_blas_mulxy_numele3_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_blas_mulxy_numele3_struct ));
}
int  openmp_blas_mulxy_numele3_get_num_compute_units (openmp_blas_mulxy_numele3_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_blas_mulxy_numele3_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_blas_mulxy_numele3_exec (openmp_blas_mulxy_numele3_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

#pragma omp parallel
{
	int  xid ;
	int  yid ;
	int  numt = 	omp_get_num_threads (  ) ;
	int  tid = 	omp_get_thread_num (  ) ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = tid) ; 	(  yid < scmc_internal_g_ylen ) ; (yid = 	(  yid + numt )))
	{
	for ((xid = 0) ; 	(  xid < scmc_internal_g_xlen ) ; (xid = 	(  xid + 1 )))
	{
	openmp_blas_mulxy_numele3_scmc_kernel ( 	( kerstr )->y , 	( kerstr )->x , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_blas_mulxy_numele3_scmc_set_parameter_y (openmp_blas_mulxy_numele3_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  openmp_blas_mulxy_numele3_scmc_set_parameter_x (openmp_blas_mulxy_numele3_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->x = pm->d_data);
}
int  openmp_blas_mulxy_numele3_scmc_set_parameter_y_cpu_core (openmp_blas_mulxy_numele3_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_blas_mulxy_numele3_scmc_set_parameter_numvec (openmp_blas_mulxy_numele3_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_blas_mulxy_numele3_scmc_set_parameter_XLEN (openmp_blas_mulxy_numele3_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_blas_mulxy_numele3_scmc_set_parameter_YLEN (openmp_blas_mulxy_numele3_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_blas_mulxy_numele3_scmc_set_parameter_ZLEN (openmp_blas_mulxy_numele3_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_blas_mulxy_numele3_scmc_set_parameter_ovlp (openmp_blas_mulxy_numele3_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_blas_mulxy_numele3_scmc_set_parameter_xblock (openmp_blas_mulxy_numele3_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_blas_mulxy_numele3_scmc_set_parameter_yblock (openmp_blas_mulxy_numele3_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_blas_mulxy_numele3_scmc_set_parameter_zblock (openmp_blas_mulxy_numele3_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_blas_mulxy_numele3_scmc_set_parameter_num_ele (openmp_blas_mulxy_numele3_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_blas_yiszero_synced_init (openmp_pscmc_env *  pe ,openmp_blas_yiszero_synced_struct *  kerstr ){
	return  0 ;}
void  openmp_blas_yiszero_synced_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_blas_yiszero_synced_struct ));
}
int  openmp_blas_yiszero_synced_get_num_compute_units (openmp_blas_yiszero_synced_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_blas_yiszero_synced_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_blas_yiszero_synced_exec (openmp_blas_yiszero_synced_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

#pragma omp parallel
{
	int  xid ;
	int  yid ;
	int  numt = 	omp_get_num_threads (  ) ;
	int  tid = 	omp_get_thread_num (  ) ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = tid) ; 	(  yid < scmc_internal_g_ylen ) ; (yid = 	(  yid + numt )))
	{
	for ((xid = 0) ; 	(  xid < scmc_internal_g_xlen ) ; (xid = 	(  xid + 1 )))
	{
	openmp_blas_yiszero_synced_scmc_kernel ( 	( kerstr )->y , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_blas_yiszero_synced_scmc_set_parameter_y (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y = pm->d_data);
}
int  openmp_blas_yiszero_synced_scmc_set_parameter_y_cpu_core (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_blas_yiszero_synced_scmc_set_parameter_numvec (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_blas_yiszero_synced_scmc_set_parameter_XLEN (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_blas_yiszero_synced_scmc_set_parameter_YLEN (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_blas_yiszero_synced_scmc_set_parameter_ZLEN (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_blas_yiszero_synced_scmc_set_parameter_ovlp (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_blas_yiszero_synced_scmc_set_parameter_xblock (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_blas_yiszero_synced_scmc_set_parameter_yblock (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_blas_yiszero_synced_scmc_set_parameter_zblock (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_blas_yiszero_synced_scmc_set_parameter_num_ele (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
