double  openmp_get_E1_local_opt (double *  shE0 ,double *  f1_x ,double *  f0_y ,double *  f0_z ,int  dir ,int  l_dir )
;
double  openmp_get_B1_local_opt (double *  shB0 ,double *  if1_x ,double *  if1_xplus ,double *  f1_y ,double *  f0_z ,int  dir ,int  l_dir )
;
void  openmp_cal_fun_f0 (double *  outf ,double  x ,int  ix )
;
void  openmp_cal_fun_f1 (double *  outf ,double  x ,int  ix )
;
void  openmp_cal_fun_if1 (double *  outf ,double  x ,int  ix )
;
void  openmp_cal_fun_df0 (double *  outf ,double  x ,int  ix )
;
void  openmp_cal_fun_dif1 (double *  outf ,double  x ,int  ix )
;
void  openmp_relng_1st_goto_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
