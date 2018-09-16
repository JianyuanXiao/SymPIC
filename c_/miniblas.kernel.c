
#include <math.h>
#include <assert.h>
#include <stdio.h>
#define IDX_OPT_MAX 1
void  c_blas_yiszero_synced_scmc_kernel (double *  y ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
void  c_blas_yiszero_scmc_kernel (double *  y ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
}}}}}}}}}}}
void  c_blas_yisconst_scmc_kernel (double *  y ,double  a ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
}}}}}}}}}}}
void  c_blas_get_ITG_Potential_scmc_kernel (double *  y ,double *  x ,double *  u ,double  minus_over_q_e ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
		0;

	 }
}}}}}}}}}}}
void  c_blas_invy_scmc_kernel (double *  y ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
}}}}}}}}}}}
void  c_blas_yisax_scmc_kernel (double *  y ,double *  x ,double  a ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
}}}}}}}}}}}
void  c_blas_axpy_scmc_kernel (double *  y ,double *  x ,double  a ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
}}}}}}}}}}}
void  c_blas_axpby_scmc_kernel (double *  y ,double *  x ,double  a ,double  b ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
}}}}}}}}}}}
void  c_blas_mulxy_scmc_kernel (double *  y ,double *  x ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
}}}}}}}}}}}
void  c_blas_findmax_scmc_kernel (double *  y ,double *  rdcd ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
}}}}}}}}}}((reduce_tmp_arr)[idx] = reduce_tmp);
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
void  c_blas_dot_scmc_kernel (double *  y ,double *  x ,double *  rdcd ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
}}}}}}}}}}((reduce_tmp_arr)[idx] = reduce_tmp);
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
void  c_blas_sum_scmc_kernel (double *  y ,double *  rdcd ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
}}}}}}}}}}((reduce_tmp_arr)[idx] = reduce_tmp);
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
