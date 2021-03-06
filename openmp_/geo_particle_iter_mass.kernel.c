#include <omp.h> 
#include <math.h>

#include <math.h>
#include <assert.h>
#include <stdio.h>
#define IDX_OPT_MAX 1
int  openmp_mass_floorx (double  x ){
	int  ax = x ;
	if (  	(  ax > x )  ){  
		(ax = 	(  ax + -1 ));

	}else{
		0;

	 }
	return  ax ;}
void  openmp_geo_rel_1st_fwd_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  LFoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
	int  call_sort = 1 ;
	int  cr_allgid = 0 ;
	int  use_local_particle_position = 1 ;
	int  mdx ;
	int  mdy ;
	int  mdz ;
	double   shB0  [375];	double   shB1  [375];	double   shE0  [375];	double   shJ0  [375];	double *  particle_head_general ;
	int  load0 ;
	int  new_load ;
	int  global_idy_tmp ;
	goto beg_prog;	core_fun:
{
	int  idy = global_idy_tmp ;
	if (  load0  ){  
			double  DELTAT = Deltat ;
	double  grid_geo_x = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_y = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_z = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  XO = (xoffset)[idy] ;
	int  Midx = 	openmp_mass_floorx ( (particle_head_general)[0] ) ;
	int  Midy = 	openmp_mass_floorx ( (particle_head_general)[1] ) ;
	int  Midz = 	openmp_mass_floorx ( (particle_head_general)[2] ) ;
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
}}}}}}}}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 375 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 375 )  ){  
		((shJ0)[ridx] = (	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  375 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}{
	long  gMYGEN310 = 0 ;
	for (0 ; 	(  	(  gMYGEN310 + 	(  idx * 1 ) ) < load0 ) ; (gMYGEN310 = 	(  gMYGEN310 + 	(  1 * xlen ) )))
	{
	long  iba_tmp = 	(  	(  idx * 1 ) + gMYGEN310 ) ;
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
((	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  particle_head_general + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
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
	double  Midx0 = 	openmp_mass_floorx ( xx0 ) ;
	double  Midy0 = 	openmp_mass_floorx ( xy0 ) ;
	double  Midz0 = 	openmp_mass_floorx ( xz0 ) ;
	double  Midx1 = 	openmp_mass_floorx ( xx1 ) ;
	double  Midy1 = 	openmp_mass_floorx ( xy1 ) ;
	double  Midz1 = 	openmp_mass_floorx ( xz1 ) ;
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
}((	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[0] = 	(  	(  Charge * Ex1 ) + 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  B0z_intyX1Y0Z0Y1 + 	(  -1.00000000000000000e+00 * B0y_intzX1Y1Z0Z1 ) ) ) ) + 	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ));
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
}((	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[1] = 	(  	(  Charge * Ey1 ) + 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * B0x_intzX1Y1Z0Z1 ) ) + 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}((	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[2] = 	(  	(  Charge * Ez1 ) + 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ));
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
	double  Midx0 = 	openmp_mass_floorx ( xx0 ) ;
	double  Midy0 = 	openmp_mass_floorx ( xy0 ) ;
	double  Midz0 = 	openmp_mass_floorx ( xz0 ) ;
	double  Midx1 = 	openmp_mass_floorx ( xx1 ) ;
	double  Midy1 = 	openmp_mass_floorx ( xy1 ) ;
	double  Midz1 = 	openmp_mass_floorx ( xz1 ) ;
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
	int  Midx2 = 	openmp_mass_floorx ( xx2 ) ;
	int  Midy2 = 	openmp_mass_floorx ( xy2 ) ;
	int  Midz2 = 	openmp_mass_floorx ( xz2 ) ;
	double  rx2 = 	(  xx2 - Midx2 ) ;
	double  ry2 = 	(  xy2 - Midy2 ) ;
	double  rz2 = 	(  xz2 - Midz2 ) ;
(RPL00 = 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ));
(RPL10 = 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ));
(RPL20 = 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * RPL10 ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) , 0.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * RPL10 ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ));
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
}((RES)[0] = 	(  	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) + res_0 ));
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
}((RES)[1] = 	(  	(  	(  -1.00000000000000000e+00 * 	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1z_intxX1Y1Z1X2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + res_1 ));
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
}((RES)[2] = 	(  	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  B1y_intxX1Y1Z1X2 + 	(  -1.00000000000000000e+00 * B1x_intyX2Y1Z1Y2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + res_2 ));
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
((JAC)[0] = 	(  	(  2.50000000000000000e-01 * 	(  Mass * 	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	pow ( DELTAT , -2 ) ) ) + 	(  -5.00000000000000000e-01 * 	(  	pow ( Tori_X0 , -2 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ));
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
}((JAC)[1] = 	(  	(  -1.00000000000000000e+00 * 	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1z_intx_xX1Y1Z1X2 ) ) ) + 	(  	(  5.00000000000000000e-01 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
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
}((JAC)[2] = 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  B1y_intx_xX1Y1Z1X2 + 	(  -1.00000000000000000e+00 * B1x_inty_xX2Y1Z1Y2 ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}((JAC)[3] = 	(  	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
((JAC)[4] = 	(  	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 4 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( RPL00 , 4 ) * 	(  	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
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
}((JAC)[5] = 	(  	(  -1.00000000000000000e+00 * 	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1x_inty_yX2Y1Z1Y2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}((JAC)[6] = 	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
((JAC)[7] = 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
((JAC)[8] = 	(  	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Z , 4 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ));
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
((shJ0)[	(  allidx + 	(  0 * 125 ) )] = 	(  (shJ0)[	(  allidx + 	(  0 * 125 ) )] + 	(  	(  Tori_X0 / 	(  Tori_X0 + 	(  XO + 	(  Bidx + xyzx ) ) ) ) * 	(  Charge0 * Jx ) ) ));
((shJ0)[	(  allidx + 	(  1 * 125 ) )] = 	(  (shJ0)[	(  allidx + 	(  1 * 125 ) )] + 	(  	(  	(  Tori_X0 + 	(  XO + 	(  Bidx + xyzx ) ) ) / Tori_X0 ) * 	(  Charge0 * Jy ) ) ));
((shJ0)[	(  allidx + 	(  2 * 125 ) )] = 	(  (shJ0)[	(  allidx + 	(  2 * 125 ) )] + 	(  	(  Tori_X0 / 	(  Tori_X0 + 	(  XO + 	(  Bidx + xyzx ) ) ) ) * 	(  Charge0 * Jz ) ) ));
}}}}}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  particle_head_general + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}0;
}}{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 375 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  375 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) ))[Gll_P9918] = (shJ0)[Gll_P9918]);
}}
	}else{
		0;

	 }
}(cur_frame_num = 	(  cur_frame_num + -1 ));
	goto 	* ( (call_stack_pointer)[cur_frame_num] );	beg_prog:
0;
	long  allgid = idy ;
	for (0 ; 	(  allgid < numvec ) ; (allgid = 	(  allgid + ylen )))
	{
	int  cu_load = (cu_xyzw)[	(  4 * allgid )] ;
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  idy = allgid ;
(load0 = 1);
(use_local_particle_position = 1);
(particle_head_general = 	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ));
(new_load = load0);
(call_sort = 0);
(global_idy_tmp = idy);

	 call_stack_pointer[cur_frame_num]=&&LAB_TMP1;
(cur_frame_num = 	(  cur_frame_num + 1 ));
	goto core_fun;
	LAB_TMP1:
0;
}}}(allgid = idy);
	for (0 ; 	(  allgid < numgrid_cu ) ; (allgid = 	(  allgid + ylen )))
	{
	int  new_load_tmp = (xyzw)[	(  4 * allgid )] ;
	long  idy = 	(  allgid / numgrid ) ;
	long  c_gid = 	(  allgid % numgrid ) ;
(cr_allgid = allgid);
(use_local_particle_position = 0);
(mdx = 	(  c_gid % XLEN ));
(mdy = 	(  	(  c_gid / XLEN ) % YLEN ));
(mdz = 	(  c_gid / 	(  XLEN * YLEN ) ));
(load0 = new_load_tmp);
(call_sort = 0);
(particle_head_general = 	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ));
(new_load = load0);
(global_idy_tmp = idy);

	 call_stack_pointer[cur_frame_num]=&&LAB_TMP2;
(cur_frame_num = 	(  cur_frame_num + 1 ));
	goto core_fun;
	LAB_TMP2:
0;
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  0 + allgid ) )] = new_load);

	}else{
		0;

	 }
}}
void  openmp_geo_rel_1st_fwd_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  LFoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
	int  call_sort = 1 ;
	int  cr_allgid = 0 ;
	int  use_local_particle_position = 1 ;
	int  mdx ;
	int  mdy ;
	int  mdz ;
	double   shB0  [375];	double   shB1  [375];	double   shE0  [375];	double   shJ0  [375];	double *  particle_head_general ;
	int  load0 ;
	int  new_load ;
	int  global_idy_tmp ;
	goto beg_prog;	core_fun:
{
	int  idy = global_idy_tmp ;
	if (  load0  ){  
			double  DELTAT = Deltat ;
	double  grid_geo_x = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_y = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_z = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  XO = (xoffset)[idy] ;
	int  Midx = 	openmp_mass_floorx ( (particle_head_general)[0] ) ;
	int  Midy = 	openmp_mass_floorx ( (particle_head_general)[1] ) ;
	int  Midz = 	openmp_mass_floorx ( (particle_head_general)[2] ) ;
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
		((	(  shJ0 + total_idx ))[ridx] = (	(  LFoutJ + 	(  	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) + 	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}}}{
	long  gMYGEN323 = 0 ;
	for (0 ; 	(  	(  gMYGEN323 + 	(  idx * 1 ) ) < load0 ) ; (gMYGEN323 = 	(  gMYGEN323 + 	(  1 * xlen ) )))
	{
	long  iba_tmp = 	(  	(  idx * 1 ) + gMYGEN323 ) ;
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
((	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  particle_head_general + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
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
	double  Midx0 = 	openmp_mass_floorx ( xx0 ) ;
	double  Midy0 = 	openmp_mass_floorx ( xy0 ) ;
	double  Midz0 = 	openmp_mass_floorx ( xz0 ) ;
	double  Midx1 = 	openmp_mass_floorx ( xx1 ) ;
	double  Midy1 = 	openmp_mass_floorx ( xy1 ) ;
	double  Midz1 = 	openmp_mass_floorx ( xz1 ) ;
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
}((	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[0] = 	(  	(  Charge * Ex1 ) + 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  B0z_intyX1Y0Z0Y1 + 	(  -1.00000000000000000e+00 * B0y_intzX1Y1Z0Z1 ) ) ) ) + 	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ));
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
}((	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[1] = 	(  	(  Charge * Ey1 ) + 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * B0x_intzX1Y1Z0Z1 ) ) + 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}((	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[2] = 	(  	(  Charge * Ez1 ) + 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ));
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
	double  Midx0 = 	openmp_mass_floorx ( xx0 ) ;
	double  Midy0 = 	openmp_mass_floorx ( xy0 ) ;
	double  Midz0 = 	openmp_mass_floorx ( xz0 ) ;
	double  Midx1 = 	openmp_mass_floorx ( xx1 ) ;
	double  Midy1 = 	openmp_mass_floorx ( xy1 ) ;
	double  Midz1 = 	openmp_mass_floorx ( xz1 ) ;
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
	int  Midx2 = 	openmp_mass_floorx ( xx2 ) ;
	int  Midy2 = 	openmp_mass_floorx ( xy2 ) ;
	int  Midz2 = 	openmp_mass_floorx ( xz2 ) ;
	double  rx2 = 	(  xx2 - Midx2 ) ;
	double  ry2 = 	(  xy2 - Midy2 ) ;
	double  rz2 = 	(  xz2 - Midz2 ) ;
(RPL00 = 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ));
(RPL10 = 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ));
(RPL20 = 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * RPL10 ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) , 0.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * RPL10 ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ));
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
}((RES)[0] = 	(  	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) + res_0 ));
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
}((RES)[1] = 	(  	(  	(  -1.00000000000000000e+00 * 	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1z_intxX1Y1Z1X2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + res_1 ));
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
}((RES)[2] = 	(  	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  B1y_intxX1Y1Z1X2 + 	(  -1.00000000000000000e+00 * B1x_intyX2Y1Z1Y2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + res_2 ));
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
((JAC)[0] = 	(  	(  2.50000000000000000e-01 * 	(  Mass * 	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	pow ( DELTAT , -2 ) ) ) + 	(  -5.00000000000000000e-01 * 	(  	pow ( Tori_X0 , -2 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ));
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
}((JAC)[1] = 	(  	(  -1.00000000000000000e+00 * 	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1z_intx_xX1Y1Z1X2 ) ) ) + 	(  	(  5.00000000000000000e-01 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
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
}((JAC)[2] = 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  B1y_intx_xX1Y1Z1X2 + 	(  -1.00000000000000000e+00 * B1x_inty_xX2Y1Z1Y2 ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}((JAC)[3] = 	(  	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
((JAC)[4] = 	(  	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 4 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( RPL00 , 4 ) * 	(  	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
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
}((JAC)[5] = 	(  	(  -1.00000000000000000e+00 * 	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1x_inty_yX2Y1Z1Y2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}((JAC)[6] = 	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
((JAC)[7] = 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
((JAC)[8] = 	(  	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Z , 4 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ));
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
((shJ0)[	(  	(  3 * allidx ) + 0 )] = 	(  (shJ0)[	(  	(  3 * allidx ) + 0 )] + 	(  	(  Tori_X0 / 	(  Tori_X0 + 	(  XO + 	(  Bidx + xyzx ) ) ) ) * 	(  Charge0 * Jx ) ) ));
((shJ0)[	(  	(  3 * allidx ) + 1 )] = 	(  (shJ0)[	(  	(  3 * allidx ) + 1 )] + 	(  	(  	(  Tori_X0 + 	(  XO + 	(  Bidx + xyzx ) ) ) / Tori_X0 ) * 	(  Charge0 * Jy ) ) ));
((shJ0)[	(  	(  3 * allidx ) + 2 )] = 	(  (shJ0)[	(  	(  3 * allidx ) + 2 )] + 	(  	(  Tori_X0 / 	(  Tori_X0 + 	(  XO + 	(  Bidx + xyzx ) ) ) ) * 	(  Charge0 * Jz ) ) ));
}}}}}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  particle_head_general + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
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
((	(  LFoutJ + 	(  	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) + 	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) ) ))[Gll_P9918] = (	(  shJ0 + total_idx ))[Gll_P9918]);
}}}}}}}}
	}else{
		0;

	 }
}(cur_frame_num = 	(  cur_frame_num + -1 ));
	goto 	* ( (call_stack_pointer)[cur_frame_num] );	beg_prog:
0;
	long  allgid = idy ;
	for (0 ; 	(  allgid < numvec ) ; (allgid = 	(  allgid + ylen )))
	{
	int  cu_load = (cu_xyzw)[	(  4 * allgid )] ;
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  idy = allgid ;
(load0 = 1);
(use_local_particle_position = 1);
(particle_head_general = 	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ));
(new_load = load0);
(call_sort = 0);
(global_idy_tmp = idy);

	 call_stack_pointer[cur_frame_num]=&&LAB_TMP3;
(cur_frame_num = 	(  cur_frame_num + 1 ));
	goto core_fun;
	LAB_TMP3:
0;
}}}(allgid = idy);
	for (0 ; 	(  allgid < numgrid_cu ) ; (allgid = 	(  allgid + ylen )))
	{
	int  new_load_tmp = (xyzw)[	(  4 * allgid )] ;
	long  idy = 	(  allgid / numgrid ) ;
	long  c_gid = 	(  allgid % numgrid ) ;
(cr_allgid = allgid);
(use_local_particle_position = 0);
(mdx = 	(  c_gid % XLEN ));
(mdy = 	(  	(  c_gid / XLEN ) % YLEN ));
(mdz = 	(  c_gid / 	(  XLEN * YLEN ) ));
(load0 = new_load_tmp);
(call_sort = 0);
(particle_head_general = 	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ));
(new_load = load0);
(global_idy_tmp = idy);

	 call_stack_pointer[cur_frame_num]=&&LAB_TMP4;
(cur_frame_num = 	(  cur_frame_num + 1 ));
	goto core_fun;
	LAB_TMP4:
0;
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  0 + allgid ) )] = new_load);

	}else{
		0;

	 }
}}
void  openmp_geo_rel_1st_bwd_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  LFoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
	int  call_sort = 1 ;
	int  cr_allgid = 0 ;
	int  use_local_particle_position = 1 ;
	int  mdx ;
	int  mdy ;
	int  mdz ;
	double   shB0  [375];	double   shB1  [375];	double   shE0  [375];	double   shJ0  [375];	double *  particle_head_general ;
	int  load0 ;
	int  new_load ;
	int  global_idy_tmp ;
	goto beg_prog;	core_fun:
{
	int  idy = global_idy_tmp ;
	if (  load0  ){  
			double  DELTAT = Deltat ;
	double  grid_geo_x = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_y = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_z = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  XO = (xoffset)[idy] ;
	int  Midx = 	openmp_mass_floorx ( (particle_head_general)[0] ) ;
	int  Midy = 	openmp_mass_floorx ( (particle_head_general)[1] ) ;
	int  Midz = 	openmp_mass_floorx ( (particle_head_general)[2] ) ;
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
}}}}}}}}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 375 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 375 )  ){  
		((shJ0)[ridx] = (	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  375 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}{
	long  gMYGEN336 = 0 ;
	for (0 ; 	(  	(  gMYGEN336 + 	(  idx * 1 ) ) < load0 ) ; (gMYGEN336 = 	(  gMYGEN336 + 	(  1 * xlen ) )))
	{
	long  iba_tmp = 	(  	(  idx * 1 ) + gMYGEN336 ) ;
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
((	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  particle_head_general + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
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
	double  Midx0 = 	openmp_mass_floorx ( xx0 ) ;
	double  Midy0 = 	openmp_mass_floorx ( xy0 ) ;
	double  Midz0 = 	openmp_mass_floorx ( xz0 ) ;
	double  Midx1 = 	openmp_mass_floorx ( xx1 ) ;
	double  Midy1 = 	openmp_mass_floorx ( xy1 ) ;
	double  Midz1 = 	openmp_mass_floorx ( xz1 ) ;
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
}((	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[0] = 	(  	(  Charge * Ex1 ) + 	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ));
{
	double  B0z_intxX0Y1Z1X1 ;
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
(sum0 = 	(  sum0 + 	(  (shB0)[	(  	(  allidx * 3 ) + 2 )] * 	(  (f0_z1)[xyzz] * 	(  	(  (if1_x1)[xyzx] - (if1_x0)[xyzx] ) * (f1_y1)[xyzy] ) ) ) ));
}}}}}}(B0z_intxX0Y1Z1X1 = sum0);
}((	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[1] = 	(  	(  Charge * Ey1 ) + 	(  	(  -1.00000000000000000e+00 * 	(  Charge * 	(  	pow ( DELTAT , -1 ) * B0z_intxX0Y1Z1X1 ) ) ) + 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}{
	double  B0y_intxX0Y1Z1X1 ;
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
(sum0 = 	(  sum0 + 	(  (shB0)[	(  	(  allidx * 3 ) + 1 )] * 	(  (f0_y1)[xyzy] * 	(  	(  (if1_x1)[xyzx] - (if1_x0)[xyzx] ) * (f1_z1)[xyzz] ) ) ) ));
}}}}}}(B0y_intxX0Y1Z1X1 = sum0);
}	double  B0x_intyX0Y0Z1Y1 ;
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
(sum0 = 	(  sum0 + 	(  (shB0)[	(  	(  allidx * 3 ) + 0 )] * 	(  (f0_x0)[xyzx] * 	(  	(  (if1_y1)[xyzy] - (if1_y0)[xyzy] ) * (f1_z1)[xyzz] ) ) ) ));
}}}}}}(B0x_intyX0Y0Z1Y1 = sum0);
}((	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[2] = 	(  	(  Charge * Ez1 ) + 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  	(  -1.00000000000000000e+00 * B0x_intyX0Y0Z1Y1 ) + B0y_intxX0Y1Z1X1 ) ) ) + 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}}}}{
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
	double  Midx0 = 	openmp_mass_floorx ( xx0 ) ;
	double  Midy0 = 	openmp_mass_floorx ( xy0 ) ;
	double  Midz0 = 	openmp_mass_floorx ( xz0 ) ;
	double  Midx1 = 	openmp_mass_floorx ( xx1 ) ;
	double  Midy1 = 	openmp_mass_floorx ( xy1 ) ;
	double  Midz1 = 	openmp_mass_floorx ( xz1 ) ;
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
	int  Midx2 = 	openmp_mass_floorx ( xx2 ) ;
	int  Midy2 = 	openmp_mass_floorx ( xy2 ) ;
	int  Midz2 = 	openmp_mass_floorx ( xz2 ) ;
	double  rx2 = 	(  xx2 - Midx2 ) ;
	double  ry2 = 	(  xy2 - Midy2 ) ;
	double  rz2 = 	(  xz2 - Midz2 ) ;
(RPL00 = 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ));
(RPL10 = 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ));
(RPL20 = 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * RPL10 ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) , 0.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * RPL10 ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ));
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
}{
	double  B1z_intyX1Y1Z2Y2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 2 )] * 	(  (f0_z2)[xyzz] * 	(  	(  (if1_y2)[xyzy] - (if1_y1)[xyzy] ) * (f1_x1)[xyzx] ) ) ) ));
}}}}}}(B1z_intyX1Y1Z2Y2 = sum0);
}	double  B1y_intzX1Y1Z1Z2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 1 )] * 	(  (f0_y1)[xyzy] * 	(  	(  (if1_z2)[xyzz] - (if1_z1)[xyzz] ) * (f1_x1)[xyzx] ) ) ) ));
}}}}}}(B1y_intzX1Y1Z1Z2 = sum0);
}((RES)[0] = 	(  	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  	(  -1.00000000000000000e+00 * B1y_intzX1Y1Z1Z2 ) + B1z_intyX1Y1Z2Y2 ) ) ) + 	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) + res_0 ));
}{
	double  B1x_intzX1Y1Z1Z2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 0 )] * 	(  (f0_x1)[xyzx] * 	(  	(  (if1_z2)[xyzz] - (if1_z1)[xyzz] ) * (f1_y1)[xyzy] ) ) ) ));
}}}}}}(B1x_intzX1Y1Z1Z2 = sum0);
}((RES)[1] = 	(  	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1x_intzX1Y1Z1Z2 ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + res_1 ));
}((RES)[2] = 	(  	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) + res_2 ));
(maxerr = 0);
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
((JAC)[0] = 	(  	(  2.50000000000000000e-01 * 	(  Mass * 	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	pow ( DELTAT , -2 ) ) ) + 	(  -5.00000000000000000e-01 * 	(  	pow ( Tori_X0 , -2 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ));
((JAC)[1] = 	(  	(  5.00000000000000000e-01 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
((JAC)[2] = 	(  5.00000000000000000e-01 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
{
	double  B1z_inty_yX1Y1Z2Y2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 2 )] * 	(  (f0_z2)[xyzz] * 	(  (dif1_y2)[xyzy] * (f1_x1)[xyzx] ) ) ) ));
}}}}}}(B1z_inty_yX1Y1Z2Y2 = sum0);
}((JAC)[3] = 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1z_inty_yX1Y1Z2Y2 ) ) + 	(  	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}((JAC)[4] = 	(  	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 4 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( RPL00 , 4 ) * 	(  	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
((JAC)[5] = 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
{
	double  B1z_inty_zX1Y1Z2Y2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 2 )] * 	(  (df0_z2)[xyzz] * 	(  	(  (if1_y2)[xyzy] - (if1_y1)[xyzy] ) * (f1_x1)[xyzx] ) ) ) ));
}}}}}}(B1z_inty_zX1Y1Z2Y2 = sum0);
}	double  B1y_intz_zX1Y1Z1Z2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 1 )] * 	(  (f0_y1)[xyzy] * 	(  (dif1_z2)[xyzz] * (f1_x1)[xyzx] ) ) ) ));
}}}}}}(B1y_intz_zX1Y1Z1Z2 = sum0);
}((JAC)[6] = 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  	(  -1.00000000000000000e+00 * B1y_intz_zX1Y1Z1Z2 ) + B1z_inty_zX1Y1Z2Y2 ) ) ) + 	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}{
	double  B1x_intz_zX1Y1Z1Z2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 0 )] * 	(  (f0_x1)[xyzx] * 	(  (dif1_z2)[xyzz] * (f1_y1)[xyzy] ) ) ) ));
}}}}}}(B1x_intz_zX1Y1Z1Z2 = sum0);
}((JAC)[7] = 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1x_intz_zX1Y1Z1Z2 ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}((JAC)[8] = 	(  	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Z , 4 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ));
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
	double  Jx = 	(  grid_geo_x * 	(  	(  (if1_x2)[xyzx] - (if1_x1)[xyzx] ) * 	(  (f0_y2)[xyzy] * (f0_z2)[xyzz] ) ) ) ;
((shJ0)[	(  allidx + 	(  0 * 125 ) )] = 	(  (shJ0)[	(  allidx + 	(  0 * 125 ) )] + 	(  	(  Tori_X0 / 	(  Tori_X0 + 	(  XO + 	(  Bidx + xyzx ) ) ) ) * 	(  Charge0 * Jx ) ) ));
	double  Jy = 	(  grid_geo_y * 	(  	(  (if1_y2)[xyzy] - (if1_y1)[xyzy] ) * 	(  (f0_x1)[xyzx] * (f0_z2)[xyzz] ) ) ) ;
((shJ0)[	(  allidx + 	(  1 * 125 ) )] = 	(  (shJ0)[	(  allidx + 	(  1 * 125 ) )] + 	(  	(  	(  Tori_X0 + 	(  XO + 	(  Bidx + xyzx ) ) ) / Tori_X0 ) * 	(  Charge0 * Jy ) ) ));
	double  Jz = 	(  grid_geo_z * 	(  	(  (if1_z2)[xyzz] - (if1_z1)[xyzz] ) * 	(  (f0_x1)[xyzx] * (f0_y1)[xyzy] ) ) ) ;
((shJ0)[	(  allidx + 	(  2 * 125 ) )] = 	(  (shJ0)[	(  allidx + 	(  2 * 125 ) )] + 	(  	(  Tori_X0 / 	(  Tori_X0 + 	(  XO + 	(  Bidx + xyzx ) ) ) ) * 	(  Charge0 * Jz ) ) ));
}}}}}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  particle_head_general + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}0;
}}{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 375 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  375 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) ))[Gll_P9918] = (shJ0)[Gll_P9918]);
}}
	}else{
		0;

	 }
}(cur_frame_num = 	(  cur_frame_num + -1 ));
	goto 	* ( (call_stack_pointer)[cur_frame_num] );	beg_prog:
0;
	long  allgid = idy ;
	for (0 ; 	(  allgid < numvec ) ; (allgid = 	(  allgid + ylen )))
	{
	int  cu_load = (cu_xyzw)[	(  4 * allgid )] ;
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  idy = allgid ;
(load0 = 1);
(use_local_particle_position = 1);
(particle_head_general = 	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ));
(new_load = load0);
(call_sort = 0);
(global_idy_tmp = idy);

	 call_stack_pointer[cur_frame_num]=&&LAB_TMP5;
(cur_frame_num = 	(  cur_frame_num + 1 ));
	goto core_fun;
	LAB_TMP5:
0;
}}}(allgid = idy);
	for (0 ; 	(  allgid < numgrid_cu ) ; (allgid = 	(  allgid + ylen )))
	{
	int  new_load_tmp = (xyzw)[	(  4 * allgid )] ;
	long  idy = 	(  allgid / numgrid ) ;
	long  c_gid = 	(  allgid % numgrid ) ;
(cr_allgid = allgid);
(use_local_particle_position = 0);
(mdx = 	(  c_gid % XLEN ));
(mdy = 	(  	(  c_gid / XLEN ) % YLEN ));
(mdz = 	(  c_gid / 	(  XLEN * YLEN ) ));
(load0 = new_load_tmp);
(call_sort = 0);
(particle_head_general = 	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ));
(new_load = load0);
(global_idy_tmp = idy);

	 call_stack_pointer[cur_frame_num]=&&LAB_TMP6;
(cur_frame_num = 	(  cur_frame_num + 1 ));
	goto core_fun;
	LAB_TMP6:
0;
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  0 + allgid ) )] = new_load);

	}else{
		0;

	 }
}}
void  openmp_geo_rel_1st_bwd_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  LFoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
	int  call_sort = 1 ;
	int  cr_allgid = 0 ;
	int  use_local_particle_position = 1 ;
	int  mdx ;
	int  mdy ;
	int  mdz ;
	double   shB0  [375];	double   shB1  [375];	double   shE0  [375];	double   shJ0  [375];	double *  particle_head_general ;
	int  load0 ;
	int  new_load ;
	int  global_idy_tmp ;
	goto beg_prog;	core_fun:
{
	int  idy = global_idy_tmp ;
	if (  load0  ){  
			double  DELTAT = Deltat ;
	double  grid_geo_x = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_y = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_z = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  XO = (xoffset)[idy] ;
	int  Midx = 	openmp_mass_floorx ( (particle_head_general)[0] ) ;
	int  Midy = 	openmp_mass_floorx ( (particle_head_general)[1] ) ;
	int  Midz = 	openmp_mass_floorx ( (particle_head_general)[2] ) ;
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
		((	(  shJ0 + total_idx ))[ridx] = (	(  LFoutJ + 	(  	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) + 	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}}}{
	long  gMYGEN349 = 0 ;
	for (0 ; 	(  	(  gMYGEN349 + 	(  idx * 1 ) ) < load0 ) ; (gMYGEN349 = 	(  gMYGEN349 + 	(  1 * xlen ) )))
	{
	long  iba_tmp = 	(  	(  idx * 1 ) + gMYGEN349 ) ;
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
((	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  particle_head_general + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
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
	double  Midx0 = 	openmp_mass_floorx ( xx0 ) ;
	double  Midy0 = 	openmp_mass_floorx ( xy0 ) ;
	double  Midz0 = 	openmp_mass_floorx ( xz0 ) ;
	double  Midx1 = 	openmp_mass_floorx ( xx1 ) ;
	double  Midy1 = 	openmp_mass_floorx ( xy1 ) ;
	double  Midz1 = 	openmp_mass_floorx ( xz1 ) ;
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
}((	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[0] = 	(  	(  Charge * Ex1 ) + 	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ));
{
	double  B0z_intxX0Y1Z1X1 ;
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
(sum0 = 	(  sum0 + 	(  (shB0)[	(  	(  allidx * 3 ) + 2 )] * 	(  (f0_z1)[xyzz] * 	(  	(  (if1_x1)[xyzx] - (if1_x0)[xyzx] ) * (f1_y1)[xyzy] ) ) ) ));
}}}}}}(B0z_intxX0Y1Z1X1 = sum0);
}((	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[1] = 	(  	(  Charge * Ey1 ) + 	(  	(  -1.00000000000000000e+00 * 	(  Charge * 	(  	pow ( DELTAT , -1 ) * B0z_intxX0Y1Z1X1 ) ) ) + 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}{
	double  B0y_intxX0Y1Z1X1 ;
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
(sum0 = 	(  sum0 + 	(  (shB0)[	(  	(  allidx * 3 ) + 1 )] * 	(  (f0_y1)[xyzy] * 	(  	(  (if1_x1)[xyzx] - (if1_x0)[xyzx] ) * (f1_z1)[xyzz] ) ) ) ));
}}}}}}(B0y_intxX0Y1Z1X1 = sum0);
}	double  B0x_intyX0Y0Z1Y1 ;
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
(sum0 = 	(  sum0 + 	(  (shB0)[	(  	(  allidx * 3 ) + 0 )] * 	(  (f0_x0)[xyzx] * 	(  	(  (if1_y1)[xyzy] - (if1_y0)[xyzy] ) * (f1_z1)[xyzz] ) ) ) ));
}}}}}}(B0x_intyX0Y0Z1Y1 = sum0);
}((	(  a_f + 	(  	(  g % 1 ) * 3 ) ))[2] = 	(  	(  Charge * Ez1 ) + 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  	(  -1.00000000000000000e+00 * B0x_intyX0Y0Z1Y1 ) + B0y_intxX0Y1Z1X1 ) ) ) + 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X0 ) + X1 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X0 + X1 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y0 ) + Y1 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z0 ) + Z1 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}}}}{
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
	double  Midx0 = 	openmp_mass_floorx ( xx0 ) ;
	double  Midy0 = 	openmp_mass_floorx ( xy0 ) ;
	double  Midz0 = 	openmp_mass_floorx ( xz0 ) ;
	double  Midx1 = 	openmp_mass_floorx ( xx1 ) ;
	double  Midy1 = 	openmp_mass_floorx ( xy1 ) ;
	double  Midz1 = 	openmp_mass_floorx ( xz1 ) ;
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
	int  Midx2 = 	openmp_mass_floorx ( xx2 ) ;
	int  Midy2 = 	openmp_mass_floorx ( xy2 ) ;
	int  Midz2 = 	openmp_mass_floorx ( xz2 ) ;
	double  rx2 = 	(  xx2 - Midx2 ) ;
	double  ry2 = 	(  xy2 - Midy2 ) ;
	double  rz2 = 	(  xz2 - Midz2 ) ;
(RPL00 = 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ));
(RPL10 = 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ));
(RPL20 = 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * RPL10 ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) , 0.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * RPL10 ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ));
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
}{
	double  B1z_intyX1Y1Z2Y2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 2 )] * 	(  (f0_z2)[xyzz] * 	(  	(  (if1_y2)[xyzy] - (if1_y1)[xyzy] ) * (f1_x1)[xyzx] ) ) ) ));
}}}}}}(B1z_intyX1Y1Z2Y2 = sum0);
}	double  B1y_intzX1Y1Z1Z2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 1 )] * 	(  (f0_y1)[xyzy] * 	(  	(  (if1_z2)[xyzz] - (if1_z1)[xyzz] ) * (f1_x1)[xyzx] ) ) ) ));
}}}}}}(B1y_intzX1Y1Z1Z2 = sum0);
}((RES)[0] = 	(  	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  	(  -1.00000000000000000e+00 * B1y_intzX1Y1Z1Z2 ) + B1z_intyX1Y1Z2Y2 ) ) ) + 	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) + res_0 ));
}{
	double  B1x_intzX1Y1Z1Z2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 0 )] * 	(  (f0_x1)[xyzx] * 	(  	(  (if1_z2)[xyzz] - (if1_z1)[xyzz] ) * (f1_y1)[xyzy] ) ) ) ));
}}}}}}(B1x_intzX1Y1Z1Z2 = sum0);
}((RES)[1] = 	(  	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1x_intzX1Y1Z1Z2 ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + res_1 ));
}((RES)[2] = 	(  	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	pow ( Tori_X0 , -1 ) * 	(  	(  5.00000000000000000e-01 * 	(  X1 + X2 ) ) + XO ) ) ) , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) + res_2 ));
(maxerr = 0);
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
((JAC)[0] = 	(  	(  2.50000000000000000e-01 * 	(  Mass * 	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	pow ( DELTAT , -2 ) ) ) + 	(  -5.00000000000000000e-01 * 	(  	pow ( Tori_X0 , -2 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ));
((JAC)[1] = 	(  	(  5.00000000000000000e-01 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
((JAC)[2] = 	(  5.00000000000000000e-01 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
{
	double  B1z_inty_yX1Y1Z2Y2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 2 )] * 	(  (f0_z2)[xyzz] * 	(  (dif1_y2)[xyzy] * (f1_x1)[xyzx] ) ) ) ));
}}}}}}(B1z_inty_yX1Y1Z2Y2 = sum0);
}((JAC)[3] = 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1z_inty_yX1Y1Z2Y2 ) ) + 	(  	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}((JAC)[4] = 	(  	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 4 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( RPL00 , 4 ) * 	(  	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
((JAC)[5] = 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
{
	double  B1z_inty_zX1Y1Z2Y2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 2 )] * 	(  (df0_z2)[xyzz] * 	(  	(  (if1_y2)[xyzy] - (if1_y1)[xyzy] ) * (f1_x1)[xyzx] ) ) ) ));
}}}}}}(B1z_inty_zX1Y1Z2Y2 = sum0);
}	double  B1y_intz_zX1Y1Z1Z2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 1 )] * 	(  (f0_y1)[xyzy] * 	(  (dif1_z2)[xyzz] * (f1_x1)[xyzx] ) ) ) ));
}}}}}}(B1y_intz_zX1Y1Z1Z2 = sum0);
}((JAC)[6] = 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * 	(  	(  -1.00000000000000000e+00 * B1y_intz_zX1Y1Z1Z2 ) + B1z_inty_zX1Y1Z2Y2 ) ) ) + 	(  -5.00000000000000000e-01 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( Tori_X0 , -1 ) * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  RPL00 * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) ) ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}{
	double  B1x_intz_zX1Y1Z1Z2 ;
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
(sum0 = 	(  sum0 + 	(  (shB1)[	(  	(  allidx * 3 ) + 0 )] * 	(  (f0_x1)[xyzx] * 	(  (dif1_z2)[xyzz] * (f1_y1)[xyzy] ) ) ) ));
}}}}}}(B1x_intz_zX1Y1Z1Z2 = sum0);
}((JAC)[7] = 	(  	(  Charge * 	(  	pow ( DELTAT , -1 ) * B1x_intz_zX1Y1Z1Z2 ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( RPL00 , 2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) * 	(  	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
}((JAC)[8] = 	(  	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Z , 4 ) * 	(  	pow ( DELTAT , -4 ) * 	(  	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -2.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  Mass * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) , -1.00000000000000000e+00 ) * 	sqrt ( 	(  1.00000000000000000e+00 + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * X1 ) + X2 ) , 2 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Y , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	(  	pow ( RPL00 , 2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Y1 ) + Y2 ) , 2 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_Z , 2 ) * 	(  	pow ( DELTAT , -2 ) * 	pow ( 	(  	(  -1.00000000000000000e+00 * Z1 ) + Z2 ) , 2 ) ) ) ) ) ) ) ) ) ) ) ) ) ));
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
	double  Jx = 	(  grid_geo_x * 	(  	(  (if1_x2)[xyzx] - (if1_x1)[xyzx] ) * 	(  (f0_y2)[xyzy] * (f0_z2)[xyzz] ) ) ) ;
((shJ0)[	(  	(  3 * allidx ) + 0 )] = 	(  (shJ0)[	(  	(  3 * allidx ) + 0 )] + 	(  	(  Tori_X0 / 	(  Tori_X0 + 	(  XO + 	(  Bidx + xyzx ) ) ) ) * 	(  Charge0 * Jx ) ) ));
	double  Jy = 	(  grid_geo_y * 	(  	(  (if1_y2)[xyzy] - (if1_y1)[xyzy] ) * 	(  (f0_x1)[xyzx] * (f0_z2)[xyzz] ) ) ) ;
((shJ0)[	(  	(  3 * allidx ) + 1 )] = 	(  (shJ0)[	(  	(  3 * allidx ) + 1 )] + 	(  	(  	(  Tori_X0 + 	(  XO + 	(  Bidx + xyzx ) ) ) / Tori_X0 ) * 	(  Charge0 * Jy ) ) ));
	double  Jz = 	(  grid_geo_z * 	(  	(  (if1_z2)[xyzz] - (if1_z1)[xyzz] ) * 	(  (f0_x1)[xyzx] * (f0_y1)[xyzy] ) ) ) ;
((shJ0)[	(  	(  3 * allidx ) + 2 )] = 	(  (shJ0)[	(  	(  3 * allidx ) + 2 )] + 	(  	(  Tori_X0 / 	(  Tori_X0 + 	(  XO + 	(  Bidx + xyzx ) ) ) ) * 	(  Charge0 * Jz ) ) ));
}}}}}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  particle_head_general + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
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
((	(  LFoutJ + 	(  	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) + 	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) ) ))[Gll_P9918] = (	(  shJ0 + total_idx ))[Gll_P9918]);
}}}}}}}}
	}else{
		0;

	 }
}(cur_frame_num = 	(  cur_frame_num + -1 ));
	goto 	* ( (call_stack_pointer)[cur_frame_num] );	beg_prog:
0;
	long  allgid = idy ;
	for (0 ; 	(  allgid < numvec ) ; (allgid = 	(  allgid + ylen )))
	{
	int  cu_load = (cu_xyzw)[	(  4 * allgid )] ;
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  idy = allgid ;
(load0 = 1);
(use_local_particle_position = 1);
(particle_head_general = 	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ));
(new_load = load0);
(call_sort = 0);
(global_idy_tmp = idy);

	 call_stack_pointer[cur_frame_num]=&&LAB_TMP7;
(cur_frame_num = 	(  cur_frame_num + 1 ));
	goto core_fun;
	LAB_TMP7:
0;
}}}(allgid = idy);
	for (0 ; 	(  allgid < numgrid_cu ) ; (allgid = 	(  allgid + ylen )))
	{
	int  new_load_tmp = (xyzw)[	(  4 * allgid )] ;
	long  idy = 	(  allgid / numgrid ) ;
	long  c_gid = 	(  allgid % numgrid ) ;
(cr_allgid = allgid);
(use_local_particle_position = 0);
(mdx = 	(  c_gid % XLEN ));
(mdy = 	(  	(  c_gid / XLEN ) % YLEN ));
(mdz = 	(  c_gid / 	(  XLEN * YLEN ) ));
(load0 = new_load_tmp);
(call_sort = 0);
(particle_head_general = 	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ));
(new_load = load0);
(global_idy_tmp = idy);

	 call_stack_pointer[cur_frame_num]=&&LAB_TMP8;
(cur_frame_num = 	(  cur_frame_num + 1 ));
	goto core_fun;
	LAB_TMP8:
0;
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  0 + allgid ) )] = new_load);

	}else{
		0;

	 }
}}
void  openmp_relng_1st_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  LFoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
	int  call_sort = 1 ;
	int  cr_allgid = 0 ;
	int  use_local_particle_position = 1 ;
	int  mdx ;
	int  mdy ;
	int  mdz ;
	double   shB0  [375];	double   shB1  [375];	double   shE0  [375];	double   shJ0  [375];	double *  particle_head_general ;
	int  load0 ;
	int  new_load ;
	int  global_idy_tmp ;
	goto beg_prog;	core_fun:
{
	int  idy = global_idy_tmp ;
	if (  load0  ){  
			double  DELTAT = Deltat ;
	double  grid_geo_x = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_y = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_z = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  XO = (xoffset)[idy] ;
	int  Midx = 	openmp_mass_floorx ( (particle_head_general)[0] ) ;
	int  Midy = 	openmp_mass_floorx ( (particle_head_general)[1] ) ;
	int  Midz = 	openmp_mass_floorx ( (particle_head_general)[2] ) ;
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
}}}}}}}}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 375 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 375 )  ){  
		((shJ0)[ridx] = (	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  375 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}{
	long  gMYGEN362 = 0 ;
	for (0 ; 	(  	(  gMYGEN362 + 	(  idx * 1 ) ) < load0 ) ; (gMYGEN362 = 	(  gMYGEN362 + 	(  1 * xlen ) )))
	{
	long  iba_tmp = 	(  	(  idx * 1 ) + gMYGEN362 ) ;
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
((	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  particle_head_general + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
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
	double  Midx0 = 	openmp_mass_floorx ( xx0 ) ;
	double  Midy0 = 	openmp_mass_floorx ( xy0 ) ;
	double  Midz0 = 	openmp_mass_floorx ( xz0 ) ;
	double  Midx1 = 	openmp_mass_floorx ( xx1 ) ;
	double  Midy1 = 	openmp_mass_floorx ( xy1 ) ;
	double  Midz1 = 	openmp_mass_floorx ( xz1 ) ;
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
	double  Midx0 = 	openmp_mass_floorx ( xx0 ) ;
	double  Midy0 = 	openmp_mass_floorx ( xy0 ) ;
	double  Midz0 = 	openmp_mass_floorx ( xz0 ) ;
	double  Midx1 = 	openmp_mass_floorx ( xx1 ) ;
	double  Midy1 = 	openmp_mass_floorx ( xy1 ) ;
	double  Midz1 = 	openmp_mass_floorx ( xz1 ) ;
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
	int  Midx2 = 	openmp_mass_floorx ( xx2 ) ;
	int  Midy2 = 	openmp_mass_floorx ( xy2 ) ;
	int  Midz2 = 	openmp_mass_floorx ( xz2 ) ;
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
((shJ0)[	(  allidx + 	(  0 * 125 ) )] = 	(  (shJ0)[	(  allidx + 	(  0 * 125 ) )] + 	(  Charge0 * Jx ) ));
((shJ0)[	(  allidx + 	(  1 * 125 ) )] = 	(  (shJ0)[	(  allidx + 	(  1 * 125 ) )] + 	(  Charge0 * Jy ) ));
((shJ0)[	(  allidx + 	(  2 * 125 ) )] = 	(  (shJ0)[	(  allidx + 	(  2 * 125 ) )] + 	(  Charge0 * Jz ) ));
}}}}}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  particle_head_general + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}0;
}}{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 375 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  375 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) ))[Gll_P9918] = (shJ0)[Gll_P9918]);
}}
	}else{
		0;

	 }
}(cur_frame_num = 	(  cur_frame_num + -1 ));
	goto 	* ( (call_stack_pointer)[cur_frame_num] );	beg_prog:
0;
	long  allgid = idy ;
	for (0 ; 	(  allgid < numvec ) ; (allgid = 	(  allgid + ylen )))
	{
	int  cu_load = (cu_xyzw)[	(  4 * allgid )] ;
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  idy = allgid ;
(load0 = 1);
(use_local_particle_position = 1);
(particle_head_general = 	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ));
(new_load = load0);
(call_sort = 0);
(global_idy_tmp = idy);

	 call_stack_pointer[cur_frame_num]=&&LAB_TMP9;
(cur_frame_num = 	(  cur_frame_num + 1 ));
	goto core_fun;
	LAB_TMP9:
0;
}}}(allgid = idy);
	for (0 ; 	(  allgid < numgrid_cu ) ; (allgid = 	(  allgid + ylen )))
	{
	int  new_load_tmp = (xyzw)[	(  4 * allgid )] ;
	long  idy = 	(  allgid / numgrid ) ;
	long  c_gid = 	(  allgid % numgrid ) ;
(cr_allgid = allgid);
(use_local_particle_position = 0);
(mdx = 	(  c_gid % XLEN ));
(mdy = 	(  	(  c_gid / XLEN ) % YLEN ));
(mdz = 	(  c_gid / 	(  XLEN * YLEN ) ));
(load0 = new_load_tmp);
(call_sort = 0);
(particle_head_general = 	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ));
(new_load = load0);
(global_idy_tmp = idy);

	 call_stack_pointer[cur_frame_num]=&&LAB_TMP10;
(cur_frame_num = 	(  cur_frame_num + 1 ));
	goto core_fun;
	LAB_TMP10:
0;
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  0 + allgid ) )] = new_load);

	}else{
		0;

	 }
}}
void  openmp_relng_1st_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,int *  xoffset ,int *  yoffset ,int *  zoffset ,double *  fieldE ,double *  fieldB ,double *  fieldB1 ,double *  LFoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  Tori_X0 ,double  Solve_Err ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
	int  call_sort = 1 ;
	int  cr_allgid = 0 ;
	int  use_local_particle_position = 1 ;
	int  mdx ;
	int  mdy ;
	int  mdz ;
	double   shB0  [375];	double   shB1  [375];	double   shE0  [375];	double   shJ0  [375];	double *  particle_head_general ;
	int  load0 ;
	int  new_load ;
	int  global_idy_tmp ;
	goto beg_prog;	core_fun:
{
	int  idy = global_idy_tmp ;
	if (  load0  ){  
			double  DELTAT = Deltat ;
	double  grid_geo_x = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_y = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_z = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  XO = (xoffset)[idy] ;
	int  Midx = 	openmp_mass_floorx ( (particle_head_general)[0] ) ;
	int  Midy = 	openmp_mass_floorx ( (particle_head_general)[1] ) ;
	int  Midz = 	openmp_mass_floorx ( (particle_head_general)[2] ) ;
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
		((	(  shJ0 + total_idx ))[ridx] = (	(  LFoutJ + 	(  	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) + 	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}}}{
	long  gMYGEN375 = 0 ;
	for (0 ; 	(  	(  gMYGEN375 + 	(  idx * 1 ) ) < load0 ) ; (gMYGEN375 = 	(  gMYGEN375 + 	(  1 * xlen ) )))
	{
	long  iba_tmp = 	(  	(  idx * 1 ) + gMYGEN375 ) ;
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
((	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  particle_head_general + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
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
	double  Midx0 = 	openmp_mass_floorx ( xx0 ) ;
	double  Midy0 = 	openmp_mass_floorx ( xy0 ) ;
	double  Midz0 = 	openmp_mass_floorx ( xz0 ) ;
	double  Midx1 = 	openmp_mass_floorx ( xx1 ) ;
	double  Midy1 = 	openmp_mass_floorx ( xy1 ) ;
	double  Midz1 = 	openmp_mass_floorx ( xz1 ) ;
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
	double  Midx0 = 	openmp_mass_floorx ( xx0 ) ;
	double  Midy0 = 	openmp_mass_floorx ( xy0 ) ;
	double  Midz0 = 	openmp_mass_floorx ( xz0 ) ;
	double  Midx1 = 	openmp_mass_floorx ( xx1 ) ;
	double  Midy1 = 	openmp_mass_floorx ( xy1 ) ;
	double  Midz1 = 	openmp_mass_floorx ( xz1 ) ;
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
	int  Midx2 = 	openmp_mass_floorx ( xx2 ) ;
	int  Midy2 = 	openmp_mass_floorx ( xy2 ) ;
	int  Midz2 = 	openmp_mass_floorx ( xz2 ) ;
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
((	(  particle_head_general + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
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
((	(  LFoutJ + 	(  	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) + 	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) ) ))[Gll_P9918] = (	(  shJ0 + total_idx ))[Gll_P9918]);
}}}}}}}}
	}else{
		0;

	 }
}(cur_frame_num = 	(  cur_frame_num + -1 ));
	goto 	* ( (call_stack_pointer)[cur_frame_num] );	beg_prog:
0;
	long  allgid = idy ;
	for (0 ; 	(  allgid < numvec ) ; (allgid = 	(  allgid + ylen )))
	{
	int  cu_load = (cu_xyzw)[	(  4 * allgid )] ;
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  idy = allgid ;
(load0 = 1);
(use_local_particle_position = 1);
(particle_head_general = 	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ));
(new_load = load0);
(call_sort = 0);
(global_idy_tmp = idy);

	 call_stack_pointer[cur_frame_num]=&&LAB_TMP11;
(cur_frame_num = 	(  cur_frame_num + 1 ));
	goto core_fun;
	LAB_TMP11:
0;
}}}(allgid = idy);
	for (0 ; 	(  allgid < numgrid_cu ) ; (allgid = 	(  allgid + ylen )))
	{
	int  new_load_tmp = (xyzw)[	(  4 * allgid )] ;
	long  idy = 	(  allgid / numgrid ) ;
	long  c_gid = 	(  allgid % numgrid ) ;
(cr_allgid = allgid);
(use_local_particle_position = 0);
(mdx = 	(  c_gid % XLEN ));
(mdy = 	(  	(  c_gid / XLEN ) % YLEN ));
(mdz = 	(  c_gid / 	(  XLEN * YLEN ) ));
(load0 = new_load_tmp);
(call_sort = 0);
(particle_head_general = 	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ));
(new_load = load0);
(global_idy_tmp = idy);

	 call_stack_pointer[cur_frame_num]=&&LAB_TMP12;
(cur_frame_num = 	(  cur_frame_num + 1 ));
	goto core_fun;
	LAB_TMP12:
0;
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  0 + allgid ) )] = new_load);

	}else{
		0;

	 }
}}
