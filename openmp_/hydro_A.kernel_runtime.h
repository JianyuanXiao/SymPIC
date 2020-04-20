
#include "local_header.h"
int  openmp_hydro_push_vA_init (openmp_pscmc_env *  pe ,openmp_hydro_push_vA_struct *  kerstr )
;
void  openmp_hydro_push_vA_get_struct_len (size_t *  len )
;
int  openmp_hydro_push_vA_get_num_compute_units (openmp_hydro_push_vA_struct *  kerstr )
;
int  openmp_hydro_push_vA_get_xlen ()
;
int  openmp_hydro_push_vA_exec (openmp_hydro_push_vA_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_hydro_push_vA_scmc_set_parameter_out_vA (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_alpha_beta_new (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_alpha_beta (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_rho_s_vx (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_vA (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_vAzero (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_y_cpu_core (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_numvec (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_XLEN (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_YLEN (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_ZLEN (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_ovlp (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_xblock (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_yblock (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_zblock (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_num_ele (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_num_ele_rho_s_vx (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_num_ele_vA (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_num_ele_alpha_beta (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_QM0 (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_U0 (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_DX (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_DY (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_DZ (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vA_scmc_set_parameter_DT (openmp_hydro_push_vA_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_init (openmp_pscmc_env *  pe ,openmp_hydro_push_jac_alpha_beta_struct *  kerstr )
;
void  openmp_hydro_push_jac_alpha_beta_get_struct_len (size_t *  len )
;
int  openmp_hydro_push_jac_alpha_beta_get_num_compute_units (openmp_hydro_push_jac_alpha_beta_struct *  kerstr )
;
int  openmp_hydro_push_jac_alpha_beta_get_xlen ()
;
int  openmp_hydro_push_jac_alpha_beta_exec (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_out_alpha_beta (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_alpha_beta_new (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_alpha_beta (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_rho_s_vx (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_vA (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_vAzero (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_y_cpu_core (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_numvec (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_XLEN (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_YLEN (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_ZLEN (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_ovlp (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_xblock (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_yblock (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_zblock (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_num_ele (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_num_ele_rho_s_vx (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_num_ele_vA (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_num_ele_alpha_beta (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_QM0 (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_U0 (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_DX (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_DY (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_DZ (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_jac_alpha_beta_scmc_set_parameter_DT (openmp_hydro_push_jac_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_init (openmp_pscmc_env *  pe ,openmp_hydro_push_alpha_beta_struct *  kerstr )
;
void  openmp_hydro_push_alpha_beta_get_struct_len (size_t *  len )
;
int  openmp_hydro_push_alpha_beta_get_num_compute_units (openmp_hydro_push_alpha_beta_struct *  kerstr )
;
int  openmp_hydro_push_alpha_beta_get_xlen ()
;
int  openmp_hydro_push_alpha_beta_exec (openmp_hydro_push_alpha_beta_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_out_alpha_beta (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_alpha_beta_new (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_alpha_beta (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_rho_s_vx (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_vA (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_vAzero (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_y_cpu_core (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_numvec (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_XLEN (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_YLEN (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_ZLEN (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_ovlp (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_xblock (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_yblock (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_zblock (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_num_ele (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_num_ele_rho_s_vx (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_num_ele_vA (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_num_ele_alpha_beta (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_QM0 (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_U0 (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_DX (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_DY (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_DZ (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_alpha_beta_scmc_set_parameter_DT (openmp_hydro_push_alpha_beta_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_init (openmp_pscmc_env *  pe ,openmp_hydro_push_vx_struct *  kerstr )
;
void  openmp_hydro_push_vx_get_struct_len (size_t *  len )
;
int  openmp_hydro_push_vx_get_num_compute_units (openmp_hydro_push_vx_struct *  kerstr )
;
int  openmp_hydro_push_vx_get_xlen ()
;
int  openmp_hydro_push_vx_exec (openmp_hydro_push_vx_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_hydro_push_vx_scmc_set_parameter_out_rho_s_vx (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_alpha_beta_new (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_alpha_beta (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_rho_s_vx (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_vA (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_vAzero (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_y_cpu_core (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_numvec (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_XLEN (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_YLEN (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_ZLEN (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_ovlp (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_xblock (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_yblock (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_zblock (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_num_ele (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_num_ele_rho_s_vx (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_num_ele_vA (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_num_ele_alpha_beta (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_QM0 (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_U0 (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_DX (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_DY (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_DZ (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_vx_scmc_set_parameter_DT (openmp_hydro_push_vx_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_init (openmp_pscmc_env *  pe ,openmp_hydro_push_rho_s_struct *  kerstr )
;
void  openmp_hydro_push_rho_s_get_struct_len (size_t *  len )
;
int  openmp_hydro_push_rho_s_get_num_compute_units (openmp_hydro_push_rho_s_struct *  kerstr )
;
int  openmp_hydro_push_rho_s_get_xlen ()
;
int  openmp_hydro_push_rho_s_exec (openmp_hydro_push_rho_s_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_out_rho_s_vx (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_alpha_beta_new (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_alpha_beta (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_rho_s_vx (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_vA (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_vAzero (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_y_cpu_core (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_numvec (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_XLEN (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_YLEN (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_ZLEN (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_ovlp (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_xblock (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_yblock (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_zblock (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_num_ele (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_num_ele_rho_s_vx (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_num_ele_vA (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_num_ele_alpha_beta (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_QM0 (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_U0 (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_DX (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_DY (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_DZ (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_hydro_push_rho_s_scmc_set_parameter_DT (openmp_hydro_push_rho_s_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
