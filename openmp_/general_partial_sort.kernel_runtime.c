#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "openmp_pscmc_inc.h"
#include "general_partial_sort.kernel_inc.h"
int  openmp_cu_swap_r_init (openmp_pscmc_env *  pe ,openmp_cu_swap_r_struct *  kerstr ){
	return  0 ;}
void  openmp_cu_swap_r_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_cu_swap_r_struct ));
}
int  openmp_cu_swap_r_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_cu_swap_r_exec (openmp_cu_swap_r_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_cu_swap_r_scmc_kernel ( 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->adjoint_vec_pids , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->the_dir_num)[0] , (	( kerstr )->XYZLEN)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_cu_swap_r_scmc_set_parameter_cu_cache (openmp_cu_swap_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_cu_swap_r_scmc_set_parameter_cu_xyzw (openmp_cu_swap_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_cu_swap_r_scmc_set_parameter_adjoint_vec_pids (openmp_cu_swap_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids = pm->d_data);
}
int  openmp_cu_swap_r_scmc_set_parameter_cu_cache_length (openmp_cu_swap_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_cu_swap_r_scmc_set_parameter_the_dir_num (openmp_cu_swap_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->the_dir_num = pm->d_data);
}
int  openmp_cu_swap_r_scmc_set_parameter_XYZLEN (openmp_cu_swap_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XYZLEN = pm->d_data);
}
int  openmp_cu_swap_l_init (openmp_pscmc_env *  pe ,openmp_cu_swap_l_struct *  kerstr ){
	return  0 ;}
void  openmp_cu_swap_l_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_cu_swap_l_struct ));
}
int  openmp_cu_swap_l_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_cu_swap_l_exec (openmp_cu_swap_l_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_cu_swap_l_scmc_kernel ( 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->adjoint_vec_pids , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->the_dir_num)[0] , (	( kerstr )->XYZLEN)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_cu_swap_l_scmc_set_parameter_cu_cache (openmp_cu_swap_l_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_cu_swap_l_scmc_set_parameter_cu_xyzw (openmp_cu_swap_l_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_cu_swap_l_scmc_set_parameter_adjoint_vec_pids (openmp_cu_swap_l_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids = pm->d_data);
}
int  openmp_cu_swap_l_scmc_set_parameter_cu_cache_length (openmp_cu_swap_l_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_cu_swap_l_scmc_set_parameter_the_dir_num (openmp_cu_swap_l_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->the_dir_num = pm->d_data);
}
int  openmp_cu_swap_l_scmc_set_parameter_XYZLEN (openmp_cu_swap_l_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XYZLEN = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_z_vlo_struct *  kerstr ){
	return  0 ;}
void  openmp_sort_one_grid_z_vlo_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sort_one_grid_z_vlo_struct ));
}
int  openmp_sort_one_grid_z_vlo_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_sort_one_grid_z_vlo_exec (openmp_sort_one_grid_z_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sort_one_grid_z_vlo_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->adjoint_vec_pids , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_inoutput (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_xyzw (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_cu_cache (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_XLEN (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_YLEN (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_ZLEN (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_ovlp (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_numvec (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_y_vlo_struct *  kerstr ){
	return  0 ;}
void  openmp_sort_one_grid_y_vlo_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sort_one_grid_y_vlo_struct ));
}
int  openmp_sort_one_grid_y_vlo_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_sort_one_grid_y_vlo_exec (openmp_sort_one_grid_y_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sort_one_grid_y_vlo_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->adjoint_vec_pids , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_inoutput (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_xyzw (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_cu_cache (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_XLEN (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_YLEN (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_ZLEN (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_ovlp (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_numvec (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_x_vlo_struct *  kerstr ){
	return  0 ;}
void  openmp_sort_one_grid_x_vlo_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sort_one_grid_x_vlo_struct ));
}
int  openmp_sort_one_grid_x_vlo_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_sort_one_grid_x_vlo_exec (openmp_sort_one_grid_x_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sort_one_grid_x_vlo_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->adjoint_vec_pids , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_inoutput (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_xyzw (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_cu_cache (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_XLEN (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_YLEN (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_ZLEN (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_ovlp (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_numvec (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_sort_one_grid_z_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_z_struct *  kerstr ){
	return  0 ;}
void  openmp_sort_one_grid_z_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sort_one_grid_z_struct ));
}
int  openmp_sort_one_grid_z_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_sort_one_grid_z_exec (openmp_sort_one_grid_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sort_one_grid_z_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->adjoint_vec_pids , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_sort_one_grid_z_scmc_set_parameter_inoutput (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_sort_one_grid_z_scmc_set_parameter_xyzw (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_sort_one_grid_z_scmc_set_parameter_cu_cache (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_sort_one_grid_z_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_sort_one_grid_z_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids = pm->d_data);
}
int  openmp_sort_one_grid_z_scmc_set_parameter_XLEN (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_sort_one_grid_z_scmc_set_parameter_YLEN (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_sort_one_grid_z_scmc_set_parameter_ZLEN (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_sort_one_grid_z_scmc_set_parameter_ovlp (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_sort_one_grid_z_scmc_set_parameter_numvec (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_sort_one_grid_z_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_sort_one_grid_z_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_sort_one_grid_y_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_y_struct *  kerstr ){
	return  0 ;}
void  openmp_sort_one_grid_y_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sort_one_grid_y_struct ));
}
int  openmp_sort_one_grid_y_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_sort_one_grid_y_exec (openmp_sort_one_grid_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sort_one_grid_y_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->adjoint_vec_pids , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_sort_one_grid_y_scmc_set_parameter_inoutput (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_sort_one_grid_y_scmc_set_parameter_xyzw (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_sort_one_grid_y_scmc_set_parameter_cu_cache (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_sort_one_grid_y_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_sort_one_grid_y_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids = pm->d_data);
}
int  openmp_sort_one_grid_y_scmc_set_parameter_XLEN (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_sort_one_grid_y_scmc_set_parameter_YLEN (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_sort_one_grid_y_scmc_set_parameter_ZLEN (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_sort_one_grid_y_scmc_set_parameter_ovlp (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_sort_one_grid_y_scmc_set_parameter_numvec (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_sort_one_grid_y_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_sort_one_grid_y_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_sort_one_grid_x_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_x_struct *  kerstr ){
	return  0 ;}
void  openmp_sort_one_grid_x_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sort_one_grid_x_struct ));
}
int  openmp_sort_one_grid_x_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_sort_one_grid_x_exec (openmp_sort_one_grid_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sort_one_grid_x_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->adjoint_vec_pids , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_sort_one_grid_x_scmc_set_parameter_inoutput (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_sort_one_grid_x_scmc_set_parameter_xyzw (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_sort_one_grid_x_scmc_set_parameter_cu_cache (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_sort_one_grid_x_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_sort_one_grid_x_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids = pm->d_data);
}
int  openmp_sort_one_grid_x_scmc_set_parameter_XLEN (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_sort_one_grid_x_scmc_set_parameter_YLEN (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_sort_one_grid_x_scmc_set_parameter_ZLEN (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_sort_one_grid_x_scmc_set_parameter_ovlp (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_sort_one_grid_x_scmc_set_parameter_numvec (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_sort_one_grid_x_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_sort_one_grid_x_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
