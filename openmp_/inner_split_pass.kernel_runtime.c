#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "openmp_pscmc_inc.h"
#include "inner_split_pass.kernel_inc.h"
int  openmp_geo_nr_Bfield_pushJ_vlo_init (openmp_pscmc_env *  pe ,openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ){
	return  0 ;}
void  openmp_geo_nr_Bfield_pushJ_vlo_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_geo_nr_Bfield_pushJ_vlo_struct ));
}
int  openmp_geo_nr_Bfield_pushJ_vlo_get_num_compute_units (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_geo_nr_Bfield_pushJ_vlo_get_xlen (){
	return  1 ;}
int  openmp_geo_nr_Bfield_pushJ_vlo_exec (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_geo_nr_Bfield_pushJ_vlo_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->xoffset , 	( kerstr )->yoffset , 	( kerstr )->zoffset , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->fieldB1 , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->Tori_X0)[0] , (	( kerstr )->r0)[0] , (	( kerstr )->MIN_R0)[0] , (	( kerstr )->Q0)[0] , (	( kerstr )->b0)[0] , (	( kerstr )->zmid)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_inoutput (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_xyzw (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_cache (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_xyzw (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_xoffset (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xoffset = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_yoffset (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yoffset = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_zoffset (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zoffset = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldE (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldB (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldB1 (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB1 = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_FoutJ (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_XLEN (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_YLEN (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_ZLEN (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_ovlp (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_numvec (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_num_ele (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_grid_cache_len (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_cache_length (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_X (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_Y (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_Z (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Mass0 (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Charge0 (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Deltat (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Tori_X0 (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Tori_X0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_r0 (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->r0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_MIN_R0 (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->MIN_R0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Q0 (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Q0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_b0 (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->b0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_zmid (openmp_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zmid = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_init (openmp_pscmc_env *  pe ,openmp_geo_nr_Bfield_pushJ_struct *  kerstr ){
	return  0 ;}
void  openmp_geo_nr_Bfield_pushJ_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_geo_nr_Bfield_pushJ_struct ));
}
int  openmp_geo_nr_Bfield_pushJ_get_num_compute_units (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_geo_nr_Bfield_pushJ_get_xlen (){
	return  1 ;}
int  openmp_geo_nr_Bfield_pushJ_exec (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_geo_nr_Bfield_pushJ_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->xoffset , 	( kerstr )->yoffset , 	( kerstr )->zoffset , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->fieldB1 , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->Tori_X0)[0] , (	( kerstr )->r0)[0] , (	( kerstr )->MIN_R0)[0] , (	( kerstr )->Q0)[0] , (	( kerstr )->b0)[0] , (	( kerstr )->zmid)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_inoutput (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_xyzw (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_cu_cache (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_cu_xyzw (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_xoffset (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xoffset = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_yoffset (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yoffset = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_zoffset (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zoffset = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_fieldE (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_fieldB (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_fieldB1 (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB1 = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_FoutJ (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_XLEN (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_YLEN (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_ZLEN (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_ovlp (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_numvec (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_num_ele (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_grid_cache_len (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_cu_cache_length (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_DELTA_X (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_DELTA_Y (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_DELTA_Z (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_Mass0 (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_Charge0 (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_Deltat (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_Tori_X0 (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Tori_X0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_r0 (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->r0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_MIN_R0 (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->MIN_R0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_Q0 (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Q0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_b0 (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->b0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_pushJ_scmc_set_parameter_zmid (openmp_geo_nr_Bfield_pushJ_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zmid = pm->d_data);
}
int  openmp_geo_nr_Bfield_init (openmp_pscmc_env *  pe ,openmp_geo_nr_Bfield_struct *  kerstr ){
	return  0 ;}
void  openmp_geo_nr_Bfield_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_geo_nr_Bfield_struct ));
}
int  openmp_geo_nr_Bfield_get_num_compute_units (openmp_geo_nr_Bfield_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_geo_nr_Bfield_get_xlen (){
	return  1 ;}
int  openmp_geo_nr_Bfield_exec (openmp_geo_nr_Bfield_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_geo_nr_Bfield_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->xoffset , 	( kerstr )->yoffset , 	( kerstr )->zoffset , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->fieldB1 , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->Tori_X0)[0] , (	( kerstr )->r0)[0] , (	( kerstr )->MIN_R0)[0] , (	( kerstr )->Q0)[0] , (	( kerstr )->b0)[0] , (	( kerstr )->zmid)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_geo_nr_Bfield_scmc_set_parameter_inoutput (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_xyzw (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_cu_cache (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_cu_xyzw (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_xoffset (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xoffset = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_yoffset (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yoffset = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_zoffset (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zoffset = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_fieldE (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_fieldB (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_fieldB1 (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB1 = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_FoutJ (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_XLEN (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_YLEN (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_ZLEN (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_ovlp (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_numvec (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_num_ele (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_grid_cache_len (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_cu_cache_length (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_DELTA_X (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_DELTA_Y (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_DELTA_Z (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_Mass0 (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_Charge0 (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_Deltat (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_Tori_X0 (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Tori_X0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_r0 (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->r0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_MIN_R0 (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->MIN_R0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_Q0 (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Q0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_b0 (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->b0 = pm->d_data);
}
int  openmp_geo_nr_Bfield_scmc_set_parameter_zmid (openmp_geo_nr_Bfield_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zmid = pm->d_data);
}
int  openmp_geo_nr_vlo_init (openmp_pscmc_env *  pe ,openmp_geo_nr_vlo_struct *  kerstr ){
	return  0 ;}
void  openmp_geo_nr_vlo_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_geo_nr_vlo_struct ));
}
int  openmp_geo_nr_vlo_get_num_compute_units (openmp_geo_nr_vlo_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_geo_nr_vlo_get_xlen (){
	return  1 ;}
int  openmp_geo_nr_vlo_exec (openmp_geo_nr_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_geo_nr_vlo_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->xoffset , 	( kerstr )->yoffset , 	( kerstr )->zoffset , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->fieldB1 , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->Tori_X0)[0] , (	( kerstr )->r0)[0] , (	( kerstr )->MIN_R0)[0] , (	( kerstr )->Q0)[0] , (	( kerstr )->b0)[0] , (	( kerstr )->zmid)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_geo_nr_vlo_scmc_set_parameter_inoutput (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_xyzw (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_cu_cache (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_cu_xyzw (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_xoffset (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xoffset = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_yoffset (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yoffset = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_zoffset (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zoffset = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_fieldE (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_fieldB (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_fieldB1 (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB1 = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_FoutJ (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_XLEN (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_YLEN (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_ZLEN (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_ovlp (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_numvec (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_num_ele (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_grid_cache_len (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_cu_cache_length (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_DELTA_X (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_DELTA_Y (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_DELTA_Z (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_Mass0 (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_Charge0 (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_Deltat (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_Tori_X0 (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Tori_X0 = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_r0 (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->r0 = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_MIN_R0 (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->MIN_R0 = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_Q0 (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Q0 = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_b0 (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->b0 = pm->d_data);
}
int  openmp_geo_nr_vlo_scmc_set_parameter_zmid (openmp_geo_nr_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zmid = pm->d_data);
}
int  openmp_geo_nr_init (openmp_pscmc_env *  pe ,openmp_geo_nr_struct *  kerstr ){
	return  0 ;}
void  openmp_geo_nr_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_geo_nr_struct ));
}
int  openmp_geo_nr_get_num_compute_units (openmp_geo_nr_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_geo_nr_get_xlen (){
	return  1 ;}
int  openmp_geo_nr_exec (openmp_geo_nr_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_geo_nr_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->xoffset , 	( kerstr )->yoffset , 	( kerstr )->zoffset , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->fieldB1 , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->Tori_X0)[0] , (	( kerstr )->r0)[0] , (	( kerstr )->MIN_R0)[0] , (	( kerstr )->Q0)[0] , (	( kerstr )->b0)[0] , (	( kerstr )->zmid)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_geo_nr_scmc_set_parameter_inoutput (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_xyzw (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_cu_cache (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_cu_xyzw (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_xoffset (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xoffset = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_yoffset (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yoffset = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_zoffset (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zoffset = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_fieldE (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_fieldB (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_fieldB1 (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB1 = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_FoutJ (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_XLEN (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_YLEN (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_ZLEN (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_ovlp (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_numvec (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_num_ele (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_grid_cache_len (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_cu_cache_length (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_DELTA_X (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_DELTA_Y (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_DELTA_Z (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_Mass0 (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_Charge0 (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_Deltat (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_Tori_X0 (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Tori_X0 = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_r0 (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->r0 = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_MIN_R0 (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->MIN_R0 = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_Q0 (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Q0 = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_b0 (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->b0 = pm->d_data);
}
int  openmp_geo_nr_scmc_set_parameter_zmid (openmp_geo_nr_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zmid = pm->d_data);
}
int  openmp_ngeo_gc_init (openmp_pscmc_env *  pe ,openmp_ngeo_gc_struct *  kerstr ){
	return  0 ;}
void  openmp_ngeo_gc_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_ngeo_gc_struct ));
}
int  openmp_ngeo_gc_get_num_compute_units (openmp_ngeo_gc_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_ngeo_gc_get_xlen (){
	return  1 ;}
int  openmp_ngeo_gc_exec (openmp_ngeo_gc_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_ngeo_gc_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , 	( kerstr )->xoffset , 	( kerstr )->yoffset , 	( kerstr )->zoffset , 	( kerstr )->fieldE , 	( kerstr )->fieldB , 	( kerstr )->fieldB1 , 	( kerstr )->FoutJ , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , (	( kerstr )->Mass0)[0] , (	( kerstr )->Charge0)[0] , (	( kerstr )->Deltat)[0] , (	( kerstr )->Tori_X0)[0] , (	( kerstr )->r0)[0] , (	( kerstr )->MIN_R0)[0] , (	( kerstr )->Q0)[0] , (	( kerstr )->b0)[0] , (	( kerstr )->zmid)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_ngeo_gc_scmc_set_parameter_inoutput (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_xyzw (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_cu_cache (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_cu_xyzw (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_xoffset (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xoffset = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_yoffset (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yoffset = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_zoffset (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zoffset = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_fieldE (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldE = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_fieldB (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_fieldB1 (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->fieldB1 = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_FoutJ (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->FoutJ = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_XLEN (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_YLEN (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_ZLEN (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_ovlp (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_numvec (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_num_ele (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_grid_cache_len (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_cu_cache_length (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_DELTA_X (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_DELTA_Y (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_DELTA_Z (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_Mass0 (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Mass0 = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_Charge0 (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Charge0 = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_Deltat (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Deltat = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_Tori_X0 (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Tori_X0 = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_r0 (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->r0 = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_MIN_R0 (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->MIN_R0 = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_Q0 (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Q0 = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_b0 (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->b0 = pm->d_data);
}
int  openmp_ngeo_gc_scmc_set_parameter_zmid (openmp_ngeo_gc_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zmid = pm->d_data);
}
