
#include "local_header.h"
int  c_kgm_eqn_core_init (c_pscmc_env *  pe ,c_kgm_eqn_core_struct *  kerstr )
;
void  c_kgm_eqn_core_get_struct_len (size_t *  len )
;
int  c_kgm_eqn_core_get_xlen ()
;
int  c_kgm_eqn_core_exec (c_kgm_eqn_core_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen )
;
int  c_kgm_eqn_core_scmc_set_parameter_outEB (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
;
int  c_kgm_eqn_core_scmc_set_parameter_inEB (c_kgm_eqn_core_struct *  kerstr ,c_pscmc_mem *  pm )
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
int  c_merge_current_init (c_pscmc_env *  pe ,c_merge_current_struct *  kerstr )
;
void  c_merge_current_get_struct_len (size_t *  len )
;
int  c_merge_current_get_xlen ()
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
int  c_Yee_FDTD_Div_FWD_4th_init (c_pscmc_env *  pe ,c_Yee_FDTD_Div_FWD_4th_struct *  kerstr )
;
void  c_Yee_FDTD_Div_FWD_4th_get_struct_len (size_t *  len )
;
int  c_Yee_FDTD_Div_FWD_4th_get_xlen ()
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
