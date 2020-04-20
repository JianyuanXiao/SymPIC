#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "openmp_pscmc_inc.h"
#include "implicit_particle_mover.kernel_inc.h"
int  openmp_split_pass_xyzE_particle_push_r_init (openmp_pscmc_env *  pe ,openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ){
	return  0 ;}
void  openmp_split_pass_xyzE_particle_push_r_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_split_pass_xyzE_particle_push_r_struct ));
}
int  openmp_split_pass_xyzE_particle_push_r_get_num_compute_units (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_split_pass_xyzE_particle_push_r_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_split_pass_xyzE_particle_push_r_exec (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_split_pass_xyzE_particle_push_r_scmc_kernel ( 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->N_l)[0] , (	( kerstr )->N_M)[0] , (	( kerstr )->push_J)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_xyzw (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_cu_cache (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_cu_xyzw (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_fieldE (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_fieldB (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_FoutJ (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_XLEN (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_YLEN (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_ZLEN (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_ovlp (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_numvec (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_num_ele (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_grid_cache_len (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_cu_cache_length (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_Mass0 (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_Charge0 (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_Deltat (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_DELTA_X (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_DELTA_Y (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_DELTA_Z (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_N_l (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->N_l = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_N_M (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->N_M = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_push_J (openmp_split_pass_xyzE_particle_push_r_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->push_J = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_init (openmp_pscmc_env *  pe ,openmp_split_pass_xyzE_particle_struct *  kerstr ){
	return  0 ;}
void  openmp_split_pass_xyzE_particle_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_split_pass_xyzE_particle_struct ));
}
int  openmp_split_pass_xyzE_particle_get_num_compute_units (openmp_split_pass_xyzE_particle_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_split_pass_xyzE_particle_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_split_pass_xyzE_particle_exec (openmp_split_pass_xyzE_particle_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_split_pass_xyzE_particle_scmc_kernel ( 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->N_l)[0] , (	( kerstr )->N_M)[0] , (	( kerstr )->push_J)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_xyzw (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_cu_cache (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_cu_xyzw (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_fieldE (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_fieldB (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_FoutJ (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_XLEN (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_YLEN (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_ZLEN (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_ovlp (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_numvec (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_num_ele (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_grid_cache_len (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_cu_cache_length (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_Mass0 (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_Charge0 (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_Deltat (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_DELTA_X (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_DELTA_Y (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_DELTA_Z (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_N_l (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->N_l = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_N_M (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->N_M = pm->d_data);
}
int  openmp_split_pass_xyzE_particle_scmc_set_parameter_push_J (openmp_split_pass_xyzE_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->push_J = pm->d_data);
}
