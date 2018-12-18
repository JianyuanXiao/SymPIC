
#include <math.h>
#include <assert.h>
#include <stdio.h>
#define IDX_OPT_MAX 1
#include <stdio.h>
double  c_rand01_k (double  x0 ,double  x1 ){
	return  0 ;}
double  c_maxwell_dist_k (double  ava ,double  sig ){
	return  0 ;}
void  c_split_pass_x_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	double   shBy  [60];	double   shBz  [60];	double   shJx  [80];	double   shJx_allidx  [	(  80 * 	(  IDX_OPT_MAX * 1 ) )];	double   ByzJxtmp  [	(  80 * 3 )];{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidx = 	floor ( xx ) ;
	int  Bidy = 	floor ( xy ) ;
	int  Bidz = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[1] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 5 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 5 ) ) ) * 3 ) ))[2]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[3] ;
	if (  	(  	(  Deltat * 	(  vx * 	(  Deltat * vx ) ) ) > 2.50000000000000000e-01 )  ){  
			fprintf ( stderr , "warning: vx=%e dt=%e\n" , vx , Deltat );

	}else{
		0;

	 }
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[0] = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 15 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
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
			double  grid_geo = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	int  lg ;
	double  xx = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidx = 	floor ( xx ) ;
	int  Bidy = 	floor ( xy ) ;
	int  Bidz = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[1] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 5 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 5 ) ) ) * 3 ) ))[2]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[3] ;
	if (  	(  	(  Deltat * 	(  vx * 	(  Deltat * vx ) ) ) > 2.50000000000000000e-01 )  ){  
			fprintf ( stderr , "warning: vx=%e dt=%e\n" , vx , Deltat );

	}else{
		0;

	 }
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[0] = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 15 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )] = new_load);

	}else{
		0;

	 }
}}}
void  c_split_pass_x_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	long  cu_offset = 	(  idy * numgrid ) ;
	long  xyzalllen = numgrid ;
	double   local_temp_particle_cache  [	(  768 * 6 )];	int   cu_xyzw_shared  [4];	double   shBy  [60];	double   shBz  [60];	double   shJx  [80];	double   shJx_allidx  [	(  80 * 	(  IDX_OPT_MAX * 1 ) )];	double   ByzJxtmp  [	(  80 * 3 )];{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidx = 	floor ( xx ) ;
	int  Bidy = 	floor ( xy ) ;
	int  Bidz = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[1] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 5 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 5 ) ) ) * 3 ) ))[2]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[3] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[0] = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 15 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
}}{
	double   local_pos_cache  [	(  64 * 6 )];	if (  	(  	(  idy < numvec ) && 	(  idx == 0 ) )  ){  
			int  cu_cur_cache_load = (cu_xyzw)[	(  4 * idy )] ;
{
	int  num_cur_load = 0 ;
	int  beg_to_left = 	(  	(  2 * cu_cache_length ) / 5 ) ;
	int  cur_to_left = beg_to_left ;
	int  cur_to_right = cu_cache_length ;
	int  cur_this = 0 ;
	int  lg ;
	int  g ;
	for (lg=0 ; 	(  lg < cu_cur_cache_load ) ; (lg = 	(  lg + 64 )))
	{
	long  num_read = ((	(  	(  lg + 64 ) > cu_cur_cache_load ))?(	(  cu_cur_cache_load - lg )):(64)) ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_read * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_pos_cache + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  lg * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	for (g=0 ; 	(  g < num_read ) ; g++)
	{
	int  gall = 	(  g + lg ) ;
	if (  	(  (	(  local_pos_cache + 	(  g * 6 ) ))[0] < 0 )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  cur_to_left * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  g * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(cur_to_left = 	(  cur_to_left + 1 ));

	}else{
			if (  	(  (	(  local_pos_cache + 	(  g * 6 ) ))[0] > XLEN )  ){  
		cur_to_right--;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  cur_to_right * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  g * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  cur_this * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  g * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(cur_this = 	(  cur_this + 1 ));

	 }

	 }
}}((cu_xyzw_shared)[0] = cur_this);
((cu_xyzw_shared)[1] = beg_to_left);
((cu_xyzw_shared)[2] = cur_to_left);
((cu_xyzw_shared)[3] = cur_to_right);
}
	}else{
		0;

	 }
	if (  	(  idy < numvec )  ){  
		{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 4 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  cu_xyzw + 	(  4 * idy ) ))[Gll_P9918] = (cu_xyzw_shared)[Gll_P9918]);
}}
	}else{
		0;

	 }
}{
	long  allgid ;
	for ((allgid = 0) ; 	(  allgid < numgrid ) ; (allgid = 	(  allgid + 1 )))
	{
	int  load0 = (xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )] ;
	int  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	int  lg ;
	double  xx = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidx = 	floor ( xx ) ;
	int  Bidy = 	floor ( xy ) ;
	int  Bidz = 	floor ( xz ) ;
	int  cur_cache_usage = 0 ;
	int  left_cache_usage = 0 ;
	int  right_cache_usage = 	(  768 - 1 ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[1] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 5 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 5 ) ) ) * 3 ) ))[2]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[3] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[0] = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] + 	(  Deltat * vx ) ));
	if (  	(  (	(  a_rva + 	(  g * 6 ) ))[0] < left_bound )  ){  
		{
	long  m ;
	for ((m = 0) ; 	(  m < 6 ) ; (m = 	(  m + 1 )))
	{
((	(  local_temp_particle_cache + 	(  left_cache_usage * 6 ) ))[m] = (	(  a_rva + 	(  g * 6 ) ))[m]);
}}(left_cache_usage = 	(  left_cache_usage + 1 ));

	}else{
			if (  	(  (	(  a_rva + 	(  g * 6 ) ))[0] > right_bound )  ){  
		{
	long  m ;
	for ((m = 0) ; 	(  m < 6 ) ; (m = 	(  m + 1 )))
	{
((	(  local_temp_particle_cache + 	(  right_cache_usage * 6 ) ))[m] = (	(  a_rva + 	(  g * 6 ) ))[m]);
}}(right_cache_usage = 	(  right_cache_usage + -1 ));

	}else{
			if (  	(  g != sort_cur )  ){  
		{
	long  m ;
	for ((m = 0) ; 	(  m < 6 ) ; (m = 	(  m + 1 )))
	{
((	(  a_rva + 	(  sort_cur * 6 ) ))[m] = (	(  a_rva + 	(  g * 6 ) ))[m]);
}}
	}else{
		0;

	 }
(sort_cur = 	(  sort_cur + 1 ));

	 }

	 }
}	if (  sort_cur  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  sort_cur * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  	(  6 * cur_cache_usage ) + 	(  lg * 0 ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(cur_cache_usage = 	(  cur_cache_usage + sort_cur ));

	}else{
		0;

	 }
}}	int  x_main = cur_cache_usage ;
	int  x_beg_minus = x_main ;
	int  x_beg_plus = 	(  	(  	(  grid_cache_len - load0 ) / 2 ) + 	(  left_cache_usage + x_main ) ) ;
	int  right_len = 	(  767 - right_cache_usage ) ;
	int   xm4  [4];((xm4)[0] = x_main);
((xm4)[1] = 	(  left_cache_usage + x_main ));
((xm4)[2] = x_beg_plus);
((xm4)[3] = 	(  right_len + x_beg_plus ));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 4 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  4 * 	(  cu_offset + allgid ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (xm4)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  left_cache_usage * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * x_beg_minus ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  right_len * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * x_beg_plus ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache + 	(  	(  right_cache_usage + 1 ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 15 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )] = new_load);

	}else{
		0;

	 }
}}}
void  c_split_pass_x_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	double   shBy  [60];	double   shBz  [60];	double   shJx  [125];	double   shJx_allidx  [	(  80 * 	(  IDX_OPT_MAX * 1 ) )];	double   ByzJxtmp  [	(  80 * 3 )];	long  allgid = idy ;
	for (0 ; 	(  allgid < numvec ) ; (allgid = 	(  allgid + ylen )))
	{
	int  cu_load = (cu_xyzw)[	(  4 * allgid )] ;
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	long  idy = allgid ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidx = 	floor ( xx ) ;
	int  Bidy = 	floor ( xy ) ;
	int  Bidz = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[1] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 5 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 5 ) ) ) * 3 ) ))[2]);
}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 125 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 125 )  ){  
		((shJx)[ridx] = (	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  375 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[3] ;
	if (  	(  	(  Deltat * 	(  vx * 	(  Deltat * vx ) ) ) > 2.50000000000000000e-01 )  ){  
			fprintf ( stderr , "warning: vx=%e dt=%e\n" , vx , Deltat );

	}else{
		0;

	 }
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[0] = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}	int  lidx = 	(  lg + idx ) ;
	long  bxyzx = 	(  lidx % 5 ) ;
	long  bxyzy = 	(  	(  lidx / 5 ) % 4 ) ;
	long  bxyzz = 	(  lidx / 	(  5 * 4 ) ) ;
(bxyzy = 	(  bxyzy + 1 ));
(bxyzz = 	(  bxyzz + 1 ));
	int  newidx = 	(  bxyzx + 	(  5 * 	(  bxyzy + 	(  5 * bxyzz ) ) ) ) ;
((shJx)[newidx] = 	(  (shJx)[newidx] + inctmp ));
}{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 125 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  375 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) ))[Gll_P9918] = (shJx)[Gll_P9918]);
}}
	}else{
		0;

	 }
}}}(allgid = idy);
	for (0 ; 	(  allgid < numgrid_cu ) ; (allgid = 	(  allgid + ylen )))
	{
	int  load0 = (xyzw)[	(  4 * allgid )] ;
	long  idy = 	(  allgid / numgrid ) ;
	int  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	int  lg ;
	double  xx = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidx = 	floor ( xx ) ;
	int  Bidy = 	floor ( xy ) ;
	int  Bidz = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[1] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 5 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 5 ) ) ) * 3 ) ))[2]);
}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 125 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 125 )  ){  
		((shJx)[ridx] = (	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  375 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[3] ;
	if (  	(  	(  Deltat * 	(  vx * 	(  Deltat * vx ) ) ) > 2.50000000000000000e-01 )  ){  
			fprintf ( stderr , "warning: vx=%e dt=%e\n" , vx , Deltat );

	}else{
		0;

	 }
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[0] = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}	int  lidx = 	(  lg + idx ) ;
	long  bxyzx = 	(  lidx % 5 ) ;
	long  bxyzy = 	(  	(  lidx / 5 ) % 4 ) ;
	long  bxyzz = 	(  lidx / 	(  5 * 4 ) ) ;
(bxyzy = 	(  bxyzy + 1 ));
(bxyzz = 	(  bxyzz + 1 ));
	int  newidx = 	(  bxyzx + 	(  5 * 	(  bxyzy + 	(  5 * bxyzz ) ) ) ) ;
((shJx)[newidx] = 	(  (shJx)[newidx] + inctmp ));
}{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 125 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  375 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) ))[Gll_P9918] = (shJx)[Gll_P9918]);
}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  0 + allgid ) )] = new_load);

	}else{
		0;

	 }
}}
void  c_split_pass_x_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	double   shBy  [60];	double   shBz  [60];	double   shJx  [125];	double   shJx_allidx  [	(  80 * 	(  IDX_OPT_MAX * 1 ) )];	double   ByzJxtmp  [	(  80 * 3 )];	long  allgid = idy ;
	for (0 ; 	(  allgid < numvec ) ; (allgid = 	(  allgid + ylen )))
	{
	int  cu_load = (cu_xyzw)[	(  4 * allgid )] ;
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	long  idy = allgid ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidx = 	floor ( xx ) ;
	int  Bidy = 	floor ( xy ) ;
	int  Bidz = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[1] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 5 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 5 ) ) ) * 3 ) ))[2]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[3] ;
	if (  	(  	(  Deltat * 	(  vx * 	(  Deltat * vx ) ) ) > 2.50000000000000000e-01 )  ){  
			fprintf ( stderr , "warning: vx=%e dt=%e\n" , vx , Deltat );

	}else{
		0;

	 }
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[0] = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 15 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
}}}(allgid = idy);
	for (0 ; 	(  allgid < numgrid_cu ) ; (allgid = 	(  allgid + ylen )))
	{
	int  load0 = (xyzw)[	(  4 * allgid )] ;
	long  idy = 	(  allgid / numgrid ) ;
	int  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	int  lg ;
	double  xx = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidx = 	floor ( xx ) ;
	int  Bidy = 	floor ( xy ) ;
	int  Bidz = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[1] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 5 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 5 ) ) ) * 3 ) ))[2]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[3] ;
	if (  	(  	(  Deltat * 	(  vx * 	(  Deltat * vx ) ) ) > 2.50000000000000000e-01 )  ){  
			fprintf ( stderr , "warning: vx=%e dt=%e\n" , vx , Deltat );

	}else{
		0;

	 }
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[0] = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 15 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  0 + allgid ) )] = new_load);

	}else{
		0;

	 }
}}
void  c_split_pass_x_vlo_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	double   shBy  [60];	double   shBz  [60];	double   shJx  [125];	double   shJx_allidx  [	(  80 * 	(  IDX_OPT_MAX * 1 ) )];	double   ByzJxtmp  [	(  80 * 3 )];	long  allgid = idy ;
	for (0 ; 	(  allgid < numvec ) ; (allgid = 	(  allgid + ylen )))
	{
	int  cu_load = (cu_xyzw)[	(  4 * allgid )] ;
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	long  idy = allgid ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidx = 	floor ( xx ) ;
	int  Bidy = 	floor ( xy ) ;
	int  Bidz = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[1] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 5 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 5 ) ) ) * 3 ) ))[2]);
}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 125 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 125 )  ){  
		((shJx)[ridx] = (	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  375 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[3] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[0] = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}	int  lidx = 	(  lg + idx ) ;
	long  bxyzx = 	(  lidx % 5 ) ;
	long  bxyzy = 	(  	(  lidx / 5 ) % 4 ) ;
	long  bxyzz = 	(  lidx / 	(  5 * 4 ) ) ;
(bxyzy = 	(  bxyzy + 1 ));
(bxyzz = 	(  bxyzz + 1 ));
	int  newidx = 	(  bxyzx + 	(  5 * 	(  bxyzy + 	(  5 * bxyzz ) ) ) ) ;
((shJx)[newidx] = 	(  (shJx)[newidx] + inctmp ));
}{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 125 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  375 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) ))[Gll_P9918] = (shJx)[Gll_P9918]);
}}
	}else{
		0;

	 }
}}}(allgid = idy);
	for (0 ; 	(  allgid < numgrid_cu ) ; (allgid = 	(  allgid + ylen )))
	{
	int  load0 = (xyzw)[	(  4 * allgid )] ;
	long  idy = 	(  allgid / numgrid ) ;
	int  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	int  lg ;
	double  xx = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidx = 	floor ( xx ) ;
	int  Bidy = 	floor ( xy ) ;
	int  Bidz = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[1] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 5 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 5 ) ) ) * 3 ) ))[2]);
}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 125 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 125 )  ){  
		((shJx)[ridx] = (	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  375 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[3] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[0] = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}	int  lidx = 	(  lg + idx ) ;
	long  bxyzx = 	(  lidx % 5 ) ;
	long  bxyzy = 	(  	(  lidx / 5 ) % 4 ) ;
	long  bxyzz = 	(  lidx / 	(  5 * 4 ) ) ;
(bxyzy = 	(  bxyzy + 1 ));
(bxyzz = 	(  bxyzz + 1 ));
	int  newidx = 	(  bxyzx + 	(  5 * 	(  bxyzy + 	(  5 * bxyzz ) ) ) ) ;
((shJx)[newidx] = 	(  (shJx)[newidx] + inctmp ));
}{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 125 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  375 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) ))[Gll_P9918] = (shJx)[Gll_P9918]);
}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  0 + allgid ) )] = new_load);

	}else{
		0;

	 }
}}
void  c_split_pass_x_vlo_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	long  cu_offset = 	(  idy * numgrid ) ;
	long  xyzalllen = numgrid ;
	double   local_temp_particle_cache  [	(  768 * 6 )];	int   cu_xyzw_shared  [4];	double   shBy  [60];	double   shBz  [60];	double   shJx  [80];	double   shJx_allidx  [	(  80 * 	(  IDX_OPT_MAX * 1 ) )];	double   ByzJxtmp  [	(  80 * 3 )];	long  allgid = idy ;
	for (0 ; 	(  allgid < numvec ) ; (allgid = 	(  allgid + ylen )))
	{
	int  cu_load = (cu_xyzw)[	(  4 * allgid )] ;
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	long  idy = allgid ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidx = 	floor ( xx ) ;
	int  Bidy = 	floor ( xy ) ;
	int  Bidz = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[1] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 5 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 5 ) ) ) * 3 ) ))[2]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[3] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[0] = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 15 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
}}}{
	double   local_pos_cache  [	(  64 * 6 )];	if (  	(  	(  idy < numvec ) && 	(  idx == 0 ) )  ){  
			int  cu_cur_cache_load = (cu_xyzw)[	(  4 * idy )] ;
{
	int  num_cur_load = 0 ;
	int  beg_to_left = 	(  	(  2 * cu_cache_length ) / 5 ) ;
	int  cur_to_left = beg_to_left ;
	int  cur_to_right = cu_cache_length ;
	int  cur_this = 0 ;
	int  lg ;
	int  g ;
	for (lg=0 ; 	(  lg < cu_cur_cache_load ) ; (lg = 	(  lg + 64 )))
	{
	long  num_read = ((	(  	(  lg + 64 ) > cu_cur_cache_load ))?(	(  cu_cur_cache_load - lg )):(64)) ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_read * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_pos_cache + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  lg * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	for (g=0 ; 	(  g < num_read ) ; g++)
	{
	int  gall = 	(  g + lg ) ;
	if (  	(  (	(  local_pos_cache + 	(  g * 6 ) ))[0] < 0 )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  cur_to_left * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  g * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(cur_to_left = 	(  cur_to_left + 1 ));

	}else{
			if (  	(  (	(  local_pos_cache + 	(  g * 6 ) ))[0] > XLEN )  ){  
		cur_to_right--;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  cur_to_right * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  g * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  cur_this * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  g * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(cur_this = 	(  cur_this + 1 ));

	 }

	 }
}}((cu_xyzw_shared)[0] = cur_this);
((cu_xyzw_shared)[1] = beg_to_left);
((cu_xyzw_shared)[2] = cur_to_left);
((cu_xyzw_shared)[3] = cur_to_right);
}
	}else{
		0;

	 }
	if (  	(  idy < numvec )  ){  
		{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 4 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  cu_xyzw + 	(  4 * idy ) ))[Gll_P9918] = (cu_xyzw_shared)[Gll_P9918]);
}}
	}else{
		0;

	 }
}(allgid = idy);
	for (0 ; 	(  allgid < numgrid_cu ) ; (allgid = 	(  allgid + ylen )))
	{
	int  load0 = (xyzw)[	(  4 * allgid )] ;
	long  idy = 	(  allgid / numgrid ) ;
	int  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_X / 	(  DELTA_Y * DELTA_Z ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	int  lg ;
	double  xx = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidx = 	floor ( xx ) ;
	int  Bidy = 	floor ( xy ) ;
	int  Bidz = 	floor ( xz ) ;
	int  cur_cache_usage = 0 ;
	int  left_cache_usage = 0 ;
	int  right_cache_usage = 	(  768 - 1 ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[1] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 5 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 5 ) ) ) * 3 ) ))[2]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 15 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 15 )  ){  
		((	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[ridx] = (	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[3] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[0] = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] + 	(  Deltat * vx ) ));
	if (  	(  (	(  a_rva + 	(  g * 6 ) ))[0] < left_bound )  ){  
		{
	long  m ;
	for ((m = 0) ; 	(  m < 6 ) ; (m = 	(  m + 1 )))
	{
((	(  local_temp_particle_cache + 	(  left_cache_usage * 6 ) ))[m] = (	(  a_rva + 	(  g * 6 ) ))[m]);
}}(left_cache_usage = 	(  left_cache_usage + 1 ));

	}else{
			if (  	(  (	(  a_rva + 	(  g * 6 ) ))[0] > right_bound )  ){  
		{
	long  m ;
	for ((m = 0) ; 	(  m < 6 ) ; (m = 	(  m + 1 )))
	{
((	(  local_temp_particle_cache + 	(  right_cache_usage * 6 ) ))[m] = (	(  a_rva + 	(  g * 6 ) ))[m]);
}}(right_cache_usage = 	(  right_cache_usage + -1 ));

	}else{
			if (  	(  g != sort_cur )  ){  
		{
	long  m ;
	for ((m = 0) ; 	(  m < 6 ) ; (m = 	(  m + 1 )))
	{
((	(  a_rva + 	(  sort_cur * 6 ) ))[m] = (	(  a_rva + 	(  g * 6 ) ))[m]);
}}
	}else{
		0;

	 }
(sort_cur = 	(  sort_cur + 1 ));

	 }

	 }
}	if (  sort_cur  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  sort_cur * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  	(  6 * cur_cache_usage ) + 	(  lg * 0 ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(cur_cache_usage = 	(  cur_cache_usage + sort_cur ));

	}else{
		0;

	 }
}}	int  x_main = cur_cache_usage ;
	int  x_beg_minus = x_main ;
	int  x_beg_plus = 	(  	(  	(  grid_cache_len - load0 ) / 2 ) + 	(  left_cache_usage + x_main ) ) ;
	int  right_len = 	(  767 - right_cache_usage ) ;
	int   xm4  [4];((xm4)[0] = x_main);
((xm4)[1] = 	(  left_cache_usage + x_main ));
((xm4)[2] = x_beg_plus);
((xm4)[3] = 	(  right_len + x_beg_plus ));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 4 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  4 * 	(  0 + allgid ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (xm4)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  left_cache_usage * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * x_beg_minus ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  right_len * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * x_beg_plus ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache + 	(  	(  right_cache_usage + 1 ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 1 ) + 	(  	(  bxyzy * 5 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 15 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidx ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  5 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  0 + allgid ) )] = new_load);

	}else{
		0;

	 }
}}
void  c_split_pass_y_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	double   shBy  [60];	double   shBz  [60];	double   shJx  [80];	double   shJx_allidx  [	(  80 * 	(  IDX_OPT_MAX * 1 ) )];	double   ByzJxtmp  [	(  80 * 3 )];{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidz = 	floor ( xx ) ;
	int  Bidx = 	floor ( xy ) ;
	int  Bidy = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  3 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 3 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[2] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 4 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 20 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[4] ;
	if (  	(  	(  Deltat * 	(  vx * 	(  Deltat * vx ) ) ) > 2.50000000000000000e-01 )  ){  
			fprintf ( stderr , "warning: vx=%e dt=%e\n" , vx , Deltat );

	}else{
		0;

	 }
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[1] = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 20 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 12 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
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
			double  grid_geo = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	int  lg ;
	double  xx = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidz = 	floor ( xx ) ;
	int  Bidx = 	floor ( xy ) ;
	int  Bidy = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  3 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 3 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[2] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 4 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 20 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[4] ;
	if (  	(  	(  Deltat * 	(  vx * 	(  Deltat * vx ) ) ) > 2.50000000000000000e-01 )  ){  
			fprintf ( stderr , "warning: vx=%e dt=%e\n" , vx , Deltat );

	}else{
		0;

	 }
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[1] = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 20 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 12 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )] = new_load);

	}else{
		0;

	 }
}}}
void  c_split_pass_y_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	long  cu_offset = 	(  idy * numgrid ) ;
	long  xyzalllen = numgrid ;
	double   local_temp_particle_cache  [	(  768 * 6 )];	int   cu_xyzw_shared  [4];	double   shBy  [60];	double   shBz  [60];	double   shJx  [80];	double   shJx_allidx  [	(  80 * 	(  IDX_OPT_MAX * 1 ) )];	double   ByzJxtmp  [	(  80 * 3 )];{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidz = 	floor ( xx ) ;
	int  Bidx = 	floor ( xy ) ;
	int  Bidy = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  3 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 3 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[2] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 4 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 20 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[4] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[1] = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 20 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 12 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
}}{
	double   local_pos_cache  [	(  64 * 6 )];	if (  	(  	(  idy < numvec ) && 	(  idx == 0 ) )  ){  
			int  cu_cur_cache_load = (cu_xyzw)[	(  4 * idy )] ;
{
	int  num_cur_load = 0 ;
	int  beg_to_left = 	(  	(  2 * cu_cache_length ) / 5 ) ;
	int  cur_to_left = beg_to_left ;
	int  cur_to_right = cu_cache_length ;
	int  cur_this = 0 ;
	int  lg ;
	int  g ;
	for (lg=0 ; 	(  lg < cu_cur_cache_load ) ; (lg = 	(  lg + 64 )))
	{
	long  num_read = ((	(  	(  lg + 64 ) > cu_cur_cache_load ))?(	(  cu_cur_cache_load - lg )):(64)) ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_read * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_pos_cache + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  lg * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	for (g=0 ; 	(  g < num_read ) ; g++)
	{
	int  gall = 	(  g + lg ) ;
	if (  	(  (	(  local_pos_cache + 	(  g * 6 ) ))[1] < 0 )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  cur_to_left * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  g * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(cur_to_left = 	(  cur_to_left + 1 ));

	}else{
			if (  	(  (	(  local_pos_cache + 	(  g * 6 ) ))[1] > YLEN )  ){  
		cur_to_right--;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  cur_to_right * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  g * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  cur_this * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  g * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(cur_this = 	(  cur_this + 1 ));

	 }

	 }
}}((cu_xyzw_shared)[0] = cur_this);
((cu_xyzw_shared)[1] = beg_to_left);
((cu_xyzw_shared)[2] = cur_to_left);
((cu_xyzw_shared)[3] = cur_to_right);
}
	}else{
		0;

	 }
	if (  	(  idy < numvec )  ){  
		{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 4 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  cu_xyzw + 	(  4 * idy ) ))[Gll_P9918] = (cu_xyzw_shared)[Gll_P9918]);
}}
	}else{
		0;

	 }
}{
	long  allgid ;
	for ((allgid = 0) ; 	(  allgid < numgrid ) ; (allgid = 	(  allgid + 1 )))
	{
	int  load0 = (xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )] ;
	int  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	int  lg ;
	double  xx = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidz = 	floor ( xx ) ;
	int  Bidx = 	floor ( xy ) ;
	int  Bidy = 	floor ( xz ) ;
	int  cur_cache_usage = 0 ;
	int  left_cache_usage = 0 ;
	int  right_cache_usage = 	(  768 - 1 ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  3 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 3 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[2] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 4 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 20 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[4] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[1] = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] + 	(  Deltat * vx ) ));
	if (  	(  (	(  a_rva + 	(  g * 6 ) ))[1] < left_bound )  ){  
		{
	long  m ;
	for ((m = 0) ; 	(  m < 6 ) ; (m = 	(  m + 1 )))
	{
((	(  local_temp_particle_cache + 	(  left_cache_usage * 6 ) ))[m] = (	(  a_rva + 	(  g * 6 ) ))[m]);
}}(left_cache_usage = 	(  left_cache_usage + 1 ));

	}else{
			if (  	(  (	(  a_rva + 	(  g * 6 ) ))[1] > right_bound )  ){  
		{
	long  m ;
	for ((m = 0) ; 	(  m < 6 ) ; (m = 	(  m + 1 )))
	{
((	(  local_temp_particle_cache + 	(  right_cache_usage * 6 ) ))[m] = (	(  a_rva + 	(  g * 6 ) ))[m]);
}}(right_cache_usage = 	(  right_cache_usage + -1 ));

	}else{
			if (  	(  g != sort_cur )  ){  
		{
	long  m ;
	for ((m = 0) ; 	(  m < 6 ) ; (m = 	(  m + 1 )))
	{
((	(  a_rva + 	(  sort_cur * 6 ) ))[m] = (	(  a_rva + 	(  g * 6 ) ))[m]);
}}
	}else{
		0;

	 }
(sort_cur = 	(  sort_cur + 1 ));

	 }

	 }
}	if (  sort_cur  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  sort_cur * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  	(  6 * cur_cache_usage ) + 	(  lg * 0 ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(cur_cache_usage = 	(  cur_cache_usage + sort_cur ));

	}else{
		0;

	 }
}}	int  x_main = cur_cache_usage ;
	int  x_beg_minus = x_main ;
	int  x_beg_plus = 	(  	(  	(  grid_cache_len - load0 ) / 2 ) + 	(  left_cache_usage + x_main ) ) ;
	int  right_len = 	(  767 - right_cache_usage ) ;
	int   xm4  [4];((xm4)[0] = x_main);
((xm4)[1] = 	(  left_cache_usage + x_main ));
((xm4)[2] = x_beg_plus);
((xm4)[3] = 	(  right_len + x_beg_plus ));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 4 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  4 * 	(  cu_offset + allgid ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (xm4)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  left_cache_usage * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * x_beg_minus ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  right_len * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * x_beg_plus ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache + 	(  	(  right_cache_usage + 1 ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 20 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 12 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )] = new_load);

	}else{
		0;

	 }
}}}
void  c_split_pass_y_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	double   shBy  [60];	double   shBz  [60];	double   shJx  [125];	double   shJx_allidx  [	(  80 * 	(  IDX_OPT_MAX * 1 ) )];	double   ByzJxtmp  [	(  80 * 3 )];	long  allgid = idy ;
	for (0 ; 	(  allgid < numvec ) ; (allgid = 	(  allgid + ylen )))
	{
	int  cu_load = (cu_xyzw)[	(  4 * allgid )] ;
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	long  idy = allgid ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidz = 	floor ( xx ) ;
	int  Bidx = 	floor ( xy ) ;
	int  Bidy = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  3 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 3 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[2] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 4 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 125 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 125 )  ){  
		((shJx)[ridx] = (	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  125 + 	(  375 * 	(  	(  Midz + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midx + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midy + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[4] ;
	if (  	(  	(  Deltat * 	(  vx * 	(  Deltat * vx ) ) ) > 2.50000000000000000e-01 )  ){  
			fprintf ( stderr , "warning: vx=%e dt=%e\n" , vx , Deltat );

	}else{
		0;

	 }
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[1] = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}	int  lidx = 	(  lg + idx ) ;
	long  bxyzx = 	(  lidx % 5 ) ;
	long  bxyzy = 	(  	(  lidx / 5 ) % 4 ) ;
	long  bxyzz = 	(  lidx / 	(  5 * 4 ) ) ;
(bxyzy = 	(  bxyzy + 1 ));
(bxyzz = 	(  bxyzz + 1 ));
	int  newidx = 	(  bxyzz + 	(  5 * 	(  bxyzx + 	(  5 * bxyzy ) ) ) ) ;
((shJx)[newidx] = 	(  (shJx)[newidx] + inctmp ));
}{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 125 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  125 + 	(  375 * 	(  	(  Midz + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midx + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midy + ovlp ) ) ) ) ) ) ) ) ))[Gll_P9918] = (shJx)[Gll_P9918]);
}}
	}else{
		0;

	 }
}}}(allgid = idy);
	for (0 ; 	(  allgid < numgrid_cu ) ; (allgid = 	(  allgid + ylen )))
	{
	int  load0 = (xyzw)[	(  4 * allgid )] ;
	long  idy = 	(  allgid / numgrid ) ;
	int  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	int  lg ;
	double  xx = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidz = 	floor ( xx ) ;
	int  Bidx = 	floor ( xy ) ;
	int  Bidy = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  3 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 3 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[2] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 4 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 125 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 125 )  ){  
		((shJx)[ridx] = (	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  125 + 	(  375 * 	(  	(  Midz + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midx + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midy + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[4] ;
	if (  	(  	(  Deltat * 	(  vx * 	(  Deltat * vx ) ) ) > 2.50000000000000000e-01 )  ){  
			fprintf ( stderr , "warning: vx=%e dt=%e\n" , vx , Deltat );

	}else{
		0;

	 }
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[1] = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}	int  lidx = 	(  lg + idx ) ;
	long  bxyzx = 	(  lidx % 5 ) ;
	long  bxyzy = 	(  	(  lidx / 5 ) % 4 ) ;
	long  bxyzz = 	(  lidx / 	(  5 * 4 ) ) ;
(bxyzy = 	(  bxyzy + 1 ));
(bxyzz = 	(  bxyzz + 1 ));
	int  newidx = 	(  bxyzz + 	(  5 * 	(  bxyzx + 	(  5 * bxyzy ) ) ) ) ;
((shJx)[newidx] = 	(  (shJx)[newidx] + inctmp ));
}{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 125 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  125 + 	(  375 * 	(  	(  Midz + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midx + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midy + ovlp ) ) ) ) ) ) ) ) ))[Gll_P9918] = (shJx)[Gll_P9918]);
}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  0 + allgid ) )] = new_load);

	}else{
		0;

	 }
}}
void  c_split_pass_y_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	double   shBy  [60];	double   shBz  [60];	double   shJx  [125];	double   shJx_allidx  [	(  80 * 	(  IDX_OPT_MAX * 1 ) )];	double   ByzJxtmp  [	(  80 * 3 )];	long  allgid = idy ;
	for (0 ; 	(  allgid < numvec ) ; (allgid = 	(  allgid + ylen )))
	{
	int  cu_load = (cu_xyzw)[	(  4 * allgid )] ;
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	long  idy = allgid ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidz = 	floor ( xx ) ;
	int  Bidx = 	floor ( xy ) ;
	int  Bidy = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  3 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 3 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[2] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 4 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 20 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[4] ;
	if (  	(  	(  Deltat * 	(  vx * 	(  Deltat * vx ) ) ) > 2.50000000000000000e-01 )  ){  
			fprintf ( stderr , "warning: vx=%e dt=%e\n" , vx , Deltat );

	}else{
		0;

	 }
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[1] = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 20 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 12 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
}}}(allgid = idy);
	for (0 ; 	(  allgid < numgrid_cu ) ; (allgid = 	(  allgid + ylen )))
	{
	int  load0 = (xyzw)[	(  4 * allgid )] ;
	long  idy = 	(  allgid / numgrid ) ;
	int  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	int  lg ;
	double  xx = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidz = 	floor ( xx ) ;
	int  Bidx = 	floor ( xy ) ;
	int  Bidy = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  3 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 3 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[2] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 4 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 20 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[4] ;
	if (  	(  	(  Deltat * 	(  vx * 	(  Deltat * vx ) ) ) > 2.50000000000000000e-01 )  ){  
			fprintf ( stderr , "warning: vx=%e dt=%e\n" , vx , Deltat );

	}else{
		0;

	 }
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[1] = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 20 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 12 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  0 + allgid ) )] = new_load);

	}else{
		0;

	 }
}}
void  c_split_pass_y_vlo_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	double   shBy  [60];	double   shBz  [60];	double   shJx  [125];	double   shJx_allidx  [	(  80 * 	(  IDX_OPT_MAX * 1 ) )];	double   ByzJxtmp  [	(  80 * 3 )];	long  allgid = idy ;
	for (0 ; 	(  allgid < numvec ) ; (allgid = 	(  allgid + ylen )))
	{
	int  cu_load = (cu_xyzw)[	(  4 * allgid )] ;
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	long  idy = allgid ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidz = 	floor ( xx ) ;
	int  Bidx = 	floor ( xy ) ;
	int  Bidy = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  3 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 3 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[2] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 4 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 125 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 125 )  ){  
		((shJx)[ridx] = (	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  125 + 	(  375 * 	(  	(  Midz + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midx + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midy + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[4] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[1] = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}	int  lidx = 	(  lg + idx ) ;
	long  bxyzx = 	(  lidx % 5 ) ;
	long  bxyzy = 	(  	(  lidx / 5 ) % 4 ) ;
	long  bxyzz = 	(  lidx / 	(  5 * 4 ) ) ;
(bxyzy = 	(  bxyzy + 1 ));
(bxyzz = 	(  bxyzz + 1 ));
	int  newidx = 	(  bxyzz + 	(  5 * 	(  bxyzx + 	(  5 * bxyzy ) ) ) ) ;
((shJx)[newidx] = 	(  (shJx)[newidx] + inctmp ));
}{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 125 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  125 + 	(  375 * 	(  	(  Midz + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midx + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midy + ovlp ) ) ) ) ) ) ) ) ))[Gll_P9918] = (shJx)[Gll_P9918]);
}}
	}else{
		0;

	 }
}}}(allgid = idy);
	for (0 ; 	(  allgid < numgrid_cu ) ; (allgid = 	(  allgid + ylen )))
	{
	int  load0 = (xyzw)[	(  4 * allgid )] ;
	long  idy = 	(  allgid / numgrid ) ;
	int  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	int  lg ;
	double  xx = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidz = 	floor ( xx ) ;
	int  Bidx = 	floor ( xy ) ;
	int  Bidy = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  3 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 3 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[2] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 4 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 125 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 125 )  ){  
		((shJx)[ridx] = (	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  125 + 	(  375 * 	(  	(  Midz + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midx + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midy + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[4] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[1] = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}	int  lidx = 	(  lg + idx ) ;
	long  bxyzx = 	(  lidx % 5 ) ;
	long  bxyzy = 	(  	(  lidx / 5 ) % 4 ) ;
	long  bxyzz = 	(  lidx / 	(  5 * 4 ) ) ;
(bxyzy = 	(  bxyzy + 1 ));
(bxyzz = 	(  bxyzz + 1 ));
	int  newidx = 	(  bxyzz + 	(  5 * 	(  bxyzx + 	(  5 * bxyzy ) ) ) ) ;
((shJx)[newidx] = 	(  (shJx)[newidx] + inctmp ));
}{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 125 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  125 + 	(  375 * 	(  	(  Midz + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midx + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midy + ovlp ) ) ) ) ) ) ) ) ))[Gll_P9918] = (shJx)[Gll_P9918]);
}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  0 + allgid ) )] = new_load);

	}else{
		0;

	 }
}}
void  c_split_pass_y_vlo_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	long  cu_offset = 	(  idy * numgrid ) ;
	long  xyzalllen = numgrid ;
	double   local_temp_particle_cache  [	(  768 * 6 )];	int   cu_xyzw_shared  [4];	double   shBy  [60];	double   shBz  [60];	double   shJx  [80];	double   shJx_allidx  [	(  80 * 	(  IDX_OPT_MAX * 1 ) )];	double   ByzJxtmp  [	(  80 * 3 )];	long  allgid = idy ;
	for (0 ; 	(  allgid < numvec ) ; (allgid = 	(  allgid + ylen )))
	{
	int  cu_load = (cu_xyzw)[	(  4 * allgid )] ;
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	long  idy = allgid ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidz = 	floor ( xx ) ;
	int  Bidx = 	floor ( xy ) ;
	int  Bidy = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  3 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 3 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[2] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 4 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 20 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[4] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[1] = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 20 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 12 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
}}}{
	double   local_pos_cache  [	(  64 * 6 )];	if (  	(  	(  idy < numvec ) && 	(  idx == 0 ) )  ){  
			int  cu_cur_cache_load = (cu_xyzw)[	(  4 * idy )] ;
{
	int  num_cur_load = 0 ;
	int  beg_to_left = 	(  	(  2 * cu_cache_length ) / 5 ) ;
	int  cur_to_left = beg_to_left ;
	int  cur_to_right = cu_cache_length ;
	int  cur_this = 0 ;
	int  lg ;
	int  g ;
	for (lg=0 ; 	(  lg < cu_cur_cache_load ) ; (lg = 	(  lg + 64 )))
	{
	long  num_read = ((	(  	(  lg + 64 ) > cu_cur_cache_load ))?(	(  cu_cur_cache_load - lg )):(64)) ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_read * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_pos_cache + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  lg * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	for (g=0 ; 	(  g < num_read ) ; g++)
	{
	int  gall = 	(  g + lg ) ;
	if (  	(  (	(  local_pos_cache + 	(  g * 6 ) ))[1] < 0 )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  cur_to_left * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  g * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(cur_to_left = 	(  cur_to_left + 1 ));

	}else{
			if (  	(  (	(  local_pos_cache + 	(  g * 6 ) ))[1] > YLEN )  ){  
		cur_to_right--;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  cur_to_right * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  g * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  cur_this * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  g * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(cur_this = 	(  cur_this + 1 ));

	 }

	 }
}}((cu_xyzw_shared)[0] = cur_this);
((cu_xyzw_shared)[1] = beg_to_left);
((cu_xyzw_shared)[2] = cur_to_left);
((cu_xyzw_shared)[3] = cur_to_right);
}
	}else{
		0;

	 }
	if (  	(  idy < numvec )  ){  
		{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 4 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  cu_xyzw + 	(  4 * idy ) ))[Gll_P9918] = (cu_xyzw_shared)[Gll_P9918]);
}}
	}else{
		0;

	 }
}(allgid = idy);
	for (0 ; 	(  allgid < numgrid_cu ) ; (allgid = 	(  allgid + ylen )))
	{
	int  load0 = (xyzw)[	(  4 * allgid )] ;
	long  idy = 	(  allgid / numgrid ) ;
	int  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Y / 	(  DELTA_Z * DELTA_X ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_Z * DELTA_Z ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	int  lg ;
	double  xx = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidz = 	floor ( xx ) ;
	int  Bidx = 	floor ( xy ) ;
	int  Bidy = 	floor ( xz ) ;
	int  cur_cache_usage = 0 ;
	int  left_cache_usage = 0 ;
	int  right_cache_usage = 	(  768 - 1 ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  3 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 3 ) + 	(  	(  bxyzy * 15 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[2] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 3 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 4 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 20 ) ) ) * 3 ) ))[0]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 20 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[4] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[1] = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] + 	(  Deltat * vx ) ));
	if (  	(  (	(  a_rva + 	(  g * 6 ) ))[1] < left_bound )  ){  
		{
	long  m ;
	for ((m = 0) ; 	(  m < 6 ) ; (m = 	(  m + 1 )))
	{
((	(  local_temp_particle_cache + 	(  left_cache_usage * 6 ) ))[m] = (	(  a_rva + 	(  g * 6 ) ))[m]);
}}(left_cache_usage = 	(  left_cache_usage + 1 ));

	}else{
			if (  	(  (	(  a_rva + 	(  g * 6 ) ))[1] > right_bound )  ){  
		{
	long  m ;
	for ((m = 0) ; 	(  m < 6 ) ; (m = 	(  m + 1 )))
	{
((	(  local_temp_particle_cache + 	(  right_cache_usage * 6 ) ))[m] = (	(  a_rva + 	(  g * 6 ) ))[m]);
}}(right_cache_usage = 	(  right_cache_usage + -1 ));

	}else{
			if (  	(  g != sort_cur )  ){  
		{
	long  m ;
	for ((m = 0) ; 	(  m < 6 ) ; (m = 	(  m + 1 )))
	{
((	(  a_rva + 	(  sort_cur * 6 ) ))[m] = (	(  a_rva + 	(  g * 6 ) ))[m]);
}}
	}else{
		0;

	 }
(sort_cur = 	(  sort_cur + 1 ));

	 }

	 }
}	if (  sort_cur  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  sort_cur * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  	(  6 * cur_cache_usage ) + 	(  lg * 0 ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(cur_cache_usage = 	(  cur_cache_usage + sort_cur ));

	}else{
		0;

	 }
}}	int  x_main = cur_cache_usage ;
	int  x_beg_minus = x_main ;
	int  x_beg_plus = 	(  	(  	(  grid_cache_len - load0 ) / 2 ) + 	(  left_cache_usage + x_main ) ) ;
	int  right_len = 	(  767 - right_cache_usage ) ;
	int   xm4  [4];((xm4)[0] = x_main);
((xm4)[1] = 	(  left_cache_usage + x_main ));
((xm4)[2] = x_beg_plus);
((xm4)[3] = 	(  right_len + x_beg_plus ));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 4 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  4 * 	(  0 + allgid ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (xm4)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  left_cache_usage * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * x_beg_minus ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  right_len * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * x_beg_plus ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache + 	(  	(  right_cache_usage + 1 ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 4 ) + 	(  	(  bxyzy * 20 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 4 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 5 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  5 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 12 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidz ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidx ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidy ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  0 + allgid ) )] = new_load);

	}else{
		0;

	 }
}}
void  c_split_pass_z_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	double   shBy  [60];	double   shBz  [60];	double   shJx  [80];	double   shJx_allidx  [	(  80 * 	(  IDX_OPT_MAX * 1 ) )];	double   ByzJxtmp  [	(  80 * 3 )];{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidy = 	floor ( xx ) ;
	int  Bidz = 	floor ( xy ) ;
	int  Bidx = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[0] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 3 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 3 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 16 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[2]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[5] ;
	if (  	(  	(  Deltat * 	(  vx * 	(  Deltat * vx ) ) ) > 2.50000000000000000e-01 )  ){  
			fprintf ( stderr , "warning: vx=%e dt=%e\n" , vx , Deltat );

	}else{
		0;

	 }
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[2] = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 16 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[2] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 12 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
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
			double  grid_geo = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	int  lg ;
	double  xx = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidy = 	floor ( xx ) ;
	int  Bidz = 	floor ( xy ) ;
	int  Bidx = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[0] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 3 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 3 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 16 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[2]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[5] ;
	if (  	(  	(  Deltat * 	(  vx * 	(  Deltat * vx ) ) ) > 2.50000000000000000e-01 )  ){  
			fprintf ( stderr , "warning: vx=%e dt=%e\n" , vx , Deltat );

	}else{
		0;

	 }
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[2] = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 16 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[2] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 12 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )] = new_load);

	}else{
		0;

	 }
}}}
void  c_split_pass_z_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	long  cu_offset = 	(  idy * numgrid ) ;
	long  xyzalllen = numgrid ;
	double   local_temp_particle_cache  [	(  768 * 6 )];	int   cu_xyzw_shared  [4];	double   shBy  [60];	double   shBz  [60];	double   shJx  [80];	double   shJx_allidx  [	(  80 * 	(  IDX_OPT_MAX * 1 ) )];	double   ByzJxtmp  [	(  80 * 3 )];{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidy = 	floor ( xx ) ;
	int  Bidz = 	floor ( xy ) ;
	int  Bidx = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[0] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 3 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 3 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 16 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[2]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[5] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[2] = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 16 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[2] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 12 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
}}{
	double   local_pos_cache  [	(  64 * 6 )];	if (  	(  	(  idy < numvec ) && 	(  idx == 0 ) )  ){  
			int  cu_cur_cache_load = (cu_xyzw)[	(  4 * idy )] ;
{
	int  num_cur_load = 0 ;
	int  beg_to_left = 	(  	(  2 * cu_cache_length ) / 5 ) ;
	int  cur_to_left = beg_to_left ;
	int  cur_to_right = cu_cache_length ;
	int  cur_this = 0 ;
	int  lg ;
	int  g ;
	for (lg=0 ; 	(  lg < cu_cur_cache_load ) ; (lg = 	(  lg + 64 )))
	{
	long  num_read = ((	(  	(  lg + 64 ) > cu_cur_cache_load ))?(	(  cu_cur_cache_load - lg )):(64)) ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_read * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_pos_cache + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  lg * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	for (g=0 ; 	(  g < num_read ) ; g++)
	{
	int  gall = 	(  g + lg ) ;
	if (  	(  (	(  local_pos_cache + 	(  g * 6 ) ))[2] < 0 )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  cur_to_left * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  g * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(cur_to_left = 	(  cur_to_left + 1 ));

	}else{
			if (  	(  (	(  local_pos_cache + 	(  g * 6 ) ))[2] > ZLEN )  ){  
		cur_to_right--;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  cur_to_right * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  g * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  cur_this * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  g * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(cur_this = 	(  cur_this + 1 ));

	 }

	 }
}}((cu_xyzw_shared)[0] = cur_this);
((cu_xyzw_shared)[1] = beg_to_left);
((cu_xyzw_shared)[2] = cur_to_left);
((cu_xyzw_shared)[3] = cur_to_right);
}
	}else{
		0;

	 }
	if (  	(  idy < numvec )  ){  
		{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 4 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  cu_xyzw + 	(  4 * idy ) ))[Gll_P9918] = (cu_xyzw_shared)[Gll_P9918]);
}}
	}else{
		0;

	 }
}{
	long  allgid ;
	for ((allgid = 0) ; 	(  allgid < numgrid ) ; (allgid = 	(  allgid + 1 )))
	{
	int  load0 = (xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )] ;
	int  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	int  lg ;
	double  xx = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidy = 	floor ( xx ) ;
	int  Bidz = 	floor ( xy ) ;
	int  Bidx = 	floor ( xz ) ;
	int  cur_cache_usage = 0 ;
	int  left_cache_usage = 0 ;
	int  right_cache_usage = 	(  768 - 1 ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[0] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 3 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 3 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 16 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[2]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[5] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[2] = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] + 	(  Deltat * vx ) ));
	if (  	(  (	(  a_rva + 	(  g * 6 ) ))[2] < left_bound )  ){  
		{
	long  m ;
	for ((m = 0) ; 	(  m < 6 ) ; (m = 	(  m + 1 )))
	{
((	(  local_temp_particle_cache + 	(  left_cache_usage * 6 ) ))[m] = (	(  a_rva + 	(  g * 6 ) ))[m]);
}}(left_cache_usage = 	(  left_cache_usage + 1 ));

	}else{
			if (  	(  (	(  a_rva + 	(  g * 6 ) ))[2] > right_bound )  ){  
		{
	long  m ;
	for ((m = 0) ; 	(  m < 6 ) ; (m = 	(  m + 1 )))
	{
((	(  local_temp_particle_cache + 	(  right_cache_usage * 6 ) ))[m] = (	(  a_rva + 	(  g * 6 ) ))[m]);
}}(right_cache_usage = 	(  right_cache_usage + -1 ));

	}else{
			if (  	(  g != sort_cur )  ){  
		{
	long  m ;
	for ((m = 0) ; 	(  m < 6 ) ; (m = 	(  m + 1 )))
	{
((	(  a_rva + 	(  sort_cur * 6 ) ))[m] = (	(  a_rva + 	(  g * 6 ) ))[m]);
}}
	}else{
		0;

	 }
(sort_cur = 	(  sort_cur + 1 ));

	 }

	 }
}	if (  sort_cur  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  sort_cur * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  	(  6 * cur_cache_usage ) + 	(  lg * 0 ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(cur_cache_usage = 	(  cur_cache_usage + sort_cur ));

	}else{
		0;

	 }
}}	int  x_main = cur_cache_usage ;
	int  x_beg_minus = x_main ;
	int  x_beg_plus = 	(  	(  	(  grid_cache_len - load0 ) / 2 ) + 	(  left_cache_usage + x_main ) ) ;
	int  right_len = 	(  767 - right_cache_usage ) ;
	int   xm4  [4];((xm4)[0] = x_main);
((xm4)[1] = 	(  left_cache_usage + x_main ));
((xm4)[2] = x_beg_plus);
((xm4)[3] = 	(  right_len + x_beg_plus ));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 4 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  4 * 	(  cu_offset + allgid ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (xm4)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  left_cache_usage * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * x_beg_minus ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  right_len * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * x_beg_plus ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache + 	(  	(  right_cache_usage + 1 ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 16 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[2] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 12 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  FoutJ + 	(  0 + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )] = new_load);

	}else{
		0;

	 }
}}}
void  c_split_pass_z_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	double   shBy  [60];	double   shBz  [60];	double   shJx  [125];	double   shJx_allidx  [	(  80 * 	(  IDX_OPT_MAX * 1 ) )];	double   ByzJxtmp  [	(  80 * 3 )];	long  allgid = idy ;
	for (0 ; 	(  allgid < numvec ) ; (allgid = 	(  allgid + ylen )))
	{
	int  cu_load = (cu_xyzw)[	(  4 * allgid )] ;
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	long  idy = allgid ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidy = 	floor ( xx ) ;
	int  Bidz = 	floor ( xy ) ;
	int  Bidx = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[0] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 3 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 3 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 125 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 125 )  ){  
		((shJx)[ridx] = (	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  250 + 	(  375 * 	(  	(  Midy + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midz + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midx + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[5] ;
	if (  	(  	(  Deltat * 	(  vx * 	(  Deltat * vx ) ) ) > 2.50000000000000000e-01 )  ){  
			fprintf ( stderr , "warning: vx=%e dt=%e\n" , vx , Deltat );

	}else{
		0;

	 }
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[2] = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}	int  lidx = 	(  lg + idx ) ;
	long  bxyzx = 	(  lidx % 5 ) ;
	long  bxyzy = 	(  	(  lidx / 5 ) % 4 ) ;
	long  bxyzz = 	(  lidx / 	(  5 * 4 ) ) ;
(bxyzy = 	(  bxyzy + 1 ));
(bxyzz = 	(  bxyzz + 1 ));
	int  newidx = 	(  bxyzy + 	(  5 * 	(  bxyzz + 	(  5 * bxyzx ) ) ) ) ;
((shJx)[newidx] = 	(  (shJx)[newidx] + inctmp ));
}{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 125 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  250 + 	(  375 * 	(  	(  Midy + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midz + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midx + ovlp ) ) ) ) ) ) ) ) ))[Gll_P9918] = (shJx)[Gll_P9918]);
}}
	}else{
		0;

	 }
}}}(allgid = idy);
	for (0 ; 	(  allgid < numgrid_cu ) ; (allgid = 	(  allgid + ylen )))
	{
	int  load0 = (xyzw)[	(  4 * allgid )] ;
	long  idy = 	(  allgid / numgrid ) ;
	int  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	int  lg ;
	double  xx = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidy = 	floor ( xx ) ;
	int  Bidz = 	floor ( xy ) ;
	int  Bidx = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[0] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 3 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 3 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 125 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 125 )  ){  
		((shJx)[ridx] = (	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  250 + 	(  375 * 	(  	(  Midy + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midz + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midx + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[5] ;
	if (  	(  	(  Deltat * 	(  vx * 	(  Deltat * vx ) ) ) > 2.50000000000000000e-01 )  ){  
			fprintf ( stderr , "warning: vx=%e dt=%e\n" , vx , Deltat );

	}else{
		0;

	 }
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[2] = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}	int  lidx = 	(  lg + idx ) ;
	long  bxyzx = 	(  lidx % 5 ) ;
	long  bxyzy = 	(  	(  lidx / 5 ) % 4 ) ;
	long  bxyzz = 	(  lidx / 	(  5 * 4 ) ) ;
(bxyzy = 	(  bxyzy + 1 ));
(bxyzz = 	(  bxyzz + 1 ));
	int  newidx = 	(  bxyzy + 	(  5 * 	(  bxyzz + 	(  5 * bxyzx ) ) ) ) ;
((shJx)[newidx] = 	(  (shJx)[newidx] + inctmp ));
}{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 125 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  250 + 	(  375 * 	(  	(  Midy + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midz + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midx + ovlp ) ) ) ) ) ) ) ) ))[Gll_P9918] = (shJx)[Gll_P9918]);
}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  0 + allgid ) )] = new_load);

	}else{
		0;

	 }
}}
void  c_split_pass_z_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	double   shBy  [60];	double   shBz  [60];	double   shJx  [125];	double   shJx_allidx  [	(  80 * 	(  IDX_OPT_MAX * 1 ) )];	double   ByzJxtmp  [	(  80 * 3 )];	long  allgid = idy ;
	for (0 ; 	(  allgid < numvec ) ; (allgid = 	(  allgid + ylen )))
	{
	int  cu_load = (cu_xyzw)[	(  4 * allgid )] ;
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	long  idy = allgid ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidy = 	floor ( xx ) ;
	int  Bidz = 	floor ( xy ) ;
	int  Bidx = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[0] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 3 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 3 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 16 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[2]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[5] ;
	if (  	(  	(  Deltat * 	(  vx * 	(  Deltat * vx ) ) ) > 2.50000000000000000e-01 )  ){  
			fprintf ( stderr , "warning: vx=%e dt=%e\n" , vx , Deltat );

	}else{
		0;

	 }
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[2] = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 16 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[2] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 12 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
}}}(allgid = idy);
	for (0 ; 	(  allgid < numgrid_cu ) ; (allgid = 	(  allgid + ylen )))
	{
	int  load0 = (xyzw)[	(  4 * allgid )] ;
	long  idy = 	(  allgid / numgrid ) ;
	int  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	int  lg ;
	double  xx = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidy = 	floor ( xx ) ;
	int  Bidz = 	floor ( xy ) ;
	int  Bidx = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[0] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 3 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 3 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 16 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[2]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[5] ;
	if (  	(  	(  Deltat * 	(  vx * 	(  Deltat * vx ) ) ) > 2.50000000000000000e-01 )  ){  
			fprintf ( stderr , "warning: vx=%e dt=%e\n" , vx , Deltat );

	}else{
		0;

	 }
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[2] = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 16 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[2] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 12 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  0 + allgid ) )] = new_load);

	}else{
		0;

	 }
}}
void  c_split_pass_z_vlo_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	double   shBy  [60];	double   shBz  [60];	double   shJx  [125];	double   shJx_allidx  [	(  80 * 	(  IDX_OPT_MAX * 1 ) )];	double   ByzJxtmp  [	(  80 * 3 )];	long  allgid = idy ;
	for (0 ; 	(  allgid < numvec ) ; (allgid = 	(  allgid + ylen )))
	{
	int  cu_load = (cu_xyzw)[	(  4 * allgid )] ;
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	long  idy = allgid ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidy = 	floor ( xx ) ;
	int  Bidz = 	floor ( xy ) ;
	int  Bidx = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[0] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 3 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 3 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 125 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 125 )  ){  
		((shJx)[ridx] = (	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  250 + 	(  375 * 	(  	(  Midy + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midz + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midx + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[5] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[2] = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}	int  lidx = 	(  lg + idx ) ;
	long  bxyzx = 	(  lidx % 5 ) ;
	long  bxyzy = 	(  	(  lidx / 5 ) % 4 ) ;
	long  bxyzz = 	(  lidx / 	(  5 * 4 ) ) ;
(bxyzy = 	(  bxyzy + 1 ));
(bxyzz = 	(  bxyzz + 1 ));
	int  newidx = 	(  bxyzy + 	(  5 * 	(  bxyzz + 	(  5 * bxyzx ) ) ) ) ;
((shJx)[newidx] = 	(  (shJx)[newidx] + inctmp ));
}{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 125 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  250 + 	(  375 * 	(  	(  Midy + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midz + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midx + ovlp ) ) ) ) ) ) ) ) ))[Gll_P9918] = (shJx)[Gll_P9918]);
}}
	}else{
		0;

	 }
}}}(allgid = idy);
	for (0 ; 	(  allgid < numgrid_cu ) ; (allgid = 	(  allgid + ylen )))
	{
	int  load0 = (xyzw)[	(  4 * allgid )] ;
	long  idy = 	(  allgid / numgrid ) ;
	int  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	int  lg ;
	double  xx = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidy = 	floor ( xx ) ;
	int  Bidz = 	floor ( xy ) ;
	int  Bidx = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[0] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 3 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 3 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 125 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 125 )  ){  
		((shJx)[ridx] = (	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  250 + 	(  375 * 	(  	(  Midy + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midz + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midx + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[5] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[2] = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}	int  lidx = 	(  lg + idx ) ;
	long  bxyzx = 	(  lidx % 5 ) ;
	long  bxyzy = 	(  	(  lidx / 5 ) % 4 ) ;
	long  bxyzz = 	(  lidx / 	(  5 * 4 ) ) ;
(bxyzy = 	(  bxyzy + 1 ));
(bxyzz = 	(  bxyzz + 1 ));
	int  newidx = 	(  bxyzy + 	(  5 * 	(  bxyzz + 	(  5 * bxyzx ) ) ) ) ;
((shJx)[newidx] = 	(  (shJx)[newidx] + inctmp ));
}{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 125 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  375 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  250 + 	(  375 * 	(  	(  Midy + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midz + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midx + ovlp ) ) ) ) ) ) ) ) ))[Gll_P9918] = (shJx)[Gll_P9918]);
}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  0 + allgid ) )] = new_load);

	}else{
		0;

	 }
}}
void  c_split_pass_z_vlo_sg2_small_grids_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  LFoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	long  cu_offset = 	(  idy * numgrid ) ;
	long  xyzalllen = numgrid ;
	double   local_temp_particle_cache  [	(  768 * 6 )];	int   cu_xyzw_shared  [4];	double   shBy  [60];	double   shBz  [60];	double   shJx  [80];	double   shJx_allidx  [	(  80 * 	(  IDX_OPT_MAX * 1 ) )];	double   ByzJxtmp  [	(  80 * 3 )];	long  allgid = idy ;
	for (0 ; 	(  allgid < numvec ) ; (allgid = 	(  allgid + ylen )))
	{
	int  cu_load = (cu_xyzw)[	(  4 * allgid )] ;
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	long  idy = allgid ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidy = 	floor ( xx ) ;
	int  Bidz = 	floor ( xy ) ;
	int  Bidx = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[0] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 3 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 3 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 16 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[2]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[5] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[2] = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] + 	(  Deltat * vx ) ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  allgid * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  6 * idx_all_base ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 16 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[2] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 12 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
}}}{
	double   local_pos_cache  [	(  64 * 6 )];	if (  	(  	(  idy < numvec ) && 	(  idx == 0 ) )  ){  
			int  cu_cur_cache_load = (cu_xyzw)[	(  4 * idy )] ;
{
	int  num_cur_load = 0 ;
	int  beg_to_left = 	(  	(  2 * cu_cache_length ) / 5 ) ;
	int  cur_to_left = beg_to_left ;
	int  cur_to_right = cu_cache_length ;
	int  cur_this = 0 ;
	int  lg ;
	int  g ;
	for (lg=0 ; 	(  lg < cu_cur_cache_load ) ; (lg = 	(  lg + 64 )))
	{
	long  num_read = ((	(  	(  lg + 64 ) > cu_cur_cache_load ))?(	(  cu_cur_cache_load - lg )):(64)) ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_read * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_pos_cache + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  lg * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	for (g=0 ; 	(  g < num_read ) ; g++)
	{
	int  gall = 	(  g + lg ) ;
	if (  	(  (	(  local_pos_cache + 	(  g * 6 ) ))[2] < 0 )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  cur_to_left * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  g * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(cur_to_left = 	(  cur_to_left + 1 ));

	}else{
			if (  	(  (	(  local_pos_cache + 	(  g * 6 ) ))[2] > ZLEN )  ){  
		cur_to_right--;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  cur_to_right * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  g * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  cur_this * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  g * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(cur_this = 	(  cur_this + 1 ));

	 }

	 }
}}((cu_xyzw_shared)[0] = cur_this);
((cu_xyzw_shared)[1] = beg_to_left);
((cu_xyzw_shared)[2] = cur_to_left);
((cu_xyzw_shared)[3] = cur_to_right);
}
	}else{
		0;

	 }
	if (  	(  idy < numvec )  ){  
		{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 4 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  cu_xyzw + 	(  4 * idy ) ))[Gll_P9918] = (cu_xyzw_shared)[Gll_P9918]);
}}
	}else{
		0;

	 }
}(allgid = idy);
	for (0 ; 	(  allgid < numgrid_cu ) ; (allgid = 	(  allgid + ylen )))
	{
	int  load0 = (xyzw)[	(  4 * allgid )] ;
	long  idy = 	(  allgid / numgrid ) ;
	int  new_load = load0 ;
	if (  load0  ){  
			double  grid_geo = 	(  DELTA_Z / 	(  DELTA_X * DELTA_Y ) ) ;
	double  grid_geo_py = 	(  1.00000000000000000e+00 / 	(  DELTA_X * DELTA_X ) ) ;
	double  grid_geo_pz = 	(  1.00000000000000000e+00 / 	(  DELTA_Y * DELTA_Y ) ) ;
	int  lg ;
	double  xx = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidy = 	floor ( xx ) ;
	int  Bidz = 	floor ( xy ) ;
	int  Bidx = 	floor ( xz ) ;
	int  cur_cache_usage = 0 ;
	int  left_cache_usage = 0 ;
	int  right_cache_usage = 	(  768 - 1 ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
	int  left_bound = Midx ;
	long  right_bound = 	(  left_bound + 1 ) ;
(Bidx = 	(  Bidx - 2 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
{
{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 3 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  3 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
	double  l1 = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[0] ;
((shBy)[total_idx] = l1);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 9 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 9 )  ){  
		((	(  ByzJxtmp + 	(  	(  total_idx * 3 ) * 3 ) ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 60 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shBz)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 12 ) + 	(  	(  bxyzy * 3 ) + 	(  bxyzz * 1 ) ) ) * 3 ) ))[1]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[ridx] = (	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((shJx)[total_idx] = (	(  ByzJxtmp + 	(  	(  	(  bxyzx * 16 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[2]);
}}	for (lg=0 ; 	(  lg < 	(  80 * 1 ) ) ; (lg = 	(  lg + 1 )))
	{
((shJx_allidx)[	(  	(  lg * IDX_OPT_MAX ) + idx )] = 0);
}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  sort_cur = 0 ;
{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midz ) ;
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[5] ;
	double  Iby = 0 ;
	double  Ibz = 0 ;
	double   fBy_y  [4];	double   fBy_z  [3];	double   fBz_z  [4];	double   fBz_y  [3];	double   fBy_x  [5];	double   fBy_xplus  [5];((fBy_y)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) ));
((fBy_y)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) ));
((fBy_y)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry ) + 	pow ( ry , 2 ) ) ) ));
((fBy_y)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry , 2 ) ));
((fBy_z)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ));
((fBy_z)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ));
((fBy_z)[2] = 	(  5.00000000000000000e-01 * rz ));
((fBz_z)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) ));
((fBz_z)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz ) ) ) ) ) ));
((fBz_z)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz ) + 	pow ( rz , 2 ) ) ) ));
((fBz_z)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz , 2 ) ));
((fBz_y)[0] = 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ));
((fBz_y)[1] = 	(  	(  2.50000000000000000e-01 * 	(  2.00000000000000000e+00 + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ) ) + 	(  5.00000000000000000e-01 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry ) ) ) ));
((fBz_y)[2] = 	(  5.00000000000000000e-01 * ry ));
((fBy_x)[0] = 1.00000000000000000e+00);
((fBy_x)[1] = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx ) ) , 2 ) ) ));
((fBy_x)[2] = 	(  	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx ) + 	pow ( rx , 2 ) ) ) ) ));
((fBy_x)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx , 2 ) ));
((fBy_x)[4] = 0.00000000000000000e+00);
	double  rxplus ;
(rxplus = 	(  rx + 	(  Deltat * vx ) ));
	double  rxplus_int = 	floor ( rxplus ) ;
(rxplus = 	(  rxplus - rxplus_int ));
	double  fByxplustmp0 ;
	double  fByxplustmp1 ;
	double  fByxplustmp2 ;
(fByxplustmp0 = 	(  1.00000000000000000e+00 + 	(  -2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rxplus ) ) , 2 ) ) ));
(fByxplustmp1 = 	(  	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ) + 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rxplus ) + 	pow ( rxplus , 2 ) ) ) ) ));
(fByxplustmp2 = 	(  2.50000000000000000e-01 * 	pow ( rxplus , 2 ) ));
	double  isrx_minus = ((	(  rxplus_int == -1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_zero = ((	(  rxplus_int == 0 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
	double  isrx_plus = ((	(  rxplus_int == 1 ))?(1.00000000000000000e+00):(0.00000000000000000e+00)) ;
((fBy_xplus)[0] = 	(  	(  isrx_minus * fByxplustmp0 ) + 	(  1.00000000000000000e+00 - isrx_minus ) ));
((fBy_xplus)[1] = 	(  	(  isrx_minus * fByxplustmp1 ) + 	(  	(  isrx_zero * fByxplustmp0 ) + isrx_plus ) ));
((fBy_xplus)[2] = 	(  	(  isrx_minus * fByxplustmp2 ) + 	(  	(  isrx_zero * fByxplustmp1 ) + 	(  isrx_plus * fByxplustmp0 ) ) ));
((fBy_xplus)[3] = 	(  	(  isrx_zero * fByxplustmp2 ) + 	(  isrx_plus * fByxplustmp1 ) ));
((fBy_xplus)[4] = 	(  isrx_plus * fByxplustmp2 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 5 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
(Iby = 	(  Iby + 	(  (shBy)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBy_z)[xyzx] ) ) ) ));
(Ibz = 	(  Ibz + 	(  (shBz)[	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) )] * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBz_z)[xyzy] * (fBz_y)[xyzx] ) ) ) ));
{
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}	int  xyzx = 3 ;
	double  Jx ;
(Jx = 	(  Charge * 	(  grid_geo * 	(  	(  (fBy_xplus)[xyzz] - (fBy_x)[xyzz] ) * 	(  (fBy_y)[xyzy] * (fBz_z)[xyzx] ) ) ) ));
((shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] = 	(  (shJx_allidx)[	(  	(  	(  	(  IDX_OPT_MAX * 	(  0 + 	(  1 * 	(  xyzz + 	(  5 * 	(  xyzy + 	(  4 * xyzx ) ) ) ) ) ) ) + idx ) * 1 ) + 	(  lg % 1 ) )] + Jx ));
}}}}((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + 	(  QE_MASS * 	(  	+ ( Iby ) * grid_geo_pz ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + 	(  QE_MASS * 	(  	- ( Ibz ) * grid_geo_py ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[2] = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] + 	(  Deltat * vx ) ));
	if (  	(  (	(  a_rva + 	(  g * 6 ) ))[2] < left_bound )  ){  
		{
	long  m ;
	for ((m = 0) ; 	(  m < 6 ) ; (m = 	(  m + 1 )))
	{
((	(  local_temp_particle_cache + 	(  left_cache_usage * 6 ) ))[m] = (	(  a_rva + 	(  g * 6 ) ))[m]);
}}(left_cache_usage = 	(  left_cache_usage + 1 ));

	}else{
			if (  	(  (	(  a_rva + 	(  g * 6 ) ))[2] > right_bound )  ){  
		{
	long  m ;
	for ((m = 0) ; 	(  m < 6 ) ; (m = 	(  m + 1 )))
	{
((	(  local_temp_particle_cache + 	(  right_cache_usage * 6 ) ))[m] = (	(  a_rva + 	(  g * 6 ) ))[m]);
}}(right_cache_usage = 	(  right_cache_usage + -1 ));

	}else{
			if (  	(  g != sort_cur )  ){  
		{
	long  m ;
	for ((m = 0) ; 	(  m < 6 ) ; (m = 	(  m + 1 )))
	{
((	(  a_rva + 	(  sort_cur * 6 ) ))[m] = (	(  a_rva + 	(  g * 6 ) ))[m]);
}}
	}else{
		0;

	 }
(sort_cur = 	(  sort_cur + 1 ));

	 }

	 }
}	if (  sort_cur  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  sort_cur * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  	(  6 * cur_cache_usage ) + 	(  lg * 0 ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(cur_cache_usage = 	(  cur_cache_usage + sort_cur ));

	}else{
		0;

	 }
}}	int  x_main = cur_cache_usage ;
	int  x_beg_minus = x_main ;
	int  x_beg_plus = 	(  	(  	(  grid_cache_len - load0 ) / 2 ) + 	(  left_cache_usage + x_main ) ) ;
	int  right_len = 	(  767 - right_cache_usage ) ;
	int   xm4  [4];((xm4)[0] = x_main);
((xm4)[1] = 	(  left_cache_usage + x_main ));
((xm4)[2] = x_beg_plus);
((xm4)[3] = 	(  right_len + x_beg_plus ));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 4 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  4 * 	(  0 + allgid ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (xm4)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  left_cache_usage * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * x_beg_minus ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  right_len * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  0 + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * x_beg_plus ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache + 	(  	(  right_cache_usage + 1 ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	for (lg=0 ; 	(  	(  lg + idx ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	double  inctmp = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  1 * IDX_OPT_MAX ) ) ; (i = 	(  i + 1 )))
	{
(inctmp = 	(  inctmp + (shJx_allidx)[	(  	(  	(  lg + idx ) * 	(  IDX_OPT_MAX * 1 ) ) + i )] ));
}}((shJx)[	(  lg + idx )] = 	(  (shJx)[	(  lg + idx )] + inctmp ));
}{
	int  lg ;
	for ((lg = 0) ; 	(  	(  idx + lg ) < 80 ) ; (lg = 	(  lg + xlen )))
	{
	int  total_idx = 	(  idx + lg ) ;
	long  bxyzx = 	(  total_idx % 5 ) ;
	long  bxyzy = 	(  	(  total_idx / 5 ) % 4 ) ;
	long  bxyzz = 	(  total_idx / 	(  5 * 4 ) ) ;
((	(  ByzJxtmp + 	(  	(  	(  bxyzx * 16 ) + 	(  	(  bxyzy * 1 ) + 	(  bxyzz * 4 ) ) ) * 3 ) ))[2] = (shJx)[total_idx]);
}{
	long  iz ;
	for ((iz = 0) ; 	(  iz < 5 ) ; (iz = 	(  iz + 1 )))
	{
{
	long  iy ;
	for ((iy = 0) ; 	(  iy < 4 ) ; (iy = 	(  iy + 1 )))
	{
	int  total_idx = 	(  iy + 	(  4 * iz ) ) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < 12 ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  LFoutJ + 	(  	(  num_ele * 	(  numallgrid * pscmc_compute_unit_id ) ) + 	(  	(  	(  num_ele * pscmc_num_compute_units ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  	(  0 + Bidy ) + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidz ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidx ) + ovlp ) ) ) ) ) ) ) ) ) ))[Gll_P9918] = (	(  ByzJxtmp + 	(  	(  4 * total_idx ) * 3 ) ))[Gll_P9918]);
}}}}}}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  0 + allgid ) )] = new_load);

	}else{
		0;

	 }
}}
void  c_split_pass_E_particle_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	double   shE  [192];{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	if (  load0  ){  
			int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidx = 	floor ( xx ) ;
	int  Bidy = 	floor ( xy ) ;
	int  Bidz = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
(Bidx = 	(  Bidx - 1 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
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
		((	(  shE + 	(  total_idx * 	(  3 * 4 ) ) ))[ridx] = (	(  fieldE + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midz ) ;
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
(AllEx = 	(  AllEx + 	(  (shE)[	(  0 + 	(  3 * 	(  idx + 	(  4 * 	(  idy + 	(  idz * 4 ) ) ) ) ) )] * 	(  (fdEx)[idx] * 	(  (fEy)[idy] * (fEz)[idz] ) ) ) ));
(AllEy = 	(  AllEy + 	(  (shE)[	(  1 + 	(  3 * 	(  idz + 	(  4 * 	(  idx + 	(  idy * 4 ) ) ) ) ) )] * 	(  (fdEy)[idx] * 	(  (fEz)[idy] * (fEx)[idz] ) ) ) ));
(AllEz = 	(  AllEz + 	(  (shE)[	(  2 + 	(  3 * 	(  idy + 	(  4 * 	(  idz + 	(  idx * 4 ) ) ) ) ) )] * 	(  (fdEz)[idx] * 	(  (fEx)[idy] * (fEy)[idz] ) ) ) ));
}}}}}}	double  allincfvx ;
	double  allincfvy ;
	double  allincfvz ;
(allincfvx = 	(  	(  Deltat * 	(  QE_MASS * AllEx ) ) / 	(  DELTA_X * DELTA_X ) ));
(allincfvy = 	(  	(  Deltat * 	(  QE_MASS * AllEy ) ) / 	(  DELTA_Y * DELTA_Y ) ));
(allincfvz = 	(  	(  Deltat * 	(  QE_MASS * AllEz ) ) / 	(  DELTA_Z * DELTA_Z ) ));
((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + allincfvx ));
((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + allincfvy ));
((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + allincfvz ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}
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
			int  lg ;
	double  xx = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidx = 	floor ( xx ) ;
	int  Bidy = 	floor ( xy ) ;
	int  Bidz = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
(Bidx = 	(  Bidx - 1 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
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
		((	(  shE + 	(  total_idx * 	(  3 * 4 ) ) ))[ridx] = (	(  fieldE + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midz ) ;
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
(AllEx = 	(  AllEx + 	(  (shE)[	(  0 + 	(  3 * 	(  idx + 	(  4 * 	(  idy + 	(  idz * 4 ) ) ) ) ) )] * 	(  (fdEx)[idx] * 	(  (fEy)[idy] * (fEz)[idz] ) ) ) ));
(AllEy = 	(  AllEy + 	(  (shE)[	(  1 + 	(  3 * 	(  idz + 	(  4 * 	(  idx + 	(  idy * 4 ) ) ) ) ) )] * 	(  (fdEy)[idx] * 	(  (fEz)[idy] * (fEx)[idz] ) ) ) ));
(AllEz = 	(  AllEz + 	(  (shE)[	(  2 + 	(  3 * 	(  idy + 	(  4 * 	(  idz + 	(  idx * 4 ) ) ) ) ) )] * 	(  (fdEz)[idx] * 	(  (fEx)[idy] * (fEy)[idz] ) ) ) ));
}}}}}}	double  allincfvx ;
	double  allincfvy ;
	double  allincfvz ;
(allincfvx = 	(  	(  Deltat * 	(  QE_MASS * AllEx ) ) / 	(  DELTA_X * DELTA_X ) ));
(allincfvy = 	(  	(  Deltat * 	(  QE_MASS * AllEy ) ) / 	(  DELTA_Y * DELTA_Y ) ));
(allincfvz = 	(  	(  Deltat * 	(  QE_MASS * AllEz ) ) / 	(  DELTA_Z * DELTA_Z ) ));
((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + allincfvx ));
((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + allincfvy ));
((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + allincfvz ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )] = new_load);

	}else{
		0;

	 }
}}}
void  c_split_pass_E_particle_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	double   shE  [192];{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	if (  load0  ){  
			int  lg ;
	double  xx = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidx = 	floor ( xx ) ;
	int  Bidy = 	floor ( xy ) ;
	int  Bidz = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
(Bidx = 	(  Bidx - 1 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
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
		((	(  shE + 	(  total_idx * 	(  3 * 4 ) ) ))[ridx] = (	(  fieldE + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midz ) ;
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
(AllEx = 	(  AllEx + 	(  (shE)[	(  0 + 	(  3 * 	(  idx + 	(  4 * 	(  idy + 	(  idz * 4 ) ) ) ) ) )] * 	(  (fdEx)[idx] * 	(  (fEy)[idy] * (fEz)[idz] ) ) ) ));
(AllEy = 	(  AllEy + 	(  (shE)[	(  1 + 	(  3 * 	(  idz + 	(  4 * 	(  idx + 	(  idy * 4 ) ) ) ) ) )] * 	(  (fdEy)[idx] * 	(  (fEz)[idy] * (fEx)[idz] ) ) ) ));
(AllEz = 	(  AllEz + 	(  (shE)[	(  2 + 	(  3 * 	(  idy + 	(  4 * 	(  idz + 	(  idx * 4 ) ) ) ) ) )] * 	(  (fdEz)[idx] * 	(  (fEx)[idy] * (fEy)[idz] ) ) ) ));
}}}}}}	double  allincfvx ;
	double  allincfvy ;
	double  allincfvz ;
(allincfvx = 	(  	(  Deltat * 	(  QE_MASS * AllEx ) ) / 	(  DELTA_X * DELTA_X ) ));
(allincfvy = 	(  	(  Deltat * 	(  QE_MASS * AllEy ) ) / 	(  DELTA_Y * DELTA_Y ) ));
(allincfvz = 	(  	(  Deltat * 	(  QE_MASS * AllEz ) ) / 	(  DELTA_Z * DELTA_Z ) ));
((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + allincfvx ));
((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + allincfvy ));
((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + allincfvz ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}
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
			int  lg ;
	double  xx = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  0 + 	(  0 * 6 ) )] ;
	double  xy = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  1 + 	(  0 * 6 ) )] ;
	double  xz = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[	(  2 + 	(  0 * 6 ) )] ;
	int  Bidx = 	floor ( xx ) ;
	int  Bidy = 	floor ( xy ) ;
	int  Bidz = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
(Bidx = 	(  Bidx - 1 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
	double  QE_MASS = 	(  Charge / Mass ) ;
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
		((	(  shE + 	(  total_idx * 	(  3 * 4 ) ) ))[ridx] = (	(  fieldE + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  iy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  iz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}	for (lg=0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	int  g = 0 ;
	double  rx = 	(  (	(  a_rva + 	(  g * 6 ) ))[0] - Midx ) ;
	double  ry = 	(  (	(  a_rva + 	(  g * 6 ) ))[1] - Midy ) ;
	double  rz = 	(  (	(  a_rva + 	(  g * 6 ) ))[2] - Midz ) ;
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
(AllEx = 	(  AllEx + 	(  (shE)[	(  0 + 	(  3 * 	(  idx + 	(  4 * 	(  idy + 	(  idz * 4 ) ) ) ) ) )] * 	(  (fdEx)[idx] * 	(  (fEy)[idy] * (fEz)[idz] ) ) ) ));
(AllEy = 	(  AllEy + 	(  (shE)[	(  1 + 	(  3 * 	(  idz + 	(  4 * 	(  idx + 	(  idy * 4 ) ) ) ) ) )] * 	(  (fdEy)[idx] * 	(  (fEz)[idy] * (fEx)[idz] ) ) ) ));
(AllEz = 	(  AllEz + 	(  (shE)[	(  2 + 	(  3 * 	(  idy + 	(  4 * 	(  idz + 	(  idx * 4 ) ) ) ) ) )] * 	(  (fdEz)[idx] * 	(  (fEx)[idy] * (fEy)[idz] ) ) ) ));
}}}}}}	double  allincfvx ;
	double  allincfvy ;
	double  allincfvz ;
(allincfvx = 	(  	(  Deltat * 	(  QE_MASS * AllEx ) ) / 	(  DELTA_X * DELTA_X ) ));
(allincfvy = 	(  	(  Deltat * 	(  QE_MASS * AllEy ) ) / 	(  DELTA_Y * DELTA_Y ) ));
(allincfvz = 	(  	(  Deltat * 	(  QE_MASS * AllEz ) ) / 	(  DELTA_Z * DELTA_Z ) ));
((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  (	(  a_rva + 	(  g * 6 ) ))[3] + allincfvx ));
((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  (	(  a_rva + 	(  g * 6 ) ))[4] + allincfvy ));
((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  (	(  a_rva + 	(  g * 6 ) ))[5] + allincfvz ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )] = new_load);

	}else{
		0;

	 }
}}}
void  c_boris_yee_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass0 ,double  Charge0 ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	double   shE  [192];	double   shB  [192];	double   shJ  [192];{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	if (  load0  ){  
			double  QE_MASS = 	(  Charge0 / Mass0 ) ;
	int  Midx = 	floor ( (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[0] ) ;
	int  Midy = 	floor ( (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[1] ) ;
	int  Midz = 	floor ( (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[2] ) ;
	int  Bidx = 	(  Midx - 1 ) ;
	int  Bidy = 	(  Midy - 1 ) ;
	int  Bidz = 	(  Midz - 1 ) ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  total_idx = 	(  3 * 	(  4 * 	(  xyzy + 	(  xyzz * 4 ) ) ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  shE + total_idx ))[ridx] = (	(  fieldE + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  shB + total_idx ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  shJ + total_idx ))[ridx] = (	(  FoutJ + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}}}{
	long  gMYGEN206 = 0 ;
	for (0 ; 	(  	(  gMYGEN206 + 	(  idx * 1 ) ) < load0 ) ; (gMYGEN206 = 	(  gMYGEN206 + 	(  1 * xlen ) )))
	{
	long  iba_tmp = 	(  	(  idx * 1 ) + gMYGEN206 ) ;
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
}}}}}{
	long  g ;
	for ((g = 0) ; 	(  g < numcp ) ; (g = 	(  g + 1 )))
	{
	double  xx0 = (	(  local_particle_head + 	(  g * 6 ) ))[0] ;
	double  xy0 = (	(  local_particle_head + 	(  g * 6 ) ))[1] ;
	double  xz0 = (	(  local_particle_head + 	(  g * 6 ) ))[2] ;
	double  rx0 = 	(  xx0 - Midx ) ;
	double  ry0 = 	(  xy0 - Midy ) ;
	double  rz0 = 	(  xz0 - Midz ) ;
	double  vx0 = (	(  local_particle_head + 	(  g * 6 ) ))[3] ;
	double  vy0 = (	(  local_particle_head + 	(  g * 6 ) ))[4] ;
	double  vz0 = (	(  local_particle_head + 	(  g * 6 ) ))[5] ;
	double   f_x_arr  [4];((f_x_arr)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) , 2 ) ));
((f_x_arr)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) ) ) ) ));
((f_x_arr)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx0 ) + 	pow ( rx0 , 2 ) ) ) ));
((f_x_arr)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx0 , 2 ) ));
	double   f_y_arr  [4];((f_y_arr)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) , 2 ) ));
((f_y_arr)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) ) ) ) ));
((f_y_arr)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry0 ) + 	pow ( ry0 , 2 ) ) ) ));
((f_y_arr)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry0 , 2 ) ));
	double   f_z_arr  [4];((f_z_arr)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) , 2 ) ));
((f_z_arr)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) ) ) ) ));
((f_z_arr)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz0 ) + 	pow ( rz0 , 2 ) ) ) ));
((f_z_arr)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz0 , 2 ) ));
	double  Ex0 = ({
	double  sum0 = 0.00000000000000000e+00 ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 4 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  allidx = 	(  xyzx + 	(  4 * 	(  xyzy + 	(  4 * xyzz ) ) ) ) ;
(sum0 = 	(  sum0 + 	(  (shE)[	(  	(  allidx * 3 ) + 0 )] * 	(  (f_x_arr)[xyzx] * 	(  (f_y_arr)[xyzy] * (f_z_arr)[xyzz] ) ) ) ));
}}}}}}sum0;
}) ;
	double  Ey0 = ({
	double  sum0 = 0.00000000000000000e+00 ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 4 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  allidx = 	(  xyzx + 	(  4 * 	(  xyzy + 	(  4 * xyzz ) ) ) ) ;
(sum0 = 	(  sum0 + 	(  (shE)[	(  	(  allidx * 3 ) + 1 )] * 	(  (f_x_arr)[xyzx] * 	(  (f_y_arr)[xyzy] * (f_z_arr)[xyzz] ) ) ) ));
}}}}}}sum0;
}) ;
	double  Ez0 = ({
	double  sum0 = 0.00000000000000000e+00 ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 4 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  allidx = 	(  xyzx + 	(  4 * 	(  xyzy + 	(  4 * xyzz ) ) ) ) ;
(sum0 = 	(  sum0 + 	(  (shE)[	(  	(  allidx * 3 ) + 2 )] * 	(  (f_x_arr)[xyzx] * 	(  (f_y_arr)[xyzy] * (f_z_arr)[xyzz] ) ) ) ));
}}}}}}sum0;
}) ;
	double  Bx0 = ({
	double  sum0 = 0.00000000000000000e+00 ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 4 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  allidx = 	(  xyzx + 	(  4 * 	(  xyzy + 	(  4 * xyzz ) ) ) ) ;
(sum0 = 	(  sum0 + 	(  (shB)[	(  	(  allidx * 3 ) + 0 )] * 	(  (f_x_arr)[xyzx] * 	(  (f_y_arr)[xyzy] * (f_z_arr)[xyzz] ) ) ) ));
}}}}}}sum0;
}) ;
	double  By0 = ({
	double  sum0 = 0.00000000000000000e+00 ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 4 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  allidx = 	(  xyzx + 	(  4 * 	(  xyzy + 	(  4 * xyzz ) ) ) ) ;
(sum0 = 	(  sum0 + 	(  (shB)[	(  	(  allidx * 3 ) + 1 )] * 	(  (f_x_arr)[xyzx] * 	(  (f_y_arr)[xyzy] * (f_z_arr)[xyzz] ) ) ) ));
}}}}}}sum0;
}) ;
	double  Bz0 = ({
	double  sum0 = 0.00000000000000000e+00 ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 4 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  allidx = 	(  xyzx + 	(  4 * 	(  xyzy + 	(  4 * xyzz ) ) ) ) ;
(sum0 = 	(  sum0 + 	(  (shB)[	(  	(  allidx * 3 ) + 2 )] * 	(  (f_x_arr)[xyzx] * 	(  (f_y_arr)[xyzy] * (f_z_arr)[xyzz] ) ) ) ));
}}}}}}sum0;
}) ;
	double  dt = Deltat ;
	double  vx1 = 	(  	(  	(  	(  	(  	(  	(  	pow ( dt , 3 ) * 	(  	(  	(  Bx0 * Bz0 ) * Ez0 ) + 	(  	(  Bx0 * By0 ) * Ey0 ) ) ) + 	(  	(  	pow ( Bx0 , 2 ) * 	pow ( dt , 3 ) ) * Ex0 ) ) * 	pow ( QE_MASS , 3 ) ) + 	(  	(  	(  	(  	(  	(  	(  	(  2 * Bx0 ) * Bz0 ) * 	pow ( dt , 2 ) ) * vz0 ) + 	(  	(  	(  	(  2 * Bx0 ) * By0 ) * 	pow ( dt , 2 ) ) * vy0 ) ) + 	(  	(  	(  	(  	(  -1 * 	pow ( Bz0 , 2 ) ) - 	pow ( By0 , 2 ) ) + 	pow ( Bx0 , 2 ) ) * 	pow ( dt , 2 ) ) * vx0 ) ) + 	(  	pow ( dt , 2 ) * 	(  	(  	(  2 * Bz0 ) * Ey0 ) - 	(  	(  2 * By0 ) * Ez0 ) ) ) ) * 	pow ( QE_MASS , 2 ) ) ) + 	(  	(  	(  	(  	(  	(  	(  -1 * 4 ) * By0 ) * dt ) * vz0 ) + 	(  	(  	(  4 * Bz0 ) * dt ) * vy0 ) ) + 	(  	(  4 * dt ) * Ex0 ) ) * QE_MASS ) ) + 	(  4 * vx0 ) ) * 	pow ( 	(  	(  	(  	(  	(  	pow ( Bz0 , 2 ) + 	pow ( By0 , 2 ) ) + 	pow ( Bx0 , 2 ) ) * 	pow ( dt , 2 ) ) * 	pow ( QE_MASS , 2 ) ) + 4 ) , 	(  -1 * 1 ) ) ) ;
	double  vy1 = 	(  	(  	(  	(  	(  	(  	(  	pow ( dt , 3 ) * 	(  	(  	(  By0 * Bz0 ) * Ez0 ) + 	(  	pow ( By0 , 2 ) * Ey0 ) ) ) + 	(  	(  	(  Bx0 * By0 ) * 	pow ( dt , 3 ) ) * Ex0 ) ) * 	pow ( QE_MASS , 3 ) ) + 	(  	(  	(  	(  	(  	(  	(  	(  	(  2 * By0 ) * Bz0 ) * 	pow ( dt , 2 ) ) * vz0 ) + 	(  	(  	(  	(  	(  -1 * 	pow ( Bz0 , 2 ) ) + 	pow ( By0 , 2 ) ) - 	pow ( Bx0 , 2 ) ) * 	pow ( dt , 2 ) ) * vy0 ) ) + 	(  	(  	(  	(  2 * Bx0 ) * By0 ) * 	pow ( dt , 2 ) ) * vx0 ) ) + 	(  	(  	(  2 * Bx0 ) * 	pow ( dt , 2 ) ) * Ez0 ) ) - 	(  	(  	(  2 * Bz0 ) * 	pow ( dt , 2 ) ) * Ex0 ) ) * 	pow ( QE_MASS , 2 ) ) ) + 	(  	(  	(  	(  	(  	(  4 * Bx0 ) * dt ) * vz0 ) - 	(  	(  	(  4 * Bz0 ) * dt ) * vx0 ) ) + 	(  	(  4 * dt ) * Ey0 ) ) * QE_MASS ) ) + 	(  4 * vy0 ) ) * 	pow ( 	(  	(  	(  	(  	(  	pow ( Bz0 , 2 ) + 	pow ( By0 , 2 ) ) + 	pow ( Bx0 , 2 ) ) * 	pow ( dt , 2 ) ) * 	pow ( QE_MASS , 2 ) ) + 4 ) , 	(  -1 * 1 ) ) ) ;
	double  vz1 = 	(  	(  	(  	(  	(  	(  	(  	pow ( dt , 3 ) * 	(  	(  	pow ( Bz0 , 2 ) * Ez0 ) + 	(  	(  By0 * Bz0 ) * Ey0 ) ) ) + 	(  	(  	(  Bx0 * Bz0 ) * 	pow ( dt , 3 ) ) * Ex0 ) ) * 	pow ( QE_MASS , 3 ) ) + 	(  	(  	(  	(  	(  	(  	(  	(  	(  	pow ( Bz0 , 2 ) - 	pow ( By0 , 2 ) ) - 	pow ( Bx0 , 2 ) ) * 	pow ( dt , 2 ) ) * vz0 ) + 	(  	(  	(  	(  2 * By0 ) * Bz0 ) * 	pow ( dt , 2 ) ) * vy0 ) ) + 	(  	(  	(  	(  2 * Bx0 ) * Bz0 ) * 	pow ( dt , 2 ) ) * vx0 ) ) - 	(  	(  	(  2 * Bx0 ) * 	pow ( dt , 2 ) ) * Ey0 ) ) + 	(  	(  	(  2 * By0 ) * 	pow ( dt , 2 ) ) * Ex0 ) ) * 	pow ( QE_MASS , 2 ) ) ) + 	(  	(  	(  	(  	(  	(  	(  -1 * 4 ) * Bx0 ) * dt ) * vy0 ) + 	(  	(  	(  4 * By0 ) * dt ) * vx0 ) ) + 	(  	(  4 * dt ) * Ez0 ) ) * QE_MASS ) ) + 	(  4 * vz0 ) ) * 	pow ( 	(  	(  	(  	(  	(  	pow ( Bz0 , 2 ) + 	pow ( By0 , 2 ) ) + 	pow ( Bx0 , 2 ) ) * 	pow ( dt , 2 ) ) * 	pow ( QE_MASS , 2 ) ) + 4 ) , 	(  -1 * 1 ) ) ) ;
	double  xx1 = 	(  xx0 + 	(  Deltat * vx1 ) ) ;
	double  xy1 = 	(  xy0 + 	(  Deltat * vy1 ) ) ;
	double  xz1 = 	(  xz0 + 	(  Deltat * vz1 ) ) ;
((	(  local_particle_head + 	(  g * 6 ) ))[0] = xx1);
((	(  local_particle_head + 	(  g * 6 ) ))[1] = xy1);
((	(  local_particle_head + 	(  g * 6 ) ))[2] = xz1);
((	(  local_particle_head + 	(  g * 6 ) ))[3] = vx1);
((	(  local_particle_head + 	(  g * 6 ) ))[4] = vy1);
((	(  local_particle_head + 	(  g * 6 ) ))[5] = vz1);
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 4 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  total_idx = 	(  3 * 	(  xyzx + 	(  4 * 	(  xyzy + 	(  xyzz * 4 ) ) ) ) ) ;
	double  coeff = 	(  (f_x_arr)[xyzx] * 	(  (f_y_arr)[xyzy] * (f_z_arr)[xyzz] ) ) ;
	double  vxall = 	(  coeff * vx1 ) ;
	double  vyall = 	(  coeff * vy1 ) ;
	double  vzall = 	(  coeff * vz1 ) ;
	double  svxall = vxall ;
	double  svyall = vyall ;
	double  svzall = vzall ;
((shJ)[	(  total_idx + 0 )] = 	(  (shJ)[	(  total_idx + 0 )] + 	(  svxall * Charge0 ) ));
((shJ)[	(  total_idx + 1 )] = 	(  (shJ)[	(  total_idx + 1 )] + 	(  svyall * Charge0 ) ));
((shJ)[	(  total_idx + 2 )] = 	(  (shJ)[	(  total_idx + 2 )] + 	(  svzall * Charge0 ) ));
}}}}}}{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  total_idx = 	(  3 * 	(  4 * 	(  xyzy + 	(  4 * xyzz ) ) ) ) ;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 12 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  FoutJ + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  shJ + total_idx ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}}}}}}}{
	long  g ;
	for ((g = 0) ; 	(  g < numcp ) ; (g = 	(  g + 1 )))
	{
}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}}
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
			double  QE_MASS = 	(  Charge0 / Mass0 ) ;
	int  Midx = 	floor ( (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[0] ) ;
	int  Midy = 	floor ( (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[1] ) ;
	int  Midz = 	floor ( (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[2] ) ;
	int  Bidx = 	(  Midx - 1 ) ;
	int  Bidy = 	(  Midy - 1 ) ;
	int  Bidz = 	(  Midz - 1 ) ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  total_idx = 	(  3 * 	(  4 * 	(  xyzy + 	(  xyzz * 4 ) ) ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  shE + total_idx ))[ridx] = (	(  fieldE + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  shB + total_idx ))[ridx] = (	(  fieldB + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  shJ + total_idx ))[ridx] = (	(  FoutJ + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}}}{
	long  gMYGEN213 = 0 ;
	for (0 ; 	(  	(  gMYGEN213 + 	(  idx * 1 ) ) < load0 ) ; (gMYGEN213 = 	(  gMYGEN213 + 	(  1 * xlen ) )))
	{
	long  iba_tmp = 	(  	(  idx * 1 ) + gMYGEN213 ) ;
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
}}}}}{
	long  g ;
	for ((g = 0) ; 	(  g < numcp ) ; (g = 	(  g + 1 )))
	{
	double  xx0 = (	(  local_particle_head + 	(  g * 6 ) ))[0] ;
	double  xy0 = (	(  local_particle_head + 	(  g * 6 ) ))[1] ;
	double  xz0 = (	(  local_particle_head + 	(  g * 6 ) ))[2] ;
	double  rx0 = 	(  xx0 - Midx ) ;
	double  ry0 = 	(  xy0 - Midy ) ;
	double  rz0 = 	(  xz0 - Midz ) ;
	double  vx0 = (	(  local_particle_head + 	(  g * 6 ) ))[3] ;
	double  vy0 = (	(  local_particle_head + 	(  g * 6 ) ))[4] ;
	double  vz0 = (	(  local_particle_head + 	(  g * 6 ) ))[5] ;
	double   f_x_arr  [4];((f_x_arr)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) , 2 ) ));
((f_x_arr)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) ) ) ) ));
((f_x_arr)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx0 ) + 	pow ( rx0 , 2 ) ) ) ));
((f_x_arr)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx0 , 2 ) ));
	double   f_y_arr  [4];((f_y_arr)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) , 2 ) ));
((f_y_arr)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) ) ) ) ));
((f_y_arr)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry0 ) + 	pow ( ry0 , 2 ) ) ) ));
((f_y_arr)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry0 , 2 ) ));
	double   f_z_arr  [4];((f_z_arr)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) , 2 ) ));
((f_z_arr)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) ) ) ) ));
((f_z_arr)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz0 ) + 	pow ( rz0 , 2 ) ) ) ));
((f_z_arr)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz0 , 2 ) ));
	double  Ex0 = ({
	double  sum0 = 0.00000000000000000e+00 ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 4 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  allidx = 	(  xyzx + 	(  4 * 	(  xyzy + 	(  4 * xyzz ) ) ) ) ;
(sum0 = 	(  sum0 + 	(  (shE)[	(  	(  allidx * 3 ) + 0 )] * 	(  (f_x_arr)[xyzx] * 	(  (f_y_arr)[xyzy] * (f_z_arr)[xyzz] ) ) ) ));
}}}}}}sum0;
}) ;
	double  Ey0 = ({
	double  sum0 = 0.00000000000000000e+00 ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 4 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  allidx = 	(  xyzx + 	(  4 * 	(  xyzy + 	(  4 * xyzz ) ) ) ) ;
(sum0 = 	(  sum0 + 	(  (shE)[	(  	(  allidx * 3 ) + 1 )] * 	(  (f_x_arr)[xyzx] * 	(  (f_y_arr)[xyzy] * (f_z_arr)[xyzz] ) ) ) ));
}}}}}}sum0;
}) ;
	double  Ez0 = ({
	double  sum0 = 0.00000000000000000e+00 ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 4 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  allidx = 	(  xyzx + 	(  4 * 	(  xyzy + 	(  4 * xyzz ) ) ) ) ;
(sum0 = 	(  sum0 + 	(  (shE)[	(  	(  allidx * 3 ) + 2 )] * 	(  (f_x_arr)[xyzx] * 	(  (f_y_arr)[xyzy] * (f_z_arr)[xyzz] ) ) ) ));
}}}}}}sum0;
}) ;
	double  Bx0 = ({
	double  sum0 = 0.00000000000000000e+00 ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 4 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  allidx = 	(  xyzx + 	(  4 * 	(  xyzy + 	(  4 * xyzz ) ) ) ) ;
(sum0 = 	(  sum0 + 	(  (shB)[	(  	(  allidx * 3 ) + 0 )] * 	(  (f_x_arr)[xyzx] * 	(  (f_y_arr)[xyzy] * (f_z_arr)[xyzz] ) ) ) ));
}}}}}}sum0;
}) ;
	double  By0 = ({
	double  sum0 = 0.00000000000000000e+00 ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 4 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  allidx = 	(  xyzx + 	(  4 * 	(  xyzy + 	(  4 * xyzz ) ) ) ) ;
(sum0 = 	(  sum0 + 	(  (shB)[	(  	(  allidx * 3 ) + 1 )] * 	(  (f_x_arr)[xyzx] * 	(  (f_y_arr)[xyzy] * (f_z_arr)[xyzz] ) ) ) ));
}}}}}}sum0;
}) ;
	double  Bz0 = ({
	double  sum0 = 0.00000000000000000e+00 ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 4 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  allidx = 	(  xyzx + 	(  4 * 	(  xyzy + 	(  4 * xyzz ) ) ) ) ;
(sum0 = 	(  sum0 + 	(  (shB)[	(  	(  allidx * 3 ) + 2 )] * 	(  (f_x_arr)[xyzx] * 	(  (f_y_arr)[xyzy] * (f_z_arr)[xyzz] ) ) ) ));
}}}}}}sum0;
}) ;
	double  dt = Deltat ;
	double  vx1 = 	(  	(  	(  	(  	(  	(  	(  	pow ( dt , 3 ) * 	(  	(  	(  Bx0 * Bz0 ) * Ez0 ) + 	(  	(  Bx0 * By0 ) * Ey0 ) ) ) + 	(  	(  	pow ( Bx0 , 2 ) * 	pow ( dt , 3 ) ) * Ex0 ) ) * 	pow ( QE_MASS , 3 ) ) + 	(  	(  	(  	(  	(  	(  	(  	(  2 * Bx0 ) * Bz0 ) * 	pow ( dt , 2 ) ) * vz0 ) + 	(  	(  	(  	(  2 * Bx0 ) * By0 ) * 	pow ( dt , 2 ) ) * vy0 ) ) + 	(  	(  	(  	(  	(  -1 * 	pow ( Bz0 , 2 ) ) - 	pow ( By0 , 2 ) ) + 	pow ( Bx0 , 2 ) ) * 	pow ( dt , 2 ) ) * vx0 ) ) + 	(  	pow ( dt , 2 ) * 	(  	(  	(  2 * Bz0 ) * Ey0 ) - 	(  	(  2 * By0 ) * Ez0 ) ) ) ) * 	pow ( QE_MASS , 2 ) ) ) + 	(  	(  	(  	(  	(  	(  	(  -1 * 4 ) * By0 ) * dt ) * vz0 ) + 	(  	(  	(  4 * Bz0 ) * dt ) * vy0 ) ) + 	(  	(  4 * dt ) * Ex0 ) ) * QE_MASS ) ) + 	(  4 * vx0 ) ) * 	pow ( 	(  	(  	(  	(  	(  	pow ( Bz0 , 2 ) + 	pow ( By0 , 2 ) ) + 	pow ( Bx0 , 2 ) ) * 	pow ( dt , 2 ) ) * 	pow ( QE_MASS , 2 ) ) + 4 ) , 	(  -1 * 1 ) ) ) ;
	double  vy1 = 	(  	(  	(  	(  	(  	(  	(  	pow ( dt , 3 ) * 	(  	(  	(  By0 * Bz0 ) * Ez0 ) + 	(  	pow ( By0 , 2 ) * Ey0 ) ) ) + 	(  	(  	(  Bx0 * By0 ) * 	pow ( dt , 3 ) ) * Ex0 ) ) * 	pow ( QE_MASS , 3 ) ) + 	(  	(  	(  	(  	(  	(  	(  	(  	(  2 * By0 ) * Bz0 ) * 	pow ( dt , 2 ) ) * vz0 ) + 	(  	(  	(  	(  	(  -1 * 	pow ( Bz0 , 2 ) ) + 	pow ( By0 , 2 ) ) - 	pow ( Bx0 , 2 ) ) * 	pow ( dt , 2 ) ) * vy0 ) ) + 	(  	(  	(  	(  2 * Bx0 ) * By0 ) * 	pow ( dt , 2 ) ) * vx0 ) ) + 	(  	(  	(  2 * Bx0 ) * 	pow ( dt , 2 ) ) * Ez0 ) ) - 	(  	(  	(  2 * Bz0 ) * 	pow ( dt , 2 ) ) * Ex0 ) ) * 	pow ( QE_MASS , 2 ) ) ) + 	(  	(  	(  	(  	(  	(  4 * Bx0 ) * dt ) * vz0 ) - 	(  	(  	(  4 * Bz0 ) * dt ) * vx0 ) ) + 	(  	(  4 * dt ) * Ey0 ) ) * QE_MASS ) ) + 	(  4 * vy0 ) ) * 	pow ( 	(  	(  	(  	(  	(  	pow ( Bz0 , 2 ) + 	pow ( By0 , 2 ) ) + 	pow ( Bx0 , 2 ) ) * 	pow ( dt , 2 ) ) * 	pow ( QE_MASS , 2 ) ) + 4 ) , 	(  -1 * 1 ) ) ) ;
	double  vz1 = 	(  	(  	(  	(  	(  	(  	(  	pow ( dt , 3 ) * 	(  	(  	pow ( Bz0 , 2 ) * Ez0 ) + 	(  	(  By0 * Bz0 ) * Ey0 ) ) ) + 	(  	(  	(  Bx0 * Bz0 ) * 	pow ( dt , 3 ) ) * Ex0 ) ) * 	pow ( QE_MASS , 3 ) ) + 	(  	(  	(  	(  	(  	(  	(  	(  	(  	pow ( Bz0 , 2 ) - 	pow ( By0 , 2 ) ) - 	pow ( Bx0 , 2 ) ) * 	pow ( dt , 2 ) ) * vz0 ) + 	(  	(  	(  	(  2 * By0 ) * Bz0 ) * 	pow ( dt , 2 ) ) * vy0 ) ) + 	(  	(  	(  	(  2 * Bx0 ) * Bz0 ) * 	pow ( dt , 2 ) ) * vx0 ) ) - 	(  	(  	(  2 * Bx0 ) * 	pow ( dt , 2 ) ) * Ey0 ) ) + 	(  	(  	(  2 * By0 ) * 	pow ( dt , 2 ) ) * Ex0 ) ) * 	pow ( QE_MASS , 2 ) ) ) + 	(  	(  	(  	(  	(  	(  	(  -1 * 4 ) * Bx0 ) * dt ) * vy0 ) + 	(  	(  	(  4 * By0 ) * dt ) * vx0 ) ) + 	(  	(  4 * dt ) * Ez0 ) ) * QE_MASS ) ) + 	(  4 * vz0 ) ) * 	pow ( 	(  	(  	(  	(  	(  	pow ( Bz0 , 2 ) + 	pow ( By0 , 2 ) ) + 	pow ( Bx0 , 2 ) ) * 	pow ( dt , 2 ) ) * 	pow ( QE_MASS , 2 ) ) + 4 ) , 	(  -1 * 1 ) ) ) ;
	double  xx1 = 	(  xx0 + 	(  Deltat * vx1 ) ) ;
	double  xy1 = 	(  xy0 + 	(  Deltat * vy1 ) ) ;
	double  xz1 = 	(  xz0 + 	(  Deltat * vz1 ) ) ;
((	(  local_particle_head + 	(  g * 6 ) ))[0] = xx1);
((	(  local_particle_head + 	(  g * 6 ) ))[1] = xy1);
((	(  local_particle_head + 	(  g * 6 ) ))[2] = xz1);
((	(  local_particle_head + 	(  g * 6 ) ))[3] = vx1);
((	(  local_particle_head + 	(  g * 6 ) ))[4] = vy1);
((	(  local_particle_head + 	(  g * 6 ) ))[5] = vz1);
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 4 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  total_idx = 	(  3 * 	(  xyzx + 	(  4 * 	(  xyzy + 	(  xyzz * 4 ) ) ) ) ) ;
	double  coeff = 	(  (f_x_arr)[xyzx] * 	(  (f_y_arr)[xyzy] * (f_z_arr)[xyzz] ) ) ;
	double  vxall = 	(  coeff * vx1 ) ;
	double  vyall = 	(  coeff * vy1 ) ;
	double  vzall = 	(  coeff * vz1 ) ;
	double  svxall = vxall ;
	double  svyall = vyall ;
	double  svzall = vzall ;
((shJ)[	(  total_idx + 0 )] = 	(  (shJ)[	(  total_idx + 0 )] + 	(  svxall * Charge0 ) ));
((shJ)[	(  total_idx + 1 )] = 	(  (shJ)[	(  total_idx + 1 )] + 	(  svyall * Charge0 ) ));
((shJ)[	(  total_idx + 2 )] = 	(  (shJ)[	(  total_idx + 2 )] + 	(  svzall * Charge0 ) ));
}}}}}}{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  total_idx = 	(  3 * 	(  4 * 	(  xyzy + 	(  4 * xyzz ) ) ) ) ;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 12 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  FoutJ + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  shJ + total_idx ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}}}}}}}{
	long  g ;
	for ((g = 0) ; 	(  g < numcp ) ; (g = 	(  g + 1 )))
	{
}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )] = new_load);

	}else{
		0;

	 }
}}}
void  c_krook_collision_remove_small_speed_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  mu_freq ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	if (  load0  ){  
			int  Midx = 	floor ( (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[0] ) ;
	int  Midy = 	floor ( (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[1] ) ;
	int  Midz = 	floor ( (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[2] ) ;
	int  mode = 0 ;
	double  mu_freq1 ;
	double  v_t_gen ;
	int  num_gen = 0 ;
	if (  (fieldE)[	(  	(  6 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  6 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) )]  ){  
		(mode = 1);
(mu_freq1 = mu_freq);
	if (  	(  mu_freq == 0 )  ){  
		(mu_freq1 = (fieldE)[	(  	(  6 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  1 + 	(  6 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) )]);

	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  (fieldE)[	(  	(  6 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  3 + 	(  6 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) )]  ){  
		(mode = 2);
(v_t_gen = (fieldE)[	(  	(  6 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  3 + 	(  6 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) )]);
(num_gen = (fieldE)[	(  	(  6 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  2 + 	(  6 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) )]);

	}else{
		0;

	 }
	int  lg = 0 ;
	int  idx_all_remove = 0 ;
	if (  	(  idx == 0 )  ){  
			if (  	(  mode == 1 )  ){  
			for (0 ; 	(  	(  1 + lg ) < load0 ) ; (lg = 	(  lg + 1 )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}	int  numcp_remove = 0 ;
{
	long  g ;
	for ((g = 0) ; 	(  g < numcp ) ; (g = 	(  g + 1 )))
	{
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[3] ;
	double  vy = (	(  a_rva + 	(  g * 6 ) ))[4] ;
	double  vz = (	(  a_rva + 	(  g * 6 ) ))[5] ;
	if (  	(  	(  Mass0 * 	(  	(  vx * vx ) + 	(  	(  vy * vy ) + 	(  vz * vz ) ) ) ) > 	(  mu_freq1 * mu_freq1 ) )  ){  
			if (  	(  numcp_remove != g )  ){  
		{
	long  s ;
	for ((s = 0) ; 	(  s < 6 ) ; (s = 	(  s + 1 )))
	{
((	(  a_rva + 	(  numcp_remove * 6 ) ))[s] = (	(  a_rva + 	(  g * 6 ) ))[s]);
}}
	}else{
		0;

	 }
(numcp_remove = 	(  numcp_remove + 1 ));

	}else{
		(new_load = 	(  new_load + -1 ));

	 }
}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp_remove * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_remove * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(idx_all_remove = 	(  idx_all_remove + numcp_remove ));
}
	}else{
			if (  	(  mode == 2 )  ){  
			if (  	(  num_gen > new_load )  ){  
		{
	long  g ;
	for ((g = num_gen) ; 	(  g < new_load ) ; (g = 	(  g + 1 )))
	{
	double   a_rva  [6];((a_rva)[0] = 	c_rand01_k ( Midx , 	(  Midx + 1 ) ));
((a_rva)[1] = 	c_rand01_k ( Midy , 	(  Midy + 1 ) ));
((a_rva)[2] = 	c_rand01_k ( Midz , 	(  Midz + 1 ) ));
((a_rva)[3] = 	c_maxwell_dist_k ( 0 , v_t_gen ));
((a_rva)[4] = 	c_maxwell_dist_k ( 0 , v_t_gen ));
((a_rva)[5] = 	c_maxwell_dist_k ( 0 , v_t_gen ));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  6 * g ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (a_rva)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}
	}else{
		0;

	 }
	if (  num_gen  ){  
		(new_load = num_gen);

	}else{
		0;

	 }

	}else{
		0;

	 }

	 }

	}else{
		0;

	 }

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
			int  Midx = 	floor ( (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[0] ) ;
	int  Midy = 	floor ( (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[1] ) ;
	int  Midz = 	floor ( (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[2] ) ;
	int  mode = 0 ;
	double  mu_freq1 ;
	double  v_t_gen ;
	int  num_gen = 0 ;
	if (  (fieldE)[	(  	(  6 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  6 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) )]  ){  
		(mode = 1);
(mu_freq1 = mu_freq);
	if (  	(  mu_freq == 0 )  ){  
		(mu_freq1 = (fieldE)[	(  	(  6 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  1 + 	(  6 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) )]);

	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  (fieldE)[	(  	(  6 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  3 + 	(  6 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) )]  ){  
		(mode = 2);
(v_t_gen = (fieldE)[	(  	(  6 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  3 + 	(  6 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) )]);
(num_gen = (fieldE)[	(  	(  6 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  2 + 	(  6 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) )]);

	}else{
		0;

	 }
	int  lg = 0 ;
	int  idx_all_remove = 0 ;
	if (  	(  idx == 0 )  ){  
			if (  	(  mode == 1 )  ){  
			for (0 ; 	(  	(  1 + lg ) < load0 ) ; (lg = 	(  lg + 1 )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}	int  numcp_remove = 0 ;
{
	long  g ;
	for ((g = 0) ; 	(  g < numcp ) ; (g = 	(  g + 1 )))
	{
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[3] ;
	double  vy = (	(  a_rva + 	(  g * 6 ) ))[4] ;
	double  vz = (	(  a_rva + 	(  g * 6 ) ))[5] ;
	if (  	(  	(  Mass0 * 	(  	(  vx * vx ) + 	(  	(  vy * vy ) + 	(  vz * vz ) ) ) ) > 	(  mu_freq1 * mu_freq1 ) )  ){  
			if (  	(  numcp_remove != g )  ){  
		{
	long  s ;
	for ((s = 0) ; 	(  s < 6 ) ; (s = 	(  s + 1 )))
	{
((	(  a_rva + 	(  numcp_remove * 6 ) ))[s] = (	(  a_rva + 	(  g * 6 ) ))[s]);
}}
	}else{
		0;

	 }
(numcp_remove = 	(  numcp_remove + 1 ));

	}else{
		(new_load = 	(  new_load + -1 ));

	 }
}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp_remove * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_remove * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(idx_all_remove = 	(  idx_all_remove + numcp_remove ));
}
	}else{
			if (  	(  mode == 2 )  ){  
			if (  	(  num_gen > new_load )  ){  
		{
	long  g ;
	for ((g = num_gen) ; 	(  g < new_load ) ; (g = 	(  g + 1 )))
	{
	double   a_rva  [6];((a_rva)[0] = 	c_rand01_k ( Midx , 	(  Midx + 1 ) ));
((a_rva)[1] = 	c_rand01_k ( Midy , 	(  Midy + 1 ) ));
((a_rva)[2] = 	c_rand01_k ( Midz , 	(  Midz + 1 ) ));
((a_rva)[3] = 	c_maxwell_dist_k ( 0 , v_t_gen ));
((a_rva)[4] = 	c_maxwell_dist_k ( 0 , v_t_gen ));
((a_rva)[5] = 	c_maxwell_dist_k ( 0 , v_t_gen ));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  6 * g ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (a_rva)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}
	}else{
		0;

	 }
	if (  num_gen  ){  
		(new_load = num_gen);

	}else{
		0;

	 }

	}else{
		0;

	 }

	 }

	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )] = new_load);

	}else{
		0;

	 }
}}}
void  c_krook_collision_test_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass0 ,double  Charge0 ,double  Deltat ,double  mu_freq ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	if (  load0  ){  
			int  Midx = 	floor ( (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[0] ) ;
	int  Midy = 	floor ( (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[1] ) ;
	int  Midz = 	floor ( (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[2] ) ;
	double  mu_freq1 ;
	if (  	(  ! (fieldE)[	(  	(  6 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  6 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) )] )  ){  
		continue;

	}else{
		(mu_freq1 = mu_freq);

	 }
	if (  	(  mu_freq == 0 )  ){  
		(mu_freq1 = (fieldE)[	(  	(  6 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  1 + 	(  6 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) )]);

	}else{
		0;

	 }
	long  lg = 0 ;
	for (0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  g ;
	for ((g = 0) ; 	(  g < numcp ) ; (g = 	(  g + 1 )))
	{
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[3] ;
	double  vy = (	(  a_rva + 	(  g * 6 ) ))[4] ;
	double  vz = (	(  a_rva + 	(  g * 6 ) ))[5] ;
((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  vx * 	(  1 - 	(  Deltat * mu_freq1 ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  vy * 	(  1 - 	(  Deltat * mu_freq1 ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  vz * 	(  1 - 	(  Deltat * mu_freq1 ) ) ));
}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}
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
			int  Midx = 	floor ( (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[0] ) ;
	int  Midy = 	floor ( (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[1] ) ;
	int  Midz = 	floor ( (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[2] ) ;
	double  mu_freq1 ;
	if (  	(  ! (fieldE)[	(  	(  6 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  6 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) )] )  ){  
		continue;

	}else{
		(mu_freq1 = mu_freq);

	 }
	if (  	(  mu_freq == 0 )  ){  
		(mu_freq1 = (fieldE)[	(  	(  6 * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  1 + 	(  6 * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) )]);

	}else{
		0;

	 }
	long  lg = 0 ;
	for (0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}{
	long  g ;
	for ((g = 0) ; 	(  g < numcp ) ; (g = 	(  g + 1 )))
	{
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[3] ;
	double  vy = (	(  a_rva + 	(  g * 6 ) ))[4] ;
	double  vz = (	(  a_rva + 	(  g * 6 ) ))[5] ;
((	(  a_rva + 	(  g * 6 ) ))[3] = 	(  vx * 	(  1 - 	(  Deltat * mu_freq1 ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[4] = 	(  vy * 	(  1 - 	(  Deltat * mu_freq1 ) ) ));
((	(  a_rva + 	(  g * 6 ) ))[5] = 	(  vz * 	(  1 - 	(  Deltat * mu_freq1 ) ) ));
}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )] = new_load);

	}else{
		0;

	 }
}}}
void  c_calculate_rho_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	double   shJ  [192];{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	if (  load0  ){  
			double  xx = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[0] ;
	double  xy = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[1] ;
	double  xz = (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[2] ;
	int  Bidx = 	floor ( xx ) ;
	int  Bidy = 	floor ( xy ) ;
	int  Bidz = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
(Bidx = 	(  Bidx - 1 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  total_idx = 	(  3 * 	(  4 * 	(  xyzy + 	(  xyzz * 4 ) ) ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  shJ + total_idx ))[ridx] = (	(  FoutJ + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}}}{
	long  gMYGEN232 = 0 ;
	for (0 ; 	(  	(  gMYGEN232 + 	(  idx * 1 ) ) < load0 ) ; (gMYGEN232 = 	(  gMYGEN232 + 	(  1 * xlen ) )))
	{
	long  iba_tmp = 	(  	(  idx * 1 ) + gMYGEN232 ) ;
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
}}}}}{
	long  g ;
	for ((g = 0) ; 	(  g < numcp ) ; (g = 	(  g + 1 )))
	{
	double  xx0 = (	(  local_particle_head + 	(  g * 6 ) ))[0] ;
	double  xy0 = (	(  local_particle_head + 	(  g * 6 ) ))[1] ;
	double  xz0 = (	(  local_particle_head + 	(  g * 6 ) ))[2] ;
	double  rx0 = 	(  xx0 - Midx ) ;
	double  ry0 = 	(  xy0 - Midy ) ;
	double  rz0 = 	(  xz0 - Midz ) ;
	double   f_x_arr  [4];((f_x_arr)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) , 2 ) ));
((f_x_arr)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) ) ) ) ));
((f_x_arr)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx0 ) + 	pow ( rx0 , 2 ) ) ) ));
((f_x_arr)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx0 , 2 ) ));
	double   f_y_arr  [4];((f_y_arr)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) , 2 ) ));
((f_y_arr)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) ) ) ) ));
((f_y_arr)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry0 ) + 	pow ( ry0 , 2 ) ) ) ));
((f_y_arr)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry0 , 2 ) ));
	double   f_z_arr  [4];((f_z_arr)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) , 2 ) ));
((f_z_arr)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) ) ) ) ));
((f_z_arr)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz0 ) + 	pow ( rz0 , 2 ) ) ) ));
((f_z_arr)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz0 , 2 ) ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 4 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  total_idx = 	(  3 * 	(  xyzx + 	(  4 * 	(  xyzy + 	(  xyzz * 4 ) ) ) ) ) ;
	double  coeff = 	(  (f_x_arr)[xyzx] * 	(  (f_y_arr)[xyzy] * (f_z_arr)[xyzz] ) ) ;
	double  rcoeff = coeff ;
((shJ)[	(  total_idx + 0 )] = 	(  (shJ)[	(  total_idx + 0 )] + 	(  rcoeff * Charge ) ));
}}}}}}}}{
	long  g ;
	for ((g = 0) ; 	(  g < numcp ) ; (g = 	(  g + 1 )))
	{
}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}}{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  total_idx = 	(  3 * 	(  4 * 	(  xyzy + 	(  4 * xyzz ) ) ) ) ;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 12 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  FoutJ + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  shJ + total_idx ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}}}}}
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
			double  xx = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[0] ;
	double  xy = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[1] ;
	double  xz = (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[2] ;
	int  Bidx = 	floor ( xx ) ;
	int  Bidy = 	floor ( xy ) ;
	int  Bidz = 	floor ( xz ) ;
	int  Midx = Bidx ;
	int  Midy = Bidy ;
	int  Midz = Bidz ;
(Bidx = 	(  Bidx - 1 ));
(Bidy = 	(  Bidy - 1 ));
(Bidz = 	(  Bidz - 1 ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  total_idx = 	(  3 * 	(  4 * 	(  xyzy + 	(  xyzz * 4 ) ) ) ) ;
{
	long  lg = 0 ;
	for (0 ; 	(  lg < 12 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 12 )  ){  
		((	(  shJ + total_idx ))[ridx] = (	(  FoutJ + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[ridx]);

	}else{
		0;

	 }
}}}}}}}}{
	long  gMYGEN237 = 0 ;
	for (0 ; 	(  	(  gMYGEN237 + 	(  idx * 1 ) ) < load0 ) ; (gMYGEN237 = 	(  gMYGEN237 + 	(  1 * xlen ) )))
	{
	long  iba_tmp = 	(  	(  idx * 1 ) + gMYGEN237 ) ;
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
}}}}}{
	long  g ;
	for ((g = 0) ; 	(  g < numcp ) ; (g = 	(  g + 1 )))
	{
	double  xx0 = (	(  local_particle_head + 	(  g * 6 ) ))[0] ;
	double  xy0 = (	(  local_particle_head + 	(  g * 6 ) ))[1] ;
	double  xz0 = (	(  local_particle_head + 	(  g * 6 ) ))[2] ;
	double  rx0 = 	(  xx0 - Midx ) ;
	double  ry0 = 	(  xy0 - Midy ) ;
	double  rz0 = 	(  xz0 - Midz ) ;
	double   f_x_arr  [4];((f_x_arr)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) , 2 ) ));
((f_x_arr)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rx0 ) ) ) ) ) ));
((f_x_arr)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rx0 ) + 	pow ( rx0 , 2 ) ) ) ));
((f_x_arr)[3] = 	(  2.50000000000000000e-01 * 	pow ( rx0 , 2 ) ));
	double   f_y_arr  [4];((f_y_arr)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) , 2 ) ));
((f_y_arr)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * ry0 ) ) ) ) ) ));
((f_y_arr)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * ry0 ) + 	pow ( ry0 , 2 ) ) ) ));
((f_y_arr)[3] = 	(  2.50000000000000000e-01 * 	pow ( ry0 , 2 ) ));
	double   f_z_arr  [4];((f_z_arr)[0] = 	(  2.50000000000000000e-01 * 	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) , 2 ) ));
((f_z_arr)[1] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	pow ( 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) , 2 ) + 	(  -2.00000000000000000e+00 * 	(  1.00000000000000000e+00 + 	(  -1.00000000000000000e+00 * rz0 ) ) ) ) ) ));
((f_z_arr)[2] = 	(  -2.50000000000000000e-01 * 	(  -1.00000000000000000e+00 + 	(  	(  -2.00000000000000000e+00 * rz0 ) + 	pow ( rz0 , 2 ) ) ) ));
((f_z_arr)[3] = 	(  2.50000000000000000e-01 * 	pow ( rz0 , 2 ) ));
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 4 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  total_idx = 	(  3 * 	(  xyzx + 	(  4 * 	(  xyzy + 	(  xyzz * 4 ) ) ) ) ) ;
	double  coeff = 	(  (f_x_arr)[xyzx] * 	(  (f_y_arr)[xyzy] * (f_z_arr)[xyzz] ) ) ;
	double  rcoeff = coeff ;
((shJ)[	(  total_idx + 0 )] = 	(  (shJ)[	(  total_idx + 0 )] + 	(  rcoeff * Charge ) ));
}}}}}}}}{
	long  g ;
	for ((g = 0) ; 	(  g < numcp ) ; (g = 	(  g + 1 )))
	{
}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  iba_tmp * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  local_particle_head + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}}{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 4 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 4 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  total_idx = 	(  3 * 	(  4 * 	(  xyzy + 	(  4 * xyzz ) ) ) ) ;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 12 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  FoutJ + 	(  	(  num_ele * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  num_ele * 	(  	(  Bidx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  	(  xyzy + Bidy ) + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  	(  xyzz + Bidz ) + ovlp ) ) ) ) ) ) ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  shJ + total_idx ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}}}}}}
	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )] = new_load);

	}else{
		0;

	 }
}}}
void  c_dump_ene_num_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,double *  fieldE ,double *  fieldB ,double *  FoutJ ,double *  FoutEN ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,int  num_ele ,long  grid_cache_len ,long  cu_cache_length ,double  Mass ,double  Charge ,int  SPEC ,int  NUM_SPEC ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  Deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
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
	double   enevec  [IDX_OPT_MAX*3];	double   avvvec  [IDX_OPT_MAX*3];	int   numcpvec  [IDX_OPT_MAX];{
	long  l1 ;
	for ((l1 = 0) ; 	(  l1 < cu_load ) ; (l1 = 	(  l1 + 1 )))
	{
	long  load0 = 1 ;
	long  new_load = load0 ;
	if (  load0  ){  
			int  Midx = 	floor ( (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[0] ) ;
	int  Midy = 	floor ( (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[1] ) ;
	int  Midz = 	floor ( (	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ))[2] ) ;
	long  lg = 0 ;
	double  allene0_x = 0.00000000000000000e+00 ;
	double  allene0_y = 0.00000000000000000e+00 ;
	double  allene0_z = 0.00000000000000000e+00 ;
	double  allavv_x = 0.00000000000000000e+00 ;
	double  allavv_y = 0.00000000000000000e+00 ;
	double  allavv_z = 0.00000000000000000e+00 ;
	int  allnumcp = 0 ;
{
	long  g ;
	for ((g = 0) ; 	(  g < 3 ) ; (g = 	(  g + 1 )))
	{
((enevec)[	(  g + 	(  3 * idx ) )] = 0);
((avvvec)[	(  g + 	(  3 * idx ) )] = 0);
}}((numcpvec)[	(  1 * idx )] = 0);
	for (0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  cu_cache + 	(  	(  idy * 	(  6 * cu_cache_length ) ) + 	(  l1 * 6 ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}	double  ene0_x = 0.00000000000000000e+00 ;
	double  ene0_y = 0.00000000000000000e+00 ;
	double  ene0_z = 0.00000000000000000e+00 ;
	double  aver_vx = 0.00000000000000000e+00 ;
	double  aver_vy = 0.00000000000000000e+00 ;
	double  aver_vz = 0.00000000000000000e+00 ;
{
	long  g ;
	for ((g = 0) ; 	(  g < numcp ) ; (g = 	(  g + 1 )))
	{
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[3] ;
	double  vy = (	(  a_rva + 	(  g * 6 ) ))[4] ;
	double  vz = (	(  a_rva + 	(  g * 6 ) ))[5] ;
	double  curene_x = 	(  Mass * 	(  5.00000000000000000e-01 * 	+ ( 	(  vx * vx ) ) ) ) ;
	double  curene_y = 	(  Mass * 	(  5.00000000000000000e-01 * 	+ ( 	(  vy * vy ) ) ) ) ;
	double  curene_z = 	(  Mass * 	(  5.00000000000000000e-01 * 	+ ( 	(  vz * vz ) ) ) ) ;
(ene0_x = 	(  ene0_x + curene_x ));
(ene0_y = 	(  ene0_y + curene_y ));
(ene0_z = 	(  ene0_z + curene_z ));
(aver_vx = 	(  aver_vx + vx ));
(aver_vy = 	(  aver_vy + vy ));
(aver_vz = 	(  aver_vz + vz ));
}}((enevec)[	(  3 * idx )] = 	(  (enevec)[	(  3 * idx )] + ene0_x ));
((enevec)[	(  	(  3 * idx ) + 1 )] = 	(  (enevec)[	(  	(  3 * idx ) + 1 )] + ene0_y ));
((enevec)[	(  	(  3 * idx ) + 2 )] = 	(  (enevec)[	(  	(  3 * idx ) + 2 )] + ene0_z ));
((avvvec)[	(  3 * idx )] = 	(  (avvvec)[	(  3 * idx )] + aver_vx ));
((avvvec)[	(  	(  3 * idx ) + 1 )] = 	(  (avvvec)[	(  	(  3 * idx ) + 1 )] + aver_vy ));
((avvvec)[	(  	(  3 * idx ) + 2 )] = 	(  (avvvec)[	(  	(  3 * idx ) + 2 )] + aver_vz ));
((numcpvec)[idx] = 	(  (numcpvec)[idx] + numcp ));
}	if (  	(  idx == 0 )  ){  
		{
	long  g ;
	for ((g = 0) ; 	(  g < xlen ) ; (g = 	(  g + 1 )))
	{
(allene0_x = 	(  allene0_x + (enevec)[	(  	(  3 * g ) + 0 )] ));
(allene0_y = 	(  allene0_y + (enevec)[	(  	(  3 * g ) + 1 )] ));
(allene0_z = 	(  allene0_z + (enevec)[	(  	(  3 * g ) + 2 )] ));
(allavv_x = 	(  allavv_x + (avvvec)[	(  	(  3 * g ) + 0 )] ));
(allavv_y = 	(  allavv_y + (avvvec)[	(  	(  3 * g ) + 1 )] ));
(allavv_z = 	(  allavv_z + (avvvec)[	(  	(  3 * g ) + 2 )] ));
(allnumcp = 	(  allnumcp + (numcpvec)[g] ));
}}((	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[0] = 	(  (	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[0] + allene0_x ));
((	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[1] = 	(  (	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[1] + allene0_y ));
((	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[2] = 	(  (	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[2] + allene0_z ));
((	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[3] = 	(  (	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[3] + allavv_x ));
((	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[4] = 	(  (	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[4] + allavv_y ));
((	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[5] = 	(  (	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[5] + allavv_z ));
((	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[6] = 	(  (	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[6] + allnumcp ));

	}else{
		0;

	 }

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
			int  Midx = 	floor ( (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[0] ) ;
	int  Midy = 	floor ( (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[1] ) ;
	int  Midz = 	floor ( (	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ))[2] ) ;
	long  lg = 0 ;
	double  allene0_x = 0.00000000000000000e+00 ;
	double  allene0_y = 0.00000000000000000e+00 ;
	double  allene0_z = 0.00000000000000000e+00 ;
	double  allavv_x = 0.00000000000000000e+00 ;
	double  allavv_y = 0.00000000000000000e+00 ;
	double  allavv_z = 0.00000000000000000e+00 ;
	int  allnumcp = 0 ;
{
	long  g ;
	for ((g = 0) ; 	(  g < 3 ) ; (g = 	(  g + 1 )))
	{
((enevec)[	(  g + 	(  3 * idx ) )] = 0);
((avvvec)[	(  g + 	(  3 * idx ) )] = 0);
}}((numcpvec)[	(  1 * idx )] = 0);
	for (0 ; 	(  	(  	(  idx * 1 ) + lg ) < load0 ) ; (lg = 	(  lg + 	(  xlen * 1 ) )))
	{
	double   a_rva  [	(  1 * 6 )];	int  idx_all_base = 	(  	(  idx * 1 ) + lg ) ;
	int  numcp = 1 ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < numcp ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 6 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  a_rva + 	(  0 * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )] = (	(  	(  inoutput + 	(  grid_base_offset + 	(  6 * 	(  allgid * grid_cache_len ) ) ) ) + 	(  idx_all_base * 6 ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}	double  ene0_x = 0.00000000000000000e+00 ;
	double  ene0_y = 0.00000000000000000e+00 ;
	double  ene0_z = 0.00000000000000000e+00 ;
	double  aver_vx = 0.00000000000000000e+00 ;
	double  aver_vy = 0.00000000000000000e+00 ;
	double  aver_vz = 0.00000000000000000e+00 ;
{
	long  g ;
	for ((g = 0) ; 	(  g < numcp ) ; (g = 	(  g + 1 )))
	{
	double  vx = (	(  a_rva + 	(  g * 6 ) ))[3] ;
	double  vy = (	(  a_rva + 	(  g * 6 ) ))[4] ;
	double  vz = (	(  a_rva + 	(  g * 6 ) ))[5] ;
	double  curene_x = 	(  Mass * 	(  5.00000000000000000e-01 * 	+ ( 	(  vx * vx ) ) ) ) ;
	double  curene_y = 	(  Mass * 	(  5.00000000000000000e-01 * 	+ ( 	(  vy * vy ) ) ) ) ;
	double  curene_z = 	(  Mass * 	(  5.00000000000000000e-01 * 	+ ( 	(  vz * vz ) ) ) ) ;
(ene0_x = 	(  ene0_x + curene_x ));
(ene0_y = 	(  ene0_y + curene_y ));
(ene0_z = 	(  ene0_z + curene_z ));
(aver_vx = 	(  aver_vx + vx ));
(aver_vy = 	(  aver_vy + vy ));
(aver_vz = 	(  aver_vz + vz ));
}}((enevec)[	(  3 * idx )] = 	(  (enevec)[	(  3 * idx )] + ene0_x ));
((enevec)[	(  	(  3 * idx ) + 1 )] = 	(  (enevec)[	(  	(  3 * idx ) + 1 )] + ene0_y ));
((enevec)[	(  	(  3 * idx ) + 2 )] = 	(  (enevec)[	(  	(  3 * idx ) + 2 )] + ene0_z ));
((avvvec)[	(  3 * idx )] = 	(  (avvvec)[	(  3 * idx )] + aver_vx ));
((avvvec)[	(  	(  3 * idx ) + 1 )] = 	(  (avvvec)[	(  	(  3 * idx ) + 1 )] + aver_vy ));
((avvvec)[	(  	(  3 * idx ) + 2 )] = 	(  (avvvec)[	(  	(  3 * idx ) + 2 )] + aver_vz ));
((numcpvec)[idx] = 	(  (numcpvec)[idx] + numcp ));
}	if (  	(  idx == 0 )  ){  
		{
	long  g ;
	for ((g = 0) ; 	(  g < xlen ) ; (g = 	(  g + 1 )))
	{
(allene0_x = 	(  allene0_x + (enevec)[	(  	(  3 * g ) + 0 )] ));
(allene0_y = 	(  allene0_y + (enevec)[	(  	(  3 * g ) + 1 )] ));
(allene0_z = 	(  allene0_z + (enevec)[	(  	(  3 * g ) + 2 )] ));
(allavv_x = 	(  allavv_x + (avvvec)[	(  	(  3 * g ) + 0 )] ));
(allavv_y = 	(  allavv_y + (avvvec)[	(  	(  3 * g ) + 1 )] ));
(allavv_z = 	(  allavv_z + (avvvec)[	(  	(  3 * g ) + 2 )] ));
(allnumcp = 	(  allnumcp + (numcpvec)[g] ));
}}((	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[0] = 	(  (	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[0] + allene0_x ));
((	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[1] = 	(  (	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[1] + allene0_y ));
((	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[2] = 	(  (	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[2] + allene0_z ));
((	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[3] = 	(  (	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[3] + allavv_x ));
((	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[4] = 	(  (	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[4] + allavv_y ));
((	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[5] = 	(  (	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[5] + allavv_z ));
((	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[6] = 	(  (	(  FoutEN + 	(  	(  	(  	(  NUM_SPEC * 7 ) * 	(  idy * 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  ZLEN + 	(  2 * ovlp ) ) ) ) ) ) + 	(  0 + 	(  	(  NUM_SPEC * 7 ) * 	(  	(  Midx + ovlp ) + 	(  	(  XLEN + 	(  2 * ovlp ) ) * 	(  	(  Midy + ovlp ) + 	(  	(  YLEN + 	(  2 * ovlp ) ) * 	(  Midz + ovlp ) ) ) ) ) ) ) ) + 	(  SPEC * 7 ) ) ))[6] + allnumcp ));

	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  load0 != new_load )  ){  
		((xyzw)[	(  4 * 	(  	(  idy * numgrid ) + allgid ) )] = new_load);

	}else{
		0;

	 }
}}}
