#include <omp.h> 
#include <math.h>

#include <math.h>
#include <assert.h>
#include <stdio.h>
#define IDX_OPT_MAX 1
int  openmp_is_in (long  x ,long  xl ,long  xr ){
	return  	(  	(  x < xr ) && 	(  x >= xl ) ) ;}
void  openmp_move_back_kernel_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long  XLEN ,long  YLEN ,long  ZLEN ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  cu_offset = 	(  idy * 	(  XLEN * 	(  YLEN * ZLEN ) ) ) ;
	long  xyzalllen = 	(  XLEN * 	(  YLEN * ZLEN ) ) ;
	long  i = 0 ;
	long  j = 0 ;
	double   local_temp_particle_cache  [384][6];	int  cu_load = (cu_xyzw)[	(  4 * idy )] ;
	int  cur_cu_load = 0 ;
	for (i=0 ; 	(  i < cu_load ) ; (i = 	(  i + 384 )))
	{
	long  numcp = ((	(  	(  i + 384 ) > cu_load ))?(	(  cu_load - i )):(384)) ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  numcp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
(((local_temp_particle_cache)[0])[	(  	(  inner_step * 1 ) + inner_g )] = (	(  cu_cache + 	(  	(  	(  cu_cache_length * idy ) + i ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	for (j=0 ; 	(  j < numcp ) ; j++)
	{
	long  allid = 	(  i + j ) ;
	long  xyzx = 	floor ( ((local_temp_particle_cache)[j])[0] ) ;
	long  xyzy = 	floor ( ((local_temp_particle_cache)[j])[1] ) ;
	long  xyzz = 	floor ( ((local_temp_particle_cache)[j])[2] ) ;
	double  dxyzx = ((local_temp_particle_cache)[j])[0] ;
	double  dxyzy = ((local_temp_particle_cache)[j])[1] ;
	double  dxyzz = ((local_temp_particle_cache)[j])[2] ;
	int  wrted_grid = 0 ;
	if (  	(  	openmp_is_in ( xyzx , 0 , XLEN ) && 	(  	openmp_is_in ( xyzy , 0 , YLEN ) && 	openmp_is_in ( xyzz , 0 , ZLEN ) ) )  ){  
			long  allid_grid = 	(  	(  0 + 	(  1 * 	(  xyzx + 	(  XLEN * 	(  xyzy + 	(  YLEN * xyzz ) ) ) ) ) ) + cu_offset ) ;
	int  gridload = (xyzw)[	(  4 * allid_grid )] ;
	if (  	(  gridload < grid_cache_len )  ){  
			long  grid_load_end = 	(  gridload + 1 ) ;
((xyzw)[	(  4 * allid_grid )] = grid_load_end);
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  inoutput + 	(  6 * 	(  	(  allid_grid * grid_cache_len ) + gridload ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = ((local_temp_particle_cache)[j])[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(wrted_grid = 1);

	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  ! wrted_grid )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 6 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_cache + 	(  6 * 	(  	(  idy * cu_cache_length ) + cur_cu_load ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = ((local_temp_particle_cache)[j])[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(cur_cu_load = 	(  cur_cu_load + 1 ));

	}else{
		0;

	 }
}}((cu_xyzw)[	(  idy * 4 )] = cur_cu_load);
}
