#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "c_pscmc_inc.h"
#include "particle_iter.kernel_inc.h"
int  c_dump_ene_num_init (c_pscmc_env *  pe ,c_dump_ene_num_struct *  kerstr ){
	return  0 ;}
void  c_dump_ene_num_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_dump_ene_num_struct ));
}
int  c_dump_ene_num_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_dump_ene_num_exec (c_dump_ene_num_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_dump_ene_num_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_dump_ene_num_scmc_set_parameter_inoutput (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_xyzw (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_cu_cache (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_cu_xyzw (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_fieldE (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_fieldB (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_FoutJ (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_FoutEN (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_XLEN (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_YLEN (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_ZLEN (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_ovlp (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_numvec (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_num_ele (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_grid_cache_len (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_cu_cache_length (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_Mass (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_Charge (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_SPEC (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_NUM_SPEC (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_DELTA_X (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_DELTA_Y (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_DELTA_Z (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_dump_ene_num_scmc_set_parameter_Deltat (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_calculate_rho_init (c_pscmc_env *  pe ,c_calculate_rho_struct *  kerstr ){
	return  0 ;}
void  c_calculate_rho_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_calculate_rho_struct ));
}
int  c_calculate_rho_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_calculate_rho_exec (c_calculate_rho_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_calculate_rho_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_calculate_rho_scmc_set_parameter_inoutput (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_xyzw (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_cu_cache (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_cu_xyzw (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_fieldE (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_fieldB (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_FoutJ (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_FoutEN (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_XLEN (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_YLEN (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_ZLEN (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_ovlp (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_numvec (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_num_ele (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_grid_cache_len (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_cu_cache_length (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_Mass (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_Charge (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_SPEC (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_NUM_SPEC (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_DELTA_X (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_DELTA_Y (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_DELTA_Z (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_calculate_rho_scmc_set_parameter_Deltat (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_krook_collision_test_init (c_pscmc_env *  pe ,c_krook_collision_test_struct *  kerstr ){
	return  0 ;}
void  c_krook_collision_test_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_krook_collision_test_struct ));
}
int  c_krook_collision_test_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_krook_collision_test_exec (c_krook_collision_test_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_krook_collision_test_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->mu_freq)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_krook_collision_test_scmc_set_parameter_inoutput (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_krook_collision_test_scmc_set_parameter_xyzw (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_krook_collision_test_scmc_set_parameter_cu_cache (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_krook_collision_test_scmc_set_parameter_cu_xyzw (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_krook_collision_test_scmc_set_parameter_fieldE (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_krook_collision_test_scmc_set_parameter_fieldB (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_krook_collision_test_scmc_set_parameter_FoutJ (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_krook_collision_test_scmc_set_parameter_XLEN (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_krook_collision_test_scmc_set_parameter_YLEN (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_krook_collision_test_scmc_set_parameter_ZLEN (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_krook_collision_test_scmc_set_parameter_ovlp (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_krook_collision_test_scmc_set_parameter_numvec (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_krook_collision_test_scmc_set_parameter_num_ele (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_krook_collision_test_scmc_set_parameter_grid_cache_len (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_krook_collision_test_scmc_set_parameter_cu_cache_length (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_krook_collision_test_scmc_set_parameter_Mass0 (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  c_krook_collision_test_scmc_set_parameter_Charge0 (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  c_krook_collision_test_scmc_set_parameter_Deltat (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_krook_collision_test_scmc_set_parameter_mu_freq (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->mu_freq = pm->d_data);
}
int  c_krook_collision_remove_small_speed_init (c_pscmc_env *  pe ,c_krook_collision_remove_small_speed_struct *  kerstr ){
	return  0 ;}
void  c_krook_collision_remove_small_speed_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_krook_collision_remove_small_speed_struct ));
}
int  c_krook_collision_remove_small_speed_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_krook_collision_remove_small_speed_exec (c_krook_collision_remove_small_speed_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_krook_collision_remove_small_speed_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->mu_freq)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_krook_collision_remove_small_speed_scmc_set_parameter_inoutput (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_krook_collision_remove_small_speed_scmc_set_parameter_xyzw (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_krook_collision_remove_small_speed_scmc_set_parameter_cu_cache (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_krook_collision_remove_small_speed_scmc_set_parameter_cu_xyzw (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_krook_collision_remove_small_speed_scmc_set_parameter_fieldE (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_krook_collision_remove_small_speed_scmc_set_parameter_fieldB (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_krook_collision_remove_small_speed_scmc_set_parameter_FoutJ (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_krook_collision_remove_small_speed_scmc_set_parameter_XLEN (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_krook_collision_remove_small_speed_scmc_set_parameter_YLEN (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_krook_collision_remove_small_speed_scmc_set_parameter_ZLEN (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_krook_collision_remove_small_speed_scmc_set_parameter_ovlp (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_krook_collision_remove_small_speed_scmc_set_parameter_numvec (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_krook_collision_remove_small_speed_scmc_set_parameter_num_ele (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_krook_collision_remove_small_speed_scmc_set_parameter_grid_cache_len (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_krook_collision_remove_small_speed_scmc_set_parameter_cu_cache_length (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_krook_collision_remove_small_speed_scmc_set_parameter_Mass0 (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  c_krook_collision_remove_small_speed_scmc_set_parameter_Charge0 (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  c_krook_collision_remove_small_speed_scmc_set_parameter_Deltat (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_krook_collision_remove_small_speed_scmc_set_parameter_mu_freq (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->mu_freq = pm->d_data);
}
int  c_boris_yee_init (c_pscmc_env *  pe ,c_boris_yee_struct *  kerstr ){
	return  0 ;}
void  c_boris_yee_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_boris_yee_struct ));
}
int  c_boris_yee_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_boris_yee_exec (c_boris_yee_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_boris_yee_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_boris_yee_scmc_set_parameter_inoutput (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_boris_yee_scmc_set_parameter_xyzw (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_boris_yee_scmc_set_parameter_cu_cache (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_boris_yee_scmc_set_parameter_cu_xyzw (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_boris_yee_scmc_set_parameter_fieldE (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_boris_yee_scmc_set_parameter_fieldB (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_boris_yee_scmc_set_parameter_FoutJ (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_boris_yee_scmc_set_parameter_XLEN (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_boris_yee_scmc_set_parameter_YLEN (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_boris_yee_scmc_set_parameter_ZLEN (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_boris_yee_scmc_set_parameter_ovlp (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_boris_yee_scmc_set_parameter_numvec (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_boris_yee_scmc_set_parameter_num_ele (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_boris_yee_scmc_set_parameter_grid_cache_len (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_boris_yee_scmc_set_parameter_cu_cache_length (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_boris_yee_scmc_set_parameter_Mass0 (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  c_boris_yee_scmc_set_parameter_Charge0 (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  c_boris_yee_scmc_set_parameter_Deltat (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_split_pass_E_particle_vlo_init (c_pscmc_env *  pe ,c_split_pass_E_particle_vlo_struct *  kerstr ){
	return  0 ;}
void  c_split_pass_E_particle_vlo_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_split_pass_E_particle_vlo_struct ));
}
int  c_split_pass_E_particle_vlo_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_split_pass_E_particle_vlo_exec (c_split_pass_E_particle_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_split_pass_E_particle_vlo_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_inoutput (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_xyzw (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_cu_cache (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_cu_xyzw (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_fieldE (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_fieldB (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_FoutJ (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_FoutEN (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_XLEN (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_YLEN (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_ZLEN (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_ovlp (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_numvec (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_num_ele (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_grid_cache_len (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_cu_cache_length (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_Mass (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_Charge (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_SPEC (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_NUM_SPEC (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_DELTA_X (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_DELTA_Y (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_DELTA_Z (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_split_pass_E_particle_vlo_scmc_set_parameter_Deltat (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_split_pass_E_particle_init (c_pscmc_env *  pe ,c_split_pass_E_particle_struct *  kerstr ){
	return  0 ;}
void  c_split_pass_E_particle_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_split_pass_E_particle_struct ));
}
int  c_split_pass_E_particle_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_split_pass_E_particle_exec (c_split_pass_E_particle_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_split_pass_E_particle_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_split_pass_E_particle_scmc_set_parameter_inoutput (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_xyzw (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_cu_cache (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_cu_xyzw (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_fieldE (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_fieldB (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_FoutJ (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_FoutEN (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_XLEN (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_YLEN (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_ZLEN (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_ovlp (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_numvec (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_num_ele (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_grid_cache_len (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_cu_cache_length (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_Mass (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_Charge (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_SPEC (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_NUM_SPEC (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_DELTA_X (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_DELTA_Y (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_DELTA_Z (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_split_pass_E_particle_scmc_set_parameter_Deltat (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_init (c_pscmc_env *  pe ,c_split_pass_z_vlo_small_grids_struct *  kerstr ){
	return  0 ;}
void  c_split_pass_z_vlo_small_grids_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_split_pass_z_vlo_small_grids_struct ));
}
int  c_split_pass_z_vlo_small_grids_get_xlen (){
	return  1 ;}
int  c_split_pass_z_vlo_small_grids_exec (c_split_pass_z_vlo_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_split_pass_z_vlo_small_grids_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->LFoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_inoutput (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_xyzw (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_cu_cache (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_fieldE (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_fieldB (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->LFoutJ = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_FoutEN (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_XLEN (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_YLEN (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_ZLEN (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_ovlp (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_numvec (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_num_ele (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_Mass (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_Charge (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_SPEC (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_Deltat (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_split_pass_z_small_grids_init (c_pscmc_env *  pe ,c_split_pass_z_small_grids_struct *  kerstr ){
	return  0 ;}
void  c_split_pass_z_small_grids_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_split_pass_z_small_grids_struct ));
}
int  c_split_pass_z_small_grids_get_xlen (){
	return  1 ;}
int  c_split_pass_z_small_grids_exec (c_split_pass_z_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_split_pass_z_small_grids_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->LFoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_split_pass_z_small_grids_scmc_set_parameter_inoutput (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_xyzw (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_cu_cache (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_fieldE (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_fieldB (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->LFoutJ = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_FoutEN (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_XLEN (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_YLEN (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_ZLEN (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_ovlp (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_numvec (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_num_ele (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_Mass (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_Charge (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_SPEC (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_split_pass_z_small_grids_scmc_set_parameter_Deltat (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_split_pass_z_vlo_init (c_pscmc_env *  pe ,c_split_pass_z_vlo_struct *  kerstr ){
	return  0 ;}
void  c_split_pass_z_vlo_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_split_pass_z_vlo_struct ));
}
int  c_split_pass_z_vlo_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_split_pass_z_vlo_exec (c_split_pass_z_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_split_pass_z_vlo_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_split_pass_z_vlo_scmc_set_parameter_inoutput (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_xyzw (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_cu_cache (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_cu_xyzw (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_fieldE (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_fieldB (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_FoutJ (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_FoutEN (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_XLEN (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_YLEN (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_ZLEN (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_ovlp (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_numvec (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_num_ele (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_grid_cache_len (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_cu_cache_length (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_Mass (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_Charge (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_SPEC (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_NUM_SPEC (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_DELTA_X (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_DELTA_Y (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_DELTA_Z (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_split_pass_z_vlo_scmc_set_parameter_Deltat (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_split_pass_z_init (c_pscmc_env *  pe ,c_split_pass_z_struct *  kerstr ){
	return  0 ;}
void  c_split_pass_z_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_split_pass_z_struct ));
}
int  c_split_pass_z_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_split_pass_z_exec (c_split_pass_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_split_pass_z_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_split_pass_z_scmc_set_parameter_inoutput (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_xyzw (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_cu_cache (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_cu_xyzw (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_fieldE (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_fieldB (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_FoutJ (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_FoutEN (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_XLEN (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_YLEN (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_ZLEN (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_ovlp (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_numvec (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_num_ele (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_grid_cache_len (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_cu_cache_length (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_Mass (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_Charge (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_SPEC (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_NUM_SPEC (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_DELTA_X (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_DELTA_Y (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_DELTA_Z (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_split_pass_z_scmc_set_parameter_Deltat (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_init (c_pscmc_env *  pe ,c_split_pass_y_vlo_small_grids_struct *  kerstr ){
	return  0 ;}
void  c_split_pass_y_vlo_small_grids_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_split_pass_y_vlo_small_grids_struct ));
}
int  c_split_pass_y_vlo_small_grids_get_xlen (){
	return  1 ;}
int  c_split_pass_y_vlo_small_grids_exec (c_split_pass_y_vlo_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_split_pass_y_vlo_small_grids_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->LFoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_inoutput (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_xyzw (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_cu_cache (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_fieldE (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_fieldB (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->LFoutJ = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_FoutEN (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_XLEN (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_YLEN (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_ZLEN (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_ovlp (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_numvec (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_num_ele (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_Mass (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_Charge (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_SPEC (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_Deltat (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_split_pass_y_small_grids_init (c_pscmc_env *  pe ,c_split_pass_y_small_grids_struct *  kerstr ){
	return  0 ;}
void  c_split_pass_y_small_grids_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_split_pass_y_small_grids_struct ));
}
int  c_split_pass_y_small_grids_get_xlen (){
	return  1 ;}
int  c_split_pass_y_small_grids_exec (c_split_pass_y_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_split_pass_y_small_grids_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->LFoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_split_pass_y_small_grids_scmc_set_parameter_inoutput (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_xyzw (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_cu_cache (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_fieldE (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_fieldB (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->LFoutJ = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_FoutEN (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_XLEN (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_YLEN (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_ZLEN (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_ovlp (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_numvec (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_num_ele (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_Mass (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_Charge (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_SPEC (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_split_pass_y_small_grids_scmc_set_parameter_Deltat (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_split_pass_y_vlo_init (c_pscmc_env *  pe ,c_split_pass_y_vlo_struct *  kerstr ){
	return  0 ;}
void  c_split_pass_y_vlo_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_split_pass_y_vlo_struct ));
}
int  c_split_pass_y_vlo_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_split_pass_y_vlo_exec (c_split_pass_y_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_split_pass_y_vlo_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_split_pass_y_vlo_scmc_set_parameter_inoutput (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_xyzw (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_cu_cache (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_cu_xyzw (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_fieldE (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_fieldB (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_FoutJ (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_FoutEN (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_XLEN (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_YLEN (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_ZLEN (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_ovlp (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_numvec (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_num_ele (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_grid_cache_len (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_cu_cache_length (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_Mass (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_Charge (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_SPEC (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_NUM_SPEC (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_DELTA_X (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_DELTA_Y (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_DELTA_Z (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_split_pass_y_vlo_scmc_set_parameter_Deltat (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_split_pass_y_init (c_pscmc_env *  pe ,c_split_pass_y_struct *  kerstr ){
	return  0 ;}
void  c_split_pass_y_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_split_pass_y_struct ));
}
int  c_split_pass_y_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_split_pass_y_exec (c_split_pass_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_split_pass_y_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_split_pass_y_scmc_set_parameter_inoutput (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_xyzw (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_cu_cache (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_cu_xyzw (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_fieldE (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_fieldB (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_FoutJ (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_FoutEN (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_XLEN (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_YLEN (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_ZLEN (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_ovlp (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_numvec (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_num_ele (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_grid_cache_len (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_cu_cache_length (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_Mass (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_Charge (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_SPEC (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_NUM_SPEC (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_DELTA_X (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_DELTA_Y (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_DELTA_Z (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_split_pass_y_scmc_set_parameter_Deltat (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_init (c_pscmc_env *  pe ,c_split_pass_x_vlo_small_grids_struct *  kerstr ){
	return  0 ;}
void  c_split_pass_x_vlo_small_grids_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_split_pass_x_vlo_small_grids_struct ));
}
int  c_split_pass_x_vlo_small_grids_get_xlen (){
	return  1 ;}
int  c_split_pass_x_vlo_small_grids_exec (c_split_pass_x_vlo_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_split_pass_x_vlo_small_grids_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->LFoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_inoutput (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_xyzw (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_cu_cache (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_fieldE (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_fieldB (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->LFoutJ = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_FoutEN (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_XLEN (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_YLEN (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_ZLEN (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_ovlp (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_numvec (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_num_ele (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_Mass (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_Charge (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_SPEC (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_Deltat (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_split_pass_x_small_grids_init (c_pscmc_env *  pe ,c_split_pass_x_small_grids_struct *  kerstr ){
	return  0 ;}
void  c_split_pass_x_small_grids_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_split_pass_x_small_grids_struct ));
}
int  c_split_pass_x_small_grids_get_xlen (){
	return  1 ;}
int  c_split_pass_x_small_grids_exec (c_split_pass_x_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_split_pass_x_small_grids_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->LFoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_split_pass_x_small_grids_scmc_set_parameter_inoutput (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_xyzw (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_cu_cache (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_fieldE (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_fieldB (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->LFoutJ = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_FoutEN (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_XLEN (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_YLEN (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_ZLEN (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_ovlp (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_numvec (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_num_ele (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_Mass (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_Charge (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_SPEC (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_split_pass_x_small_grids_scmc_set_parameter_Deltat (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_split_pass_x_vlo_init (c_pscmc_env *  pe ,c_split_pass_x_vlo_struct *  kerstr ){
	return  0 ;}
void  c_split_pass_x_vlo_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_split_pass_x_vlo_struct ));
}
int  c_split_pass_x_vlo_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_split_pass_x_vlo_exec (c_split_pass_x_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_split_pass_x_vlo_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_split_pass_x_vlo_scmc_set_parameter_inoutput (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_xyzw (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_cu_cache (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_cu_xyzw (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_fieldE (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_fieldB (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_FoutJ (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_FoutEN (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_XLEN (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_YLEN (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_ZLEN (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_ovlp (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_numvec (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_num_ele (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_grid_cache_len (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_cu_cache_length (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_Mass (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_Charge (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_SPEC (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_NUM_SPEC (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_DELTA_X (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_DELTA_Y (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_DELTA_Z (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_split_pass_x_vlo_scmc_set_parameter_Deltat (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_split_pass_x_init (c_pscmc_env *  pe ,c_split_pass_x_struct *  kerstr ){
	return  0 ;}
void  c_split_pass_x_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_split_pass_x_struct ));
}
int  c_split_pass_x_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_split_pass_x_exec (c_split_pass_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_split_pass_x_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , 	( kerstr )->FoutEN , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass)[0] , (	( kerstr )->Charge)[0] , (	( kerstr )->SPEC)[0] , (	( kerstr )->NUM_SPEC)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_split_pass_x_scmc_set_parameter_inoutput (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_xyzw (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_cu_cache (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_cu_xyzw (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_fieldE (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_fieldB (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_FoutJ (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_FoutEN (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutEN = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_XLEN (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_YLEN (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_ZLEN (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_ovlp (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_numvec (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_num_ele (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_grid_cache_len (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_cu_cache_length (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_Mass (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_Charge (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_SPEC (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->SPEC = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_NUM_SPEC (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->NUM_SPEC = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_DELTA_X (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_DELTA_Y (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_DELTA_Z (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_split_pass_x_scmc_set_parameter_Deltat (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
