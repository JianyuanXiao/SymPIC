#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "openmp_pscmc_inc.h"
#include "geo_yeefdtd_rect.kernel_inc.h"
int  openmp_RECT_YEE_CURL_L_init (openmp_pscmc_env *  pe ,openmp_RECT_YEE_CURL_L_struct *  kerstr ){
	return  0 ;}
void  openmp_RECT_YEE_CURL_L_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_RECT_YEE_CURL_L_struct ));
}
int  openmp_RECT_YEE_CURL_L_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_RECT_YEE_CURL_L_exec (openmp_RECT_YEE_CURL_L_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_RECT_YEE_CURL_L_scmc_kernel ( 	( kerstr )->inoutE1 , 	( kerstr )->inB0 , 	( kerstr )->xoffset , 	( kerstr )->yoffset , 	( kerstr )->zoffset , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , (	( kerstr )->DELTA_X)[0] , (	( kerstr )->DELTA_Y)[0] , (	( kerstr )->DELTA_Z)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_inoutE1 (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutE1 = pm->d_data);
}
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_inB0 (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inB0 = pm->d_data);
}
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_xoffset (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xoffset = pm->d_data);
}
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_yoffset (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yoffset = pm->d_data);
}
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_zoffset (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zoffset = pm->d_data);
}
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_y_cpu_core (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_numvec (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_XLEN (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_YLEN (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_ZLEN (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_ovlp (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_xblock (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_yblock (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_zblock (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_num_ele (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_DT (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_DELTA_X (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_X = pm->d_data);
}
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_DELTA_Y (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Y = pm->d_data);
}
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_DELTA_Z (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DELTA_Z = pm->d_data);
}
