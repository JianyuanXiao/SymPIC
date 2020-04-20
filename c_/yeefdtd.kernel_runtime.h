
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
