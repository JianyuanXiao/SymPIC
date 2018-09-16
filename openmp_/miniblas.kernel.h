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
