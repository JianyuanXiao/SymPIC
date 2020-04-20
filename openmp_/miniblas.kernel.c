#include <omp.h> 
#include <math.h>

#include <math.h>
#include <assert.h>
#include <stdio.h>
#define IDX_OPT_MAX 1
void  openmp_blas_yiszero_synced_scmc_kernel (double *  y ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / y_cpu_core ) + 1 ) ;
	const long  LOCAL_CACHE_LEN = 128 ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	double   zeros  [LOCAL_CACHE_LEN];	long  lg = 0 ;
	for ((lg = 0) ; 	(  	(  lg + idx ) < LOCAL_CACHE_LEN ) ; (lg = 	(  lg + xlen )))
	{
((zeros)[	(  lg + idx )] = 0);
}{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	long  blk_offset_t1 = 	(  blk_all_len * i ) ;
	long  j = 0 ;
	for ((j = 0) ; 	(  j < blk_all_len ) ; (j = 	(  j + LOCAL_CACHE_LEN )))
	{
	int  numcp = ((	(  	(  j + LOCAL_CACHE_LEN ) < blk_all_len ))?(LOCAL_CACHE_LEN):(	(  blk_all_len - j ))) ;
{
	long  Gll_P9918 ;
	for ((Gll_P9918 = 0) ; 	(  Gll_P9918 < numcp ) ; (Gll_P9918 = 	(  Gll_P9918 + 1 )))
	{
((	(  y + 	(  blk_offset_t1 + j ) ))[Gll_P9918] = (zeros)[Gll_P9918]);
}}}}}}
void  openmp_blas_mulxy_numele3_scmc_kernel (double *  y ,double *  x ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / y_cpu_core ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len_0 = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	long  blk_all_len_1 = 	(  xb * 	(  yb * 	(  zb * 3 ) ) ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	long  j = 0 ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  blk_offset_0 = 	(  	(  blk_all_len_0 * i ) + 	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ) ;
	long  blk_offset_1 = 	(  	(  blk_all_len_1 * i ) + 	(  0 + 	(  3 * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ) ;
{
	long  g = 0 ;
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * num_ele ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
	int  cur_id = 	(  realidx % num_ele ) ;
	int  realidx_1 = 	(  cur_id + 	(  3 * 	(  realidx / num_ele ) ) ) ;
	if (  	(  cur_id < 3 )  ){  
		((y)[	(  blk_offset_0 + realidx )] = 	(  (y)[	(  blk_offset_0 + realidx )] * (x)[	(  blk_offset_1 + realidx_1 )] ));

	}else{
		0;

	 }
}}}}}}}}}}}
void  openmp_blas_yiszero_scmc_kernel (double *  y ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / y_cpu_core ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	double   reduce_tmp_arr  [IDX_OPT_MAX];	double  reduce_tmp = 0.00000000000000000e+00 ;
{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	long  j = 0 ;
	if (  	(  blk_all_len <= 1 )  ){  
			double   fast_y  [1];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((fast_y)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  y + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
{
	long  realidx ;
	for ((realidx = 0) ; 	(  realidx < 	(  num_ele * XLEN ) ) ; (realidx = 	(  realidx + 1 )))
	{
((fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] = 0);
}}}}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  y + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (fast_y)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  blk_offset_t1 = 	(  blk_all_len * i ) ;
	long  blk_offset = 	(  	(  blk_all_len * i ) + 	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ) ;
{
	long  g = 0 ;
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * num_ele ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
((y)[	(  blk_offset + realidx )] = 0);
}}}}}}}}
	 }
}}}
void  openmp_blas_yisconst_scmc_kernel (double *  y ,double  a ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / y_cpu_core ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	double   reduce_tmp_arr  [IDX_OPT_MAX];	double  reduce_tmp = 0.00000000000000000e+00 ;
{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	long  j = 0 ;
	if (  	(  blk_all_len <= 1 )  ){  
			double   fast_y  [1];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((fast_y)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  y + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
{
	long  realidx ;
	for ((realidx = 0) ; 	(  realidx < 	(  num_ele * XLEN ) ) ; (realidx = 	(  realidx + 1 )))
	{
((fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] = a);
}}}}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  y + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (fast_y)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  blk_offset_t1 = 	(  blk_all_len * i ) ;
	long  blk_offset = 	(  	(  blk_all_len * i ) + 	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ) ;
{
	long  g = 0 ;
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * num_ele ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
((y)[	(  blk_offset + realidx )] = a);
}}}}}}}}
	 }
}}}
void  openmp_blas_get_ITG_Potential_scmc_kernel (double *  y ,double *  x ,double *  u ,double  minus_over_q_e ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / y_cpu_core ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	double   reduce_tmp_arr  [IDX_OPT_MAX];	double  reduce_tmp = 0.00000000000000000e+00 ;
{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	long  j = 0 ;
	if (  	(  blk_all_len <= 1 )  ){  
			double   fast_y  [1];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((fast_y)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  y + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	double   fast_x  [1];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((fast_x)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  x + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	double   fast_u  [1];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((fast_u)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  u + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
{
	long  realidx ;
	for ((realidx = 0) ; 	(  realidx < 	(  num_ele * XLEN ) ) ; (realidx = 	(  realidx + 1 )))
	{
	if (  	(  	(  (fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] > 0 ) && 	(  (fast_u)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] > 0 ) )  ){  
		((fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] = 	(  minus_over_q_e * 	(  (fast_x)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] * 	log ( 	(  (fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] / (fast_u)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] ) ) ) ));

	}else{
		((fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] = 0);

	 }
}}}}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  y + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (fast_y)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  blk_offset_t1 = 	(  blk_all_len * i ) ;
	long  blk_offset = 	(  	(  blk_all_len * i ) + 	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ) ;
{
	long  g = 0 ;
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * num_ele ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
	if (  	(  	(  (y)[	(  blk_offset + realidx )] > 0 ) && 	(  (u)[	(  blk_offset + realidx )] > 0 ) )  ){  
		((y)[	(  blk_offset + realidx )] = 	(  minus_over_q_e * 	(  (x)[	(  blk_offset + realidx )] * 	log ( 	(  (y)[	(  blk_offset + realidx )] / (u)[	(  blk_offset + realidx )] ) ) ) ));

	}else{
		((y)[	(  blk_offset + realidx )] = 0);

	 }
}}}}}}}}
	 }
}}}
void  openmp_blas_invy_scmc_kernel (double *  y ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / y_cpu_core ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	double   reduce_tmp_arr  [IDX_OPT_MAX];	double  reduce_tmp = 0.00000000000000000e+00 ;
{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	long  j = 0 ;
	if (  	(  blk_all_len <= 1 )  ){  
			double   fast_y  [1];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((fast_y)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  y + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
{
	long  realidx ;
	for ((realidx = 0) ; 	(  realidx < 	(  num_ele * XLEN ) ) ; (realidx = 	(  realidx + 1 )))
	{
	if (  	(  (fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] != 0 )  ){  
		((fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] = 	(  1.00000000000000000e+00 / (fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] ));

	}else{
		0;

	 }
}}}}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  y + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (fast_y)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  blk_offset_t1 = 	(  blk_all_len * i ) ;
	long  blk_offset = 	(  	(  blk_all_len * i ) + 	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ) ;
{
	long  g = 0 ;
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * num_ele ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
	if (  	(  (y)[	(  blk_offset + realidx )] != 0 )  ){  
		((y)[	(  blk_offset + realidx )] = 	(  1.00000000000000000e+00 / (y)[	(  blk_offset + realidx )] ));

	}else{
		0;

	 }
}}}}}}}}
	 }
}}}
void  openmp_blas_yisax_scmc_kernel (double *  y ,double *  x ,double  a ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / y_cpu_core ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	double   reduce_tmp_arr  [IDX_OPT_MAX];	double  reduce_tmp = 0.00000000000000000e+00 ;
{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	long  j = 0 ;
	if (  	(  blk_all_len <= 1 )  ){  
			double   fast_y  [1];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((fast_y)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  y + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	double   fast_x  [1];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((fast_x)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  x + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
{
	long  realidx ;
	for ((realidx = 0) ; 	(  realidx < 	(  num_ele * XLEN ) ) ; (realidx = 	(  realidx + 1 )))
	{
((fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] = 	(  a * (fast_x)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] ));
}}}}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  y + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (fast_y)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  blk_offset_t1 = 	(  blk_all_len * i ) ;
	long  blk_offset = 	(  	(  blk_all_len * i ) + 	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ) ;
{
	long  g = 0 ;
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * num_ele ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
((y)[	(  blk_offset + realidx )] = 	(  a * (x)[	(  blk_offset + realidx )] ));
}}}}}}}}
	 }
}}}
void  openmp_blas_axpy_scmc_kernel (double *  y ,double *  x ,double  a ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / y_cpu_core ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	double   reduce_tmp_arr  [IDX_OPT_MAX];	double  reduce_tmp = 0.00000000000000000e+00 ;
{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	long  j = 0 ;
	if (  	(  blk_all_len <= 1 )  ){  
			double   fast_y  [1];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((fast_y)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  y + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	double   fast_x  [1];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((fast_x)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  x + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
{
	long  realidx ;
	for ((realidx = 0) ; 	(  realidx < 	(  num_ele * XLEN ) ) ; (realidx = 	(  realidx + 1 )))
	{
((fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] = 	(  (fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] + 	(  a * (fast_x)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] ) ));
}}}}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  y + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (fast_y)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  blk_offset_t1 = 	(  blk_all_len * i ) ;
	long  blk_offset = 	(  	(  blk_all_len * i ) + 	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ) ;
{
	long  g = 0 ;
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * num_ele ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
((y)[	(  blk_offset + realidx )] = 	(  (y)[	(  blk_offset + realidx )] + 	(  a * (x)[	(  blk_offset + realidx )] ) ));
}}}}}}}}
	 }
}}}
void  openmp_blas_axpby_scmc_kernel (double *  y ,double *  x ,double  a ,double  b ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / y_cpu_core ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	double   reduce_tmp_arr  [IDX_OPT_MAX];	double  reduce_tmp = 0.00000000000000000e+00 ;
{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	long  j = 0 ;
	if (  	(  blk_all_len <= 1 )  ){  
			double   fast_y  [1];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((fast_y)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  y + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	double   fast_x  [1];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((fast_x)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  x + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
{
	long  realidx ;
	for ((realidx = 0) ; 	(  realidx < 	(  num_ele * XLEN ) ) ; (realidx = 	(  realidx + 1 )))
	{
((fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] = 	(  	(  a * (fast_x)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] ) + 	(  b * (fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] ) ));
}}}}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  y + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (fast_y)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  blk_offset_t1 = 	(  blk_all_len * i ) ;
	long  blk_offset = 	(  	(  blk_all_len * i ) + 	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ) ;
{
	long  g = 0 ;
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * num_ele ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
((y)[	(  blk_offset + realidx )] = 	(  	(  a * (x)[	(  blk_offset + realidx )] ) + 	(  b * (y)[	(  blk_offset + realidx )] ) ));
}}}}}}}}
	 }
}}}
void  openmp_blas_mulxy_scmc_kernel (double *  y ,double *  x ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / y_cpu_core ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	double   reduce_tmp_arr  [IDX_OPT_MAX];	double  reduce_tmp = 0.00000000000000000e+00 ;
{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	long  j = 0 ;
	if (  	(  blk_all_len <= 1 )  ){  
			double   fast_y  [1];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((fast_y)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  y + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	double   fast_x  [1];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((fast_x)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  x + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
{
	long  realidx ;
	for ((realidx = 0) ; 	(  realidx < 	(  num_ele * XLEN ) ) ; (realidx = 	(  realidx + 1 )))
	{
((fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] = 	(  (fast_x)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] * (fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] ));
}}}}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  y + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (fast_y)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  blk_offset_t1 = 	(  blk_all_len * i ) ;
	long  blk_offset = 	(  	(  blk_all_len * i ) + 	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ) ;
{
	long  g = 0 ;
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * num_ele ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
((y)[	(  blk_offset + realidx )] = 	(  (x)[	(  blk_offset + realidx )] * (y)[	(  blk_offset + realidx )] ));
}}}}}}}}
	 }
}}}
void  openmp_blas_findmax_scmc_kernel (double *  y ,double *  rdcd ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / y_cpu_core ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	double   reduce_tmp_arr  [IDX_OPT_MAX];	double  reduce_tmp = 0.00000000000000000e+00 ;
{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	long  j = 0 ;
	if (  	(  blk_all_len <= 1 )  ){  
			double   fast_y  [1];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((fast_y)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  y + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
{
	long  realidx ;
	for ((realidx = 0) ; 	(  realidx < 	(  num_ele * XLEN ) ) ; (realidx = 	(  realidx + 1 )))
	{
(reduce_tmp = ((	(  	fabs ( (fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] ) > reduce_tmp ))?(	fabs ( (fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] )):(reduce_tmp)));
}}}}}}}}
	}else{
		{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  blk_offset_t1 = 	(  blk_all_len * i ) ;
	long  blk_offset = 	(  	(  blk_all_len * i ) + 	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ) ;
{
	long  g = 0 ;
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * num_ele ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
(reduce_tmp = ((	(  	fabs ( (y)[	(  blk_offset + realidx )] ) > reduce_tmp ))?(	fabs ( (y)[	(  blk_offset + realidx )] )):(reduce_tmp)));
}}}}}}}}
	 }
}}((reduce_tmp_arr)[idx] = reduce_tmp);
	if (  	(  idx == 0 )  ){  
		{
	long  i1 ;
	for ((i1 = 1) ; 	(  i1 < IDX_OPT_MAX ) ; (i1 = 	(  i1 + 1 )))
	{
(reduce_tmp = ((	(  	fabs ( (reduce_tmp_arr)[i1] ) > reduce_tmp ))?(	fabs ( (reduce_tmp_arr)[i1] )):(reduce_tmp)));
}}((rdcd)[idy] = reduce_tmp);

	}else{
		0;

	 }
}
void  openmp_blas_dot_scmc_kernel (double *  y ,double *  x ,double *  rdcd ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / y_cpu_core ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	double   reduce_tmp_arr  [IDX_OPT_MAX];	double  reduce_tmp = 0.00000000000000000e+00 ;
{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	long  j = 0 ;
	if (  	(  blk_all_len <= 1 )  ){  
			double   fast_y  [1];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((fast_y)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  y + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	double   fast_x  [1];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((fast_x)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  x + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
{
	long  realidx ;
	for ((realidx = 0) ; 	(  realidx < 	(  num_ele * XLEN ) ) ; (realidx = 	(  realidx + 1 )))
	{
(reduce_tmp = 	(  reduce_tmp + 	(  (fast_x)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] * (fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] ) ));
}}}}}}}}
	}else{
		{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  blk_offset_t1 = 	(  blk_all_len * i ) ;
	long  blk_offset = 	(  	(  blk_all_len * i ) + 	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ) ;
{
	long  g = 0 ;
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * num_ele ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
(reduce_tmp = 	(  reduce_tmp + 	(  (x)[	(  blk_offset + realidx )] * (y)[	(  blk_offset + realidx )] ) ));
}}}}}}}}
	 }
}}((reduce_tmp_arr)[idx] = reduce_tmp);
	if (  	(  idx == 0 )  ){  
		{
	long  i1 ;
	for ((i1 = 1) ; 	(  i1 < IDX_OPT_MAX ) ; (i1 = 	(  i1 + 1 )))
	{
(reduce_tmp = 	(  reduce_tmp + 	(  1 * (reduce_tmp_arr)[i1] ) ));
}}((rdcd)[idy] = reduce_tmp);

	}else{
		0;

	 }
}
void  openmp_blas_sum_scmc_kernel (double *  y ,double *  rdcd ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / y_cpu_core ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	double   reduce_tmp_arr  [IDX_OPT_MAX];	double  reduce_tmp = 0.00000000000000000e+00 ;
{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	long  j = 0 ;
	if (  	(  blk_all_len <= 1 )  ){  
			double   fast_y  [1];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < blk_all_len ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((fast_y)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  y + 	(  i * blk_all_len ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
{
	long  realidx ;
	for ((realidx = 0) ; 	(  realidx < 	(  num_ele * XLEN ) ) ; (realidx = 	(  realidx + 1 )))
	{
(reduce_tmp = 	(  reduce_tmp + (fast_y)[	(  	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) + realidx )] ));
}}}}}}}}
	}else{
		{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ZLEN ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < YLEN ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  blk_offset_t1 = 	(  blk_all_len * i ) ;
	long  blk_offset = 	(  	(  blk_all_len * i ) + 	(  0 + 	(  num_ele * 	(  ovlp + 	(  xb * 	(  	(  xyzy + ovlp ) + 	(  yb * 	(  xyzz + ovlp ) ) ) ) ) ) ) ) ;
{
	long  g = 0 ;
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * num_ele ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
(reduce_tmp = 	(  reduce_tmp + (y)[	(  blk_offset + realidx )] ));
}}}}}}}}
	 }
}}((reduce_tmp_arr)[idx] = reduce_tmp);
	if (  	(  idx == 0 )  ){  
		{
	long  i1 ;
	for ((i1 = 1) ; 	(  i1 < IDX_OPT_MAX ) ; (i1 = 	(  i1 + 1 )))
	{
(reduce_tmp = 	(  reduce_tmp + (reduce_tmp_arr)[i1] ));
}}((rdcd)[idy] = reduce_tmp);

	}else{
		0;

	 }
}
