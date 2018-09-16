#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "openmp_pscmc_inc.h"
#include "mur_abc.kernel_inc.h"
int  openmp_yee_damp_xyz_init (openmp_pscmc_env *  pe ,openmp_yee_damp_xyz_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_damp_xyz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_damp_xyz_struct ));
}
int  openmp_yee_damp_xyz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_damp_xyz_exec (openmp_yee_damp_xyz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_damp_xyz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_damp_xyz_scmc_set_parameter_outEB (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_damp_xyz_scmc_set_parameter_inEB (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_damp_xyz_scmc_set_parameter_cur_rankx (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_damp_xyz_scmc_set_parameter_cur_ranky (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_damp_xyz_scmc_set_parameter_cur_rankz (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_damp_xyz_scmc_set_parameter_y_cpu_core (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_damp_xyz_scmc_set_parameter_numvec (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_damp_xyz_scmc_set_parameter_XLEN (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_damp_xyz_scmc_set_parameter_YLEN (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_damp_xyz_scmc_set_parameter_ZLEN (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_damp_xyz_scmc_set_parameter_ovlp (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_damp_xyz_scmc_set_parameter_xblock (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_damp_xyz_scmc_set_parameter_yblock (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_damp_xyz_scmc_set_parameter_zblock (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_damp_xyz_scmc_set_parameter_num_ele (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_damp_xyz_scmc_set_parameter_damp_vars (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_damp_xyz_scmc_set_parameter_deltat (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_pec_xyz_init (openmp_pscmc_env *  pe ,openmp_yee_pec_xyz_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_pec_xyz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_pec_xyz_struct ));
}
int  openmp_yee_pec_xyz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_pec_xyz_exec (openmp_yee_pec_xyz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_pec_xyz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_pec_xyz_scmc_set_parameter_outEB (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_pec_xyz_scmc_set_parameter_inEB (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_pec_xyz_scmc_set_parameter_cur_rankx (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_pec_xyz_scmc_set_parameter_cur_ranky (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_pec_xyz_scmc_set_parameter_cur_rankz (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_pec_xyz_scmc_set_parameter_y_cpu_core (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_pec_xyz_scmc_set_parameter_numvec (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_pec_xyz_scmc_set_parameter_XLEN (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_pec_xyz_scmc_set_parameter_YLEN (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_pec_xyz_scmc_set_parameter_ZLEN (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_pec_xyz_scmc_set_parameter_ovlp (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_pec_xyz_scmc_set_parameter_xblock (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_pec_xyz_scmc_set_parameter_yblock (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_pec_xyz_scmc_set_parameter_zblock (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_pec_xyz_scmc_set_parameter_num_ele (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_pec_xyz_scmc_set_parameter_damp_vars (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_pec_xyz_scmc_set_parameter_deltat (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_abc_xyz_init (openmp_pscmc_env *  pe ,openmp_yee_abc_xyz_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_abc_xyz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_abc_xyz_struct ));
}
int  openmp_yee_abc_xyz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_abc_xyz_exec (openmp_yee_abc_xyz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_abc_xyz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_abc_xyz_scmc_set_parameter_outEB (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_abc_xyz_scmc_set_parameter_inEB (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_abc_xyz_scmc_set_parameter_cur_rankx (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_abc_xyz_scmc_set_parameter_cur_ranky (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_abc_xyz_scmc_set_parameter_cur_rankz (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_abc_xyz_scmc_set_parameter_y_cpu_core (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_abc_xyz_scmc_set_parameter_numvec (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_abc_xyz_scmc_set_parameter_XLEN (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_abc_xyz_scmc_set_parameter_YLEN (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_abc_xyz_scmc_set_parameter_ZLEN (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_abc_xyz_scmc_set_parameter_ovlp (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_abc_xyz_scmc_set_parameter_xblock (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_abc_xyz_scmc_set_parameter_yblock (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_abc_xyz_scmc_set_parameter_zblock (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_abc_xyz_scmc_set_parameter_num_ele (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_abc_xyz_scmc_set_parameter_damp_vars (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_abc_xyz_scmc_set_parameter_deltat (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_damp_yz_init (openmp_pscmc_env *  pe ,openmp_yee_damp_yz_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_damp_yz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_damp_yz_struct ));
}
int  openmp_yee_damp_yz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_damp_yz_exec (openmp_yee_damp_yz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_damp_yz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_damp_yz_scmc_set_parameter_outEB (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_damp_yz_scmc_set_parameter_inEB (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_damp_yz_scmc_set_parameter_cur_rankx (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_damp_yz_scmc_set_parameter_cur_ranky (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_damp_yz_scmc_set_parameter_cur_rankz (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_damp_yz_scmc_set_parameter_y_cpu_core (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_damp_yz_scmc_set_parameter_numvec (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_damp_yz_scmc_set_parameter_XLEN (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_damp_yz_scmc_set_parameter_YLEN (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_damp_yz_scmc_set_parameter_ZLEN (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_damp_yz_scmc_set_parameter_ovlp (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_damp_yz_scmc_set_parameter_xblock (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_damp_yz_scmc_set_parameter_yblock (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_damp_yz_scmc_set_parameter_zblock (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_damp_yz_scmc_set_parameter_num_ele (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_damp_yz_scmc_set_parameter_damp_vars (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_damp_yz_scmc_set_parameter_deltat (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_pec_yz_init (openmp_pscmc_env *  pe ,openmp_yee_pec_yz_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_pec_yz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_pec_yz_struct ));
}
int  openmp_yee_pec_yz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_pec_yz_exec (openmp_yee_pec_yz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_pec_yz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_pec_yz_scmc_set_parameter_outEB (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_pec_yz_scmc_set_parameter_inEB (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_pec_yz_scmc_set_parameter_cur_rankx (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_pec_yz_scmc_set_parameter_cur_ranky (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_pec_yz_scmc_set_parameter_cur_rankz (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_pec_yz_scmc_set_parameter_y_cpu_core (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_pec_yz_scmc_set_parameter_numvec (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_pec_yz_scmc_set_parameter_XLEN (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_pec_yz_scmc_set_parameter_YLEN (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_pec_yz_scmc_set_parameter_ZLEN (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_pec_yz_scmc_set_parameter_ovlp (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_pec_yz_scmc_set_parameter_xblock (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_pec_yz_scmc_set_parameter_yblock (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_pec_yz_scmc_set_parameter_zblock (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_pec_yz_scmc_set_parameter_num_ele (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_pec_yz_scmc_set_parameter_damp_vars (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_pec_yz_scmc_set_parameter_deltat (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_abc_yz_init (openmp_pscmc_env *  pe ,openmp_yee_abc_yz_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_abc_yz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_abc_yz_struct ));
}
int  openmp_yee_abc_yz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_abc_yz_exec (openmp_yee_abc_yz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_abc_yz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_abc_yz_scmc_set_parameter_outEB (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_abc_yz_scmc_set_parameter_inEB (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_abc_yz_scmc_set_parameter_cur_rankx (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_abc_yz_scmc_set_parameter_cur_ranky (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_abc_yz_scmc_set_parameter_cur_rankz (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_abc_yz_scmc_set_parameter_y_cpu_core (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_abc_yz_scmc_set_parameter_numvec (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_abc_yz_scmc_set_parameter_XLEN (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_abc_yz_scmc_set_parameter_YLEN (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_abc_yz_scmc_set_parameter_ZLEN (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_abc_yz_scmc_set_parameter_ovlp (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_abc_yz_scmc_set_parameter_xblock (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_abc_yz_scmc_set_parameter_yblock (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_abc_yz_scmc_set_parameter_zblock (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_abc_yz_scmc_set_parameter_num_ele (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_abc_yz_scmc_set_parameter_damp_vars (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_abc_yz_scmc_set_parameter_deltat (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_damp_xz_init (openmp_pscmc_env *  pe ,openmp_yee_damp_xz_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_damp_xz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_damp_xz_struct ));
}
int  openmp_yee_damp_xz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_damp_xz_exec (openmp_yee_damp_xz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_damp_xz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_damp_xz_scmc_set_parameter_outEB (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_damp_xz_scmc_set_parameter_inEB (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_damp_xz_scmc_set_parameter_cur_rankx (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_damp_xz_scmc_set_parameter_cur_ranky (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_damp_xz_scmc_set_parameter_cur_rankz (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_damp_xz_scmc_set_parameter_y_cpu_core (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_damp_xz_scmc_set_parameter_numvec (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_damp_xz_scmc_set_parameter_XLEN (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_damp_xz_scmc_set_parameter_YLEN (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_damp_xz_scmc_set_parameter_ZLEN (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_damp_xz_scmc_set_parameter_ovlp (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_damp_xz_scmc_set_parameter_xblock (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_damp_xz_scmc_set_parameter_yblock (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_damp_xz_scmc_set_parameter_zblock (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_damp_xz_scmc_set_parameter_num_ele (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_damp_xz_scmc_set_parameter_damp_vars (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_damp_xz_scmc_set_parameter_deltat (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_pec_xz_init (openmp_pscmc_env *  pe ,openmp_yee_pec_xz_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_pec_xz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_pec_xz_struct ));
}
int  openmp_yee_pec_xz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_pec_xz_exec (openmp_yee_pec_xz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_pec_xz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_pec_xz_scmc_set_parameter_outEB (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_pec_xz_scmc_set_parameter_inEB (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_pec_xz_scmc_set_parameter_cur_rankx (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_pec_xz_scmc_set_parameter_cur_ranky (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_pec_xz_scmc_set_parameter_cur_rankz (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_pec_xz_scmc_set_parameter_y_cpu_core (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_pec_xz_scmc_set_parameter_numvec (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_pec_xz_scmc_set_parameter_XLEN (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_pec_xz_scmc_set_parameter_YLEN (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_pec_xz_scmc_set_parameter_ZLEN (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_pec_xz_scmc_set_parameter_ovlp (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_pec_xz_scmc_set_parameter_xblock (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_pec_xz_scmc_set_parameter_yblock (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_pec_xz_scmc_set_parameter_zblock (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_pec_xz_scmc_set_parameter_num_ele (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_pec_xz_scmc_set_parameter_damp_vars (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_pec_xz_scmc_set_parameter_deltat (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_abc_xz_init (openmp_pscmc_env *  pe ,openmp_yee_abc_xz_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_abc_xz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_abc_xz_struct ));
}
int  openmp_yee_abc_xz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_abc_xz_exec (openmp_yee_abc_xz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_abc_xz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_abc_xz_scmc_set_parameter_outEB (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_abc_xz_scmc_set_parameter_inEB (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_abc_xz_scmc_set_parameter_cur_rankx (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_abc_xz_scmc_set_parameter_cur_ranky (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_abc_xz_scmc_set_parameter_cur_rankz (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_abc_xz_scmc_set_parameter_y_cpu_core (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_abc_xz_scmc_set_parameter_numvec (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_abc_xz_scmc_set_parameter_XLEN (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_abc_xz_scmc_set_parameter_YLEN (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_abc_xz_scmc_set_parameter_ZLEN (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_abc_xz_scmc_set_parameter_ovlp (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_abc_xz_scmc_set_parameter_xblock (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_abc_xz_scmc_set_parameter_yblock (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_abc_xz_scmc_set_parameter_zblock (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_abc_xz_scmc_set_parameter_num_ele (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_abc_xz_scmc_set_parameter_damp_vars (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_abc_xz_scmc_set_parameter_deltat (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_damp_xy_init (openmp_pscmc_env *  pe ,openmp_yee_damp_xy_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_damp_xy_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_damp_xy_struct ));
}
int  openmp_yee_damp_xy_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_damp_xy_exec (openmp_yee_damp_xy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_damp_xy_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_damp_xy_scmc_set_parameter_outEB (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_damp_xy_scmc_set_parameter_inEB (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_damp_xy_scmc_set_parameter_cur_rankx (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_damp_xy_scmc_set_parameter_cur_ranky (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_damp_xy_scmc_set_parameter_cur_rankz (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_damp_xy_scmc_set_parameter_y_cpu_core (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_damp_xy_scmc_set_parameter_numvec (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_damp_xy_scmc_set_parameter_XLEN (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_damp_xy_scmc_set_parameter_YLEN (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_damp_xy_scmc_set_parameter_ZLEN (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_damp_xy_scmc_set_parameter_ovlp (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_damp_xy_scmc_set_parameter_xblock (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_damp_xy_scmc_set_parameter_yblock (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_damp_xy_scmc_set_parameter_zblock (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_damp_xy_scmc_set_parameter_num_ele (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_damp_xy_scmc_set_parameter_damp_vars (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_damp_xy_scmc_set_parameter_deltat (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_pec_xy_init (openmp_pscmc_env *  pe ,openmp_yee_pec_xy_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_pec_xy_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_pec_xy_struct ));
}
int  openmp_yee_pec_xy_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_pec_xy_exec (openmp_yee_pec_xy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_pec_xy_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_pec_xy_scmc_set_parameter_outEB (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_pec_xy_scmc_set_parameter_inEB (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_pec_xy_scmc_set_parameter_cur_rankx (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_pec_xy_scmc_set_parameter_cur_ranky (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_pec_xy_scmc_set_parameter_cur_rankz (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_pec_xy_scmc_set_parameter_y_cpu_core (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_pec_xy_scmc_set_parameter_numvec (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_pec_xy_scmc_set_parameter_XLEN (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_pec_xy_scmc_set_parameter_YLEN (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_pec_xy_scmc_set_parameter_ZLEN (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_pec_xy_scmc_set_parameter_ovlp (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_pec_xy_scmc_set_parameter_xblock (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_pec_xy_scmc_set_parameter_yblock (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_pec_xy_scmc_set_parameter_zblock (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_pec_xy_scmc_set_parameter_num_ele (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_pec_xy_scmc_set_parameter_damp_vars (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_pec_xy_scmc_set_parameter_deltat (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_abc_xy_init (openmp_pscmc_env *  pe ,openmp_yee_abc_xy_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_abc_xy_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_abc_xy_struct ));
}
int  openmp_yee_abc_xy_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_abc_xy_exec (openmp_yee_abc_xy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_abc_xy_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_abc_xy_scmc_set_parameter_outEB (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_abc_xy_scmc_set_parameter_inEB (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_abc_xy_scmc_set_parameter_cur_rankx (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_abc_xy_scmc_set_parameter_cur_ranky (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_abc_xy_scmc_set_parameter_cur_rankz (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_abc_xy_scmc_set_parameter_y_cpu_core (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_abc_xy_scmc_set_parameter_numvec (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_abc_xy_scmc_set_parameter_XLEN (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_abc_xy_scmc_set_parameter_YLEN (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_abc_xy_scmc_set_parameter_ZLEN (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_abc_xy_scmc_set_parameter_ovlp (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_abc_xy_scmc_set_parameter_xblock (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_abc_xy_scmc_set_parameter_yblock (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_abc_xy_scmc_set_parameter_zblock (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_abc_xy_scmc_set_parameter_num_ele (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_abc_xy_scmc_set_parameter_damp_vars (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_abc_xy_scmc_set_parameter_deltat (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_damp_z_init (openmp_pscmc_env *  pe ,openmp_yee_damp_z_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_damp_z_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_damp_z_struct ));
}
int  openmp_yee_damp_z_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_damp_z_exec (openmp_yee_damp_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_damp_z_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_damp_z_scmc_set_parameter_outEB (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_damp_z_scmc_set_parameter_inEB (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_damp_z_scmc_set_parameter_cur_rankx (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_damp_z_scmc_set_parameter_cur_ranky (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_damp_z_scmc_set_parameter_cur_rankz (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_damp_z_scmc_set_parameter_y_cpu_core (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_damp_z_scmc_set_parameter_numvec (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_damp_z_scmc_set_parameter_XLEN (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_damp_z_scmc_set_parameter_YLEN (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_damp_z_scmc_set_parameter_ZLEN (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_damp_z_scmc_set_parameter_ovlp (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_damp_z_scmc_set_parameter_xblock (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_damp_z_scmc_set_parameter_yblock (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_damp_z_scmc_set_parameter_zblock (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_damp_z_scmc_set_parameter_num_ele (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_damp_z_scmc_set_parameter_damp_vars (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_damp_z_scmc_set_parameter_deltat (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_pec_z_init (openmp_pscmc_env *  pe ,openmp_yee_pec_z_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_pec_z_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_pec_z_struct ));
}
int  openmp_yee_pec_z_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_pec_z_exec (openmp_yee_pec_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_pec_z_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_pec_z_scmc_set_parameter_outEB (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_pec_z_scmc_set_parameter_inEB (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_pec_z_scmc_set_parameter_cur_rankx (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_pec_z_scmc_set_parameter_cur_ranky (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_pec_z_scmc_set_parameter_cur_rankz (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_pec_z_scmc_set_parameter_y_cpu_core (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_pec_z_scmc_set_parameter_numvec (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_pec_z_scmc_set_parameter_XLEN (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_pec_z_scmc_set_parameter_YLEN (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_pec_z_scmc_set_parameter_ZLEN (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_pec_z_scmc_set_parameter_ovlp (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_pec_z_scmc_set_parameter_xblock (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_pec_z_scmc_set_parameter_yblock (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_pec_z_scmc_set_parameter_zblock (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_pec_z_scmc_set_parameter_num_ele (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_pec_z_scmc_set_parameter_damp_vars (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_pec_z_scmc_set_parameter_deltat (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_abc_z_init (openmp_pscmc_env *  pe ,openmp_yee_abc_z_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_abc_z_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_abc_z_struct ));
}
int  openmp_yee_abc_z_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_abc_z_exec (openmp_yee_abc_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_abc_z_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_abc_z_scmc_set_parameter_outEB (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_abc_z_scmc_set_parameter_inEB (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_abc_z_scmc_set_parameter_cur_rankx (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_abc_z_scmc_set_parameter_cur_ranky (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_abc_z_scmc_set_parameter_cur_rankz (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_abc_z_scmc_set_parameter_y_cpu_core (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_abc_z_scmc_set_parameter_numvec (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_abc_z_scmc_set_parameter_XLEN (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_abc_z_scmc_set_parameter_YLEN (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_abc_z_scmc_set_parameter_ZLEN (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_abc_z_scmc_set_parameter_ovlp (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_abc_z_scmc_set_parameter_xblock (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_abc_z_scmc_set_parameter_yblock (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_abc_z_scmc_set_parameter_zblock (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_abc_z_scmc_set_parameter_num_ele (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_abc_z_scmc_set_parameter_damp_vars (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_abc_z_scmc_set_parameter_deltat (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_damp_y_init (openmp_pscmc_env *  pe ,openmp_yee_damp_y_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_damp_y_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_damp_y_struct ));
}
int  openmp_yee_damp_y_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_damp_y_exec (openmp_yee_damp_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_damp_y_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_damp_y_scmc_set_parameter_outEB (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_damp_y_scmc_set_parameter_inEB (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_damp_y_scmc_set_parameter_cur_rankx (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_damp_y_scmc_set_parameter_cur_ranky (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_damp_y_scmc_set_parameter_cur_rankz (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_damp_y_scmc_set_parameter_y_cpu_core (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_damp_y_scmc_set_parameter_numvec (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_damp_y_scmc_set_parameter_XLEN (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_damp_y_scmc_set_parameter_YLEN (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_damp_y_scmc_set_parameter_ZLEN (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_damp_y_scmc_set_parameter_ovlp (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_damp_y_scmc_set_parameter_xblock (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_damp_y_scmc_set_parameter_yblock (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_damp_y_scmc_set_parameter_zblock (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_damp_y_scmc_set_parameter_num_ele (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_damp_y_scmc_set_parameter_damp_vars (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_damp_y_scmc_set_parameter_deltat (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_pec_y_init (openmp_pscmc_env *  pe ,openmp_yee_pec_y_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_pec_y_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_pec_y_struct ));
}
int  openmp_yee_pec_y_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_pec_y_exec (openmp_yee_pec_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_pec_y_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_pec_y_scmc_set_parameter_outEB (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_pec_y_scmc_set_parameter_inEB (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_pec_y_scmc_set_parameter_cur_rankx (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_pec_y_scmc_set_parameter_cur_ranky (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_pec_y_scmc_set_parameter_cur_rankz (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_pec_y_scmc_set_parameter_y_cpu_core (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_pec_y_scmc_set_parameter_numvec (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_pec_y_scmc_set_parameter_XLEN (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_pec_y_scmc_set_parameter_YLEN (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_pec_y_scmc_set_parameter_ZLEN (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_pec_y_scmc_set_parameter_ovlp (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_pec_y_scmc_set_parameter_xblock (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_pec_y_scmc_set_parameter_yblock (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_pec_y_scmc_set_parameter_zblock (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_pec_y_scmc_set_parameter_num_ele (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_pec_y_scmc_set_parameter_damp_vars (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_pec_y_scmc_set_parameter_deltat (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_abc_y_init (openmp_pscmc_env *  pe ,openmp_yee_abc_y_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_abc_y_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_abc_y_struct ));
}
int  openmp_yee_abc_y_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_abc_y_exec (openmp_yee_abc_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_abc_y_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_abc_y_scmc_set_parameter_outEB (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_abc_y_scmc_set_parameter_inEB (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_abc_y_scmc_set_parameter_cur_rankx (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_abc_y_scmc_set_parameter_cur_ranky (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_abc_y_scmc_set_parameter_cur_rankz (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_abc_y_scmc_set_parameter_y_cpu_core (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_abc_y_scmc_set_parameter_numvec (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_abc_y_scmc_set_parameter_XLEN (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_abc_y_scmc_set_parameter_YLEN (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_abc_y_scmc_set_parameter_ZLEN (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_abc_y_scmc_set_parameter_ovlp (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_abc_y_scmc_set_parameter_xblock (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_abc_y_scmc_set_parameter_yblock (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_abc_y_scmc_set_parameter_zblock (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_abc_y_scmc_set_parameter_num_ele (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_abc_y_scmc_set_parameter_damp_vars (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_abc_y_scmc_set_parameter_deltat (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_damp_x_init (openmp_pscmc_env *  pe ,openmp_yee_damp_x_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_damp_x_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_damp_x_struct ));
}
int  openmp_yee_damp_x_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_damp_x_exec (openmp_yee_damp_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_damp_x_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_damp_x_scmc_set_parameter_outEB (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_damp_x_scmc_set_parameter_inEB (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_damp_x_scmc_set_parameter_cur_rankx (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_damp_x_scmc_set_parameter_cur_ranky (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_damp_x_scmc_set_parameter_cur_rankz (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_damp_x_scmc_set_parameter_y_cpu_core (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_damp_x_scmc_set_parameter_numvec (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_damp_x_scmc_set_parameter_XLEN (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_damp_x_scmc_set_parameter_YLEN (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_damp_x_scmc_set_parameter_ZLEN (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_damp_x_scmc_set_parameter_ovlp (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_damp_x_scmc_set_parameter_xblock (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_damp_x_scmc_set_parameter_yblock (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_damp_x_scmc_set_parameter_zblock (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_damp_x_scmc_set_parameter_num_ele (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_damp_x_scmc_set_parameter_damp_vars (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_damp_x_scmc_set_parameter_deltat (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_pec_x_init (openmp_pscmc_env *  pe ,openmp_yee_pec_x_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_pec_x_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_pec_x_struct ));
}
int  openmp_yee_pec_x_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_pec_x_exec (openmp_yee_pec_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_pec_x_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_pec_x_scmc_set_parameter_outEB (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_pec_x_scmc_set_parameter_inEB (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_pec_x_scmc_set_parameter_cur_rankx (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_pec_x_scmc_set_parameter_cur_ranky (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_pec_x_scmc_set_parameter_cur_rankz (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_pec_x_scmc_set_parameter_y_cpu_core (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_pec_x_scmc_set_parameter_numvec (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_pec_x_scmc_set_parameter_XLEN (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_pec_x_scmc_set_parameter_YLEN (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_pec_x_scmc_set_parameter_ZLEN (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_pec_x_scmc_set_parameter_ovlp (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_pec_x_scmc_set_parameter_xblock (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_pec_x_scmc_set_parameter_yblock (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_pec_x_scmc_set_parameter_zblock (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_pec_x_scmc_set_parameter_num_ele (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_pec_x_scmc_set_parameter_damp_vars (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_pec_x_scmc_set_parameter_deltat (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_abc_x_init (openmp_pscmc_env *  pe ,openmp_yee_abc_x_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_abc_x_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_abc_x_struct ));
}
int  openmp_yee_abc_x_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_abc_x_exec (openmp_yee_abc_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_abc_x_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_abc_x_scmc_set_parameter_outEB (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_abc_x_scmc_set_parameter_inEB (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_abc_x_scmc_set_parameter_cur_rankx (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_abc_x_scmc_set_parameter_cur_ranky (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_abc_x_scmc_set_parameter_cur_rankz (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_abc_x_scmc_set_parameter_y_cpu_core (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_abc_x_scmc_set_parameter_numvec (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_abc_x_scmc_set_parameter_XLEN (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_abc_x_scmc_set_parameter_YLEN (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_abc_x_scmc_set_parameter_ZLEN (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_abc_x_scmc_set_parameter_ovlp (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_abc_x_scmc_set_parameter_xblock (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_abc_x_scmc_set_parameter_yblock (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_abc_x_scmc_set_parameter_zblock (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_abc_x_scmc_set_parameter_num_ele (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_abc_x_scmc_set_parameter_damp_vars (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_abc_x_scmc_set_parameter_deltat (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_damp__init (openmp_pscmc_env *  pe ,openmp_yee_damp__struct *  kerstr ){
	return  0 ;}
void  openmp_yee_damp__get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_damp__struct ));
}
int  openmp_yee_damp__get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_damp__exec (openmp_yee_damp__struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_damp__scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_damp__scmc_set_parameter_outEB (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_damp__scmc_set_parameter_inEB (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_damp__scmc_set_parameter_cur_rankx (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_damp__scmc_set_parameter_cur_ranky (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_damp__scmc_set_parameter_cur_rankz (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_damp__scmc_set_parameter_y_cpu_core (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_damp__scmc_set_parameter_numvec (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_damp__scmc_set_parameter_XLEN (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_damp__scmc_set_parameter_YLEN (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_damp__scmc_set_parameter_ZLEN (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_damp__scmc_set_parameter_ovlp (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_damp__scmc_set_parameter_xblock (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_damp__scmc_set_parameter_yblock (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_damp__scmc_set_parameter_zblock (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_damp__scmc_set_parameter_num_ele (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_damp__scmc_set_parameter_damp_vars (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_damp__scmc_set_parameter_deltat (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_pec__init (openmp_pscmc_env *  pe ,openmp_yee_pec__struct *  kerstr ){
	return  0 ;}
void  openmp_yee_pec__get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_pec__struct ));
}
int  openmp_yee_pec__get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_pec__exec (openmp_yee_pec__struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_pec__scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_pec__scmc_set_parameter_outEB (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_pec__scmc_set_parameter_inEB (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_pec__scmc_set_parameter_cur_rankx (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_pec__scmc_set_parameter_cur_ranky (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_pec__scmc_set_parameter_cur_rankz (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_pec__scmc_set_parameter_y_cpu_core (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_pec__scmc_set_parameter_numvec (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_pec__scmc_set_parameter_XLEN (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_pec__scmc_set_parameter_YLEN (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_pec__scmc_set_parameter_ZLEN (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_pec__scmc_set_parameter_ovlp (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_pec__scmc_set_parameter_xblock (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_pec__scmc_set_parameter_yblock (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_pec__scmc_set_parameter_zblock (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_pec__scmc_set_parameter_num_ele (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_pec__scmc_set_parameter_damp_vars (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_pec__scmc_set_parameter_deltat (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  openmp_yee_abc__init (openmp_pscmc_env *  pe ,openmp_yee_abc__struct *  kerstr ){
	return  0 ;}
void  openmp_yee_abc__get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_abc__struct ));
}
int  openmp_yee_abc__get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_abc__exec (openmp_yee_abc__struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_abc__scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_abc__scmc_set_parameter_outEB (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  openmp_yee_abc__scmc_set_parameter_inEB (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  openmp_yee_abc__scmc_set_parameter_cur_rankx (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  openmp_yee_abc__scmc_set_parameter_cur_ranky (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  openmp_yee_abc__scmc_set_parameter_cur_rankz (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  openmp_yee_abc__scmc_set_parameter_y_cpu_core (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  openmp_yee_abc__scmc_set_parameter_numvec (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_abc__scmc_set_parameter_XLEN (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_yee_abc__scmc_set_parameter_YLEN (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_yee_abc__scmc_set_parameter_ZLEN (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_yee_abc__scmc_set_parameter_ovlp (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_abc__scmc_set_parameter_xblock (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_abc__scmc_set_parameter_yblock (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_abc__scmc_set_parameter_zblock (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_abc__scmc_set_parameter_num_ele (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_abc__scmc_set_parameter_damp_vars (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  openmp_yee_abc__scmc_set_parameter_deltat (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
