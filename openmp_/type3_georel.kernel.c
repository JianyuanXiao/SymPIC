#include <omp.h> 
#include <math.h>

#include <math.h>
#include <assert.h>
#include <stdio.h>
#define IDX_OPT_MAX 1
double  openmp_get_E1_local_opt (double *  shE0 ,double *  f1_x ,double *  f0_y ,double *  f0_z ,int  dir ,int  l_dir ){
	double  sum0 = 0.00000000000000000e+00 ;
	double *  ftmp ;
	if (  	(  dir == 1 )  ){  
		(ftmp = f0_y);
(f0_y = f1_x);
(f1_x = f0_z);
(f0_z = ftmp);

	}else{
			if (  	(  dir == 2 )  ){  
		(ftmp = f0_y);
(f0_y = f0_z);
(f0_z = f1_x);
(f1_x = ftmp);

	}else{
		0;

	 }

	 }
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 5 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 5 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  allidx = 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ;
(sum0 = 	(  sum0 + 	(  (shE0)[	(  	(  allidx * 3 ) + l_dir )] * 	(  (f1_x)[xyzx] * 	(  (f0_y)[xyzy] * (f0_z)[xyzz] ) ) ) ));
}}}}}}	return  sum0 ;}
double  openmp_get_B1_local_opt (double *  shB0 ,double *  if1_x ,double *  if1_xplus ,double *  f1_y ,double *  f0_z ,int  dir ,int  l_dir ){
	double  sum0 = 0.00000000000000000e+00 ;
	if (  	(  dir == 0 )  ){  
		{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 5 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 5 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  allidx ;
(allidx = 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ));
(sum0 = 	(  sum0 + 	(  (shB0)[	(  	(  allidx * 3 ) + l_dir )] * 	(  	(  (if1_xplus)[xyzx] - (if1_x)[xyzx] ) * 	(  (f1_y)[xyzy] * (f0_z)[xyzz] ) ) ) ));
}}}}}}
	}else{
			if (  	(  dir == 1 )  ){  
		{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 5 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 5 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  allidx ;
(allidx = 	(  xyzz + 	(  5 * 	(  xyzx + 	(  5 * xyzy ) ) ) ));
(sum0 = 	(  sum0 + 	(  (shB0)[	(  	(  allidx * 3 ) + l_dir )] * 	(  	(  (if1_xplus)[xyzx] - (if1_x)[xyzx] ) * 	(  (f1_y)[xyzy] * (f0_z)[xyzz] ) ) ) ));
}}}}}}
	}else{
			if (  	(  dir == 2 )  ){  
		{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 5 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 5 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  allidx ;
(allidx = 	(  xyzy + 	(  5 * 	(  xyzz + 	(  5 * xyzx ) ) ) ));
(sum0 = 	(  sum0 + 	(  (shB0)[	(  	(  allidx * 3 ) + l_dir )] * 	(  	(  (if1_xplus)[xyzx] - (if1_x)[xyzx] ) * 	(  (f1_y)[xyzy] * (f0_z)[xyzz] ) ) ) ));
}}}}}}
	}else{
		0;

	 }

	 }

	 }
	return  sum0 ;}
void  openmp_cal_fun_f0 (double *  outf ,double  x ,int  ix ){
{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((outf)[i] = 0);
}}((outf)[	(  0 + 	(  ix + 1 ) )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * x ) ) , 2 ) ));
((outf)[	(  1 + 	(  ix + 1 ) )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * x ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * x ) ) ) ) ) ));
((outf)[	(  2 + 	(  ix + 1 ) )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * x ) + 	pow ( x , 2 ) ) ) ));
((outf)[	(  3 + 	(  ix + 1 ) )] = 	(  2.50000000000000000e-01 * 	pow ( x , 2 ) ));
}
void  openmp_cal_fun_f1 (double *  outf ,double  x ,int  ix ){
{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((outf)[i] = 0);
}}((outf)[	(  0 + 	(  ix + 1 ) )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * x ) ) ));
((outf)[	(  1 + 	(  ix + 1 ) )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * x ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * x ) ) ) ));
((outf)[	(  2 + 	(  ix + 1 ) )] = 	(  5.00000000000000000e-01 * x ));
}
void  openmp_cal_fun_if1 (double *  outf ,double  x ,int  ix ){
((outf)[0] = 1);
((outf)[1] = 1);
((outf)[3] = 0);
((outf)[4] = 0);
((outf)[	(  0 + 	(  ix + 1 ) )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * x ) ) , 2 ) ) ));
((outf)[	(  1 + 	(  ix + 1 ) )] = 	(  	(  2.50000000000000000e-01 * 	pow ( x , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * x ) + 	pow ( x , 2 ) ) ) ) ));
((outf)[	(  2 + 	(  ix + 1 ) )] = 	(  2.50000000000000000e-01 * 	pow ( x , 2 ) ));
}
void  openmp_cal_fun_df0 (double *  outf ,double  x ,int  ix ){
{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((outf)[i] = 0);
}}((outf)[	(  0 + 	(  ix + 1 ) )] = 	(  -5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * x ) ) ));
((outf)[	(  1 + 	(  ix + 1 ) )] = 	(  -2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * x ) ) ) ) ));
((outf)[	(  2 + 	(  ix + 1 ) )] = 	(  -2.50000000000000000e-01 * 	(  -2.00000000000000000e+00 + 	(  2.00000000000000000e+00 * x ) ) ));
((outf)[	(  3 + 	(  ix + 1 ) )] = 	(  5.00000000000000000e-01 * x ));
}
void  openmp_cal_fun_dif1 (double *  outf ,double  x ,int  ix ){
{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((outf)[i] = 0);
}}((outf)[	(  0 + 	(  ix + 1 ) )] = -5.00000000000000000e-01);
((outf)[	(  1 + 	(  ix + 1 ) )] = 0.00000000000000000e+00);
((outf)[	(  2 + 	(  ix + 1 ) )] = 5.00000000000000000e-01);
}
void  openmp_relng_1st_goto_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN 
#endif
#define IDX_LOCAL_XLEN 1
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	void *   call_stack_pointer  [4];	int  cur_frame_num = 0 ;
	long  numgrid = 	(  XLEN * 	(  YLEN * ZLEN ) ) ;
	long  numallgrid = 	(  	(  XLEN + 	(  ovlp + ovlp ) ) * 	(  	(  YLEN + 	(  ovlp + ovlp ) ) * 	(  ZLEN + 	(  ovlp + ovlp ) ) ) ) ;
	long  numgrid_cu = 	(  numgrid * numvec ) ;
	long  grid_base_offset = 	(  idy * 	(  numgrid * 	(  grid_cache_len * 6 ) ) ) ;
	int  cu_load = (cu_xyzw)[	(  4 * idy )] ;
	long  load0 = 0 ;
	double *  particle_head_general ;
	long  i_idy = 0 ;
	double  DELTAT = Deltat ;
	double  grid_geo_x = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_y = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_z = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  XO ;
	double  X0 ;
	double  X1 ;
	double  X2 ;
	double  Y0 ;
	double  Y1 ;
	double  Y2 ;
	double  Z0 ;
	double  Z1 ;
	double  Z2 ;
	double   shB0  [375];	double   shB1  [375];	double   shE0  [375];	double   shJ0  [375];	double   f0_x0  [5];	double   f1_x0  [5];	double   if1_x0  [5];	double   f0_y0  [5];	double   f1_y0  [5];	double   if1_y0  [5];	double   f0_z0  [5];	double   f1_z0  [5];	double   if1_z0  [5];	double   f0_x1  [5];	double   f1_x1  [5];	double   if1_x1  [5];	double   f0_y1  [5];	double   f1_y1  [5];	double   if1_y1  [5];	double   f0_z1  [5];	double   f1_z1  [5];	double   if1_z1  [5];	double   f0_x2  [5];	double   f1_x2  [5];	double   if1_x2  [5];	double   df0_x2  [5];	double   dif1_x2  [5];	double   f0_y2  [5];	double   f1_y2  [5];	double   if1_y2  [5];	double   df0_y2  [5];	double   dif1_y2  [5];	double   f0_z2  [5];	double   f1_z2  [5];	double   if1_z2  [5];	double   df0_z2  [5];	double   dif1_z2  [5];	goto beg_prog;	core_fun:
	if (  load0  ){  
		(XO = (xoffset)[i_idy]);
	int  Midx = 	floor ( (particle_head_general)[0] ) ;
	int  Midy = 	floor ( (particle_head_general)[1] ) ;
	int  Midz = 	floor ( (particle_head_general)[2] ) ;
	int  Bidx = 	(  Midx - 2 ) ;
	int  Bidy = 	(  Midy - 2 ) ;
	int  Bidz = 	(  Midz - 2 ) ;
	double  Mass = 1.00000000000000000e+00 ;
	double  Charge = 	(  Charge0 / Mass0 ) ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 5 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  total_idx = 	(  3 * 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 	(  3 * 5 ) ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 	(  3 * 5 ) )  ){  
		((	(  shE0 + total_idx ))[ridx] = (	(  fieldE + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 	(  3 * 5 ) ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 	(  3 * 5 ) )  ){  
		((	(  shB0 + total_idx ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 	(  3 * 5 ) ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 	(  3 * 5 ) )  ){  
		((	(  shB1 + total_idx ))[ridx] = (	(  fieldB1 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 	(  3 * 5 ) ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 	(  3 * 5 ) )  ){  
		((	(  shJ0 + total_idx ))[ridx] = (	(  FoutJ + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}}}{
	long  g_inner ;
	for ((g_inner = 0) ; 	(  g_inner < load0 ) ; (g_inner = 	(  g_inner + 1 )))
	{
	double   local_particle_head  [6];{
	long  stmpg1 ;
	for ((stmpg1 = 0) ; 	(  stmpg1 < 6 ) ; (stmpg1 = 	(  stmpg1 + 1 )))
	{
((local_particle_head)[stmpg1] = (particle_head_general)[	(  stmpg1 + 	(  g_inner * 6 ) )]);
}}	double  vx0 = (local_particle_head)[3] ;
	double  vy0 = (local_particle_head)[4] ;
	double  vz0 = (local_particle_head)[5] ;
	double  xx1 = 	(  (local_particle_head)[0] - 5.00000000000000000e-01 ) ;
	double  xy1 = 	(  (local_particle_head)[1] - 5.00000000000000000e-01 ) ;
	double  xz1 = 	(  (local_particle_head)[2] - 5.00000000000000000e-01 ) ;
	double  xx0 = 	(  xx1 - 	(  Deltat * vx0 ) ) ;
	double  xy0 = 	(  xy1 - 	(  Deltat * vy0 ) ) ;
	double  xz0 = 	(  xz1 - 	(  Deltat * vz0 ) ) ;
	double  Midx0 = 	floor ( xx0 ) ;
	double  Midy0 = 	floor ( xy0 ) ;
	double  Midz0 = 	floor ( xz0 ) ;
	double  Midx1 = 	floor ( xx1 ) ;
	double  Midy1 = 	floor ( xy1 ) ;
	double  Midz1 = 	floor ( xz1 ) ;
	int  ixx0 = 	(  Midx0 - Midx ) ;
	int  ixy0 = 	(  Midy0 - Midy ) ;
	int  ixz0 = 	(  Midz0 - Midz ) ;
	int  ixx1 = 	(  Midx1 - Midx ) ;
	int  ixy1 = 	(  Midy1 - Midy ) ;
	int  ixz1 = 	(  Midz1 - Midz ) ;
	double  rx0 = 	(  xx0 - Midx0 ) ;
	double  ry0 = 	(  xy0 - Midy0 ) ;
	double  rz0 = 	(  xz0 - Midz0 ) ;
	double  rx1 = 	(  xx1 - Midx1 ) ;
	double  ry1 = 	(  xy1 - Midy1 ) ;
	double  rz1 = 	(  xz1 - Midz1 ) ;
(X0 = xx0);
(X1 = xx1);
(Y0 = xy0);
(Y1 = xy1);
(Z0 = xz0);
(Z1 = xz1);
	openmp_cal_fun_f0 ( f0_x0 , rx0 , ixx0 );
	openmp_cal_fun_f0 ( f0_y0 , ry0 , ixy0 );
	openmp_cal_fun_f0 ( f0_z0 , rz0 , ixz0 );
	openmp_cal_fun_f0 ( f0_x1 , rx1 , ixx1 );
	openmp_cal_fun_f0 ( f0_y1 , ry1 , ixy1 );
	openmp_cal_fun_f0 ( f0_z1 , rz1 , ixz1 );
	openmp_cal_fun_f1 ( f1_x0 , rx0 , ixx0 );
	openmp_cal_fun_f1 ( f1_y0 , ry0 , ixy0 );
	openmp_cal_fun_f1 ( f1_z0 , rz0 , ixz0 );
	openmp_cal_fun_f1 ( f1_x1 , rx1 , ixx1 );
	openmp_cal_fun_f1 ( f1_y1 , ry1 , ixy1 );
	openmp_cal_fun_f1 ( f1_z1 , rz1 , ixz1 );
	openmp_cal_fun_if1 ( if1_x0 , rx0 , ixx0 );
	openmp_cal_fun_if1 ( if1_y0 , ry0 , ixy0 );
	openmp_cal_fun_if1 ( if1_z0 , rz0 , ixz0 );
	openmp_cal_fun_if1 ( if1_x1 , rx1 , ixx1 );
	openmp_cal_fun_if1 ( if1_y1 , ry1 , ixy1 );
	openmp_cal_fun_if1 ( if1_z1 , rz1 , ixz1 );
	double  Ex1 = 	openmp_get_E1_local_opt ( shE0 , f1_x1 , f0_y1 , f0_z1 , 0 , 0 ) ;
	double  Ey1 = 	openmp_get_E1_local_opt ( shE0 , f1_y1 , f0_z1 , f0_x1 , 1 , 1 ) ;
	double  Ez1 = 	openmp_get_E1_local_opt ( shE0 , f1_z1 , f0_x1 , f0_y1 , 2 , 2 ) ;
	static int  i0 = 0 ;
	double  Resx ;
	double  Resy ;
	double  Resz ;
{
	double  B0y_intzX1Y1Z0Z1 ;
(B0y_intzX1Y1Z0Z1 = 	openmp_get_B1_local_opt ( shB0 , if1_z0 , if1_z1 , f1_x1 , f0_y1 , 2 , 1 ));
	double  B0z_intyX1Y0Z0Y1 ;
(B0z_intyX1Y0Z0Y1 = 	openmp_get_B1_local_opt ( shB0 , if1_y0 , if1_y1 , f0_z0 , f1_x1 , 1 , 2 ));
(Resx = 	(  	(  Charge * Ex1 ) + 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  B0z_intyX1Y0Z0Y1 + 	(  -1.00000000000000000e+00 * B0y_intzX1Y1Z0Z1 ) ) ) ) + 	(  Mass * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}{
	double  B0x_intzX1Y1Z0Z1 ;
(B0x_intzX1Y1Z0Z1 = 	openmp_get_B1_local_opt ( shB0 , if1_z0 , if1_z1 , f0_x1 , f1_y1 , 2 , 0 ));
(Resy = 	(  	(  Charge * Ey1 ) + 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * B0x_intzX1Y1Z0Z1 ) ) + 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}(Resz = 	(  	(  Charge * Ez1 ) + 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ));
(X2 = 	(  	(  2 * xx1 ) - xx0 ));
(Y2 = 	(  	(  2 * xy1 ) - xy0 ));
(Z2 = 	(  	(  2 * xz1 ) - xz0 ));
{
	double  maxerr = 0.00000000000000000e+00 ;
	double   RES  [3];	double   L_RES  [3];	double   JAC  [9];	double   IJAC  [9];	double  RPL00 ;
	double  RPL10 ;
	double  RPL20 ;
{
	long  z ;
	for ((z = 0) ; 	(  z < 32 ) ; (z = 	(  z + 1 )))
	{
{
	int  Midx2 = 	floor ( X2 ) ;
	int  Midy2 = 	floor ( Y2 ) ;
	int  Midz2 = 	floor ( Z2 ) ;
	double  rx2 = 	(  X2 - Midx2 ) ;
	double  ry2 = 	(  Y2 - Midy2 ) ;
	double  rz2 = 	(  Z2 - Midz2 ) ;
	int  ixx2 = 	(  Midx2 - Midx ) ;
	int  ixy2 = 	(  Midy2 - Midy ) ;
	int  ixz2 = 	(  Midz2 - Midz ) ;
	openmp_cal_fun_f0 ( f0_x2 , rx2 , ixx2 );
	openmp_cal_fun_f0 ( f0_y2 , ry2 , ixy2 );
	openmp_cal_fun_f0 ( f0_z2 , rz2 , ixz2 );
	openmp_cal_fun_f1 ( f1_x2 , rx2 , ixx2 );
	openmp_cal_fun_f1 ( f1_y2 , ry2 , ixy2 );
	openmp_cal_fun_f1 ( f1_z2 , rz2 , ixz2 );
	openmp_cal_fun_if1 ( if1_x2 , rx2 , ixx2 );
	openmp_cal_fun_if1 ( if1_y2 , ry2 , ixy2 );
	openmp_cal_fun_if1 ( if1_z2 , rz2 , ixz2 );
	openmp_cal_fun_df0 ( df0_x2 , rx2 , ixx2 );
	openmp_cal_fun_df0 ( df0_y2 , ry2 , ixy2 );
	openmp_cal_fun_df0 ( df0_z2 , rz2 , ixz2 );
	openmp_cal_fun_dif1 ( dif1_x2 , rx2 , ixx2 );
	openmp_cal_fun_dif1 ( dif1_y2 , ry2 , ixy2 );
	openmp_cal_fun_dif1 ( dif1_z2 , rz2 , ixz2 );
}((RES)[0] = 	(  	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) + Resx ));
{
	double  B1z_intxX1Y1Z1X2 ;
(B1z_intxX1Y1Z1X2 = 	openmp_get_B1_local_opt ( shB1 , if1_x1 , if1_x2 , f1_y1 , f0_z1 , 0 , 2 ));
((RES)[1] = 	(  	(  	(  -1.00000000000000000e+00 * 	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1z_intxX1Y1Z1X2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + Resy ));
}{
	double  B1x_intyX2Y1Z1Y2 ;
(B1x_intyX2Y1Z1Y2 = 	openmp_get_B1_local_opt ( shB1 , if1_y1 , if1_y2 , f1_z1 , f0_x2 , 1 , 0 ));
	double  B1y_intxX1Y1Z1X2 ;
(B1y_intxX1Y1Z1X2 = 	openmp_get_B1_local_opt ( shB1 , if1_x1 , if1_x2 , f0_y1 , f1_z1 , 0 , 1 ));
((RES)[2] = 	(  	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  B1y_intxX1Y1Z1X2 + 	(  -1.00000000000000000e+00 * B1x_intyX2Y1Z1Y2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + Resz ));
}(maxerr = 0);
{
	long  i ;
	for ((i = 0) ; 	(  i < 3 ) ; (i = 	(  i + 1 )))
	{
	double  absvalv = 	fabs ( (RES)[i] ) ;
	double  absval = absvalv ;
(maxerr = ((	(  absval > maxerr ))?(absval):(maxerr)));
}}	if (  	(  maxerr < Solve_Err )  ){  
		break;

	}else{
		0;

	 }
((JAC)[0] = 	(  	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_X , 4 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ));
{
	double  B1z_intx_xX1Y1Z1X2 ;
(B1z_intx_xX1Y1Z1X2 = 	openmp_get_E1_local_opt ( shB1 , dif1_x2 , f0_z1 , f1_y1 , 2 , 0 ));
((JAC)[1] = 	(  	(  -1.00000000000000000e+00 * 	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1z_intx_xX1Y1Z1X2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}{
	double  B1x_inty_xX2Y1Z1Y2 ;
{
	double  sum0 = 0.00000000000000000e+00 ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 5 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 5 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  allidx = 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ;
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 0 )] * 	(  (df0_x2)[xyzx] * 	(  	(  (if1_y2)[xyzy] - (if1_y1)[xyzy] ) * (f1_z1)[xyzz] ) ) ) ));
}}}}}}(B1x_inty_xX2Y1Z1Y2 = sum0);
}	double  B1y_intx_xX1Y1Z1X2 ;
(B1y_intx_xX1Y1Z1X2 = 	openmp_get_E1_local_opt ( shB1 , dif1_x2 , f1_z1 , f0_y1 , 1 , 0 ));
((JAC)[2] = 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  B1y_intx_xX1Y1Z1X2 + 	(  -1.00000000000000000e+00 * B1x_inty_xX2Y1Z1Y2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}((JAC)[3] = 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
((JAC)[4] = 	(  	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 4 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ));
{
	double  B1x_inty_yX2Y1Z1Y2 ;
(B1x_inty_yX2Y1Z1Y2 = 	openmp_get_E1_local_opt ( shB1 , dif1_y2 , f0_x2 , f1_z1 , 0 , 1 ));
((JAC)[5] = 	(  	(  -1.00000000000000000e+00 * 	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1x_inty_yX2Y1Z1Y2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}((JAC)[6] = 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
((JAC)[7] = 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
((JAC)[8] = 	(  	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Z , 4 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ));
{
	double  r00 = (JAC)[0] ;
	double  r10 = (JAC)[3] ;
	double  r20 = (JAC)[6] ;
	double  r01 = (JAC)[1] ;
	double  r11 = (JAC)[4] ;
	double  r21 = (JAC)[7] ;
	double  r02 = (JAC)[2] ;
	double  r12 = (JAC)[5] ;
	double  r22 = (JAC)[8] ;
	double  jactmp = 	(  1 / 	(  	(  r02 * 	(  	(  -1.00000000000000000e+00 * 	(  r11 * r20 ) ) + 	(  r10 * r21 ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  r01 * 	(  	(  -1.00000000000000000e+00 * 	(  r12 * r20 ) ) + 	(  r10 * r22 ) ) ) ) + 	(  r00 * 	(  	(  -1.00000000000000000e+00 * 	(  r12 * r21 ) ) + 	(  r11 * r22 ) ) ) ) ) ) ;
((IJAC)[0] = 	(  jactmp * 	(  	(  -1.00000000000000000e+00 * 	(  r12 * r21 ) ) + 	(  r11 * r22 ) ) ));
((IJAC)[3] = 	(  jactmp * 	(  	(  r12 * r20 ) + 	(  -1.00000000000000000e+00 * 	(  r10 * r22 ) ) ) ));
((IJAC)[6] = 	(  jactmp * 	(  	(  -1.00000000000000000e+00 * 	(  r11 * r20 ) ) + 	(  r10 * r21 ) ) ));
((IJAC)[1] = 	(  jactmp * 	(  	(  r02 * r21 ) + 	(  -1.00000000000000000e+00 * 	(  r01 * r22 ) ) ) ));
((IJAC)[4] = 	(  jactmp * 	(  	(  -1.00000000000000000e+00 * 	(  r02 * r20 ) ) + 	(  r00 * r22 ) ) ));
((IJAC)[7] = 	(  jactmp * 	(  	(  r01 * r20 ) + 	(  -1.00000000000000000e+00 * 	(  r00 * r21 ) ) ) ));
((IJAC)[2] = 	(  jactmp * 	(  	(  -1.00000000000000000e+00 * 	(  r02 * r11 ) ) + 	(  r01 * r12 ) ) ));
((IJAC)[5] = 	(  jactmp * 	(  	(  r02 * r10 ) + 	(  -1.00000000000000000e+00 * 	(  r00 * r12 ) ) ) ));
((IJAC)[8] = 	(  jactmp * 	(  	(  -1.00000000000000000e+00 * 	(  r01 * r10 ) ) + 	(  r00 * r11 ) ) ));
}((L_RES)[0] = 	(  	(  (IJAC)[0] * (RES)[0] ) + 	(  	(  (IJAC)[1] * (RES)[1] ) + 	(  (IJAC)[2] * (RES)[2] ) ) ));
((L_RES)[1] = 	(  	(  (IJAC)[3] * (RES)[0] ) + 	(  	(  (IJAC)[4] * (RES)[1] ) + 	(  (IJAC)[5] * (RES)[2] ) ) ));
((L_RES)[2] = 	(  	(  (IJAC)[6] * (RES)[0] ) + 	(  	(  (IJAC)[7] * (RES)[1] ) + 	(  (IJAC)[8] * (RES)[2] ) ) ));
(X2 = 	(  X2 - (L_RES)[0] ));
(Y2 = 	(  Y2 - (L_RES)[1] ));
(Z2 = 	(  Z2 - (L_RES)[2] ));
}}}((local_particle_head)[0] = 	(  X2 + 5.00000000000000000e-01 ));
((local_particle_head)[1] = 	(  Y2 + 5.00000000000000000e-01 ));
((local_particle_head)[2] = 	(  Z2 + 5.00000000000000000e-01 ));
((local_particle_head)[3] = 	(  	(  X2 - xx1 ) / Deltat ));
((local_particle_head)[4] = 	(  	(  Y2 - xy1 ) / Deltat ));
((local_particle_head)[5] = 	(  	(  Z2 - xz1 ) / Deltat ));
{
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 5 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 5 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  allidx = 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ;
	double  Jx ;
	double  Jy ;
	double  Jz ;
(Jx = 	(  grid_geo_x * 	(  	(  (if1_x2)[xyzx] - (if1_x1)[xyzx] ) * 	(  (f0_y1)[xyzy] * (f0_z1)[xyzz] ) ) ));
(Jy = 	(  grid_geo_y * 	(  	(  (if1_y2)[xyzy] - (if1_y1)[xyzy] ) * 	(  (f0_x2)[xyzx] * (f0_z1)[xyzz] ) ) ));
(Jz = 	(  grid_geo_z * 	(  	(  (if1_z2)[xyzz] - (if1_z1)[xyzz] ) * 	(  (f0_x2)[xyzx] * (f0_y2)[xyzy] ) ) ));
((shJ0)[	(  	(  3 * allidx ) + 0 )] = 	(  (shJ0)[	(  	(  3 * allidx ) + 0 )] + 	(  Charge0 * Jx ) ));
((shJ0)[	(  	(  3 * allidx ) + 1 )] = 	(  (shJ0)[	(  	(  3 * allidx ) + 1 )] + 	(  Charge0 * Jy ) ));
((shJ0)[	(  	(  3 * allidx ) + 2 )] = 	(  (shJ0)[	(  	(  3 * allidx ) + 2 )] + 	(  Charge0 * Jz ) ));
}}}}}}}{
	long  stmpg1 ;
	for ((stmpg1 = 0) ; 	(  stmpg1 < 6 ) ; (stmpg1 = 	(  stmpg1 + 1 )))
	{
((particle_head_general)[	(  stmpg1 + 	(  g_inner * 6 ) )] = (local_particle_head)[stmpg1]);
}}}}{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 5 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  total_idx = 	(  3 * 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 	(  3 * 5 ) ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  FoutJ + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  shJ0 + total_idx ))[Gll_P9918]);
}}}}}}}}
	}else{
		0;

	 }
(cur_frame_num = 	(  cur_frame_num + -1 ));
	goto 	* ( (call_stack_pointer)[cur_frame_num] );	beg_prog:
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
(load0 = 1);
	long  new_load = load0 ;
(i_idy = idy);
(particle_head_general = 	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ));

	 call_stack_pointer[cur_frame_num]=&&LAB_TMP1;
(cur_frame_num = 	(  cur_frame_num + 1 ));
	goto core_fun;
	LAB_TMP1:
0;
}}{
	long  allgid ;
	for ((allgid = 0) ; 	(  allgid < numgrid ) ; (allgid = 	(  allgid + 1 )))
	{
(load0 = (xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )]);
	long  new_load = load0 ;
(particle_head_general = 	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ));
(i_idy = idy);

	 call_stack_pointer[cur_frame_num]=&&LAB_TMP2;
(cur_frame_num = 	(  cur_frame_num + 1 ));
	goto core_fun;
	LAB_TMP2:
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )] = new_load);

	}else{
		0;

	 }
}}}
