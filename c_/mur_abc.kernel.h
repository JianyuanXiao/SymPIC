void  c_yee_abc__scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_pec__scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_damp__scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_abc_x_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_pec_x_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_damp_x_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_abc_y_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_pec_y_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_damp_y_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_abc_z_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_pec_z_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_damp_z_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_abc_xy_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_pec_xy_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_damp_xy_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_abc_xz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_pec_xz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_damp_xz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_abc_yz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_pec_yz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_damp_yz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_abc_xyz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_pec_xyz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
void  c_yee_damp_xyz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen )
;
