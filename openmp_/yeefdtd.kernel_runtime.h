
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
int  openmp_kgm_eqn_core_scmc_set_parameter_extA0 (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
;
int  openmp_kgm_eqn_core_scmc_set_parameter_extA1 (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
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
int  openmp_kgm_eqn_core_scmc_set_parameter_g_beg (openmp_kgm_eqn_core_struct *  kerstr ,openmp_pscmc_mem *  pm )
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
