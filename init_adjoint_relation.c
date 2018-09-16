#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
	#ifndef   NCSPIC_SEQ_FIELD    
		#include <mpi.h>

#define PS_MPI_INT MPI_INT

#define PS_MPI_DOUBLE MPI_DOUBLE

#define PS_MPI_FLOAT MPI_FLOAT

#define PS_MPI_LONG MPI_LONG

#define PS_MPI_LONG_LONG MPI_LONG_LONG

#define PS_MPI_COMM_WORLD MPI_COMM_WORLD

typedef MPI_Comm PS_MPI_Comm;

typedef MPI_Datatype PS_MPI_Datatype;

typedef MPI_Request PS_MPI_Request;

typedef MPI_Status PS_MPI_Status;
#include "libsmallmpi.h"

#define NCSPIC_SEQ_FIELD
typedef double NUMBER_REAL;
typedef enum {CD_C,CD_OpenMP,CD_OpenCL,CD_CUDA} SEQ_FIELD_TYPES;

#define NUM_SYNC_LAYER 27

#define NUM_SYNC_KERNEL 4

#define NUM_FDTD_KERNEL 18
typedef struct { 	void *  pe ;
	long  xlen ;
	long  ylen ;
	long  zlen ;
	long  xblock ;
	long  yblock ;
	long  zblock ;
	long  numvec ;
	long  x_num_thread_block ;
	long  y_num_thread_block ;
	long  z_num_thread_block ;
	int  ovlp ;
	int  num_ele ;
	int  CD_type ;
	void *   sync_layer_pscmc  [NUM_SYNC_LAYER];	void *   swap_layer_pscmc  [NUM_SYNC_LAYER];	void *   sync_kernels  [NUM_SYNC_KERNEL];	void *   fdtd_kernels  [NUM_FDTD_KERNEL];	void *   dm_kernels  [1];	void *   geo_yeefdtd_kernels  [1];	void *   geo_yeefdtd_rect_kernels  [1];	void *   yee_abc_kernels  [8];	void *   yee_pec_kernels  [8];	void *   yee_damp_kernels  [8];	void *  rdcd ;
	double *  rdcd_host ;
	void *  cur_rankx_pscmc ;
	void *  cur_ranky_pscmc ;
	void *  cur_rankz_pscmc ;
	void *  xoffset ;
	void *  yoffset ;
	void *  zoffset ;
	long *  global_x_offset ;
	long *  global_y_offset ;
	long *  global_z_offset ;
	long *  global_id ;
	long  global_pid ;
	long *  adj_ids ;
	long *  adj_processes ;
	long *  adj_local_tid ;
	void *  main_data ;
	double  delta_x ;
	double  delta_y ;
	double  delta_z ;
	void *  blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel ;
	void *  blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel ;
	void *  blas_axpby_kernel ;
	void *  blas_axpy_kernel ;
	void *  blas_yisax_kernel ;
	void *  blas_mulxy_kernel ;
	void *  blas_findmax_kernel ;
	void *  blas_dot_kernel ;
	void *  blas_sum_kernel ;
} Field3D_Seq;typedef struct { 	Field3D_Seq *  pfield ;
	Field3D_Seq *  pfieldE ;
	Field3D_Seq *  pfieldB ;
	Field3D_Seq *  pfieldB1 ;
	Field3D_Seq *  pFoutJ ;
	Field3D_Seq *  pLFoutJ ;
	Field3D_Seq *  pFoutEN ;
	void *   sort_kernel  [6];	void *   geo_rel_1st_kernel  [5];	void *   rel_1st_kernel  [1];	void *   krook_collision_test_kernel  [2];	void *   boris_yee_kernel  [1];	void *  cu_swap_l_kernel ;
	void *  cu_swap_r_kernel ;
	void *  move_back_kernel_kernel ;
	double  Mass ;
	double  Charge ;
	double  Number_particle_per_marker ;
	long  grid_cache_len ;
	long  cu_cache_length ;
	void *  split_pass_x_kernel ;
	void *  split_pass_y_kernel ;
	void *  split_pass_z_kernel ;
	void *  split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel ;
	void *  split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel ;
	void *  calculate_rho_kernel ;
	void *  inoutput ;
	void *  xyzw ;
	void *  cu_cache ;
	void *  cu_xyzw ;
	void *  adjoint_vec_pids ;
} One_Particle_Collection;typedef struct { 	Field3D_Seq *  car ;
	void *  cdr ;
} Field3D_Seq_PAIR;typedef struct { 	Field3D_Seq *  data ;
	long  num_runtime ;
	PS_MPI_Comm  comm ;
	long  cur_rank ;
	long  num_mpi_process ;
	long   sync_layer_len  [NUM_SYNC_LAYER];	PS_MPI_Request * *  rqst ;
	One_Particle_Collection *  particles ;
	int  num_spec ;
	double  damp_vars ;
} Field3D_MPI;typedef struct { 	Field3D_MPI  MPI_fieldE ;
	Field3D_MPI  MPI_fieldB ;
	Field3D_MPI  MPI_fieldB1 ;
	Field3D_MPI  MPI_FoutJ ;
	Field3D_MPI  MPI_LFoutJ ;
	Field3D_MPI  MPI_fieldEtmp ;
	Field3D_MPI *  pMPI_FoutJ ;
	Field3D_MPI *  pMPI_FoutEN ;
	Field3D_MPI  MPI_fieldE_ext ;
	Field3D_MPI  MPI_fieldB_ext ;
	Field3D_MPI  MPI_fieldE_filter ;
	Field3D_MPI  MPI_fieldB_filter ;
	Field3D_MPI *  pB0 ;
	Field3D_MPI *  pB1 ;
	int  use_small_grid ;
	double  dt ;
} Particle_in_Cell_MPI;
	#ifndef   LINEAR_OPERATOR_PICUS_001    
		
#define LINEAR_OPERATOR_PICUS_001 
 typedef int (* linear_operator_mpi )(Field3D_MPI * ,Field3D_MPI * ,void * );

	#else
		
	 #endif
typedef struct { 	Field3D_MPI *  r1 ;
	Field3D_MPI *  ti ;
	Field3D_MPI *  si1 ;
	Field3D_MPI *  si ;
	Field3D_MPI *  vi1 ;
	Field3D_MPI *  pi ;
	Field3D_MPI *  pi1 ;
	Field3D_MPI *  ri1 ;
	Field3D_MPI *  ri ;
	Field3D_MPI *  r0h ;
	linear_operator_mpi  A ;
	void *  fv ;
	int  zmax ;
	double  solve_err ;
} bicg_space;
	#else
		
	 #endif
#include "cfgcst.h"
#include "c_/c_pscmc_inc.h"
#include "openmp_/openmp_pscmc_inc.h"
#include "c_/yeefdtd.kernel_inc.h"
#include "c_/mergefields.kernel_inc.h"
#include "c_/miniblas.kernel_inc.h"
#include "c_/general_partial_sort.kernel_inc.h"
#include "c_/move_back.kernel_inc.h"
#include "c_/particle_iter.kernel_inc.h"
#include "c_/mur_abc.kernel_inc.h"
#include "c_/dm.kernel_inc.h"
#include "c_/geo_yeefdtd_rect.kernel_inc.h"
#include "c_/geo_yeefdtd.kernel_inc.h"
#include "c_/geo_particle_iter_mass.kernel_inc.h"
#include "c_/geo_particle_iter.kernel_inc.h"
#include "c_/rel_particle_iter.kernel_inc.h"
#include "c_yeefdtd.h"
#include "openmp_/yeefdtd.kernel_inc.h"
#include "openmp_/mergefields.kernel_inc.h"
#include "openmp_/miniblas.kernel_inc.h"
#include "openmp_/general_partial_sort.kernel_inc.h"
#include "openmp_/move_back.kernel_inc.h"
#include "openmp_/particle_iter.kernel_inc.h"
#include "openmp_/mur_abc.kernel_inc.h"
#include "openmp_/dm.kernel_inc.h"
#include "openmp_/geo_yeefdtd_rect.kernel_inc.h"
#include "openmp_/geo_yeefdtd.kernel_inc.h"
#include "openmp_/geo_particle_iter_mass.kernel_inc.h"
#include "openmp_/geo_particle_iter.kernel_inc.h"
#include "openmp_/rel_particle_iter.kernel_inc.h"
#include "openmp_yeefdtd.h"
#include "space_filling_curve.h"
int  init_complexity_tid (unsigned long  num_proc ,unsigned long  num_thread ,size_t *  ori_vec ,long *  num_thread_array ,long *  local_tid_array ){
	long *  cplx_array = 	malloc ( 	(  sizeof(long ) * num_thread ) ) ;
	double  total_complexity = 0.00000000000000000e+00 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < num_thread ) ; (i = 	(  i + 1 )))
	{
((cplx_array)[i] = 	floor ( 	call_CAL_FUN_ONE_PARA ( "get_thread_complexity" , (ori_vec)[i] ) ));
	assert ( 	(  (cplx_array)[i] >= 0 ) );
(total_complexity = 	(  total_complexity + (cplx_array)[i] ));
}}	assert ( total_complexity );
	long  global_cplx = 0 ;
	long  current_pid = 0 ;
	long  l_tid = 0 ;
((num_thread_array)[0] = 0);
{
	long  i ;
	for ((i = 0) ; 	(  i < num_thread ) ; (i = 	(  i + 1 )))
	{
	if (  	(  	(  global_cplx * num_proc ) >= 	(  current_pid * total_complexity ) )  ){  
			if (  	(  current_pid < num_proc )  ){  
		((num_thread_array)[current_pid] = i);

	}else{
		0;

	 }
	if (  	(  current_pid < num_proc )  ){  
		(current_pid = 	(  current_pid + 1 ));
(l_tid = -1);

	}else{
		0;

	 }

	}else{
		0;

	 }
(global_cplx = 	(  global_cplx + (cplx_array)[i] ));
(l_tid = 	(  l_tid + 1 ));
((local_tid_array)[i] = l_tid);
}}	assert ( 	(  current_pid == num_proc ) );
	free ( cplx_array );
	return  0 ;}
int  init_uniform_tid (unsigned long  num_proc ,unsigned long  num_thread ,long *  num_thread_array ,long *  local_tid_array ){
	long  i = 0 ;
	long  global_tid = 0 ;
	long  oneprocnum = 	(  num_thread / num_proc ) ;
	long  plusone = 	(  num_thread % num_proc ) ;
	for (i=0 ; i<num_proc ; i++)
	{
((num_thread_array)[i] = global_tid);
	long  old_pid = global_tid ;
(global_tid = 	(  global_tid + oneprocnum ));
	if (  	(  i < plusone )  ){  
		(global_tid = 	(  global_tid + 1 ));

	}else{
		0;

	 }
	if (  	(  global_tid > num_thread )  ){  
		(global_tid = num_thread);

	}else{
		0;

	 }
{
	long  j ;
	for ((j = old_pid) ; 	(  j < global_tid ) ; (j = 	(  j + 1 )))
	{
((local_tid_array)[j] = 	(  j - old_pid ));
}}}	return  0 ;}
long  get_cur_tid (long  pid ,long  num_thread ,long  num_proc ,long *  num_thread_array ){
	return  (num_thread_array)[pid] ;}
long  get_cur_num_tid (long  pid ,long  num_thread ,long  num_proc ,long *  num_thread_array ){
	long  ret = 0 ;
	assert ( 	(  pid < num_proc ) );
(ret = ((	(  pid < 	(  num_proc - 1 ) ))?(	(  (num_thread_array)[	(  pid + 1 )] - (num_thread_array)[pid] )):(	(  num_thread - (num_thread_array)[pid] ))));
	return  ret ;}
long  find_the_proc_id (long  tid ,unsigned long  num_proc ,long *  num_thread_array ){
	if (  	(  num_proc <= 1 )  ){  
			return  0 ;
	}else{
			if (  	(  tid < (num_thread_array)[	(  num_proc / 2 )] )  ){  
			return  	find_the_proc_id ( tid , 	(  num_proc / 2 ) , num_thread_array ) ;
	}else{
			return  	(  	(  num_proc / 2 ) + 	find_the_proc_id ( tid , 	(  num_proc - 	(  num_proc / 2 ) ) , 	(  num_thread_array + 	(  num_proc / 2 ) ) ) ) ;
	 }

	 }
}
int  init_adjoint_relations (Field3D_Seq *  pthis ,long  n ,long  ndim ,long  adj_type ,long  num_proc ,long *  ovvec ,long *  ori_vec ,long *  num_thread_array ,long *  local_tid_array ){
	void *  pe = 	( pthis )->pe ;
	long  xlen = 	( pthis )->xlen ;
	long  ylen = 	( pthis )->ylen ;
	long  zlen = 	( pthis )->zlen ;
	long  xblock = 	( pthis )->xblock ;
	long  yblock = 	( pthis )->yblock ;
	long  zblock = 	( pthis )->zblock ;
	long  numvec = 	( pthis )->numvec ;
	long  x_num_thread_block = 	( pthis )->x_num_thread_block ;
	long  y_num_thread_block = 	( pthis )->y_num_thread_block ;
	long  z_num_thread_block = 	( pthis )->z_num_thread_block ;
	int  ovlp = 	( pthis )->ovlp ;
	int  num_ele = 	( pthis )->num_ele ;
	int  CD_type = 	( pthis )->CD_type ;
	void * *  sync_layer_pscmc = 	( pthis )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( pthis )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( pthis )->sync_kernels ;
	void * *  fdtd_kernels = 	( pthis )->fdtd_kernels ;
	void * *  dm_kernels = 	( pthis )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pthis )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pthis )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( pthis )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pthis )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pthis )->yee_damp_kernels ;
	void *  rdcd = 	( pthis )->rdcd ;
	double *  rdcd_host = 	( pthis )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( pthis )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( pthis )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( pthis )->cur_rankz_pscmc ;
	void *  xoffset = 	( pthis )->xoffset ;
	void *  yoffset = 	( pthis )->yoffset ;
	void *  zoffset = 	( pthis )->zoffset ;
	long *  global_x_offset = 	( pthis )->global_x_offset ;
	long *  global_y_offset = 	( pthis )->global_y_offset ;
	long *  global_z_offset = 	( pthis )->global_z_offset ;
	long *  global_id = 	( pthis )->global_id ;
	long  global_pid = 	( pthis )->global_pid ;
	long *  adj_ids = 	( pthis )->adj_ids ;
	long *  adj_processes = 	( pthis )->adj_processes ;
	long *  adj_local_tid = 	( pthis )->adj_local_tid ;
	void *  main_data = 	( pthis )->main_data ;
	double  delta_x = 	( pthis )->delta_x ;
	double  delta_y = 	( pthis )->delta_y ;
	double  delta_z = 	( pthis )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( pthis )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( pthis )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( pthis )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( pthis )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( pthis )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( pthis )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( pthis )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( pthis )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( pthis )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( pthis )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( pthis )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( pthis )->blas_sum_kernel ;
	long  onen = 	(  1 << n ) ;
	long  alllen = 1 ;
	assert ( ndim<4 );
{
	long  g ;
	for ((g = 0) ; 	(  g < ndim ) ; (g = 	(  g + 1 )))
	{
(alllen = 	(  alllen * onen ));
}}	long  i = 0 ;
	for (i=0 ; 	(  i < numvec ) ; (i = 	(  i + 1 )))
	{
	long  cur_thread = (ori_vec)[	(  (num_thread_array)[global_pid] + i )] ;
	long  bxyzx = 	(  cur_thread % x_num_thread_block ) ;
	long  bxyzy = 	(  	(  cur_thread / x_num_thread_block ) % y_num_thread_block ) ;
	long  bxyzz = 	(  cur_thread / 	(  x_num_thread_block * y_num_thread_block ) ) ;
((global_x_offset)[i] = 	(  xlen * bxyzx ));
((global_y_offset)[i] = 	(  ylen * bxyzy ));
((global_z_offset)[i] = 	(  zlen * bxyzz ));
{
	int *  tmpv = ((	(  0 == CD_type ))?(	c_pscmc_get_h_data ( cur_rankx_pscmc , NULL )):(((	(  1 == CD_type ))?(	openmp_pscmc_get_h_data ( cur_rankx_pscmc , NULL )):(0)))) ;
((tmpv)[i] = 	(  	(  2 * 	(  bxyzx == 	(  x_num_thread_block - 1 ) ) ) + 	(  bxyzx == 0 ) ));
(tmpv = ((	(  0 == CD_type ))?(	c_pscmc_get_h_data ( xoffset , NULL )):(((	(  1 == CD_type ))?(	openmp_pscmc_get_h_data ( xoffset , NULL )):(0)))));
((tmpv)[i] = (global_x_offset)[i]);
}{
	int *  tmpv = ((	(  0 == CD_type ))?(	c_pscmc_get_h_data ( cur_ranky_pscmc , NULL )):(((	(  1 == CD_type ))?(	openmp_pscmc_get_h_data ( cur_ranky_pscmc , NULL )):(0)))) ;
((tmpv)[i] = 	(  	(  2 * 	(  bxyzy == 	(  y_num_thread_block - 1 ) ) ) + 	(  bxyzy == 0 ) ));
(tmpv = ((	(  0 == CD_type ))?(	c_pscmc_get_h_data ( yoffset , NULL )):(((	(  1 == CD_type ))?(	openmp_pscmc_get_h_data ( yoffset , NULL )):(0)))));
((tmpv)[i] = (global_y_offset)[i]);
}{
	int *  tmpv = ((	(  0 == CD_type ))?(	c_pscmc_get_h_data ( cur_rankz_pscmc , NULL )):(((	(  1 == CD_type ))?(	openmp_pscmc_get_h_data ( cur_rankz_pscmc , NULL )):(0)))) ;
((tmpv)[i] = 	(  	(  2 * 	(  bxyzz == 	(  z_num_thread_block - 1 ) ) ) + 	(  bxyzz == 0 ) ));
(tmpv = ((	(  0 == CD_type ))?(	c_pscmc_get_h_data ( zoffset , NULL )):(((	(  1 == CD_type ))?(	openmp_pscmc_get_h_data ( zoffset , NULL )):(0)))));
((tmpv)[i] = (global_z_offset)[i]);
}	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( cur_rankx_pscmc );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( cur_rankx_pscmc );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( cur_ranky_pscmc );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( cur_ranky_pscmc );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( cur_rankz_pscmc );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( cur_rankz_pscmc );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( xoffset );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( xoffset );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( yoffset );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( yoffset );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( zoffset );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( zoffset );

	}else{
		0;

	 }

	 }
((global_id)[i] = cur_thread);
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 3 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 3 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 3 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	int  xyzlocalall = 	(  0 + 	(  1 * 	(  xyzx + 	(  3 * 	(  xyzy + 	(  3 * xyzz ) ) ) ) ) ) ;
	long  adj_id_pre = 	(  0 + 	(  1 * 	(  	(  	(  	(  bxyzx + 	(  xyzx - 1 ) ) + x_num_thread_block ) % x_num_thread_block ) + 	(  x_num_thread_block * 	(  	(  	(  	(  bxyzy + 	(  xyzy - 1 ) ) + y_num_thread_block ) % y_num_thread_block ) + 	(  y_num_thread_block * 	(  	(  	(  bxyzz + 	(  xyzz - 1 ) ) + z_num_thread_block ) % z_num_thread_block ) ) ) ) ) ) ) ;
	long  cur_adj_id = (ovvec)[adj_id_pre] ;
((adj_ids)[	(  	(  i * NUM_SYNC_LAYER ) + xyzlocalall )] = cur_adj_id);
	long  cur_adj_pid = 	find_the_proc_id ( cur_adj_id , num_proc , num_thread_array ) ;
((adj_processes)[	(  	(  i * NUM_SYNC_LAYER ) + xyzlocalall )] = cur_adj_pid);
((adj_local_tid)[	(  	(  i * NUM_SYNC_LAYER ) + xyzlocalall )] = (local_tid_array)[cur_adj_id]);
}}}}}}}	return  0 ;}
