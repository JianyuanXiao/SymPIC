#include <omp.h> 
#include <math.h>

#include <math.h>
#include <assert.h>
#include <stdio.h>
#define IDX_OPT_MAX 1
#include <stdio.h>
void  openmp_split_pass_xyzE_particle_scmc_kernel (int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,int  N_l ,int  N_M ,int  push_J ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
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
	int  call_sort = 1 ;
	int  cr_allgid = 0 ;
	int  use_local_particle_position = 1 ;
	int  mdx ;
	int  mdy ;
	int  mdz ;
{
	long  load0 = cu_load ;
	const long  global_idy_tmp = idy ;
(use_local_particle_position = 1);
	if (  load0  ){  
		{
	long  g_inner ;
	for ((g_inner = 0) ; 	(  g_inner < load0 ) ; (g_inner = 	(  g_inner + 1 )))
	{
	double   local_particle_head  [6];{
	long  stmpg1 ;
	for ((stmpg1 = 0) ; 	(  stmpg1 < 6 ) ; (stmpg1 = 	(  stmpg1 + 1 )))
	{
((local_particle_head)[stmpg1] = (	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ))[	(  stmpg1 + 	(  g_inner * 6 ) )]);
}}((local_particle_head)[0] = 	(  (local_particle_head)[0] + -5.00000000000000000e-01 ));
((local_particle_head)[1] = 	(  (local_particle_head)[1] + -5.00000000000000000e-01 ));
((local_particle_head)[2] = 	(  (local_particle_head)[2] + -5.00000000000000000e-01 ));
	double  xx = (local_particle_head)[0] ;
	double  xy = (local_particle_head)[1] ;
	double  xz = (local_particle_head)[2] ;
	double  vx = (local_particle_head)[3] ;
	double  vy = (local_particle_head)[4] ;
	double  vz = (local_particle_head)[5] ;
	double  grid_geo_x = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_y = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_z = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double   localE  [192];	double   localJ  [375];	double   localB  [375];	int  Bidx = 	floor ( 	(  5.00000000000000000e-01 + xx ) ) ;
	int  Bidy = 	floor ( 	(  5.00000000000000000e-01 + xy ) ) ;
	int  Bidz = 	floor ( 	(  5.00000000000000000e-01 + xz ) ) ;
	if (  1  ){  
		{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	long  total_idx = 	(  iy + 	(  iz * 4 ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 	(  3 * 4 ) ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 	(  3 * 4 ) )  ){  
		((	(  localE + 	(  total_idx * 	(  4 * 3 ) ) ))[ridx] = (	(  fieldE + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  Bidx - 1 ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + 	(  Bidy + -1 ) ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + 	(  Bidz + -1 ) ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	double  QE_MASS = 	(  Charge0 / Mass0 ) ;
	double  rx = 	(  xx - Midx ) ;
	double  ry = 	(  xy - Midy ) ;
	double  rz = 	(  xz - Midz ) ;
	double   fEx  [4];	double   fEy  [4];	double   fEz  [4];	double   fdEx  [3];	double   fdEy  [3];	double   fdEz  [3];	double  AllEx = 0 ;
	double  AllEy = 0 ;
	double  AllEz = 0 ;
((fEx)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ));
((fEy)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fEz)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fEx)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) ) ) ) ));
((fEy)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fEz)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fEx)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ));
((fEy)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fEz)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fEx)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fEy)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fEz)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fdEx)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) ));
((fdEy)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fdEz)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fdEx)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) ) ));
((fdEy)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fdEz)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fdEx)[2] = 	(  5.00000000000000000e-01 * rx ));
((fdEy)[2] = 	(  5.00000000000000000e-01 * ry ));
((fdEz)[2] = 	(  5.00000000000000000e-01 * rz ));
{
	long  idz ;
	for ((idz = 0) ; 	(  idz < 4 ) ; (idz = 	(  idz + 1 )))
	{
{
	long  idy ;
	for ((idy = 0) ; 	(  idy < 4 ) ; (idy = 	(  idy + 1 )))
	{
{
	long  idx ;
	for ((idx = 0) ; 	(  idx < 3 ) ; (idx = 	(  idx + 1 )))
	{
(AllEx = 	(  AllEx + 	(  (localE)[	(  0 + 	(  3 * 	(  idx + 	(  4 * 	(  idy + 	(  idz * 4 ) ) ) ) ) )] * 	(  (fdEx)[idx] * 	(  (fEy)[idy] * (fEz)[idz] ) ) ) ));
(AllEy = 	(  AllEy + 	(  (localE)[	(  1 + 	(  3 * 	(  idz + 	(  4 * 	(  idx + 	(  idy * 4 ) ) ) ) ) )] * 	(  (fdEy)[idx] * 	(  (fEz)[idy] * (fEx)[idz] ) ) ) ));
(AllEz = 	(  AllEz + 	(  (localE)[	(  2 + 	(  3 * 	(  idy + 	(  4 * 	(  idz + 	(  idx * 4 ) ) ) ) ) )] * 	(  (fdEz)[idx] * 	(  (fEx)[idy] * (fEy)[idz] ) ) ) ));
}}}}}}	double  allincfvx ;
	double  allincfvy ;
	double  allincfvz ;
(allincfvx = 	(  	(  Deltat * 	(  N_l * 	(  QE_MASS * AllEx ) ) ) / 	(  DELTA_X * DELTA_X ) ));
(allincfvy = 	(  	(  Deltat * 	(  N_l * 	(  QE_MASS * AllEy ) ) ) / 	(  DELTA_Y * DELTA_Y ) ));
(allincfvz = 	(  	(  Deltat * 	(  N_l * 	(  QE_MASS * AllEz ) ) ) / 	(  DELTA_Z * DELTA_Z ) ));
((local_particle_head)[3] = 	(  (local_particle_head)[3] + allincfvx ));
((local_particle_head)[4] = 	(  (local_particle_head)[4] + allincfvy ));
((local_particle_head)[5] = 	(  (local_particle_head)[5] + allincfvz ));
}
	}else{
		0;

	 }
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	long  total_idx = 	(  iy + 	(  iz * 5 ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 	(  3 * 5 ) ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 	(  3 * 5 ) )  ){  
		((	(  localB + 	(  total_idx * 	(  5 * 3 ) ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  Bidx - 2 ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + 	(  Bidy + -2 ) ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + 	(  Bidz + -2 ) ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	long  total_idx = 	(  iy + 	(  iz * 5 ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 	(  3 * 5 ) ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 	(  3 * 5 ) )  ){  
		((	(  localJ + 	(  total_idx * 	(  5 * 3 ) ) ))[ridx] = (	(  FoutJ + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  Bidx - 2 ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + 	(  Bidy + -2 ) ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + 	(  Bidz + -2 ) ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}{
	long  i ;
	for ((i = 0) ; 	(  i < N_l ) ; (i = 	(  i + 1 )))
	{
	if (  	(  i == 0 )  ){  
		{
	double  grid_geo = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  xx = (local_particle_head)[0] ;
	double  xy = (local_particle_head)[1] ;
	double  xz = (local_particle_head)[2] ;
	int  rBidx = 	floor ( xx ) ;
	int  rBidy = 	floor ( xy ) ;
	int  rBidz = 	floor ( xz ) ;
	double  QE_MASS = 	(  Charge0 / Mass0 ) ;
	double  rx = 	(  xx - rBidx ) ;
	double  ry = 	(  xy - rBidy ) ;
	double  rz = 	(  xz - rBidz ) ;
	double  vx = (local_particle_head)[3] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [5];	double   fBy_z  [5];	double   fBz_z  [5];	double   fBz_y  [5];	double   fBy_x  [5];	double   fBy_xplus  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((fBy_y)[i] = 0);
((fBy_z)[i] = 0);
((fBz_z)[i] = 0);
((fBz_y)[i] = 0);
((fBy_x)[i] = 0);
((fBy_xplus)[i] = 0);
}}	double  xxplus ;
(xxplus = 	(  xx + 	(  	(  5.00000000000000000e-01 * Deltat ) * vx ) ));
	int  l_xoff = 	(  	floor ( xx ) - Bidx ) ;
	int  l_yoff = 	(  	floor ( xy ) - Bidy ) ;
	int  l_zoff = 	(  	floor ( xz ) - Bidz ) ;
	int  l_xplus_off = 	(  	floor ( xxplus ) - Bidx ) ;
((fBy_y)[	(  1 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[	(  2 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[	(  3 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[	(  4 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[	(  1 + l_zoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[	(  2 + l_zoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[	(  3 + l_zoff )] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[	(  1 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[	(  2 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[	(  3 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[	(  4 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[	(  1 + l_yoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[	(  2 + l_yoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[	(  3 + l_yoff )] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 1.00000000000000000e+00);
((fBy_x)[	(  1 + l_xoff )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[	(  2 + l_xoff )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[	(  3 + l_xoff )] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
	double  rx_plus = 	(  xxplus - 	floor ( xxplus ) ) ;
((fBy_xplus)[0] = 1.00000000000000000e+00);
((fBy_xplus)[1] = 1.00000000000000000e+00);
((fBy_xplus)[	(  1 + l_xplus_off )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx_plus ) ) , 2 ) ) ));
((fBy_xplus)[	(  2 + l_xplus_off )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx_plus ) + 	pow ( rx_plus , 2 ) ) ) ) ));
((fBy_xplus)[	(  3 + l_xplus_off )] = 	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ));
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
(Iby = 	(  Iby + 	(  (localB)[	(  1 + 	(  3 * 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzz] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (localB)[	(  2 + 	(  3 * 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBz_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge0 * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
((localJ)[	(  0 + 	(  3 * 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ) )] = 	(  (localJ)[	(  0 + 	(  3 * 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ) )] + Jx ));
}}}}}}}((local_particle_head)[5] = 	(  (local_particle_head)[5] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((local_particle_head)[4] = 	(  (local_particle_head)[4] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((local_particle_head)[0] = 	(  (local_particle_head)[0] + 	(  	(  5.00000000000000000e-01 * Deltat ) * vx ) ));
}
	}else{
		0;

	 }
{
	double  grid_geo = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	double  xx = (local_particle_head)[1] ;
	double  xy = (local_particle_head)[2] ;
	double  xz = (local_particle_head)[0] ;
	int  rBidx = 	floor ( xx ) ;
	int  rBidy = 	floor ( xy ) ;
	int  rBidz = 	floor ( xz ) ;
	double  QE_MASS = 	(  Charge0 / Mass0 ) ;
	double  rx = 	(  xx - rBidx ) ;
	double  ry = 	(  xy - rBidy ) ;
	double  rz = 	(  xz - rBidz ) ;
	double  vx = (local_particle_head)[4] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [5];	double   fBy_z  [5];	double   fBz_z  [5];	double   fBz_y  [5];	double   fBy_x  [5];	double   fBy_xplus  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((fBy_y)[i] = 0);
((fBy_z)[i] = 0);
((fBz_z)[i] = 0);
((fBz_y)[i] = 0);
((fBy_x)[i] = 0);
((fBy_xplus)[i] = 0);
}}	double  xxplus ;
(xxplus = 	(  xx + 	(  	(  5.00000000000000000e-01 * Deltat ) * vx ) ));
	int  l_xoff = 	(  	floor ( xx ) - Bidy ) ;
	int  l_yoff = 	(  	floor ( xy ) - Bidz ) ;
	int  l_zoff = 	(  	floor ( xz ) - Bidx ) ;
	int  l_xplus_off = 	(  	floor ( xxplus ) - Bidy ) ;
((fBy_y)[	(  1 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[	(  2 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[	(  3 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[	(  4 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[	(  1 + l_zoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[	(  2 + l_zoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[	(  3 + l_zoff )] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[	(  1 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[	(  2 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[	(  3 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[	(  4 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[	(  1 + l_yoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[	(  2 + l_yoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[	(  3 + l_yoff )] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 1.00000000000000000e+00);
((fBy_x)[	(  1 + l_xoff )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[	(  2 + l_xoff )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[	(  3 + l_xoff )] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
	double  rx_plus = 	(  xxplus - 	floor ( xxplus ) ) ;
((fBy_xplus)[0] = 1.00000000000000000e+00);
((fBy_xplus)[1] = 1.00000000000000000e+00);
((fBy_xplus)[	(  1 + l_xplus_off )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx_plus ) ) , 2 ) ) ));
((fBy_xplus)[	(  2 + l_xplus_off )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx_plus ) + 	pow ( rx_plus , 2 ) ) ) ) ));
((fBy_xplus)[	(  3 + l_xplus_off )] = 	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ));
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
(Iby = 	(  Iby + 	(  (localB)[	(  2 + 	(  3 * 	(  xyzz + 	(  5 * 	(  xyzx + 	(  5 * xyzy ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzz] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (localB)[	(  0 + 	(  3 * 	(  xyzz + 	(  5 * 	(  xyzx + 	(  5 * xyzy ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBz_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge0 * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
((localJ)[	(  1 + 	(  3 * 	(  xyzz + 	(  5 * 	(  xyzx + 	(  5 * xyzy ) ) ) ) ) )] = 	(  (localJ)[	(  1 + 	(  3 * 	(  xyzz + 	(  5 * 	(  xyzx + 	(  5 * xyzy ) ) ) ) ) )] + Jx ));
}}}}}}}((local_particle_head)[3] = 	(  (local_particle_head)[3] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((local_particle_head)[5] = 	(  (local_particle_head)[5] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((local_particle_head)[1] = 	(  (local_particle_head)[1] + 	(  	(  5.00000000000000000e-01 * Deltat ) * vx ) ));
}{
	double  grid_geo = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	double  xx = (local_particle_head)[2] ;
	double  xy = (local_particle_head)[0] ;
	double  xz = (local_particle_head)[1] ;
	int  rBidx = 	floor ( xx ) ;
	int  rBidy = 	floor ( xy ) ;
	int  rBidz = 	floor ( xz ) ;
	double  QE_MASS = 	(  Charge0 / Mass0 ) ;
	double  rx = 	(  xx - rBidx ) ;
	double  ry = 	(  xy - rBidy ) ;
	double  rz = 	(  xz - rBidz ) ;
	double  vx = (local_particle_head)[5] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [5];	double   fBy_z  [5];	double   fBz_z  [5];	double   fBz_y  [5];	double   fBy_x  [5];	double   fBy_xplus  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((fBy_y)[i] = 0);
((fBy_z)[i] = 0);
((fBz_z)[i] = 0);
((fBz_y)[i] = 0);
((fBy_x)[i] = 0);
((fBy_xplus)[i] = 0);
}}	double  xxplus ;
(xxplus = 	(  xx + 	(  	(  1 * Deltat ) * vx ) ));
	int  l_xoff = 	(  	floor ( xx ) - Bidz ) ;
	int  l_yoff = 	(  	floor ( xy ) - Bidx ) ;
	int  l_zoff = 	(  	floor ( xz ) - Bidy ) ;
	int  l_xplus_off = 	(  	floor ( xxplus ) - Bidz ) ;
((fBy_y)[	(  1 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[	(  2 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[	(  3 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[	(  4 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[	(  1 + l_zoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[	(  2 + l_zoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[	(  3 + l_zoff )] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[	(  1 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[	(  2 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[	(  3 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[	(  4 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[	(  1 + l_yoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[	(  2 + l_yoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[	(  3 + l_yoff )] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 1.00000000000000000e+00);
((fBy_x)[	(  1 + l_xoff )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[	(  2 + l_xoff )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[	(  3 + l_xoff )] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
	double  rx_plus = 	(  xxplus - 	floor ( xxplus ) ) ;
((fBy_xplus)[0] = 1.00000000000000000e+00);
((fBy_xplus)[1] = 1.00000000000000000e+00);
((fBy_xplus)[	(  1 + l_xplus_off )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx_plus ) ) , 2 ) ) ));
((fBy_xplus)[	(  2 + l_xplus_off )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx_plus ) + 	pow ( rx_plus , 2 ) ) ) ) ));
((fBy_xplus)[	(  3 + l_xplus_off )] = 	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ));
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
(Iby = 	(  Iby + 	(  (localB)[	(  0 + 	(  3 * 	(  xyzy + 	(  5 * 	(  xyzz + 	(  5 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzz] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (localB)[	(  1 + 	(  3 * 	(  xyzy + 	(  5 * 	(  xyzz + 	(  5 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBz_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge0 * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
((localJ)[	(  2 + 	(  3 * 	(  xyzy + 	(  5 * 	(  xyzz + 	(  5 * xyzx ) ) ) ) ) )] = 	(  (localJ)[	(  2 + 	(  3 * 	(  xyzy + 	(  5 * 	(  xyzz + 	(  5 * xyzx ) ) ) ) ) )] + Jx ));
}}}}}}}((local_particle_head)[4] = 	(  (local_particle_head)[4] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((local_particle_head)[3] = 	(  (local_particle_head)[3] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((local_particle_head)[2] = 	(  (local_particle_head)[2] + 	(  	(  1 * Deltat ) * vx ) ));
}{
	double  grid_geo = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	double  xx = (local_particle_head)[1] ;
	double  xy = (local_particle_head)[2] ;
	double  xz = (local_particle_head)[0] ;
	int  rBidx = 	floor ( xx ) ;
	int  rBidy = 	floor ( xy ) ;
	int  rBidz = 	floor ( xz ) ;
	double  QE_MASS = 	(  Charge0 / Mass0 ) ;
	double  rx = 	(  xx - rBidx ) ;
	double  ry = 	(  xy - rBidy ) ;
	double  rz = 	(  xz - rBidz ) ;
	double  vx = (local_particle_head)[4] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [5];	double   fBy_z  [5];	double   fBz_z  [5];	double   fBz_y  [5];	double   fBy_x  [5];	double   fBy_xplus  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((fBy_y)[i] = 0);
((fBy_z)[i] = 0);
((fBz_z)[i] = 0);
((fBz_y)[i] = 0);
((fBy_x)[i] = 0);
((fBy_xplus)[i] = 0);
}}	double  xxplus ;
(xxplus = 	(  xx + 	(  	(  5.00000000000000000e-01 * Deltat ) * vx ) ));
	int  l_xoff = 	(  	floor ( xx ) - Bidy ) ;
	int  l_yoff = 	(  	floor ( xy ) - Bidz ) ;
	int  l_zoff = 	(  	floor ( xz ) - Bidx ) ;
	int  l_xplus_off = 	(  	floor ( xxplus ) - Bidy ) ;
((fBy_y)[	(  1 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[	(  2 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[	(  3 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[	(  4 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[	(  1 + l_zoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[	(  2 + l_zoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[	(  3 + l_zoff )] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[	(  1 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[	(  2 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[	(  3 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[	(  4 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[	(  1 + l_yoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[	(  2 + l_yoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[	(  3 + l_yoff )] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 1.00000000000000000e+00);
((fBy_x)[	(  1 + l_xoff )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[	(  2 + l_xoff )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[	(  3 + l_xoff )] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
	double  rx_plus = 	(  xxplus - 	floor ( xxplus ) ) ;
((fBy_xplus)[0] = 1.00000000000000000e+00);
((fBy_xplus)[1] = 1.00000000000000000e+00);
((fBy_xplus)[	(  1 + l_xplus_off )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx_plus ) ) , 2 ) ) ));
((fBy_xplus)[	(  2 + l_xplus_off )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx_plus ) + 	pow ( rx_plus , 2 ) ) ) ) ));
((fBy_xplus)[	(  3 + l_xplus_off )] = 	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ));
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
(Iby = 	(  Iby + 	(  (localB)[	(  2 + 	(  3 * 	(  xyzz + 	(  5 * 	(  xyzx + 	(  5 * xyzy ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzz] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (localB)[	(  0 + 	(  3 * 	(  xyzz + 	(  5 * 	(  xyzx + 	(  5 * xyzy ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBz_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge0 * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
((localJ)[	(  1 + 	(  3 * 	(  xyzz + 	(  5 * 	(  xyzx + 	(  5 * xyzy ) ) ) ) ) )] = 	(  (localJ)[	(  1 + 	(  3 * 	(  xyzz + 	(  5 * 	(  xyzx + 	(  5 * xyzy ) ) ) ) ) )] + Jx ));
}}}}}}}((local_particle_head)[3] = 	(  (local_particle_head)[3] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((local_particle_head)[5] = 	(  (local_particle_head)[5] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((local_particle_head)[1] = 	(  (local_particle_head)[1] + 	(  	(  5.00000000000000000e-01 * Deltat ) * vx ) ));
}{
	double  grid_geo = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  xx = (local_particle_head)[0] ;
	double  xy = (local_particle_head)[1] ;
	double  xz = (local_particle_head)[2] ;
	int  rBidx = 	floor ( xx ) ;
	int  rBidy = 	floor ( xy ) ;
	int  rBidz = 	floor ( xz ) ;
	double  QE_MASS = 	(  Charge0 / Mass0 ) ;
	double  rx = 	(  xx - rBidx ) ;
	double  ry = 	(  xy - rBidy ) ;
	double  rz = 	(  xz - rBidz ) ;
	double  vx = (local_particle_head)[3] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [5];	double   fBy_z  [5];	double   fBz_z  [5];	double   fBz_y  [5];	double   fBy_x  [5];	double   fBy_xplus  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((fBy_y)[i] = 0);
((fBy_z)[i] = 0);
((fBz_z)[i] = 0);
((fBz_y)[i] = 0);
((fBy_x)[i] = 0);
((fBy_xplus)[i] = 0);
}}	double  xxplus ;
(xxplus = 	(  xx + 	(  	(  Deltat * ((	(  i == 	(  N_l - 1 ) ))?(5.00000000000000000e-01):(1)) ) * vx ) ));
	int  l_xoff = 	(  	floor ( xx ) - Bidx ) ;
	int  l_yoff = 	(  	floor ( xy ) - Bidy ) ;
	int  l_zoff = 	(  	floor ( xz ) - Bidz ) ;
	int  l_xplus_off = 	(  	floor ( xxplus ) - Bidx ) ;
((fBy_y)[	(  1 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[	(  2 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[	(  3 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[	(  4 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[	(  1 + l_zoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[	(  2 + l_zoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[	(  3 + l_zoff )] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[	(  1 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[	(  2 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[	(  3 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[	(  4 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[	(  1 + l_yoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[	(  2 + l_yoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[	(  3 + l_yoff )] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 1.00000000000000000e+00);
((fBy_x)[	(  1 + l_xoff )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[	(  2 + l_xoff )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[	(  3 + l_xoff )] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
	double  rx_plus = 	(  xxplus - 	floor ( xxplus ) ) ;
((fBy_xplus)[0] = 1.00000000000000000e+00);
((fBy_xplus)[1] = 1.00000000000000000e+00);
((fBy_xplus)[	(  1 + l_xplus_off )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx_plus ) ) , 2 ) ) ));
((fBy_xplus)[	(  2 + l_xplus_off )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx_plus ) + 	pow ( rx_plus , 2 ) ) ) ) ));
((fBy_xplus)[	(  3 + l_xplus_off )] = 	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ));
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
(Iby = 	(  Iby + 	(  (localB)[	(  1 + 	(  3 * 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzz] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (localB)[	(  2 + 	(  3 * 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBz_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge0 * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
((localJ)[	(  0 + 	(  3 * 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ) )] = 	(  (localJ)[	(  0 + 	(  3 * 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ) )] + Jx ));
}}}}}}}((local_particle_head)[5] = 	(  (local_particle_head)[5] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((local_particle_head)[4] = 	(  (local_particle_head)[4] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((local_particle_head)[0] = 	(  (local_particle_head)[0] + 	(  	(  Deltat * ((	(  i == 	(  N_l - 1 ) ))?(5.00000000000000000e-01):(1)) ) * vx ) ));
}}}}((local_particle_head)[0] = 	(  (local_particle_head)[0] + 5.00000000000000000e-01 ));
((local_particle_head)[1] = 	(  (local_particle_head)[1] + 5.00000000000000000e-01 ));
((local_particle_head)[2] = 	(  (local_particle_head)[2] + 5.00000000000000000e-01 ));
	if (  push_J  ){  
		{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	long  total_idx = 	(  iy + 	(  iz * 5 ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 	(  3 * 5 ) ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  FoutJ + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  Bidx - 2 ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + 	(  Bidy + -2 ) ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + 	(  Bidz + -2 ) ) + ovlp ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  localJ + 	(  total_idx * 	(  5 * 3 ) ) ))[Gll_P9918]);
}}}}}}
	}else{
		0;

	 }
}}
	}else{
		0;

	 }
}}
void  openmp_split_pass_xyzE_particle_push_r_scmc_kernel (int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,int  N_l ,int  N_M ,int  push_J ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
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
	int  call_sort = 1 ;
	int  cr_allgid = 0 ;
	int  use_local_particle_position = 1 ;
	int  mdx ;
	int  mdy ;
	int  mdz ;
{
	long  load0 = cu_load ;
	const long  global_idy_tmp = idy ;
(use_local_particle_position = 1);
	if (  load0  ){  
		{
	long  g_inner ;
	for ((g_inner = 0) ; 	(  g_inner < load0 ) ; (g_inner = 	(  g_inner + 1 )))
	{
	double   local_particle_head  [6];{
	long  stmpg1 ;
	for ((stmpg1 = 0) ; 	(  stmpg1 < 6 ) ; (stmpg1 = 	(  stmpg1 + 1 )))
	{
((local_particle_head)[stmpg1] = (	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ))[	(  stmpg1 + 	(  g_inner * 6 ) )]);
}}((local_particle_head)[0] = 	(  (local_particle_head)[0] + -5.00000000000000000e-01 ));
((local_particle_head)[1] = 	(  (local_particle_head)[1] + -5.00000000000000000e-01 ));
((local_particle_head)[2] = 	(  (local_particle_head)[2] + -5.00000000000000000e-01 ));
	double  xx = (local_particle_head)[0] ;
	double  xy = (local_particle_head)[1] ;
	double  xz = (local_particle_head)[2] ;
	double  vx = (local_particle_head)[3] ;
	double  vy = (local_particle_head)[4] ;
	double  vz = (local_particle_head)[5] ;
	double  grid_geo_x = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_y = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_z = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double   localE  [192];	double   localJ  [375];	double   localB  [375];	int  Bidx = 	floor ( 	(  5.00000000000000000e-01 + xx ) ) ;
	int  Bidy = 	floor ( 	(  5.00000000000000000e-01 + xy ) ) ;
	int  Bidz = 	floor ( 	(  5.00000000000000000e-01 + xz ) ) ;
	if (  1  ){  
		{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	long  total_idx = 	(  iy + 	(  iz * 4 ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 	(  3 * 4 ) ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 	(  3 * 4 ) )  ){  
		((	(  localE + 	(  total_idx * 	(  4 * 3 ) ) ))[ridx] = (	(  fieldE + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  Bidx - 1 ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + 	(  Bidy + -1 ) ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + 	(  Bidz + -1 ) ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	double  QE_MASS = 	(  Charge0 / Mass0 ) ;
	double  rx = 	(  xx - Midx ) ;
	double  ry = 	(  xy - Midy ) ;
	double  rz = 	(  xz - Midz ) ;
	double   fEx  [4];	double   fEy  [4];	double   fEz  [4];	double   fdEx  [3];	double   fdEy  [3];	double   fdEz  [3];	double  AllEx = 0 ;
	double  AllEy = 0 ;
	double  AllEz = 0 ;
((fEx)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ));
((fEy)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fEz)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fEx)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) ) ) ) ));
((fEy)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fEz)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fEx)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ));
((fEy)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fEz)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fEx)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fEy)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fEz)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fdEx)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) ));
((fdEy)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fdEz)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fdEx)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) ) ));
((fdEy)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fdEz)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fdEx)[2] = 	(  5.00000000000000000e-01 * rx ));
((fdEy)[2] = 	(  5.00000000000000000e-01 * ry ));
((fdEz)[2] = 	(  5.00000000000000000e-01 * rz ));
{
	long  idz ;
	for ((idz = 0) ; 	(  idz < 4 ) ; (idz = 	(  idz + 1 )))
	{
{
	long  idy ;
	for ((idy = 0) ; 	(  idy < 4 ) ; (idy = 	(  idy + 1 )))
	{
{
	long  idx ;
	for ((idx = 0) ; 	(  idx < 3 ) ; (idx = 	(  idx + 1 )))
	{
(AllEx = 	(  AllEx + 	(  (localE)[	(  0 + 	(  3 * 	(  idx + 	(  4 * 	(  idy + 	(  idz * 4 ) ) ) ) ) )] * 	(  (fdEx)[idx] * 	(  (fEy)[idy] * (fEz)[idz] ) ) ) ));
(AllEy = 	(  AllEy + 	(  (localE)[	(  1 + 	(  3 * 	(  idz + 	(  4 * 	(  idx + 	(  idy * 4 ) ) ) ) ) )] * 	(  (fdEy)[idx] * 	(  (fEz)[idy] * (fEx)[idz] ) ) ) ));
(AllEz = 	(  AllEz + 	(  (localE)[	(  2 + 	(  3 * 	(  idy + 	(  4 * 	(  idz + 	(  idx * 4 ) ) ) ) ) )] * 	(  (fdEz)[idx] * 	(  (fEx)[idy] * (fEy)[idz] ) ) ) ));
}}}}}}	double  allincfvx ;
	double  allincfvy ;
	double  allincfvz ;
(allincfvx = 	(  	(  Deltat * 	(  N_l * 	(  QE_MASS * AllEx ) ) ) / 	(  DELTA_X * DELTA_X ) ));
(allincfvy = 	(  	(  Deltat * 	(  N_l * 	(  QE_MASS * AllEy ) ) ) / 	(  DELTA_Y * DELTA_Y ) ));
(allincfvz = 	(  	(  Deltat * 	(  N_l * 	(  QE_MASS * AllEz ) ) ) / 	(  DELTA_Z * DELTA_Z ) ));
((local_particle_head)[3] = 	(  (local_particle_head)[3] + allincfvx ));
((local_particle_head)[4] = 	(  (local_particle_head)[4] + allincfvy ));
((local_particle_head)[5] = 	(  (local_particle_head)[5] + allincfvz ));
}
	}else{
		0;

	 }
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	long  total_idx = 	(  iy + 	(  iz * 5 ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 	(  3 * 5 ) ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 	(  3 * 5 ) )  ){  
		((	(  localB + 	(  total_idx * 	(  5 * 3 ) ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  Bidx - 2 ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + 	(  Bidy + -2 ) ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + 	(  Bidz + -2 ) ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	long  total_idx = 	(  iy + 	(  iz * 5 ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 	(  3 * 5 ) ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 	(  3 * 5 ) )  ){  
		((	(  localJ + 	(  total_idx * 	(  5 * 3 ) ) ))[ridx] = (	(  FoutJ + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  Bidx - 2 ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + 	(  Bidy + -2 ) ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + 	(  Bidz + -2 ) ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}{
	long  i ;
	for ((i = 0) ; 	(  i < N_l ) ; (i = 	(  i + 1 )))
	{
	if (  	(  i == 0 )  ){  
		{
	double  grid_geo = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  xx = (local_particle_head)[0] ;
	double  xy = (local_particle_head)[1] ;
	double  xz = (local_particle_head)[2] ;
	int  rBidx = 	floor ( xx ) ;
	int  rBidy = 	floor ( xy ) ;
	int  rBidz = 	floor ( xz ) ;
	double  QE_MASS = 	(  Charge0 / Mass0 ) ;
	double  rx = 	(  xx - rBidx ) ;
	double  ry = 	(  xy - rBidy ) ;
	double  rz = 	(  xz - rBidz ) ;
	double  vx = (local_particle_head)[3] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [5];	double   fBy_z  [5];	double   fBz_z  [5];	double   fBz_y  [5];	double   fBy_x  [5];	double   fBy_xplus  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((fBy_y)[i] = 0);
((fBy_z)[i] = 0);
((fBz_z)[i] = 0);
((fBz_y)[i] = 0);
((fBy_x)[i] = 0);
((fBy_xplus)[i] = 0);
}}	double  xxplus ;
(xxplus = 	(  xx + 	(  	(  5.00000000000000000e-01 * Deltat ) * vx ) ));
	int  l_xoff = 	(  	floor ( xx ) - Bidx ) ;
	int  l_yoff = 	(  	floor ( xy ) - Bidy ) ;
	int  l_zoff = 	(  	floor ( xz ) - Bidz ) ;
	int  l_xplus_off = 	(  	floor ( xxplus ) - Bidx ) ;
((fBy_y)[	(  1 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[	(  2 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[	(  3 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[	(  4 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[	(  1 + l_zoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[	(  2 + l_zoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[	(  3 + l_zoff )] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[	(  1 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[	(  2 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[	(  3 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[	(  4 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[	(  1 + l_yoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[	(  2 + l_yoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[	(  3 + l_yoff )] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 1.00000000000000000e+00);
((fBy_x)[	(  1 + l_xoff )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[	(  2 + l_xoff )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[	(  3 + l_xoff )] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
	double  rx_plus = 	(  xxplus - 	floor ( xxplus ) ) ;
((fBy_xplus)[0] = 1.00000000000000000e+00);
((fBy_xplus)[1] = 1.00000000000000000e+00);
((fBy_xplus)[	(  1 + l_xplus_off )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx_plus ) ) , 2 ) ) ));
((fBy_xplus)[	(  2 + l_xplus_off )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx_plus ) + 	pow ( rx_plus , 2 ) ) ) ) ));
((fBy_xplus)[	(  3 + l_xplus_off )] = 	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ));
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
(Iby = 	(  Iby + 	(  (localB)[	(  1 + 	(  3 * 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzz] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (localB)[	(  2 + 	(  3 * 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBz_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge0 * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
((localJ)[	(  0 + 	(  3 * 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ) )] = 	(  (localJ)[	(  0 + 	(  3 * 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ) )] + Jx ));
}}}}}}}((local_particle_head)[5] = 	(  (local_particle_head)[5] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((local_particle_head)[4] = 	(  (local_particle_head)[4] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((local_particle_head)[0] = 	(  (local_particle_head)[0] + 	(  	(  5.00000000000000000e-01 * Deltat ) * vx ) ));
}
	}else{
		0;

	 }
{
	double  grid_geo = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	double  xx = (local_particle_head)[1] ;
	double  xy = (local_particle_head)[2] ;
	double  xz = (local_particle_head)[0] ;
	int  rBidx = 	floor ( xx ) ;
	int  rBidy = 	floor ( xy ) ;
	int  rBidz = 	floor ( xz ) ;
	double  QE_MASS = 	(  Charge0 / Mass0 ) ;
	double  rx = 	(  xx - rBidx ) ;
	double  ry = 	(  xy - rBidy ) ;
	double  rz = 	(  xz - rBidz ) ;
	double  vx = (local_particle_head)[4] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [5];	double   fBy_z  [5];	double   fBz_z  [5];	double   fBz_y  [5];	double   fBy_x  [5];	double   fBy_xplus  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((fBy_y)[i] = 0);
((fBy_z)[i] = 0);
((fBz_z)[i] = 0);
((fBz_y)[i] = 0);
((fBy_x)[i] = 0);
((fBy_xplus)[i] = 0);
}}	double  xxplus ;
(xxplus = 	(  xx + 	(  	(  5.00000000000000000e-01 * Deltat ) * vx ) ));
	int  l_xoff = 	(  	floor ( xx ) - Bidy ) ;
	int  l_yoff = 	(  	floor ( xy ) - Bidz ) ;
	int  l_zoff = 	(  	floor ( xz ) - Bidx ) ;
	int  l_xplus_off = 	(  	floor ( xxplus ) - Bidy ) ;
((fBy_y)[	(  1 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[	(  2 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[	(  3 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[	(  4 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[	(  1 + l_zoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[	(  2 + l_zoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[	(  3 + l_zoff )] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[	(  1 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[	(  2 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[	(  3 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[	(  4 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[	(  1 + l_yoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[	(  2 + l_yoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[	(  3 + l_yoff )] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 1.00000000000000000e+00);
((fBy_x)[	(  1 + l_xoff )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[	(  2 + l_xoff )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[	(  3 + l_xoff )] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
	double  rx_plus = 	(  xxplus - 	floor ( xxplus ) ) ;
((fBy_xplus)[0] = 1.00000000000000000e+00);
((fBy_xplus)[1] = 1.00000000000000000e+00);
((fBy_xplus)[	(  1 + l_xplus_off )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx_plus ) ) , 2 ) ) ));
((fBy_xplus)[	(  2 + l_xplus_off )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx_plus ) + 	pow ( rx_plus , 2 ) ) ) ) ));
((fBy_xplus)[	(  3 + l_xplus_off )] = 	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ));
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
(Iby = 	(  Iby + 	(  (localB)[	(  2 + 	(  3 * 	(  xyzz + 	(  5 * 	(  xyzx + 	(  5 * xyzy ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzz] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (localB)[	(  0 + 	(  3 * 	(  xyzz + 	(  5 * 	(  xyzx + 	(  5 * xyzy ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBz_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge0 * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
((localJ)[	(  1 + 	(  3 * 	(  xyzz + 	(  5 * 	(  xyzx + 	(  5 * xyzy ) ) ) ) ) )] = 	(  (localJ)[	(  1 + 	(  3 * 	(  xyzz + 	(  5 * 	(  xyzx + 	(  5 * xyzy ) ) ) ) ) )] + Jx ));
}}}}}}}((local_particle_head)[3] = 	(  (local_particle_head)[3] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((local_particle_head)[5] = 	(  (local_particle_head)[5] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((local_particle_head)[1] = 	(  (local_particle_head)[1] + 	(  	(  5.00000000000000000e-01 * Deltat ) * vx ) ));
}{
	double  grid_geo = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	double  xx = (local_particle_head)[2] ;
	double  xy = (local_particle_head)[0] ;
	double  xz = (local_particle_head)[1] ;
	int  rBidx = 	floor ( xx ) ;
	int  rBidy = 	floor ( xy ) ;
	int  rBidz = 	floor ( xz ) ;
	double  QE_MASS = 	(  Charge0 / Mass0 ) ;
	double  rx = 	(  xx - rBidx ) ;
	double  ry = 	(  xy - rBidy ) ;
	double  rz = 	(  xz - rBidz ) ;
	double  vx = (local_particle_head)[5] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [5];	double   fBy_z  [5];	double   fBz_z  [5];	double   fBz_y  [5];	double   fBy_x  [5];	double   fBy_xplus  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((fBy_y)[i] = 0);
((fBy_z)[i] = 0);
((fBz_z)[i] = 0);
((fBz_y)[i] = 0);
((fBy_x)[i] = 0);
((fBy_xplus)[i] = 0);
}}	double  xxplus ;
(xxplus = 	(  xx + 	(  	(  1 * Deltat ) * vx ) ));
	int  l_xoff = 	(  	floor ( xx ) - Bidz ) ;
	int  l_yoff = 	(  	floor ( xy ) - Bidx ) ;
	int  l_zoff = 	(  	floor ( xz ) - Bidy ) ;
	int  l_xplus_off = 	(  	floor ( xxplus ) - Bidz ) ;
((fBy_y)[	(  1 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[	(  2 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[	(  3 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[	(  4 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[	(  1 + l_zoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[	(  2 + l_zoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[	(  3 + l_zoff )] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[	(  1 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[	(  2 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[	(  3 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[	(  4 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[	(  1 + l_yoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[	(  2 + l_yoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[	(  3 + l_yoff )] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 1.00000000000000000e+00);
((fBy_x)[	(  1 + l_xoff )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[	(  2 + l_xoff )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[	(  3 + l_xoff )] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
	double  rx_plus = 	(  xxplus - 	floor ( xxplus ) ) ;
((fBy_xplus)[0] = 1.00000000000000000e+00);
((fBy_xplus)[1] = 1.00000000000000000e+00);
((fBy_xplus)[	(  1 + l_xplus_off )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx_plus ) ) , 2 ) ) ));
((fBy_xplus)[	(  2 + l_xplus_off )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx_plus ) + 	pow ( rx_plus , 2 ) ) ) ) ));
((fBy_xplus)[	(  3 + l_xplus_off )] = 	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ));
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
(Iby = 	(  Iby + 	(  (localB)[	(  0 + 	(  3 * 	(  xyzy + 	(  5 * 	(  xyzz + 	(  5 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzz] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (localB)[	(  1 + 	(  3 * 	(  xyzy + 	(  5 * 	(  xyzz + 	(  5 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBz_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge0 * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
((localJ)[	(  2 + 	(  3 * 	(  xyzy + 	(  5 * 	(  xyzz + 	(  5 * xyzx ) ) ) ) ) )] = 	(  (localJ)[	(  2 + 	(  3 * 	(  xyzy + 	(  5 * 	(  xyzz + 	(  5 * xyzx ) ) ) ) ) )] + Jx ));
}}}}}}}((local_particle_head)[4] = 	(  (local_particle_head)[4] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((local_particle_head)[3] = 	(  (local_particle_head)[3] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((local_particle_head)[2] = 	(  (local_particle_head)[2] + 	(  	(  1 * Deltat ) * vx ) ));
}{
	double  grid_geo = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	double  xx = (local_particle_head)[1] ;
	double  xy = (local_particle_head)[2] ;
	double  xz = (local_particle_head)[0] ;
	int  rBidx = 	floor ( xx ) ;
	int  rBidy = 	floor ( xy ) ;
	int  rBidz = 	floor ( xz ) ;
	double  QE_MASS = 	(  Charge0 / Mass0 ) ;
	double  rx = 	(  xx - rBidx ) ;
	double  ry = 	(  xy - rBidy ) ;
	double  rz = 	(  xz - rBidz ) ;
	double  vx = (local_particle_head)[4] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [5];	double   fBy_z  [5];	double   fBz_z  [5];	double   fBz_y  [5];	double   fBy_x  [5];	double   fBy_xplus  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((fBy_y)[i] = 0);
((fBy_z)[i] = 0);
((fBz_z)[i] = 0);
((fBz_y)[i] = 0);
((fBy_x)[i] = 0);
((fBy_xplus)[i] = 0);
}}	double  xxplus ;
(xxplus = 	(  xx + 	(  	(  5.00000000000000000e-01 * Deltat ) * vx ) ));
	int  l_xoff = 	(  	floor ( xx ) - Bidy ) ;
	int  l_yoff = 	(  	floor ( xy ) - Bidz ) ;
	int  l_zoff = 	(  	floor ( xz ) - Bidx ) ;
	int  l_xplus_off = 	(  	floor ( xxplus ) - Bidy ) ;
((fBy_y)[	(  1 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[	(  2 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[	(  3 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[	(  4 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[	(  1 + l_zoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[	(  2 + l_zoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[	(  3 + l_zoff )] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[	(  1 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[	(  2 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[	(  3 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[	(  4 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[	(  1 + l_yoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[	(  2 + l_yoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[	(  3 + l_yoff )] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 1.00000000000000000e+00);
((fBy_x)[	(  1 + l_xoff )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[	(  2 + l_xoff )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[	(  3 + l_xoff )] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
	double  rx_plus = 	(  xxplus - 	floor ( xxplus ) ) ;
((fBy_xplus)[0] = 1.00000000000000000e+00);
((fBy_xplus)[1] = 1.00000000000000000e+00);
((fBy_xplus)[	(  1 + l_xplus_off )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx_plus ) ) , 2 ) ) ));
((fBy_xplus)[	(  2 + l_xplus_off )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx_plus ) + 	pow ( rx_plus , 2 ) ) ) ) ));
((fBy_xplus)[	(  3 + l_xplus_off )] = 	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ));
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
(Iby = 	(  Iby + 	(  (localB)[	(  2 + 	(  3 * 	(  xyzz + 	(  5 * 	(  xyzx + 	(  5 * xyzy ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzz] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (localB)[	(  0 + 	(  3 * 	(  xyzz + 	(  5 * 	(  xyzx + 	(  5 * xyzy ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBz_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge0 * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
((localJ)[	(  1 + 	(  3 * 	(  xyzz + 	(  5 * 	(  xyzx + 	(  5 * xyzy ) ) ) ) ) )] = 	(  (localJ)[	(  1 + 	(  3 * 	(  xyzz + 	(  5 * 	(  xyzx + 	(  5 * xyzy ) ) ) ) ) )] + Jx ));
}}}}}}}((local_particle_head)[3] = 	(  (local_particle_head)[3] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((local_particle_head)[5] = 	(  (local_particle_head)[5] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((local_particle_head)[1] = 	(  (local_particle_head)[1] + 	(  	(  5.00000000000000000e-01 * Deltat ) * vx ) ));
}{
	double  grid_geo = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  xx = (local_particle_head)[0] ;
	double  xy = (local_particle_head)[1] ;
	double  xz = (local_particle_head)[2] ;
	int  rBidx = 	floor ( xx ) ;
	int  rBidy = 	floor ( xy ) ;
	int  rBidz = 	floor ( xz ) ;
	double  QE_MASS = 	(  Charge0 / Mass0 ) ;
	double  rx = 	(  xx - rBidx ) ;
	double  ry = 	(  xy - rBidy ) ;
	double  rz = 	(  xz - rBidz ) ;
	double  vx = (local_particle_head)[3] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [5];	double   fBy_z  [5];	double   fBz_z  [5];	double   fBz_y  [5];	double   fBy_x  [5];	double   fBy_xplus  [5];{
	long  i ;
	for ((i = 0) ; 	(  i < 5 ) ; (i = 	(  i + 1 )))
	{
((fBy_y)[i] = 0);
((fBy_z)[i] = 0);
((fBz_z)[i] = 0);
((fBz_y)[i] = 0);
((fBy_x)[i] = 0);
((fBy_xplus)[i] = 0);
}}	double  xxplus ;
(xxplus = 	(  xx + 	(  	(  Deltat * ((	(  i == 	(  N_l - 1 ) ))?(5.00000000000000000e-01):(1)) ) * vx ) ));
	int  l_xoff = 	(  	floor ( xx ) - Bidx ) ;
	int  l_yoff = 	(  	floor ( xy ) - Bidy ) ;
	int  l_zoff = 	(  	floor ( xz ) - Bidz ) ;
	int  l_xplus_off = 	(  	floor ( xxplus ) - Bidx ) ;
((fBy_y)[	(  1 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[	(  2 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[	(  3 + l_yoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[	(  4 + l_yoff )] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[	(  1 + l_zoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[	(  2 + l_zoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[	(  3 + l_zoff )] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[	(  1 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[	(  2 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[	(  3 + l_zoff )] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[	(  4 + l_zoff )] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[	(  1 + l_yoff )] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[	(  2 + l_yoff )] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[	(  3 + l_yoff )] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 1.00000000000000000e+00);
((fBy_x)[	(  1 + l_xoff )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[	(  2 + l_xoff )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[	(  3 + l_xoff )] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
	double  rx_plus = 	(  xxplus - 	floor ( xxplus ) ) ;
((fBy_xplus)[0] = 1.00000000000000000e+00);
((fBy_xplus)[1] = 1.00000000000000000e+00);
((fBy_xplus)[	(  1 + l_xplus_off )] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx_plus ) ) , 2 ) ) ));
((fBy_xplus)[	(  2 + l_xplus_off )] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx_plus ) + 	pow ( rx_plus , 2 ) ) ) ) ));
((fBy_xplus)[	(  3 + l_xplus_off )] = 	(  2.50000000000000000e-01 * 	pow ( rx_plus , 2 ) ));
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
(Iby = 	(  Iby + 	(  (localB)[	(  1 + 	(  3 * 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzz] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (localB)[	(  2 + 	(  3 * 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBz_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge0 * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzx] - (fBy_x)[xyzx] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzz] ) ) ) ));
((localJ)[	(  0 + 	(  3 * 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ) )] = 	(  (localJ)[	(  0 + 	(  3 * 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ) )] + Jx ));
}}}}}}}((local_particle_head)[5] = 	(  (local_particle_head)[5] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((local_particle_head)[4] = 	(  (local_particle_head)[4] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((local_particle_head)[0] = 	(  (local_particle_head)[0] + 	(  	(  Deltat * ((	(  i == 	(  N_l - 1 ) ))?(5.00000000000000000e-01):(1)) ) * vx ) ));
}}}}((local_particle_head)[0] = 	(  (local_particle_head)[0] + 5.00000000000000000e-01 ));
((local_particle_head)[1] = 	(  (local_particle_head)[1] + 5.00000000000000000e-01 ));
((local_particle_head)[2] = 	(  (local_particle_head)[2] + 5.00000000000000000e-01 ));
	if (  push_J  ){  
		{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	long  total_idx = 	(  iy + 	(  iz * 5 ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 	(  3 * 5 ) ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  FoutJ + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  Bidx - 2 ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + 	(  Bidy + -2 ) ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + 	(  Bidz + -2 ) ) + ovlp ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  localJ + 	(  total_idx * 	(  5 * 3 ) ) ))[Gll_P9918]);
}}}}}}
	}else{
		0;

	 }
{
	long  stmpg1 ;
	for ((stmpg1 = 0) ; 	(  stmpg1 < 6 ) ; (stmpg1 = 	(  stmpg1 + 1 )))
	{
((	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ))[	(  stmpg1 + 	(  g_inner * 6 ) )] = (local_particle_head)[stmpg1]);
}}}}
	}else{
		0;

	 }
}}
