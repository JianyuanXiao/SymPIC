#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
#include "init_adjoint_relation.h"
#include "init_field3d_mpi.h"
#include "mpifields.h"
#include "cfgcst.h"
#include "genrand.h"
#include <cgapsio.h>
void  init_Field3D_MPI_from_new_num_ele (Field3D_MPI *  pthis ,Field3D_MPI *  f ,int  new_num_ele ){
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
((pthis)[0] = (f)[0]);
	reinit_Field3D_MPI ( pthis , new_num_ele );
}
void  init_Field3D_MPI_from (Field3D_MPI *  pthis ,Field3D_MPI *  f ){
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
	init_Field3D_MPI_from_new_num_ele ( pthis , f , 0 );
}
void  reinit_Field3D_MPI (Field3D_MPI *  pthis ,int  new_num_ele ){
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
{
	Field3D_Seq *  tmpdata = pthis->data ;
(	( pthis )->data = 	malloc ( 	(  sizeof(Field3D_Seq ) * num_runtime ) ));
(	( pthis )->rqst = 	malloc ( 	(  sizeof(PS_MPI_Request * ) * num_runtime ) ));
{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
	{
((pthis->data)[i] = (tmpdata)[i]);
	if (  new_num_ele  ){  
		(	( 	(  pthis->data + i ) )->num_ele = new_num_ele);

	}else{
		0;

	 }
{
	int  CD_type = 	( 	(  pthis->data + i ) )->CD_type ;
	long  numvec = 	( 	(  pthis->data + i ) )->numvec ;
	alloc_Field3D_Seq ( 	(  pthis->data + i ) , 0 );
(	( 	(  pthis->data + i ) )->cur_rankx_pscmc = 	( 	(  tmpdata + i ) )->cur_rankx_pscmc);
(	( 	(  pthis->data + i ) )->cur_ranky_pscmc = 	( 	(  tmpdata + i ) )->cur_ranky_pscmc);
(	( 	(  pthis->data + i ) )->cur_rankz_pscmc = 	( 	(  tmpdata + i ) )->cur_rankz_pscmc);
(	( 	(  pthis->data + i ) )->xoffset = 	( 	(  tmpdata + i ) )->xoffset);
(	( 	(  pthis->data + i ) )->yoffset = 	( 	(  tmpdata + i ) )->yoffset);
(	( 	(  pthis->data + i ) )->zoffset = 	( 	(  tmpdata + i ) )->zoffset);
	int *  tmpvi = ((	(  0 == CD_type ))?(	c_pscmc_get_h_data ( 	( 	(  pthis->data + i ) )->cur_rankx_pscmc , NULL )):(((	(  1 == CD_type ))?(	openmp_pscmc_get_h_data ( 	( 	(  pthis->data + i ) )->cur_rankx_pscmc , NULL )):(0)))) ;
	memcpy ( 	( 	(  pthis->data + i ) )->global_id , 	( 	(  tmpdata + i ) )->global_id , 	(  sizeof(long ) * 	(  1 * numvec ) ) );
	memcpy ( 	( 	(  pthis->data + i ) )->global_x_offset , 	( 	(  tmpdata + i ) )->global_x_offset , 	(  sizeof(long ) * 	(  1 * numvec ) ) );
	memcpy ( 	( 	(  pthis->data + i ) )->global_y_offset , 	( 	(  tmpdata + i ) )->global_y_offset , 	(  sizeof(long ) * 	(  1 * numvec ) ) );
	memcpy ( 	( 	(  pthis->data + i ) )->global_z_offset , 	( 	(  tmpdata + i ) )->global_z_offset , 	(  sizeof(long ) * 	(  1 * numvec ) ) );
	memcpy ( 	( 	(  pthis->data + i ) )->adj_ids , 	( 	(  tmpdata + i ) )->adj_ids , 	(  sizeof(long ) * 	(  NUM_SYNC_LAYER * numvec ) ) );
	memcpy ( 	( 	(  pthis->data + i ) )->adj_processes , 	( 	(  tmpdata + i ) )->adj_processes , 	(  sizeof(long ) * 	(  NUM_SYNC_LAYER * numvec ) ) );
	memcpy ( 	( 	(  pthis->data + i ) )->adj_local_tid , 	( 	(  tmpdata + i ) )->adj_local_tid , 	(  sizeof(long ) * 	(  NUM_SYNC_LAYER * numvec ) ) );
}((pthis->rqst)[i] = 	malloc ( 	(  sizeof(PS_MPI_Request ) * 	(  NUM_SYNC_LAYER * pthis->data->numvec ) ) ));
}}}}
int  init_Field3D_MPI_ALL (Field3D_MPI *  pthis ,Field3D_Seq *  sample_field ,long  n_hilbert ,int  ndim ,int  adjoint_type ,long *  tids ,long *  local_tid_array ,int *  cd_types ,int *  dev_nums ,long  num_runtime ,PS_MPI_Comm  comm ,long  cur_rank ,long  num_mpi_process ){
(	( pthis )->num_runtime = num_runtime);
(	( pthis )->comm = comm);
(	( pthis )->cur_rank = cur_rank);
(	( pthis )->num_mpi_process = num_mpi_process);
{
	double  G_DAMP_RATIO = 	call_GET_VAR ( "DAMP_RATIO" ) ;
(	( pthis )->damp_vars = G_DAMP_RATIO);
}(	( pthis )->data = 	malloc ( 	(  sizeof(Field3D_Seq ) * num_runtime ) ));
	long  i = 0 ;
	long  onedim_len = 	(  1 << n_hilbert ) ;
	long  numallthreads = ((	(  ndim == 1 ))?(onedim_len):(((	(  ndim == 2 ))?(	(  onedim_len * onedim_len )):(((	(  ndim == 3 ))?(	(  onedim_len * 	(  onedim_len * onedim_len ) )):(	fprintf ( stderr , "Warning: unknown dimension d=%d\n" , ndim ))))))) ;
	long  onen = 	(  1 << n_hilbert ) ;
	long  alllen = 1 ;
	assert ( ndim<4 );
{
	long  g ;
	for ((g = 0) ; 	(  g < ndim ) ; (g = 	(  g + 1 )))
	{
(alllen = 	(  alllen * onen ));
}}	size_t *  ovvec = 	malloc ( 	(  sizeof(size_t ) * alllen ) ) ;
	size_t *  ori_vec = 	malloc ( 	(  sizeof(size_t ) * alllen ) ) ;
	if (  	(  ndim == 1 )  ){  
			sp_fill_curve_1d ( ovvec , ori_vec , onen );

	}else{
			if (  	(  ndim == 2 )  ){  
			hilbert_curve_2d ( ovvec , ori_vec , n_hilbert , onen );

	}else{
			if (  	(  ndim == 3 )  ){  
			hilbert_curve_3d ( ovvec , ori_vec , n_hilbert , onen , onen );

	}else{
			fprintf ( stderr , "Error: unknown ndim=%d\n" , ndim );
	assert ( 0 );

	 }

	 }

	 }
{
	double  M_USE_CALC_WEIGHT = 	call_GET_VAR ( "USE_CALC_WEIGHT" ) ;
	long  n = NUM_PROCESS ;
	long  num_runtime = NUM_RUNTIME ;
	long  numt = alllen ;
	if (  M_USE_CALC_WEIGHT  ){  
			init_complexity_tid ( 	(  n * num_runtime ) , numt , ori_vec , tids , local_tid_array );

	}else{
			init_uniform_tid ( 	(  n * num_runtime ) , numt , tids , local_tid_array );

	 }
}(pthis->rqst = 	malloc ( 	(  sizeof(PS_MPI_Request * ) * num_runtime ) ));
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
((pthis->data)[i] = (sample_field)[0]);
(	( 	(  pthis->data + i ) )->CD_type = (cd_types)[i]);
(	( 	(  pthis->data + i ) )->numvec = 	get_cur_num_tid ( 	(  	(  num_runtime * cur_rank ) + i ) , numallthreads , 	(  num_runtime * num_mpi_process ) , tids ));
	size_t  pelen ;
	int  CD_type = 	( 	(  pthis->data + i ) )->CD_type ;
	if (  	(  0 == CD_type )  ){  
			c_pscmc_get_env_len ( 	& ( pelen ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_get_env_len ( 	& ( pelen ) );

	}else{
		0;

	 }

	 }
(	( 	(  pthis->data + i ) )->pe = 	malloc ( pelen ));
	if (  	(  0 == CD_type )  ){  
			c_pscmc_env_init ( 	( 	(  pthis->data + i ) )->pe , (dev_nums)[i] , NULL );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_env_init ( 	( 	(  pthis->data + i ) )->pe , (dev_nums)[i] , NULL );

	}else{
		0;

	 }

	 }
(	( 	(  pthis->data + i ) )->global_pid = 	(  	(  cur_rank * num_runtime ) + i ));
	alloc_Field3D_Seq ( 	(  pthis->data + i ) , 1 );
((pthis->rqst)[i] = 	malloc ( 	(  sizeof(PS_MPI_Request ) * 	(  NUM_SYNC_LAYER * pthis->data->numvec ) ) ));
	init_adjoint_relations ( 	(  pthis->data + i ) , n_hilbert , ndim , adjoint_type , 	(  num_mpi_process * num_runtime ) , ovvec , ori_vec , tids , local_tid_array );
}{
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
	void *  pe = 	( sample_field )->pe ;
	long  xlen = 	( sample_field )->xlen ;
	long  ylen = 	( sample_field )->ylen ;
	long  zlen = 	( sample_field )->zlen ;
	long  xblock = 	( sample_field )->xblock ;
	long  yblock = 	( sample_field )->yblock ;
	long  zblock = 	( sample_field )->zblock ;
	long  numvec = 	( sample_field )->numvec ;
	long  x_num_thread_block = 	( sample_field )->x_num_thread_block ;
	long  y_num_thread_block = 	( sample_field )->y_num_thread_block ;
	long  z_num_thread_block = 	( sample_field )->z_num_thread_block ;
	int  ovlp = 	( sample_field )->ovlp ;
	int  num_ele = 	( sample_field )->num_ele ;
	int  CD_type = 	( sample_field )->CD_type ;
	void * *  sync_layer_pscmc = 	( sample_field )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( sample_field )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( sample_field )->sync_kernels ;
	void * *  fdtd_kernels = 	( sample_field )->fdtd_kernels ;
	void * *  dm_kernels = 	( sample_field )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( sample_field )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( sample_field )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( sample_field )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( sample_field )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( sample_field )->yee_damp_kernels ;
	void *  rdcd = 	( sample_field )->rdcd ;
	double *  rdcd_host = 	( sample_field )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( sample_field )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( sample_field )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( sample_field )->cur_rankz_pscmc ;
	void *  xoffset = 	( sample_field )->xoffset ;
	void *  yoffset = 	( sample_field )->yoffset ;
	void *  zoffset = 	( sample_field )->zoffset ;
	long *  global_x_offset = 	( sample_field )->global_x_offset ;
	long *  global_y_offset = 	( sample_field )->global_y_offset ;
	long *  global_z_offset = 	( sample_field )->global_z_offset ;
	long *  global_id = 	( sample_field )->global_id ;
	long  global_pid = 	( sample_field )->global_pid ;
	long *  adj_ids = 	( sample_field )->adj_ids ;
	long *  adj_processes = 	( sample_field )->adj_processes ;
	long *  adj_local_tid = 	( sample_field )->adj_local_tid ;
	void *  main_data = 	( sample_field )->main_data ;
	double  delta_x = 	( sample_field )->delta_x ;
	double  delta_y = 	( sample_field )->delta_y ;
	double  delta_z = 	( sample_field )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( sample_field )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( sample_field )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( sample_field )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( sample_field )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( sample_field )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( sample_field )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( sample_field )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( sample_field )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( sample_field )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( sample_field )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( sample_field )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( sample_field )->blas_sum_kernel ;
	long  rxlen = ovlp ;
	long  rylen = ovlp ;
	long  rzlen = ovlp ;
	if (  	(  xyzx == 1 )  ){  
		(rxlen = xlen);

	}else{
		0;

	 }
	if (  	(  xyzy == 1 )  ){  
		(rylen = ylen);

	}else{
		0;

	 }
	if (  	(  xyzz == 1 )  ){  
		(rzlen = zlen);

	}else{
		0;

	 }
((pthis->sync_layer_len)[	(  0 + 	(  1 * 	(  xyzx + 	(  3 * 	(  xyzy + 	(  3 * xyzz ) ) ) ) ) )] = 	(  rxlen * 	(  rylen * 	(  rzlen * num_ele ) ) ));
}}}}}}	free ( ovvec );
	free ( ori_vec );
	return  0 ;}
int  command_flush_Field3D_MPI (Field3D_MPI *  pthis ){
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
	command_flush_Field3D_Seq ( 	(  data + i ) );
}	return  0 ;}
int  delete_Field3D_MPI (Field3D_MPI *  pthis ){
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
	delete_Field3D_Seq ( 	(  data + i ) );
}	return  0 ;}
void  init_external_field3d_E (Field3D_MPI *  pthis ){
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
	char *  nm = "E_file" ;
	FILE *  fp = 	fopen ( nm , "r" ) ;
	if (  fp  ){  
			fclose ( fp );
	fprintf ( stderr , "found %s for input\n" , nm );
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	GAPS_IO_InitIFile ( pgid , nm );
{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
	if (  1  ){  
		{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
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
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + 0 ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
	assert ( 	(  	( pgid )->dim == 4 ) );
	assert ( 	(  	( pgid )->version == 0 ) );
	assert ( 	(  	( pgid )->type == GAPS_IO_FLOAT64 ) );
	assert ( 	(  (	( pgid )->pdimarray)[0] == num_ele ) );
	long  imax = (	( pgid )->pdimarray)[1] ;
	long  jmax = (	( pgid )->pdimarray)[2] ;
	long  kmax = (	( pgid )->pdimarray)[3] ;
	GAPS_IO_DataSeek ( pgid , 0 , 	(  num_ele * 	(  is + 	(  imax * 	(  js + 	(  jmax * ks ) ) ) ) ) );
	GAPS_IO_FRead ( pgid , 	& ( ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  0 + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] ) , 	(  num_ele * xlen ) );
}}}}}}}}
	}else{
		{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 	(  zlen + 	(  2 * ovlp ) ) ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 	(  ylen + 	(  2 * ovlp ) ) ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + 0 ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
	assert ( 	(  	( pgid )->dim == 4 ) );
	assert ( 	(  	( pgid )->version == 0 ) );
	assert ( 	(  	( pgid )->type == GAPS_IO_FLOAT64 ) );
	assert ( 	(  (	( pgid )->pdimarray)[0] == num_ele ) );
	long  imax = (	( pgid )->pdimarray)[1] ;
	long  jmax = (	( pgid )->pdimarray)[2] ;
	long  kmax = (	( pgid )->pdimarray)[3] ;
	GAPS_IO_DataSeek ( pgid , 0 , 	(  num_ele * 	(  is + 	(  imax * 	(  js + 	(  jmax * ks ) ) ) ) ) );
	GAPS_IO_FRead ( pgid , 	& ( ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  	- ( ovlp ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  	(  xyzy - ovlp ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  	(  xyzz - ovlp ) + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] ) , 	(  num_ele * 	(  xlen + 	(  2 * ovlp ) ) ) );
}}}}}}}}
	 }
}}
	}else{
		{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
{
	long  xyzz ;
	for ((xyzz = 	- ( ovlp )) ; 	(  xyzz < 	(  zlen + ovlp ) ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 	- ( ovlp )) ; 	(  xyzy < 	(  ylen + ovlp ) ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 	- ( ovlp )) ; 	(  xyzx < 	(  xlen + ovlp ) ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + xyzx ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
{
	long  l ;
	for ((l = 0) ; 	(  l < num_ele ) ; (l = 	(  l + 1 )))
	{
(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  l + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  xyzx + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] = 	call_GET_INIT_E ( ks , js , is , l ));
}}}}}}}}}}}}
	 }
}
void  init_external_field3d_B (Field3D_MPI *  pthis ){
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
	char *  nm = "B_file" ;
	FILE *  fp = 	fopen ( nm , "r" ) ;
	if (  fp  ){  
			fclose ( fp );
	fprintf ( stderr , "found %s for input\n" , nm );
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	GAPS_IO_InitIFile ( pgid , nm );
{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
	if (  1  ){  
		{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
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
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + 0 ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
	assert ( 	(  	( pgid )->dim == 4 ) );
	assert ( 	(  	( pgid )->version == 0 ) );
	assert ( 	(  	( pgid )->type == GAPS_IO_FLOAT64 ) );
	assert ( 	(  (	( pgid )->pdimarray)[0] == num_ele ) );
	long  imax = (	( pgid )->pdimarray)[1] ;
	long  jmax = (	( pgid )->pdimarray)[2] ;
	long  kmax = (	( pgid )->pdimarray)[3] ;
	GAPS_IO_DataSeek ( pgid , 0 , 	(  num_ele * 	(  is + 	(  imax * 	(  js + 	(  jmax * ks ) ) ) ) ) );
	GAPS_IO_FRead ( pgid , 	& ( ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  0 + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] ) , 	(  num_ele * xlen ) );
}}}}}}}}
	}else{
		{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 	(  zlen + 	(  2 * ovlp ) ) ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 	(  ylen + 	(  2 * ovlp ) ) ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + 0 ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
	assert ( 	(  	( pgid )->dim == 4 ) );
	assert ( 	(  	( pgid )->version == 0 ) );
	assert ( 	(  	( pgid )->type == GAPS_IO_FLOAT64 ) );
	assert ( 	(  (	( pgid )->pdimarray)[0] == num_ele ) );
	long  imax = (	( pgid )->pdimarray)[1] ;
	long  jmax = (	( pgid )->pdimarray)[2] ;
	long  kmax = (	( pgid )->pdimarray)[3] ;
	GAPS_IO_DataSeek ( pgid , 0 , 	(  num_ele * 	(  is + 	(  imax * 	(  js + 	(  jmax * ks ) ) ) ) ) );
	GAPS_IO_FRead ( pgid , 	& ( ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  	- ( ovlp ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  	(  xyzy - ovlp ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  	(  xyzz - ovlp ) + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] ) , 	(  num_ele * 	(  xlen + 	(  2 * ovlp ) ) ) );
}}}}}}}}
	 }
}}
	}else{
		{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
{
	long  xyzz ;
	for ((xyzz = 	- ( ovlp )) ; 	(  xyzz < 	(  zlen + ovlp ) ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 	- ( ovlp )) ; 	(  xyzy < 	(  ylen + ovlp ) ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 	- ( ovlp )) ; 	(  xyzx < 	(  xlen + ovlp ) ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + xyzx ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
{
	long  l ;
	for ((l = 0) ; 	(  l < num_ele ) ; (l = 	(  l + 1 )))
	{
(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  l + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  xyzx + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] = 	call_GET_INIT_B ( ks , js , is , l ));
}}}}}}}}}}}}
	 }
}
void  init_external_field3d_E0 (Field3D_MPI *  pthis ){
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
	char *  nm = "E0_file" ;
	FILE *  fp = 	fopen ( nm , "r" ) ;
	if (  fp  ){  
			fclose ( fp );
	fprintf ( stderr , "found %s for input\n" , nm );
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	GAPS_IO_InitIFile ( pgid , nm );
{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
	if (  1  ){  
		{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
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
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + 0 ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
	assert ( 	(  	( pgid )->dim == 4 ) );
	assert ( 	(  	( pgid )->version == 0 ) );
	assert ( 	(  	( pgid )->type == GAPS_IO_FLOAT64 ) );
	assert ( 	(  (	( pgid )->pdimarray)[0] == num_ele ) );
	long  imax = (	( pgid )->pdimarray)[1] ;
	long  jmax = (	( pgid )->pdimarray)[2] ;
	long  kmax = (	( pgid )->pdimarray)[3] ;
	GAPS_IO_DataSeek ( pgid , 0 , 	(  num_ele * 	(  is + 	(  imax * 	(  js + 	(  jmax * ks ) ) ) ) ) );
	GAPS_IO_FRead ( pgid , 	& ( ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  0 + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] ) , 	(  num_ele * xlen ) );
}}}}}}}}
	}else{
		{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 	(  zlen + 	(  2 * ovlp ) ) ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 	(  ylen + 	(  2 * ovlp ) ) ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + 0 ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
	assert ( 	(  	( pgid )->dim == 4 ) );
	assert ( 	(  	( pgid )->version == 0 ) );
	assert ( 	(  	( pgid )->type == GAPS_IO_FLOAT64 ) );
	assert ( 	(  (	( pgid )->pdimarray)[0] == num_ele ) );
	long  imax = (	( pgid )->pdimarray)[1] ;
	long  jmax = (	( pgid )->pdimarray)[2] ;
	long  kmax = (	( pgid )->pdimarray)[3] ;
	GAPS_IO_DataSeek ( pgid , 0 , 	(  num_ele * 	(  is + 	(  imax * 	(  js + 	(  jmax * ks ) ) ) ) ) );
	GAPS_IO_FRead ( pgid , 	& ( ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  	- ( ovlp ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  	(  xyzy - ovlp ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  	(  xyzz - ovlp ) + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] ) , 	(  num_ele * 	(  xlen + 	(  2 * ovlp ) ) ) );
}}}}}}}}
	 }
}}
	}else{
		{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
{
	long  xyzz ;
	for ((xyzz = 	- ( ovlp )) ; 	(  xyzz < 	(  zlen + ovlp ) ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 	- ( ovlp )) ; 	(  xyzy < 	(  ylen + ovlp ) ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 	- ( ovlp )) ; 	(  xyzx < 	(  xlen + ovlp ) ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + xyzx ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
{
	long  l ;
	for ((l = 0) ; 	(  l < num_ele ) ; (l = 	(  l + 1 )))
	{
(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  l + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  xyzx + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] = 	call_GET_INIT_E0 ( ks , js , is , l ));
}}}}}}}}}}}}
	 }
}
void  init_external_field3d_B0 (Field3D_MPI *  pthis ){
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
	char *  nm = "B0_file" ;
	FILE *  fp = 	fopen ( nm , "r" ) ;
	if (  fp  ){  
			fclose ( fp );
	fprintf ( stderr , "found %s for input\n" , nm );
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	GAPS_IO_InitIFile ( pgid , nm );
{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
	if (  1  ){  
		{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
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
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + 0 ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
	assert ( 	(  	( pgid )->dim == 4 ) );
	assert ( 	(  	( pgid )->version == 0 ) );
	assert ( 	(  	( pgid )->type == GAPS_IO_FLOAT64 ) );
	assert ( 	(  (	( pgid )->pdimarray)[0] == num_ele ) );
	long  imax = (	( pgid )->pdimarray)[1] ;
	long  jmax = (	( pgid )->pdimarray)[2] ;
	long  kmax = (	( pgid )->pdimarray)[3] ;
	GAPS_IO_DataSeek ( pgid , 0 , 	(  num_ele * 	(  is + 	(  imax * 	(  js + 	(  jmax * ks ) ) ) ) ) );
	GAPS_IO_FRead ( pgid , 	& ( ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  0 + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] ) , 	(  num_ele * xlen ) );
}}}}}}}}
	}else{
		{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 	(  zlen + 	(  2 * ovlp ) ) ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 	(  ylen + 	(  2 * ovlp ) ) ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + 0 ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
	assert ( 	(  	( pgid )->dim == 4 ) );
	assert ( 	(  	( pgid )->version == 0 ) );
	assert ( 	(  	( pgid )->type == GAPS_IO_FLOAT64 ) );
	assert ( 	(  (	( pgid )->pdimarray)[0] == num_ele ) );
	long  imax = (	( pgid )->pdimarray)[1] ;
	long  jmax = (	( pgid )->pdimarray)[2] ;
	long  kmax = (	( pgid )->pdimarray)[3] ;
	GAPS_IO_DataSeek ( pgid , 0 , 	(  num_ele * 	(  is + 	(  imax * 	(  js + 	(  jmax * ks ) ) ) ) ) );
	GAPS_IO_FRead ( pgid , 	& ( ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  	- ( ovlp ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  	(  xyzy - ovlp ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  	(  xyzz - ovlp ) + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] ) , 	(  num_ele * 	(  xlen + 	(  2 * ovlp ) ) ) );
}}}}}}}}
	 }
}}
	}else{
		{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
{
	long  xyzz ;
	for ((xyzz = 	- ( ovlp )) ; 	(  xyzz < 	(  zlen + ovlp ) ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 	- ( ovlp )) ; 	(  xyzy < 	(  ylen + ovlp ) ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 	- ( ovlp )) ; 	(  xyzx < 	(  xlen + ovlp ) ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + xyzx ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
{
	long  l ;
	for ((l = 0) ; 	(  l < num_ele ) ; (l = 	(  l + 1 )))
	{
(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  l + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  xyzx + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] = 	call_GET_INIT_B0 ( ks , js , is , l ));
}}}}}}}}}}}}
	 }
}
void  init_external_field3d_FILTER_E (Field3D_MPI *  pthis ){
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
	char *  nm = "FILTER_E_file" ;
	FILE *  fp = 	fopen ( nm , "r" ) ;
	if (  fp  ){  
			fclose ( fp );
	fprintf ( stderr , "found %s for input\n" , nm );
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	GAPS_IO_InitIFile ( pgid , nm );
{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
	if (  1  ){  
		{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
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
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + 0 ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
	assert ( 	(  	( pgid )->dim == 4 ) );
	assert ( 	(  	( pgid )->version == 0 ) );
	assert ( 	(  	( pgid )->type == GAPS_IO_FLOAT64 ) );
	assert ( 	(  (	( pgid )->pdimarray)[0] == num_ele ) );
	long  imax = (	( pgid )->pdimarray)[1] ;
	long  jmax = (	( pgid )->pdimarray)[2] ;
	long  kmax = (	( pgid )->pdimarray)[3] ;
	GAPS_IO_DataSeek ( pgid , 0 , 	(  num_ele * 	(  is + 	(  imax * 	(  js + 	(  jmax * ks ) ) ) ) ) );
	GAPS_IO_FRead ( pgid , 	& ( ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  0 + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] ) , 	(  num_ele * xlen ) );
}}}}}}}}
	}else{
		{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 	(  zlen + 	(  2 * ovlp ) ) ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 	(  ylen + 	(  2 * ovlp ) ) ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + 0 ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
	assert ( 	(  	( pgid )->dim == 4 ) );
	assert ( 	(  	( pgid )->version == 0 ) );
	assert ( 	(  	( pgid )->type == GAPS_IO_FLOAT64 ) );
	assert ( 	(  (	( pgid )->pdimarray)[0] == num_ele ) );
	long  imax = (	( pgid )->pdimarray)[1] ;
	long  jmax = (	( pgid )->pdimarray)[2] ;
	long  kmax = (	( pgid )->pdimarray)[3] ;
	GAPS_IO_DataSeek ( pgid , 0 , 	(  num_ele * 	(  is + 	(  imax * 	(  js + 	(  jmax * ks ) ) ) ) ) );
	GAPS_IO_FRead ( pgid , 	& ( ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  	- ( ovlp ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  	(  xyzy - ovlp ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  	(  xyzz - ovlp ) + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] ) , 	(  num_ele * 	(  xlen + 	(  2 * ovlp ) ) ) );
}}}}}}}}
	 }
}}
	}else{
		{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
{
	long  xyzz ;
	for ((xyzz = 	- ( ovlp )) ; 	(  xyzz < 	(  zlen + ovlp ) ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 	- ( ovlp )) ; 	(  xyzy < 	(  ylen + ovlp ) ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 	- ( ovlp )) ; 	(  xyzx < 	(  xlen + ovlp ) ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + xyzx ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
{
	long  l ;
	for ((l = 0) ; 	(  l < num_ele ) ; (l = 	(  l + 1 )))
	{
(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  l + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  xyzx + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] = 	call_GET_INIT_FILTER_E ( ks , js , is , l ));
}}}}}}}}}}}}
	 }
}
void  init_external_field3d_FILTER_B (Field3D_MPI *  pthis ){
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
	char *  nm = "FILTER_B_file" ;
	FILE *  fp = 	fopen ( nm , "r" ) ;
	if (  fp  ){  
			fclose ( fp );
	fprintf ( stderr , "found %s for input\n" , nm );
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	GAPS_IO_InitIFile ( pgid , nm );
{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
	if (  1  ){  
		{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
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
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + 0 ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
	assert ( 	(  	( pgid )->dim == 4 ) );
	assert ( 	(  	( pgid )->version == 0 ) );
	assert ( 	(  	( pgid )->type == GAPS_IO_FLOAT64 ) );
	assert ( 	(  (	( pgid )->pdimarray)[0] == num_ele ) );
	long  imax = (	( pgid )->pdimarray)[1] ;
	long  jmax = (	( pgid )->pdimarray)[2] ;
	long  kmax = (	( pgid )->pdimarray)[3] ;
	GAPS_IO_DataSeek ( pgid , 0 , 	(  num_ele * 	(  is + 	(  imax * 	(  js + 	(  jmax * ks ) ) ) ) ) );
	GAPS_IO_FRead ( pgid , 	& ( ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  0 + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] ) , 	(  num_ele * xlen ) );
}}}}}}}}
	}else{
		{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 	(  zlen + 	(  2 * ovlp ) ) ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 	(  ylen + 	(  2 * ovlp ) ) ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + 0 ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
	assert ( 	(  	( pgid )->dim == 4 ) );
	assert ( 	(  	( pgid )->version == 0 ) );
	assert ( 	(  	( pgid )->type == GAPS_IO_FLOAT64 ) );
	assert ( 	(  (	( pgid )->pdimarray)[0] == num_ele ) );
	long  imax = (	( pgid )->pdimarray)[1] ;
	long  jmax = (	( pgid )->pdimarray)[2] ;
	long  kmax = (	( pgid )->pdimarray)[3] ;
	GAPS_IO_DataSeek ( pgid , 0 , 	(  num_ele * 	(  is + 	(  imax * 	(  js + 	(  jmax * ks ) ) ) ) ) );
	GAPS_IO_FRead ( pgid , 	& ( ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  	- ( ovlp ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  	(  xyzy - ovlp ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  	(  xyzz - ovlp ) + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] ) , 	(  num_ele * 	(  xlen + 	(  2 * ovlp ) ) ) );
}}}}}}}}
	 }
}}
	}else{
		{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
{
	long  xyzz ;
	for ((xyzz = 	- ( ovlp )) ; 	(  xyzz < 	(  zlen + ovlp ) ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 	- ( ovlp )) ; 	(  xyzy < 	(  ylen + ovlp ) ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 	- ( ovlp )) ; 	(  xyzx < 	(  xlen + ovlp ) ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + xyzx ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
{
	long  l ;
	for ((l = 0) ; 	(  l < num_ele ) ; (l = 	(  l + 1 )))
	{
(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  l + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  xyzx + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] = 	call_GET_INIT_FILTER_B ( ks , js , is , l ));
}}}}}}}}}}}}
	 }
}
void  init_external_field3d_FILTER_KROOK (Field3D_MPI *  pthis ){
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
	char *  nm = "FILTER_KROOK_file" ;
	FILE *  fp = 	fopen ( nm , "r" ) ;
	if (  fp  ){  
			fclose ( fp );
	fprintf ( stderr , "found %s for input\n" , nm );
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	GAPS_IO_InitIFile ( pgid , nm );
{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
	if (  1  ){  
		{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
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
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + 0 ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
	assert ( 	(  	( pgid )->dim == 4 ) );
	assert ( 	(  	( pgid )->version == 0 ) );
	assert ( 	(  	( pgid )->type == GAPS_IO_FLOAT64 ) );
	assert ( 	(  (	( pgid )->pdimarray)[0] == num_ele ) );
	long  imax = (	( pgid )->pdimarray)[1] ;
	long  jmax = (	( pgid )->pdimarray)[2] ;
	long  kmax = (	( pgid )->pdimarray)[3] ;
	GAPS_IO_DataSeek ( pgid , 0 , 	(  num_ele * 	(  is + 	(  imax * 	(  js + 	(  jmax * ks ) ) ) ) ) );
	GAPS_IO_FRead ( pgid , 	& ( ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  0 + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] ) , 	(  num_ele * xlen ) );
}}}}}}}}
	}else{
		{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 	(  zlen + 	(  2 * ovlp ) ) ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 	(  ylen + 	(  2 * ovlp ) ) ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + 0 ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
	assert ( 	(  	( pgid )->dim == 4 ) );
	assert ( 	(  	( pgid )->version == 0 ) );
	assert ( 	(  	( pgid )->type == GAPS_IO_FLOAT64 ) );
	assert ( 	(  (	( pgid )->pdimarray)[0] == num_ele ) );
	long  imax = (	( pgid )->pdimarray)[1] ;
	long  jmax = (	( pgid )->pdimarray)[2] ;
	long  kmax = (	( pgid )->pdimarray)[3] ;
	GAPS_IO_DataSeek ( pgid , 0 , 	(  num_ele * 	(  is + 	(  imax * 	(  js + 	(  jmax * ks ) ) ) ) ) );
	GAPS_IO_FRead ( pgid , 	& ( ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  	- ( ovlp ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  	(  xyzy - ovlp ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  	(  xyzz - ovlp ) + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] ) , 	(  num_ele * 	(  xlen + 	(  2 * ovlp ) ) ) );
}}}}}}}}
	 }
}}
	}else{
		{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
{
	long  xyzz ;
	for ((xyzz = 	- ( ovlp )) ; 	(  xyzz < 	(  zlen + ovlp ) ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 	- ( ovlp )) ; 	(  xyzy < 	(  ylen + ovlp ) ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 	- ( ovlp )) ; 	(  xyzx < 	(  xlen + ovlp ) ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + xyzx ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
{
	long  l ;
	for ((l = 0) ; 	(  l < num_ele ) ; (l = 	(  l + 1 )))
	{
(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  l + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  xyzx + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] = 	call_GET_INIT_FILTER_KROOK ( ks , js , is , l ));
}}}}}}}}}}}}
	 }
}
void  init_external_field3d_without_ss_KGM (Field3D_MPI *  pthis ){
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
	char *  nm = "KGM_file" ;
	FILE *  fp = 	fopen ( nm , "r" ) ;
	if (  fp  ){  
			fclose ( fp );
	fprintf ( stderr , "found %s for input\n" , nm );
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	GAPS_IO_InitIFile ( pgid , nm );
{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
	if (  1  ){  
		{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
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
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + 0 ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
	assert ( 	(  	( pgid )->dim == 4 ) );
	assert ( 	(  	( pgid )->version == 0 ) );
	assert ( 	(  	( pgid )->type == GAPS_IO_FLOAT64 ) );
	assert ( 	(  (	( pgid )->pdimarray)[0] == num_ele ) );
	long  imax = (	( pgid )->pdimarray)[1] ;
	long  jmax = (	( pgid )->pdimarray)[2] ;
	long  kmax = (	( pgid )->pdimarray)[3] ;
	GAPS_IO_DataSeek ( pgid , 0 , 	(  num_ele * 	(  is + 	(  imax * 	(  js + 	(  jmax * ks ) ) ) ) ) );
	GAPS_IO_FRead ( pgid , 	& ( ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  0 + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] ) , 	(  num_ele * xlen ) );
}}}}}}}}
	}else{
		{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 	(  zlen + 	(  2 * ovlp ) ) ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 	(  ylen + 	(  2 * ovlp ) ) ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < 1 ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + 0 ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
	assert ( 	(  	( pgid )->dim == 4 ) );
	assert ( 	(  	( pgid )->version == 0 ) );
	assert ( 	(  	( pgid )->type == GAPS_IO_FLOAT64 ) );
	assert ( 	(  (	( pgid )->pdimarray)[0] == num_ele ) );
	long  imax = (	( pgid )->pdimarray)[1] ;
	long  jmax = (	( pgid )->pdimarray)[2] ;
	long  kmax = (	( pgid )->pdimarray)[3] ;
	GAPS_IO_DataSeek ( pgid , 0 , 	(  num_ele * 	(  is + 	(  imax * 	(  js + 	(  jmax * ks ) ) ) ) ) );
	GAPS_IO_FRead ( pgid , 	& ( ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  	- ( ovlp ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  	(  xyzy - ovlp ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  	(  xyzz - ovlp ) + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] ) , 	(  num_ele * 	(  xlen + 	(  2 * ovlp ) ) ) );
}}}}}}}}
	 }
}}
	}else{
		{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
{
	long  xyzz ;
	for ((xyzz = 	- ( ovlp )) ; 	(  xyzz < 	(  zlen + ovlp ) ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 	- ( ovlp )) ; 	(  xyzy < 	(  ylen + ovlp ) ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 	- ( ovlp )) ; 	(  xyzx < 	(  xlen + ovlp ) ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  is = 	(  (global_x_offset)[j] + xyzx ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
{
	long  l ;
	for ((l = 0) ; 	(  l < num_ele ) ; (l = 	(  l + 1 )))
	{
(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  l + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  xyzx + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] = ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  l + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  xyzx + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )]);
}}}}}}}}}}}}
	 }
}
void  init_dm_phi_global (Field3D_MPI *  pthis ,double  phi_r1 ,double  phi_r2 ,double  phi_r3 ,double  phi_r4 ,double  phi_i1 ,double  phi_i2 ,double  phi_i3 ,double  phi_i4 ,double  sgm ,double  frq ){
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
{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
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
	long  ks = 	(  (global_x_offset)[j] + xyzx ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  is = 	(  (global_z_offset)[j] + xyzz ) ;
{
	long  ls ;
	for ((ls = 0) ; 	(  ls < num_ele ) ; (ls = 	(  ls + 1 )))
	{
(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  ls + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  xyzx + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] = ((	(  ls == 0 ))?(	(  phi_r1 + 	rand01 ( 	- ( sgm ) , sgm ) )):(0)));
}}}}}}}}}}}}}
void  init_dm_A0_global (Field3D_MPI *  pthis ,double  ampEy ,double  dt ){
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
{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
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
	long  ks = 	(  (global_x_offset)[j] + xyzx ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  is = 	(  (global_z_offset)[j] + xyzz ) ;
{
	long  ls ;
	for ((ls = 0) ; 	(  ls < num_ele ) ; (ls = 	(  ls + 1 )))
	{
(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  ls + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  xyzx + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] = 0);
}}}}}}}}}}}}}
void  init_dm_A1_global (Field3D_MPI *  pthis ,double  ampx ,double  ampEy ,double  dt ){
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
{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
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
	long  ks = 	(  (global_x_offset)[j] + xyzx ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  is = 	(  (global_z_offset)[j] + xyzz ) ;
{
	long  ls ;
	for ((ls = 0) ; 	(  ls < num_ele ) ; (ls = 	(  ls + 1 )))
	{
(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  ls + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  xyzx + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] = ((	(  ls == 0 ))?(	(  	rand01 ( 	- ( ampx ) , ampx ) * dt )):(0)));
}}}}}}}}}}}}}
void  init_kgm_assemble (Field3D_MPI *  pthis ,double  ampx ,double  ampEy ,double  dt ,double  sgm ,double  frq ,double  kgm_ass_e_loc0 ){
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
{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
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
	long  ks = 	(  (global_x_offset)[j] + xyzx ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  is = 	(  (global_z_offset)[j] + xyzz ) ;
	double  E1 = 	(  	(  ampEy * 	(  	exp ( 	(  	pow ( 	(  ks - kgm_ass_e_loc0 ) , 2 ) / 	(  sgm * 	(  sgm * -2 ) ) ) ) * 	sin ( 	(  ks * frq ) ) ) ) / frq ) ;
	double  ks1 = 	(  ks - dt ) ;
	double  E0 = 	(  	(  ampEy * 	(  	exp ( 	(  	pow ( 	(  ks1 - kgm_ass_e_loc0 ) , 2 ) / 	(  sgm * 	(  sgm * -2 ) ) ) ) * 	sin ( 	(  ks1 * frq ) ) ) ) / frq ) ;
{
	long  ls ;
	for ((ls = 0) ; 	(  ls < num_ele ) ; (ls = 	(  ls + 1 )))
	{
(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  ls + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  xyzx + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] = ((	(  ls == 1 ))?(E0):(((	(  ls == 6 ))?(E1):(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  ls + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  xyzx + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )])))));
}}}}}}}}}}}}}
void  init_kgm_global (Field3D_MPI *  pthis ,double  phi_r0 ,double  m0 ,double  e0 ,double  ampx ,double  ampEy ,double  dt ,double  sgm ,double  frq ,double  kgm_mid ,double  kgm_len_a0 ,double  kgm_sgm_dens ,double  use_sper ,double  xmid ,double  ymid ,double  zmid ){
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
{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
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
	long  ks = 	(  (global_x_offset)[j] + xyzx ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  is = 	(  (global_z_offset)[j] + xyzz ) ;
	double  p0 ;
	long  mid = 	abs ( 	(  ks - kgm_mid ) ) ;
	double  a0 = kgm_len_a0 ;
	if (  	(  mid < a0 )  ){  
		(p0 = phi_r0);

	}else{
		(p0 = ({
	double  c0 = 	(  mid - a0 ) ;
	(  phi_r0 * 	exp ( 	- ( 	(  	(  c0 * c0 ) / kgm_sgm_dens ) ) ) );
}));

	 }
	double  rx = 	(  ks - xmid ) ;
	double  ry = 	(  js - ymid ) ;
	double  rz = 	(  is - zmid ) ;
	if (  	(  use_sper == 1 )  ){  
		(p0 = 	(  phi_r0 * 	exp ( 	- ( 	(  	(  	(  rx * rx ) + 	(  	(  ry * ry ) + 	(  rz * rz ) ) ) / 	(  2 * 	(  kgm_sgm_dens * kgm_sgm_dens ) ) ) ) ) ));

	}else{
		0;

	 }
	double  E1 = 	(  ampEy * 	(  	exp ( 	(  	pow ( 	(  ks - 64 ) , 2 ) / 	(  sgm * 	(  sgm * -2 ) ) ) ) * 	sin ( 	(  ks * frq ) ) ) ) ;
	double  E0 = 0 ;
{
	long  ls ;
	for ((ls = 0) ; 	(  ls < num_ele ) ; (ls = 	(  ls + 1 )))
	{
(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  ls + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  xyzx + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] = ((	(  use_sper == 0 ))?(((	(  ls == 0 ))?(	(  E0 * dt )):(((	(  ls == 1 ))?(	(  E1 * dt )):(((	(  ls == 3 ))?(p0):(((	(  ls == 4 ))?(	(  p0 * 	(  m0 * dt ) )):(((	(  ls == 5 ))?(0):(((	(  ls == 8 ))?(p0):(((	(  ls == 9 ))?(0):(0))))))))))))))):(((	(  use_sper == 1 ))?(((	(  ls == 3 ))?(p0):(((	(  ls == 4 ))?(	(  p0 * 	(  m0 * dt ) )):(((	(  ls == 4 ))?(0):(((	(  ls == 8 ))?(p0):(0))))))))):(0)))));
}}}}}}}}}}}}}
int  set_ecrh_fields (Field3D_MPI *  pthis ,double  tomega ,double  ampx ,double  ampy ,double  ampz ,double  ky ,double  kz ,double  ikt ,long  x0 ,double  y0 ,double  y1 ,double  z0 ,double  z1 ){
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
{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
	long  ofx = (global_x_offset)[j] ;
	long  ofy = (global_y_offset)[j] ;
	long  ofz = (global_z_offset)[j] ;
	if (  	(  	(  x0 < 	(  ofx + xlen ) ) && 	(  x0 >= ofx ) )  ){  
		{
	long  idy ;
	for ((idy = 0) ; 	(  idy < ylen ) ; (idy = 	(  idy + 1 )))
	{
{
	long  idz ;
	for ((idz = 0) ; 	(  idz < zlen ) ; (idz = 	(  idz + 1 )))
	{
	long  oy = 	(  idy + ofy ) ;
	long  oz = 	(  idz + ofz ) ;
	if (  	(  	(  oy >= y0 ) && 	(  	(  oy < y1 ) && 	(  	(  oz >= z0 ) && 	(  oz < z1 ) ) ) )  ){  
			double  kyy = 	(  	(  ky * 	(  oy - y0 ) ) / 	(  y1 - y0 ) ) ;
	double  kyz = 	(  	(  kz * 	(  oz - z0 ) ) / 	(  z1 - z0 ) ) ;
	double  kall = 	(  kyy + kyz ) ;
	double  phs = 	(  tomega - 	(  2 * 	(  M_PI * kall ) ) ) ;
	double  coef = 	(  1 - 	exp ( 	(  -1 * 	(  tomega * ikt ) ) ) ) ;
(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  	(  x0 - ofx ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  idy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  idz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] = 	(  ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  	(  x0 - ofx ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  idy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  idz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] + 	(  ampx * 	(  	sin ( phs ) * coef ) ) ));
(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  1 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  	(  x0 - ofx ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  idy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  idz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] = 	(  ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  1 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  	(  x0 - ofx ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  idy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  idz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] + 	(  ampy * 	(  	sin ( phs ) * coef ) ) ));
(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  2 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  	(  x0 - ofx ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  idy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  idz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] = 	(  ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  2 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  	(  x0 - ofx ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  idy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  idz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] + 	(  ampz * 	(  	sin ( phs ) * coef ) ) ));

	}else{
		0;

	 }
}}}}
	}else{
		0;

	 }
}}}}	return  0 ;}
int  set_lhcd_fields (Field3D_MPI *  pthis ,double  tomega ,double  k ,long  location ,double  ampx ,double  ampy ){
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
{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
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
{
	long  j ;
	for ((j = 0) ; 	(  j < numvec ) ; (j = 	(  j + 1 )))
	{
	long  ofx = (global_x_offset)[j] ;
	long  ofy = (global_y_offset)[j] ;
	if (  	(  	(  location < 	(  ofx + xlen ) ) && 	(  location >= ofx ) )  ){  
		{
	long  idy ;
	for ((idy = 0) ; 	(  idy < ylen ) ; (idy = 	(  idy + 1 )))
	{
	double  kyy = 	(  	(  k * 	(  idy + ofy ) ) / 	(  ylen * y_num_thread_block ) ) ;
(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  	(  location - ofx ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  idy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  0 + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] = 	(  ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  0 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  	(  location - ofx ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  idy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  0 + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] + 	(  ampx * 	sin ( 	(  tomega + 	(  2 * 	(  M_PI * kyy ) ) ) ) ) ));
(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  1 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  	(  location - ofx ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  idy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  0 + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] = 	(  ((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  1 + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  	(  location - ofx ) + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  idy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  0 + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] + 	(  ampy * 	sin ( 	(  tomega + 	(  2 * 	(  M_PI * kyy ) ) ) ) ) ));
}}
	}else{
		0;

	 }
}}}}	return  0 ;}
int  test_set_mainland (Field3D_MPI *  pthis ,double  val ){
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
	long  j = 0 ;
	for (j=0 ; j<numvec ; j++)
	{
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
	long  l = 0 ;
	long  is = 	(  (global_x_offset)[j] + xyzx ) ;
	long  js = 	(  (global_y_offset)[j] + xyzy ) ;
	long  ks = 	(  (global_z_offset)[j] + xyzz ) ;
	for (l=0 ; l<num_ele ; l++)
	{
(((((double * * )	( 	(  data + i ) )->main_data))[0])[	(  	(  j * 	(  	( 	(  data + i ) )->xblock * 	(  	( 	(  data + i ) )->yblock * 	(  	( 	(  data + i ) )->zblock * 	( 	(  data + i ) )->num_ele ) ) ) ) + 	(  l + 	(  	( 	(  data + i ) )->num_ele * 	(  	(  xyzx + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->xblock * 	(  	(  xyzy + 	( 	(  data + i ) )->ovlp ) + 	(  	( 	(  data + i ) )->yblock * 	(  xyzz + 	( 	(  data + i ) )->ovlp ) ) ) ) ) ) ) )] = 	(  val * 	(  1 * 	(  0 == l ) ) ));
}}}}}}}}}	return  0 ;}
