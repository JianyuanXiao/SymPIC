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

#define NUM_FDTD_KERNEL 22
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
	void *   sort_kernel  [6];	void *   geo_rel_1st_kernel  [8];	void *   rel_1st_kernel  [1];	void *   krook_collision_test_kernel  [2];	void *   boris_yee_kernel  [1];	void *  cu_swap_l_kernel ;
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
	void *  split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel ;
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
	Field3D_MPI  MPI_fieldEtmp1 ;
	Field3D_MPI  MPI_fieldBtmp1 ;
	Field3D_MPI  MPI_fieldPMLB ;
	Field3D_MPI  MPI_fieldPMLE ;
	Field3D_MPI *  pMPI_FoutJ ;
	Field3D_MPI *  pMPI_FoutEN ;
	Field3D_MPI  MPI_fieldE_ext ;
	Field3D_MPI  MPI_fieldB_ext ;
	Field3D_MPI  MPI_fieldE_filter ;
	Field3D_MPI  MPI_fieldB_filter ;
	Field3D_MPI *  pB0 ;
	Field3D_MPI *  pB1 ;
	int  use_pml_abc_dir ;
	int  use_pml_level ;
	int  use_small_grid ;
	long  allxmax ;
	long  allymax ;
	long  allzmax ;
	double  use_pml_sigma_max ;
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
#include "genrand.h"
#include "cfgcst.h"
#include "init_field3d_mpi.h"
#include "sync_fields.h"
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
long  find_vec_id (long  id ,long *  adj_ids ,long  numvec ){
	long  num_id_min = (adj_ids)[	(  NUM_SYNC_LAYER / 2 )] ;
	long  num_id_max = 	(  num_id_min + 	(  numvec - 1 ) ) ;
	if (  	(  	(  id < num_id_min ) || 	(  id > num_id_max ) )  ){  
			return  -1 ;
	}else{
			return  	(  id - num_id_min ) ;
	 }
}
int  init_particle (One_Particle_Collection *  pthis ,Field3D_Seq *  pfield ,double  Mass ,double  Charge ,double  Number_particle_per_marker ,long  grid_cache_len ,long  cu_cache_length ){
	if (  	(  grid_cache_len % 4 )  ){  
		(grid_cache_len = 	(  4 * 	(  	(  grid_cache_len / 4 ) + 1 ) ));

	}else{
			if (  	(  grid_cache_len == 0 )  ){  
		(grid_cache_len = 4);

	}else{
		0;

	 }

	 }
	if (  	(  cu_cache_length % 4 )  ){  
		(cu_cache_length = 	(  4 * 	(  	(  cu_cache_length / 4 ) + 1 ) ));

	}else{
			if (  	(  cu_cache_length == 0 )  ){  
		(cu_cache_length = 4);

	}else{
		0;

	 }

	 }
(	( pthis )->pfield = pfield);
(	( pthis )->Mass = Mass);
(	( pthis )->Charge = Charge);
(	( pthis )->Number_particle_per_marker = Number_particle_per_marker);
(	( pthis )->grid_cache_len = grid_cache_len);
(	( pthis )->cu_cache_length = cu_cache_length);
{
	void *  pe = 	( pfield )->pe ;
	long  xlen = 	( pfield )->xlen ;
	long  ylen = 	( pfield )->ylen ;
	long  zlen = 	( pfield )->zlen ;
	long  xblock = 	( pfield )->xblock ;
	long  yblock = 	( pfield )->yblock ;
	long  zblock = 	( pfield )->zblock ;
	long  numvec = 	( pfield )->numvec ;
	long  x_num_thread_block = 	( pfield )->x_num_thread_block ;
	long  y_num_thread_block = 	( pfield )->y_num_thread_block ;
	long  z_num_thread_block = 	( pfield )->z_num_thread_block ;
	int  ovlp = 	( pfield )->ovlp ;
	int  num_ele = 	( pfield )->num_ele ;
	int  CD_type = 	( pfield )->CD_type ;
	void * *  sync_layer_pscmc = 	( pfield )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( pfield )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( pfield )->sync_kernels ;
	void * *  fdtd_kernels = 	( pfield )->fdtd_kernels ;
	void * *  dm_kernels = 	( pfield )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pfield )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pfield )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( pfield )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pfield )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pfield )->yee_damp_kernels ;
	void *  rdcd = 	( pfield )->rdcd ;
	double *  rdcd_host = 	( pfield )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( pfield )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( pfield )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( pfield )->cur_rankz_pscmc ;
	void *  xoffset = 	( pfield )->xoffset ;
	void *  yoffset = 	( pfield )->yoffset ;
	void *  zoffset = 	( pfield )->zoffset ;
	long *  global_x_offset = 	( pfield )->global_x_offset ;
	long *  global_y_offset = 	( pfield )->global_y_offset ;
	long *  global_z_offset = 	( pfield )->global_z_offset ;
	long *  global_id = 	( pfield )->global_id ;
	long  global_pid = 	( pfield )->global_pid ;
	long *  adj_ids = 	( pfield )->adj_ids ;
	long *  adj_processes = 	( pfield )->adj_processes ;
	long *  adj_local_tid = 	( pfield )->adj_local_tid ;
	void *  main_data = 	( pfield )->main_data ;
	double  delta_x = 	( pfield )->delta_x ;
	double  delta_y = 	( pfield )->delta_y ;
	double  delta_z = 	( pfield )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( pfield )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( pfield )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( pfield )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( pfield )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( pfield )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( pfield )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( pfield )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( pfield )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( pfield )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( pfield )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( pfield )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( pfield )->blas_sum_kernel ;
	void * *  sort_kernel = 	( pthis )->sort_kernel ;
(	( pthis )->inoutput = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_pscmc_mem )):(((	(  1 == CD_type ))?(sizeof(openmp_pscmc_mem )):(0)))) ));
(	( pthis )->xyzw = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_pscmc_mem )):(((	(  1 == CD_type ))?(sizeof(openmp_pscmc_mem )):(0)))) ));
(	( pthis )->cu_cache = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_pscmc_mem )):(((	(  1 == CD_type ))?(sizeof(openmp_pscmc_mem )):(0)))) ));
(	( pthis )->cu_xyzw = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_pscmc_mem )):(((	(  1 == CD_type ))?(sizeof(openmp_pscmc_mem )):(0)))) ));
(	( pthis )->adjoint_vec_pids = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_pscmc_mem )):(((	(  1 == CD_type ))?(sizeof(openmp_pscmc_mem )):(0)))) ));
{
	size_t  structlen ;
	if (  	(  0 == CD_type )  ){  
			c_relng_1st_sg2_small_grids_get_struct_len ( 	& ( structlen ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_relng_1st_sg2_small_grids_get_struct_len ( 	& ( structlen ) );

	}else{
		0;

	 }

	 }
((	( pthis )->geo_rel_1st_kernel)[7] = 	malloc ( structlen ));
	if (  	(  0 == CD_type )  ){  
			c_relng_1st_sg2_small_grids_init ( pe , (	( pthis )->geo_rel_1st_kernel)[7] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_relng_1st_sg2_small_grids_init ( pe , (	( pthis )->geo_rel_1st_kernel)[7] );

	}else{
		0;

	 }

	 }
}{
	size_t  structlen ;
	if (  	(  0 == CD_type )  ){  
			c_geo_rel_1st_bwd_sg2_small_grids_get_struct_len ( 	& ( structlen ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_geo_rel_1st_bwd_sg2_small_grids_get_struct_len ( 	& ( structlen ) );

	}else{
		0;

	 }

	 }
((	( pthis )->geo_rel_1st_kernel)[6] = 	malloc ( structlen ));
	if (  	(  0 == CD_type )  ){  
			c_geo_rel_1st_bwd_sg2_small_grids_init ( pe , (	( pthis )->geo_rel_1st_kernel)[6] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_geo_rel_1st_bwd_sg2_small_grids_init ( pe , (	( pthis )->geo_rel_1st_kernel)[6] );

	}else{
		0;

	 }

	 }
}{
	size_t  structlen ;
	if (  	(  0 == CD_type )  ){  
			c_geo_rel_1st_fwd_sg2_small_grids_get_struct_len ( 	& ( structlen ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_geo_rel_1st_fwd_sg2_small_grids_get_struct_len ( 	& ( structlen ) );

	}else{
		0;

	 }

	 }
((	( pthis )->geo_rel_1st_kernel)[5] = 	malloc ( structlen ));
	if (  	(  0 == CD_type )  ){  
			c_geo_rel_1st_fwd_sg2_small_grids_init ( pe , (	( pthis )->geo_rel_1st_kernel)[5] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_geo_rel_1st_fwd_sg2_small_grids_init ( pe , (	( pthis )->geo_rel_1st_kernel)[5] );

	}else{
		0;

	 }

	 }
}{
	size_t  structlen ;
	if (  	(  0 == CD_type )  ){  
			c_relng_1st_small_grids_get_struct_len ( 	& ( structlen ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_relng_1st_small_grids_get_struct_len ( 	& ( structlen ) );

	}else{
		0;

	 }

	 }
((	( pthis )->geo_rel_1st_kernel)[4] = 	malloc ( structlen ));
	if (  	(  0 == CD_type )  ){  
			c_relng_1st_small_grids_init ( pe , (	( pthis )->geo_rel_1st_kernel)[4] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_relng_1st_small_grids_init ( pe , (	( pthis )->geo_rel_1st_kernel)[4] );

	}else{
		0;

	 }

	 }
}{
	size_t  structlen ;
	if (  	(  0 == CD_type )  ){  
			c_geo_rel_1st_bwd_small_grids_get_struct_len ( 	& ( structlen ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_geo_rel_1st_bwd_small_grids_get_struct_len ( 	& ( structlen ) );

	}else{
		0;

	 }

	 }
((	( pthis )->geo_rel_1st_kernel)[3] = 	malloc ( structlen ));
	if (  	(  0 == CD_type )  ){  
			c_geo_rel_1st_bwd_small_grids_init ( pe , (	( pthis )->geo_rel_1st_kernel)[3] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_geo_rel_1st_bwd_small_grids_init ( pe , (	( pthis )->geo_rel_1st_kernel)[3] );

	}else{
		0;

	 }

	 }
}{
	size_t  structlen ;
	if (  	(  0 == CD_type )  ){  
			c_geo_rel_1st_fwd_small_grids_get_struct_len ( 	& ( structlen ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_geo_rel_1st_fwd_small_grids_get_struct_len ( 	& ( structlen ) );

	}else{
		0;

	 }

	 }
((	( pthis )->geo_rel_1st_kernel)[2] = 	malloc ( structlen ));
	if (  	(  0 == CD_type )  ){  
			c_geo_rel_1st_fwd_small_grids_init ( pe , (	( pthis )->geo_rel_1st_kernel)[2] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_geo_rel_1st_fwd_small_grids_init ( pe , (	( pthis )->geo_rel_1st_kernel)[2] );

	}else{
		0;

	 }

	 }
}{
	size_t  structlen ;
	if (  	(  0 == CD_type )  ){  
			c_geo_rel_1st_bwd_get_struct_len ( 	& ( structlen ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_geo_rel_1st_bwd_get_struct_len ( 	& ( structlen ) );

	}else{
		0;

	 }

	 }
((	( pthis )->geo_rel_1st_kernel)[1] = 	malloc ( structlen ));
	if (  	(  0 == CD_type )  ){  
			c_geo_rel_1st_bwd_init ( pe , (	( pthis )->geo_rel_1st_kernel)[1] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_geo_rel_1st_bwd_init ( pe , (	( pthis )->geo_rel_1st_kernel)[1] );

	}else{
		0;

	 }

	 }
}{
	size_t  structlen ;
	if (  	(  0 == CD_type )  ){  
			c_geo_rel_1st_fwd_get_struct_len ( 	& ( structlen ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_geo_rel_1st_fwd_get_struct_len ( 	& ( structlen ) );

	}else{
		0;

	 }

	 }
((	( pthis )->geo_rel_1st_kernel)[0] = 	malloc ( structlen ));
	if (  	(  0 == CD_type )  ){  
			c_geo_rel_1st_fwd_init ( pe , (	( pthis )->geo_rel_1st_kernel)[0] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_geo_rel_1st_fwd_init ( pe , (	( pthis )->geo_rel_1st_kernel)[0] );

	}else{
		0;

	 }

	 }
}{
	size_t  structlen ;
	if (  	(  0 == CD_type )  ){  
			c_relng_1st_get_struct_len ( 	& ( structlen ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_relng_1st_get_struct_len ( 	& ( structlen ) );

	}else{
		0;

	 }

	 }
((	( pthis )->rel_1st_kernel)[0] = 	malloc ( structlen ));
	if (  	(  0 == CD_type )  ){  
			c_relng_1st_init ( pe , (	( pthis )->rel_1st_kernel)[0] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_relng_1st_init ( pe , (	( pthis )->rel_1st_kernel)[0] );

	}else{
		0;

	 }

	 }
}{
	size_t  structlen ;
	if (  	(  0 == CD_type )  ){  
			c_krook_collision_remove_small_speed_get_struct_len ( 	& ( structlen ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_krook_collision_remove_small_speed_get_struct_len ( 	& ( structlen ) );

	}else{
		0;

	 }

	 }
((	( pthis )->krook_collision_test_kernel)[1] = 	malloc ( structlen ));
	if (  	(  0 == CD_type )  ){  
			c_krook_collision_remove_small_speed_init ( pe , (	( pthis )->krook_collision_test_kernel)[1] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_krook_collision_remove_small_speed_init ( pe , (	( pthis )->krook_collision_test_kernel)[1] );

	}else{
		0;

	 }

	 }
}{
	size_t  structlen ;
	if (  	(  0 == CD_type )  ){  
			c_krook_collision_test_get_struct_len ( 	& ( structlen ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_krook_collision_test_get_struct_len ( 	& ( structlen ) );

	}else{
		0;

	 }

	 }
((	( pthis )->krook_collision_test_kernel)[0] = 	malloc ( structlen ));
	if (  	(  0 == CD_type )  ){  
			c_krook_collision_test_init ( pe , (	( pthis )->krook_collision_test_kernel)[0] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_krook_collision_test_init ( pe , (	( pthis )->krook_collision_test_kernel)[0] );

	}else{
		0;

	 }

	 }
}{
	size_t  structlen ;
	if (  	(  0 == CD_type )  ){  
			c_boris_yee_get_struct_len ( 	& ( structlen ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_boris_yee_get_struct_len ( 	& ( structlen ) );

	}else{
		0;

	 }

	 }
((	( pthis )->boris_yee_kernel)[0] = 	malloc ( structlen ));
	if (  	(  0 == CD_type )  ){  
			c_boris_yee_init ( pe , (	( pthis )->boris_yee_kernel)[0] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_boris_yee_init ( pe , (	( pthis )->boris_yee_kernel)[0] );

	}else{
		0;

	 }

	 }
}	long  num_grids = 	(  numvec * 	(  xlen * 	(  ylen * zlen ) ) ) ;
(	( pthis )->cu_swap_l_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_cu_swap_l_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_cu_swap_l_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_cu_swap_l_init ( pe , 	( pthis )->cu_swap_l_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_cu_swap_l_init ( pe , 	( pthis )->cu_swap_l_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->cu_swap_r_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_cu_swap_r_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_cu_swap_r_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_cu_swap_r_init ( pe , 	( pthis )->cu_swap_r_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_cu_swap_r_init ( pe , 	( pthis )->cu_swap_r_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->move_back_kernel_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_move_back_kernel_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_move_back_kernel_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_move_back_kernel_init ( pe , 	( pthis )->move_back_kernel_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_move_back_kernel_init ( pe , 	( pthis )->move_back_kernel_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_x_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_x_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_x_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_x_init ( pe , 	( pthis )->split_pass_x_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_x_init ( pe , 	( pthis )->split_pass_x_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_y_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_y_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_y_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_y_init ( pe , 	( pthis )->split_pass_y_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_y_init ( pe , 	( pthis )->split_pass_y_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_z_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_z_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_z_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_z_init ( pe , 	( pthis )->split_pass_z_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_z_init ( pe , 	( pthis )->split_pass_z_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_x_small_grids_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_x_small_grids_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_x_small_grids_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_x_small_grids_init ( pe , 	( pthis )->split_pass_x_small_grids_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_x_small_grids_init ( pe , 	( pthis )->split_pass_x_small_grids_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_y_small_grids_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_y_small_grids_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_y_small_grids_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_y_small_grids_init ( pe , 	( pthis )->split_pass_y_small_grids_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_y_small_grids_init ( pe , 	( pthis )->split_pass_y_small_grids_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_z_small_grids_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_z_small_grids_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_z_small_grids_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_z_small_grids_init ( pe , 	( pthis )->split_pass_z_small_grids_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_z_small_grids_init ( pe , 	( pthis )->split_pass_z_small_grids_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_x_sg2_small_grids_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_x_sg2_small_grids_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_x_sg2_small_grids_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_x_sg2_small_grids_init ( pe , 	( pthis )->split_pass_x_sg2_small_grids_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_x_sg2_small_grids_init ( pe , 	( pthis )->split_pass_x_sg2_small_grids_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_y_sg2_small_grids_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_y_sg2_small_grids_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_y_sg2_small_grids_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_y_sg2_small_grids_init ( pe , 	( pthis )->split_pass_y_sg2_small_grids_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_y_sg2_small_grids_init ( pe , 	( pthis )->split_pass_y_sg2_small_grids_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_z_sg2_small_grids_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_z_sg2_small_grids_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_z_sg2_small_grids_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_z_sg2_small_grids_init ( pe , 	( pthis )->split_pass_z_sg2_small_grids_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_z_sg2_small_grids_init ( pe , 	( pthis )->split_pass_z_sg2_small_grids_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_E_particle_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_E_particle_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_E_particle_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_E_particle_init ( pe , 	( pthis )->split_pass_E_particle_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_E_particle_init ( pe , 	( pthis )->split_pass_E_particle_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_x_vlo_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_x_vlo_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_x_vlo_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_x_vlo_init ( pe , 	( pthis )->split_pass_x_vlo_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_x_vlo_init ( pe , 	( pthis )->split_pass_x_vlo_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_y_vlo_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_y_vlo_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_y_vlo_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_y_vlo_init ( pe , 	( pthis )->split_pass_y_vlo_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_y_vlo_init ( pe , 	( pthis )->split_pass_y_vlo_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_z_vlo_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_z_vlo_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_z_vlo_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_z_vlo_init ( pe , 	( pthis )->split_pass_z_vlo_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_z_vlo_init ( pe , 	( pthis )->split_pass_z_vlo_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_x_vlo_small_grids_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_x_vlo_small_grids_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_x_vlo_small_grids_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_x_vlo_small_grids_init ( pe , 	( pthis )->split_pass_x_vlo_small_grids_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_x_vlo_small_grids_init ( pe , 	( pthis )->split_pass_x_vlo_small_grids_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_y_vlo_small_grids_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_y_vlo_small_grids_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_y_vlo_small_grids_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_y_vlo_small_grids_init ( pe , 	( pthis )->split_pass_y_vlo_small_grids_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_y_vlo_small_grids_init ( pe , 	( pthis )->split_pass_y_vlo_small_grids_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_z_vlo_small_grids_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_z_vlo_small_grids_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_z_vlo_small_grids_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_z_vlo_small_grids_init ( pe , 	( pthis )->split_pass_z_vlo_small_grids_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_z_vlo_small_grids_init ( pe , 	( pthis )->split_pass_z_vlo_small_grids_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_x_vlo_sg2_small_grids_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_x_vlo_sg2_small_grids_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_x_vlo_sg2_small_grids_init ( pe , 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_x_vlo_sg2_small_grids_init ( pe , 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_y_vlo_sg2_small_grids_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_y_vlo_sg2_small_grids_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_y_vlo_sg2_small_grids_init ( pe , 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_y_vlo_sg2_small_grids_init ( pe , 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_z_vlo_sg2_small_grids_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_z_vlo_sg2_small_grids_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_z_vlo_sg2_small_grids_init ( pe , 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_z_vlo_sg2_small_grids_init ( pe , 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->split_pass_E_particle_vlo_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_split_pass_E_particle_vlo_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_split_pass_E_particle_vlo_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_E_particle_vlo_init ( pe , 	( pthis )->split_pass_E_particle_vlo_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_E_particle_vlo_init ( pe , 	( pthis )->split_pass_E_particle_vlo_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->dump_ene_num_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_dump_ene_num_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_dump_ene_num_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_dump_ene_num_init ( pe , 	( pthis )->dump_ene_num_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_dump_ene_num_init ( pe , 	( pthis )->dump_ene_num_kernel );

	}else{
		0;

	 }

	 }
(	( pthis )->calculate_rho_kernel = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_calculate_rho_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_calculate_rho_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_calculate_rho_init ( pe , 	( pthis )->calculate_rho_kernel );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_calculate_rho_init ( pe , 	( pthis )->calculate_rho_kernel );

	}else{
		0;

	 }

	 }
((sort_kernel)[0] = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_sort_one_grid_x_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_sort_one_grid_x_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_sort_one_grid_x_init ( pe , (sort_kernel)[0] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_sort_one_grid_x_init ( pe , (sort_kernel)[0] );

	}else{
		0;

	 }

	 }
((sort_kernel)[1] = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_sort_one_grid_y_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_sort_one_grid_y_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_sort_one_grid_y_init ( pe , (sort_kernel)[1] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_sort_one_grid_y_init ( pe , (sort_kernel)[1] );

	}else{
		0;

	 }

	 }
((sort_kernel)[2] = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_sort_one_grid_z_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_sort_one_grid_z_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_sort_one_grid_z_init ( pe , (sort_kernel)[2] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_sort_one_grid_z_init ( pe , (sort_kernel)[2] );

	}else{
		0;

	 }

	 }
((sort_kernel)[3] = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_sort_one_grid_x_vlo_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_sort_one_grid_x_vlo_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_sort_one_grid_x_vlo_init ( pe , (sort_kernel)[3] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_sort_one_grid_x_vlo_init ( pe , (sort_kernel)[3] );

	}else{
		0;

	 }

	 }
((sort_kernel)[4] = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_sort_one_grid_y_vlo_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_sort_one_grid_y_vlo_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_sort_one_grid_y_vlo_init ( pe , (sort_kernel)[4] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_sort_one_grid_y_vlo_init ( pe , (sort_kernel)[4] );

	}else{
		0;

	 }

	 }
((sort_kernel)[5] = 	malloc ( ((	(  0 == CD_type ))?(sizeof(c_sort_one_grid_z_vlo_struct )):(((	(  1 == CD_type ))?(sizeof(openmp_sort_one_grid_z_vlo_struct )):(0)))) ));
	if (  	(  0 == CD_type )  ){  
			c_sort_one_grid_z_vlo_init ( pe , (sort_kernel)[5] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_sort_one_grid_z_vlo_init ( pe , (sort_kernel)[5] );

	}else{
		0;

	 }

	 }
{
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_init ( pe , 	( pthis )->inoutput , PS_DOUBLE_NUM , 	(  6 * 	(  grid_cache_len * 	(  xlen * 	(  ylen * 	(  zlen * numvec ) ) ) ) ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_init ( pe , 	( pthis )->inoutput , PS_DOUBLE_NUM , 	(  6 * 	(  grid_cache_len * 	(  xlen * 	(  ylen * 	(  zlen * numvec ) ) ) ) ) );

	}else{
		0;

	 }

	 }
	char *  tmp_h_data ;
	if (  	(  0 == CD_type )  ){  
			c_pscmc_get_h_data ( 	( pthis )->inoutput , 	& ( tmp_h_data ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_get_h_data ( 	( pthis )->inoutput , 	& ( tmp_h_data ) );

	}else{
		0;

	 }

	 }
	memset ( tmp_h_data , 0 , 	(  sizeof(double ) * 	(  6 * 	(  grid_cache_len * 	(  xlen * 	(  ylen * 	(  zlen * numvec ) ) ) ) ) ) );
}{
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_init ( pe , 	( pthis )->xyzw , PS_INT_NUM , 	(  4 * 	(  xlen * 	(  ylen * 	(  zlen * numvec ) ) ) ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_init ( pe , 	( pthis )->xyzw , PS_INT_NUM , 	(  4 * 	(  xlen * 	(  ylen * 	(  zlen * numvec ) ) ) ) );

	}else{
		0;

	 }

	 }
	char *  tmp_h_data ;
	if (  	(  0 == CD_type )  ){  
			c_pscmc_get_h_data ( 	( pthis )->xyzw , 	& ( tmp_h_data ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_get_h_data ( 	( pthis )->xyzw , 	& ( tmp_h_data ) );

	}else{
		0;

	 }

	 }
	memset ( tmp_h_data , 0 , 	(  sizeof(int ) * 	(  4 * 	(  xlen * 	(  ylen * 	(  zlen * numvec ) ) ) ) ) );
}{
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_init ( pe , 	( pthis )->cu_cache , PS_DOUBLE_NUM , 	(  6 * 	(  cu_cache_length * numvec ) ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_init ( pe , 	( pthis )->cu_cache , PS_DOUBLE_NUM , 	(  6 * 	(  cu_cache_length * numvec ) ) );

	}else{
		0;

	 }

	 }
	char *  tmp_h_data ;
	if (  	(  0 == CD_type )  ){  
			c_pscmc_get_h_data ( 	( pthis )->cu_cache , 	& ( tmp_h_data ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_get_h_data ( 	( pthis )->cu_cache , 	& ( tmp_h_data ) );

	}else{
		0;

	 }

	 }
	memset ( tmp_h_data , 0 , 	(  sizeof(double ) * 	(  6 * 	(  cu_cache_length * numvec ) ) ) );
}{
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_init ( pe , 	( pthis )->cu_xyzw , PS_INT_NUM , 	(  numvec * 4 ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_init ( pe , 	( pthis )->cu_xyzw , PS_INT_NUM , 	(  numvec * 4 ) );

	}else{
		0;

	 }

	 }
	char *  tmp_h_data ;
	if (  	(  0 == CD_type )  ){  
			c_pscmc_get_h_data ( 	( pthis )->cu_xyzw , 	& ( tmp_h_data ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_get_h_data ( 	( pthis )->cu_xyzw , 	& ( tmp_h_data ) );

	}else{
		0;

	 }

	 }
	memset ( tmp_h_data , 0 , 	(  sizeof(int ) * 	(  numvec * 4 ) ) );
}{
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_init ( pe , 	( pthis )->adjoint_vec_pids , PS_LONG_NUM , 	(  numvec * 6 ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_init ( pe , 	( pthis )->adjoint_vec_pids , PS_LONG_NUM , 	(  numvec * 6 ) );

	}else{
		0;

	 }

	 }
	char *  tmp_h_data ;
	if (  	(  0 == CD_type )  ){  
			c_pscmc_get_h_data ( 	( pthis )->adjoint_vec_pids , 	& ( tmp_h_data ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_get_h_data ( 	( pthis )->adjoint_vec_pids , 	& ( tmp_h_data ) );

	}else{
		0;

	 }

	 }
	memset ( tmp_h_data , 0 , 	(  sizeof(long ) * 	(  numvec * 6 ) ) );
}{
	Field3D_Seq *  pfield = 	( pthis )->pfield ;
	Field3D_Seq *  pfieldE = 	( pthis )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( pthis )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( pthis )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( pthis )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( pthis )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( pthis )->pFoutEN ;
	void * *  sort_kernel = 	( pthis )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( pthis )->geo_rel_1st_kernel ;
	void * *  rel_1st_kernel = 	( pthis )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( pthis )->krook_collision_test_kernel ;
	void * *  boris_yee_kernel = 	( pthis )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( pthis )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( pthis )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( pthis )->move_back_kernel_kernel ;
	double  Mass = 	( pthis )->Mass ;
	double  Charge = 	( pthis )->Charge ;
	double  Number_particle_per_marker = 	( pthis )->Number_particle_per_marker ;
	long  grid_cache_len = 	( pthis )->grid_cache_len ;
	long  cu_cache_length = 	( pthis )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( pthis )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( pthis )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( pthis )->split_pass_z_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( pthis )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( pthis )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( pthis )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( pthis )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( pthis )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( pthis )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( pthis )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( pthis )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( pthis )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( pthis )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( pthis )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( pthis )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( pthis )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( pthis )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( pthis )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( pthis )->calculate_rho_kernel ;
	void *  inoutput = 	( pthis )->inoutput ;
	void *  xyzw = 	( pthis )->xyzw ;
	void *  cu_cache = 	( pthis )->cu_cache ;
	void *  cu_xyzw = 	( pthis )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( pthis )->adjoint_vec_pids ;
	long *  adjoint_vec_pids_host = (((long * * )adjoint_vec_pids))[0] ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 1 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 1 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < numvec ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long *  cur_adj_id = 	(  adjoint_vec_pids_host + 	(  6 * xyzx ) ) ;
((cur_adj_id)[0] = 	find_vec_id ( (adj_ids)[	(  	(  xyzx * NUM_SYNC_LAYER ) + 	(  0 + 	(  1 * 	(  0 + 	(  3 * 	(  1 + 	(  3 * 1 ) ) ) ) ) ) )] , adj_ids , numvec ));
((cur_adj_id)[1] = 	find_vec_id ( (adj_ids)[	(  	(  xyzx * NUM_SYNC_LAYER ) + 	(  0 + 	(  1 * 	(  2 + 	(  3 * 	(  1 + 	(  3 * 1 ) ) ) ) ) ) )] , adj_ids , numvec ));
((cur_adj_id)[2] = 	find_vec_id ( (adj_ids)[	(  	(  xyzx * NUM_SYNC_LAYER ) + 	(  0 + 	(  1 * 	(  1 + 	(  3 * 	(  0 + 	(  3 * 1 ) ) ) ) ) ) )] , adj_ids , numvec ));
((cur_adj_id)[3] = 	find_vec_id ( (adj_ids)[	(  	(  xyzx * NUM_SYNC_LAYER ) + 	(  0 + 	(  1 * 	(  1 + 	(  3 * 	(  2 + 	(  3 * 1 ) ) ) ) ) ) )] , adj_ids , numvec ));
((cur_adj_id)[4] = 	find_vec_id ( (adj_ids)[	(  	(  xyzx * NUM_SYNC_LAYER ) + 	(  0 + 	(  1 * 	(  1 + 	(  3 * 	(  1 + 	(  3 * 0 ) ) ) ) ) ) )] , adj_ids , numvec ));
((cur_adj_id)[5] = 	find_vec_id ( (adj_ids)[	(  	(  xyzx * NUM_SYNC_LAYER ) + 	(  0 + 	(  1 * 	(  1 + 	(  3 * 	(  1 + 	(  3 * 2 ) ) ) ) ) ) )] , adj_ids , numvec ));
}}}}}}	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( adjoint_vec_pids );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( adjoint_vec_pids );

	}else{
		0;

	 }

	 }
}}	return  0 ;}
int  delete_particle (One_Particle_Collection *  pthis ){
	Field3D_Seq *  pfield = 	( pthis )->pfield ;
	Field3D_Seq *  pfieldE = 	( pthis )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( pthis )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( pthis )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( pthis )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( pthis )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( pthis )->pFoutEN ;
	void * *  sort_kernel = 	( pthis )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( pthis )->geo_rel_1st_kernel ;
	void * *  rel_1st_kernel = 	( pthis )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( pthis )->krook_collision_test_kernel ;
	void * *  boris_yee_kernel = 	( pthis )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( pthis )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( pthis )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( pthis )->move_back_kernel_kernel ;
	double  Mass = 	( pthis )->Mass ;
	double  Charge = 	( pthis )->Charge ;
	double  Number_particle_per_marker = 	( pthis )->Number_particle_per_marker ;
	long  grid_cache_len = 	( pthis )->grid_cache_len ;
	long  cu_cache_length = 	( pthis )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( pthis )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( pthis )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( pthis )->split_pass_z_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( pthis )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( pthis )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( pthis )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( pthis )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( pthis )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( pthis )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( pthis )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( pthis )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( pthis )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( pthis )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( pthis )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( pthis )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( pthis )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( pthis )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( pthis )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( pthis )->calculate_rho_kernel ;
	void *  inoutput = 	( pthis )->inoutput ;
	void *  xyzw = 	( pthis )->xyzw ;
	void *  cu_cache = 	( pthis )->cu_cache ;
	void *  cu_xyzw = 	( pthis )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( pthis )->adjoint_vec_pids ;
	void *  pe = 	( pfield )->pe ;
	long  xlen = 	( pfield )->xlen ;
	long  ylen = 	( pfield )->ylen ;
	long  zlen = 	( pfield )->zlen ;
	long  xblock = 	( pfield )->xblock ;
	long  yblock = 	( pfield )->yblock ;
	long  zblock = 	( pfield )->zblock ;
	long  numvec = 	( pfield )->numvec ;
	long  x_num_thread_block = 	( pfield )->x_num_thread_block ;
	long  y_num_thread_block = 	( pfield )->y_num_thread_block ;
	long  z_num_thread_block = 	( pfield )->z_num_thread_block ;
	int  ovlp = 	( pfield )->ovlp ;
	int  num_ele = 	( pfield )->num_ele ;
	int  CD_type = 	( pfield )->CD_type ;
	void * *  sync_layer_pscmc = 	( pfield )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( pfield )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( pfield )->sync_kernels ;
	void * *  fdtd_kernels = 	( pfield )->fdtd_kernels ;
	void * *  dm_kernels = 	( pfield )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pfield )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pfield )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( pfield )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pfield )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pfield )->yee_damp_kernels ;
	void *  rdcd = 	( pfield )->rdcd ;
	double *  rdcd_host = 	( pfield )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( pfield )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( pfield )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( pfield )->cur_rankz_pscmc ;
	void *  xoffset = 	( pfield )->xoffset ;
	void *  yoffset = 	( pfield )->yoffset ;
	void *  zoffset = 	( pfield )->zoffset ;
	long *  global_x_offset = 	( pfield )->global_x_offset ;
	long *  global_y_offset = 	( pfield )->global_y_offset ;
	long *  global_z_offset = 	( pfield )->global_z_offset ;
	long *  global_id = 	( pfield )->global_id ;
	long  global_pid = 	( pfield )->global_pid ;
	long *  adj_ids = 	( pfield )->adj_ids ;
	long *  adj_processes = 	( pfield )->adj_processes ;
	long *  adj_local_tid = 	( pfield )->adj_local_tid ;
	void *  main_data = 	( pfield )->main_data ;
	double  delta_x = 	( pfield )->delta_x ;
	double  delta_y = 	( pfield )->delta_y ;
	double  delta_z = 	( pfield )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( pfield )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( pfield )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( pfield )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( pfield )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( pfield )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( pfield )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( pfield )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( pfield )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( pfield )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( pfield )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( pfield )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( pfield )->blas_sum_kernel ;
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_destroy ( inoutput );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_destroy ( inoutput );

	}else{
		0;

	 }

	 }
	free ( inoutput );
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_destroy ( xyzw );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_destroy ( xyzw );

	}else{
		0;

	 }

	 }
	free ( xyzw );
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_destroy ( cu_cache );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_destroy ( cu_cache );

	}else{
		0;

	 }

	 }
	free ( cu_cache );
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_destroy ( cu_xyzw );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_destroy ( cu_xyzw );

	}else{
		0;

	 }

	 }
	free ( cu_xyzw );
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_destroy ( adjoint_vec_pids );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_destroy ( adjoint_vec_pids );

	}else{
		0;

	 }

	 }
	free ( adjoint_vec_pids );
	int  i ;
	for (i=0 ; i<3 ; i++)
	{
	free ( (sort_kernel)[i] );
}	return  0 ;}
int  init_particle_mpi (Field3D_MPI *  pthis ,int  num_spec ,double *  Mass ,double *  Charge ,double *  Number_particle_per_marker ,long *  grid_cache_len ,long *  cu_cache_length ){
(	( pthis )->num_spec = num_spec);
	long  num_runtime = 	( pthis )->num_runtime ;
(	( pthis )->particles = 	malloc ( 	(  sizeof(One_Particle_Collection ) * 	(  num_spec * num_runtime ) ) ));
	int  i ;
	int  j ;
	for (i=0 ; 	(  i < num_spec ) ; i++)
	{
	for (j=0 ; 	(  j < num_runtime ) ; j++)
	{
	void *  pe = 	( 	(  	( pthis )->data + j ) )->pe ;
	long  xlen = 	( 	(  	( pthis )->data + j ) )->xlen ;
	long  ylen = 	( 	(  	( pthis )->data + j ) )->ylen ;
	long  zlen = 	( 	(  	( pthis )->data + j ) )->zlen ;
	long  xblock = 	( 	(  	( pthis )->data + j ) )->xblock ;
	long  yblock = 	( 	(  	( pthis )->data + j ) )->yblock ;
	long  zblock = 	( 	(  	( pthis )->data + j ) )->zblock ;
	long  numvec = 	( 	(  	( pthis )->data + j ) )->numvec ;
	long  x_num_thread_block = 	( 	(  	( pthis )->data + j ) )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	(  	( pthis )->data + j ) )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	(  	( pthis )->data + j ) )->z_num_thread_block ;
	int  ovlp = 	( 	(  	( pthis )->data + j ) )->ovlp ;
	int  num_ele = 	( 	(  	( pthis )->data + j ) )->num_ele ;
	int  CD_type = 	( 	(  	( pthis )->data + j ) )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	(  	( pthis )->data + j ) )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	(  	( pthis )->data + j ) )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	(  	( pthis )->data + j ) )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	(  	( pthis )->data + j ) )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	(  	( pthis )->data + j ) )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  	( pthis )->data + j ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  	( pthis )->data + j ) )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( 	(  	( pthis )->data + j ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  	( pthis )->data + j ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  	( pthis )->data + j ) )->yee_damp_kernels ;
	void *  rdcd = 	( 	(  	( pthis )->data + j ) )->rdcd ;
	double *  rdcd_host = 	( 	(  	( pthis )->data + j ) )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	(  	( pthis )->data + j ) )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	(  	( pthis )->data + j ) )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	(  	( pthis )->data + j ) )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	(  	( pthis )->data + j ) )->xoffset ;
	void *  yoffset = 	( 	(  	( pthis )->data + j ) )->yoffset ;
	void *  zoffset = 	( 	(  	( pthis )->data + j ) )->zoffset ;
	long *  global_x_offset = 	( 	(  	( pthis )->data + j ) )->global_x_offset ;
	long *  global_y_offset = 	( 	(  	( pthis )->data + j ) )->global_y_offset ;
	long *  global_z_offset = 	( 	(  	( pthis )->data + j ) )->global_z_offset ;
	long *  global_id = 	( 	(  	( pthis )->data + j ) )->global_id ;
	long  global_pid = 	( 	(  	( pthis )->data + j ) )->global_pid ;
	long *  adj_ids = 	( 	(  	( pthis )->data + j ) )->adj_ids ;
	long *  adj_processes = 	( 	(  	( pthis )->data + j ) )->adj_processes ;
	long *  adj_local_tid = 	( 	(  	( pthis )->data + j ) )->adj_local_tid ;
	void *  main_data = 	( 	(  	( pthis )->data + j ) )->main_data ;
	double  delta_x = 	( 	(  	( pthis )->data + j ) )->delta_x ;
	double  delta_y = 	( 	(  	( pthis )->data + j ) )->delta_y ;
	double  delta_z = 	( 	(  	( pthis )->data + j ) )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	(  	( pthis )->data + j ) )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( 	(  	( pthis )->data + j ) )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	(  	( pthis )->data + j ) )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	(  	( pthis )->data + j ) )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	(  	( pthis )->data + j ) )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	(  	( pthis )->data + j ) )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	(  	( pthis )->data + j ) )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	(  	( pthis )->data + j ) )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	(  	( pthis )->data + j ) )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	(  	( pthis )->data + j ) )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	(  	( pthis )->data + j ) )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	(  	( pthis )->data + j ) )->blas_sum_kernel ;
	init_particle ( 	(  	( pthis )->particles + 	(  	(  i * num_runtime ) + j ) ) , 	(  	( pthis )->data + j ) , (Mass)[i] , (Charge)[i] , (Number_particle_per_marker)[i] , 	(  (grid_cache_len)[i] * ((USE_NON_UNI_CACHE_DIST)?(({
	double  cplx = 0.00000000000000000e+00 ;
{
	long  k ;
	for ((k = 0) ; 	(  k < numvec ) ; (k = 	(  k + 1 )))
	{
	double  new_cplx = 	call_GET_NON_UNI_CACHE_DIST ( i , (global_id)[k] ) ;
	if (  	(  new_cplx > cplx )  ){  
		(cplx = new_cplx);

	}else{
		0;

	 }
}}cplx;
})):(1)) ) , 	(  (cu_cache_length)[i] * ((USE_NON_UNI_CACHE_DIST)?(({
	double  cplx = 0.00000000000000000e+00 ;
{
	long  k ;
	for ((k = 0) ; 	(  k < numvec ) ; (k = 	(  k + 1 )))
	{
	double  new_cplx = 	call_GET_NON_UNI_CACHE_DIST ( i , (global_id)[k] ) ;
	if (  	(  new_cplx > cplx )  ){  
		(cplx = new_cplx);

	}else{
		0;

	 }
}}cplx;
})):(1)) ) );
}}	return  0 ;}
int  generate_random_particle_mpi (Field3D_MPI *  pthis ){
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
	int  i ;
	int  j ;
	for (i=0 ; 	(  i < num_spec ) ; i++)
	{
	for (j=0 ; 	(  j < num_runtime ) ; j++)
	{
	generate_random_self_particle ( 	(  	( pthis )->particles + 	(  	(  i * num_runtime ) + j ) ) );
}}	return  0 ;}
int  delete_particle_mpi (Field3D_MPI *  pthis ){
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
	int  i ;
	int  j ;
	for (i=0 ; 	(  i < num_spec ) ; i++)
	{
	for (j=0 ; 	(  j < num_runtime ) ; j++)
	{
	delete_particle ( 	(  	( pthis )->particles + 	(  	(  i * num_runtime ) + j ) ) );
}}	free ( 	( pthis )->particles );
	return  0 ;}
int  generate_random_self_particle (One_Particle_Collection *  pthis ){
	Field3D_Seq *  pfield = 	( pthis )->pfield ;
	Field3D_Seq *  pfieldE = 	( pthis )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( pthis )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( pthis )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( pthis )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( pthis )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( pthis )->pFoutEN ;
	void * *  sort_kernel = 	( pthis )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( pthis )->geo_rel_1st_kernel ;
	void * *  rel_1st_kernel = 	( pthis )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( pthis )->krook_collision_test_kernel ;
	void * *  boris_yee_kernel = 	( pthis )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( pthis )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( pthis )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( pthis )->move_back_kernel_kernel ;
	double  Mass = 	( pthis )->Mass ;
	double  Charge = 	( pthis )->Charge ;
	double  Number_particle_per_marker = 	( pthis )->Number_particle_per_marker ;
	long  grid_cache_len = 	( pthis )->grid_cache_len ;
	long  cu_cache_length = 	( pthis )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( pthis )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( pthis )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( pthis )->split_pass_z_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( pthis )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( pthis )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( pthis )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( pthis )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( pthis )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( pthis )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( pthis )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( pthis )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( pthis )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( pthis )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( pthis )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( pthis )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( pthis )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( pthis )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( pthis )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( pthis )->calculate_rho_kernel ;
	void *  inoutput = 	( pthis )->inoutput ;
	void *  xyzw = 	( pthis )->xyzw ;
	void *  cu_cache = 	( pthis )->cu_cache ;
	void *  cu_xyzw = 	( pthis )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( pthis )->adjoint_vec_pids ;
{
	Field3D_Seq *  pfield = 	( pthis )->pfield ;
	Field3D_Seq *  pfieldE = 	( pthis )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( pthis )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( pthis )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( pthis )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( pthis )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( pthis )->pFoutEN ;
	void * *  sort_kernel = 	( pthis )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( pthis )->geo_rel_1st_kernel ;
	void * *  rel_1st_kernel = 	( pthis )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( pthis )->krook_collision_test_kernel ;
	void * *  boris_yee_kernel = 	( pthis )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( pthis )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( pthis )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( pthis )->move_back_kernel_kernel ;
	double  Mass = 	( pthis )->Mass ;
	double  Charge = 	( pthis )->Charge ;
	double  Number_particle_per_marker = 	( pthis )->Number_particle_per_marker ;
	long  grid_cache_len = 	( pthis )->grid_cache_len ;
	long  cu_cache_length = 	( pthis )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( pthis )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( pthis )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( pthis )->split_pass_z_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( pthis )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( pthis )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( pthis )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( pthis )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( pthis )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( pthis )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( pthis )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( pthis )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( pthis )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( pthis )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( pthis )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( pthis )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( pthis )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( pthis )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( pthis )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( pthis )->calculate_rho_kernel ;
	void *  inoutput = 	( pthis )->inoutput ;
	void *  xyzw = 	( pthis )->xyzw ;
	void *  cu_cache = 	( pthis )->cu_cache ;
	void *  cu_xyzw = 	( pthis )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( pthis )->adjoint_vec_pids ;
	void *  pe = 	( pfield )->pe ;
	long  xlen = 	( pfield )->xlen ;
	long  ylen = 	( pfield )->ylen ;
	long  zlen = 	( pfield )->zlen ;
	long  xblock = 	( pfield )->xblock ;
	long  yblock = 	( pfield )->yblock ;
	long  zblock = 	( pfield )->zblock ;
	long  numvec = 	( pfield )->numvec ;
	long  x_num_thread_block = 	( pfield )->x_num_thread_block ;
	long  y_num_thread_block = 	( pfield )->y_num_thread_block ;
	long  z_num_thread_block = 	( pfield )->z_num_thread_block ;
	int  ovlp = 	( pfield )->ovlp ;
	int  num_ele = 	( pfield )->num_ele ;
	int  CD_type = 	( pfield )->CD_type ;
	void * *  sync_layer_pscmc = 	( pfield )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( pfield )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( pfield )->sync_kernels ;
	void * *  fdtd_kernels = 	( pfield )->fdtd_kernels ;
	void * *  dm_kernels = 	( pfield )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pfield )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pfield )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( pfield )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pfield )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pfield )->yee_damp_kernels ;
	void *  rdcd = 	( pfield )->rdcd ;
	double *  rdcd_host = 	( pfield )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( pfield )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( pfield )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( pfield )->cur_rankz_pscmc ;
	void *  xoffset = 	( pfield )->xoffset ;
	void *  yoffset = 	( pfield )->yoffset ;
	void *  zoffset = 	( pfield )->zoffset ;
	long *  global_x_offset = 	( pfield )->global_x_offset ;
	long *  global_y_offset = 	( pfield )->global_y_offset ;
	long *  global_z_offset = 	( pfield )->global_z_offset ;
	long *  global_id = 	( pfield )->global_id ;
	long  global_pid = 	( pfield )->global_pid ;
	long *  adj_ids = 	( pfield )->adj_ids ;
	long *  adj_processes = 	( pfield )->adj_processes ;
	long *  adj_local_tid = 	( pfield )->adj_local_tid ;
	void *  main_data = 	( pfield )->main_data ;
	double  delta_x = 	( pfield )->delta_x ;
	double  delta_y = 	( pfield )->delta_y ;
	double  delta_z = 	( pfield )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( pfield )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( pfield )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( pfield )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( pfield )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( pfield )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( pfield )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( pfield )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( pfield )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( pfield )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( pfield )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( pfield )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( pfield )->blas_sum_kernel ;
	long  alllenoff = 	(  xlen * 	(  ylen * zlen ) ) ;
	long  cur_pcid ;
	double *  host_data = (((double * * )inoutput))[0] ;
	int *  xyzw_data = (((int * * )xyzw))[0] ;
	fprintf ( stderr , "xyzw=0x%x\n" , xyzw_data );
	for (cur_pcid=0 ; 	(  cur_pcid < numvec ) ; cur_pcid++)
	{
	double *  grid_r_0 = 	(  host_data + 	(  cur_pcid * 	(  alllenoff * 	(  6 * grid_cache_len ) ) ) ) ;
	int *  xyzw_0 = 	(  xyzw_data + 	(  cur_pcid * 	(  alllenoff * 4 ) ) ) ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < zlen ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < ylen ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < xlen ) ; (xyzx = 	(  xyzx + 1 )))
	{
	double *  grid_r = 	(  grid_r_0 + 	(  0 + 	(  	(  6 * grid_cache_len ) * 	(  xyzx + 	(  xlen * 	(  xyzy + 	(  ylen * xyzz ) ) ) ) ) ) ) ;
	int *  grid_xyzw = 	(  xyzw_0 + 	(  0 + 	(  4 * 	(  xyzx + 	(  xlen * 	(  xyzy + 	(  ylen * xyzz ) ) ) ) ) ) ) ;
	long  l = 0 ;
	int  load = 	(  grid_cache_len * 8.00000000000000044e-01 ) ;
	for (l ; 	(  l < load ) ; l++)
	{
	double *  xyzvs = 	(  grid_r + 	(  l * 6 ) ) ;
((xyzvs)[0] = 	rand01 ( 	(  xyzx - 1 ) , 	(  xyzx + 2 ) ));
((xyzvs)[1] = 	rand01 ( 	(  xyzy - 1 ) , 	(  xyzy + 2 ) ));
((xyzvs)[2] = 	rand01 ( 	(  xyzz - 1 ) , 	(  xyzz + 2 ) ));
((xyzvs)[3] = 0);
((xyzvs)[4] = 0);
((xyzvs)[5] = 0);
}((grid_xyzw)[0] = load);
}}}}}}}}{
	void *  pe = 	( pfield )->pe ;
	long  xlen = 	( pfield )->xlen ;
	long  ylen = 	( pfield )->ylen ;
	long  zlen = 	( pfield )->zlen ;
	long  xblock = 	( pfield )->xblock ;
	long  yblock = 	( pfield )->yblock ;
	long  zblock = 	( pfield )->zblock ;
	long  numvec = 	( pfield )->numvec ;
	long  x_num_thread_block = 	( pfield )->x_num_thread_block ;
	long  y_num_thread_block = 	( pfield )->y_num_thread_block ;
	long  z_num_thread_block = 	( pfield )->z_num_thread_block ;
	int  ovlp = 	( pfield )->ovlp ;
	int  num_ele = 	( pfield )->num_ele ;
	int  CD_type = 	( pfield )->CD_type ;
	void * *  sync_layer_pscmc = 	( pfield )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( pfield )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( pfield )->sync_kernels ;
	void * *  fdtd_kernels = 	( pfield )->fdtd_kernels ;
	void * *  dm_kernels = 	( pfield )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pfield )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pfield )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( pfield )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pfield )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pfield )->yee_damp_kernels ;
	void *  rdcd = 	( pfield )->rdcd ;
	double *  rdcd_host = 	( pfield )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( pfield )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( pfield )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( pfield )->cur_rankz_pscmc ;
	void *  xoffset = 	( pfield )->xoffset ;
	void *  yoffset = 	( pfield )->yoffset ;
	void *  zoffset = 	( pfield )->zoffset ;
	long *  global_x_offset = 	( pfield )->global_x_offset ;
	long *  global_y_offset = 	( pfield )->global_y_offset ;
	long *  global_z_offset = 	( pfield )->global_z_offset ;
	long *  global_id = 	( pfield )->global_id ;
	long  global_pid = 	( pfield )->global_pid ;
	long *  adj_ids = 	( pfield )->adj_ids ;
	long *  adj_processes = 	( pfield )->adj_processes ;
	long *  adj_local_tid = 	( pfield )->adj_local_tid ;
	void *  main_data = 	( pfield )->main_data ;
	double  delta_x = 	( pfield )->delta_x ;
	double  delta_y = 	( pfield )->delta_y ;
	double  delta_z = 	( pfield )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( pfield )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( pfield )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( pfield )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( pfield )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( pfield )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( pfield )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( pfield )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( pfield )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( pfield )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( pfield )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( pfield )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( pfield )->blas_sum_kernel ;
	memset ( (((int * * )cu_xyzw))[0] , 0 , 	(  4 * 	(  sizeof(int ) * numvec ) ) );
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( inoutput );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( inoutput );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( xyzw );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( xyzw );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( cu_xyzw );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( cu_xyzw );

	}else{
		0;

	 }

	 }
}	return  0 ;}
int  init_maxwell_dist_particle_opc (One_Particle_Collection *  pthis ,int  tgrid_load ,double  VT ,int  use_lost_cone ,double  mu0 ,double  delta ){
	Field3D_Seq *  pfield = 	( pthis )->pfield ;
	Field3D_Seq *  pfieldE = 	( pthis )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( pthis )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( pthis )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( pthis )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( pthis )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( pthis )->pFoutEN ;
	void * *  sort_kernel = 	( pthis )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( pthis )->geo_rel_1st_kernel ;
	void * *  rel_1st_kernel = 	( pthis )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( pthis )->krook_collision_test_kernel ;
	void * *  boris_yee_kernel = 	( pthis )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( pthis )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( pthis )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( pthis )->move_back_kernel_kernel ;
	double  Mass = 	( pthis )->Mass ;
	double  Charge = 	( pthis )->Charge ;
	double  Number_particle_per_marker = 	( pthis )->Number_particle_per_marker ;
	long  grid_cache_len = 	( pthis )->grid_cache_len ;
	long  cu_cache_length = 	( pthis )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( pthis )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( pthis )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( pthis )->split_pass_z_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( pthis )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( pthis )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( pthis )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( pthis )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( pthis )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( pthis )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( pthis )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( pthis )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( pthis )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( pthis )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( pthis )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( pthis )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( pthis )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( pthis )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( pthis )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( pthis )->calculate_rho_kernel ;
	void *  inoutput = 	( pthis )->inoutput ;
	void *  xyzw = 	( pthis )->xyzw ;
	void *  cu_cache = 	( pthis )->cu_cache ;
	void *  cu_xyzw = 	( pthis )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( pthis )->adjoint_vec_pids ;
{
	Field3D_Seq *  pfield = 	( pthis )->pfield ;
	Field3D_Seq *  pfieldE = 	( pthis )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( pthis )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( pthis )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( pthis )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( pthis )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( pthis )->pFoutEN ;
	void * *  sort_kernel = 	( pthis )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( pthis )->geo_rel_1st_kernel ;
	void * *  rel_1st_kernel = 	( pthis )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( pthis )->krook_collision_test_kernel ;
	void * *  boris_yee_kernel = 	( pthis )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( pthis )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( pthis )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( pthis )->move_back_kernel_kernel ;
	double  Mass = 	( pthis )->Mass ;
	double  Charge = 	( pthis )->Charge ;
	double  Number_particle_per_marker = 	( pthis )->Number_particle_per_marker ;
	long  grid_cache_len = 	( pthis )->grid_cache_len ;
	long  cu_cache_length = 	( pthis )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( pthis )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( pthis )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( pthis )->split_pass_z_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( pthis )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( pthis )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( pthis )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( pthis )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( pthis )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( pthis )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( pthis )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( pthis )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( pthis )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( pthis )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( pthis )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( pthis )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( pthis )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( pthis )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( pthis )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( pthis )->calculate_rho_kernel ;
	void *  inoutput = 	( pthis )->inoutput ;
	void *  xyzw = 	( pthis )->xyzw ;
	void *  cu_cache = 	( pthis )->cu_cache ;
	void *  cu_xyzw = 	( pthis )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( pthis )->adjoint_vec_pids ;
	void *  pe = 	( pfield )->pe ;
	long  xlen = 	( pfield )->xlen ;
	long  ylen = 	( pfield )->ylen ;
	long  zlen = 	( pfield )->zlen ;
	long  xblock = 	( pfield )->xblock ;
	long  yblock = 	( pfield )->yblock ;
	long  zblock = 	( pfield )->zblock ;
	long  numvec = 	( pfield )->numvec ;
	long  x_num_thread_block = 	( pfield )->x_num_thread_block ;
	long  y_num_thread_block = 	( pfield )->y_num_thread_block ;
	long  z_num_thread_block = 	( pfield )->z_num_thread_block ;
	int  ovlp = 	( pfield )->ovlp ;
	int  num_ele = 	( pfield )->num_ele ;
	int  CD_type = 	( pfield )->CD_type ;
	void * *  sync_layer_pscmc = 	( pfield )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( pfield )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( pfield )->sync_kernels ;
	void * *  fdtd_kernels = 	( pfield )->fdtd_kernels ;
	void * *  dm_kernels = 	( pfield )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pfield )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pfield )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( pfield )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pfield )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pfield )->yee_damp_kernels ;
	void *  rdcd = 	( pfield )->rdcd ;
	double *  rdcd_host = 	( pfield )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( pfield )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( pfield )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( pfield )->cur_rankz_pscmc ;
	void *  xoffset = 	( pfield )->xoffset ;
	void *  yoffset = 	( pfield )->yoffset ;
	void *  zoffset = 	( pfield )->zoffset ;
	long *  global_x_offset = 	( pfield )->global_x_offset ;
	long *  global_y_offset = 	( pfield )->global_y_offset ;
	long *  global_z_offset = 	( pfield )->global_z_offset ;
	long *  global_id = 	( pfield )->global_id ;
	long  global_pid = 	( pfield )->global_pid ;
	long *  adj_ids = 	( pfield )->adj_ids ;
	long *  adj_processes = 	( pfield )->adj_processes ;
	long *  adj_local_tid = 	( pfield )->adj_local_tid ;
	void *  main_data = 	( pfield )->main_data ;
	double  delta_x = 	( pfield )->delta_x ;
	double  delta_y = 	( pfield )->delta_y ;
	double  delta_z = 	( pfield )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( pfield )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( pfield )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( pfield )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( pfield )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( pfield )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( pfield )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( pfield )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( pfield )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( pfield )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( pfield )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( pfield )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( pfield )->blas_sum_kernel ;
	long  alllenoff = 	(  xlen * 	(  ylen * zlen ) ) ;
	long  cur_pcid ;
	double *  host_data = (((double * * )inoutput))[0] ;
	int *  xyzw_data = (((int * * )xyzw))[0] ;
	fprintf ( stderr , "xyzw=0x%x\n" , xyzw_data );
	for (cur_pcid=0 ; 	(  cur_pcid < numvec ) ; cur_pcid++)
	{
	double *  grid_r_0 = 	(  host_data + 	(  cur_pcid * 	(  alllenoff * 	(  6 * grid_cache_len ) ) ) ) ;
	int *  xyzw_0 = 	(  xyzw_data + 	(  cur_pcid * 	(  alllenoff * 4 ) ) ) ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < zlen ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < ylen ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < xlen ) ; (xyzx = 	(  xyzx + 1 )))
	{
	double *  grid_r = 	(  grid_r_0 + 	(  0 + 	(  	(  6 * grid_cache_len ) * 	(  xyzx + 	(  xlen * 	(  xyzy + 	(  ylen * xyzz ) ) ) ) ) ) ) ;
	int *  grid_xyzw = 	(  xyzw_0 + 	(  0 + 	(  4 * 	(  xyzx + 	(  xlen * 	(  xyzy + 	(  ylen * xyzz ) ) ) ) ) ) ) ;
	long  l = 0 ;
	long  grid_load = tgrid_load ;
	if (  	(  grid_load > grid_cache_len )  ){  
			fprintf ( stderr , "Error, gl=%d gcl=%d global_id=%d cur_picid=%d\n" , grid_load , grid_cache_len , (global_id)[cur_pcid] , cur_pcid );

	}else{
		0;

	 }
	assert ( 	(  grid_load <= grid_cache_len ) );
	for (l ; 	(  l < grid_load ) ; l++)
	{
((grid_xyzw)[0] = grid_load);
	double *  xyzvs = 	(  grid_r + 	(  l * 6 ) ) ;
((xyzvs)[0] = 	rand01 ( xyzx , 	(  xyzx + 1 ) ));
((xyzvs)[1] = 	rand01 ( xyzy , 	(  xyzy + 1 ) ));
((xyzvs)[2] = 	rand01 ( xyzz , 	(  xyzz + 1 ) ));
	befmaxinit:
((xyzvs)[3] = 	maxwell_dist ( 0 , VT ));
((xyzvs)[4] = 	maxwell_dist ( 0 , VT ));
((xyzvs)[5] = 	maxwell_dist ( 0 , VT ));
	double  vx = (xyzvs)[3] ;
	double  vy = (xyzvs)[4] ;
	double  vz = (xyzvs)[5] ;
	if (  	(  	(  	(  	(  vx * vx ) + 	(  vy * vy ) ) + 	(  vz * vz ) ) >= 1 )  ){  
			goto befmaxinit;
	}else{
		0;

	 }
	if (  use_lost_cone  ){  
			double  vall = 	sqrt ( 	(  	pow ( vx , 2 ) + 	(  	pow ( vy , 2 ) + 	pow ( vz , 2 ) ) ) ) ;
	double  mu = 	(  vx / vall ) ;
	if (  	(  ! 	lost_cone_dist ( mu , mu0 , delta ) )  ){  
			goto befmaxinit;
	}else{
		0;

	 }

	}else{
		0;

	 }
}}}}}}}}}{
	void *  pe = 	( pfield )->pe ;
	long  xlen = 	( pfield )->xlen ;
	long  ylen = 	( pfield )->ylen ;
	long  zlen = 	( pfield )->zlen ;
	long  xblock = 	( pfield )->xblock ;
	long  yblock = 	( pfield )->yblock ;
	long  zblock = 	( pfield )->zblock ;
	long  numvec = 	( pfield )->numvec ;
	long  x_num_thread_block = 	( pfield )->x_num_thread_block ;
	long  y_num_thread_block = 	( pfield )->y_num_thread_block ;
	long  z_num_thread_block = 	( pfield )->z_num_thread_block ;
	int  ovlp = 	( pfield )->ovlp ;
	int  num_ele = 	( pfield )->num_ele ;
	int  CD_type = 	( pfield )->CD_type ;
	void * *  sync_layer_pscmc = 	( pfield )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( pfield )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( pfield )->sync_kernels ;
	void * *  fdtd_kernels = 	( pfield )->fdtd_kernels ;
	void * *  dm_kernels = 	( pfield )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pfield )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pfield )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( pfield )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pfield )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pfield )->yee_damp_kernels ;
	void *  rdcd = 	( pfield )->rdcd ;
	double *  rdcd_host = 	( pfield )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( pfield )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( pfield )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( pfield )->cur_rankz_pscmc ;
	void *  xoffset = 	( pfield )->xoffset ;
	void *  yoffset = 	( pfield )->yoffset ;
	void *  zoffset = 	( pfield )->zoffset ;
	long *  global_x_offset = 	( pfield )->global_x_offset ;
	long *  global_y_offset = 	( pfield )->global_y_offset ;
	long *  global_z_offset = 	( pfield )->global_z_offset ;
	long *  global_id = 	( pfield )->global_id ;
	long  global_pid = 	( pfield )->global_pid ;
	long *  adj_ids = 	( pfield )->adj_ids ;
	long *  adj_processes = 	( pfield )->adj_processes ;
	long *  adj_local_tid = 	( pfield )->adj_local_tid ;
	void *  main_data = 	( pfield )->main_data ;
	double  delta_x = 	( pfield )->delta_x ;
	double  delta_y = 	( pfield )->delta_y ;
	double  delta_z = 	( pfield )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( pfield )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( pfield )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( pfield )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( pfield )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( pfield )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( pfield )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( pfield )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( pfield )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( pfield )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( pfield )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( pfield )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( pfield )->blas_sum_kernel ;
	memset ( (((int * * )cu_xyzw))[0] , 0 , 	(  4 * 	(  sizeof(int ) * numvec ) ) );
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( inoutput );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( inoutput );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( xyzw );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( xyzw );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( cu_xyzw );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( cu_xyzw );

	}else{
		0;

	 }

	 }
}	return  0 ;}
int  init_maxwell_dist_particle_fmpi (Field3D_MPI *  pthis ){
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
	int  use_lost_cone = 	call_GET_VAR ( "USE_LOST_CONE_DIST" ) ;
	double  mu0 = 0.00000000000000000e+00 ;
	double  delta = 0.00000000000000000e+00 ;
	if (  use_lost_cone  ){  
		(mu0 = 	call_GET_VAR ( "LOST_CONE_MU0" ));
(delta = 	call_GET_VAR ( "LOST_CONE_DELTA" ));

	}else{
		0;

	 }
	int  i ;
	int  j ;
	for (i=0 ; 	(  i < num_spec ) ; i++)
	{
	for (j=0 ; 	(  j < num_runtime ) ; j++)
	{
	init_maxwell_dist_particle_opc ( 	(  	( pthis )->particles + 	(  	(  i * num_runtime ) + j ) ) , 	call_GET_INIT_LOAD ( i ) , 	call_GET_INIT_VT ( i ) , ((	(  i == 0 ))?(use_lost_cone):(0)) , mu0 , delta );
}}	return  0 ;}
int  init_non_uni_particle_opc (One_Particle_Collection *  pthis ,int  tgrid_load ,int  cur_sp ,double  VT ){
	Field3D_Seq *  pfield = 	( pthis )->pfield ;
	Field3D_Seq *  pfieldE = 	( pthis )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( pthis )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( pthis )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( pthis )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( pthis )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( pthis )->pFoutEN ;
	void * *  sort_kernel = 	( pthis )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( pthis )->geo_rel_1st_kernel ;
	void * *  rel_1st_kernel = 	( pthis )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( pthis )->krook_collision_test_kernel ;
	void * *  boris_yee_kernel = 	( pthis )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( pthis )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( pthis )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( pthis )->move_back_kernel_kernel ;
	double  Mass = 	( pthis )->Mass ;
	double  Charge = 	( pthis )->Charge ;
	double  Number_particle_per_marker = 	( pthis )->Number_particle_per_marker ;
	long  grid_cache_len = 	( pthis )->grid_cache_len ;
	long  cu_cache_length = 	( pthis )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( pthis )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( pthis )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( pthis )->split_pass_z_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( pthis )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( pthis )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( pthis )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( pthis )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( pthis )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( pthis )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( pthis )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( pthis )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( pthis )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( pthis )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( pthis )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( pthis )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( pthis )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( pthis )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( pthis )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( pthis )->calculate_rho_kernel ;
	void *  inoutput = 	( pthis )->inoutput ;
	void *  xyzw = 	( pthis )->xyzw ;
	void *  cu_cache = 	( pthis )->cu_cache ;
	void *  cu_xyzw = 	( pthis )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( pthis )->adjoint_vec_pids ;
{
	Field3D_Seq *  pfield = 	( pthis )->pfield ;
	Field3D_Seq *  pfieldE = 	( pthis )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( pthis )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( pthis )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( pthis )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( pthis )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( pthis )->pFoutEN ;
	void * *  sort_kernel = 	( pthis )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( pthis )->geo_rel_1st_kernel ;
	void * *  rel_1st_kernel = 	( pthis )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( pthis )->krook_collision_test_kernel ;
	void * *  boris_yee_kernel = 	( pthis )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( pthis )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( pthis )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( pthis )->move_back_kernel_kernel ;
	double  Mass = 	( pthis )->Mass ;
	double  Charge = 	( pthis )->Charge ;
	double  Number_particle_per_marker = 	( pthis )->Number_particle_per_marker ;
	long  grid_cache_len = 	( pthis )->grid_cache_len ;
	long  cu_cache_length = 	( pthis )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( pthis )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( pthis )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( pthis )->split_pass_z_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( pthis )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( pthis )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( pthis )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( pthis )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( pthis )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( pthis )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( pthis )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( pthis )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( pthis )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( pthis )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( pthis )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( pthis )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( pthis )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( pthis )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( pthis )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( pthis )->calculate_rho_kernel ;
	void *  inoutput = 	( pthis )->inoutput ;
	void *  xyzw = 	( pthis )->xyzw ;
	void *  cu_cache = 	( pthis )->cu_cache ;
	void *  cu_xyzw = 	( pthis )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( pthis )->adjoint_vec_pids ;
	void *  pe = 	( pfield )->pe ;
	long  xlen = 	( pfield )->xlen ;
	long  ylen = 	( pfield )->ylen ;
	long  zlen = 	( pfield )->zlen ;
	long  xblock = 	( pfield )->xblock ;
	long  yblock = 	( pfield )->yblock ;
	long  zblock = 	( pfield )->zblock ;
	long  numvec = 	( pfield )->numvec ;
	long  x_num_thread_block = 	( pfield )->x_num_thread_block ;
	long  y_num_thread_block = 	( pfield )->y_num_thread_block ;
	long  z_num_thread_block = 	( pfield )->z_num_thread_block ;
	int  ovlp = 	( pfield )->ovlp ;
	int  num_ele = 	( pfield )->num_ele ;
	int  CD_type = 	( pfield )->CD_type ;
	void * *  sync_layer_pscmc = 	( pfield )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( pfield )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( pfield )->sync_kernels ;
	void * *  fdtd_kernels = 	( pfield )->fdtd_kernels ;
	void * *  dm_kernels = 	( pfield )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pfield )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pfield )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( pfield )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pfield )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pfield )->yee_damp_kernels ;
	void *  rdcd = 	( pfield )->rdcd ;
	double *  rdcd_host = 	( pfield )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( pfield )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( pfield )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( pfield )->cur_rankz_pscmc ;
	void *  xoffset = 	( pfield )->xoffset ;
	void *  yoffset = 	( pfield )->yoffset ;
	void *  zoffset = 	( pfield )->zoffset ;
	long *  global_x_offset = 	( pfield )->global_x_offset ;
	long *  global_y_offset = 	( pfield )->global_y_offset ;
	long *  global_z_offset = 	( pfield )->global_z_offset ;
	long *  global_id = 	( pfield )->global_id ;
	long  global_pid = 	( pfield )->global_pid ;
	long *  adj_ids = 	( pfield )->adj_ids ;
	long *  adj_processes = 	( pfield )->adj_processes ;
	long *  adj_local_tid = 	( pfield )->adj_local_tid ;
	void *  main_data = 	( pfield )->main_data ;
	double  delta_x = 	( pfield )->delta_x ;
	double  delta_y = 	( pfield )->delta_y ;
	double  delta_z = 	( pfield )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( pfield )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( pfield )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( pfield )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( pfield )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( pfield )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( pfield )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( pfield )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( pfield )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( pfield )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( pfield )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( pfield )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( pfield )->blas_sum_kernel ;
	long  alllenoff = 	(  xlen * 	(  ylen * zlen ) ) ;
	long  cur_pcid ;
	double *  host_data = (((double * * )inoutput))[0] ;
	int *  xyzw_data = (((int * * )xyzw))[0] ;
	fprintf ( stderr , "xyzw=0x%x\n" , xyzw_data );
	for (cur_pcid=0 ; 	(  cur_pcid < numvec ) ; cur_pcid++)
	{
	double *  grid_r_0 = 	(  host_data + 	(  cur_pcid * 	(  alllenoff * 	(  6 * grid_cache_len ) ) ) ) ;
	int *  xyzw_0 = 	(  xyzw_data + 	(  cur_pcid * 	(  alllenoff * 4 ) ) ) ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < zlen ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < ylen ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < xlen ) ; (xyzx = 	(  xyzx + 1 )))
	{
	double *  grid_r = 	(  grid_r_0 + 	(  0 + 	(  	(  6 * grid_cache_len ) * 	(  xyzx + 	(  xlen * 	(  xyzy + 	(  ylen * xyzz ) ) ) ) ) ) ) ;
	int *  grid_xyzw = 	(  xyzw_0 + 	(  0 + 	(  4 * 	(  xyzx + 	(  xlen * 	(  xyzy + 	(  ylen * xyzz ) ) ) ) ) ) ) ;
	long  l = 0 ;
	long  grid_load = 	(  	call_GET_INIT_DENSITY_DIST ( cur_sp , 	(  (global_z_offset)[cur_pcid] + 	(  xyzz + 5.00000000000000000e-01 ) ) , 	(  (global_y_offset)[cur_pcid] + 	(  xyzy + 5.00000000000000000e-01 ) ) , 	(  (global_x_offset)[cur_pcid] + 	(  xyzx + 5.00000000000000000e-01 ) ) ) * tgrid_load ) ;
	if (  	(  grid_load > grid_cache_len )  ){  
			fprintf ( stderr , "Error, gl=%d gcl=%d global_id=%d cur_picid=%d\n" , grid_load , grid_cache_len , (global_id)[cur_pcid] , cur_pcid );

	}else{
		0;

	 }
	assert ( 	(  grid_load <= grid_cache_len ) );
	double  vx_ijk = 0 ;
	double  vy_ijk = 0 ;
	double  vz_ijk = 0 ;
	if (  USE_INIT_V0  ){  
		(vx_ijk = 	call_GET_INIT_V0_x ( cur_sp , 	(  (global_z_offset)[cur_pcid] + 	(  xyzz + 5.00000000000000000e-01 ) ) , 	(  (global_y_offset)[cur_pcid] + 	(  xyzy + 5.00000000000000000e-01 ) ) , 	(  (global_x_offset)[cur_pcid] + 	(  xyzx + 5.00000000000000000e-01 ) ) ));
(vy_ijk = 	call_GET_INIT_V0_y ( cur_sp , 	(  (global_z_offset)[cur_pcid] + 	(  xyzz + 5.00000000000000000e-01 ) ) , 	(  (global_y_offset)[cur_pcid] + 	(  xyzy + 5.00000000000000000e-01 ) ) , 	(  (global_x_offset)[cur_pcid] + 	(  xyzx + 5.00000000000000000e-01 ) ) ));
(vz_ijk = 	call_GET_INIT_V0_z ( cur_sp , 	(  (global_z_offset)[cur_pcid] + 	(  xyzz + 5.00000000000000000e-01 ) ) , 	(  (global_y_offset)[cur_pcid] + 	(  xyzy + 5.00000000000000000e-01 ) ) , 	(  (global_x_offset)[cur_pcid] + 	(  xyzx + 5.00000000000000000e-01 ) ) ));

	}else{
		0;

	 }
	double  tempx = 1 ;
	double  tempy = 1 ;
	double  tempz = 1 ;
	if (  USE_NON_UNI_TEMPERATURE  ){  
		(tempx = 	call_GET_INIT_TEMPERATURE_DIST ( cur_sp , 	(  (global_z_offset)[cur_pcid] + 	(  xyzz + 5.00000000000000000e-01 ) ) , 	(  (global_y_offset)[cur_pcid] + 	(  xyzy + 5.00000000000000000e-01 ) ) , 	(  (global_x_offset)[cur_pcid] + 	(  xyzx + 5.00000000000000000e-01 ) ) , 0 ));
(tempy = 	call_GET_INIT_TEMPERATURE_DIST ( cur_sp , 	(  (global_z_offset)[cur_pcid] + 	(  xyzz + 5.00000000000000000e-01 ) ) , 	(  (global_y_offset)[cur_pcid] + 	(  xyzy + 5.00000000000000000e-01 ) ) , 	(  (global_x_offset)[cur_pcid] + 	(  xyzx + 5.00000000000000000e-01 ) ) , 1 ));
(tempz = 	call_GET_INIT_TEMPERATURE_DIST ( cur_sp , 	(  (global_z_offset)[cur_pcid] + 	(  xyzz + 5.00000000000000000e-01 ) ) , 	(  (global_y_offset)[cur_pcid] + 	(  xyzy + 5.00000000000000000e-01 ) ) , 	(  (global_x_offset)[cur_pcid] + 	(  xyzx + 5.00000000000000000e-01 ) ) , 2 ));

	}else{
		0;

	 }
	for (l ; 	(  l < grid_load ) ; l++)
	{
((grid_xyzw)[0] = grid_load);
	double *  xyzvs = 	(  grid_r + 	(  l * 6 ) ) ;
((xyzvs)[0] = 	rand01 ( xyzx , 	(  xyzx + 1 ) ));
((xyzvs)[1] = 	rand01 ( xyzy , 	(  xyzy + 1 ) ));
((xyzvs)[2] = 	rand01 ( xyzz , 	(  xyzz + 1 ) ));
	befmaxinit:
((xyzvs)[3] = 	maxwell_dist ( vx_ijk , 	(  tempx * VT ) ));
((xyzvs)[4] = 	maxwell_dist ( vy_ijk , 	(  tempy * VT ) ));
((xyzvs)[5] = 	maxwell_dist ( vz_ijk , 	(  tempz * VT ) ));
	double  vx = (xyzvs)[3] ;
	double  vy = (xyzvs)[4] ;
	double  vz = (xyzvs)[5] ;
	if (  	(  	(  	(  	(  vx * vx ) + 	(  vy * vy ) ) + 	(  vz * vz ) ) >= 1 )  ){  
			goto befmaxinit;
	}else{
		0;

	 }
}}}}}}}}}{
	void *  pe = 	( pfield )->pe ;
	long  xlen = 	( pfield )->xlen ;
	long  ylen = 	( pfield )->ylen ;
	long  zlen = 	( pfield )->zlen ;
	long  xblock = 	( pfield )->xblock ;
	long  yblock = 	( pfield )->yblock ;
	long  zblock = 	( pfield )->zblock ;
	long  numvec = 	( pfield )->numvec ;
	long  x_num_thread_block = 	( pfield )->x_num_thread_block ;
	long  y_num_thread_block = 	( pfield )->y_num_thread_block ;
	long  z_num_thread_block = 	( pfield )->z_num_thread_block ;
	int  ovlp = 	( pfield )->ovlp ;
	int  num_ele = 	( pfield )->num_ele ;
	int  CD_type = 	( pfield )->CD_type ;
	void * *  sync_layer_pscmc = 	( pfield )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( pfield )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( pfield )->sync_kernels ;
	void * *  fdtd_kernels = 	( pfield )->fdtd_kernels ;
	void * *  dm_kernels = 	( pfield )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pfield )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pfield )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( pfield )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pfield )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pfield )->yee_damp_kernels ;
	void *  rdcd = 	( pfield )->rdcd ;
	double *  rdcd_host = 	( pfield )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( pfield )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( pfield )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( pfield )->cur_rankz_pscmc ;
	void *  xoffset = 	( pfield )->xoffset ;
	void *  yoffset = 	( pfield )->yoffset ;
	void *  zoffset = 	( pfield )->zoffset ;
	long *  global_x_offset = 	( pfield )->global_x_offset ;
	long *  global_y_offset = 	( pfield )->global_y_offset ;
	long *  global_z_offset = 	( pfield )->global_z_offset ;
	long *  global_id = 	( pfield )->global_id ;
	long  global_pid = 	( pfield )->global_pid ;
	long *  adj_ids = 	( pfield )->adj_ids ;
	long *  adj_processes = 	( pfield )->adj_processes ;
	long *  adj_local_tid = 	( pfield )->adj_local_tid ;
	void *  main_data = 	( pfield )->main_data ;
	double  delta_x = 	( pfield )->delta_x ;
	double  delta_y = 	( pfield )->delta_y ;
	double  delta_z = 	( pfield )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( pfield )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( pfield )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( pfield )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( pfield )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( pfield )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( pfield )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( pfield )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( pfield )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( pfield )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( pfield )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( pfield )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( pfield )->blas_sum_kernel ;
	memset ( (((int * * )cu_xyzw))[0] , 0 , 	(  4 * 	(  sizeof(int ) * numvec ) ) );
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( inoutput );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( inoutput );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( xyzw );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( xyzw );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( cu_xyzw );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( cu_xyzw );

	}else{
		0;

	 }

	 }
}	return  0 ;}
int  init_non_uni_particle_fmpi (Field3D_MPI *  pthis ){
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
	int  i ;
	int  j ;
	for (i=0 ; 	(  i < num_spec ) ; i++)
	{
	for (j=0 ; 	(  j < num_runtime ) ; j++)
	{
	init_non_uni_particle_opc ( 	(  	( pthis )->particles + 	(  	(  i * num_runtime ) + j ) ) , 	call_GET_INIT_LOAD ( i ) , i , 	call_GET_INIT_VT ( i ) );
}}	return  0 ;}
int  init_single_particle_opc (One_Particle_Collection *  pthis ,int  tgrid_load ){
	Field3D_Seq *  pfield = 	( pthis )->pfield ;
	Field3D_Seq *  pfieldE = 	( pthis )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( pthis )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( pthis )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( pthis )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( pthis )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( pthis )->pFoutEN ;
	void * *  sort_kernel = 	( pthis )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( pthis )->geo_rel_1st_kernel ;
	void * *  rel_1st_kernel = 	( pthis )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( pthis )->krook_collision_test_kernel ;
	void * *  boris_yee_kernel = 	( pthis )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( pthis )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( pthis )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( pthis )->move_back_kernel_kernel ;
	double  Mass = 	( pthis )->Mass ;
	double  Charge = 	( pthis )->Charge ;
	double  Number_particle_per_marker = 	( pthis )->Number_particle_per_marker ;
	long  grid_cache_len = 	( pthis )->grid_cache_len ;
	long  cu_cache_length = 	( pthis )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( pthis )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( pthis )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( pthis )->split_pass_z_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( pthis )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( pthis )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( pthis )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( pthis )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( pthis )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( pthis )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( pthis )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( pthis )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( pthis )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( pthis )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( pthis )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( pthis )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( pthis )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( pthis )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( pthis )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( pthis )->calculate_rho_kernel ;
	void *  inoutput = 	( pthis )->inoutput ;
	void *  xyzw = 	( pthis )->xyzw ;
	void *  cu_cache = 	( pthis )->cu_cache ;
	void *  cu_xyzw = 	( pthis )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( pthis )->adjoint_vec_pids ;
{
	Field3D_Seq *  pfield = 	( pthis )->pfield ;
	Field3D_Seq *  pfieldE = 	( pthis )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( pthis )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( pthis )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( pthis )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( pthis )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( pthis )->pFoutEN ;
	void * *  sort_kernel = 	( pthis )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( pthis )->geo_rel_1st_kernel ;
	void * *  rel_1st_kernel = 	( pthis )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( pthis )->krook_collision_test_kernel ;
	void * *  boris_yee_kernel = 	( pthis )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( pthis )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( pthis )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( pthis )->move_back_kernel_kernel ;
	double  Mass = 	( pthis )->Mass ;
	double  Charge = 	( pthis )->Charge ;
	double  Number_particle_per_marker = 	( pthis )->Number_particle_per_marker ;
	long  grid_cache_len = 	( pthis )->grid_cache_len ;
	long  cu_cache_length = 	( pthis )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( pthis )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( pthis )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( pthis )->split_pass_z_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( pthis )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( pthis )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( pthis )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( pthis )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( pthis )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( pthis )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( pthis )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( pthis )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( pthis )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( pthis )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( pthis )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( pthis )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( pthis )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( pthis )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( pthis )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( pthis )->calculate_rho_kernel ;
	void *  inoutput = 	( pthis )->inoutput ;
	void *  xyzw = 	( pthis )->xyzw ;
	void *  cu_cache = 	( pthis )->cu_cache ;
	void *  cu_xyzw = 	( pthis )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( pthis )->adjoint_vec_pids ;
	void *  pe = 	( pfield )->pe ;
	long  xlen = 	( pfield )->xlen ;
	long  ylen = 	( pfield )->ylen ;
	long  zlen = 	( pfield )->zlen ;
	long  xblock = 	( pfield )->xblock ;
	long  yblock = 	( pfield )->yblock ;
	long  zblock = 	( pfield )->zblock ;
	long  numvec = 	( pfield )->numvec ;
	long  x_num_thread_block = 	( pfield )->x_num_thread_block ;
	long  y_num_thread_block = 	( pfield )->y_num_thread_block ;
	long  z_num_thread_block = 	( pfield )->z_num_thread_block ;
	int  ovlp = 	( pfield )->ovlp ;
	int  num_ele = 	( pfield )->num_ele ;
	int  CD_type = 	( pfield )->CD_type ;
	void * *  sync_layer_pscmc = 	( pfield )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( pfield )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( pfield )->sync_kernels ;
	void * *  fdtd_kernels = 	( pfield )->fdtd_kernels ;
	void * *  dm_kernels = 	( pfield )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pfield )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pfield )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( pfield )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pfield )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pfield )->yee_damp_kernels ;
	void *  rdcd = 	( pfield )->rdcd ;
	double *  rdcd_host = 	( pfield )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( pfield )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( pfield )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( pfield )->cur_rankz_pscmc ;
	void *  xoffset = 	( pfield )->xoffset ;
	void *  yoffset = 	( pfield )->yoffset ;
	void *  zoffset = 	( pfield )->zoffset ;
	long *  global_x_offset = 	( pfield )->global_x_offset ;
	long *  global_y_offset = 	( pfield )->global_y_offset ;
	long *  global_z_offset = 	( pfield )->global_z_offset ;
	long *  global_id = 	( pfield )->global_id ;
	long  global_pid = 	( pfield )->global_pid ;
	long *  adj_ids = 	( pfield )->adj_ids ;
	long *  adj_processes = 	( pfield )->adj_processes ;
	long *  adj_local_tid = 	( pfield )->adj_local_tid ;
	void *  main_data = 	( pfield )->main_data ;
	double  delta_x = 	( pfield )->delta_x ;
	double  delta_y = 	( pfield )->delta_y ;
	double  delta_z = 	( pfield )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( pfield )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( pfield )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( pfield )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( pfield )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( pfield )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( pfield )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( pfield )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( pfield )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( pfield )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( pfield )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( pfield )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( pfield )->blas_sum_kernel ;
	long  alllenoff = 	(  xlen * 	(  ylen * zlen ) ) ;
	long  cur_pcid ;
	double *  host_data = (((double * * )inoutput))[0] ;
	int *  xyzw_data = (((int * * )xyzw))[0] ;
	fprintf ( stderr , "xyzw=0x%x\n" , xyzw_data );
	for (cur_pcid=0 ; 	(  cur_pcid < numvec ) ; cur_pcid++)
	{
	double *  grid_r_0 = 	(  host_data + 	(  cur_pcid * 	(  alllenoff * 	(  6 * grid_cache_len ) ) ) ) ;
	int *  xyzw_0 = 	(  xyzw_data + 	(  cur_pcid * 	(  alllenoff * 4 ) ) ) ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < zlen ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < ylen ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < xlen ) ; (xyzx = 	(  xyzx + 1 )))
	{
	double *  grid_r = 	(  grid_r_0 + 	(  0 + 	(  	(  6 * grid_cache_len ) * 	(  xyzx + 	(  xlen * 	(  xyzy + 	(  ylen * xyzz ) ) ) ) ) ) ) ;
	int *  grid_xyzw = 	(  xyzw_0 + 	(  0 + 	(  4 * 	(  xyzx + 	(  xlen * 	(  xyzy + 	(  ylen * xyzz ) ) ) ) ) ) ) ;
	long  l = 0 ;
	long  grid_load = 	(  tgrid_load * 	(  	(  cur_pcid == 0 ) && 	(  	(  xyzx == 0 ) && 	(  	(  xyzy == 1 ) && 	(  xyzz == 2 ) ) ) ) ) ;
	if (  	(  grid_load > grid_cache_len )  ){  
			fprintf ( stderr , "Error, gl=%d gcl=%d global_id=%d cur_picid=%d\n" , grid_load , grid_cache_len , (global_id)[cur_pcid] , cur_pcid );

	}else{
		0;

	 }
	assert ( 	(  grid_load <= grid_cache_len ) );
	for (l ; 	(  l < grid_load ) ; l++)
	{
((grid_xyzw)[0] = grid_load);
	double *  xyzvs = 	(  grid_r + 	(  l * 6 ) ) ;
((xyzvs)[0] = 2.05156247007062795e+01);
((xyzvs)[1] = 5.10387377109614016e-01);
((xyzvs)[2] = 2.11747892660395998e+01);
((xyzvs)[0] = 2.08401877169962972e+01);
((xyzvs)[0] = 2.25101877169962954e+01);
((xyzvs)[1] = 3.94382926868274974e-01);
((xyzvs)[2] = 	(  16 + 7.83099223626777530e-01 ));
((xyzvs)[2] = 	(  16 + 5.01000000000000001e-01 ));
((xyzvs)[0] = 8.40187716996297018e-01);
((xyzvs)[1] = 1.51018771699629695e+00);
((xyzvs)[2] = 2.89438292686827481e+00);
((xyzvs)[3] = 5.70203321560689494e-02);
((xyzvs)[4] = -9.18939941663985127e-02);
((xyzvs)[5] = -1.26085561086057996e-02);
((xyzvs)[3] = 9.51591927521633352e-03);
((xyzvs)[4] = 2.01650148587055296e-03);
((xyzvs)[5] = -6.31084706625983927e-05);
((xyzvs)[3] = -1.19999999999999996e-01);
((xyzvs)[4] = 2.00000000000000011e-01);
((xyzvs)[5] = 1.40000000000000013e-01);
}}}}}}}}}{
	void *  pe = 	( pfield )->pe ;
	long  xlen = 	( pfield )->xlen ;
	long  ylen = 	( pfield )->ylen ;
	long  zlen = 	( pfield )->zlen ;
	long  xblock = 	( pfield )->xblock ;
	long  yblock = 	( pfield )->yblock ;
	long  zblock = 	( pfield )->zblock ;
	long  numvec = 	( pfield )->numvec ;
	long  x_num_thread_block = 	( pfield )->x_num_thread_block ;
	long  y_num_thread_block = 	( pfield )->y_num_thread_block ;
	long  z_num_thread_block = 	( pfield )->z_num_thread_block ;
	int  ovlp = 	( pfield )->ovlp ;
	int  num_ele = 	( pfield )->num_ele ;
	int  CD_type = 	( pfield )->CD_type ;
	void * *  sync_layer_pscmc = 	( pfield )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( pfield )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( pfield )->sync_kernels ;
	void * *  fdtd_kernels = 	( pfield )->fdtd_kernels ;
	void * *  dm_kernels = 	( pfield )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pfield )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pfield )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( pfield )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pfield )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pfield )->yee_damp_kernels ;
	void *  rdcd = 	( pfield )->rdcd ;
	double *  rdcd_host = 	( pfield )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( pfield )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( pfield )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( pfield )->cur_rankz_pscmc ;
	void *  xoffset = 	( pfield )->xoffset ;
	void *  yoffset = 	( pfield )->yoffset ;
	void *  zoffset = 	( pfield )->zoffset ;
	long *  global_x_offset = 	( pfield )->global_x_offset ;
	long *  global_y_offset = 	( pfield )->global_y_offset ;
	long *  global_z_offset = 	( pfield )->global_z_offset ;
	long *  global_id = 	( pfield )->global_id ;
	long  global_pid = 	( pfield )->global_pid ;
	long *  adj_ids = 	( pfield )->adj_ids ;
	long *  adj_processes = 	( pfield )->adj_processes ;
	long *  adj_local_tid = 	( pfield )->adj_local_tid ;
	void *  main_data = 	( pfield )->main_data ;
	double  delta_x = 	( pfield )->delta_x ;
	double  delta_y = 	( pfield )->delta_y ;
	double  delta_z = 	( pfield )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( pfield )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( pfield )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( pfield )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( pfield )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( pfield )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( pfield )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( pfield )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( pfield )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( pfield )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( pfield )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( pfield )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( pfield )->blas_sum_kernel ;
	memset ( (((int * * )cu_xyzw))[0] , 0 , 	(  4 * 	(  sizeof(int ) * numvec ) ) );
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( inoutput );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( inoutput );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( xyzw );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( xyzw );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( cu_xyzw );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( cu_xyzw );

	}else{
		0;

	 }

	 }
}	return  0 ;}
int  init_single_particle_fmpi (Field3D_MPI *  pthis ){
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
	int  i ;
	int  j ;
	for (i=0 ; 	(  i < num_spec ) ; i++)
	{
	for (j=0 ; 	(  j < num_runtime ) ; j++)
	{
	init_single_particle_opc ( 	(  	( pthis )->particles + 	(  	(  i * num_runtime ) + j ) ) , ((	(  j == 0 ))?(1):(0)) );
}}	return  0 ;}
void  init_global_particles (Particle_in_Cell_MPI *  pthis ,Field3D_MPI *  fE ,Field3D_MPI *  fEN ,int  use_small_num_grids ,int  pml_abc_dir ,int  pml_level ,double  pml_sigma_max ,double  deltat ,int  num_spec ,long *  allxyzmax ,double *  massp ,double *  chargep ,double *  npm ,long *  grid_cache_len ,long *  cu_cache_len ){
	Field3D_MPI  MPI_fieldE = 	( pthis )->MPI_fieldE ;
	Field3D_MPI  MPI_fieldB = 	( pthis )->MPI_fieldB ;
	Field3D_MPI  MPI_fieldB1 = 	( pthis )->MPI_fieldB1 ;
	Field3D_MPI  MPI_FoutJ = 	( pthis )->MPI_FoutJ ;
	Field3D_MPI  MPI_LFoutJ = 	( pthis )->MPI_LFoutJ ;
	Field3D_MPI  MPI_fieldEtmp = 	( pthis )->MPI_fieldEtmp ;
	Field3D_MPI  MPI_fieldEtmp1 = 	( pthis )->MPI_fieldEtmp1 ;
	Field3D_MPI  MPI_fieldBtmp1 = 	( pthis )->MPI_fieldBtmp1 ;
	Field3D_MPI  MPI_fieldPMLB = 	( pthis )->MPI_fieldPMLB ;
	Field3D_MPI  MPI_fieldPMLE = 	( pthis )->MPI_fieldPMLE ;
	Field3D_MPI *  pMPI_FoutJ = 	( pthis )->pMPI_FoutJ ;
	Field3D_MPI *  pMPI_FoutEN = 	( pthis )->pMPI_FoutEN ;
	Field3D_MPI  MPI_fieldE_ext = 	( pthis )->MPI_fieldE_ext ;
	Field3D_MPI  MPI_fieldB_ext = 	( pthis )->MPI_fieldB_ext ;
	Field3D_MPI  MPI_fieldE_filter = 	( pthis )->MPI_fieldE_filter ;
	Field3D_MPI  MPI_fieldB_filter = 	( pthis )->MPI_fieldB_filter ;
	Field3D_MPI *  pB0 = 	( pthis )->pB0 ;
	Field3D_MPI *  pB1 = 	( pthis )->pB1 ;
	int  use_pml_abc_dir = 	( pthis )->use_pml_abc_dir ;
	int  use_pml_level = 	( pthis )->use_pml_level ;
	int  use_small_grid = 	( pthis )->use_small_grid ;
	long  allxmax = 	( pthis )->allxmax ;
	long  allymax = 	( pthis )->allymax ;
	long  allzmax = 	( pthis )->allzmax ;
	double  use_pml_sigma_max = 	( pthis )->use_pml_sigma_max ;
	double  dt = 	( pthis )->dt ;
	init_Field3D_MPI_from ( 	& ( 	( pthis )->MPI_fieldE ) , fE );
	init_Field3D_MPI_from ( 	& ( 	( pthis )->MPI_fieldB ) , fE );
	init_Field3D_MPI_from ( 	& ( 	( pthis )->MPI_fieldE_ext ) , fE );
	init_Field3D_MPI_from ( 	& ( 	( pthis )->MPI_fieldB_ext ) , fE );
	init_Field3D_MPI_from ( 	& ( 	( pthis )->MPI_fieldE_filter ) , fE );
	init_Field3D_MPI_from ( 	& ( 	( pthis )->MPI_fieldB_filter ) , fE );
	init_Field3D_MPI_from ( 	& ( 	( pthis )->MPI_fieldEtmp ) , fE );
	if (  use_pml_abc_dir  ){  
			init_Field3D_MPI_from ( 	& ( 	( pthis )->MPI_fieldPMLB ) , fE );
	init_Field3D_MPI_from ( 	& ( 	( pthis )->MPI_fieldPMLE ) , fE );
	blas_yiszero_Field3D_MPI ( 	& ( 	( pthis )->MPI_fieldPMLB ) , 	& ( 	( pthis )->MPI_fieldPMLB ) );
	blas_yiszero_Field3D_MPI ( 	& ( 	( pthis )->MPI_fieldPMLE ) , 	& ( 	( pthis )->MPI_fieldPMLE ) );
(	( pthis )->use_pml_abc_dir = pml_abc_dir);
(	( pthis )->use_pml_level = pml_level);
(	( pthis )->use_pml_sigma_max = pml_sigma_max);
(	( pthis )->allxmax = (allxyzmax)[0]);
(	( pthis )->allymax = (allxyzmax)[1]);
(	( pthis )->allzmax = (allxyzmax)[2]);

	}else{
		0;

	 }
	if (  	(  USE_FILTER == 2 )  ){  
			init_Field3D_MPI_from ( 	& ( 	( pthis )->MPI_fieldEtmp1 ) , fE );
	init_Field3D_MPI_from ( 	& ( 	( pthis )->MPI_fieldBtmp1 ) , fE );

	}else{
		0;

	 }
	init_Field3D_MPI_from ( 	& ( 	( pthis )->MPI_fieldB1 ) , fE );
	init_Field3D_MPI_from ( 	& ( 	( pthis )->MPI_FoutJ ) , fE );
(	( pthis )->use_small_grid = 0);
	if (  	(  use_small_num_grids == 1 )  ){  
			init_Field3D_MPI_from_new_num_ele ( 	& ( 	( pthis )->MPI_LFoutJ ) , fE , 375 );
(	( pthis )->use_small_grid = 1);

	}else{
			if (  	(  use_small_num_grids == 2 )  ){  
			build_Field_compute_unit_from_mpi_field ( 	& ( 	( pthis )->MPI_LFoutJ ) , fE );
(	( pthis )->use_small_grid = 2);

	}else{
		0;

	 }

	 }
(	( pthis )->pMPI_FoutEN = fEN);
	if (  USE_FILTER  ){  
			init_external_field3d_FILTER_E ( 	& ( 	( pthis )->MPI_fieldE_filter ) );
	init_external_field3d_FILTER_B ( 	& ( 	( pthis )->MPI_fieldB_filter ) );
	sync_main_data_h2d ( 	& ( 	( pthis )->MPI_fieldE_filter ) );
	sync_main_data_h2d ( 	& ( 	( pthis )->MPI_fieldB_filter ) );

	}else{
		0;

	 }
	if (  USE_INIT_EXT_EB  ){  
			init_external_field3d_E ( 	& ( 	( pthis )->MPI_fieldE_ext ) );
	init_external_field3d_B ( 	& ( 	( pthis )->MPI_fieldB_ext ) );
	sync_main_data_h2d ( 	& ( 	( pthis )->MPI_fieldE_ext ) );
	sync_main_data_h2d ( 	& ( 	( pthis )->MPI_fieldB_ext ) );

	}else{
		0;

	 }
	if (  USE_INIT_EB0  ){  
			init_external_field3d_E0 ( 	& ( 	( pthis )->MPI_fieldE ) );
	init_external_field3d_B0 ( 	& ( 	( pthis )->MPI_fieldB ) );

	}else{
			test_set_mainland ( 	& ( pthis->MPI_fieldB ) , 0.00000000000000000e+00 );
	test_set_mainland ( 	& ( pthis->MPI_fieldE ) , 0.00000000000000000e+00 );

	 }
	sync_main_data_h2d ( 	& ( 	( pthis )->MPI_fieldE ) );
	sync_main_data_h2d ( 	& ( 	( pthis )->MPI_fieldB ) );
(	( pthis )->pMPI_FoutJ = 	& ( 	( pthis )->MPI_FoutJ ));
	init_particle_mpi ( 	& ( 	( pthis )->MPI_fieldE ) , num_spec , massp , chargep , npm , grid_cache_len , cu_cache_len );
	int  num_runtime = 	( 	( pthis )->MPI_fieldE ).num_runtime ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 	(  num_spec * num_runtime ) ) ; (i = 	(  i + 1 )))
	{
(	( 	(  	( 	( pthis )->MPI_fieldE ).particles + i ) )->pfieldE = 	(  	( 	( pthis )->MPI_fieldE ).data + 	(  i % num_runtime ) ));
(	( 	(  	( 	( pthis )->MPI_fieldE ).particles + i ) )->pfieldB = 	(  	( 	( pthis )->MPI_fieldB ).data + 	(  i % num_runtime ) ));
(	( 	(  	( 	( pthis )->MPI_fieldE ).particles + i ) )->pFoutJ = 	(  	( 	( pthis )->MPI_FoutJ ).data + 	(  i % num_runtime ) ));
(	( 	(  	( 	( pthis )->MPI_fieldE ).particles + i ) )->pLFoutJ = ((use_small_num_grids)?(	(  	( 	( pthis )->MPI_LFoutJ ).data + 	(  i % num_runtime ) )):(NULL)));
(	( 	(  	( 	( pthis )->MPI_fieldE ).particles + i ) )->pFoutEN = 	(  	( 	( pthis )->pMPI_FoutEN )->data + 	(  i % num_runtime ) ));
}}(	( pthis )->dt = deltat);
}
