#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "openmp_pscmc_inc.h"
#include "dm.kernel_inc.h"
int  openmp_dm_1st_eqn_right_init (openmp_pscmc_env *  pe ,openmp_dm_1st_eqn_right_struct *  kerstr ){
	return  0 ;}
void  openmp_dm_1st_eqn_right_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_dm_1st_eqn_right_struct ));
}
int  openmp_dm_1st_eqn_right_get_num_compute_units (openmp_dm_1st_eqn_right_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_dm_1st_eqn_right_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_dm_1st_eqn_right_exec (openmp_dm_1st_eqn_right_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_dm_1st_eqn_right_scmc_kernel ( 	( kerstr )->phi_out , 	( kerstr )->phi_in , 	( kerstr )->phi_1 , 	( kerstr )->A1 , 	( kerstr )->A2 , 	( kerstr )->A3 , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->num_ele_A1)[0] , (	( kerstr )->DT)[0] , (	( kerstr )->M)[0] , (	( kerstr )->Q)[0] , (	( kerstr )->DM_A)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_phi_out (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->phi_out = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_phi_in (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->phi_in = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_phi_1 (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->phi_1 = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_A1 (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->A1 = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_A2 (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->A2 = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_A3 (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->A3 = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_y_cpu_core (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_numvec (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_XLEN (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_YLEN (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_ZLEN (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_ovlp (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_xblock (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_yblock (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_zblock (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_num_ele (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_num_ele_A1 (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele_A1 = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_DT (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_M (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->M = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_Q (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Q = pm->d_data);
}
int  openmp_dm_1st_eqn_right_scmc_set_parameter_DM_A (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DM_A = pm->d_data);
}
int  openmp_dm_1st_eqn_core_init (openmp_pscmc_env *  pe ,openmp_dm_1st_eqn_core_struct *  kerstr ){
	return  0 ;}
void  openmp_dm_1st_eqn_core_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_dm_1st_eqn_core_struct ));
}
int  openmp_dm_1st_eqn_core_get_num_compute_units (openmp_dm_1st_eqn_core_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_dm_1st_eqn_core_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_dm_1st_eqn_core_exec (openmp_dm_1st_eqn_core_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_dm_1st_eqn_core_scmc_kernel ( 	( kerstr )->phi_out , 	( kerstr )->phi_in , 	( kerstr )->phi_1 , 	( kerstr )->A1 , 	( kerstr )->A2 , 	( kerstr )->A3 , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->num_ele_A1)[0] , (	( kerstr )->DT)[0] , (	( kerstr )->M)[0] , (	( kerstr )->Q)[0] , (	( kerstr )->DM_A)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_phi_out (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->phi_out = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_phi_in (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->phi_in = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_phi_1 (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->phi_1 = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_A1 (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->A1 = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_A2 (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->A2 = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_A3 (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->A3 = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_y_cpu_core (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_numvec (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_XLEN (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_YLEN (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_ZLEN (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_ovlp (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_xblock (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_yblock (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_zblock (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_num_ele (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_num_ele_A1 (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele_A1 = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_DT (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_M (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->M = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_Q (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Q = pm->d_data);
}
int  openmp_dm_1st_eqn_core_scmc_set_parameter_DM_A (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DM_A = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_init (openmp_pscmc_env *  pe ,openmp_dm_1st_eqn_fdtd_struct *  kerstr ){
	return  0 ;}
void  openmp_dm_1st_eqn_fdtd_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_dm_1st_eqn_fdtd_struct ));
}
int  openmp_dm_1st_eqn_fdtd_get_num_compute_units (openmp_dm_1st_eqn_fdtd_struct *  kerstr ){
	return  	omp_get_max_threads (  ) ;}
int  openmp_dm_1st_eqn_fdtd_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_dm_1st_eqn_fdtd_exec (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_dm_1st_eqn_fdtd_scmc_kernel ( 	( kerstr )->phi_out , 	( kerstr )->phi_in , 	( kerstr )->phi_1 , 	( kerstr )->A1 , 	( kerstr )->A2 , 	( kerstr )->A3 , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->num_ele_A1)[0] , (	( kerstr )->DT)[0] , (	( kerstr )->M)[0] , (	( kerstr )->Q)[0] , (	( kerstr )->DM_A)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_phi_out (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->phi_out = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_phi_in (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->phi_in = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_phi_1 (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->phi_1 = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_A1 (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->A1 = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_A2 (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->A2 = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_A3 (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->A3 = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_y_cpu_core (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_numvec (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_XLEN (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_YLEN (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_ZLEN (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_ovlp (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_xblock (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_yblock (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_zblock (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_num_ele (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_num_ele_A1 (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele_A1 = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_DT (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_M (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->M = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_Q (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->Q = pm->d_data);
}
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_DM_A (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DM_A = pm->d_data);
}
