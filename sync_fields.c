#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
#include "mpifields.h"
int  merge_ovlp_mpi_field (Field3D_MPI *  pthis ){
	Field3D_Seq *  data = 	( pthis )->data ;
	long  num_runtime = 	( pthis )->num_runtime ;
	PS_MPI_Comm  comm = 	( pthis )->comm ;
	long  cur_rank = 	( pthis )->cur_rank ;
	long  num_mpi_process = 	( pthis )->num_mpi_process ;
	long *  sync_layer_len = 	( pthis )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( pthis )->rqst ;
	One_Particle_Collection *  particles = 	( pthis )->particles ;
	int  num_spec = 	( pthis )->num_spec ;
	double  damp_vars = 	( pthis )->damp_vars ;
	long  i = 0 ;
	long  num_data = num_runtime ;
	for (i=0 ; i<num_data ; i++)
	{
	Field3D_Seq_ovlp_merge_ovlp_m2o ( 	(  data + i ) , 1 );
}	int  fieldid ;
	for (fieldid=0 ; 	(  fieldid < NUM_SYNC_LAYER ) ; fieldid++)
	{
	if (  	(  fieldid == 	(  NUM_SYNC_LAYER / 2 ) )  ){  
		continue;

	}else{
		0;

	 }
	for (i=0 ; i<num_data ; i++)
	{
	void *  pe = 	( 	(  data + i ) )->pe ;
	long  xlen = 	( 	(  data + i ) )->xlen ;
	long  ylen = 	( 	(  data + i ) )->ylen ;
	long  zlen = 	( 	(  data + i ) )->zlen ;
	long  xblock = 	( 	(  data + i ) )->xblock ;
	long  yblock = 	( 	(  data + i ) )->yblock ;
	long  zblock = 	( 	(  data + i ) )->zblock ;
	long  numvec = 	( 	(  data + i ) )->numvec ;
	long  x_num_thread_block = 	( 	(  data + i ) )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	(  data + i ) )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	(  data + i ) )->z_num_thread_block ;
	int  ovlp = 	( 	(  data + i ) )->ovlp ;
	int  num_ele = 	( 	(  data + i ) )->num_ele ;
	int  CD_type = 	( 	(  data + i ) )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	(  data + i ) )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	(  data + i ) )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	(  data + i ) )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	(  data + i ) )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	(  data + i ) )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  data + i ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  data + i ) )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( 	(  data + i ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  data + i ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  data + i ) )->yee_damp_kernels ;
	void *  rdcd = 	( 	(  data + i ) )->rdcd ;
	double *  rdcd_host = 	( 	(  data + i ) )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	(  data + i ) )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	(  data + i ) )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	(  data + i ) )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	(  data + i ) )->xoffset ;
	void *  yoffset = 	( 	(  data + i ) )->yoffset ;
	void *  zoffset = 	( 	(  data + i ) )->zoffset ;
	long *  global_x_offset = 	( 	(  data + i ) )->global_x_offset ;
	long *  global_y_offset = 	( 	(  data + i ) )->global_y_offset ;
	long *  global_z_offset = 	( 	(  data + i ) )->global_z_offset ;
	long *  global_id = 	( 	(  data + i ) )->global_id ;
	long  global_pid = 	( 	(  data + i ) )->global_pid ;
	long *  adj_ids = 	( 	(  data + i ) )->adj_ids ;
	long *  adj_processes = 	( 	(  data + i ) )->adj_processes ;
	long *  adj_local_tid = 	( 	(  data + i ) )->adj_local_tid ;
	void *  main_data = 	( 	(  data + i ) )->main_data ;
	double  delta_x = 	( 	(  data + i ) )->delta_x ;
	double  delta_y = 	( 	(  data + i ) )->delta_y ;
	double  delta_z = 	( 	(  data + i ) )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	(  data + i ) )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( 	(  data + i ) )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	(  data + i ) )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	(  data + i ) )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	(  data + i ) )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	(  data + i ) )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	(  data + i ) )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	(  data + i ) )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	(  data + i ) )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	(  data + i ) )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	(  data + i ) )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	(  data + i ) )->blas_sum_kernel ;
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_d2h ( (sync_layer_pscmc)[fieldid] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_d2h ( (sync_layer_pscmc)[fieldid] );

	}else{
		0;

	 }

	 }
	int  tid ;
	for (tid=0 ; 	(  tid < numvec ) ; tid++)
	{
	long  sllen = (sync_layer_len)[fieldid] ;
	double *  t0 ;
	if (  	(  0 == CD_type )  ){  
			c_pscmc_get_h_data ( (sync_layer_pscmc)[fieldid] , 	& ( t0 ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_get_h_data ( (sync_layer_pscmc)[fieldid] , 	& ( t0 ) );

	}else{
		0;

	 }

	 }
	int  REMOTE_PROC_ID = 	(  (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid )] / 	( pthis )->num_runtime ) ;
{
	if (  	(  cur_rank == REMOTE_PROC_ID )  ){  
		continue;

	}else{
			PS_MPI_Isend ( 	(  t0 + 	(  tid * sllen ) ) , sllen , PS_MPI_DOUBLE , REMOTE_PROC_ID , 	(  	(  NUM_SYNC_LAYER * (adj_ids)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid )] ) + fieldid ) , comm , 	(  (rqst)[i] + 	(  	(  tid * NUM_SYNC_LAYER ) + fieldid ) ) );

	 }
}}}	for (i=0 ; i<num_data ; i++)
	{
	void *  pe = 	( 	(  data + i ) )->pe ;
	long  xlen = 	( 	(  data + i ) )->xlen ;
	long  ylen = 	( 	(  data + i ) )->ylen ;
	long  zlen = 	( 	(  data + i ) )->zlen ;
	long  xblock = 	( 	(  data + i ) )->xblock ;
	long  yblock = 	( 	(  data + i ) )->yblock ;
	long  zblock = 	( 	(  data + i ) )->zblock ;
	long  numvec = 	( 	(  data + i ) )->numvec ;
	long  x_num_thread_block = 	( 	(  data + i ) )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	(  data + i ) )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	(  data + i ) )->z_num_thread_block ;
	int  ovlp = 	( 	(  data + i ) )->ovlp ;
	int  num_ele = 	( 	(  data + i ) )->num_ele ;
	int  CD_type = 	( 	(  data + i ) )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	(  data + i ) )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	(  data + i ) )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	(  data + i ) )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	(  data + i ) )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	(  data + i ) )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  data + i ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  data + i ) )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( 	(  data + i ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  data + i ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  data + i ) )->yee_damp_kernels ;
	void *  rdcd = 	( 	(  data + i ) )->rdcd ;
	double *  rdcd_host = 	( 	(  data + i ) )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	(  data + i ) )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	(  data + i ) )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	(  data + i ) )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	(  data + i ) )->xoffset ;
	void *  yoffset = 	( 	(  data + i ) )->yoffset ;
	void *  zoffset = 	( 	(  data + i ) )->zoffset ;
	long *  global_x_offset = 	( 	(  data + i ) )->global_x_offset ;
	long *  global_y_offset = 	( 	(  data + i ) )->global_y_offset ;
	long *  global_z_offset = 	( 	(  data + i ) )->global_z_offset ;
	long *  global_id = 	( 	(  data + i ) )->global_id ;
	long  global_pid = 	( 	(  data + i ) )->global_pid ;
	long *  adj_ids = 	( 	(  data + i ) )->adj_ids ;
	long *  adj_processes = 	( 	(  data + i ) )->adj_processes ;
	long *  adj_local_tid = 	( 	(  data + i ) )->adj_local_tid ;
	void *  main_data = 	( 	(  data + i ) )->main_data ;
	double  delta_x = 	( 	(  data + i ) )->delta_x ;
	double  delta_y = 	( 	(  data + i ) )->delta_y ;
	double  delta_z = 	( 	(  data + i ) )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	(  data + i ) )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( 	(  data + i ) )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	(  data + i ) )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	(  data + i ) )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	(  data + i ) )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	(  data + i ) )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	(  data + i ) )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	(  data + i ) )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	(  data + i ) )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	(  data + i ) )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	(  data + i ) )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	(  data + i ) )->blas_sum_kernel ;
	int  tid ;
	int  fieldid1 = 	(  	(  NUM_SYNC_LAYER - 1 ) - fieldid ) ;
	for (tid=0 ; 	(  tid < numvec ) ; tid++)
	{
	long  sllen = (sync_layer_len)[fieldid1] ;
	double *  t1 ;
	double *  t0 ;
	if (  	(  0 == CD_type )  ){  
			c_pscmc_get_h_data ( (swap_layer_pscmc)[fieldid1] , 	& ( t1 ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_get_h_data ( (swap_layer_pscmc)[fieldid1] , 	& ( t1 ) );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_get_h_data ( (sync_layer_pscmc)[	(  	(  NUM_SYNC_LAYER - 1 ) - fieldid1 )] , 	& ( t0 ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_get_h_data ( (sync_layer_pscmc)[	(  	(  NUM_SYNC_LAYER - 1 ) - fieldid1 )] , 	& ( t0 ) );

	}else{
		0;

	 }

	 }
{
	long  adj_proc_id = (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid1 )] ;
	int  REMOTE_PROC_ID = 	(  adj_proc_id / 	( pthis )->num_runtime ) ;
	if (  	(  adj_proc_id == (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + 	(  NUM_SYNC_LAYER / 2 ) )] )  ){  
			long  t0id = (adj_local_tid)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid1 )] ;
	memcpy ( 	(  t1 + 	(  tid * sllen ) ) , 	(  t0 + 	(  t0id * sllen ) ) , 	(  sizeof(double ) * sllen ) );

	}else{
			PS_MPI_Recv ( 	(  t1 + 	(  tid * sllen ) ) , sllen , PS_MPI_DOUBLE , REMOTE_PROC_ID , 	(  	(  NUM_SYNC_LAYER * (adj_ids)[	(  	(  tid * NUM_SYNC_LAYER ) + 	(  NUM_SYNC_LAYER / 2 ) )] ) + 	(  	(  NUM_SYNC_LAYER - 1 ) - fieldid1 ) ) , comm , NULL );

	 }
}}	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( (swap_layer_pscmc)[fieldid1] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( (swap_layer_pscmc)[fieldid1] );

	}else{
		0;

	 }

	 }
}	for (i=0 ; i<num_data ; i++)
	{
	void *  pe = 	( 	(  data + i ) )->pe ;
	long  xlen = 	( 	(  data + i ) )->xlen ;
	long  ylen = 	( 	(  data + i ) )->ylen ;
	long  zlen = 	( 	(  data + i ) )->zlen ;
	long  xblock = 	( 	(  data + i ) )->xblock ;
	long  yblock = 	( 	(  data + i ) )->yblock ;
	long  zblock = 	( 	(  data + i ) )->zblock ;
	long  numvec = 	( 	(  data + i ) )->numvec ;
	long  x_num_thread_block = 	( 	(  data + i ) )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	(  data + i ) )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	(  data + i ) )->z_num_thread_block ;
	int  ovlp = 	( 	(  data + i ) )->ovlp ;
	int  num_ele = 	( 	(  data + i ) )->num_ele ;
	int  CD_type = 	( 	(  data + i ) )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	(  data + i ) )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	(  data + i ) )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	(  data + i ) )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	(  data + i ) )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	(  data + i ) )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  data + i ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  data + i ) )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( 	(  data + i ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  data + i ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  data + i ) )->yee_damp_kernels ;
	void *  rdcd = 	( 	(  data + i ) )->rdcd ;
	double *  rdcd_host = 	( 	(  data + i ) )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	(  data + i ) )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	(  data + i ) )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	(  data + i ) )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	(  data + i ) )->xoffset ;
	void *  yoffset = 	( 	(  data + i ) )->yoffset ;
	void *  zoffset = 	( 	(  data + i ) )->zoffset ;
	long *  global_x_offset = 	( 	(  data + i ) )->global_x_offset ;
	long *  global_y_offset = 	( 	(  data + i ) )->global_y_offset ;
	long *  global_z_offset = 	( 	(  data + i ) )->global_z_offset ;
	long *  global_id = 	( 	(  data + i ) )->global_id ;
	long  global_pid = 	( 	(  data + i ) )->global_pid ;
	long *  adj_ids = 	( 	(  data + i ) )->adj_ids ;
	long *  adj_processes = 	( 	(  data + i ) )->adj_processes ;
	long *  adj_local_tid = 	( 	(  data + i ) )->adj_local_tid ;
	void *  main_data = 	( 	(  data + i ) )->main_data ;
	double  delta_x = 	( 	(  data + i ) )->delta_x ;
	double  delta_y = 	( 	(  data + i ) )->delta_y ;
	double  delta_z = 	( 	(  data + i ) )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	(  data + i ) )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( 	(  data + i ) )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	(  data + i ) )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	(  data + i ) )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	(  data + i ) )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	(  data + i ) )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	(  data + i ) )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	(  data + i ) )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	(  data + i ) )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	(  data + i ) )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	(  data + i ) )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	(  data + i ) )->blas_sum_kernel ;
	int  tid ;
	for (tid=0 ; 	(  tid < numvec ) ; tid++)
	{
	long  adj_proc_id = (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid )] ;
	int  REMOTE_PROC_ID = 	(  adj_proc_id / 	( pthis )->num_runtime ) ;
	if (  	(  adj_proc_id == (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + 	(  NUM_SYNC_LAYER / 2 ) )] )  ){  
		continue;

	}else{
			PS_MPI_Wait ( 	(  (rqst)[i] + 	(  	(  tid * NUM_SYNC_LAYER ) + fieldid ) ) , NULL );

	 }
}}}	for (i=0 ; i<num_data ; i++)
	{
	Field3D_Seq_ovlp_merge_ovlp_o2m ( 	(  data + i ) , 0 );
}	return  0 ;}
int  merge_ovlp_mpi_field_swap_loop (Field3D_MPI *  pthis ){
	Field3D_Seq *  data = 	( pthis )->data ;
	long  num_runtime = 	( pthis )->num_runtime ;
	PS_MPI_Comm  comm = 	( pthis )->comm ;
	long  cur_rank = 	( pthis )->cur_rank ;
	long  num_mpi_process = 	( pthis )->num_mpi_process ;
	long *  sync_layer_len = 	( pthis )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( pthis )->rqst ;
	One_Particle_Collection *  particles = 	( pthis )->particles ;
	int  num_spec = 	( pthis )->num_spec ;
	double  damp_vars = 	( pthis )->damp_vars ;
	long  i = 0 ;
	long  num_data = num_runtime ;
	for (i=0 ; i<num_data ; i++)
	{
	Field3D_Seq_ovlp_merge_ovlp_m2o ( 	(  data + i ) , 1 );
}	for (i=0 ; i<num_data ; i++)
	{
	void *  pe = 	( 	(  data + i ) )->pe ;
	long  xlen = 	( 	(  data + i ) )->xlen ;
	long  ylen = 	( 	(  data + i ) )->ylen ;
	long  zlen = 	( 	(  data + i ) )->zlen ;
	long  xblock = 	( 	(  data + i ) )->xblock ;
	long  yblock = 	( 	(  data + i ) )->yblock ;
	long  zblock = 	( 	(  data + i ) )->zblock ;
	long  numvec = 	( 	(  data + i ) )->numvec ;
	long  x_num_thread_block = 	( 	(  data + i ) )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	(  data + i ) )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	(  data + i ) )->z_num_thread_block ;
	int  ovlp = 	( 	(  data + i ) )->ovlp ;
	int  num_ele = 	( 	(  data + i ) )->num_ele ;
	int  CD_type = 	( 	(  data + i ) )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	(  data + i ) )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	(  data + i ) )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	(  data + i ) )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	(  data + i ) )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	(  data + i ) )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  data + i ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  data + i ) )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( 	(  data + i ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  data + i ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  data + i ) )->yee_damp_kernels ;
	void *  rdcd = 	( 	(  data + i ) )->rdcd ;
	double *  rdcd_host = 	( 	(  data + i ) )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	(  data + i ) )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	(  data + i ) )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	(  data + i ) )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	(  data + i ) )->xoffset ;
	void *  yoffset = 	( 	(  data + i ) )->yoffset ;
	void *  zoffset = 	( 	(  data + i ) )->zoffset ;
	long *  global_x_offset = 	( 	(  data + i ) )->global_x_offset ;
	long *  global_y_offset = 	( 	(  data + i ) )->global_y_offset ;
	long *  global_z_offset = 	( 	(  data + i ) )->global_z_offset ;
	long *  global_id = 	( 	(  data + i ) )->global_id ;
	long  global_pid = 	( 	(  data + i ) )->global_pid ;
	long *  adj_ids = 	( 	(  data + i ) )->adj_ids ;
	long *  adj_processes = 	( 	(  data + i ) )->adj_processes ;
	long *  adj_local_tid = 	( 	(  data + i ) )->adj_local_tid ;
	void *  main_data = 	( 	(  data + i ) )->main_data ;
	double  delta_x = 	( 	(  data + i ) )->delta_x ;
	double  delta_y = 	( 	(  data + i ) )->delta_y ;
	double  delta_z = 	( 	(  data + i ) )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	(  data + i ) )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( 	(  data + i ) )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	(  data + i ) )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	(  data + i ) )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	(  data + i ) )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	(  data + i ) )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	(  data + i ) )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	(  data + i ) )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	(  data + i ) )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	(  data + i ) )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	(  data + i ) )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	(  data + i ) )->blas_sum_kernel ;
	int  fieldid ;
	for (fieldid=0 ; 	(  fieldid < NUM_SYNC_LAYER ) ; fieldid++)
	{
	if (  	(  fieldid == 	(  NUM_SYNC_LAYER / 2 ) )  ){  
		continue;

	}else{
		0;

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_d2h ( (sync_layer_pscmc)[fieldid] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_d2h ( (sync_layer_pscmc)[fieldid] );

	}else{
		0;

	 }

	 }
	int  tid ;
	for (tid=0 ; 	(  tid < numvec ) ; tid++)
	{
	long  sllen = (sync_layer_len)[fieldid] ;
	double *  t0 ;
	if (  	(  0 == CD_type )  ){  
			c_pscmc_get_h_data ( (sync_layer_pscmc)[fieldid] , 	& ( t0 ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_get_h_data ( (sync_layer_pscmc)[fieldid] , 	& ( t0 ) );

	}else{
		0;

	 }

	 }
	int  REMOTE_PROC_ID = 	(  (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid )] / 	( pthis )->num_runtime ) ;
{
	if (  	(  cur_rank == REMOTE_PROC_ID )  ){  
		continue;

	}else{
			PS_MPI_Isend ( 	(  t0 + 	(  tid * sllen ) ) , sllen , PS_MPI_DOUBLE , REMOTE_PROC_ID , 	(  	(  NUM_SYNC_LAYER * (adj_ids)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid )] ) + fieldid ) , comm , 	(  (rqst)[i] + 	(  	(  tid * NUM_SYNC_LAYER ) + fieldid ) ) );

	 }
}}}}	for (i=0 ; i<num_data ; i++)
	{
	void *  pe = 	( 	(  data + i ) )->pe ;
	long  xlen = 	( 	(  data + i ) )->xlen ;
	long  ylen = 	( 	(  data + i ) )->ylen ;
	long  zlen = 	( 	(  data + i ) )->zlen ;
	long  xblock = 	( 	(  data + i ) )->xblock ;
	long  yblock = 	( 	(  data + i ) )->yblock ;
	long  zblock = 	( 	(  data + i ) )->zblock ;
	long  numvec = 	( 	(  data + i ) )->numvec ;
	long  x_num_thread_block = 	( 	(  data + i ) )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	(  data + i ) )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	(  data + i ) )->z_num_thread_block ;
	int  ovlp = 	( 	(  data + i ) )->ovlp ;
	int  num_ele = 	( 	(  data + i ) )->num_ele ;
	int  CD_type = 	( 	(  data + i ) )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	(  data + i ) )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	(  data + i ) )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	(  data + i ) )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	(  data + i ) )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	(  data + i ) )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  data + i ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  data + i ) )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( 	(  data + i ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  data + i ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  data + i ) )->yee_damp_kernels ;
	void *  rdcd = 	( 	(  data + i ) )->rdcd ;
	double *  rdcd_host = 	( 	(  data + i ) )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	(  data + i ) )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	(  data + i ) )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	(  data + i ) )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	(  data + i ) )->xoffset ;
	void *  yoffset = 	( 	(  data + i ) )->yoffset ;
	void *  zoffset = 	( 	(  data + i ) )->zoffset ;
	long *  global_x_offset = 	( 	(  data + i ) )->global_x_offset ;
	long *  global_y_offset = 	( 	(  data + i ) )->global_y_offset ;
	long *  global_z_offset = 	( 	(  data + i ) )->global_z_offset ;
	long *  global_id = 	( 	(  data + i ) )->global_id ;
	long  global_pid = 	( 	(  data + i ) )->global_pid ;
	long *  adj_ids = 	( 	(  data + i ) )->adj_ids ;
	long *  adj_processes = 	( 	(  data + i ) )->adj_processes ;
	long *  adj_local_tid = 	( 	(  data + i ) )->adj_local_tid ;
	void *  main_data = 	( 	(  data + i ) )->main_data ;
	double  delta_x = 	( 	(  data + i ) )->delta_x ;
	double  delta_y = 	( 	(  data + i ) )->delta_y ;
	double  delta_z = 	( 	(  data + i ) )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	(  data + i ) )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( 	(  data + i ) )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	(  data + i ) )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	(  data + i ) )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	(  data + i ) )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	(  data + i ) )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	(  data + i ) )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	(  data + i ) )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	(  data + i ) )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	(  data + i ) )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	(  data + i ) )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	(  data + i ) )->blas_sum_kernel ;
	int  fieldid ;
	for (fieldid=0 ; 	(  fieldid < NUM_SYNC_LAYER ) ; fieldid++)
	{
	if (  	(  fieldid == 	(  NUM_SYNC_LAYER / 2 ) )  ){  
		continue;

	}else{
		0;

	 }
	int  tid ;
	for (tid=0 ; 	(  tid < numvec ) ; tid++)
	{
	long  sllen = (sync_layer_len)[fieldid] ;
	double *  t1 ;
	double *  t0 ;
	if (  	(  0 == CD_type )  ){  
			c_pscmc_get_h_data ( (swap_layer_pscmc)[fieldid] , 	& ( t1 ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_get_h_data ( (swap_layer_pscmc)[fieldid] , 	& ( t1 ) );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_get_h_data ( (sync_layer_pscmc)[	(  	(  NUM_SYNC_LAYER - 1 ) - fieldid )] , 	& ( t0 ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_get_h_data ( (sync_layer_pscmc)[	(  	(  NUM_SYNC_LAYER - 1 ) - fieldid )] , 	& ( t0 ) );

	}else{
		0;

	 }

	 }
{
	long  adj_proc_id = (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid )] ;
	int  REMOTE_PROC_ID = 	(  adj_proc_id / 	( pthis )->num_runtime ) ;
	if (  	(  adj_proc_id == (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + 	(  NUM_SYNC_LAYER / 2 ) )] )  ){  
			long  t0id = (adj_local_tid)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid )] ;
	memcpy ( 	(  t1 + 	(  tid * sllen ) ) , 	(  t0 + 	(  t0id * sllen ) ) , 	(  sizeof(double ) * sllen ) );

	}else{
			PS_MPI_Recv ( 	(  t1 + 	(  tid * sllen ) ) , sllen , PS_MPI_DOUBLE , REMOTE_PROC_ID , 	(  	(  NUM_SYNC_LAYER * (adj_ids)[	(  	(  tid * NUM_SYNC_LAYER ) + 	(  NUM_SYNC_LAYER / 2 ) )] ) + 	(  	(  NUM_SYNC_LAYER - 1 ) - fieldid ) ) , comm , NULL );

	 }
}}	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( (swap_layer_pscmc)[fieldid] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( (swap_layer_pscmc)[fieldid] );

	}else{
		0;

	 }

	 }
}}	for (i=0 ; i<num_data ; i++)
	{
	void *  pe = 	( 	(  data + i ) )->pe ;
	long  xlen = 	( 	(  data + i ) )->xlen ;
	long  ylen = 	( 	(  data + i ) )->ylen ;
	long  zlen = 	( 	(  data + i ) )->zlen ;
	long  xblock = 	( 	(  data + i ) )->xblock ;
	long  yblock = 	( 	(  data + i ) )->yblock ;
	long  zblock = 	( 	(  data + i ) )->zblock ;
	long  numvec = 	( 	(  data + i ) )->numvec ;
	long  x_num_thread_block = 	( 	(  data + i ) )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	(  data + i ) )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	(  data + i ) )->z_num_thread_block ;
	int  ovlp = 	( 	(  data + i ) )->ovlp ;
	int  num_ele = 	( 	(  data + i ) )->num_ele ;
	int  CD_type = 	( 	(  data + i ) )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	(  data + i ) )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	(  data + i ) )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	(  data + i ) )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	(  data + i ) )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	(  data + i ) )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  data + i ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  data + i ) )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( 	(  data + i ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  data + i ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  data + i ) )->yee_damp_kernels ;
	void *  rdcd = 	( 	(  data + i ) )->rdcd ;
	double *  rdcd_host = 	( 	(  data + i ) )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	(  data + i ) )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	(  data + i ) )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	(  data + i ) )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	(  data + i ) )->xoffset ;
	void *  yoffset = 	( 	(  data + i ) )->yoffset ;
	void *  zoffset = 	( 	(  data + i ) )->zoffset ;
	long *  global_x_offset = 	( 	(  data + i ) )->global_x_offset ;
	long *  global_y_offset = 	( 	(  data + i ) )->global_y_offset ;
	long *  global_z_offset = 	( 	(  data + i ) )->global_z_offset ;
	long *  global_id = 	( 	(  data + i ) )->global_id ;
	long  global_pid = 	( 	(  data + i ) )->global_pid ;
	long *  adj_ids = 	( 	(  data + i ) )->adj_ids ;
	long *  adj_processes = 	( 	(  data + i ) )->adj_processes ;
	long *  adj_local_tid = 	( 	(  data + i ) )->adj_local_tid ;
	void *  main_data = 	( 	(  data + i ) )->main_data ;
	double  delta_x = 	( 	(  data + i ) )->delta_x ;
	double  delta_y = 	( 	(  data + i ) )->delta_y ;
	double  delta_z = 	( 	(  data + i ) )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	(  data + i ) )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( 	(  data + i ) )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	(  data + i ) )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	(  data + i ) )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	(  data + i ) )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	(  data + i ) )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	(  data + i ) )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	(  data + i ) )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	(  data + i ) )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	(  data + i ) )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	(  data + i ) )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	(  data + i ) )->blas_sum_kernel ;
	int  fieldid ;
	for (fieldid=0 ; 	(  fieldid < NUM_SYNC_LAYER ) ; fieldid++)
	{
	if (  	(  fieldid == 	(  NUM_SYNC_LAYER / 2 ) )  ){  
		continue;

	}else{
		0;

	 }
	int  tid ;
	for (tid=0 ; 	(  tid < numvec ) ; tid++)
	{
	long  adj_proc_id = (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid )] ;
	int  REMOTE_PROC_ID = 	(  adj_proc_id / 	( pthis )->num_runtime ) ;
	if (  	(  adj_proc_id == (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + 	(  NUM_SYNC_LAYER / 2 ) )] )  ){  
		continue;

	}else{
			PS_MPI_Wait ( 	(  (rqst)[i] + 	(  	(  tid * NUM_SYNC_LAYER ) + fieldid ) ) , NULL );

	 }
}}}	for (i=0 ; i<num_data ; i++)
	{
	Field3D_Seq_ovlp_merge_ovlp_o2m ( 	(  data + i ) , 0 );
}	return  0 ;}
int  sync_ovlp_mpi_field (Field3D_MPI *  pthis ){
	Field3D_Seq *  data = 	( pthis )->data ;
	long  num_runtime = 	( pthis )->num_runtime ;
	PS_MPI_Comm  comm = 	( pthis )->comm ;
	long  cur_rank = 	( pthis )->cur_rank ;
	long  num_mpi_process = 	( pthis )->num_mpi_process ;
	long *  sync_layer_len = 	( pthis )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( pthis )->rqst ;
	One_Particle_Collection *  particles = 	( pthis )->particles ;
	int  num_spec = 	( pthis )->num_spec ;
	double  damp_vars = 	( pthis )->damp_vars ;
	long  i = 0 ;
	long  num_data = num_runtime ;
	for (i=0 ; i<num_data ; i++)
	{
	Field3D_Seq_ovlp_sync_ovlp_m2o ( 	(  data + i ) , 1 );
}	int  fieldid ;
	for (fieldid=0 ; 	(  fieldid < NUM_SYNC_LAYER ) ; fieldid++)
	{
	if (  	(  fieldid == 	(  NUM_SYNC_LAYER / 2 ) )  ){  
		continue;

	}else{
		0;

	 }
	for (i=0 ; i<num_data ; i++)
	{
	void *  pe = 	( 	(  data + i ) )->pe ;
	long  xlen = 	( 	(  data + i ) )->xlen ;
	long  ylen = 	( 	(  data + i ) )->ylen ;
	long  zlen = 	( 	(  data + i ) )->zlen ;
	long  xblock = 	( 	(  data + i ) )->xblock ;
	long  yblock = 	( 	(  data + i ) )->yblock ;
	long  zblock = 	( 	(  data + i ) )->zblock ;
	long  numvec = 	( 	(  data + i ) )->numvec ;
	long  x_num_thread_block = 	( 	(  data + i ) )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	(  data + i ) )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	(  data + i ) )->z_num_thread_block ;
	int  ovlp = 	( 	(  data + i ) )->ovlp ;
	int  num_ele = 	( 	(  data + i ) )->num_ele ;
	int  CD_type = 	( 	(  data + i ) )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	(  data + i ) )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	(  data + i ) )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	(  data + i ) )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	(  data + i ) )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	(  data + i ) )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  data + i ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  data + i ) )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( 	(  data + i ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  data + i ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  data + i ) )->yee_damp_kernels ;
	void *  rdcd = 	( 	(  data + i ) )->rdcd ;
	double *  rdcd_host = 	( 	(  data + i ) )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	(  data + i ) )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	(  data + i ) )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	(  data + i ) )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	(  data + i ) )->xoffset ;
	void *  yoffset = 	( 	(  data + i ) )->yoffset ;
	void *  zoffset = 	( 	(  data + i ) )->zoffset ;
	long *  global_x_offset = 	( 	(  data + i ) )->global_x_offset ;
	long *  global_y_offset = 	( 	(  data + i ) )->global_y_offset ;
	long *  global_z_offset = 	( 	(  data + i ) )->global_z_offset ;
	long *  global_id = 	( 	(  data + i ) )->global_id ;
	long  global_pid = 	( 	(  data + i ) )->global_pid ;
	long *  adj_ids = 	( 	(  data + i ) )->adj_ids ;
	long *  adj_processes = 	( 	(  data + i ) )->adj_processes ;
	long *  adj_local_tid = 	( 	(  data + i ) )->adj_local_tid ;
	void *  main_data = 	( 	(  data + i ) )->main_data ;
	double  delta_x = 	( 	(  data + i ) )->delta_x ;
	double  delta_y = 	( 	(  data + i ) )->delta_y ;
	double  delta_z = 	( 	(  data + i ) )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	(  data + i ) )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( 	(  data + i ) )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	(  data + i ) )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	(  data + i ) )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	(  data + i ) )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	(  data + i ) )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	(  data + i ) )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	(  data + i ) )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	(  data + i ) )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	(  data + i ) )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	(  data + i ) )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	(  data + i ) )->blas_sum_kernel ;
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_d2h ( (sync_layer_pscmc)[fieldid] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_d2h ( (sync_layer_pscmc)[fieldid] );

	}else{
		0;

	 }

	 }
	int  tid ;
	for (tid=0 ; 	(  tid < numvec ) ; tid++)
	{
	long  sllen = (sync_layer_len)[fieldid] ;
	double *  t0 ;
	if (  	(  0 == CD_type )  ){  
			c_pscmc_get_h_data ( (sync_layer_pscmc)[fieldid] , 	& ( t0 ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_get_h_data ( (sync_layer_pscmc)[fieldid] , 	& ( t0 ) );

	}else{
		0;

	 }

	 }
	int  REMOTE_PROC_ID = 	(  (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid )] / 	( pthis )->num_runtime ) ;
{
	if (  	(  cur_rank == REMOTE_PROC_ID )  ){  
		continue;

	}else{
			PS_MPI_Isend ( 	(  t0 + 	(  tid * sllen ) ) , sllen , PS_MPI_DOUBLE , REMOTE_PROC_ID , 	(  	(  NUM_SYNC_LAYER * (adj_ids)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid )] ) + fieldid ) , comm , 	(  (rqst)[i] + 	(  	(  tid * NUM_SYNC_LAYER ) + fieldid ) ) );

	 }
}}}	for (i=0 ; i<num_data ; i++)
	{
	void *  pe = 	( 	(  data + i ) )->pe ;
	long  xlen = 	( 	(  data + i ) )->xlen ;
	long  ylen = 	( 	(  data + i ) )->ylen ;
	long  zlen = 	( 	(  data + i ) )->zlen ;
	long  xblock = 	( 	(  data + i ) )->xblock ;
	long  yblock = 	( 	(  data + i ) )->yblock ;
	long  zblock = 	( 	(  data + i ) )->zblock ;
	long  numvec = 	( 	(  data + i ) )->numvec ;
	long  x_num_thread_block = 	( 	(  data + i ) )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	(  data + i ) )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	(  data + i ) )->z_num_thread_block ;
	int  ovlp = 	( 	(  data + i ) )->ovlp ;
	int  num_ele = 	( 	(  data + i ) )->num_ele ;
	int  CD_type = 	( 	(  data + i ) )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	(  data + i ) )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	(  data + i ) )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	(  data + i ) )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	(  data + i ) )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	(  data + i ) )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  data + i ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  data + i ) )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( 	(  data + i ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  data + i ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  data + i ) )->yee_damp_kernels ;
	void *  rdcd = 	( 	(  data + i ) )->rdcd ;
	double *  rdcd_host = 	( 	(  data + i ) )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	(  data + i ) )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	(  data + i ) )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	(  data + i ) )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	(  data + i ) )->xoffset ;
	void *  yoffset = 	( 	(  data + i ) )->yoffset ;
	void *  zoffset = 	( 	(  data + i ) )->zoffset ;
	long *  global_x_offset = 	( 	(  data + i ) )->global_x_offset ;
	long *  global_y_offset = 	( 	(  data + i ) )->global_y_offset ;
	long *  global_z_offset = 	( 	(  data + i ) )->global_z_offset ;
	long *  global_id = 	( 	(  data + i ) )->global_id ;
	long  global_pid = 	( 	(  data + i ) )->global_pid ;
	long *  adj_ids = 	( 	(  data + i ) )->adj_ids ;
	long *  adj_processes = 	( 	(  data + i ) )->adj_processes ;
	long *  adj_local_tid = 	( 	(  data + i ) )->adj_local_tid ;
	void *  main_data = 	( 	(  data + i ) )->main_data ;
	double  delta_x = 	( 	(  data + i ) )->delta_x ;
	double  delta_y = 	( 	(  data + i ) )->delta_y ;
	double  delta_z = 	( 	(  data + i ) )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	(  data + i ) )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( 	(  data + i ) )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	(  data + i ) )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	(  data + i ) )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	(  data + i ) )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	(  data + i ) )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	(  data + i ) )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	(  data + i ) )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	(  data + i ) )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	(  data + i ) )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	(  data + i ) )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	(  data + i ) )->blas_sum_kernel ;
	int  tid ;
	int  fieldid1 = 	(  	(  NUM_SYNC_LAYER - 1 ) - fieldid ) ;
	for (tid=0 ; 	(  tid < numvec ) ; tid++)
	{
	long  sllen = (sync_layer_len)[fieldid1] ;
	double *  t1 ;
	double *  t0 ;
	if (  	(  0 == CD_type )  ){  
			c_pscmc_get_h_data ( (swap_layer_pscmc)[fieldid1] , 	& ( t1 ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_get_h_data ( (swap_layer_pscmc)[fieldid1] , 	& ( t1 ) );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_get_h_data ( (sync_layer_pscmc)[	(  	(  NUM_SYNC_LAYER - 1 ) - fieldid1 )] , 	& ( t0 ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_get_h_data ( (sync_layer_pscmc)[	(  	(  NUM_SYNC_LAYER - 1 ) - fieldid1 )] , 	& ( t0 ) );

	}else{
		0;

	 }

	 }
{
	long  adj_proc_id = (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid1 )] ;
	int  REMOTE_PROC_ID = 	(  adj_proc_id / 	( pthis )->num_runtime ) ;
	if (  	(  adj_proc_id == (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + 	(  NUM_SYNC_LAYER / 2 ) )] )  ){  
			long  t0id = (adj_local_tid)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid1 )] ;
	memcpy ( 	(  t1 + 	(  tid * sllen ) ) , 	(  t0 + 	(  t0id * sllen ) ) , 	(  sizeof(double ) * sllen ) );

	}else{
			PS_MPI_Recv ( 	(  t1 + 	(  tid * sllen ) ) , sllen , PS_MPI_DOUBLE , REMOTE_PROC_ID , 	(  	(  NUM_SYNC_LAYER * (adj_ids)[	(  	(  tid * NUM_SYNC_LAYER ) + 	(  NUM_SYNC_LAYER / 2 ) )] ) + 	(  	(  NUM_SYNC_LAYER - 1 ) - fieldid1 ) ) , comm , NULL );

	 }
}}	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( (swap_layer_pscmc)[fieldid1] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( (swap_layer_pscmc)[fieldid1] );

	}else{
		0;

	 }

	 }
}	for (i=0 ; i<num_data ; i++)
	{
	void *  pe = 	( 	(  data + i ) )->pe ;
	long  xlen = 	( 	(  data + i ) )->xlen ;
	long  ylen = 	( 	(  data + i ) )->ylen ;
	long  zlen = 	( 	(  data + i ) )->zlen ;
	long  xblock = 	( 	(  data + i ) )->xblock ;
	long  yblock = 	( 	(  data + i ) )->yblock ;
	long  zblock = 	( 	(  data + i ) )->zblock ;
	long  numvec = 	( 	(  data + i ) )->numvec ;
	long  x_num_thread_block = 	( 	(  data + i ) )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	(  data + i ) )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	(  data + i ) )->z_num_thread_block ;
	int  ovlp = 	( 	(  data + i ) )->ovlp ;
	int  num_ele = 	( 	(  data + i ) )->num_ele ;
	int  CD_type = 	( 	(  data + i ) )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	(  data + i ) )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	(  data + i ) )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	(  data + i ) )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	(  data + i ) )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	(  data + i ) )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  data + i ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  data + i ) )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( 	(  data + i ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  data + i ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  data + i ) )->yee_damp_kernels ;
	void *  rdcd = 	( 	(  data + i ) )->rdcd ;
	double *  rdcd_host = 	( 	(  data + i ) )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	(  data + i ) )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	(  data + i ) )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	(  data + i ) )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	(  data + i ) )->xoffset ;
	void *  yoffset = 	( 	(  data + i ) )->yoffset ;
	void *  zoffset = 	( 	(  data + i ) )->zoffset ;
	long *  global_x_offset = 	( 	(  data + i ) )->global_x_offset ;
	long *  global_y_offset = 	( 	(  data + i ) )->global_y_offset ;
	long *  global_z_offset = 	( 	(  data + i ) )->global_z_offset ;
	long *  global_id = 	( 	(  data + i ) )->global_id ;
	long  global_pid = 	( 	(  data + i ) )->global_pid ;
	long *  adj_ids = 	( 	(  data + i ) )->adj_ids ;
	long *  adj_processes = 	( 	(  data + i ) )->adj_processes ;
	long *  adj_local_tid = 	( 	(  data + i ) )->adj_local_tid ;
	void *  main_data = 	( 	(  data + i ) )->main_data ;
	double  delta_x = 	( 	(  data + i ) )->delta_x ;
	double  delta_y = 	( 	(  data + i ) )->delta_y ;
	double  delta_z = 	( 	(  data + i ) )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	(  data + i ) )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( 	(  data + i ) )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	(  data + i ) )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	(  data + i ) )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	(  data + i ) )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	(  data + i ) )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	(  data + i ) )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	(  data + i ) )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	(  data + i ) )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	(  data + i ) )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	(  data + i ) )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	(  data + i ) )->blas_sum_kernel ;
	int  tid ;
	for (tid=0 ; 	(  tid < numvec ) ; tid++)
	{
	long  adj_proc_id = (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid )] ;
	int  REMOTE_PROC_ID = 	(  adj_proc_id / 	( pthis )->num_runtime ) ;
	if (  	(  adj_proc_id == (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + 	(  NUM_SYNC_LAYER / 2 ) )] )  ){  
		continue;

	}else{
			PS_MPI_Wait ( 	(  (rqst)[i] + 	(  	(  tid * NUM_SYNC_LAYER ) + fieldid ) ) , NULL );

	 }
}}}	for (i=0 ; i<num_data ; i++)
	{
	Field3D_Seq_ovlp_sync_ovlp_o2m ( 	(  data + i ) , 0 );
}	return  0 ;}
int  sync_ovlp_mpi_field_swap_loop (Field3D_MPI *  pthis ){
	Field3D_Seq *  data = 	( pthis )->data ;
	long  num_runtime = 	( pthis )->num_runtime ;
	PS_MPI_Comm  comm = 	( pthis )->comm ;
	long  cur_rank = 	( pthis )->cur_rank ;
	long  num_mpi_process = 	( pthis )->num_mpi_process ;
	long *  sync_layer_len = 	( pthis )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( pthis )->rqst ;
	One_Particle_Collection *  particles = 	( pthis )->particles ;
	int  num_spec = 	( pthis )->num_spec ;
	double  damp_vars = 	( pthis )->damp_vars ;
	long  i = 0 ;
	long  num_data = num_runtime ;
	for (i=0 ; i<num_data ; i++)
	{
	Field3D_Seq_ovlp_sync_ovlp_m2o ( 	(  data + i ) , 1 );
}	for (i=0 ; i<num_data ; i++)
	{
	void *  pe = 	( 	(  data + i ) )->pe ;
	long  xlen = 	( 	(  data + i ) )->xlen ;
	long  ylen = 	( 	(  data + i ) )->ylen ;
	long  zlen = 	( 	(  data + i ) )->zlen ;
	long  xblock = 	( 	(  data + i ) )->xblock ;
	long  yblock = 	( 	(  data + i ) )->yblock ;
	long  zblock = 	( 	(  data + i ) )->zblock ;
	long  numvec = 	( 	(  data + i ) )->numvec ;
	long  x_num_thread_block = 	( 	(  data + i ) )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	(  data + i ) )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	(  data + i ) )->z_num_thread_block ;
	int  ovlp = 	( 	(  data + i ) )->ovlp ;
	int  num_ele = 	( 	(  data + i ) )->num_ele ;
	int  CD_type = 	( 	(  data + i ) )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	(  data + i ) )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	(  data + i ) )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	(  data + i ) )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	(  data + i ) )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	(  data + i ) )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  data + i ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  data + i ) )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( 	(  data + i ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  data + i ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  data + i ) )->yee_damp_kernels ;
	void *  rdcd = 	( 	(  data + i ) )->rdcd ;
	double *  rdcd_host = 	( 	(  data + i ) )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	(  data + i ) )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	(  data + i ) )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	(  data + i ) )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	(  data + i ) )->xoffset ;
	void *  yoffset = 	( 	(  data + i ) )->yoffset ;
	void *  zoffset = 	( 	(  data + i ) )->zoffset ;
	long *  global_x_offset = 	( 	(  data + i ) )->global_x_offset ;
	long *  global_y_offset = 	( 	(  data + i ) )->global_y_offset ;
	long *  global_z_offset = 	( 	(  data + i ) )->global_z_offset ;
	long *  global_id = 	( 	(  data + i ) )->global_id ;
	long  global_pid = 	( 	(  data + i ) )->global_pid ;
	long *  adj_ids = 	( 	(  data + i ) )->adj_ids ;
	long *  adj_processes = 	( 	(  data + i ) )->adj_processes ;
	long *  adj_local_tid = 	( 	(  data + i ) )->adj_local_tid ;
	void *  main_data = 	( 	(  data + i ) )->main_data ;
	double  delta_x = 	( 	(  data + i ) )->delta_x ;
	double  delta_y = 	( 	(  data + i ) )->delta_y ;
	double  delta_z = 	( 	(  data + i ) )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	(  data + i ) )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( 	(  data + i ) )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	(  data + i ) )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	(  data + i ) )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	(  data + i ) )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	(  data + i ) )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	(  data + i ) )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	(  data + i ) )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	(  data + i ) )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	(  data + i ) )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	(  data + i ) )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	(  data + i ) )->blas_sum_kernel ;
	int  fieldid ;
	for (fieldid=0 ; 	(  fieldid < NUM_SYNC_LAYER ) ; fieldid++)
	{
	if (  	(  fieldid == 	(  NUM_SYNC_LAYER / 2 ) )  ){  
		continue;

	}else{
		0;

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_d2h ( (sync_layer_pscmc)[fieldid] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_d2h ( (sync_layer_pscmc)[fieldid] );

	}else{
		0;

	 }

	 }
	int  tid ;
	for (tid=0 ; 	(  tid < numvec ) ; tid++)
	{
	long  sllen = (sync_layer_len)[fieldid] ;
	double *  t0 ;
	if (  	(  0 == CD_type )  ){  
			c_pscmc_get_h_data ( (sync_layer_pscmc)[fieldid] , 	& ( t0 ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_get_h_data ( (sync_layer_pscmc)[fieldid] , 	& ( t0 ) );

	}else{
		0;

	 }

	 }
	int  REMOTE_PROC_ID = 	(  (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid )] / 	( pthis )->num_runtime ) ;
{
	if (  	(  cur_rank == REMOTE_PROC_ID )  ){  
		continue;

	}else{
			PS_MPI_Isend ( 	(  t0 + 	(  tid * sllen ) ) , sllen , PS_MPI_DOUBLE , REMOTE_PROC_ID , 	(  	(  NUM_SYNC_LAYER * (adj_ids)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid )] ) + fieldid ) , comm , 	(  (rqst)[i] + 	(  	(  tid * NUM_SYNC_LAYER ) + fieldid ) ) );

	 }
}}}}	for (i=0 ; i<num_data ; i++)
	{
	void *  pe = 	( 	(  data + i ) )->pe ;
	long  xlen = 	( 	(  data + i ) )->xlen ;
	long  ylen = 	( 	(  data + i ) )->ylen ;
	long  zlen = 	( 	(  data + i ) )->zlen ;
	long  xblock = 	( 	(  data + i ) )->xblock ;
	long  yblock = 	( 	(  data + i ) )->yblock ;
	long  zblock = 	( 	(  data + i ) )->zblock ;
	long  numvec = 	( 	(  data + i ) )->numvec ;
	long  x_num_thread_block = 	( 	(  data + i ) )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	(  data + i ) )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	(  data + i ) )->z_num_thread_block ;
	int  ovlp = 	( 	(  data + i ) )->ovlp ;
	int  num_ele = 	( 	(  data + i ) )->num_ele ;
	int  CD_type = 	( 	(  data + i ) )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	(  data + i ) )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	(  data + i ) )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	(  data + i ) )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	(  data + i ) )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	(  data + i ) )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  data + i ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  data + i ) )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( 	(  data + i ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  data + i ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  data + i ) )->yee_damp_kernels ;
	void *  rdcd = 	( 	(  data + i ) )->rdcd ;
	double *  rdcd_host = 	( 	(  data + i ) )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	(  data + i ) )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	(  data + i ) )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	(  data + i ) )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	(  data + i ) )->xoffset ;
	void *  yoffset = 	( 	(  data + i ) )->yoffset ;
	void *  zoffset = 	( 	(  data + i ) )->zoffset ;
	long *  global_x_offset = 	( 	(  data + i ) )->global_x_offset ;
	long *  global_y_offset = 	( 	(  data + i ) )->global_y_offset ;
	long *  global_z_offset = 	( 	(  data + i ) )->global_z_offset ;
	long *  global_id = 	( 	(  data + i ) )->global_id ;
	long  global_pid = 	( 	(  data + i ) )->global_pid ;
	long *  adj_ids = 	( 	(  data + i ) )->adj_ids ;
	long *  adj_processes = 	( 	(  data + i ) )->adj_processes ;
	long *  adj_local_tid = 	( 	(  data + i ) )->adj_local_tid ;
	void *  main_data = 	( 	(  data + i ) )->main_data ;
	double  delta_x = 	( 	(  data + i ) )->delta_x ;
	double  delta_y = 	( 	(  data + i ) )->delta_y ;
	double  delta_z = 	( 	(  data + i ) )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	(  data + i ) )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( 	(  data + i ) )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	(  data + i ) )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	(  data + i ) )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	(  data + i ) )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	(  data + i ) )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	(  data + i ) )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	(  data + i ) )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	(  data + i ) )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	(  data + i ) )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	(  data + i ) )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	(  data + i ) )->blas_sum_kernel ;
	int  fieldid ;
	for (fieldid=0 ; 	(  fieldid < NUM_SYNC_LAYER ) ; fieldid++)
	{
	if (  	(  fieldid == 	(  NUM_SYNC_LAYER / 2 ) )  ){  
		continue;

	}else{
		0;

	 }
	int  tid ;
	for (tid=0 ; 	(  tid < numvec ) ; tid++)
	{
	long  sllen = (sync_layer_len)[fieldid] ;
	double *  t1 ;
	double *  t0 ;
	if (  	(  0 == CD_type )  ){  
			c_pscmc_get_h_data ( (swap_layer_pscmc)[fieldid] , 	& ( t1 ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_get_h_data ( (swap_layer_pscmc)[fieldid] , 	& ( t1 ) );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_get_h_data ( (sync_layer_pscmc)[	(  	(  NUM_SYNC_LAYER - 1 ) - fieldid )] , 	& ( t0 ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_get_h_data ( (sync_layer_pscmc)[	(  	(  NUM_SYNC_LAYER - 1 ) - fieldid )] , 	& ( t0 ) );

	}else{
		0;

	 }

	 }
{
	long  adj_proc_id = (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid )] ;
	int  REMOTE_PROC_ID = 	(  adj_proc_id / 	( pthis )->num_runtime ) ;
	if (  	(  adj_proc_id == (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + 	(  NUM_SYNC_LAYER / 2 ) )] )  ){  
			long  t0id = (adj_local_tid)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid )] ;
	memcpy ( 	(  t1 + 	(  tid * sllen ) ) , 	(  t0 + 	(  t0id * sllen ) ) , 	(  sizeof(double ) * sllen ) );

	}else{
			PS_MPI_Recv ( 	(  t1 + 	(  tid * sllen ) ) , sllen , PS_MPI_DOUBLE , REMOTE_PROC_ID , 	(  	(  NUM_SYNC_LAYER * (adj_ids)[	(  	(  tid * NUM_SYNC_LAYER ) + 	(  NUM_SYNC_LAYER / 2 ) )] ) + 	(  	(  NUM_SYNC_LAYER - 1 ) - fieldid ) ) , comm , NULL );

	 }
}}	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( (swap_layer_pscmc)[fieldid] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( (swap_layer_pscmc)[fieldid] );

	}else{
		0;

	 }

	 }
}}	for (i=0 ; i<num_data ; i++)
	{
	void *  pe = 	( 	(  data + i ) )->pe ;
	long  xlen = 	( 	(  data + i ) )->xlen ;
	long  ylen = 	( 	(  data + i ) )->ylen ;
	long  zlen = 	( 	(  data + i ) )->zlen ;
	long  xblock = 	( 	(  data + i ) )->xblock ;
	long  yblock = 	( 	(  data + i ) )->yblock ;
	long  zblock = 	( 	(  data + i ) )->zblock ;
	long  numvec = 	( 	(  data + i ) )->numvec ;
	long  x_num_thread_block = 	( 	(  data + i ) )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	(  data + i ) )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	(  data + i ) )->z_num_thread_block ;
	int  ovlp = 	( 	(  data + i ) )->ovlp ;
	int  num_ele = 	( 	(  data + i ) )->num_ele ;
	int  CD_type = 	( 	(  data + i ) )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	(  data + i ) )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	(  data + i ) )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	(  data + i ) )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	(  data + i ) )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	(  data + i ) )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  data + i ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  data + i ) )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( 	(  data + i ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  data + i ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  data + i ) )->yee_damp_kernels ;
	void *  rdcd = 	( 	(  data + i ) )->rdcd ;
	double *  rdcd_host = 	( 	(  data + i ) )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	(  data + i ) )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	(  data + i ) )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	(  data + i ) )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	(  data + i ) )->xoffset ;
	void *  yoffset = 	( 	(  data + i ) )->yoffset ;
	void *  zoffset = 	( 	(  data + i ) )->zoffset ;
	long *  global_x_offset = 	( 	(  data + i ) )->global_x_offset ;
	long *  global_y_offset = 	( 	(  data + i ) )->global_y_offset ;
	long *  global_z_offset = 	( 	(  data + i ) )->global_z_offset ;
	long *  global_id = 	( 	(  data + i ) )->global_id ;
	long  global_pid = 	( 	(  data + i ) )->global_pid ;
	long *  adj_ids = 	( 	(  data + i ) )->adj_ids ;
	long *  adj_processes = 	( 	(  data + i ) )->adj_processes ;
	long *  adj_local_tid = 	( 	(  data + i ) )->adj_local_tid ;
	void *  main_data = 	( 	(  data + i ) )->main_data ;
	double  delta_x = 	( 	(  data + i ) )->delta_x ;
	double  delta_y = 	( 	(  data + i ) )->delta_y ;
	double  delta_z = 	( 	(  data + i ) )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	(  data + i ) )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( 	(  data + i ) )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	(  data + i ) )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	(  data + i ) )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	(  data + i ) )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	(  data + i ) )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	(  data + i ) )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	(  data + i ) )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	(  data + i ) )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	(  data + i ) )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	(  data + i ) )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	(  data + i ) )->blas_sum_kernel ;
	int  fieldid ;
	for (fieldid=0 ; 	(  fieldid < NUM_SYNC_LAYER ) ; fieldid++)
	{
	if (  	(  fieldid == 	(  NUM_SYNC_LAYER / 2 ) )  ){  
		continue;

	}else{
		0;

	 }
	int  tid ;
	for (tid=0 ; 	(  tid < numvec ) ; tid++)
	{
	long  adj_proc_id = (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + fieldid )] ;
	int  REMOTE_PROC_ID = 	(  adj_proc_id / 	( pthis )->num_runtime ) ;
	if (  	(  adj_proc_id == (adj_processes)[	(  	(  tid * NUM_SYNC_LAYER ) + 	(  NUM_SYNC_LAYER / 2 ) )] )  ){  
		continue;

	}else{
			PS_MPI_Wait ( 	(  (rqst)[i] + 	(  	(  tid * NUM_SYNC_LAYER ) + fieldid ) ) , NULL );

	 }
}}}	for (i=0 ; i<num_data ; i++)
	{
	Field3D_Seq_ovlp_sync_ovlp_o2m ( 	(  data + i ) , 0 );
}	return  0 ;}
int  sync_main_data_d2h (Field3D_MPI *  pthis ){
	Field3D_Seq *  data = 	( pthis )->data ;
	long  num_runtime = 	( pthis )->num_runtime ;
	PS_MPI_Comm  comm = 	( pthis )->comm ;
	long  cur_rank = 	( pthis )->cur_rank ;
	long  num_mpi_process = 	( pthis )->num_mpi_process ;
	long *  sync_layer_len = 	( pthis )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( pthis )->rqst ;
	One_Particle_Collection *  particles = 	( pthis )->particles ;
	int  num_spec = 	( pthis )->num_spec ;
	double  damp_vars = 	( pthis )->damp_vars ;
	long  i = 0 ;
	for (i=0 ; i<num_runtime ; i++)
	{
	void *  pe = 	( 	(  data + i ) )->pe ;
	long  xlen = 	( 	(  data + i ) )->xlen ;
	long  ylen = 	( 	(  data + i ) )->ylen ;
	long  zlen = 	( 	(  data + i ) )->zlen ;
	long  xblock = 	( 	(  data + i ) )->xblock ;
	long  yblock = 	( 	(  data + i ) )->yblock ;
	long  zblock = 	( 	(  data + i ) )->zblock ;
	long  numvec = 	( 	(  data + i ) )->numvec ;
	long  x_num_thread_block = 	( 	(  data + i ) )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	(  data + i ) )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	(  data + i ) )->z_num_thread_block ;
	int  ovlp = 	( 	(  data + i ) )->ovlp ;
	int  num_ele = 	( 	(  data + i ) )->num_ele ;
	int  CD_type = 	( 	(  data + i ) )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	(  data + i ) )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	(  data + i ) )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	(  data + i ) )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	(  data + i ) )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	(  data + i ) )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  data + i ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  data + i ) )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( 	(  data + i ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  data + i ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  data + i ) )->yee_damp_kernels ;
	void *  rdcd = 	( 	(  data + i ) )->rdcd ;
	double *  rdcd_host = 	( 	(  data + i ) )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	(  data + i ) )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	(  data + i ) )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	(  data + i ) )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	(  data + i ) )->xoffset ;
	void *  yoffset = 	( 	(  data + i ) )->yoffset ;
	void *  zoffset = 	( 	(  data + i ) )->zoffset ;
	long *  global_x_offset = 	( 	(  data + i ) )->global_x_offset ;
	long *  global_y_offset = 	( 	(  data + i ) )->global_y_offset ;
	long *  global_z_offset = 	( 	(  data + i ) )->global_z_offset ;
	long *  global_id = 	( 	(  data + i ) )->global_id ;
	long  global_pid = 	( 	(  data + i ) )->global_pid ;
	long *  adj_ids = 	( 	(  data + i ) )->adj_ids ;
	long *  adj_processes = 	( 	(  data + i ) )->adj_processes ;
	long *  adj_local_tid = 	( 	(  data + i ) )->adj_local_tid ;
	void *  main_data = 	( 	(  data + i ) )->main_data ;
	double  delta_x = 	( 	(  data + i ) )->delta_x ;
	double  delta_y = 	( 	(  data + i ) )->delta_y ;
	double  delta_z = 	( 	(  data + i ) )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	(  data + i ) )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( 	(  data + i ) )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	(  data + i ) )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	(  data + i ) )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	(  data + i ) )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	(  data + i ) )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	(  data + i ) )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	(  data + i ) )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	(  data + i ) )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	(  data + i ) )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	(  data + i ) )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	(  data + i ) )->blas_sum_kernel ;
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_d2h ( main_data );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_d2h ( main_data );

	}else{
		0;

	 }

	 }
}	return  0 ;}
int  sync_main_data_h2d (Field3D_MPI *  pthis ){
	Field3D_Seq *  data = 	( pthis )->data ;
	long  num_runtime = 	( pthis )->num_runtime ;
	PS_MPI_Comm  comm = 	( pthis )->comm ;
	long  cur_rank = 	( pthis )->cur_rank ;
	long  num_mpi_process = 	( pthis )->num_mpi_process ;
	long *  sync_layer_len = 	( pthis )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( pthis )->rqst ;
	One_Particle_Collection *  particles = 	( pthis )->particles ;
	int  num_spec = 	( pthis )->num_spec ;
	double  damp_vars = 	( pthis )->damp_vars ;
	long  i = 0 ;
	for (i=0 ; i<num_runtime ; i++)
	{
	void *  pe = 	( 	(  data + i ) )->pe ;
	long  xlen = 	( 	(  data + i ) )->xlen ;
	long  ylen = 	( 	(  data + i ) )->ylen ;
	long  zlen = 	( 	(  data + i ) )->zlen ;
	long  xblock = 	( 	(  data + i ) )->xblock ;
	long  yblock = 	( 	(  data + i ) )->yblock ;
	long  zblock = 	( 	(  data + i ) )->zblock ;
	long  numvec = 	( 	(  data + i ) )->numvec ;
	long  x_num_thread_block = 	( 	(  data + i ) )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	(  data + i ) )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	(  data + i ) )->z_num_thread_block ;
	int  ovlp = 	( 	(  data + i ) )->ovlp ;
	int  num_ele = 	( 	(  data + i ) )->num_ele ;
	int  CD_type = 	( 	(  data + i ) )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	(  data + i ) )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	(  data + i ) )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	(  data + i ) )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	(  data + i ) )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	(  data + i ) )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  data + i ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  data + i ) )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( 	(  data + i ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  data + i ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  data + i ) )->yee_damp_kernels ;
	void *  rdcd = 	( 	(  data + i ) )->rdcd ;
	double *  rdcd_host = 	( 	(  data + i ) )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	(  data + i ) )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	(  data + i ) )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	(  data + i ) )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	(  data + i ) )->xoffset ;
	void *  yoffset = 	( 	(  data + i ) )->yoffset ;
	void *  zoffset = 	( 	(  data + i ) )->zoffset ;
	long *  global_x_offset = 	( 	(  data + i ) )->global_x_offset ;
	long *  global_y_offset = 	( 	(  data + i ) )->global_y_offset ;
	long *  global_z_offset = 	( 	(  data + i ) )->global_z_offset ;
	long *  global_id = 	( 	(  data + i ) )->global_id ;
	long  global_pid = 	( 	(  data + i ) )->global_pid ;
	long *  adj_ids = 	( 	(  data + i ) )->adj_ids ;
	long *  adj_processes = 	( 	(  data + i ) )->adj_processes ;
	long *  adj_local_tid = 	( 	(  data + i ) )->adj_local_tid ;
	void *  main_data = 	( 	(  data + i ) )->main_data ;
	double  delta_x = 	( 	(  data + i ) )->delta_x ;
	double  delta_y = 	( 	(  data + i ) )->delta_y ;
	double  delta_z = 	( 	(  data + i ) )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	(  data + i ) )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( 	(  data + i ) )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	(  data + i ) )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	(  data + i ) )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	(  data + i ) )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	(  data + i ) )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	(  data + i ) )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	(  data + i ) )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	(  data + i ) )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	(  data + i ) )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	(  data + i ) )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	(  data + i ) )->blas_sum_kernel ;
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( main_data );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( main_data );

	}else{
		0;

	 }

	 }
}	return  0 ;}
