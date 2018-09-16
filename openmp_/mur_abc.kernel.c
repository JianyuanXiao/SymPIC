#include <omp.h> 
#include <math.h>

#include <math.h>
#include <assert.h>
#include <stdio.h>
#define IDX_OPT_MAX 1
void  openmp_yee_abc__scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
}
void  openmp_yee_pec__scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
}
void  openmp_yee_damp__scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
}
void  openmp_yee_abc_x_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_x & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  1 + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_x >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  	(  XLEN - 2 ) + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
}
void  openmp_yee_pec_x_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_x & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_x >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
}
void  openmp_yee_damp_x_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_x & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_x >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
}
void  openmp_yee_abc_y_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  1 + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  	(  YLEN - 2 ) + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
}
void  openmp_yee_pec_y_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
}
void  openmp_yee_damp_y_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
}
void  openmp_yee_abc_z_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  1 + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  	(  ZLEN - 2 ) + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
}
void  openmp_yee_pec_z_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
}
void  openmp_yee_damp_z_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
}
void  openmp_yee_abc_xy_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  1 + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  	(  YLEN - 2 ) + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  cur_rank_x & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  1 + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  1 + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  1 + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  1 + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  	(  YLEN - 2 ) + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_x >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  	(  XLEN - 2 ) + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  	(  XLEN - 2 ) + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  1 + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  	(  XLEN - 2 ) + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  	(  YLEN - 2 ) + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
}
void  openmp_yee_pec_xy_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  cur_rank_x & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_x >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
}
void  openmp_yee_damp_xy_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  cur_rank_x & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_x >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
}
void  openmp_yee_abc_xz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  1 + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  	(  ZLEN - 2 ) + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  cur_rank_x & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  1 + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  1 + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  1 + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  1 + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  	(  ZLEN - 2 ) + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_x >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  	(  XLEN - 2 ) + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  	(  XLEN - 2 ) + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  1 + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  	(  XLEN - 2 ) + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  	(  ZLEN - 2 ) + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
}
void  openmp_yee_pec_xz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  cur_rank_x & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_x >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
}
void  openmp_yee_damp_xz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  cur_rank_x & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_x >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
}
void  openmp_yee_abc_yz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  1 + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  	(  ZLEN - 2 ) + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  1 + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  1 + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  1 + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  1 + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  	(  ZLEN - 2 ) + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  	(  YLEN - 2 ) + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  	(  YLEN - 2 ) + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  1 + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  	(  YLEN - 2 ) + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  	(  ZLEN - 2 ) + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
}
void  openmp_yee_pec_yz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
}
void  openmp_yee_damp_yz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
}
void  openmp_yee_abc_xyz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  1 + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  	(  ZLEN - 2 ) + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  1 + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  1 + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  1 + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  1 + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  	(  ZLEN - 2 ) + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  	(  YLEN - 2 ) + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  	(  YLEN - 2 ) + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  1 + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  	(  YLEN - 2 ) + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  	(  ZLEN - 2 ) + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  cur_rank_x & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  1 + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  1 + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  1 + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  1 + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  	(  ZLEN - 2 ) + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  1 + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  1 + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  1 + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  1 + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  1 + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  1 + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  1 + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  	(  ZLEN - 2 ) + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  1 + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  	(  YLEN - 2 ) + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  1 + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  	(  YLEN - 2 ) + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  1 + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  1 + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  	(  YLEN - 2 ) + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  	(  ZLEN - 2 ) + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_x >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  	(  XLEN - 2 ) + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  1.00000000000000000e+00 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  	(  XLEN - 2 ) + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  1 + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  	(  XLEN - 2 ) + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  	(  ZLEN - 2 ) + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  	(  XLEN - 2 ) + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  1 + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  	(  XLEN - 2 ) + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  1 + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  1 + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  	(  XLEN - 2 ) + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  1 + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  	(  ZLEN - 2 ) + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  	(  XLEN - 2 ) + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  	(  YLEN - 2 ) + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  7.07106781186547462e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  	(  XLEN - 2 ) + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  	(  YLEN - 2 ) + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  1 + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	double  tmpval = 0.00000000000000000e+00 ;
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  	(  XLEN - 2 ) + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  	(  YLEN - 2 ) + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}{
	long  realidx1 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  	(  ZLEN - 2 ) + ovlp ) ) ) ) ) ) ) ;
(tmpval = 	(  tmpval + 	(  5.77350269189625842e-01 * 	(  (inEB)[	(  blk_offset + realidx1 )] - (inEB)[	(  blk_offset + realidx0 )] ) ) ));
}((outEB)[	(  blk_offset + realidx0 )] = 	(  	(  deltat * tmpval ) + (inEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }

	}else{
		0;

	 }
}
void  openmp_yee_pec_xyz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  cur_rank_x & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_x >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 0);
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }

	}else{
		0;

	 }
}
void  openmp_yee_damp_xyz_scmc_kernel (double *  outEB ,double *  inEB ,int *  cur_rankx ,int *  cur_ranky ,int *  cur_rankz ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  damp_vars ,double  deltat ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_offset = 	(  idy * blk_all_len ) ;
	int  cur_rank_x = (cur_rankx)[idy] ;
	int  cur_rank_y = (cur_ranky)[idy] ;
	int  cur_rank_z = (cur_rankz)[idy] ;
	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  cur_rank_x & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  1 - 0 ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 0 ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_x >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  cur_rank_y & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  1 - 0 ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 0 ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  	(  cur_rank_y >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}	if (  	(  cur_rank_z & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  1 - 0 ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 0 ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }
	if (  	(  	(  cur_rank_z >> 1 ) & 1 )  ){  
		{
	long  inner_g_static = 0 ;
	long  inner_xrange = 	(  XLEN - 	(  XLEN - 1 ) ) ;
	long  inner_yrange = 	(  YLEN - 	(  YLEN - 1 ) ) ;
	long  inner_zrange = 	(  ZLEN - 	(  ZLEN - 1 ) ) ;
	long  inner_allmax = 	(  inner_xrange * 	(  inner_yrange * inner_zrange ) ) ;
	for (0 ; 	(  	(  inner_g_static + idx ) < inner_allmax ) ; (inner_g_static = 	(  inner_g_static + xlen )))
	{
	long  bxyzx = 	(  	(  inner_g_static + idx ) % inner_xrange ) ;
	long  bxyzy = 	(  	(  	(  inner_g_static + idx ) / inner_xrange ) % inner_yrange ) ;
	long  bxyzz = 	(  	(  inner_g_static + idx ) / 	(  inner_xrange * inner_yrange ) ) ;
	long  xyzx = bxyzx ;
	long  xyzy = bxyzy ;
	long  xyzz = bxyzz ;
(xyzx = 	(  xyzx + 	(  XLEN - 1 ) ));
(xyzy = 	(  xyzy + 	(  YLEN - 1 ) ));
(xyzz = 	(  xyzz + 	(  ZLEN - 1 ) ));
{
	long  l ;
	for ((l = 0) ; 	(  l < 3 ) ; (l = 	(  l + 1 )))
	{
{
	long  realidx0 = 	(  l + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ;
((outEB)[	(  blk_offset + realidx0 )] = 	(  damp_vars * (outEB)[	(  blk_offset + realidx0 )] ));
}}}}}
	}else{
		0;

	 }

	}else{
		0;

	 }

	}else{
		0;

	 }
}
