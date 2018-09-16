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
