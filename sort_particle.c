#include <stdio.h>
#include <stdlib.h>
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
#include <assert.h>
#include <math.h>
int  c_call_particle_sort_single_x (One_Particle_Collection *  pthis ){
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
	long  the_xlen = 	c_pscmc_get_local_len (  ) ;
	long  XLEN = xlen ;
	long  YLEN = ylen ;
	long  ZLEN = zlen ;
	c_sort_one_grid_x_scmc_set_parameter_inoutput ( (sort_kernel)[0] , inoutput );
	c_sort_one_grid_x_scmc_set_parameter_xyzw ( (sort_kernel)[0] , xyzw );
	c_sort_one_grid_x_scmc_set_parameter_cu_cache ( (sort_kernel)[0] , cu_cache );
	c_sort_one_grid_x_scmc_set_parameter_cu_xyzw ( (sort_kernel)[0] , cu_xyzw );
	c_sort_one_grid_x_scmc_set_parameter_adjoint_vec_pids ( (sort_kernel)[0] , adjoint_vec_pids );
	c_cu_swap_l_scmc_set_parameter_cu_cache ( cu_swap_l_kernel , cu_cache );
	c_cu_swap_r_scmc_set_parameter_cu_cache ( cu_swap_r_kernel , cu_cache );
	c_cu_swap_l_scmc_set_parameter_cu_xyzw ( cu_swap_l_kernel , cu_xyzw );
	c_cu_swap_r_scmc_set_parameter_cu_xyzw ( cu_swap_r_kernel , cu_xyzw );
	c_cu_swap_l_scmc_set_parameter_adjoint_vec_pids ( cu_swap_l_kernel , adjoint_vec_pids );
	c_cu_swap_r_scmc_set_parameter_adjoint_vec_pids ( cu_swap_r_kernel , adjoint_vec_pids );
	c_pscmc_mem  c_alloc_prefix_XLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XLEN ).h_data))[0] = XLEN);
	c_sort_one_grid_x_scmc_set_parameter_XLEN ( (sort_kernel)[0] , 	& ( c_alloc_prefix_XLEN ) );
	c_pscmc_mem  c_alloc_prefix_YLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_YLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_YLEN ).h_data))[0] = YLEN);
	c_sort_one_grid_x_scmc_set_parameter_YLEN ( (sort_kernel)[0] , 	& ( c_alloc_prefix_YLEN ) );
	c_pscmc_mem  c_alloc_prefix_ZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_ZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_ZLEN ).h_data))[0] = ZLEN);
	c_sort_one_grid_x_scmc_set_parameter_ZLEN ( (sort_kernel)[0] , 	& ( c_alloc_prefix_ZLEN ) );
	c_pscmc_mem  c_alloc_prefix_ovlp ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_ovlp ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_ovlp ).h_data))[0] = ovlp);
	c_sort_one_grid_x_scmc_set_parameter_ovlp ( (sort_kernel)[0] , 	& ( c_alloc_prefix_ovlp ) );
	c_pscmc_mem  c_alloc_prefix_numvec ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_numvec ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_numvec ).h_data))[0] = numvec);
	c_sort_one_grid_x_scmc_set_parameter_numvec ( (sort_kernel)[0] , 	& ( c_alloc_prefix_numvec ) );
	c_pscmc_mem  c_alloc_prefix_grid_cache_len ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_grid_cache_len ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_grid_cache_len ).h_data))[0] = grid_cache_len);
	c_sort_one_grid_x_scmc_set_parameter_grid_cache_len ( (sort_kernel)[0] , 	& ( c_alloc_prefix_grid_cache_len ) );
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_sort_one_grid_x_scmc_set_parameter_cu_cache_length ( (sort_kernel)[0] , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_sort_one_grid_x_exec ( (sort_kernel)[0] , the_xlen , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_YLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_ZLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_ovlp ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_numvec ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_grid_cache_len ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	long  XYZLEN = XLEN ;
	int  the_dir_num = 0 ;
{
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_cu_swap_l_scmc_set_parameter_cu_cache_length ( cu_swap_l_kernel , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem  c_alloc_prefix_the_dir_num ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	c_cu_swap_l_scmc_set_parameter_the_dir_num ( cu_swap_l_kernel , 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem  c_alloc_prefix_XYZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	c_cu_swap_l_scmc_set_parameter_XYZLEN ( cu_swap_l_kernel , 	& ( c_alloc_prefix_XYZLEN ) );
	c_cu_swap_l_exec ( cu_swap_l_kernel , 1 , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XYZLEN ) );
}(XYZLEN = 	- ( XYZLEN ));
{
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_cu_swap_r_scmc_set_parameter_cu_cache_length ( cu_swap_r_kernel , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem  c_alloc_prefix_the_dir_num ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	c_cu_swap_r_scmc_set_parameter_the_dir_num ( cu_swap_r_kernel , 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem  c_alloc_prefix_XYZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	c_cu_swap_r_scmc_set_parameter_XYZLEN ( cu_swap_r_kernel , 	& ( c_alloc_prefix_XYZLEN ) );
	c_cu_swap_r_exec ( cu_swap_r_kernel , 1 , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XYZLEN ) );
}	return  0 ;}
int  c_call_particle_sort_single_y (One_Particle_Collection *  pthis ){
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
	long  the_xlen = 	c_pscmc_get_local_len (  ) ;
	long  XLEN = xlen ;
	long  YLEN = ylen ;
	long  ZLEN = zlen ;
	c_sort_one_grid_y_scmc_set_parameter_inoutput ( (sort_kernel)[1] , inoutput );
	c_sort_one_grid_y_scmc_set_parameter_xyzw ( (sort_kernel)[1] , xyzw );
	c_sort_one_grid_y_scmc_set_parameter_cu_cache ( (sort_kernel)[1] , cu_cache );
	c_sort_one_grid_y_scmc_set_parameter_cu_xyzw ( (sort_kernel)[1] , cu_xyzw );
	c_sort_one_grid_y_scmc_set_parameter_adjoint_vec_pids ( (sort_kernel)[1] , adjoint_vec_pids );
	c_cu_swap_l_scmc_set_parameter_cu_cache ( cu_swap_l_kernel , cu_cache );
	c_cu_swap_r_scmc_set_parameter_cu_cache ( cu_swap_r_kernel , cu_cache );
	c_cu_swap_l_scmc_set_parameter_cu_xyzw ( cu_swap_l_kernel , cu_xyzw );
	c_cu_swap_r_scmc_set_parameter_cu_xyzw ( cu_swap_r_kernel , cu_xyzw );
	c_cu_swap_l_scmc_set_parameter_adjoint_vec_pids ( cu_swap_l_kernel , adjoint_vec_pids );
	c_cu_swap_r_scmc_set_parameter_adjoint_vec_pids ( cu_swap_r_kernel , adjoint_vec_pids );
	c_pscmc_mem  c_alloc_prefix_XLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XLEN ).h_data))[0] = XLEN);
	c_sort_one_grid_y_scmc_set_parameter_XLEN ( (sort_kernel)[1] , 	& ( c_alloc_prefix_XLEN ) );
	c_pscmc_mem  c_alloc_prefix_YLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_YLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_YLEN ).h_data))[0] = YLEN);
	c_sort_one_grid_y_scmc_set_parameter_YLEN ( (sort_kernel)[1] , 	& ( c_alloc_prefix_YLEN ) );
	c_pscmc_mem  c_alloc_prefix_ZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_ZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_ZLEN ).h_data))[0] = ZLEN);
	c_sort_one_grid_y_scmc_set_parameter_ZLEN ( (sort_kernel)[1] , 	& ( c_alloc_prefix_ZLEN ) );
	c_pscmc_mem  c_alloc_prefix_ovlp ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_ovlp ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_ovlp ).h_data))[0] = ovlp);
	c_sort_one_grid_y_scmc_set_parameter_ovlp ( (sort_kernel)[1] , 	& ( c_alloc_prefix_ovlp ) );
	c_pscmc_mem  c_alloc_prefix_numvec ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_numvec ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_numvec ).h_data))[0] = numvec);
	c_sort_one_grid_y_scmc_set_parameter_numvec ( (sort_kernel)[1] , 	& ( c_alloc_prefix_numvec ) );
	c_pscmc_mem  c_alloc_prefix_grid_cache_len ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_grid_cache_len ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_grid_cache_len ).h_data))[0] = grid_cache_len);
	c_sort_one_grid_y_scmc_set_parameter_grid_cache_len ( (sort_kernel)[1] , 	& ( c_alloc_prefix_grid_cache_len ) );
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_sort_one_grid_y_scmc_set_parameter_cu_cache_length ( (sort_kernel)[1] , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_sort_one_grid_y_exec ( (sort_kernel)[1] , the_xlen , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_YLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_ZLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_ovlp ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_numvec ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_grid_cache_len ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	long  XYZLEN = YLEN ;
	int  the_dir_num = 1 ;
{
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_cu_swap_l_scmc_set_parameter_cu_cache_length ( cu_swap_l_kernel , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem  c_alloc_prefix_the_dir_num ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	c_cu_swap_l_scmc_set_parameter_the_dir_num ( cu_swap_l_kernel , 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem  c_alloc_prefix_XYZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	c_cu_swap_l_scmc_set_parameter_XYZLEN ( cu_swap_l_kernel , 	& ( c_alloc_prefix_XYZLEN ) );
	c_cu_swap_l_exec ( cu_swap_l_kernel , 1 , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XYZLEN ) );
}(XYZLEN = 	- ( XYZLEN ));
{
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_cu_swap_r_scmc_set_parameter_cu_cache_length ( cu_swap_r_kernel , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem  c_alloc_prefix_the_dir_num ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	c_cu_swap_r_scmc_set_parameter_the_dir_num ( cu_swap_r_kernel , 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem  c_alloc_prefix_XYZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	c_cu_swap_r_scmc_set_parameter_XYZLEN ( cu_swap_r_kernel , 	& ( c_alloc_prefix_XYZLEN ) );
	c_cu_swap_r_exec ( cu_swap_r_kernel , 1 , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XYZLEN ) );
}	return  0 ;}
int  c_call_particle_sort_single_z (One_Particle_Collection *  pthis ){
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
	long  the_xlen = 	c_pscmc_get_local_len (  ) ;
	long  XLEN = xlen ;
	long  YLEN = ylen ;
	long  ZLEN = zlen ;
	c_sort_one_grid_z_scmc_set_parameter_inoutput ( (sort_kernel)[2] , inoutput );
	c_sort_one_grid_z_scmc_set_parameter_xyzw ( (sort_kernel)[2] , xyzw );
	c_sort_one_grid_z_scmc_set_parameter_cu_cache ( (sort_kernel)[2] , cu_cache );
	c_sort_one_grid_z_scmc_set_parameter_cu_xyzw ( (sort_kernel)[2] , cu_xyzw );
	c_sort_one_grid_z_scmc_set_parameter_adjoint_vec_pids ( (sort_kernel)[2] , adjoint_vec_pids );
	c_cu_swap_l_scmc_set_parameter_cu_cache ( cu_swap_l_kernel , cu_cache );
	c_cu_swap_r_scmc_set_parameter_cu_cache ( cu_swap_r_kernel , cu_cache );
	c_cu_swap_l_scmc_set_parameter_cu_xyzw ( cu_swap_l_kernel , cu_xyzw );
	c_cu_swap_r_scmc_set_parameter_cu_xyzw ( cu_swap_r_kernel , cu_xyzw );
	c_cu_swap_l_scmc_set_parameter_adjoint_vec_pids ( cu_swap_l_kernel , adjoint_vec_pids );
	c_cu_swap_r_scmc_set_parameter_adjoint_vec_pids ( cu_swap_r_kernel , adjoint_vec_pids );
	c_pscmc_mem  c_alloc_prefix_XLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XLEN ).h_data))[0] = XLEN);
	c_sort_one_grid_z_scmc_set_parameter_XLEN ( (sort_kernel)[2] , 	& ( c_alloc_prefix_XLEN ) );
	c_pscmc_mem  c_alloc_prefix_YLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_YLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_YLEN ).h_data))[0] = YLEN);
	c_sort_one_grid_z_scmc_set_parameter_YLEN ( (sort_kernel)[2] , 	& ( c_alloc_prefix_YLEN ) );
	c_pscmc_mem  c_alloc_prefix_ZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_ZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_ZLEN ).h_data))[0] = ZLEN);
	c_sort_one_grid_z_scmc_set_parameter_ZLEN ( (sort_kernel)[2] , 	& ( c_alloc_prefix_ZLEN ) );
	c_pscmc_mem  c_alloc_prefix_ovlp ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_ovlp ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_ovlp ).h_data))[0] = ovlp);
	c_sort_one_grid_z_scmc_set_parameter_ovlp ( (sort_kernel)[2] , 	& ( c_alloc_prefix_ovlp ) );
	c_pscmc_mem  c_alloc_prefix_numvec ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_numvec ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_numvec ).h_data))[0] = numvec);
	c_sort_one_grid_z_scmc_set_parameter_numvec ( (sort_kernel)[2] , 	& ( c_alloc_prefix_numvec ) );
	c_pscmc_mem  c_alloc_prefix_grid_cache_len ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_grid_cache_len ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_grid_cache_len ).h_data))[0] = grid_cache_len);
	c_sort_one_grid_z_scmc_set_parameter_grid_cache_len ( (sort_kernel)[2] , 	& ( c_alloc_prefix_grid_cache_len ) );
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_sort_one_grid_z_scmc_set_parameter_cu_cache_length ( (sort_kernel)[2] , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_sort_one_grid_z_exec ( (sort_kernel)[2] , the_xlen , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_YLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_ZLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_ovlp ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_numvec ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_grid_cache_len ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	long  XYZLEN = ZLEN ;
	int  the_dir_num = 2 ;
{
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_cu_swap_l_scmc_set_parameter_cu_cache_length ( cu_swap_l_kernel , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem  c_alloc_prefix_the_dir_num ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	c_cu_swap_l_scmc_set_parameter_the_dir_num ( cu_swap_l_kernel , 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem  c_alloc_prefix_XYZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	c_cu_swap_l_scmc_set_parameter_XYZLEN ( cu_swap_l_kernel , 	& ( c_alloc_prefix_XYZLEN ) );
	c_cu_swap_l_exec ( cu_swap_l_kernel , 1 , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XYZLEN ) );
}(XYZLEN = 	- ( XYZLEN ));
{
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_cu_swap_r_scmc_set_parameter_cu_cache_length ( cu_swap_r_kernel , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem  c_alloc_prefix_the_dir_num ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	c_cu_swap_r_scmc_set_parameter_the_dir_num ( cu_swap_r_kernel , 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem  c_alloc_prefix_XYZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	c_cu_swap_r_scmc_set_parameter_XYZLEN ( cu_swap_r_kernel , 	& ( c_alloc_prefix_XYZLEN ) );
	c_cu_swap_r_exec ( cu_swap_r_kernel , 1 , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XYZLEN ) );
}	return  0 ;}
int  c_call_particle_sort_single_x_vlo (One_Particle_Collection *  pthis ){
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
	long  the_xlen = 	c_pscmc_get_local_len (  ) ;
	long  XLEN = xlen ;
	long  YLEN = ylen ;
	long  ZLEN = zlen ;
	c_sort_one_grid_x_vlo_scmc_set_parameter_inoutput ( (sort_kernel)[3] , inoutput );
	c_sort_one_grid_x_vlo_scmc_set_parameter_xyzw ( (sort_kernel)[3] , xyzw );
	c_sort_one_grid_x_vlo_scmc_set_parameter_cu_cache ( (sort_kernel)[3] , cu_cache );
	c_sort_one_grid_x_vlo_scmc_set_parameter_cu_xyzw ( (sort_kernel)[3] , cu_xyzw );
	c_sort_one_grid_x_vlo_scmc_set_parameter_adjoint_vec_pids ( (sort_kernel)[3] , adjoint_vec_pids );
	c_cu_swap_l_scmc_set_parameter_cu_cache ( cu_swap_l_kernel , cu_cache );
	c_cu_swap_r_scmc_set_parameter_cu_cache ( cu_swap_r_kernel , cu_cache );
	c_cu_swap_l_scmc_set_parameter_cu_xyzw ( cu_swap_l_kernel , cu_xyzw );
	c_cu_swap_r_scmc_set_parameter_cu_xyzw ( cu_swap_r_kernel , cu_xyzw );
	c_cu_swap_l_scmc_set_parameter_adjoint_vec_pids ( cu_swap_l_kernel , adjoint_vec_pids );
	c_cu_swap_r_scmc_set_parameter_adjoint_vec_pids ( cu_swap_r_kernel , adjoint_vec_pids );
	c_pscmc_mem  c_alloc_prefix_XLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XLEN ).h_data))[0] = XLEN);
	c_sort_one_grid_x_vlo_scmc_set_parameter_XLEN ( (sort_kernel)[3] , 	& ( c_alloc_prefix_XLEN ) );
	c_pscmc_mem  c_alloc_prefix_YLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_YLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_YLEN ).h_data))[0] = YLEN);
	c_sort_one_grid_x_vlo_scmc_set_parameter_YLEN ( (sort_kernel)[3] , 	& ( c_alloc_prefix_YLEN ) );
	c_pscmc_mem  c_alloc_prefix_ZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_ZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_ZLEN ).h_data))[0] = ZLEN);
	c_sort_one_grid_x_vlo_scmc_set_parameter_ZLEN ( (sort_kernel)[3] , 	& ( c_alloc_prefix_ZLEN ) );
	c_pscmc_mem  c_alloc_prefix_ovlp ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_ovlp ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_ovlp ).h_data))[0] = ovlp);
	c_sort_one_grid_x_vlo_scmc_set_parameter_ovlp ( (sort_kernel)[3] , 	& ( c_alloc_prefix_ovlp ) );
	c_pscmc_mem  c_alloc_prefix_numvec ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_numvec ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_numvec ).h_data))[0] = numvec);
	c_sort_one_grid_x_vlo_scmc_set_parameter_numvec ( (sort_kernel)[3] , 	& ( c_alloc_prefix_numvec ) );
	c_pscmc_mem  c_alloc_prefix_grid_cache_len ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_grid_cache_len ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_grid_cache_len ).h_data))[0] = grid_cache_len);
	c_sort_one_grid_x_vlo_scmc_set_parameter_grid_cache_len ( (sort_kernel)[3] , 	& ( c_alloc_prefix_grid_cache_len ) );
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_sort_one_grid_x_vlo_scmc_set_parameter_cu_cache_length ( (sort_kernel)[3] , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_sort_one_grid_x_vlo_exec ( (sort_kernel)[3] , the_xlen , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_YLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_ZLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_ovlp ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_numvec ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_grid_cache_len ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	long  XYZLEN = XLEN ;
	int  the_dir_num = 0 ;
{
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_cu_swap_l_scmc_set_parameter_cu_cache_length ( cu_swap_l_kernel , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem  c_alloc_prefix_the_dir_num ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	c_cu_swap_l_scmc_set_parameter_the_dir_num ( cu_swap_l_kernel , 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem  c_alloc_prefix_XYZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	c_cu_swap_l_scmc_set_parameter_XYZLEN ( cu_swap_l_kernel , 	& ( c_alloc_prefix_XYZLEN ) );
	c_cu_swap_l_exec ( cu_swap_l_kernel , 1 , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XYZLEN ) );
}(XYZLEN = 	- ( XYZLEN ));
{
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_cu_swap_r_scmc_set_parameter_cu_cache_length ( cu_swap_r_kernel , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem  c_alloc_prefix_the_dir_num ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	c_cu_swap_r_scmc_set_parameter_the_dir_num ( cu_swap_r_kernel , 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem  c_alloc_prefix_XYZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	c_cu_swap_r_scmc_set_parameter_XYZLEN ( cu_swap_r_kernel , 	& ( c_alloc_prefix_XYZLEN ) );
	c_cu_swap_r_exec ( cu_swap_r_kernel , 1 , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XYZLEN ) );
}	return  0 ;}
int  c_call_particle_sort_single_y_vlo (One_Particle_Collection *  pthis ){
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
	long  the_xlen = 	c_pscmc_get_local_len (  ) ;
	long  XLEN = xlen ;
	long  YLEN = ylen ;
	long  ZLEN = zlen ;
	c_sort_one_grid_y_vlo_scmc_set_parameter_inoutput ( (sort_kernel)[4] , inoutput );
	c_sort_one_grid_y_vlo_scmc_set_parameter_xyzw ( (sort_kernel)[4] , xyzw );
	c_sort_one_grid_y_vlo_scmc_set_parameter_cu_cache ( (sort_kernel)[4] , cu_cache );
	c_sort_one_grid_y_vlo_scmc_set_parameter_cu_xyzw ( (sort_kernel)[4] , cu_xyzw );
	c_sort_one_grid_y_vlo_scmc_set_parameter_adjoint_vec_pids ( (sort_kernel)[4] , adjoint_vec_pids );
	c_cu_swap_l_scmc_set_parameter_cu_cache ( cu_swap_l_kernel , cu_cache );
	c_cu_swap_r_scmc_set_parameter_cu_cache ( cu_swap_r_kernel , cu_cache );
	c_cu_swap_l_scmc_set_parameter_cu_xyzw ( cu_swap_l_kernel , cu_xyzw );
	c_cu_swap_r_scmc_set_parameter_cu_xyzw ( cu_swap_r_kernel , cu_xyzw );
	c_cu_swap_l_scmc_set_parameter_adjoint_vec_pids ( cu_swap_l_kernel , adjoint_vec_pids );
	c_cu_swap_r_scmc_set_parameter_adjoint_vec_pids ( cu_swap_r_kernel , adjoint_vec_pids );
	c_pscmc_mem  c_alloc_prefix_XLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XLEN ).h_data))[0] = XLEN);
	c_sort_one_grid_y_vlo_scmc_set_parameter_XLEN ( (sort_kernel)[4] , 	& ( c_alloc_prefix_XLEN ) );
	c_pscmc_mem  c_alloc_prefix_YLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_YLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_YLEN ).h_data))[0] = YLEN);
	c_sort_one_grid_y_vlo_scmc_set_parameter_YLEN ( (sort_kernel)[4] , 	& ( c_alloc_prefix_YLEN ) );
	c_pscmc_mem  c_alloc_prefix_ZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_ZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_ZLEN ).h_data))[0] = ZLEN);
	c_sort_one_grid_y_vlo_scmc_set_parameter_ZLEN ( (sort_kernel)[4] , 	& ( c_alloc_prefix_ZLEN ) );
	c_pscmc_mem  c_alloc_prefix_ovlp ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_ovlp ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_ovlp ).h_data))[0] = ovlp);
	c_sort_one_grid_y_vlo_scmc_set_parameter_ovlp ( (sort_kernel)[4] , 	& ( c_alloc_prefix_ovlp ) );
	c_pscmc_mem  c_alloc_prefix_numvec ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_numvec ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_numvec ).h_data))[0] = numvec);
	c_sort_one_grid_y_vlo_scmc_set_parameter_numvec ( (sort_kernel)[4] , 	& ( c_alloc_prefix_numvec ) );
	c_pscmc_mem  c_alloc_prefix_grid_cache_len ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_grid_cache_len ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_grid_cache_len ).h_data))[0] = grid_cache_len);
	c_sort_one_grid_y_vlo_scmc_set_parameter_grid_cache_len ( (sort_kernel)[4] , 	& ( c_alloc_prefix_grid_cache_len ) );
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_sort_one_grid_y_vlo_scmc_set_parameter_cu_cache_length ( (sort_kernel)[4] , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_sort_one_grid_y_vlo_exec ( (sort_kernel)[4] , the_xlen , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_YLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_ZLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_ovlp ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_numvec ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_grid_cache_len ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	long  XYZLEN = YLEN ;
	int  the_dir_num = 1 ;
{
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_cu_swap_l_scmc_set_parameter_cu_cache_length ( cu_swap_l_kernel , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem  c_alloc_prefix_the_dir_num ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	c_cu_swap_l_scmc_set_parameter_the_dir_num ( cu_swap_l_kernel , 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem  c_alloc_prefix_XYZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	c_cu_swap_l_scmc_set_parameter_XYZLEN ( cu_swap_l_kernel , 	& ( c_alloc_prefix_XYZLEN ) );
	c_cu_swap_l_exec ( cu_swap_l_kernel , 1 , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XYZLEN ) );
}(XYZLEN = 	- ( XYZLEN ));
{
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_cu_swap_r_scmc_set_parameter_cu_cache_length ( cu_swap_r_kernel , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem  c_alloc_prefix_the_dir_num ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	c_cu_swap_r_scmc_set_parameter_the_dir_num ( cu_swap_r_kernel , 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem  c_alloc_prefix_XYZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	c_cu_swap_r_scmc_set_parameter_XYZLEN ( cu_swap_r_kernel , 	& ( c_alloc_prefix_XYZLEN ) );
	c_cu_swap_r_exec ( cu_swap_r_kernel , 1 , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XYZLEN ) );
}	return  0 ;}
int  c_call_particle_sort_single_z_vlo (One_Particle_Collection *  pthis ){
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
	long  the_xlen = 	c_pscmc_get_local_len (  ) ;
	long  XLEN = xlen ;
	long  YLEN = ylen ;
	long  ZLEN = zlen ;
	c_sort_one_grid_z_vlo_scmc_set_parameter_inoutput ( (sort_kernel)[5] , inoutput );
	c_sort_one_grid_z_vlo_scmc_set_parameter_xyzw ( (sort_kernel)[5] , xyzw );
	c_sort_one_grid_z_vlo_scmc_set_parameter_cu_cache ( (sort_kernel)[5] , cu_cache );
	c_sort_one_grid_z_vlo_scmc_set_parameter_cu_xyzw ( (sort_kernel)[5] , cu_xyzw );
	c_sort_one_grid_z_vlo_scmc_set_parameter_adjoint_vec_pids ( (sort_kernel)[5] , adjoint_vec_pids );
	c_cu_swap_l_scmc_set_parameter_cu_cache ( cu_swap_l_kernel , cu_cache );
	c_cu_swap_r_scmc_set_parameter_cu_cache ( cu_swap_r_kernel , cu_cache );
	c_cu_swap_l_scmc_set_parameter_cu_xyzw ( cu_swap_l_kernel , cu_xyzw );
	c_cu_swap_r_scmc_set_parameter_cu_xyzw ( cu_swap_r_kernel , cu_xyzw );
	c_cu_swap_l_scmc_set_parameter_adjoint_vec_pids ( cu_swap_l_kernel , adjoint_vec_pids );
	c_cu_swap_r_scmc_set_parameter_adjoint_vec_pids ( cu_swap_r_kernel , adjoint_vec_pids );
	c_pscmc_mem  c_alloc_prefix_XLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XLEN ).h_data))[0] = XLEN);
	c_sort_one_grid_z_vlo_scmc_set_parameter_XLEN ( (sort_kernel)[5] , 	& ( c_alloc_prefix_XLEN ) );
	c_pscmc_mem  c_alloc_prefix_YLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_YLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_YLEN ).h_data))[0] = YLEN);
	c_sort_one_grid_z_vlo_scmc_set_parameter_YLEN ( (sort_kernel)[5] , 	& ( c_alloc_prefix_YLEN ) );
	c_pscmc_mem  c_alloc_prefix_ZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_ZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_ZLEN ).h_data))[0] = ZLEN);
	c_sort_one_grid_z_vlo_scmc_set_parameter_ZLEN ( (sort_kernel)[5] , 	& ( c_alloc_prefix_ZLEN ) );
	c_pscmc_mem  c_alloc_prefix_ovlp ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_ovlp ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_ovlp ).h_data))[0] = ovlp);
	c_sort_one_grid_z_vlo_scmc_set_parameter_ovlp ( (sort_kernel)[5] , 	& ( c_alloc_prefix_ovlp ) );
	c_pscmc_mem  c_alloc_prefix_numvec ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_numvec ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_numvec ).h_data))[0] = numvec);
	c_sort_one_grid_z_vlo_scmc_set_parameter_numvec ( (sort_kernel)[5] , 	& ( c_alloc_prefix_numvec ) );
	c_pscmc_mem  c_alloc_prefix_grid_cache_len ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_grid_cache_len ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_grid_cache_len ).h_data))[0] = grid_cache_len);
	c_sort_one_grid_z_vlo_scmc_set_parameter_grid_cache_len ( (sort_kernel)[5] , 	& ( c_alloc_prefix_grid_cache_len ) );
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_sort_one_grid_z_vlo_scmc_set_parameter_cu_cache_length ( (sort_kernel)[5] , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_sort_one_grid_z_vlo_exec ( (sort_kernel)[5] , the_xlen , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_YLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_ZLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_ovlp ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_numvec ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_grid_cache_len ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	long  XYZLEN = ZLEN ;
	int  the_dir_num = 2 ;
{
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_cu_swap_l_scmc_set_parameter_cu_cache_length ( cu_swap_l_kernel , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem  c_alloc_prefix_the_dir_num ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	c_cu_swap_l_scmc_set_parameter_the_dir_num ( cu_swap_l_kernel , 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem  c_alloc_prefix_XYZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	c_cu_swap_l_scmc_set_parameter_XYZLEN ( cu_swap_l_kernel , 	& ( c_alloc_prefix_XYZLEN ) );
	c_cu_swap_l_exec ( cu_swap_l_kernel , 1 , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XYZLEN ) );
}(XYZLEN = 	- ( XYZLEN ));
{
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_cu_swap_r_scmc_set_parameter_cu_cache_length ( cu_swap_r_kernel , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem  c_alloc_prefix_the_dir_num ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	c_cu_swap_r_scmc_set_parameter_the_dir_num ( cu_swap_r_kernel , 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem  c_alloc_prefix_XYZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	c_cu_swap_r_scmc_set_parameter_XYZLEN ( cu_swap_r_kernel , 	& ( c_alloc_prefix_XYZLEN ) );
	c_cu_swap_r_exec ( cu_swap_r_kernel , 1 , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_the_dir_num ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XYZLEN ) );
}	return  0 ;}
int  openmp_call_particle_sort_single_x (One_Particle_Collection *  pthis ){
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
	long  the_xlen = 	openmp_pscmc_get_local_len (  ) ;
	long  XLEN = xlen ;
	long  YLEN = ylen ;
	long  ZLEN = zlen ;
	openmp_sort_one_grid_x_scmc_set_parameter_inoutput ( (sort_kernel)[0] , inoutput );
	openmp_sort_one_grid_x_scmc_set_parameter_xyzw ( (sort_kernel)[0] , xyzw );
	openmp_sort_one_grid_x_scmc_set_parameter_cu_cache ( (sort_kernel)[0] , cu_cache );
	openmp_sort_one_grid_x_scmc_set_parameter_cu_xyzw ( (sort_kernel)[0] , cu_xyzw );
	openmp_sort_one_grid_x_scmc_set_parameter_adjoint_vec_pids ( (sort_kernel)[0] , adjoint_vec_pids );
	openmp_cu_swap_l_scmc_set_parameter_cu_cache ( cu_swap_l_kernel , cu_cache );
	openmp_cu_swap_r_scmc_set_parameter_cu_cache ( cu_swap_r_kernel , cu_cache );
	openmp_cu_swap_l_scmc_set_parameter_cu_xyzw ( cu_swap_l_kernel , cu_xyzw );
	openmp_cu_swap_r_scmc_set_parameter_cu_xyzw ( cu_swap_r_kernel , cu_xyzw );
	openmp_cu_swap_l_scmc_set_parameter_adjoint_vec_pids ( cu_swap_l_kernel , adjoint_vec_pids );
	openmp_cu_swap_r_scmc_set_parameter_adjoint_vec_pids ( cu_swap_r_kernel , adjoint_vec_pids );
	openmp_pscmc_mem  openmp_alloc_prefix_XLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XLEN ).h_data))[0] = XLEN);
	openmp_sort_one_grid_x_scmc_set_parameter_XLEN ( (sort_kernel)[0] , 	& ( openmp_alloc_prefix_XLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_YLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_YLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_YLEN ).h_data))[0] = YLEN);
	openmp_sort_one_grid_x_scmc_set_parameter_YLEN ( (sort_kernel)[0] , 	& ( openmp_alloc_prefix_YLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_ZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_ZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_ZLEN ).h_data))[0] = ZLEN);
	openmp_sort_one_grid_x_scmc_set_parameter_ZLEN ( (sort_kernel)[0] , 	& ( openmp_alloc_prefix_ZLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_ovlp ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_ovlp ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_ovlp ).h_data))[0] = ovlp);
	openmp_sort_one_grid_x_scmc_set_parameter_ovlp ( (sort_kernel)[0] , 	& ( openmp_alloc_prefix_ovlp ) );
	openmp_pscmc_mem  openmp_alloc_prefix_numvec ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_numvec ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_numvec ).h_data))[0] = numvec);
	openmp_sort_one_grid_x_scmc_set_parameter_numvec ( (sort_kernel)[0] , 	& ( openmp_alloc_prefix_numvec ) );
	openmp_pscmc_mem  openmp_alloc_prefix_grid_cache_len ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_grid_cache_len ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_grid_cache_len ).h_data))[0] = grid_cache_len);
	openmp_sort_one_grid_x_scmc_set_parameter_grid_cache_len ( (sort_kernel)[0] , 	& ( openmp_alloc_prefix_grid_cache_len ) );
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_sort_one_grid_x_scmc_set_parameter_cu_cache_length ( (sort_kernel)[0] , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_sort_one_grid_x_exec ( (sort_kernel)[0] , the_xlen , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_YLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_ZLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_ovlp ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_numvec ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_grid_cache_len ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	long  XYZLEN = XLEN ;
	int  the_dir_num = 0 ;
{
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_cu_swap_l_scmc_set_parameter_cu_cache_length ( cu_swap_l_kernel , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem  openmp_alloc_prefix_the_dir_num ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	openmp_cu_swap_l_scmc_set_parameter_the_dir_num ( cu_swap_l_kernel , 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem  openmp_alloc_prefix_XYZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	openmp_cu_swap_l_scmc_set_parameter_XYZLEN ( cu_swap_l_kernel , 	& ( openmp_alloc_prefix_XYZLEN ) );
	openmp_cu_swap_l_exec ( cu_swap_l_kernel , 1 , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XYZLEN ) );
}(XYZLEN = 	- ( XYZLEN ));
{
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_cu_swap_r_scmc_set_parameter_cu_cache_length ( cu_swap_r_kernel , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem  openmp_alloc_prefix_the_dir_num ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	openmp_cu_swap_r_scmc_set_parameter_the_dir_num ( cu_swap_r_kernel , 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem  openmp_alloc_prefix_XYZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	openmp_cu_swap_r_scmc_set_parameter_XYZLEN ( cu_swap_r_kernel , 	& ( openmp_alloc_prefix_XYZLEN ) );
	openmp_cu_swap_r_exec ( cu_swap_r_kernel , 1 , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XYZLEN ) );
}	return  0 ;}
int  openmp_call_particle_sort_single_y (One_Particle_Collection *  pthis ){
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
	long  the_xlen = 	openmp_pscmc_get_local_len (  ) ;
	long  XLEN = xlen ;
	long  YLEN = ylen ;
	long  ZLEN = zlen ;
	openmp_sort_one_grid_y_scmc_set_parameter_inoutput ( (sort_kernel)[1] , inoutput );
	openmp_sort_one_grid_y_scmc_set_parameter_xyzw ( (sort_kernel)[1] , xyzw );
	openmp_sort_one_grid_y_scmc_set_parameter_cu_cache ( (sort_kernel)[1] , cu_cache );
	openmp_sort_one_grid_y_scmc_set_parameter_cu_xyzw ( (sort_kernel)[1] , cu_xyzw );
	openmp_sort_one_grid_y_scmc_set_parameter_adjoint_vec_pids ( (sort_kernel)[1] , adjoint_vec_pids );
	openmp_cu_swap_l_scmc_set_parameter_cu_cache ( cu_swap_l_kernel , cu_cache );
	openmp_cu_swap_r_scmc_set_parameter_cu_cache ( cu_swap_r_kernel , cu_cache );
	openmp_cu_swap_l_scmc_set_parameter_cu_xyzw ( cu_swap_l_kernel , cu_xyzw );
	openmp_cu_swap_r_scmc_set_parameter_cu_xyzw ( cu_swap_r_kernel , cu_xyzw );
	openmp_cu_swap_l_scmc_set_parameter_adjoint_vec_pids ( cu_swap_l_kernel , adjoint_vec_pids );
	openmp_cu_swap_r_scmc_set_parameter_adjoint_vec_pids ( cu_swap_r_kernel , adjoint_vec_pids );
	openmp_pscmc_mem  openmp_alloc_prefix_XLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XLEN ).h_data))[0] = XLEN);
	openmp_sort_one_grid_y_scmc_set_parameter_XLEN ( (sort_kernel)[1] , 	& ( openmp_alloc_prefix_XLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_YLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_YLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_YLEN ).h_data))[0] = YLEN);
	openmp_sort_one_grid_y_scmc_set_parameter_YLEN ( (sort_kernel)[1] , 	& ( openmp_alloc_prefix_YLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_ZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_ZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_ZLEN ).h_data))[0] = ZLEN);
	openmp_sort_one_grid_y_scmc_set_parameter_ZLEN ( (sort_kernel)[1] , 	& ( openmp_alloc_prefix_ZLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_ovlp ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_ovlp ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_ovlp ).h_data))[0] = ovlp);
	openmp_sort_one_grid_y_scmc_set_parameter_ovlp ( (sort_kernel)[1] , 	& ( openmp_alloc_prefix_ovlp ) );
	openmp_pscmc_mem  openmp_alloc_prefix_numvec ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_numvec ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_numvec ).h_data))[0] = numvec);
	openmp_sort_one_grid_y_scmc_set_parameter_numvec ( (sort_kernel)[1] , 	& ( openmp_alloc_prefix_numvec ) );
	openmp_pscmc_mem  openmp_alloc_prefix_grid_cache_len ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_grid_cache_len ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_grid_cache_len ).h_data))[0] = grid_cache_len);
	openmp_sort_one_grid_y_scmc_set_parameter_grid_cache_len ( (sort_kernel)[1] , 	& ( openmp_alloc_prefix_grid_cache_len ) );
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_sort_one_grid_y_scmc_set_parameter_cu_cache_length ( (sort_kernel)[1] , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_sort_one_grid_y_exec ( (sort_kernel)[1] , the_xlen , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_YLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_ZLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_ovlp ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_numvec ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_grid_cache_len ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	long  XYZLEN = YLEN ;
	int  the_dir_num = 1 ;
{
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_cu_swap_l_scmc_set_parameter_cu_cache_length ( cu_swap_l_kernel , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem  openmp_alloc_prefix_the_dir_num ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	openmp_cu_swap_l_scmc_set_parameter_the_dir_num ( cu_swap_l_kernel , 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem  openmp_alloc_prefix_XYZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	openmp_cu_swap_l_scmc_set_parameter_XYZLEN ( cu_swap_l_kernel , 	& ( openmp_alloc_prefix_XYZLEN ) );
	openmp_cu_swap_l_exec ( cu_swap_l_kernel , 1 , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XYZLEN ) );
}(XYZLEN = 	- ( XYZLEN ));
{
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_cu_swap_r_scmc_set_parameter_cu_cache_length ( cu_swap_r_kernel , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem  openmp_alloc_prefix_the_dir_num ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	openmp_cu_swap_r_scmc_set_parameter_the_dir_num ( cu_swap_r_kernel , 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem  openmp_alloc_prefix_XYZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	openmp_cu_swap_r_scmc_set_parameter_XYZLEN ( cu_swap_r_kernel , 	& ( openmp_alloc_prefix_XYZLEN ) );
	openmp_cu_swap_r_exec ( cu_swap_r_kernel , 1 , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XYZLEN ) );
}	return  0 ;}
int  openmp_call_particle_sort_single_z (One_Particle_Collection *  pthis ){
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
	long  the_xlen = 	openmp_pscmc_get_local_len (  ) ;
	long  XLEN = xlen ;
	long  YLEN = ylen ;
	long  ZLEN = zlen ;
	openmp_sort_one_grid_z_scmc_set_parameter_inoutput ( (sort_kernel)[2] , inoutput );
	openmp_sort_one_grid_z_scmc_set_parameter_xyzw ( (sort_kernel)[2] , xyzw );
	openmp_sort_one_grid_z_scmc_set_parameter_cu_cache ( (sort_kernel)[2] , cu_cache );
	openmp_sort_one_grid_z_scmc_set_parameter_cu_xyzw ( (sort_kernel)[2] , cu_xyzw );
	openmp_sort_one_grid_z_scmc_set_parameter_adjoint_vec_pids ( (sort_kernel)[2] , adjoint_vec_pids );
	openmp_cu_swap_l_scmc_set_parameter_cu_cache ( cu_swap_l_kernel , cu_cache );
	openmp_cu_swap_r_scmc_set_parameter_cu_cache ( cu_swap_r_kernel , cu_cache );
	openmp_cu_swap_l_scmc_set_parameter_cu_xyzw ( cu_swap_l_kernel , cu_xyzw );
	openmp_cu_swap_r_scmc_set_parameter_cu_xyzw ( cu_swap_r_kernel , cu_xyzw );
	openmp_cu_swap_l_scmc_set_parameter_adjoint_vec_pids ( cu_swap_l_kernel , adjoint_vec_pids );
	openmp_cu_swap_r_scmc_set_parameter_adjoint_vec_pids ( cu_swap_r_kernel , adjoint_vec_pids );
	openmp_pscmc_mem  openmp_alloc_prefix_XLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XLEN ).h_data))[0] = XLEN);
	openmp_sort_one_grid_z_scmc_set_parameter_XLEN ( (sort_kernel)[2] , 	& ( openmp_alloc_prefix_XLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_YLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_YLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_YLEN ).h_data))[0] = YLEN);
	openmp_sort_one_grid_z_scmc_set_parameter_YLEN ( (sort_kernel)[2] , 	& ( openmp_alloc_prefix_YLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_ZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_ZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_ZLEN ).h_data))[0] = ZLEN);
	openmp_sort_one_grid_z_scmc_set_parameter_ZLEN ( (sort_kernel)[2] , 	& ( openmp_alloc_prefix_ZLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_ovlp ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_ovlp ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_ovlp ).h_data))[0] = ovlp);
	openmp_sort_one_grid_z_scmc_set_parameter_ovlp ( (sort_kernel)[2] , 	& ( openmp_alloc_prefix_ovlp ) );
	openmp_pscmc_mem  openmp_alloc_prefix_numvec ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_numvec ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_numvec ).h_data))[0] = numvec);
	openmp_sort_one_grid_z_scmc_set_parameter_numvec ( (sort_kernel)[2] , 	& ( openmp_alloc_prefix_numvec ) );
	openmp_pscmc_mem  openmp_alloc_prefix_grid_cache_len ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_grid_cache_len ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_grid_cache_len ).h_data))[0] = grid_cache_len);
	openmp_sort_one_grid_z_scmc_set_parameter_grid_cache_len ( (sort_kernel)[2] , 	& ( openmp_alloc_prefix_grid_cache_len ) );
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_sort_one_grid_z_scmc_set_parameter_cu_cache_length ( (sort_kernel)[2] , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_sort_one_grid_z_exec ( (sort_kernel)[2] , the_xlen , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_YLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_ZLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_ovlp ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_numvec ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_grid_cache_len ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	long  XYZLEN = ZLEN ;
	int  the_dir_num = 2 ;
{
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_cu_swap_l_scmc_set_parameter_cu_cache_length ( cu_swap_l_kernel , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem  openmp_alloc_prefix_the_dir_num ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	openmp_cu_swap_l_scmc_set_parameter_the_dir_num ( cu_swap_l_kernel , 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem  openmp_alloc_prefix_XYZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	openmp_cu_swap_l_scmc_set_parameter_XYZLEN ( cu_swap_l_kernel , 	& ( openmp_alloc_prefix_XYZLEN ) );
	openmp_cu_swap_l_exec ( cu_swap_l_kernel , 1 , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XYZLEN ) );
}(XYZLEN = 	- ( XYZLEN ));
{
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_cu_swap_r_scmc_set_parameter_cu_cache_length ( cu_swap_r_kernel , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem  openmp_alloc_prefix_the_dir_num ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	openmp_cu_swap_r_scmc_set_parameter_the_dir_num ( cu_swap_r_kernel , 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem  openmp_alloc_prefix_XYZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	openmp_cu_swap_r_scmc_set_parameter_XYZLEN ( cu_swap_r_kernel , 	& ( openmp_alloc_prefix_XYZLEN ) );
	openmp_cu_swap_r_exec ( cu_swap_r_kernel , 1 , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XYZLEN ) );
}	return  0 ;}
int  openmp_call_particle_sort_single_x_vlo (One_Particle_Collection *  pthis ){
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
	long  the_xlen = 	openmp_pscmc_get_local_len (  ) ;
	long  XLEN = xlen ;
	long  YLEN = ylen ;
	long  ZLEN = zlen ;
	openmp_sort_one_grid_x_vlo_scmc_set_parameter_inoutput ( (sort_kernel)[3] , inoutput );
	openmp_sort_one_grid_x_vlo_scmc_set_parameter_xyzw ( (sort_kernel)[3] , xyzw );
	openmp_sort_one_grid_x_vlo_scmc_set_parameter_cu_cache ( (sort_kernel)[3] , cu_cache );
	openmp_sort_one_grid_x_vlo_scmc_set_parameter_cu_xyzw ( (sort_kernel)[3] , cu_xyzw );
	openmp_sort_one_grid_x_vlo_scmc_set_parameter_adjoint_vec_pids ( (sort_kernel)[3] , adjoint_vec_pids );
	openmp_cu_swap_l_scmc_set_parameter_cu_cache ( cu_swap_l_kernel , cu_cache );
	openmp_cu_swap_r_scmc_set_parameter_cu_cache ( cu_swap_r_kernel , cu_cache );
	openmp_cu_swap_l_scmc_set_parameter_cu_xyzw ( cu_swap_l_kernel , cu_xyzw );
	openmp_cu_swap_r_scmc_set_parameter_cu_xyzw ( cu_swap_r_kernel , cu_xyzw );
	openmp_cu_swap_l_scmc_set_parameter_adjoint_vec_pids ( cu_swap_l_kernel , adjoint_vec_pids );
	openmp_cu_swap_r_scmc_set_parameter_adjoint_vec_pids ( cu_swap_r_kernel , adjoint_vec_pids );
	openmp_pscmc_mem  openmp_alloc_prefix_XLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XLEN ).h_data))[0] = XLEN);
	openmp_sort_one_grid_x_vlo_scmc_set_parameter_XLEN ( (sort_kernel)[3] , 	& ( openmp_alloc_prefix_XLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_YLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_YLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_YLEN ).h_data))[0] = YLEN);
	openmp_sort_one_grid_x_vlo_scmc_set_parameter_YLEN ( (sort_kernel)[3] , 	& ( openmp_alloc_prefix_YLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_ZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_ZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_ZLEN ).h_data))[0] = ZLEN);
	openmp_sort_one_grid_x_vlo_scmc_set_parameter_ZLEN ( (sort_kernel)[3] , 	& ( openmp_alloc_prefix_ZLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_ovlp ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_ovlp ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_ovlp ).h_data))[0] = ovlp);
	openmp_sort_one_grid_x_vlo_scmc_set_parameter_ovlp ( (sort_kernel)[3] , 	& ( openmp_alloc_prefix_ovlp ) );
	openmp_pscmc_mem  openmp_alloc_prefix_numvec ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_numvec ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_numvec ).h_data))[0] = numvec);
	openmp_sort_one_grid_x_vlo_scmc_set_parameter_numvec ( (sort_kernel)[3] , 	& ( openmp_alloc_prefix_numvec ) );
	openmp_pscmc_mem  openmp_alloc_prefix_grid_cache_len ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_grid_cache_len ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_grid_cache_len ).h_data))[0] = grid_cache_len);
	openmp_sort_one_grid_x_vlo_scmc_set_parameter_grid_cache_len ( (sort_kernel)[3] , 	& ( openmp_alloc_prefix_grid_cache_len ) );
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_sort_one_grid_x_vlo_scmc_set_parameter_cu_cache_length ( (sort_kernel)[3] , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_sort_one_grid_x_vlo_exec ( (sort_kernel)[3] , the_xlen , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_YLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_ZLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_ovlp ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_numvec ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_grid_cache_len ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	long  XYZLEN = XLEN ;
	int  the_dir_num = 0 ;
{
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_cu_swap_l_scmc_set_parameter_cu_cache_length ( cu_swap_l_kernel , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem  openmp_alloc_prefix_the_dir_num ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	openmp_cu_swap_l_scmc_set_parameter_the_dir_num ( cu_swap_l_kernel , 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem  openmp_alloc_prefix_XYZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	openmp_cu_swap_l_scmc_set_parameter_XYZLEN ( cu_swap_l_kernel , 	& ( openmp_alloc_prefix_XYZLEN ) );
	openmp_cu_swap_l_exec ( cu_swap_l_kernel , 1 , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XYZLEN ) );
}(XYZLEN = 	- ( XYZLEN ));
{
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_cu_swap_r_scmc_set_parameter_cu_cache_length ( cu_swap_r_kernel , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem  openmp_alloc_prefix_the_dir_num ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	openmp_cu_swap_r_scmc_set_parameter_the_dir_num ( cu_swap_r_kernel , 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem  openmp_alloc_prefix_XYZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	openmp_cu_swap_r_scmc_set_parameter_XYZLEN ( cu_swap_r_kernel , 	& ( openmp_alloc_prefix_XYZLEN ) );
	openmp_cu_swap_r_exec ( cu_swap_r_kernel , 1 , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XYZLEN ) );
}	return  0 ;}
int  openmp_call_particle_sort_single_y_vlo (One_Particle_Collection *  pthis ){
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
	long  the_xlen = 	openmp_pscmc_get_local_len (  ) ;
	long  XLEN = xlen ;
	long  YLEN = ylen ;
	long  ZLEN = zlen ;
	openmp_sort_one_grid_y_vlo_scmc_set_parameter_inoutput ( (sort_kernel)[4] , inoutput );
	openmp_sort_one_grid_y_vlo_scmc_set_parameter_xyzw ( (sort_kernel)[4] , xyzw );
	openmp_sort_one_grid_y_vlo_scmc_set_parameter_cu_cache ( (sort_kernel)[4] , cu_cache );
	openmp_sort_one_grid_y_vlo_scmc_set_parameter_cu_xyzw ( (sort_kernel)[4] , cu_xyzw );
	openmp_sort_one_grid_y_vlo_scmc_set_parameter_adjoint_vec_pids ( (sort_kernel)[4] , adjoint_vec_pids );
	openmp_cu_swap_l_scmc_set_parameter_cu_cache ( cu_swap_l_kernel , cu_cache );
	openmp_cu_swap_r_scmc_set_parameter_cu_cache ( cu_swap_r_kernel , cu_cache );
	openmp_cu_swap_l_scmc_set_parameter_cu_xyzw ( cu_swap_l_kernel , cu_xyzw );
	openmp_cu_swap_r_scmc_set_parameter_cu_xyzw ( cu_swap_r_kernel , cu_xyzw );
	openmp_cu_swap_l_scmc_set_parameter_adjoint_vec_pids ( cu_swap_l_kernel , adjoint_vec_pids );
	openmp_cu_swap_r_scmc_set_parameter_adjoint_vec_pids ( cu_swap_r_kernel , adjoint_vec_pids );
	openmp_pscmc_mem  openmp_alloc_prefix_XLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XLEN ).h_data))[0] = XLEN);
	openmp_sort_one_grid_y_vlo_scmc_set_parameter_XLEN ( (sort_kernel)[4] , 	& ( openmp_alloc_prefix_XLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_YLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_YLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_YLEN ).h_data))[0] = YLEN);
	openmp_sort_one_grid_y_vlo_scmc_set_parameter_YLEN ( (sort_kernel)[4] , 	& ( openmp_alloc_prefix_YLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_ZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_ZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_ZLEN ).h_data))[0] = ZLEN);
	openmp_sort_one_grid_y_vlo_scmc_set_parameter_ZLEN ( (sort_kernel)[4] , 	& ( openmp_alloc_prefix_ZLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_ovlp ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_ovlp ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_ovlp ).h_data))[0] = ovlp);
	openmp_sort_one_grid_y_vlo_scmc_set_parameter_ovlp ( (sort_kernel)[4] , 	& ( openmp_alloc_prefix_ovlp ) );
	openmp_pscmc_mem  openmp_alloc_prefix_numvec ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_numvec ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_numvec ).h_data))[0] = numvec);
	openmp_sort_one_grid_y_vlo_scmc_set_parameter_numvec ( (sort_kernel)[4] , 	& ( openmp_alloc_prefix_numvec ) );
	openmp_pscmc_mem  openmp_alloc_prefix_grid_cache_len ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_grid_cache_len ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_grid_cache_len ).h_data))[0] = grid_cache_len);
	openmp_sort_one_grid_y_vlo_scmc_set_parameter_grid_cache_len ( (sort_kernel)[4] , 	& ( openmp_alloc_prefix_grid_cache_len ) );
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_sort_one_grid_y_vlo_scmc_set_parameter_cu_cache_length ( (sort_kernel)[4] , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_sort_one_grid_y_vlo_exec ( (sort_kernel)[4] , the_xlen , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_YLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_ZLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_ovlp ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_numvec ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_grid_cache_len ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	long  XYZLEN = YLEN ;
	int  the_dir_num = 1 ;
{
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_cu_swap_l_scmc_set_parameter_cu_cache_length ( cu_swap_l_kernel , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem  openmp_alloc_prefix_the_dir_num ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	openmp_cu_swap_l_scmc_set_parameter_the_dir_num ( cu_swap_l_kernel , 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem  openmp_alloc_prefix_XYZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	openmp_cu_swap_l_scmc_set_parameter_XYZLEN ( cu_swap_l_kernel , 	& ( openmp_alloc_prefix_XYZLEN ) );
	openmp_cu_swap_l_exec ( cu_swap_l_kernel , 1 , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XYZLEN ) );
}(XYZLEN = 	- ( XYZLEN ));
{
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_cu_swap_r_scmc_set_parameter_cu_cache_length ( cu_swap_r_kernel , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem  openmp_alloc_prefix_the_dir_num ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	openmp_cu_swap_r_scmc_set_parameter_the_dir_num ( cu_swap_r_kernel , 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem  openmp_alloc_prefix_XYZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	openmp_cu_swap_r_scmc_set_parameter_XYZLEN ( cu_swap_r_kernel , 	& ( openmp_alloc_prefix_XYZLEN ) );
	openmp_cu_swap_r_exec ( cu_swap_r_kernel , 1 , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XYZLEN ) );
}	return  0 ;}
int  openmp_call_particle_sort_single_z_vlo (One_Particle_Collection *  pthis ){
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
	long  the_xlen = 	openmp_pscmc_get_local_len (  ) ;
	long  XLEN = xlen ;
	long  YLEN = ylen ;
	long  ZLEN = zlen ;
	openmp_sort_one_grid_z_vlo_scmc_set_parameter_inoutput ( (sort_kernel)[5] , inoutput );
	openmp_sort_one_grid_z_vlo_scmc_set_parameter_xyzw ( (sort_kernel)[5] , xyzw );
	openmp_sort_one_grid_z_vlo_scmc_set_parameter_cu_cache ( (sort_kernel)[5] , cu_cache );
	openmp_sort_one_grid_z_vlo_scmc_set_parameter_cu_xyzw ( (sort_kernel)[5] , cu_xyzw );
	openmp_sort_one_grid_z_vlo_scmc_set_parameter_adjoint_vec_pids ( (sort_kernel)[5] , adjoint_vec_pids );
	openmp_cu_swap_l_scmc_set_parameter_cu_cache ( cu_swap_l_kernel , cu_cache );
	openmp_cu_swap_r_scmc_set_parameter_cu_cache ( cu_swap_r_kernel , cu_cache );
	openmp_cu_swap_l_scmc_set_parameter_cu_xyzw ( cu_swap_l_kernel , cu_xyzw );
	openmp_cu_swap_r_scmc_set_parameter_cu_xyzw ( cu_swap_r_kernel , cu_xyzw );
	openmp_cu_swap_l_scmc_set_parameter_adjoint_vec_pids ( cu_swap_l_kernel , adjoint_vec_pids );
	openmp_cu_swap_r_scmc_set_parameter_adjoint_vec_pids ( cu_swap_r_kernel , adjoint_vec_pids );
	openmp_pscmc_mem  openmp_alloc_prefix_XLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XLEN ).h_data))[0] = XLEN);
	openmp_sort_one_grid_z_vlo_scmc_set_parameter_XLEN ( (sort_kernel)[5] , 	& ( openmp_alloc_prefix_XLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_YLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_YLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_YLEN ).h_data))[0] = YLEN);
	openmp_sort_one_grid_z_vlo_scmc_set_parameter_YLEN ( (sort_kernel)[5] , 	& ( openmp_alloc_prefix_YLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_ZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_ZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_ZLEN ).h_data))[0] = ZLEN);
	openmp_sort_one_grid_z_vlo_scmc_set_parameter_ZLEN ( (sort_kernel)[5] , 	& ( openmp_alloc_prefix_ZLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_ovlp ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_ovlp ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_ovlp ).h_data))[0] = ovlp);
	openmp_sort_one_grid_z_vlo_scmc_set_parameter_ovlp ( (sort_kernel)[5] , 	& ( openmp_alloc_prefix_ovlp ) );
	openmp_pscmc_mem  openmp_alloc_prefix_numvec ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_numvec ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_numvec ).h_data))[0] = numvec);
	openmp_sort_one_grid_z_vlo_scmc_set_parameter_numvec ( (sort_kernel)[5] , 	& ( openmp_alloc_prefix_numvec ) );
	openmp_pscmc_mem  openmp_alloc_prefix_grid_cache_len ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_grid_cache_len ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_grid_cache_len ).h_data))[0] = grid_cache_len);
	openmp_sort_one_grid_z_vlo_scmc_set_parameter_grid_cache_len ( (sort_kernel)[5] , 	& ( openmp_alloc_prefix_grid_cache_len ) );
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_sort_one_grid_z_vlo_scmc_set_parameter_cu_cache_length ( (sort_kernel)[5] , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_sort_one_grid_z_vlo_exec ( (sort_kernel)[5] , the_xlen , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_YLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_ZLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_ovlp ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_numvec ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_grid_cache_len ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	long  XYZLEN = ZLEN ;
	int  the_dir_num = 2 ;
{
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_cu_swap_l_scmc_set_parameter_cu_cache_length ( cu_swap_l_kernel , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem  openmp_alloc_prefix_the_dir_num ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	openmp_cu_swap_l_scmc_set_parameter_the_dir_num ( cu_swap_l_kernel , 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem  openmp_alloc_prefix_XYZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	openmp_cu_swap_l_scmc_set_parameter_XYZLEN ( cu_swap_l_kernel , 	& ( openmp_alloc_prefix_XYZLEN ) );
	openmp_cu_swap_l_exec ( cu_swap_l_kernel , 1 , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XYZLEN ) );
}(XYZLEN = 	- ( XYZLEN ));
{
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_cu_swap_r_scmc_set_parameter_cu_cache_length ( cu_swap_r_kernel , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem  openmp_alloc_prefix_the_dir_num ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_the_dir_num ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_the_dir_num ).h_data))[0] = the_dir_num);
	openmp_cu_swap_r_scmc_set_parameter_the_dir_num ( cu_swap_r_kernel , 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem  openmp_alloc_prefix_XYZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XYZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XYZLEN ).h_data))[0] = XYZLEN);
	openmp_cu_swap_r_scmc_set_parameter_XYZLEN ( cu_swap_r_kernel , 	& ( openmp_alloc_prefix_XYZLEN ) );
	openmp_cu_swap_r_exec ( cu_swap_r_kernel , 1 , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_the_dir_num ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XYZLEN ) );
}	return  0 ;}
int  c_call_move_back_kernel_single (One_Particle_Collection *  pthis ){
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
	long  XLEN = xlen ;
	long  YLEN = ylen ;
	long  ZLEN = zlen ;
{
	c_move_back_kernel_scmc_set_parameter_inoutput ( move_back_kernel_kernel , inoutput );
	c_move_back_kernel_scmc_set_parameter_xyzw ( move_back_kernel_kernel , xyzw );
	c_move_back_kernel_scmc_set_parameter_cu_cache ( move_back_kernel_kernel , cu_cache );
	c_move_back_kernel_scmc_set_parameter_cu_xyzw ( move_back_kernel_kernel , cu_xyzw );
	c_pscmc_mem  c_alloc_prefix_XLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XLEN ).h_data))[0] = XLEN);
	c_move_back_kernel_scmc_set_parameter_XLEN ( move_back_kernel_kernel , 	& ( c_alloc_prefix_XLEN ) );
	c_pscmc_mem  c_alloc_prefix_YLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_YLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_YLEN ).h_data))[0] = YLEN);
	c_move_back_kernel_scmc_set_parameter_YLEN ( move_back_kernel_kernel , 	& ( c_alloc_prefix_YLEN ) );
	c_pscmc_mem  c_alloc_prefix_ZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_ZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_ZLEN ).h_data))[0] = ZLEN);
	c_move_back_kernel_scmc_set_parameter_ZLEN ( move_back_kernel_kernel , 	& ( c_alloc_prefix_ZLEN ) );
	c_pscmc_mem  c_alloc_prefix_grid_cache_len ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_grid_cache_len ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_grid_cache_len ).h_data))[0] = grid_cache_len);
	c_move_back_kernel_scmc_set_parameter_grid_cache_len ( move_back_kernel_kernel , 	& ( c_alloc_prefix_grid_cache_len ) );
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_move_back_kernel_scmc_set_parameter_cu_cache_length ( move_back_kernel_kernel , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_move_back_kernel_exec ( move_back_kernel_kernel , 1 , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_YLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_ZLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_grid_cache_len ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
}	return  0 ;}
int  openmp_call_move_back_kernel_single (One_Particle_Collection *  pthis ){
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
	long  XLEN = xlen ;
	long  YLEN = ylen ;
	long  ZLEN = zlen ;
{
	openmp_move_back_kernel_scmc_set_parameter_inoutput ( move_back_kernel_kernel , inoutput );
	openmp_move_back_kernel_scmc_set_parameter_xyzw ( move_back_kernel_kernel , xyzw );
	openmp_move_back_kernel_scmc_set_parameter_cu_cache ( move_back_kernel_kernel , cu_cache );
	openmp_move_back_kernel_scmc_set_parameter_cu_xyzw ( move_back_kernel_kernel , cu_xyzw );
	openmp_pscmc_mem  openmp_alloc_prefix_XLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XLEN ).h_data))[0] = XLEN);
	openmp_move_back_kernel_scmc_set_parameter_XLEN ( move_back_kernel_kernel , 	& ( openmp_alloc_prefix_XLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_YLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_YLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_YLEN ).h_data))[0] = YLEN);
	openmp_move_back_kernel_scmc_set_parameter_YLEN ( move_back_kernel_kernel , 	& ( openmp_alloc_prefix_YLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_ZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_ZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_ZLEN ).h_data))[0] = ZLEN);
	openmp_move_back_kernel_scmc_set_parameter_ZLEN ( move_back_kernel_kernel , 	& ( openmp_alloc_prefix_ZLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_grid_cache_len ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_grid_cache_len ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_grid_cache_len ).h_data))[0] = grid_cache_len);
	openmp_move_back_kernel_scmc_set_parameter_grid_cache_len ( move_back_kernel_kernel , 	& ( openmp_alloc_prefix_grid_cache_len ) );
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_move_back_kernel_scmc_set_parameter_cu_cache_length ( move_back_kernel_kernel , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_move_back_kernel_exec ( move_back_kernel_kernel , 1 , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_YLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_ZLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_grid_cache_len ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
}	return  0 ;}
int  call_particle_sort_single (One_Particle_Collection *  pthis ,int  dir ,int  use_vlo ){
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
	if (  use_vlo  ){  
			if (  	(  dir == 0 )  ){  
			if (  	(  0 == CD_type )  ){  
			c_call_particle_sort_single_x_vlo ( pthis );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_call_particle_sort_single_x_vlo ( pthis );

	}else{
		0;

	 }

	 }

	}else{
			if (  	(  dir == 1 )  ){  
			if (  	(  0 == CD_type )  ){  
			c_call_particle_sort_single_y_vlo ( pthis );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_call_particle_sort_single_y_vlo ( pthis );

	}else{
		0;

	 }

	 }

	}else{
			if (  	(  dir == 2 )  ){  
			if (  	(  0 == CD_type )  ){  
			c_call_particle_sort_single_z_vlo ( pthis );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_call_particle_sort_single_z_vlo ( pthis );

	}else{
		0;

	 }

	 }

	}else{
		0;

	 }

	 }

	 }

	}else{
			if (  	(  dir == 0 )  ){  
			if (  	(  0 == CD_type )  ){  
			c_call_particle_sort_single_x ( pthis );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_call_particle_sort_single_x ( pthis );

	}else{
		0;

	 }

	 }

	}else{
			if (  	(  dir == 1 )  ){  
			if (  	(  0 == CD_type )  ){  
			c_call_particle_sort_single_y ( pthis );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_call_particle_sort_single_y ( pthis );

	}else{
		0;

	 }

	 }

	}else{
			if (  	(  dir == 2 )  ){  
			if (  	(  0 == CD_type )  ){  
			c_call_particle_sort_single_z ( pthis );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_call_particle_sort_single_z ( pthis );

	}else{
		0;

	 }

	 }

	}else{
		0;

	 }

	 }

	 }

	 }
}
int  dump_particles_mpi (One_Particle_Collection *  pthis ,FILE *  of ){
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
			c_pscmc_mem_sync_d2h ( cu_cache );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_d2h ( cu_cache );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_d2h ( inoutput );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_d2h ( inoutput );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_d2h ( xyzw );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_d2h ( xyzw );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_d2h ( cu_xyzw );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_d2h ( cu_xyzw );

	}else{
		0;

	 }

	 }
	double *  grid_cache_arr = (((double * * )inoutput))[0] ;
	double *  cu_cache_arr = (((double * * )cu_cache))[0] ;
	int *  xyzw_arr = (((int * * )xyzw))[0] ;
	int *  cu_xyzw_arr = (((int * * )cu_xyzw))[0] ;
	long  i = 0 ;
	for (i=0 ; 	(  i < numvec ) ; i++)
	{
	int  offset = 	(  xlen * 	(  ylen * 	(  zlen * i ) ) ) ;
	long  j = 0 ;
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
	long  grid_offset = 	(  offset + 	(  0 + 	(  1 * 	(  xyzx + 	(  xlen * 	(  xyzy + 	(  ylen * xyzz ) ) ) ) ) ) ) ;
	int  load0 = (xyzw_arr)[	(  4 * grid_offset )] ;
	for (j=0 ; 	(  j < grid_cache_len ) ; j++)
	{
	if (  	(  j < load0 )  ){  
			long  l = 0 ;
	long  cur_offset = 	(  j + 	(  grid_offset * grid_cache_len ) ) ;
	for (l=0 ; 	(  l < 6 ) ; l++)
	{
	double  opt = (grid_cache_arr)[	(  l + 	(  6 * cur_offset ) )] ;
	fprintf ( of , "%.15e " , opt );
}	fprintf ( of , "\n" );

	}else{
		0;

	 }
}}}}}}}	long  cur_offset = 	(  i * cu_cache_length ) ;
	int  load0 = (cu_xyzw_arr)[	(  4 * i )] ;
	int  load_beg_left = (cu_xyzw_arr)[	(  1 + 	(  4 * i ) )] ;
	int  load_end_left = (cu_xyzw_arr)[	(  2 + 	(  4 * i ) )] ;
	int  load_beg_right = (cu_xyzw_arr)[	(  3 + 	(  4 * i ) )] ;
	for (j=0 ; 	(  j < load0 ) ; j++)
	{
	long  l = 0 ;
	for (l=0 ; 	(  l < 6 ) ; l++)
	{
	double  opt = (cu_cache_arr)[	(  l + 	(  6 * 	(  cur_offset + j ) ) )] ;
	fprintf ( of , "%e " , opt );
}	fprintf ( of , "\n" );
}}	fflush ( of );
	return  0 ;}
int  print_particles_mpi (One_Particle_Collection *  pthis ,int  dir ){
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
	#if   1    
			if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_d2h ( cu_cache );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_d2h ( cu_cache );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_d2h ( inoutput );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_d2h ( inoutput );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_d2h ( xyzw );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_d2h ( xyzw );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_d2h ( cu_xyzw );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_d2h ( cu_xyzw );

	}else{
		0;

	 }

	 }
	double *  grid_cache_arr = (((double * * )inoutput))[0] ;
	double *  cu_cache_arr = (((double * * )cu_cache))[0] ;
	int *  xyzw_arr = (((int * * )xyzw))[0] ;
	int *  cu_xyzw_arr = (((int * * )cu_xyzw))[0] ;
	long  i = 0 ;
	for (i=0 ; 	(  i < numvec ) ; i++)
	{
	#if   1    
			int  offset = 	(  xlen * 	(  ylen * 	(  zlen * i ) ) ) ;
	long  j = 0 ;
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
	long  grid_offset = 	(  offset + 	(  0 + 	(  1 * 	(  xyzx + 	(  xlen * 	(  xyzy + 	(  ylen * xyzz ) ) ) ) ) ) ) ;
	int  load0 = (xyzw_arr)[	(  4 * grid_offset )] ;
	if (  0  ){  
			fprintf ( stderr , "xyz=[%d %d %d], load=%d " , xyzx , xyzy , xyzz , load0 );
	for (j=0 ; 	(  j < load0 ) ; j++)
	{
	long  cur_offset = 	(  j + 	(  grid_offset * grid_cache_len ) ) ;
	fprintf ( stderr , "%e " , (grid_cache_arr)[	(  6 * cur_offset )] );
}	fprintf ( stderr , "\n" );

	}else{
		0;

	 }
}}}}}}	long  cur_offset = 	(  i * cu_cache_length ) ;
	int  load0 = (cu_xyzw_arr)[	(  4 * i )] ;
	int  load_beg_left = (cu_xyzw_arr)[	(  1 + 	(  4 * i ) )] ;
	int  load_end_left = (cu_xyzw_arr)[	(  2 + 	(  4 * i ) )] ;
	int  load_beg_right = (cu_xyzw_arr)[	(  3 + 	(  4 * i ) )] ;
	if (  1  ){  
			fprintf ( stderr , "cu %d, load=%d " , i , load0 );
	for (j=0 ; 	(  j < load0 ) ; j++)
	{
	double *  r0 = 	(  cu_cache_arr + 	(  6 * 	(  cur_offset + j ) ) ) ;
	fprintf ( stderr , "%e [%e %e %e] " , (r0)[dir] , (r0)[0] , (r0)[1] , (r0)[2] );
}	fprintf ( stderr , "\n" );

	}else{
		0;

	 }
	if (  	(  0 && 	(  load_end_left - load_beg_left ) )  ){  
			fprintf ( stderr , "ERR: cu %d, left_load=%d beg=%d " , i , 	(  load_end_left - load_beg_left ) , load_beg_left );
	for (j=load_beg_left ; 	(  j < load_end_left ) ; j++)
	{
	fprintf ( stderr , "%e " , (cu_cache_arr)[	(  6 * 	(  cur_offset + j ) )] );
}	fprintf ( stderr , "\n" );

	}else{
		0;

	 }
	if (  	(  0 && 	(  cu_cache_length - load_beg_right ) )  ){  
			fprintf ( stderr , "ERR: cu %d, right_load=%d " , i , 	(  cu_cache_length - load_beg_right ) );
	for (j=load_beg_right ; 	(  j < cu_cache_length ) ; j++)
	{
	fprintf ( stderr , "%e " , (cu_cache_arr)[	(  6 * 	(  cur_offset + j ) )] );
}	fprintf ( stderr , "\n" );

	}else{
		0;

	 }

	#else
		
	 #endif
}	return  0 ;
	#else
		
	 #endif
	return  0 ;}
int  swap_particle_sort_host_l (Field3D_MPI *  pthis ,int  dir ){
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
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 1 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 1 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < num_spec ) ; (xyzx = 	(  xyzx + 1 )))
	{
	One_Particle_Collection *  particle_spec_1 = 	(  particles + 	(  xyzx * num_runtime ) ) ;
	long  i ;
	long  j ;
	int * *  p_to_left_len_buffer = 	malloc ( 	(  sizeof(int * ) * num_runtime ) ) ;
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  pfield = 	( 	(  particle_spec_1 + i ) )->pfield ;
	Field3D_Seq *  pfieldE = 	( 	(  particle_spec_1 + i ) )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( 	(  particle_spec_1 + i ) )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( 	(  particle_spec_1 + i ) )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( 	(  particle_spec_1 + i ) )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( 	(  particle_spec_1 + i ) )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( 	(  particle_spec_1 + i ) )->pFoutEN ;
	void * *  sort_kernel = 	( 	(  particle_spec_1 + i ) )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( 	(  particle_spec_1 + i ) )->geo_rel_1st_kernel ;
	void * *  rel_1st_kernel = 	( 	(  particle_spec_1 + i ) )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( 	(  particle_spec_1 + i ) )->krook_collision_test_kernel ;
	void * *  boris_yee_kernel = 	( 	(  particle_spec_1 + i ) )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( 	(  particle_spec_1 + i ) )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( 	(  particle_spec_1 + i ) )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( 	(  particle_spec_1 + i ) )->move_back_kernel_kernel ;
	double  Mass = 	( 	(  particle_spec_1 + i ) )->Mass ;
	double  Charge = 	( 	(  particle_spec_1 + i ) )->Charge ;
	double  Number_particle_per_marker = 	( 	(  particle_spec_1 + i ) )->Number_particle_per_marker ;
	long  grid_cache_len = 	( 	(  particle_spec_1 + i ) )->grid_cache_len ;
	long  cu_cache_length = 	( 	(  particle_spec_1 + i ) )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( 	(  particle_spec_1 + i ) )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( 	(  particle_spec_1 + i ) )->calculate_rho_kernel ;
	void *  inoutput = 	( 	(  particle_spec_1 + i ) )->inoutput ;
	void *  xyzw = 	( 	(  particle_spec_1 + i ) )->xyzw ;
	void *  cu_cache = 	( 	(  particle_spec_1 + i ) )->cu_cache ;
	void *  cu_xyzw = 	( 	(  particle_spec_1 + i ) )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( 	(  particle_spec_1 + i ) )->adjoint_vec_pids ;
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
	double *  cu_cache_host = (((double * * )cu_cache))[0] ;
	int *  cu_xyzw_host = (((int * * )cu_xyzw))[0] ;
	long *  adjoint_vec_pids_host = (((long * * )adjoint_vec_pids))[0] ;
((p_to_left_len_buffer)[i] = 	malloc ( 	(  sizeof(int ) * numvec ) ));
	for (j=0 ; 	(  j < numvec ) ; j++)
	{
	long *  cur_adj_ids = 	(  adj_ids + 	(  j * NUM_SYNC_LAYER ) ) ;
	long *  cur_adj_procs = 	(  adj_processes + 	(  j * NUM_SYNC_LAYER ) ) ;
	long *  cur_local_tid = 	(  adj_local_tid + 	(  j * NUM_SYNC_LAYER ) ) ;
	long *  cur_adjoint_vec_pids = 	(  adjoint_vec_pids_host + 	(  j * 6 ) ) ;
	int *  cur_cu_xyzw = 	(  cu_xyzw_host + 	(  4 * j ) ) ;
	int  beg_to_left = (cur_cu_xyzw)[1] ;
	int  end_to_left = (cur_cu_xyzw)[2] ;
	double *  cur_cu_cache = 	(  cu_cache_host + 	(  j * 	(  cu_cache_length * 6 ) ) ) ;
	long   xyzarr  [3];((xyzarr)[0] = 1);
((xyzarr)[1] = 1);
((xyzarr)[2] = 1);
((xyzarr)[dir] = 0);
	long  left_pid = (cur_adj_procs)[	(  0 + 	(  1 * 	(  (xyzarr)[0] + 	(  3 * 	(  (xyzarr)[1] + 	(  3 * (xyzarr)[2] ) ) ) ) ) )] ;
	long  left_proc_id = 	(  left_pid / 	( pthis )->num_runtime ) ;
	long  cur_proc_id = (	(  adj_processes + 	(  j * NUM_SYNC_LAYER ) ))[	(  NUM_SYNC_LAYER / 2 )] ;
	int  local_xyz_all_tmp = 	(  0 + 	(  1 * 	(  (xyzarr)[0] + 	(  3 * 	(  (xyzarr)[1] + 	(  3 * (xyzarr)[2] ) ) ) ) ) ) ;
	long  left_id = (cur_adj_ids)[local_xyz_all_tmp] ;
	long  left_local_tid = (cur_local_tid)[local_xyz_all_tmp] ;
	long  cur_left_id_ismin1 = (cur_adjoint_vec_pids)[	(  	(  2 * dir ) + 	(  0 / 2 ) )] ;
	long  cur_id = (cur_adj_ids)[	(  NUM_SYNC_LAYER / 2 )] ;
	int  to_left_len = 	(  end_to_left - beg_to_left ) ;
(((p_to_left_len_buffer)[i])[j] = to_left_len);
	if (  	(  cur_left_id_ismin1 == -1 )  ){  
			if (  	(  left_proc_id != cur_rank )  ){  
			PS_MPI_Isend ( 	(  (p_to_left_len_buffer)[i] + j ) , 1 , PS_MPI_INT , left_proc_id , 	(  left_id * 2 ) , comm , 	(  (rqst)[i] + j ) );
	PS_MPI_Isend ( 	(  cur_cu_cache + 	(  beg_to_left * 6 ) ) , 	(  to_left_len * 6 ) , PS_MPI_DOUBLE , left_proc_id , 	(  1 + 	(  left_id * 2 ) ) , comm , 	(  (rqst)[i] + 	(  numvec + j ) ) );

	}else{
		0;

	 }

	}else{
		0;

	 }
}}	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  pfield = 	( 	(  particle_spec_1 + i ) )->pfield ;
	Field3D_Seq *  pfieldE = 	( 	(  particle_spec_1 + i ) )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( 	(  particle_spec_1 + i ) )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( 	(  particle_spec_1 + i ) )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( 	(  particle_spec_1 + i ) )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( 	(  particle_spec_1 + i ) )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( 	(  particle_spec_1 + i ) )->pFoutEN ;
	void * *  sort_kernel = 	( 	(  particle_spec_1 + i ) )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( 	(  particle_spec_1 + i ) )->geo_rel_1st_kernel ;
	void * *  rel_1st_kernel = 	( 	(  particle_spec_1 + i ) )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( 	(  particle_spec_1 + i ) )->krook_collision_test_kernel ;
	void * *  boris_yee_kernel = 	( 	(  particle_spec_1 + i ) )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( 	(  particle_spec_1 + i ) )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( 	(  particle_spec_1 + i ) )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( 	(  particle_spec_1 + i ) )->move_back_kernel_kernel ;
	double  Mass = 	( 	(  particle_spec_1 + i ) )->Mass ;
	double  Charge = 	( 	(  particle_spec_1 + i ) )->Charge ;
	double  Number_particle_per_marker = 	( 	(  particle_spec_1 + i ) )->Number_particle_per_marker ;
	long  grid_cache_len = 	( 	(  particle_spec_1 + i ) )->grid_cache_len ;
	long  cu_cache_length = 	( 	(  particle_spec_1 + i ) )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( 	(  particle_spec_1 + i ) )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( 	(  particle_spec_1 + i ) )->calculate_rho_kernel ;
	void *  inoutput = 	( 	(  particle_spec_1 + i ) )->inoutput ;
	void *  xyzw = 	( 	(  particle_spec_1 + i ) )->xyzw ;
	void *  cu_cache = 	( 	(  particle_spec_1 + i ) )->cu_cache ;
	void *  cu_xyzw = 	( 	(  particle_spec_1 + i ) )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( 	(  particle_spec_1 + i ) )->adjoint_vec_pids ;
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
	double *  cu_cache_host = (((double * * )cu_cache))[0] ;
	int *  cu_xyzw_host = (((int * * )cu_xyzw))[0] ;
	long *  adjoint_vec_pids_host = (((long * * )adjoint_vec_pids))[0] ;
	for (j=0 ; 	(  j < numvec ) ; j++)
	{
	long *  cur_adj_ids = 	(  adj_ids + 	(  j * NUM_SYNC_LAYER ) ) ;
	long *  cur_adj_procs = 	(  adj_processes + 	(  j * NUM_SYNC_LAYER ) ) ;
	long *  cur_local_tid = 	(  adj_local_tid + 	(  j * NUM_SYNC_LAYER ) ) ;
	long *  cur_adjoint_vec_pids = 	(  adjoint_vec_pids_host + 	(  j * 6 ) ) ;
	int *  cur_cu_xyzw = 	(  cu_xyzw_host + 	(  4 * j ) ) ;
	int  beg_to_left = (cur_cu_xyzw)[1] ;
	int  end_to_left = (cur_cu_xyzw)[2] ;
	double *  cur_cu_cache = 	(  cu_cache_host + 	(  j * 	(  cu_cache_length * 6 ) ) ) ;
	long   xyzarr  [3];((xyzarr)[0] = 1);
((xyzarr)[1] = 1);
((xyzarr)[2] = 1);
((xyzarr)[dir] = 2);
	long  left_pid = (cur_adj_procs)[	(  0 + 	(  1 * 	(  (xyzarr)[0] + 	(  3 * 	(  (xyzarr)[1] + 	(  3 * (xyzarr)[2] ) ) ) ) ) )] ;
	long  left_proc_id = 	(  left_pid / 	( pthis )->num_runtime ) ;
	long  cur_proc_id = (	(  adj_processes + 	(  j * NUM_SYNC_LAYER ) ))[	(  NUM_SYNC_LAYER / 2 )] ;
	int  local_xyz_all_tmp = 	(  0 + 	(  1 * 	(  (xyzarr)[0] + 	(  3 * 	(  (xyzarr)[1] + 	(  3 * (xyzarr)[2] ) ) ) ) ) ) ;
	long  left_id = (cur_adj_ids)[local_xyz_all_tmp] ;
	long  left_local_tid = (cur_local_tid)[local_xyz_all_tmp] ;
	long  cur_left_id_ismin1 = (cur_adjoint_vec_pids)[	(  	(  2 * dir ) + 	(  2 / 2 ) )] ;
	long  cur_id = (cur_adj_ids)[	(  NUM_SYNC_LAYER / 2 )] ;
	int  to_left_len = 	(  end_to_left - beg_to_left ) ;
	if (  	(  cur_left_id_ismin1 == -1 )  ){  
			volatile int  from_right_len ;
	int  cur_len = (cur_cu_xyzw)[0] ;
	if (  	(  left_pid != cur_proc_id )  ){  
			PS_MPI_Recv ( 	& ( from_right_len ) , 1 , PS_MPI_INT , left_proc_id , 	(  2 * cur_id ) , comm , NULL );
	if (  	(  	(  (cur_cu_xyzw)[0] + from_right_len ) >= beg_to_left )  ){  
			fprintf ( stderr , "[%e %e %e],offs=[%d %d %d]\n" , (cur_cu_cache)[0] , (cur_cu_cache)[1] , (cur_cu_cache)[2] , (global_x_offset)[j] , (global_y_offset)[j] , (global_z_offset)[j] );

	}else{
		0;

	 }
	assert ( 	(  	(  (cur_cu_xyzw)[0] + from_right_len ) < beg_to_left ) );
	PS_MPI_Recv ( 	(  cur_cu_cache + 	(  6 * cur_len ) ) , 	(  from_right_len * 6 ) , PS_MPI_DOUBLE , left_proc_id , 	(  1 + 	(  2 * cur_id ) ) , comm , NULL );

	}else{
		(from_right_len = 	(  (cu_xyzw_host)[	(  	(  4 * left_local_tid ) + 2 )] - (cu_xyzw_host)[	(  	(  4 * left_local_tid ) + 1 )] ));
	if (  	(  	(  (cur_cu_xyzw)[0] + from_right_len ) >= beg_to_left )  ){  
			fprintf ( stderr , "[%e %e %e],offs=[%d %d %d]\n" , (cur_cu_cache)[0] , (cur_cu_cache)[1] , (cur_cu_cache)[2] , (global_x_offset)[j] , (global_y_offset)[j] , (global_z_offset)[j] );

	}else{
		0;

	 }
	assert ( 	(  	(  (cur_cu_xyzw)[0] + from_right_len ) < beg_to_left ) );
	memcpy ( 	(  cur_cu_cache + 	(  6 * cur_len ) ) , 	(  cu_cache_host + 	(  	(  left_pid * 	(  6 * cu_cache_length ) ) + 	(  6 * (cu_xyzw_host)[	(  	(  4 * left_local_tid ) + 2 )] ) ) ) , 	(  from_right_len * 	(  6 * sizeof(double ) ) ) );

	 }
	long   xyzlenarr  [3];((xyzlenarr)[0] = xlen);
((xyzlenarr)[1] = ylen);
((xyzlenarr)[2] = zlen);
	long  XYZLEN = 	(  	(  1 - 0 ) * (xyzlenarr)[dir] ) ;
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
	for ((xyzx = 0) ; 	(  xyzx < from_right_len ) ; (xyzx = 	(  xyzx + 1 )))
	{
((cur_cu_cache)[	(  	(  6 * 	(  xyzx + cur_len ) ) + dir )] = 	(  (cur_cu_cache)[	(  	(  6 * 	(  xyzx + cur_len ) ) + dir )] + XYZLEN ));
}}}}}}((cur_cu_xyzw)[0] = 	(  (cur_cu_xyzw)[0] + from_right_len ));

	}else{
		0;

	 }
}}	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  pfield = 	( 	(  particle_spec_1 + i ) )->pfield ;
	Field3D_Seq *  pfieldE = 	( 	(  particle_spec_1 + i ) )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( 	(  particle_spec_1 + i ) )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( 	(  particle_spec_1 + i ) )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( 	(  particle_spec_1 + i ) )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( 	(  particle_spec_1 + i ) )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( 	(  particle_spec_1 + i ) )->pFoutEN ;
	void * *  sort_kernel = 	( 	(  particle_spec_1 + i ) )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( 	(  particle_spec_1 + i ) )->geo_rel_1st_kernel ;
	void * *  rel_1st_kernel = 	( 	(  particle_spec_1 + i ) )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( 	(  particle_spec_1 + i ) )->krook_collision_test_kernel ;
	void * *  boris_yee_kernel = 	( 	(  particle_spec_1 + i ) )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( 	(  particle_spec_1 + i ) )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( 	(  particle_spec_1 + i ) )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( 	(  particle_spec_1 + i ) )->move_back_kernel_kernel ;
	double  Mass = 	( 	(  particle_spec_1 + i ) )->Mass ;
	double  Charge = 	( 	(  particle_spec_1 + i ) )->Charge ;
	double  Number_particle_per_marker = 	( 	(  particle_spec_1 + i ) )->Number_particle_per_marker ;
	long  grid_cache_len = 	( 	(  particle_spec_1 + i ) )->grid_cache_len ;
	long  cu_cache_length = 	( 	(  particle_spec_1 + i ) )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( 	(  particle_spec_1 + i ) )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( 	(  particle_spec_1 + i ) )->calculate_rho_kernel ;
	void *  inoutput = 	( 	(  particle_spec_1 + i ) )->inoutput ;
	void *  xyzw = 	( 	(  particle_spec_1 + i ) )->xyzw ;
	void *  cu_cache = 	( 	(  particle_spec_1 + i ) )->cu_cache ;
	void *  cu_xyzw = 	( 	(  particle_spec_1 + i ) )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( 	(  particle_spec_1 + i ) )->adjoint_vec_pids ;
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
	double *  cu_cache_host = (((double * * )cu_cache))[0] ;
	int *  cu_xyzw_host = (((int * * )cu_xyzw))[0] ;
	long *  adjoint_vec_pids_host = (((long * * )adjoint_vec_pids))[0] ;
	for (j=0 ; 	(  j < numvec ) ; j++)
	{
	long *  cur_adj_ids = 	(  adj_ids + 	(  j * NUM_SYNC_LAYER ) ) ;
	long *  cur_adj_procs = 	(  adj_processes + 	(  j * NUM_SYNC_LAYER ) ) ;
	long *  cur_local_tid = 	(  adj_local_tid + 	(  j * NUM_SYNC_LAYER ) ) ;
	long *  cur_adjoint_vec_pids = 	(  adjoint_vec_pids_host + 	(  j * 6 ) ) ;
	int *  cur_cu_xyzw = 	(  cu_xyzw_host + 	(  4 * j ) ) ;
	long  beg_to_left = 0 ;
	long  end_to_left = 0 ;
	double *  cur_cu_cache = 	(  cu_cache_host + 	(  j * 	(  cu_cache_length * 6 ) ) ) ;
	long   xyzarr  [3];((xyzarr)[0] = 1);
((xyzarr)[1] = 1);
((xyzarr)[2] = 1);
((xyzarr)[dir] = 0);
	long  left_pid = (cur_adj_procs)[	(  0 + 	(  1 * 	(  (xyzarr)[0] + 	(  3 * 	(  (xyzarr)[1] + 	(  3 * (xyzarr)[2] ) ) ) ) ) )] ;
	long  left_proc_id = 	(  left_pid / 	( pthis )->num_runtime ) ;
	long  cur_proc_id = (	(  adj_processes + 	(  j * NUM_SYNC_LAYER ) ))[	(  NUM_SYNC_LAYER / 2 )] ;
	int  local_xyz_all_tmp = 	(  0 + 	(  1 * 	(  (xyzarr)[0] + 	(  3 * 	(  (xyzarr)[1] + 	(  3 * (xyzarr)[2] ) ) ) ) ) ) ;
	long  left_id = (cur_adj_ids)[local_xyz_all_tmp] ;
	long  left_local_tid = (cur_local_tid)[local_xyz_all_tmp] ;
	long  cur_left_id_ismin1 = (cur_adjoint_vec_pids)[	(  	(  2 * dir ) + 	(  0 / 2 ) )] ;
	long  cur_id = (cur_adj_ids)[	(  NUM_SYNC_LAYER / 2 )] ;
	int  to_left_len = 	(  end_to_left - beg_to_left ) ;
	if (  	(  cur_left_id_ismin1 == -1 )  ){  
			if (  	(  cur_proc_id != left_pid )  ){  
			PS_MPI_Wait ( 	(  (rqst)[i] + j ) , NULL );
	PS_MPI_Wait ( 	(  (rqst)[i] + 	(  numvec + j ) ) , NULL );

	}else{
		0;

	 }

	}else{
		0;

	 }
}}{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
	{
	free ( (p_to_left_len_buffer)[i] );
}}	free ( p_to_left_len_buffer );
}}}}}}	return  0 ;}
int  swap_particle_sort_host_r (Field3D_MPI *  pthis ,int  dir ){
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
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < 1 ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < 1 ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < num_spec ) ; (xyzx = 	(  xyzx + 1 )))
	{
	One_Particle_Collection *  particle_spec_1 = 	(  particles + 	(  xyzx * num_runtime ) ) ;
	long  i ;
	long  j ;
	int * *  p_to_left_len_buffer = 	malloc ( 	(  sizeof(int * ) * num_runtime ) ) ;
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  pfield = 	( 	(  particle_spec_1 + i ) )->pfield ;
	Field3D_Seq *  pfieldE = 	( 	(  particle_spec_1 + i ) )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( 	(  particle_spec_1 + i ) )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( 	(  particle_spec_1 + i ) )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( 	(  particle_spec_1 + i ) )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( 	(  particle_spec_1 + i ) )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( 	(  particle_spec_1 + i ) )->pFoutEN ;
	void * *  sort_kernel = 	( 	(  particle_spec_1 + i ) )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( 	(  particle_spec_1 + i ) )->geo_rel_1st_kernel ;
	void * *  rel_1st_kernel = 	( 	(  particle_spec_1 + i ) )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( 	(  particle_spec_1 + i ) )->krook_collision_test_kernel ;
	void * *  boris_yee_kernel = 	( 	(  particle_spec_1 + i ) )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( 	(  particle_spec_1 + i ) )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( 	(  particle_spec_1 + i ) )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( 	(  particle_spec_1 + i ) )->move_back_kernel_kernel ;
	double  Mass = 	( 	(  particle_spec_1 + i ) )->Mass ;
	double  Charge = 	( 	(  particle_spec_1 + i ) )->Charge ;
	double  Number_particle_per_marker = 	( 	(  particle_spec_1 + i ) )->Number_particle_per_marker ;
	long  grid_cache_len = 	( 	(  particle_spec_1 + i ) )->grid_cache_len ;
	long  cu_cache_length = 	( 	(  particle_spec_1 + i ) )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( 	(  particle_spec_1 + i ) )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( 	(  particle_spec_1 + i ) )->calculate_rho_kernel ;
	void *  inoutput = 	( 	(  particle_spec_1 + i ) )->inoutput ;
	void *  xyzw = 	( 	(  particle_spec_1 + i ) )->xyzw ;
	void *  cu_cache = 	( 	(  particle_spec_1 + i ) )->cu_cache ;
	void *  cu_xyzw = 	( 	(  particle_spec_1 + i ) )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( 	(  particle_spec_1 + i ) )->adjoint_vec_pids ;
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
	double *  cu_cache_host = (((double * * )cu_cache))[0] ;
	int *  cu_xyzw_host = (((int * * )cu_xyzw))[0] ;
	long *  adjoint_vec_pids_host = (((long * * )adjoint_vec_pids))[0] ;
((p_to_left_len_buffer)[i] = 	malloc ( 	(  sizeof(int ) * numvec ) ));
	for (j=0 ; 	(  j < numvec ) ; j++)
	{
	long *  cur_adj_ids = 	(  adj_ids + 	(  j * NUM_SYNC_LAYER ) ) ;
	long *  cur_adj_procs = 	(  adj_processes + 	(  j * NUM_SYNC_LAYER ) ) ;
	long *  cur_local_tid = 	(  adj_local_tid + 	(  j * NUM_SYNC_LAYER ) ) ;
	long *  cur_adjoint_vec_pids = 	(  adjoint_vec_pids_host + 	(  j * 6 ) ) ;
	int *  cur_cu_xyzw = 	(  cu_xyzw_host + 	(  4 * j ) ) ;
	int  beg_to_left = (cur_cu_xyzw)[3] ;
	long  end_to_left = cu_cache_length ;
	double *  cur_cu_cache = 	(  cu_cache_host + 	(  j * 	(  cu_cache_length * 6 ) ) ) ;
	long   xyzarr  [3];((xyzarr)[0] = 1);
((xyzarr)[1] = 1);
((xyzarr)[2] = 1);
((xyzarr)[dir] = 2);
	long  left_pid = (cur_adj_procs)[	(  0 + 	(  1 * 	(  (xyzarr)[0] + 	(  3 * 	(  (xyzarr)[1] + 	(  3 * (xyzarr)[2] ) ) ) ) ) )] ;
	long  left_proc_id = 	(  left_pid / 	( pthis )->num_runtime ) ;
	long  cur_proc_id = (	(  adj_processes + 	(  j * NUM_SYNC_LAYER ) ))[	(  NUM_SYNC_LAYER / 2 )] ;
	int  local_xyz_all_tmp = 	(  0 + 	(  1 * 	(  (xyzarr)[0] + 	(  3 * 	(  (xyzarr)[1] + 	(  3 * (xyzarr)[2] ) ) ) ) ) ) ;
	long  left_id = (cur_adj_ids)[local_xyz_all_tmp] ;
	long  left_local_tid = (cur_local_tid)[local_xyz_all_tmp] ;
	long  cur_left_id_ismin1 = (cur_adjoint_vec_pids)[	(  	(  2 * dir ) + 	(  2 / 2 ) )] ;
	long  cur_id = (cur_adj_ids)[	(  NUM_SYNC_LAYER / 2 )] ;
	int  to_left_len = 	(  end_to_left - beg_to_left ) ;
(((p_to_left_len_buffer)[i])[j] = to_left_len);
	if (  	(  cur_left_id_ismin1 == -1 )  ){  
			if (  	(  left_proc_id != cur_rank )  ){  
			PS_MPI_Isend ( 	(  (p_to_left_len_buffer)[i] + j ) , 1 , PS_MPI_INT , left_proc_id , 	(  left_id * 2 ) , comm , 	(  (rqst)[i] + j ) );
	PS_MPI_Isend ( 	(  cur_cu_cache + 	(  beg_to_left * 6 ) ) , 	(  to_left_len * 6 ) , PS_MPI_DOUBLE , left_proc_id , 	(  1 + 	(  left_id * 2 ) ) , comm , 	(  (rqst)[i] + 	(  numvec + j ) ) );

	}else{
		0;

	 }

	}else{
		0;

	 }
}}	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  pfield = 	( 	(  particle_spec_1 + i ) )->pfield ;
	Field3D_Seq *  pfieldE = 	( 	(  particle_spec_1 + i ) )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( 	(  particle_spec_1 + i ) )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( 	(  particle_spec_1 + i ) )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( 	(  particle_spec_1 + i ) )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( 	(  particle_spec_1 + i ) )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( 	(  particle_spec_1 + i ) )->pFoutEN ;
	void * *  sort_kernel = 	( 	(  particle_spec_1 + i ) )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( 	(  particle_spec_1 + i ) )->geo_rel_1st_kernel ;
	void * *  rel_1st_kernel = 	( 	(  particle_spec_1 + i ) )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( 	(  particle_spec_1 + i ) )->krook_collision_test_kernel ;
	void * *  boris_yee_kernel = 	( 	(  particle_spec_1 + i ) )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( 	(  particle_spec_1 + i ) )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( 	(  particle_spec_1 + i ) )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( 	(  particle_spec_1 + i ) )->move_back_kernel_kernel ;
	double  Mass = 	( 	(  particle_spec_1 + i ) )->Mass ;
	double  Charge = 	( 	(  particle_spec_1 + i ) )->Charge ;
	double  Number_particle_per_marker = 	( 	(  particle_spec_1 + i ) )->Number_particle_per_marker ;
	long  grid_cache_len = 	( 	(  particle_spec_1 + i ) )->grid_cache_len ;
	long  cu_cache_length = 	( 	(  particle_spec_1 + i ) )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( 	(  particle_spec_1 + i ) )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( 	(  particle_spec_1 + i ) )->calculate_rho_kernel ;
	void *  inoutput = 	( 	(  particle_spec_1 + i ) )->inoutput ;
	void *  xyzw = 	( 	(  particle_spec_1 + i ) )->xyzw ;
	void *  cu_cache = 	( 	(  particle_spec_1 + i ) )->cu_cache ;
	void *  cu_xyzw = 	( 	(  particle_spec_1 + i ) )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( 	(  particle_spec_1 + i ) )->adjoint_vec_pids ;
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
	double *  cu_cache_host = (((double * * )cu_cache))[0] ;
	int *  cu_xyzw_host = (((int * * )cu_xyzw))[0] ;
	long *  adjoint_vec_pids_host = (((long * * )adjoint_vec_pids))[0] ;
	for (j=0 ; 	(  j < numvec ) ; j++)
	{
	long *  cur_adj_ids = 	(  adj_ids + 	(  j * NUM_SYNC_LAYER ) ) ;
	long *  cur_adj_procs = 	(  adj_processes + 	(  j * NUM_SYNC_LAYER ) ) ;
	long *  cur_local_tid = 	(  adj_local_tid + 	(  j * NUM_SYNC_LAYER ) ) ;
	long *  cur_adjoint_vec_pids = 	(  adjoint_vec_pids_host + 	(  j * 6 ) ) ;
	int *  cur_cu_xyzw = 	(  cu_xyzw_host + 	(  4 * j ) ) ;
	int  beg_to_left = (cur_cu_xyzw)[3] ;
	long  end_to_left = cu_cache_length ;
	double *  cur_cu_cache = 	(  cu_cache_host + 	(  j * 	(  cu_cache_length * 6 ) ) ) ;
	long   xyzarr  [3];((xyzarr)[0] = 1);
((xyzarr)[1] = 1);
((xyzarr)[2] = 1);
((xyzarr)[dir] = 0);
	long  left_pid = (cur_adj_procs)[	(  0 + 	(  1 * 	(  (xyzarr)[0] + 	(  3 * 	(  (xyzarr)[1] + 	(  3 * (xyzarr)[2] ) ) ) ) ) )] ;
	long  left_proc_id = 	(  left_pid / 	( pthis )->num_runtime ) ;
	long  cur_proc_id = (	(  adj_processes + 	(  j * NUM_SYNC_LAYER ) ))[	(  NUM_SYNC_LAYER / 2 )] ;
	int  local_xyz_all_tmp = 	(  0 + 	(  1 * 	(  (xyzarr)[0] + 	(  3 * 	(  (xyzarr)[1] + 	(  3 * (xyzarr)[2] ) ) ) ) ) ) ;
	long  left_id = (cur_adj_ids)[local_xyz_all_tmp] ;
	long  left_local_tid = (cur_local_tid)[local_xyz_all_tmp] ;
	long  cur_left_id_ismin1 = (cur_adjoint_vec_pids)[	(  	(  2 * dir ) + 	(  0 / 2 ) )] ;
	long  cur_id = (cur_adj_ids)[	(  NUM_SYNC_LAYER / 2 )] ;
	int  to_left_len = 	(  end_to_left - beg_to_left ) ;
	if (  	(  cur_left_id_ismin1 == -1 )  ){  
			volatile int  from_right_len ;
	int  cur_len = (cur_cu_xyzw)[0] ;
	if (  	(  left_pid != cur_proc_id )  ){  
			PS_MPI_Recv ( 	& ( from_right_len ) , 1 , PS_MPI_INT , left_proc_id , 	(  2 * cur_id ) , comm , NULL );
	if (  	(  	(  (cur_cu_xyzw)[0] + from_right_len ) >= beg_to_left )  ){  
			fprintf ( stderr , "[%e %e %e],offs=[%d %d %d]\n" , (cur_cu_cache)[0] , (cur_cu_cache)[1] , (cur_cu_cache)[2] , (global_x_offset)[j] , (global_y_offset)[j] , (global_z_offset)[j] );

	}else{
		0;

	 }
	assert ( 	(  	(  (cur_cu_xyzw)[0] + from_right_len ) < beg_to_left ) );
	PS_MPI_Recv ( 	(  cur_cu_cache + 	(  6 * cur_len ) ) , 	(  from_right_len * 6 ) , PS_MPI_DOUBLE , left_proc_id , 	(  1 + 	(  2 * cur_id ) ) , comm , NULL );

	}else{
		(from_right_len = 	(  (cu_xyzw_host)[	(  	(  4 * left_local_tid ) + 3 )] - cu_cache_length ));
	if (  	(  	(  (cur_cu_xyzw)[0] + from_right_len ) >= beg_to_left )  ){  
			fprintf ( stderr , "[%e %e %e],offs=[%d %d %d]\n" , (cur_cu_cache)[0] , (cur_cu_cache)[1] , (cur_cu_cache)[2] , (global_x_offset)[j] , (global_y_offset)[j] , (global_z_offset)[j] );

	}else{
		0;

	 }
	assert ( 	(  	(  (cur_cu_xyzw)[0] + from_right_len ) < beg_to_left ) );
	memcpy ( 	(  cur_cu_cache + 	(  6 * cur_len ) ) , 	(  cu_cache_host + 	(  	(  left_pid * 	(  6 * cu_cache_length ) ) + 	(  6 * (cu_xyzw_host)[	(  	(  4 * left_local_tid ) + 3 )] ) ) ) , 	(  from_right_len * 	(  6 * sizeof(double ) ) ) );

	 }
	long   xyzlenarr  [3];((xyzlenarr)[0] = xlen);
((xyzlenarr)[1] = ylen);
((xyzlenarr)[2] = zlen);
	long  XYZLEN = 	(  	(  1 - 2 ) * (xyzlenarr)[dir] ) ;
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
	for ((xyzx = 0) ; 	(  xyzx < from_right_len ) ; (xyzx = 	(  xyzx + 1 )))
	{
((cur_cu_cache)[	(  	(  6 * 	(  xyzx + cur_len ) ) + dir )] = 	(  (cur_cu_cache)[	(  	(  6 * 	(  xyzx + cur_len ) ) + dir )] + XYZLEN ));
}}}}}}((cur_cu_xyzw)[0] = 	(  (cur_cu_xyzw)[0] + from_right_len ));

	}else{
		0;

	 }
}}	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  pfield = 	( 	(  particle_spec_1 + i ) )->pfield ;
	Field3D_Seq *  pfieldE = 	( 	(  particle_spec_1 + i ) )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( 	(  particle_spec_1 + i ) )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( 	(  particle_spec_1 + i ) )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( 	(  particle_spec_1 + i ) )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( 	(  particle_spec_1 + i ) )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( 	(  particle_spec_1 + i ) )->pFoutEN ;
	void * *  sort_kernel = 	( 	(  particle_spec_1 + i ) )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( 	(  particle_spec_1 + i ) )->geo_rel_1st_kernel ;
	void * *  rel_1st_kernel = 	( 	(  particle_spec_1 + i ) )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( 	(  particle_spec_1 + i ) )->krook_collision_test_kernel ;
	void * *  boris_yee_kernel = 	( 	(  particle_spec_1 + i ) )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( 	(  particle_spec_1 + i ) )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( 	(  particle_spec_1 + i ) )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( 	(  particle_spec_1 + i ) )->move_back_kernel_kernel ;
	double  Mass = 	( 	(  particle_spec_1 + i ) )->Mass ;
	double  Charge = 	( 	(  particle_spec_1 + i ) )->Charge ;
	double  Number_particle_per_marker = 	( 	(  particle_spec_1 + i ) )->Number_particle_per_marker ;
	long  grid_cache_len = 	( 	(  particle_spec_1 + i ) )->grid_cache_len ;
	long  cu_cache_length = 	( 	(  particle_spec_1 + i ) )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( 	(  particle_spec_1 + i ) )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( 	(  particle_spec_1 + i ) )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( 	(  particle_spec_1 + i ) )->calculate_rho_kernel ;
	void *  inoutput = 	( 	(  particle_spec_1 + i ) )->inoutput ;
	void *  xyzw = 	( 	(  particle_spec_1 + i ) )->xyzw ;
	void *  cu_cache = 	( 	(  particle_spec_1 + i ) )->cu_cache ;
	void *  cu_xyzw = 	( 	(  particle_spec_1 + i ) )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( 	(  particle_spec_1 + i ) )->adjoint_vec_pids ;
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
	double *  cu_cache_host = (((double * * )cu_cache))[0] ;
	int *  cu_xyzw_host = (((int * * )cu_xyzw))[0] ;
	long *  adjoint_vec_pids_host = (((long * * )adjoint_vec_pids))[0] ;
	for (j=0 ; 	(  j < numvec ) ; j++)
	{
	long *  cur_adj_ids = 	(  adj_ids + 	(  j * NUM_SYNC_LAYER ) ) ;
	long *  cur_adj_procs = 	(  adj_processes + 	(  j * NUM_SYNC_LAYER ) ) ;
	long *  cur_local_tid = 	(  adj_local_tid + 	(  j * NUM_SYNC_LAYER ) ) ;
	long *  cur_adjoint_vec_pids = 	(  adjoint_vec_pids_host + 	(  j * 6 ) ) ;
	int *  cur_cu_xyzw = 	(  cu_xyzw_host + 	(  4 * j ) ) ;
	long  beg_to_left = 0 ;
	long  end_to_left = 0 ;
	double *  cur_cu_cache = 	(  cu_cache_host + 	(  j * 	(  cu_cache_length * 6 ) ) ) ;
	long   xyzarr  [3];((xyzarr)[0] = 1);
((xyzarr)[1] = 1);
((xyzarr)[2] = 1);
((xyzarr)[dir] = 2);
	long  left_pid = (cur_adj_procs)[	(  0 + 	(  1 * 	(  (xyzarr)[0] + 	(  3 * 	(  (xyzarr)[1] + 	(  3 * (xyzarr)[2] ) ) ) ) ) )] ;
	long  left_proc_id = 	(  left_pid / 	( pthis )->num_runtime ) ;
	long  cur_proc_id = (	(  adj_processes + 	(  j * NUM_SYNC_LAYER ) ))[	(  NUM_SYNC_LAYER / 2 )] ;
	int  local_xyz_all_tmp = 	(  0 + 	(  1 * 	(  (xyzarr)[0] + 	(  3 * 	(  (xyzarr)[1] + 	(  3 * (xyzarr)[2] ) ) ) ) ) ) ;
	long  left_id = (cur_adj_ids)[local_xyz_all_tmp] ;
	long  left_local_tid = (cur_local_tid)[local_xyz_all_tmp] ;
	long  cur_left_id_ismin1 = (cur_adjoint_vec_pids)[	(  	(  2 * dir ) + 	(  2 / 2 ) )] ;
	long  cur_id = (cur_adj_ids)[	(  NUM_SYNC_LAYER / 2 )] ;
	int  to_left_len = 	(  end_to_left - beg_to_left ) ;
	if (  	(  cur_left_id_ismin1 == -1 )  ){  
			if (  	(  cur_proc_id != left_pid )  ){  
			PS_MPI_Wait ( 	(  (rqst)[i] + j ) , NULL );
	PS_MPI_Wait ( 	(  (rqst)[i] + 	(  numvec + j ) ) , NULL );

	}else{
		0;

	 }

	}else{
		0;

	 }
}}{
	long  i ;
	for ((i = 0) ; 	(  i < num_runtime ) ; (i = 	(  i + 1 )))
	{
	free ( (p_to_left_len_buffer)[i] );
}}	free ( p_to_left_len_buffer );
}}}}}}	return  0 ;}
void  dump_particles (Field3D_MPI *  pthis ,FILE *  fp ){
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
	for (i=0 ; 	(  i < 	(  num_spec * num_runtime ) ) ; i++)
	{
	dump_particles_mpi ( 	(  particles + i ) , fp );
}	fflush ( fp );
}
int  call_particle_sort_mpi (Field3D_MPI *  pthis ,int  dir ,int  use_vlo ){
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
	for (i=0 ; 	(  i < 	(  num_spec * num_runtime ) ) ; i++)
	{
	call_particle_sort_single ( 	(  particles + i ) , dir , use_vlo );
	Field3D_Seq *  pfield = 	( 	(  particles + i ) )->pfield ;
	Field3D_Seq *  pfieldE = 	( 	(  particles + i ) )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( 	(  particles + i ) )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( 	(  particles + i ) )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( 	(  particles + i ) )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( 	(  particles + i ) )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( 	(  particles + i ) )->pFoutEN ;
	void * *  sort_kernel = 	( 	(  particles + i ) )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( 	(  particles + i ) )->geo_rel_1st_kernel ;
	void * *  rel_1st_kernel = 	( 	(  particles + i ) )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( 	(  particles + i ) )->krook_collision_test_kernel ;
	void * *  boris_yee_kernel = 	( 	(  particles + i ) )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( 	(  particles + i ) )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( 	(  particles + i ) )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( 	(  particles + i ) )->move_back_kernel_kernel ;
	double  Mass = 	( 	(  particles + i ) )->Mass ;
	double  Charge = 	( 	(  particles + i ) )->Charge ;
	double  Number_particle_per_marker = 	( 	(  particles + i ) )->Number_particle_per_marker ;
	long  grid_cache_len = 	( 	(  particles + i ) )->grid_cache_len ;
	long  cu_cache_length = 	( 	(  particles + i ) )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( 	(  particles + i ) )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( 	(  particles + i ) )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( 	(  particles + i ) )->split_pass_z_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( 	(  particles + i ) )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( 	(  particles + i ) )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( 	(  particles + i ) )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( 	(  particles + i ) )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( 	(  particles + i ) )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( 	(  particles + i ) )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( 	(  particles + i ) )->calculate_rho_kernel ;
	void *  inoutput = 	( 	(  particles + i ) )->inoutput ;
	void *  xyzw = 	( 	(  particles + i ) )->xyzw ;
	void *  cu_cache = 	( 	(  particles + i ) )->cu_cache ;
	void *  cu_xyzw = 	( 	(  particles + i ) )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( 	(  particles + i ) )->adjoint_vec_pids ;
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
			c_pscmc_mem_sync_d2h ( cu_cache );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_d2h ( cu_cache );

	}else{
		0;

	 }

	 }
	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_d2h ( cu_xyzw );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_d2h ( cu_xyzw );

	}else{
		0;

	 }

	 }
}	swap_particle_sort_host_l ( pthis , dir );
	swap_particle_sort_host_r ( pthis , dir );
	for (i=0 ; 	(  i < 	(  num_runtime * num_spec ) ) ; i++)
	{
	Field3D_Seq *  pfield = 	( 	(  particles + i ) )->pfield ;
	Field3D_Seq *  pfieldE = 	( 	(  particles + i ) )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( 	(  particles + i ) )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( 	(  particles + i ) )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( 	(  particles + i ) )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( 	(  particles + i ) )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( 	(  particles + i ) )->pFoutEN ;
	void * *  sort_kernel = 	( 	(  particles + i ) )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( 	(  particles + i ) )->geo_rel_1st_kernel ;
	void * *  rel_1st_kernel = 	( 	(  particles + i ) )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( 	(  particles + i ) )->krook_collision_test_kernel ;
	void * *  boris_yee_kernel = 	( 	(  particles + i ) )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( 	(  particles + i ) )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( 	(  particles + i ) )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( 	(  particles + i ) )->move_back_kernel_kernel ;
	double  Mass = 	( 	(  particles + i ) )->Mass ;
	double  Charge = 	( 	(  particles + i ) )->Charge ;
	double  Number_particle_per_marker = 	( 	(  particles + i ) )->Number_particle_per_marker ;
	long  grid_cache_len = 	( 	(  particles + i ) )->grid_cache_len ;
	long  cu_cache_length = 	( 	(  particles + i ) )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( 	(  particles + i ) )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( 	(  particles + i ) )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( 	(  particles + i ) )->split_pass_z_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( 	(  particles + i ) )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( 	(  particles + i ) )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( 	(  particles + i ) )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( 	(  particles + i ) )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( 	(  particles + i ) )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( 	(  particles + i ) )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( 	(  particles + i ) )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( 	(  particles + i ) )->calculate_rho_kernel ;
	void *  inoutput = 	( 	(  particles + i ) )->inoutput ;
	void *  xyzw = 	( 	(  particles + i ) )->xyzw ;
	void *  cu_cache = 	( 	(  particles + i ) )->cu_cache ;
	void *  cu_xyzw = 	( 	(  particles + i ) )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( 	(  particles + i ) )->adjoint_vec_pids ;
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
			c_pscmc_mem_sync_h2d ( cu_cache );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( cu_cache );

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
	if (  	(  0 == CD_type )  ){  
			c_call_move_back_kernel_single ( 	(  particles + i ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_call_move_back_kernel_single ( 	(  particles + i ) );

	}else{
		0;

	 }

	 }
}	return  0 ;}
