
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
