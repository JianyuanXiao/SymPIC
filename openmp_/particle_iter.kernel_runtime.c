#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "openmp_pscmc_inc.h"
#include "particle_iter.kernel_inc.h"
int  openmp_dump_ene_num_init (openmp_pscmc_env *  pe ,openmp_dump_ene_num_struct *  kerstr ){
	return  0 ;}
void  openmp_dump_ene_num_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_dump_ene_num_struct ));
}
int  openmp_dump_ene_num_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_dump_ene_num_exec (openmp_dump_ene_num_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_dump_ene_num_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_dump_ene_num_scmc_set_parameter_inoutput (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_xyzw (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_cu_cache (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_cu_xyzw (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_fieldE (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_fieldB (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_FoutJ (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_FoutEN (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_XLEN (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_YLEN (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_ZLEN (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_ovlp (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_numvec (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_num_ele (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_grid_cache_len (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_cu_cache_length (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_Mass (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_Charge (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_SPEC (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_NUM_SPEC (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_DELTA_X (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_DELTA_Y (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_DELTA_Z (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_dump_ene_num_scmc_set_parameter_Deltat (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_calculate_rho_init (openmp_pscmc_env *  pe ,openmp_calculate_rho_struct *  kerstr ){
	return  0 ;}
void  openmp_calculate_rho_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_calculate_rho_struct ));
}
int  openmp_calculate_rho_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_calculate_rho_exec (openmp_calculate_rho_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_calculate_rho_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_calculate_rho_scmc_set_parameter_inoutput (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_xyzw (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_cu_cache (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_cu_xyzw (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_fieldE (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_fieldB (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_FoutJ (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_FoutEN (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_XLEN (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_YLEN (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_ZLEN (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_ovlp (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_numvec (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_num_ele (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_grid_cache_len (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_cu_cache_length (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_Mass (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_Charge (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_SPEC (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_NUM_SPEC (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_DELTA_X (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_DELTA_Y (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_DELTA_Z (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_calculate_rho_scmc_set_parameter_Deltat (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_krook_collision_test_init (openmp_pscmc_env *  pe ,openmp_krook_collision_test_struct *  kerstr ){
	return  0 ;}
void  openmp_krook_collision_test_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_krook_collision_test_struct ));
}
int  openmp_krook_collision_test_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_krook_collision_test_exec (openmp_krook_collision_test_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_krook_collision_test_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->mu_freq)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_krook_collision_test_scmc_set_parameter_inoutput (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_krook_collision_test_scmc_set_parameter_xyzw (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_krook_collision_test_scmc_set_parameter_cu_cache (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_krook_collision_test_scmc_set_parameter_cu_xyzw (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_krook_collision_test_scmc_set_parameter_fieldE (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_krook_collision_test_scmc_set_parameter_fieldB (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_krook_collision_test_scmc_set_parameter_FoutJ (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_krook_collision_test_scmc_set_parameter_XLEN (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_krook_collision_test_scmc_set_parameter_YLEN (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_krook_collision_test_scmc_set_parameter_ZLEN (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_krook_collision_test_scmc_set_parameter_ovlp (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_krook_collision_test_scmc_set_parameter_numvec (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_krook_collision_test_scmc_set_parameter_num_ele (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_krook_collision_test_scmc_set_parameter_grid_cache_len (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_krook_collision_test_scmc_set_parameter_cu_cache_length (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_krook_collision_test_scmc_set_parameter_Mass0 (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  openmp_krook_collision_test_scmc_set_parameter_Charge0 (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  openmp_krook_collision_test_scmc_set_parameter_Deltat (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_krook_collision_test_scmc_set_parameter_mu_freq (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->mu_freq = pm->d_data);
}
int  openmp_krook_collision_remove_small_speed_init (openmp_pscmc_env *  pe ,openmp_krook_collision_remove_small_speed_struct *  kerstr ){
	return  0 ;}
void  openmp_krook_collision_remove_small_speed_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_krook_collision_remove_small_speed_struct ));
}
int  openmp_krook_collision_remove_small_speed_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_krook_collision_remove_small_speed_exec (openmp_krook_collision_remove_small_speed_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_krook_collision_remove_small_speed_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->mu_freq)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_inoutput (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_xyzw (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_cu_cache (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_cu_xyzw (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_fieldE (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_fieldB (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_FoutJ (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_XLEN (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_YLEN (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_ZLEN (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_ovlp (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_numvec (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_num_ele (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_grid_cache_len (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_cu_cache_length (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_Mass0 (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_Charge0 (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_Deltat (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_mu_freq (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->mu_freq = pm->d_data);
}
int  openmp_boris_yee_init (openmp_pscmc_env *  pe ,openmp_boris_yee_struct *  kerstr ){
	return  0 ;}
void  openmp_boris_yee_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_boris_yee_struct ));
}
int  openmp_boris_yee_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_boris_yee_exec (openmp_boris_yee_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_boris_yee_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_boris_yee_scmc_set_parameter_inoutput (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_boris_yee_scmc_set_parameter_xyzw (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_boris_yee_scmc_set_parameter_cu_cache (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_boris_yee_scmc_set_parameter_cu_xyzw (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_boris_yee_scmc_set_parameter_fieldE (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_boris_yee_scmc_set_parameter_fieldB (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_boris_yee_scmc_set_parameter_FoutJ (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_boris_yee_scmc_set_parameter_XLEN (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_boris_yee_scmc_set_parameter_YLEN (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_boris_yee_scmc_set_parameter_ZLEN (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_boris_yee_scmc_set_parameter_ovlp (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_boris_yee_scmc_set_parameter_numvec (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_boris_yee_scmc_set_parameter_num_ele (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_boris_yee_scmc_set_parameter_grid_cache_len (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_boris_yee_scmc_set_parameter_cu_cache_length (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_boris_yee_scmc_set_parameter_Mass0 (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  openmp_boris_yee_scmc_set_parameter_Charge0 (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  openmp_boris_yee_scmc_set_parameter_Deltat (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_init (openmp_pscmc_env *  pe ,openmp_split_pass_E_particle_vlo_struct *  kerstr ){
	return  0 ;}
void  openmp_split_pass_E_particle_vlo_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_split_pass_E_particle_vlo_struct ));
}
int  openmp_split_pass_E_particle_vlo_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_split_pass_E_particle_vlo_exec (openmp_split_pass_E_particle_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_split_pass_E_particle_vlo_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_inoutput (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_xyzw (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_cu_cache (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_cu_xyzw (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_fieldE (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_fieldB (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_FoutJ (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_FoutEN (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_XLEN (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_YLEN (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_ZLEN (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_ovlp (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_numvec (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_num_ele (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_grid_cache_len (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_cu_cache_length (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_Mass (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_Charge (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_SPEC (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_NUM_SPEC (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_DELTA_X (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_DELTA_Y (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_DELTA_Z (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_Deltat (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_split_pass_E_particle_init (openmp_pscmc_env *  pe ,openmp_split_pass_E_particle_struct *  kerstr ){
	return  0 ;}
void  openmp_split_pass_E_particle_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_split_pass_E_particle_struct ));
}
int  openmp_split_pass_E_particle_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_split_pass_E_particle_exec (openmp_split_pass_E_particle_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_split_pass_E_particle_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_split_pass_E_particle_scmc_set_parameter_inoutput (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_xyzw (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_cu_cache (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_cu_xyzw (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_fieldE (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_fieldB (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_FoutJ (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_FoutEN (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_XLEN (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_YLEN (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_ZLEN (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_ovlp (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_numvec (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_num_ele (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_grid_cache_len (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_cu_cache_length (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_Mass (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_Charge (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_SPEC (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_NUM_SPEC (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_DELTA_X (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_DELTA_Y (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_DELTA_Z (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_split_pass_E_particle_scmc_set_parameter_Deltat (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_init (openmp_pscmc_env *  pe ,openmp_split_pass_z_vlo_small_grids_struct *  kerstr ){
	return  0 ;}
void  openmp_split_pass_z_vlo_small_grids_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_split_pass_z_vlo_small_grids_struct ));
}
int  openmp_split_pass_z_vlo_small_grids_get_xlen (){
	return  1 ;}
int  openmp_split_pass_z_vlo_small_grids_exec (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_split_pass_z_vlo_small_grids_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->LFoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_inoutput (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_xyzw (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_cu_cache (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_cu_xyzw (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_fieldE (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_fieldB (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_LFoutJ (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->LFoutJ = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_FoutEN (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_XLEN (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_YLEN (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_ZLEN (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_ovlp (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_numvec (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_num_ele (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_grid_cache_len (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_cu_cache_length (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_Mass (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_Charge (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_SPEC (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_NUM_SPEC (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_DELTA_X (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_DELTA_Y (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_DELTA_Z (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_Deltat (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_split_pass_z_small_grids_init (openmp_pscmc_env *  pe ,openmp_split_pass_z_small_grids_struct *  kerstr ){
	return  0 ;}
void  openmp_split_pass_z_small_grids_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_split_pass_z_small_grids_struct ));
}
int  openmp_split_pass_z_small_grids_get_xlen (){
	return  1 ;}
int  openmp_split_pass_z_small_grids_exec (openmp_split_pass_z_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_split_pass_z_small_grids_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->LFoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_inoutput (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_xyzw (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_cu_cache (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_cu_xyzw (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_fieldE (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_fieldB (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_LFoutJ (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->LFoutJ = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_FoutEN (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_XLEN (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_YLEN (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_ZLEN (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_ovlp (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_numvec (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_num_ele (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_grid_cache_len (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_cu_cache_length (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_Mass (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_Charge (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_SPEC (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_NUM_SPEC (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_DELTA_X (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_DELTA_Y (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_DELTA_Z (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_split_pass_z_small_grids_scmc_set_parameter_Deltat (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_split_pass_z_vlo_init (openmp_pscmc_env *  pe ,openmp_split_pass_z_vlo_struct *  kerstr ){
	return  0 ;}
void  openmp_split_pass_z_vlo_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_split_pass_z_vlo_struct ));
}
int  openmp_split_pass_z_vlo_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_split_pass_z_vlo_exec (openmp_split_pass_z_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_split_pass_z_vlo_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_split_pass_z_vlo_scmc_set_parameter_inoutput (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_xyzw (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_cu_cache (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_cu_xyzw (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_fieldE (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_fieldB (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_FoutJ (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_FoutEN (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_XLEN (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_YLEN (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_ZLEN (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_ovlp (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_numvec (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_num_ele (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_grid_cache_len (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_cu_cache_length (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_Mass (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_Charge (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_SPEC (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_NUM_SPEC (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_DELTA_X (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_DELTA_Y (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_DELTA_Z (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_split_pass_z_vlo_scmc_set_parameter_Deltat (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_split_pass_z_init (openmp_pscmc_env *  pe ,openmp_split_pass_z_struct *  kerstr ){
	return  0 ;}
void  openmp_split_pass_z_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_split_pass_z_struct ));
}
int  openmp_split_pass_z_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_split_pass_z_exec (openmp_split_pass_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_split_pass_z_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_split_pass_z_scmc_set_parameter_inoutput (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_xyzw (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_cu_cache (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_cu_xyzw (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_fieldE (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_fieldB (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_FoutJ (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_FoutEN (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_XLEN (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_YLEN (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_ZLEN (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_ovlp (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_numvec (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_num_ele (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_grid_cache_len (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_cu_cache_length (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_Mass (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_Charge (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_SPEC (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_NUM_SPEC (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_DELTA_X (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_DELTA_Y (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_DELTA_Z (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_split_pass_z_scmc_set_parameter_Deltat (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_init (openmp_pscmc_env *  pe ,openmp_split_pass_y_vlo_small_grids_struct *  kerstr ){
	return  0 ;}
void  openmp_split_pass_y_vlo_small_grids_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_split_pass_y_vlo_small_grids_struct ));
}
int  openmp_split_pass_y_vlo_small_grids_get_xlen (){
	return  1 ;}
int  openmp_split_pass_y_vlo_small_grids_exec (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_split_pass_y_vlo_small_grids_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->LFoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_inoutput (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_xyzw (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_cu_cache (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_cu_xyzw (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_fieldE (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_fieldB (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_LFoutJ (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->LFoutJ = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_FoutEN (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_XLEN (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_YLEN (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_ZLEN (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_ovlp (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_numvec (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_num_ele (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_grid_cache_len (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_cu_cache_length (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_Mass (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_Charge (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_SPEC (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_NUM_SPEC (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_DELTA_X (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_DELTA_Y (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_DELTA_Z (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_Deltat (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_split_pass_y_small_grids_init (openmp_pscmc_env *  pe ,openmp_split_pass_y_small_grids_struct *  kerstr ){
	return  0 ;}
void  openmp_split_pass_y_small_grids_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_split_pass_y_small_grids_struct ));
}
int  openmp_split_pass_y_small_grids_get_xlen (){
	return  1 ;}
int  openmp_split_pass_y_small_grids_exec (openmp_split_pass_y_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_split_pass_y_small_grids_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->LFoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_inoutput (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_xyzw (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_cu_cache (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_cu_xyzw (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_fieldE (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_fieldB (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_LFoutJ (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->LFoutJ = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_FoutEN (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_XLEN (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_YLEN (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_ZLEN (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_ovlp (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_numvec (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_num_ele (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_grid_cache_len (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_cu_cache_length (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_Mass (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_Charge (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_SPEC (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_NUM_SPEC (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_DELTA_X (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_DELTA_Y (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_DELTA_Z (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_split_pass_y_small_grids_scmc_set_parameter_Deltat (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_split_pass_y_vlo_init (openmp_pscmc_env *  pe ,openmp_split_pass_y_vlo_struct *  kerstr ){
	return  0 ;}
void  openmp_split_pass_y_vlo_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_split_pass_y_vlo_struct ));
}
int  openmp_split_pass_y_vlo_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_split_pass_y_vlo_exec (openmp_split_pass_y_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_split_pass_y_vlo_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_split_pass_y_vlo_scmc_set_parameter_inoutput (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_xyzw (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_cu_cache (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_cu_xyzw (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_fieldE (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_fieldB (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_FoutJ (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_FoutEN (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_XLEN (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_YLEN (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_ZLEN (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_ovlp (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_numvec (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_num_ele (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_grid_cache_len (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_cu_cache_length (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_Mass (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_Charge (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_SPEC (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_NUM_SPEC (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_DELTA_X (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_DELTA_Y (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_DELTA_Z (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_split_pass_y_vlo_scmc_set_parameter_Deltat (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_split_pass_y_init (openmp_pscmc_env *  pe ,openmp_split_pass_y_struct *  kerstr ){
	return  0 ;}
void  openmp_split_pass_y_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_split_pass_y_struct ));
}
int  openmp_split_pass_y_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_split_pass_y_exec (openmp_split_pass_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_split_pass_y_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_split_pass_y_scmc_set_parameter_inoutput (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_xyzw (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_cu_cache (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_cu_xyzw (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_fieldE (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_fieldB (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_FoutJ (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_FoutEN (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_XLEN (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_YLEN (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_ZLEN (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_ovlp (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_numvec (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_num_ele (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_grid_cache_len (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_cu_cache_length (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_Mass (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_Charge (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_SPEC (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_NUM_SPEC (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_DELTA_X (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_DELTA_Y (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_DELTA_Z (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_split_pass_y_scmc_set_parameter_Deltat (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_init (openmp_pscmc_env *  pe ,openmp_split_pass_x_vlo_small_grids_struct *  kerstr ){
	return  0 ;}
void  openmp_split_pass_x_vlo_small_grids_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_split_pass_x_vlo_small_grids_struct ));
}
int  openmp_split_pass_x_vlo_small_grids_get_xlen (){
	return  1 ;}
int  openmp_split_pass_x_vlo_small_grids_exec (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_split_pass_x_vlo_small_grids_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->LFoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_inoutput (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_xyzw (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_cu_cache (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_cu_xyzw (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_fieldE (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_fieldB (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_LFoutJ (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->LFoutJ = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_FoutEN (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_XLEN (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_YLEN (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_ZLEN (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_ovlp (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_numvec (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_num_ele (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_grid_cache_len (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_cu_cache_length (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_Mass (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_Charge (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_SPEC (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_NUM_SPEC (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_DELTA_X (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_DELTA_Y (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_DELTA_Z (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_Deltat (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_split_pass_x_small_grids_init (openmp_pscmc_env *  pe ,openmp_split_pass_x_small_grids_struct *  kerstr ){
	return  0 ;}
void  openmp_split_pass_x_small_grids_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_split_pass_x_small_grids_struct ));
}
int  openmp_split_pass_x_small_grids_get_xlen (){
	return  1 ;}
int  openmp_split_pass_x_small_grids_exec (openmp_split_pass_x_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_split_pass_x_small_grids_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->LFoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_inoutput (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_xyzw (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_cu_cache (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_cu_xyzw (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_fieldE (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_fieldB (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_LFoutJ (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->LFoutJ = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_FoutEN (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_XLEN (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_YLEN (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_ZLEN (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_ovlp (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_numvec (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_num_ele (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_grid_cache_len (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_cu_cache_length (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_Mass (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_Charge (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_SPEC (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_NUM_SPEC (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_DELTA_X (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_DELTA_Y (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_DELTA_Z (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_split_pass_x_small_grids_scmc_set_parameter_Deltat (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_split_pass_x_vlo_init (openmp_pscmc_env *  pe ,openmp_split_pass_x_vlo_struct *  kerstr ){
	return  0 ;}
void  openmp_split_pass_x_vlo_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_split_pass_x_vlo_struct ));
}
int  openmp_split_pass_x_vlo_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_split_pass_x_vlo_exec (openmp_split_pass_x_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_split_pass_x_vlo_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_split_pass_x_vlo_scmc_set_parameter_inoutput (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_xyzw (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_cu_cache (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_cu_xyzw (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_fieldE (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_fieldB (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_FoutJ (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_FoutEN (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_XLEN (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_YLEN (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_ZLEN (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_ovlp (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_numvec (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_num_ele (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_grid_cache_len (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_cu_cache_length (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_Mass (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_Charge (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_SPEC (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_NUM_SPEC (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_DELTA_X (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_DELTA_Y (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_DELTA_Z (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_split_pass_x_vlo_scmc_set_parameter_Deltat (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_split_pass_x_init (openmp_pscmc_env *  pe ,openmp_split_pass_x_struct *  kerstr ){
	return  0 ;}
void  openmp_split_pass_x_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_split_pass_x_struct ));
}
int  openmp_split_pass_x_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_split_pass_x_exec (openmp_split_pass_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_split_pass_x_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_split_pass_x_scmc_set_parameter_inoutput (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_xyzw (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_cu_cache (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_cu_xyzw (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_fieldE (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_fieldB (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_FoutJ (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_FoutEN (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_XLEN (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_YLEN (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_ZLEN (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_ovlp (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_numvec (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_num_ele (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_grid_cache_len (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_cu_cache_length (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_Mass (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_Charge (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_SPEC (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_NUM_SPEC (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_DELTA_X (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_DELTA_Y (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_DELTA_Z (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_split_pass_x_scmc_set_parameter_Deltat (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
