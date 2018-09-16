void  openmp_dm_1st_eqn_fdtd_scmc_kernel (double *  phi_out ,double *  phi_in ,double *  phi_1 ,double *  A1 ,double *  A2 ,double *  A3 ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_A1 ,double  DT ,double  M ,double  Q ,double  DM_A ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_dm_1st_eqn_core_scmc_kernel (double *  phi_out ,double *  phi_in ,double *  phi_1 ,double *  A1 ,double *  A2 ,double *  A3 ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_A1 ,double  DT ,double  M ,double  Q ,double  DM_A ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_dm_1st_eqn_right_scmc_kernel (double *  phi_out ,double *  phi_in ,double *  phi_1 ,double *  A1 ,double *  A2 ,double *  A3 ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,int  num_ele_A1 ,double  DT ,double  M ,double  Q ,double  DM_A ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
