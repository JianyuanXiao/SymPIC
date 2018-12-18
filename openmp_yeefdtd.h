void  openmp_Yee_FDTD_Curl_E_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_Yee_FDTD_Curl_E_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_Yee_FDTD_Curl_B_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_Yee_FDTD_Curl_B_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_Yee_FDTD_Grad_BWD_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_Yee_FDTD_Grad_BWD_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_Yee_FDTD_Grad_FWD_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_Yee_FDTD_Grad_FWD_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_Yee_FDTD_Curl_BWD_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_Yee_FDTD_Curl_BWD_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_Yee_FDTD_Curl_FWD_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_Yee_FDTD_Curl_FWD_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_Yee_FDTD_Div_BWD_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_Yee_FDTD_Div_BWD_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_Yee_FDTD_Div_FWD_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_Yee_FDTD_Div_FWD_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_merge_current_2_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_merge_current_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_PML_FDTD_CURL_FWD_scmc_kernel (double *  outEB ,double *  inEB ,double *  outPMLEB ,double *  inPMLEB ,int *  xoffset ,int *  yoffset ,int *  zoffset ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,double  M ,double  Q ,double  DX ,double  DY ,double  DZ ,int  abc_dir ,int  level ,int  pml_m ,double  max_sigma ,long  allxmax ,long  allymax ,long  allzmax ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_PML_FDTD_CURL_BWD_scmc_kernel (double *  outEB ,double *  inEB ,double *  outPMLEB ,double *  inPMLEB ,int *  xoffset ,int *  yoffset ,int *  zoffset ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,double  M ,double  Q ,double  DX ,double  DY ,double  DZ ,int  abc_dir ,int  level ,int  pml_m ,double  max_sigma ,long  allxmax ,long  allymax ,long  allzmax ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_kgm_calc_rho_scmc_kernel (double *  outEB ,double *  inEB ,int *  xoffset ,int *  yoffset ,int *  zoffset ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,double  M ,double  Q ,double  DX ,double  refz0 ,double  q ,double  dtodx ,int  mode ,int  swap_input ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_kgm_eqn_core_scmc_kernel (double *  outEB ,double *  inEB ,int *  xoffset ,int *  yoffset ,int *  zoffset ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,double  M ,double  Q ,double  DX ,double  GEXT ,double  rfz0 ,int  swap_input ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  openmp_kgm_eqn_core_init (openmp_pscmc_env *  pe ,openmp_kgm_eqn_core_struct *  kerstr )
;
void  openmp_kgm_eqn_core_get_struct_len (size_t *  len )
;
int  openmp_kgm_eqn_core_get_num_compute_units (openmp_kgm_eqn_core_struct *  kerstr )
;
int  openmp_kgm_eqn_core_get_xlen ()
;
int  openmp_kgm_eqn_core_exec (openmp_kgm_eqn_core_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_outEB (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_inEB (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_xoffset (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_yoffset (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_zoffset (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_y_cpu_core (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_numvec (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_XLEN (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_YLEN (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_ZLEN (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_ovlp (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_xblock (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_yblock (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_zblock (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_num_ele (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_DT (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_M (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_Q (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_DX (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_GEXT (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_rfz0 (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_swap_input (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_init (openmp_pscmc_env *  pe ,openmp_kgm_calc_rho_struct *  kerstr )
;
void  openmp_kgm_calc_rho_get_struct_len (size_t *  len )
;
int  openmp_kgm_calc_rho_get_num_compute_units (openmp_kgm_calc_rho_struct *  kerstr )
;
int  openmp_kgm_calc_rho_get_xlen ()
;
int  openmp_kgm_calc_rho_exec (openmp_kgm_calc_rho_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_outEB (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_inEB (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_xoffset (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_yoffset (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_zoffset (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_y_cpu_core (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_numvec (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_XLEN (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_YLEN (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_ZLEN (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_ovlp (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_xblock (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_yblock (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_zblock (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_num_ele (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_DT (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_M (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_Q (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_DX (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_refz0 (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_q (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_dtodx (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_mode (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_calc_rho_scmc_set_parameter_swap_input (openmp_kgm_calc_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_init (openmp_pscmc_env *  pe ,openmp_PML_FDTD_CURL_BWD_struct *  kerstr )
;
void  openmp_PML_FDTD_CURL_BWD_get_struct_len (size_t *  len )
;
int  openmp_PML_FDTD_CURL_BWD_get_num_compute_units (openmp_PML_FDTD_CURL_BWD_struct *  kerstr )
;
int  openmp_PML_FDTD_CURL_BWD_get_xlen ()
;
int  openmp_PML_FDTD_CURL_BWD_exec (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_outEB (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_inEB (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_outPMLEB (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_inPMLEB (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_xoffset (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_yoffset (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_zoffset (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_y_cpu_core (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_numvec (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_XLEN (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_YLEN (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_ZLEN (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_ovlp (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_xblock (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_yblock (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_zblock (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_num_ele (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_DT (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_M (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_Q (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_DX (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_DY (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_DZ (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_abc_dir (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_level (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_pml_m (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_max_sigma (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_allxmax (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_allymax (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_BWD_scmc_set_parameter_allzmax (openmp_PML_FDTD_CURL_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_init (openmp_pscmc_env *  pe ,openmp_PML_FDTD_CURL_FWD_struct *  kerstr )
;
void  openmp_PML_FDTD_CURL_FWD_get_struct_len (size_t *  len )
;
int  openmp_PML_FDTD_CURL_FWD_get_num_compute_units (openmp_PML_FDTD_CURL_FWD_struct *  kerstr )
;
int  openmp_PML_FDTD_CURL_FWD_get_xlen ()
;
int  openmp_PML_FDTD_CURL_FWD_exec (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_outEB (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_inEB (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_outPMLEB (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_inPMLEB (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_xoffset (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_yoffset (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_zoffset (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_y_cpu_core (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_numvec (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_XLEN (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_YLEN (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_ZLEN (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_ovlp (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_xblock (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_yblock (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_zblock (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_num_ele (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_DT (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_M (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_Q (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_DX (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_DY (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_DZ (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_abc_dir (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_level (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_pml_m (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_max_sigma (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_allxmax (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_allymax (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_PML_FDTD_CURL_FWD_scmc_set_parameter_allzmax (openmp_PML_FDTD_CURL_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_init (openmp_pscmc_env *  pe ,openmp_merge_current_struct *  kerstr )
;
void  openmp_merge_current_get_struct_len (size_t *  len )
;
int  openmp_merge_current_get_num_compute_units (openmp_merge_current_struct *  kerstr )
;
int  openmp_merge_current_get_xlen ()
;
int  openmp_merge_current_exec (openmp_merge_current_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_merge_current_scmc_set_parameter_outEB (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_scmc_set_parameter_inEB (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_scmc_set_parameter_y_cpu_core (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_scmc_set_parameter_numvec (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_scmc_set_parameter_XLEN (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_scmc_set_parameter_YLEN (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_scmc_set_parameter_ZLEN (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_scmc_set_parameter_ovlp (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_scmc_set_parameter_xblock (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_scmc_set_parameter_yblock (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_scmc_set_parameter_zblock (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_scmc_set_parameter_num_ele (openmp_merge_current_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_2_init (openmp_pscmc_env *  pe ,openmp_merge_current_2_struct *  kerstr )
;
void  openmp_merge_current_2_get_struct_len (size_t *  len )
;
int  openmp_merge_current_2_get_num_compute_units (openmp_merge_current_2_struct *  kerstr )
;
int  openmp_merge_current_2_get_xlen ()
;
int  openmp_merge_current_2_exec (openmp_merge_current_2_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_merge_current_2_scmc_set_parameter_outEB (openmp_merge_current_2_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_2_scmc_set_parameter_inEB (openmp_merge_current_2_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_2_scmc_set_parameter_y_cpu_core (openmp_merge_current_2_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_2_scmc_set_parameter_numvec (openmp_merge_current_2_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_2_scmc_set_parameter_XLEN (openmp_merge_current_2_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_2_scmc_set_parameter_YLEN (openmp_merge_current_2_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_2_scmc_set_parameter_ZLEN (openmp_merge_current_2_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_2_scmc_set_parameter_ovlp (openmp_merge_current_2_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_2_scmc_set_parameter_xblock (openmp_merge_current_2_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_2_scmc_set_parameter_yblock (openmp_merge_current_2_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_2_scmc_set_parameter_zblock (openmp_merge_current_2_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_current_2_scmc_set_parameter_num_ele (openmp_merge_current_2_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_4th_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr )
;
void  openmp_Yee_FDTD_Div_FWD_4th_get_struct_len (size_t *  len )
;
int  openmp_Yee_FDTD_Div_FWD_4th_get_num_compute_units (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr )
;
int  openmp_Yee_FDTD_Div_FWD_4th_get_xlen ()
;
int  openmp_Yee_FDTD_Div_FWD_4th_exec (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_outEB (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_inEB (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_numvec (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_xblock (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_yblock (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_zblock (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_DT (openmp_Yee_FDTD_Div_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Div_FWD_struct *  kerstr )
;
void  openmp_Yee_FDTD_Div_FWD_get_struct_len (size_t *  len )
;
int  openmp_Yee_FDTD_Div_FWD_get_num_compute_units (openmp_Yee_FDTD_Div_FWD_struct *  kerstr )
;
int  openmp_Yee_FDTD_Div_FWD_get_xlen ()
;
int  openmp_Yee_FDTD_Div_FWD_exec (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_outEB (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_inEB (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_numvec (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_xblock (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_yblock (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_zblock (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_FWD_scmc_set_parameter_DT (openmp_Yee_FDTD_Div_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_4th_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr )
;
void  openmp_Yee_FDTD_Div_BWD_4th_get_struct_len (size_t *  len )
;
int  openmp_Yee_FDTD_Div_BWD_4th_get_num_compute_units (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr )
;
int  openmp_Yee_FDTD_Div_BWD_4th_get_xlen ()
;
int  openmp_Yee_FDTD_Div_BWD_4th_exec (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_outEB (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_inEB (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_numvec (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_xblock (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_yblock (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_zblock (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_DT (openmp_Yee_FDTD_Div_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Div_BWD_struct *  kerstr )
;
void  openmp_Yee_FDTD_Div_BWD_get_struct_len (size_t *  len )
;
int  openmp_Yee_FDTD_Div_BWD_get_num_compute_units (openmp_Yee_FDTD_Div_BWD_struct *  kerstr )
;
int  openmp_Yee_FDTD_Div_BWD_get_xlen ()
;
int  openmp_Yee_FDTD_Div_BWD_exec (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_outEB (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_inEB (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_numvec (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_xblock (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_yblock (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_zblock (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Div_BWD_scmc_set_parameter_DT (openmp_Yee_FDTD_Div_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_4th_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr )
;
void  openmp_Yee_FDTD_Curl_FWD_4th_get_struct_len (size_t *  len )
;
int  openmp_Yee_FDTD_Curl_FWD_4th_get_num_compute_units (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr )
;
int  openmp_Yee_FDTD_Curl_FWD_4th_get_xlen ()
;
int  openmp_Yee_FDTD_Curl_FWD_4th_exec (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_outEB (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_inEB (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_numvec (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_xblock (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_yblock (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_zblock (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_DT (openmp_Yee_FDTD_Curl_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Curl_FWD_struct *  kerstr )
;
void  openmp_Yee_FDTD_Curl_FWD_get_struct_len (size_t *  len )
;
int  openmp_Yee_FDTD_Curl_FWD_get_num_compute_units (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr )
;
int  openmp_Yee_FDTD_Curl_FWD_get_xlen ()
;
int  openmp_Yee_FDTD_Curl_FWD_exec (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_outEB (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_inEB (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_numvec (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_xblock (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_yblock (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_zblock (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_FWD_scmc_set_parameter_DT (openmp_Yee_FDTD_Curl_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_4th_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr )
;
void  openmp_Yee_FDTD_Curl_BWD_4th_get_struct_len (size_t *  len )
;
int  openmp_Yee_FDTD_Curl_BWD_4th_get_num_compute_units (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr )
;
int  openmp_Yee_FDTD_Curl_BWD_4th_get_xlen ()
;
int  openmp_Yee_FDTD_Curl_BWD_4th_exec (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_outEB (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_inEB (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_numvec (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_xblock (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_yblock (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_zblock (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_DT (openmp_Yee_FDTD_Curl_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Curl_BWD_struct *  kerstr )
;
void  openmp_Yee_FDTD_Curl_BWD_get_struct_len (size_t *  len )
;
int  openmp_Yee_FDTD_Curl_BWD_get_num_compute_units (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr )
;
int  openmp_Yee_FDTD_Curl_BWD_get_xlen ()
;
int  openmp_Yee_FDTD_Curl_BWD_exec (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_outEB (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_inEB (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_numvec (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_xblock (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_yblock (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_zblock (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_BWD_scmc_set_parameter_DT (openmp_Yee_FDTD_Curl_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_4th_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr )
;
void  openmp_Yee_FDTD_Grad_FWD_4th_get_struct_len (size_t *  len )
;
int  openmp_Yee_FDTD_Grad_FWD_4th_get_num_compute_units (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr )
;
int  openmp_Yee_FDTD_Grad_FWD_4th_get_xlen ()
;
int  openmp_Yee_FDTD_Grad_FWD_4th_exec (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_outEB (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_inEB (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_numvec (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_xblock (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_yblock (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_zblock (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_DT (openmp_Yee_FDTD_Grad_FWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Grad_FWD_struct *  kerstr )
;
void  openmp_Yee_FDTD_Grad_FWD_get_struct_len (size_t *  len )
;
int  openmp_Yee_FDTD_Grad_FWD_get_num_compute_units (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr )
;
int  openmp_Yee_FDTD_Grad_FWD_get_xlen ()
;
int  openmp_Yee_FDTD_Grad_FWD_exec (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_outEB (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_inEB (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_numvec (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_xblock (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_yblock (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_zblock (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_FWD_scmc_set_parameter_DT (openmp_Yee_FDTD_Grad_FWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_4th_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr )
;
void  openmp_Yee_FDTD_Grad_BWD_4th_get_struct_len (size_t *  len )
;
int  openmp_Yee_FDTD_Grad_BWD_4th_get_num_compute_units (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr )
;
int  openmp_Yee_FDTD_Grad_BWD_4th_get_xlen ()
;
int  openmp_Yee_FDTD_Grad_BWD_4th_exec (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_outEB (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_inEB (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_numvec (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_xblock (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_yblock (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_zblock (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_DT (openmp_Yee_FDTD_Grad_BWD_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Grad_BWD_struct *  kerstr )
;
void  openmp_Yee_FDTD_Grad_BWD_get_struct_len (size_t *  len )
;
int  openmp_Yee_FDTD_Grad_BWD_get_num_compute_units (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr )
;
int  openmp_Yee_FDTD_Grad_BWD_get_xlen ()
;
int  openmp_Yee_FDTD_Grad_BWD_exec (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_outEB (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_inEB (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_numvec (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_xblock (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_yblock (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_zblock (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Grad_BWD_scmc_set_parameter_DT (openmp_Yee_FDTD_Grad_BWD_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_4th_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr )
;
void  openmp_Yee_FDTD_Curl_B_4th_get_struct_len (size_t *  len )
;
int  openmp_Yee_FDTD_Curl_B_4th_get_num_compute_units (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr )
;
int  openmp_Yee_FDTD_Curl_B_4th_get_xlen ()
;
int  openmp_Yee_FDTD_Curl_B_4th_exec (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_outEB (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_inEB (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_numvec (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_xblock (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_yblock (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_zblock (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_4th_scmc_set_parameter_DT (openmp_Yee_FDTD_Curl_B_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Curl_B_struct *  kerstr )
;
void  openmp_Yee_FDTD_Curl_B_get_struct_len (size_t *  len )
;
int  openmp_Yee_FDTD_Curl_B_get_num_compute_units (openmp_Yee_FDTD_Curl_B_struct *  kerstr )
;
int  openmp_Yee_FDTD_Curl_B_get_xlen ()
;
int  openmp_Yee_FDTD_Curl_B_exec (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_outEB (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_inEB (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_numvec (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_xblock (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_yblock (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_zblock (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_B_scmc_set_parameter_DT (openmp_Yee_FDTD_Curl_B_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_4th_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr )
;
void  openmp_Yee_FDTD_Curl_E_4th_get_struct_len (size_t *  len )
;
int  openmp_Yee_FDTD_Curl_E_4th_get_num_compute_units (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr )
;
int  openmp_Yee_FDTD_Curl_E_4th_get_xlen ()
;
int  openmp_Yee_FDTD_Curl_E_4th_exec (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_outEB (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_inEB (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_numvec (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_xblock (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_yblock (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_zblock (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_4th_scmc_set_parameter_DT (openmp_Yee_FDTD_Curl_E_4th_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_Curl_E_struct *  kerstr )
;
void  openmp_Yee_FDTD_Curl_E_get_struct_len (size_t *  len )
;
int  openmp_Yee_FDTD_Curl_E_get_num_compute_units (openmp_Yee_FDTD_Curl_E_struct *  kerstr )
;
int  openmp_Yee_FDTD_Curl_E_get_xlen ()
;
int  openmp_Yee_FDTD_Curl_E_exec (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_outEB (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_inEB (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_numvec (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_XLEN (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_YLEN (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_ovlp (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_xblock (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_yblock (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_zblock (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_num_ele (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_Yee_FDTD_Curl_E_scmc_set_parameter_DT (openmp_Yee_FDTD_Curl_E_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
void  openmp_yee_local_scmc_kernel (double *  inout ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_sync_ovlp_o2m_scmc_kernel (double *  vecmain ,double *  vecovlp ,int  ovlpindex ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_sync_ovlp_m2o_scmc_kernel (double *  vecmain ,double *  vecovlp ,int  ovlpindex ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_merge_ovlp_o2m_scmc_kernel (double *  vecmain ,double *  vecovlp ,int  ovlpindex ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_merge_ovlp_m2o_scmc_kernel (double *  vecmain ,double *  vecovlp ,int  ovlpindex ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  openmp_merge_ovlp_m2o_init (openmp_pscmc_env *  pe ,openmp_merge_ovlp_m2o_struct *  kerstr )
;
void  openmp_merge_ovlp_m2o_get_struct_len (size_t *  len )
;
int  openmp_merge_ovlp_m2o_get_num_compute_units (openmp_merge_ovlp_m2o_struct *  kerstr )
;
int  openmp_merge_ovlp_m2o_get_xlen ()
;
int  openmp_merge_ovlp_m2o_exec (openmp_merge_ovlp_m2o_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_merge_ovlp_m2o_scmc_set_parameter_vecmain (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_ovlp_m2o_scmc_set_parameter_vecovlp (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_ovlp_m2o_scmc_set_parameter_ovlpindex (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_ovlp_m2o_scmc_set_parameter_numvec (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_ovlp_m2o_scmc_set_parameter_num_ele (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_ovlp_m2o_scmc_set_parameter_xblock (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_ovlp_m2o_scmc_set_parameter_yblock (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_ovlp_m2o_scmc_set_parameter_zblock (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_ovlp_m2o_scmc_set_parameter_ovlp (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_ovlp_o2m_init (openmp_pscmc_env *  pe ,openmp_merge_ovlp_o2m_struct *  kerstr )
;
void  openmp_merge_ovlp_o2m_get_struct_len (size_t *  len )
;
int  openmp_merge_ovlp_o2m_get_num_compute_units (openmp_merge_ovlp_o2m_struct *  kerstr )
;
int  openmp_merge_ovlp_o2m_get_xlen ()
;
int  openmp_merge_ovlp_o2m_exec (openmp_merge_ovlp_o2m_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_merge_ovlp_o2m_scmc_set_parameter_vecmain (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_ovlp_o2m_scmc_set_parameter_vecovlp (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_ovlp_o2m_scmc_set_parameter_ovlpindex (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_ovlp_o2m_scmc_set_parameter_numvec (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_ovlp_o2m_scmc_set_parameter_num_ele (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_ovlp_o2m_scmc_set_parameter_xblock (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_ovlp_o2m_scmc_set_parameter_yblock (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_ovlp_o2m_scmc_set_parameter_zblock (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_merge_ovlp_o2m_scmc_set_parameter_ovlp (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sync_ovlp_m2o_init (openmp_pscmc_env *  pe ,openmp_sync_ovlp_m2o_struct *  kerstr )
;
void  openmp_sync_ovlp_m2o_get_struct_len (size_t *  len )
;
int  openmp_sync_ovlp_m2o_get_num_compute_units (openmp_sync_ovlp_m2o_struct *  kerstr )
;
int  openmp_sync_ovlp_m2o_get_xlen ()
;
int  openmp_sync_ovlp_m2o_exec (openmp_sync_ovlp_m2o_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_sync_ovlp_m2o_scmc_set_parameter_vecmain (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sync_ovlp_m2o_scmc_set_parameter_vecovlp (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sync_ovlp_m2o_scmc_set_parameter_ovlpindex (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sync_ovlp_m2o_scmc_set_parameter_numvec (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sync_ovlp_m2o_scmc_set_parameter_num_ele (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sync_ovlp_m2o_scmc_set_parameter_xblock (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sync_ovlp_m2o_scmc_set_parameter_yblock (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sync_ovlp_m2o_scmc_set_parameter_zblock (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sync_ovlp_m2o_scmc_set_parameter_ovlp (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sync_ovlp_o2m_init (openmp_pscmc_env *  pe ,openmp_sync_ovlp_o2m_struct *  kerstr )
;
void  openmp_sync_ovlp_o2m_get_struct_len (size_t *  len )
;
int  openmp_sync_ovlp_o2m_get_num_compute_units (openmp_sync_ovlp_o2m_struct *  kerstr )
;
int  openmp_sync_ovlp_o2m_get_xlen ()
;
int  openmp_sync_ovlp_o2m_exec (openmp_sync_ovlp_o2m_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_sync_ovlp_o2m_scmc_set_parameter_vecmain (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sync_ovlp_o2m_scmc_set_parameter_vecovlp (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sync_ovlp_o2m_scmc_set_parameter_ovlpindex (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sync_ovlp_o2m_scmc_set_parameter_numvec (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sync_ovlp_o2m_scmc_set_parameter_num_ele (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sync_ovlp_o2m_scmc_set_parameter_xblock (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sync_ovlp_o2m_scmc_set_parameter_yblock (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sync_ovlp_o2m_scmc_set_parameter_zblock (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sync_ovlp_o2m_scmc_set_parameter_ovlp (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_local_init (openmp_pscmc_env *  pe ,openmp_yee_local_struct *  kerstr )
;
void  openmp_yee_local_get_struct_len (size_t *  len )
;
int  openmp_yee_local_get_num_compute_units (openmp_yee_local_struct *  kerstr )
;
int  openmp_yee_local_get_xlen ()
;
int  openmp_yee_local_exec (openmp_yee_local_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_local_scmc_set_parameter_inout (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_local_scmc_set_parameter_numvec (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_local_scmc_set_parameter_num_ele (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_local_scmc_set_parameter_xblock (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_local_scmc_set_parameter_yblock (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_local_scmc_set_parameter_zblock (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_local_scmc_set_parameter_ovlp (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
void  openmp_blas_yiszero_synced_scmc_kernel (double *  y ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_blas_yiszero_scmc_kernel (double *  y ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_blas_yisconst_scmc_kernel (double *  y ,double  a ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_blas_get_ITG_Potential_scmc_kernel (double *  y ,double *  x ,double *  u ,double  minus_over_q_e ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_blas_invy_scmc_kernel (double *  y ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_blas_yisax_scmc_kernel (double *  y ,double *  x ,double  a ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_blas_axpy_scmc_kernel (double *  y ,double *  x ,double  a ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_blas_axpby_scmc_kernel (double *  y ,double *  x ,double  a ,double  b ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_blas_mulxy_scmc_kernel (double *  y ,double *  x ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_blas_findmax_scmc_kernel (double *  y ,double *  rdcd ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_blas_dot_scmc_kernel (double *  y ,double *  x ,double *  rdcd ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_blas_sum_scmc_kernel (double *  y ,double *  rdcd ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  openmp_blas_sum_init (openmp_pscmc_env *  pe ,openmp_blas_sum_struct *  kerstr )
;
void  openmp_blas_sum_get_struct_len (size_t *  len )
;
int  openmp_blas_sum_get_num_compute_units (openmp_blas_sum_struct *  kerstr )
;
int  openmp_blas_sum_get_xlen ()
;
int  openmp_blas_sum_exec (openmp_blas_sum_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_blas_sum_scmc_set_parameter_y (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_sum_scmc_set_parameter_rdcd (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_sum_scmc_set_parameter_y_cpu_core (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_sum_scmc_set_parameter_numvec (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_sum_scmc_set_parameter_XLEN (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_sum_scmc_set_parameter_YLEN (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_sum_scmc_set_parameter_ZLEN (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_sum_scmc_set_parameter_ovlp (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_sum_scmc_set_parameter_xblock (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_sum_scmc_set_parameter_yblock (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_sum_scmc_set_parameter_zblock (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_sum_scmc_set_parameter_num_ele (openmp_blas_sum_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_dot_init (openmp_pscmc_env *  pe ,openmp_blas_dot_struct *  kerstr )
;
void  openmp_blas_dot_get_struct_len (size_t *  len )
;
int  openmp_blas_dot_get_num_compute_units (openmp_blas_dot_struct *  kerstr )
;
int  openmp_blas_dot_get_xlen ()
;
int  openmp_blas_dot_exec (openmp_blas_dot_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_blas_dot_scmc_set_parameter_y (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_dot_scmc_set_parameter_x (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_dot_scmc_set_parameter_rdcd (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_dot_scmc_set_parameter_y_cpu_core (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_dot_scmc_set_parameter_numvec (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_dot_scmc_set_parameter_XLEN (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_dot_scmc_set_parameter_YLEN (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_dot_scmc_set_parameter_ZLEN (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_dot_scmc_set_parameter_ovlp (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_dot_scmc_set_parameter_xblock (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_dot_scmc_set_parameter_yblock (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_dot_scmc_set_parameter_zblock (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_dot_scmc_set_parameter_num_ele (openmp_blas_dot_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_findmax_init (openmp_pscmc_env *  pe ,openmp_blas_findmax_struct *  kerstr )
;
void  openmp_blas_findmax_get_struct_len (size_t *  len )
;
int  openmp_blas_findmax_get_num_compute_units (openmp_blas_findmax_struct *  kerstr )
;
int  openmp_blas_findmax_get_xlen ()
;
int  openmp_blas_findmax_exec (openmp_blas_findmax_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_blas_findmax_scmc_set_parameter_y (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_findmax_scmc_set_parameter_rdcd (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_findmax_scmc_set_parameter_y_cpu_core (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_findmax_scmc_set_parameter_numvec (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_findmax_scmc_set_parameter_XLEN (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_findmax_scmc_set_parameter_YLEN (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_findmax_scmc_set_parameter_ZLEN (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_findmax_scmc_set_parameter_ovlp (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_findmax_scmc_set_parameter_xblock (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_findmax_scmc_set_parameter_yblock (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_findmax_scmc_set_parameter_zblock (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_findmax_scmc_set_parameter_num_ele (openmp_blas_findmax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_mulxy_init (openmp_pscmc_env *  pe ,openmp_blas_mulxy_struct *  kerstr )
;
void  openmp_blas_mulxy_get_struct_len (size_t *  len )
;
int  openmp_blas_mulxy_get_num_compute_units (openmp_blas_mulxy_struct *  kerstr )
;
int  openmp_blas_mulxy_get_xlen ()
;
int  openmp_blas_mulxy_exec (openmp_blas_mulxy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_blas_mulxy_scmc_set_parameter_y (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_mulxy_scmc_set_parameter_x (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_mulxy_scmc_set_parameter_y_cpu_core (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_mulxy_scmc_set_parameter_numvec (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_mulxy_scmc_set_parameter_XLEN (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_mulxy_scmc_set_parameter_YLEN (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_mulxy_scmc_set_parameter_ZLEN (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_mulxy_scmc_set_parameter_ovlp (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_mulxy_scmc_set_parameter_xblock (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_mulxy_scmc_set_parameter_yblock (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_mulxy_scmc_set_parameter_zblock (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_mulxy_scmc_set_parameter_num_ele (openmp_blas_mulxy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpby_init (openmp_pscmc_env *  pe ,openmp_blas_axpby_struct *  kerstr )
;
void  openmp_blas_axpby_get_struct_len (size_t *  len )
;
int  openmp_blas_axpby_get_num_compute_units (openmp_blas_axpby_struct *  kerstr )
;
int  openmp_blas_axpby_get_xlen ()
;
int  openmp_blas_axpby_exec (openmp_blas_axpby_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_blas_axpby_scmc_set_parameter_y (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpby_scmc_set_parameter_x (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpby_scmc_set_parameter_a (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpby_scmc_set_parameter_b (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpby_scmc_set_parameter_y_cpu_core (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpby_scmc_set_parameter_numvec (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpby_scmc_set_parameter_XLEN (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpby_scmc_set_parameter_YLEN (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpby_scmc_set_parameter_ZLEN (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpby_scmc_set_parameter_ovlp (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpby_scmc_set_parameter_xblock (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpby_scmc_set_parameter_yblock (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpby_scmc_set_parameter_zblock (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpby_scmc_set_parameter_num_ele (openmp_blas_axpby_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpy_init (openmp_pscmc_env *  pe ,openmp_blas_axpy_struct *  kerstr )
;
void  openmp_blas_axpy_get_struct_len (size_t *  len )
;
int  openmp_blas_axpy_get_num_compute_units (openmp_blas_axpy_struct *  kerstr )
;
int  openmp_blas_axpy_get_xlen ()
;
int  openmp_blas_axpy_exec (openmp_blas_axpy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_blas_axpy_scmc_set_parameter_y (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpy_scmc_set_parameter_x (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpy_scmc_set_parameter_a (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpy_scmc_set_parameter_y_cpu_core (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpy_scmc_set_parameter_numvec (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpy_scmc_set_parameter_XLEN (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpy_scmc_set_parameter_YLEN (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpy_scmc_set_parameter_ZLEN (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpy_scmc_set_parameter_ovlp (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpy_scmc_set_parameter_xblock (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpy_scmc_set_parameter_yblock (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpy_scmc_set_parameter_zblock (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_axpy_scmc_set_parameter_num_ele (openmp_blas_axpy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisax_init (openmp_pscmc_env *  pe ,openmp_blas_yisax_struct *  kerstr )
;
void  openmp_blas_yisax_get_struct_len (size_t *  len )
;
int  openmp_blas_yisax_get_num_compute_units (openmp_blas_yisax_struct *  kerstr )
;
int  openmp_blas_yisax_get_xlen ()
;
int  openmp_blas_yisax_exec (openmp_blas_yisax_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_blas_yisax_scmc_set_parameter_y (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisax_scmc_set_parameter_x (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisax_scmc_set_parameter_a (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisax_scmc_set_parameter_y_cpu_core (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisax_scmc_set_parameter_numvec (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisax_scmc_set_parameter_XLEN (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisax_scmc_set_parameter_YLEN (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisax_scmc_set_parameter_ZLEN (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisax_scmc_set_parameter_ovlp (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisax_scmc_set_parameter_xblock (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisax_scmc_set_parameter_yblock (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisax_scmc_set_parameter_zblock (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisax_scmc_set_parameter_num_ele (openmp_blas_yisax_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_invy_init (openmp_pscmc_env *  pe ,openmp_blas_invy_struct *  kerstr )
;
void  openmp_blas_invy_get_struct_len (size_t *  len )
;
int  openmp_blas_invy_get_num_compute_units (openmp_blas_invy_struct *  kerstr )
;
int  openmp_blas_invy_get_xlen ()
;
int  openmp_blas_invy_exec (openmp_blas_invy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_blas_invy_scmc_set_parameter_y (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_invy_scmc_set_parameter_y_cpu_core (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_invy_scmc_set_parameter_numvec (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_invy_scmc_set_parameter_XLEN (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_invy_scmc_set_parameter_YLEN (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_invy_scmc_set_parameter_ZLEN (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_invy_scmc_set_parameter_ovlp (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_invy_scmc_set_parameter_xblock (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_invy_scmc_set_parameter_yblock (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_invy_scmc_set_parameter_zblock (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_invy_scmc_set_parameter_num_ele (openmp_blas_invy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_get_ITG_Potential_init (openmp_pscmc_env *  pe ,openmp_blas_get_ITG_Potential_struct *  kerstr )
;
void  openmp_blas_get_ITG_Potential_get_struct_len (size_t *  len )
;
int  openmp_blas_get_ITG_Potential_get_num_compute_units (openmp_blas_get_ITG_Potential_struct *  kerstr )
;
int  openmp_blas_get_ITG_Potential_get_xlen ()
;
int  openmp_blas_get_ITG_Potential_exec (openmp_blas_get_ITG_Potential_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_y (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_x (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_u (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_minus_over_q_e (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_y_cpu_core (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_numvec (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_XLEN (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_YLEN (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_ZLEN (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_ovlp (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_xblock (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_yblock (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_zblock (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_get_ITG_Potential_scmc_set_parameter_num_ele (openmp_blas_get_ITG_Potential_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisconst_init (openmp_pscmc_env *  pe ,openmp_blas_yisconst_struct *  kerstr )
;
void  openmp_blas_yisconst_get_struct_len (size_t *  len )
;
int  openmp_blas_yisconst_get_num_compute_units (openmp_blas_yisconst_struct *  kerstr )
;
int  openmp_blas_yisconst_get_xlen ()
;
int  openmp_blas_yisconst_exec (openmp_blas_yisconst_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_blas_yisconst_scmc_set_parameter_y (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisconst_scmc_set_parameter_a (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisconst_scmc_set_parameter_y_cpu_core (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisconst_scmc_set_parameter_numvec (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisconst_scmc_set_parameter_XLEN (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisconst_scmc_set_parameter_YLEN (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisconst_scmc_set_parameter_ZLEN (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisconst_scmc_set_parameter_ovlp (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisconst_scmc_set_parameter_xblock (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisconst_scmc_set_parameter_yblock (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisconst_scmc_set_parameter_zblock (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yisconst_scmc_set_parameter_num_ele (openmp_blas_yisconst_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_init (openmp_pscmc_env *  pe ,openmp_blas_yiszero_struct *  kerstr )
;
void  openmp_blas_yiszero_get_struct_len (size_t *  len )
;
int  openmp_blas_yiszero_get_num_compute_units (openmp_blas_yiszero_struct *  kerstr )
;
int  openmp_blas_yiszero_get_xlen ()
;
int  openmp_blas_yiszero_exec (openmp_blas_yiszero_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_blas_yiszero_scmc_set_parameter_y (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_scmc_set_parameter_y_cpu_core (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_scmc_set_parameter_numvec (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_scmc_set_parameter_XLEN (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_scmc_set_parameter_YLEN (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_scmc_set_parameter_ZLEN (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_scmc_set_parameter_ovlp (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_scmc_set_parameter_xblock (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_scmc_set_parameter_yblock (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_scmc_set_parameter_zblock (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_scmc_set_parameter_num_ele (openmp_blas_yiszero_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_synced_init (openmp_pscmc_env *  pe ,openmp_blas_yiszero_synced_struct *  kerstr )
;
void  openmp_blas_yiszero_synced_get_struct_len (size_t *  len )
;
int  openmp_blas_yiszero_synced_get_num_compute_units (openmp_blas_yiszero_synced_struct *  kerstr )
;
int  openmp_blas_yiszero_synced_get_xlen ()
;
int  openmp_blas_yiszero_synced_exec (openmp_blas_yiszero_synced_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_blas_yiszero_synced_scmc_set_parameter_y (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_synced_scmc_set_parameter_y_cpu_core (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_synced_scmc_set_parameter_numvec (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_synced_scmc_set_parameter_XLEN (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_synced_scmc_set_parameter_YLEN (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_synced_scmc_set_parameter_ZLEN (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_synced_scmc_set_parameter_ovlp (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_synced_scmc_set_parameter_xblock (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_synced_scmc_set_parameter_yblock (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_synced_scmc_set_parameter_zblock (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_blas_yiszero_synced_scmc_set_parameter_num_ele (openmp_blas_yiszero_synced_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
void  openmp_sort_one_grid_x_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_sort_one_grid_y_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_sort_one_grid_z_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_sort_one_grid_x_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_sort_one_grid_y_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_sort_one_grid_z_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_cu_swap_l_scmc_kernel (double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  cu_cache_length ,int  the_dir_num ,long  XYZLEN ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_cu_swap_r_scmc_kernel (double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  cu_cache_length ,int  the_dir_num ,long  XYZLEN ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  openmp_cu_swap_r_init (openmp_pscmc_env *  pe ,openmp_cu_swap_r_struct *  kerstr )
;
void  openmp_cu_swap_r_get_struct_len (size_t *  len )
;
int  openmp_cu_swap_r_get_num_compute_units (openmp_cu_swap_r_struct *  kerstr )
;
int  openmp_cu_swap_r_get_xlen ()
;
int  openmp_cu_swap_r_exec (openmp_cu_swap_r_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_cu_swap_r_scmc_set_parameter_cu_cache (openmp_cu_swap_r_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_cu_swap_r_scmc_set_parameter_cu_xyzw (openmp_cu_swap_r_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_cu_swap_r_scmc_set_parameter_adjoint_vec_pids (openmp_cu_swap_r_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_cu_swap_r_scmc_set_parameter_cu_cache_length (openmp_cu_swap_r_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_cu_swap_r_scmc_set_parameter_the_dir_num (openmp_cu_swap_r_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_cu_swap_r_scmc_set_parameter_XYZLEN (openmp_cu_swap_r_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_cu_swap_l_init (openmp_pscmc_env *  pe ,openmp_cu_swap_l_struct *  kerstr )
;
void  openmp_cu_swap_l_get_struct_len (size_t *  len )
;
int  openmp_cu_swap_l_get_num_compute_units (openmp_cu_swap_l_struct *  kerstr )
;
int  openmp_cu_swap_l_get_xlen ()
;
int  openmp_cu_swap_l_exec (openmp_cu_swap_l_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_cu_swap_l_scmc_set_parameter_cu_cache (openmp_cu_swap_l_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_cu_swap_l_scmc_set_parameter_cu_xyzw (openmp_cu_swap_l_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_cu_swap_l_scmc_set_parameter_adjoint_vec_pids (openmp_cu_swap_l_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_cu_swap_l_scmc_set_parameter_cu_cache_length (openmp_cu_swap_l_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_cu_swap_l_scmc_set_parameter_the_dir_num (openmp_cu_swap_l_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_cu_swap_l_scmc_set_parameter_XYZLEN (openmp_cu_swap_l_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_vlo_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_z_vlo_struct *  kerstr )
;
void  openmp_sort_one_grid_z_vlo_get_struct_len (size_t *  len )
;
int  openmp_sort_one_grid_z_vlo_get_num_compute_units (openmp_sort_one_grid_z_vlo_struct *  kerstr )
;
int  openmp_sort_one_grid_z_vlo_get_xlen ()
;
int  openmp_sort_one_grid_z_vlo_exec (openmp_sort_one_grid_z_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_inoutput (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_xyzw (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_cu_cache (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_XLEN (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_YLEN (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_ZLEN (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_ovlp (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_numvec (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_vlo_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_vlo_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_y_vlo_struct *  kerstr )
;
void  openmp_sort_one_grid_y_vlo_get_struct_len (size_t *  len )
;
int  openmp_sort_one_grid_y_vlo_get_num_compute_units (openmp_sort_one_grid_y_vlo_struct *  kerstr )
;
int  openmp_sort_one_grid_y_vlo_get_xlen ()
;
int  openmp_sort_one_grid_y_vlo_exec (openmp_sort_one_grid_y_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_inoutput (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_xyzw (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_cu_cache (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_XLEN (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_YLEN (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_ZLEN (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_ovlp (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_numvec (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_vlo_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_vlo_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_x_vlo_struct *  kerstr )
;
void  openmp_sort_one_grid_x_vlo_get_struct_len (size_t *  len )
;
int  openmp_sort_one_grid_x_vlo_get_num_compute_units (openmp_sort_one_grid_x_vlo_struct *  kerstr )
;
int  openmp_sort_one_grid_x_vlo_get_xlen ()
;
int  openmp_sort_one_grid_x_vlo_exec (openmp_sort_one_grid_x_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_inoutput (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_xyzw (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_cu_cache (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_XLEN (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_YLEN (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_ZLEN (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_ovlp (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_numvec (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_vlo_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_z_struct *  kerstr )
;
void  openmp_sort_one_grid_z_get_struct_len (size_t *  len )
;
int  openmp_sort_one_grid_z_get_num_compute_units (openmp_sort_one_grid_z_struct *  kerstr )
;
int  openmp_sort_one_grid_z_get_xlen ()
;
int  openmp_sort_one_grid_z_exec (openmp_sort_one_grid_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_sort_one_grid_z_scmc_set_parameter_inoutput (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_scmc_set_parameter_xyzw (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_scmc_set_parameter_cu_cache (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_scmc_set_parameter_XLEN (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_scmc_set_parameter_YLEN (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_scmc_set_parameter_ZLEN (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_scmc_set_parameter_ovlp (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_scmc_set_parameter_numvec (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_z_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_y_struct *  kerstr )
;
void  openmp_sort_one_grid_y_get_struct_len (size_t *  len )
;
int  openmp_sort_one_grid_y_get_num_compute_units (openmp_sort_one_grid_y_struct *  kerstr )
;
int  openmp_sort_one_grid_y_get_xlen ()
;
int  openmp_sort_one_grid_y_exec (openmp_sort_one_grid_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_sort_one_grid_y_scmc_set_parameter_inoutput (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_scmc_set_parameter_xyzw (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_scmc_set_parameter_cu_cache (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_scmc_set_parameter_XLEN (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_scmc_set_parameter_YLEN (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_scmc_set_parameter_ZLEN (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_scmc_set_parameter_ovlp (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_scmc_set_parameter_numvec (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_y_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_x_struct *  kerstr )
;
void  openmp_sort_one_grid_x_get_struct_len (size_t *  len )
;
int  openmp_sort_one_grid_x_get_num_compute_units (openmp_sort_one_grid_x_struct *  kerstr )
;
int  openmp_sort_one_grid_x_get_xlen ()
;
int  openmp_sort_one_grid_x_exec (openmp_sort_one_grid_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_sort_one_grid_x_scmc_set_parameter_inoutput (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_scmc_set_parameter_xyzw (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_scmc_set_parameter_cu_cache (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_scmc_set_parameter_XLEN (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_scmc_set_parameter_YLEN (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_scmc_set_parameter_ZLEN (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_scmc_set_parameter_ovlp (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_scmc_set_parameter_numvec (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_sort_one_grid_x_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_is_in (long  x ,long  xl ,long  xr )
;
void  openmp_move_back_kernel_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long  XLEN ,long  YLEN ,long  ZLEN ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  openmp_move_back_kernel_init (openmp_pscmc_env *  pe ,openmp_move_back_kernel_struct *  kerstr )
;
void  openmp_move_back_kernel_get_struct_len (size_t *  len )
;
int  openmp_move_back_kernel_get_num_compute_units (openmp_move_back_kernel_struct *  kerstr )
;
int  openmp_move_back_kernel_get_xlen ()
;
int  openmp_move_back_kernel_exec (openmp_move_back_kernel_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_move_back_kernel_scmc_set_parameter_inoutput (openmp_move_back_kernel_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_move_back_kernel_scmc_set_parameter_xyzw (openmp_move_back_kernel_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_move_back_kernel_scmc_set_parameter_cu_cache (openmp_move_back_kernel_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_move_back_kernel_scmc_set_parameter_cu_xyzw (openmp_move_back_kernel_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_move_back_kernel_scmc_set_parameter_XLEN (openmp_move_back_kernel_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_move_back_kernel_scmc_set_parameter_YLEN (openmp_move_back_kernel_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_move_back_kernel_scmc_set_parameter_ZLEN (openmp_move_back_kernel_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_move_back_kernel_scmc_set_parameter_grid_cache_len (openmp_move_back_kernel_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_move_back_kernel_scmc_set_parameter_cu_cache_length (openmp_move_back_kernel_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
double  openmp_rand01_k (double  x0 ,double  x1 )
;
double  openmp_maxwell_dist_k (double  ava ,double  sig )
;
void  openmp_split_pass_x_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_x_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_x_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_x_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_x_vlo_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_x_vlo_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_y_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_y_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_y_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_y_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_y_vlo_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_y_vlo_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_z_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_z_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_z_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_z_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_z_vlo_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_z_vlo_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_E_particle_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_E_particle_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_boris_yee_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass0 ,double  Charge0 ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_krook_collision_remove_small_speed_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  mu_freq ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_krook_collision_test_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  mu_freq ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_calculate_rho_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_dump_ene_num_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  openmp_dump_ene_num_init (openmp_pscmc_env *  pe ,openmp_dump_ene_num_struct *  kerstr )
;
void  openmp_dump_ene_num_get_struct_len (size_t *  len )
;
int  openmp_dump_ene_num_get_num_compute_units (openmp_dump_ene_num_struct *  kerstr )
;
int  openmp_dump_ene_num_get_xlen ()
;
int  openmp_dump_ene_num_exec (openmp_dump_ene_num_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_dump_ene_num_scmc_set_parameter_inoutput (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_xyzw (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_cu_cache (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_cu_xyzw (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_fieldE (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_fieldB (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_FoutJ (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_FoutEN (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_XLEN (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_YLEN (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_ZLEN (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_ovlp (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_numvec (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_num_ele (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_grid_cache_len (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_cu_cache_length (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_Mass (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_Charge (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_SPEC (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_NUM_SPEC (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_DELTA_X (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_DELTA_Y (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_DELTA_Z (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dump_ene_num_scmc_set_parameter_Deltat (openmp_dump_ene_num_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_init (openmp_pscmc_env *  pe ,openmp_calculate_rho_struct *  kerstr )
;
void  openmp_calculate_rho_get_struct_len (size_t *  len )
;
int  openmp_calculate_rho_get_num_compute_units (openmp_calculate_rho_struct *  kerstr )
;
int  openmp_calculate_rho_get_xlen ()
;
int  openmp_calculate_rho_exec (openmp_calculate_rho_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_calculate_rho_scmc_set_parameter_inoutput (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_xyzw (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_cu_cache (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_cu_xyzw (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_fieldE (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_fieldB (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_FoutJ (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_FoutEN (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_XLEN (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_YLEN (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_ZLEN (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_ovlp (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_numvec (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_num_ele (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_grid_cache_len (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_cu_cache_length (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_Mass (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_Charge (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_SPEC (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_NUM_SPEC (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_DELTA_X (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_DELTA_Y (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_DELTA_Z (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_calculate_rho_scmc_set_parameter_Deltat (openmp_calculate_rho_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_test_init (openmp_pscmc_env *  pe ,openmp_krook_collision_test_struct *  kerstr )
;
void  openmp_krook_collision_test_get_struct_len (size_t *  len )
;
int  openmp_krook_collision_test_get_num_compute_units (openmp_krook_collision_test_struct *  kerstr )
;
int  openmp_krook_collision_test_get_xlen ()
;
int  openmp_krook_collision_test_exec (openmp_krook_collision_test_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_krook_collision_test_scmc_set_parameter_inoutput (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_test_scmc_set_parameter_xyzw (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_test_scmc_set_parameter_cu_cache (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_test_scmc_set_parameter_cu_xyzw (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_test_scmc_set_parameter_fieldE (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_test_scmc_set_parameter_fieldB (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_test_scmc_set_parameter_FoutJ (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_test_scmc_set_parameter_XLEN (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_test_scmc_set_parameter_YLEN (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_test_scmc_set_parameter_ZLEN (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_test_scmc_set_parameter_ovlp (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_test_scmc_set_parameter_numvec (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_test_scmc_set_parameter_num_ele (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_test_scmc_set_parameter_grid_cache_len (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_test_scmc_set_parameter_cu_cache_length (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_test_scmc_set_parameter_Mass0 (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_test_scmc_set_parameter_Charge0 (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_test_scmc_set_parameter_Deltat (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_test_scmc_set_parameter_mu_freq (openmp_krook_collision_test_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_remove_small_speed_init (openmp_pscmc_env *  pe ,openmp_krook_collision_remove_small_speed_struct *  kerstr )
;
void  openmp_krook_collision_remove_small_speed_get_struct_len (size_t *  len )
;
int  openmp_krook_collision_remove_small_speed_get_num_compute_units (openmp_krook_collision_remove_small_speed_struct *  kerstr )
;
int  openmp_krook_collision_remove_small_speed_get_xlen ()
;
int  openmp_krook_collision_remove_small_speed_exec (openmp_krook_collision_remove_small_speed_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_inoutput (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_xyzw (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_cu_cache (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_cu_xyzw (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_fieldE (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_fieldB (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_FoutJ (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_XLEN (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_YLEN (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_ZLEN (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_ovlp (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_numvec (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_num_ele (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_grid_cache_len (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_cu_cache_length (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_Mass0 (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_Charge0 (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_Deltat (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_krook_collision_remove_small_speed_scmc_set_parameter_mu_freq (openmp_krook_collision_remove_small_speed_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_boris_yee_init (openmp_pscmc_env *  pe ,openmp_boris_yee_struct *  kerstr )
;
void  openmp_boris_yee_get_struct_len (size_t *  len )
;
int  openmp_boris_yee_get_num_compute_units (openmp_boris_yee_struct *  kerstr )
;
int  openmp_boris_yee_get_xlen ()
;
int  openmp_boris_yee_exec (openmp_boris_yee_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_boris_yee_scmc_set_parameter_inoutput (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_boris_yee_scmc_set_parameter_xyzw (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_boris_yee_scmc_set_parameter_cu_cache (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_boris_yee_scmc_set_parameter_cu_xyzw (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_boris_yee_scmc_set_parameter_fieldE (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_boris_yee_scmc_set_parameter_fieldB (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_boris_yee_scmc_set_parameter_FoutJ (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_boris_yee_scmc_set_parameter_XLEN (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_boris_yee_scmc_set_parameter_YLEN (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_boris_yee_scmc_set_parameter_ZLEN (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_boris_yee_scmc_set_parameter_ovlp (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_boris_yee_scmc_set_parameter_numvec (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_boris_yee_scmc_set_parameter_num_ele (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_boris_yee_scmc_set_parameter_grid_cache_len (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_boris_yee_scmc_set_parameter_cu_cache_length (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_boris_yee_scmc_set_parameter_Mass0 (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_boris_yee_scmc_set_parameter_Charge0 (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_boris_yee_scmc_set_parameter_Deltat (openmp_boris_yee_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_init (openmp_pscmc_env *  pe ,openmp_split_pass_E_particle_vlo_struct *  kerstr )
;
void  openmp_split_pass_E_particle_vlo_get_struct_len (size_t *  len )
;
int  openmp_split_pass_E_particle_vlo_get_num_compute_units (openmp_split_pass_E_particle_vlo_struct *  kerstr )
;
int  openmp_split_pass_E_particle_vlo_get_xlen ()
;
int  openmp_split_pass_E_particle_vlo_exec (openmp_split_pass_E_particle_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_inoutput (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_xyzw (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_cu_cache (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_cu_xyzw (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_fieldE (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_fieldB (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_FoutJ (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_FoutEN (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_XLEN (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_YLEN (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_ZLEN (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_ovlp (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_numvec (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_num_ele (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_grid_cache_len (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_cu_cache_length (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_Mass (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_Charge (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_SPEC (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_NUM_SPEC (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_DELTA_X (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_DELTA_Y (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_DELTA_Z (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_vlo_scmc_set_parameter_Deltat (openmp_split_pass_E_particle_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_init (openmp_pscmc_env *  pe ,openmp_split_pass_E_particle_struct *  kerstr )
;
void  openmp_split_pass_E_particle_get_struct_len (size_t *  len )
;
int  openmp_split_pass_E_particle_get_num_compute_units (openmp_split_pass_E_particle_struct *  kerstr )
;
int  openmp_split_pass_E_particle_get_xlen ()
;
int  openmp_split_pass_E_particle_exec (openmp_split_pass_E_particle_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_inoutput (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_xyzw (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_cu_cache (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_cu_xyzw (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_fieldE (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_fieldB (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_FoutJ (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_FoutEN (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_XLEN (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_YLEN (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_ZLEN (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_ovlp (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_numvec (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_num_ele (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_grid_cache_len (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_cu_cache_length (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_Mass (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_Charge (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_SPEC (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_NUM_SPEC (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_DELTA_X (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_DELTA_Y (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_DELTA_Z (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_E_particle_scmc_set_parameter_Deltat (openmp_split_pass_E_particle_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_init (openmp_pscmc_env *  pe ,openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr )
;
void  openmp_split_pass_z_vlo_sg2_small_grids_get_struct_len (size_t *  len )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_get_num_compute_units (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_get_xlen ()
;
int  openmp_split_pass_z_vlo_sg2_small_grids_exec (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_inoutput (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_xyzw (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_cu_cache (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_cu_xyzw (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_fieldE (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_fieldB (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_LFoutJ (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_FoutEN (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_XLEN (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_YLEN (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_ZLEN (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_ovlp (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_numvec (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_num_ele (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_grid_cache_len (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_cu_cache_length (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_Mass (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_Charge (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_SPEC (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_NUM_SPEC (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_DELTA_X (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Y (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Z (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_Deltat (openmp_split_pass_z_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_init (openmp_pscmc_env *  pe ,openmp_split_pass_z_vlo_small_grids_struct *  kerstr )
;
void  openmp_split_pass_z_vlo_small_grids_get_struct_len (size_t *  len )
;
int  openmp_split_pass_z_vlo_small_grids_get_num_compute_units (openmp_split_pass_z_vlo_small_grids_struct *  kerstr )
;
int  openmp_split_pass_z_vlo_small_grids_get_xlen ()
;
int  openmp_split_pass_z_vlo_small_grids_exec (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_inoutput (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_xyzw (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_cu_cache (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_cu_xyzw (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_fieldE (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_fieldB (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_LFoutJ (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_FoutEN (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_XLEN (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_YLEN (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_ZLEN (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_ovlp (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_numvec (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_num_ele (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_grid_cache_len (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_cu_cache_length (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_Mass (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_Charge (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_SPEC (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_NUM_SPEC (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_DELTA_X (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_DELTA_Y (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_DELTA_Z (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_small_grids_scmc_set_parameter_Deltat (openmp_split_pass_z_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_init (openmp_pscmc_env *  pe ,openmp_split_pass_z_sg2_small_grids_struct *  kerstr )
;
void  openmp_split_pass_z_sg2_small_grids_get_struct_len (size_t *  len )
;
int  openmp_split_pass_z_sg2_small_grids_get_num_compute_units (openmp_split_pass_z_sg2_small_grids_struct *  kerstr )
;
int  openmp_split_pass_z_sg2_small_grids_get_xlen ()
;
int  openmp_split_pass_z_sg2_small_grids_exec (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_inoutput (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_xyzw (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_cu_cache (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_cu_xyzw (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_fieldE (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_fieldB (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_LFoutJ (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_FoutEN (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_XLEN (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_YLEN (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_ZLEN (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_ovlp (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_numvec (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_num_ele (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_grid_cache_len (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_cu_cache_length (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_Mass (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_Charge (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_SPEC (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_NUM_SPEC (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_DELTA_X (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_DELTA_Y (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_DELTA_Z (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_sg2_small_grids_scmc_set_parameter_Deltat (openmp_split_pass_z_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_init (openmp_pscmc_env *  pe ,openmp_split_pass_z_small_grids_struct *  kerstr )
;
void  openmp_split_pass_z_small_grids_get_struct_len (size_t *  len )
;
int  openmp_split_pass_z_small_grids_get_num_compute_units (openmp_split_pass_z_small_grids_struct *  kerstr )
;
int  openmp_split_pass_z_small_grids_get_xlen ()
;
int  openmp_split_pass_z_small_grids_exec (openmp_split_pass_z_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_inoutput (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_xyzw (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_cu_cache (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_cu_xyzw (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_fieldE (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_fieldB (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_LFoutJ (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_FoutEN (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_XLEN (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_YLEN (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_ZLEN (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_ovlp (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_numvec (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_num_ele (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_grid_cache_len (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_cu_cache_length (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_Mass (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_Charge (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_SPEC (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_NUM_SPEC (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_DELTA_X (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_DELTA_Y (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_DELTA_Z (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_small_grids_scmc_set_parameter_Deltat (openmp_split_pass_z_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_init (openmp_pscmc_env *  pe ,openmp_split_pass_z_vlo_struct *  kerstr )
;
void  openmp_split_pass_z_vlo_get_struct_len (size_t *  len )
;
int  openmp_split_pass_z_vlo_get_num_compute_units (openmp_split_pass_z_vlo_struct *  kerstr )
;
int  openmp_split_pass_z_vlo_get_xlen ()
;
int  openmp_split_pass_z_vlo_exec (openmp_split_pass_z_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_inoutput (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_xyzw (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_cu_cache (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_cu_xyzw (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_fieldE (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_fieldB (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_FoutJ (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_FoutEN (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_XLEN (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_YLEN (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_ZLEN (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_ovlp (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_numvec (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_num_ele (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_grid_cache_len (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_cu_cache_length (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_Mass (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_Charge (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_SPEC (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_NUM_SPEC (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_DELTA_X (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_DELTA_Y (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_DELTA_Z (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_vlo_scmc_set_parameter_Deltat (openmp_split_pass_z_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_init (openmp_pscmc_env *  pe ,openmp_split_pass_z_struct *  kerstr )
;
void  openmp_split_pass_z_get_struct_len (size_t *  len )
;
int  openmp_split_pass_z_get_num_compute_units (openmp_split_pass_z_struct *  kerstr )
;
int  openmp_split_pass_z_get_xlen ()
;
int  openmp_split_pass_z_exec (openmp_split_pass_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_z_scmc_set_parameter_inoutput (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_xyzw (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_cu_cache (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_cu_xyzw (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_fieldE (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_fieldB (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_FoutJ (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_FoutEN (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_XLEN (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_YLEN (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_ZLEN (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_ovlp (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_numvec (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_num_ele (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_grid_cache_len (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_cu_cache_length (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_Mass (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_Charge (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_SPEC (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_NUM_SPEC (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_DELTA_X (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_DELTA_Y (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_DELTA_Z (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_z_scmc_set_parameter_Deltat (openmp_split_pass_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_init (openmp_pscmc_env *  pe ,openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr )
;
void  openmp_split_pass_y_vlo_sg2_small_grids_get_struct_len (size_t *  len )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_get_num_compute_units (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_get_xlen ()
;
int  openmp_split_pass_y_vlo_sg2_small_grids_exec (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_inoutput (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_xyzw (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_cu_cache (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_cu_xyzw (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_fieldE (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_fieldB (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_LFoutJ (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_FoutEN (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_XLEN (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_YLEN (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_ZLEN (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_ovlp (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_numvec (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_num_ele (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_grid_cache_len (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_cu_cache_length (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_Mass (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_Charge (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_SPEC (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_NUM_SPEC (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_DELTA_X (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Y (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Z (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_Deltat (openmp_split_pass_y_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_init (openmp_pscmc_env *  pe ,openmp_split_pass_y_vlo_small_grids_struct *  kerstr )
;
void  openmp_split_pass_y_vlo_small_grids_get_struct_len (size_t *  len )
;
int  openmp_split_pass_y_vlo_small_grids_get_num_compute_units (openmp_split_pass_y_vlo_small_grids_struct *  kerstr )
;
int  openmp_split_pass_y_vlo_small_grids_get_xlen ()
;
int  openmp_split_pass_y_vlo_small_grids_exec (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_inoutput (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_xyzw (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_cu_cache (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_cu_xyzw (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_fieldE (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_fieldB (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_LFoutJ (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_FoutEN (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_XLEN (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_YLEN (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_ZLEN (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_ovlp (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_numvec (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_num_ele (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_grid_cache_len (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_cu_cache_length (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_Mass (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_Charge (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_SPEC (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_NUM_SPEC (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_DELTA_X (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_DELTA_Y (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_DELTA_Z (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_small_grids_scmc_set_parameter_Deltat (openmp_split_pass_y_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_init (openmp_pscmc_env *  pe ,openmp_split_pass_y_sg2_small_grids_struct *  kerstr )
;
void  openmp_split_pass_y_sg2_small_grids_get_struct_len (size_t *  len )
;
int  openmp_split_pass_y_sg2_small_grids_get_num_compute_units (openmp_split_pass_y_sg2_small_grids_struct *  kerstr )
;
int  openmp_split_pass_y_sg2_small_grids_get_xlen ()
;
int  openmp_split_pass_y_sg2_small_grids_exec (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_inoutput (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_xyzw (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_cu_cache (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_cu_xyzw (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_fieldE (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_fieldB (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_LFoutJ (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_FoutEN (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_XLEN (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_YLEN (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_ZLEN (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_ovlp (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_numvec (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_num_ele (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_grid_cache_len (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_cu_cache_length (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_Mass (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_Charge (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_SPEC (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_NUM_SPEC (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_DELTA_X (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_DELTA_Y (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_DELTA_Z (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_sg2_small_grids_scmc_set_parameter_Deltat (openmp_split_pass_y_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_init (openmp_pscmc_env *  pe ,openmp_split_pass_y_small_grids_struct *  kerstr )
;
void  openmp_split_pass_y_small_grids_get_struct_len (size_t *  len )
;
int  openmp_split_pass_y_small_grids_get_num_compute_units (openmp_split_pass_y_small_grids_struct *  kerstr )
;
int  openmp_split_pass_y_small_grids_get_xlen ()
;
int  openmp_split_pass_y_small_grids_exec (openmp_split_pass_y_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_inoutput (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_xyzw (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_cu_cache (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_cu_xyzw (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_fieldE (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_fieldB (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_LFoutJ (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_FoutEN (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_XLEN (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_YLEN (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_ZLEN (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_ovlp (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_numvec (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_num_ele (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_grid_cache_len (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_cu_cache_length (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_Mass (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_Charge (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_SPEC (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_NUM_SPEC (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_DELTA_X (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_DELTA_Y (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_DELTA_Z (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_small_grids_scmc_set_parameter_Deltat (openmp_split_pass_y_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_init (openmp_pscmc_env *  pe ,openmp_split_pass_y_vlo_struct *  kerstr )
;
void  openmp_split_pass_y_vlo_get_struct_len (size_t *  len )
;
int  openmp_split_pass_y_vlo_get_num_compute_units (openmp_split_pass_y_vlo_struct *  kerstr )
;
int  openmp_split_pass_y_vlo_get_xlen ()
;
int  openmp_split_pass_y_vlo_exec (openmp_split_pass_y_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_inoutput (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_xyzw (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_cu_cache (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_cu_xyzw (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_fieldE (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_fieldB (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_FoutJ (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_FoutEN (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_XLEN (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_YLEN (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_ZLEN (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_ovlp (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_numvec (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_num_ele (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_grid_cache_len (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_cu_cache_length (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_Mass (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_Charge (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_SPEC (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_NUM_SPEC (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_DELTA_X (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_DELTA_Y (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_DELTA_Z (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_vlo_scmc_set_parameter_Deltat (openmp_split_pass_y_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_init (openmp_pscmc_env *  pe ,openmp_split_pass_y_struct *  kerstr )
;
void  openmp_split_pass_y_get_struct_len (size_t *  len )
;
int  openmp_split_pass_y_get_num_compute_units (openmp_split_pass_y_struct *  kerstr )
;
int  openmp_split_pass_y_get_xlen ()
;
int  openmp_split_pass_y_exec (openmp_split_pass_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_y_scmc_set_parameter_inoutput (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_xyzw (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_cu_cache (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_cu_xyzw (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_fieldE (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_fieldB (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_FoutJ (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_FoutEN (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_XLEN (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_YLEN (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_ZLEN (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_ovlp (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_numvec (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_num_ele (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_grid_cache_len (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_cu_cache_length (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_Mass (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_Charge (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_SPEC (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_NUM_SPEC (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_DELTA_X (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_DELTA_Y (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_DELTA_Z (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_y_scmc_set_parameter_Deltat (openmp_split_pass_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_init (openmp_pscmc_env *  pe ,openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr )
;
void  openmp_split_pass_x_vlo_sg2_small_grids_get_struct_len (size_t *  len )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_get_num_compute_units (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_get_xlen ()
;
int  openmp_split_pass_x_vlo_sg2_small_grids_exec (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_inoutput (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_xyzw (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_cu_cache (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_cu_xyzw (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_fieldE (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_fieldB (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_LFoutJ (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_FoutEN (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_XLEN (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_YLEN (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_ZLEN (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_ovlp (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_numvec (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_num_ele (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_grid_cache_len (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_cu_cache_length (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_Mass (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_Charge (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_SPEC (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_NUM_SPEC (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_DELTA_X (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Y (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Z (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_Deltat (openmp_split_pass_x_vlo_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_init (openmp_pscmc_env *  pe ,openmp_split_pass_x_vlo_small_grids_struct *  kerstr )
;
void  openmp_split_pass_x_vlo_small_grids_get_struct_len (size_t *  len )
;
int  openmp_split_pass_x_vlo_small_grids_get_num_compute_units (openmp_split_pass_x_vlo_small_grids_struct *  kerstr )
;
int  openmp_split_pass_x_vlo_small_grids_get_xlen ()
;
int  openmp_split_pass_x_vlo_small_grids_exec (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_inoutput (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_xyzw (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_cu_cache (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_cu_xyzw (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_fieldE (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_fieldB (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_LFoutJ (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_FoutEN (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_XLEN (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_YLEN (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_ZLEN (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_ovlp (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_numvec (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_num_ele (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_grid_cache_len (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_cu_cache_length (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_Mass (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_Charge (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_SPEC (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_NUM_SPEC (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_DELTA_X (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_DELTA_Y (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_DELTA_Z (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_small_grids_scmc_set_parameter_Deltat (openmp_split_pass_x_vlo_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_init (openmp_pscmc_env *  pe ,openmp_split_pass_x_sg2_small_grids_struct *  kerstr )
;
void  openmp_split_pass_x_sg2_small_grids_get_struct_len (size_t *  len )
;
int  openmp_split_pass_x_sg2_small_grids_get_num_compute_units (openmp_split_pass_x_sg2_small_grids_struct *  kerstr )
;
int  openmp_split_pass_x_sg2_small_grids_get_xlen ()
;
int  openmp_split_pass_x_sg2_small_grids_exec (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_inoutput (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_xyzw (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_cu_cache (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_cu_xyzw (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_fieldE (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_fieldB (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_LFoutJ (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_FoutEN (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_XLEN (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_YLEN (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_ZLEN (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_ovlp (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_numvec (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_num_ele (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_grid_cache_len (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_cu_cache_length (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_Mass (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_Charge (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_SPEC (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_NUM_SPEC (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_DELTA_X (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_DELTA_Y (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_DELTA_Z (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_sg2_small_grids_scmc_set_parameter_Deltat (openmp_split_pass_x_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_init (openmp_pscmc_env *  pe ,openmp_split_pass_x_small_grids_struct *  kerstr )
;
void  openmp_split_pass_x_small_grids_get_struct_len (size_t *  len )
;
int  openmp_split_pass_x_small_grids_get_num_compute_units (openmp_split_pass_x_small_grids_struct *  kerstr )
;
int  openmp_split_pass_x_small_grids_get_xlen ()
;
int  openmp_split_pass_x_small_grids_exec (openmp_split_pass_x_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_inoutput (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_xyzw (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_cu_cache (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_cu_xyzw (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_fieldE (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_fieldB (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_LFoutJ (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_FoutEN (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_XLEN (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_YLEN (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_ZLEN (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_ovlp (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_numvec (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_num_ele (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_grid_cache_len (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_cu_cache_length (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_Mass (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_Charge (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_SPEC (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_NUM_SPEC (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_DELTA_X (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_DELTA_Y (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_DELTA_Z (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_small_grids_scmc_set_parameter_Deltat (openmp_split_pass_x_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_init (openmp_pscmc_env *  pe ,openmp_split_pass_x_vlo_struct *  kerstr )
;
void  openmp_split_pass_x_vlo_get_struct_len (size_t *  len )
;
int  openmp_split_pass_x_vlo_get_num_compute_units (openmp_split_pass_x_vlo_struct *  kerstr )
;
int  openmp_split_pass_x_vlo_get_xlen ()
;
int  openmp_split_pass_x_vlo_exec (openmp_split_pass_x_vlo_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_inoutput (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_xyzw (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_cu_cache (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_cu_xyzw (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_fieldE (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_fieldB (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_FoutJ (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_FoutEN (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_XLEN (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_YLEN (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_ZLEN (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_ovlp (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_numvec (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_num_ele (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_grid_cache_len (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_cu_cache_length (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_Mass (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_Charge (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_SPEC (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_NUM_SPEC (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_DELTA_X (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_DELTA_Y (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_DELTA_Z (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_vlo_scmc_set_parameter_Deltat (openmp_split_pass_x_vlo_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_init (openmp_pscmc_env *  pe ,openmp_split_pass_x_struct *  kerstr )
;
void  openmp_split_pass_x_get_struct_len (size_t *  len )
;
int  openmp_split_pass_x_get_num_compute_units (openmp_split_pass_x_struct *  kerstr )
;
int  openmp_split_pass_x_get_xlen ()
;
int  openmp_split_pass_x_exec (openmp_split_pass_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_split_pass_x_scmc_set_parameter_inoutput (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_xyzw (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_cu_cache (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_cu_xyzw (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_fieldE (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_fieldB (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_FoutJ (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_FoutEN (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_XLEN (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_YLEN (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_ZLEN (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_ovlp (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_numvec (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_num_ele (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_grid_cache_len (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_cu_cache_length (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_Mass (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_Charge (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_SPEC (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_NUM_SPEC (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_DELTA_X (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_DELTA_Y (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_DELTA_Z (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_split_pass_x_scmc_set_parameter_Deltat (openmp_split_pass_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
void  openmp_yee_abc__scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_pec__scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_damp__scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_abc_x_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_pec_x_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_damp_x_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_abc_y_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_pec_y_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_damp_y_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_abc_z_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_pec_z_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_damp_z_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_abc_xy_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_pec_xy_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_damp_xy_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_abc_xz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_pec_xz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_damp_xz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_abc_yz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_pec_yz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_damp_yz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_abc_xyz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_pec_xyz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_yee_damp_xyz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  openmp_yee_damp_xyz_init (openmp_pscmc_env *  pe ,openmp_yee_damp_xyz_struct *  kerstr )
;
void  openmp_yee_damp_xyz_get_struct_len (size_t *  len )
;
int  openmp_yee_damp_xyz_get_num_compute_units (openmp_yee_damp_xyz_struct *  kerstr )
;
int  openmp_yee_damp_xyz_get_xlen ()
;
int  openmp_yee_damp_xyz_exec (openmp_yee_damp_xyz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_damp_xyz_scmc_set_parameter_outEB (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xyz_scmc_set_parameter_inEB (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xyz_scmc_set_parameter_cur_rankx (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xyz_scmc_set_parameter_cur_ranky (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xyz_scmc_set_parameter_cur_rankz (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xyz_scmc_set_parameter_y_cpu_core (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xyz_scmc_set_parameter_numvec (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xyz_scmc_set_parameter_XLEN (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xyz_scmc_set_parameter_YLEN (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xyz_scmc_set_parameter_ZLEN (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xyz_scmc_set_parameter_ovlp (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xyz_scmc_set_parameter_xblock (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xyz_scmc_set_parameter_yblock (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xyz_scmc_set_parameter_zblock (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xyz_scmc_set_parameter_num_ele (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xyz_scmc_set_parameter_damp_vars (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xyz_scmc_set_parameter_deltat (openmp_yee_damp_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xyz_init (openmp_pscmc_env *  pe ,openmp_yee_pec_xyz_struct *  kerstr )
;
void  openmp_yee_pec_xyz_get_struct_len (size_t *  len )
;
int  openmp_yee_pec_xyz_get_num_compute_units (openmp_yee_pec_xyz_struct *  kerstr )
;
int  openmp_yee_pec_xyz_get_xlen ()
;
int  openmp_yee_pec_xyz_exec (openmp_yee_pec_xyz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_pec_xyz_scmc_set_parameter_outEB (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xyz_scmc_set_parameter_inEB (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xyz_scmc_set_parameter_cur_rankx (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xyz_scmc_set_parameter_cur_ranky (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xyz_scmc_set_parameter_cur_rankz (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xyz_scmc_set_parameter_y_cpu_core (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xyz_scmc_set_parameter_numvec (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xyz_scmc_set_parameter_XLEN (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xyz_scmc_set_parameter_YLEN (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xyz_scmc_set_parameter_ZLEN (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xyz_scmc_set_parameter_ovlp (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xyz_scmc_set_parameter_xblock (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xyz_scmc_set_parameter_yblock (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xyz_scmc_set_parameter_zblock (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xyz_scmc_set_parameter_num_ele (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xyz_scmc_set_parameter_damp_vars (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xyz_scmc_set_parameter_deltat (openmp_yee_pec_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xyz_init (openmp_pscmc_env *  pe ,openmp_yee_abc_xyz_struct *  kerstr )
;
void  openmp_yee_abc_xyz_get_struct_len (size_t *  len )
;
int  openmp_yee_abc_xyz_get_num_compute_units (openmp_yee_abc_xyz_struct *  kerstr )
;
int  openmp_yee_abc_xyz_get_xlen ()
;
int  openmp_yee_abc_xyz_exec (openmp_yee_abc_xyz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_abc_xyz_scmc_set_parameter_outEB (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xyz_scmc_set_parameter_inEB (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xyz_scmc_set_parameter_cur_rankx (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xyz_scmc_set_parameter_cur_ranky (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xyz_scmc_set_parameter_cur_rankz (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xyz_scmc_set_parameter_y_cpu_core (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xyz_scmc_set_parameter_numvec (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xyz_scmc_set_parameter_XLEN (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xyz_scmc_set_parameter_YLEN (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xyz_scmc_set_parameter_ZLEN (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xyz_scmc_set_parameter_ovlp (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xyz_scmc_set_parameter_xblock (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xyz_scmc_set_parameter_yblock (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xyz_scmc_set_parameter_zblock (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xyz_scmc_set_parameter_num_ele (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xyz_scmc_set_parameter_damp_vars (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xyz_scmc_set_parameter_deltat (openmp_yee_abc_xyz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_yz_init (openmp_pscmc_env *  pe ,openmp_yee_damp_yz_struct *  kerstr )
;
void  openmp_yee_damp_yz_get_struct_len (size_t *  len )
;
int  openmp_yee_damp_yz_get_num_compute_units (openmp_yee_damp_yz_struct *  kerstr )
;
int  openmp_yee_damp_yz_get_xlen ()
;
int  openmp_yee_damp_yz_exec (openmp_yee_damp_yz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_damp_yz_scmc_set_parameter_outEB (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_yz_scmc_set_parameter_inEB (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_yz_scmc_set_parameter_cur_rankx (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_yz_scmc_set_parameter_cur_ranky (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_yz_scmc_set_parameter_cur_rankz (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_yz_scmc_set_parameter_y_cpu_core (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_yz_scmc_set_parameter_numvec (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_yz_scmc_set_parameter_XLEN (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_yz_scmc_set_parameter_YLEN (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_yz_scmc_set_parameter_ZLEN (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_yz_scmc_set_parameter_ovlp (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_yz_scmc_set_parameter_xblock (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_yz_scmc_set_parameter_yblock (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_yz_scmc_set_parameter_zblock (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_yz_scmc_set_parameter_num_ele (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_yz_scmc_set_parameter_damp_vars (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_yz_scmc_set_parameter_deltat (openmp_yee_damp_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_yz_init (openmp_pscmc_env *  pe ,openmp_yee_pec_yz_struct *  kerstr )
;
void  openmp_yee_pec_yz_get_struct_len (size_t *  len )
;
int  openmp_yee_pec_yz_get_num_compute_units (openmp_yee_pec_yz_struct *  kerstr )
;
int  openmp_yee_pec_yz_get_xlen ()
;
int  openmp_yee_pec_yz_exec (openmp_yee_pec_yz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_pec_yz_scmc_set_parameter_outEB (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_yz_scmc_set_parameter_inEB (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_yz_scmc_set_parameter_cur_rankx (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_yz_scmc_set_parameter_cur_ranky (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_yz_scmc_set_parameter_cur_rankz (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_yz_scmc_set_parameter_y_cpu_core (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_yz_scmc_set_parameter_numvec (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_yz_scmc_set_parameter_XLEN (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_yz_scmc_set_parameter_YLEN (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_yz_scmc_set_parameter_ZLEN (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_yz_scmc_set_parameter_ovlp (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_yz_scmc_set_parameter_xblock (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_yz_scmc_set_parameter_yblock (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_yz_scmc_set_parameter_zblock (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_yz_scmc_set_parameter_num_ele (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_yz_scmc_set_parameter_damp_vars (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_yz_scmc_set_parameter_deltat (openmp_yee_pec_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_yz_init (openmp_pscmc_env *  pe ,openmp_yee_abc_yz_struct *  kerstr )
;
void  openmp_yee_abc_yz_get_struct_len (size_t *  len )
;
int  openmp_yee_abc_yz_get_num_compute_units (openmp_yee_abc_yz_struct *  kerstr )
;
int  openmp_yee_abc_yz_get_xlen ()
;
int  openmp_yee_abc_yz_exec (openmp_yee_abc_yz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_abc_yz_scmc_set_parameter_outEB (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_yz_scmc_set_parameter_inEB (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_yz_scmc_set_parameter_cur_rankx (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_yz_scmc_set_parameter_cur_ranky (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_yz_scmc_set_parameter_cur_rankz (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_yz_scmc_set_parameter_y_cpu_core (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_yz_scmc_set_parameter_numvec (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_yz_scmc_set_parameter_XLEN (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_yz_scmc_set_parameter_YLEN (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_yz_scmc_set_parameter_ZLEN (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_yz_scmc_set_parameter_ovlp (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_yz_scmc_set_parameter_xblock (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_yz_scmc_set_parameter_yblock (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_yz_scmc_set_parameter_zblock (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_yz_scmc_set_parameter_num_ele (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_yz_scmc_set_parameter_damp_vars (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_yz_scmc_set_parameter_deltat (openmp_yee_abc_yz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xz_init (openmp_pscmc_env *  pe ,openmp_yee_damp_xz_struct *  kerstr )
;
void  openmp_yee_damp_xz_get_struct_len (size_t *  len )
;
int  openmp_yee_damp_xz_get_num_compute_units (openmp_yee_damp_xz_struct *  kerstr )
;
int  openmp_yee_damp_xz_get_xlen ()
;
int  openmp_yee_damp_xz_exec (openmp_yee_damp_xz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_damp_xz_scmc_set_parameter_outEB (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xz_scmc_set_parameter_inEB (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xz_scmc_set_parameter_cur_rankx (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xz_scmc_set_parameter_cur_ranky (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xz_scmc_set_parameter_cur_rankz (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xz_scmc_set_parameter_y_cpu_core (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xz_scmc_set_parameter_numvec (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xz_scmc_set_parameter_XLEN (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xz_scmc_set_parameter_YLEN (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xz_scmc_set_parameter_ZLEN (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xz_scmc_set_parameter_ovlp (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xz_scmc_set_parameter_xblock (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xz_scmc_set_parameter_yblock (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xz_scmc_set_parameter_zblock (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xz_scmc_set_parameter_num_ele (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xz_scmc_set_parameter_damp_vars (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xz_scmc_set_parameter_deltat (openmp_yee_damp_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xz_init (openmp_pscmc_env *  pe ,openmp_yee_pec_xz_struct *  kerstr )
;
void  openmp_yee_pec_xz_get_struct_len (size_t *  len )
;
int  openmp_yee_pec_xz_get_num_compute_units (openmp_yee_pec_xz_struct *  kerstr )
;
int  openmp_yee_pec_xz_get_xlen ()
;
int  openmp_yee_pec_xz_exec (openmp_yee_pec_xz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_pec_xz_scmc_set_parameter_outEB (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xz_scmc_set_parameter_inEB (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xz_scmc_set_parameter_cur_rankx (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xz_scmc_set_parameter_cur_ranky (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xz_scmc_set_parameter_cur_rankz (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xz_scmc_set_parameter_y_cpu_core (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xz_scmc_set_parameter_numvec (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xz_scmc_set_parameter_XLEN (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xz_scmc_set_parameter_YLEN (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xz_scmc_set_parameter_ZLEN (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xz_scmc_set_parameter_ovlp (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xz_scmc_set_parameter_xblock (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xz_scmc_set_parameter_yblock (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xz_scmc_set_parameter_zblock (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xz_scmc_set_parameter_num_ele (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xz_scmc_set_parameter_damp_vars (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xz_scmc_set_parameter_deltat (openmp_yee_pec_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xz_init (openmp_pscmc_env *  pe ,openmp_yee_abc_xz_struct *  kerstr )
;
void  openmp_yee_abc_xz_get_struct_len (size_t *  len )
;
int  openmp_yee_abc_xz_get_num_compute_units (openmp_yee_abc_xz_struct *  kerstr )
;
int  openmp_yee_abc_xz_get_xlen ()
;
int  openmp_yee_abc_xz_exec (openmp_yee_abc_xz_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_abc_xz_scmc_set_parameter_outEB (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xz_scmc_set_parameter_inEB (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xz_scmc_set_parameter_cur_rankx (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xz_scmc_set_parameter_cur_ranky (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xz_scmc_set_parameter_cur_rankz (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xz_scmc_set_parameter_y_cpu_core (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xz_scmc_set_parameter_numvec (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xz_scmc_set_parameter_XLEN (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xz_scmc_set_parameter_YLEN (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xz_scmc_set_parameter_ZLEN (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xz_scmc_set_parameter_ovlp (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xz_scmc_set_parameter_xblock (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xz_scmc_set_parameter_yblock (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xz_scmc_set_parameter_zblock (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xz_scmc_set_parameter_num_ele (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xz_scmc_set_parameter_damp_vars (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xz_scmc_set_parameter_deltat (openmp_yee_abc_xz_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xy_init (openmp_pscmc_env *  pe ,openmp_yee_damp_xy_struct *  kerstr )
;
void  openmp_yee_damp_xy_get_struct_len (size_t *  len )
;
int  openmp_yee_damp_xy_get_num_compute_units (openmp_yee_damp_xy_struct *  kerstr )
;
int  openmp_yee_damp_xy_get_xlen ()
;
int  openmp_yee_damp_xy_exec (openmp_yee_damp_xy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_damp_xy_scmc_set_parameter_outEB (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xy_scmc_set_parameter_inEB (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xy_scmc_set_parameter_cur_rankx (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xy_scmc_set_parameter_cur_ranky (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xy_scmc_set_parameter_cur_rankz (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xy_scmc_set_parameter_y_cpu_core (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xy_scmc_set_parameter_numvec (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xy_scmc_set_parameter_XLEN (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xy_scmc_set_parameter_YLEN (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xy_scmc_set_parameter_ZLEN (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xy_scmc_set_parameter_ovlp (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xy_scmc_set_parameter_xblock (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xy_scmc_set_parameter_yblock (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xy_scmc_set_parameter_zblock (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xy_scmc_set_parameter_num_ele (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xy_scmc_set_parameter_damp_vars (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_xy_scmc_set_parameter_deltat (openmp_yee_damp_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xy_init (openmp_pscmc_env *  pe ,openmp_yee_pec_xy_struct *  kerstr )
;
void  openmp_yee_pec_xy_get_struct_len (size_t *  len )
;
int  openmp_yee_pec_xy_get_num_compute_units (openmp_yee_pec_xy_struct *  kerstr )
;
int  openmp_yee_pec_xy_get_xlen ()
;
int  openmp_yee_pec_xy_exec (openmp_yee_pec_xy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_pec_xy_scmc_set_parameter_outEB (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xy_scmc_set_parameter_inEB (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xy_scmc_set_parameter_cur_rankx (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xy_scmc_set_parameter_cur_ranky (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xy_scmc_set_parameter_cur_rankz (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xy_scmc_set_parameter_y_cpu_core (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xy_scmc_set_parameter_numvec (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xy_scmc_set_parameter_XLEN (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xy_scmc_set_parameter_YLEN (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xy_scmc_set_parameter_ZLEN (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xy_scmc_set_parameter_ovlp (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xy_scmc_set_parameter_xblock (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xy_scmc_set_parameter_yblock (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xy_scmc_set_parameter_zblock (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xy_scmc_set_parameter_num_ele (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xy_scmc_set_parameter_damp_vars (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_xy_scmc_set_parameter_deltat (openmp_yee_pec_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xy_init (openmp_pscmc_env *  pe ,openmp_yee_abc_xy_struct *  kerstr )
;
void  openmp_yee_abc_xy_get_struct_len (size_t *  len )
;
int  openmp_yee_abc_xy_get_num_compute_units (openmp_yee_abc_xy_struct *  kerstr )
;
int  openmp_yee_abc_xy_get_xlen ()
;
int  openmp_yee_abc_xy_exec (openmp_yee_abc_xy_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_abc_xy_scmc_set_parameter_outEB (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xy_scmc_set_parameter_inEB (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xy_scmc_set_parameter_cur_rankx (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xy_scmc_set_parameter_cur_ranky (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xy_scmc_set_parameter_cur_rankz (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xy_scmc_set_parameter_y_cpu_core (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xy_scmc_set_parameter_numvec (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xy_scmc_set_parameter_XLEN (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xy_scmc_set_parameter_YLEN (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xy_scmc_set_parameter_ZLEN (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xy_scmc_set_parameter_ovlp (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xy_scmc_set_parameter_xblock (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xy_scmc_set_parameter_yblock (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xy_scmc_set_parameter_zblock (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xy_scmc_set_parameter_num_ele (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xy_scmc_set_parameter_damp_vars (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_xy_scmc_set_parameter_deltat (openmp_yee_abc_xy_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_z_init (openmp_pscmc_env *  pe ,openmp_yee_damp_z_struct *  kerstr )
;
void  openmp_yee_damp_z_get_struct_len (size_t *  len )
;
int  openmp_yee_damp_z_get_num_compute_units (openmp_yee_damp_z_struct *  kerstr )
;
int  openmp_yee_damp_z_get_xlen ()
;
int  openmp_yee_damp_z_exec (openmp_yee_damp_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_damp_z_scmc_set_parameter_outEB (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_z_scmc_set_parameter_inEB (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_z_scmc_set_parameter_cur_rankx (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_z_scmc_set_parameter_cur_ranky (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_z_scmc_set_parameter_cur_rankz (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_z_scmc_set_parameter_y_cpu_core (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_z_scmc_set_parameter_numvec (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_z_scmc_set_parameter_XLEN (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_z_scmc_set_parameter_YLEN (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_z_scmc_set_parameter_ZLEN (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_z_scmc_set_parameter_ovlp (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_z_scmc_set_parameter_xblock (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_z_scmc_set_parameter_yblock (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_z_scmc_set_parameter_zblock (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_z_scmc_set_parameter_num_ele (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_z_scmc_set_parameter_damp_vars (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_z_scmc_set_parameter_deltat (openmp_yee_damp_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_z_init (openmp_pscmc_env *  pe ,openmp_yee_pec_z_struct *  kerstr )
;
void  openmp_yee_pec_z_get_struct_len (size_t *  len )
;
int  openmp_yee_pec_z_get_num_compute_units (openmp_yee_pec_z_struct *  kerstr )
;
int  openmp_yee_pec_z_get_xlen ()
;
int  openmp_yee_pec_z_exec (openmp_yee_pec_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_pec_z_scmc_set_parameter_outEB (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_z_scmc_set_parameter_inEB (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_z_scmc_set_parameter_cur_rankx (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_z_scmc_set_parameter_cur_ranky (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_z_scmc_set_parameter_cur_rankz (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_z_scmc_set_parameter_y_cpu_core (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_z_scmc_set_parameter_numvec (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_z_scmc_set_parameter_XLEN (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_z_scmc_set_parameter_YLEN (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_z_scmc_set_parameter_ZLEN (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_z_scmc_set_parameter_ovlp (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_z_scmc_set_parameter_xblock (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_z_scmc_set_parameter_yblock (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_z_scmc_set_parameter_zblock (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_z_scmc_set_parameter_num_ele (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_z_scmc_set_parameter_damp_vars (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_z_scmc_set_parameter_deltat (openmp_yee_pec_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_z_init (openmp_pscmc_env *  pe ,openmp_yee_abc_z_struct *  kerstr )
;
void  openmp_yee_abc_z_get_struct_len (size_t *  len )
;
int  openmp_yee_abc_z_get_num_compute_units (openmp_yee_abc_z_struct *  kerstr )
;
int  openmp_yee_abc_z_get_xlen ()
;
int  openmp_yee_abc_z_exec (openmp_yee_abc_z_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_abc_z_scmc_set_parameter_outEB (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_z_scmc_set_parameter_inEB (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_z_scmc_set_parameter_cur_rankx (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_z_scmc_set_parameter_cur_ranky (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_z_scmc_set_parameter_cur_rankz (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_z_scmc_set_parameter_y_cpu_core (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_z_scmc_set_parameter_numvec (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_z_scmc_set_parameter_XLEN (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_z_scmc_set_parameter_YLEN (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_z_scmc_set_parameter_ZLEN (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_z_scmc_set_parameter_ovlp (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_z_scmc_set_parameter_xblock (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_z_scmc_set_parameter_yblock (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_z_scmc_set_parameter_zblock (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_z_scmc_set_parameter_num_ele (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_z_scmc_set_parameter_damp_vars (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_z_scmc_set_parameter_deltat (openmp_yee_abc_z_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_y_init (openmp_pscmc_env *  pe ,openmp_yee_damp_y_struct *  kerstr )
;
void  openmp_yee_damp_y_get_struct_len (size_t *  len )
;
int  openmp_yee_damp_y_get_num_compute_units (openmp_yee_damp_y_struct *  kerstr )
;
int  openmp_yee_damp_y_get_xlen ()
;
int  openmp_yee_damp_y_exec (openmp_yee_damp_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_damp_y_scmc_set_parameter_outEB (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_y_scmc_set_parameter_inEB (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_y_scmc_set_parameter_cur_rankx (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_y_scmc_set_parameter_cur_ranky (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_y_scmc_set_parameter_cur_rankz (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_y_scmc_set_parameter_y_cpu_core (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_y_scmc_set_parameter_numvec (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_y_scmc_set_parameter_XLEN (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_y_scmc_set_parameter_YLEN (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_y_scmc_set_parameter_ZLEN (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_y_scmc_set_parameter_ovlp (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_y_scmc_set_parameter_xblock (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_y_scmc_set_parameter_yblock (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_y_scmc_set_parameter_zblock (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_y_scmc_set_parameter_num_ele (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_y_scmc_set_parameter_damp_vars (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_y_scmc_set_parameter_deltat (openmp_yee_damp_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_y_init (openmp_pscmc_env *  pe ,openmp_yee_pec_y_struct *  kerstr )
;
void  openmp_yee_pec_y_get_struct_len (size_t *  len )
;
int  openmp_yee_pec_y_get_num_compute_units (openmp_yee_pec_y_struct *  kerstr )
;
int  openmp_yee_pec_y_get_xlen ()
;
int  openmp_yee_pec_y_exec (openmp_yee_pec_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_pec_y_scmc_set_parameter_outEB (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_y_scmc_set_parameter_inEB (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_y_scmc_set_parameter_cur_rankx (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_y_scmc_set_parameter_cur_ranky (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_y_scmc_set_parameter_cur_rankz (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_y_scmc_set_parameter_y_cpu_core (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_y_scmc_set_parameter_numvec (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_y_scmc_set_parameter_XLEN (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_y_scmc_set_parameter_YLEN (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_y_scmc_set_parameter_ZLEN (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_y_scmc_set_parameter_ovlp (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_y_scmc_set_parameter_xblock (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_y_scmc_set_parameter_yblock (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_y_scmc_set_parameter_zblock (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_y_scmc_set_parameter_num_ele (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_y_scmc_set_parameter_damp_vars (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_y_scmc_set_parameter_deltat (openmp_yee_pec_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_y_init (openmp_pscmc_env *  pe ,openmp_yee_abc_y_struct *  kerstr )
;
void  openmp_yee_abc_y_get_struct_len (size_t *  len )
;
int  openmp_yee_abc_y_get_num_compute_units (openmp_yee_abc_y_struct *  kerstr )
;
int  openmp_yee_abc_y_get_xlen ()
;
int  openmp_yee_abc_y_exec (openmp_yee_abc_y_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_abc_y_scmc_set_parameter_outEB (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_y_scmc_set_parameter_inEB (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_y_scmc_set_parameter_cur_rankx (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_y_scmc_set_parameter_cur_ranky (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_y_scmc_set_parameter_cur_rankz (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_y_scmc_set_parameter_y_cpu_core (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_y_scmc_set_parameter_numvec (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_y_scmc_set_parameter_XLEN (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_y_scmc_set_parameter_YLEN (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_y_scmc_set_parameter_ZLEN (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_y_scmc_set_parameter_ovlp (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_y_scmc_set_parameter_xblock (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_y_scmc_set_parameter_yblock (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_y_scmc_set_parameter_zblock (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_y_scmc_set_parameter_num_ele (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_y_scmc_set_parameter_damp_vars (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_y_scmc_set_parameter_deltat (openmp_yee_abc_y_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_x_init (openmp_pscmc_env *  pe ,openmp_yee_damp_x_struct *  kerstr )
;
void  openmp_yee_damp_x_get_struct_len (size_t *  len )
;
int  openmp_yee_damp_x_get_num_compute_units (openmp_yee_damp_x_struct *  kerstr )
;
int  openmp_yee_damp_x_get_xlen ()
;
int  openmp_yee_damp_x_exec (openmp_yee_damp_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_damp_x_scmc_set_parameter_outEB (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_x_scmc_set_parameter_inEB (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_x_scmc_set_parameter_cur_rankx (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_x_scmc_set_parameter_cur_ranky (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_x_scmc_set_parameter_cur_rankz (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_x_scmc_set_parameter_y_cpu_core (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_x_scmc_set_parameter_numvec (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_x_scmc_set_parameter_XLEN (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_x_scmc_set_parameter_YLEN (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_x_scmc_set_parameter_ZLEN (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_x_scmc_set_parameter_ovlp (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_x_scmc_set_parameter_xblock (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_x_scmc_set_parameter_yblock (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_x_scmc_set_parameter_zblock (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_x_scmc_set_parameter_num_ele (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_x_scmc_set_parameter_damp_vars (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp_x_scmc_set_parameter_deltat (openmp_yee_damp_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_x_init (openmp_pscmc_env *  pe ,openmp_yee_pec_x_struct *  kerstr )
;
void  openmp_yee_pec_x_get_struct_len (size_t *  len )
;
int  openmp_yee_pec_x_get_num_compute_units (openmp_yee_pec_x_struct *  kerstr )
;
int  openmp_yee_pec_x_get_xlen ()
;
int  openmp_yee_pec_x_exec (openmp_yee_pec_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_pec_x_scmc_set_parameter_outEB (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_x_scmc_set_parameter_inEB (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_x_scmc_set_parameter_cur_rankx (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_x_scmc_set_parameter_cur_ranky (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_x_scmc_set_parameter_cur_rankz (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_x_scmc_set_parameter_y_cpu_core (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_x_scmc_set_parameter_numvec (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_x_scmc_set_parameter_XLEN (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_x_scmc_set_parameter_YLEN (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_x_scmc_set_parameter_ZLEN (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_x_scmc_set_parameter_ovlp (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_x_scmc_set_parameter_xblock (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_x_scmc_set_parameter_yblock (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_x_scmc_set_parameter_zblock (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_x_scmc_set_parameter_num_ele (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_x_scmc_set_parameter_damp_vars (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec_x_scmc_set_parameter_deltat (openmp_yee_pec_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_x_init (openmp_pscmc_env *  pe ,openmp_yee_abc_x_struct *  kerstr )
;
void  openmp_yee_abc_x_get_struct_len (size_t *  len )
;
int  openmp_yee_abc_x_get_num_compute_units (openmp_yee_abc_x_struct *  kerstr )
;
int  openmp_yee_abc_x_get_xlen ()
;
int  openmp_yee_abc_x_exec (openmp_yee_abc_x_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_abc_x_scmc_set_parameter_outEB (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_x_scmc_set_parameter_inEB (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_x_scmc_set_parameter_cur_rankx (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_x_scmc_set_parameter_cur_ranky (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_x_scmc_set_parameter_cur_rankz (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_x_scmc_set_parameter_y_cpu_core (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_x_scmc_set_parameter_numvec (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_x_scmc_set_parameter_XLEN (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_x_scmc_set_parameter_YLEN (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_x_scmc_set_parameter_ZLEN (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_x_scmc_set_parameter_ovlp (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_x_scmc_set_parameter_xblock (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_x_scmc_set_parameter_yblock (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_x_scmc_set_parameter_zblock (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_x_scmc_set_parameter_num_ele (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_x_scmc_set_parameter_damp_vars (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc_x_scmc_set_parameter_deltat (openmp_yee_abc_x_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp__init (openmp_pscmc_env *  pe ,openmp_yee_damp__struct *  kerstr )
;
void  openmp_yee_damp__get_struct_len (size_t *  len )
;
int  openmp_yee_damp__get_num_compute_units (openmp_yee_damp__struct *  kerstr )
;
int  openmp_yee_damp__get_xlen ()
;
int  openmp_yee_damp__exec (openmp_yee_damp__struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_damp__scmc_set_parameter_outEB (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp__scmc_set_parameter_inEB (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp__scmc_set_parameter_cur_rankx (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp__scmc_set_parameter_cur_ranky (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp__scmc_set_parameter_cur_rankz (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp__scmc_set_parameter_y_cpu_core (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp__scmc_set_parameter_numvec (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp__scmc_set_parameter_XLEN (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp__scmc_set_parameter_YLEN (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp__scmc_set_parameter_ZLEN (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp__scmc_set_parameter_ovlp (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp__scmc_set_parameter_xblock (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp__scmc_set_parameter_yblock (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp__scmc_set_parameter_zblock (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp__scmc_set_parameter_num_ele (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp__scmc_set_parameter_damp_vars (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_damp__scmc_set_parameter_deltat (openmp_yee_damp__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec__init (openmp_pscmc_env *  pe ,openmp_yee_pec__struct *  kerstr )
;
void  openmp_yee_pec__get_struct_len (size_t *  len )
;
int  openmp_yee_pec__get_num_compute_units (openmp_yee_pec__struct *  kerstr )
;
int  openmp_yee_pec__get_xlen ()
;
int  openmp_yee_pec__exec (openmp_yee_pec__struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_pec__scmc_set_parameter_outEB (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec__scmc_set_parameter_inEB (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec__scmc_set_parameter_cur_rankx (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec__scmc_set_parameter_cur_ranky (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec__scmc_set_parameter_cur_rankz (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec__scmc_set_parameter_y_cpu_core (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec__scmc_set_parameter_numvec (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec__scmc_set_parameter_XLEN (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec__scmc_set_parameter_YLEN (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec__scmc_set_parameter_ZLEN (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec__scmc_set_parameter_ovlp (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec__scmc_set_parameter_xblock (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec__scmc_set_parameter_yblock (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec__scmc_set_parameter_zblock (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec__scmc_set_parameter_num_ele (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec__scmc_set_parameter_damp_vars (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_pec__scmc_set_parameter_deltat (openmp_yee_pec__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc__init (openmp_pscmc_env *  pe ,openmp_yee_abc__struct *  kerstr )
;
void  openmp_yee_abc__get_struct_len (size_t *  len )
;
int  openmp_yee_abc__get_num_compute_units (openmp_yee_abc__struct *  kerstr )
;
int  openmp_yee_abc__get_xlen ()
;
int  openmp_yee_abc__exec (openmp_yee_abc__struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_yee_abc__scmc_set_parameter_outEB (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc__scmc_set_parameter_inEB (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc__scmc_set_parameter_cur_rankx (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc__scmc_set_parameter_cur_ranky (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc__scmc_set_parameter_cur_rankz (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc__scmc_set_parameter_y_cpu_core (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc__scmc_set_parameter_numvec (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc__scmc_set_parameter_XLEN (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc__scmc_set_parameter_YLEN (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc__scmc_set_parameter_ZLEN (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc__scmc_set_parameter_ovlp (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc__scmc_set_parameter_xblock (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc__scmc_set_parameter_yblock (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc__scmc_set_parameter_zblock (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc__scmc_set_parameter_num_ele (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc__scmc_set_parameter_damp_vars (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_yee_abc__scmc_set_parameter_deltat (openmp_yee_abc__struct *  kerstr ,openmp_pscmc_mem *  pm )
;
void  openmp_dm_1st_eqn_fdtd_scmc_kernel (double *  phi_out ,double *  phi_in ,double *  phi_1 ,double *  A1 ,double *  A2 ,double *  A3 ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_A1 ,double  DT ,double  M ,double  Q ,double  DM_A ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_dm_1st_eqn_core_scmc_kernel (double *  phi_out ,double *  phi_in ,double *  phi_1 ,double *  A1 ,double *  A2 ,double *  A3 ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_A1 ,double  DT ,double  M ,double  Q ,double  DM_A ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_dm_1st_eqn_right_scmc_kernel (double *  phi_out ,double *  phi_in ,double *  phi_1 ,double *  A1 ,double *  A2 ,double *  A3 ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_A1 ,double  DT ,double  M ,double  Q ,double  DM_A ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  openmp_dm_1st_eqn_right_init (openmp_pscmc_env *  pe ,openmp_dm_1st_eqn_right_struct *  kerstr )
;
void  openmp_dm_1st_eqn_right_get_struct_len (size_t *  len )
;
int  openmp_dm_1st_eqn_right_get_num_compute_units (openmp_dm_1st_eqn_right_struct *  kerstr )
;
int  openmp_dm_1st_eqn_right_get_xlen ()
;
int  openmp_dm_1st_eqn_right_exec (openmp_dm_1st_eqn_right_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_phi_out (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_phi_in (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_phi_1 (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_A1 (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_A2 (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_A3 (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_y_cpu_core (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_numvec (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_XLEN (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_YLEN (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_ZLEN (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_ovlp (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_xblock (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_yblock (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_zblock (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_num_ele (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_num_ele_A1 (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_DT (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_M (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_Q (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_right_scmc_set_parameter_DM_A (openmp_dm_1st_eqn_right_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_init (openmp_pscmc_env *  pe ,openmp_dm_1st_eqn_core_struct *  kerstr )
;
void  openmp_dm_1st_eqn_core_get_struct_len (size_t *  len )
;
int  openmp_dm_1st_eqn_core_get_num_compute_units (openmp_dm_1st_eqn_core_struct *  kerstr )
;
int  openmp_dm_1st_eqn_core_get_xlen ()
;
int  openmp_dm_1st_eqn_core_exec (openmp_dm_1st_eqn_core_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_phi_out (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_phi_in (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_phi_1 (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_A1 (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_A2 (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_A3 (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_y_cpu_core (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_numvec (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_XLEN (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_YLEN (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_ZLEN (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_ovlp (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_xblock (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_yblock (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_zblock (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_num_ele (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_num_ele_A1 (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_DT (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_M (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_Q (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_core_scmc_set_parameter_DM_A (openmp_dm_1st_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_init (openmp_pscmc_env *  pe ,openmp_dm_1st_eqn_fdtd_struct *  kerstr )
;
void  openmp_dm_1st_eqn_fdtd_get_struct_len (size_t *  len )
;
int  openmp_dm_1st_eqn_fdtd_get_num_compute_units (openmp_dm_1st_eqn_fdtd_struct *  kerstr )
;
int  openmp_dm_1st_eqn_fdtd_get_xlen ()
;
int  openmp_dm_1st_eqn_fdtd_exec (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_phi_out (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_phi_in (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_phi_1 (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_A1 (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_A2 (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_A3 (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_y_cpu_core (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_numvec (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_XLEN (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_YLEN (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_ZLEN (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_ovlp (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_xblock (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_yblock (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_zblock (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_num_ele (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_num_ele_A1 (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_DT (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_M (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_Q (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_dm_1st_eqn_fdtd_scmc_set_parameter_DM_A (openmp_dm_1st_eqn_fdtd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
void  openmp_RECT_YEE_CURL_L_scmc_kernel (double *  inoutE1 ,double *  inB0 ,int *  xoffset ,int *  yoffset ,int *  zoffset ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  openmp_RECT_YEE_CURL_L_init (openmp_pscmc_env *  pe ,openmp_RECT_YEE_CURL_L_struct *  kerstr )
;
void  openmp_RECT_YEE_CURL_L_get_struct_len (size_t *  len )
;
int  openmp_RECT_YEE_CURL_L_get_num_compute_units (openmp_RECT_YEE_CURL_L_struct *  kerstr )
;
int  openmp_RECT_YEE_CURL_L_get_xlen ()
;
int  openmp_RECT_YEE_CURL_L_exec (openmp_RECT_YEE_CURL_L_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_inoutE1 (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_inB0 (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_xoffset (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_yoffset (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_zoffset (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_y_cpu_core (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_numvec (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_XLEN (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_YLEN (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_ZLEN (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_ovlp (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_xblock (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_yblock (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_zblock (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_num_ele (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_DT (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_DELTA_X (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_DELTA_Y (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_RECT_YEE_CURL_L_scmc_set_parameter_DELTA_Z (openmp_RECT_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
void  openmp_GEO_YEE_CURL_L_scmc_kernel (double *  inoutE1 ,double *  inB0 ,int *  xoffset ,int *  yoffset ,int *  zoffset ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,double  DELTA_Z ,double  DELTA_Y ,double  DELTA_X ,double  x0 ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  openmp_GEO_YEE_CURL_L_init (openmp_pscmc_env *  pe ,openmp_GEO_YEE_CURL_L_struct *  kerstr )
;
void  openmp_GEO_YEE_CURL_L_get_struct_len (size_t *  len )
;
int  openmp_GEO_YEE_CURL_L_get_num_compute_units (openmp_GEO_YEE_CURL_L_struct *  kerstr )
;
int  openmp_GEO_YEE_CURL_L_get_xlen ()
;
int  openmp_GEO_YEE_CURL_L_exec (openmp_GEO_YEE_CURL_L_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_inoutE1 (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_inB0 (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_xoffset (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_yoffset (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_zoffset (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_y_cpu_core (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_numvec (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_XLEN (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_YLEN (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_ZLEN (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_ovlp (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_xblock (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_yblock (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_zblock (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_num_ele (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_DT (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_Z (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_Y (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_X (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_GEO_YEE_CURL_L_scmc_set_parameter_x0 (openmp_GEO_YEE_CURL_L_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_mass_floorx (double  x )
;
void  openmp_geo_rel_1st_fwd_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  LFoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  LFoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_geo_rel_1st_bwd_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  LFoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  LFoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_relng_1st_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  LFoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_relng_1st_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  LFoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  openmp_relng_1st_sg2_small_grids_init (openmp_pscmc_env *  pe ,openmp_relng_1st_sg2_small_grids_struct *  kerstr )
;
void  openmp_relng_1st_sg2_small_grids_get_struct_len (size_t *  len )
;
int  openmp_relng_1st_sg2_small_grids_get_num_compute_units (openmp_relng_1st_sg2_small_grids_struct *  kerstr )
;
int  openmp_relng_1st_sg2_small_grids_get_xlen ()
;
int  openmp_relng_1st_sg2_small_grids_exec (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_inoutput (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_xyzw (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_cu_cache (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_cu_xyzw (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_xoffset (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_yoffset (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_zoffset (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_fieldE (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_fieldB (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_fieldB1 (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_LFoutJ (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_XLEN (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_YLEN (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_ZLEN (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_ovlp (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_numvec (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_num_ele (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_grid_cache_len (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_cu_cache_length (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_DELTA_X (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_DELTA_Y (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_DELTA_Z (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_Mass0 (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_Charge0 (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_Deltat (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_Tori_X0 (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_sg2_small_grids_scmc_set_parameter_Solve_Err (openmp_relng_1st_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_init (openmp_pscmc_env *  pe ,openmp_relng_1st_small_grids_struct *  kerstr )
;
void  openmp_relng_1st_small_grids_get_struct_len (size_t *  len )
;
int  openmp_relng_1st_small_grids_get_num_compute_units (openmp_relng_1st_small_grids_struct *  kerstr )
;
int  openmp_relng_1st_small_grids_get_xlen ()
;
int  openmp_relng_1st_small_grids_exec (openmp_relng_1st_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_inoutput (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_xyzw (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_cu_cache (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_cu_xyzw (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_xoffset (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_yoffset (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_zoffset (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_fieldE (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_fieldB (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_fieldB1 (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_LFoutJ (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_XLEN (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_YLEN (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_ZLEN (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_ovlp (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_numvec (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_num_ele (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_grid_cache_len (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_cu_cache_length (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_DELTA_X (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_DELTA_Y (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_DELTA_Z (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_Mass0 (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_Charge0 (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_Deltat (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_Tori_X0 (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_small_grids_scmc_set_parameter_Solve_Err (openmp_relng_1st_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_init (openmp_pscmc_env *  pe ,openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr )
;
void  openmp_geo_rel_1st_bwd_sg2_small_grids_get_struct_len (size_t *  len )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_get_num_compute_units (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_get_xlen ()
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_exec (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_inoutput (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_xyzw (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_cu_cache (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_cu_xyzw (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_xoffset (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_yoffset (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_zoffset (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_fieldE (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_fieldB (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_fieldB1 (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_LFoutJ (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_XLEN (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_YLEN (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_ZLEN (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_ovlp (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_numvec (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_num_ele (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_grid_cache_len (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_cu_cache_length (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_DELTA_X (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_DELTA_Y (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_DELTA_Z (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_Mass0 (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_Charge0 (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_Deltat (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_Tori_X0 (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_set_parameter_Solve_Err (openmp_geo_rel_1st_bwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_init (openmp_pscmc_env *  pe ,openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr )
;
void  openmp_geo_rel_1st_bwd_small_grids_get_struct_len (size_t *  len )
;
int  openmp_geo_rel_1st_bwd_small_grids_get_num_compute_units (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr )
;
int  openmp_geo_rel_1st_bwd_small_grids_get_xlen ()
;
int  openmp_geo_rel_1st_bwd_small_grids_exec (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_inoutput (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_xyzw (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_cu_cache (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_cu_xyzw (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_xoffset (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_yoffset (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_zoffset (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_fieldE (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_fieldB (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_fieldB1 (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_LFoutJ (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_XLEN (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_YLEN (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_ZLEN (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_ovlp (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_numvec (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_num_ele (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_grid_cache_len (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_cu_cache_length (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_DELTA_X (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_DELTA_Y (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_DELTA_Z (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_Mass0 (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_Charge0 (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_Deltat (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_Tori_X0 (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_small_grids_scmc_set_parameter_Solve_Err (openmp_geo_rel_1st_bwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_init (openmp_pscmc_env *  pe ,openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr )
;
void  openmp_geo_rel_1st_fwd_sg2_small_grids_get_struct_len (size_t *  len )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_get_num_compute_units (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_get_xlen ()
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_exec (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_inoutput (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_xyzw (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_cu_cache (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_cu_xyzw (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_xoffset (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_yoffset (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_zoffset (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_fieldE (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_fieldB (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_fieldB1 (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_LFoutJ (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_XLEN (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_YLEN (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_ZLEN (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_ovlp (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_numvec (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_num_ele (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_grid_cache_len (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_cu_cache_length (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_DELTA_X (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_DELTA_Y (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_DELTA_Z (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_Mass0 (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_Charge0 (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_Deltat (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_Tori_X0 (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_set_parameter_Solve_Err (openmp_geo_rel_1st_fwd_sg2_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_init (openmp_pscmc_env *  pe ,openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr )
;
void  openmp_geo_rel_1st_fwd_small_grids_get_struct_len (size_t *  len )
;
int  openmp_geo_rel_1st_fwd_small_grids_get_num_compute_units (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr )
;
int  openmp_geo_rel_1st_fwd_small_grids_get_xlen ()
;
int  openmp_geo_rel_1st_fwd_small_grids_exec (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_inoutput (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_xyzw (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_cu_cache (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_cu_xyzw (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_xoffset (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_yoffset (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_zoffset (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_fieldE (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_fieldB (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_fieldB1 (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_LFoutJ (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_XLEN (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_YLEN (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_ZLEN (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_ovlp (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_numvec (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_num_ele (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_grid_cache_len (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_cu_cache_length (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_DELTA_X (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_DELTA_Y (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_DELTA_Z (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_Mass0 (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_Charge0 (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_Deltat (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_Tori_X0 (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_small_grids_scmc_set_parameter_Solve_Err (openmp_geo_rel_1st_fwd_small_grids_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_floorx (double  x )
;
void  openmp_geo_rel_1st_fwd_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_geo_rel_1st_bwd_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  openmp_geo_rel_1st_bwd_init (openmp_pscmc_env *  pe ,openmp_geo_rel_1st_bwd_struct *  kerstr )
;
void  openmp_geo_rel_1st_bwd_get_struct_len (size_t *  len )
;
int  openmp_geo_rel_1st_bwd_get_num_compute_units (openmp_geo_rel_1st_bwd_struct *  kerstr )
;
int  openmp_geo_rel_1st_bwd_get_xlen ()
;
int  openmp_geo_rel_1st_bwd_exec (openmp_geo_rel_1st_bwd_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_inoutput (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_xyzw (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_cu_cache (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_cu_xyzw (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_xoffset (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_yoffset (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_zoffset (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_fieldE (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_fieldB (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_fieldB1 (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_FoutJ (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_XLEN (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_YLEN (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_ZLEN (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_ovlp (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_numvec (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_num_ele (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_grid_cache_len (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_cu_cache_length (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_DELTA_X (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_DELTA_Y (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_DELTA_Z (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_Mass0 (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_Charge0 (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_Deltat (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_Tori_X0 (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_bwd_scmc_set_parameter_Solve_Err (openmp_geo_rel_1st_bwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_init (openmp_pscmc_env *  pe ,openmp_geo_rel_1st_fwd_struct *  kerstr )
;
void  openmp_geo_rel_1st_fwd_get_struct_len (size_t *  len )
;
int  openmp_geo_rel_1st_fwd_get_num_compute_units (openmp_geo_rel_1st_fwd_struct *  kerstr )
;
int  openmp_geo_rel_1st_fwd_get_xlen ()
;
int  openmp_geo_rel_1st_fwd_exec (openmp_geo_rel_1st_fwd_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_inoutput (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_xyzw (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_cu_cache (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_cu_xyzw (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_xoffset (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_yoffset (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_zoffset (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_fieldE (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_fieldB (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_fieldB1 (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_FoutJ (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_XLEN (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_YLEN (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_ZLEN (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_ovlp (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_numvec (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_num_ele (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_grid_cache_len (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_cu_cache_length (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_DELTA_X (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_DELTA_Y (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_DELTA_Z (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_Mass0 (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_Charge0 (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_Deltat (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_Tori_X0 (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_geo_rel_1st_fwd_scmc_set_parameter_Solve_Err (openmp_geo_rel_1st_fwd_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_floory (double  x )
;
void  openmp_relng_1st_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;

#include "local_header.h"
int  openmp_relng_1st_init (openmp_pscmc_env *  pe ,openmp_relng_1st_struct *  kerstr )
;
void  openmp_relng_1st_get_struct_len (size_t *  len )
;
int  openmp_relng_1st_get_num_compute_units (openmp_relng_1st_struct *  kerstr )
;
int  openmp_relng_1st_get_xlen ()
;
int  openmp_relng_1st_exec (openmp_relng_1st_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  openmp_relng_1st_scmc_set_parameter_inoutput (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_xyzw (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_cu_cache (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_cu_xyzw (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_xoffset (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_yoffset (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_zoffset (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_fieldE (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_fieldB (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_fieldB1 (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_FoutJ (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_XLEN (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_YLEN (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_ZLEN (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_ovlp (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_numvec (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_num_ele (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_grid_cache_len (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_cu_cache_length (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_DELTA_X (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_DELTA_Y (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_DELTA_Z (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_Mass0 (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_Charge0 (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_Deltat (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_Tori_X0 (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_relng_1st_scmc_set_parameter_Solve_Err (openmp_relng_1st_struct *  kerstr ,openmp_pscmc_mem *  pm )
;

#include "local_header.h"
int  openmp_pscmc_mem_init (openmp_pscmc_env *  pe ,openmp_pscmc_mem *  pm ,int  type ,size_t  len )
;
int  openmp_pscmc_get_local_len ()
;
int  openmp_pscmc_get_env_len (size_t *  l )
;
int  openmp_pscmc_flush (openmp_pscmc_env *  pe )
;
void *  openmp_pscmc_get_h_data (openmp_pscmc_mem *  pm ,void * *  h_data )
;
int  openmp_pscmc_mem_destroy (openmp_pscmc_mem *  pm )
;
int  openmp_pscmc_mem_sync_d2h (openmp_pscmc_mem *  pm )
;
int  openmp_pscmc_mem_sync_h2d (openmp_pscmc_mem *  pm )
;
int  openmp_pscmc_env_init (openmp_pscmc_env *  pe ,int  dev_num ,void *  fv )
;
size_t  openmp_pscmc_mem_get_num (openmp_pscmc_mem *  pm )
;
