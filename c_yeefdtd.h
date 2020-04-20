void  c_hydro_push_rho_s_scmc_kernel (double *  out_rho_s_vx ,double *  alpha_beta_new ,double *  alpha_beta ,double *  rho_s_vx ,double *  vA ,double *  vAzero ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_rho_s_vx ,int  num_ele_vA ,int  num_ele_alpha_beta ,double  QM0 ,double  U0 ,double  DX ,double  DY ,double  DZ ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_hydro_push_vx_scmc_kernel (double *  out_rho_s_vx ,double *  alpha_beta_new ,double *  alpha_beta ,double *  rho_s_vx ,double *  vA ,double *  vAzero ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_rho_s_vx ,int  num_ele_vA ,int  num_ele_alpha_beta ,double  QM0 ,double  U0 ,double  DX ,double  DY ,double  DZ ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_hydro_push_alpha_beta_scmc_kernel (double *  out_alpha_beta ,double *  alpha_beta_new ,double *  alpha_beta ,double *  rho_s_vx ,double *  vA ,double *  vAzero ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_rho_s_vx ,int  num_ele_vA ,int  num_ele_alpha_beta ,double  QM0 ,double  U0 ,double  DX ,double  DY ,double  DZ ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_hydro_push_jac_alpha_beta_scmc_kernel (double *  out_alpha_beta ,double *  alpha_beta_new ,double *  alpha_beta ,double *  rho_s_vx ,double *  vA ,double *  vAzero ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_rho_s_vx ,int  num_ele_vA ,int  num_ele_alpha_beta ,double  QM0 ,double  U0 ,double  DX ,double  DY ,double  DZ ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_hydro_push_vA_scmc_kernel (double *  out_vA ,double *  alpha_beta_new ,double *  alpha_beta ,double *  rho_s_vx ,double *  vA ,double *  vAzero ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_rho_s_vx ,int  num_ele_vA ,int  num_ele_alpha_beta ,double  QM0 ,double  U0 ,double  DX ,double  DY ,double  DZ ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

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
void  c_split_pass_xyzE_particle_scmc_kernel (int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,int  N_l ,int  N_M ,int  push_J ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_xyzE_particle_push_r_scmc_kernel (int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,int  N_l ,int  N_M ,int  push_J ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  c_split_pass_xyzE_particle_push_r_init (c_pscmc_env *  pe ,c_split_pass_xyzE_particle_push_r_struct *  kerstr )
;
void  c_split_pass_xyzE_particle_push_r_get_struct_len (size_t *  len )
;
int  c_split_pass_xyzE_particle_push_r_get_xlen ()
;
int  c_split_pass_xyzE_particle_push_r_get_num_compute_units (c_split_pass_xyzE_particle_push_r_struct *  kerstr )
;
int  c_split_pass_xyzE_particle_push_r_exec (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_xyzw (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_cu_cache (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_cu_xyzw (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_fieldE (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_fieldB (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_FoutJ (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_XLEN (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_YLEN (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_ZLEN (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_ovlp (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_numvec (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_num_ele (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_grid_cache_len (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_cu_cache_length (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_Mass0 (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_Charge0 (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_Deltat (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_DELTA_X (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_DELTA_Y (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_DELTA_Z (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_N_l (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_N_M (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_push_r_scmc_set_parameter_push_J (c_split_pass_xyzE_particle_push_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_init (c_pscmc_env *  pe ,c_split_pass_xyzE_particle_struct *  kerstr )
;
void  c_split_pass_xyzE_particle_get_struct_len (size_t *  len )
;
int  c_split_pass_xyzE_particle_get_xlen ()
;
int  c_split_pass_xyzE_particle_get_num_compute_units (c_split_pass_xyzE_particle_struct *  kerstr )
;
int  c_split_pass_xyzE_particle_exec (c_split_pass_xyzE_particle_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_xyzw (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_cu_cache (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_cu_xyzw (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_fieldE (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_fieldB (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_FoutJ (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_XLEN (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_YLEN (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_ZLEN (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_ovlp (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_numvec (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_num_ele (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_grid_cache_len (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_cu_cache_length (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_Mass0 (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_Charge0 (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_Deltat (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_DELTA_X (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_DELTA_Y (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_DELTA_Z (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_N_l (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_N_M (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_xyzE_particle_scmc_set_parameter_push_J (c_split_pass_xyzE_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
double  c_get_E1_local_opt (double *  shE0 ,double *  f1_x ,double *  f0_y ,double *  f0_z ,int  dir ,int  l_dir )
;
double  c_get_B1_local_opt (double *  shB0 ,double *  if1_x ,double *  if1_xplus ,double *  f1_y ,double *  f0_z ,int  dir ,int  l_dir )
;
void  c_cal_fun_f0 (double *  outf ,double  x ,int  ix )
;
void  c_cal_fun_f1 (double *  outf ,double  x ,int  ix )
;
void  c_cal_fun_if1 (double *  outf ,double  x ,int  ix )
;
void  c_cal_fun_df0 (double *  outf ,double  x ,int  ix )
;
void  c_cal_fun_dif1 (double *  outf ,double  x ,int  ix )
;
void  c_relng_1st_goto_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  c_relng_1st_goto_init (c_pscmc_env *  pe ,c_relng_1st_goto_struct *  kerstr )
;
void  c_relng_1st_goto_get_struct_len (size_t *  len )
;
int  c_relng_1st_goto_get_xlen ()
;
int  c_relng_1st_goto_get_num_compute_units (c_relng_1st_goto_struct *  kerstr )
;
int  c_relng_1st_goto_exec (c_relng_1st_goto_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_relng_1st_goto_scmc_set_parameter_inoutput (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_xyzw (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_cu_cache (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_cu_xyzw (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_xoffset (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_yoffset (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_zoffset (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_fieldE (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_fieldB (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_fieldB1 (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_FoutJ (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_XLEN (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_YLEN (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_ZLEN (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_ovlp (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_numvec (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_num_ele (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_grid_cache_len (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_cu_cache_length (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_DELTA_X (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_DELTA_Y (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_DELTA_Z (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_Mass0 (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_Charge0 (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_Deltat (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_Tori_X0 (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_goto_scmc_set_parameter_Solve_Err (c_relng_1st_goto_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_flrx (double  x )
;
void  c_ngeo_gc_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  r0 ,double  MIN_R0 ,double  Q0 ,double  b0 ,double  zmid ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_geo_nr_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  r0 ,double  MIN_R0 ,double  Q0 ,double  b0 ,double  zmid ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_geo_nr_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  r0 ,double  MIN_R0 ,double  Q0 ,double  b0 ,double  zmid ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_geo_nr_Bfield_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  r0 ,double  MIN_R0 ,double  Q0 ,double  b0 ,double  zmid ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_geo_nr_Bfield_pushJ_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  r0 ,double  MIN_R0 ,double  Q0 ,double  b0 ,double  zmid ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_geo_nr_Bfield_pushJ_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  r0 ,double  MIN_R0 ,double  Q0 ,double  b0 ,double  zmid ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  c_geo_nr_Bfield_pushJ_vlo_init (c_pscmc_env *  pe ,c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr )
;
void  c_geo_nr_Bfield_pushJ_vlo_get_struct_len (size_t *  len )
;
int  c_geo_nr_Bfield_pushJ_vlo_get_xlen ()
;
int  c_geo_nr_Bfield_pushJ_vlo_get_num_compute_units (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr )
;
int  c_geo_nr_Bfield_pushJ_vlo_exec (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_inoutput (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_xyzw (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_cache (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_xyzw (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_xoffset (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_yoffset (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_zoffset (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldE (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldB (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldB1 (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_FoutJ (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_XLEN (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_YLEN (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_ZLEN (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_ovlp (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_numvec (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_num_ele (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_grid_cache_len (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_cache_length (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_X (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_Y (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_Z (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Mass0 (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Charge0 (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Deltat (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Tori_X0 (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_r0 (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_MIN_R0 (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Q0 (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_b0 (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_zmid (c_geo_nr_Bfield_pushJ_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_init (c_pscmc_env *  pe ,c_geo_nr_Bfield_pushJ_struct *  kerstr )
;
void  c_geo_nr_Bfield_pushJ_get_struct_len (size_t *  len )
;
int  c_geo_nr_Bfield_pushJ_get_xlen ()
;
int  c_geo_nr_Bfield_pushJ_get_num_compute_units (c_geo_nr_Bfield_pushJ_struct *  kerstr )
;
int  c_geo_nr_Bfield_pushJ_exec (c_geo_nr_Bfield_pushJ_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_inoutput (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_xyzw (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_cu_cache (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_cu_xyzw (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_xoffset (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_yoffset (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_zoffset (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_fieldE (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_fieldB (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_fieldB1 (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_FoutJ (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_XLEN (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_YLEN (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_ZLEN (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_ovlp (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_numvec (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_num_ele (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_grid_cache_len (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_cu_cache_length (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_DELTA_X (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_DELTA_Y (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_DELTA_Z (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_Mass0 (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_Charge0 (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_Deltat (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_Tori_X0 (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_r0 (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_MIN_R0 (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_Q0 (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_b0 (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_pushJ_scmc_set_parameter_zmid (c_geo_nr_Bfield_pushJ_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_init (c_pscmc_env *  pe ,c_geo_nr_Bfield_struct *  kerstr )
;
void  c_geo_nr_Bfield_get_struct_len (size_t *  len )
;
int  c_geo_nr_Bfield_get_xlen ()
;
int  c_geo_nr_Bfield_get_num_compute_units (c_geo_nr_Bfield_struct *  kerstr )
;
int  c_geo_nr_Bfield_exec (c_geo_nr_Bfield_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_geo_nr_Bfield_scmc_set_parameter_inoutput (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_xyzw (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_cu_cache (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_cu_xyzw (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_xoffset (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_yoffset (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_zoffset (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_fieldE (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_fieldB (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_fieldB1 (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_FoutJ (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_XLEN (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_YLEN (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_ZLEN (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_ovlp (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_numvec (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_num_ele (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_grid_cache_len (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_cu_cache_length (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_DELTA_X (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_DELTA_Y (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_DELTA_Z (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_Mass0 (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_Charge0 (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_Deltat (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_Tori_X0 (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_r0 (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_MIN_R0 (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_Q0 (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_b0 (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_Bfield_scmc_set_parameter_zmid (c_geo_nr_Bfield_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_init (c_pscmc_env *  pe ,c_geo_nr_vlo_struct *  kerstr )
;
void  c_geo_nr_vlo_get_struct_len (size_t *  len )
;
int  c_geo_nr_vlo_get_xlen ()
;
int  c_geo_nr_vlo_get_num_compute_units (c_geo_nr_vlo_struct *  kerstr )
;
int  c_geo_nr_vlo_exec (c_geo_nr_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_geo_nr_vlo_scmc_set_parameter_inoutput (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_xyzw (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_cu_cache (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_cu_xyzw (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_xoffset (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_yoffset (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_zoffset (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_fieldE (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_fieldB (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_fieldB1 (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_FoutJ (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_XLEN (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_YLEN (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_ZLEN (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_ovlp (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_numvec (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_num_ele (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_grid_cache_len (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_cu_cache_length (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_DELTA_X (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_DELTA_Y (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_DELTA_Z (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_Mass0 (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_Charge0 (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_Deltat (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_Tori_X0 (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_r0 (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_MIN_R0 (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_Q0 (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_b0 (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_vlo_scmc_set_parameter_zmid (c_geo_nr_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_init (c_pscmc_env *  pe ,c_geo_nr_struct *  kerstr )
;
void  c_geo_nr_get_struct_len (size_t *  len )
;
int  c_geo_nr_get_xlen ()
;
int  c_geo_nr_get_num_compute_units (c_geo_nr_struct *  kerstr )
;
int  c_geo_nr_exec (c_geo_nr_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_geo_nr_scmc_set_parameter_inoutput (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_xyzw (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_cu_cache (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_cu_xyzw (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_xoffset (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_yoffset (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_zoffset (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_fieldE (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_fieldB (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_fieldB1 (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_FoutJ (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_XLEN (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_YLEN (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_ZLEN (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_ovlp (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_numvec (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_num_ele (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_grid_cache_len (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_cu_cache_length (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_DELTA_X (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_DELTA_Y (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_DELTA_Z (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_Mass0 (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_Charge0 (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_Deltat (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_Tori_X0 (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_r0 (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_MIN_R0 (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_Q0 (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_b0 (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_nr_scmc_set_parameter_zmid (c_geo_nr_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_init (c_pscmc_env *  pe ,c_ngeo_gc_struct *  kerstr )
;
void  c_ngeo_gc_get_struct_len (size_t *  len )
;
int  c_ngeo_gc_get_xlen ()
;
int  c_ngeo_gc_get_num_compute_units (c_ngeo_gc_struct *  kerstr )
;
int  c_ngeo_gc_exec (c_ngeo_gc_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_ngeo_gc_scmc_set_parameter_inoutput (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_xyzw (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_cu_cache (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_cu_xyzw (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_xoffset (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_yoffset (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_zoffset (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_fieldE (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_fieldB (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_fieldB1 (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_FoutJ (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_XLEN (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_YLEN (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_ZLEN (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_ovlp (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_numvec (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_num_ele (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_grid_cache_len (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_cu_cache_length (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_DELTA_X (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_DELTA_Y (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_DELTA_Z (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_Mass0 (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_Charge0 (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_Deltat (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_Tori_X0 (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_r0 (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_MIN_R0 (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_Q0 (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_b0 (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_ngeo_gc_scmc_set_parameter_zmid (c_ngeo_gc_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_mass_floorx (double  x )
;
void  c_geo_rel_1st_fwd_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  LFoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_geo_rel_1st_fwd_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  LFoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_geo_rel_1st_bwd_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  LFoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_geo_rel_1st_bwd_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  LFoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_relng_1st_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  LFoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_relng_1st_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  LFoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  c_relng_1st_sg2_small_grids_init (c_pscmc_env *  pe ,c_relng_1st_sg2_small_grids_struct *  kerstr )
;
void  c_relng_1st_sg2_small_grids_get_struct_len (size_t *  len )
;
int  c_relng_1st_sg2_small_grids_get_xlen ()
;
int  c_relng_1st_sg2_small_grids_get_num_compute_units (c_relng_1st_sg2_small_grids_struct *  kerstr )
;
int  c_relng_1st_sg2_small_grids_exec (c_relng_1st_sg2_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_inoutput (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_xyzw (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_cu_cache (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_cu_xyzw (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_xoffset (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_yoffset (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_zoffset (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_fieldE (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_fieldB (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_fieldB1 (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_LFoutJ (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_XLEN (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_YLEN (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_ZLEN (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_ovlp (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_numvec (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_num_ele (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_grid_cache_len (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_cu_cache_length (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_DELTA_X (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_DELTA_Y (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_DELTA_Z (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_Mass0 (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_Charge0 (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_Deltat (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_Tori_X0 (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_sg2_small_grids_scmc_set_parameter_Solve_Err (c_relng_1st_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_init (c_pscmc_env *  pe ,c_relng_1st_small_grids_struct *  kerstr )
;
void  c_relng_1st_small_grids_get_struct_len (size_t *  len )
;
int  c_relng_1st_small_grids_get_xlen ()
;
int  c_relng_1st_small_grids_get_num_compute_units (c_relng_1st_small_grids_struct *  kerstr )
;
int  c_relng_1st_small_grids_exec (c_relng_1st_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_relng_1st_small_grids_scmc_set_parameter_inoutput (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_xyzw (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_cu_cache (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_cu_xyzw (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_xoffset (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_yoffset (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_zoffset (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_fieldE (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_fieldB (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_fieldB1 (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_LFoutJ (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_XLEN (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_YLEN (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_ZLEN (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_ovlp (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_numvec (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_num_ele (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_grid_cache_len (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_cu_cache_length (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_DELTA_X (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_DELTA_Y (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_DELTA_Z (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_Mass0 (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_Charge0 (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_Deltat (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_Tori_X0 (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_small_grids_scmc_set_parameter_Solve_Err (c_relng_1st_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_init (c_pscmc_env *  pe ,c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr )
;
void  c_geo_rel_1st_bwd_sg2_small_grids_get_struct_len (size_t *  len )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_get_xlen ()
;
int  c_geo_rel_1st_bwd_sg2_small_grids_get_num_compute_units (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_exec (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_inoutput (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_xyzw (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_cu_cache (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_cu_xyzw (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_xoffset (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_yoffset (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_zoffset (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_fieldE (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_fieldB (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_fieldB1 (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_LFoutJ (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_XLEN (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_YLEN (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_ZLEN (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_ovlp (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_numvec (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_num_ele (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_grid_cache_len (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_cu_cache_length (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_DELTA_X (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_DELTA_Y (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_DELTA_Z (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_Mass0 (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_Charge0 (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_Deltat (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_Tori_X0 (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_Solve_Err (c_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_init (c_pscmc_env *  pe ,c_geo_rel_1st_bwd_small_grids_struct *  kerstr )
;
void  c_geo_rel_1st_bwd_small_grids_get_struct_len (size_t *  len )
;
int  c_geo_rel_1st_bwd_small_grids_get_xlen ()
;
int  c_geo_rel_1st_bwd_small_grids_get_num_compute_units (c_geo_rel_1st_bwd_small_grids_struct *  kerstr )
;
int  c_geo_rel_1st_bwd_small_grids_exec (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_inoutput (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_xyzw (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_cu_cache (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_cu_xyzw (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_xoffset (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_yoffset (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_zoffset (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_fieldE (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_fieldB (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_fieldB1 (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_LFoutJ (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_XLEN (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_YLEN (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_ZLEN (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_ovlp (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_numvec (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_num_ele (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_grid_cache_len (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_cu_cache_length (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_DELTA_X (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_DELTA_Y (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_DELTA_Z (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_Mass0 (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_Charge0 (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_Deltat (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_Tori_X0 (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_small_grids_scmc_set_parameter_Solve_Err (c_geo_rel_1st_bwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_init (c_pscmc_env *  pe ,c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr )
;
void  c_geo_rel_1st_fwd_sg2_small_grids_get_struct_len (size_t *  len )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_get_xlen ()
;
int  c_geo_rel_1st_fwd_sg2_small_grids_get_num_compute_units (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_exec (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_inoutput (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_xyzw (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_cu_cache (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_cu_xyzw (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_xoffset (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_yoffset (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_zoffset (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_fieldE (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_fieldB (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_fieldB1 (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_LFoutJ (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_XLEN (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_YLEN (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_ZLEN (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_ovlp (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_numvec (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_num_ele (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_grid_cache_len (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_cu_cache_length (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_DELTA_X (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_DELTA_Y (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_DELTA_Z (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_Mass0 (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_Charge0 (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_Deltat (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_Tori_X0 (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_Solve_Err (c_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_init (c_pscmc_env *  pe ,c_geo_rel_1st_fwd_small_grids_struct *  kerstr )
;
void  c_geo_rel_1st_fwd_small_grids_get_struct_len (size_t *  len )
;
int  c_geo_rel_1st_fwd_small_grids_get_xlen ()
;
int  c_geo_rel_1st_fwd_small_grids_get_num_compute_units (c_geo_rel_1st_fwd_small_grids_struct *  kerstr )
;
int  c_geo_rel_1st_fwd_small_grids_exec (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_inoutput (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_xyzw (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_cu_cache (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_cu_xyzw (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_xoffset (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_yoffset (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_zoffset (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_fieldE (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_fieldB (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_fieldB1 (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_LFoutJ (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_XLEN (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_YLEN (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_ZLEN (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_ovlp (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_numvec (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_num_ele (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_grid_cache_len (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_cu_cache_length (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_DELTA_X (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_DELTA_Y (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_DELTA_Z (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_Mass0 (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_Charge0 (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_Deltat (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_Tori_X0 (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_small_grids_scmc_set_parameter_Solve_Err (c_geo_rel_1st_fwd_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_floorx (double  x )
;
void  c_geo_rel_1st_fwd_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_geo_rel_1st_bwd_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  c_geo_rel_1st_bwd_init (c_pscmc_env *  pe ,c_geo_rel_1st_bwd_struct *  kerstr )
;
void  c_geo_rel_1st_bwd_get_struct_len (size_t *  len )
;
int  c_geo_rel_1st_bwd_get_xlen ()
;
int  c_geo_rel_1st_bwd_get_num_compute_units (c_geo_rel_1st_bwd_struct *  kerstr )
;
int  c_geo_rel_1st_bwd_exec (c_geo_rel_1st_bwd_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_inoutput (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_xyzw (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_cu_cache (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_cu_xyzw (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_xoffset (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_yoffset (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_zoffset (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_fieldE (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_fieldB (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_fieldB1 (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_FoutJ (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_XLEN (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_YLEN (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_ZLEN (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_ovlp (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_numvec (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_num_ele (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_grid_cache_len (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_cu_cache_length (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_DELTA_X (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_DELTA_Y (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_DELTA_Z (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_Mass0 (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_Charge0 (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_Deltat (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_Tori_X0 (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_bwd_scmc_set_parameter_Solve_Err (c_geo_rel_1st_bwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_init (c_pscmc_env *  pe ,c_geo_rel_1st_fwd_struct *  kerstr )
;
void  c_geo_rel_1st_fwd_get_struct_len (size_t *  len )
;
int  c_geo_rel_1st_fwd_get_xlen ()
;
int  c_geo_rel_1st_fwd_get_num_compute_units (c_geo_rel_1st_fwd_struct *  kerstr )
;
int  c_geo_rel_1st_fwd_exec (c_geo_rel_1st_fwd_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_inoutput (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_xyzw (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_cu_cache (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_cu_xyzw (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_xoffset (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_yoffset (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_zoffset (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_fieldE (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_fieldB (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_fieldB1 (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_FoutJ (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_XLEN (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_YLEN (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_ZLEN (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_ovlp (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_numvec (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_num_ele (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_grid_cache_len (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_cu_cache_length (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_DELTA_X (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_DELTA_Y (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_DELTA_Z (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_Mass0 (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_Charge0 (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_Deltat (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_Tori_X0 (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_geo_rel_1st_fwd_scmc_set_parameter_Solve_Err (c_geo_rel_1st_fwd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_floory (double  x )
;
void  c_relng_1st_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  c_relng_1st_init (c_pscmc_env *  pe ,c_relng_1st_struct *  kerstr )
;
void  c_relng_1st_get_struct_len (size_t *  len )
;
int  c_relng_1st_get_xlen ()
;
int  c_relng_1st_get_num_compute_units (c_relng_1st_struct *  kerstr )
;
int  c_relng_1st_exec (c_relng_1st_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_relng_1st_scmc_set_parameter_inoutput (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_xyzw (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_cu_cache (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_cu_xyzw (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_xoffset (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_yoffset (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_zoffset (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_fieldE (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_fieldB (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_fieldB1 (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_FoutJ (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_XLEN (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_YLEN (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_ZLEN (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_ovlp (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_numvec (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_num_ele (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_grid_cache_len (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_cu_cache_length (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_DELTA_X (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_DELTA_Y (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_DELTA_Z (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_Mass0 (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_Charge0 (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_Deltat (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_Tori_X0 (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_relng_1st_scmc_set_parameter_Solve_Err (c_relng_1st_struct *  kerstr ,c_pscmc_mem *  pm )
;
void  c_Yee_FDTD_Curl_E_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_Yee_FDTD_Curl_E_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_Yee_FDTD_Curl_B_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_Yee_FDTD_Curl_B_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_Yee_FDTD_Grad_BWD_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_Yee_FDTD_Grad_BWD_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_Yee_FDTD_Grad_FWD_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_Yee_FDTD_Grad_FWD_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_Yee_FDTD_Curl_BWD_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_Yee_FDTD_Curl_BWD_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_Yee_FDTD_Curl_FWD_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_Yee_FDTD_Curl_FWD_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_Yee_FDTD_Div_BWD_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_Yee_FDTD_Div_BWD_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_Yee_FDTD_Div_FWD_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_Yee_FDTD_Div_FWD_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_merge_current_2_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_merge_current_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_PML_FDTD_CURL_FWD_scmc_kernel (double *  outEB ,double *  inEB ,double *  outPMLEB ,double *  inPMLEB ,int *  xoffset ,int *  yoffset ,int *  zoffset ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,double  M ,double  Q ,double  DX ,double  DY ,double  DZ ,int  abc_dir ,int  level ,int  pml_m ,double  max_sigma ,long  allxmax ,long  allymax ,long  allzmax ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_PML_FDTD_CURL_BWD_scmc_kernel (double *  outEB ,double *  inEB ,double *  outPMLEB ,double *  inPMLEB ,int *  xoffset ,int *  yoffset ,int *  zoffset ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,double  M ,double  Q ,double  DX ,double  DY ,double  DZ ,int  abc_dir ,int  level ,int  pml_m ,double  max_sigma ,long  allxmax ,long  allymax ,long  allzmax ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_kgm_calc_rho_scmc_kernel (double *  outEB ,double *  inEB ,int *  xoffset ,int *  yoffset ,int *  zoffset ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,double  M ,double  Q ,double  DX ,double  refz0 ,double  q ,double  dtodx ,int  mode ,int  swap_input ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_kgm_eqn_core_scmc_kernel (double *  outEB ,double *  inEB ,double *  extA0 ,double *  extA1 ,int *  xoffset ,int *  yoffset ,int *  zoffset ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,double  M ,double  Q ,double  DX ,double  GEXT ,double  rfz0 ,double  g_beg ,int  swap_input ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  c_kgm_eqn_core_init (c_pscmc_env *  pe ,c_kgm_eqn_core_struct *  kerstr )
;
void  c_kgm_eqn_core_get_struct_len (size_t *  len )
;
int  c_kgm_eqn_core_get_xlen ()
;
int  c_kgm_eqn_core_get_num_compute_units (c_kgm_eqn_core_struct *  kerstr )
;
int  c_kgm_eqn_core_exec (c_kgm_eqn_core_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_kgm_eqn_core_scmc_set_parameter_outEB (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_inEB (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_extA0 (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_extA1 (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_xoffset (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_yoffset (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_zoffset (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_y_cpu_core (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_numvec (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_XLEN (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_YLEN (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_ZLEN (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_ovlp (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_xblock (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_yblock (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_zblock (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_num_ele (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_DT (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_M (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_Q (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_DX (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_GEXT (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_rfz0 (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_g_beg (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_swap_input (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_init (c_pscmc_env *  pe ,c_kgm_calc_rho_struct *  kerstr )
;
void  c_kgm_calc_rho_get_struct_len (size_t *  len )
;
int  c_kgm_calc_rho_get_xlen ()
;
int  c_kgm_calc_rho_get_num_compute_units (c_kgm_calc_rho_struct *  kerstr )
;
int  c_kgm_calc_rho_exec (c_kgm_calc_rho_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_kgm_calc_rho_scmc_set_parameter_outEB (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_inEB (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_xoffset (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_yoffset (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_zoffset (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_y_cpu_core (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_numvec (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_XLEN (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_YLEN (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_ZLEN (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_ovlp (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_xblock (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_yblock (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_zblock (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_num_ele (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_DT (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_M (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_Q (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_DX (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_refz0 (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_q (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_dtodx (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_mode (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_calc_rho_scmc_set_parameter_swap_input (c_kgm_calc_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_init (c_pscmc_env *  pe ,c_PML_FDTD_CURL_BWD_struct *  kerstr )
;
void  c_PML_FDTD_CURL_BWD_get_struct_len (size_t *  len )
;
int  c_PML_FDTD_CURL_BWD_get_xlen ()
;
int  c_PML_FDTD_CURL_BWD_get_num_compute_units (c_PML_FDTD_CURL_BWD_struct *  kerstr )
;
int  c_PML_FDTD_CURL_BWD_exec (c_PML_FDTD_CURL_BWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_outEB (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_inEB (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_outPMLEB (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_inPMLEB (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_xoffset (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_yoffset (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_zoffset (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_y_cpu_core (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_numvec (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_XLEN (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_YLEN (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_ZLEN (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_ovlp (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_xblock (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_yblock (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_zblock (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_num_ele (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_DT (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_M (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_Q (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_DX (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_DY (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_DZ (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_abc_dir (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_level (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_pml_m (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_max_sigma (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_allxmax (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_allymax (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_BWD_scmc_set_parameter_allzmax (c_PML_FDTD_CURL_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_init (c_pscmc_env *  pe ,c_PML_FDTD_CURL_FWD_struct *  kerstr )
;
void  c_PML_FDTD_CURL_FWD_get_struct_len (size_t *  len )
;
int  c_PML_FDTD_CURL_FWD_get_xlen ()
;
int  c_PML_FDTD_CURL_FWD_get_num_compute_units (c_PML_FDTD_CURL_FWD_struct *  kerstr )
;
int  c_PML_FDTD_CURL_FWD_exec (c_PML_FDTD_CURL_FWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_outEB (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_inEB (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_outPMLEB (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_inPMLEB (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_xoffset (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_yoffset (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_zoffset (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_y_cpu_core (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_numvec (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_XLEN (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_YLEN (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_ZLEN (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_ovlp (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_xblock (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_yblock (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_zblock (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_num_ele (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_DT (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_M (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_Q (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_DX (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_DY (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_DZ (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_abc_dir (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_level (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_pml_m (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_max_sigma (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_allxmax (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_allymax (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_PML_FDTD_CURL_FWD_scmc_set_parameter_allzmax (c_PML_FDTD_CURL_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_init (c_pscmc_env *  pe ,c_merge_current_struct *  kerstr )
;
void  c_merge_current_get_struct_len (size_t *  len )
;
int  c_merge_current_get_xlen ()
;
int  c_merge_current_get_num_compute_units (c_merge_current_struct *  kerstr )
;
int  c_merge_current_exec (c_merge_current_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_merge_current_scmc_set_parameter_outEB (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_scmc_set_parameter_inEB (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_scmc_set_parameter_y_cpu_core (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_scmc_set_parameter_numvec (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_scmc_set_parameter_XLEN (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_scmc_set_parameter_YLEN (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_scmc_set_parameter_ZLEN (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_scmc_set_parameter_ovlp (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_scmc_set_parameter_xblock (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_scmc_set_parameter_yblock (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_scmc_set_parameter_zblock (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_scmc_set_parameter_num_ele (c_merge_current_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_2_init (c_pscmc_env *  pe ,c_merge_current_2_struct *  kerstr )
;
void  c_merge_current_2_get_struct_len (size_t *  len )
;
int  c_merge_current_2_get_xlen ()
;
int  c_merge_current_2_get_num_compute_units (c_merge_current_2_struct *  kerstr )
;
int  c_merge_current_2_exec (c_merge_current_2_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_merge_current_2_scmc_set_parameter_outEB (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_2_scmc_set_parameter_inEB (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_2_scmc_set_parameter_y_cpu_core (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_2_scmc_set_parameter_numvec (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_2_scmc_set_parameter_XLEN (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_2_scmc_set_parameter_YLEN (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_2_scmc_set_parameter_ZLEN (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_2_scmc_set_parameter_ovlp (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_2_scmc_set_parameter_xblock (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_2_scmc_set_parameter_yblock (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_2_scmc_set_parameter_zblock (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_current_2_scmc_set_parameter_num_ele (c_merge_current_2_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_4th_init (c_pscmc_env *  pe ,c_Yee_FDTD_Div_FWD_4th_struct *  kerstr )
;
void  c_Yee_FDTD_Div_FWD_4th_get_struct_len (size_t *  len )
;
int  c_Yee_FDTD_Div_FWD_4th_get_xlen ()
;
int  c_Yee_FDTD_Div_FWD_4th_get_num_compute_units (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr )
;
int  c_Yee_FDTD_Div_FWD_4th_exec (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_outEB (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_inEB (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_numvec (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_XLEN (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_YLEN (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_ZLEN (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_ovlp (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_xblock (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_yblock (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_zblock (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_num_ele (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_DT (c_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_init (c_pscmc_env *  pe ,c_Yee_FDTD_Div_FWD_struct *  kerstr )
;
void  c_Yee_FDTD_Div_FWD_get_struct_len (size_t *  len )
;
int  c_Yee_FDTD_Div_FWD_get_xlen ()
;
int  c_Yee_FDTD_Div_FWD_get_num_compute_units (c_Yee_FDTD_Div_FWD_struct *  kerstr )
;
int  c_Yee_FDTD_Div_FWD_exec (c_Yee_FDTD_Div_FWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_outEB (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_inEB (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_numvec (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_XLEN (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_YLEN (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_ZLEN (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_ovlp (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_xblock (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_yblock (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_zblock (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_num_ele (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_FWD_scmc_set_parameter_DT (c_Yee_FDTD_Div_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_4th_init (c_pscmc_env *  pe ,c_Yee_FDTD_Div_BWD_4th_struct *  kerstr )
;
void  c_Yee_FDTD_Div_BWD_4th_get_struct_len (size_t *  len )
;
int  c_Yee_FDTD_Div_BWD_4th_get_xlen ()
;
int  c_Yee_FDTD_Div_BWD_4th_get_num_compute_units (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr )
;
int  c_Yee_FDTD_Div_BWD_4th_exec (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_outEB (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_inEB (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_numvec (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_XLEN (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_YLEN (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_ZLEN (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_ovlp (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_xblock (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_yblock (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_zblock (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_num_ele (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_DT (c_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_init (c_pscmc_env *  pe ,c_Yee_FDTD_Div_BWD_struct *  kerstr )
;
void  c_Yee_FDTD_Div_BWD_get_struct_len (size_t *  len )
;
int  c_Yee_FDTD_Div_BWD_get_xlen ()
;
int  c_Yee_FDTD_Div_BWD_get_num_compute_units (c_Yee_FDTD_Div_BWD_struct *  kerstr )
;
int  c_Yee_FDTD_Div_BWD_exec (c_Yee_FDTD_Div_BWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_outEB (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_inEB (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_numvec (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_XLEN (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_YLEN (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_ZLEN (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_ovlp (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_xblock (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_yblock (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_zblock (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_num_ele (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Div_BWD_scmc_set_parameter_DT (c_Yee_FDTD_Div_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_4th_init (c_pscmc_env *  pe ,c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr )
;
void  c_Yee_FDTD_Curl_FWD_4th_get_struct_len (size_t *  len )
;
int  c_Yee_FDTD_Curl_FWD_4th_get_xlen ()
;
int  c_Yee_FDTD_Curl_FWD_4th_get_num_compute_units (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr )
;
int  c_Yee_FDTD_Curl_FWD_4th_exec (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_outEB (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_inEB (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_numvec (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_XLEN (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_YLEN (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_ZLEN (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_ovlp (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_xblock (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_yblock (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_zblock (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_num_ele (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_DT (c_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_init (c_pscmc_env *  pe ,c_Yee_FDTD_Curl_FWD_struct *  kerstr )
;
void  c_Yee_FDTD_Curl_FWD_get_struct_len (size_t *  len )
;
int  c_Yee_FDTD_Curl_FWD_get_xlen ()
;
int  c_Yee_FDTD_Curl_FWD_get_num_compute_units (c_Yee_FDTD_Curl_FWD_struct *  kerstr )
;
int  c_Yee_FDTD_Curl_FWD_exec (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_outEB (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_inEB (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_numvec (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_XLEN (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_YLEN (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_ZLEN (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_ovlp (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_xblock (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_yblock (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_zblock (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_num_ele (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_FWD_scmc_set_parameter_DT (c_Yee_FDTD_Curl_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_4th_init (c_pscmc_env *  pe ,c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr )
;
void  c_Yee_FDTD_Curl_BWD_4th_get_struct_len (size_t *  len )
;
int  c_Yee_FDTD_Curl_BWD_4th_get_xlen ()
;
int  c_Yee_FDTD_Curl_BWD_4th_get_num_compute_units (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr )
;
int  c_Yee_FDTD_Curl_BWD_4th_exec (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_outEB (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_inEB (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_numvec (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_XLEN (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_YLEN (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_ZLEN (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_ovlp (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_xblock (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_yblock (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_zblock (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_num_ele (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_DT (c_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_init (c_pscmc_env *  pe ,c_Yee_FDTD_Curl_BWD_struct *  kerstr )
;
void  c_Yee_FDTD_Curl_BWD_get_struct_len (size_t *  len )
;
int  c_Yee_FDTD_Curl_BWD_get_xlen ()
;
int  c_Yee_FDTD_Curl_BWD_get_num_compute_units (c_Yee_FDTD_Curl_BWD_struct *  kerstr )
;
int  c_Yee_FDTD_Curl_BWD_exec (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_outEB (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_inEB (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_numvec (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_XLEN (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_YLEN (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_ZLEN (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_ovlp (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_xblock (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_yblock (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_zblock (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_num_ele (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_BWD_scmc_set_parameter_DT (c_Yee_FDTD_Curl_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_4th_init (c_pscmc_env *  pe ,c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr )
;
void  c_Yee_FDTD_Grad_FWD_4th_get_struct_len (size_t *  len )
;
int  c_Yee_FDTD_Grad_FWD_4th_get_xlen ()
;
int  c_Yee_FDTD_Grad_FWD_4th_get_num_compute_units (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr )
;
int  c_Yee_FDTD_Grad_FWD_4th_exec (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_outEB (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_inEB (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_numvec (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_XLEN (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_YLEN (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_ZLEN (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_ovlp (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_xblock (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_yblock (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_zblock (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_num_ele (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_DT (c_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_init (c_pscmc_env *  pe ,c_Yee_FDTD_Grad_FWD_struct *  kerstr )
;
void  c_Yee_FDTD_Grad_FWD_get_struct_len (size_t *  len )
;
int  c_Yee_FDTD_Grad_FWD_get_xlen ()
;
int  c_Yee_FDTD_Grad_FWD_get_num_compute_units (c_Yee_FDTD_Grad_FWD_struct *  kerstr )
;
int  c_Yee_FDTD_Grad_FWD_exec (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_outEB (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_inEB (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_numvec (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_XLEN (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_YLEN (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_ZLEN (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_ovlp (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_xblock (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_yblock (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_zblock (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_num_ele (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_FWD_scmc_set_parameter_DT (c_Yee_FDTD_Grad_FWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_4th_init (c_pscmc_env *  pe ,c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr )
;
void  c_Yee_FDTD_Grad_BWD_4th_get_struct_len (size_t *  len )
;
int  c_Yee_FDTD_Grad_BWD_4th_get_xlen ()
;
int  c_Yee_FDTD_Grad_BWD_4th_get_num_compute_units (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr )
;
int  c_Yee_FDTD_Grad_BWD_4th_exec (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_outEB (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_inEB (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_numvec (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_XLEN (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_YLEN (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_ZLEN (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_ovlp (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_xblock (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_yblock (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_zblock (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_num_ele (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_DT (c_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_init (c_pscmc_env *  pe ,c_Yee_FDTD_Grad_BWD_struct *  kerstr )
;
void  c_Yee_FDTD_Grad_BWD_get_struct_len (size_t *  len )
;
int  c_Yee_FDTD_Grad_BWD_get_xlen ()
;
int  c_Yee_FDTD_Grad_BWD_get_num_compute_units (c_Yee_FDTD_Grad_BWD_struct *  kerstr )
;
int  c_Yee_FDTD_Grad_BWD_exec (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_outEB (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_inEB (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_numvec (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_XLEN (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_YLEN (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_ZLEN (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_ovlp (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_xblock (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_yblock (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_zblock (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_num_ele (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Grad_BWD_scmc_set_parameter_DT (c_Yee_FDTD_Grad_BWD_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_4th_init (c_pscmc_env *  pe ,c_Yee_FDTD_Curl_B_4th_struct *  kerstr )
;
void  c_Yee_FDTD_Curl_B_4th_get_struct_len (size_t *  len )
;
int  c_Yee_FDTD_Curl_B_4th_get_xlen ()
;
int  c_Yee_FDTD_Curl_B_4th_get_num_compute_units (c_Yee_FDTD_Curl_B_4th_struct *  kerstr )
;
int  c_Yee_FDTD_Curl_B_4th_exec (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_outEB (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_inEB (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_numvec (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_XLEN (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_YLEN (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_ZLEN (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_ovlp (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_xblock (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_yblock (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_zblock (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_num_ele (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_4th_scmc_set_parameter_DT (c_Yee_FDTD_Curl_B_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_init (c_pscmc_env *  pe ,c_Yee_FDTD_Curl_B_struct *  kerstr )
;
void  c_Yee_FDTD_Curl_B_get_struct_len (size_t *  len )
;
int  c_Yee_FDTD_Curl_B_get_xlen ()
;
int  c_Yee_FDTD_Curl_B_get_num_compute_units (c_Yee_FDTD_Curl_B_struct *  kerstr )
;
int  c_Yee_FDTD_Curl_B_exec (c_Yee_FDTD_Curl_B_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_outEB (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_inEB (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_numvec (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_XLEN (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_YLEN (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_ZLEN (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_ovlp (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_xblock (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_yblock (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_zblock (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_num_ele (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_B_scmc_set_parameter_DT (c_Yee_FDTD_Curl_B_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_4th_init (c_pscmc_env *  pe ,c_Yee_FDTD_Curl_E_4th_struct *  kerstr )
;
void  c_Yee_FDTD_Curl_E_4th_get_struct_len (size_t *  len )
;
int  c_Yee_FDTD_Curl_E_4th_get_xlen ()
;
int  c_Yee_FDTD_Curl_E_4th_get_num_compute_units (c_Yee_FDTD_Curl_E_4th_struct *  kerstr )
;
int  c_Yee_FDTD_Curl_E_4th_exec (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_outEB (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_inEB (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_numvec (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_XLEN (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_YLEN (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_ZLEN (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_ovlp (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_xblock (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_yblock (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_zblock (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_num_ele (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_4th_scmc_set_parameter_DT (c_Yee_FDTD_Curl_E_4th_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_init (c_pscmc_env *  pe ,c_Yee_FDTD_Curl_E_struct *  kerstr )
;
void  c_Yee_FDTD_Curl_E_get_struct_len (size_t *  len )
;
int  c_Yee_FDTD_Curl_E_get_xlen ()
;
int  c_Yee_FDTD_Curl_E_get_num_compute_units (c_Yee_FDTD_Curl_E_struct *  kerstr )
;
int  c_Yee_FDTD_Curl_E_exec (c_Yee_FDTD_Curl_E_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_outEB (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_inEB (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_y_cpu_core (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_numvec (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_XLEN (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_YLEN (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_ZLEN (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_ovlp (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_xblock (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_yblock (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_zblock (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_num_ele (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_Yee_FDTD_Curl_E_scmc_set_parameter_DT (c_Yee_FDTD_Curl_E_struct *  kerstr ,c_pscmc_mem *  pm )
;
void  c_yee_local_scmc_kernel (double *  inout ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_sync_ovlp_o2m_scmc_kernel (double *  vecmain ,double *  vecovlp ,int  ovlpindex ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_sync_ovlp_m2o_scmc_kernel (double *  vecmain ,double *  vecovlp ,int  ovlpindex ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_merge_ovlp_o2m_scmc_kernel (double *  vecmain ,double *  vecovlp ,int  ovlpindex ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_merge_ovlp_m2o_scmc_kernel (double *  vecmain ,double *  vecovlp ,int  ovlpindex ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  c_merge_ovlp_m2o_init (c_pscmc_env *  pe ,c_merge_ovlp_m2o_struct *  kerstr )
;
void  c_merge_ovlp_m2o_get_struct_len (size_t *  len )
;
int  c_merge_ovlp_m2o_get_xlen ()
;
int  c_merge_ovlp_m2o_get_num_compute_units (c_merge_ovlp_m2o_struct *  kerstr )
;
int  c_merge_ovlp_m2o_exec (c_merge_ovlp_m2o_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_merge_ovlp_m2o_scmc_set_parameter_vecmain (c_merge_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_ovlp_m2o_scmc_set_parameter_vecovlp (c_merge_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_ovlp_m2o_scmc_set_parameter_ovlpindex (c_merge_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_ovlp_m2o_scmc_set_parameter_numvec (c_merge_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_ovlp_m2o_scmc_set_parameter_num_ele (c_merge_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_ovlp_m2o_scmc_set_parameter_xblock (c_merge_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_ovlp_m2o_scmc_set_parameter_yblock (c_merge_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_ovlp_m2o_scmc_set_parameter_zblock (c_merge_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_ovlp_m2o_scmc_set_parameter_ovlp (c_merge_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_ovlp_o2m_init (c_pscmc_env *  pe ,c_merge_ovlp_o2m_struct *  kerstr )
;
void  c_merge_ovlp_o2m_get_struct_len (size_t *  len )
;
int  c_merge_ovlp_o2m_get_xlen ()
;
int  c_merge_ovlp_o2m_get_num_compute_units (c_merge_ovlp_o2m_struct *  kerstr )
;
int  c_merge_ovlp_o2m_exec (c_merge_ovlp_o2m_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_merge_ovlp_o2m_scmc_set_parameter_vecmain (c_merge_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_ovlp_o2m_scmc_set_parameter_vecovlp (c_merge_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_ovlp_o2m_scmc_set_parameter_ovlpindex (c_merge_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_ovlp_o2m_scmc_set_parameter_numvec (c_merge_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_ovlp_o2m_scmc_set_parameter_num_ele (c_merge_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_ovlp_o2m_scmc_set_parameter_xblock (c_merge_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_ovlp_o2m_scmc_set_parameter_yblock (c_merge_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_ovlp_o2m_scmc_set_parameter_zblock (c_merge_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_merge_ovlp_o2m_scmc_set_parameter_ovlp (c_merge_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sync_ovlp_m2o_init (c_pscmc_env *  pe ,c_sync_ovlp_m2o_struct *  kerstr )
;
void  c_sync_ovlp_m2o_get_struct_len (size_t *  len )
;
int  c_sync_ovlp_m2o_get_xlen ()
;
int  c_sync_ovlp_m2o_get_num_compute_units (c_sync_ovlp_m2o_struct *  kerstr )
;
int  c_sync_ovlp_m2o_exec (c_sync_ovlp_m2o_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_sync_ovlp_m2o_scmc_set_parameter_vecmain (c_sync_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sync_ovlp_m2o_scmc_set_parameter_vecovlp (c_sync_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sync_ovlp_m2o_scmc_set_parameter_ovlpindex (c_sync_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sync_ovlp_m2o_scmc_set_parameter_numvec (c_sync_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sync_ovlp_m2o_scmc_set_parameter_num_ele (c_sync_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sync_ovlp_m2o_scmc_set_parameter_xblock (c_sync_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sync_ovlp_m2o_scmc_set_parameter_yblock (c_sync_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sync_ovlp_m2o_scmc_set_parameter_zblock (c_sync_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sync_ovlp_m2o_scmc_set_parameter_ovlp (c_sync_ovlp_m2o_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sync_ovlp_o2m_init (c_pscmc_env *  pe ,c_sync_ovlp_o2m_struct *  kerstr )
;
void  c_sync_ovlp_o2m_get_struct_len (size_t *  len )
;
int  c_sync_ovlp_o2m_get_xlen ()
;
int  c_sync_ovlp_o2m_get_num_compute_units (c_sync_ovlp_o2m_struct *  kerstr )
;
int  c_sync_ovlp_o2m_exec (c_sync_ovlp_o2m_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_sync_ovlp_o2m_scmc_set_parameter_vecmain (c_sync_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sync_ovlp_o2m_scmc_set_parameter_vecovlp (c_sync_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sync_ovlp_o2m_scmc_set_parameter_ovlpindex (c_sync_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sync_ovlp_o2m_scmc_set_parameter_numvec (c_sync_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sync_ovlp_o2m_scmc_set_parameter_num_ele (c_sync_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sync_ovlp_o2m_scmc_set_parameter_xblock (c_sync_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sync_ovlp_o2m_scmc_set_parameter_yblock (c_sync_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sync_ovlp_o2m_scmc_set_parameter_zblock (c_sync_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sync_ovlp_o2m_scmc_set_parameter_ovlp (c_sync_ovlp_o2m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_local_init (c_pscmc_env *  pe ,c_yee_local_struct *  kerstr )
;
void  c_yee_local_get_struct_len (size_t *  len )
;
int  c_yee_local_get_xlen ()
;
int  c_yee_local_get_num_compute_units (c_yee_local_struct *  kerstr )
;
int  c_yee_local_exec (c_yee_local_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_local_scmc_set_parameter_inout (c_yee_local_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_local_scmc_set_parameter_numvec (c_yee_local_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_local_scmc_set_parameter_num_ele (c_yee_local_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_local_scmc_set_parameter_xblock (c_yee_local_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_local_scmc_set_parameter_yblock (c_yee_local_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_local_scmc_set_parameter_zblock (c_yee_local_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_local_scmc_set_parameter_ovlp (c_yee_local_struct *  kerstr ,c_pscmc_mem *  pm )
;
void  c_blas_yiszero_synced_scmc_kernel (double *  y ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_blas_mulxy_numele3_scmc_kernel (double *  y ,double *  x ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_blas_yiszero_scmc_kernel (double *  y ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_blas_yisconst_scmc_kernel (double *  y ,double  a ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_blas_get_ITG_Potential_scmc_kernel (double *  y ,double *  x ,double *  u ,double  minus_over_q_e ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_blas_invy_scmc_kernel (double *  y ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_blas_yisax_scmc_kernel (double *  y ,double *  x ,double  a ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_blas_axpy_scmc_kernel (double *  y ,double *  x ,double  a ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_blas_axpby_scmc_kernel (double *  y ,double *  x ,double  a ,double  b ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_blas_mulxy_scmc_kernel (double *  y ,double *  x ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_blas_findmax_scmc_kernel (double *  y ,double *  rdcd ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_blas_dot_scmc_kernel (double *  y ,double *  x ,double *  rdcd ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_blas_sum_scmc_kernel (double *  y ,double *  rdcd ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  c_blas_sum_init (c_pscmc_env *  pe ,c_blas_sum_struct *  kerstr )
;
void  c_blas_sum_get_struct_len (size_t *  len )
;
int  c_blas_sum_get_xlen ()
;
int  c_blas_sum_get_num_compute_units (c_blas_sum_struct *  kerstr )
;
int  c_blas_sum_exec (c_blas_sum_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_blas_sum_scmc_set_parameter_y (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_sum_scmc_set_parameter_rdcd (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_sum_scmc_set_parameter_y_cpu_core (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_sum_scmc_set_parameter_numvec (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_sum_scmc_set_parameter_XLEN (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_sum_scmc_set_parameter_YLEN (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_sum_scmc_set_parameter_ZLEN (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_sum_scmc_set_parameter_ovlp (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_sum_scmc_set_parameter_xblock (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_sum_scmc_set_parameter_yblock (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_sum_scmc_set_parameter_zblock (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_sum_scmc_set_parameter_num_ele (c_blas_sum_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_dot_init (c_pscmc_env *  pe ,c_blas_dot_struct *  kerstr )
;
void  c_blas_dot_get_struct_len (size_t *  len )
;
int  c_blas_dot_get_xlen ()
;
int  c_blas_dot_get_num_compute_units (c_blas_dot_struct *  kerstr )
;
int  c_blas_dot_exec (c_blas_dot_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_blas_dot_scmc_set_parameter_y (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_dot_scmc_set_parameter_x (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_dot_scmc_set_parameter_rdcd (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_dot_scmc_set_parameter_y_cpu_core (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_dot_scmc_set_parameter_numvec (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_dot_scmc_set_parameter_XLEN (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_dot_scmc_set_parameter_YLEN (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_dot_scmc_set_parameter_ZLEN (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_dot_scmc_set_parameter_ovlp (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_dot_scmc_set_parameter_xblock (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_dot_scmc_set_parameter_yblock (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_dot_scmc_set_parameter_zblock (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_dot_scmc_set_parameter_num_ele (c_blas_dot_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_findmax_init (c_pscmc_env *  pe ,c_blas_findmax_struct *  kerstr )
;
void  c_blas_findmax_get_struct_len (size_t *  len )
;
int  c_blas_findmax_get_xlen ()
;
int  c_blas_findmax_get_num_compute_units (c_blas_findmax_struct *  kerstr )
;
int  c_blas_findmax_exec (c_blas_findmax_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_blas_findmax_scmc_set_parameter_y (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_findmax_scmc_set_parameter_rdcd (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_findmax_scmc_set_parameter_y_cpu_core (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_findmax_scmc_set_parameter_numvec (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_findmax_scmc_set_parameter_XLEN (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_findmax_scmc_set_parameter_YLEN (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_findmax_scmc_set_parameter_ZLEN (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_findmax_scmc_set_parameter_ovlp (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_findmax_scmc_set_parameter_xblock (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_findmax_scmc_set_parameter_yblock (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_findmax_scmc_set_parameter_zblock (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_findmax_scmc_set_parameter_num_ele (c_blas_findmax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_init (c_pscmc_env *  pe ,c_blas_mulxy_struct *  kerstr )
;
void  c_blas_mulxy_get_struct_len (size_t *  len )
;
int  c_blas_mulxy_get_xlen ()
;
int  c_blas_mulxy_get_num_compute_units (c_blas_mulxy_struct *  kerstr )
;
int  c_blas_mulxy_exec (c_blas_mulxy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_blas_mulxy_scmc_set_parameter_y (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_scmc_set_parameter_x (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_scmc_set_parameter_y_cpu_core (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_scmc_set_parameter_numvec (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_scmc_set_parameter_XLEN (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_scmc_set_parameter_YLEN (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_scmc_set_parameter_ZLEN (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_scmc_set_parameter_ovlp (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_scmc_set_parameter_xblock (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_scmc_set_parameter_yblock (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_scmc_set_parameter_zblock (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_scmc_set_parameter_num_ele (c_blas_mulxy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpby_init (c_pscmc_env *  pe ,c_blas_axpby_struct *  kerstr )
;
void  c_blas_axpby_get_struct_len (size_t *  len )
;
int  c_blas_axpby_get_xlen ()
;
int  c_blas_axpby_get_num_compute_units (c_blas_axpby_struct *  kerstr )
;
int  c_blas_axpby_exec (c_blas_axpby_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_blas_axpby_scmc_set_parameter_y (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpby_scmc_set_parameter_x (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpby_scmc_set_parameter_a (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpby_scmc_set_parameter_b (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpby_scmc_set_parameter_y_cpu_core (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpby_scmc_set_parameter_numvec (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpby_scmc_set_parameter_XLEN (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpby_scmc_set_parameter_YLEN (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpby_scmc_set_parameter_ZLEN (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpby_scmc_set_parameter_ovlp (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpby_scmc_set_parameter_xblock (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpby_scmc_set_parameter_yblock (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpby_scmc_set_parameter_zblock (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpby_scmc_set_parameter_num_ele (c_blas_axpby_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpy_init (c_pscmc_env *  pe ,c_blas_axpy_struct *  kerstr )
;
void  c_blas_axpy_get_struct_len (size_t *  len )
;
int  c_blas_axpy_get_xlen ()
;
int  c_blas_axpy_get_num_compute_units (c_blas_axpy_struct *  kerstr )
;
int  c_blas_axpy_exec (c_blas_axpy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_blas_axpy_scmc_set_parameter_y (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpy_scmc_set_parameter_x (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpy_scmc_set_parameter_a (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpy_scmc_set_parameter_y_cpu_core (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpy_scmc_set_parameter_numvec (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpy_scmc_set_parameter_XLEN (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpy_scmc_set_parameter_YLEN (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpy_scmc_set_parameter_ZLEN (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpy_scmc_set_parameter_ovlp (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpy_scmc_set_parameter_xblock (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpy_scmc_set_parameter_yblock (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpy_scmc_set_parameter_zblock (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_axpy_scmc_set_parameter_num_ele (c_blas_axpy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisax_init (c_pscmc_env *  pe ,c_blas_yisax_struct *  kerstr )
;
void  c_blas_yisax_get_struct_len (size_t *  len )
;
int  c_blas_yisax_get_xlen ()
;
int  c_blas_yisax_get_num_compute_units (c_blas_yisax_struct *  kerstr )
;
int  c_blas_yisax_exec (c_blas_yisax_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_blas_yisax_scmc_set_parameter_y (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisax_scmc_set_parameter_x (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisax_scmc_set_parameter_a (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisax_scmc_set_parameter_y_cpu_core (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisax_scmc_set_parameter_numvec (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisax_scmc_set_parameter_XLEN (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisax_scmc_set_parameter_YLEN (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisax_scmc_set_parameter_ZLEN (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisax_scmc_set_parameter_ovlp (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisax_scmc_set_parameter_xblock (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisax_scmc_set_parameter_yblock (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisax_scmc_set_parameter_zblock (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisax_scmc_set_parameter_num_ele (c_blas_yisax_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_invy_init (c_pscmc_env *  pe ,c_blas_invy_struct *  kerstr )
;
void  c_blas_invy_get_struct_len (size_t *  len )
;
int  c_blas_invy_get_xlen ()
;
int  c_blas_invy_get_num_compute_units (c_blas_invy_struct *  kerstr )
;
int  c_blas_invy_exec (c_blas_invy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_blas_invy_scmc_set_parameter_y (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_invy_scmc_set_parameter_y_cpu_core (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_invy_scmc_set_parameter_numvec (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_invy_scmc_set_parameter_XLEN (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_invy_scmc_set_parameter_YLEN (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_invy_scmc_set_parameter_ZLEN (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_invy_scmc_set_parameter_ovlp (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_invy_scmc_set_parameter_xblock (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_invy_scmc_set_parameter_yblock (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_invy_scmc_set_parameter_zblock (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_invy_scmc_set_parameter_num_ele (c_blas_invy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_get_ITG_Potential_init (c_pscmc_env *  pe ,c_blas_get_ITG_Potential_struct *  kerstr )
;
void  c_blas_get_ITG_Potential_get_struct_len (size_t *  len )
;
int  c_blas_get_ITG_Potential_get_xlen ()
;
int  c_blas_get_ITG_Potential_get_num_compute_units (c_blas_get_ITG_Potential_struct *  kerstr )
;
int  c_blas_get_ITG_Potential_exec (c_blas_get_ITG_Potential_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_blas_get_ITG_Potential_scmc_set_parameter_y (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_get_ITG_Potential_scmc_set_parameter_x (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_get_ITG_Potential_scmc_set_parameter_u (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_get_ITG_Potential_scmc_set_parameter_minus_over_q_e (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_get_ITG_Potential_scmc_set_parameter_y_cpu_core (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_get_ITG_Potential_scmc_set_parameter_numvec (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_get_ITG_Potential_scmc_set_parameter_XLEN (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_get_ITG_Potential_scmc_set_parameter_YLEN (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_get_ITG_Potential_scmc_set_parameter_ZLEN (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_get_ITG_Potential_scmc_set_parameter_ovlp (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_get_ITG_Potential_scmc_set_parameter_xblock (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_get_ITG_Potential_scmc_set_parameter_yblock (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_get_ITG_Potential_scmc_set_parameter_zblock (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_get_ITG_Potential_scmc_set_parameter_num_ele (c_blas_get_ITG_Potential_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisconst_init (c_pscmc_env *  pe ,c_blas_yisconst_struct *  kerstr )
;
void  c_blas_yisconst_get_struct_len (size_t *  len )
;
int  c_blas_yisconst_get_xlen ()
;
int  c_blas_yisconst_get_num_compute_units (c_blas_yisconst_struct *  kerstr )
;
int  c_blas_yisconst_exec (c_blas_yisconst_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_blas_yisconst_scmc_set_parameter_y (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisconst_scmc_set_parameter_a (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisconst_scmc_set_parameter_y_cpu_core (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisconst_scmc_set_parameter_numvec (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisconst_scmc_set_parameter_XLEN (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisconst_scmc_set_parameter_YLEN (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisconst_scmc_set_parameter_ZLEN (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisconst_scmc_set_parameter_ovlp (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisconst_scmc_set_parameter_xblock (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisconst_scmc_set_parameter_yblock (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisconst_scmc_set_parameter_zblock (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yisconst_scmc_set_parameter_num_ele (c_blas_yisconst_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_init (c_pscmc_env *  pe ,c_blas_yiszero_struct *  kerstr )
;
void  c_blas_yiszero_get_struct_len (size_t *  len )
;
int  c_blas_yiszero_get_xlen ()
;
int  c_blas_yiszero_get_num_compute_units (c_blas_yiszero_struct *  kerstr )
;
int  c_blas_yiszero_exec (c_blas_yiszero_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_blas_yiszero_scmc_set_parameter_y (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_scmc_set_parameter_y_cpu_core (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_scmc_set_parameter_numvec (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_scmc_set_parameter_XLEN (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_scmc_set_parameter_YLEN (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_scmc_set_parameter_ZLEN (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_scmc_set_parameter_ovlp (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_scmc_set_parameter_xblock (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_scmc_set_parameter_yblock (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_scmc_set_parameter_zblock (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_scmc_set_parameter_num_ele (c_blas_yiszero_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_numele3_init (c_pscmc_env *  pe ,c_blas_mulxy_numele3_struct *  kerstr )
;
void  c_blas_mulxy_numele3_get_struct_len (size_t *  len )
;
int  c_blas_mulxy_numele3_get_xlen ()
;
int  c_blas_mulxy_numele3_get_num_compute_units (c_blas_mulxy_numele3_struct *  kerstr )
;
int  c_blas_mulxy_numele3_exec (c_blas_mulxy_numele3_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_blas_mulxy_numele3_scmc_set_parameter_y (c_blas_mulxy_numele3_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_numele3_scmc_set_parameter_x (c_blas_mulxy_numele3_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_numele3_scmc_set_parameter_y_cpu_core (c_blas_mulxy_numele3_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_numele3_scmc_set_parameter_numvec (c_blas_mulxy_numele3_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_numele3_scmc_set_parameter_XLEN (c_blas_mulxy_numele3_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_numele3_scmc_set_parameter_YLEN (c_blas_mulxy_numele3_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_numele3_scmc_set_parameter_ZLEN (c_blas_mulxy_numele3_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_numele3_scmc_set_parameter_ovlp (c_blas_mulxy_numele3_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_numele3_scmc_set_parameter_xblock (c_blas_mulxy_numele3_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_numele3_scmc_set_parameter_yblock (c_blas_mulxy_numele3_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_numele3_scmc_set_parameter_zblock (c_blas_mulxy_numele3_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_mulxy_numele3_scmc_set_parameter_num_ele (c_blas_mulxy_numele3_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_synced_init (c_pscmc_env *  pe ,c_blas_yiszero_synced_struct *  kerstr )
;
void  c_blas_yiszero_synced_get_struct_len (size_t *  len )
;
int  c_blas_yiszero_synced_get_xlen ()
;
int  c_blas_yiszero_synced_get_num_compute_units (c_blas_yiszero_synced_struct *  kerstr )
;
int  c_blas_yiszero_synced_exec (c_blas_yiszero_synced_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_blas_yiszero_synced_scmc_set_parameter_y (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_synced_scmc_set_parameter_y_cpu_core (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_synced_scmc_set_parameter_numvec (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_synced_scmc_set_parameter_XLEN (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_synced_scmc_set_parameter_YLEN (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_synced_scmc_set_parameter_ZLEN (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_synced_scmc_set_parameter_ovlp (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_synced_scmc_set_parameter_xblock (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_synced_scmc_set_parameter_yblock (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_synced_scmc_set_parameter_zblock (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_blas_yiszero_synced_scmc_set_parameter_num_ele (c_blas_yiszero_synced_struct *  kerstr ,c_pscmc_mem *  pm )
;
void  c_sort_one_grid_x_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_sort_one_grid_y_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_sort_one_grid_z_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_sort_one_grid_x_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_sort_one_grid_y_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_sort_one_grid_z_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_cu_swap_l_scmc_kernel (double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  cu_cache_length ,int  the_dir_num ,long  XYZLEN ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_cu_swap_r_scmc_kernel (double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  cu_cache_length ,int  the_dir_num ,long  XYZLEN ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  c_cu_swap_r_init (c_pscmc_env *  pe ,c_cu_swap_r_struct *  kerstr )
;
void  c_cu_swap_r_get_struct_len (size_t *  len )
;
int  c_cu_swap_r_get_xlen ()
;
int  c_cu_swap_r_get_num_compute_units (c_cu_swap_r_struct *  kerstr )
;
int  c_cu_swap_r_exec (c_cu_swap_r_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_cu_swap_r_scmc_set_parameter_cu_cache (c_cu_swap_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_cu_swap_r_scmc_set_parameter_cu_xyzw (c_cu_swap_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_cu_swap_r_scmc_set_parameter_adjoint_vec_pids (c_cu_swap_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_cu_swap_r_scmc_set_parameter_cu_cache_length (c_cu_swap_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_cu_swap_r_scmc_set_parameter_the_dir_num (c_cu_swap_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_cu_swap_r_scmc_set_parameter_XYZLEN (c_cu_swap_r_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_cu_swap_l_init (c_pscmc_env *  pe ,c_cu_swap_l_struct *  kerstr )
;
void  c_cu_swap_l_get_struct_len (size_t *  len )
;
int  c_cu_swap_l_get_xlen ()
;
int  c_cu_swap_l_get_num_compute_units (c_cu_swap_l_struct *  kerstr )
;
int  c_cu_swap_l_exec (c_cu_swap_l_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_cu_swap_l_scmc_set_parameter_cu_cache (c_cu_swap_l_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_cu_swap_l_scmc_set_parameter_cu_xyzw (c_cu_swap_l_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_cu_swap_l_scmc_set_parameter_adjoint_vec_pids (c_cu_swap_l_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_cu_swap_l_scmc_set_parameter_cu_cache_length (c_cu_swap_l_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_cu_swap_l_scmc_set_parameter_the_dir_num (c_cu_swap_l_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_cu_swap_l_scmc_set_parameter_XYZLEN (c_cu_swap_l_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_vlo_init (c_pscmc_env *  pe ,c_sort_one_grid_z_vlo_struct *  kerstr )
;
void  c_sort_one_grid_z_vlo_get_struct_len (size_t *  len )
;
int  c_sort_one_grid_z_vlo_get_xlen ()
;
int  c_sort_one_grid_z_vlo_get_num_compute_units (c_sort_one_grid_z_vlo_struct *  kerstr )
;
int  c_sort_one_grid_z_vlo_exec (c_sort_one_grid_z_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_sort_one_grid_z_vlo_scmc_set_parameter_inoutput (c_sort_one_grid_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_vlo_scmc_set_parameter_xyzw (c_sort_one_grid_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_vlo_scmc_set_parameter_cu_cache (c_sort_one_grid_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_vlo_scmc_set_parameter_cu_xyzw (c_sort_one_grid_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_vlo_scmc_set_parameter_adjoint_vec_pids (c_sort_one_grid_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_vlo_scmc_set_parameter_XLEN (c_sort_one_grid_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_vlo_scmc_set_parameter_YLEN (c_sort_one_grid_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_vlo_scmc_set_parameter_ZLEN (c_sort_one_grid_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_vlo_scmc_set_parameter_ovlp (c_sort_one_grid_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_vlo_scmc_set_parameter_numvec (c_sort_one_grid_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_vlo_scmc_set_parameter_grid_cache_len (c_sort_one_grid_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_vlo_scmc_set_parameter_cu_cache_length (c_sort_one_grid_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_vlo_init (c_pscmc_env *  pe ,c_sort_one_grid_y_vlo_struct *  kerstr )
;
void  c_sort_one_grid_y_vlo_get_struct_len (size_t *  len )
;
int  c_sort_one_grid_y_vlo_get_xlen ()
;
int  c_sort_one_grid_y_vlo_get_num_compute_units (c_sort_one_grid_y_vlo_struct *  kerstr )
;
int  c_sort_one_grid_y_vlo_exec (c_sort_one_grid_y_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_sort_one_grid_y_vlo_scmc_set_parameter_inoutput (c_sort_one_grid_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_vlo_scmc_set_parameter_xyzw (c_sort_one_grid_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_vlo_scmc_set_parameter_cu_cache (c_sort_one_grid_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_vlo_scmc_set_parameter_cu_xyzw (c_sort_one_grid_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_vlo_scmc_set_parameter_adjoint_vec_pids (c_sort_one_grid_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_vlo_scmc_set_parameter_XLEN (c_sort_one_grid_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_vlo_scmc_set_parameter_YLEN (c_sort_one_grid_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_vlo_scmc_set_parameter_ZLEN (c_sort_one_grid_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_vlo_scmc_set_parameter_ovlp (c_sort_one_grid_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_vlo_scmc_set_parameter_numvec (c_sort_one_grid_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_vlo_scmc_set_parameter_grid_cache_len (c_sort_one_grid_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_vlo_scmc_set_parameter_cu_cache_length (c_sort_one_grid_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_vlo_init (c_pscmc_env *  pe ,c_sort_one_grid_x_vlo_struct *  kerstr )
;
void  c_sort_one_grid_x_vlo_get_struct_len (size_t *  len )
;
int  c_sort_one_grid_x_vlo_get_xlen ()
;
int  c_sort_one_grid_x_vlo_get_num_compute_units (c_sort_one_grid_x_vlo_struct *  kerstr )
;
int  c_sort_one_grid_x_vlo_exec (c_sort_one_grid_x_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_sort_one_grid_x_vlo_scmc_set_parameter_inoutput (c_sort_one_grid_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_vlo_scmc_set_parameter_xyzw (c_sort_one_grid_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_vlo_scmc_set_parameter_cu_cache (c_sort_one_grid_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_vlo_scmc_set_parameter_cu_xyzw (c_sort_one_grid_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_vlo_scmc_set_parameter_adjoint_vec_pids (c_sort_one_grid_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_vlo_scmc_set_parameter_XLEN (c_sort_one_grid_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_vlo_scmc_set_parameter_YLEN (c_sort_one_grid_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_vlo_scmc_set_parameter_ZLEN (c_sort_one_grid_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_vlo_scmc_set_parameter_ovlp (c_sort_one_grid_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_vlo_scmc_set_parameter_numvec (c_sort_one_grid_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_vlo_scmc_set_parameter_grid_cache_len (c_sort_one_grid_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_vlo_scmc_set_parameter_cu_cache_length (c_sort_one_grid_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_init (c_pscmc_env *  pe ,c_sort_one_grid_z_struct *  kerstr )
;
void  c_sort_one_grid_z_get_struct_len (size_t *  len )
;
int  c_sort_one_grid_z_get_xlen ()
;
int  c_sort_one_grid_z_get_num_compute_units (c_sort_one_grid_z_struct *  kerstr )
;
int  c_sort_one_grid_z_exec (c_sort_one_grid_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_sort_one_grid_z_scmc_set_parameter_inoutput (c_sort_one_grid_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_scmc_set_parameter_xyzw (c_sort_one_grid_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_scmc_set_parameter_cu_cache (c_sort_one_grid_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_scmc_set_parameter_cu_xyzw (c_sort_one_grid_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_scmc_set_parameter_adjoint_vec_pids (c_sort_one_grid_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_scmc_set_parameter_XLEN (c_sort_one_grid_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_scmc_set_parameter_YLEN (c_sort_one_grid_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_scmc_set_parameter_ZLEN (c_sort_one_grid_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_scmc_set_parameter_ovlp (c_sort_one_grid_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_scmc_set_parameter_numvec (c_sort_one_grid_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_scmc_set_parameter_grid_cache_len (c_sort_one_grid_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_z_scmc_set_parameter_cu_cache_length (c_sort_one_grid_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_init (c_pscmc_env *  pe ,c_sort_one_grid_y_struct *  kerstr )
;
void  c_sort_one_grid_y_get_struct_len (size_t *  len )
;
int  c_sort_one_grid_y_get_xlen ()
;
int  c_sort_one_grid_y_get_num_compute_units (c_sort_one_grid_y_struct *  kerstr )
;
int  c_sort_one_grid_y_exec (c_sort_one_grid_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_sort_one_grid_y_scmc_set_parameter_inoutput (c_sort_one_grid_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_scmc_set_parameter_xyzw (c_sort_one_grid_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_scmc_set_parameter_cu_cache (c_sort_one_grid_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_scmc_set_parameter_cu_xyzw (c_sort_one_grid_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_scmc_set_parameter_adjoint_vec_pids (c_sort_one_grid_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_scmc_set_parameter_XLEN (c_sort_one_grid_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_scmc_set_parameter_YLEN (c_sort_one_grid_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_scmc_set_parameter_ZLEN (c_sort_one_grid_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_scmc_set_parameter_ovlp (c_sort_one_grid_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_scmc_set_parameter_numvec (c_sort_one_grid_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_scmc_set_parameter_grid_cache_len (c_sort_one_grid_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_y_scmc_set_parameter_cu_cache_length (c_sort_one_grid_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_init (c_pscmc_env *  pe ,c_sort_one_grid_x_struct *  kerstr )
;
void  c_sort_one_grid_x_get_struct_len (size_t *  len )
;
int  c_sort_one_grid_x_get_xlen ()
;
int  c_sort_one_grid_x_get_num_compute_units (c_sort_one_grid_x_struct *  kerstr )
;
int  c_sort_one_grid_x_exec (c_sort_one_grid_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_sort_one_grid_x_scmc_set_parameter_inoutput (c_sort_one_grid_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_scmc_set_parameter_xyzw (c_sort_one_grid_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_scmc_set_parameter_cu_cache (c_sort_one_grid_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_scmc_set_parameter_cu_xyzw (c_sort_one_grid_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_scmc_set_parameter_adjoint_vec_pids (c_sort_one_grid_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_scmc_set_parameter_XLEN (c_sort_one_grid_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_scmc_set_parameter_YLEN (c_sort_one_grid_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_scmc_set_parameter_ZLEN (c_sort_one_grid_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_scmc_set_parameter_ovlp (c_sort_one_grid_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_scmc_set_parameter_numvec (c_sort_one_grid_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_scmc_set_parameter_grid_cache_len (c_sort_one_grid_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_sort_one_grid_x_scmc_set_parameter_cu_cache_length (c_sort_one_grid_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_is_in (long  x ,long  xl ,long  xr )
;
void  c_move_back_kernel_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long  XLEN ,long  YLEN ,long  ZLEN ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  c_move_back_kernel_init (c_pscmc_env *  pe ,c_move_back_kernel_struct *  kerstr )
;
void  c_move_back_kernel_get_struct_len (size_t *  len )
;
int  c_move_back_kernel_get_xlen ()
;
int  c_move_back_kernel_get_num_compute_units (c_move_back_kernel_struct *  kerstr )
;
int  c_move_back_kernel_exec (c_move_back_kernel_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_move_back_kernel_scmc_set_parameter_inoutput (c_move_back_kernel_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_move_back_kernel_scmc_set_parameter_xyzw (c_move_back_kernel_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_move_back_kernel_scmc_set_parameter_cu_cache (c_move_back_kernel_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_move_back_kernel_scmc_set_parameter_cu_xyzw (c_move_back_kernel_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_move_back_kernel_scmc_set_parameter_XLEN (c_move_back_kernel_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_move_back_kernel_scmc_set_parameter_YLEN (c_move_back_kernel_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_move_back_kernel_scmc_set_parameter_ZLEN (c_move_back_kernel_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_move_back_kernel_scmc_set_parameter_grid_cache_len (c_move_back_kernel_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_move_back_kernel_scmc_set_parameter_cu_cache_length (c_move_back_kernel_struct *  kerstr ,c_pscmc_mem *  pm )
;
double  c_rand01_k (double  x0 ,double  x1 )
;
double  c_maxwell_dist_k (double  ava ,double  sig )
;
void  c_split_pass_x_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_x_nopush_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_x_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_x_vlo_nopush_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_x_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_x_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_x_vlo_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_x_vlo_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_y_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_y_nopush_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_y_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_y_vlo_nopush_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_y_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_y_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_y_vlo_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_y_vlo_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_z_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_z_nopush_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_z_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_z_vlo_nopush_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_z_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_z_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_z_vlo_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_z_vlo_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_E_particle_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_split_pass_E_particle_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_boris_yee_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass0 ,double  Charge0 ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_krook_collision_remove_small_speed_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  mu_freq ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_krook_collision_test_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  mu_freq ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_calculate_rho_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_dump_ene_num_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  c_dump_ene_num_init (c_pscmc_env *  pe ,c_dump_ene_num_struct *  kerstr )
;
void  c_dump_ene_num_get_struct_len (size_t *  len )
;
int  c_dump_ene_num_get_xlen ()
;
int  c_dump_ene_num_get_num_compute_units (c_dump_ene_num_struct *  kerstr )
;
int  c_dump_ene_num_exec (c_dump_ene_num_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_dump_ene_num_scmc_set_parameter_inoutput (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_xyzw (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_cu_cache (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_cu_xyzw (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_fieldE (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_fieldB (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_FoutJ (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_FoutEN (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_XLEN (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_YLEN (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_ZLEN (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_ovlp (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_numvec (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_num_ele (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_grid_cache_len (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_cu_cache_length (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_Mass (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_Charge (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_SPEC (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_NUM_SPEC (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_DELTA_X (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_DELTA_Y (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_DELTA_Z (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dump_ene_num_scmc_set_parameter_Deltat (c_dump_ene_num_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_init (c_pscmc_env *  pe ,c_calculate_rho_struct *  kerstr )
;
void  c_calculate_rho_get_struct_len (size_t *  len )
;
int  c_calculate_rho_get_xlen ()
;
int  c_calculate_rho_get_num_compute_units (c_calculate_rho_struct *  kerstr )
;
int  c_calculate_rho_exec (c_calculate_rho_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_calculate_rho_scmc_set_parameter_inoutput (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_xyzw (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_cu_cache (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_cu_xyzw (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_fieldE (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_fieldB (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_FoutJ (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_FoutEN (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_XLEN (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_YLEN (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_ZLEN (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_ovlp (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_numvec (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_num_ele (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_grid_cache_len (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_cu_cache_length (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_Mass (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_Charge (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_SPEC (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_NUM_SPEC (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_DELTA_X (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_DELTA_Y (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_DELTA_Z (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_calculate_rho_scmc_set_parameter_Deltat (c_calculate_rho_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_test_init (c_pscmc_env *  pe ,c_krook_collision_test_struct *  kerstr )
;
void  c_krook_collision_test_get_struct_len (size_t *  len )
;
int  c_krook_collision_test_get_xlen ()
;
int  c_krook_collision_test_get_num_compute_units (c_krook_collision_test_struct *  kerstr )
;
int  c_krook_collision_test_exec (c_krook_collision_test_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_krook_collision_test_scmc_set_parameter_inoutput (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_test_scmc_set_parameter_xyzw (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_test_scmc_set_parameter_cu_cache (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_test_scmc_set_parameter_cu_xyzw (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_test_scmc_set_parameter_fieldE (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_test_scmc_set_parameter_fieldB (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_test_scmc_set_parameter_FoutJ (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_test_scmc_set_parameter_XLEN (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_test_scmc_set_parameter_YLEN (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_test_scmc_set_parameter_ZLEN (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_test_scmc_set_parameter_ovlp (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_test_scmc_set_parameter_numvec (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_test_scmc_set_parameter_num_ele (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_test_scmc_set_parameter_grid_cache_len (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_test_scmc_set_parameter_cu_cache_length (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_test_scmc_set_parameter_Mass0 (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_test_scmc_set_parameter_Charge0 (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_test_scmc_set_parameter_Deltat (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_test_scmc_set_parameter_mu_freq (c_krook_collision_test_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_remove_small_speed_init (c_pscmc_env *  pe ,c_krook_collision_remove_small_speed_struct *  kerstr )
;
void  c_krook_collision_remove_small_speed_get_struct_len (size_t *  len )
;
int  c_krook_collision_remove_small_speed_get_xlen ()
;
int  c_krook_collision_remove_small_speed_get_num_compute_units (c_krook_collision_remove_small_speed_struct *  kerstr )
;
int  c_krook_collision_remove_small_speed_exec (c_krook_collision_remove_small_speed_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_krook_collision_remove_small_speed_scmc_set_parameter_inoutput (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_remove_small_speed_scmc_set_parameter_xyzw (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_remove_small_speed_scmc_set_parameter_cu_cache (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_remove_small_speed_scmc_set_parameter_cu_xyzw (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_remove_small_speed_scmc_set_parameter_fieldE (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_remove_small_speed_scmc_set_parameter_fieldB (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_remove_small_speed_scmc_set_parameter_FoutJ (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_remove_small_speed_scmc_set_parameter_XLEN (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_remove_small_speed_scmc_set_parameter_YLEN (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_remove_small_speed_scmc_set_parameter_ZLEN (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_remove_small_speed_scmc_set_parameter_ovlp (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_remove_small_speed_scmc_set_parameter_numvec (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_remove_small_speed_scmc_set_parameter_num_ele (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_remove_small_speed_scmc_set_parameter_grid_cache_len (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_remove_small_speed_scmc_set_parameter_cu_cache_length (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_remove_small_speed_scmc_set_parameter_Mass0 (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_remove_small_speed_scmc_set_parameter_Charge0 (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_remove_small_speed_scmc_set_parameter_Deltat (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_krook_collision_remove_small_speed_scmc_set_parameter_mu_freq (c_krook_collision_remove_small_speed_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_boris_yee_init (c_pscmc_env *  pe ,c_boris_yee_struct *  kerstr )
;
void  c_boris_yee_get_struct_len (size_t *  len )
;
int  c_boris_yee_get_xlen ()
;
int  c_boris_yee_get_num_compute_units (c_boris_yee_struct *  kerstr )
;
int  c_boris_yee_exec (c_boris_yee_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_boris_yee_scmc_set_parameter_inoutput (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_boris_yee_scmc_set_parameter_xyzw (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_boris_yee_scmc_set_parameter_cu_cache (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_boris_yee_scmc_set_parameter_cu_xyzw (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_boris_yee_scmc_set_parameter_fieldE (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_boris_yee_scmc_set_parameter_fieldB (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_boris_yee_scmc_set_parameter_FoutJ (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_boris_yee_scmc_set_parameter_XLEN (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_boris_yee_scmc_set_parameter_YLEN (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_boris_yee_scmc_set_parameter_ZLEN (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_boris_yee_scmc_set_parameter_ovlp (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_boris_yee_scmc_set_parameter_numvec (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_boris_yee_scmc_set_parameter_num_ele (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_boris_yee_scmc_set_parameter_grid_cache_len (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_boris_yee_scmc_set_parameter_cu_cache_length (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_boris_yee_scmc_set_parameter_Mass0 (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_boris_yee_scmc_set_parameter_Charge0 (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_boris_yee_scmc_set_parameter_Deltat (c_boris_yee_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_init (c_pscmc_env *  pe ,c_split_pass_E_particle_vlo_struct *  kerstr )
;
void  c_split_pass_E_particle_vlo_get_struct_len (size_t *  len )
;
int  c_split_pass_E_particle_vlo_get_xlen ()
;
int  c_split_pass_E_particle_vlo_get_num_compute_units (c_split_pass_E_particle_vlo_struct *  kerstr )
;
int  c_split_pass_E_particle_vlo_exec (c_split_pass_E_particle_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_inoutput (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_xyzw (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_cu_cache (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_cu_xyzw (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_fieldE (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_fieldB (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_FoutJ (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_FoutEN (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_XLEN (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_YLEN (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_ZLEN (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_ovlp (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_numvec (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_num_ele (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_grid_cache_len (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_cu_cache_length (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_Mass (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_Charge (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_SPEC (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_NUM_SPEC (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_DELTA_X (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_DELTA_Y (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_DELTA_Z (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_vlo_scmc_set_parameter_Deltat (c_split_pass_E_particle_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_init (c_pscmc_env *  pe ,c_split_pass_E_particle_struct *  kerstr )
;
void  c_split_pass_E_particle_get_struct_len (size_t *  len )
;
int  c_split_pass_E_particle_get_xlen ()
;
int  c_split_pass_E_particle_get_num_compute_units (c_split_pass_E_particle_struct *  kerstr )
;
int  c_split_pass_E_particle_exec (c_split_pass_E_particle_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_E_particle_scmc_set_parameter_inoutput (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_xyzw (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_cu_cache (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_cu_xyzw (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_fieldE (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_fieldB (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_FoutJ (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_FoutEN (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_XLEN (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_YLEN (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_ZLEN (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_ovlp (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_numvec (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_num_ele (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_grid_cache_len (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_cu_cache_length (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_Mass (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_Charge (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_SPEC (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_NUM_SPEC (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_DELTA_X (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_DELTA_Y (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_DELTA_Z (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_E_particle_scmc_set_parameter_Deltat (c_split_pass_E_particle_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_init (c_pscmc_env *  pe ,c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr )
;
void  c_split_pass_z_vlo_sg2_nopush_small_grids_get_struct_len (size_t *  len )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_get_xlen ()
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_get_num_compute_units (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_exec (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_inoutput (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_xyzw (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_cache (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_fieldE (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_fieldB (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_FoutEN (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_XLEN (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_YLEN (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_ZLEN (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_ovlp (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_numvec (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_num_ele (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_Mass (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_Charge (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_SPEC (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_Deltat (c_split_pass_z_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_init (c_pscmc_env *  pe ,c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr )
;
void  c_split_pass_z_vlo_sg2_small_grids_get_struct_len (size_t *  len )
;
int  c_split_pass_z_vlo_sg2_small_grids_get_xlen ()
;
int  c_split_pass_z_vlo_sg2_small_grids_get_num_compute_units (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr )
;
int  c_split_pass_z_vlo_sg2_small_grids_exec (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_inoutput (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_xyzw (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_cu_cache (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_fieldE (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_fieldB (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_FoutEN (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_XLEN (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_YLEN (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_ZLEN (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_ovlp (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_numvec (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_num_ele (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_Mass (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_Charge (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_SPEC (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_Deltat (c_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_init (c_pscmc_env *  pe ,c_split_pass_z_vlo_small_grids_struct *  kerstr )
;
void  c_split_pass_z_vlo_small_grids_get_struct_len (size_t *  len )
;
int  c_split_pass_z_vlo_small_grids_get_xlen ()
;
int  c_split_pass_z_vlo_small_grids_get_num_compute_units (c_split_pass_z_vlo_small_grids_struct *  kerstr )
;
int  c_split_pass_z_vlo_small_grids_exec (c_split_pass_z_vlo_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_inoutput (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_xyzw (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_cu_cache (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_fieldE (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_fieldB (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_FoutEN (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_XLEN (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_YLEN (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_ZLEN (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_ovlp (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_numvec (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_num_ele (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_Mass (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_Charge (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_SPEC (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_small_grids_scmc_set_parameter_Deltat (c_split_pass_z_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_init (c_pscmc_env *  pe ,c_split_pass_z_sg2_small_grids_struct *  kerstr )
;
void  c_split_pass_z_sg2_small_grids_get_struct_len (size_t *  len )
;
int  c_split_pass_z_sg2_small_grids_get_xlen ()
;
int  c_split_pass_z_sg2_small_grids_get_num_compute_units (c_split_pass_z_sg2_small_grids_struct *  kerstr )
;
int  c_split_pass_z_sg2_small_grids_exec (c_split_pass_z_sg2_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_inoutput (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_xyzw (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_cu_cache (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_fieldE (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_fieldB (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_FoutEN (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_XLEN (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_YLEN (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_ZLEN (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_ovlp (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_numvec (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_num_ele (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_Mass (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_Charge (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_SPEC (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_sg2_small_grids_scmc_set_parameter_Deltat (c_split_pass_z_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_init (c_pscmc_env *  pe ,c_split_pass_z_small_grids_struct *  kerstr )
;
void  c_split_pass_z_small_grids_get_struct_len (size_t *  len )
;
int  c_split_pass_z_small_grids_get_xlen ()
;
int  c_split_pass_z_small_grids_get_num_compute_units (c_split_pass_z_small_grids_struct *  kerstr )
;
int  c_split_pass_z_small_grids_exec (c_split_pass_z_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_inoutput (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_xyzw (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_cu_cache (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_fieldE (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_fieldB (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_FoutEN (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_XLEN (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_YLEN (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_ZLEN (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_ovlp (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_numvec (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_num_ele (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_Mass (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_Charge (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_SPEC (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_small_grids_scmc_set_parameter_Deltat (c_split_pass_z_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_init (c_pscmc_env *  pe ,c_split_pass_z_vlo_nopush_struct *  kerstr )
;
void  c_split_pass_z_vlo_nopush_get_struct_len (size_t *  len )
;
int  c_split_pass_z_vlo_nopush_get_xlen ()
;
int  c_split_pass_z_vlo_nopush_get_num_compute_units (c_split_pass_z_vlo_nopush_struct *  kerstr )
;
int  c_split_pass_z_vlo_nopush_exec (c_split_pass_z_vlo_nopush_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_inoutput (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_xyzw (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_cu_cache (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_cu_xyzw (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_fieldE (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_fieldB (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_FoutJ (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_FoutEN (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_XLEN (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_YLEN (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_ZLEN (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_ovlp (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_numvec (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_num_ele (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_grid_cache_len (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_cu_cache_length (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_Mass (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_Charge (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_SPEC (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_NUM_SPEC (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_DELTA_X (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_DELTA_Y (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_DELTA_Z (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_nopush_scmc_set_parameter_Deltat (c_split_pass_z_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_init (c_pscmc_env *  pe ,c_split_pass_z_vlo_struct *  kerstr )
;
void  c_split_pass_z_vlo_get_struct_len (size_t *  len )
;
int  c_split_pass_z_vlo_get_xlen ()
;
int  c_split_pass_z_vlo_get_num_compute_units (c_split_pass_z_vlo_struct *  kerstr )
;
int  c_split_pass_z_vlo_exec (c_split_pass_z_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_z_vlo_scmc_set_parameter_inoutput (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_xyzw (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_cu_cache (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_cu_xyzw (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_fieldE (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_fieldB (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_FoutJ (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_FoutEN (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_XLEN (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_YLEN (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_ZLEN (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_ovlp (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_numvec (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_num_ele (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_grid_cache_len (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_cu_cache_length (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_Mass (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_Charge (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_SPEC (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_NUM_SPEC (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_DELTA_X (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_DELTA_Y (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_DELTA_Z (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_vlo_scmc_set_parameter_Deltat (c_split_pass_z_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_init (c_pscmc_env *  pe ,c_split_pass_z_nopush_struct *  kerstr )
;
void  c_split_pass_z_nopush_get_struct_len (size_t *  len )
;
int  c_split_pass_z_nopush_get_xlen ()
;
int  c_split_pass_z_nopush_get_num_compute_units (c_split_pass_z_nopush_struct *  kerstr )
;
int  c_split_pass_z_nopush_exec (c_split_pass_z_nopush_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_z_nopush_scmc_set_parameter_inoutput (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_xyzw (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_cu_cache (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_cu_xyzw (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_fieldE (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_fieldB (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_FoutJ (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_FoutEN (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_XLEN (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_YLEN (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_ZLEN (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_ovlp (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_numvec (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_num_ele (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_grid_cache_len (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_cu_cache_length (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_Mass (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_Charge (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_SPEC (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_NUM_SPEC (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_DELTA_X (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_DELTA_Y (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_DELTA_Z (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_nopush_scmc_set_parameter_Deltat (c_split_pass_z_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_init (c_pscmc_env *  pe ,c_split_pass_z_struct *  kerstr )
;
void  c_split_pass_z_get_struct_len (size_t *  len )
;
int  c_split_pass_z_get_xlen ()
;
int  c_split_pass_z_get_num_compute_units (c_split_pass_z_struct *  kerstr )
;
int  c_split_pass_z_exec (c_split_pass_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_z_scmc_set_parameter_inoutput (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_xyzw (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_cu_cache (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_cu_xyzw (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_fieldE (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_fieldB (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_FoutJ (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_FoutEN (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_XLEN (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_YLEN (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_ZLEN (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_ovlp (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_numvec (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_num_ele (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_grid_cache_len (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_cu_cache_length (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_Mass (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_Charge (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_SPEC (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_NUM_SPEC (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_DELTA_X (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_DELTA_Y (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_DELTA_Z (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_z_scmc_set_parameter_Deltat (c_split_pass_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_init (c_pscmc_env *  pe ,c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr )
;
void  c_split_pass_y_vlo_sg2_nopush_small_grids_get_struct_len (size_t *  len )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_get_xlen ()
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_get_num_compute_units (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_exec (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_inoutput (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_xyzw (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_cache (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_fieldE (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_fieldB (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_FoutEN (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_XLEN (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_YLEN (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_ZLEN (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_ovlp (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_numvec (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_num_ele (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_Mass (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_Charge (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_SPEC (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_Deltat (c_split_pass_y_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_init (c_pscmc_env *  pe ,c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr )
;
void  c_split_pass_y_vlo_sg2_small_grids_get_struct_len (size_t *  len )
;
int  c_split_pass_y_vlo_sg2_small_grids_get_xlen ()
;
int  c_split_pass_y_vlo_sg2_small_grids_get_num_compute_units (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr )
;
int  c_split_pass_y_vlo_sg2_small_grids_exec (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_inoutput (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_xyzw (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_cu_cache (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_fieldE (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_fieldB (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_FoutEN (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_XLEN (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_YLEN (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_ZLEN (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_ovlp (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_numvec (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_num_ele (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_Mass (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_Charge (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_SPEC (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_Deltat (c_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_init (c_pscmc_env *  pe ,c_split_pass_y_vlo_small_grids_struct *  kerstr )
;
void  c_split_pass_y_vlo_small_grids_get_struct_len (size_t *  len )
;
int  c_split_pass_y_vlo_small_grids_get_xlen ()
;
int  c_split_pass_y_vlo_small_grids_get_num_compute_units (c_split_pass_y_vlo_small_grids_struct *  kerstr )
;
int  c_split_pass_y_vlo_small_grids_exec (c_split_pass_y_vlo_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_inoutput (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_xyzw (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_cu_cache (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_fieldE (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_fieldB (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_FoutEN (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_XLEN (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_YLEN (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_ZLEN (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_ovlp (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_numvec (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_num_ele (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_Mass (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_Charge (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_SPEC (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_small_grids_scmc_set_parameter_Deltat (c_split_pass_y_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_init (c_pscmc_env *  pe ,c_split_pass_y_sg2_small_grids_struct *  kerstr )
;
void  c_split_pass_y_sg2_small_grids_get_struct_len (size_t *  len )
;
int  c_split_pass_y_sg2_small_grids_get_xlen ()
;
int  c_split_pass_y_sg2_small_grids_get_num_compute_units (c_split_pass_y_sg2_small_grids_struct *  kerstr )
;
int  c_split_pass_y_sg2_small_grids_exec (c_split_pass_y_sg2_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_inoutput (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_xyzw (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_cu_cache (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_fieldE (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_fieldB (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_FoutEN (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_XLEN (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_YLEN (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_ZLEN (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_ovlp (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_numvec (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_num_ele (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_Mass (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_Charge (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_SPEC (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_sg2_small_grids_scmc_set_parameter_Deltat (c_split_pass_y_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_init (c_pscmc_env *  pe ,c_split_pass_y_small_grids_struct *  kerstr )
;
void  c_split_pass_y_small_grids_get_struct_len (size_t *  len )
;
int  c_split_pass_y_small_grids_get_xlen ()
;
int  c_split_pass_y_small_grids_get_num_compute_units (c_split_pass_y_small_grids_struct *  kerstr )
;
int  c_split_pass_y_small_grids_exec (c_split_pass_y_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_inoutput (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_xyzw (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_cu_cache (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_fieldE (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_fieldB (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_FoutEN (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_XLEN (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_YLEN (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_ZLEN (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_ovlp (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_numvec (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_num_ele (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_Mass (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_Charge (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_SPEC (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_small_grids_scmc_set_parameter_Deltat (c_split_pass_y_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_init (c_pscmc_env *  pe ,c_split_pass_y_vlo_nopush_struct *  kerstr )
;
void  c_split_pass_y_vlo_nopush_get_struct_len (size_t *  len )
;
int  c_split_pass_y_vlo_nopush_get_xlen ()
;
int  c_split_pass_y_vlo_nopush_get_num_compute_units (c_split_pass_y_vlo_nopush_struct *  kerstr )
;
int  c_split_pass_y_vlo_nopush_exec (c_split_pass_y_vlo_nopush_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_inoutput (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_xyzw (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_cu_cache (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_cu_xyzw (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_fieldE (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_fieldB (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_FoutJ (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_FoutEN (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_XLEN (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_YLEN (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_ZLEN (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_ovlp (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_numvec (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_num_ele (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_grid_cache_len (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_cu_cache_length (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_Mass (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_Charge (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_SPEC (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_NUM_SPEC (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_DELTA_X (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_DELTA_Y (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_DELTA_Z (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_nopush_scmc_set_parameter_Deltat (c_split_pass_y_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_init (c_pscmc_env *  pe ,c_split_pass_y_vlo_struct *  kerstr )
;
void  c_split_pass_y_vlo_get_struct_len (size_t *  len )
;
int  c_split_pass_y_vlo_get_xlen ()
;
int  c_split_pass_y_vlo_get_num_compute_units (c_split_pass_y_vlo_struct *  kerstr )
;
int  c_split_pass_y_vlo_exec (c_split_pass_y_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_y_vlo_scmc_set_parameter_inoutput (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_xyzw (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_cu_cache (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_cu_xyzw (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_fieldE (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_fieldB (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_FoutJ (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_FoutEN (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_XLEN (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_YLEN (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_ZLEN (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_ovlp (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_numvec (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_num_ele (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_grid_cache_len (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_cu_cache_length (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_Mass (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_Charge (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_SPEC (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_NUM_SPEC (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_DELTA_X (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_DELTA_Y (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_DELTA_Z (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_vlo_scmc_set_parameter_Deltat (c_split_pass_y_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_init (c_pscmc_env *  pe ,c_split_pass_y_nopush_struct *  kerstr )
;
void  c_split_pass_y_nopush_get_struct_len (size_t *  len )
;
int  c_split_pass_y_nopush_get_xlen ()
;
int  c_split_pass_y_nopush_get_num_compute_units (c_split_pass_y_nopush_struct *  kerstr )
;
int  c_split_pass_y_nopush_exec (c_split_pass_y_nopush_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_y_nopush_scmc_set_parameter_inoutput (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_xyzw (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_cu_cache (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_cu_xyzw (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_fieldE (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_fieldB (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_FoutJ (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_FoutEN (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_XLEN (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_YLEN (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_ZLEN (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_ovlp (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_numvec (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_num_ele (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_grid_cache_len (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_cu_cache_length (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_Mass (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_Charge (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_SPEC (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_NUM_SPEC (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_DELTA_X (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_DELTA_Y (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_DELTA_Z (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_nopush_scmc_set_parameter_Deltat (c_split_pass_y_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_init (c_pscmc_env *  pe ,c_split_pass_y_struct *  kerstr )
;
void  c_split_pass_y_get_struct_len (size_t *  len )
;
int  c_split_pass_y_get_xlen ()
;
int  c_split_pass_y_get_num_compute_units (c_split_pass_y_struct *  kerstr )
;
int  c_split_pass_y_exec (c_split_pass_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_y_scmc_set_parameter_inoutput (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_xyzw (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_cu_cache (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_cu_xyzw (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_fieldE (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_fieldB (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_FoutJ (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_FoutEN (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_XLEN (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_YLEN (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_ZLEN (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_ovlp (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_numvec (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_num_ele (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_grid_cache_len (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_cu_cache_length (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_Mass (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_Charge (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_SPEC (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_NUM_SPEC (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_DELTA_X (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_DELTA_Y (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_DELTA_Z (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_y_scmc_set_parameter_Deltat (c_split_pass_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_init (c_pscmc_env *  pe ,c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr )
;
void  c_split_pass_x_vlo_sg2_nopush_small_grids_get_struct_len (size_t *  len )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_get_xlen ()
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_get_num_compute_units (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_exec (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_inoutput (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_xyzw (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_cache (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_fieldE (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_fieldB (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_FoutEN (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_XLEN (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_YLEN (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_ZLEN (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_ovlp (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_numvec (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_num_ele (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_Mass (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_Charge (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_SPEC (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_Deltat (c_split_pass_x_vlo_sg2_nopush_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_init (c_pscmc_env *  pe ,c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr )
;
void  c_split_pass_x_vlo_sg2_small_grids_get_struct_len (size_t *  len )
;
int  c_split_pass_x_vlo_sg2_small_grids_get_xlen ()
;
int  c_split_pass_x_vlo_sg2_small_grids_get_num_compute_units (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr )
;
int  c_split_pass_x_vlo_sg2_small_grids_exec (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_inoutput (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_xyzw (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_cu_cache (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_fieldE (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_fieldB (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_FoutEN (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_XLEN (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_YLEN (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_ZLEN (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_ovlp (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_numvec (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_num_ele (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_Mass (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_Charge (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_SPEC (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_Deltat (c_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_init (c_pscmc_env *  pe ,c_split_pass_x_vlo_small_grids_struct *  kerstr )
;
void  c_split_pass_x_vlo_small_grids_get_struct_len (size_t *  len )
;
int  c_split_pass_x_vlo_small_grids_get_xlen ()
;
int  c_split_pass_x_vlo_small_grids_get_num_compute_units (c_split_pass_x_vlo_small_grids_struct *  kerstr )
;
int  c_split_pass_x_vlo_small_grids_exec (c_split_pass_x_vlo_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_inoutput (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_xyzw (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_cu_cache (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_fieldE (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_fieldB (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_FoutEN (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_XLEN (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_YLEN (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_ZLEN (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_ovlp (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_numvec (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_num_ele (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_Mass (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_Charge (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_SPEC (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_small_grids_scmc_set_parameter_Deltat (c_split_pass_x_vlo_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_init (c_pscmc_env *  pe ,c_split_pass_x_sg2_small_grids_struct *  kerstr )
;
void  c_split_pass_x_sg2_small_grids_get_struct_len (size_t *  len )
;
int  c_split_pass_x_sg2_small_grids_get_xlen ()
;
int  c_split_pass_x_sg2_small_grids_get_num_compute_units (c_split_pass_x_sg2_small_grids_struct *  kerstr )
;
int  c_split_pass_x_sg2_small_grids_exec (c_split_pass_x_sg2_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_inoutput (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_xyzw (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_cu_cache (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_fieldE (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_fieldB (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_FoutEN (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_XLEN (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_YLEN (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_ZLEN (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_ovlp (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_numvec (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_num_ele (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_Mass (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_Charge (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_SPEC (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_sg2_small_grids_scmc_set_parameter_Deltat (c_split_pass_x_sg2_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_init (c_pscmc_env *  pe ,c_split_pass_x_small_grids_struct *  kerstr )
;
void  c_split_pass_x_small_grids_get_struct_len (size_t *  len )
;
int  c_split_pass_x_small_grids_get_xlen ()
;
int  c_split_pass_x_small_grids_get_num_compute_units (c_split_pass_x_small_grids_struct *  kerstr )
;
int  c_split_pass_x_small_grids_exec (c_split_pass_x_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_inoutput (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_xyzw (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_cu_cache (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_cu_xyzw (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_fieldE (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_fieldB (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_LFoutJ (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_FoutEN (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_XLEN (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_YLEN (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_ZLEN (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_ovlp (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_numvec (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_num_ele (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_grid_cache_len (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_cu_cache_length (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_Mass (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_Charge (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_SPEC (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_NUM_SPEC (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_DELTA_X (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_DELTA_Y (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_DELTA_Z (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_small_grids_scmc_set_parameter_Deltat (c_split_pass_x_small_grids_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_init (c_pscmc_env *  pe ,c_split_pass_x_vlo_nopush_struct *  kerstr )
;
void  c_split_pass_x_vlo_nopush_get_struct_len (size_t *  len )
;
int  c_split_pass_x_vlo_nopush_get_xlen ()
;
int  c_split_pass_x_vlo_nopush_get_num_compute_units (c_split_pass_x_vlo_nopush_struct *  kerstr )
;
int  c_split_pass_x_vlo_nopush_exec (c_split_pass_x_vlo_nopush_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_inoutput (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_xyzw (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_cu_cache (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_cu_xyzw (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_fieldE (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_fieldB (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_FoutJ (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_FoutEN (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_XLEN (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_YLEN (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_ZLEN (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_ovlp (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_numvec (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_num_ele (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_grid_cache_len (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_cu_cache_length (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_Mass (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_Charge (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_SPEC (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_NUM_SPEC (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_DELTA_X (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_DELTA_Y (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_DELTA_Z (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_nopush_scmc_set_parameter_Deltat (c_split_pass_x_vlo_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_init (c_pscmc_env *  pe ,c_split_pass_x_vlo_struct *  kerstr )
;
void  c_split_pass_x_vlo_get_struct_len (size_t *  len )
;
int  c_split_pass_x_vlo_get_xlen ()
;
int  c_split_pass_x_vlo_get_num_compute_units (c_split_pass_x_vlo_struct *  kerstr )
;
int  c_split_pass_x_vlo_exec (c_split_pass_x_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_x_vlo_scmc_set_parameter_inoutput (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_xyzw (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_cu_cache (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_cu_xyzw (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_fieldE (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_fieldB (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_FoutJ (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_FoutEN (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_XLEN (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_YLEN (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_ZLEN (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_ovlp (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_numvec (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_num_ele (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_grid_cache_len (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_cu_cache_length (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_Mass (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_Charge (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_SPEC (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_NUM_SPEC (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_DELTA_X (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_DELTA_Y (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_DELTA_Z (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_vlo_scmc_set_parameter_Deltat (c_split_pass_x_vlo_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_init (c_pscmc_env *  pe ,c_split_pass_x_nopush_struct *  kerstr )
;
void  c_split_pass_x_nopush_get_struct_len (size_t *  len )
;
int  c_split_pass_x_nopush_get_xlen ()
;
int  c_split_pass_x_nopush_get_num_compute_units (c_split_pass_x_nopush_struct *  kerstr )
;
int  c_split_pass_x_nopush_exec (c_split_pass_x_nopush_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_x_nopush_scmc_set_parameter_inoutput (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_xyzw (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_cu_cache (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_cu_xyzw (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_fieldE (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_fieldB (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_FoutJ (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_FoutEN (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_XLEN (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_YLEN (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_ZLEN (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_ovlp (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_numvec (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_num_ele (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_grid_cache_len (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_cu_cache_length (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_Mass (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_Charge (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_SPEC (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_NUM_SPEC (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_DELTA_X (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_DELTA_Y (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_DELTA_Z (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_nopush_scmc_set_parameter_Deltat (c_split_pass_x_nopush_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_init (c_pscmc_env *  pe ,c_split_pass_x_struct *  kerstr )
;
void  c_split_pass_x_get_struct_len (size_t *  len )
;
int  c_split_pass_x_get_xlen ()
;
int  c_split_pass_x_get_num_compute_units (c_split_pass_x_struct *  kerstr )
;
int  c_split_pass_x_exec (c_split_pass_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_split_pass_x_scmc_set_parameter_inoutput (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_xyzw (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_cu_cache (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_cu_xyzw (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_fieldE (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_fieldB (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_FoutJ (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_FoutEN (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_XLEN (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_YLEN (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_ZLEN (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_ovlp (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_numvec (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_num_ele (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_grid_cache_len (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_cu_cache_length (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_Mass (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_Charge (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_SPEC (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_NUM_SPEC (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_DELTA_X (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_DELTA_Y (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_DELTA_Z (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_split_pass_x_scmc_set_parameter_Deltat (c_split_pass_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
void  c_yee_abc__scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_pec__scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_damp__scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_setfix__scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_abc_x_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_pec_x_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_damp_x_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_setfix_x_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_abc_y_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_pec_y_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_damp_y_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_setfix_y_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_abc_z_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_pec_z_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_damp_z_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_setfix_z_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_abc_xy_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_pec_xy_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_damp_xy_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_setfix_xy_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_abc_xz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_pec_xz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_damp_xz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_setfix_xz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_abc_yz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_pec_yz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_damp_yz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_setfix_yz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_abc_xyz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_pec_xyz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_damp_xyz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_setfix_xyz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  c_yee_setfix_xyz_init (c_pscmc_env *  pe ,c_yee_setfix_xyz_struct *  kerstr )
;
void  c_yee_setfix_xyz_get_struct_len (size_t *  len )
;
int  c_yee_setfix_xyz_get_xlen ()
;
int  c_yee_setfix_xyz_get_num_compute_units (c_yee_setfix_xyz_struct *  kerstr )
;
int  c_yee_setfix_xyz_exec (c_yee_setfix_xyz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_setfix_xyz_scmc_set_parameter_outEB (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xyz_scmc_set_parameter_inEB (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xyz_scmc_set_parameter_cur_rankx (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xyz_scmc_set_parameter_cur_ranky (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xyz_scmc_set_parameter_cur_rankz (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xyz_scmc_set_parameter_y_cpu_core (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xyz_scmc_set_parameter_numvec (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xyz_scmc_set_parameter_XLEN (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xyz_scmc_set_parameter_YLEN (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xyz_scmc_set_parameter_ZLEN (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xyz_scmc_set_parameter_ovlp (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xyz_scmc_set_parameter_xblock (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xyz_scmc_set_parameter_yblock (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xyz_scmc_set_parameter_zblock (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xyz_scmc_set_parameter_num_ele (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xyz_scmc_set_parameter_damp_vars (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xyz_scmc_set_parameter_deltat (c_yee_setfix_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xyz_init (c_pscmc_env *  pe ,c_yee_damp_xyz_struct *  kerstr )
;
void  c_yee_damp_xyz_get_struct_len (size_t *  len )
;
int  c_yee_damp_xyz_get_xlen ()
;
int  c_yee_damp_xyz_get_num_compute_units (c_yee_damp_xyz_struct *  kerstr )
;
int  c_yee_damp_xyz_exec (c_yee_damp_xyz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_damp_xyz_scmc_set_parameter_outEB (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xyz_scmc_set_parameter_inEB (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xyz_scmc_set_parameter_cur_rankx (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xyz_scmc_set_parameter_cur_ranky (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xyz_scmc_set_parameter_cur_rankz (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xyz_scmc_set_parameter_y_cpu_core (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xyz_scmc_set_parameter_numvec (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xyz_scmc_set_parameter_XLEN (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xyz_scmc_set_parameter_YLEN (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xyz_scmc_set_parameter_ZLEN (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xyz_scmc_set_parameter_ovlp (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xyz_scmc_set_parameter_xblock (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xyz_scmc_set_parameter_yblock (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xyz_scmc_set_parameter_zblock (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xyz_scmc_set_parameter_num_ele (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xyz_scmc_set_parameter_damp_vars (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xyz_scmc_set_parameter_deltat (c_yee_damp_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xyz_init (c_pscmc_env *  pe ,c_yee_pec_xyz_struct *  kerstr )
;
void  c_yee_pec_xyz_get_struct_len (size_t *  len )
;
int  c_yee_pec_xyz_get_xlen ()
;
int  c_yee_pec_xyz_get_num_compute_units (c_yee_pec_xyz_struct *  kerstr )
;
int  c_yee_pec_xyz_exec (c_yee_pec_xyz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_pec_xyz_scmc_set_parameter_outEB (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xyz_scmc_set_parameter_inEB (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xyz_scmc_set_parameter_cur_rankx (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xyz_scmc_set_parameter_cur_ranky (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xyz_scmc_set_parameter_cur_rankz (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xyz_scmc_set_parameter_y_cpu_core (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xyz_scmc_set_parameter_numvec (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xyz_scmc_set_parameter_XLEN (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xyz_scmc_set_parameter_YLEN (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xyz_scmc_set_parameter_ZLEN (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xyz_scmc_set_parameter_ovlp (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xyz_scmc_set_parameter_xblock (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xyz_scmc_set_parameter_yblock (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xyz_scmc_set_parameter_zblock (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xyz_scmc_set_parameter_num_ele (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xyz_scmc_set_parameter_damp_vars (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xyz_scmc_set_parameter_deltat (c_yee_pec_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xyz_init (c_pscmc_env *  pe ,c_yee_abc_xyz_struct *  kerstr )
;
void  c_yee_abc_xyz_get_struct_len (size_t *  len )
;
int  c_yee_abc_xyz_get_xlen ()
;
int  c_yee_abc_xyz_get_num_compute_units (c_yee_abc_xyz_struct *  kerstr )
;
int  c_yee_abc_xyz_exec (c_yee_abc_xyz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_abc_xyz_scmc_set_parameter_outEB (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xyz_scmc_set_parameter_inEB (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xyz_scmc_set_parameter_cur_rankx (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xyz_scmc_set_parameter_cur_ranky (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xyz_scmc_set_parameter_cur_rankz (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xyz_scmc_set_parameter_y_cpu_core (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xyz_scmc_set_parameter_numvec (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xyz_scmc_set_parameter_XLEN (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xyz_scmc_set_parameter_YLEN (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xyz_scmc_set_parameter_ZLEN (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xyz_scmc_set_parameter_ovlp (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xyz_scmc_set_parameter_xblock (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xyz_scmc_set_parameter_yblock (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xyz_scmc_set_parameter_zblock (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xyz_scmc_set_parameter_num_ele (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xyz_scmc_set_parameter_damp_vars (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xyz_scmc_set_parameter_deltat (c_yee_abc_xyz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_yz_init (c_pscmc_env *  pe ,c_yee_setfix_yz_struct *  kerstr )
;
void  c_yee_setfix_yz_get_struct_len (size_t *  len )
;
int  c_yee_setfix_yz_get_xlen ()
;
int  c_yee_setfix_yz_get_num_compute_units (c_yee_setfix_yz_struct *  kerstr )
;
int  c_yee_setfix_yz_exec (c_yee_setfix_yz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_setfix_yz_scmc_set_parameter_outEB (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_yz_scmc_set_parameter_inEB (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_yz_scmc_set_parameter_cur_rankx (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_yz_scmc_set_parameter_cur_ranky (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_yz_scmc_set_parameter_cur_rankz (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_yz_scmc_set_parameter_y_cpu_core (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_yz_scmc_set_parameter_numvec (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_yz_scmc_set_parameter_XLEN (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_yz_scmc_set_parameter_YLEN (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_yz_scmc_set_parameter_ZLEN (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_yz_scmc_set_parameter_ovlp (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_yz_scmc_set_parameter_xblock (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_yz_scmc_set_parameter_yblock (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_yz_scmc_set_parameter_zblock (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_yz_scmc_set_parameter_num_ele (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_yz_scmc_set_parameter_damp_vars (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_yz_scmc_set_parameter_deltat (c_yee_setfix_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_yz_init (c_pscmc_env *  pe ,c_yee_damp_yz_struct *  kerstr )
;
void  c_yee_damp_yz_get_struct_len (size_t *  len )
;
int  c_yee_damp_yz_get_xlen ()
;
int  c_yee_damp_yz_get_num_compute_units (c_yee_damp_yz_struct *  kerstr )
;
int  c_yee_damp_yz_exec (c_yee_damp_yz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_damp_yz_scmc_set_parameter_outEB (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_yz_scmc_set_parameter_inEB (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_yz_scmc_set_parameter_cur_rankx (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_yz_scmc_set_parameter_cur_ranky (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_yz_scmc_set_parameter_cur_rankz (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_yz_scmc_set_parameter_y_cpu_core (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_yz_scmc_set_parameter_numvec (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_yz_scmc_set_parameter_XLEN (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_yz_scmc_set_parameter_YLEN (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_yz_scmc_set_parameter_ZLEN (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_yz_scmc_set_parameter_ovlp (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_yz_scmc_set_parameter_xblock (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_yz_scmc_set_parameter_yblock (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_yz_scmc_set_parameter_zblock (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_yz_scmc_set_parameter_num_ele (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_yz_scmc_set_parameter_damp_vars (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_yz_scmc_set_parameter_deltat (c_yee_damp_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_yz_init (c_pscmc_env *  pe ,c_yee_pec_yz_struct *  kerstr )
;
void  c_yee_pec_yz_get_struct_len (size_t *  len )
;
int  c_yee_pec_yz_get_xlen ()
;
int  c_yee_pec_yz_get_num_compute_units (c_yee_pec_yz_struct *  kerstr )
;
int  c_yee_pec_yz_exec (c_yee_pec_yz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_pec_yz_scmc_set_parameter_outEB (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_yz_scmc_set_parameter_inEB (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_yz_scmc_set_parameter_cur_rankx (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_yz_scmc_set_parameter_cur_ranky (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_yz_scmc_set_parameter_cur_rankz (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_yz_scmc_set_parameter_y_cpu_core (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_yz_scmc_set_parameter_numvec (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_yz_scmc_set_parameter_XLEN (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_yz_scmc_set_parameter_YLEN (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_yz_scmc_set_parameter_ZLEN (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_yz_scmc_set_parameter_ovlp (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_yz_scmc_set_parameter_xblock (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_yz_scmc_set_parameter_yblock (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_yz_scmc_set_parameter_zblock (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_yz_scmc_set_parameter_num_ele (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_yz_scmc_set_parameter_damp_vars (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_yz_scmc_set_parameter_deltat (c_yee_pec_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_yz_init (c_pscmc_env *  pe ,c_yee_abc_yz_struct *  kerstr )
;
void  c_yee_abc_yz_get_struct_len (size_t *  len )
;
int  c_yee_abc_yz_get_xlen ()
;
int  c_yee_abc_yz_get_num_compute_units (c_yee_abc_yz_struct *  kerstr )
;
int  c_yee_abc_yz_exec (c_yee_abc_yz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_abc_yz_scmc_set_parameter_outEB (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_yz_scmc_set_parameter_inEB (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_yz_scmc_set_parameter_cur_rankx (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_yz_scmc_set_parameter_cur_ranky (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_yz_scmc_set_parameter_cur_rankz (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_yz_scmc_set_parameter_y_cpu_core (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_yz_scmc_set_parameter_numvec (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_yz_scmc_set_parameter_XLEN (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_yz_scmc_set_parameter_YLEN (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_yz_scmc_set_parameter_ZLEN (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_yz_scmc_set_parameter_ovlp (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_yz_scmc_set_parameter_xblock (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_yz_scmc_set_parameter_yblock (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_yz_scmc_set_parameter_zblock (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_yz_scmc_set_parameter_num_ele (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_yz_scmc_set_parameter_damp_vars (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_yz_scmc_set_parameter_deltat (c_yee_abc_yz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xz_init (c_pscmc_env *  pe ,c_yee_setfix_xz_struct *  kerstr )
;
void  c_yee_setfix_xz_get_struct_len (size_t *  len )
;
int  c_yee_setfix_xz_get_xlen ()
;
int  c_yee_setfix_xz_get_num_compute_units (c_yee_setfix_xz_struct *  kerstr )
;
int  c_yee_setfix_xz_exec (c_yee_setfix_xz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_setfix_xz_scmc_set_parameter_outEB (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xz_scmc_set_parameter_inEB (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xz_scmc_set_parameter_cur_rankx (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xz_scmc_set_parameter_cur_ranky (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xz_scmc_set_parameter_cur_rankz (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xz_scmc_set_parameter_y_cpu_core (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xz_scmc_set_parameter_numvec (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xz_scmc_set_parameter_XLEN (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xz_scmc_set_parameter_YLEN (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xz_scmc_set_parameter_ZLEN (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xz_scmc_set_parameter_ovlp (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xz_scmc_set_parameter_xblock (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xz_scmc_set_parameter_yblock (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xz_scmc_set_parameter_zblock (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xz_scmc_set_parameter_num_ele (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xz_scmc_set_parameter_damp_vars (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xz_scmc_set_parameter_deltat (c_yee_setfix_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xz_init (c_pscmc_env *  pe ,c_yee_damp_xz_struct *  kerstr )
;
void  c_yee_damp_xz_get_struct_len (size_t *  len )
;
int  c_yee_damp_xz_get_xlen ()
;
int  c_yee_damp_xz_get_num_compute_units (c_yee_damp_xz_struct *  kerstr )
;
int  c_yee_damp_xz_exec (c_yee_damp_xz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_damp_xz_scmc_set_parameter_outEB (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xz_scmc_set_parameter_inEB (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xz_scmc_set_parameter_cur_rankx (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xz_scmc_set_parameter_cur_ranky (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xz_scmc_set_parameter_cur_rankz (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xz_scmc_set_parameter_y_cpu_core (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xz_scmc_set_parameter_numvec (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xz_scmc_set_parameter_XLEN (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xz_scmc_set_parameter_YLEN (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xz_scmc_set_parameter_ZLEN (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xz_scmc_set_parameter_ovlp (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xz_scmc_set_parameter_xblock (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xz_scmc_set_parameter_yblock (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xz_scmc_set_parameter_zblock (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xz_scmc_set_parameter_num_ele (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xz_scmc_set_parameter_damp_vars (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xz_scmc_set_parameter_deltat (c_yee_damp_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xz_init (c_pscmc_env *  pe ,c_yee_pec_xz_struct *  kerstr )
;
void  c_yee_pec_xz_get_struct_len (size_t *  len )
;
int  c_yee_pec_xz_get_xlen ()
;
int  c_yee_pec_xz_get_num_compute_units (c_yee_pec_xz_struct *  kerstr )
;
int  c_yee_pec_xz_exec (c_yee_pec_xz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_pec_xz_scmc_set_parameter_outEB (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xz_scmc_set_parameter_inEB (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xz_scmc_set_parameter_cur_rankx (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xz_scmc_set_parameter_cur_ranky (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xz_scmc_set_parameter_cur_rankz (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xz_scmc_set_parameter_y_cpu_core (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xz_scmc_set_parameter_numvec (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xz_scmc_set_parameter_XLEN (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xz_scmc_set_parameter_YLEN (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xz_scmc_set_parameter_ZLEN (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xz_scmc_set_parameter_ovlp (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xz_scmc_set_parameter_xblock (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xz_scmc_set_parameter_yblock (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xz_scmc_set_parameter_zblock (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xz_scmc_set_parameter_num_ele (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xz_scmc_set_parameter_damp_vars (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xz_scmc_set_parameter_deltat (c_yee_pec_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xz_init (c_pscmc_env *  pe ,c_yee_abc_xz_struct *  kerstr )
;
void  c_yee_abc_xz_get_struct_len (size_t *  len )
;
int  c_yee_abc_xz_get_xlen ()
;
int  c_yee_abc_xz_get_num_compute_units (c_yee_abc_xz_struct *  kerstr )
;
int  c_yee_abc_xz_exec (c_yee_abc_xz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_abc_xz_scmc_set_parameter_outEB (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xz_scmc_set_parameter_inEB (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xz_scmc_set_parameter_cur_rankx (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xz_scmc_set_parameter_cur_ranky (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xz_scmc_set_parameter_cur_rankz (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xz_scmc_set_parameter_y_cpu_core (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xz_scmc_set_parameter_numvec (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xz_scmc_set_parameter_XLEN (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xz_scmc_set_parameter_YLEN (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xz_scmc_set_parameter_ZLEN (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xz_scmc_set_parameter_ovlp (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xz_scmc_set_parameter_xblock (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xz_scmc_set_parameter_yblock (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xz_scmc_set_parameter_zblock (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xz_scmc_set_parameter_num_ele (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xz_scmc_set_parameter_damp_vars (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xz_scmc_set_parameter_deltat (c_yee_abc_xz_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xy_init (c_pscmc_env *  pe ,c_yee_setfix_xy_struct *  kerstr )
;
void  c_yee_setfix_xy_get_struct_len (size_t *  len )
;
int  c_yee_setfix_xy_get_xlen ()
;
int  c_yee_setfix_xy_get_num_compute_units (c_yee_setfix_xy_struct *  kerstr )
;
int  c_yee_setfix_xy_exec (c_yee_setfix_xy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_setfix_xy_scmc_set_parameter_outEB (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xy_scmc_set_parameter_inEB (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xy_scmc_set_parameter_cur_rankx (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xy_scmc_set_parameter_cur_ranky (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xy_scmc_set_parameter_cur_rankz (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xy_scmc_set_parameter_y_cpu_core (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xy_scmc_set_parameter_numvec (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xy_scmc_set_parameter_XLEN (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xy_scmc_set_parameter_YLEN (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xy_scmc_set_parameter_ZLEN (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xy_scmc_set_parameter_ovlp (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xy_scmc_set_parameter_xblock (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xy_scmc_set_parameter_yblock (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xy_scmc_set_parameter_zblock (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xy_scmc_set_parameter_num_ele (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xy_scmc_set_parameter_damp_vars (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_xy_scmc_set_parameter_deltat (c_yee_setfix_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xy_init (c_pscmc_env *  pe ,c_yee_damp_xy_struct *  kerstr )
;
void  c_yee_damp_xy_get_struct_len (size_t *  len )
;
int  c_yee_damp_xy_get_xlen ()
;
int  c_yee_damp_xy_get_num_compute_units (c_yee_damp_xy_struct *  kerstr )
;
int  c_yee_damp_xy_exec (c_yee_damp_xy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_damp_xy_scmc_set_parameter_outEB (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xy_scmc_set_parameter_inEB (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xy_scmc_set_parameter_cur_rankx (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xy_scmc_set_parameter_cur_ranky (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xy_scmc_set_parameter_cur_rankz (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xy_scmc_set_parameter_y_cpu_core (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xy_scmc_set_parameter_numvec (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xy_scmc_set_parameter_XLEN (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xy_scmc_set_parameter_YLEN (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xy_scmc_set_parameter_ZLEN (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xy_scmc_set_parameter_ovlp (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xy_scmc_set_parameter_xblock (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xy_scmc_set_parameter_yblock (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xy_scmc_set_parameter_zblock (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xy_scmc_set_parameter_num_ele (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xy_scmc_set_parameter_damp_vars (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_xy_scmc_set_parameter_deltat (c_yee_damp_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xy_init (c_pscmc_env *  pe ,c_yee_pec_xy_struct *  kerstr )
;
void  c_yee_pec_xy_get_struct_len (size_t *  len )
;
int  c_yee_pec_xy_get_xlen ()
;
int  c_yee_pec_xy_get_num_compute_units (c_yee_pec_xy_struct *  kerstr )
;
int  c_yee_pec_xy_exec (c_yee_pec_xy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_pec_xy_scmc_set_parameter_outEB (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xy_scmc_set_parameter_inEB (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xy_scmc_set_parameter_cur_rankx (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xy_scmc_set_parameter_cur_ranky (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xy_scmc_set_parameter_cur_rankz (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xy_scmc_set_parameter_y_cpu_core (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xy_scmc_set_parameter_numvec (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xy_scmc_set_parameter_XLEN (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xy_scmc_set_parameter_YLEN (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xy_scmc_set_parameter_ZLEN (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xy_scmc_set_parameter_ovlp (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xy_scmc_set_parameter_xblock (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xy_scmc_set_parameter_yblock (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xy_scmc_set_parameter_zblock (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xy_scmc_set_parameter_num_ele (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xy_scmc_set_parameter_damp_vars (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_xy_scmc_set_parameter_deltat (c_yee_pec_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xy_init (c_pscmc_env *  pe ,c_yee_abc_xy_struct *  kerstr )
;
void  c_yee_abc_xy_get_struct_len (size_t *  len )
;
int  c_yee_abc_xy_get_xlen ()
;
int  c_yee_abc_xy_get_num_compute_units (c_yee_abc_xy_struct *  kerstr )
;
int  c_yee_abc_xy_exec (c_yee_abc_xy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_abc_xy_scmc_set_parameter_outEB (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xy_scmc_set_parameter_inEB (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xy_scmc_set_parameter_cur_rankx (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xy_scmc_set_parameter_cur_ranky (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xy_scmc_set_parameter_cur_rankz (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xy_scmc_set_parameter_y_cpu_core (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xy_scmc_set_parameter_numvec (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xy_scmc_set_parameter_XLEN (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xy_scmc_set_parameter_YLEN (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xy_scmc_set_parameter_ZLEN (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xy_scmc_set_parameter_ovlp (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xy_scmc_set_parameter_xblock (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xy_scmc_set_parameter_yblock (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xy_scmc_set_parameter_zblock (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xy_scmc_set_parameter_num_ele (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xy_scmc_set_parameter_damp_vars (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_xy_scmc_set_parameter_deltat (c_yee_abc_xy_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_z_init (c_pscmc_env *  pe ,c_yee_setfix_z_struct *  kerstr )
;
void  c_yee_setfix_z_get_struct_len (size_t *  len )
;
int  c_yee_setfix_z_get_xlen ()
;
int  c_yee_setfix_z_get_num_compute_units (c_yee_setfix_z_struct *  kerstr )
;
int  c_yee_setfix_z_exec (c_yee_setfix_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_setfix_z_scmc_set_parameter_outEB (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_z_scmc_set_parameter_inEB (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_z_scmc_set_parameter_cur_rankx (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_z_scmc_set_parameter_cur_ranky (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_z_scmc_set_parameter_cur_rankz (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_z_scmc_set_parameter_y_cpu_core (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_z_scmc_set_parameter_numvec (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_z_scmc_set_parameter_XLEN (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_z_scmc_set_parameter_YLEN (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_z_scmc_set_parameter_ZLEN (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_z_scmc_set_parameter_ovlp (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_z_scmc_set_parameter_xblock (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_z_scmc_set_parameter_yblock (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_z_scmc_set_parameter_zblock (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_z_scmc_set_parameter_num_ele (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_z_scmc_set_parameter_damp_vars (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_z_scmc_set_parameter_deltat (c_yee_setfix_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_z_init (c_pscmc_env *  pe ,c_yee_damp_z_struct *  kerstr )
;
void  c_yee_damp_z_get_struct_len (size_t *  len )
;
int  c_yee_damp_z_get_xlen ()
;
int  c_yee_damp_z_get_num_compute_units (c_yee_damp_z_struct *  kerstr )
;
int  c_yee_damp_z_exec (c_yee_damp_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_damp_z_scmc_set_parameter_outEB (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_z_scmc_set_parameter_inEB (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_z_scmc_set_parameter_cur_rankx (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_z_scmc_set_parameter_cur_ranky (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_z_scmc_set_parameter_cur_rankz (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_z_scmc_set_parameter_y_cpu_core (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_z_scmc_set_parameter_numvec (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_z_scmc_set_parameter_XLEN (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_z_scmc_set_parameter_YLEN (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_z_scmc_set_parameter_ZLEN (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_z_scmc_set_parameter_ovlp (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_z_scmc_set_parameter_xblock (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_z_scmc_set_parameter_yblock (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_z_scmc_set_parameter_zblock (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_z_scmc_set_parameter_num_ele (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_z_scmc_set_parameter_damp_vars (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_z_scmc_set_parameter_deltat (c_yee_damp_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_z_init (c_pscmc_env *  pe ,c_yee_pec_z_struct *  kerstr )
;
void  c_yee_pec_z_get_struct_len (size_t *  len )
;
int  c_yee_pec_z_get_xlen ()
;
int  c_yee_pec_z_get_num_compute_units (c_yee_pec_z_struct *  kerstr )
;
int  c_yee_pec_z_exec (c_yee_pec_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_pec_z_scmc_set_parameter_outEB (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_z_scmc_set_parameter_inEB (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_z_scmc_set_parameter_cur_rankx (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_z_scmc_set_parameter_cur_ranky (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_z_scmc_set_parameter_cur_rankz (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_z_scmc_set_parameter_y_cpu_core (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_z_scmc_set_parameter_numvec (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_z_scmc_set_parameter_XLEN (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_z_scmc_set_parameter_YLEN (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_z_scmc_set_parameter_ZLEN (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_z_scmc_set_parameter_ovlp (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_z_scmc_set_parameter_xblock (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_z_scmc_set_parameter_yblock (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_z_scmc_set_parameter_zblock (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_z_scmc_set_parameter_num_ele (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_z_scmc_set_parameter_damp_vars (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_z_scmc_set_parameter_deltat (c_yee_pec_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_z_init (c_pscmc_env *  pe ,c_yee_abc_z_struct *  kerstr )
;
void  c_yee_abc_z_get_struct_len (size_t *  len )
;
int  c_yee_abc_z_get_xlen ()
;
int  c_yee_abc_z_get_num_compute_units (c_yee_abc_z_struct *  kerstr )
;
int  c_yee_abc_z_exec (c_yee_abc_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_abc_z_scmc_set_parameter_outEB (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_z_scmc_set_parameter_inEB (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_z_scmc_set_parameter_cur_rankx (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_z_scmc_set_parameter_cur_ranky (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_z_scmc_set_parameter_cur_rankz (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_z_scmc_set_parameter_y_cpu_core (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_z_scmc_set_parameter_numvec (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_z_scmc_set_parameter_XLEN (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_z_scmc_set_parameter_YLEN (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_z_scmc_set_parameter_ZLEN (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_z_scmc_set_parameter_ovlp (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_z_scmc_set_parameter_xblock (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_z_scmc_set_parameter_yblock (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_z_scmc_set_parameter_zblock (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_z_scmc_set_parameter_num_ele (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_z_scmc_set_parameter_damp_vars (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_z_scmc_set_parameter_deltat (c_yee_abc_z_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_y_init (c_pscmc_env *  pe ,c_yee_setfix_y_struct *  kerstr )
;
void  c_yee_setfix_y_get_struct_len (size_t *  len )
;
int  c_yee_setfix_y_get_xlen ()
;
int  c_yee_setfix_y_get_num_compute_units (c_yee_setfix_y_struct *  kerstr )
;
int  c_yee_setfix_y_exec (c_yee_setfix_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_setfix_y_scmc_set_parameter_outEB (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_y_scmc_set_parameter_inEB (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_y_scmc_set_parameter_cur_rankx (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_y_scmc_set_parameter_cur_ranky (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_y_scmc_set_parameter_cur_rankz (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_y_scmc_set_parameter_y_cpu_core (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_y_scmc_set_parameter_numvec (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_y_scmc_set_parameter_XLEN (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_y_scmc_set_parameter_YLEN (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_y_scmc_set_parameter_ZLEN (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_y_scmc_set_parameter_ovlp (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_y_scmc_set_parameter_xblock (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_y_scmc_set_parameter_yblock (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_y_scmc_set_parameter_zblock (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_y_scmc_set_parameter_num_ele (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_y_scmc_set_parameter_damp_vars (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_y_scmc_set_parameter_deltat (c_yee_setfix_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_y_init (c_pscmc_env *  pe ,c_yee_damp_y_struct *  kerstr )
;
void  c_yee_damp_y_get_struct_len (size_t *  len )
;
int  c_yee_damp_y_get_xlen ()
;
int  c_yee_damp_y_get_num_compute_units (c_yee_damp_y_struct *  kerstr )
;
int  c_yee_damp_y_exec (c_yee_damp_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_damp_y_scmc_set_parameter_outEB (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_y_scmc_set_parameter_inEB (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_y_scmc_set_parameter_cur_rankx (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_y_scmc_set_parameter_cur_ranky (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_y_scmc_set_parameter_cur_rankz (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_y_scmc_set_parameter_y_cpu_core (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_y_scmc_set_parameter_numvec (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_y_scmc_set_parameter_XLEN (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_y_scmc_set_parameter_YLEN (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_y_scmc_set_parameter_ZLEN (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_y_scmc_set_parameter_ovlp (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_y_scmc_set_parameter_xblock (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_y_scmc_set_parameter_yblock (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_y_scmc_set_parameter_zblock (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_y_scmc_set_parameter_num_ele (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_y_scmc_set_parameter_damp_vars (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_y_scmc_set_parameter_deltat (c_yee_damp_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_y_init (c_pscmc_env *  pe ,c_yee_pec_y_struct *  kerstr )
;
void  c_yee_pec_y_get_struct_len (size_t *  len )
;
int  c_yee_pec_y_get_xlen ()
;
int  c_yee_pec_y_get_num_compute_units (c_yee_pec_y_struct *  kerstr )
;
int  c_yee_pec_y_exec (c_yee_pec_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_pec_y_scmc_set_parameter_outEB (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_y_scmc_set_parameter_inEB (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_y_scmc_set_parameter_cur_rankx (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_y_scmc_set_parameter_cur_ranky (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_y_scmc_set_parameter_cur_rankz (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_y_scmc_set_parameter_y_cpu_core (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_y_scmc_set_parameter_numvec (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_y_scmc_set_parameter_XLEN (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_y_scmc_set_parameter_YLEN (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_y_scmc_set_parameter_ZLEN (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_y_scmc_set_parameter_ovlp (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_y_scmc_set_parameter_xblock (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_y_scmc_set_parameter_yblock (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_y_scmc_set_parameter_zblock (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_y_scmc_set_parameter_num_ele (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_y_scmc_set_parameter_damp_vars (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_y_scmc_set_parameter_deltat (c_yee_pec_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_y_init (c_pscmc_env *  pe ,c_yee_abc_y_struct *  kerstr )
;
void  c_yee_abc_y_get_struct_len (size_t *  len )
;
int  c_yee_abc_y_get_xlen ()
;
int  c_yee_abc_y_get_num_compute_units (c_yee_abc_y_struct *  kerstr )
;
int  c_yee_abc_y_exec (c_yee_abc_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_abc_y_scmc_set_parameter_outEB (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_y_scmc_set_parameter_inEB (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_y_scmc_set_parameter_cur_rankx (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_y_scmc_set_parameter_cur_ranky (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_y_scmc_set_parameter_cur_rankz (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_y_scmc_set_parameter_y_cpu_core (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_y_scmc_set_parameter_numvec (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_y_scmc_set_parameter_XLEN (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_y_scmc_set_parameter_YLEN (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_y_scmc_set_parameter_ZLEN (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_y_scmc_set_parameter_ovlp (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_y_scmc_set_parameter_xblock (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_y_scmc_set_parameter_yblock (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_y_scmc_set_parameter_zblock (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_y_scmc_set_parameter_num_ele (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_y_scmc_set_parameter_damp_vars (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_y_scmc_set_parameter_deltat (c_yee_abc_y_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_x_init (c_pscmc_env *  pe ,c_yee_setfix_x_struct *  kerstr )
;
void  c_yee_setfix_x_get_struct_len (size_t *  len )
;
int  c_yee_setfix_x_get_xlen ()
;
int  c_yee_setfix_x_get_num_compute_units (c_yee_setfix_x_struct *  kerstr )
;
int  c_yee_setfix_x_exec (c_yee_setfix_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_setfix_x_scmc_set_parameter_outEB (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_x_scmc_set_parameter_inEB (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_x_scmc_set_parameter_cur_rankx (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_x_scmc_set_parameter_cur_ranky (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_x_scmc_set_parameter_cur_rankz (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_x_scmc_set_parameter_y_cpu_core (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_x_scmc_set_parameter_numvec (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_x_scmc_set_parameter_XLEN (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_x_scmc_set_parameter_YLEN (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_x_scmc_set_parameter_ZLEN (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_x_scmc_set_parameter_ovlp (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_x_scmc_set_parameter_xblock (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_x_scmc_set_parameter_yblock (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_x_scmc_set_parameter_zblock (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_x_scmc_set_parameter_num_ele (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_x_scmc_set_parameter_damp_vars (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix_x_scmc_set_parameter_deltat (c_yee_setfix_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_x_init (c_pscmc_env *  pe ,c_yee_damp_x_struct *  kerstr )
;
void  c_yee_damp_x_get_struct_len (size_t *  len )
;
int  c_yee_damp_x_get_xlen ()
;
int  c_yee_damp_x_get_num_compute_units (c_yee_damp_x_struct *  kerstr )
;
int  c_yee_damp_x_exec (c_yee_damp_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_damp_x_scmc_set_parameter_outEB (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_x_scmc_set_parameter_inEB (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_x_scmc_set_parameter_cur_rankx (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_x_scmc_set_parameter_cur_ranky (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_x_scmc_set_parameter_cur_rankz (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_x_scmc_set_parameter_y_cpu_core (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_x_scmc_set_parameter_numvec (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_x_scmc_set_parameter_XLEN (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_x_scmc_set_parameter_YLEN (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_x_scmc_set_parameter_ZLEN (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_x_scmc_set_parameter_ovlp (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_x_scmc_set_parameter_xblock (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_x_scmc_set_parameter_yblock (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_x_scmc_set_parameter_zblock (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_x_scmc_set_parameter_num_ele (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_x_scmc_set_parameter_damp_vars (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp_x_scmc_set_parameter_deltat (c_yee_damp_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_x_init (c_pscmc_env *  pe ,c_yee_pec_x_struct *  kerstr )
;
void  c_yee_pec_x_get_struct_len (size_t *  len )
;
int  c_yee_pec_x_get_xlen ()
;
int  c_yee_pec_x_get_num_compute_units (c_yee_pec_x_struct *  kerstr )
;
int  c_yee_pec_x_exec (c_yee_pec_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_pec_x_scmc_set_parameter_outEB (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_x_scmc_set_parameter_inEB (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_x_scmc_set_parameter_cur_rankx (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_x_scmc_set_parameter_cur_ranky (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_x_scmc_set_parameter_cur_rankz (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_x_scmc_set_parameter_y_cpu_core (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_x_scmc_set_parameter_numvec (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_x_scmc_set_parameter_XLEN (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_x_scmc_set_parameter_YLEN (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_x_scmc_set_parameter_ZLEN (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_x_scmc_set_parameter_ovlp (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_x_scmc_set_parameter_xblock (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_x_scmc_set_parameter_yblock (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_x_scmc_set_parameter_zblock (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_x_scmc_set_parameter_num_ele (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_x_scmc_set_parameter_damp_vars (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec_x_scmc_set_parameter_deltat (c_yee_pec_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_x_init (c_pscmc_env *  pe ,c_yee_abc_x_struct *  kerstr )
;
void  c_yee_abc_x_get_struct_len (size_t *  len )
;
int  c_yee_abc_x_get_xlen ()
;
int  c_yee_abc_x_get_num_compute_units (c_yee_abc_x_struct *  kerstr )
;
int  c_yee_abc_x_exec (c_yee_abc_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_abc_x_scmc_set_parameter_outEB (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_x_scmc_set_parameter_inEB (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_x_scmc_set_parameter_cur_rankx (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_x_scmc_set_parameter_cur_ranky (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_x_scmc_set_parameter_cur_rankz (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_x_scmc_set_parameter_y_cpu_core (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_x_scmc_set_parameter_numvec (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_x_scmc_set_parameter_XLEN (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_x_scmc_set_parameter_YLEN (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_x_scmc_set_parameter_ZLEN (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_x_scmc_set_parameter_ovlp (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_x_scmc_set_parameter_xblock (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_x_scmc_set_parameter_yblock (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_x_scmc_set_parameter_zblock (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_x_scmc_set_parameter_num_ele (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_x_scmc_set_parameter_damp_vars (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc_x_scmc_set_parameter_deltat (c_yee_abc_x_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix__init (c_pscmc_env *  pe ,c_yee_setfix__struct *  kerstr )
;
void  c_yee_setfix__get_struct_len (size_t *  len )
;
int  c_yee_setfix__get_xlen ()
;
int  c_yee_setfix__get_num_compute_units (c_yee_setfix__struct *  kerstr )
;
int  c_yee_setfix__exec (c_yee_setfix__struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_setfix__scmc_set_parameter_outEB (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix__scmc_set_parameter_inEB (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix__scmc_set_parameter_cur_rankx (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix__scmc_set_parameter_cur_ranky (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix__scmc_set_parameter_cur_rankz (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix__scmc_set_parameter_y_cpu_core (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix__scmc_set_parameter_numvec (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix__scmc_set_parameter_XLEN (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix__scmc_set_parameter_YLEN (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix__scmc_set_parameter_ZLEN (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix__scmc_set_parameter_ovlp (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix__scmc_set_parameter_xblock (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix__scmc_set_parameter_yblock (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix__scmc_set_parameter_zblock (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix__scmc_set_parameter_num_ele (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix__scmc_set_parameter_damp_vars (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_setfix__scmc_set_parameter_deltat (c_yee_setfix__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp__init (c_pscmc_env *  pe ,c_yee_damp__struct *  kerstr )
;
void  c_yee_damp__get_struct_len (size_t *  len )
;
int  c_yee_damp__get_xlen ()
;
int  c_yee_damp__get_num_compute_units (c_yee_damp__struct *  kerstr )
;
int  c_yee_damp__exec (c_yee_damp__struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_damp__scmc_set_parameter_outEB (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp__scmc_set_parameter_inEB (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp__scmc_set_parameter_cur_rankx (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp__scmc_set_parameter_cur_ranky (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp__scmc_set_parameter_cur_rankz (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp__scmc_set_parameter_y_cpu_core (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp__scmc_set_parameter_numvec (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp__scmc_set_parameter_XLEN (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp__scmc_set_parameter_YLEN (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp__scmc_set_parameter_ZLEN (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp__scmc_set_parameter_ovlp (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp__scmc_set_parameter_xblock (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp__scmc_set_parameter_yblock (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp__scmc_set_parameter_zblock (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp__scmc_set_parameter_num_ele (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp__scmc_set_parameter_damp_vars (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_damp__scmc_set_parameter_deltat (c_yee_damp__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec__init (c_pscmc_env *  pe ,c_yee_pec__struct *  kerstr )
;
void  c_yee_pec__get_struct_len (size_t *  len )
;
int  c_yee_pec__get_xlen ()
;
int  c_yee_pec__get_num_compute_units (c_yee_pec__struct *  kerstr )
;
int  c_yee_pec__exec (c_yee_pec__struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_pec__scmc_set_parameter_outEB (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec__scmc_set_parameter_inEB (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec__scmc_set_parameter_cur_rankx (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec__scmc_set_parameter_cur_ranky (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec__scmc_set_parameter_cur_rankz (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec__scmc_set_parameter_y_cpu_core (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec__scmc_set_parameter_numvec (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec__scmc_set_parameter_XLEN (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec__scmc_set_parameter_YLEN (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec__scmc_set_parameter_ZLEN (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec__scmc_set_parameter_ovlp (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec__scmc_set_parameter_xblock (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec__scmc_set_parameter_yblock (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec__scmc_set_parameter_zblock (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec__scmc_set_parameter_num_ele (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec__scmc_set_parameter_damp_vars (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_pec__scmc_set_parameter_deltat (c_yee_pec__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc__init (c_pscmc_env *  pe ,c_yee_abc__struct *  kerstr )
;
void  c_yee_abc__get_struct_len (size_t *  len )
;
int  c_yee_abc__get_xlen ()
;
int  c_yee_abc__get_num_compute_units (c_yee_abc__struct *  kerstr )
;
int  c_yee_abc__exec (c_yee_abc__struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_yee_abc__scmc_set_parameter_outEB (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc__scmc_set_parameter_inEB (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc__scmc_set_parameter_cur_rankx (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc__scmc_set_parameter_cur_ranky (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc__scmc_set_parameter_cur_rankz (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc__scmc_set_parameter_y_cpu_core (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc__scmc_set_parameter_numvec (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc__scmc_set_parameter_XLEN (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc__scmc_set_parameter_YLEN (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc__scmc_set_parameter_ZLEN (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc__scmc_set_parameter_ovlp (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc__scmc_set_parameter_xblock (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc__scmc_set_parameter_yblock (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc__scmc_set_parameter_zblock (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc__scmc_set_parameter_num_ele (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc__scmc_set_parameter_damp_vars (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_yee_abc__scmc_set_parameter_deltat (c_yee_abc__struct *  kerstr ,c_pscmc_mem *  pm )
;
void  c_dm_bihamt_dual_psi_eqn_J_scmc_kernel (double *  dphi_dt_out ,double *  phi_in ,double *  A1 ,double *  Y1 ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_A1 ,double  M ,double  Q ,double  DM_A ,double  DX ,double  DY ,double  DZ ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_dm_bihamt_eqn_dydt_scmc_kernel (double *  dphi_dt_out ,double *  phi_in ,double *  A1 ,double *  Y1 ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_A1 ,double  M ,double  Q ,double  DM_A ,double  DX ,double  DY ,double  DZ ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_dm_cayley_eqn_J_scmc_kernel (double *  dphi_dt_out ,double *  phi_in ,double *  A1 ,double *  Y1 ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_A1 ,double  M ,double  Q ,double  DM_A ,double  DX ,double  DY ,double  DZ ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_dm_calc_hamt_scmc_kernel (double *  dphi_dt_out ,double *  phi_in ,double *  A1 ,double *  Y1 ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_A1 ,double  M ,double  Q ,double  DM_A ,double  DX ,double  DY ,double  DZ ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_dm_exact_eqn_m_scmc_kernel (double *  dphi_dt_out ,double *  phi_in ,double *  A1 ,double *  Y1 ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_A1 ,double  M ,double  Q ,double  DM_A ,double  DX ,double  DY ,double  DZ ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_dm_cayley_eqn_core_scmc_kernel (double *  dphi_dt_out ,double *  phi_in ,double *  A1 ,double *  Y1 ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_A1 ,double  M ,double  Q ,double  DM_A ,double  DX ,double  DY ,double  DZ ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_dm_calc_hamt_dual_scmc_kernel (double *  dphi_dt_out ,double *  phi_in ,double *  A1 ,double *  Y1 ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_A1 ,double  M ,double  Q ,double  DM_A ,double  DX ,double  DY ,double  DZ ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  c_dm_calc_hamt_dual_init (c_pscmc_env *  pe ,c_dm_calc_hamt_dual_struct *  kerstr )
;
void  c_dm_calc_hamt_dual_get_struct_len (size_t *  len )
;
int  c_dm_calc_hamt_dual_get_xlen ()
;
int  c_dm_calc_hamt_dual_get_num_compute_units (c_dm_calc_hamt_dual_struct *  kerstr )
;
int  c_dm_calc_hamt_dual_exec (c_dm_calc_hamt_dual_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_dphi_dt_out (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_phi_in (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_A1 (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_Y1 (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_y_cpu_core (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_numvec (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_XLEN (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_YLEN (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_ZLEN (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_ovlp (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_xblock (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_yblock (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_zblock (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_num_ele (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_num_ele_A1 (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_M (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_Q (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_DM_A (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_DX (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_DY (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_DZ (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_dual_scmc_set_parameter_DT (c_dm_calc_hamt_dual_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_init (c_pscmc_env *  pe ,c_dm_cayley_eqn_core_struct *  kerstr )
;
void  c_dm_cayley_eqn_core_get_struct_len (size_t *  len )
;
int  c_dm_cayley_eqn_core_get_xlen ()
;
int  c_dm_cayley_eqn_core_get_num_compute_units (c_dm_cayley_eqn_core_struct *  kerstr )
;
int  c_dm_cayley_eqn_core_exec (c_dm_cayley_eqn_core_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_dphi_dt_out (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_phi_in (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_A1 (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_Y1 (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_y_cpu_core (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_numvec (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_XLEN (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_YLEN (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_ZLEN (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_ovlp (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_xblock (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_yblock (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_zblock (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_num_ele (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_num_ele_A1 (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_M (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_Q (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_DM_A (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_DX (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_DY (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_DZ (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_core_scmc_set_parameter_DT (c_dm_cayley_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_init (c_pscmc_env *  pe ,c_dm_exact_eqn_m_struct *  kerstr )
;
void  c_dm_exact_eqn_m_get_struct_len (size_t *  len )
;
int  c_dm_exact_eqn_m_get_xlen ()
;
int  c_dm_exact_eqn_m_get_num_compute_units (c_dm_exact_eqn_m_struct *  kerstr )
;
int  c_dm_exact_eqn_m_exec (c_dm_exact_eqn_m_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_dphi_dt_out (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_phi_in (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_A1 (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_Y1 (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_y_cpu_core (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_numvec (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_XLEN (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_YLEN (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_ZLEN (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_ovlp (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_xblock (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_yblock (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_zblock (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_num_ele (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_num_ele_A1 (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_M (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_Q (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_DM_A (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_DX (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_DY (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_DZ (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_exact_eqn_m_scmc_set_parameter_DT (c_dm_exact_eqn_m_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_init (c_pscmc_env *  pe ,c_dm_calc_hamt_struct *  kerstr )
;
void  c_dm_calc_hamt_get_struct_len (size_t *  len )
;
int  c_dm_calc_hamt_get_xlen ()
;
int  c_dm_calc_hamt_get_num_compute_units (c_dm_calc_hamt_struct *  kerstr )
;
int  c_dm_calc_hamt_exec (c_dm_calc_hamt_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_dm_calc_hamt_scmc_set_parameter_dphi_dt_out (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_phi_in (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_A1 (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_Y1 (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_y_cpu_core (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_numvec (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_XLEN (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_YLEN (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_ZLEN (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_ovlp (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_xblock (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_yblock (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_zblock (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_num_ele (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_num_ele_A1 (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_M (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_Q (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_DM_A (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_DX (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_DY (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_DZ (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_calc_hamt_scmc_set_parameter_DT (c_dm_calc_hamt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_init (c_pscmc_env *  pe ,c_dm_cayley_eqn_J_struct *  kerstr )
;
void  c_dm_cayley_eqn_J_get_struct_len (size_t *  len )
;
int  c_dm_cayley_eqn_J_get_xlen ()
;
int  c_dm_cayley_eqn_J_get_num_compute_units (c_dm_cayley_eqn_J_struct *  kerstr )
;
int  c_dm_cayley_eqn_J_exec (c_dm_cayley_eqn_J_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_dphi_dt_out (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_phi_in (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_A1 (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_Y1 (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_y_cpu_core (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_numvec (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_XLEN (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_YLEN (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_ZLEN (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_ovlp (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_xblock (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_yblock (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_zblock (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_num_ele (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_num_ele_A1 (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_M (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_Q (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_DM_A (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_DX (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_DY (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_DZ (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_cayley_eqn_J_scmc_set_parameter_DT (c_dm_cayley_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_init (c_pscmc_env *  pe ,c_dm_bihamt_eqn_dydt_struct *  kerstr )
;
void  c_dm_bihamt_eqn_dydt_get_struct_len (size_t *  len )
;
int  c_dm_bihamt_eqn_dydt_get_xlen ()
;
int  c_dm_bihamt_eqn_dydt_get_num_compute_units (c_dm_bihamt_eqn_dydt_struct *  kerstr )
;
int  c_dm_bihamt_eqn_dydt_exec (c_dm_bihamt_eqn_dydt_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_dphi_dt_out (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_phi_in (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_A1 (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_Y1 (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_y_cpu_core (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_numvec (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_XLEN (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_YLEN (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_ZLEN (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_ovlp (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_xblock (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_yblock (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_zblock (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_num_ele (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_num_ele_A1 (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_M (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_Q (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_DM_A (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_DX (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_DY (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_DZ (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_eqn_dydt_scmc_set_parameter_DT (c_dm_bihamt_eqn_dydt_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_init (c_pscmc_env *  pe ,c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr )
;
void  c_dm_bihamt_dual_psi_eqn_J_get_struct_len (size_t *  len )
;
int  c_dm_bihamt_dual_psi_eqn_J_get_xlen ()
;
int  c_dm_bihamt_dual_psi_eqn_J_get_num_compute_units (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr )
;
int  c_dm_bihamt_dual_psi_eqn_J_exec (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_dphi_dt_out (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_phi_in (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_A1 (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_Y1 (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_y_cpu_core (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_numvec (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_XLEN (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_YLEN (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_ZLEN (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_ovlp (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_xblock (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_yblock (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_zblock (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_num_ele (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_num_ele_A1 (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_M (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_Q (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_DM_A (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_DX (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_DY (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_DZ (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_bihamt_dual_psi_eqn_J_scmc_set_parameter_DT (c_dm_bihamt_dual_psi_eqn_J_struct *  kerstr ,c_pscmc_mem *  pm )
;
void  c_dm_1st_eqn_fdtd_scmc_kernel (double *  phi_out ,double *  phi_in ,double *  phi_1 ,double *  A1 ,double *  A2 ,double *  A3 ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_A1 ,double  DT ,double  M ,double  Q ,double  DM_A ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_dm_1st_eqn_core_scmc_kernel (double *  phi_out ,double *  phi_in ,double *  phi_1 ,double *  A1 ,double *  A2 ,double *  A3 ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_A1 ,double  DT ,double  M ,double  Q ,double  DM_A ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_dm_1st_eqn_right_scmc_kernel (double *  phi_out ,double *  phi_in ,double *  phi_1 ,double *  A1 ,double *  A2 ,double *  A3 ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_A1 ,double  DT ,double  M ,double  Q ,double  DM_A ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  c_dm_1st_eqn_right_init (c_pscmc_env *  pe ,c_dm_1st_eqn_right_struct *  kerstr )
;
void  c_dm_1st_eqn_right_get_struct_len (size_t *  len )
;
int  c_dm_1st_eqn_right_get_xlen ()
;
int  c_dm_1st_eqn_right_get_num_compute_units (c_dm_1st_eqn_right_struct *  kerstr )
;
int  c_dm_1st_eqn_right_exec (c_dm_1st_eqn_right_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_phi_out (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_phi_in (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_phi_1 (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_A1 (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_A2 (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_A3 (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_y_cpu_core (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_numvec (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_XLEN (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_YLEN (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_ZLEN (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_ovlp (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_xblock (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_yblock (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_zblock (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_num_ele (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_num_ele_A1 (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_DT (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_M (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_Q (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_right_scmc_set_parameter_DM_A (c_dm_1st_eqn_right_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_init (c_pscmc_env *  pe ,c_dm_1st_eqn_core_struct *  kerstr )
;
void  c_dm_1st_eqn_core_get_struct_len (size_t *  len )
;
int  c_dm_1st_eqn_core_get_xlen ()
;
int  c_dm_1st_eqn_core_get_num_compute_units (c_dm_1st_eqn_core_struct *  kerstr )
;
int  c_dm_1st_eqn_core_exec (c_dm_1st_eqn_core_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_phi_out (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_phi_in (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_phi_1 (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_A1 (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_A2 (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_A3 (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_y_cpu_core (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_numvec (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_XLEN (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_YLEN (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_ZLEN (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_ovlp (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_xblock (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_yblock (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_zblock (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_num_ele (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_num_ele_A1 (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_DT (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_M (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_Q (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_core_scmc_set_parameter_DM_A (c_dm_1st_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_init (c_pscmc_env *  pe ,c_dm_1st_eqn_fdtd_struct *  kerstr )
;
void  c_dm_1st_eqn_fdtd_get_struct_len (size_t *  len )
;
int  c_dm_1st_eqn_fdtd_get_xlen ()
;
int  c_dm_1st_eqn_fdtd_get_num_compute_units (c_dm_1st_eqn_fdtd_struct *  kerstr )
;
int  c_dm_1st_eqn_fdtd_exec (c_dm_1st_eqn_fdtd_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_phi_out (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_phi_in (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_phi_1 (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_A1 (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_A2 (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_A3 (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_y_cpu_core (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_numvec (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_XLEN (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_YLEN (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_ZLEN (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_ovlp (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_xblock (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_yblock (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_zblock (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_num_ele (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_num_ele_A1 (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_DT (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_M (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_Q (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_dm_1st_eqn_fdtd_scmc_set_parameter_DM_A (c_dm_1st_eqn_fdtd_struct *  kerstr ,c_pscmc_mem *  pm )
;
void  c_RECT_YEE_CURL_L_scmc_kernel (double *  inoutE1 ,double *  inB0 ,int *  xoffset ,int *  yoffset ,int *  zoffset ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  c_RECT_YEE_CURL_L_init (c_pscmc_env *  pe ,c_RECT_YEE_CURL_L_struct *  kerstr )
;
void  c_RECT_YEE_CURL_L_get_struct_len (size_t *  len )
;
int  c_RECT_YEE_CURL_L_get_xlen ()
;
int  c_RECT_YEE_CURL_L_get_num_compute_units (c_RECT_YEE_CURL_L_struct *  kerstr )
;
int  c_RECT_YEE_CURL_L_exec (c_RECT_YEE_CURL_L_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_RECT_YEE_CURL_L_scmc_set_parameter_inoutE1 (c_RECT_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_RECT_YEE_CURL_L_scmc_set_parameter_inB0 (c_RECT_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_RECT_YEE_CURL_L_scmc_set_parameter_xoffset (c_RECT_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_RECT_YEE_CURL_L_scmc_set_parameter_yoffset (c_RECT_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_RECT_YEE_CURL_L_scmc_set_parameter_zoffset (c_RECT_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_RECT_YEE_CURL_L_scmc_set_parameter_y_cpu_core (c_RECT_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_RECT_YEE_CURL_L_scmc_set_parameter_numvec (c_RECT_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_RECT_YEE_CURL_L_scmc_set_parameter_XLEN (c_RECT_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_RECT_YEE_CURL_L_scmc_set_parameter_YLEN (c_RECT_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_RECT_YEE_CURL_L_scmc_set_parameter_ZLEN (c_RECT_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_RECT_YEE_CURL_L_scmc_set_parameter_ovlp (c_RECT_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_RECT_YEE_CURL_L_scmc_set_parameter_xblock (c_RECT_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_RECT_YEE_CURL_L_scmc_set_parameter_yblock (c_RECT_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_RECT_YEE_CURL_L_scmc_set_parameter_zblock (c_RECT_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_RECT_YEE_CURL_L_scmc_set_parameter_num_ele (c_RECT_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_RECT_YEE_CURL_L_scmc_set_parameter_DT (c_RECT_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_RECT_YEE_CURL_L_scmc_set_parameter_DELTA_X (c_RECT_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_RECT_YEE_CURL_L_scmc_set_parameter_DELTA_Y (c_RECT_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_RECT_YEE_CURL_L_scmc_set_parameter_DELTA_Z (c_RECT_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
void  c_GEO_YEE_CURL_L_scmc_kernel (double *  inoutE1 ,double *  inB0 ,int *  xoffset ,int *  yoffset ,int *  zoffset ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,double  DELTA_Z ,double  DELTA_Y ,double  DELTA_X ,double  x0 ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_YEE_CURL_R_scmc_kernel (double *  inoutE1 ,double *  inB0 ,int *  xoffset ,int *  yoffset ,int *  zoffset ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  c_YEE_CURL_R_init (c_pscmc_env *  pe ,c_YEE_CURL_R_struct *  kerstr )
;
void  c_YEE_CURL_R_get_struct_len (size_t *  len )
;
int  c_YEE_CURL_R_get_xlen ()
;
int  c_YEE_CURL_R_get_num_compute_units (c_YEE_CURL_R_struct *  kerstr )
;
int  c_YEE_CURL_R_exec (c_YEE_CURL_R_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_YEE_CURL_R_scmc_set_parameter_inoutE1 (c_YEE_CURL_R_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_YEE_CURL_R_scmc_set_parameter_inB0 (c_YEE_CURL_R_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_YEE_CURL_R_scmc_set_parameter_xoffset (c_YEE_CURL_R_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_YEE_CURL_R_scmc_set_parameter_yoffset (c_YEE_CURL_R_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_YEE_CURL_R_scmc_set_parameter_zoffset (c_YEE_CURL_R_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_YEE_CURL_R_scmc_set_parameter_y_cpu_core (c_YEE_CURL_R_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_YEE_CURL_R_scmc_set_parameter_numvec (c_YEE_CURL_R_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_YEE_CURL_R_scmc_set_parameter_XLEN (c_YEE_CURL_R_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_YEE_CURL_R_scmc_set_parameter_YLEN (c_YEE_CURL_R_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_YEE_CURL_R_scmc_set_parameter_ZLEN (c_YEE_CURL_R_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_YEE_CURL_R_scmc_set_parameter_ovlp (c_YEE_CURL_R_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_YEE_CURL_R_scmc_set_parameter_xblock (c_YEE_CURL_R_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_YEE_CURL_R_scmc_set_parameter_yblock (c_YEE_CURL_R_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_YEE_CURL_R_scmc_set_parameter_zblock (c_YEE_CURL_R_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_YEE_CURL_R_scmc_set_parameter_num_ele (c_YEE_CURL_R_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_YEE_CURL_R_scmc_set_parameter_DT (c_YEE_CURL_R_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_init (c_pscmc_env *  pe ,c_GEO_YEE_CURL_L_struct *  kerstr )
;
void  c_GEO_YEE_CURL_L_get_struct_len (size_t *  len )
;
int  c_GEO_YEE_CURL_L_get_xlen ()
;
int  c_GEO_YEE_CURL_L_get_num_compute_units (c_GEO_YEE_CURL_L_struct *  kerstr )
;
int  c_GEO_YEE_CURL_L_exec (c_GEO_YEE_CURL_L_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_inoutE1 (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_inB0 (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_xoffset (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_yoffset (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_zoffset (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_y_cpu_core (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_numvec (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_XLEN (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_YLEN (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_ZLEN (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_ovlp (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_xblock (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_yblock (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_zblock (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_num_ele (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_DT (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_Z (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_Y (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_X (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_GEO_YEE_CURL_L_scmc_set_parameter_x0 (c_GEO_YEE_CURL_L_struct *  kerstr ,c_pscmc_mem *  pm )
;

#include "local_header.h"
int  c_pscmc_mem_init (c_pscmc_env *  pe ,c_pscmc_mem *  pm ,int  type ,size_t  len )
;
int  c_pscmc_flush (c_pscmc_env *  pe )
;
void *  c_pscmc_get_h_data (c_pscmc_mem *  pm ,void * *  h_data )
;
int  c_pscmc_get_env_len (size_t *  l )
;
int  c_pscmc_get_local_len ()
;
int  c_pscmc_mem_destroy (c_pscmc_mem *  pm )
;
int  c_pscmc_get_num_compute_units (c_pscmc_env *  pe )
;
int  c_pscmc_mem_sync_d2h (c_pscmc_mem *  pm )
;
int  c_pscmc_mem_sync_h2d (c_pscmc_mem *  pm )
;
int  c_pscmc_env_init (c_pscmc_env *  pe ,int  dev_num ,void *  fv )
;
size_t  c_pscmc_mem_get_num (c_pscmc_mem *  pm )
;
