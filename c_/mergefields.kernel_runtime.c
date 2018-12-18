#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "c_pscmc_inc.h"
#include "mergefields.kernel_inc.h"
int  c_merge_ovlp_m2o_init (c_pscmc_env *  pe ,c_merge_ovlp_m2o_struct *  kerstr ){
	return  0 ;}
void  c_merge_ovlp_m2o_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_merge_ovlp_m2o_struct ));
}
int  c_merge_ovlp_m2o_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_merge_ovlp_m2o_get_num_compute_units (c_merge_ovlp_m2o_struct *  kerstr ){
	return  1 ;}
int  c_merge_ovlp_m2o_exec (c_merge_ovlp_m2o_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_merge_ovlp_m2o_scmc_kernel ( 	( kerstr )->vecmain , 	( kerstr )->vecovlp , (	( kerstr )->ovlpindex)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->ovlp)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_merge_ovlp_m2o_scmc_set_parameter_vecmain (c_merge_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->vecmain = pm->d_data);
}
int  c_merge_ovlp_m2o_scmc_set_parameter_vecovlp (c_merge_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->vecovlp = pm->d_data);
}
int  c_merge_ovlp_m2o_scmc_set_parameter_ovlpindex (c_merge_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlpindex = pm->d_data);
}
int  c_merge_ovlp_m2o_scmc_set_parameter_numvec (c_merge_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_merge_ovlp_m2o_scmc_set_parameter_num_ele (c_merge_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_merge_ovlp_m2o_scmc_set_parameter_xblock (c_merge_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_merge_ovlp_m2o_scmc_set_parameter_yblock (c_merge_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_merge_ovlp_m2o_scmc_set_parameter_zblock (c_merge_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_merge_ovlp_m2o_scmc_set_parameter_ovlp (c_merge_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_merge_ovlp_o2m_init (c_pscmc_env *  pe ,c_merge_ovlp_o2m_struct *  kerstr ){
	return  0 ;}
void  c_merge_ovlp_o2m_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_merge_ovlp_o2m_struct ));
}
int  c_merge_ovlp_o2m_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_merge_ovlp_o2m_get_num_compute_units (c_merge_ovlp_o2m_struct *  kerstr ){
	return  1 ;}
int  c_merge_ovlp_o2m_exec (c_merge_ovlp_o2m_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_merge_ovlp_o2m_scmc_kernel ( 	( kerstr )->vecmain , 	( kerstr )->vecovlp , (	( kerstr )->ovlpindex)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->ovlp)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_merge_ovlp_o2m_scmc_set_parameter_vecmain (c_merge_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->vecmain = pm->d_data);
}
int  c_merge_ovlp_o2m_scmc_set_parameter_vecovlp (c_merge_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->vecovlp = pm->d_data);
}
int  c_merge_ovlp_o2m_scmc_set_parameter_ovlpindex (c_merge_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlpindex = pm->d_data);
}
int  c_merge_ovlp_o2m_scmc_set_parameter_numvec (c_merge_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_merge_ovlp_o2m_scmc_set_parameter_num_ele (c_merge_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_merge_ovlp_o2m_scmc_set_parameter_xblock (c_merge_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_merge_ovlp_o2m_scmc_set_parameter_yblock (c_merge_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_merge_ovlp_o2m_scmc_set_parameter_zblock (c_merge_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_merge_ovlp_o2m_scmc_set_parameter_ovlp (c_merge_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_sync_ovlp_m2o_init (c_pscmc_env *  pe ,c_sync_ovlp_m2o_struct *  kerstr ){
	return  0 ;}
void  c_sync_ovlp_m2o_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_sync_ovlp_m2o_struct ));
}
int  c_sync_ovlp_m2o_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_sync_ovlp_m2o_get_num_compute_units (c_sync_ovlp_m2o_struct *  kerstr ){
	return  1 ;}
int  c_sync_ovlp_m2o_exec (c_sync_ovlp_m2o_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_sync_ovlp_m2o_scmc_kernel ( 	( kerstr )->vecmain , 	( kerstr )->vecovlp , (	( kerstr )->ovlpindex)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->ovlp)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_sync_ovlp_m2o_scmc_set_parameter_vecmain (c_sync_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->vecmain = pm->d_data);
}
int  c_sync_ovlp_m2o_scmc_set_parameter_vecovlp (c_sync_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->vecovlp = pm->d_data);
}
int  c_sync_ovlp_m2o_scmc_set_parameter_ovlpindex (c_sync_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlpindex = pm->d_data);
}
int  c_sync_ovlp_m2o_scmc_set_parameter_numvec (c_sync_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_sync_ovlp_m2o_scmc_set_parameter_num_ele (c_sync_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_sync_ovlp_m2o_scmc_set_parameter_xblock (c_sync_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_sync_ovlp_m2o_scmc_set_parameter_yblock (c_sync_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_sync_ovlp_m2o_scmc_set_parameter_zblock (c_sync_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_sync_ovlp_m2o_scmc_set_parameter_ovlp (c_sync_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_sync_ovlp_o2m_init (c_pscmc_env *  pe ,c_sync_ovlp_o2m_struct *  kerstr ){
	return  0 ;}
void  c_sync_ovlp_o2m_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_sync_ovlp_o2m_struct ));
}
int  c_sync_ovlp_o2m_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_sync_ovlp_o2m_get_num_compute_units (c_sync_ovlp_o2m_struct *  kerstr ){
	return  1 ;}
int  c_sync_ovlp_o2m_exec (c_sync_ovlp_o2m_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_sync_ovlp_o2m_scmc_kernel ( 	( kerstr )->vecmain , 	( kerstr )->vecovlp , (	( kerstr )->ovlpindex)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->ovlp)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_sync_ovlp_o2m_scmc_set_parameter_vecmain (c_sync_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->vecmain = pm->d_data);
}
int  c_sync_ovlp_o2m_scmc_set_parameter_vecovlp (c_sync_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->vecovlp = pm->d_data);
}
int  c_sync_ovlp_o2m_scmc_set_parameter_ovlpindex (c_sync_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlpindex = pm->d_data);
}
int  c_sync_ovlp_o2m_scmc_set_parameter_numvec (c_sync_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_sync_ovlp_o2m_scmc_set_parameter_num_ele (c_sync_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_sync_ovlp_o2m_scmc_set_parameter_xblock (c_sync_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_sync_ovlp_o2m_scmc_set_parameter_yblock (c_sync_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_sync_ovlp_o2m_scmc_set_parameter_zblock (c_sync_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_sync_ovlp_o2m_scmc_set_parameter_ovlp (c_sync_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_local_init (c_pscmc_env *  pe ,c_yee_local_struct *  kerstr ){
	return  0 ;}
void  c_yee_local_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_local_struct ));
}
int  c_yee_local_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_local_get_num_compute_units (c_yee_local_struct *  kerstr ){
	return  1 ;}
int  c_yee_local_exec (c_yee_local_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_local_scmc_kernel ( 	( kerstr )->inout , (	( kerstr )->numvec)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->ovlp)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_local_scmc_set_parameter_inout (c_yee_local_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inout = pm->d_data);
}
int  c_yee_local_scmc_set_parameter_numvec (c_yee_local_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_local_scmc_set_parameter_num_ele (c_yee_local_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_local_scmc_set_parameter_xblock (c_yee_local_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_local_scmc_set_parameter_yblock (c_yee_local_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_local_scmc_set_parameter_zblock (c_yee_local_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_local_scmc_set_parameter_ovlp (c_yee_local_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
