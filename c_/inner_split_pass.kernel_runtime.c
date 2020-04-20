#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "c_pscmc_inc.h"
#include "inner_split_pass.kernel_inc.h"
int  c_geo_nr_Bfield_pushJ_vlo_init (c_pscmc_env *  pe ,c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ){
	return  0 ;}
void  c_geo_nr_Bfield_pushJ_vlo_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_geo_nr_Bfield_pushJ_vlo_struct ));
}
int  c_geo_nr_Bfield_pushJ_vlo_get_xlen (){
	return  1 ;}
int  c_geo_nr_Bfield_pushJ_vlo_get_num_compute_units (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ){
	return  1 ;}
int  c_geo_nr_Bfield_pushJ_vlo_exec (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_geo_nr_Bfield_pushJ_vlo_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->xoffset , 	( kerstr )->yoffset , 	( kerstr )->zoffset , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->fieldB1 , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->Tori_X0)[0] , (	( kerstr )->r0)[0] , (	( kerstr )->MIN_R0)[0] , (	( kerstr )->Q0)[0] , (	( kerstr )->b0)[0] , (	( kerstr )->zmid)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_inoutput (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_xyzw (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_cache (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_xyzw (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_xoffset (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xoffset = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_yoffset (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yoffset = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_zoffset (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zoffset = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldE (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldB (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldB1 (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB1 = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_FoutJ (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_XLEN (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_YLEN (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_ZLEN (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_ovlp (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_numvec (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_num_ele (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_grid_cache_len (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_cache_length (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_X (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_Y (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_Z (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Mass0 (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Charge0 (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Deltat (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Tori_X0 (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Tori_X0 = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_r0 (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->r0 = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_MIN_R0 (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->MIN_R0 = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Q0 (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Q0 = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_b0 (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->b0 = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_zmid (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zmid = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_init (c_pscmc_env *  pe ,c_geo_nr_Bfield_pushJ_struct *  kerstr ){
	return  0 ;}
void  c_geo_nr_Bfield_pushJ_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_geo_nr_Bfield_pushJ_struct ));
}
int  c_geo_nr_Bfield_pushJ_get_xlen (){
	return  1 ;}
int  c_geo_nr_Bfield_pushJ_get_num_compute_units (c_geo_nr_Bfield_pushJ_struct *  kerstr ){
	return  1 ;}
int  c_geo_nr_Bfield_pushJ_exec (c_geo_nr_Bfield_pushJ_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_geo_nr_Bfield_pushJ_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->xoffset , 	( kerstr )->yoffset , 	( kerstr )->zoffset , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->fieldB1 , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->Tori_X0)[0] , (	( kerstr )->r0)[0] , (	( kerstr )->MIN_R0)[0] , (	( kerstr )->Q0)[0] , (	( kerstr )->b0)[0] , (	( kerstr )->zmid)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_inoutput (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_xyzw (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_cu_cache (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_cu_xyzw (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_xoffset (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xoffset = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_yoffset (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yoffset = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_zoffset (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zoffset = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_fieldE (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_fieldB (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_fieldB1 (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB1 = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_FoutJ (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_XLEN (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_YLEN (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_ZLEN (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_ovlp (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_numvec (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_num_ele (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_grid_cache_len (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_cu_cache_length (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_DELTA_X (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_DELTA_Y (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_DELTA_Z (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_Mass0 (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_Charge0 (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_Deltat (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_Tori_X0 (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Tori_X0 = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_r0 (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->r0 = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_MIN_R0 (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->MIN_R0 = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_Q0 (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Q0 = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_b0 (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->b0 = pm->d_data);
}
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_zmid (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zmid = pm->d_data);
}
int  c_geo_nr_Bfield_init (c_pscmc_env *  pe ,c_geo_nr_Bfield_struct *  kerstr ){
	return  0 ;}
void  c_geo_nr_Bfield_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_geo_nr_Bfield_struct ));
}
int  c_geo_nr_Bfield_get_xlen (){
	return  1 ;}
int  c_geo_nr_Bfield_get_num_compute_units (c_geo_nr_Bfield_struct *  kerstr ){
	return  1 ;}
int  c_geo_nr_Bfield_exec (c_geo_nr_Bfield_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_geo_nr_Bfield_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->xoffset , 	( kerstr )->yoffset , 	( kerstr )->zoffset , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->fieldB1 , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->Tori_X0)[0] , (	( kerstr )->r0)[0] , (	( kerstr )->MIN_R0)[0] , (	( kerstr )->Q0)[0] , (	( kerstr )->b0)[0] , (	( kerstr )->zmid)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_geo_nr_Bfield_scmc_set_parameter_inoutput (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_xyzw (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_cu_cache (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_cu_xyzw (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_xoffset (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xoffset = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_yoffset (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yoffset = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_zoffset (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zoffset = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_fieldE (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_fieldB (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_fieldB1 (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB1 = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_FoutJ (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_XLEN (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_YLEN (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_ZLEN (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_ovlp (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_numvec (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_num_ele (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_grid_cache_len (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_cu_cache_length (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_DELTA_X (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_DELTA_Y (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_DELTA_Z (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_Mass0 (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_Charge0 (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_Deltat (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_Tori_X0 (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Tori_X0 = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_r0 (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->r0 = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_MIN_R0 (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->MIN_R0 = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_Q0 (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Q0 = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_b0 (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->b0 = pm->d_data);
}
int  c_geo_nr_Bfield_scmc_set_parameter_zmid (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zmid = pm->d_data);
}
int  c_geo_nr_vlo_init (c_pscmc_env *  pe ,c_geo_nr_vlo_struct *  kerstr ){
	return  0 ;}
void  c_geo_nr_vlo_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_geo_nr_vlo_struct ));
}
int  c_geo_nr_vlo_get_xlen (){
	return  1 ;}
int  c_geo_nr_vlo_get_num_compute_units (c_geo_nr_vlo_struct *  kerstr ){
	return  1 ;}
int  c_geo_nr_vlo_exec (c_geo_nr_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_geo_nr_vlo_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->xoffset , 	( kerstr )->yoffset , 	( kerstr )->zoffset , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->fieldB1 , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->Tori_X0)[0] , (	( kerstr )->r0)[0] , (	( kerstr )->MIN_R0)[0] , (	( kerstr )->Q0)[0] , (	( kerstr )->b0)[0] , (	( kerstr )->zmid)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_geo_nr_vlo_scmc_set_parameter_inoutput (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_xyzw (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_cu_cache (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_cu_xyzw (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_xoffset (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xoffset = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_yoffset (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yoffset = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_zoffset (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zoffset = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_fieldE (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_fieldB (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_fieldB1 (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB1 = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_FoutJ (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_XLEN (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_YLEN (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_ZLEN (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_ovlp (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_numvec (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_num_ele (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_grid_cache_len (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_cu_cache_length (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_DELTA_X (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_DELTA_Y (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_DELTA_Z (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_Mass0 (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_Charge0 (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_Deltat (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_Tori_X0 (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Tori_X0 = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_r0 (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->r0 = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_MIN_R0 (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->MIN_R0 = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_Q0 (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Q0 = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_b0 (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->b0 = pm->d_data);
}
int  c_geo_nr_vlo_scmc_set_parameter_zmid (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zmid = pm->d_data);
}
int  c_geo_nr_init (c_pscmc_env *  pe ,c_geo_nr_struct *  kerstr ){
	return  0 ;}
void  c_geo_nr_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_geo_nr_struct ));
}
int  c_geo_nr_get_xlen (){
	return  1 ;}
int  c_geo_nr_get_num_compute_units (c_geo_nr_struct *  kerstr ){
	return  1 ;}
int  c_geo_nr_exec (c_geo_nr_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_geo_nr_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->xoffset , 	( kerstr )->yoffset , 	( kerstr )->zoffset , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->fieldB1 , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->Tori_X0)[0] , (	( kerstr )->r0)[0] , (	( kerstr )->MIN_R0)[0] , (	( kerstr )->Q0)[0] , (	( kerstr )->b0)[0] , (	( kerstr )->zmid)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_geo_nr_scmc_set_parameter_inoutput (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_xyzw (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_cu_cache (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_cu_xyzw (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_xoffset (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xoffset = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_yoffset (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yoffset = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_zoffset (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zoffset = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_fieldE (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_fieldB (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_fieldB1 (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB1 = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_FoutJ (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_XLEN (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_YLEN (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_ZLEN (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_ovlp (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_numvec (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_num_ele (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_grid_cache_len (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_cu_cache_length (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_DELTA_X (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_DELTA_Y (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_DELTA_Z (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_Mass0 (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_Charge0 (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_Deltat (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_Tori_X0 (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Tori_X0 = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_r0 (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->r0 = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_MIN_R0 (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->MIN_R0 = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_Q0 (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Q0 = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_b0 (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->b0 = pm->d_data);
}
int  c_geo_nr_scmc_set_parameter_zmid (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zmid = pm->d_data);
}
int  c_ngeo_gc_init (c_pscmc_env *  pe ,c_ngeo_gc_struct *  kerstr ){
	return  0 ;}
void  c_ngeo_gc_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_ngeo_gc_struct ));
}
int  c_ngeo_gc_get_xlen (){
	return  1 ;}
int  c_ngeo_gc_get_num_compute_units (c_ngeo_gc_struct *  kerstr ){
	return  1 ;}
int  c_ngeo_gc_exec (c_ngeo_gc_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_ngeo_gc_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->xoffset , 	( kerstr )->yoffset , 	( kerstr )->zoffset , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->fieldB1 , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->Tori_X0)[0] , (	( kerstr )->r0)[0] , (	( kerstr )->MIN_R0)[0] , (	( kerstr )->Q0)[0] , (	( kerstr )->b0)[0] , (	( kerstr )->zmid)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_ngeo_gc_scmc_set_parameter_inoutput (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_xyzw (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_cu_cache (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_cu_xyzw (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_xoffset (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xoffset = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_yoffset (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yoffset = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_zoffset (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zoffset = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_fieldE (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_fieldB (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_fieldB1 (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->fieldB1 = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_FoutJ (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_XLEN (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_YLEN (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_ZLEN (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_ovlp (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_numvec (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_num_ele (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_grid_cache_len (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_cu_cache_length (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_DELTA_X (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_DELTA_Y (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_DELTA_Z (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_Mass0 (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_Charge0 (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_Deltat (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_Tori_X0 (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Tori_X0 = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_r0 (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->r0 = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_MIN_R0 (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->MIN_R0 = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_Q0 (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Q0 = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_b0 (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->b0 = pm->d_data);
}
int  c_ngeo_gc_scmc_set_parameter_zmid (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zmid = pm->d_data);
}
