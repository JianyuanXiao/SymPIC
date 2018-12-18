
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
