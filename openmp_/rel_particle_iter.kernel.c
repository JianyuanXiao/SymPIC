#include <omp.h> 
#include <math.h>

#include <math.h>
#include <assert.h>
#include <stdio.h>
#define IDX_OPT_MAX 1
int  openmp_floory (double  x ){
	int  ax = x ;
	if (  	(  ax > x )  ){  
		(ax = 	(  ax + -1 ));

	}else{
		0;

	 }
	return  ax ;}
void  openmp_relng_1st_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const int  IDX_LOCAL_XLEN = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  numgrid = 	(  XLEN * 	(  YLEN * ZLEN ) ) ;
	long  numallgrid = 	(  	(  XLEN + 	(  ovlp + ovlp ) ) * 	(  	(  YLEN + 	(  ovlp + ovlp ) ) * 	(  ZLEN + 	(  ovlp + ovlp ) ) ) ) ;
	long  numgrid_cu = 	(  numgrid * numvec ) ;
	long  grid_base_offset = 	(  idy * 	(  numgrid * 	(  grid_cache_len * 6 ) ) ) ;
	int  cu_load = (cu_xyzw)[	(  4 * idy )] ;
	double   shB0  [375];	double   shB1  [375];	double   shE0  [375];	double   shJ0  [375];{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	if (  load0  ){  
			double  DELTAT = Deltat ;
	double  grid_geo_x = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_y = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_z = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  XO = (xoffset)[idy] ;
	int  Midx = 	openmp_floory ( (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[0] ) ;
	int  Midy = 	openmp_floory ( (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[1] ) ;
	int  Midz = 	openmp_floory ( (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[2] ) ;
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
	long  gMYGEN102 = 0 ;
	for (0 ; 	(  	(  gMYGEN102 + 	(  idx * 1 ) ) < load0 ) ; (gMYGEN102 = 	(  gMYGEN102 + 	(  1 * xlen ) )))
	{
	long  iba_tmp = 	(  	(  idx * 1 ) + gMYGEN102 ) ;
	long  numcp = 1 ;
	double   local_particle_head  [	(  1 * 6 )];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}	double   a_f  [	(  1 * 3 )];0;
{
	long  g ;
	for ((g = 0) ; 	(  g < numcp ) ; (g = 	(  g + 1 )))
	{
	double  vx0 = (	(  local_particle_head + 	(  g * 6 ) ))[3] ;
	double  vy0 = (	(  local_particle_head + 	(  g * 6 ) ))[4] ;
	double  vz0 = (	(  local_particle_head + 	(  g * 6 ) ))[5] ;
	double  xx1 = 	(  (	(  local_particle_head + 	(  g * 6 ) ))[0] - 5.00000000000000000e-01 ) ;
	double  xy1 = 	(  (	(  local_particle_head + 	(  g * 6 ) ))[1] - 5.00000000000000000e-01 ) ;
	double  xz1 = 	(  (	(  local_particle_head + 	(  g * 6 ) ))[2] - 5.00000000000000000e-01 ) ;
	double  xx0 = 	(  xx1 - 	(  Deltat * vx0 ) ) ;
	double  xy0 = 	(  xy1 - 	(  Deltat * vy0 ) ) ;
	double  xz0 = 	(  xz1 - 	(  Deltat * vz0 ) ) ;
	double  Midx0 = 	openmp_floory ( xx0 ) ;
	double  Midy0 = 	openmp_floory ( xy0 ) ;
	double  Midz0 = 	openmp_floory ( xz0 ) ;
	double  Midx1 = 	openmp_floory ( xx1 ) ;
	double  Midy1 = 	openmp_floory ( xy1 ) ;
	double  Midz1 = 	openmp_floory ( xz1 ) ;
	double  rx0 = 	(  xx0 - Midx0 ) ;
	double  ry0 = 	(  xy0 - Midy0 ) ;
	double  rz0 = 	(  xz0 - Midz0 ) ;
	double  rx1 = 	(  xx1 - Midx1 ) ;
	double  ry1 = 	(  xy1 - Midy1 ) ;
	double  rz1 = 	(  xz1 - Midz1 ) ;
	double  X0 = xx0 ;
	double  X1 = xx1 ;
	double  Y0 = xy0 ;
	double  Y1 = xy1 ;
	double  Z0 = xz0 ;
	double  Z1 = xz1 ;
{
	double   f0_x0  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_x0)[i] = 0);
}}	double   f1_x0  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_x0)[i] = 0);
}}	double   if1_x0  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_x0)[i] = 0);
}}	double   f0_y0  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_y0)[i] = 0);
}}	double   f1_y0  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_y0)[i] = 0);
}}	double   if1_y0  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_y0)[i] = 0);
}}	double   f0_z0  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_z0)[i] = 0);
}}	double   f1_z0  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_z0)[i] = 0);
}}	double   if1_z0  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_z0)[i] = 0);
}}	double   f0_x1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_x1)[i] = 0);
}}	double   f1_x1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_x1)[i] = 0);
}}	double   if1_x1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_x1)[i] = 0);
}}	double   f0_y1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_y1)[i] = 0);
}}	double   f1_y1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_y1)[i] = 0);
}}	double   if1_y1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_y1)[i] = 0);
}}	double   f0_z1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_z1)[i] = 0);
}}	double   f1_z1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_z1)[i] = 0);
}}	double   if1_z1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_z1)[i] = 0);
}}	int  ixx0 = ((	(  xx0 >= Midx ))?(1):(0)) ;
	int  ixy0 = ((	(  xy0 >= Midy ))?(1):(0)) ;
	int  ixz0 = ((	(  xz0 >= Midz ))?(1):(0)) ;
	int  ixx1 = ((	(  xx1 >= Midx ))?(1):(0)) ;
	int  ixy1 = ((	(  xy1 >= Midy ))?(1):(0)) ;
	int  ixz1 = ((	(  xz1 >= Midz ))?(1):(0)) ;
((if1_x0)[0] = 1);
((if1_x0)[1] = 1);
((if1_y0)[0] = 1);
((if1_y0)[1] = 1);
((if1_z0)[0] = 1);
((if1_z0)[1] = 1);
((if1_x1)[0] = 1);
((if1_x1)[1] = 1);
((if1_y1)[0] = 1);
((if1_y1)[1] = 1);
((if1_z1)[0] = 1);
((if1_z1)[1] = 1);
((f0_x0)[	(  0 + ixx0 )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) , 2 ) ));
((f1_x0)[	(  0 + ixx0 )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) ));
((if1_x0)[	(  0 + ixx0 )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) , 2 ) ) ));
((f0_x0)[	(  1 + ixx0 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) ) ) ) ));
((f1_x0)[	(  1 + ixx0 )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) ) ));
((if1_x0)[	(  1 + ixx0 )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx0 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx0 ) + 	pow ( rx0 , 2 ) ) ) ) ));
((f0_x0)[	(  2 + ixx0 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx0 ) + 	pow ( rx0 , 2 ) ) ) ));
((f1_x0)[	(  2 + ixx0 )] = 	(  5.00000000000000000e-01 * rx0 ));
((if1_x0)[	(  2 + ixx0 )] = 	(  2.50000000000000000e-01 * 	pow ( rx0 , 2 ) ));
((f0_x0)[	(  3 + ixx0 )] = 	(  2.50000000000000000e-01 * 	pow ( rx0 , 2 ) ));
((f0_y0)[	(  0 + ixy0 )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) , 2 ) ));
((f1_y0)[	(  0 + ixy0 )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) ));
((if1_y0)[	(  0 + ixy0 )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) , 2 ) ) ));
((f0_y0)[	(  1 + ixy0 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) ) ) ) ));
((f1_y0)[	(  1 + ixy0 )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) ) ));
((if1_y0)[	(  1 + ixy0 )] = 	(  	(  2.50000000000000000e-01 * 	pow ( ry0 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry0 ) + 	pow ( ry0 , 2 ) ) ) ) ));
((f0_y0)[	(  2 + ixy0 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry0 ) + 	pow ( ry0 , 2 ) ) ) ));
((f1_y0)[	(  2 + ixy0 )] = 	(  5.00000000000000000e-01 * ry0 ));
((if1_y0)[	(  2 + ixy0 )] = 	(  2.50000000000000000e-01 * 	pow ( ry0 , 2 ) ));
((f0_y0)[	(  3 + ixy0 )] = 	(  2.50000000000000000e-01 * 	pow ( ry0 , 2 ) ));
((f0_z0)[	(  0 + ixz0 )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) , 2 ) ));
((f1_z0)[	(  0 + ixz0 )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) ));
((if1_z0)[	(  0 + ixz0 )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) , 2 ) ) ));
((f0_z0)[	(  1 + ixz0 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) ) ) ) ));
((f1_z0)[	(  1 + ixz0 )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) ) ));
((if1_z0)[	(  1 + ixz0 )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rz0 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz0 ) + 	pow ( rz0 , 2 ) ) ) ) ));
((f0_z0)[	(  2 + ixz0 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz0 ) + 	pow ( rz0 , 2 ) ) ) ));
((f1_z0)[	(  2 + ixz0 )] = 	(  5.00000000000000000e-01 * rz0 ));
((if1_z0)[	(  2 + ixz0 )] = 	(  2.50000000000000000e-01 * 	pow ( rz0 , 2 ) ));
((f0_z0)[	(  3 + ixz0 )] = 	(  2.50000000000000000e-01 * 	pow ( rz0 , 2 ) ));
((f0_x1)[	(  0 + ixx1 )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) , 2 ) ));
((f1_x1)[	(  0 + ixx1 )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) ));
((if1_x1)[	(  0 + ixx1 )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) , 2 ) ) ));
((f0_x1)[	(  1 + ixx1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) ) ) ) ));
((f1_x1)[	(  1 + ixx1 )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) ) ));
((if1_x1)[	(  1 + ixx1 )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx1 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx1 ) + 	pow ( rx1 , 2 ) ) ) ) ));
((f0_x1)[	(  2 + ixx1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx1 ) + 	pow ( rx1 , 2 ) ) ) ));
((f1_x1)[	(  2 + ixx1 )] = 	(  5.00000000000000000e-01 * rx1 ));
((if1_x1)[	(  2 + ixx1 )] = 	(  2.50000000000000000e-01 * 	pow ( rx1 , 2 ) ));
((f0_x1)[	(  3 + ixx1 )] = 	(  2.50000000000000000e-01 * 	pow ( rx1 , 2 ) ));
((f0_y1)[	(  0 + ixy1 )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) , 2 ) ));
((f1_y1)[	(  0 + ixy1 )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) ));
((if1_y1)[	(  0 + ixy1 )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) , 2 ) ) ));
((f0_y1)[	(  1 + ixy1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) ) ) ) ));
((f1_y1)[	(  1 + ixy1 )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) ) ));
((if1_y1)[	(  1 + ixy1 )] = 	(  	(  2.50000000000000000e-01 * 	pow ( ry1 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry1 ) + 	pow ( ry1 , 2 ) ) ) ) ));
((f0_y1)[	(  2 + ixy1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry1 ) + 	pow ( ry1 , 2 ) ) ) ));
((f1_y1)[	(  2 + ixy1 )] = 	(  5.00000000000000000e-01 * ry1 ));
((if1_y1)[	(  2 + ixy1 )] = 	(  2.50000000000000000e-01 * 	pow ( ry1 , 2 ) ));
((f0_y1)[	(  3 + ixy1 )] = 	(  2.50000000000000000e-01 * 	pow ( ry1 , 2 ) ));
((f0_z1)[	(  0 + ixz1 )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) , 2 ) ));
((f1_z1)[	(  0 + ixz1 )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) ));
((if1_z1)[	(  0 + ixz1 )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) , 2 ) ) ));
((f0_z1)[	(  1 + ixz1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) ) ) ) ));
((f1_z1)[	(  1 + ixz1 )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) ) ));
((if1_z1)[	(  1 + ixz1 )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rz1 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz1 ) + 	pow ( rz1 , 2 ) ) ) ) ));
((f0_z1)[	(  2 + ixz1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz1 ) + 	pow ( rz1 , 2 ) ) ) ));
((f1_z1)[	(  2 + ixz1 )] = 	(  5.00000000000000000e-01 * rz1 ));
((if1_z1)[	(  2 + ixz1 )] = 	(  2.50000000000000000e-01 * 	pow ( rz1 , 2 ) ));
((f0_z1)[	(  3 + ixz1 )] = 	(  2.50000000000000000e-01 * 	pow ( rz1 , 2 ) ));
	double  Ex1 ;
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
(sum0 = 	(  sum0 + 	(  (shE0)[	(  	(  allidx * 3 ) + 0 )] * 	(  (f1_x1)[xyzx] * 	(  (f0_y1)[xyzy] * (f0_z1)[xyzz] ) ) ) ));
}}}}}}(Ex1 = sum0);
}	double  Ey1 ;
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
(sum0 = 	(  sum0 + 	(  (shE0)[	(  	(  allidx * 3 ) + 1 )] * 	(  (f1_y1)[xyzy] * 	(  (f0_x1)[xyzx] * (f0_z1)[xyzz] ) ) ) ));
}}}}}}(Ey1 = sum0);
}	double  Ez1 ;
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
(sum0 = 	(  sum0 + 	(  (shE0)[	(  	(  allidx * 3 ) + 2 )] * 	(  (f1_z1)[xyzz] * 	(  (f0_x1)[xyzx] * (f0_y1)[xyzy] ) ) ) ));
}}}}}}(Ez1 = sum0);
}{
	double  B0y_intzX1Y1Z0Z1 ;
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
(sum0 = 	(  sum0 + 	(  (shB0)[	(  	(  allidx * 3 ) + 1 )] * 	(  (f0_y1)[xyzy] * 	(  	(  (if1_z1)[xyzz] - (if1_z0)[xyzz] ) * (f1_x1)[xyzx] ) ) ) ));
}}}}}}(B0y_intzX1Y1Z0Z1 = sum0);
}	double  B0z_intyX1Y0Z0Y1 ;
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
(sum0 = 	(  sum0 + 	(  (shB0)[	(  	(  allidx * 3 ) + 2 )] * 	(  (f0_z0)[xyzz] * 	(  	(  (if1_y1)[xyzy] - (if1_y0)[xyzy] ) * (f1_x1)[xyzx] ) ) ) ));
}}}}}}(B0z_intyX1Y0Z0Y1 = sum0);
}((	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[0] = 	(  	(  Charge * Ex1 ) + 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  B0z_intyX1Y0Z0Y1 + 	(  -1.00000000000000000e+00 * B0y_intzX1Y1Z0Z1 ) ) ) ) + 	(  Mass * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}{
	double  B0x_intzX1Y1Z0Z1 ;
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
(sum0 = 	(  sum0 + 	(  (shB0)[	(  	(  allidx * 3 ) + 0 )] * 	(  (f0_x1)[xyzx] * 	(  	(  (if1_z1)[xyzz] - (if1_z0)[xyzz] ) * (f1_y1)[xyzy] ) ) ) ));
}}}}}}(B0x_intzX1Y1Z0Z1 = sum0);
}((	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[1] = 	(  	(  Charge * Ey1 ) + 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * B0x_intzX1Y1Z0Z1 ) ) + 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}((	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[2] = 	(  	(  Charge * Ez1 ) + 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}}}{
	long  g ;
	for ((g = 0) ; 	(  g < numcp ) ; (g = 	(  g + 1 )))
	{
	double  res_0 = (	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[0] ;
	double  res_1 = (	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[1] ;
	double  res_2 = (	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[2] ;
	double  vx0 = (	(  local_particle_head + 	(  g * 6 ) ))[3] ;
	double  vy0 = (	(  local_particle_head + 	(  g * 6 ) ))[4] ;
	double  vz0 = (	(  local_particle_head + 	(  g * 6 ) ))[5] ;
	double  xx1 = 	(  (	(  local_particle_head + 	(  g * 6 ) ))[0] - 5.00000000000000000e-01 ) ;
	double  xy1 = 	(  (	(  local_particle_head + 	(  g * 6 ) ))[1] - 5.00000000000000000e-01 ) ;
	double  xz1 = 	(  (	(  local_particle_head + 	(  g * 6 ) ))[2] - 5.00000000000000000e-01 ) ;
	double  xx0 = 	(  xx1 - 	(  Deltat * vx0 ) ) ;
	double  xy0 = 	(  xy1 - 	(  Deltat * vy0 ) ) ;
	double  xz0 = 	(  xz1 - 	(  Deltat * vz0 ) ) ;
	double  Midx0 = 	openmp_floory ( xx0 ) ;
	double  Midy0 = 	openmp_floory ( xy0 ) ;
	double  Midz0 = 	openmp_floory ( xz0 ) ;
	double  Midx1 = 	openmp_floory ( xx1 ) ;
	double  Midy1 = 	openmp_floory ( xy1 ) ;
	double  Midz1 = 	openmp_floory ( xz1 ) ;
	double  rx0 = 	(  xx0 - Midx0 ) ;
	double  ry0 = 	(  xy0 - Midy0 ) ;
	double  rz0 = 	(  xz0 - Midz0 ) ;
	double  rx1 = 	(  xx1 - Midx1 ) ;
	double  ry1 = 	(  xy1 - Midy1 ) ;
	double  rz1 = 	(  xz1 - Midz1 ) ;
	double  X0 = xx0 ;
	double  X1 = xx1 ;
	double  X2 = 	(  	(  2 * xx1 ) - xx0 ) ;
	double  Y0 = xy0 ;
	double  Y1 = xy1 ;
	double  Y2 = 	(  	(  2 * xy1 ) - xy0 ) ;
	double  Z0 = xz0 ;
	double  Z1 = xz1 ;
	double  Z2 = 	(  	(  2 * xz1 ) - xz0 ) ;
	double   f0_x1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_x1)[i] = 0);
}}	double   f1_x1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_x1)[i] = 0);
}}	double   if1_x1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_x1)[i] = 0);
}}	double   df0_x1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((df0_x1)[i] = 0);
}}	double   dif1_x1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((dif1_x1)[i] = 0);
}}	double   f0_y1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_y1)[i] = 0);
}}	double   f1_y1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_y1)[i] = 0);
}}	double   if1_y1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_y1)[i] = 0);
}}	double   df0_y1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((df0_y1)[i] = 0);
}}	double   dif1_y1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((dif1_y1)[i] = 0);
}}	double   f0_z1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_z1)[i] = 0);
}}	double   f1_z1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_z1)[i] = 0);
}}	double   if1_z1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_z1)[i] = 0);
}}	double   df0_z1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((df0_z1)[i] = 0);
}}	double   dif1_z1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((dif1_z1)[i] = 0);
}}	double   f0_x2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_x2)[i] = 0);
}}	double   f1_x2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_x2)[i] = 0);
}}	double   if1_x2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_x2)[i] = 0);
}}	double   df0_x2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((df0_x2)[i] = 0);
}}	double   dif1_x2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((dif1_x2)[i] = 0);
}}	double   f0_y2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_y2)[i] = 0);
}}	double   f1_y2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_y2)[i] = 0);
}}	double   if1_y2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_y2)[i] = 0);
}}	double   df0_y2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((df0_y2)[i] = 0);
}}	double   dif1_y2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((dif1_y2)[i] = 0);
}}	double   f0_z2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_z2)[i] = 0);
}}	double   f1_z2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_z2)[i] = 0);
}}	double   if1_z2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_z2)[i] = 0);
}}	double   df0_z2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((df0_z2)[i] = 0);
}}	double   dif1_z2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((dif1_z2)[i] = 0);
}}	int  ixx0 = ((	(  xx0 >= Midx ))?(1):(0)) ;
	int  ixy0 = ((	(  xy0 >= Midy ))?(1):(0)) ;
	int  ixz0 = ((	(  xz0 >= Midz ))?(1):(0)) ;
	int  ixx1 = ((	(  xx1 >= Midx ))?(1):(0)) ;
	int  ixy1 = ((	(  xy1 >= Midy ))?(1):(0)) ;
	int  ixz1 = ((	(  xz1 >= Midz ))?(1):(0)) ;
((if1_x1)[0] = 1);
((if1_x1)[1] = 1);
((if1_y1)[0] = 1);
((if1_y1)[1] = 1);
((if1_z1)[0] = 1);
((if1_z1)[1] = 1);
((f0_x1)[	(  0 + ixx1 )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) , 2 ) ));
((f1_x1)[	(  0 + ixx1 )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) ));
((if1_x1)[	(  0 + ixx1 )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) , 2 ) ) ));
((f0_x1)[	(  1 + ixx1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) ) ) ) ));
((f1_x1)[	(  1 + ixx1 )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) ) ));
((if1_x1)[	(  1 + ixx1 )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx1 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx1 ) + 	pow ( rx1 , 2 ) ) ) ) ));
((f0_x1)[	(  2 + ixx1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx1 ) + 	pow ( rx1 , 2 ) ) ) ));
((f1_x1)[	(  2 + ixx1 )] = 	(  5.00000000000000000e-01 * rx1 ));
((if1_x1)[	(  2 + ixx1 )] = 	(  2.50000000000000000e-01 * 	pow ( rx1 , 2 ) ));
((f0_x1)[	(  3 + ixx1 )] = 	(  2.50000000000000000e-01 * 	pow ( rx1 , 2 ) ));
((f0_y1)[	(  0 + ixy1 )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) , 2 ) ));
((f1_y1)[	(  0 + ixy1 )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) ));
((if1_y1)[	(  0 + ixy1 )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) , 2 ) ) ));
((f0_y1)[	(  1 + ixy1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) ) ) ) ));
((f1_y1)[	(  1 + ixy1 )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) ) ));
((if1_y1)[	(  1 + ixy1 )] = 	(  	(  2.50000000000000000e-01 * 	pow ( ry1 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry1 ) + 	pow ( ry1 , 2 ) ) ) ) ));
((f0_y1)[	(  2 + ixy1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry1 ) + 	pow ( ry1 , 2 ) ) ) ));
((f1_y1)[	(  2 + ixy1 )] = 	(  5.00000000000000000e-01 * ry1 ));
((if1_y1)[	(  2 + ixy1 )] = 	(  2.50000000000000000e-01 * 	pow ( ry1 , 2 ) ));
((f0_y1)[	(  3 + ixy1 )] = 	(  2.50000000000000000e-01 * 	pow ( ry1 , 2 ) ));
((f0_z1)[	(  0 + ixz1 )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) , 2 ) ));
((f1_z1)[	(  0 + ixz1 )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) ));
((if1_z1)[	(  0 + ixz1 )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) , 2 ) ) ));
((f0_z1)[	(  1 + ixz1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) ) ) ) ));
((f1_z1)[	(  1 + ixz1 )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) ) ));
((if1_z1)[	(  1 + ixz1 )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rz1 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz1 ) + 	pow ( rz1 , 2 ) ) ) ) ));
((f0_z1)[	(  2 + ixz1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz1 ) + 	pow ( rz1 , 2 ) ) ) ));
((f1_z1)[	(  2 + ixz1 )] = 	(  5.00000000000000000e-01 * rz1 ));
((if1_z1)[	(  2 + ixz1 )] = 	(  2.50000000000000000e-01 * 	pow ( rz1 , 2 ) ));
((f0_z1)[	(  3 + ixz1 )] = 	(  2.50000000000000000e-01 * 	pow ( rz1 , 2 ) ));
{
	double  maxerr = 0.00000000000000000e+00 ;
	double  RPL00 ;
	double  RPL10 ;
	double  RPL20 ;
	double   RES  [3];	double   L_RES  [3];	double   JAC  [9];	double   IJAC  [9];{
	long  z ;
	for ((z = 0) ; 	(  z < 32 ) ; (z = 	(  z + 1 )))
	{
{
	double  xx2 = X2 ;
	double  xy2 = Y2 ;
	double  xz2 = Z2 ;
	int  Midx2 = 	openmp_floory ( xx2 ) ;
	int  Midy2 = 	openmp_floory ( xy2 ) ;
	int  Midz2 = 	openmp_floory ( xz2 ) ;
	double  rx2 = 	(  xx2 - Midx2 ) ;
	double  ry2 = 	(  xy2 - Midy2 ) ;
	double  rz2 = 	(  xz2 - Midz2 ) ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_x2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_x2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_x2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((df0_x2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((dif1_x2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_y2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_y2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_y2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((df0_y2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((dif1_y2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_z2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_z2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_z2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((df0_z2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((dif1_z2)[i] = 0);
}}((if1_x2)[0] = 1);
((if1_x2)[1] = 1);
((if1_y2)[0] = 1);
((if1_y2)[1] = 1);
((if1_z2)[0] = 1);
((if1_z2)[1] = 1);
	double  ixx2 = ((	(  xx2 >= Midx ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  ixy2 = ((	(  xy2 >= Midy ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  ixz2 = ((	(  xz2 >= Midz ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  f0_0x2_nv_bac ;
(f0_0x2_nv_bac = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx2 ) ) , 2 ) ));
	double  df0_0x2_nv_bac ;
(df0_0x2_nv_bac = 	(  -5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx2 ) ) ));
	double  dif1_0x2_nv_bac ;
(dif1_0x2_nv_bac = -5.00000000000000000e-01);
	double  f1_0x2_nv_bac ;
(f1_0x2_nv_bac = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx2 ) ) ));
	double  if1_0x2_nv_bac ;
(if1_0x2_nv_bac = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx2 ) ) , 2 ) ) ));
	double  f0_1x2_nv_bac ;
(f0_1x2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx2 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx2 ) ) ) ) ) ));
	double  df0_1x2_nv_bac ;
(df0_1x2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx2 ) ) ) ) ));
	double  dif1_1x2_nv_bac ;
(dif1_1x2_nv_bac = 0.00000000000000000e+00);
	double  f1_1x2_nv_bac ;
(f1_1x2_nv_bac = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx2 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx2 ) ) ) ));
	double  if1_1x2_nv_bac ;
(if1_1x2_nv_bac = 	(  	(  2.50000000000000000e-01 * 	pow ( rx2 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx2 ) + 	pow ( rx2 , 2 ) ) ) ) ));
	double  f0_2x2_nv_bac ;
(f0_2x2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx2 ) + 	pow ( rx2 , 2 ) ) ) ));
	double  df0_2x2_nv_bac ;
(df0_2x2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  -2.00000000000000000e+00 + 	(  2.00000000000000000e+00 * rx2 ) ) ));
	double  dif1_2x2_nv_bac ;
(dif1_2x2_nv_bac = 5.00000000000000000e-01);
	double  f1_2x2_nv_bac ;
(f1_2x2_nv_bac = 	(  5.00000000000000000e-01 * rx2 ));
	double  if1_2x2_nv_bac ;
(if1_2x2_nv_bac = 	(  2.50000000000000000e-01 * 	pow ( rx2 , 2 ) ));
	double  f0_3x2_nv_bac ;
(f0_3x2_nv_bac = 	(  2.50000000000000000e-01 * 	pow ( rx2 , 2 ) ));
	double  df0_3x2_nv_bac ;
(df0_3x2_nv_bac = 	(  5.00000000000000000e-01 * rx2 ));
	double  f0_0y2_nv_bac ;
(f0_0y2_nv_bac = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry2 ) ) , 2 ) ));
	double  df0_0y2_nv_bac ;
(df0_0y2_nv_bac = 	(  -5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry2 ) ) ));
	double  dif1_0y2_nv_bac ;
(dif1_0y2_nv_bac = -5.00000000000000000e-01);
	double  f1_0y2_nv_bac ;
(f1_0y2_nv_bac = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry2 ) ) ));
	double  if1_0y2_nv_bac ;
(if1_0y2_nv_bac = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry2 ) ) , 2 ) ) ));
	double  f0_1y2_nv_bac ;
(f0_1y2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry2 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry2 ) ) ) ) ) ));
	double  df0_1y2_nv_bac ;
(df0_1y2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry2 ) ) ) ) ));
	double  dif1_1y2_nv_bac ;
(dif1_1y2_nv_bac = 0.00000000000000000e+00);
	double  f1_1y2_nv_bac ;
(f1_1y2_nv_bac = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry2 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry2 ) ) ) ));
	double  if1_1y2_nv_bac ;
(if1_1y2_nv_bac = 	(  	(  2.50000000000000000e-01 * 	pow ( ry2 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry2 ) + 	pow ( ry2 , 2 ) ) ) ) ));
	double  f0_2y2_nv_bac ;
(f0_2y2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry2 ) + 	pow ( ry2 , 2 ) ) ) ));
	double  df0_2y2_nv_bac ;
(df0_2y2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  -2.00000000000000000e+00 + 	(  2.00000000000000000e+00 * ry2 ) ) ));
	double  dif1_2y2_nv_bac ;
(dif1_2y2_nv_bac = 5.00000000000000000e-01);
	double  f1_2y2_nv_bac ;
(f1_2y2_nv_bac = 	(  5.00000000000000000e-01 * ry2 ));
	double  if1_2y2_nv_bac ;
(if1_2y2_nv_bac = 	(  2.50000000000000000e-01 * 	pow ( ry2 , 2 ) ));
	double  f0_3y2_nv_bac ;
(f0_3y2_nv_bac = 	(  2.50000000000000000e-01 * 	pow ( ry2 , 2 ) ));
	double  df0_3y2_nv_bac ;
(df0_3y2_nv_bac = 	(  5.00000000000000000e-01 * ry2 ));
	double  f0_0z2_nv_bac ;
(f0_0z2_nv_bac = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz2 ) ) , 2 ) ));
	double  df0_0z2_nv_bac ;
(df0_0z2_nv_bac = 	(  -5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz2 ) ) ));
	double  dif1_0z2_nv_bac ;
(dif1_0z2_nv_bac = -5.00000000000000000e-01);
	double  f1_0z2_nv_bac ;
(f1_0z2_nv_bac = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz2 ) ) ));
	double  if1_0z2_nv_bac ;
(if1_0z2_nv_bac = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz2 ) ) , 2 ) ) ));
	double  f0_1z2_nv_bac ;
(f0_1z2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz2 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz2 ) ) ) ) ) ));
	double  df0_1z2_nv_bac ;
(df0_1z2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz2 ) ) ) ) ));
	double  dif1_1z2_nv_bac ;
(dif1_1z2_nv_bac = 0.00000000000000000e+00);
	double  f1_1z2_nv_bac ;
(f1_1z2_nv_bac = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz2 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz2 ) ) ) ));
	double  if1_1z2_nv_bac ;
(if1_1z2_nv_bac = 	(  	(  2.50000000000000000e-01 * 	pow ( rz2 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz2 ) + 	pow ( rz2 , 2 ) ) ) ) ));
	double  f0_2z2_nv_bac ;
(f0_2z2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz2 ) + 	pow ( rz2 , 2 ) ) ) ));
	double  df0_2z2_nv_bac ;
(df0_2z2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  -2.00000000000000000e+00 + 	(  2.00000000000000000e+00 * rz2 ) ) ));
	double  dif1_2z2_nv_bac ;
(dif1_2z2_nv_bac = 5.00000000000000000e-01);
	double  f1_2z2_nv_bac ;
(f1_2z2_nv_bac = 	(  5.00000000000000000e-01 * rz2 ));
	double  if1_2z2_nv_bac ;
(if1_2z2_nv_bac = 	(  2.50000000000000000e-01 * 	pow ( rz2 , 2 ) ));
	double  f0_3z2_nv_bac ;
(f0_3z2_nv_bac = 	(  2.50000000000000000e-01 * 	pow ( rz2 , 2 ) ));
	double  df0_3z2_nv_bac ;
(df0_3z2_nv_bac = 	(  5.00000000000000000e-01 * rz2 ));
((f0_x2)[0] = 	(  	(  ixx2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * f0_0x2_nv_bac ) ));
((df0_x2)[0] = 	(  	(  ixx2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * df0_0x2_nv_bac ) ));
((dif1_x2)[0] = 	(  	(  ixx2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * dif1_0x2_nv_bac ) ));
((f1_x2)[0] = 	(  	(  ixx2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * f1_0x2_nv_bac ) ));
((if1_x2)[0] = 	(  	(  ixx2 * 1.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * if1_0x2_nv_bac ) ));
((f0_x2)[1] = 	(  	(  ixx2 * f0_0x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * f0_1x2_nv_bac ) ));
((df0_x2)[1] = 	(  	(  ixx2 * df0_0x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * df0_1x2_nv_bac ) ));
((dif1_x2)[1] = 	(  	(  ixx2 * dif1_0x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * dif1_1x2_nv_bac ) ));
((f1_x2)[1] = 	(  	(  ixx2 * f1_0x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * f1_1x2_nv_bac ) ));
((if1_x2)[1] = 	(  	(  ixx2 * if1_0x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * if1_1x2_nv_bac ) ));
((f0_x2)[2] = 	(  	(  ixx2 * f0_1x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * f0_2x2_nv_bac ) ));
((df0_x2)[2] = 	(  	(  ixx2 * df0_1x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * df0_2x2_nv_bac ) ));
((dif1_x2)[2] = 	(  	(  ixx2 * dif1_1x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * dif1_2x2_nv_bac ) ));
((f1_x2)[2] = 	(  	(  ixx2 * f1_1x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * f1_2x2_nv_bac ) ));
((if1_x2)[2] = 	(  	(  ixx2 * if1_1x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * if1_2x2_nv_bac ) ));
((f0_x2)[3] = 	(  	(  ixx2 * f0_2x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * f0_3x2_nv_bac ) ));
((df0_x2)[3] = 	(  	(  ixx2 * df0_2x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * df0_3x2_nv_bac ) ));
((dif1_x2)[3] = 	(  	(  ixx2 * dif1_2x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * 0 ) ));
((f1_x2)[3] = 	(  	(  ixx2 * f1_2x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * 0 ) ));
((if1_x2)[3] = 	(  	(  ixx2 * if1_2x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * 0 ) ));
((f0_x2)[4] = 	(  	(  ixx2 * f0_3x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * 0 ) ));
((df0_x2)[4] = 	(  	(  ixx2 * df0_3x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * 0 ) ));
((f0_y2)[0] = 	(  	(  ixy2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * f0_0y2_nv_bac ) ));
((df0_y2)[0] = 	(  	(  ixy2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * df0_0y2_nv_bac ) ));
((dif1_y2)[0] = 	(  	(  ixy2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * dif1_0y2_nv_bac ) ));
((f1_y2)[0] = 	(  	(  ixy2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * f1_0y2_nv_bac ) ));
((if1_y2)[0] = 	(  	(  ixy2 * 1.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * if1_0y2_nv_bac ) ));
((f0_y2)[1] = 	(  	(  ixy2 * f0_0y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * f0_1y2_nv_bac ) ));
((df0_y2)[1] = 	(  	(  ixy2 * df0_0y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * df0_1y2_nv_bac ) ));
((dif1_y2)[1] = 	(  	(  ixy2 * dif1_0y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * dif1_1y2_nv_bac ) ));
((f1_y2)[1] = 	(  	(  ixy2 * f1_0y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * f1_1y2_nv_bac ) ));
((if1_y2)[1] = 	(  	(  ixy2 * if1_0y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * if1_1y2_nv_bac ) ));
((f0_y2)[2] = 	(  	(  ixy2 * f0_1y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * f0_2y2_nv_bac ) ));
((df0_y2)[2] = 	(  	(  ixy2 * df0_1y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * df0_2y2_nv_bac ) ));
((dif1_y2)[2] = 	(  	(  ixy2 * dif1_1y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * dif1_2y2_nv_bac ) ));
((f1_y2)[2] = 	(  	(  ixy2 * f1_1y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * f1_2y2_nv_bac ) ));
((if1_y2)[2] = 	(  	(  ixy2 * if1_1y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * if1_2y2_nv_bac ) ));
((f0_y2)[3] = 	(  	(  ixy2 * f0_2y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * f0_3y2_nv_bac ) ));
((df0_y2)[3] = 	(  	(  ixy2 * df0_2y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * df0_3y2_nv_bac ) ));
((dif1_y2)[3] = 	(  	(  ixy2 * dif1_2y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * 0 ) ));
((f1_y2)[3] = 	(  	(  ixy2 * f1_2y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * 0 ) ));
((if1_y2)[3] = 	(  	(  ixy2 * if1_2y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * 0 ) ));
((f0_y2)[4] = 	(  	(  ixy2 * f0_3y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * 0 ) ));
((df0_y2)[4] = 	(  	(  ixy2 * df0_3y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * 0 ) ));
((f0_z2)[0] = 	(  	(  ixz2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * f0_0z2_nv_bac ) ));
((df0_z2)[0] = 	(  	(  ixz2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * df0_0z2_nv_bac ) ));
((dif1_z2)[0] = 	(  	(  ixz2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * dif1_0z2_nv_bac ) ));
((f1_z2)[0] = 	(  	(  ixz2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * f1_0z2_nv_bac ) ));
((if1_z2)[0] = 	(  	(  ixz2 * 1.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * if1_0z2_nv_bac ) ));
((f0_z2)[1] = 	(  	(  ixz2 * f0_0z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * f0_1z2_nv_bac ) ));
((df0_z2)[1] = 	(  	(  ixz2 * df0_0z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * df0_1z2_nv_bac ) ));
((dif1_z2)[1] = 	(  	(  ixz2 * dif1_0z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * dif1_1z2_nv_bac ) ));
((f1_z2)[1] = 	(  	(  ixz2 * f1_0z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * f1_1z2_nv_bac ) ));
((if1_z2)[1] = 	(  	(  ixz2 * if1_0z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * if1_1z2_nv_bac ) ));
((f0_z2)[2] = 	(  	(  ixz2 * f0_1z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * f0_2z2_nv_bac ) ));
((df0_z2)[2] = 	(  	(  ixz2 * df0_1z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * df0_2z2_nv_bac ) ));
((dif1_z2)[2] = 	(  	(  ixz2 * dif1_1z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * dif1_2z2_nv_bac ) ));
((f1_z2)[2] = 	(  	(  ixz2 * f1_1z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * f1_2z2_nv_bac ) ));
((if1_z2)[2] = 	(  	(  ixz2 * if1_1z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * if1_2z2_nv_bac ) ));
((f0_z2)[3] = 	(  	(  ixz2 * f0_2z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * f0_3z2_nv_bac ) ));
((df0_z2)[3] = 	(  	(  ixz2 * df0_2z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * df0_3z2_nv_bac ) ));
((dif1_z2)[3] = 	(  	(  ixz2 * dif1_2z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * 0 ) ));
((f1_z2)[3] = 	(  	(  ixz2 * f1_2z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * 0 ) ));
((if1_z2)[3] = 	(  	(  ixz2 * if1_2z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * 0 ) ));
((f0_z2)[4] = 	(  	(  ixz2 * f0_3z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * 0 ) ));
((df0_z2)[4] = 	(  	(  ixz2 * df0_3z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * 0 ) ));
}((RES)[0] = 	(  	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) + res_0 ));
{
	double  B1z_intxX1Y1Z1X2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 2 )] * 	(  (f0_z1)[xyzz] * 	(  	(  (if1_x2)[xyzx] - (if1_x1)[xyzx] ) * (f1_y1)[xyzy] ) ) ) ));
}}}}}}(B1z_intxX1Y1Z1X2 = sum0);
}((RES)[1] = 	(  	(  	(  -1.00000000000000000e+00 * 	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1z_intxX1Y1Z1X2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + res_1 ));
}{
	double  B1x_intyX2Y1Z1Y2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 0 )] * 	(  (f0_x2)[xyzx] * 	(  	(  (if1_y2)[xyzy] - (if1_y1)[xyzy] ) * (f1_z1)[xyzz] ) ) ) ));
}}}}}}(B1x_intyX2Y1Z1Y2 = sum0);
}	double  B1y_intxX1Y1Z1X2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 1 )] * 	(  (f0_y1)[xyzy] * 	(  	(  (if1_x2)[xyzx] - (if1_x1)[xyzx] ) * (f1_z1)[xyzz] ) ) ) ));
}}}}}}(B1y_intxX1Y1Z1X2 = sum0);
}((RES)[2] = 	(  	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  B1y_intxX1Y1Z1X2 + 	(  -1.00000000000000000e+00 * B1x_intyX2Y1Z1Y2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + res_2 ));
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 2 )] * 	(  (f0_z1)[xyzz] * 	(  (dif1_x2)[xyzx] * (f1_y1)[xyzy] ) ) ) ));
}}}}}}(B1z_intx_xX1Y1Z1X2 = sum0);
}((JAC)[1] = 	(  	(  -1.00000000000000000e+00 * 	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1z_intx_xX1Y1Z1X2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 1 )] * 	(  (f0_y1)[xyzy] * 	(  (dif1_x2)[xyzx] * (f1_z1)[xyzz] ) ) ) ));
}}}}}}(B1y_intx_xX1Y1Z1X2 = sum0);
}((JAC)[2] = 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  B1y_intx_xX1Y1Z1X2 + 	(  -1.00000000000000000e+00 * B1x_inty_xX2Y1Z1Y2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}((JAC)[3] = 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
((JAC)[4] = 	(  	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 4 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ));
{
	double  B1x_inty_yX2Y1Z1Y2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 0 )] * 	(  (f0_x2)[xyzx] * 	(  (dif1_y2)[xyzy] * (f1_z1)[xyzz] ) ) ) ));
}}}}}}(B1x_inty_yX2Y1Z1Y2 = sum0);
}((JAC)[5] = 	(  	(  -1.00000000000000000e+00 * 	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1x_inty_yX2Y1Z1Y2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
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
}}}((	(  local_particle_head + 	(  g * 6 ) ))[0] = 	(  X2 + 5.00000000000000000e-01 ));
((	(  local_particle_head + 	(  g * 6 ) ))[1] = 	(  Y2 + 5.00000000000000000e-01 ));
((	(  local_particle_head + 	(  g * 6 ) ))[2] = 	(  Z2 + 5.00000000000000000e-01 ));
((	(  local_particle_head + 	(  g * 6 ) ))[3] = 	(  	(  X2 - xx1 ) / Deltat ));
((	(  local_particle_head + 	(  g * 6 ) ))[4] = 	(  	(  Y2 - xy1 ) / Deltat ));
((	(  local_particle_head + 	(  g * 6 ) ))[5] = 	(  	(  Z2 - xz1 ) / Deltat ));
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
}}}}}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}0;
}}{
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
}}{
	long  allgid ;
	for ((allgid = 0) ; 	(  allgid < numgrid ) ; (allgid = 	(  allgid + 1 )))
	{
	int  load0 = (xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )] ;
	int  new_load = load0 ;
	if (  load0  ){  
			double  DELTAT = Deltat ;
	double  grid_geo_x = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_y = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_z = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  XO = (xoffset)[idy] ;
	int  Midx = 	openmp_floory ( (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[0] ) ;
	int  Midy = 	openmp_floory ( (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[1] ) ;
	int  Midz = 	openmp_floory ( (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[2] ) ;
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
	long  gMYGEN115 = 0 ;
	for (0 ; 	(  	(  gMYGEN115 + 	(  idx * 1 ) ) < load0 ) ; (gMYGEN115 = 	(  gMYGEN115 + 	(  1 * xlen ) )))
	{
	long  iba_tmp = 	(  	(  idx * 1 ) + gMYGEN115 ) ;
	long  numcp = 1 ;
	double   local_particle_head  [	(  1 * 6 )];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}	double   a_f  [	(  1 * 3 )];0;
{
	long  g ;
	for ((g = 0) ; 	(  g < numcp ) ; (g = 	(  g + 1 )))
	{
	double  vx0 = (	(  local_particle_head + 	(  g * 6 ) ))[3] ;
	double  vy0 = (	(  local_particle_head + 	(  g * 6 ) ))[4] ;
	double  vz0 = (	(  local_particle_head + 	(  g * 6 ) ))[5] ;
	double  xx1 = 	(  (	(  local_particle_head + 	(  g * 6 ) ))[0] - 5.00000000000000000e-01 ) ;
	double  xy1 = 	(  (	(  local_particle_head + 	(  g * 6 ) ))[1] - 5.00000000000000000e-01 ) ;
	double  xz1 = 	(  (	(  local_particle_head + 	(  g * 6 ) ))[2] - 5.00000000000000000e-01 ) ;
	double  xx0 = 	(  xx1 - 	(  Deltat * vx0 ) ) ;
	double  xy0 = 	(  xy1 - 	(  Deltat * vy0 ) ) ;
	double  xz0 = 	(  xz1 - 	(  Deltat * vz0 ) ) ;
	double  Midx0 = 	openmp_floory ( xx0 ) ;
	double  Midy0 = 	openmp_floory ( xy0 ) ;
	double  Midz0 = 	openmp_floory ( xz0 ) ;
	double  Midx1 = 	openmp_floory ( xx1 ) ;
	double  Midy1 = 	openmp_floory ( xy1 ) ;
	double  Midz1 = 	openmp_floory ( xz1 ) ;
	double  rx0 = 	(  xx0 - Midx0 ) ;
	double  ry0 = 	(  xy0 - Midy0 ) ;
	double  rz0 = 	(  xz0 - Midz0 ) ;
	double  rx1 = 	(  xx1 - Midx1 ) ;
	double  ry1 = 	(  xy1 - Midy1 ) ;
	double  rz1 = 	(  xz1 - Midz1 ) ;
	double  X0 = xx0 ;
	double  X1 = xx1 ;
	double  Y0 = xy0 ;
	double  Y1 = xy1 ;
	double  Z0 = xz0 ;
	double  Z1 = xz1 ;
{
	double   f0_x0  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_x0)[i] = 0);
}}	double   f1_x0  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_x0)[i] = 0);
}}	double   if1_x0  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_x0)[i] = 0);
}}	double   f0_y0  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_y0)[i] = 0);
}}	double   f1_y0  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_y0)[i] = 0);
}}	double   if1_y0  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_y0)[i] = 0);
}}	double   f0_z0  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_z0)[i] = 0);
}}	double   f1_z0  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_z0)[i] = 0);
}}	double   if1_z0  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_z0)[i] = 0);
}}	double   f0_x1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_x1)[i] = 0);
}}	double   f1_x1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_x1)[i] = 0);
}}	double   if1_x1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_x1)[i] = 0);
}}	double   f0_y1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_y1)[i] = 0);
}}	double   f1_y1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_y1)[i] = 0);
}}	double   if1_y1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_y1)[i] = 0);
}}	double   f0_z1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_z1)[i] = 0);
}}	double   f1_z1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_z1)[i] = 0);
}}	double   if1_z1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_z1)[i] = 0);
}}	int  ixx0 = ((	(  xx0 >= Midx ))?(1):(0)) ;
	int  ixy0 = ((	(  xy0 >= Midy ))?(1):(0)) ;
	int  ixz0 = ((	(  xz0 >= Midz ))?(1):(0)) ;
	int  ixx1 = ((	(  xx1 >= Midx ))?(1):(0)) ;
	int  ixy1 = ((	(  xy1 >= Midy ))?(1):(0)) ;
	int  ixz1 = ((	(  xz1 >= Midz ))?(1):(0)) ;
((if1_x0)[0] = 1);
((if1_x0)[1] = 1);
((if1_y0)[0] = 1);
((if1_y0)[1] = 1);
((if1_z0)[0] = 1);
((if1_z0)[1] = 1);
((if1_x1)[0] = 1);
((if1_x1)[1] = 1);
((if1_y1)[0] = 1);
((if1_y1)[1] = 1);
((if1_z1)[0] = 1);
((if1_z1)[1] = 1);
((f0_x0)[	(  0 + ixx0 )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) , 2 ) ));
((f1_x0)[	(  0 + ixx0 )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) ));
((if1_x0)[	(  0 + ixx0 )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) , 2 ) ) ));
((f0_x0)[	(  1 + ixx0 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) ) ) ) ));
((f1_x0)[	(  1 + ixx0 )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) ) ));
((if1_x0)[	(  1 + ixx0 )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx0 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx0 ) + 	pow ( rx0 , 2 ) ) ) ) ));
((f0_x0)[	(  2 + ixx0 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx0 ) + 	pow ( rx0 , 2 ) ) ) ));
((f1_x0)[	(  2 + ixx0 )] = 	(  5.00000000000000000e-01 * rx0 ));
((if1_x0)[	(  2 + ixx0 )] = 	(  2.50000000000000000e-01 * 	pow ( rx0 , 2 ) ));
((f0_x0)[	(  3 + ixx0 )] = 	(  2.50000000000000000e-01 * 	pow ( rx0 , 2 ) ));
((f0_y0)[	(  0 + ixy0 )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) , 2 ) ));
((f1_y0)[	(  0 + ixy0 )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) ));
((if1_y0)[	(  0 + ixy0 )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) , 2 ) ) ));
((f0_y0)[	(  1 + ixy0 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) ) ) ) ));
((f1_y0)[	(  1 + ixy0 )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) ) ));
((if1_y0)[	(  1 + ixy0 )] = 	(  	(  2.50000000000000000e-01 * 	pow ( ry0 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry0 ) + 	pow ( ry0 , 2 ) ) ) ) ));
((f0_y0)[	(  2 + ixy0 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry0 ) + 	pow ( ry0 , 2 ) ) ) ));
((f1_y0)[	(  2 + ixy0 )] = 	(  5.00000000000000000e-01 * ry0 ));
((if1_y0)[	(  2 + ixy0 )] = 	(  2.50000000000000000e-01 * 	pow ( ry0 , 2 ) ));
((f0_y0)[	(  3 + ixy0 )] = 	(  2.50000000000000000e-01 * 	pow ( ry0 , 2 ) ));
((f0_z0)[	(  0 + ixz0 )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) , 2 ) ));
((f1_z0)[	(  0 + ixz0 )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) ));
((if1_z0)[	(  0 + ixz0 )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) , 2 ) ) ));
((f0_z0)[	(  1 + ixz0 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) ) ) ) ));
((f1_z0)[	(  1 + ixz0 )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) ) ));
((if1_z0)[	(  1 + ixz0 )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rz0 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz0 ) + 	pow ( rz0 , 2 ) ) ) ) ));
((f0_z0)[	(  2 + ixz0 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz0 ) + 	pow ( rz0 , 2 ) ) ) ));
((f1_z0)[	(  2 + ixz0 )] = 	(  5.00000000000000000e-01 * rz0 ));
((if1_z0)[	(  2 + ixz0 )] = 	(  2.50000000000000000e-01 * 	pow ( rz0 , 2 ) ));
((f0_z0)[	(  3 + ixz0 )] = 	(  2.50000000000000000e-01 * 	pow ( rz0 , 2 ) ));
((f0_x1)[	(  0 + ixx1 )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) , 2 ) ));
((f1_x1)[	(  0 + ixx1 )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) ));
((if1_x1)[	(  0 + ixx1 )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) , 2 ) ) ));
((f0_x1)[	(  1 + ixx1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) ) ) ) ));
((f1_x1)[	(  1 + ixx1 )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) ) ));
((if1_x1)[	(  1 + ixx1 )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx1 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx1 ) + 	pow ( rx1 , 2 ) ) ) ) ));
((f0_x1)[	(  2 + ixx1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx1 ) + 	pow ( rx1 , 2 ) ) ) ));
((f1_x1)[	(  2 + ixx1 )] = 	(  5.00000000000000000e-01 * rx1 ));
((if1_x1)[	(  2 + ixx1 )] = 	(  2.50000000000000000e-01 * 	pow ( rx1 , 2 ) ));
((f0_x1)[	(  3 + ixx1 )] = 	(  2.50000000000000000e-01 * 	pow ( rx1 , 2 ) ));
((f0_y1)[	(  0 + ixy1 )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) , 2 ) ));
((f1_y1)[	(  0 + ixy1 )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) ));
((if1_y1)[	(  0 + ixy1 )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) , 2 ) ) ));
((f0_y1)[	(  1 + ixy1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) ) ) ) ));
((f1_y1)[	(  1 + ixy1 )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) ) ));
((if1_y1)[	(  1 + ixy1 )] = 	(  	(  2.50000000000000000e-01 * 	pow ( ry1 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry1 ) + 	pow ( ry1 , 2 ) ) ) ) ));
((f0_y1)[	(  2 + ixy1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry1 ) + 	pow ( ry1 , 2 ) ) ) ));
((f1_y1)[	(  2 + ixy1 )] = 	(  5.00000000000000000e-01 * ry1 ));
((if1_y1)[	(  2 + ixy1 )] = 	(  2.50000000000000000e-01 * 	pow ( ry1 , 2 ) ));
((f0_y1)[	(  3 + ixy1 )] = 	(  2.50000000000000000e-01 * 	pow ( ry1 , 2 ) ));
((f0_z1)[	(  0 + ixz1 )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) , 2 ) ));
((f1_z1)[	(  0 + ixz1 )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) ));
((if1_z1)[	(  0 + ixz1 )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) , 2 ) ) ));
((f0_z1)[	(  1 + ixz1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) ) ) ) ));
((f1_z1)[	(  1 + ixz1 )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) ) ));
((if1_z1)[	(  1 + ixz1 )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rz1 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz1 ) + 	pow ( rz1 , 2 ) ) ) ) ));
((f0_z1)[	(  2 + ixz1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz1 ) + 	pow ( rz1 , 2 ) ) ) ));
((f1_z1)[	(  2 + ixz1 )] = 	(  5.00000000000000000e-01 * rz1 ));
((if1_z1)[	(  2 + ixz1 )] = 	(  2.50000000000000000e-01 * 	pow ( rz1 , 2 ) ));
((f0_z1)[	(  3 + ixz1 )] = 	(  2.50000000000000000e-01 * 	pow ( rz1 , 2 ) ));
	double  Ex1 ;
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
(sum0 = 	(  sum0 + 	(  (shE0)[	(  	(  allidx * 3 ) + 0 )] * 	(  (f1_x1)[xyzx] * 	(  (f0_y1)[xyzy] * (f0_z1)[xyzz] ) ) ) ));
}}}}}}(Ex1 = sum0);
}	double  Ey1 ;
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
(sum0 = 	(  sum0 + 	(  (shE0)[	(  	(  allidx * 3 ) + 1 )] * 	(  (f1_y1)[xyzy] * 	(  (f0_x1)[xyzx] * (f0_z1)[xyzz] ) ) ) ));
}}}}}}(Ey1 = sum0);
}	double  Ez1 ;
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
(sum0 = 	(  sum0 + 	(  (shE0)[	(  	(  allidx * 3 ) + 2 )] * 	(  (f1_z1)[xyzz] * 	(  (f0_x1)[xyzx] * (f0_y1)[xyzy] ) ) ) ));
}}}}}}(Ez1 = sum0);
}{
	double  B0y_intzX1Y1Z0Z1 ;
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
(sum0 = 	(  sum0 + 	(  (shB0)[	(  	(  allidx * 3 ) + 1 )] * 	(  (f0_y1)[xyzy] * 	(  	(  (if1_z1)[xyzz] - (if1_z0)[xyzz] ) * (f1_x1)[xyzx] ) ) ) ));
}}}}}}(B0y_intzX1Y1Z0Z1 = sum0);
}	double  B0z_intyX1Y0Z0Y1 ;
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
(sum0 = 	(  sum0 + 	(  (shB0)[	(  	(  allidx * 3 ) + 2 )] * 	(  (f0_z0)[xyzz] * 	(  	(  (if1_y1)[xyzy] - (if1_y0)[xyzy] ) * (f1_x1)[xyzx] ) ) ) ));
}}}}}}(B0z_intyX1Y0Z0Y1 = sum0);
}((	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[0] = 	(  	(  Charge * Ex1 ) + 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  B0z_intyX1Y0Z0Y1 + 	(  -1.00000000000000000e+00 * B0y_intzX1Y1Z0Z1 ) ) ) ) + 	(  Mass * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}{
	double  B0x_intzX1Y1Z0Z1 ;
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
(sum0 = 	(  sum0 + 	(  (shB0)[	(  	(  allidx * 3 ) + 0 )] * 	(  (f0_x1)[xyzx] * 	(  	(  (if1_z1)[xyzz] - (if1_z0)[xyzz] ) * (f1_y1)[xyzy] ) ) ) ));
}}}}}}(B0x_intzX1Y1Z0Z1 = sum0);
}((	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[1] = 	(  	(  Charge * Ey1 ) + 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * B0x_intzX1Y1Z0Z1 ) ) + 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}((	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[2] = 	(  	(  Charge * Ez1 ) + 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}}}{
	long  g ;
	for ((g = 0) ; 	(  g < numcp ) ; (g = 	(  g + 1 )))
	{
	double  res_0 = (	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[0] ;
	double  res_1 = (	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[1] ;
	double  res_2 = (	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[2] ;
	double  vx0 = (	(  local_particle_head + 	(  g * 6 ) ))[3] ;
	double  vy0 = (	(  local_particle_head + 	(  g * 6 ) ))[4] ;
	double  vz0 = (	(  local_particle_head + 	(  g * 6 ) ))[5] ;
	double  xx1 = 	(  (	(  local_particle_head + 	(  g * 6 ) ))[0] - 5.00000000000000000e-01 ) ;
	double  xy1 = 	(  (	(  local_particle_head + 	(  g * 6 ) ))[1] - 5.00000000000000000e-01 ) ;
	double  xz1 = 	(  (	(  local_particle_head + 	(  g * 6 ) ))[2] - 5.00000000000000000e-01 ) ;
	double  xx0 = 	(  xx1 - 	(  Deltat * vx0 ) ) ;
	double  xy0 = 	(  xy1 - 	(  Deltat * vy0 ) ) ;
	double  xz0 = 	(  xz1 - 	(  Deltat * vz0 ) ) ;
	double  Midx0 = 	openmp_floory ( xx0 ) ;
	double  Midy0 = 	openmp_floory ( xy0 ) ;
	double  Midz0 = 	openmp_floory ( xz0 ) ;
	double  Midx1 = 	openmp_floory ( xx1 ) ;
	double  Midy1 = 	openmp_floory ( xy1 ) ;
	double  Midz1 = 	openmp_floory ( xz1 ) ;
	double  rx0 = 	(  xx0 - Midx0 ) ;
	double  ry0 = 	(  xy0 - Midy0 ) ;
	double  rz0 = 	(  xz0 - Midz0 ) ;
	double  rx1 = 	(  xx1 - Midx1 ) ;
	double  ry1 = 	(  xy1 - Midy1 ) ;
	double  rz1 = 	(  xz1 - Midz1 ) ;
	double  X0 = xx0 ;
	double  X1 = xx1 ;
	double  X2 = 	(  	(  2 * xx1 ) - xx0 ) ;
	double  Y0 = xy0 ;
	double  Y1 = xy1 ;
	double  Y2 = 	(  	(  2 * xy1 ) - xy0 ) ;
	double  Z0 = xz0 ;
	double  Z1 = xz1 ;
	double  Z2 = 	(  	(  2 * xz1 ) - xz0 ) ;
	double   f0_x1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_x1)[i] = 0);
}}	double   f1_x1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_x1)[i] = 0);
}}	double   if1_x1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_x1)[i] = 0);
}}	double   df0_x1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((df0_x1)[i] = 0);
}}	double   dif1_x1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((dif1_x1)[i] = 0);
}}	double   f0_y1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_y1)[i] = 0);
}}	double   f1_y1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_y1)[i] = 0);
}}	double   if1_y1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_y1)[i] = 0);
}}	double   df0_y1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((df0_y1)[i] = 0);
}}	double   dif1_y1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((dif1_y1)[i] = 0);
}}	double   f0_z1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_z1)[i] = 0);
}}	double   f1_z1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_z1)[i] = 0);
}}	double   if1_z1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_z1)[i] = 0);
}}	double   df0_z1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((df0_z1)[i] = 0);
}}	double   dif1_z1  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((dif1_z1)[i] = 0);
}}	double   f0_x2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_x2)[i] = 0);
}}	double   f1_x2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_x2)[i] = 0);
}}	double   if1_x2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_x2)[i] = 0);
}}	double   df0_x2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((df0_x2)[i] = 0);
}}	double   dif1_x2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((dif1_x2)[i] = 0);
}}	double   f0_y2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_y2)[i] = 0);
}}	double   f1_y2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_y2)[i] = 0);
}}	double   if1_y2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_y2)[i] = 0);
}}	double   df0_y2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((df0_y2)[i] = 0);
}}	double   dif1_y2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((dif1_y2)[i] = 0);
}}	double   f0_z2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_z2)[i] = 0);
}}	double   f1_z2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_z2)[i] = 0);
}}	double   if1_z2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_z2)[i] = 0);
}}	double   df0_z2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((df0_z2)[i] = 0);
}}	double   dif1_z2  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((dif1_z2)[i] = 0);
}}	int  ixx0 = ((	(  xx0 >= Midx ))?(1):(0)) ;
	int  ixy0 = ((	(  xy0 >= Midy ))?(1):(0)) ;
	int  ixz0 = ((	(  xz0 >= Midz ))?(1):(0)) ;
	int  ixx1 = ((	(  xx1 >= Midx ))?(1):(0)) ;
	int  ixy1 = ((	(  xy1 >= Midy ))?(1):(0)) ;
	int  ixz1 = ((	(  xz1 >= Midz ))?(1):(0)) ;
((if1_x1)[0] = 1);
((if1_x1)[1] = 1);
((if1_y1)[0] = 1);
((if1_y1)[1] = 1);
((if1_z1)[0] = 1);
((if1_z1)[1] = 1);
((f0_x1)[	(  0 + ixx1 )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) , 2 ) ));
((f1_x1)[	(  0 + ixx1 )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) ));
((if1_x1)[	(  0 + ixx1 )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) , 2 ) ) ));
((f0_x1)[	(  1 + ixx1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) ) ) ) ));
((f1_x1)[	(  1 + ixx1 )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx1 ) ) ) ));
((if1_x1)[	(  1 + ixx1 )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx1 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx1 ) + 	pow ( rx1 , 2 ) ) ) ) ));
((f0_x1)[	(  2 + ixx1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx1 ) + 	pow ( rx1 , 2 ) ) ) ));
((f1_x1)[	(  2 + ixx1 )] = 	(  5.00000000000000000e-01 * rx1 ));
((if1_x1)[	(  2 + ixx1 )] = 	(  2.50000000000000000e-01 * 	pow ( rx1 , 2 ) ));
((f0_x1)[	(  3 + ixx1 )] = 	(  2.50000000000000000e-01 * 	pow ( rx1 , 2 ) ));
((f0_y1)[	(  0 + ixy1 )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) , 2 ) ));
((f1_y1)[	(  0 + ixy1 )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) ));
((if1_y1)[	(  0 + ixy1 )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) , 2 ) ) ));
((f0_y1)[	(  1 + ixy1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) ) ) ) ));
((f1_y1)[	(  1 + ixy1 )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry1 ) ) ) ));
((if1_y1)[	(  1 + ixy1 )] = 	(  	(  2.50000000000000000e-01 * 	pow ( ry1 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry1 ) + 	pow ( ry1 , 2 ) ) ) ) ));
((f0_y1)[	(  2 + ixy1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry1 ) + 	pow ( ry1 , 2 ) ) ) ));
((f1_y1)[	(  2 + ixy1 )] = 	(  5.00000000000000000e-01 * ry1 ));
((if1_y1)[	(  2 + ixy1 )] = 	(  2.50000000000000000e-01 * 	pow ( ry1 , 2 ) ));
((f0_y1)[	(  3 + ixy1 )] = 	(  2.50000000000000000e-01 * 	pow ( ry1 , 2 ) ));
((f0_z1)[	(  0 + ixz1 )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) , 2 ) ));
((f1_z1)[	(  0 + ixz1 )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) ));
((if1_z1)[	(  0 + ixz1 )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) , 2 ) ) ));
((f0_z1)[	(  1 + ixz1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) ) ) ) ));
((f1_z1)[	(  1 + ixz1 )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz1 ) ) ) ));
((if1_z1)[	(  1 + ixz1 )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rz1 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz1 ) + 	pow ( rz1 , 2 ) ) ) ) ));
((f0_z1)[	(  2 + ixz1 )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz1 ) + 	pow ( rz1 , 2 ) ) ) ));
((f1_z1)[	(  2 + ixz1 )] = 	(  5.00000000000000000e-01 * rz1 ));
((if1_z1)[	(  2 + ixz1 )] = 	(  2.50000000000000000e-01 * 	pow ( rz1 , 2 ) ));
((f0_z1)[	(  3 + ixz1 )] = 	(  2.50000000000000000e-01 * 	pow ( rz1 , 2 ) ));
{
	double  maxerr = 0.00000000000000000e+00 ;
	double  RPL00 ;
	double  RPL10 ;
	double  RPL20 ;
	double   RES  [3];	double   L_RES  [3];	double   JAC  [9];	double   IJAC  [9];{
	long  z ;
	for ((z = 0) ; 	(  z < 32 ) ; (z = 	(  z + 1 )))
	{
{
	double  xx2 = X2 ;
	double  xy2 = Y2 ;
	double  xz2 = Z2 ;
	int  Midx2 = 	openmp_floory ( xx2 ) ;
	int  Midy2 = 	openmp_floory ( xy2 ) ;
	int  Midz2 = 	openmp_floory ( xz2 ) ;
	double  rx2 = 	(  xx2 - Midx2 ) ;
	double  ry2 = 	(  xy2 - Midy2 ) ;
	double  rz2 = 	(  xz2 - Midz2 ) ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_x2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_x2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_x2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((df0_x2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((dif1_x2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_y2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_y2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_y2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((df0_y2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((dif1_y2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f0_z2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((f1_z2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((if1_z2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((df0_z2)[i] = 0);
}}{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((dif1_z2)[i] = 0);
}}((if1_x2)[0] = 1);
((if1_x2)[1] = 1);
((if1_y2)[0] = 1);
((if1_y2)[1] = 1);
((if1_z2)[0] = 1);
((if1_z2)[1] = 1);
	double  ixx2 = ((	(  xx2 >= Midx ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  ixy2 = ((	(  xy2 >= Midy ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  ixz2 = ((	(  xz2 >= Midz ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  f0_0x2_nv_bac ;
(f0_0x2_nv_bac = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx2 ) ) , 2 ) ));
	double  df0_0x2_nv_bac ;
(df0_0x2_nv_bac = 	(  -5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx2 ) ) ));
	double  dif1_0x2_nv_bac ;
(dif1_0x2_nv_bac = -5.00000000000000000e-01);
	double  f1_0x2_nv_bac ;
(f1_0x2_nv_bac = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx2 ) ) ));
	double  if1_0x2_nv_bac ;
(if1_0x2_nv_bac = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx2 ) ) , 2 ) ) ));
	double  f0_1x2_nv_bac ;
(f0_1x2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx2 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx2 ) ) ) ) ) ));
	double  df0_1x2_nv_bac ;
(df0_1x2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx2 ) ) ) ) ));
	double  dif1_1x2_nv_bac ;
(dif1_1x2_nv_bac = 0.00000000000000000e+00);
	double  f1_1x2_nv_bac ;
(f1_1x2_nv_bac = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx2 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx2 ) ) ) ));
	double  if1_1x2_nv_bac ;
(if1_1x2_nv_bac = 	(  	(  2.50000000000000000e-01 * 	pow ( rx2 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx2 ) + 	pow ( rx2 , 2 ) ) ) ) ));
	double  f0_2x2_nv_bac ;
(f0_2x2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx2 ) + 	pow ( rx2 , 2 ) ) ) ));
	double  df0_2x2_nv_bac ;
(df0_2x2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  -2.00000000000000000e+00 + 	(  2.00000000000000000e+00 * rx2 ) ) ));
	double  dif1_2x2_nv_bac ;
(dif1_2x2_nv_bac = 5.00000000000000000e-01);
	double  f1_2x2_nv_bac ;
(f1_2x2_nv_bac = 	(  5.00000000000000000e-01 * rx2 ));
	double  if1_2x2_nv_bac ;
(if1_2x2_nv_bac = 	(  2.50000000000000000e-01 * 	pow ( rx2 , 2 ) ));
	double  f0_3x2_nv_bac ;
(f0_3x2_nv_bac = 	(  2.50000000000000000e-01 * 	pow ( rx2 , 2 ) ));
	double  df0_3x2_nv_bac ;
(df0_3x2_nv_bac = 	(  5.00000000000000000e-01 * rx2 ));
	double  f0_0y2_nv_bac ;
(f0_0y2_nv_bac = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry2 ) ) , 2 ) ));
	double  df0_0y2_nv_bac ;
(df0_0y2_nv_bac = 	(  -5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry2 ) ) ));
	double  dif1_0y2_nv_bac ;
(dif1_0y2_nv_bac = -5.00000000000000000e-01);
	double  f1_0y2_nv_bac ;
(f1_0y2_nv_bac = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry2 ) ) ));
	double  if1_0y2_nv_bac ;
(if1_0y2_nv_bac = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry2 ) ) , 2 ) ) ));
	double  f0_1y2_nv_bac ;
(f0_1y2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry2 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry2 ) ) ) ) ) ));
	double  df0_1y2_nv_bac ;
(df0_1y2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry2 ) ) ) ) ));
	double  dif1_1y2_nv_bac ;
(dif1_1y2_nv_bac = 0.00000000000000000e+00);
	double  f1_1y2_nv_bac ;
(f1_1y2_nv_bac = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry2 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry2 ) ) ) ));
	double  if1_1y2_nv_bac ;
(if1_1y2_nv_bac = 	(  	(  2.50000000000000000e-01 * 	pow ( ry2 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry2 ) + 	pow ( ry2 , 2 ) ) ) ) ));
	double  f0_2y2_nv_bac ;
(f0_2y2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry2 ) + 	pow ( ry2 , 2 ) ) ) ));
	double  df0_2y2_nv_bac ;
(df0_2y2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  -2.00000000000000000e+00 + 	(  2.00000000000000000e+00 * ry2 ) ) ));
	double  dif1_2y2_nv_bac ;
(dif1_2y2_nv_bac = 5.00000000000000000e-01);
	double  f1_2y2_nv_bac ;
(f1_2y2_nv_bac = 	(  5.00000000000000000e-01 * ry2 ));
	double  if1_2y2_nv_bac ;
(if1_2y2_nv_bac = 	(  2.50000000000000000e-01 * 	pow ( ry2 , 2 ) ));
	double  f0_3y2_nv_bac ;
(f0_3y2_nv_bac = 	(  2.50000000000000000e-01 * 	pow ( ry2 , 2 ) ));
	double  df0_3y2_nv_bac ;
(df0_3y2_nv_bac = 	(  5.00000000000000000e-01 * ry2 ));
	double  f0_0z2_nv_bac ;
(f0_0z2_nv_bac = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz2 ) ) , 2 ) ));
	double  df0_0z2_nv_bac ;
(df0_0z2_nv_bac = 	(  -5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz2 ) ) ));
	double  dif1_0z2_nv_bac ;
(dif1_0z2_nv_bac = -5.00000000000000000e-01);
	double  f1_0z2_nv_bac ;
(f1_0z2_nv_bac = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz2 ) ) ));
	double  if1_0z2_nv_bac ;
(if1_0z2_nv_bac = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz2 ) ) , 2 ) ) ));
	double  f0_1z2_nv_bac ;
(f0_1z2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz2 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz2 ) ) ) ) ) ));
	double  df0_1z2_nv_bac ;
(df0_1z2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz2 ) ) ) ) ));
	double  dif1_1z2_nv_bac ;
(dif1_1z2_nv_bac = 0.00000000000000000e+00);
	double  f1_1z2_nv_bac ;
(f1_1z2_nv_bac = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz2 ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz2 ) ) ) ));
	double  if1_1z2_nv_bac ;
(if1_1z2_nv_bac = 	(  	(  2.50000000000000000e-01 * 	pow ( rz2 , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz2 ) + 	pow ( rz2 , 2 ) ) ) ) ));
	double  f0_2z2_nv_bac ;
(f0_2z2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz2 ) + 	pow ( rz2 , 2 ) ) ) ));
	double  df0_2z2_nv_bac ;
(df0_2z2_nv_bac = 	(  -2.50000000000000000e-01 * 	(  -2.00000000000000000e+00 + 	(  2.00000000000000000e+00 * rz2 ) ) ));
	double  dif1_2z2_nv_bac ;
(dif1_2z2_nv_bac = 5.00000000000000000e-01);
	double  f1_2z2_nv_bac ;
(f1_2z2_nv_bac = 	(  5.00000000000000000e-01 * rz2 ));
	double  if1_2z2_nv_bac ;
(if1_2z2_nv_bac = 	(  2.50000000000000000e-01 * 	pow ( rz2 , 2 ) ));
	double  f0_3z2_nv_bac ;
(f0_3z2_nv_bac = 	(  2.50000000000000000e-01 * 	pow ( rz2 , 2 ) ));
	double  df0_3z2_nv_bac ;
(df0_3z2_nv_bac = 	(  5.00000000000000000e-01 * rz2 ));
((f0_x2)[0] = 	(  	(  ixx2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * f0_0x2_nv_bac ) ));
((df0_x2)[0] = 	(  	(  ixx2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * df0_0x2_nv_bac ) ));
((dif1_x2)[0] = 	(  	(  ixx2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * dif1_0x2_nv_bac ) ));
((f1_x2)[0] = 	(  	(  ixx2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * f1_0x2_nv_bac ) ));
((if1_x2)[0] = 	(  	(  ixx2 * 1.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * if1_0x2_nv_bac ) ));
((f0_x2)[1] = 	(  	(  ixx2 * f0_0x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * f0_1x2_nv_bac ) ));
((df0_x2)[1] = 	(  	(  ixx2 * df0_0x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * df0_1x2_nv_bac ) ));
((dif1_x2)[1] = 	(  	(  ixx2 * dif1_0x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * dif1_1x2_nv_bac ) ));
((f1_x2)[1] = 	(  	(  ixx2 * f1_0x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * f1_1x2_nv_bac ) ));
((if1_x2)[1] = 	(  	(  ixx2 * if1_0x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * if1_1x2_nv_bac ) ));
((f0_x2)[2] = 	(  	(  ixx2 * f0_1x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * f0_2x2_nv_bac ) ));
((df0_x2)[2] = 	(  	(  ixx2 * df0_1x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * df0_2x2_nv_bac ) ));
((dif1_x2)[2] = 	(  	(  ixx2 * dif1_1x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * dif1_2x2_nv_bac ) ));
((f1_x2)[2] = 	(  	(  ixx2 * f1_1x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * f1_2x2_nv_bac ) ));
((if1_x2)[2] = 	(  	(  ixx2 * if1_1x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * if1_2x2_nv_bac ) ));
((f0_x2)[3] = 	(  	(  ixx2 * f0_2x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * f0_3x2_nv_bac ) ));
((df0_x2)[3] = 	(  	(  ixx2 * df0_2x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * df0_3x2_nv_bac ) ));
((dif1_x2)[3] = 	(  	(  ixx2 * dif1_2x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * 0 ) ));
((f1_x2)[3] = 	(  	(  ixx2 * f1_2x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * 0 ) ));
((if1_x2)[3] = 	(  	(  ixx2 * if1_2x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * 0 ) ));
((f0_x2)[4] = 	(  	(  ixx2 * f0_3x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * 0 ) ));
((df0_x2)[4] = 	(  	(  ixx2 * df0_3x2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixx2 ) * 0 ) ));
((f0_y2)[0] = 	(  	(  ixy2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * f0_0y2_nv_bac ) ));
((df0_y2)[0] = 	(  	(  ixy2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * df0_0y2_nv_bac ) ));
((dif1_y2)[0] = 	(  	(  ixy2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * dif1_0y2_nv_bac ) ));
((f1_y2)[0] = 	(  	(  ixy2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * f1_0y2_nv_bac ) ));
((if1_y2)[0] = 	(  	(  ixy2 * 1.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * if1_0y2_nv_bac ) ));
((f0_y2)[1] = 	(  	(  ixy2 * f0_0y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * f0_1y2_nv_bac ) ));
((df0_y2)[1] = 	(  	(  ixy2 * df0_0y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * df0_1y2_nv_bac ) ));
((dif1_y2)[1] = 	(  	(  ixy2 * dif1_0y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * dif1_1y2_nv_bac ) ));
((f1_y2)[1] = 	(  	(  ixy2 * f1_0y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * f1_1y2_nv_bac ) ));
((if1_y2)[1] = 	(  	(  ixy2 * if1_0y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * if1_1y2_nv_bac ) ));
((f0_y2)[2] = 	(  	(  ixy2 * f0_1y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * f0_2y2_nv_bac ) ));
((df0_y2)[2] = 	(  	(  ixy2 * df0_1y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * df0_2y2_nv_bac ) ));
((dif1_y2)[2] = 	(  	(  ixy2 * dif1_1y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * dif1_2y2_nv_bac ) ));
((f1_y2)[2] = 	(  	(  ixy2 * f1_1y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * f1_2y2_nv_bac ) ));
((if1_y2)[2] = 	(  	(  ixy2 * if1_1y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * if1_2y2_nv_bac ) ));
((f0_y2)[3] = 	(  	(  ixy2 * f0_2y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * f0_3y2_nv_bac ) ));
((df0_y2)[3] = 	(  	(  ixy2 * df0_2y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * df0_3y2_nv_bac ) ));
((dif1_y2)[3] = 	(  	(  ixy2 * dif1_2y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * 0 ) ));
((f1_y2)[3] = 	(  	(  ixy2 * f1_2y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * 0 ) ));
((if1_y2)[3] = 	(  	(  ixy2 * if1_2y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * 0 ) ));
((f0_y2)[4] = 	(  	(  ixy2 * f0_3y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * 0 ) ));
((df0_y2)[4] = 	(  	(  ixy2 * df0_3y2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixy2 ) * 0 ) ));
((f0_z2)[0] = 	(  	(  ixz2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * f0_0z2_nv_bac ) ));
((df0_z2)[0] = 	(  	(  ixz2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * df0_0z2_nv_bac ) ));
((dif1_z2)[0] = 	(  	(  ixz2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * dif1_0z2_nv_bac ) ));
((f1_z2)[0] = 	(  	(  ixz2 * 0.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * f1_0z2_nv_bac ) ));
((if1_z2)[0] = 	(  	(  ixz2 * 1.00000000000000000e+00 ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * if1_0z2_nv_bac ) ));
((f0_z2)[1] = 	(  	(  ixz2 * f0_0z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * f0_1z2_nv_bac ) ));
((df0_z2)[1] = 	(  	(  ixz2 * df0_0z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * df0_1z2_nv_bac ) ));
((dif1_z2)[1] = 	(  	(  ixz2 * dif1_0z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * dif1_1z2_nv_bac ) ));
((f1_z2)[1] = 	(  	(  ixz2 * f1_0z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * f1_1z2_nv_bac ) ));
((if1_z2)[1] = 	(  	(  ixz2 * if1_0z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * if1_1z2_nv_bac ) ));
((f0_z2)[2] = 	(  	(  ixz2 * f0_1z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * f0_2z2_nv_bac ) ));
((df0_z2)[2] = 	(  	(  ixz2 * df0_1z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * df0_2z2_nv_bac ) ));
((dif1_z2)[2] = 	(  	(  ixz2 * dif1_1z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * dif1_2z2_nv_bac ) ));
((f1_z2)[2] = 	(  	(  ixz2 * f1_1z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * f1_2z2_nv_bac ) ));
((if1_z2)[2] = 	(  	(  ixz2 * if1_1z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * if1_2z2_nv_bac ) ));
((f0_z2)[3] = 	(  	(  ixz2 * f0_2z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * f0_3z2_nv_bac ) ));
((df0_z2)[3] = 	(  	(  ixz2 * df0_2z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * df0_3z2_nv_bac ) ));
((dif1_z2)[3] = 	(  	(  ixz2 * dif1_2z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * 0 ) ));
((f1_z2)[3] = 	(  	(  ixz2 * f1_2z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * 0 ) ));
((if1_z2)[3] = 	(  	(  ixz2 * if1_2z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * 0 ) ));
((f0_z2)[4] = 	(  	(  ixz2 * f0_3z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * 0 ) ));
((df0_z2)[4] = 	(  	(  ixz2 * df0_3z2_nv_bac ) + 	(  	(  1.00000000000000000e+00 - ixz2 ) * 0 ) ));
}((RES)[0] = 	(  	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) + res_0 ));
{
	double  B1z_intxX1Y1Z1X2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 2 )] * 	(  (f0_z1)[xyzz] * 	(  	(  (if1_x2)[xyzx] - (if1_x1)[xyzx] ) * (f1_y1)[xyzy] ) ) ) ));
}}}}}}(B1z_intxX1Y1Z1X2 = sum0);
}((RES)[1] = 	(  	(  	(  -1.00000000000000000e+00 * 	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1z_intxX1Y1Z1X2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + res_1 ));
}{
	double  B1x_intyX2Y1Z1Y2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 0 )] * 	(  (f0_x2)[xyzx] * 	(  	(  (if1_y2)[xyzy] - (if1_y1)[xyzy] ) * (f1_z1)[xyzz] ) ) ) ));
}}}}}}(B1x_intyX2Y1Z1Y2 = sum0);
}	double  B1y_intxX1Y1Z1X2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 1 )] * 	(  (f0_y1)[xyzy] * 	(  	(  (if1_x2)[xyzx] - (if1_x1)[xyzx] ) * (f1_z1)[xyzz] ) ) ) ));
}}}}}}(B1y_intxX1Y1Z1X2 = sum0);
}((RES)[2] = 	(  	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  B1y_intxX1Y1Z1X2 + 	(  -1.00000000000000000e+00 * B1x_intyX2Y1Z1Y2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + res_2 ));
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 2 )] * 	(  (f0_z1)[xyzz] * 	(  (dif1_x2)[xyzx] * (f1_y1)[xyzy] ) ) ) ));
}}}}}}(B1z_intx_xX1Y1Z1X2 = sum0);
}((JAC)[1] = 	(  	(  -1.00000000000000000e+00 * 	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1z_intx_xX1Y1Z1X2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 1 )] * 	(  (f0_y1)[xyzy] * 	(  (dif1_x2)[xyzx] * (f1_z1)[xyzz] ) ) ) ));
}}}}}}(B1y_intx_xX1Y1Z1X2 = sum0);
}((JAC)[2] = 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  B1y_intx_xX1Y1Z1X2 + 	(  -1.00000000000000000e+00 * B1x_inty_xX2Y1Z1Y2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}((JAC)[3] = 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
((JAC)[4] = 	(  	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 4 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ));
{
	double  B1x_inty_yX2Y1Z1Y2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 0 )] * 	(  (f0_x2)[xyzx] * 	(  (dif1_y2)[xyzy] * (f1_z1)[xyzz] ) ) ) ));
}}}}}}(B1x_inty_yX2Y1Z1Y2 = sum0);
}((JAC)[5] = 	(  	(  -1.00000000000000000e+00 * 	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1x_inty_yX2Y1Z1Y2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
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
}}}((	(  local_particle_head + 	(  g * 6 ) ))[0] = 	(  X2 + 5.00000000000000000e-01 ));
((	(  local_particle_head + 	(  g * 6 ) ))[1] = 	(  Y2 + 5.00000000000000000e-01 ));
((	(  local_particle_head + 	(  g * 6 ) ))[2] = 	(  Z2 + 5.00000000000000000e-01 ));
((	(  local_particle_head + 	(  g * 6 ) ))[3] = 	(  	(  X2 - xx1 ) / Deltat ));
((	(  local_particle_head + 	(  g * 6 ) ))[4] = 	(  	(  Y2 - xy1 ) / Deltat ));
((	(  local_particle_head + 	(  g * 6 ) ))[5] = 	(  	(  Z2 - xz1 ) / Deltat ));
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
}}}}}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}0;
}}{
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
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )] = new_load);

	}else{
		0;

	 }
}}}
