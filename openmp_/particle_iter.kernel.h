void  openmp_split_pass_x_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_x_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_x_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_x_vlo_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_y_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_y_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_y_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_y_vlo_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_z_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_z_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_z_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_z_vlo_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_E_particle_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_split_pass_E_particle_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_boris_yee_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass0 ,double  Charge0 ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_krook_collision_remove_small_speed_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  mu_freq ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_krook_collision_test_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  mu_freq ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_calculate_rho_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  openmp_dump_ene_num_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
