#include <omp.h> 
#include <math.h>

#include <math.h>
#include <assert.h>
#include <stdio.h>
#define IDX_OPT_MAX 1
void  openmp_RECT_YEE_CURL_L_scmc_kernel (double *  inoutE1 ,double *  inB0 ,int *  xoffset ,int *  yoffset ,int *  zoffset ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
	long  blk_all_len_nonele = 	(  xblock * 	(  yblock * zblock ) ) ;
{
	long  i ;
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; (i = 	(  i + 1 )))
	{
	int  gxoffset = (xoffset)[i] ;
	int  gyoffset = (yoffset)[i] ;
	int  gzoffset = (zoffset)[i] ;
	long  allmax = 	(  XLEN * 	(  YLEN * ZLEN ) ) ;
	long  lg = 0 ;
	for ((lg = 0) ; 	(  lg < allmax ) ; (lg = 	(  lg + xlen )))
	{
	long  g = 	(  lg + idx ) ;
	long  xyzx = 	(  g % XLEN ) ;
	long  xyzy = 	(  	(  g / XLEN ) % YLEN ) ;
	long  xyzz = 	(  g / 	(  XLEN * YLEN ) ) ;
	long  blk_offset = 	(  blk_all_len_nonele * 	(  i * num_ele ) ) ;
	double  vB00001 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10001 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20001 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01001 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11001 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21001 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB00101 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10101 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20101 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01101 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11101 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21101 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB00011 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10011 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20011 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01011 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11011 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21011 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB00111 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10111 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20111 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01111 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11111 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21111 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  xo0 = 	(  gxoffset + 	(  xyzx + -1 ) ) ;
((	(  inoutE1 + blk_offset ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  (	(  inoutE1 + blk_offset ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] + 	(  DT * 	(  DELTA_X * 	(  	pow ( DELTA_Y , -1 ) * 	(  	pow ( DELTA_Z , -1 ) * 	(  	(  	pow ( DELTA_X , -1 ) * 	(  DELTA_Y * 	(  	pow ( DELTA_Z , -1 ) * vB10111 ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , -1 ) * 	(  DELTA_Y * 	(  	pow ( DELTA_Z , -1 ) * vB11111 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , -1 ) * 	(  	pow ( DELTA_Y , -1 ) * 	(  DELTA_Z * vB21011 ) ) ) ) + 	(  	pow ( DELTA_X , -1 ) * 	(  	pow ( DELTA_Y , -1 ) * 	(  DELTA_Z * vB21111 ) ) ) ) ) ) ) ) ) ) ));
((	(  inoutE1 + blk_offset ))[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  (	(  inoutE1 + blk_offset ))[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] + 	(  DT * 	(  	pow ( DELTA_X , -1 ) * 	(  DELTA_Y * 	(  	pow ( DELTA_Z , -1 ) * 	(  	(  -1.00000000000000000e+00 * 	(  DELTA_X * 	(  	pow ( DELTA_Y , -1 ) * 	(  	pow ( DELTA_Z , -1 ) * vB00111 ) ) ) ) + 	(  	(  DELTA_X * 	(  	pow ( DELTA_Y , -1 ) * 	(  	pow ( DELTA_Z , -1 ) * vB01111 ) ) ) + 	(  	(  	pow ( DELTA_X , -1 ) * 	(  	pow ( DELTA_Y , -1 ) * 	(  DELTA_Z * vB21101 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , -1 ) * 	(  	pow ( DELTA_Y , -1 ) * 	(  DELTA_Z * vB21111 ) ) ) ) ) ) ) ) ) ) ) ));
((	(  inoutE1 + blk_offset ))[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  (	(  inoutE1 + blk_offset ))[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] + 	(  DT * 	(  	pow ( DELTA_X , -1 ) * 	(  	pow ( DELTA_Y , -1 ) * 	(  DELTA_Z * 	(  	(  DELTA_X * 	(  	pow ( DELTA_Y , -1 ) * 	(  	pow ( DELTA_Z , -1 ) * vB01011 ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  DELTA_X * 	(  	pow ( DELTA_Y , -1 ) * 	(  	pow ( DELTA_Z , -1 ) * vB01111 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , -1 ) * 	(  DELTA_Y * 	(  	pow ( DELTA_Z , -1 ) * vB11101 ) ) ) ) + 	(  	pow ( DELTA_X , -1 ) * 	(  DELTA_Y * 	(  	pow ( DELTA_Z , -1 ) * vB11111 ) ) ) ) ) ) ) ) ) ) ));
}}}}
