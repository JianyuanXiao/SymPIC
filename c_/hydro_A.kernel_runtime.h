
#include "local_header.h"
int  c_hydro_push_vA_init (c_pscmc_env *  pe ,c_hydro_push_vA_struct *  kerstr )
;
void  c_hydro_push_vA_get_struct_len (size_t *  len )
;
int  c_hydro_push_vA_get_xlen ()
;
int  c_hydro_push_vA_get_num_compute_units (c_hydro_push_vA_struct *  kerstr )
;
int  c_hydro_push_vA_exec (c_hydro_push_vA_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_hydro_push_vA_scmc_set_parameter_out_vA (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_alpha_beta_new (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_alpha_beta (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_rho_s_vx (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_vA (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_vAzero (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_y_cpu_core (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_numvec (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_XLEN (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_YLEN (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_ZLEN (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_ovlp (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_xblock (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_yblock (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_zblock (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_num_ele (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_num_ele_rho_s_vx (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_num_ele_vA (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_num_ele_alpha_beta (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_QM0 (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_U0 (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_DX (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_DY (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_DZ (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vA_scmc_set_parameter_DT (c_hydro_push_vA_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_init (c_pscmc_env *  pe ,c_hydro_push_jac_alpha_beta_struct *  kerstr )
;
void  c_hydro_push_jac_alpha_beta_get_struct_len (size_t *  len )
;
int  c_hydro_push_jac_alpha_beta_get_xlen ()
;
int  c_hydro_push_jac_alpha_beta_get_num_compute_units (c_hydro_push_jac_alpha_beta_struct *  kerstr )
;
int  c_hydro_push_jac_alpha_beta_exec (c_hydro_push_jac_alpha_beta_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_out_alpha_beta (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_alpha_beta_new (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_alpha_beta (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_rho_s_vx (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_vA (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_vAzero (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_y_cpu_core (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_numvec (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_XLEN (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_YLEN (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_ZLEN (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_ovlp (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_xblock (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_yblock (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_zblock (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_num_ele (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_num_ele_rho_s_vx (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_num_ele_vA (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_num_ele_alpha_beta (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_QM0 (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_U0 (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_DX (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_DY (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_DZ (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_jac_alpha_beta_scmc_set_parameter_DT (c_hydro_push_jac_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_init (c_pscmc_env *  pe ,c_hydro_push_alpha_beta_struct *  kerstr )
;
void  c_hydro_push_alpha_beta_get_struct_len (size_t *  len )
;
int  c_hydro_push_alpha_beta_get_xlen ()
;
int  c_hydro_push_alpha_beta_get_num_compute_units (c_hydro_push_alpha_beta_struct *  kerstr )
;
int  c_hydro_push_alpha_beta_exec (c_hydro_push_alpha_beta_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_out_alpha_beta (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_alpha_beta_new (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_alpha_beta (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_rho_s_vx (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_vA (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_vAzero (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_y_cpu_core (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_numvec (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_XLEN (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_YLEN (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_ZLEN (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_ovlp (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_xblock (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_yblock (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_zblock (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_num_ele (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_num_ele_rho_s_vx (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_num_ele_vA (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_num_ele_alpha_beta (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_QM0 (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_U0 (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_DX (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_DY (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_DZ (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_alpha_beta_scmc_set_parameter_DT (c_hydro_push_alpha_beta_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_init (c_pscmc_env *  pe ,c_hydro_push_vx_struct *  kerstr )
;
void  c_hydro_push_vx_get_struct_len (size_t *  len )
;
int  c_hydro_push_vx_get_xlen ()
;
int  c_hydro_push_vx_get_num_compute_units (c_hydro_push_vx_struct *  kerstr )
;
int  c_hydro_push_vx_exec (c_hydro_push_vx_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_hydro_push_vx_scmc_set_parameter_out_rho_s_vx (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_alpha_beta_new (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_alpha_beta (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_rho_s_vx (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_vA (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_vAzero (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_y_cpu_core (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_numvec (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_XLEN (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_YLEN (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_ZLEN (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_ovlp (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_xblock (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_yblock (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_zblock (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_num_ele (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_num_ele_rho_s_vx (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_num_ele_vA (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_num_ele_alpha_beta (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_QM0 (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_U0 (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_DX (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_DY (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_DZ (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_vx_scmc_set_parameter_DT (c_hydro_push_vx_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_init (c_pscmc_env *  pe ,c_hydro_push_rho_s_struct *  kerstr )
;
void  c_hydro_push_rho_s_get_struct_len (size_t *  len )
;
int  c_hydro_push_rho_s_get_xlen ()
;
int  c_hydro_push_rho_s_get_num_compute_units (c_hydro_push_rho_s_struct *  kerstr )
;
int  c_hydro_push_rho_s_exec (c_hydro_push_rho_s_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_hydro_push_rho_s_scmc_set_parameter_out_rho_s_vx (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_alpha_beta_new (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_alpha_beta (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_rho_s_vx (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_vA (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_vAzero (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_y_cpu_core (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_numvec (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_XLEN (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_YLEN (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_ZLEN (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_ovlp (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_xblock (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_yblock (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_zblock (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_num_ele (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_num_ele_rho_s_vx (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_num_ele_vA (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_num_ele_alpha_beta (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_QM0 (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_U0 (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_DX (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_DY (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_DZ (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_hydro_push_rho_s_scmc_set_parameter_DT (c_hydro_push_rho_s_struct *  kerstr ,c_pscmc_mem *  pm )
;
