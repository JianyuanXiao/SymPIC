#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "c_pscmc_inc.h"
#include "hydro_A.kernel_inc.h"
int  c_hydro_push_vA_init (c_pscmc_env *  pe ,c_hydro_push_vA_struct *  kerstr ){
	return  0 ;}
void  c_hydro_push_vA_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_hydro_push_vA_struct ));
}
int  c_hydro_push_vA_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_hydro_push_vA_get_num_compute_units (c_hydro_push_vA_struct *  kerstr ){
	return  1 ;}
int  c_hydro_push_vA_exec (c_hydro_push_vA_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_hydro_push_vA_scmc_kernel ( 	( kerstr )->out_vA , 	( kerstr )->alpha_beta_new , 	( kerstr )->alpha_beta , 	( kerstr )->rho_s_vx , 	( kerstr )->vA , 	( kerstr )->vAzero , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->num_ele_rho_s_vx)[0] , (	( kerstr )->num_ele_vA)[0] , (	( kerstr )->num_ele_alpha_beta)[0] , (	( kerstr )->QM0)[0] , (	( kerstr )->U0)[0] , (	( kerstr )->DX)[0] , (	( kerstr )->DY)[0] , (	( kerstr )->DZ)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_hydro_push_vA_scmc_set_parameter_out_vA (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->out_vA = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_alpha_beta_new (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->alpha_beta_new = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_alpha_beta (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->alpha_beta = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_rho_s_vx (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->rho_s_vx = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_vA (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->vA = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_vAzero (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->vAzero = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_y_cpu_core (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_numvec (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_XLEN (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_YLEN (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_ZLEN (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_ovlp (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_xblock (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_yblock (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_zblock (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_num_ele (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_num_ele_rho_s_vx (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_rho_s_vx = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_num_ele_vA (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_vA = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_num_ele_alpha_beta (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_alpha_beta = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_QM0 (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->QM0 = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_U0 (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->U0 = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_DX (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DX = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_DY (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DY = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_DZ (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DZ = pm->d_data);
}
int  c_hydro_push_vA_scmc_set_parameter_DT (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_init (c_pscmc_env *  pe ,c_hydro_push_jac_alpha_beta_struct *  kerstr ){
	return  0 ;}
void  c_hydro_push_jac_alpha_beta_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_hydro_push_jac_alpha_beta_struct ));
}
int  c_hydro_push_jac_alpha_beta_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_hydro_push_jac_alpha_beta_get_num_compute_units (c_hydro_push_jac_alpha_beta_struct *  kerstr ){
	return  1 ;}
int  c_hydro_push_jac_alpha_beta_exec (c_hydro_push_jac_alpha_beta_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_hydro_push_jac_alpha_beta_scmc_kernel ( 	( kerstr )->out_alpha_beta , 	( kerstr )->alpha_beta_new , 	( kerstr )->alpha_beta , 	( kerstr )->rho_s_vx , 	( kerstr )->vA , 	( kerstr )->vAzero , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->num_ele_rho_s_vx)[0] , (	( kerstr )->num_ele_vA)[0] , (	( kerstr )->num_ele_alpha_beta)[0] , (	( kerstr )->QM0)[0] , (	( kerstr )->U0)[0] , (	( kerstr )->DX)[0] , (	( kerstr )->DY)[0] , (	( kerstr )->DZ)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_out_alpha_beta (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->out_alpha_beta = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_alpha_beta_new (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->alpha_beta_new = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_alpha_beta (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->alpha_beta = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_rho_s_vx (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->rho_s_vx = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_vA (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->vA = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_vAzero (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->vAzero = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_y_cpu_core (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_numvec (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_XLEN (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_YLEN (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_ZLEN (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_ovlp (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_xblock (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_yblock (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_zblock (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_num_ele (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_num_ele_rho_s_vx (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_rho_s_vx = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_num_ele_vA (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_vA = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_num_ele_alpha_beta (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_alpha_beta = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_QM0 (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->QM0 = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_U0 (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->U0 = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_DX (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DX = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_DY (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DY = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_DZ (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DZ = pm->d_data);
}
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_DT (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_hydro_push_alpha_beta_init (c_pscmc_env *  pe ,c_hydro_push_alpha_beta_struct *  kerstr ){
	return  0 ;}
void  c_hydro_push_alpha_beta_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_hydro_push_alpha_beta_struct ));
}
int  c_hydro_push_alpha_beta_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_hydro_push_alpha_beta_get_num_compute_units (c_hydro_push_alpha_beta_struct *  kerstr ){
	return  1 ;}
int  c_hydro_push_alpha_beta_exec (c_hydro_push_alpha_beta_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_hydro_push_alpha_beta_scmc_kernel ( 	( kerstr )->out_alpha_beta , 	( kerstr )->alpha_beta_new , 	( kerstr )->alpha_beta , 	( kerstr )->rho_s_vx , 	( kerstr )->vA , 	( kerstr )->vAzero , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->num_ele_rho_s_vx)[0] , (	( kerstr )->num_ele_vA)[0] , (	( kerstr )->num_ele_alpha_beta)[0] , (	( kerstr )->QM0)[0] , (	( kerstr )->U0)[0] , (	( kerstr )->DX)[0] , (	( kerstr )->DY)[0] , (	( kerstr )->DZ)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_hydro_push_alpha_beta_scmc_set_parameter_out_alpha_beta (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->out_alpha_beta = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_alpha_beta_new (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->alpha_beta_new = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_alpha_beta (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->alpha_beta = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_rho_s_vx (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->rho_s_vx = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_vA (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->vA = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_vAzero (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->vAzero = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_y_cpu_core (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_numvec (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_XLEN (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_YLEN (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_ZLEN (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_ovlp (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_xblock (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_yblock (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_zblock (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_num_ele (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_num_ele_rho_s_vx (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_rho_s_vx = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_num_ele_vA (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_vA = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_num_ele_alpha_beta (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_alpha_beta = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_QM0 (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->QM0 = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_U0 (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->U0 = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_DX (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DX = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_DY (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DY = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_DZ (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DZ = pm->d_data);
}
int  c_hydro_push_alpha_beta_scmc_set_parameter_DT (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_hydro_push_vx_init (c_pscmc_env *  pe ,c_hydro_push_vx_struct *  kerstr ){
	return  0 ;}
void  c_hydro_push_vx_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_hydro_push_vx_struct ));
}
int  c_hydro_push_vx_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_hydro_push_vx_get_num_compute_units (c_hydro_push_vx_struct *  kerstr ){
	return  1 ;}
int  c_hydro_push_vx_exec (c_hydro_push_vx_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_hydro_push_vx_scmc_kernel ( 	( kerstr )->out_rho_s_vx , 	( kerstr )->alpha_beta_new , 	( kerstr )->alpha_beta , 	( kerstr )->rho_s_vx , 	( kerstr )->vA , 	( kerstr )->vAzero , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->num_ele_rho_s_vx)[0] , (	( kerstr )->num_ele_vA)[0] , (	( kerstr )->num_ele_alpha_beta)[0] , (	( kerstr )->QM0)[0] , (	( kerstr )->U0)[0] , (	( kerstr )->DX)[0] , (	( kerstr )->DY)[0] , (	( kerstr )->DZ)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_hydro_push_vx_scmc_set_parameter_out_rho_s_vx (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->out_rho_s_vx = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_alpha_beta_new (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->alpha_beta_new = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_alpha_beta (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->alpha_beta = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_rho_s_vx (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->rho_s_vx = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_vA (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->vA = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_vAzero (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->vAzero = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_y_cpu_core (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_numvec (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_XLEN (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_YLEN (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_ZLEN (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_ovlp (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_xblock (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_yblock (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_zblock (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_num_ele (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_num_ele_rho_s_vx (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_rho_s_vx = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_num_ele_vA (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_vA = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_num_ele_alpha_beta (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_alpha_beta = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_QM0 (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->QM0 = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_U0 (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->U0 = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_DX (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DX = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_DY (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DY = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_DZ (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DZ = pm->d_data);
}
int  c_hydro_push_vx_scmc_set_parameter_DT (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_hydro_push_rho_s_init (c_pscmc_env *  pe ,c_hydro_push_rho_s_struct *  kerstr ){
	return  0 ;}
void  c_hydro_push_rho_s_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_hydro_push_rho_s_struct ));
}
int  c_hydro_push_rho_s_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_hydro_push_rho_s_get_num_compute_units (c_hydro_push_rho_s_struct *  kerstr ){
	return  1 ;}
int  c_hydro_push_rho_s_exec (c_hydro_push_rho_s_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_hydro_push_rho_s_scmc_kernel ( 	( kerstr )->out_rho_s_vx , 	( kerstr )->alpha_beta_new , 	( kerstr )->alpha_beta , 	( kerstr )->rho_s_vx , 	( kerstr )->vA , 	( kerstr )->vAzero , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->num_ele_rho_s_vx)[0] , (	( kerstr )->num_ele_vA)[0] , (	( kerstr )->num_ele_alpha_beta)[0] , (	( kerstr )->QM0)[0] , (	( kerstr )->U0)[0] , (	( kerstr )->DX)[0] , (	( kerstr )->DY)[0] , (	( kerstr )->DZ)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_hydro_push_rho_s_scmc_set_parameter_out_rho_s_vx (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->out_rho_s_vx = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_alpha_beta_new (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->alpha_beta_new = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_alpha_beta (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->alpha_beta = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_rho_s_vx (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->rho_s_vx = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_vA (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->vA = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_vAzero (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->vAzero = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_y_cpu_core (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_numvec (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_XLEN (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_YLEN (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_ZLEN (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_ovlp (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_xblock (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_yblock (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_zblock (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_num_ele (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_num_ele_rho_s_vx (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_rho_s_vx = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_num_ele_vA (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_vA = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_num_ele_alpha_beta (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_alpha_beta = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_QM0 (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->QM0 = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_U0 (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->U0 = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_DX (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DX = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_DY (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DY = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_DZ (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DZ = pm->d_data);
}
int  c_hydro_push_rho_s_scmc_set_parameter_DT (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
