#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "c_pscmc_inc.h"
#include "mur_abc.kernel_inc.h"
int  c_yee_setfix_xyz_init (c_pscmc_env *  pe ,c_yee_setfix_xyz_struct *  kerstr ){
	return  0 ;}
void  c_yee_setfix_xyz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_setfix_xyz_struct ));
}
int  c_yee_setfix_xyz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_setfix_xyz_get_num_compute_units (c_yee_setfix_xyz_struct *  kerstr ){
	return  1 ;}
int  c_yee_setfix_xyz_exec (c_yee_setfix_xyz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_setfix_xyz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_setfix_xyz_scmc_set_parameter_outEB (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_setfix_xyz_scmc_set_parameter_inEB (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_setfix_xyz_scmc_set_parameter_cur_rankx (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_setfix_xyz_scmc_set_parameter_cur_ranky (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_setfix_xyz_scmc_set_parameter_cur_rankz (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_setfix_xyz_scmc_set_parameter_y_cpu_core (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_setfix_xyz_scmc_set_parameter_numvec (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_setfix_xyz_scmc_set_parameter_XLEN (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_setfix_xyz_scmc_set_parameter_YLEN (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_setfix_xyz_scmc_set_parameter_ZLEN (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_setfix_xyz_scmc_set_parameter_ovlp (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_setfix_xyz_scmc_set_parameter_xblock (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_setfix_xyz_scmc_set_parameter_yblock (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_setfix_xyz_scmc_set_parameter_zblock (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_setfix_xyz_scmc_set_parameter_num_ele (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_setfix_xyz_scmc_set_parameter_damp_vars (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_setfix_xyz_scmc_set_parameter_deltat (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_damp_xyz_init (c_pscmc_env *  pe ,c_yee_damp_xyz_struct *  kerstr ){
	return  0 ;}
void  c_yee_damp_xyz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_damp_xyz_struct ));
}
int  c_yee_damp_xyz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_damp_xyz_get_num_compute_units (c_yee_damp_xyz_struct *  kerstr ){
	return  1 ;}
int  c_yee_damp_xyz_exec (c_yee_damp_xyz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_damp_xyz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_damp_xyz_scmc_set_parameter_outEB (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_damp_xyz_scmc_set_parameter_inEB (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_damp_xyz_scmc_set_parameter_cur_rankx (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_damp_xyz_scmc_set_parameter_cur_ranky (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_damp_xyz_scmc_set_parameter_cur_rankz (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_damp_xyz_scmc_set_parameter_y_cpu_core (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_damp_xyz_scmc_set_parameter_numvec (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_damp_xyz_scmc_set_parameter_XLEN (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_damp_xyz_scmc_set_parameter_YLEN (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_damp_xyz_scmc_set_parameter_ZLEN (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_damp_xyz_scmc_set_parameter_ovlp (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_damp_xyz_scmc_set_parameter_xblock (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_damp_xyz_scmc_set_parameter_yblock (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_damp_xyz_scmc_set_parameter_zblock (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_damp_xyz_scmc_set_parameter_num_ele (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_damp_xyz_scmc_set_parameter_damp_vars (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_damp_xyz_scmc_set_parameter_deltat (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_pec_xyz_init (c_pscmc_env *  pe ,c_yee_pec_xyz_struct *  kerstr ){
	return  0 ;}
void  c_yee_pec_xyz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_pec_xyz_struct ));
}
int  c_yee_pec_xyz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_pec_xyz_get_num_compute_units (c_yee_pec_xyz_struct *  kerstr ){
	return  1 ;}
int  c_yee_pec_xyz_exec (c_yee_pec_xyz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_pec_xyz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_pec_xyz_scmc_set_parameter_outEB (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_pec_xyz_scmc_set_parameter_inEB (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_pec_xyz_scmc_set_parameter_cur_rankx (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_pec_xyz_scmc_set_parameter_cur_ranky (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_pec_xyz_scmc_set_parameter_cur_rankz (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_pec_xyz_scmc_set_parameter_y_cpu_core (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_pec_xyz_scmc_set_parameter_numvec (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_pec_xyz_scmc_set_parameter_XLEN (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_pec_xyz_scmc_set_parameter_YLEN (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_pec_xyz_scmc_set_parameter_ZLEN (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_pec_xyz_scmc_set_parameter_ovlp (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_pec_xyz_scmc_set_parameter_xblock (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_pec_xyz_scmc_set_parameter_yblock (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_pec_xyz_scmc_set_parameter_zblock (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_pec_xyz_scmc_set_parameter_num_ele (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_pec_xyz_scmc_set_parameter_damp_vars (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_pec_xyz_scmc_set_parameter_deltat (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_abc_xyz_init (c_pscmc_env *  pe ,c_yee_abc_xyz_struct *  kerstr ){
	return  0 ;}
void  c_yee_abc_xyz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_abc_xyz_struct ));
}
int  c_yee_abc_xyz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_abc_xyz_get_num_compute_units (c_yee_abc_xyz_struct *  kerstr ){
	return  1 ;}
int  c_yee_abc_xyz_exec (c_yee_abc_xyz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_abc_xyz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_abc_xyz_scmc_set_parameter_outEB (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_abc_xyz_scmc_set_parameter_inEB (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_abc_xyz_scmc_set_parameter_cur_rankx (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_abc_xyz_scmc_set_parameter_cur_ranky (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_abc_xyz_scmc_set_parameter_cur_rankz (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_abc_xyz_scmc_set_parameter_y_cpu_core (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_abc_xyz_scmc_set_parameter_numvec (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_abc_xyz_scmc_set_parameter_XLEN (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_abc_xyz_scmc_set_parameter_YLEN (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_abc_xyz_scmc_set_parameter_ZLEN (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_abc_xyz_scmc_set_parameter_ovlp (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_abc_xyz_scmc_set_parameter_xblock (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_abc_xyz_scmc_set_parameter_yblock (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_abc_xyz_scmc_set_parameter_zblock (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_abc_xyz_scmc_set_parameter_num_ele (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_abc_xyz_scmc_set_parameter_damp_vars (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_abc_xyz_scmc_set_parameter_deltat (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_setfix_yz_init (c_pscmc_env *  pe ,c_yee_setfix_yz_struct *  kerstr ){
	return  0 ;}
void  c_yee_setfix_yz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_setfix_yz_struct ));
}
int  c_yee_setfix_yz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_setfix_yz_get_num_compute_units (c_yee_setfix_yz_struct *  kerstr ){
	return  1 ;}
int  c_yee_setfix_yz_exec (c_yee_setfix_yz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_setfix_yz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_setfix_yz_scmc_set_parameter_outEB (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_setfix_yz_scmc_set_parameter_inEB (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_setfix_yz_scmc_set_parameter_cur_rankx (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_setfix_yz_scmc_set_parameter_cur_ranky (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_setfix_yz_scmc_set_parameter_cur_rankz (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_setfix_yz_scmc_set_parameter_y_cpu_core (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_setfix_yz_scmc_set_parameter_numvec (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_setfix_yz_scmc_set_parameter_XLEN (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_setfix_yz_scmc_set_parameter_YLEN (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_setfix_yz_scmc_set_parameter_ZLEN (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_setfix_yz_scmc_set_parameter_ovlp (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_setfix_yz_scmc_set_parameter_xblock (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_setfix_yz_scmc_set_parameter_yblock (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_setfix_yz_scmc_set_parameter_zblock (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_setfix_yz_scmc_set_parameter_num_ele (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_setfix_yz_scmc_set_parameter_damp_vars (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_setfix_yz_scmc_set_parameter_deltat (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_damp_yz_init (c_pscmc_env *  pe ,c_yee_damp_yz_struct *  kerstr ){
	return  0 ;}
void  c_yee_damp_yz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_damp_yz_struct ));
}
int  c_yee_damp_yz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_damp_yz_get_num_compute_units (c_yee_damp_yz_struct *  kerstr ){
	return  1 ;}
int  c_yee_damp_yz_exec (c_yee_damp_yz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_damp_yz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_damp_yz_scmc_set_parameter_outEB (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_damp_yz_scmc_set_parameter_inEB (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_damp_yz_scmc_set_parameter_cur_rankx (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_damp_yz_scmc_set_parameter_cur_ranky (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_damp_yz_scmc_set_parameter_cur_rankz (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_damp_yz_scmc_set_parameter_y_cpu_core (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_damp_yz_scmc_set_parameter_numvec (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_damp_yz_scmc_set_parameter_XLEN (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_damp_yz_scmc_set_parameter_YLEN (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_damp_yz_scmc_set_parameter_ZLEN (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_damp_yz_scmc_set_parameter_ovlp (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_damp_yz_scmc_set_parameter_xblock (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_damp_yz_scmc_set_parameter_yblock (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_damp_yz_scmc_set_parameter_zblock (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_damp_yz_scmc_set_parameter_num_ele (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_damp_yz_scmc_set_parameter_damp_vars (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_damp_yz_scmc_set_parameter_deltat (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_pec_yz_init (c_pscmc_env *  pe ,c_yee_pec_yz_struct *  kerstr ){
	return  0 ;}
void  c_yee_pec_yz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_pec_yz_struct ));
}
int  c_yee_pec_yz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_pec_yz_get_num_compute_units (c_yee_pec_yz_struct *  kerstr ){
	return  1 ;}
int  c_yee_pec_yz_exec (c_yee_pec_yz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_pec_yz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_pec_yz_scmc_set_parameter_outEB (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_pec_yz_scmc_set_parameter_inEB (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_pec_yz_scmc_set_parameter_cur_rankx (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_pec_yz_scmc_set_parameter_cur_ranky (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_pec_yz_scmc_set_parameter_cur_rankz (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_pec_yz_scmc_set_parameter_y_cpu_core (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_pec_yz_scmc_set_parameter_numvec (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_pec_yz_scmc_set_parameter_XLEN (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_pec_yz_scmc_set_parameter_YLEN (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_pec_yz_scmc_set_parameter_ZLEN (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_pec_yz_scmc_set_parameter_ovlp (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_pec_yz_scmc_set_parameter_xblock (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_pec_yz_scmc_set_parameter_yblock (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_pec_yz_scmc_set_parameter_zblock (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_pec_yz_scmc_set_parameter_num_ele (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_pec_yz_scmc_set_parameter_damp_vars (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_pec_yz_scmc_set_parameter_deltat (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_abc_yz_init (c_pscmc_env *  pe ,c_yee_abc_yz_struct *  kerstr ){
	return  0 ;}
void  c_yee_abc_yz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_abc_yz_struct ));
}
int  c_yee_abc_yz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_abc_yz_get_num_compute_units (c_yee_abc_yz_struct *  kerstr ){
	return  1 ;}
int  c_yee_abc_yz_exec (c_yee_abc_yz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_abc_yz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_abc_yz_scmc_set_parameter_outEB (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_abc_yz_scmc_set_parameter_inEB (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_abc_yz_scmc_set_parameter_cur_rankx (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_abc_yz_scmc_set_parameter_cur_ranky (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_abc_yz_scmc_set_parameter_cur_rankz (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_abc_yz_scmc_set_parameter_y_cpu_core (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_abc_yz_scmc_set_parameter_numvec (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_abc_yz_scmc_set_parameter_XLEN (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_abc_yz_scmc_set_parameter_YLEN (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_abc_yz_scmc_set_parameter_ZLEN (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_abc_yz_scmc_set_parameter_ovlp (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_abc_yz_scmc_set_parameter_xblock (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_abc_yz_scmc_set_parameter_yblock (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_abc_yz_scmc_set_parameter_zblock (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_abc_yz_scmc_set_parameter_num_ele (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_abc_yz_scmc_set_parameter_damp_vars (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_abc_yz_scmc_set_parameter_deltat (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_setfix_xz_init (c_pscmc_env *  pe ,c_yee_setfix_xz_struct *  kerstr ){
	return  0 ;}
void  c_yee_setfix_xz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_setfix_xz_struct ));
}
int  c_yee_setfix_xz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_setfix_xz_get_num_compute_units (c_yee_setfix_xz_struct *  kerstr ){
	return  1 ;}
int  c_yee_setfix_xz_exec (c_yee_setfix_xz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_setfix_xz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_setfix_xz_scmc_set_parameter_outEB (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_setfix_xz_scmc_set_parameter_inEB (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_setfix_xz_scmc_set_parameter_cur_rankx (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_setfix_xz_scmc_set_parameter_cur_ranky (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_setfix_xz_scmc_set_parameter_cur_rankz (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_setfix_xz_scmc_set_parameter_y_cpu_core (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_setfix_xz_scmc_set_parameter_numvec (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_setfix_xz_scmc_set_parameter_XLEN (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_setfix_xz_scmc_set_parameter_YLEN (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_setfix_xz_scmc_set_parameter_ZLEN (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_setfix_xz_scmc_set_parameter_ovlp (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_setfix_xz_scmc_set_parameter_xblock (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_setfix_xz_scmc_set_parameter_yblock (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_setfix_xz_scmc_set_parameter_zblock (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_setfix_xz_scmc_set_parameter_num_ele (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_setfix_xz_scmc_set_parameter_damp_vars (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_setfix_xz_scmc_set_parameter_deltat (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_damp_xz_init (c_pscmc_env *  pe ,c_yee_damp_xz_struct *  kerstr ){
	return  0 ;}
void  c_yee_damp_xz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_damp_xz_struct ));
}
int  c_yee_damp_xz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_damp_xz_get_num_compute_units (c_yee_damp_xz_struct *  kerstr ){
	return  1 ;}
int  c_yee_damp_xz_exec (c_yee_damp_xz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_damp_xz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_damp_xz_scmc_set_parameter_outEB (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_damp_xz_scmc_set_parameter_inEB (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_damp_xz_scmc_set_parameter_cur_rankx (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_damp_xz_scmc_set_parameter_cur_ranky (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_damp_xz_scmc_set_parameter_cur_rankz (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_damp_xz_scmc_set_parameter_y_cpu_core (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_damp_xz_scmc_set_parameter_numvec (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_damp_xz_scmc_set_parameter_XLEN (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_damp_xz_scmc_set_parameter_YLEN (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_damp_xz_scmc_set_parameter_ZLEN (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_damp_xz_scmc_set_parameter_ovlp (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_damp_xz_scmc_set_parameter_xblock (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_damp_xz_scmc_set_parameter_yblock (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_damp_xz_scmc_set_parameter_zblock (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_damp_xz_scmc_set_parameter_num_ele (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_damp_xz_scmc_set_parameter_damp_vars (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_damp_xz_scmc_set_parameter_deltat (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_pec_xz_init (c_pscmc_env *  pe ,c_yee_pec_xz_struct *  kerstr ){
	return  0 ;}
void  c_yee_pec_xz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_pec_xz_struct ));
}
int  c_yee_pec_xz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_pec_xz_get_num_compute_units (c_yee_pec_xz_struct *  kerstr ){
	return  1 ;}
int  c_yee_pec_xz_exec (c_yee_pec_xz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_pec_xz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_pec_xz_scmc_set_parameter_outEB (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_pec_xz_scmc_set_parameter_inEB (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_pec_xz_scmc_set_parameter_cur_rankx (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_pec_xz_scmc_set_parameter_cur_ranky (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_pec_xz_scmc_set_parameter_cur_rankz (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_pec_xz_scmc_set_parameter_y_cpu_core (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_pec_xz_scmc_set_parameter_numvec (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_pec_xz_scmc_set_parameter_XLEN (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_pec_xz_scmc_set_parameter_YLEN (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_pec_xz_scmc_set_parameter_ZLEN (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_pec_xz_scmc_set_parameter_ovlp (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_pec_xz_scmc_set_parameter_xblock (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_pec_xz_scmc_set_parameter_yblock (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_pec_xz_scmc_set_parameter_zblock (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_pec_xz_scmc_set_parameter_num_ele (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_pec_xz_scmc_set_parameter_damp_vars (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_pec_xz_scmc_set_parameter_deltat (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_abc_xz_init (c_pscmc_env *  pe ,c_yee_abc_xz_struct *  kerstr ){
	return  0 ;}
void  c_yee_abc_xz_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_abc_xz_struct ));
}
int  c_yee_abc_xz_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_abc_xz_get_num_compute_units (c_yee_abc_xz_struct *  kerstr ){
	return  1 ;}
int  c_yee_abc_xz_exec (c_yee_abc_xz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_abc_xz_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_abc_xz_scmc_set_parameter_outEB (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_abc_xz_scmc_set_parameter_inEB (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_abc_xz_scmc_set_parameter_cur_rankx (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_abc_xz_scmc_set_parameter_cur_ranky (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_abc_xz_scmc_set_parameter_cur_rankz (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_abc_xz_scmc_set_parameter_y_cpu_core (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_abc_xz_scmc_set_parameter_numvec (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_abc_xz_scmc_set_parameter_XLEN (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_abc_xz_scmc_set_parameter_YLEN (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_abc_xz_scmc_set_parameter_ZLEN (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_abc_xz_scmc_set_parameter_ovlp (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_abc_xz_scmc_set_parameter_xblock (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_abc_xz_scmc_set_parameter_yblock (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_abc_xz_scmc_set_parameter_zblock (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_abc_xz_scmc_set_parameter_num_ele (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_abc_xz_scmc_set_parameter_damp_vars (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_abc_xz_scmc_set_parameter_deltat (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_setfix_xy_init (c_pscmc_env *  pe ,c_yee_setfix_xy_struct *  kerstr ){
	return  0 ;}
void  c_yee_setfix_xy_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_setfix_xy_struct ));
}
int  c_yee_setfix_xy_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_setfix_xy_get_num_compute_units (c_yee_setfix_xy_struct *  kerstr ){
	return  1 ;}
int  c_yee_setfix_xy_exec (c_yee_setfix_xy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_setfix_xy_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_setfix_xy_scmc_set_parameter_outEB (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_setfix_xy_scmc_set_parameter_inEB (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_setfix_xy_scmc_set_parameter_cur_rankx (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_setfix_xy_scmc_set_parameter_cur_ranky (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_setfix_xy_scmc_set_parameter_cur_rankz (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_setfix_xy_scmc_set_parameter_y_cpu_core (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_setfix_xy_scmc_set_parameter_numvec (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_setfix_xy_scmc_set_parameter_XLEN (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_setfix_xy_scmc_set_parameter_YLEN (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_setfix_xy_scmc_set_parameter_ZLEN (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_setfix_xy_scmc_set_parameter_ovlp (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_setfix_xy_scmc_set_parameter_xblock (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_setfix_xy_scmc_set_parameter_yblock (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_setfix_xy_scmc_set_parameter_zblock (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_setfix_xy_scmc_set_parameter_num_ele (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_setfix_xy_scmc_set_parameter_damp_vars (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_setfix_xy_scmc_set_parameter_deltat (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_damp_xy_init (c_pscmc_env *  pe ,c_yee_damp_xy_struct *  kerstr ){
	return  0 ;}
void  c_yee_damp_xy_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_damp_xy_struct ));
}
int  c_yee_damp_xy_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_damp_xy_get_num_compute_units (c_yee_damp_xy_struct *  kerstr ){
	return  1 ;}
int  c_yee_damp_xy_exec (c_yee_damp_xy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_damp_xy_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_damp_xy_scmc_set_parameter_outEB (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_damp_xy_scmc_set_parameter_inEB (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_damp_xy_scmc_set_parameter_cur_rankx (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_damp_xy_scmc_set_parameter_cur_ranky (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_damp_xy_scmc_set_parameter_cur_rankz (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_damp_xy_scmc_set_parameter_y_cpu_core (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_damp_xy_scmc_set_parameter_numvec (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_damp_xy_scmc_set_parameter_XLEN (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_damp_xy_scmc_set_parameter_YLEN (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_damp_xy_scmc_set_parameter_ZLEN (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_damp_xy_scmc_set_parameter_ovlp (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_damp_xy_scmc_set_parameter_xblock (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_damp_xy_scmc_set_parameter_yblock (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_damp_xy_scmc_set_parameter_zblock (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_damp_xy_scmc_set_parameter_num_ele (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_damp_xy_scmc_set_parameter_damp_vars (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_damp_xy_scmc_set_parameter_deltat (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_pec_xy_init (c_pscmc_env *  pe ,c_yee_pec_xy_struct *  kerstr ){
	return  0 ;}
void  c_yee_pec_xy_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_pec_xy_struct ));
}
int  c_yee_pec_xy_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_pec_xy_get_num_compute_units (c_yee_pec_xy_struct *  kerstr ){
	return  1 ;}
int  c_yee_pec_xy_exec (c_yee_pec_xy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_pec_xy_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_pec_xy_scmc_set_parameter_outEB (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_pec_xy_scmc_set_parameter_inEB (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_pec_xy_scmc_set_parameter_cur_rankx (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_pec_xy_scmc_set_parameter_cur_ranky (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_pec_xy_scmc_set_parameter_cur_rankz (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_pec_xy_scmc_set_parameter_y_cpu_core (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_pec_xy_scmc_set_parameter_numvec (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_pec_xy_scmc_set_parameter_XLEN (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_pec_xy_scmc_set_parameter_YLEN (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_pec_xy_scmc_set_parameter_ZLEN (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_pec_xy_scmc_set_parameter_ovlp (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_pec_xy_scmc_set_parameter_xblock (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_pec_xy_scmc_set_parameter_yblock (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_pec_xy_scmc_set_parameter_zblock (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_pec_xy_scmc_set_parameter_num_ele (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_pec_xy_scmc_set_parameter_damp_vars (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_pec_xy_scmc_set_parameter_deltat (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_abc_xy_init (c_pscmc_env *  pe ,c_yee_abc_xy_struct *  kerstr ){
	return  0 ;}
void  c_yee_abc_xy_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_abc_xy_struct ));
}
int  c_yee_abc_xy_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_abc_xy_get_num_compute_units (c_yee_abc_xy_struct *  kerstr ){
	return  1 ;}
int  c_yee_abc_xy_exec (c_yee_abc_xy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_abc_xy_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_abc_xy_scmc_set_parameter_outEB (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_abc_xy_scmc_set_parameter_inEB (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_abc_xy_scmc_set_parameter_cur_rankx (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_abc_xy_scmc_set_parameter_cur_ranky (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_abc_xy_scmc_set_parameter_cur_rankz (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_abc_xy_scmc_set_parameter_y_cpu_core (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_abc_xy_scmc_set_parameter_numvec (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_abc_xy_scmc_set_parameter_XLEN (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_abc_xy_scmc_set_parameter_YLEN (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_abc_xy_scmc_set_parameter_ZLEN (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_abc_xy_scmc_set_parameter_ovlp (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_abc_xy_scmc_set_parameter_xblock (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_abc_xy_scmc_set_parameter_yblock (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_abc_xy_scmc_set_parameter_zblock (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_abc_xy_scmc_set_parameter_num_ele (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_abc_xy_scmc_set_parameter_damp_vars (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_abc_xy_scmc_set_parameter_deltat (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_setfix_z_init (c_pscmc_env *  pe ,c_yee_setfix_z_struct *  kerstr ){
	return  0 ;}
void  c_yee_setfix_z_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_setfix_z_struct ));
}
int  c_yee_setfix_z_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_setfix_z_get_num_compute_units (c_yee_setfix_z_struct *  kerstr ){
	return  1 ;}
int  c_yee_setfix_z_exec (c_yee_setfix_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_setfix_z_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_setfix_z_scmc_set_parameter_outEB (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_setfix_z_scmc_set_parameter_inEB (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_setfix_z_scmc_set_parameter_cur_rankx (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_setfix_z_scmc_set_parameter_cur_ranky (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_setfix_z_scmc_set_parameter_cur_rankz (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_setfix_z_scmc_set_parameter_y_cpu_core (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_setfix_z_scmc_set_parameter_numvec (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_setfix_z_scmc_set_parameter_XLEN (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_setfix_z_scmc_set_parameter_YLEN (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_setfix_z_scmc_set_parameter_ZLEN (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_setfix_z_scmc_set_parameter_ovlp (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_setfix_z_scmc_set_parameter_xblock (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_setfix_z_scmc_set_parameter_yblock (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_setfix_z_scmc_set_parameter_zblock (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_setfix_z_scmc_set_parameter_num_ele (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_setfix_z_scmc_set_parameter_damp_vars (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_setfix_z_scmc_set_parameter_deltat (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_damp_z_init (c_pscmc_env *  pe ,c_yee_damp_z_struct *  kerstr ){
	return  0 ;}
void  c_yee_damp_z_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_damp_z_struct ));
}
int  c_yee_damp_z_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_damp_z_get_num_compute_units (c_yee_damp_z_struct *  kerstr ){
	return  1 ;}
int  c_yee_damp_z_exec (c_yee_damp_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_damp_z_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_damp_z_scmc_set_parameter_outEB (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_damp_z_scmc_set_parameter_inEB (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_damp_z_scmc_set_parameter_cur_rankx (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_damp_z_scmc_set_parameter_cur_ranky (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_damp_z_scmc_set_parameter_cur_rankz (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_damp_z_scmc_set_parameter_y_cpu_core (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_damp_z_scmc_set_parameter_numvec (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_damp_z_scmc_set_parameter_XLEN (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_damp_z_scmc_set_parameter_YLEN (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_damp_z_scmc_set_parameter_ZLEN (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_damp_z_scmc_set_parameter_ovlp (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_damp_z_scmc_set_parameter_xblock (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_damp_z_scmc_set_parameter_yblock (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_damp_z_scmc_set_parameter_zblock (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_damp_z_scmc_set_parameter_num_ele (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_damp_z_scmc_set_parameter_damp_vars (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_damp_z_scmc_set_parameter_deltat (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_pec_z_init (c_pscmc_env *  pe ,c_yee_pec_z_struct *  kerstr ){
	return  0 ;}
void  c_yee_pec_z_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_pec_z_struct ));
}
int  c_yee_pec_z_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_pec_z_get_num_compute_units (c_yee_pec_z_struct *  kerstr ){
	return  1 ;}
int  c_yee_pec_z_exec (c_yee_pec_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_pec_z_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_pec_z_scmc_set_parameter_outEB (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_pec_z_scmc_set_parameter_inEB (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_pec_z_scmc_set_parameter_cur_rankx (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_pec_z_scmc_set_parameter_cur_ranky (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_pec_z_scmc_set_parameter_cur_rankz (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_pec_z_scmc_set_parameter_y_cpu_core (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_pec_z_scmc_set_parameter_numvec (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_pec_z_scmc_set_parameter_XLEN (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_pec_z_scmc_set_parameter_YLEN (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_pec_z_scmc_set_parameter_ZLEN (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_pec_z_scmc_set_parameter_ovlp (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_pec_z_scmc_set_parameter_xblock (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_pec_z_scmc_set_parameter_yblock (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_pec_z_scmc_set_parameter_zblock (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_pec_z_scmc_set_parameter_num_ele (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_pec_z_scmc_set_parameter_damp_vars (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_pec_z_scmc_set_parameter_deltat (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_abc_z_init (c_pscmc_env *  pe ,c_yee_abc_z_struct *  kerstr ){
	return  0 ;}
void  c_yee_abc_z_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_abc_z_struct ));
}
int  c_yee_abc_z_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_abc_z_get_num_compute_units (c_yee_abc_z_struct *  kerstr ){
	return  1 ;}
int  c_yee_abc_z_exec (c_yee_abc_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_abc_z_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_abc_z_scmc_set_parameter_outEB (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_abc_z_scmc_set_parameter_inEB (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_abc_z_scmc_set_parameter_cur_rankx (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_abc_z_scmc_set_parameter_cur_ranky (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_abc_z_scmc_set_parameter_cur_rankz (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_abc_z_scmc_set_parameter_y_cpu_core (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_abc_z_scmc_set_parameter_numvec (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_abc_z_scmc_set_parameter_XLEN (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_abc_z_scmc_set_parameter_YLEN (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_abc_z_scmc_set_parameter_ZLEN (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_abc_z_scmc_set_parameter_ovlp (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_abc_z_scmc_set_parameter_xblock (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_abc_z_scmc_set_parameter_yblock (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_abc_z_scmc_set_parameter_zblock (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_abc_z_scmc_set_parameter_num_ele (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_abc_z_scmc_set_parameter_damp_vars (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_abc_z_scmc_set_parameter_deltat (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_setfix_y_init (c_pscmc_env *  pe ,c_yee_setfix_y_struct *  kerstr ){
	return  0 ;}
void  c_yee_setfix_y_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_setfix_y_struct ));
}
int  c_yee_setfix_y_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_setfix_y_get_num_compute_units (c_yee_setfix_y_struct *  kerstr ){
	return  1 ;}
int  c_yee_setfix_y_exec (c_yee_setfix_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_setfix_y_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_setfix_y_scmc_set_parameter_outEB (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_setfix_y_scmc_set_parameter_inEB (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_setfix_y_scmc_set_parameter_cur_rankx (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_setfix_y_scmc_set_parameter_cur_ranky (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_setfix_y_scmc_set_parameter_cur_rankz (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_setfix_y_scmc_set_parameter_y_cpu_core (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_setfix_y_scmc_set_parameter_numvec (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_setfix_y_scmc_set_parameter_XLEN (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_setfix_y_scmc_set_parameter_YLEN (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_setfix_y_scmc_set_parameter_ZLEN (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_setfix_y_scmc_set_parameter_ovlp (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_setfix_y_scmc_set_parameter_xblock (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_setfix_y_scmc_set_parameter_yblock (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_setfix_y_scmc_set_parameter_zblock (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_setfix_y_scmc_set_parameter_num_ele (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_setfix_y_scmc_set_parameter_damp_vars (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_setfix_y_scmc_set_parameter_deltat (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_damp_y_init (c_pscmc_env *  pe ,c_yee_damp_y_struct *  kerstr ){
	return  0 ;}
void  c_yee_damp_y_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_damp_y_struct ));
}
int  c_yee_damp_y_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_damp_y_get_num_compute_units (c_yee_damp_y_struct *  kerstr ){
	return  1 ;}
int  c_yee_damp_y_exec (c_yee_damp_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_damp_y_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_damp_y_scmc_set_parameter_outEB (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_damp_y_scmc_set_parameter_inEB (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_damp_y_scmc_set_parameter_cur_rankx (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_damp_y_scmc_set_parameter_cur_ranky (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_damp_y_scmc_set_parameter_cur_rankz (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_damp_y_scmc_set_parameter_y_cpu_core (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_damp_y_scmc_set_parameter_numvec (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_damp_y_scmc_set_parameter_XLEN (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_damp_y_scmc_set_parameter_YLEN (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_damp_y_scmc_set_parameter_ZLEN (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_damp_y_scmc_set_parameter_ovlp (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_damp_y_scmc_set_parameter_xblock (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_damp_y_scmc_set_parameter_yblock (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_damp_y_scmc_set_parameter_zblock (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_damp_y_scmc_set_parameter_num_ele (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_damp_y_scmc_set_parameter_damp_vars (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_damp_y_scmc_set_parameter_deltat (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_pec_y_init (c_pscmc_env *  pe ,c_yee_pec_y_struct *  kerstr ){
	return  0 ;}
void  c_yee_pec_y_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_pec_y_struct ));
}
int  c_yee_pec_y_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_pec_y_get_num_compute_units (c_yee_pec_y_struct *  kerstr ){
	return  1 ;}
int  c_yee_pec_y_exec (c_yee_pec_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_pec_y_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_pec_y_scmc_set_parameter_outEB (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_pec_y_scmc_set_parameter_inEB (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_pec_y_scmc_set_parameter_cur_rankx (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_pec_y_scmc_set_parameter_cur_ranky (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_pec_y_scmc_set_parameter_cur_rankz (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_pec_y_scmc_set_parameter_y_cpu_core (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_pec_y_scmc_set_parameter_numvec (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_pec_y_scmc_set_parameter_XLEN (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_pec_y_scmc_set_parameter_YLEN (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_pec_y_scmc_set_parameter_ZLEN (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_pec_y_scmc_set_parameter_ovlp (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_pec_y_scmc_set_parameter_xblock (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_pec_y_scmc_set_parameter_yblock (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_pec_y_scmc_set_parameter_zblock (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_pec_y_scmc_set_parameter_num_ele (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_pec_y_scmc_set_parameter_damp_vars (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_pec_y_scmc_set_parameter_deltat (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_abc_y_init (c_pscmc_env *  pe ,c_yee_abc_y_struct *  kerstr ){
	return  0 ;}
void  c_yee_abc_y_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_abc_y_struct ));
}
int  c_yee_abc_y_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_abc_y_get_num_compute_units (c_yee_abc_y_struct *  kerstr ){
	return  1 ;}
int  c_yee_abc_y_exec (c_yee_abc_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_abc_y_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_abc_y_scmc_set_parameter_outEB (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_abc_y_scmc_set_parameter_inEB (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_abc_y_scmc_set_parameter_cur_rankx (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_abc_y_scmc_set_parameter_cur_ranky (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_abc_y_scmc_set_parameter_cur_rankz (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_abc_y_scmc_set_parameter_y_cpu_core (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_abc_y_scmc_set_parameter_numvec (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_abc_y_scmc_set_parameter_XLEN (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_abc_y_scmc_set_parameter_YLEN (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_abc_y_scmc_set_parameter_ZLEN (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_abc_y_scmc_set_parameter_ovlp (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_abc_y_scmc_set_parameter_xblock (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_abc_y_scmc_set_parameter_yblock (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_abc_y_scmc_set_parameter_zblock (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_abc_y_scmc_set_parameter_num_ele (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_abc_y_scmc_set_parameter_damp_vars (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_abc_y_scmc_set_parameter_deltat (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_setfix_x_init (c_pscmc_env *  pe ,c_yee_setfix_x_struct *  kerstr ){
	return  0 ;}
void  c_yee_setfix_x_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_setfix_x_struct ));
}
int  c_yee_setfix_x_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_setfix_x_get_num_compute_units (c_yee_setfix_x_struct *  kerstr ){
	return  1 ;}
int  c_yee_setfix_x_exec (c_yee_setfix_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_setfix_x_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_setfix_x_scmc_set_parameter_outEB (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_setfix_x_scmc_set_parameter_inEB (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_setfix_x_scmc_set_parameter_cur_rankx (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_setfix_x_scmc_set_parameter_cur_ranky (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_setfix_x_scmc_set_parameter_cur_rankz (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_setfix_x_scmc_set_parameter_y_cpu_core (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_setfix_x_scmc_set_parameter_numvec (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_setfix_x_scmc_set_parameter_XLEN (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_setfix_x_scmc_set_parameter_YLEN (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_setfix_x_scmc_set_parameter_ZLEN (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_setfix_x_scmc_set_parameter_ovlp (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_setfix_x_scmc_set_parameter_xblock (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_setfix_x_scmc_set_parameter_yblock (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_setfix_x_scmc_set_parameter_zblock (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_setfix_x_scmc_set_parameter_num_ele (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_setfix_x_scmc_set_parameter_damp_vars (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_setfix_x_scmc_set_parameter_deltat (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_damp_x_init (c_pscmc_env *  pe ,c_yee_damp_x_struct *  kerstr ){
	return  0 ;}
void  c_yee_damp_x_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_damp_x_struct ));
}
int  c_yee_damp_x_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_damp_x_get_num_compute_units (c_yee_damp_x_struct *  kerstr ){
	return  1 ;}
int  c_yee_damp_x_exec (c_yee_damp_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_damp_x_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_damp_x_scmc_set_parameter_outEB (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_damp_x_scmc_set_parameter_inEB (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_damp_x_scmc_set_parameter_cur_rankx (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_damp_x_scmc_set_parameter_cur_ranky (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_damp_x_scmc_set_parameter_cur_rankz (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_damp_x_scmc_set_parameter_y_cpu_core (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_damp_x_scmc_set_parameter_numvec (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_damp_x_scmc_set_parameter_XLEN (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_damp_x_scmc_set_parameter_YLEN (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_damp_x_scmc_set_parameter_ZLEN (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_damp_x_scmc_set_parameter_ovlp (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_damp_x_scmc_set_parameter_xblock (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_damp_x_scmc_set_parameter_yblock (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_damp_x_scmc_set_parameter_zblock (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_damp_x_scmc_set_parameter_num_ele (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_damp_x_scmc_set_parameter_damp_vars (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_damp_x_scmc_set_parameter_deltat (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_pec_x_init (c_pscmc_env *  pe ,c_yee_pec_x_struct *  kerstr ){
	return  0 ;}
void  c_yee_pec_x_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_pec_x_struct ));
}
int  c_yee_pec_x_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_pec_x_get_num_compute_units (c_yee_pec_x_struct *  kerstr ){
	return  1 ;}
int  c_yee_pec_x_exec (c_yee_pec_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_pec_x_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_pec_x_scmc_set_parameter_outEB (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_pec_x_scmc_set_parameter_inEB (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_pec_x_scmc_set_parameter_cur_rankx (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_pec_x_scmc_set_parameter_cur_ranky (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_pec_x_scmc_set_parameter_cur_rankz (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_pec_x_scmc_set_parameter_y_cpu_core (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_pec_x_scmc_set_parameter_numvec (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_pec_x_scmc_set_parameter_XLEN (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_pec_x_scmc_set_parameter_YLEN (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_pec_x_scmc_set_parameter_ZLEN (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_pec_x_scmc_set_parameter_ovlp (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_pec_x_scmc_set_parameter_xblock (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_pec_x_scmc_set_parameter_yblock (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_pec_x_scmc_set_parameter_zblock (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_pec_x_scmc_set_parameter_num_ele (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_pec_x_scmc_set_parameter_damp_vars (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_pec_x_scmc_set_parameter_deltat (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_abc_x_init (c_pscmc_env *  pe ,c_yee_abc_x_struct *  kerstr ){
	return  0 ;}
void  c_yee_abc_x_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_abc_x_struct ));
}
int  c_yee_abc_x_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_abc_x_get_num_compute_units (c_yee_abc_x_struct *  kerstr ){
	return  1 ;}
int  c_yee_abc_x_exec (c_yee_abc_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_abc_x_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_abc_x_scmc_set_parameter_outEB (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_abc_x_scmc_set_parameter_inEB (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_abc_x_scmc_set_parameter_cur_rankx (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_abc_x_scmc_set_parameter_cur_ranky (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_abc_x_scmc_set_parameter_cur_rankz (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_abc_x_scmc_set_parameter_y_cpu_core (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_abc_x_scmc_set_parameter_numvec (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_abc_x_scmc_set_parameter_XLEN (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_abc_x_scmc_set_parameter_YLEN (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_abc_x_scmc_set_parameter_ZLEN (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_abc_x_scmc_set_parameter_ovlp (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_abc_x_scmc_set_parameter_xblock (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_abc_x_scmc_set_parameter_yblock (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_abc_x_scmc_set_parameter_zblock (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_abc_x_scmc_set_parameter_num_ele (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_abc_x_scmc_set_parameter_damp_vars (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_abc_x_scmc_set_parameter_deltat (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_setfix__init (c_pscmc_env *  pe ,c_yee_setfix__struct *  kerstr ){
	return  0 ;}
void  c_yee_setfix__get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_setfix__struct ));
}
int  c_yee_setfix__get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_setfix__get_num_compute_units (c_yee_setfix__struct *  kerstr ){
	return  1 ;}
int  c_yee_setfix__exec (c_yee_setfix__struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_setfix__scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_setfix__scmc_set_parameter_outEB (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_setfix__scmc_set_parameter_inEB (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_setfix__scmc_set_parameter_cur_rankx (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_setfix__scmc_set_parameter_cur_ranky (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_setfix__scmc_set_parameter_cur_rankz (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_setfix__scmc_set_parameter_y_cpu_core (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_setfix__scmc_set_parameter_numvec (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_setfix__scmc_set_parameter_XLEN (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_setfix__scmc_set_parameter_YLEN (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_setfix__scmc_set_parameter_ZLEN (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_setfix__scmc_set_parameter_ovlp (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_setfix__scmc_set_parameter_xblock (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_setfix__scmc_set_parameter_yblock (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_setfix__scmc_set_parameter_zblock (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_setfix__scmc_set_parameter_num_ele (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_setfix__scmc_set_parameter_damp_vars (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_setfix__scmc_set_parameter_deltat (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_damp__init (c_pscmc_env *  pe ,c_yee_damp__struct *  kerstr ){
	return  0 ;}
void  c_yee_damp__get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_damp__struct ));
}
int  c_yee_damp__get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_damp__get_num_compute_units (c_yee_damp__struct *  kerstr ){
	return  1 ;}
int  c_yee_damp__exec (c_yee_damp__struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_damp__scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_damp__scmc_set_parameter_outEB (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_damp__scmc_set_parameter_inEB (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_damp__scmc_set_parameter_cur_rankx (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_damp__scmc_set_parameter_cur_ranky (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_damp__scmc_set_parameter_cur_rankz (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_damp__scmc_set_parameter_y_cpu_core (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_damp__scmc_set_parameter_numvec (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_damp__scmc_set_parameter_XLEN (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_damp__scmc_set_parameter_YLEN (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_damp__scmc_set_parameter_ZLEN (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_damp__scmc_set_parameter_ovlp (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_damp__scmc_set_parameter_xblock (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_damp__scmc_set_parameter_yblock (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_damp__scmc_set_parameter_zblock (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_damp__scmc_set_parameter_num_ele (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_damp__scmc_set_parameter_damp_vars (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_damp__scmc_set_parameter_deltat (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_pec__init (c_pscmc_env *  pe ,c_yee_pec__struct *  kerstr ){
	return  0 ;}
void  c_yee_pec__get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_pec__struct ));
}
int  c_yee_pec__get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_pec__get_num_compute_units (c_yee_pec__struct *  kerstr ){
	return  1 ;}
int  c_yee_pec__exec (c_yee_pec__struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_pec__scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_pec__scmc_set_parameter_outEB (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_pec__scmc_set_parameter_inEB (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_pec__scmc_set_parameter_cur_rankx (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_pec__scmc_set_parameter_cur_ranky (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_pec__scmc_set_parameter_cur_rankz (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_pec__scmc_set_parameter_y_cpu_core (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_pec__scmc_set_parameter_numvec (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_pec__scmc_set_parameter_XLEN (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_pec__scmc_set_parameter_YLEN (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_pec__scmc_set_parameter_ZLEN (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_pec__scmc_set_parameter_ovlp (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_pec__scmc_set_parameter_xblock (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_pec__scmc_set_parameter_yblock (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_pec__scmc_set_parameter_zblock (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_pec__scmc_set_parameter_num_ele (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_pec__scmc_set_parameter_damp_vars (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_pec__scmc_set_parameter_deltat (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
int  c_yee_abc__init (c_pscmc_env *  pe ,c_yee_abc__struct *  kerstr ){
	return  0 ;}
void  c_yee_abc__get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_yee_abc__struct ));
}
int  c_yee_abc__get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_yee_abc__get_num_compute_units (c_yee_abc__struct *  kerstr ){
	return  1 ;}
int  c_yee_abc__exec (c_yee_abc__struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_yee_abc__scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->cur_rankx , 	( kerstr )->cur_ranky , 	( kerstr )->cur_rankz , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->damp_vars)[0] , (	( kerstr )->deltat)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_yee_abc__scmc_set_parameter_outEB (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_yee_abc__scmc_set_parameter_inEB (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_yee_abc__scmc_set_parameter_cur_rankx (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankx = pm->d_data);
}
int  c_yee_abc__scmc_set_parameter_cur_ranky (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_ranky = pm->d_data);
}
int  c_yee_abc__scmc_set_parameter_cur_rankz (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cur_rankz = pm->d_data);
}
int  c_yee_abc__scmc_set_parameter_y_cpu_core (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_yee_abc__scmc_set_parameter_numvec (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_yee_abc__scmc_set_parameter_XLEN (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_yee_abc__scmc_set_parameter_YLEN (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_yee_abc__scmc_set_parameter_ZLEN (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_yee_abc__scmc_set_parameter_ovlp (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_yee_abc__scmc_set_parameter_xblock (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_yee_abc__scmc_set_parameter_yblock (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_yee_abc__scmc_set_parameter_zblock (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_yee_abc__scmc_set_parameter_num_ele (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_yee_abc__scmc_set_parameter_damp_vars (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->damp_vars = pm->d_data);
}
int  c_yee_abc__scmc_set_parameter_deltat (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->deltat = pm->d_data);
}
