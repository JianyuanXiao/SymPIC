#include <omp.h> 
#include <math.h>

#include <math.h>
#include <assert.h>
#include <stdio.h>
#define IDX_OPT_MAX 1
void  openmp_RECT_YEE_CURL_L_scmc_kernel (double *  inoutE1 ,double *  inB0 ,int *  xoffset ,int *  yoffset ,int *  zoffset ,long  y_cpu_core ,long  numvec ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  xblock ,long  yblock ,long  zblock ,int  num_ele ,double  DT ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
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
	long  blk_offset = 	(  blk_all_len_nonele * 	(  i * num_ele ) ) ;
	if (  	(  0 && 	(  	(  blk_all_len_nonele * num_ele ) < 2048 ) )  ){  
			double   vread_tmp  [2048];	double   vwrt_tmp  [2048];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  blk_all_len_nonele * num_ele ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((vread_tmp)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  inB0 + blk_offset ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  blk_all_len_nonele * num_ele ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((vwrt_tmp)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  inoutE1 + blk_offset ))[	(  	(  inner_step * 1 ) + inner_g )]);
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
	for ((xyzx = 0) ; 	(  xyzx < XLEN ) ; (xyzx = 	(  xyzx + 1 )))
	{
	double  vB00001 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10001 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20001 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01001 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11001 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21001 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB02001 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB12001 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB22001 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB00101 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10101 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20101 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01101 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11101 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21101 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB02101 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB12101 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB22101 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB00201 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10201 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20201 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01201 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11201 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21201 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB02201 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB12201 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB22201 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB00011 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10011 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20011 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01011 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11011 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21011 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB02011 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB12011 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB22011 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB00111 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10111 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20111 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01111 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11111 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21111 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB02111 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB12111 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB22111 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB00211 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10211 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20211 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01211 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11211 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21211 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB02211 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB12211 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB22211 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB00021 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10021 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20021 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01021 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11021 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21021 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB02021 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB12021 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB22021 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB00121 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10121 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20121 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01121 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11121 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21121 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB02121 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB12121 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB22121 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB00221 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10221 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20221 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01221 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11221 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21221 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB02221 = (vread_tmp)[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB12221 = (vread_tmp)[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB22221 = (vread_tmp)[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  xo0 = 	(  gxoffset + 	(  xyzx + -1 ) ) ;
((vwrt_tmp)[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  (vwrt_tmp)[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] + 	(  DT * 	(  DELTA_X * 	(  	pow ( DELTA_Y , -1 ) * 	(  	pow ( DELTA_Z , -1 ) * 	(  	(  	pow ( DELTA_X , -1 ) * 	(  DELTA_Y * 	(  	pow ( DELTA_Z , -1 ) * vB10111 ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , -1 ) * 	(  DELTA_Y * 	(  	pow ( DELTA_Z , -1 ) * vB11111 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , -1 ) * 	(  	pow ( DELTA_Y , -1 ) * 	(  DELTA_Z * vB21011 ) ) ) ) + 	(  	pow ( DELTA_X , -1 ) * 	(  	pow ( DELTA_Y , -1 ) * 	(  DELTA_Z * vB21111 ) ) ) ) ) ) ) ) ) ) ));
((vwrt_tmp)[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  (vwrt_tmp)[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] + 	(  DT * 	(  	pow ( DELTA_X , -1 ) * 	(  DELTA_Y * 	(  	pow ( DELTA_Z , -1 ) * 	(  	(  -1.00000000000000000e+00 * 	(  DELTA_X * 	(  	pow ( DELTA_Y , -1 ) * 	(  	pow ( DELTA_Z , -1 ) * vB00111 ) ) ) ) + 	(  	(  DELTA_X * 	(  	pow ( DELTA_Y , -1 ) * 	(  	pow ( DELTA_Z , -1 ) * vB01111 ) ) ) + 	(  	(  	pow ( DELTA_X , -1 ) * 	(  	pow ( DELTA_Y , -1 ) * 	(  DELTA_Z * vB21101 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , -1 ) * 	(  	pow ( DELTA_Y , -1 ) * 	(  DELTA_Z * vB21111 ) ) ) ) ) ) ) ) ) ) ) ));
((vwrt_tmp)[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  (vwrt_tmp)[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] + 	(  DT * 	(  	pow ( DELTA_X , -1 ) * 	(  	pow ( DELTA_Y , -1 ) * 	(  DELTA_Z * 	(  	(  DELTA_X * 	(  	pow ( DELTA_Y , -1 ) * 	(  	pow ( DELTA_Z , -1 ) * vB01011 ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  DELTA_X * 	(  	pow ( DELTA_Y , -1 ) * 	(  	pow ( DELTA_Z , -1 ) * vB01111 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , -1 ) * 	(  DELTA_Y * 	(  	pow ( DELTA_Z , -1 ) * vB11101 ) ) ) ) + 	(  	pow ( DELTA_X , -1 ) * 	(  DELTA_Y * 	(  	pow ( DELTA_Z , -1 ) * vB11111 ) ) ) ) ) ) ) ) ) ) ));
}}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  blk_all_len_nonele * num_ele ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  inoutE1 + blk_offset ))[	(  	(  inner_step * 1 ) + inner_g )] = (vwrt_tmp)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
			long  lg = 0 ;
	for ((lg = 0) ; 	(  lg < allmax ) ; (lg = 	(  lg + xlen )))
	{
	long  g = 	(  lg + idx ) ;
	long  xyzx = 	(  g % XLEN ) ;
	long  xyzy = 	(  	(  g / XLEN ) % YLEN ) ;
	long  xyzz = 	(  g / 	(  XLEN * YLEN ) ) ;
	double  vB00001 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10001 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20001 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01001 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11001 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21001 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB02001 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB12001 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB22001 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB00101 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10101 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20101 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01101 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11101 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21101 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB02101 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB12101 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB22101 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB00201 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10201 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20201 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01201 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11201 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21201 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB02201 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB12201 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB22201 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  0 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB00011 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10011 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20011 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01011 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11011 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21011 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB02011 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB12011 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB22011 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB00111 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10111 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20111 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01111 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11111 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21111 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB02111 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB12111 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB22111 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB00211 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10211 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20211 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01211 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11211 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21211 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB02211 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB12211 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB22211 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  1 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB00021 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10021 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20021 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01021 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11021 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21021 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB02021 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB12021 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB22021 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  0 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB00121 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10121 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20121 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01121 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11121 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21121 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB02121 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB12121 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB22121 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  1 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB00221 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB10221 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB20221 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  0 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB01221 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB11221 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB21221 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  1 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB02221 = (	(  inB0 + blk_offset ))[	(  	(  0 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB12221 = (	(  inB0 + blk_offset ))[	(  	(  1 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  vB22221 = (	(  inB0 + blk_offset ))[	(  	(  2 + 0 ) + 	(  num_ele * 	(  	(  	(  2 + 	(  xyzx + -1 ) ) + ovlp ) + 	(  xblock * 	(  	(  	(  2 + 	(  xyzy + -1 ) ) + ovlp ) + 	(  yblock * 	(  	(  2 + 	(  xyzz + -1 ) ) + ovlp ) ) ) ) ) ) )] ;
	double  xo0 = 	(  gxoffset + 	(  xyzx + -1 ) ) ;
((	(  inoutE1 + blk_offset ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  (	(  inoutE1 + blk_offset ))[	(  0 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] + 	(  DT * 	(  DELTA_X * 	(  	pow ( DELTA_Y , -1 ) * 	(  	pow ( DELTA_Z , -1 ) * 	(  	(  	pow ( DELTA_X , -1 ) * 	(  DELTA_Y * 	(  	pow ( DELTA_Z , -1 ) * vB10111 ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , -1 ) * 	(  DELTA_Y * 	(  	pow ( DELTA_Z , -1 ) * vB11111 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , -1 ) * 	(  	pow ( DELTA_Y , -1 ) * 	(  DELTA_Z * vB21011 ) ) ) ) + 	(  	pow ( DELTA_X , -1 ) * 	(  	pow ( DELTA_Y , -1 ) * 	(  DELTA_Z * vB21111 ) ) ) ) ) ) ) ) ) ) ));
((	(  inoutE1 + blk_offset ))[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  (	(  inoutE1 + blk_offset ))[	(  1 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] + 	(  DT * 	(  	pow ( DELTA_X , -1 ) * 	(  DELTA_Y * 	(  	pow ( DELTA_Z , -1 ) * 	(  	(  -1.00000000000000000e+00 * 	(  DELTA_X * 	(  	pow ( DELTA_Y , -1 ) * 	(  	pow ( DELTA_Z , -1 ) * vB00111 ) ) ) ) + 	(  	(  DELTA_X * 	(  	pow ( DELTA_Y , -1 ) * 	(  	pow ( DELTA_Z , -1 ) * vB01111 ) ) ) + 	(  	(  	pow ( DELTA_X , -1 ) * 	(  	pow ( DELTA_Y , -1 ) * 	(  DELTA_Z * vB21101 ) ) ) + 	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , -1 ) * 	(  	pow ( DELTA_Y , -1 ) * 	(  DELTA_Z * vB21111 ) ) ) ) ) ) ) ) ) ) ) ));
((	(  inoutE1 + blk_offset ))[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] = 	(  (	(  inoutE1 + blk_offset ))[	(  2 + 	(  num_ele * 	(  	(  xyzx + ovlp ) + 	(  xblock * 	(  	(  xyzy + ovlp ) + 	(  yblock * 	(  xyzz + ovlp ) ) ) ) ) ) )] + 	(  DT * 	(  	pow ( DELTA_X , -1 ) * 	(  	pow ( DELTA_Y , -1 ) * 	(  DELTA_Z * 	(  	(  DELTA_X * 	(  	pow ( DELTA_Y , -1 ) * 	(  	pow ( DELTA_Z , -1 ) * vB01011 ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  DELTA_X * 	(  	pow ( DELTA_Y , -1 ) * 	(  	pow ( DELTA_Z , -1 ) * vB01111 ) ) ) ) + 	(  	(  -1.00000000000000000e+00 * 	(  	pow ( DELTA_X , -1 ) * 	(  DELTA_Y * 	(  	pow ( DELTA_Z , -1 ) * vB11101 ) ) ) ) + 	(  	pow ( DELTA_X , -1 ) * 	(  DELTA_Y * 	(  	pow ( DELTA_Z , -1 ) * vB11111 ) ) ) ) ) ) ) ) ) ) ));
}
	 }
}}}
