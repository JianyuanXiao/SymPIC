#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "c_pscmc_inc.h"
#include "implicit_particle_mover.kernel_inc.h"
int  c_split_pass_xyzE_particle_push_r_init (c_pscmc_env *  pe ,c_split_pass_xyzE_particle_push_r_struct *  kerstr ){
	return  0 ;}
void  c_split_pass_xyzE_particle_push_r_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_split_pass_xyzE_particle_push_r_struct ));
}
int  c_split_pass_xyzE_particle_push_r_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_split_pass_xyzE_particle_push_r_get_num_compute_units (c_split_pass_xyzE_particle_push_r_struct *  kerstr ){
	return  1 ;}
int  c_split_pass_xyzE_particle_push_r_exec (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_split_pass_xyzE_particle_push_r_scmc_kernel ( 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->N_l)[0] , (	( kerstr )->N_M)[0] , (	( kerstr )->push_J)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_xyzw (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_cu_cache (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_cu_xyzw (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_fieldE (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_fieldB (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_FoutJ (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_XLEN (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_YLEN (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_ZLEN (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_ovlp (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_numvec (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_num_ele (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_grid_cache_len (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_cu_cache_length (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_Mass0 (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_Charge0 (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_Deltat (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_DELTA_X (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_DELTA_Y (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_DELTA_Z (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_N_l (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->N_l = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_N_M (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->N_M = pm->d_data);
}
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_push_J (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->push_J = pm->d_data);
}
int  c_split_pass_xyzE_particle_init (c_pscmc_env *  pe ,c_split_pass_xyzE_particle_struct *  kerstr ){
	return  0 ;}
void  c_split_pass_xyzE_particle_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_split_pass_xyzE_particle_struct ));
}
int  c_split_pass_xyzE_particle_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_split_pass_xyzE_particle_get_num_compute_units (c_split_pass_xyzE_particle_struct *  kerstr ){
	return  1 ;}
int  c_split_pass_xyzE_particle_exec (c_split_pass_xyzE_particle_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_split_pass_xyzE_particle_scmc_kernel ( 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->N_l)[0] , (	( kerstr )->N_M)[0] , (	( kerstr )->push_J)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_split_pass_xyzE_particle_scmc_set_parameter_xyzw (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_cu_cache (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_cu_xyzw (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_fieldE (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_fieldB (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_FoutJ (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_XLEN (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_YLEN (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_ZLEN (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_ovlp (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_numvec (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_num_ele (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_grid_cache_len (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_cu_cache_length (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_Mass0 (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_Charge0 (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_Deltat (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_DELTA_X (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_DELTA_Y (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_DELTA_Z (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_N_l (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->N_l = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_N_M (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->N_M = pm->d_data);
}
int  c_split_pass_xyzE_particle_scmc_set_parameter_push_J (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->push_J = pm->d_data);
}
