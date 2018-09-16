#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "openmp_pscmc_inc.h"
#include "yeefdtd.kernel_inc.h"
int  openmp_kgm_eqn_core_init (openmp_pscmc_env *  pe ,openmp_kgm_eqn_core_struct *  kerstr ){
	return  0 ;}
void  openmp_kgm_eqn_core_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_kgm_eqn_core_struct ));
}
int  openmp_kgm_eqn_core_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_kgm_eqn_core_exec (openmp_kgm_eqn_core_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_kgm_eqn_core_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->xoffset , 	( kerstr )->yoffset , 	( kerstr )->zoffset , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , (	( kerstr )->M)[0] , (	( kerstr )->Q)[0] , (	( kerstr )->DX)[0] , (	( kerstr )->GEXT)[0] , (	( kerstr )->rfz0)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_kgm_eqn_core_scmc_set_parameter_outEB (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_inEB (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_xoffset (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xoffset = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_yoffset (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yoffset = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_zoffset (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zoffset = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_y_cpu_core (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_numvec (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_XLEN (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_YLEN (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_ZLEN (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_ovlp (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_xblock (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_yblock (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_zblock (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_num_ele (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_DT (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_M (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->M = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_Q (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Q = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_DX (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DX = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_GEXT (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->GEXT = pm->d_data);
}
int  openmp_kgm_eqn_core_scmc_set_parameter_rfz0 (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->rfz0 = pm->d_data);
}
int  openmp_merge_current_init (openmp_pscmc_env *  pe ,openmp_merge_current_struct *  kerstr ){
	return  0 ;}
void  openmp_merge_current_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_merge_current_struct ));
}
int  openmp_merge_current_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_merge_current_exec (openmp_merge_current_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_merge_current_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_merge_current_scmc_set_parameter_outEB (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_merge_current_scmc_set_parameter_inEB (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_merge_current_scmc_set_parameter_y_cpu_core (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_merge_current_scmc_set_parameter_numvec (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_merge_current_scmc_set_parameter_XLEN (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_merge_current_scmc_set_parameter_YLEN (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_merge_current_scmc_set_parameter_ZLEN (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_merge_current_scmc_set_parameter_ovlp (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_merge_current_scmc_set_parameter_xblock (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_merge_current_scmc_set_parameter_yblock (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_merge_current_scmc_set_parameter_zblock (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_merge_current_scmc_set_parameter_num_ele (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_4th_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ){
	return  0 ;}
void  openmp_Yee_FDTD_Div_FWD_4th_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_Yee_FDTD_Div_FWD_4th_struct ));
}
int  openmp_Yee_FDTD_Div_FWD_4th_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_Yee_FDTD_Div_FWD_4th_exec (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_Yee_FDTD_Div_FWD_4th_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_outEB (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_inEB (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_numvec (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_xblock (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_yblock (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_zblock (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_DT (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Div_FWD_struct *  kerstr ){
	return  0 ;}
void  openmp_Yee_FDTD_Div_FWD_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_Yee_FDTD_Div_FWD_struct ));
}
int  openmp_Yee_FDTD_Div_FWD_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_Yee_FDTD_Div_FWD_exec (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_Yee_FDTD_Div_FWD_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_outEB (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_inEB (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_numvec (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_xblock (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_yblock (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_zblock (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_DT (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_4th_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ){
	return  0 ;}
void  openmp_Yee_FDTD_Div_BWD_4th_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_Yee_FDTD_Div_BWD_4th_struct ));
}
int  openmp_Yee_FDTD_Div_BWD_4th_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_Yee_FDTD_Div_BWD_4th_exec (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_Yee_FDTD_Div_BWD_4th_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_outEB (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_inEB (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_numvec (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_xblock (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_yblock (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_zblock (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_DT (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Div_BWD_struct *  kerstr ){
	return  0 ;}
void  openmp_Yee_FDTD_Div_BWD_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_Yee_FDTD_Div_BWD_struct ));
}
int  openmp_Yee_FDTD_Div_BWD_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_Yee_FDTD_Div_BWD_exec (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_Yee_FDTD_Div_BWD_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_outEB (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_inEB (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_numvec (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_xblock (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_yblock (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_zblock (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_DT (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_4th_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ){
	return  0 ;}
void  openmp_Yee_FDTD_Curl_FWD_4th_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_Yee_FDTD_Curl_FWD_4th_struct ));
}
int  openmp_Yee_FDTD_Curl_FWD_4th_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_Yee_FDTD_Curl_FWD_4th_exec (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_Yee_FDTD_Curl_FWD_4th_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_outEB (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_inEB (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_numvec (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_xblock (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_yblock (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_zblock (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_DT (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ){
	return  0 ;}
void  openmp_Yee_FDTD_Curl_FWD_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_Yee_FDTD_Curl_FWD_struct ));
}
int  openmp_Yee_FDTD_Curl_FWD_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_Yee_FDTD_Curl_FWD_exec (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_Yee_FDTD_Curl_FWD_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_outEB (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_inEB (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_numvec (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_xblock (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_yblock (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_zblock (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_DT (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_4th_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ){
	return  0 ;}
void  openmp_Yee_FDTD_Curl_BWD_4th_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_Yee_FDTD_Curl_BWD_4th_struct ));
}
int  openmp_Yee_FDTD_Curl_BWD_4th_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_Yee_FDTD_Curl_BWD_4th_exec (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_Yee_FDTD_Curl_BWD_4th_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_outEB (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_inEB (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_numvec (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_xblock (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_yblock (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_zblock (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_DT (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ){
	return  0 ;}
void  openmp_Yee_FDTD_Curl_BWD_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_Yee_FDTD_Curl_BWD_struct ));
}
int  openmp_Yee_FDTD_Curl_BWD_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_Yee_FDTD_Curl_BWD_exec (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_Yee_FDTD_Curl_BWD_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_outEB (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_inEB (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_numvec (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_xblock (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_yblock (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_zblock (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_DT (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_4th_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ){
	return  0 ;}
void  openmp_Yee_FDTD_Grad_FWD_4th_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_Yee_FDTD_Grad_FWD_4th_struct ));
}
int  openmp_Yee_FDTD_Grad_FWD_4th_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_Yee_FDTD_Grad_FWD_4th_exec (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_Yee_FDTD_Grad_FWD_4th_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_outEB (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_inEB (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_numvec (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_xblock (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_yblock (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_zblock (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_DT (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ){
	return  0 ;}
void  openmp_Yee_FDTD_Grad_FWD_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_Yee_FDTD_Grad_FWD_struct ));
}
int  openmp_Yee_FDTD_Grad_FWD_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_Yee_FDTD_Grad_FWD_exec (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_Yee_FDTD_Grad_FWD_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_outEB (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_inEB (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_numvec (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_xblock (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_yblock (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_zblock (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_DT (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_4th_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ){
	return  0 ;}
void  openmp_Yee_FDTD_Grad_BWD_4th_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_Yee_FDTD_Grad_BWD_4th_struct ));
}
int  openmp_Yee_FDTD_Grad_BWD_4th_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_Yee_FDTD_Grad_BWD_4th_exec (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_Yee_FDTD_Grad_BWD_4th_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_outEB (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_inEB (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_numvec (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_xblock (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_yblock (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_zblock (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_DT (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ){
	return  0 ;}
void  openmp_Yee_FDTD_Grad_BWD_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_Yee_FDTD_Grad_BWD_struct ));
}
int  openmp_Yee_FDTD_Grad_BWD_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_Yee_FDTD_Grad_BWD_exec (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_Yee_FDTD_Grad_BWD_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_outEB (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_inEB (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_numvec (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_xblock (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_yblock (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_zblock (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_DT (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_4th_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ){
	return  0 ;}
void  openmp_Yee_FDTD_Curl_B_4th_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_Yee_FDTD_Curl_B_4th_struct ));
}
int  openmp_Yee_FDTD_Curl_B_4th_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_Yee_FDTD_Curl_B_4th_exec (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_Yee_FDTD_Curl_B_4th_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_outEB (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_inEB (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_numvec (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_xblock (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_yblock (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_zblock (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_DT (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Curl_B_struct *  kerstr ){
	return  0 ;}
void  openmp_Yee_FDTD_Curl_B_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_Yee_FDTD_Curl_B_struct ));
}
int  openmp_Yee_FDTD_Curl_B_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_Yee_FDTD_Curl_B_exec (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_Yee_FDTD_Curl_B_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_outEB (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_inEB (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_numvec (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_xblock (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_yblock (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_zblock (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_DT (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_4th_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ){
	return  0 ;}
void  openmp_Yee_FDTD_Curl_E_4th_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_Yee_FDTD_Curl_E_4th_struct ));
}
int  openmp_Yee_FDTD_Curl_E_4th_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_Yee_FDTD_Curl_E_4th_exec (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_Yee_FDTD_Curl_E_4th_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_outEB (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_inEB (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_numvec (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_xblock (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_yblock (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_zblock (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_DT (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Curl_E_struct *  kerstr ){
	return  0 ;}
void  openmp_Yee_FDTD_Curl_E_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_Yee_FDTD_Curl_E_struct ));
}
int  openmp_Yee_FDTD_Curl_E_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_Yee_FDTD_Curl_E_exec (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_Yee_FDTD_Curl_E_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_outEB (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_inEB (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_numvec (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_xblock (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_yblock (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_zblock (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_DT (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
