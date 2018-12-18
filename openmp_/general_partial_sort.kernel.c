#include <omp.h> 
#include <math.h>

#include <math.h>
#include <assert.h>
#include <stdio.h>
#define IDX_OPT_MAX 1
void  openmp_sort_one_grid_x_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  cu_offset = 	(  idy * 	(  XLEN * 	(  YLEN * ZLEN ) ) ) ;
	long  xyzalllen = 	(  XLEN * 	(  YLEN * ZLEN ) ) ;
	long  i = 0 ;
	double   local_temp_particle_cache_plus  [	(  384 * 6 )];	double   local_temp_particle_cache_minus  [	(  384 * 6 )];	double   local_pos_cache  [	(  64 * 6 )];	double   local_vel_cache  [192];	int   cu_xyzw_shared  [4];	int  cu_cur_cache_load = (cu_xyzw)[	(  4 * idy )] ;
	if (  	(  idx == 0 )  ){  
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
	for (i=0 ; 	(  	(  idx + 	(  i * xlen ) ) < xyzalllen ) ; i++)
	{
	long  grid_id = 	(  idx + 	(  i * xlen ) ) ;
	if (  	(  grid_id < xyzalllen )  ){  
			int  cur_load = (xyzw)[	(  4 * 	(  cu_offset + grid_id ) )] ;
	long  bxyzx = 	(  grid_id % XLEN ) ;
	long  bxyzy = 	(  	(  grid_id / XLEN ) % YLEN ) ;
	long  bxyzz = 	(  grid_id / 	(  XLEN * YLEN ) ) ;
	int  g = 0 ;
	int  lg = 0 ;
	long  plus_offset = 0 ;
	long  minus_offset = 0 ;
	long  left_bound = bxyzx ;
	long  right_bound = 	(  left_bound + 1 ) ;
	int  sizeof_double = sizeof(double ) ;
	long  num_writed_minus = 0 ;
	long  num_writed_plus = 0 ;
	long  num_writed_main = 0 ;
	long  num_write_tmp = 0 ;
	for (lg=0 ; 	(  lg < cur_load ) ; (lg = 	(  lg + 64 )))
	{
	long  num_read = ((	(  	(  lg + 64 ) > cur_load ))?(	(  cur_load - lg )):(64)) ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_read * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_pos_cache + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  lg * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < num_read ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 3 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((local_vel_cache)[	(  	(  inner_step * 3 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  3 + 	(  lg * 6 ) ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}	for (g=0 ; 	(  g < num_read ) ; g++)
	{
	if (  	(  (	(  local_pos_cache + 	(  g * 6 ) ))[0] < left_bound )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_write_tmp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  num_writed_main * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  	(  g - num_write_tmp ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(num_writed_main = 	(  num_writed_main + num_write_tmp ));
(num_write_tmp = 0);
{
	long  i ;
	for ((i = 0) ; 	(  i < 6 ) ; (i = 	(  i + 1 )))
	{
((	(  local_temp_particle_cache_minus + 	(  num_writed_minus * 6 ) ))[i] = (	(  local_pos_cache + 	(  g * 6 ) ))[i]);
}}num_writed_minus++;

	}else{
			if (  	(  (	(  local_pos_cache + 	(  g * 6 ) ))[0] > right_bound )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_write_tmp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  num_writed_main * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  	(  g - num_write_tmp ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(num_writed_main = 	(  num_writed_main + num_write_tmp ));
(num_write_tmp = 0);
{
	long  i ;
	for ((i = 0) ; 	(  i < 6 ) ; (i = 	(  i + 1 )))
	{
((	(  local_temp_particle_cache_plus + 	(  num_writed_plus * 6 ) ))[i] = (	(  local_pos_cache + 	(  g * 6 ) ))[i]);
}}num_writed_plus++;

	}else{
			if (  	(  	(  	(  (local_vel_cache)[	(  	(  g * 3 ) + 0 )] * (local_vel_cache)[	(  	(  g * 3 ) + 0 )] ) + 	(  	(  (local_vel_cache)[	(  	(  g * 3 ) + 1 )] * (local_vel_cache)[	(  	(  g * 3 ) + 1 )] ) + 	(  (local_vel_cache)[	(  	(  g * 3 ) + 2 )] * (local_vel_cache)[	(  	(  g * 3 ) + 2 )] ) ) ) > 1.00000000000000000e+00 )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_write_tmp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  num_writed_main * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  	(  g - num_write_tmp ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(num_writed_main = 	(  num_writed_main + num_write_tmp ));
(num_write_tmp = 0);

	}else{
		num_write_tmp++;

	 }

	 }

	 }
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_write_tmp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  num_writed_main * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  	(  g - num_write_tmp ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(num_writed_main = 	(  num_writed_main + num_write_tmp ));
(num_write_tmp = 0);
}	int  x_main = num_writed_main ;
	int  x_beg_minus = x_main ;
	int  x_beg_plus = 	(  	(  	(  grid_cache_len - cur_load ) / 2 ) + 	(  num_writed_minus + x_main ) ) ;
	int   xm4  [4];((xm4)[0] = x_main);
((xm4)[1] = 	(  num_writed_minus + x_main ));
((xm4)[2] = x_beg_plus);
((xm4)[3] = 	(  num_writed_plus + x_beg_plus ));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 4 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  4 * 	(  cu_offset + grid_id ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (xm4)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_writed_minus ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  x_beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	if (  	(  (xm4)[3] > grid_cache_len )  ){  
			long  i = 0 ;
	for (i=0 ; 	(  i < 4 ) ; i++)
	{
}	assert ( 0 );

	}else{
		0;

	 }
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_writed_plus ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  x_beg_plus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_plus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
}	if (  1  ){  
			for (i=0 ; 	(  	(  idx + 	(  i * xlen ) ) < xyzalllen ) ; i++)
	{
	long  grid_id = 	(  idx + 	(  i * xlen ) ) ;
	if (  	(  grid_id < xyzalllen )  ){  
			int   cur_xyzw  [4];	int   cur_zw  [2];	int   prev_zw  [2];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 4 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((cur_xyzw)[	(  	(  inner_step * 4 ) + inner_g )] = (	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 0 ) ))[	(  	(  inner_step * 4 ) + inner_g )]);
}}}}}	long  bxyzx = 	(  grid_id % XLEN ) ;
	long  bxyzy = 	(  	(  grid_id / XLEN ) % YLEN ) ;
	long  bxyzz = 	(  grid_id / 	(  XLEN * YLEN ) ) ;
	int  is_most_left = 	(  bxyzx == 0 ) ;
	int  is_most_right = 	(  bxyzx == 	(  XLEN - 1 ) ) ;
	if (  is_most_left  ){  
		((prev_zw)[0] = grid_cache_len);
((prev_zw)[1] = grid_cache_len);

	}else{
		{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 2 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((prev_zw)[	(  	(  inner_step * 2 ) + inner_g )] = (	(  xyzw + 	(  	(  4 * 	(  	(  cu_offset + grid_id ) - 1 ) ) + 2 ) ))[	(  	(  inner_step * 2 ) + inner_g )]);
}}}}}
	 }
	int  beg_minus = (cur_xyzw)[0] ;
	int  end_minus = (cur_xyzw)[1] ;
	int  minus_max = (cur_xyzw)[2] ;
	int  beg_plus = (prev_zw)[0] ;
	int  end_plus = (prev_zw)[1] ;
	int  num_to_left = 	(  end_minus - beg_minus ) ;
	int  num_from_left = 	(  end_plus - beg_plus ) ;
	int  num_cur_remains = 	(  minus_max - beg_minus ) ;
	int  num_left_remains = 	(  grid_cache_len - beg_plus ) ;
	#if   0    
			long  j = 0 ;
	if (  	(  	(  bxyzx == 1 ) && 	(  bxyzy == 1 ) )  ){  
			fprintf ( stderr , "idy=%d x=[%d %d %d] main_load=%d cur_rem=%d " , idy , bxyzx , bxyzy , bxyzz , beg_minus , num_cur_remains );
	for (j ; 	(  j < beg_minus ) ; j++)
	{
	fprintf ( stderr , "%e " , (	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ))[	(  j * 6 )] );
}	fprintf ( stderr , "\n" );
	fprintf ( stderr , "x=%d left_load=%d " , bxyzx , 	(  end_minus - beg_minus ) );
	for (j=beg_minus ; 	(  j < end_minus ) ; j++)
	{
	fprintf ( stderr , "%e " , (	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ))[	(  j * 6 )] );
}	fprintf ( stderr , "\n" );
	fprintf ( stderr , "x=%d right_load=%d " , bxyzx , 	(  end_plus - beg_plus ) );
	for (j=beg_plus ; 	(  j < end_plus ) ; j++)
	{
	fprintf ( stderr , "%e " , (	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ))[	(  j * 6 )] );
}	fprintf ( stderr , "\n" );

	}else{
		0;

	 }

	#else
		
	 #endif
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_to_left ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	if (  num_from_left  ){  
		{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_from_left ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_temp_particle_cache_plus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  	(  beg_plus - 	(  1 * grid_cache_len ) ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}
	}else{
		0;

	 }
	int  num_left_to_cu_cache = ((	(  num_cur_remains < num_from_left ))?(	(  num_from_left - num_cur_remains )):(0)) ;
	int  num_cur_to_cu_cache = ((	(  num_left_remains < num_to_left ))?(	(  num_to_left - num_left_remains )):(0)) ;
(num_from_left = ((	(  num_cur_remains < num_from_left ))?(num_cur_remains):(num_from_left)));
(num_to_left = ((	(  num_left_remains < num_to_left ))?(num_left_remains):(num_to_left)));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_from_left * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_plus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	if (  num_to_left  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_to_left * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  	(  beg_plus * 6 ) - 	(  1 * 	(  grid_cache_len * 6 ) ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  num_left_to_cu_cache  ){  
			int  cur_cu_cache_load = ({
	int  tmp0123212663 = (cu_xyzw_shared)[0] ;
((cu_xyzw_shared)[0] = 	(  (cu_xyzw_shared)[0] + num_left_to_cu_cache ));
tmp0123212663;
}) ;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_left_to_cu_cache * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_cache + 	(  	(  idy * 	(  cu_cache_length * 6 ) ) + 	(  cur_cu_cache_load * 6 ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_plus + 	(  num_from_left * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  num_cur_to_cu_cache  ){  
			int  cur_cu_cache_load = ((is_most_left)?(({
	int  tmp0123212663 = (	(  cu_xyzw_shared + 2 ))[0] ;
((	(  cu_xyzw_shared + 2 ))[0] = 	(  (	(  cu_xyzw_shared + 2 ))[0] + num_cur_to_cu_cache ));
tmp0123212663;
})):(({
	int  tmp0123212663 = (cu_xyzw_shared)[0] ;
((cu_xyzw_shared)[0] = 	(  (cu_xyzw_shared)[0] + num_cur_to_cu_cache ));
tmp0123212663;
}))) ;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_cur_to_cu_cache * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_cache + 	(  	(  idy * 	(  cu_cache_length * 6 ) ) + 	(  cur_cu_cache_load * 6 ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  num_to_left * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
(beg_minus = 	(  beg_minus + num_from_left ));
((cur_xyzw)[0] = beg_minus);
((cur_xyzw)[1] = beg_minus);
((prev_zw)[1] = 	(  beg_plus + num_to_left ));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 0 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (cur_xyzw)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	if (  	(  ! is_most_left )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  	(  4 * 	(  cu_offset + 	(  grid_id - 1 ) ) ) + 2 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (prev_zw)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  is_most_right  ){  
			int  cur_beg_plus = (cur_xyzw)[2] ;
	int  cur_end_plus = (cur_xyzw)[3] ;
	int  cur_to_cu_cache = 	(  cur_end_plus - cur_beg_plus ) ;
	int  cur_cu_cache_load = ({
	int  tmp0123212663 = (	(  cu_xyzw_shared + 3 ))[0] ;
((	(  cu_xyzw_shared + 3 ))[0] = 	(  (	(  cu_xyzw_shared + 3 ))[0] + 	- ( cur_to_cu_cache ) ));
tmp0123212663;
}) ;
((cur_xyzw)[2] = beg_minus);
((cur_xyzw)[3] = beg_minus);
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 	(  6 * cur_to_cu_cache ) ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_cache + 	(  	(  idy * 	(  cu_cache_length * 6 ) ) + 	(  	(  cur_cu_cache_load - cur_to_cu_cache ) * 6 ) ) ))[	(  	(  inner_step * 	(  6 * cur_to_cu_cache ) ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  6 * cur_beg_plus ) ))[	(  	(  inner_step * 	(  6 * cur_to_cu_cache ) ) + inner_g )]);
}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 2 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  cur_xyzw + 2 ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
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
	if (  	(  idx == 0 )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 4 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_xyzw + 	(  4 * idy ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (cu_xyzw_shared)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  1  ){  
			for (i=0 ; 	(  	(  idx + 	(  i * xlen ) ) < xyzalllen ) ; i++)
	{
	long  grid_id = 	(  idx + 	(  i * xlen ) ) ;
	if (  	(  grid_id < xyzalllen )  ){  
			int   cur_xyzw  [4];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 4 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((cur_xyzw)[	(  	(  inner_step * 4 ) + inner_g )] = (	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 0 ) ))[	(  	(  inner_step * 4 ) + inner_g )]);
}}}}}	int  beg_minus = (cur_xyzw)[0] ;
	int  beg_plus = (cur_xyzw)[2] ;
	int  end_plus = (cur_xyzw)[3] ;
	int  pluslen = 	(  end_plus - beg_plus ) ;
	int  load0 = 	(  beg_minus + pluslen ) ;
((xyzw)[	(  4 * 	(  cu_offset + grid_id ) )] = load0);
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * pluslen ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_plus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * pluslen ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
}
	}else{
		0;

	 }
}
void  openmp_sort_one_grid_y_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  cu_offset = 	(  idy * 	(  XLEN * 	(  YLEN * ZLEN ) ) ) ;
	long  xyzalllen = 	(  XLEN * 	(  YLEN * ZLEN ) ) ;
	long  i = 0 ;
	double   local_temp_particle_cache_plus  [	(  384 * 6 )];	double   local_temp_particle_cache_minus  [	(  384 * 6 )];	double   local_pos_cache  [	(  64 * 6 )];	double   local_vel_cache  [192];	int   cu_xyzw_shared  [4];	int  cu_cur_cache_load = (cu_xyzw)[	(  4 * idy )] ;
	if (  	(  idx == 0 )  ){  
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
	for (i=0 ; 	(  	(  idx + 	(  i * xlen ) ) < xyzalllen ) ; i++)
	{
	long  grid_id = 	(  idx + 	(  i * xlen ) ) ;
	if (  	(  grid_id < xyzalllen )  ){  
			int  cur_load = (xyzw)[	(  4 * 	(  cu_offset + grid_id ) )] ;
	long  bxyzx = 	(  grid_id % XLEN ) ;
	long  bxyzy = 	(  	(  grid_id / XLEN ) % YLEN ) ;
	long  bxyzz = 	(  grid_id / 	(  XLEN * YLEN ) ) ;
	int  g = 0 ;
	int  lg = 0 ;
	long  plus_offset = 0 ;
	long  minus_offset = 0 ;
	long  left_bound = bxyzy ;
	long  right_bound = 	(  left_bound + 1 ) ;
	int  sizeof_double = sizeof(double ) ;
	long  num_writed_minus = 0 ;
	long  num_writed_plus = 0 ;
	long  num_writed_main = 0 ;
	long  num_write_tmp = 0 ;
	for (lg=0 ; 	(  lg < cur_load ) ; (lg = 	(  lg + 64 )))
	{
	long  num_read = ((	(  	(  lg + 64 ) > cur_load ))?(	(  cur_load - lg )):(64)) ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_read * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_pos_cache + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  lg * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < num_read ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 3 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((local_vel_cache)[	(  	(  inner_step * 3 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  3 + 	(  lg * 6 ) ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}	for (g=0 ; 	(  g < num_read ) ; g++)
	{
	if (  	(  (	(  local_pos_cache + 	(  g * 6 ) ))[1] < left_bound )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_write_tmp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  num_writed_main * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  	(  g - num_write_tmp ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(num_writed_main = 	(  num_writed_main + num_write_tmp ));
(num_write_tmp = 0);
{
	long  i ;
	for ((i = 0) ; 	(  i < 6 ) ; (i = 	(  i + 1 )))
	{
((	(  local_temp_particle_cache_minus + 	(  num_writed_minus * 6 ) ))[i] = (	(  local_pos_cache + 	(  g * 6 ) ))[i]);
}}num_writed_minus++;

	}else{
			if (  	(  (	(  local_pos_cache + 	(  g * 6 ) ))[1] > right_bound )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_write_tmp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  num_writed_main * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  	(  g - num_write_tmp ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(num_writed_main = 	(  num_writed_main + num_write_tmp ));
(num_write_tmp = 0);
{
	long  i ;
	for ((i = 0) ; 	(  i < 6 ) ; (i = 	(  i + 1 )))
	{
((	(  local_temp_particle_cache_plus + 	(  num_writed_plus * 6 ) ))[i] = (	(  local_pos_cache + 	(  g * 6 ) ))[i]);
}}num_writed_plus++;

	}else{
			if (  	(  	(  	(  (local_vel_cache)[	(  	(  g * 3 ) + 0 )] * (local_vel_cache)[	(  	(  g * 3 ) + 0 )] ) + 	(  	(  (local_vel_cache)[	(  	(  g * 3 ) + 1 )] * (local_vel_cache)[	(  	(  g * 3 ) + 1 )] ) + 	(  (local_vel_cache)[	(  	(  g * 3 ) + 2 )] * (local_vel_cache)[	(  	(  g * 3 ) + 2 )] ) ) ) > 1.00000000000000000e+00 )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_write_tmp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  num_writed_main * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  	(  g - num_write_tmp ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(num_writed_main = 	(  num_writed_main + num_write_tmp ));
(num_write_tmp = 0);

	}else{
		num_write_tmp++;

	 }

	 }

	 }
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_write_tmp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  num_writed_main * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  	(  g - num_write_tmp ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(num_writed_main = 	(  num_writed_main + num_write_tmp ));
(num_write_tmp = 0);
}	int  x_main = num_writed_main ;
	int  x_beg_minus = x_main ;
	int  x_beg_plus = 	(  	(  	(  grid_cache_len - cur_load ) / 2 ) + 	(  num_writed_minus + x_main ) ) ;
	int   xm4  [4];((xm4)[0] = x_main);
((xm4)[1] = 	(  num_writed_minus + x_main ));
((xm4)[2] = x_beg_plus);
((xm4)[3] = 	(  num_writed_plus + x_beg_plus ));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 4 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  4 * 	(  cu_offset + grid_id ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (xm4)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_writed_minus ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  x_beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	if (  	(  (xm4)[3] > grid_cache_len )  ){  
			long  i = 0 ;
	for (i=0 ; 	(  i < 4 ) ; i++)
	{
}	assert ( 0 );

	}else{
		0;

	 }
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_writed_plus ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  x_beg_plus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_plus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
}	if (  1  ){  
			for (i=0 ; 	(  	(  idx + 	(  i * xlen ) ) < xyzalllen ) ; i++)
	{
	long  grid_id = 	(  idx + 	(  i * xlen ) ) ;
	if (  	(  grid_id < xyzalllen )  ){  
			int   cur_xyzw  [4];	int   cur_zw  [2];	int   prev_zw  [2];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 4 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((cur_xyzw)[	(  	(  inner_step * 4 ) + inner_g )] = (	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 0 ) ))[	(  	(  inner_step * 4 ) + inner_g )]);
}}}}}	long  bxyzx = 	(  grid_id % XLEN ) ;
	long  bxyzy = 	(  	(  grid_id / XLEN ) % YLEN ) ;
	long  bxyzz = 	(  grid_id / 	(  XLEN * YLEN ) ) ;
	int  is_most_left = 	(  bxyzy == 0 ) ;
	int  is_most_right = 	(  bxyzy == 	(  YLEN - 1 ) ) ;
	if (  is_most_left  ){  
		((prev_zw)[0] = grid_cache_len);
((prev_zw)[1] = grid_cache_len);

	}else{
		{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 2 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((prev_zw)[	(  	(  inner_step * 2 ) + inner_g )] = (	(  xyzw + 	(  	(  4 * 	(  	(  cu_offset + grid_id ) - XLEN ) ) + 2 ) ))[	(  	(  inner_step * 2 ) + inner_g )]);
}}}}}
	 }
	int  beg_minus = (cur_xyzw)[0] ;
	int  end_minus = (cur_xyzw)[1] ;
	int  minus_max = (cur_xyzw)[2] ;
	int  beg_plus = (prev_zw)[0] ;
	int  end_plus = (prev_zw)[1] ;
	int  num_to_left = 	(  end_minus - beg_minus ) ;
	int  num_from_left = 	(  end_plus - beg_plus ) ;
	int  num_cur_remains = 	(  minus_max - beg_minus ) ;
	int  num_left_remains = 	(  grid_cache_len - beg_plus ) ;
	#if   0    
			long  j = 0 ;
	if (  	(  	(  bxyzx == 1 ) && 	(  bxyzy == 1 ) )  ){  
			fprintf ( stderr , "idy=%d x=[%d %d %d] main_load=%d cur_rem=%d " , idy , bxyzx , bxyzy , bxyzz , beg_minus , num_cur_remains );
	for (j ; 	(  j < beg_minus ) ; j++)
	{
	fprintf ( stderr , "%e " , (	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ))[	(  j * 6 )] );
}	fprintf ( stderr , "\n" );
	fprintf ( stderr , "x=%d left_load=%d " , bxyzx , 	(  end_minus - beg_minus ) );
	for (j=beg_minus ; 	(  j < end_minus ) ; j++)
	{
	fprintf ( stderr , "%e " , (	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ))[	(  j * 6 )] );
}	fprintf ( stderr , "\n" );
	fprintf ( stderr , "x=%d right_load=%d " , bxyzx , 	(  end_plus - beg_plus ) );
	for (j=beg_plus ; 	(  j < end_plus ) ; j++)
	{
	fprintf ( stderr , "%e " , (	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ))[	(  j * 6 )] );
}	fprintf ( stderr , "\n" );

	}else{
		0;

	 }

	#else
		
	 #endif
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_to_left ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	if (  num_from_left  ){  
		{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_from_left ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_temp_particle_cache_plus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  	(  beg_plus - 	(  XLEN * grid_cache_len ) ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}
	}else{
		0;

	 }
	int  num_left_to_cu_cache = ((	(  num_cur_remains < num_from_left ))?(	(  num_from_left - num_cur_remains )):(0)) ;
	int  num_cur_to_cu_cache = ((	(  num_left_remains < num_to_left ))?(	(  num_to_left - num_left_remains )):(0)) ;
(num_from_left = ((	(  num_cur_remains < num_from_left ))?(num_cur_remains):(num_from_left)));
(num_to_left = ((	(  num_left_remains < num_to_left ))?(num_left_remains):(num_to_left)));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_from_left * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_plus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	if (  num_to_left  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_to_left * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  	(  beg_plus * 6 ) - 	(  XLEN * 	(  grid_cache_len * 6 ) ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  num_left_to_cu_cache  ){  
			int  cur_cu_cache_load = ({
	int  tmp0123212663 = (cu_xyzw_shared)[0] ;
((cu_xyzw_shared)[0] = 	(  (cu_xyzw_shared)[0] + num_left_to_cu_cache ));
tmp0123212663;
}) ;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_left_to_cu_cache * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_cache + 	(  	(  idy * 	(  cu_cache_length * 6 ) ) + 	(  cur_cu_cache_load * 6 ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_plus + 	(  num_from_left * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  num_cur_to_cu_cache  ){  
			int  cur_cu_cache_load = ((is_most_left)?(({
	int  tmp0123212663 = (	(  cu_xyzw_shared + 2 ))[0] ;
((	(  cu_xyzw_shared + 2 ))[0] = 	(  (	(  cu_xyzw_shared + 2 ))[0] + num_cur_to_cu_cache ));
tmp0123212663;
})):(({
	int  tmp0123212663 = (cu_xyzw_shared)[0] ;
((cu_xyzw_shared)[0] = 	(  (cu_xyzw_shared)[0] + num_cur_to_cu_cache ));
tmp0123212663;
}))) ;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_cur_to_cu_cache * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_cache + 	(  	(  idy * 	(  cu_cache_length * 6 ) ) + 	(  cur_cu_cache_load * 6 ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  num_to_left * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
(beg_minus = 	(  beg_minus + num_from_left ));
((cur_xyzw)[0] = beg_minus);
((cur_xyzw)[1] = beg_minus);
((prev_zw)[1] = 	(  beg_plus + num_to_left ));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 0 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (cur_xyzw)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	if (  	(  ! is_most_left )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  	(  4 * 	(  cu_offset + 	(  grid_id - XLEN ) ) ) + 2 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (prev_zw)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  is_most_right  ){  
			int  cur_beg_plus = (cur_xyzw)[2] ;
	int  cur_end_plus = (cur_xyzw)[3] ;
	int  cur_to_cu_cache = 	(  cur_end_plus - cur_beg_plus ) ;
	int  cur_cu_cache_load = ({
	int  tmp0123212663 = (	(  cu_xyzw_shared + 3 ))[0] ;
((	(  cu_xyzw_shared + 3 ))[0] = 	(  (	(  cu_xyzw_shared + 3 ))[0] + 	- ( cur_to_cu_cache ) ));
tmp0123212663;
}) ;
((cur_xyzw)[2] = beg_minus);
((cur_xyzw)[3] = beg_minus);
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 	(  6 * cur_to_cu_cache ) ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_cache + 	(  	(  idy * 	(  cu_cache_length * 6 ) ) + 	(  	(  cur_cu_cache_load - cur_to_cu_cache ) * 6 ) ) ))[	(  	(  inner_step * 	(  6 * cur_to_cu_cache ) ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  6 * cur_beg_plus ) ))[	(  	(  inner_step * 	(  6 * cur_to_cu_cache ) ) + inner_g )]);
}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 2 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  cur_xyzw + 2 ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
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
	if (  	(  idx == 0 )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 4 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_xyzw + 	(  4 * idy ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (cu_xyzw_shared)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  1  ){  
			for (i=0 ; 	(  	(  idx + 	(  i * xlen ) ) < xyzalllen ) ; i++)
	{
	long  grid_id = 	(  idx + 	(  i * xlen ) ) ;
	if (  	(  grid_id < xyzalllen )  ){  
			int   cur_xyzw  [4];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 4 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((cur_xyzw)[	(  	(  inner_step * 4 ) + inner_g )] = (	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 0 ) ))[	(  	(  inner_step * 4 ) + inner_g )]);
}}}}}	int  beg_minus = (cur_xyzw)[0] ;
	int  beg_plus = (cur_xyzw)[2] ;
	int  end_plus = (cur_xyzw)[3] ;
	int  pluslen = 	(  end_plus - beg_plus ) ;
	int  load0 = 	(  beg_minus + pluslen ) ;
((xyzw)[	(  4 * 	(  cu_offset + grid_id ) )] = load0);
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * pluslen ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_plus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * pluslen ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
}
	}else{
		0;

	 }
}
void  openmp_sort_one_grid_z_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  cu_offset = 	(  idy * 	(  XLEN * 	(  YLEN * ZLEN ) ) ) ;
	long  xyzalllen = 	(  XLEN * 	(  YLEN * ZLEN ) ) ;
	long  i = 0 ;
	double   local_temp_particle_cache_plus  [	(  384 * 6 )];	double   local_temp_particle_cache_minus  [	(  384 * 6 )];	double   local_pos_cache  [	(  64 * 6 )];	double   local_vel_cache  [192];	int   cu_xyzw_shared  [4];	int  cu_cur_cache_load = (cu_xyzw)[	(  4 * idy )] ;
	if (  	(  idx == 0 )  ){  
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
	for (i=0 ; 	(  	(  idx + 	(  i * xlen ) ) < xyzalllen ) ; i++)
	{
	long  grid_id = 	(  idx + 	(  i * xlen ) ) ;
	if (  	(  grid_id < xyzalllen )  ){  
			int  cur_load = (xyzw)[	(  4 * 	(  cu_offset + grid_id ) )] ;
	long  bxyzx = 	(  grid_id % XLEN ) ;
	long  bxyzy = 	(  	(  grid_id / XLEN ) % YLEN ) ;
	long  bxyzz = 	(  grid_id / 	(  XLEN * YLEN ) ) ;
	int  g = 0 ;
	int  lg = 0 ;
	long  plus_offset = 0 ;
	long  minus_offset = 0 ;
	long  left_bound = bxyzz ;
	long  right_bound = 	(  left_bound + 1 ) ;
	int  sizeof_double = sizeof(double ) ;
	long  num_writed_minus = 0 ;
	long  num_writed_plus = 0 ;
	long  num_writed_main = 0 ;
	long  num_write_tmp = 0 ;
	for (lg=0 ; 	(  lg < cur_load ) ; (lg = 	(  lg + 64 )))
	{
	long  num_read = ((	(  	(  lg + 64 ) > cur_load ))?(	(  cur_load - lg )):(64)) ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_read * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_pos_cache + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  lg * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < num_read ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 3 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((local_vel_cache)[	(  	(  inner_step * 3 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  3 + 	(  lg * 6 ) ) ))[	(  	(  inner_step * 6 ) + inner_g )]);
}}}}}	for (g=0 ; 	(  g < num_read ) ; g++)
	{
	if (  	(  (	(  local_pos_cache + 	(  g * 6 ) ))[2] < left_bound )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_write_tmp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  num_writed_main * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  	(  g - num_write_tmp ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(num_writed_main = 	(  num_writed_main + num_write_tmp ));
(num_write_tmp = 0);
{
	long  i ;
	for ((i = 0) ; 	(  i < 6 ) ; (i = 	(  i + 1 )))
	{
((	(  local_temp_particle_cache_minus + 	(  num_writed_minus * 6 ) ))[i] = (	(  local_pos_cache + 	(  g * 6 ) ))[i]);
}}num_writed_minus++;

	}else{
			if (  	(  (	(  local_pos_cache + 	(  g * 6 ) ))[2] > right_bound )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_write_tmp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  num_writed_main * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  	(  g - num_write_tmp ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(num_writed_main = 	(  num_writed_main + num_write_tmp ));
(num_write_tmp = 0);
{
	long  i ;
	for ((i = 0) ; 	(  i < 6 ) ; (i = 	(  i + 1 )))
	{
((	(  local_temp_particle_cache_plus + 	(  num_writed_plus * 6 ) ))[i] = (	(  local_pos_cache + 	(  g * 6 ) ))[i]);
}}num_writed_plus++;

	}else{
			if (  	(  	(  	(  (local_vel_cache)[	(  	(  g * 3 ) + 0 )] * (local_vel_cache)[	(  	(  g * 3 ) + 0 )] ) + 	(  	(  (local_vel_cache)[	(  	(  g * 3 ) + 1 )] * (local_vel_cache)[	(  	(  g * 3 ) + 1 )] ) + 	(  (local_vel_cache)[	(  	(  g * 3 ) + 2 )] * (local_vel_cache)[	(  	(  g * 3 ) + 2 )] ) ) ) > 1.00000000000000000e+00 )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_write_tmp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  num_writed_main * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  	(  g - num_write_tmp ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(num_writed_main = 	(  num_writed_main + num_write_tmp ));
(num_write_tmp = 0);

	}else{
		num_write_tmp++;

	 }

	 }

	 }
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_write_tmp * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  num_writed_main * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_pos_cache + 	(  	(  g - num_write_tmp ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(num_writed_main = 	(  num_writed_main + num_write_tmp ));
(num_write_tmp = 0);
}	int  x_main = num_writed_main ;
	int  x_beg_minus = x_main ;
	int  x_beg_plus = 	(  	(  	(  grid_cache_len - cur_load ) / 2 ) + 	(  num_writed_minus + x_main ) ) ;
	int   xm4  [4];((xm4)[0] = x_main);
((xm4)[1] = 	(  num_writed_minus + x_main ));
((xm4)[2] = x_beg_plus);
((xm4)[3] = 	(  num_writed_plus + x_beg_plus ));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 4 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  4 * 	(  cu_offset + grid_id ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (xm4)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_writed_minus ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  x_beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	if (  	(  (xm4)[3] > grid_cache_len )  ){  
			long  i = 0 ;
	for (i=0 ; 	(  i < 4 ) ; i++)
	{
}	assert ( 0 );

	}else{
		0;

	 }
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_writed_plus ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  x_beg_plus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_plus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
}	if (  1  ){  
			for (i=0 ; 	(  	(  idx + 	(  i * xlen ) ) < xyzalllen ) ; i++)
	{
	long  grid_id = 	(  idx + 	(  i * xlen ) ) ;
	if (  	(  grid_id < xyzalllen )  ){  
			int   cur_xyzw  [4];	int   cur_zw  [2];	int   prev_zw  [2];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 4 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((cur_xyzw)[	(  	(  inner_step * 4 ) + inner_g )] = (	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 0 ) ))[	(  	(  inner_step * 4 ) + inner_g )]);
}}}}}	long  bxyzx = 	(  grid_id % XLEN ) ;
	long  bxyzy = 	(  	(  grid_id / XLEN ) % YLEN ) ;
	long  bxyzz = 	(  grid_id / 	(  XLEN * YLEN ) ) ;
	int  is_most_left = 	(  bxyzz == 0 ) ;
	int  is_most_right = 	(  bxyzz == 	(  ZLEN - 1 ) ) ;
	if (  is_most_left  ){  
		((prev_zw)[0] = grid_cache_len);
((prev_zw)[1] = grid_cache_len);

	}else{
		{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 2 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((prev_zw)[	(  	(  inner_step * 2 ) + inner_g )] = (	(  xyzw + 	(  	(  4 * 	(  	(  cu_offset + grid_id ) - 	(  XLEN * YLEN ) ) ) + 2 ) ))[	(  	(  inner_step * 2 ) + inner_g )]);
}}}}}
	 }
	int  beg_minus = (cur_xyzw)[0] ;
	int  end_minus = (cur_xyzw)[1] ;
	int  minus_max = (cur_xyzw)[2] ;
	int  beg_plus = (prev_zw)[0] ;
	int  end_plus = (prev_zw)[1] ;
	int  num_to_left = 	(  end_minus - beg_minus ) ;
	int  num_from_left = 	(  end_plus - beg_plus ) ;
	int  num_cur_remains = 	(  minus_max - beg_minus ) ;
	int  num_left_remains = 	(  grid_cache_len - beg_plus ) ;
	#if   0    
			long  j = 0 ;
	if (  	(  	(  bxyzx == 1 ) && 	(  bxyzy == 1 ) )  ){  
			fprintf ( stderr , "idy=%d x=[%d %d %d] main_load=%d cur_rem=%d " , idy , bxyzx , bxyzy , bxyzz , beg_minus , num_cur_remains );
	for (j ; 	(  j < beg_minus ) ; j++)
	{
	fprintf ( stderr , "%e " , (	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ))[	(  j * 6 )] );
}	fprintf ( stderr , "\n" );
	fprintf ( stderr , "x=%d left_load=%d " , bxyzx , 	(  end_minus - beg_minus ) );
	for (j=beg_minus ; 	(  j < end_minus ) ; j++)
	{
	fprintf ( stderr , "%e " , (	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ))[	(  j * 6 )] );
}	fprintf ( stderr , "\n" );
	fprintf ( stderr , "x=%d right_load=%d " , bxyzx , 	(  end_plus - beg_plus ) );
	for (j=beg_plus ; 	(  j < end_plus ) ; j++)
	{
	fprintf ( stderr , "%e " , (	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ))[	(  j * 6 )] );
}	fprintf ( stderr , "\n" );

	}else{
		0;

	 }

	#else
		
	 #endif
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_to_left ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	if (  num_from_left  ){  
		{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_from_left ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_temp_particle_cache_plus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  	(  beg_plus - 	(  	(  XLEN * YLEN ) * grid_cache_len ) ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}
	}else{
		0;

	 }
	int  num_left_to_cu_cache = ((	(  num_cur_remains < num_from_left ))?(	(  num_from_left - num_cur_remains )):(0)) ;
	int  num_cur_to_cu_cache = ((	(  num_left_remains < num_to_left ))?(	(  num_to_left - num_left_remains )):(0)) ;
(num_from_left = ((	(  num_cur_remains < num_from_left ))?(num_cur_remains):(num_from_left)));
(num_to_left = ((	(  num_left_remains < num_to_left ))?(num_left_remains):(num_to_left)));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_from_left * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_plus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	if (  num_to_left  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_to_left * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  	(  beg_plus * 6 ) - 	(  	(  XLEN * YLEN ) * 	(  grid_cache_len * 6 ) ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  num_left_to_cu_cache  ){  
			int  cur_cu_cache_load = ({
	int  tmp0123212663 = (cu_xyzw_shared)[0] ;
((cu_xyzw_shared)[0] = 	(  (cu_xyzw_shared)[0] + num_left_to_cu_cache ));
tmp0123212663;
}) ;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_left_to_cu_cache * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_cache + 	(  	(  idy * 	(  cu_cache_length * 6 ) ) + 	(  cur_cu_cache_load * 6 ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_plus + 	(  num_from_left * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  num_cur_to_cu_cache  ){  
			int  cur_cu_cache_load = ((is_most_left)?(({
	int  tmp0123212663 = (	(  cu_xyzw_shared + 2 ))[0] ;
((	(  cu_xyzw_shared + 2 ))[0] = 	(  (	(  cu_xyzw_shared + 2 ))[0] + num_cur_to_cu_cache ));
tmp0123212663;
})):(({
	int  tmp0123212663 = (cu_xyzw_shared)[0] ;
((cu_xyzw_shared)[0] = 	(  (cu_xyzw_shared)[0] + num_cur_to_cu_cache ));
tmp0123212663;
}))) ;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_cur_to_cu_cache * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_cache + 	(  	(  idy * 	(  cu_cache_length * 6 ) ) + 	(  cur_cu_cache_load * 6 ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  num_to_left * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
(beg_minus = 	(  beg_minus + num_from_left ));
((cur_xyzw)[0] = beg_minus);
((cur_xyzw)[1] = beg_minus);
((prev_zw)[1] = 	(  beg_plus + num_to_left ));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 0 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (cur_xyzw)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	if (  	(  ! is_most_left )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  	(  4 * 	(  cu_offset + 	(  grid_id - 	(  XLEN * YLEN ) ) ) ) + 2 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (prev_zw)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  is_most_right  ){  
			int  cur_beg_plus = (cur_xyzw)[2] ;
	int  cur_end_plus = (cur_xyzw)[3] ;
	int  cur_to_cu_cache = 	(  cur_end_plus - cur_beg_plus ) ;
	int  cur_cu_cache_load = ({
	int  tmp0123212663 = (	(  cu_xyzw_shared + 3 ))[0] ;
((	(  cu_xyzw_shared + 3 ))[0] = 	(  (	(  cu_xyzw_shared + 3 ))[0] + 	- ( cur_to_cu_cache ) ));
tmp0123212663;
}) ;
((cur_xyzw)[2] = beg_minus);
((cur_xyzw)[3] = beg_minus);
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 	(  6 * cur_to_cu_cache ) ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_cache + 	(  	(  idy * 	(  cu_cache_length * 6 ) ) + 	(  	(  cur_cu_cache_load - cur_to_cu_cache ) * 6 ) ) ))[	(  	(  inner_step * 	(  6 * cur_to_cu_cache ) ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  6 * cur_beg_plus ) ))[	(  	(  inner_step * 	(  6 * cur_to_cu_cache ) ) + inner_g )]);
}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 2 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  cur_xyzw + 2 ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
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
	if (  	(  idx == 0 )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 4 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_xyzw + 	(  4 * idy ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (cu_xyzw_shared)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  1  ){  
			for (i=0 ; 	(  	(  idx + 	(  i * xlen ) ) < xyzalllen ) ; i++)
	{
	long  grid_id = 	(  idx + 	(  i * xlen ) ) ;
	if (  	(  grid_id < xyzalllen )  ){  
			int   cur_xyzw  [4];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 4 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((cur_xyzw)[	(  	(  inner_step * 4 ) + inner_g )] = (	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 0 ) ))[	(  	(  inner_step * 4 ) + inner_g )]);
}}}}}	int  beg_minus = (cur_xyzw)[0] ;
	int  beg_plus = (cur_xyzw)[2] ;
	int  end_plus = (cur_xyzw)[3] ;
	int  pluslen = 	(  end_plus - beg_plus ) ;
	int  load0 = 	(  beg_minus + pluslen ) ;
((xyzw)[	(  4 * 	(  cu_offset + grid_id ) )] = load0);
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * pluslen ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_plus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * pluslen ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
}
	}else{
		0;

	 }
}
void  openmp_sort_one_grid_x_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  cu_offset = 	(  idy * 	(  XLEN * 	(  YLEN * ZLEN ) ) ) ;
	long  xyzalllen = 	(  XLEN * 	(  YLEN * ZLEN ) ) ;
	long  i = 0 ;
	double   local_temp_particle_cache_plus  [	(  384 * 6 )];	double   local_temp_particle_cache_minus  [	(  384 * 6 )];	double   local_pos_cache  [	(  64 * 6 )];	double   local_vel_cache  [192];	int   cu_xyzw_shared  [4];{
	long  lg = 0 ;
	for (0 ; 	(  lg < 4 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 4 )  ){  
		((cu_xyzw_shared)[ridx] = (	(  cu_xyzw + 	(  4 * idy ) ))[ridx]);

	}else{
		0;

	 }
}}	if (  1  ){  
			for (i=0 ; 	(  	(  idx + 	(  i * xlen ) ) < xyzalllen ) ; i++)
	{
	long  grid_id = 	(  idx + 	(  i * xlen ) ) ;
	if (  	(  grid_id < xyzalllen )  ){  
			int   cur_xyzw  [4];	int   cur_zw  [2];	int   prev_zw  [2];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 4 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((cur_xyzw)[	(  	(  inner_step * 4 ) + inner_g )] = (	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 0 ) ))[	(  	(  inner_step * 4 ) + inner_g )]);
}}}}}	long  bxyzx = 	(  grid_id % XLEN ) ;
	long  bxyzy = 	(  	(  grid_id / XLEN ) % YLEN ) ;
	long  bxyzz = 	(  grid_id / 	(  XLEN * YLEN ) ) ;
	int  is_most_left = 	(  bxyzx == 0 ) ;
	int  is_most_right = 	(  bxyzx == 	(  XLEN - 1 ) ) ;
	if (  is_most_left  ){  
		((prev_zw)[0] = grid_cache_len);
((prev_zw)[1] = grid_cache_len);

	}else{
		{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 2 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((prev_zw)[	(  	(  inner_step * 2 ) + inner_g )] = (	(  xyzw + 	(  	(  4 * 	(  	(  cu_offset + grid_id ) - 1 ) ) + 2 ) ))[	(  	(  inner_step * 2 ) + inner_g )]);
}}}}}
	 }
	int  beg_minus = (cur_xyzw)[0] ;
	int  end_minus = (cur_xyzw)[1] ;
	int  minus_max = (cur_xyzw)[2] ;
	int  beg_plus = (prev_zw)[0] ;
	int  end_plus = (prev_zw)[1] ;
	int  num_to_left = 	(  end_minus - beg_minus ) ;
	int  num_from_left = 	(  end_plus - beg_plus ) ;
	int  num_cur_remains = 	(  minus_max - beg_minus ) ;
	int  num_left_remains = 	(  grid_cache_len - beg_plus ) ;
	#if   0    
			long  j = 0 ;
	if (  	(  	(  bxyzx == 1 ) && 	(  bxyzy == 1 ) )  ){  
			fprintf ( stderr , "idy=%d x=[%d %d %d] main_load=%d cur_rem=%d " , idy , bxyzx , bxyzy , bxyzz , beg_minus , num_cur_remains );
	for (j ; 	(  j < beg_minus ) ; j++)
	{
	fprintf ( stderr , "%e " , (	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ))[	(  j * 6 )] );
}	fprintf ( stderr , "\n" );
	fprintf ( stderr , "x=%d left_load=%d " , bxyzx , 	(  end_minus - beg_minus ) );
	for (j=beg_minus ; 	(  j < end_minus ) ; j++)
	{
	fprintf ( stderr , "%e " , (	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ))[	(  j * 6 )] );
}	fprintf ( stderr , "\n" );
	fprintf ( stderr , "x=%d right_load=%d " , bxyzx , 	(  end_plus - beg_plus ) );
	for (j=beg_plus ; 	(  j < end_plus ) ; j++)
	{
	fprintf ( stderr , "%e " , (	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ))[	(  j * 6 )] );
}	fprintf ( stderr , "\n" );

	}else{
		0;

	 }

	#else
		
	 #endif
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_to_left ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	if (  num_from_left  ){  
		{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_from_left ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_temp_particle_cache_plus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  	(  beg_plus - 	(  1 * grid_cache_len ) ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}
	}else{
		0;

	 }
	int  num_left_to_cu_cache = ((	(  num_cur_remains < num_from_left ))?(	(  num_from_left - num_cur_remains )):(0)) ;
	int  num_cur_to_cu_cache = ((	(  num_left_remains < num_to_left ))?(	(  num_to_left - num_left_remains )):(0)) ;
(num_from_left = ((	(  num_cur_remains < num_from_left ))?(num_cur_remains):(num_from_left)));
(num_to_left = ((	(  num_left_remains < num_to_left ))?(num_left_remains):(num_to_left)));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_from_left * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_plus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	if (  num_to_left  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_to_left * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  	(  beg_plus * 6 ) - 	(  1 * 	(  grid_cache_len * 6 ) ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  num_left_to_cu_cache  ){  
			int  cur_cu_cache_load = ({
	int  tmp0123212663 = (cu_xyzw_shared)[0] ;
((cu_xyzw_shared)[0] = 	(  (cu_xyzw_shared)[0] + num_left_to_cu_cache ));
tmp0123212663;
}) ;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_left_to_cu_cache * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_cache + 	(  	(  idy * 	(  cu_cache_length * 6 ) ) + 	(  cur_cu_cache_load * 6 ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_plus + 	(  num_from_left * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  num_cur_to_cu_cache  ){  
			int  cur_cu_cache_load = ((is_most_left)?(({
	int  tmp0123212663 = (	(  cu_xyzw_shared + 2 ))[0] ;
((	(  cu_xyzw_shared + 2 ))[0] = 	(  (	(  cu_xyzw_shared + 2 ))[0] + num_cur_to_cu_cache ));
tmp0123212663;
})):(({
	int  tmp0123212663 = (cu_xyzw_shared)[0] ;
((cu_xyzw_shared)[0] = 	(  (cu_xyzw_shared)[0] + num_cur_to_cu_cache ));
tmp0123212663;
}))) ;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_cur_to_cu_cache * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_cache + 	(  	(  idy * 	(  cu_cache_length * 6 ) ) + 	(  cur_cu_cache_load * 6 ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  num_to_left * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
(beg_minus = 	(  beg_minus + num_from_left ));
((cur_xyzw)[0] = beg_minus);
((cur_xyzw)[1] = beg_minus);
((prev_zw)[1] = 	(  beg_plus + num_to_left ));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 0 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (cur_xyzw)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	if (  	(  ! is_most_left )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  	(  4 * 	(  cu_offset + 	(  grid_id - 1 ) ) ) + 2 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (prev_zw)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  is_most_right  ){  
			int  cur_beg_plus = (cur_xyzw)[2] ;
	int  cur_end_plus = (cur_xyzw)[3] ;
	int  cur_to_cu_cache = 	(  cur_end_plus - cur_beg_plus ) ;
	int  cur_cu_cache_load = ({
	int  tmp0123212663 = (	(  cu_xyzw_shared + 3 ))[0] ;
((	(  cu_xyzw_shared + 3 ))[0] = 	(  (	(  cu_xyzw_shared + 3 ))[0] + 	- ( cur_to_cu_cache ) ));
tmp0123212663;
}) ;
((cur_xyzw)[2] = beg_minus);
((cur_xyzw)[3] = beg_minus);
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 	(  6 * cur_to_cu_cache ) ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_cache + 	(  	(  idy * 	(  cu_cache_length * 6 ) ) + 	(  	(  cur_cu_cache_load - cur_to_cu_cache ) * 6 ) ) ))[	(  	(  inner_step * 	(  6 * cur_to_cu_cache ) ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  6 * cur_beg_plus ) ))[	(  	(  inner_step * 	(  6 * cur_to_cu_cache ) ) + inner_g )]);
}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 2 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  cur_xyzw + 2 ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
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
	if (  	(  idx == 0 )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 4 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_xyzw + 	(  4 * idy ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (cu_xyzw_shared)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  1  ){  
			for (i=0 ; 	(  	(  idx + 	(  i * xlen ) ) < xyzalllen ) ; i++)
	{
	long  grid_id = 	(  idx + 	(  i * xlen ) ) ;
	if (  	(  grid_id < xyzalllen )  ){  
			int   cur_xyzw  [4];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 4 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((cur_xyzw)[	(  	(  inner_step * 4 ) + inner_g )] = (	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 0 ) ))[	(  	(  inner_step * 4 ) + inner_g )]);
}}}}}	int  beg_minus = (cur_xyzw)[0] ;
	int  beg_plus = (cur_xyzw)[2] ;
	int  end_plus = (cur_xyzw)[3] ;
	int  pluslen = 	(  end_plus - beg_plus ) ;
	int  load0 = 	(  beg_minus + pluslen ) ;
((xyzw)[	(  4 * 	(  cu_offset + grid_id ) )] = load0);
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * pluslen ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_plus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * pluslen ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
}
	}else{
		0;

	 }
}
void  openmp_sort_one_grid_y_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  cu_offset = 	(  idy * 	(  XLEN * 	(  YLEN * ZLEN ) ) ) ;
	long  xyzalllen = 	(  XLEN * 	(  YLEN * ZLEN ) ) ;
	long  i = 0 ;
	double   local_temp_particle_cache_plus  [	(  384 * 6 )];	double   local_temp_particle_cache_minus  [	(  384 * 6 )];	double   local_pos_cache  [	(  64 * 6 )];	double   local_vel_cache  [192];	int   cu_xyzw_shared  [4];{
	long  lg = 0 ;
	for (0 ; 	(  lg < 4 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 4 )  ){  
		((cu_xyzw_shared)[ridx] = (	(  cu_xyzw + 	(  4 * idy ) ))[ridx]);

	}else{
		0;

	 }
}}	if (  1  ){  
			for (i=0 ; 	(  	(  idx + 	(  i * xlen ) ) < xyzalllen ) ; i++)
	{
	long  grid_id = 	(  idx + 	(  i * xlen ) ) ;
	if (  	(  grid_id < xyzalllen )  ){  
			int   cur_xyzw  [4];	int   cur_zw  [2];	int   prev_zw  [2];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 4 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((cur_xyzw)[	(  	(  inner_step * 4 ) + inner_g )] = (	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 0 ) ))[	(  	(  inner_step * 4 ) + inner_g )]);
}}}}}	long  bxyzx = 	(  grid_id % XLEN ) ;
	long  bxyzy = 	(  	(  grid_id / XLEN ) % YLEN ) ;
	long  bxyzz = 	(  grid_id / 	(  XLEN * YLEN ) ) ;
	int  is_most_left = 	(  bxyzy == 0 ) ;
	int  is_most_right = 	(  bxyzy == 	(  YLEN - 1 ) ) ;
	if (  is_most_left  ){  
		((prev_zw)[0] = grid_cache_len);
((prev_zw)[1] = grid_cache_len);

	}else{
		{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 2 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((prev_zw)[	(  	(  inner_step * 2 ) + inner_g )] = (	(  xyzw + 	(  	(  4 * 	(  	(  cu_offset + grid_id ) - XLEN ) ) + 2 ) ))[	(  	(  inner_step * 2 ) + inner_g )]);
}}}}}
	 }
	int  beg_minus = (cur_xyzw)[0] ;
	int  end_minus = (cur_xyzw)[1] ;
	int  minus_max = (cur_xyzw)[2] ;
	int  beg_plus = (prev_zw)[0] ;
	int  end_plus = (prev_zw)[1] ;
	int  num_to_left = 	(  end_minus - beg_minus ) ;
	int  num_from_left = 	(  end_plus - beg_plus ) ;
	int  num_cur_remains = 	(  minus_max - beg_minus ) ;
	int  num_left_remains = 	(  grid_cache_len - beg_plus ) ;
	#if   0    
			long  j = 0 ;
	if (  	(  	(  bxyzx == 1 ) && 	(  bxyzy == 1 ) )  ){  
			fprintf ( stderr , "idy=%d x=[%d %d %d] main_load=%d cur_rem=%d " , idy , bxyzx , bxyzy , bxyzz , beg_minus , num_cur_remains );
	for (j ; 	(  j < beg_minus ) ; j++)
	{
	fprintf ( stderr , "%e " , (	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ))[	(  j * 6 )] );
}	fprintf ( stderr , "\n" );
	fprintf ( stderr , "x=%d left_load=%d " , bxyzx , 	(  end_minus - beg_minus ) );
	for (j=beg_minus ; 	(  j < end_minus ) ; j++)
	{
	fprintf ( stderr , "%e " , (	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ))[	(  j * 6 )] );
}	fprintf ( stderr , "\n" );
	fprintf ( stderr , "x=%d right_load=%d " , bxyzx , 	(  end_plus - beg_plus ) );
	for (j=beg_plus ; 	(  j < end_plus ) ; j++)
	{
	fprintf ( stderr , "%e " , (	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ))[	(  j * 6 )] );
}	fprintf ( stderr , "\n" );

	}else{
		0;

	 }

	#else
		
	 #endif
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_to_left ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	if (  num_from_left  ){  
		{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_from_left ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_temp_particle_cache_plus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  	(  beg_plus - 	(  XLEN * grid_cache_len ) ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}
	}else{
		0;

	 }
	int  num_left_to_cu_cache = ((	(  num_cur_remains < num_from_left ))?(	(  num_from_left - num_cur_remains )):(0)) ;
	int  num_cur_to_cu_cache = ((	(  num_left_remains < num_to_left ))?(	(  num_to_left - num_left_remains )):(0)) ;
(num_from_left = ((	(  num_cur_remains < num_from_left ))?(num_cur_remains):(num_from_left)));
(num_to_left = ((	(  num_left_remains < num_to_left ))?(num_left_remains):(num_to_left)));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_from_left * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_plus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	if (  num_to_left  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_to_left * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  	(  beg_plus * 6 ) - 	(  XLEN * 	(  grid_cache_len * 6 ) ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  num_left_to_cu_cache  ){  
			int  cur_cu_cache_load = ({
	int  tmp0123212663 = (cu_xyzw_shared)[0] ;
((cu_xyzw_shared)[0] = 	(  (cu_xyzw_shared)[0] + num_left_to_cu_cache ));
tmp0123212663;
}) ;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_left_to_cu_cache * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_cache + 	(  	(  idy * 	(  cu_cache_length * 6 ) ) + 	(  cur_cu_cache_load * 6 ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_plus + 	(  num_from_left * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  num_cur_to_cu_cache  ){  
			int  cur_cu_cache_load = ((is_most_left)?(({
	int  tmp0123212663 = (	(  cu_xyzw_shared + 2 ))[0] ;
((	(  cu_xyzw_shared + 2 ))[0] = 	(  (	(  cu_xyzw_shared + 2 ))[0] + num_cur_to_cu_cache ));
tmp0123212663;
})):(({
	int  tmp0123212663 = (cu_xyzw_shared)[0] ;
((cu_xyzw_shared)[0] = 	(  (cu_xyzw_shared)[0] + num_cur_to_cu_cache ));
tmp0123212663;
}))) ;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_cur_to_cu_cache * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_cache + 	(  	(  idy * 	(  cu_cache_length * 6 ) ) + 	(  cur_cu_cache_load * 6 ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  num_to_left * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
(beg_minus = 	(  beg_minus + num_from_left ));
((cur_xyzw)[0] = beg_minus);
((cur_xyzw)[1] = beg_minus);
((prev_zw)[1] = 	(  beg_plus + num_to_left ));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 0 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (cur_xyzw)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	if (  	(  ! is_most_left )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  	(  4 * 	(  cu_offset + 	(  grid_id - XLEN ) ) ) + 2 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (prev_zw)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  is_most_right  ){  
			int  cur_beg_plus = (cur_xyzw)[2] ;
	int  cur_end_plus = (cur_xyzw)[3] ;
	int  cur_to_cu_cache = 	(  cur_end_plus - cur_beg_plus ) ;
	int  cur_cu_cache_load = ({
	int  tmp0123212663 = (	(  cu_xyzw_shared + 3 ))[0] ;
((	(  cu_xyzw_shared + 3 ))[0] = 	(  (	(  cu_xyzw_shared + 3 ))[0] + 	- ( cur_to_cu_cache ) ));
tmp0123212663;
}) ;
((cur_xyzw)[2] = beg_minus);
((cur_xyzw)[3] = beg_minus);
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 	(  6 * cur_to_cu_cache ) ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_cache + 	(  	(  idy * 	(  cu_cache_length * 6 ) ) + 	(  	(  cur_cu_cache_load - cur_to_cu_cache ) * 6 ) ) ))[	(  	(  inner_step * 	(  6 * cur_to_cu_cache ) ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  6 * cur_beg_plus ) ))[	(  	(  inner_step * 	(  6 * cur_to_cu_cache ) ) + inner_g )]);
}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 2 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  cur_xyzw + 2 ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
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
	if (  	(  idx == 0 )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 4 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_xyzw + 	(  4 * idy ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (cu_xyzw_shared)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  1  ){  
			for (i=0 ; 	(  	(  idx + 	(  i * xlen ) ) < xyzalllen ) ; i++)
	{
	long  grid_id = 	(  idx + 	(  i * xlen ) ) ;
	if (  	(  grid_id < xyzalllen )  ){  
			int   cur_xyzw  [4];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 4 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((cur_xyzw)[	(  	(  inner_step * 4 ) + inner_g )] = (	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 0 ) ))[	(  	(  inner_step * 4 ) + inner_g )]);
}}}}}	int  beg_minus = (cur_xyzw)[0] ;
	int  beg_plus = (cur_xyzw)[2] ;
	int  end_plus = (cur_xyzw)[3] ;
	int  pluslen = 	(  end_plus - beg_plus ) ;
	int  load0 = 	(  beg_minus + pluslen ) ;
((xyzw)[	(  4 * 	(  cu_offset + grid_id ) )] = load0);
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * pluslen ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_plus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * pluslen ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
}
	}else{
		0;

	 }
}
void  openmp_sort_one_grid_z_vlo_scmc_kernel (double *  inoutput ,int *  xyzw ,double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  XLEN ,long  YLEN ,long  ZLEN ,int  ovlp ,long  numvec ,long  grid_cache_len ,long  cu_cache_length ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  cu_offset = 	(  idy * 	(  XLEN * 	(  YLEN * ZLEN ) ) ) ;
	long  xyzalllen = 	(  XLEN * 	(  YLEN * ZLEN ) ) ;
	long  i = 0 ;
	double   local_temp_particle_cache_plus  [	(  384 * 6 )];	double   local_temp_particle_cache_minus  [	(  384 * 6 )];	double   local_pos_cache  [	(  64 * 6 )];	double   local_vel_cache  [192];	int   cu_xyzw_shared  [4];{
	long  lg = 0 ;
	for (0 ; 	(  lg < 4 ) ; (lg = 	(  lg + xlen )))
	{
	int  ridx = 	(  lg + idx ) ;
	if (  	(  ridx < 4 )  ){  
		((cu_xyzw_shared)[ridx] = (	(  cu_xyzw + 	(  4 * idy ) ))[ridx]);

	}else{
		0;

	 }
}}	if (  1  ){  
			for (i=0 ; 	(  	(  idx + 	(  i * xlen ) ) < xyzalllen ) ; i++)
	{
	long  grid_id = 	(  idx + 	(  i * xlen ) ) ;
	if (  	(  grid_id < xyzalllen )  ){  
			int   cur_xyzw  [4];	int   cur_zw  [2];	int   prev_zw  [2];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 4 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((cur_xyzw)[	(  	(  inner_step * 4 ) + inner_g )] = (	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 0 ) ))[	(  	(  inner_step * 4 ) + inner_g )]);
}}}}}	long  bxyzx = 	(  grid_id % XLEN ) ;
	long  bxyzy = 	(  	(  grid_id / XLEN ) % YLEN ) ;
	long  bxyzz = 	(  grid_id / 	(  XLEN * YLEN ) ) ;
	int  is_most_left = 	(  bxyzz == 0 ) ;
	int  is_most_right = 	(  bxyzz == 	(  ZLEN - 1 ) ) ;
	if (  is_most_left  ){  
		((prev_zw)[0] = grid_cache_len);
((prev_zw)[1] = grid_cache_len);

	}else{
		{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 2 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((prev_zw)[	(  	(  inner_step * 2 ) + inner_g )] = (	(  xyzw + 	(  	(  4 * 	(  	(  cu_offset + grid_id ) - 	(  XLEN * YLEN ) ) ) + 2 ) ))[	(  	(  inner_step * 2 ) + inner_g )]);
}}}}}
	 }
	int  beg_minus = (cur_xyzw)[0] ;
	int  end_minus = (cur_xyzw)[1] ;
	int  minus_max = (cur_xyzw)[2] ;
	int  beg_plus = (prev_zw)[0] ;
	int  end_plus = (prev_zw)[1] ;
	int  num_to_left = 	(  end_minus - beg_minus ) ;
	int  num_from_left = 	(  end_plus - beg_plus ) ;
	int  num_cur_remains = 	(  minus_max - beg_minus ) ;
	int  num_left_remains = 	(  grid_cache_len - beg_plus ) ;
	#if   0    
			long  j = 0 ;
	if (  	(  	(  bxyzx == 1 ) && 	(  bxyzy == 1 ) )  ){  
			fprintf ( stderr , "idy=%d x=[%d %d %d] main_load=%d cur_rem=%d " , idy , bxyzx , bxyzy , bxyzz , beg_minus , num_cur_remains );
	for (j ; 	(  j < beg_minus ) ; j++)
	{
	fprintf ( stderr , "%e " , (	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ))[	(  j * 6 )] );
}	fprintf ( stderr , "\n" );
	fprintf ( stderr , "x=%d left_load=%d " , bxyzx , 	(  end_minus - beg_minus ) );
	for (j=beg_minus ; 	(  j < end_minus ) ; j++)
	{
	fprintf ( stderr , "%e " , (	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ))[	(  j * 6 )] );
}	fprintf ( stderr , "\n" );
	fprintf ( stderr , "x=%d right_load=%d " , bxyzx , 	(  end_plus - beg_plus ) );
	for (j=beg_plus ; 	(  j < end_plus ) ; j++)
	{
	fprintf ( stderr , "%e " , (	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ))[	(  j * 6 )] );
}	fprintf ( stderr , "\n" );

	}else{
		0;

	 }

	#else
		
	 #endif
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_to_left ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	if (  num_from_left  ){  
		{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_from_left ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_temp_particle_cache_plus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  	(  beg_plus - 	(  	(  XLEN * YLEN ) * grid_cache_len ) ) * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}
	}else{
		0;

	 }
	int  num_left_to_cu_cache = ((	(  num_cur_remains < num_from_left ))?(	(  num_from_left - num_cur_remains )):(0)) ;
	int  num_cur_to_cu_cache = ((	(  num_left_remains < num_to_left ))?(	(  num_to_left - num_left_remains )):(0)) ;
(num_from_left = ((	(  num_cur_remains < num_from_left ))?(num_cur_remains):(num_from_left)));
(num_to_left = ((	(  num_left_remains < num_to_left ))?(num_left_remains):(num_to_left)));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_from_left * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_plus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	if (  num_to_left  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_to_left * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  	(  beg_plus * 6 ) - 	(  	(  XLEN * YLEN ) * 	(  grid_cache_len * 6 ) ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  num_left_to_cu_cache  ){  
			int  cur_cu_cache_load = ({
	int  tmp0123212663 = (cu_xyzw_shared)[0] ;
((cu_xyzw_shared)[0] = 	(  (cu_xyzw_shared)[0] + num_left_to_cu_cache ));
tmp0123212663;
}) ;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_left_to_cu_cache * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_cache + 	(  	(  idy * 	(  cu_cache_length * 6 ) ) + 	(  cur_cu_cache_load * 6 ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_plus + 	(  num_from_left * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  num_cur_to_cu_cache  ){  
			int  cur_cu_cache_load = ((is_most_left)?(({
	int  tmp0123212663 = (	(  cu_xyzw_shared + 2 ))[0] ;
((	(  cu_xyzw_shared + 2 ))[0] = 	(  (	(  cu_xyzw_shared + 2 ))[0] + num_cur_to_cu_cache ));
tmp0123212663;
})):(({
	int  tmp0123212663 = (cu_xyzw_shared)[0] ;
((cu_xyzw_shared)[0] = 	(  (cu_xyzw_shared)[0] + num_cur_to_cu_cache ));
tmp0123212663;
}))) ;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  num_cur_to_cu_cache * 6 ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_cache + 	(  	(  idy * 	(  cu_cache_length * 6 ) ) + 	(  cur_cu_cache_load * 6 ) ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  num_to_left * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
(beg_minus = 	(  beg_minus + num_from_left ));
((cur_xyzw)[0] = beg_minus);
((cur_xyzw)[1] = beg_minus);
((prev_zw)[1] = 	(  beg_plus + num_to_left ));
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 0 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (cur_xyzw)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	if (  	(  ! is_most_left )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  	(  4 * 	(  cu_offset + 	(  grid_id - 	(  XLEN * YLEN ) ) ) ) + 2 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (prev_zw)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  is_most_right  ){  
			int  cur_beg_plus = (cur_xyzw)[2] ;
	int  cur_end_plus = (cur_xyzw)[3] ;
	int  cur_to_cu_cache = 	(  cur_end_plus - cur_beg_plus ) ;
	int  cur_cu_cache_load = ({
	int  tmp0123212663 = (	(  cu_xyzw_shared + 3 ))[0] ;
((	(  cu_xyzw_shared + 3 ))[0] = 	(  (	(  cu_xyzw_shared + 3 ))[0] + 	- ( cur_to_cu_cache ) ));
tmp0123212663;
}) ;
((cur_xyzw)[2] = beg_minus);
((cur_xyzw)[3] = beg_minus);
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 	(  6 * cur_to_cu_cache ) ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_cache + 	(  	(  idy * 	(  cu_cache_length * 6 ) ) + 	(  	(  cur_cu_cache_load - cur_to_cu_cache ) * 6 ) ) ))[	(  	(  inner_step * 	(  6 * cur_to_cu_cache ) ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  6 * cur_beg_plus ) ))[	(  	(  inner_step * 	(  6 * cur_to_cu_cache ) ) + inner_g )]);
}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 2 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  cur_xyzw + 2 ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
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
	if (  	(  idx == 0 )  ){  
		{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 4 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_xyzw + 	(  4 * idy ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (cu_xyzw_shared)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
	if (  1  ){  
			for (i=0 ; 	(  	(  idx + 	(  i * xlen ) ) < xyzalllen ) ; i++)
	{
	long  grid_id = 	(  idx + 	(  i * xlen ) ) ;
	if (  	(  grid_id < xyzalllen )  ){  
			int   cur_xyzw  [4];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 4 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((cur_xyzw)[	(  	(  inner_step * 4 ) + inner_g )] = (	(  xyzw + 	(  	(  4 * 	(  cu_offset + grid_id ) ) + 0 ) ))[	(  	(  inner_step * 4 ) + inner_g )]);
}}}}}	int  beg_minus = (cur_xyzw)[0] ;
	int  beg_plus = (cur_xyzw)[2] ;
	int  end_plus = (cur_xyzw)[3] ;
	int  pluslen = 	(  end_plus - beg_plus ) ;
	int  load0 = 	(  beg_minus + pluslen ) ;
((xyzw)[	(  4 * 	(  cu_offset + grid_id ) )] = load0);
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * pluslen ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_plus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * pluslen ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  inoutput + 	(  	(  	(  cu_offset + grid_id ) * grid_cache_len ) * 6 ) ) + 	(  beg_minus * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_temp_particle_cache_minus + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}
	}else{
		0;

	 }
}
	}else{
		0;

	 }
}
void  openmp_cu_swap_l_scmc_kernel (double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  cu_cache_length ,int  the_dir_num ,long  XYZLEN ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	if (  	(  idx == 0 )  ){  
			int   cu_xyzw_shared  [4];	long   adjoint_vec_pids_shared  [2];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((adjoint_vec_pids_shared)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  adjoint_vec_pids + 	(  	(  6 * idy ) + 	(  2 * the_dir_num ) ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 4 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((cu_xyzw_shared)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  cu_xyzw + 	(  4 * idy ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	long  left_pid = (adjoint_vec_pids_shared)[0] ;
	int  beg_left_par = (cu_xyzw_shared)[1] ;
	int  end_left_par = (cu_xyzw_shared)[2] ;
	#if   0    
			fprintf ( stderr , "id=%d left_pid=%d lr=l\n" , idy , left_pid );
	fprintf ( stderr , "lr=l, idy=%d, lpid=%d sdl=%d\n" , idy , left_pid , 	(  end_left_par - beg_left_par ) );

	#else
		
	 #endif
	if (  	(  1 && 	(  	(  left_pid != -1 ) && 	(  beg_left_par != end_left_par ) ) )  ){  
			int  end_cu_par = (cu_xyzw)[	(  	(  left_pid * 4 ) + 0 )] ;
	int  new_left_par = 	(  end_cu_par + 	(  end_left_par - beg_left_par ) ) ;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_xyzw + 	(  4 * left_pid ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	& ( new_left_par ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	if (  1  ){  
		{
	int   al1  [2];((al1)[0] = (cu_xyzw_shared)[3]);
((al1)[1] = (cu_xyzw_shared)[3]);
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_xyzw + 	(  	(  4 * idy ) + 1 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (al1)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}
	}else{
		0;

	 }
	double   local_cache  [	(  384 * 6 )];	int  i ;
	for ((i = beg_left_par) ; 	(  i < end_left_par ) ; (i = 	(  i + 384 )))
	{
	int  num_cp = ((	(  	(  i + 384 ) > end_left_par ))?(	(  end_left_par - i )):(384)) ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_cp ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_cache + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  6 * i ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	int  ii ;
	for ((ii = 0) ; 	(  ii < num_cp ) ; ii++)
	{
((	(  local_cache + 	(  ii * 6 ) ))[the_dir_num] = 	(  (	(  local_cache + 	(  ii * 6 ) ))[the_dir_num] + XYZLEN ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_cp ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  left_pid * 	(  6 * cu_cache_length ) ) ) + 	(  6 * end_cu_par ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_cache + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(end_cu_par = 	(  end_cu_par + num_cp ));
}
	}else{
		0;

	 }

	}else{
		0;

	 }
}
void  openmp_cu_swap_r_scmc_kernel (double *  cu_cache ,int *  cu_xyzw ,long *  adjoint_vec_pids ,long  cu_cache_length ,int  the_dir_num ,long  XYZLEN ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  pscmc_compute_unit_id = 	omp_get_thread_num (  ) ;
	const long  pscmc_num_compute_units = 	omp_get_num_threads (  ) ;
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	if (  	(  idx == 0 )  ){  
			int   cu_xyzw_shared  [4];	long   adjoint_vec_pids_shared  [2];{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 2 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((adjoint_vec_pids_shared)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  adjoint_vec_pids + 	(  	(  6 * idy ) + 	(  2 * the_dir_num ) ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 4 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((cu_xyzw_shared)[	(  	(  inner_step * 1 ) + inner_g )] = (	(  cu_xyzw + 	(  4 * idy ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	long  left_pid = (adjoint_vec_pids_shared)[1] ;
	int  beg_left_par = (cu_xyzw_shared)[3] ;
	long  end_left_par = cu_cache_length ;
	#if   0    
			fprintf ( stderr , "id=%d left_pid=%d lr=r\n" , idy , left_pid );
	fprintf ( stderr , "lr=r, idy=%d, lpid=%d sdl=%d\n" , idy , left_pid , 	(  end_left_par - beg_left_par ) );

	#else
		
	 #endif
	if (  	(  1 && 	(  	(  left_pid != -1 ) && 	(  beg_left_par != end_left_par ) ) )  ){  
			int  end_cu_par = (cu_xyzw)[	(  	(  left_pid * 4 ) + 0 )] ;
	int  new_left_par = 	(  end_cu_par + 	(  end_left_par - beg_left_par ) ) ;
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_xyzw + 	(  4 * left_pid ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	& ( new_left_par ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}	if (  1  ){  
		{
	int   al1  [2];((al1)[0] = cu_cache_length);
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 1 ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  cu_xyzw + 	(  	(  4 * idy ) + 3 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (al1)[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}
	}else{
		0;

	 }
	double   local_cache  [	(  384 * 6 )];	int  i ;
	for ((i = beg_left_par) ; 	(  i < end_left_par ) ; (i = 	(  i + 384 )))
	{
	int  num_cp = ((	(  	(  i + 384 ) > end_left_par ))?(	(  end_left_par - i )):(384)) ;
{
{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_cp ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  local_cache + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  	(  cu_cache + 	(  idy * 	(  6 * cu_cache_length ) ) ) + 	(  6 * i ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}}	int  ii ;
	for ((ii = 0) ; 	(  ii < num_cp ) ; ii++)
	{
((	(  local_cache + 	(  ii * 6 ) ))[the_dir_num] = 	(  (	(  local_cache + 	(  ii * 6 ) ))[the_dir_num] + XYZLEN ));
}{
	long  inner_step ;
	for ((inner_step = 0) ; 	(  inner_step < 	(  6 * num_cp ) ) ; (inner_step = 	(  inner_step + 1 )))
	{
{
	long  inner_g ;
	for ((inner_g = 0) ; 	(  inner_g < 1 ) ; (inner_g = 	(  inner_g + 1 )))
	{
((	(  	(  cu_cache + 	(  left_pid * 	(  6 * cu_cache_length ) ) ) + 	(  6 * end_cu_par ) ))[	(  	(  inner_step * 1 ) + inner_g )] = (	(  local_cache + 	(  0 * 6 ) ))[	(  	(  inner_step * 1 ) + inner_g )]);
}}}}(end_cu_par = 	(  end_cu_par + num_cp ));
}
	}else{
		0;

	 }

	}else{
		0;

	 }
}
