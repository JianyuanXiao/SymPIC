
#include "local_header.h"
int  openmp_move_back_kernel_init (openmp_pscmc_env *  pe ,openmp_move_back_kernel_struct *  kerstr )
;
void  openmp_move_back_kernel_get_struct_len (size_t *  len )
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
