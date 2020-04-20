#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "c_pscmc_inc.h"
#include "dmbihamt.kernel_inc.h"
int  c_dm_calc_hamt_dual_init (c_pscmc_env *  pe ,c_dm_calc_hamt_dual_struct *  kerstr ){
	return  0 ;}
void  c_dm_calc_hamt_dual_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_dm_calc_hamt_dual_struct ));
}
int  c_dm_calc_hamt_dual_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_dm_calc_hamt_dual_get_num_compute_units (c_dm_calc_hamt_dual_struct *  kerstr ){
	return  1 ;}
int  c_dm_calc_hamt_dual_exec (c_dm_calc_hamt_dual_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_dm_calc_hamt_dual_scmc_kernel ( 	( kerstr )->dphi_dt_out , 	( kerstr )->phi_in , 	( kerstr )->A1 , 	( kerstr )->Y1 , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->num_ele_A1)[0] , (	( kerstr )->M)[0] , (	( kerstr )->Q)[0] , (	( kerstr )->DM_A)[0] , (	( kerstr )->DX)[0] , (	( kerstr )->DY)[0] , (	( kerstr )->DZ)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_dm_calc_hamt_dual_scmc_set_parameter_dphi_dt_out (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->dphi_dt_out = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_phi_in (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->phi_in = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_A1 (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->A1 = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_Y1 (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Y1 = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_y_cpu_core (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_numvec (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_XLEN (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_YLEN (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_ZLEN (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_ovlp (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_xblock (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_yblock (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_zblock (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_num_ele (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_num_ele_A1 (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_A1 = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_M (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->M = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_Q (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Q = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_DM_A (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DM_A = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_DX (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DX = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_DY (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DY = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_DZ (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DZ = pm->d_data);
}
int  c_dm_calc_hamt_dual_scmc_set_parameter_DT (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_dm_cayley_eqn_core_init (c_pscmc_env *  pe ,c_dm_cayley_eqn_core_struct *  kerstr ){
	return  0 ;}
void  c_dm_cayley_eqn_core_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_dm_cayley_eqn_core_struct ));
}
int  c_dm_cayley_eqn_core_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_dm_cayley_eqn_core_get_num_compute_units (c_dm_cayley_eqn_core_struct *  kerstr ){
	return  1 ;}
int  c_dm_cayley_eqn_core_exec (c_dm_cayley_eqn_core_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_dm_cayley_eqn_core_scmc_kernel ( 	( kerstr )->dphi_dt_out , 	( kerstr )->phi_in , 	( kerstr )->A1 , 	( kerstr )->Y1 , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->num_ele_A1)[0] , (	( kerstr )->M)[0] , (	( kerstr )->Q)[0] , (	( kerstr )->DM_A)[0] , (	( kerstr )->DX)[0] , (	( kerstr )->DY)[0] , (	( kerstr )->DZ)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_dm_cayley_eqn_core_scmc_set_parameter_dphi_dt_out (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->dphi_dt_out = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_phi_in (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->phi_in = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_A1 (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->A1 = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_Y1 (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Y1 = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_y_cpu_core (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_numvec (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_XLEN (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_YLEN (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_ZLEN (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_ovlp (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_xblock (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_yblock (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_zblock (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_num_ele (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_num_ele_A1 (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_A1 = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_M (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->M = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_Q (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Q = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_DM_A (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DM_A = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_DX (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DX = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_DY (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DY = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_DZ (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DZ = pm->d_data);
}
int  c_dm_cayley_eqn_core_scmc_set_parameter_DT (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_dm_exact_eqn_m_init (c_pscmc_env *  pe ,c_dm_exact_eqn_m_struct *  kerstr ){
	return  0 ;}
void  c_dm_exact_eqn_m_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_dm_exact_eqn_m_struct ));
}
int  c_dm_exact_eqn_m_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_dm_exact_eqn_m_get_num_compute_units (c_dm_exact_eqn_m_struct *  kerstr ){
	return  1 ;}
int  c_dm_exact_eqn_m_exec (c_dm_exact_eqn_m_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_dm_exact_eqn_m_scmc_kernel ( 	( kerstr )->dphi_dt_out , 	( kerstr )->phi_in , 	( kerstr )->A1 , 	( kerstr )->Y1 , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->num_ele_A1)[0] , (	( kerstr )->M)[0] , (	( kerstr )->Q)[0] , (	( kerstr )->DM_A)[0] , (	( kerstr )->DX)[0] , (	( kerstr )->DY)[0] , (	( kerstr )->DZ)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_dm_exact_eqn_m_scmc_set_parameter_dphi_dt_out (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->dphi_dt_out = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_phi_in (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->phi_in = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_A1 (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->A1 = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_Y1 (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Y1 = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_y_cpu_core (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_numvec (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_XLEN (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_YLEN (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_ZLEN (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_ovlp (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_xblock (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_yblock (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_zblock (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_num_ele (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_num_ele_A1 (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_A1 = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_M (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->M = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_Q (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Q = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_DM_A (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DM_A = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_DX (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DX = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_DY (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DY = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_DZ (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DZ = pm->d_data);
}
int  c_dm_exact_eqn_m_scmc_set_parameter_DT (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_dm_calc_hamt_init (c_pscmc_env *  pe ,c_dm_calc_hamt_struct *  kerstr ){
	return  0 ;}
void  c_dm_calc_hamt_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_dm_calc_hamt_struct ));
}
int  c_dm_calc_hamt_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_dm_calc_hamt_get_num_compute_units (c_dm_calc_hamt_struct *  kerstr ){
	return  1 ;}
int  c_dm_calc_hamt_exec (c_dm_calc_hamt_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_dm_calc_hamt_scmc_kernel ( 	( kerstr )->dphi_dt_out , 	( kerstr )->phi_in , 	( kerstr )->A1 , 	( kerstr )->Y1 , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->num_ele_A1)[0] , (	( kerstr )->M)[0] , (	( kerstr )->Q)[0] , (	( kerstr )->DM_A)[0] , (	( kerstr )->DX)[0] , (	( kerstr )->DY)[0] , (	( kerstr )->DZ)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_dm_calc_hamt_scmc_set_parameter_dphi_dt_out (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->dphi_dt_out = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_phi_in (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->phi_in = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_A1 (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->A1 = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_Y1 (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Y1 = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_y_cpu_core (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_numvec (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_XLEN (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_YLEN (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_ZLEN (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_ovlp (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_xblock (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_yblock (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_zblock (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_num_ele (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_num_ele_A1 (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_A1 = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_M (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->M = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_Q (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Q = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_DM_A (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DM_A = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_DX (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DX = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_DY (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DY = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_DZ (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DZ = pm->d_data);
}
int  c_dm_calc_hamt_scmc_set_parameter_DT (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_dm_cayley_eqn_J_init (c_pscmc_env *  pe ,c_dm_cayley_eqn_J_struct *  kerstr ){
	return  0 ;}
void  c_dm_cayley_eqn_J_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_dm_cayley_eqn_J_struct ));
}
int  c_dm_cayley_eqn_J_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_dm_cayley_eqn_J_get_num_compute_units (c_dm_cayley_eqn_J_struct *  kerstr ){
	return  1 ;}
int  c_dm_cayley_eqn_J_exec (c_dm_cayley_eqn_J_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_dm_cayley_eqn_J_scmc_kernel ( 	( kerstr )->dphi_dt_out , 	( kerstr )->phi_in , 	( kerstr )->A1 , 	( kerstr )->Y1 , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->num_ele_A1)[0] , (	( kerstr )->M)[0] , (	( kerstr )->Q)[0] , (	( kerstr )->DM_A)[0] , (	( kerstr )->DX)[0] , (	( kerstr )->DY)[0] , (	( kerstr )->DZ)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_dm_cayley_eqn_J_scmc_set_parameter_dphi_dt_out (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->dphi_dt_out = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_phi_in (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->phi_in = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_A1 (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->A1 = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_Y1 (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Y1 = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_y_cpu_core (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_numvec (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_XLEN (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_YLEN (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_ZLEN (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_ovlp (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_xblock (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_yblock (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_zblock (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_num_ele (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_num_ele_A1 (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_A1 = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_M (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->M = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_Q (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Q = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_DM_A (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DM_A = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_DX (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DX = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_DY (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DY = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_DZ (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DZ = pm->d_data);
}
int  c_dm_cayley_eqn_J_scmc_set_parameter_DT (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_init (c_pscmc_env *  pe ,c_dm_bihamt_eqn_dydt_struct *  kerstr ){
	return  0 ;}
void  c_dm_bihamt_eqn_dydt_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_dm_bihamt_eqn_dydt_struct ));
}
int  c_dm_bihamt_eqn_dydt_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_dm_bihamt_eqn_dydt_get_num_compute_units (c_dm_bihamt_eqn_dydt_struct *  kerstr ){
	return  1 ;}
int  c_dm_bihamt_eqn_dydt_exec (c_dm_bihamt_eqn_dydt_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_dm_bihamt_eqn_dydt_scmc_kernel ( 	( kerstr )->dphi_dt_out , 	( kerstr )->phi_in , 	( kerstr )->A1 , 	( kerstr )->Y1 , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->num_ele_A1)[0] , (	( kerstr )->M)[0] , (	( kerstr )->Q)[0] , (	( kerstr )->DM_A)[0] , (	( kerstr )->DX)[0] , (	( kerstr )->DY)[0] , (	( kerstr )->DZ)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_dphi_dt_out (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->dphi_dt_out = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_phi_in (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->phi_in = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_A1 (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->A1 = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_Y1 (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Y1 = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_y_cpu_core (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_numvec (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_XLEN (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_YLEN (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_ZLEN (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_ovlp (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_xblock (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_yblock (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_zblock (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_num_ele (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_num_ele_A1 (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_A1 = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_M (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->M = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_Q (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Q = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_DM_A (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DM_A = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_DX (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DX = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_DY (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DY = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_DZ (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DZ = pm->d_data);
}
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_DT (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_init (c_pscmc_env *  pe ,c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ){
	return  0 ;}
void  c_dm_bihamt_dual_psi_eqn_J_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_dm_bihamt_dual_psi_eqn_J_struct ));
}
int  c_dm_bihamt_dual_psi_eqn_J_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_dm_bihamt_dual_psi_eqn_J_get_num_compute_units (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ){
	return  1 ;}
int  c_dm_bihamt_dual_psi_eqn_J_exec (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_dm_bihamt_dual_psi_eqn_J_scmc_kernel ( 	( kerstr )->dphi_dt_out , 	( kerstr )->phi_in , 	( kerstr )->A1 , 	( kerstr )->Y1 , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->num_ele_A1)[0] , (	( kerstr )->M)[0] , (	( kerstr )->Q)[0] , (	( kerstr )->DM_A)[0] , (	( kerstr )->DX)[0] , (	( kerstr )->DY)[0] , (	( kerstr )->DZ)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_dphi_dt_out (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->dphi_dt_out = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_phi_in (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->phi_in = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_A1 (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->A1 = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_Y1 (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Y1 = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_y_cpu_core (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_numvec (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_XLEN (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_YLEN (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_ZLEN (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_ovlp (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_xblock (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_yblock (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_zblock (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_num_ele (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_num_ele_A1 (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele_A1 = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_M (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->M = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_Q (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Q = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_DM_A (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DM_A = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_DX (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DX = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_DY (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DY = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_DZ (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DZ = pm->d_data);
}
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_DT (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
