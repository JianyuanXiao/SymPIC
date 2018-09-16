#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "openmp_pscmc_inc.h"
#include "mergefields.kernel_inc.h"
int  openmp_merge_ovlp_m2o_init (openmp_pscmc_env *  pe ,openmp_merge_ovlp_m2o_struct *  kerstr ){
	return  0 ;}
void  openmp_merge_ovlp_m2o_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_merge_ovlp_m2o_struct ));
}
int  openmp_merge_ovlp_m2o_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_merge_ovlp_m2o_exec (openmp_merge_ovlp_m2o_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_merge_ovlp_m2o_scmc_kernel ( 	( kerstr )->vecmain , 	( kerstr )->vecovlp , (	( kerstr )->ovlpindex)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->ovlp)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_merge_ovlp_m2o_scmc_set_parameter_vecmain (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecmain = pm->d_data);
}
int  openmp_merge_ovlp_m2o_scmc_set_parameter_vecovlp (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp = pm->d_data);
}
int  openmp_merge_ovlp_m2o_scmc_set_parameter_ovlpindex (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlpindex = pm->d_data);
}
int  openmp_merge_ovlp_m2o_scmc_set_parameter_numvec (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_merge_ovlp_m2o_scmc_set_parameter_num_ele (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_merge_ovlp_m2o_scmc_set_parameter_xblock (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_merge_ovlp_m2o_scmc_set_parameter_yblock (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_merge_ovlp_m2o_scmc_set_parameter_zblock (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_merge_ovlp_m2o_scmc_set_parameter_ovlp (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_merge_ovlp_o2m_init (openmp_pscmc_env *  pe ,openmp_merge_ovlp_o2m_struct *  kerstr ){
	return  0 ;}
void  openmp_merge_ovlp_o2m_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_merge_ovlp_o2m_struct ));
}
int  openmp_merge_ovlp_o2m_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_merge_ovlp_o2m_exec (openmp_merge_ovlp_o2m_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_merge_ovlp_o2m_scmc_kernel ( 	( kerstr )->vecmain , 	( kerstr )->vecovlp , (	( kerstr )->ovlpindex)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->ovlp)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_merge_ovlp_o2m_scmc_set_parameter_vecmain (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecmain = pm->d_data);
}
int  openmp_merge_ovlp_o2m_scmc_set_parameter_vecovlp (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp = pm->d_data);
}
int  openmp_merge_ovlp_o2m_scmc_set_parameter_ovlpindex (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlpindex = pm->d_data);
}
int  openmp_merge_ovlp_o2m_scmc_set_parameter_numvec (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_merge_ovlp_o2m_scmc_set_parameter_num_ele (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_merge_ovlp_o2m_scmc_set_parameter_xblock (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_merge_ovlp_o2m_scmc_set_parameter_yblock (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_merge_ovlp_o2m_scmc_set_parameter_zblock (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_merge_ovlp_o2m_scmc_set_parameter_ovlp (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_sync_ovlp_m2o_init (openmp_pscmc_env *  pe ,openmp_sync_ovlp_m2o_struct *  kerstr ){
	return  0 ;}
void  openmp_sync_ovlp_m2o_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sync_ovlp_m2o_struct ));
}
int  openmp_sync_ovlp_m2o_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_sync_ovlp_m2o_exec (openmp_sync_ovlp_m2o_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sync_ovlp_m2o_scmc_kernel ( 	( kerstr )->vecmain , 	( kerstr )->vecovlp , (	( kerstr )->ovlpindex)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->ovlp)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_sync_ovlp_m2o_scmc_set_parameter_vecmain (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecmain = pm->d_data);
}
int  openmp_sync_ovlp_m2o_scmc_set_parameter_vecovlp (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp = pm->d_data);
}
int  openmp_sync_ovlp_m2o_scmc_set_parameter_ovlpindex (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlpindex = pm->d_data);
}
int  openmp_sync_ovlp_m2o_scmc_set_parameter_numvec (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_sync_ovlp_m2o_scmc_set_parameter_num_ele (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_sync_ovlp_m2o_scmc_set_parameter_xblock (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_sync_ovlp_m2o_scmc_set_parameter_yblock (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_sync_ovlp_m2o_scmc_set_parameter_zblock (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_sync_ovlp_m2o_scmc_set_parameter_ovlp (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_sync_ovlp_o2m_init (openmp_pscmc_env *  pe ,openmp_sync_ovlp_o2m_struct *  kerstr ){
	return  0 ;}
void  openmp_sync_ovlp_o2m_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sync_ovlp_o2m_struct ));
}
int  openmp_sync_ovlp_o2m_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_sync_ovlp_o2m_exec (openmp_sync_ovlp_o2m_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sync_ovlp_o2m_scmc_kernel ( 	( kerstr )->vecmain , 	( kerstr )->vecovlp , (	( kerstr )->ovlpindex)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->ovlp)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_sync_ovlp_o2m_scmc_set_parameter_vecmain (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecmain = pm->d_data);
}
int  openmp_sync_ovlp_o2m_scmc_set_parameter_vecovlp (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp = pm->d_data);
}
int  openmp_sync_ovlp_o2m_scmc_set_parameter_ovlpindex (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlpindex = pm->d_data);
}
int  openmp_sync_ovlp_o2m_scmc_set_parameter_numvec (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_sync_ovlp_o2m_scmc_set_parameter_num_ele (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_sync_ovlp_o2m_scmc_set_parameter_xblock (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_sync_ovlp_o2m_scmc_set_parameter_yblock (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_sync_ovlp_o2m_scmc_set_parameter_zblock (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_sync_ovlp_o2m_scmc_set_parameter_ovlp (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  openmp_yee_local_init (openmp_pscmc_env *  pe ,openmp_yee_local_struct *  kerstr ){
	return  0 ;}
void  openmp_yee_local_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_local_struct ));
}
int  openmp_yee_local_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_yee_local_exec (openmp_yee_local_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_local_scmc_kernel ( 	( kerstr )->inout , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->ovlp)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_yee_local_scmc_set_parameter_inout (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inout = pm->d_data);
}
int  openmp_yee_local_scmc_set_parameter_numvec (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  openmp_yee_local_scmc_set_parameter_num_ele (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  openmp_yee_local_scmc_set_parameter_xblock (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  openmp_yee_local_scmc_set_parameter_yblock (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  openmp_yee_local_scmc_set_parameter_zblock (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  openmp_yee_local_scmc_set_parameter_ovlp (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
