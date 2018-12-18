#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "c_pscmc_inc.h"
#include "yeefdtd.kernel_inc.h"
int  c_kgm_eqn_core_init (c_pscmc_env *  pe ,c_kgm_eqn_core_struct *  kerstr ){
	return  0 ;}
void  c_kgm_eqn_core_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_kgm_eqn_core_struct ));
}
int  c_kgm_eqn_core_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_kgm_eqn_core_get_num_compute_units (c_kgm_eqn_core_struct *  kerstr ){
	return  1 ;}
int  c_kgm_eqn_core_exec (c_kgm_eqn_core_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_kgm_eqn_core_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->xoffset , 	( kerstr )->yoffset , 	( kerstr )->zoffset , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , (	( kerstr )->M)[0] , (	( kerstr )->Q)[0] , (	( kerstr )->DX)[0] , (	( kerstr )->GEXT)[0] , (	( kerstr )->rfz0)[0] , (	( kerstr )->swap_input)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_kgm_eqn_core_scmc_set_parameter_outEB (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_inEB (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_xoffset (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xoffset = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_yoffset (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yoffset = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_zoffset (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zoffset = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_y_cpu_core (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_numvec (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_XLEN (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_YLEN (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_ZLEN (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_ovlp (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_xblock (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_yblock (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_zblock (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_num_ele (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_DT (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_M (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->M = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_Q (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Q = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_DX (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DX = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_GEXT (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->GEXT = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_rfz0 (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->rfz0 = pm->d_data);
}
int  c_kgm_eqn_core_scmc_set_parameter_swap_input (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->swap_input = pm->d_data);
}
int  c_kgm_calc_rho_init (c_pscmc_env *  pe ,c_kgm_calc_rho_struct *  kerstr ){
	return  0 ;}
void  c_kgm_calc_rho_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_kgm_calc_rho_struct ));
}
int  c_kgm_calc_rho_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_kgm_calc_rho_get_num_compute_units (c_kgm_calc_rho_struct *  kerstr ){
	return  1 ;}
int  c_kgm_calc_rho_exec (c_kgm_calc_rho_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_kgm_calc_rho_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->xoffset , 	( kerstr )->yoffset , 	( kerstr )->zoffset , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , (	( kerstr )->M)[0] , (	( kerstr )->Q)[0] , (	( kerstr )->DX)[0] , (	( kerstr )->refz0)[0] , (	( kerstr )->q)[0] , (	( kerstr )->dtodx)[0] , (	( kerstr )->mode)[0] , (	( kerstr )->swap_input)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_kgm_calc_rho_scmc_set_parameter_outEB (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_inEB (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_xoffset (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xoffset = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_yoffset (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yoffset = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_zoffset (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zoffset = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_y_cpu_core (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_numvec (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_XLEN (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_YLEN (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_ZLEN (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_ovlp (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_xblock (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_yblock (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_zblock (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_num_ele (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_DT (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_M (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->M = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_Q (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Q = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_DX (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DX = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_refz0 (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->refz0 = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_q (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->q = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_dtodx (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->dtodx = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_mode (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->mode = pm->d_data);
}
int  c_kgm_calc_rho_scmc_set_parameter_swap_input (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->swap_input = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_init (c_pscmc_env *  pe ,c_PML_FDTD_CURL_BWD_struct *  kerstr ){
	return  0 ;}
void  c_PML_FDTD_CURL_BWD_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_PML_FDTD_CURL_BWD_struct ));
}
int  c_PML_FDTD_CURL_BWD_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_PML_FDTD_CURL_BWD_get_num_compute_units (c_PML_FDTD_CURL_BWD_struct *  kerstr ){
	return  1 ;}
int  c_PML_FDTD_CURL_BWD_exec (c_PML_FDTD_CURL_BWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_PML_FDTD_CURL_BWD_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->outPMLEB , 	( kerstr )->inPMLEB , 	( kerstr )->xoffset , 	( kerstr )->yoffset , 	( kerstr )->zoffset , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , (	( kerstr )->M)[0] , (	( kerstr )->Q)[0] , (	( kerstr )->DX)[0] , (	( kerstr )->DY)[0] , (	( kerstr )->DZ)[0] , (	( kerstr )->abc_dir)[0] , (	( kerstr )->level)[0] , (	( kerstr )->pml_m)[0] , (	( kerstr )->max_sigma)[0] , (	( kerstr )->allxmax)[0] , (	( kerstr )->allymax)[0] , (	( kerstr )->allzmax)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_outEB (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_inEB (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_outPMLEB (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outPMLEB = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_inPMLEB (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inPMLEB = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_xoffset (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xoffset = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_yoffset (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yoffset = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_zoffset (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zoffset = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_y_cpu_core (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_numvec (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_XLEN (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_YLEN (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_ZLEN (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_ovlp (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_xblock (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_yblock (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_zblock (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_num_ele (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_DT (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_M (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->M = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_Q (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Q = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_DX (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DX = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_DY (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DY = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_DZ (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DZ = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_abc_dir (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->abc_dir = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_level (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->level = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_pml_m (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->pml_m = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_max_sigma (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->max_sigma = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_allxmax (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->allxmax = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_allymax (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->allymax = pm->d_data);
}
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_allzmax (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->allzmax = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_init (c_pscmc_env *  pe ,c_PML_FDTD_CURL_FWD_struct *  kerstr ){
	return  0 ;}
void  c_PML_FDTD_CURL_FWD_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_PML_FDTD_CURL_FWD_struct ));
}
int  c_PML_FDTD_CURL_FWD_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_PML_FDTD_CURL_FWD_get_num_compute_units (c_PML_FDTD_CURL_FWD_struct *  kerstr ){
	return  1 ;}
int  c_PML_FDTD_CURL_FWD_exec (c_PML_FDTD_CURL_FWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_PML_FDTD_CURL_FWD_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , 	( kerstr )->outPMLEB , 	( kerstr )->inPMLEB , 	( kerstr )->xoffset , 	( kerstr )->yoffset , 	( kerstr )->zoffset , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , (	( kerstr )->M)[0] , (	( kerstr )->Q)[0] , (	( kerstr )->DX)[0] , (	( kerstr )->DY)[0] , (	( kerstr )->DZ)[0] , (	( kerstr )->abc_dir)[0] , (	( kerstr )->level)[0] , (	( kerstr )->pml_m)[0] , (	( kerstr )->max_sigma)[0] , (	( kerstr )->allxmax)[0] , (	( kerstr )->allymax)[0] , (	( kerstr )->allzmax)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_outEB (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_inEB (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_outPMLEB (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outPMLEB = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_inPMLEB (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inPMLEB = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_xoffset (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xoffset = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_yoffset (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yoffset = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_zoffset (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zoffset = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_y_cpu_core (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_numvec (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_XLEN (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_YLEN (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_ZLEN (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_ovlp (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_xblock (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_yblock (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_zblock (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_num_ele (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_DT (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_M (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->M = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_Q (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->Q = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_DX (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DX = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_DY (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DY = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_DZ (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DZ = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_abc_dir (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->abc_dir = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_level (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->level = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_pml_m (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->pml_m = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_max_sigma (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->max_sigma = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_allxmax (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->allxmax = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_allymax (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->allymax = pm->d_data);
}
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_allzmax (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->allzmax = pm->d_data);
}
int  c_merge_current_init (c_pscmc_env *  pe ,c_merge_current_struct *  kerstr ){
	return  0 ;}
void  c_merge_current_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_merge_current_struct ));
}
int  c_merge_current_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_merge_current_get_num_compute_units (c_merge_current_struct *  kerstr ){
	return  1 ;}
int  c_merge_current_exec (c_merge_current_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_merge_current_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_merge_current_scmc_set_parameter_outEB (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_merge_current_scmc_set_parameter_inEB (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_merge_current_scmc_set_parameter_y_cpu_core (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_merge_current_scmc_set_parameter_numvec (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_merge_current_scmc_set_parameter_XLEN (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_merge_current_scmc_set_parameter_YLEN (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_merge_current_scmc_set_parameter_ZLEN (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_merge_current_scmc_set_parameter_ovlp (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_merge_current_scmc_set_parameter_xblock (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_merge_current_scmc_set_parameter_yblock (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_merge_current_scmc_set_parameter_zblock (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_merge_current_scmc_set_parameter_num_ele (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_merge_current_2_init (c_pscmc_env *  pe ,c_merge_current_2_struct *  kerstr ){
	return  0 ;}
void  c_merge_current_2_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_merge_current_2_struct ));
}
int  c_merge_current_2_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_merge_current_2_get_num_compute_units (c_merge_current_2_struct *  kerstr ){
	return  1 ;}
int  c_merge_current_2_exec (c_merge_current_2_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_merge_current_2_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_merge_current_2_scmc_set_parameter_outEB (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_merge_current_2_scmc_set_parameter_inEB (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_merge_current_2_scmc_set_parameter_y_cpu_core (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_merge_current_2_scmc_set_parameter_numvec (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_merge_current_2_scmc_set_parameter_XLEN (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_merge_current_2_scmc_set_parameter_YLEN (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_merge_current_2_scmc_set_parameter_ZLEN (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_merge_current_2_scmc_set_parameter_ovlp (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_merge_current_2_scmc_set_parameter_xblock (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_merge_current_2_scmc_set_parameter_yblock (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_merge_current_2_scmc_set_parameter_zblock (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_merge_current_2_scmc_set_parameter_num_ele (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_4th_init (c_pscmc_env *  pe ,c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ){
	return  0 ;}
void  c_Yee_FDTD_Div_FWD_4th_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_Yee_FDTD_Div_FWD_4th_struct ));
}
int  c_Yee_FDTD_Div_FWD_4th_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_Yee_FDTD_Div_FWD_4th_get_num_compute_units (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ){
	return  1 ;}
int  c_Yee_FDTD_Div_FWD_4th_exec (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_Yee_FDTD_Div_FWD_4th_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_outEB (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_inEB (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_numvec (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_XLEN (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_YLEN (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_ZLEN (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_ovlp (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_xblock (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_yblock (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_zblock (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_num_ele (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_DT (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_init (c_pscmc_env *  pe ,c_Yee_FDTD_Div_FWD_struct *  kerstr ){
	return  0 ;}
void  c_Yee_FDTD_Div_FWD_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_Yee_FDTD_Div_FWD_struct ));
}
int  c_Yee_FDTD_Div_FWD_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_Yee_FDTD_Div_FWD_get_num_compute_units (c_Yee_FDTD_Div_FWD_struct *  kerstr ){
	return  1 ;}
int  c_Yee_FDTD_Div_FWD_exec (c_Yee_FDTD_Div_FWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_Yee_FDTD_Div_FWD_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_outEB (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_inEB (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_numvec (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_XLEN (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_YLEN (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_ZLEN (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_ovlp (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_xblock (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_yblock (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_zblock (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_num_ele (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_DT (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_4th_init (c_pscmc_env *  pe ,c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ){
	return  0 ;}
void  c_Yee_FDTD_Div_BWD_4th_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_Yee_FDTD_Div_BWD_4th_struct ));
}
int  c_Yee_FDTD_Div_BWD_4th_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_Yee_FDTD_Div_BWD_4th_get_num_compute_units (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ){
	return  1 ;}
int  c_Yee_FDTD_Div_BWD_4th_exec (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_Yee_FDTD_Div_BWD_4th_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_outEB (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_inEB (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_numvec (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_XLEN (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_YLEN (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_ZLEN (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_ovlp (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_xblock (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_yblock (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_zblock (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_num_ele (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_DT (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_init (c_pscmc_env *  pe ,c_Yee_FDTD_Div_BWD_struct *  kerstr ){
	return  0 ;}
void  c_Yee_FDTD_Div_BWD_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_Yee_FDTD_Div_BWD_struct ));
}
int  c_Yee_FDTD_Div_BWD_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_Yee_FDTD_Div_BWD_get_num_compute_units (c_Yee_FDTD_Div_BWD_struct *  kerstr ){
	return  1 ;}
int  c_Yee_FDTD_Div_BWD_exec (c_Yee_FDTD_Div_BWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_Yee_FDTD_Div_BWD_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_outEB (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_inEB (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_numvec (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_XLEN (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_YLEN (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_ZLEN (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_ovlp (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_xblock (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_yblock (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_zblock (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_num_ele (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_DT (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_4th_init (c_pscmc_env *  pe ,c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ){
	return  0 ;}
void  c_Yee_FDTD_Curl_FWD_4th_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_Yee_FDTD_Curl_FWD_4th_struct ));
}
int  c_Yee_FDTD_Curl_FWD_4th_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_Yee_FDTD_Curl_FWD_4th_get_num_compute_units (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ){
	return  1 ;}
int  c_Yee_FDTD_Curl_FWD_4th_exec (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_Yee_FDTD_Curl_FWD_4th_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_outEB (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_inEB (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_numvec (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_XLEN (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_YLEN (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_ZLEN (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_ovlp (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_xblock (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_yblock (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_zblock (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_num_ele (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_DT (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_init (c_pscmc_env *  pe ,c_Yee_FDTD_Curl_FWD_struct *  kerstr ){
	return  0 ;}
void  c_Yee_FDTD_Curl_FWD_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_Yee_FDTD_Curl_FWD_struct ));
}
int  c_Yee_FDTD_Curl_FWD_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_Yee_FDTD_Curl_FWD_get_num_compute_units (c_Yee_FDTD_Curl_FWD_struct *  kerstr ){
	return  1 ;}
int  c_Yee_FDTD_Curl_FWD_exec (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_Yee_FDTD_Curl_FWD_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_outEB (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_inEB (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_numvec (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_XLEN (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_YLEN (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_ZLEN (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_ovlp (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_xblock (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_yblock (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_zblock (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_num_ele (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_DT (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_4th_init (c_pscmc_env *  pe ,c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ){
	return  0 ;}
void  c_Yee_FDTD_Curl_BWD_4th_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_Yee_FDTD_Curl_BWD_4th_struct ));
}
int  c_Yee_FDTD_Curl_BWD_4th_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_Yee_FDTD_Curl_BWD_4th_get_num_compute_units (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ){
	return  1 ;}
int  c_Yee_FDTD_Curl_BWD_4th_exec (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_Yee_FDTD_Curl_BWD_4th_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_outEB (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_inEB (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_numvec (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_XLEN (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_YLEN (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_ZLEN (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_ovlp (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_xblock (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_yblock (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_zblock (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_num_ele (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_DT (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_init (c_pscmc_env *  pe ,c_Yee_FDTD_Curl_BWD_struct *  kerstr ){
	return  0 ;}
void  c_Yee_FDTD_Curl_BWD_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_Yee_FDTD_Curl_BWD_struct ));
}
int  c_Yee_FDTD_Curl_BWD_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_Yee_FDTD_Curl_BWD_get_num_compute_units (c_Yee_FDTD_Curl_BWD_struct *  kerstr ){
	return  1 ;}
int  c_Yee_FDTD_Curl_BWD_exec (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_Yee_FDTD_Curl_BWD_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_outEB (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_inEB (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_numvec (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_XLEN (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_YLEN (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_ZLEN (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_ovlp (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_xblock (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_yblock (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_zblock (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_num_ele (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_DT (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_4th_init (c_pscmc_env *  pe ,c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ){
	return  0 ;}
void  c_Yee_FDTD_Grad_FWD_4th_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_Yee_FDTD_Grad_FWD_4th_struct ));
}
int  c_Yee_FDTD_Grad_FWD_4th_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_Yee_FDTD_Grad_FWD_4th_get_num_compute_units (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ){
	return  1 ;}
int  c_Yee_FDTD_Grad_FWD_4th_exec (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_Yee_FDTD_Grad_FWD_4th_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_outEB (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_inEB (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_numvec (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_XLEN (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_YLEN (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_ZLEN (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_ovlp (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_xblock (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_yblock (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_zblock (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_num_ele (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_DT (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_init (c_pscmc_env *  pe ,c_Yee_FDTD_Grad_FWD_struct *  kerstr ){
	return  0 ;}
void  c_Yee_FDTD_Grad_FWD_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_Yee_FDTD_Grad_FWD_struct ));
}
int  c_Yee_FDTD_Grad_FWD_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_Yee_FDTD_Grad_FWD_get_num_compute_units (c_Yee_FDTD_Grad_FWD_struct *  kerstr ){
	return  1 ;}
int  c_Yee_FDTD_Grad_FWD_exec (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_Yee_FDTD_Grad_FWD_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_outEB (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_inEB (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_numvec (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_XLEN (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_YLEN (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_ZLEN (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_ovlp (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_xblock (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_yblock (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_zblock (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_num_ele (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_DT (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_4th_init (c_pscmc_env *  pe ,c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ){
	return  0 ;}
void  c_Yee_FDTD_Grad_BWD_4th_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_Yee_FDTD_Grad_BWD_4th_struct ));
}
int  c_Yee_FDTD_Grad_BWD_4th_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_Yee_FDTD_Grad_BWD_4th_get_num_compute_units (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ){
	return  1 ;}
int  c_Yee_FDTD_Grad_BWD_4th_exec (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_Yee_FDTD_Grad_BWD_4th_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_outEB (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_inEB (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_numvec (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_XLEN (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_YLEN (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_ZLEN (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_ovlp (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_xblock (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_yblock (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_zblock (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_num_ele (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_DT (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_init (c_pscmc_env *  pe ,c_Yee_FDTD_Grad_BWD_struct *  kerstr ){
	return  0 ;}
void  c_Yee_FDTD_Grad_BWD_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_Yee_FDTD_Grad_BWD_struct ));
}
int  c_Yee_FDTD_Grad_BWD_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_Yee_FDTD_Grad_BWD_get_num_compute_units (c_Yee_FDTD_Grad_BWD_struct *  kerstr ){
	return  1 ;}
int  c_Yee_FDTD_Grad_BWD_exec (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_Yee_FDTD_Grad_BWD_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_outEB (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_inEB (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_numvec (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_XLEN (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_YLEN (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_ZLEN (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_ovlp (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_xblock (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_yblock (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_zblock (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_num_ele (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_DT (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_4th_init (c_pscmc_env *  pe ,c_Yee_FDTD_Curl_B_4th_struct *  kerstr ){
	return  0 ;}
void  c_Yee_FDTD_Curl_B_4th_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_Yee_FDTD_Curl_B_4th_struct ));
}
int  c_Yee_FDTD_Curl_B_4th_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_Yee_FDTD_Curl_B_4th_get_num_compute_units (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ){
	return  1 ;}
int  c_Yee_FDTD_Curl_B_4th_exec (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_Yee_FDTD_Curl_B_4th_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_outEB (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_inEB (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_numvec (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_XLEN (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_YLEN (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_ZLEN (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_ovlp (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_xblock (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_yblock (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_zblock (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_num_ele (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_DT (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_init (c_pscmc_env *  pe ,c_Yee_FDTD_Curl_B_struct *  kerstr ){
	return  0 ;}
void  c_Yee_FDTD_Curl_B_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_Yee_FDTD_Curl_B_struct ));
}
int  c_Yee_FDTD_Curl_B_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_Yee_FDTD_Curl_B_get_num_compute_units (c_Yee_FDTD_Curl_B_struct *  kerstr ){
	return  1 ;}
int  c_Yee_FDTD_Curl_B_exec (c_Yee_FDTD_Curl_B_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_Yee_FDTD_Curl_B_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_outEB (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_inEB (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_numvec (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_XLEN (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_YLEN (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_ZLEN (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_ovlp (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_xblock (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_yblock (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_zblock (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_num_ele (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_DT (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_4th_init (c_pscmc_env *  pe ,c_Yee_FDTD_Curl_E_4th_struct *  kerstr ){
	return  0 ;}
void  c_Yee_FDTD_Curl_E_4th_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_Yee_FDTD_Curl_E_4th_struct ));
}
int  c_Yee_FDTD_Curl_E_4th_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_Yee_FDTD_Curl_E_4th_get_num_compute_units (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ){
	return  1 ;}
int  c_Yee_FDTD_Curl_E_4th_exec (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_Yee_FDTD_Curl_E_4th_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_outEB (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_inEB (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_numvec (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_XLEN (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_YLEN (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_ZLEN (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_ovlp (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_xblock (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_yblock (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_zblock (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_num_ele (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_DT (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_init (c_pscmc_env *  pe ,c_Yee_FDTD_Curl_E_struct *  kerstr ){
	return  0 ;}
void  c_Yee_FDTD_Curl_E_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_Yee_FDTD_Curl_E_struct ));
}
int  c_Yee_FDTD_Curl_E_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_Yee_FDTD_Curl_E_get_num_compute_units (c_Yee_FDTD_Curl_E_struct *  kerstr ){
	return  1 ;}
int  c_Yee_FDTD_Curl_E_exec (c_Yee_FDTD_Curl_E_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_Yee_FDTD_Curl_E_scmc_kernel ( 	( kerstr )->outEB , 	( kerstr )->inEB , (	( kerstr )->y_cpu_core)[0] , (	( kerstr )->numvec)[0] , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->ovlp)[0] , (	( kerstr )->xblock)[0] , (	( kerstr )->yblock)[0] , (	( kerstr )->zblock)[0] , (	( kerstr )->num_ele)[0] , (	( kerstr )->DT)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_outEB (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->outEB = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_inEB (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inEB = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_numvec (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->numvec = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_XLEN (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_YLEN (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_ZLEN (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_ovlp (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ovlp = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_xblock (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_yblock (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->yblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_zblock (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->zblock = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_num_ele (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->num_ele = pm->d_data);
}
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_DT (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->DT = pm->d_data);
}
