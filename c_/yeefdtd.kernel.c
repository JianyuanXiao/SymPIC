
#include <math.h>
#include <assert.h>
#include <stdio.h>
#define IDX_OPT_MAX 1
void  c_Yee_FDTD_Curl_E_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
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
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
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
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * 3 ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
	long  l = 	(  realidx % 3 ) ;
	long  xidx = 	(  realidx / 3 ) ;
(realidx = 	(  	(  	(  realidx / 3 ) * num_ele ) + l ));
	if (  	(  l == 0 )  ){  
			(  (outEB)[	(  blk_offset + realidx )] -= 	(  DT * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) );

	}else{
			if (  	(  l == 1 )  ){  
			(  (outEB)[	(  blk_offset + realidx )] -= 	(  DT * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) );

	}else{
			if (  	(  l == 2 )  ){  
			(  (outEB)[	(  blk_offset + realidx )] -= 	(  DT * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) );

	}else{
		0;

	 }

	 }

	 }
}}}}}}}}}}
void  c_Yee_FDTD_Curl_E_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
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
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
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
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * 3 ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
	long  l = 	(  realidx % 3 ) ;
	long  xidx = 	(  realidx / 3 ) ;
(realidx = 	(  	(  	(  realidx / 3 ) * num_ele ) + l ));
	if (  	(  l == 0 )  ){  
			(  (outEB)[	(  blk_offset + realidx )] -= 	(  DT * 	(  	(  1.12500000000000000e+00 * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) - 	(  	(  	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  2 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  2 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) / 24 ) ) ) );

	}else{
			if (  	(  l == 1 )  ){  
			(  (outEB)[	(  blk_offset + realidx )] -= 	(  DT * 	(  	(  1.12500000000000000e+00 * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) - 	(  	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  2 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 2 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) / 24 ) ) ) );

	}else{
			if (  	(  l == 2 )  ){  
			(  (outEB)[	(  blk_offset + realidx )] -= 	(  DT * 	(  	(  1.12500000000000000e+00 * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) - 	(  	(  	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 2 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  2 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) / 24 ) ) ) );

	}else{
		0;

	 }

	 }

	 }
}}}}}}}}}}
void  c_Yee_FDTD_Curl_B_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
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
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
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
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * 3 ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
	long  l = 	(  realidx % 3 ) ;
	long  xidx = 	(  realidx / 3 ) ;
(realidx = 	(  	(  	(  realidx / 3 ) * num_ele ) + l ));
	if (  	(  l == 0 )  ){  
			(  (outEB)[	(  blk_offset + realidx )] -= 	(  DT * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) );

	}else{
			if (  	(  l == 1 )  ){  
			(  (outEB)[	(  blk_offset + realidx )] -= 	(  DT * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) );

	}else{
			if (  	(  l == 2 )  ){  
			(  (outEB)[	(  blk_offset + realidx )] -= 	(  DT * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) );

	}else{
		0;

	 }

	 }

	 }
}}}}}}}}}}
void  c_Yee_FDTD_Curl_B_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
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
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
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
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * 3 ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
	long  l = 	(  realidx % 3 ) ;
	long  xidx = 	(  realidx / 3 ) ;
(realidx = 	(  	(  	(  realidx / 3 ) * num_ele ) + l ));
	if (  	(  l == 0 )  ){  
			(  (outEB)[	(  blk_offset + realidx )] -= 	(  DT * 	(  	(  1.12500000000000000e+00 * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) - 	(  	(  	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -2 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -2 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) / 24 ) ) ) );

	}else{
			if (  	(  l == 1 )  ){  
			(  (outEB)[	(  blk_offset + realidx )] -= 	(  DT * 	(  	(  1.12500000000000000e+00 * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) - 	(  	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -2 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -2 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) / 24 ) ) ) );

	}else{
			if (  	(  l == 2 )  ){  
			(  (outEB)[	(  blk_offset + realidx )] -= 	(  DT * 	(  	(  1.12500000000000000e+00 * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) - 	(  	(  	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -2 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -2 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) / 24 ) ) ) );

	}else{
		0;

	 }

	 }

	 }
}}}}}}}}}}
void  c_Yee_FDTD_Grad_BWD_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
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
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
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
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * 3 ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
	long  l = 	(  realidx % 3 ) ;
	long  xidx = 	(  realidx / 3 ) ;
(realidx = 	(  	(  	(  realidx / 3 ) * num_ele ) + l ));
	if (  	(  l == 0 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ));

	}else{
			if (  	(  l == 1 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ));

	}else{
			if (  	(  l == 2 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ));

	}else{
		0;

	 }

	 }

	 }
}}}}}}}}}}
void  c_Yee_FDTD_Grad_BWD_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
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
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
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
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * 3 ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
	long  l = 	(  realidx % 3 ) ;
	long  xidx = 	(  realidx / 3 ) ;
(realidx = 	(  	(  	(  realidx / 3 ) * num_ele ) + l ));
	if (  	(  l == 0 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  	(  1.12500000000000000e+00 * 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) - 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -2 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) / 24 ) ));

	}else{
			if (  	(  l == 1 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  	(  1.12500000000000000e+00 * 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) - 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -2 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) / 24 ) ));

	}else{
			if (  	(  l == 2 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  	(  1.12500000000000000e+00 * 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) - 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -2 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) / 24 ) ));

	}else{
		0;

	 }

	 }

	 }
}}}}}}}}}}
void  c_Yee_FDTD_Grad_FWD_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
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
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
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
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * 3 ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
	long  l = 	(  realidx % 3 ) ;
	long  xidx = 	(  realidx / 3 ) ;
(realidx = 	(  	(  	(  realidx / 3 ) * num_ele ) + l ));
	if (  	(  l == 0 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ));

	}else{
			if (  	(  l == 1 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ));

	}else{
			if (  	(  l == 2 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ));

	}else{
		0;

	 }

	 }

	 }
}}}}}}}}}}
void  c_Yee_FDTD_Grad_FWD_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
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
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
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
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * 3 ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
	long  l = 	(  realidx % 3 ) ;
	long  xidx = 	(  realidx / 3 ) ;
(realidx = 	(  	(  	(  realidx / 3 ) * num_ele ) + l ));
	if (  	(  l == 0 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  	(  1.12500000000000000e+00 * 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) - 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 2 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) / 24 ) ));

	}else{
			if (  	(  l == 1 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  	(  1.12500000000000000e+00 * 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) - 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  2 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) / 24 ) ));

	}else{
			if (  	(  l == 2 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  	(  1.12500000000000000e+00 * 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) - 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  2 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) / 24 ) ));

	}else{
		0;

	 }

	 }

	 }
}}}}}}}}}}
void  c_Yee_FDTD_Curl_BWD_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
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
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
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
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * 3 ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
	long  l = 	(  realidx % 3 ) ;
	long  xidx = 	(  realidx / 3 ) ;
(realidx = 	(  	(  	(  realidx / 3 ) * num_ele ) + l ));
	if (  	(  l == 0 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ));

	}else{
			if (  	(  l == 1 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ));

	}else{
			if (  	(  l == 2 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ));

	}else{
		0;

	 }

	 }

	 }
}}}}}}}}}}
void  c_Yee_FDTD_Curl_BWD_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
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
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
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
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * 3 ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
	long  l = 	(  realidx % 3 ) ;
	long  xidx = 	(  realidx / 3 ) ;
(realidx = 	(  	(  	(  realidx / 3 ) * num_ele ) + l ));
	if (  	(  l == 0 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  	(  1.12500000000000000e+00 * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) - 	(  	(  	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -2 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -2 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) / 24 ) ));

	}else{
			if (  	(  l == 1 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  	(  1.12500000000000000e+00 * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) - 	(  	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -2 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -2 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) / 24 ) ));

	}else{
			if (  	(  l == 2 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  	(  1.12500000000000000e+00 * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) - 	(  	(  	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -2 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -2 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) / 24 ) ));

	}else{
		0;

	 }

	 }

	 }
}}}}}}}}}}
void  c_Yee_FDTD_Curl_FWD_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
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
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
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
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * 3 ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
	long  l = 	(  realidx % 3 ) ;
	long  xidx = 	(  realidx / 3 ) ;
(realidx = 	(  	(  	(  realidx / 3 ) * num_ele ) + l ));
	if (  	(  l == 0 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ));

	}else{
			if (  	(  l == 1 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ));

	}else{
			if (  	(  l == 2 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ));

	}else{
		0;

	 }

	 }

	 }
}}}}}}}}}}
void  c_Yee_FDTD_Curl_FWD_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
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
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
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
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < 	(  XLEN * 3 ) ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
	long  l = 	(  realidx % 3 ) ;
	long  xidx = 	(  realidx / 3 ) ;
(realidx = 	(  	(  	(  realidx / 3 ) * num_ele ) + l ));
	if (  	(  l == 0 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  	(  1.12500000000000000e+00 * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) - 	(  	(  	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  2 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  2 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) / 24 ) ));

	}else{
			if (  	(  l == 1 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  	(  1.12500000000000000e+00 * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) - 	(  	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  2 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 2 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) / 24 ) ));

	}else{
			if (  	(  l == 2 )  ){  
		((outEB)[	(  blk_offset + realidx )] = 	(  	(  1.12500000000000000e+00 * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) - 	(  	(  	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 2 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  2 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) / 24 ) ));

	}else{
		0;

	 }

	 }

	 }
}}}}}}}}}}
void  c_Yee_FDTD_Div_BWD_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
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
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
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
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < XLEN ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
	long  xidx = realidx ;
(realidx = 	(  realidx * num_ele ));
((outEB)[	(  blk_offset + realidx )] = 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) + 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) + 	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ));
}}}}}}}}}}
void  c_Yee_FDTD_Div_BWD_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
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
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
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
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < XLEN ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
	long  xidx = realidx ;
(realidx = 	(  realidx * num_ele ));
((outEB)[	(  blk_offset + realidx )] = 	(  	(  1.12500000000000000e+00 * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) + 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) + 	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) ) - 	(  	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -2 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) + 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -2 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) + 	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -2 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) / 24 ) ));
}}}}}}}}}}
void  c_Yee_FDTD_Div_FWD_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
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
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
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
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < XLEN ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
	long  xidx = realidx ;
(realidx = 	(  realidx * num_ele ));
((outEB)[	(  blk_offset + realidx )] = 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) + 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) + 	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ));
}}}}}}}}}}
void  c_Yee_FDTD_Div_FWD_4th_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
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
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
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
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < XLEN ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
	long  xidx = realidx ;
(realidx = 	(  realidx * num_ele ));
((outEB)[	(  blk_offset + realidx )] = 	(  	(  1.12500000000000000e+00 * 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) + 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) + 	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) ) - 	(  	(  	(  (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 2 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  0 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) + 	(  	(  (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  2 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  1 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) + 	(  (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  2 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + blk_offset_t1 ))[	(  2 + 	(  num_ele * 	(  	(  	(  xidx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) / 24 ) ));
}}}}}}}}}}
void  c_merge_current_2_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / y_cpu_core ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	long  ori_num_ele = 	(  num_ele * pscmc_num_compute_units ) ;
	long  blk_all_len = 	(  xblock * 	(  yblock * 	(  zblock * ori_num_ele ) ) ) ;
	long  blk_len = 	(  xblock * 	(  yblock * zblock ) ) ;
{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	long  lg = 0 ;
	if (  	(  idx == 0 )  ){  
		{
	long  lg ;
	for ((lg = 0) ; 	(  lg < blk_len ) ; (lg = 	(  lg + 1 )))
	{
	long  g = lg ;
	long  xx = 	(  g % xblock ) ;
	long  xy = 	(  	(  g / xblock ) % yblock ) ;
	long  xz = 	(  g / 	(  xblock * yblock ) ) ;
	long  blk_offset = 	(  blk_all_len * i ) ;
{
	long  ig ;
	for ((ig = 0) ; 	(  ig < num_ele ) ; (ig = 	(  ig + 1 )))
	{
	double  lst_n0 = 0 ;
	long  new_allid = 	(  ig + 	(  num_ele * 	(  xx + 	(  xblock * 	(  xy + 	(  yblock * xz ) ) ) ) ) ) ;
{
	long  il ;
	for ((il = 0) ; 	(  il < pscmc_num_compute_units ) ; (il = 	(  il + 1 )))
	{
	long  ori_allid = 	(  new_allid + 	(  il * 	(  blk_len * num_ele ) ) ) ;
(lst_n0 = 	(  lst_n0 + (inEB)[	(  ori_allid + blk_offset )] ));
}}((outEB)[	(  new_allid + 	(  blk_len * 	(  i * num_ele ) ) )] = lst_n0);
}}}}
	}else{
		0;

	 }
}}}
void  c_merge_current_scmc_kernel (double *  outEB ,double *  inEB ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / y_cpu_core ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	long  blk_all_len = 	(  xblock * 	(  yblock * 	(  zblock * 375 ) ) ) ;
	long  blk_len = 	(  xblock * 	(  yblock * zblock ) ) ;
{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	long  lg = 0 ;
	if (  	(  idx == 0 )  ){  
			for ((lg = 0) ; 	(  lg < blk_len ) ; (lg = 	(  lg + 1 )))
	{
	long  g = lg ;
	long  xx = 	(  g % xblock ) ;
	long  xy = 	(  	(  g / xblock ) % yblock ) ;
	long  xz = 	(  g / 	(  xblock * yblock ) ) ;
	long  blk_offset = 	(  blk_all_len * i ) ;
	double  jx = 0 ;
	double  jy = 0 ;
	double  jz = 0 ;
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
	long  local_all_id = 	(  xyzx + 	(  5 * 	(  xyzy + 	(  5 * xyzz ) ) ) ) ;
	long  curx = 	(  	(  2 - xyzx ) + xx ) ;
	long  cury = 	(  	(  2 - xyzy ) + xy ) ;
	long  curz = 	(  	(  2 - xyzz ) + xz ) ;
	long  final_all_id = 	(  local_all_id + 	(  375 * 	(  curx + 	(  xblock * 	(  cury + 	(  yblock * curz ) ) ) ) ) ) ;
	if (  	(  	(  curx >= ovlp ) && 	(  	(  curx < 	(  xblock - ovlp ) ) && 	(  	(  cury >= ovlp ) && 	(  	(  cury < 	(  yblock - ovlp ) ) && 	(  	(  curz >= ovlp ) && 	(  curz < 	(  zblock - ovlp ) ) ) ) ) ) )  ){  
		(jx = 	(  jx + (	(  inEB + blk_offset ))[	(  final_all_id + 0 )] ));
(jy = 	(  jy + (	(  inEB + blk_offset ))[	(  final_all_id + 125 )] ));
(jz = 	(  jz + (	(  inEB + blk_offset ))[	(  final_all_id + 250 )] ));

	}else{
		0;

	 }
}}}}}}	long  offset_idx = 	(  xblock * 	(  yblock * 	(  zblock * 	(  3 * i ) ) ) ) ;
((outEB)[	(  offset_idx + 	(  	(  3 * g ) + 0 ) )] = jx);
((outEB)[	(  offset_idx + 	(  	(  3 * g ) + 1 ) )] = jy);
((outEB)[	(  offset_idx + 	(  	(  3 * g ) + 2 ) )] = jz);
}
	}else{
		0;

	 }
}}}
void  c_PML_FDTD_CURL_FWD_scmc_kernel (double *  outEB ,double *  inEB ,double *  outPMLEB ,double *  inPMLEB ,int *  xoffset ,int *  yoffset ,int *  zoffset ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,double  M ,double  Q ,double  DX ,double  DY ,double  DZ ,int  abc_dir ,int  level ,int  pml_m ,double  max_sigma ,long  allxmax ,long  allymax ,long  allzmax ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / y_cpu_core ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	long  blk_all_len = 	(  xblock * 	(  yblock * 	(  zblock * num_ele ) ) ) ;
{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	long  allmax = 	(  XLEN * 	(  YLEN * ZLEN ) ) ;
	long  g = 0 ;
	int  xoffi = (xoffset)[i] ;
	int  yoffi = (yoffset)[i] ;
	int  zoffi = (zoffset)[i] ;
	int  x_use_abc = 	(  abc_dir % 2 ) ;
	int  y_use_abc = 	(  	(  abc_dir / 2 ) % 2 ) ;
	int  z_use_abc = 	(  	(  abc_dir / 4 ) % 2 ) ;
	for ((g = 0) ; 	(  g < allmax ) ; (g = 	(  g + 1 )))
	{
	long  xyzx = 	(  g % XLEN ) ;
	long  xyzy = 	(  	(  g / XLEN ) % YLEN ) ;
	long  xyzz = 	(  g / 	(  XLEN * YLEN ) ) ;
	long  blk_offset = 	(  blk_all_len * i ) ;
	if (  	(  idx == 0 )  ){  
			long  use_pml_calc = 0 ;
	long  inner_pec = 0 ;
	double  sigma_Ex = 0.00000000000000000e+00 ;
	double  sigma_Ey = 0.00000000000000000e+00 ;
	double  sigma_Ez = 0.00000000000000000e+00 ;
	long  cur_x = 	(  xoffi + xyzx ) ;
	long  cur_y = 	(  yoffi + xyzy ) ;
	long  cur_z = 	(  zoffi + xyzz ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	if (  	(  x_use_abc && 	(  	(  cur_x < level ) || 	(  cur_x >= 	(  allxmax - level ) ) ) )  ){  
			double  ocs = 	(  	(  1.00000000000000000e+00 * ((	(  cur_x < level ))?(	(  	(  level - 1 ) - cur_x )):(	(  cur_x - 	(  allxmax - level ) ))) ) / level ) ;
(sigma_Ex = 	(  max_sigma * 	pow ( ocs , pml_m ) ));
(use_pml_calc = 1);
	if (  	(  cur_x == 0 )  ){  
		(inner_pec = 1);

	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  y_use_abc && 	(  	(  cur_y < level ) || 	(  cur_y >= 	(  allymax - level ) ) ) )  ){  
			double  ocs = 	(  	(  1.00000000000000000e+00 * ((	(  cur_y < level ))?(	(  	(  level - 1 ) - cur_y )):(	(  cur_y - 	(  allymax - level ) ))) ) / level ) ;
(sigma_Ey = 	(  max_sigma * 	pow ( ocs , pml_m ) ));
(use_pml_calc = 1);
	if (  	(  cur_y == 0 )  ){  
		(inner_pec = 1);

	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  z_use_abc && 	(  	(  cur_z < level ) || 	(  cur_z >= 	(  allzmax - level ) ) ) )  ){  
			double  ocs = 	(  	(  1.00000000000000000e+00 * ((	(  cur_z < level ))?(	(  	(  level - 1 ) - cur_z )):(	(  cur_z - 	(  allzmax - level ) ))) ) / level ) ;
(sigma_Ez = 	(  max_sigma * 	pow ( ocs , pml_m ) ));
(use_pml_calc = 1);
	if (  	(  cur_z == 0 )  ){  
		(inner_pec = 1);

	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  use_pml_calc  ){  
			if (  inner_pec  ){  
		((	(  outEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 0);

	}else{
		{
	double  sgmB = sigma_Ey ;
	double  expsgmBt = 	exp ( 	- ( 	(  DT * sgmB ) ) ) ;
	double  mesgbosgbdb = ((	(  sgmB == 0 ))?(	(  DT / DY )):(	(  	(  1 - expsgmBt ) / 	(  sgmB * DY ) ))) ;
	double  dceb_A = 	(  (	(  inEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 1 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] - (	(  inEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) ;
	double  dceb_B = 	(  (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 1 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) ;
((	(  outEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  1.00000000000000000e+00 * 	(  	(  expsgmBt * (	(  outEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) + 	(  1 * 	(  -1 * 	(  mesgbosgbdb * 	(  dceb_A + dceb_B ) ) ) ) ) ));
}
	 }
	if (  inner_pec  ){  
		((	(  outPMLEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] = 0);

	}else{
		{
	double  sgmB = sigma_Ez ;
	double  expsgmBt = 	exp ( 	- ( 	(  DT * sgmB ) ) ) ;
	double  mesgbosgbdb = ((	(  sgmB == 0 ))?(	(  DT / DZ )):(	(  	(  1 - expsgmBt ) / 	(  sgmB * DZ ) ))) ;
	double  dceb_A = 	(  (	(  inEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 1 ) + ovlp ) ) ) ) ) ) )] - (	(  inEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] ) ;
	double  dceb_B = 	(  (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 1 ) + ovlp ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] ) ;
((	(  outPMLEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] = 	(  1.00000000000000000e+00 * 	(  	(  expsgmBt * (	(  outPMLEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] ) + 	(  -1 * 	(  -1 * 	(  mesgbosgbdb * 	(  dceb_A + dceb_B ) ) ) ) ) ));
}
	 }
	if (  inner_pec  ){  
		((	(  outEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] = 0);

	}else{
		{
	double  sgmB = sigma_Ez ;
	double  expsgmBt = 	exp ( 	- ( 	(  DT * sgmB ) ) ) ;
	double  mesgbosgbdb = ((	(  sgmB == 0 ))?(	(  DT / DZ )):(	(  	(  1 - expsgmBt ) / 	(  sgmB * DZ ) ))) ;
	double  dceb_A = 	(  (	(  inEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 1 ) + ovlp ) ) ) ) ) ) )] - (	(  inEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] ) ;
	double  dceb_B = 	(  (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 1 ) + ovlp ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] ) ;
((	(  outEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] = 	(  1.00000000000000000e+00 * 	(  	(  expsgmBt * (	(  outEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] ) + 	(  1 * 	(  -1 * 	(  mesgbosgbdb * 	(  dceb_A + dceb_B ) ) ) ) ) ));
}
	 }
	if (  inner_pec  ){  
		((	(  outPMLEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 0);

	}else{
		{
	double  sgmB = sigma_Ex ;
	double  expsgmBt = 	exp ( 	- ( 	(  DT * sgmB ) ) ) ;
	double  mesgbosgbdb = ((	(  sgmB == 0 ))?(	(  DT / DX )):(	(  	(  1 - expsgmBt ) / 	(  sgmB * DX ) ))) ;
	double  dceb_A = 	(  (	(  inEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + 1 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] - (	(  inEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) ;
	double  dceb_B = 	(  (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + 1 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) ;
((	(  outPMLEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  1.00000000000000000e+00 * 	(  	(  expsgmBt * (	(  outPMLEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) + 	(  -1 * 	(  -1 * 	(  mesgbosgbdb * 	(  dceb_A + dceb_B ) ) ) ) ) ));
}
	 }
	if (  inner_pec  ){  
		((	(  outEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 0);

	}else{
		{
	double  sgmB = sigma_Ex ;
	double  expsgmBt = 	exp ( 	- ( 	(  DT * sgmB ) ) ) ;
	double  mesgbosgbdb = ((	(  sgmB == 0 ))?(	(  DT / DX )):(	(  	(  1 - expsgmBt ) / 	(  sgmB * DX ) ))) ;
	double  dceb_A = 	(  (	(  inEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + 1 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] - (	(  inEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) ;
	double  dceb_B = 	(  (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + 1 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) ;
((	(  outEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  1.00000000000000000e+00 * 	(  	(  expsgmBt * (	(  outEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) + 	(  1 * 	(  -1 * 	(  mesgbosgbdb * 	(  dceb_A + dceb_B ) ) ) ) ) ));
}
	 }
	if (  inner_pec  ){  
		((	(  outPMLEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 0);

	}else{
		{
	double  sgmB = sigma_Ey ;
	double  expsgmBt = 	exp ( 	- ( 	(  DT * sgmB ) ) ) ;
	double  mesgbosgbdb = ((	(  sgmB == 0 ))?(	(  DT / DY )):(	(  	(  1 - expsgmBt ) / 	(  sgmB * DY ) ))) ;
	double  dceb_A = 	(  (	(  inEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 1 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] - (	(  inEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) ;
	double  dceb_B = 	(  (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 1 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) ;
((	(  outPMLEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  1.00000000000000000e+00 * 	(  	(  expsgmBt * (	(  outPMLEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) + 	(  -1 * 	(  -1 * 	(  mesgbosgbdb * 	(  dceb_A + dceb_B ) ) ) ) ) ));
}
	 }

	}else{
			(  (	(  outEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] -= 	(  DT * 	(  	(  	(  (	(  inEB + 	(  i * blk_all_len ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + 	(  i * blk_all_len ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + 	(  i * blk_all_len ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + 	(  i * blk_all_len ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) + 	(  	(  (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) ) );
	(  (	(  outEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] -= 	(  DT * 	(  	(  	(  (	(  inEB + 	(  i * blk_all_len ) ))[	(  0 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + 	(  i * blk_all_len ) ))[	(  0 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + 	(  i * blk_all_len ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + 	(  i * blk_all_len ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) + 	(  	(  (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  0 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  0 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) ) );
	(  (	(  outEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] -= 	(  DT * 	(  	(  	(  (	(  inEB + 	(  i * blk_all_len ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + 	(  i * blk_all_len ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + 	(  i * blk_all_len ) ))[	(  0 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + 	(  i * blk_all_len ) ))[	(  0 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) + 	(  	(  (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  0 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  0 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) ) );

	 }

	}else{
		0;

	 }
}}}}
void  c_PML_FDTD_CURL_BWD_scmc_kernel (double *  outEB ,double *  inEB ,double *  outPMLEB ,double *  inPMLEB ,int *  xoffset ,int *  yoffset ,int *  zoffset ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,double  M ,double  Q ,double  DX ,double  DY ,double  DZ ,int  abc_dir ,int  level ,int  pml_m ,double  max_sigma ,long  allxmax ,long  allymax ,long  allzmax ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / y_cpu_core ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	long  blk_all_len = 	(  xblock * 	(  yblock * 	(  zblock * num_ele ) ) ) ;
{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	long  allmax = 	(  XLEN * 	(  YLEN * ZLEN ) ) ;
	long  g = 0 ;
	int  xoffi = (xoffset)[i] ;
	int  yoffi = (yoffset)[i] ;
	int  zoffi = (zoffset)[i] ;
	int  x_use_abc = 	(  abc_dir % 2 ) ;
	int  y_use_abc = 	(  	(  abc_dir / 2 ) % 2 ) ;
	int  z_use_abc = 	(  	(  abc_dir / 4 ) % 2 ) ;
	for ((g = 0) ; 	(  g < allmax ) ; (g = 	(  g + 1 )))
	{
	long  xyzx = 	(  g % XLEN ) ;
	long  xyzy = 	(  	(  g / XLEN ) % YLEN ) ;
	long  xyzz = 	(  g / 	(  XLEN * YLEN ) ) ;
	long  blk_offset = 	(  blk_all_len * i ) ;
	if (  	(  idx == 0 )  ){  
			long  use_pml_calc = 0 ;
	long  inner_pec = 0 ;
	double  sigma_Ex = 0.00000000000000000e+00 ;
	double  sigma_Ey = 0.00000000000000000e+00 ;
	double  sigma_Ez = 0.00000000000000000e+00 ;
	long  cur_x = 	(  xoffi + xyzx ) ;
	long  cur_y = 	(  yoffi + xyzy ) ;
	long  cur_z = 	(  zoffi + xyzz ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	if (  	(  x_use_abc && 	(  	(  cur_x < level ) || 	(  cur_x >= 	(  allxmax - level ) ) ) )  ){  
			double  ocs = 	(  	(  1.00000000000000000e+00 * ((	(  cur_x < level ))?(	(  	(  level - 1 ) - cur_x )):(	(  cur_x - 	(  allxmax - level ) ))) ) / level ) ;
(sigma_Ex = 	(  max_sigma * 	pow ( ocs , pml_m ) ));
(use_pml_calc = 1);
	if (  	(  cur_x == 0 )  ){  
		(inner_pec = 1);

	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  y_use_abc && 	(  	(  cur_y < level ) || 	(  cur_y >= 	(  allymax - level ) ) ) )  ){  
			double  ocs = 	(  	(  1.00000000000000000e+00 * ((	(  cur_y < level ))?(	(  	(  level - 1 ) - cur_y )):(	(  cur_y - 	(  allymax - level ) ))) ) / level ) ;
(sigma_Ey = 	(  max_sigma * 	pow ( ocs , pml_m ) ));
(use_pml_calc = 1);
	if (  	(  cur_y == 0 )  ){  
		(inner_pec = 1);

	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  z_use_abc && 	(  	(  cur_z < level ) || 	(  cur_z >= 	(  allzmax - level ) ) ) )  ){  
			double  ocs = 	(  	(  1.00000000000000000e+00 * ((	(  cur_z < level ))?(	(  	(  level - 1 ) - cur_z )):(	(  cur_z - 	(  allzmax - level ) ))) ) / level ) ;
(sigma_Ez = 	(  max_sigma * 	pow ( ocs , pml_m ) ));
(use_pml_calc = 1);
	if (  	(  cur_z == 0 )  ){  
		(inner_pec = 1);

	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  use_pml_calc  ){  
			if (  inner_pec  ){  
		((	(  outEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 0);

	}else{
		{
	double  sgmB = sigma_Ey ;
	double  expsgmBt = 	exp ( 	- ( 	(  DT * sgmB ) ) ) ;
	double  mesgbosgbdb = ((	(  sgmB == 0 ))?(	(  DT / DY )):(	(  	(  1 - expsgmBt ) / 	(  sgmB * DY ) ))) ;
	double  dceb_A = 	(  (	(  inEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + -1 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] - (	(  inEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) ;
	double  dceb_B = 	(  (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + -1 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) ;
((	(  outEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  1.00000000000000000e+00 * 	(  	(  expsgmBt * (	(  outEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) + 	(  1 * 	(  -1 * 	(  mesgbosgbdb * 	(  dceb_A + dceb_B ) ) ) ) ) ));
}
	 }
	if (  inner_pec  ){  
		((	(  outPMLEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] = 0);

	}else{
		{
	double  sgmB = sigma_Ez ;
	double  expsgmBt = 	exp ( 	- ( 	(  DT * sgmB ) ) ) ;
	double  mesgbosgbdb = ((	(  sgmB == 0 ))?(	(  DT / DZ )):(	(  	(  1 - expsgmBt ) / 	(  sgmB * DZ ) ))) ;
	double  dceb_A = 	(  (	(  inEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + -1 ) + ovlp ) ) ) ) ) ) )] - (	(  inEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] ) ;
	double  dceb_B = 	(  (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + -1 ) + ovlp ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] ) ;
((	(  outPMLEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] = 	(  1.00000000000000000e+00 * 	(  	(  expsgmBt * (	(  outPMLEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] ) + 	(  -1 * 	(  -1 * 	(  mesgbosgbdb * 	(  dceb_A + dceb_B ) ) ) ) ) ));
}
	 }
	if (  inner_pec  ){  
		((	(  outEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] = 0);

	}else{
		{
	double  sgmB = sigma_Ez ;
	double  expsgmBt = 	exp ( 	- ( 	(  DT * sgmB ) ) ) ;
	double  mesgbosgbdb = ((	(  sgmB == 0 ))?(	(  DT / DZ )):(	(  	(  1 - expsgmBt ) / 	(  sgmB * DZ ) ))) ;
	double  dceb_A = 	(  (	(  inEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + -1 ) + ovlp ) ) ) ) ) ) )] - (	(  inEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] ) ;
	double  dceb_B = 	(  (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + -1 ) + ovlp ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] ) ;
((	(  outEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] = 	(  1.00000000000000000e+00 * 	(  	(  expsgmBt * (	(  outEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  	(  xyzz + 0 ) + ovlp ) ) ) ) ) ) )] ) + 	(  1 * 	(  -1 * 	(  mesgbosgbdb * 	(  dceb_A + dceb_B ) ) ) ) ) ));
}
	 }
	if (  inner_pec  ){  
		((	(  outPMLEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 0);

	}else{
		{
	double  sgmB = sigma_Ex ;
	double  expsgmBt = 	exp ( 	- ( 	(  DT * sgmB ) ) ) ;
	double  mesgbosgbdb = ((	(  sgmB == 0 ))?(	(  DT / DX )):(	(  	(  1 - expsgmBt ) / 	(  sgmB * DX ) ))) ;
	double  dceb_A = 	(  (	(  inEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + -1 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] - (	(  inEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) ;
	double  dceb_B = 	(  (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + -1 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) ;
((	(  outPMLEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  1.00000000000000000e+00 * 	(  	(  expsgmBt * (	(  outPMLEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) + 	(  -1 * 	(  -1 * 	(  mesgbosgbdb * 	(  dceb_A + dceb_B ) ) ) ) ) ));
}
	 }
	if (  inner_pec  ){  
		((	(  outEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 0);

	}else{
		{
	double  sgmB = sigma_Ex ;
	double  expsgmBt = 	exp ( 	- ( 	(  DT * sgmB ) ) ) ;
	double  mesgbosgbdb = ((	(  sgmB == 0 ))?(	(  DT / DX )):(	(  	(  1 - expsgmBt ) / 	(  sgmB * DX ) ))) ;
	double  dceb_A = 	(  (	(  inEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + -1 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] - (	(  inEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) ;
	double  dceb_B = 	(  (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + -1 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) ;
((	(  outEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  1.00000000000000000e+00 * 	(  	(  expsgmBt * (	(  outEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) + 	(  1 * 	(  -1 * 	(  mesgbosgbdb * 	(  dceb_A + dceb_B ) ) ) ) ) ));
}
	 }
	if (  inner_pec  ){  
		((	(  outPMLEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 0);

	}else{
		{
	double  sgmB = sigma_Ey ;
	double  expsgmBt = 	exp ( 	- ( 	(  DT * sgmB ) ) ) ;
	double  mesgbosgbdb = ((	(  sgmB == 0 ))?(	(  DT / DY )):(	(  	(  1 - expsgmBt ) / 	(  sgmB * DY ) ))) ;
	double  dceb_A = 	(  (	(  inEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + -1 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] - (	(  inEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) ;
	double  dceb_B = 	(  (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + -1 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) ;
((	(  outPMLEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  1.00000000000000000e+00 * 	(  	(  expsgmBt * (	(  outPMLEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  	(  xyzy + 0 ) + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ) + 	(  -1 * 	(  -1 * 	(  mesgbosgbdb * 	(  dceb_A + dceb_B ) ) ) ) ) ));
}
	 }

	}else{
			(  (	(  outEB + 	(  blk_all_len * i ) ))[	(  0 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] -= 	(  DT * 	(  	(  	(  (	(  inEB + 	(  i * blk_all_len ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + 	(  i * blk_all_len ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + 	(  i * blk_all_len ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + 	(  i * blk_all_len ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) + 	(  	(  (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) ) );
	(  (	(  outEB + 	(  blk_all_len * i ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] -= 	(  DT * 	(  	(  	(  (	(  inEB + 	(  i * blk_all_len ) ))[	(  0 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + 	(  i * blk_all_len ) ))[	(  0 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + 	(  i * blk_all_len ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + 	(  i * blk_all_len ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) + 	(  	(  (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  0 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  -1 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  0 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) ) );
	(  (	(  outEB + 	(  blk_all_len * i ) ))[	(  2 + 	(  num_ele * 	(  	(  	(  xyzx + 0 ) + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] -= 	(  DT * 	(  	(  	(  (	(  inEB + 	(  i * blk_all_len ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + 	(  i * blk_all_len ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inEB + 	(  i * blk_all_len ) ))[	(  0 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inEB + 	(  i * blk_all_len ) ))[	(  0 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) + 	(  	(  (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + -1 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  1 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) - 	(  (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  0 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  -1 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] - (	(  inPMLEB + 	(  i * blk_all_len ) ))[	(  0 + 	(  num_ele * 	(  	(  	(  xyzx + ovlp ) + 0 ) + 	(  xb * 	(  	(  0 + 	(  xyzy + ovlp ) ) + 	(  yb * 	(  0 + 	(  xyzz + ovlp ) ) ) ) ) ) ) )] ) ) ) ) );

	 }

	}else{
		0;

	 }
}}}}
void  c_kgm_calc_rho_scmc_kernel (double *  outEB ,double *  inEB ,int *  xoffset ,int *  yoffset ,int *  zoffset ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,double  M ,double  Q ,double  DX ,double  refz0 ,double  q ,double  dtodx ,int  mode ,int  swap_input ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / y_cpu_core ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	long  blk_all_len = 	(  xblock * 	(  yblock * 	(  zblock * num_ele ) ) ) ;
{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	long  allmax = 	(  XLEN * 	(  YLEN * ZLEN ) ) ;
	long  g = 0 ;
	for ((g = 0) ; 	(  g < allmax ) ; (g = 	(  g + 1 )))
	{
	long  xyzx = 	(  g % XLEN ) ;
	long  xyzy = 	(  	(  g / XLEN ) % YLEN ) ;
	long  xyzz = 	(  g / 	(  XLEN * YLEN ) ) ;
	long  blk_offset = 	(  blk_all_len * i ) ;
	if (  	(  idx == 0 )  ){  
			double  rho = 0 ;
{
	long  num_ele = 10 ;
	double  p0r = (	(  inEB + 	(  10 * blk_offset ) ))[	(  8 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ;
	double  p0i = (	(  inEB + 	(  10 * blk_offset ) ))[	(  9 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ;
	double  p1r = (	(  inEB + 	(  10 * blk_offset ) ))[	(  3 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ;
	double  p1i = (	(  inEB + 	(  10 * blk_offset ) ))[	(  4 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] ;
	double  cjp1i = p0i*p1r-p0r*p1i ;
(rho = 	(  	(  2 * 	(  cjp1i * q ) ) / dtodx ));
	double   curr  [3];((curr)[0] = 	(  xyzx + (xoffset)[i] ));
((curr)[1] = 	(  xyzy + (yoffset)[i] ));
((curr)[2] = 	(  xyzz + (zoffset)[i] ));
	if (  	(  	(  mode > 0 ) && 	(  mode < 4 ) )  ){  
		(rho = 	(  rho * (curr)[	(  mode - 1 )] ));

	}else{
			if (  	(  	(  mode > 3 ) && 	(  mode < 6 ) )  ){  
		(rho = 	(  rho * 	pow ( (curr)[	(  mode - 4 )] , 2 ) ));

	}else{
		0;

	 }

	 }
}((	(  outEB + blk_offset ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = rho);

	}else{
		0;

	 }
}}}}
void  c_kgm_eqn_core_scmc_kernel (double *  outEB ,double *  inEB ,double *  extA0 ,double *  extA1 ,int *  xoffset ,int *  yoffset ,int *  zoffset ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,double  M ,double  Q ,double  DX ,double  GEXT ,double  rfz0 ,double  g_beg ,int  swap_input ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 0 ;
	const long  pscmc_num_compute_units = 1 ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / y_cpu_core ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	long  blk_all_len = 	(  xblock * 	(  yblock * 	(  zblock * num_ele ) ) ) ;
{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	long  allmax = 	(  XLEN * 	(  YLEN * ZLEN ) ) ;
	long  g = 0 ;
	for ((g = 0) ; 	(  g < allmax ) ; (g = 	(  g + 1 )))
	{
	long  xyzx = 	(  g % XLEN ) ;
	long  xyzy = 	(  	(  g / XLEN ) % YLEN ) ;
	long  xyzz = 	(  g / 	(  XLEN * YLEN ) ) ;
	long  blk_offset = 	(  blk_all_len * i ) ;
	if (  	(  idx == 0 )  ){  
			double  veA0000_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1000_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0000_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1000_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0000_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1000_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0000_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1000_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0000_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1000_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0000_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1000_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0000 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0000 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1000 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1000 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0100_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1100_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0100_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1100_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0100_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1100_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0100_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1100_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0100_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1100_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0100_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1100_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0100 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0100 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1100 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1100 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0200_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1200_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0200_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1200_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0200_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1200_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0200_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1200_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0200_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1200_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0200_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1200_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0200 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0200 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1200 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1200 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0010_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1010_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0010_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1010_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0010_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1010_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0010_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1010_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0010_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1010_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0010_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1010_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0010 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0010 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1010 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1010 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0110_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1110_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0110_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1110_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0110_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1110_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0110_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1110_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0110_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1110_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0110_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1110_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0110 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0110 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1110 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1110 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0210_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1210_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0210_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1210_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0210_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1210_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0210_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1210_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0210_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1210_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0210_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1210_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0210 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0210 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1210 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1210 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0020_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1020_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0020_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1020_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0020_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1020_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0020_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1020_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0020_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1020_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0020_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1020_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0020 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0020 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1020 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1020 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0120_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1120_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0120_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1120_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0120_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1120_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0120_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1120_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0120_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1120_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0120_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1120_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0120 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0120 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1120 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1120 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0220_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1220_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0220_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1220_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0220_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1220_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0220_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1220_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0220_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1220_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0220_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1220_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0220 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0220 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1220 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1220 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0001_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1001_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0001_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1001_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0001_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1001_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0001_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1001_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0001_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1001_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0001_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1001_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0001 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0001 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1001 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1001 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0101_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1101_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0101_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1101_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0101_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1101_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0101_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1101_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0101_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1101_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0101_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1101_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0101 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0101 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1101 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1101 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0201_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1201_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0201_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1201_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0201_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1201_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0201_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1201_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0201_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1201_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0201_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1201_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0201 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0201 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1201 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1201 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0011_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1011_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0011_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1011_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0011_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1011_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0011_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1011_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0011_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1011_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0011_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1011_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0011 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0011 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1011 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1011 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0111_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1111_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0111_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1111_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0111_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1111_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0111_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1111_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0111_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1111_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0111_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1111_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0111 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0111 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1111 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1111 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0211_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1211_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0211_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1211_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0211_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1211_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0211_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1211_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0211_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1211_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0211_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1211_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0211 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0211 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1211 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1211 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0021_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1021_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0021_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1021_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0021_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1021_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0021_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1021_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0021_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1021_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0021_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1021_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0021 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0021 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1021 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1021 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0121_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1121_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0121_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1121_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0121_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1121_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0121_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1121_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0121_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1121_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0121_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1121_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0121 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0121 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1121 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1121 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0221_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1221_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0221_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1221_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0221_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1221_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0221_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1221_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0221_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1221_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0221_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1221_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0221 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0221 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1221 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1221 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0002_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1002_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0002_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1002_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0002_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1002_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0002_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1002_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0002_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1002_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0002_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1002_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0002 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0002 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1002 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1002 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0102_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1102_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0102_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1102_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0102_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1102_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0102_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1102_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0102_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1102_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0102_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1102_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0102 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0102 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1102 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1102 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0202_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1202_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0202_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1202_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0202_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1202_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0202_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1202_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0202_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1202_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0202_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1202_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0202 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0202 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1202 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1202 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0012_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1012_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0012_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1012_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0012_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1012_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0012_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1012_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0012_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1012_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0012_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1012_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0012 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0012 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1012 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1012 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0112_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1112_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0112_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1112_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0112_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1112_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0112_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1112_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0112_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1112_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0112_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1112_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0112 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0112 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1112 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1112 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0212_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1212_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0212_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1212_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0212_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1212_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0212_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1212_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0212_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1212_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0212_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1212_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0212 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0212 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1212 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1212 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0022_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1022_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0022_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1022_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0022_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1022_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0022_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1022_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0022_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1022_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0022_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1022_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0022 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0022 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1022 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1022 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0122_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1122_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0122_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1122_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0122_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1122_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0122_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1122_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0122_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1122_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0122_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1122_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0122 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0122 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1122 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1122 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0222_1 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1222_1 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0222_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1222_1 = (	(  inEB + blk_offset ))[	(  	(  1 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0222_2 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1222_2 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0222_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1222_2 = (	(  inEB + blk_offset ))[	(  	(  2 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA0222_3 = (	(  extA0 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  veA1222_3 = (	(  extA1 + 	(  	(  blk_offset * 3 ) / num_ele ) ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  3 * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA0222_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 5 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vA1222_3 = (	(  inEB + blk_offset ))[	(  	(  3 + 	(  -1 + 0 ) ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R0222 = (	(  inEB + blk_offset ))[	(  8 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I0222 = (	(  inEB + blk_offset ))[	(  9 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_R1222 = (	(  inEB + blk_offset ))[	(  3 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  PHI1_I1222 = (	(  inEB + blk_offset ))[	(  4 + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  REFZ0 = 	(  xyzz + 	(  rfz0 + (zoffset)[i] ) ) ;
	if (  	(  g_beg < REFZ0 )  ){  
		(GEXT = 0);

	}else{
		0;

	 }
((	(  outEB + blk_offset ))[	(  	(  0 + 5 ) + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = vA1111_1);
((	(  outEB + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  	pow ( DX , -2 ) * 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DX , 2 ) * vA0111_1 ) ) + 	(  	(  	pow ( DT , 2 ) * vA1011_1 ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * vA1011_3 ) ) + 	(  	(  	pow ( DT , 2 ) * vA1012_3 ) + 	(  	(  	pow ( DT , 2 ) * vA1101_1 ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * vA1101_2 ) ) + 	(  	(  	pow ( DT , 2 ) * vA1102_2 ) + 	(  	(  	(  	(  -4.00000000000000000e+00 * 	pow ( DT , 2 ) ) + 	(  2.00000000000000000e+00 * 	pow ( DX , 2 ) ) ) * vA1111_1 ) + 	(  	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  DX * 	(  PHI1_I1112 * PHI1_R1111 ) ) ) ) + 	(  2.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  DX * 	(  PHI1_I1111 * PHI1_R1112 ) ) ) ) ) * 	(  Q * 	cos ( 	(  DX * 	(  Q * vA1111_1 ) ) ) ) ) + 	(  	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  DX * 	(  PHI1_I1111 * PHI1_I1112 ) ) ) ) + 	(  -2.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  DX * 	(  PHI1_R1111 * PHI1_R1112 ) ) ) ) ) * 	(  Q * 	sin ( 	(  DX * 	(  Q * vA1111_1 ) ) ) ) ) + 	(  	(  	pow ( DT , 2 ) * vA1111_2 ) + 	(  	(  	pow ( DT , 2 ) * vA1111_3 ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * vA1112_2 ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * vA1112_3 ) ) + 	(  	(  	pow ( DT , 2 ) * vA1121_1 ) + 	(  	pow ( DT , 2 ) * vA1211_1 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
((	(  outEB + blk_offset ))[	(  	(  1 + 5 ) + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = vA1111_2);
((	(  outEB + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  	pow ( DX , -2 ) * 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DX , 2 ) * vA0111_2 ) ) + 	(  	(  	pow ( DT , 2 ) * vA1011_2 ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * vA1011_3 ) ) + 	(  	(  	pow ( DT , 2 ) * vA1021_3 ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * vA1110_1 ) ) + 	(  	(  	pow ( DT , 2 ) * vA1110_2 ) + 	(  	(  	pow ( DT , 2 ) * vA1111_1 ) + 	(  	(  	(  	(  -4.00000000000000000e+00 * 	pow ( DT , 2 ) ) + 	(  2.00000000000000000e+00 * 	pow ( DX , 2 ) ) ) * vA1111_2 ) + 	(  	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  DX * 	(  PHI1_I1121 * PHI1_R1111 ) ) ) ) + 	(  2.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  DX * 	(  PHI1_I1111 * PHI1_R1121 ) ) ) ) ) * 	(  Q * 	cos ( 	(  DX * 	(  Q * vA1111_2 ) ) ) ) ) + 	(  	(  	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  DX * 	(  PHI1_I1111 * PHI1_I1121 ) ) ) ) + 	(  -2.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  DX * 	(  PHI1_R1111 * PHI1_R1121 ) ) ) ) ) * 	(  Q * 	sin ( 	(  DX * 	(  Q * vA1111_2 ) ) ) ) ) + 	(  	(  	pow ( DT , 2 ) * vA1111_3 ) + 	(  	(  	pow ( DT , 2 ) * vA1112_2 ) + 	(  	(  	pow ( DT , 2 ) * vA1120_1 ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * vA1121_1 ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * vA1121_3 ) ) + 	(  	pow ( DT , 2 ) * vA1211_2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
((	(  outEB + blk_offset ))[	(  	(  2 + 5 ) + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = vA1111_3);
((	(  outEB + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  -1.00000000000000000e+00 * 	(  	pow ( DX , -2 ) * 	(  	(  	pow ( DX , 2 ) * vA0111_3 ) + 	(  	(  	pow ( DT , 2 ) * vA1101_2 ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * vA1101_3 ) ) + 	(  	(  	pow ( DT , 2 ) * vA1110_1 ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * vA1110_3 ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * vA1111_1 ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * vA1111_2 ) ) + 	(  	(  	(  	(  4.00000000000000000e+00 * 	pow ( DT , 2 ) ) + 	(  -2.00000000000000000e+00 * 	pow ( DX , 2 ) ) ) * vA1111_3 ) + 	(  	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  DX * 	(  PHI1_I1211 * PHI1_R1111 ) ) ) ) + 	(  -2.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  DX * 	(  PHI1_I1111 * PHI1_R1211 ) ) ) ) ) * 	(  Q * 	cos ( 	(  DX * 	(  Q * vA1111_3 ) ) ) ) ) + 	(  	(  	(  	(  2.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  DX * 	(  PHI1_I1111 * PHI1_I1211 ) ) ) ) + 	(  2.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  DX * 	(  PHI1_R1111 * PHI1_R1211 ) ) ) ) ) * 	(  Q * 	sin ( 	(  DX * 	(  Q * vA1111_3 ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * vA1112_3 ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * vA1121_3 ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * vA1201_2 ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * vA1210_1 ) ) + 	(  	(  	pow ( DT , 2 ) * vA1211_1 ) + 	(  	pow ( DT , 2 ) * vA1211_2 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ));
((	(  outEB + blk_offset ))[	(  	(  3 + 5 ) + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = PHI1_R1111);
((	(  outEB + blk_offset ))[	(  	(  3 + 0 ) + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  	pow ( DX , -2 ) * 	(  	(  	pow ( DX , 2 ) * PHI1_R0111 ) + 	(  	(  	(  	(  	(  	(  -6.00000000000000000e+00 * 	pow ( DT , 2 ) ) + 	(  	(  2.00000000000000000e+00 * 	pow ( DX , 2 ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  	pow ( DX , 2 ) * 	pow ( M , 2 ) ) ) ) ) ) * PHI1_R1111 ) + 	(  	(  	pow ( DT , 2 ) * 	(  PHI1_R1011 * 	cos ( 	(  DX * 	(  Q * vA1011_3 ) ) ) ) ) + 	(  	(  	pow ( DT , 2 ) * 	(  PHI1_I1011 * 	sin ( 	(  DX * 	(  Q * vA1011_3 ) ) ) ) ) + 	(  	(  	pow ( DT , 2 ) * 	(  PHI1_R1101 * 	cos ( 	(  DX * 	(  Q * vA1101_2 ) ) ) ) ) + 	(  	(  	pow ( DT , 2 ) * 	(  PHI1_I1101 * 	sin ( 	(  DX * 	(  Q * vA1101_2 ) ) ) ) ) + 	(  	(  	pow ( DT , 2 ) * 	(  PHI1_R1110 * 	cos ( 	(  DX * 	(  Q * vA1110_1 ) ) ) ) ) + 	(  	(  	pow ( DT , 2 ) * 	(  PHI1_I1110 * 	sin ( 	(  DX * 	(  Q * vA1110_1 ) ) ) ) ) + 	(  	(  	pow ( DT , 2 ) * 	(  PHI1_R1112 * 	cos ( 	(  DX * 	(  Q * vA1111_1 ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_I1112 * 	sin ( 	(  DX * 	(  Q * vA1111_1 ) ) ) ) ) ) + 	(  	(  	pow ( DT , 2 ) * 	(  PHI1_R1121 * 	cos ( 	(  DX * 	(  Q * vA1111_2 ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_I1121 * 	sin ( 	(  DX * 	(  Q * vA1111_2 ) ) ) ) ) ) + 	(  	(  	pow ( DT , 2 ) * 	(  PHI1_R1211 * 	cos ( 	(  DX * 	(  Q * vA1111_3 ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_I1211 * 	sin ( 	(  DX * 	(  Q * vA1111_3 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) * 	cos ( 	(  DT * 	(  Q * veA0111_1 ) ) ) ) + 	(  	(  -2.00000000000000000e+00 * 	(  	pow ( DX , 2 ) * 	(  PHI1_R0111 * 	pow ( 	cos ( 	(  DT * 	(  Q * veA0111_1 ) ) ) , 2 ) ) ) ) + 	(  	(  	(  	(  	(  6.00000000000000000e+00 * 	pow ( DT , 2 ) ) + 	(  	(  -2.00000000000000000e+00 * 	pow ( DX , 2 ) ) + 	(  	pow ( DT , 2 ) * 	(  	pow ( DX , 2 ) * 	pow ( M , 2 ) ) ) ) ) * PHI1_I1111 ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_I1011 * 	cos ( 	(  DX * 	(  Q * vA1011_3 ) ) ) ) ) ) + 	(  	(  	pow ( DT , 2 ) * 	(  PHI1_R1011 * 	sin ( 	(  DX * 	(  Q * vA1011_3 ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_I1101 * 	cos ( 	(  DX * 	(  Q * vA1101_2 ) ) ) ) ) ) + 	(  	(  	pow ( DT , 2 ) * 	(  PHI1_R1101 * 	sin ( 	(  DX * 	(  Q * vA1101_2 ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_I1110 * 	cos ( 	(  DX * 	(  Q * vA1110_1 ) ) ) ) ) ) + 	(  	(  	pow ( DT , 2 ) * 	(  PHI1_R1110 * 	sin ( 	(  DX * 	(  Q * vA1110_1 ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_I1112 * 	cos ( 	(  DX * 	(  Q * vA1111_1 ) ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_R1112 * 	sin ( 	(  DX * 	(  Q * vA1111_1 ) ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_I1121 * 	cos ( 	(  DX * 	(  Q * vA1111_2 ) ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_R1121 * 	sin ( 	(  DX * 	(  Q * vA1111_2 ) ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_I1211 * 	cos ( 	(  DX * 	(  Q * vA1111_3 ) ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_R1211 * 	sin ( 	(  DX * 	(  Q * vA1111_3 ) ) ) ) ) ) + 	(  2.00000000000000000e+00 * 	(  	pow ( DX , 2 ) * 	(  PHI1_I0111 * 	cos ( 	(  DT * 	(  Q * veA0111_1 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) * 	sin ( 	(  DT * 	(  Q * veA0111_1 ) ) ) ) ) ) ) ));
((	(  outEB + blk_offset ))[	(  	(  4 + 5 ) + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = PHI1_I1111);
((	(  outEB + blk_offset ))[	(  	(  4 + 0 ) + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  -1.00000000000000000e+00 * 	(  	pow ( DX , -2 ) * 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DX , 2 ) * PHI1_I0111 ) ) + 	(  	(  	(  	(  	(  	(  6.00000000000000000e+00 * 	pow ( DT , 2 ) ) + 	(  	(  -2.00000000000000000e+00 * 	pow ( DX , 2 ) ) + 	(  	pow ( DT , 2 ) * 	(  	pow ( DX , 2 ) * 	pow ( M , 2 ) ) ) ) ) * PHI1_I1111 ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_I1011 * 	cos ( 	(  DX * 	(  Q * vA1011_3 ) ) ) ) ) ) + 	(  	(  	pow ( DT , 2 ) * 	(  PHI1_R1011 * 	sin ( 	(  DX * 	(  Q * vA1011_3 ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_I1101 * 	cos ( 	(  DX * 	(  Q * vA1101_2 ) ) ) ) ) ) + 	(  	(  	pow ( DT , 2 ) * 	(  PHI1_R1101 * 	sin ( 	(  DX * 	(  Q * vA1101_2 ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_I1110 * 	cos ( 	(  DX * 	(  Q * vA1110_1 ) ) ) ) ) ) + 	(  	(  	pow ( DT , 2 ) * 	(  PHI1_R1110 * 	sin ( 	(  DX * 	(  Q * vA1110_1 ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_I1112 * 	cos ( 	(  DX * 	(  Q * vA1111_1 ) ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_R1112 * 	sin ( 	(  DX * 	(  Q * vA1111_1 ) ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_I1121 * 	cos ( 	(  DX * 	(  Q * vA1111_2 ) ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_R1121 * 	sin ( 	(  DX * 	(  Q * vA1111_2 ) ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_I1211 * 	cos ( 	(  DX * 	(  Q * vA1111_3 ) ) ) ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_R1211 * 	sin ( 	(  DX * 	(  Q * vA1111_3 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) * 	cos ( 	(  DT * 	(  Q * veA0111_1 ) ) ) ) + 	(  	(  2.00000000000000000e+00 * 	(  	pow ( DX , 2 ) * 	(  PHI1_I0111 * 	pow ( 	cos ( 	(  DT * 	(  Q * veA0111_1 ) ) ) , 2 ) ) ) ) + 	(  	(  	(  	(  	(  6.00000000000000000e+00 * 	pow ( DT , 2 ) ) + 	(  	(  -2.00000000000000000e+00 * 	pow ( DX , 2 ) ) + 	(  	pow ( DT , 2 ) * 	(  	pow ( DX , 2 ) * 	pow ( M , 2 ) ) ) ) ) * PHI1_R1111 ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_R1011 * 	cos ( 	(  DX * 	(  Q * vA1011_3 ) ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_I1011 * 	sin ( 	(  DX * 	(  Q * vA1011_3 ) ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_R1101 * 	cos ( 	(  DX * 	(  Q * vA1101_2 ) ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_I1101 * 	sin ( 	(  DX * 	(  Q * vA1101_2 ) ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_R1110 * 	cos ( 	(  DX * 	(  Q * vA1110_1 ) ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_I1110 * 	sin ( 	(  DX * 	(  Q * vA1110_1 ) ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_R1112 * 	cos ( 	(  DX * 	(  Q * vA1111_1 ) ) ) ) ) ) + 	(  	(  	pow ( DT , 2 ) * 	(  PHI1_I1112 * 	sin ( 	(  DX * 	(  Q * vA1111_1 ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_R1121 * 	cos ( 	(  DX * 	(  Q * vA1111_2 ) ) ) ) ) ) + 	(  	(  	pow ( DT , 2 ) * 	(  PHI1_I1121 * 	sin ( 	(  DX * 	(  Q * vA1111_2 ) ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DT , 2 ) * 	(  PHI1_R1211 * 	cos ( 	(  DX * 	(  Q * vA1111_3 ) ) ) ) ) ) + 	(  	(  	pow ( DT , 2 ) * 	(  PHI1_I1211 * 	sin ( 	(  DX * 	(  Q * vA1111_3 ) ) ) ) ) + 	(  2.00000000000000000e+00 * 	(  	pow ( DX , 2 ) * 	(  PHI1_R0111 * 	cos ( 	(  DT * 	(  Q * veA0111_1 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) * 	sin ( 	(  DT * 	(  Q * veA0111_1 ) ) ) ) ) ) ) ) ));

	}else{
		0;

	 }
}}}}
