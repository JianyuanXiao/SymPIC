typedef struct { 	int *  xyzw ;
	double *  cu_cache ;
	int *  cu_xyzw ;
	double *  fieldE ;
	double *  fieldB ;
	double *  FoutJ ;
	long *  XLEN ;
	long *  YLEN ;
	long *  ZLEN ;
	int *  ovlp ;
	long *  numvec ;
	int *  num_ele ;
	long *  grid_cache_len ;
	long *  cu_cache_length ;
	double *  Mass0 ;
	double *  Charge0 ;
	double *  Deltat ;
	double *  DELTA_X ;
	double *  DELTA_Y ;
	double *  DELTA_Z ;
	int *  N_l ;
	int *  N_M ;
	int *  push_J ;
	long  xyzw_len ;
	long  cu_cache_len ;
	long  cu_xyzw_len ;
	long  fieldE_len ;
	long  fieldB_len ;
	long  FoutJ_len ;
	long  XLEN_len ;
	long  YLEN_len ;
	long  ZLEN_len ;
	long  ovlp_len ;
	long  numvec_len ;
	long  num_ele_len ;
	long  grid_cache_len_len ;
	long  cu_cache_length_len ;
	long  Mass0_len ;
	long  Charge0_len ;
	long  Deltat_len ;
	long  DELTA_X_len ;
	long  DELTA_Y_len ;
	long  DELTA_Z_len ;
	long  N_l_len ;
	long  N_M_len ;
	long  push_J_len ;
} c_split_pass_xyzE_particle_push_r_struct;void  c_split_pass_xyzE_particle_push_r_scmc_kernel (int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,int  N_l ,int  N_M ,int  push_J ,long  yid_kernel ,long  ylen_kernel );
typedef struct { 	int *  xyzw ;
	double *  cu_cache ;
	int *  cu_xyzw ;
	double *  fieldE ;
	double *  fieldB ;
	double *  FoutJ ;
	long *  XLEN ;
	long *  YLEN ;
	long *  ZLEN ;
	int *  ovlp ;
	long *  numvec ;
	int *  num_ele ;
	long *  grid_cache_len ;
	long *  cu_cache_length ;
	double *  Mass0 ;
	double *  Charge0 ;
	double *  Deltat ;
	double *  DELTA_X ;
	double *  DELTA_Y ;
	double *  DELTA_Z ;
	int *  N_l ;
	int *  N_M ;
	int *  push_J ;
	long  xyzw_len ;
	long  cu_cache_len ;
	long  cu_xyzw_len ;
	long  fieldE_len ;
	long  fieldB_len ;
	long  FoutJ_len ;
	long  XLEN_len ;
	long  YLEN_len ;
	long  ZLEN_len ;
	long  ovlp_len ;
	long  numvec_len ;
	long  num_ele_len ;
	long  grid_cache_len_len ;
	long  cu_cache_length_len ;
	long  Mass0_len ;
	long  Charge0_len ;
	long  Deltat_len ;
	long  DELTA_X_len ;
	long  DELTA_Y_len ;
	long  DELTA_Z_len ;
	long  N_l_len ;
	long  N_M_len ;
	long  push_J_len ;
} c_split_pass_xyzE_particle_struct;void  c_split_pass_xyzE_particle_scmc_kernel (int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,int  N_l ,int  N_M ,int  push_J ,long  yid_kernel ,long  ylen_kernel );
