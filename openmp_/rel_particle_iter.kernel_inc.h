typedef struct { 	double *  inoutput ;
	int *  xyzw ;
	double *  cu_cache ;
	int *  cu_xyzw ;
	int *  xoffset ;
	int *  yoffset ;
	int *  zoffset ;
	double *  fieldE ;
	double *  fieldB ;
	double *  fieldB1 ;
	double *  FoutJ ;
	long *  XLEN ;
	long *  YLEN ;
	long *  ZLEN ;
	int *  ovlp ;
	long *  numvec ;
	int *  num_ele ;
	long *  grid_cache_len ;
	long *  cu_cache_length ;
	double *  DELTA_X ;
	double *  DELTA_Y ;
	double *  DELTA_Z ;
	double *  Mass0 ;
	double *  Charge0 ;
	double *  Deltat ;
	double *  Tori_X0 ;
	double *  Solve_Err ;
	long  inoutput_len ;
	long  xyzw_len ;
	long  cu_cache_len ;
	long  cu_xyzw_len ;
	long  xoffset_len ;
	long  yoffset_len ;
	long  zoffset_len ;
	long  fieldE_len ;
	long  fieldB_len ;
	long  fieldB1_len ;
	long  FoutJ_len ;
	long  XLEN_len ;
	long  YLEN_len ;
	long  ZLEN_len ;
	long  ovlp_len ;
	long  numvec_len ;
	long  num_ele_len ;
	long  grid_cache_len_len ;
	long  cu_cache_length_len ;
	long  DELTA_X_len ;
	long  DELTA_Y_len ;
	long  DELTA_Z_len ;
	long  Mass0_len ;
	long  Charge0_len ;
	long  Deltat_len ;
	long  Tori_X0_len ;
	long  Solve_Err_len ;
} openmp_relng_1st_struct;void  openmp_relng_1st_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  yid_kernel ,long  ylen_kernel );
