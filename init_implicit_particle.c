#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
	#ifndef   NCSPIC_SEQ_FIELD    
		#include <mpi.h>

#define PS_MPI_CHAR MPI_CHAR

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
	void *   sync_layer_pscmc  [NUM_SYNC_LAYER];	void *   swap_layer_pscmc  [NUM_SYNC_LAYER];	void *   sync_kernels  [NUM_SYNC_KERNEL];	void *   fdtd_kernels  [NUM_FDTD_KERNEL];	void *   dm_kernels  [3];	void *   dmbihamt_kernels  [7];	void *   geo_yeefdtd_kernels  [2];	void *   geo_yeefdtd_rect_kernels  [1];	void *   hydroA_kernels  [8];	void *   yee_abc_kernels  [8];	void *   yee_pec_kernels  [8];	void *   yee_damp_kernels  [8];	void *   yee_setfix_kernels  [8];	void *  rdcd ;
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
	void *  blas_mulxy_numele3_kernel ;
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
	void *   sort_kernel  [6];	void *   geo_rel_1st_kernel  [9];	void *   implicit_kernel  [2];	void *   rel_1st_kernel  [2];	void *   krook_collision_test_kernel  [2];	void *   nonrel_test_kernel  [18];	void *   boris_yee_kernel  [1];	void *  cu_swap_l_kernel ;
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
	void *  split_pass_x_nopush_kernel ;
	void *  split_pass_y_nopush_kernel ;
	void *  split_pass_z_nopush_kernel ;
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
	void *  split_pass_x_vlo_nopush_kernel ;
	void *  split_pass_y_vlo_nopush_kernel ;
	void *  split_pass_z_vlo_nopush_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_nopush_small_grids_kernel ;
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
	Field3D_MPI  MPI_fieldEtmp2 ;
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
	int  o_N_l ;
	int  o_N_M ;
	double *  o_pmass ;
	double *  o_pcharge ;
	int *  o_particle_type ;
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
} bicg_space;typedef struct { 	bicg_space  bs ;
	linear_operator_mpi  oscc ;
	Field3D_MPI *  x0 ;
	Field3D_MPI *  oscc_x0 ;
	Field3D_MPI *  res_tmp ;
	void *  fv ;
	void *   p_vfv  [5];	int  newton_zmax ;
	int  zmax ;
	double  solve_err ;
	double  newton_solve_err ;
	double  epsl ;
} jfnk_newton_space;
	#else
		
	 #endif
#include "genrand.h"
#include "cfgcst.h"
#include "init_field3d_mpi.h"
#include "sync_fields.h"
#include "c_/c_pscmc_inc.h"
#include "openmp_/openmp_pscmc_inc.h"
#include "c_/hydro_A.kernel_inc.h"
#include "c_/implicit_particle_mover.kernel_inc.h"
#include "c_/type3_georel.kernel_inc.h"
#include "c_/inner_split_pass.kernel_inc.h"
#include "c_/geo_particle_iter_mass.kernel_inc.h"
#include "c_/geo_particle_iter.kernel_inc.h"
#include "c_/rel_particle_iter.kernel_inc.h"
#include "c_/yeefdtd.kernel_inc.h"
#include "c_/mergefields.kernel_inc.h"
#include "c_/miniblas.kernel_inc.h"
#include "c_/general_partial_sort.kernel_inc.h"
#include "c_/move_back.kernel_inc.h"
#include "c_/particle_iter.kernel_inc.h"
#include "c_/mur_abc.kernel_inc.h"
#include "c_/dmbihamt.kernel_inc.h"
#include "c_/dm.kernel_inc.h"
#include "c_/geo_yeefdtd_rect.kernel_inc.h"
#include "c_/geo_yeefdtd.kernel_inc.h"
#include "c_yeefdtd.h"
#include "openmp_/hydro_A.kernel_inc.h"
#include "openmp_/implicit_particle_mover.kernel_inc.h"
#include "openmp_/type3_georel.kernel_inc.h"
#include "openmp_/inner_split_pass.kernel_inc.h"
#include "openmp_/geo_particle_iter_mass.kernel_inc.h"
#include "openmp_/geo_particle_iter.kernel_inc.h"
#include "openmp_/rel_particle_iter.kernel_inc.h"
#include "openmp_/yeefdtd.kernel_inc.h"
#include "openmp_/mergefields.kernel_inc.h"
#include "openmp_/miniblas.kernel_inc.h"
#include "openmp_/general_partial_sort.kernel_inc.h"
#include "openmp_/move_back.kernel_inc.h"
#include "openmp_/particle_iter.kernel_inc.h"
#include "openmp_/mur_abc.kernel_inc.h"
#include "openmp_/dmbihamt.kernel_inc.h"
#include "openmp_/dm.kernel_inc.h"
#include "openmp_/geo_yeefdtd_rect.kernel_inc.h"
#include "openmp_/geo_yeefdtd.kernel_inc.h"
#include "openmp_yeefdtd.h"
int  init_dist_particle_nogrid_opc (One_Particle_Collection *  pthis ,int  tgrid_load ,double  VT ,int  fluid_dim ){
	Field3D_Seq *  pfield = 	( pthis )->pfield ;
	Field3D_Seq *  pfieldE = 	( pthis )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( pthis )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( pthis )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( pthis )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( pthis )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( pthis )->pFoutEN ;
	void * *  sort_kernel = 	( pthis )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( pthis )->geo_rel_1st_kernel ;
	void * *  implicit_kernel = 	( pthis )->implicit_kernel ;
	void * *  rel_1st_kernel = 	( pthis )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( pthis )->krook_collision_test_kernel ;
	void * *  nonrel_test_kernel = 	( pthis )->nonrel_test_kernel ;
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
	void *  split_pass_x_nopush_kernel = 	( pthis )->split_pass_x_nopush_kernel ;
	void *  split_pass_y_nopush_kernel = 	( pthis )->split_pass_y_nopush_kernel ;
	void *  split_pass_z_nopush_kernel = 	( pthis )->split_pass_z_nopush_kernel ;
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
	void *  split_pass_x_vlo_nopush_kernel = 	( pthis )->split_pass_x_vlo_nopush_kernel ;
	void *  split_pass_y_vlo_nopush_kernel = 	( pthis )->split_pass_y_vlo_nopush_kernel ;
	void *  split_pass_z_vlo_nopush_kernel = 	( pthis )->split_pass_z_vlo_nopush_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( pthis )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( pthis )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( pthis )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_nopush_small_grids_kernel ;
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
	void * *  implicit_kernel = 	( pthis )->implicit_kernel ;
	void * *  rel_1st_kernel = 	( pthis )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( pthis )->krook_collision_test_kernel ;
	void * *  nonrel_test_kernel = 	( pthis )->nonrel_test_kernel ;
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
	void *  split_pass_x_nopush_kernel = 	( pthis )->split_pass_x_nopush_kernel ;
	void *  split_pass_y_nopush_kernel = 	( pthis )->split_pass_y_nopush_kernel ;
	void *  split_pass_z_nopush_kernel = 	( pthis )->split_pass_z_nopush_kernel ;
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
	void *  split_pass_x_vlo_nopush_kernel = 	( pthis )->split_pass_x_vlo_nopush_kernel ;
	void *  split_pass_y_vlo_nopush_kernel = 	( pthis )->split_pass_y_vlo_nopush_kernel ;
	void *  split_pass_z_vlo_nopush_kernel = 	( pthis )->split_pass_z_vlo_nopush_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( pthis )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( pthis )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( pthis )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_nopush_small_grids_kernel ;
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
	void * *  dmbihamt_kernels = 	( pfield )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pfield )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pfield )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( pfield )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( pfield )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pfield )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pfield )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( pfield )->yee_setfix_kernels ;
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
	void *  blas_mulxy_numele3_kernel = 	( pfield )->blas_mulxy_numele3_kernel ;
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
	double *  host_data = (((double * * )cu_cache))[0] ;
	int *  cu_xyzw_data = (((int * * )cu_xyzw))[0] ;
{
	long  cur_pcid ;
	for ((cur_pcid = 0) ; 	(  cur_pcid < numvec ) ; (cur_pcid = 	(  cur_pcid + 1 )))
	{
	double *  cu_r_0 = 	(  host_data + 	(  cur_pcid * 	(  cu_cache_length * 6 ) ) ) ;
	int *  cu_xyzw_0 = 	(  cu_xyzw_data + 	(  cur_pcid * 4 ) ) ;
	int  cu_load ;
(cu_load = 	(  tgrid_load * 	(  xlen * 	(  ylen * zlen ) ) ));
((cu_xyzw_0)[0] = cu_load);
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
	long  offset_grid = 	(  xyzx + 	(  xlen * 	(  xyzy + 	(  ylen * xyzz ) ) ) ) ;
{
	long  l ;
	for ((l = 0) ; 	(  l < tgrid_load ) ; (l = 	(  l + 1 )))
	{
	double *  cu_r_current = 	(  cu_r_0 + 	(  	(  	(  offset_grid * tgrid_load ) + l ) * 6 ) ) ;
((cu_r_current)[0] = 	(  xyzx + 5.00000000000000000e-01 ));
((cu_r_current)[1] = 	(  xyzy + 5.00000000000000000e-01 ));
((cu_r_current)[2] = 	(  xyzz + 5.00000000000000000e-01 ));
((cu_r_current)[3] = 	maxwell_dist ( 0 , VT ));
((cu_r_current)[4] = 	maxwell_dist ( 0 , VT ));
((cu_r_current)[5] = 	maxwell_dist ( 0 , VT ));
	if (  	(  fluid_dim & 1 )  ){  
		((cu_r_current)[0] = 	(  	(  	(  l + 5.00000000000000000e-01 ) / tgrid_load ) + xyzx ));

	}else{
			if (  	(  fluid_dim & 2 )  ){  
		((cu_r_current)[1] = 	(  	(  	(  l + 5.00000000000000000e-01 ) / tgrid_load ) + xyzy ));

	}else{
			if (  	(  fluid_dim & 4 )  ){  
		((cu_r_current)[2] = 	(  	(  	(  l + 5.00000000000000000e-01 ) / tgrid_load ) + xyzz ));

	}else{
		0;

	 }

	 }

	 }
}}}}}}}}}}}	return  0 ;}
int  init_dist_particle_nogrid_fmpi (Field3D_MPI *  pthis ,int  fluid_dim ){
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
	for ((i = 0) ; 	(  i < num_spec ) ; (i = 	(  i + 1 )))
	{
	if (  	(  (	( ((Particle_in_Cell_MPI * )pthis) )->o_particle_type)[i] == 1 )  ){  
		{
	long  j ;
	for ((j = 0) ; 	(  j < num_runtime ) ; (j = 	(  j + 1 )))
	{
	init_dist_particle_nogrid_opc ( 	(  	( pthis )->particles + 	(  	(  i * num_runtime ) + j ) ) , 	call_GET_INIT_LOAD ( i ) , 	call_GET_INIT_VT ( i ) , fluid_dim );
}}
	}else{
		0;

	 }
}}}
int  init_implicit_particle (One_Particle_Collection *  pthis ){
{
	void *  pe = 	( pthis->pfield )->pe ;
	long  xlen = 	( pthis->pfield )->xlen ;
	long  ylen = 	( pthis->pfield )->ylen ;
	long  zlen = 	( pthis->pfield )->zlen ;
	long  xblock = 	( pthis->pfield )->xblock ;
	long  yblock = 	( pthis->pfield )->yblock ;
	long  zblock = 	( pthis->pfield )->zblock ;
	long  numvec = 	( pthis->pfield )->numvec ;
	long  x_num_thread_block = 	( pthis->pfield )->x_num_thread_block ;
	long  y_num_thread_block = 	( pthis->pfield )->y_num_thread_block ;
	long  z_num_thread_block = 	( pthis->pfield )->z_num_thread_block ;
	int  ovlp = 	( pthis->pfield )->ovlp ;
	int  num_ele = 	( pthis->pfield )->num_ele ;
	int  CD_type = 	( pthis->pfield )->CD_type ;
	void * *  sync_layer_pscmc = 	( pthis->pfield )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( pthis->pfield )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( pthis->pfield )->sync_kernels ;
	void * *  fdtd_kernels = 	( pthis->pfield )->fdtd_kernels ;
	void * *  dm_kernels = 	( pthis->pfield )->dm_kernels ;
	void * *  dmbihamt_kernels = 	( pthis->pfield )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pthis->pfield )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pthis->pfield )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( pthis->pfield )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( pthis->pfield )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pthis->pfield )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pthis->pfield )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( pthis->pfield )->yee_setfix_kernels ;
	void *  rdcd = 	( pthis->pfield )->rdcd ;
	double *  rdcd_host = 	( pthis->pfield )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( pthis->pfield )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( pthis->pfield )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( pthis->pfield )->cur_rankz_pscmc ;
	void *  xoffset = 	( pthis->pfield )->xoffset ;
	void *  yoffset = 	( pthis->pfield )->yoffset ;
	void *  zoffset = 	( pthis->pfield )->zoffset ;
	long *  global_x_offset = 	( pthis->pfield )->global_x_offset ;
	long *  global_y_offset = 	( pthis->pfield )->global_y_offset ;
	long *  global_z_offset = 	( pthis->pfield )->global_z_offset ;
	long *  global_id = 	( pthis->pfield )->global_id ;
	long  global_pid = 	( pthis->pfield )->global_pid ;
	long *  adj_ids = 	( pthis->pfield )->adj_ids ;
	long *  adj_processes = 	( pthis->pfield )->adj_processes ;
	long *  adj_local_tid = 	( pthis->pfield )->adj_local_tid ;
	void *  main_data = 	( pthis->pfield )->main_data ;
	double  delta_x = 	( pthis->pfield )->delta_x ;
	double  delta_y = 	( pthis->pfield )->delta_y ;
	double  delta_z = 	( pthis->pfield )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( pthis->pfield )->blas_yiszero_synced_kernel ;
	void *  blas_mulxy_numele3_kernel = 	( pthis->pfield )->blas_mulxy_numele3_kernel ;
	void *  blas_yiszero_kernel = 	( pthis->pfield )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( pthis->pfield )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( pthis->pfield )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( pthis->pfield )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( pthis->pfield )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( pthis->pfield )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( pthis->pfield )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( pthis->pfield )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( pthis->pfield )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( pthis->pfield )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( pthis->pfield )->blas_sum_kernel ;
{
	size_t  structlen ;
	if (  	(  0 == CD_type )  ){  
			c_split_pass_xyzE_particle_push_r_get_struct_len ( 	& ( structlen ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_xyzE_particle_push_r_get_struct_len ( 	& ( structlen ) );

	}else{
		0;

	 }

	 }
((	( pthis )->implicit_kernel)[1] = 	malloc ( structlen ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_xyzE_particle_push_r_init ( pe , (	( pthis )->implicit_kernel)[1] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_xyzE_particle_push_r_init ( pe , (	( pthis )->implicit_kernel)[1] );

	}else{
		0;

	 }

	 }
}{
	size_t  structlen ;
	if (  	(  0 == CD_type )  ){  
			c_split_pass_xyzE_particle_get_struct_len ( 	& ( structlen ) );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_xyzE_particle_get_struct_len ( 	& ( structlen ) );

	}else{
		0;

	 }

	 }
((	( pthis )->implicit_kernel)[0] = 	malloc ( structlen ));
	if (  	(  0 == CD_type )  ){  
			c_split_pass_xyzE_particle_init ( pe , (	( pthis )->implicit_kernel)[0] );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_split_pass_xyzE_particle_init ( pe , (	( pthis )->implicit_kernel)[0] );

	}else{
		0;

	 }

	 }
}}	return  0 ;}
int  init_implicit_particle_mpi (Field3D_MPI *  pthis ){
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
	for ((i = 0) ; 	(  i < num_spec ) ; (i = 	(  i + 1 )))
	{
{
	long  j ;
	for ((j = 0) ; 	(  j < num_runtime ) ; (j = 	(  j + 1 )))
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
	void * *  dmbihamt_kernels = 	( 	(  	( pthis )->data + j ) )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  	( pthis )->data + j ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  	( pthis )->data + j ) )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( 	(  	( pthis )->data + j ) )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( 	(  	( pthis )->data + j ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  	( pthis )->data + j ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  	( pthis )->data + j ) )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( 	(  	( pthis )->data + j ) )->yee_setfix_kernels ;
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
	void *  blas_mulxy_numele3_kernel = 	( 	(  	( pthis )->data + j ) )->blas_mulxy_numele3_kernel ;
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
	init_implicit_particle ( 	(  	( pthis )->particles + 	(  	(  i * num_runtime ) + j ) ) );
}}}}	return  0 ;}
int  c_One_Particle_Collection_split_pass_xyzE_particle_push_r (One_Particle_Collection *  pthis ,Field3D_Seq *  fieldE ,Field3D_Seq *  fieldB ,Field3D_Seq *  FoutJ ,double  Mass0_lst_fix ,double  Charge0_lst_fix ,double  Deltat ,int  N_l ,int  N_M ,int  push_J ,int  SPEC ,int  NUM_SPEC ){
	Field3D_Seq *  pfield = 	( pthis )->pfield ;
	Field3D_Seq *  pfieldE = 	( pthis )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( pthis )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( pthis )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( pthis )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( pthis )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( pthis )->pFoutEN ;
	void * *  sort_kernel = 	( pthis )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( pthis )->geo_rel_1st_kernel ;
	void * *  implicit_kernel = 	( pthis )->implicit_kernel ;
	void * *  rel_1st_kernel = 	( pthis )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( pthis )->krook_collision_test_kernel ;
	void * *  nonrel_test_kernel = 	( pthis )->nonrel_test_kernel ;
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
	void *  split_pass_x_nopush_kernel = 	( pthis )->split_pass_x_nopush_kernel ;
	void *  split_pass_y_nopush_kernel = 	( pthis )->split_pass_y_nopush_kernel ;
	void *  split_pass_z_nopush_kernel = 	( pthis )->split_pass_z_nopush_kernel ;
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
	void *  split_pass_x_vlo_nopush_kernel = 	( pthis )->split_pass_x_vlo_nopush_kernel ;
	void *  split_pass_y_vlo_nopush_kernel = 	( pthis )->split_pass_y_vlo_nopush_kernel ;
	void *  split_pass_z_vlo_nopush_kernel = 	( pthis )->split_pass_z_vlo_nopush_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( pthis )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( pthis )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( pthis )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_nopush_small_grids_kernel ;
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
	void * *  dmbihamt_kernels = 	( pfield )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pfield )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pfield )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( pfield )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( pfield )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pfield )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pfield )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( pfield )->yee_setfix_kernels ;
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
	void *  blas_mulxy_numele3_kernel = 	( pfield )->blas_mulxy_numele3_kernel ;
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
	double  DELTA_X = delta_x ;
	double  DELTA_Y = delta_y ;
	double  DELTA_Z = delta_z ;
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_fieldE ( (implicit_kernel)[1] , 	( fieldE )->main_data );
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_fieldB ( (implicit_kernel)[1] , 	( fieldB )->main_data );
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_FoutJ ( (implicit_kernel)[1] , 	( FoutJ )->main_data );
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_xyzw ( (implicit_kernel)[1] , xyzw );
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_cu_cache ( (implicit_kernel)[1] , cu_cache );
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_cu_xyzw ( (implicit_kernel)[1] , cu_xyzw );
{
	double  Mass0 = Mass0_lst_fix ;
	double  Charge0 = Charge0_lst_fix ;
	c_pscmc_mem  c_alloc_prefix_XLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XLEN ).h_data))[0] = XLEN);
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_XLEN ( (implicit_kernel)[1] , 	& ( c_alloc_prefix_XLEN ) );
	c_pscmc_mem  c_alloc_prefix_YLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_YLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_YLEN ).h_data))[0] = YLEN);
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_YLEN ( (implicit_kernel)[1] , 	& ( c_alloc_prefix_YLEN ) );
	c_pscmc_mem  c_alloc_prefix_ZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_ZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_ZLEN ).h_data))[0] = ZLEN);
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_ZLEN ( (implicit_kernel)[1] , 	& ( c_alloc_prefix_ZLEN ) );
	c_pscmc_mem  c_alloc_prefix_ovlp ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_ovlp ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_ovlp ).h_data))[0] = ovlp);
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_ovlp ( (implicit_kernel)[1] , 	& ( c_alloc_prefix_ovlp ) );
	c_pscmc_mem  c_alloc_prefix_numvec ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_numvec ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_numvec ).h_data))[0] = numvec);
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_numvec ( (implicit_kernel)[1] , 	& ( c_alloc_prefix_numvec ) );
	c_pscmc_mem  c_alloc_prefix_num_ele ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_num_ele ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_num_ele ).h_data))[0] = num_ele);
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_num_ele ( (implicit_kernel)[1] , 	& ( c_alloc_prefix_num_ele ) );
	c_pscmc_mem  c_alloc_prefix_grid_cache_len ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_grid_cache_len ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_grid_cache_len ).h_data))[0] = grid_cache_len);
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_grid_cache_len ( (implicit_kernel)[1] , 	& ( c_alloc_prefix_grid_cache_len ) );
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_cu_cache_length ( (implicit_kernel)[1] , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem  c_alloc_prefix_DELTA_X ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_DELTA_X ) , PS_DOUBLE_NUM , 0 );
((((double * )	( c_alloc_prefix_DELTA_X ).h_data))[0] = DELTA_X);
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_DELTA_X ( (implicit_kernel)[1] , 	& ( c_alloc_prefix_DELTA_X ) );
	c_pscmc_mem  c_alloc_prefix_DELTA_Y ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_DELTA_Y ) , PS_DOUBLE_NUM , 0 );
((((double * )	( c_alloc_prefix_DELTA_Y ).h_data))[0] = DELTA_Y);
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_DELTA_Y ( (implicit_kernel)[1] , 	& ( c_alloc_prefix_DELTA_Y ) );
	c_pscmc_mem  c_alloc_prefix_DELTA_Z ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_DELTA_Z ) , PS_DOUBLE_NUM , 0 );
((((double * )	( c_alloc_prefix_DELTA_Z ).h_data))[0] = DELTA_Z);
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_DELTA_Z ( (implicit_kernel)[1] , 	& ( c_alloc_prefix_DELTA_Z ) );
	c_pscmc_mem  c_alloc_prefix_Mass0 ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_Mass0 ) , PS_DOUBLE_NUM , 0 );
((((double * )	( c_alloc_prefix_Mass0 ).h_data))[0] = Mass0);
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_Mass0 ( (implicit_kernel)[1] , 	& ( c_alloc_prefix_Mass0 ) );
	c_pscmc_mem  c_alloc_prefix_Charge0 ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_Charge0 ) , PS_DOUBLE_NUM , 0 );
((((double * )	( c_alloc_prefix_Charge0 ).h_data))[0] = Charge0);
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_Charge0 ( (implicit_kernel)[1] , 	& ( c_alloc_prefix_Charge0 ) );
	c_pscmc_mem  c_alloc_prefix_Deltat ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_Deltat ) , PS_DOUBLE_NUM , 0 );
((((double * )	( c_alloc_prefix_Deltat ).h_data))[0] = Deltat);
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_Deltat ( (implicit_kernel)[1] , 	& ( c_alloc_prefix_Deltat ) );
	c_pscmc_mem  c_alloc_prefix_N_l ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_N_l ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_N_l ).h_data))[0] = N_l);
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_N_l ( (implicit_kernel)[1] , 	& ( c_alloc_prefix_N_l ) );
	c_pscmc_mem  c_alloc_prefix_N_M ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_N_M ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_N_M ).h_data))[0] = N_M);
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_N_M ( (implicit_kernel)[1] , 	& ( c_alloc_prefix_N_M ) );
	c_pscmc_mem  c_alloc_prefix_push_J ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_push_J ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_push_J ).h_data))[0] = push_J);
	c_split_pass_xyzE_particle_push_r_scmc_set_parameter_push_J ( (implicit_kernel)[1] , 	& ( c_alloc_prefix_push_J ) );
	c_split_pass_xyzE_particle_push_r_exec ( (implicit_kernel)[1] , 	c_split_pass_xyzE_particle_push_r_get_xlen (  ) , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_YLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_ZLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_ovlp ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_numvec ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_num_ele ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_grid_cache_len ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_DELTA_X ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_DELTA_Y ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_DELTA_Z ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_Mass0 ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_Charge0 ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_Deltat ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_N_l ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_N_M ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_push_J ) );
}	return  0 ;}
int  c_One_Particle_Collection_split_pass_xyzE_particle (One_Particle_Collection *  pthis ,Field3D_Seq *  fieldE ,Field3D_Seq *  fieldB ,Field3D_Seq *  FoutJ ,double  Mass0_lst_fix ,double  Charge0_lst_fix ,double  Deltat ,int  N_l ,int  N_M ,int  push_J ,int  SPEC ,int  NUM_SPEC ){
	Field3D_Seq *  pfield = 	( pthis )->pfield ;
	Field3D_Seq *  pfieldE = 	( pthis )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( pthis )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( pthis )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( pthis )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( pthis )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( pthis )->pFoutEN ;
	void * *  sort_kernel = 	( pthis )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( pthis )->geo_rel_1st_kernel ;
	void * *  implicit_kernel = 	( pthis )->implicit_kernel ;
	void * *  rel_1st_kernel = 	( pthis )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( pthis )->krook_collision_test_kernel ;
	void * *  nonrel_test_kernel = 	( pthis )->nonrel_test_kernel ;
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
	void *  split_pass_x_nopush_kernel = 	( pthis )->split_pass_x_nopush_kernel ;
	void *  split_pass_y_nopush_kernel = 	( pthis )->split_pass_y_nopush_kernel ;
	void *  split_pass_z_nopush_kernel = 	( pthis )->split_pass_z_nopush_kernel ;
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
	void *  split_pass_x_vlo_nopush_kernel = 	( pthis )->split_pass_x_vlo_nopush_kernel ;
	void *  split_pass_y_vlo_nopush_kernel = 	( pthis )->split_pass_y_vlo_nopush_kernel ;
	void *  split_pass_z_vlo_nopush_kernel = 	( pthis )->split_pass_z_vlo_nopush_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( pthis )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( pthis )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( pthis )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_nopush_small_grids_kernel ;
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
	void * *  dmbihamt_kernels = 	( pfield )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pfield )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pfield )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( pfield )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( pfield )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pfield )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pfield )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( pfield )->yee_setfix_kernels ;
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
	void *  blas_mulxy_numele3_kernel = 	( pfield )->blas_mulxy_numele3_kernel ;
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
	double  DELTA_X = delta_x ;
	double  DELTA_Y = delta_y ;
	double  DELTA_Z = delta_z ;
	c_split_pass_xyzE_particle_scmc_set_parameter_fieldE ( (implicit_kernel)[0] , 	( fieldE )->main_data );
	c_split_pass_xyzE_particle_scmc_set_parameter_fieldB ( (implicit_kernel)[0] , 	( fieldB )->main_data );
	c_split_pass_xyzE_particle_scmc_set_parameter_FoutJ ( (implicit_kernel)[0] , 	( FoutJ )->main_data );
	c_split_pass_xyzE_particle_scmc_set_parameter_xyzw ( (implicit_kernel)[0] , xyzw );
	c_split_pass_xyzE_particle_scmc_set_parameter_cu_cache ( (implicit_kernel)[0] , cu_cache );
	c_split_pass_xyzE_particle_scmc_set_parameter_cu_xyzw ( (implicit_kernel)[0] , cu_xyzw );
{
	double  Mass0 = Mass0_lst_fix ;
	double  Charge0 = Charge0_lst_fix ;
	c_pscmc_mem  c_alloc_prefix_XLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_XLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_XLEN ).h_data))[0] = XLEN);
	c_split_pass_xyzE_particle_scmc_set_parameter_XLEN ( (implicit_kernel)[0] , 	& ( c_alloc_prefix_XLEN ) );
	c_pscmc_mem  c_alloc_prefix_YLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_YLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_YLEN ).h_data))[0] = YLEN);
	c_split_pass_xyzE_particle_scmc_set_parameter_YLEN ( (implicit_kernel)[0] , 	& ( c_alloc_prefix_YLEN ) );
	c_pscmc_mem  c_alloc_prefix_ZLEN ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_ZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_ZLEN ).h_data))[0] = ZLEN);
	c_split_pass_xyzE_particle_scmc_set_parameter_ZLEN ( (implicit_kernel)[0] , 	& ( c_alloc_prefix_ZLEN ) );
	c_pscmc_mem  c_alloc_prefix_ovlp ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_ovlp ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_ovlp ).h_data))[0] = ovlp);
	c_split_pass_xyzE_particle_scmc_set_parameter_ovlp ( (implicit_kernel)[0] , 	& ( c_alloc_prefix_ovlp ) );
	c_pscmc_mem  c_alloc_prefix_numvec ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_numvec ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_numvec ).h_data))[0] = numvec);
	c_split_pass_xyzE_particle_scmc_set_parameter_numvec ( (implicit_kernel)[0] , 	& ( c_alloc_prefix_numvec ) );
	c_pscmc_mem  c_alloc_prefix_num_ele ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_num_ele ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_num_ele ).h_data))[0] = num_ele);
	c_split_pass_xyzE_particle_scmc_set_parameter_num_ele ( (implicit_kernel)[0] , 	& ( c_alloc_prefix_num_ele ) );
	c_pscmc_mem  c_alloc_prefix_grid_cache_len ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_grid_cache_len ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_grid_cache_len ).h_data))[0] = grid_cache_len);
	c_split_pass_xyzE_particle_scmc_set_parameter_grid_cache_len ( (implicit_kernel)[0] , 	& ( c_alloc_prefix_grid_cache_len ) );
	c_pscmc_mem  c_alloc_prefix_cu_cache_length ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( c_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	c_split_pass_xyzE_particle_scmc_set_parameter_cu_cache_length ( (implicit_kernel)[0] , 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem  c_alloc_prefix_DELTA_X ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_DELTA_X ) , PS_DOUBLE_NUM , 0 );
((((double * )	( c_alloc_prefix_DELTA_X ).h_data))[0] = DELTA_X);
	c_split_pass_xyzE_particle_scmc_set_parameter_DELTA_X ( (implicit_kernel)[0] , 	& ( c_alloc_prefix_DELTA_X ) );
	c_pscmc_mem  c_alloc_prefix_DELTA_Y ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_DELTA_Y ) , PS_DOUBLE_NUM , 0 );
((((double * )	( c_alloc_prefix_DELTA_Y ).h_data))[0] = DELTA_Y);
	c_split_pass_xyzE_particle_scmc_set_parameter_DELTA_Y ( (implicit_kernel)[0] , 	& ( c_alloc_prefix_DELTA_Y ) );
	c_pscmc_mem  c_alloc_prefix_DELTA_Z ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_DELTA_Z ) , PS_DOUBLE_NUM , 0 );
((((double * )	( c_alloc_prefix_DELTA_Z ).h_data))[0] = DELTA_Z);
	c_split_pass_xyzE_particle_scmc_set_parameter_DELTA_Z ( (implicit_kernel)[0] , 	& ( c_alloc_prefix_DELTA_Z ) );
	c_pscmc_mem  c_alloc_prefix_Mass0 ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_Mass0 ) , PS_DOUBLE_NUM , 0 );
((((double * )	( c_alloc_prefix_Mass0 ).h_data))[0] = Mass0);
	c_split_pass_xyzE_particle_scmc_set_parameter_Mass0 ( (implicit_kernel)[0] , 	& ( c_alloc_prefix_Mass0 ) );
	c_pscmc_mem  c_alloc_prefix_Charge0 ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_Charge0 ) , PS_DOUBLE_NUM , 0 );
((((double * )	( c_alloc_prefix_Charge0 ).h_data))[0] = Charge0);
	c_split_pass_xyzE_particle_scmc_set_parameter_Charge0 ( (implicit_kernel)[0] , 	& ( c_alloc_prefix_Charge0 ) );
	c_pscmc_mem  c_alloc_prefix_Deltat ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_Deltat ) , PS_DOUBLE_NUM , 0 );
((((double * )	( c_alloc_prefix_Deltat ).h_data))[0] = Deltat);
	c_split_pass_xyzE_particle_scmc_set_parameter_Deltat ( (implicit_kernel)[0] , 	& ( c_alloc_prefix_Deltat ) );
	c_pscmc_mem  c_alloc_prefix_N_l ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_N_l ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_N_l ).h_data))[0] = N_l);
	c_split_pass_xyzE_particle_scmc_set_parameter_N_l ( (implicit_kernel)[0] , 	& ( c_alloc_prefix_N_l ) );
	c_pscmc_mem  c_alloc_prefix_N_M ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_N_M ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_N_M ).h_data))[0] = N_M);
	c_split_pass_xyzE_particle_scmc_set_parameter_N_M ( (implicit_kernel)[0] , 	& ( c_alloc_prefix_N_M ) );
	c_pscmc_mem  c_alloc_prefix_push_J ;
	c_pscmc_mem_init ( pe , 	& ( c_alloc_prefix_push_J ) , PS_INT_NUM , 0 );
((((int * )	( c_alloc_prefix_push_J ).h_data))[0] = push_J);
	c_split_pass_xyzE_particle_scmc_set_parameter_push_J ( (implicit_kernel)[0] , 	& ( c_alloc_prefix_push_J ) );
	c_split_pass_xyzE_particle_exec ( (implicit_kernel)[0] , 	c_split_pass_xyzE_particle_get_xlen (  ) , numvec );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_XLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_YLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_ZLEN ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_ovlp ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_numvec ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_num_ele ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_grid_cache_len ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_cu_cache_length ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_DELTA_X ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_DELTA_Y ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_DELTA_Z ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_Mass0 ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_Charge0 ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_Deltat ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_N_l ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_N_M ) );
	c_pscmc_mem_destroy ( 	& ( c_alloc_prefix_push_J ) );
}	return  0 ;}
int  openmp_One_Particle_Collection_split_pass_xyzE_particle_push_r (One_Particle_Collection *  pthis ,Field3D_Seq *  fieldE ,Field3D_Seq *  fieldB ,Field3D_Seq *  FoutJ ,double  Mass0_lst_fix ,double  Charge0_lst_fix ,double  Deltat ,int  N_l ,int  N_M ,int  push_J ,int  SPEC ,int  NUM_SPEC ){
	Field3D_Seq *  pfield = 	( pthis )->pfield ;
	Field3D_Seq *  pfieldE = 	( pthis )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( pthis )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( pthis )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( pthis )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( pthis )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( pthis )->pFoutEN ;
	void * *  sort_kernel = 	( pthis )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( pthis )->geo_rel_1st_kernel ;
	void * *  implicit_kernel = 	( pthis )->implicit_kernel ;
	void * *  rel_1st_kernel = 	( pthis )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( pthis )->krook_collision_test_kernel ;
	void * *  nonrel_test_kernel = 	( pthis )->nonrel_test_kernel ;
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
	void *  split_pass_x_nopush_kernel = 	( pthis )->split_pass_x_nopush_kernel ;
	void *  split_pass_y_nopush_kernel = 	( pthis )->split_pass_y_nopush_kernel ;
	void *  split_pass_z_nopush_kernel = 	( pthis )->split_pass_z_nopush_kernel ;
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
	void *  split_pass_x_vlo_nopush_kernel = 	( pthis )->split_pass_x_vlo_nopush_kernel ;
	void *  split_pass_y_vlo_nopush_kernel = 	( pthis )->split_pass_y_vlo_nopush_kernel ;
	void *  split_pass_z_vlo_nopush_kernel = 	( pthis )->split_pass_z_vlo_nopush_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( pthis )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( pthis )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( pthis )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_nopush_small_grids_kernel ;
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
	void * *  dmbihamt_kernels = 	( pfield )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pfield )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pfield )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( pfield )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( pfield )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pfield )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pfield )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( pfield )->yee_setfix_kernels ;
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
	void *  blas_mulxy_numele3_kernel = 	( pfield )->blas_mulxy_numele3_kernel ;
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
	double  DELTA_X = delta_x ;
	double  DELTA_Y = delta_y ;
	double  DELTA_Z = delta_z ;
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_fieldE ( (implicit_kernel)[1] , 	( fieldE )->main_data );
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_fieldB ( (implicit_kernel)[1] , 	( fieldB )->main_data );
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_FoutJ ( (implicit_kernel)[1] , 	( FoutJ )->main_data );
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_xyzw ( (implicit_kernel)[1] , xyzw );
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_cu_cache ( (implicit_kernel)[1] , cu_cache );
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_cu_xyzw ( (implicit_kernel)[1] , cu_xyzw );
{
	double  Mass0 = Mass0_lst_fix ;
	double  Charge0 = Charge0_lst_fix ;
	openmp_pscmc_mem  openmp_alloc_prefix_XLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XLEN ).h_data))[0] = XLEN);
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_XLEN ( (implicit_kernel)[1] , 	& ( openmp_alloc_prefix_XLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_YLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_YLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_YLEN ).h_data))[0] = YLEN);
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_YLEN ( (implicit_kernel)[1] , 	& ( openmp_alloc_prefix_YLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_ZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_ZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_ZLEN ).h_data))[0] = ZLEN);
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_ZLEN ( (implicit_kernel)[1] , 	& ( openmp_alloc_prefix_ZLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_ovlp ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_ovlp ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_ovlp ).h_data))[0] = ovlp);
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_ovlp ( (implicit_kernel)[1] , 	& ( openmp_alloc_prefix_ovlp ) );
	openmp_pscmc_mem  openmp_alloc_prefix_numvec ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_numvec ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_numvec ).h_data))[0] = numvec);
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_numvec ( (implicit_kernel)[1] , 	& ( openmp_alloc_prefix_numvec ) );
	openmp_pscmc_mem  openmp_alloc_prefix_num_ele ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_num_ele ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_num_ele ).h_data))[0] = num_ele);
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_num_ele ( (implicit_kernel)[1] , 	& ( openmp_alloc_prefix_num_ele ) );
	openmp_pscmc_mem  openmp_alloc_prefix_grid_cache_len ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_grid_cache_len ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_grid_cache_len ).h_data))[0] = grid_cache_len);
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_grid_cache_len ( (implicit_kernel)[1] , 	& ( openmp_alloc_prefix_grid_cache_len ) );
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_cu_cache_length ( (implicit_kernel)[1] , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem  openmp_alloc_prefix_DELTA_X ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_DELTA_X ) , PS_DOUBLE_NUM , 0 );
((((double * )	( openmp_alloc_prefix_DELTA_X ).h_data))[0] = DELTA_X);
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_DELTA_X ( (implicit_kernel)[1] , 	& ( openmp_alloc_prefix_DELTA_X ) );
	openmp_pscmc_mem  openmp_alloc_prefix_DELTA_Y ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_DELTA_Y ) , PS_DOUBLE_NUM , 0 );
((((double * )	( openmp_alloc_prefix_DELTA_Y ).h_data))[0] = DELTA_Y);
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_DELTA_Y ( (implicit_kernel)[1] , 	& ( openmp_alloc_prefix_DELTA_Y ) );
	openmp_pscmc_mem  openmp_alloc_prefix_DELTA_Z ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_DELTA_Z ) , PS_DOUBLE_NUM , 0 );
((((double * )	( openmp_alloc_prefix_DELTA_Z ).h_data))[0] = DELTA_Z);
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_DELTA_Z ( (implicit_kernel)[1] , 	& ( openmp_alloc_prefix_DELTA_Z ) );
	openmp_pscmc_mem  openmp_alloc_prefix_Mass0 ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_Mass0 ) , PS_DOUBLE_NUM , 0 );
((((double * )	( openmp_alloc_prefix_Mass0 ).h_data))[0] = Mass0);
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_Mass0 ( (implicit_kernel)[1] , 	& ( openmp_alloc_prefix_Mass0 ) );
	openmp_pscmc_mem  openmp_alloc_prefix_Charge0 ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_Charge0 ) , PS_DOUBLE_NUM , 0 );
((((double * )	( openmp_alloc_prefix_Charge0 ).h_data))[0] = Charge0);
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_Charge0 ( (implicit_kernel)[1] , 	& ( openmp_alloc_prefix_Charge0 ) );
	openmp_pscmc_mem  openmp_alloc_prefix_Deltat ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_Deltat ) , PS_DOUBLE_NUM , 0 );
((((double * )	( openmp_alloc_prefix_Deltat ).h_data))[0] = Deltat);
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_Deltat ( (implicit_kernel)[1] , 	& ( openmp_alloc_prefix_Deltat ) );
	openmp_pscmc_mem  openmp_alloc_prefix_N_l ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_N_l ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_N_l ).h_data))[0] = N_l);
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_N_l ( (implicit_kernel)[1] , 	& ( openmp_alloc_prefix_N_l ) );
	openmp_pscmc_mem  openmp_alloc_prefix_N_M ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_N_M ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_N_M ).h_data))[0] = N_M);
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_N_M ( (implicit_kernel)[1] , 	& ( openmp_alloc_prefix_N_M ) );
	openmp_pscmc_mem  openmp_alloc_prefix_push_J ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_push_J ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_push_J ).h_data))[0] = push_J);
	openmp_split_pass_xyzE_particle_push_r_scmc_set_parameter_push_J ( (implicit_kernel)[1] , 	& ( openmp_alloc_prefix_push_J ) );
	openmp_split_pass_xyzE_particle_push_r_exec ( (implicit_kernel)[1] , 	openmp_split_pass_xyzE_particle_push_r_get_xlen (  ) , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_YLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_ZLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_ovlp ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_numvec ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_num_ele ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_grid_cache_len ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_DELTA_X ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_DELTA_Y ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_DELTA_Z ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_Mass0 ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_Charge0 ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_Deltat ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_N_l ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_N_M ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_push_J ) );
}	return  0 ;}
int  openmp_One_Particle_Collection_split_pass_xyzE_particle (One_Particle_Collection *  pthis ,Field3D_Seq *  fieldE ,Field3D_Seq *  fieldB ,Field3D_Seq *  FoutJ ,double  Mass0_lst_fix ,double  Charge0_lst_fix ,double  Deltat ,int  N_l ,int  N_M ,int  push_J ,int  SPEC ,int  NUM_SPEC ){
	Field3D_Seq *  pfield = 	( pthis )->pfield ;
	Field3D_Seq *  pfieldE = 	( pthis )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( pthis )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( pthis )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( pthis )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( pthis )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( pthis )->pFoutEN ;
	void * *  sort_kernel = 	( pthis )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( pthis )->geo_rel_1st_kernel ;
	void * *  implicit_kernel = 	( pthis )->implicit_kernel ;
	void * *  rel_1st_kernel = 	( pthis )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( pthis )->krook_collision_test_kernel ;
	void * *  nonrel_test_kernel = 	( pthis )->nonrel_test_kernel ;
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
	void *  split_pass_x_nopush_kernel = 	( pthis )->split_pass_x_nopush_kernel ;
	void *  split_pass_y_nopush_kernel = 	( pthis )->split_pass_y_nopush_kernel ;
	void *  split_pass_z_nopush_kernel = 	( pthis )->split_pass_z_nopush_kernel ;
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
	void *  split_pass_x_vlo_nopush_kernel = 	( pthis )->split_pass_x_vlo_nopush_kernel ;
	void *  split_pass_y_vlo_nopush_kernel = 	( pthis )->split_pass_y_vlo_nopush_kernel ;
	void *  split_pass_z_vlo_nopush_kernel = 	( pthis )->split_pass_z_vlo_nopush_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( pthis )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( pthis )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( pthis )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_nopush_small_grids_kernel ;
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
	void * *  dmbihamt_kernels = 	( pfield )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pfield )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pfield )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( pfield )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( pfield )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pfield )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pfield )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( pfield )->yee_setfix_kernels ;
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
	void *  blas_mulxy_numele3_kernel = 	( pfield )->blas_mulxy_numele3_kernel ;
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
	double  DELTA_X = delta_x ;
	double  DELTA_Y = delta_y ;
	double  DELTA_Z = delta_z ;
	openmp_split_pass_xyzE_particle_scmc_set_parameter_fieldE ( (implicit_kernel)[0] , 	( fieldE )->main_data );
	openmp_split_pass_xyzE_particle_scmc_set_parameter_fieldB ( (implicit_kernel)[0] , 	( fieldB )->main_data );
	openmp_split_pass_xyzE_particle_scmc_set_parameter_FoutJ ( (implicit_kernel)[0] , 	( FoutJ )->main_data );
	openmp_split_pass_xyzE_particle_scmc_set_parameter_xyzw ( (implicit_kernel)[0] , xyzw );
	openmp_split_pass_xyzE_particle_scmc_set_parameter_cu_cache ( (implicit_kernel)[0] , cu_cache );
	openmp_split_pass_xyzE_particle_scmc_set_parameter_cu_xyzw ( (implicit_kernel)[0] , cu_xyzw );
{
	double  Mass0 = Mass0_lst_fix ;
	double  Charge0 = Charge0_lst_fix ;
	openmp_pscmc_mem  openmp_alloc_prefix_XLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_XLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_XLEN ).h_data))[0] = XLEN);
	openmp_split_pass_xyzE_particle_scmc_set_parameter_XLEN ( (implicit_kernel)[0] , 	& ( openmp_alloc_prefix_XLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_YLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_YLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_YLEN ).h_data))[0] = YLEN);
	openmp_split_pass_xyzE_particle_scmc_set_parameter_YLEN ( (implicit_kernel)[0] , 	& ( openmp_alloc_prefix_YLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_ZLEN ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_ZLEN ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_ZLEN ).h_data))[0] = ZLEN);
	openmp_split_pass_xyzE_particle_scmc_set_parameter_ZLEN ( (implicit_kernel)[0] , 	& ( openmp_alloc_prefix_ZLEN ) );
	openmp_pscmc_mem  openmp_alloc_prefix_ovlp ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_ovlp ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_ovlp ).h_data))[0] = ovlp);
	openmp_split_pass_xyzE_particle_scmc_set_parameter_ovlp ( (implicit_kernel)[0] , 	& ( openmp_alloc_prefix_ovlp ) );
	openmp_pscmc_mem  openmp_alloc_prefix_numvec ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_numvec ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_numvec ).h_data))[0] = numvec);
	openmp_split_pass_xyzE_particle_scmc_set_parameter_numvec ( (implicit_kernel)[0] , 	& ( openmp_alloc_prefix_numvec ) );
	openmp_pscmc_mem  openmp_alloc_prefix_num_ele ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_num_ele ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_num_ele ).h_data))[0] = num_ele);
	openmp_split_pass_xyzE_particle_scmc_set_parameter_num_ele ( (implicit_kernel)[0] , 	& ( openmp_alloc_prefix_num_ele ) );
	openmp_pscmc_mem  openmp_alloc_prefix_grid_cache_len ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_grid_cache_len ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_grid_cache_len ).h_data))[0] = grid_cache_len);
	openmp_split_pass_xyzE_particle_scmc_set_parameter_grid_cache_len ( (implicit_kernel)[0] , 	& ( openmp_alloc_prefix_grid_cache_len ) );
	openmp_pscmc_mem  openmp_alloc_prefix_cu_cache_length ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_cu_cache_length ) , PS_LONG_NUM , 0 );
((((long * )	( openmp_alloc_prefix_cu_cache_length ).h_data))[0] = cu_cache_length);
	openmp_split_pass_xyzE_particle_scmc_set_parameter_cu_cache_length ( (implicit_kernel)[0] , 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem  openmp_alloc_prefix_DELTA_X ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_DELTA_X ) , PS_DOUBLE_NUM , 0 );
((((double * )	( openmp_alloc_prefix_DELTA_X ).h_data))[0] = DELTA_X);
	openmp_split_pass_xyzE_particle_scmc_set_parameter_DELTA_X ( (implicit_kernel)[0] , 	& ( openmp_alloc_prefix_DELTA_X ) );
	openmp_pscmc_mem  openmp_alloc_prefix_DELTA_Y ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_DELTA_Y ) , PS_DOUBLE_NUM , 0 );
((((double * )	( openmp_alloc_prefix_DELTA_Y ).h_data))[0] = DELTA_Y);
	openmp_split_pass_xyzE_particle_scmc_set_parameter_DELTA_Y ( (implicit_kernel)[0] , 	& ( openmp_alloc_prefix_DELTA_Y ) );
	openmp_pscmc_mem  openmp_alloc_prefix_DELTA_Z ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_DELTA_Z ) , PS_DOUBLE_NUM , 0 );
((((double * )	( openmp_alloc_prefix_DELTA_Z ).h_data))[0] = DELTA_Z);
	openmp_split_pass_xyzE_particle_scmc_set_parameter_DELTA_Z ( (implicit_kernel)[0] , 	& ( openmp_alloc_prefix_DELTA_Z ) );
	openmp_pscmc_mem  openmp_alloc_prefix_Mass0 ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_Mass0 ) , PS_DOUBLE_NUM , 0 );
((((double * )	( openmp_alloc_prefix_Mass0 ).h_data))[0] = Mass0);
	openmp_split_pass_xyzE_particle_scmc_set_parameter_Mass0 ( (implicit_kernel)[0] , 	& ( openmp_alloc_prefix_Mass0 ) );
	openmp_pscmc_mem  openmp_alloc_prefix_Charge0 ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_Charge0 ) , PS_DOUBLE_NUM , 0 );
((((double * )	( openmp_alloc_prefix_Charge0 ).h_data))[0] = Charge0);
	openmp_split_pass_xyzE_particle_scmc_set_parameter_Charge0 ( (implicit_kernel)[0] , 	& ( openmp_alloc_prefix_Charge0 ) );
	openmp_pscmc_mem  openmp_alloc_prefix_Deltat ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_Deltat ) , PS_DOUBLE_NUM , 0 );
((((double * )	( openmp_alloc_prefix_Deltat ).h_data))[0] = Deltat);
	openmp_split_pass_xyzE_particle_scmc_set_parameter_Deltat ( (implicit_kernel)[0] , 	& ( openmp_alloc_prefix_Deltat ) );
	openmp_pscmc_mem  openmp_alloc_prefix_N_l ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_N_l ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_N_l ).h_data))[0] = N_l);
	openmp_split_pass_xyzE_particle_scmc_set_parameter_N_l ( (implicit_kernel)[0] , 	& ( openmp_alloc_prefix_N_l ) );
	openmp_pscmc_mem  openmp_alloc_prefix_N_M ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_N_M ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_N_M ).h_data))[0] = N_M);
	openmp_split_pass_xyzE_particle_scmc_set_parameter_N_M ( (implicit_kernel)[0] , 	& ( openmp_alloc_prefix_N_M ) );
	openmp_pscmc_mem  openmp_alloc_prefix_push_J ;
	openmp_pscmc_mem_init ( pe , 	& ( openmp_alloc_prefix_push_J ) , PS_INT_NUM , 0 );
((((int * )	( openmp_alloc_prefix_push_J ).h_data))[0] = push_J);
	openmp_split_pass_xyzE_particle_scmc_set_parameter_push_J ( (implicit_kernel)[0] , 	& ( openmp_alloc_prefix_push_J ) );
	openmp_split_pass_xyzE_particle_exec ( (implicit_kernel)[0] , 	openmp_split_pass_xyzE_particle_get_xlen (  ) , numvec );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_XLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_YLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_ZLEN ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_ovlp ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_numvec ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_num_ele ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_grid_cache_len ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_cu_cache_length ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_DELTA_X ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_DELTA_Y ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_DELTA_Z ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_Mass0 ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_Charge0 ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_Deltat ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_N_l ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_N_M ) );
	openmp_pscmc_mem_destroy ( 	& ( openmp_alloc_prefix_push_J ) );
}	return  0 ;}
int  One_Particle_Collection_split_pass_xyzE_particle_push_r (One_Particle_Collection *  pthis ,Field3D_Seq *  fieldE ,Field3D_Seq *  fieldB ,Field3D_Seq *  FoutJ ,double  Mass0_lst_fix ,double  Charge0_lst_fix ,double  Deltat ,int  N_l ,int  N_M ,int  push_J ,int  spec ,int  num_spec ){
	Field3D_Seq *  pfield = 	( pthis )->pfield ;
	Field3D_Seq *  pfieldE = 	( pthis )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( pthis )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( pthis )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( pthis )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( pthis )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( pthis )->pFoutEN ;
	void * *  sort_kernel = 	( pthis )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( pthis )->geo_rel_1st_kernel ;
	void * *  implicit_kernel = 	( pthis )->implicit_kernel ;
	void * *  rel_1st_kernel = 	( pthis )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( pthis )->krook_collision_test_kernel ;
	void * *  nonrel_test_kernel = 	( pthis )->nonrel_test_kernel ;
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
	void *  split_pass_x_nopush_kernel = 	( pthis )->split_pass_x_nopush_kernel ;
	void *  split_pass_y_nopush_kernel = 	( pthis )->split_pass_y_nopush_kernel ;
	void *  split_pass_z_nopush_kernel = 	( pthis )->split_pass_z_nopush_kernel ;
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
	void *  split_pass_x_vlo_nopush_kernel = 	( pthis )->split_pass_x_vlo_nopush_kernel ;
	void *  split_pass_y_vlo_nopush_kernel = 	( pthis )->split_pass_y_vlo_nopush_kernel ;
	void *  split_pass_z_vlo_nopush_kernel = 	( pthis )->split_pass_z_vlo_nopush_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( pthis )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( pthis )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( pthis )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_nopush_small_grids_kernel ;
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
	void * *  dmbihamt_kernels = 	( pfield )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pfield )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pfield )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( pfield )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( pfield )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pfield )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pfield )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( pfield )->yee_setfix_kernels ;
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
	void *  blas_mulxy_numele3_kernel = 	( pfield )->blas_mulxy_numele3_kernel ;
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
			c_One_Particle_Collection_split_pass_xyzE_particle_push_r ( pthis , fieldE , fieldB , FoutJ , Mass0_lst_fix , Charge0_lst_fix , Deltat , N_l , N_M , push_J , spec , num_spec );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_One_Particle_Collection_split_pass_xyzE_particle_push_r ( pthis , fieldE , fieldB , FoutJ , Mass0_lst_fix , Charge0_lst_fix , Deltat , N_l , N_M , push_J , spec , num_spec );

	}else{
		0;

	 }

	 }
	return  0 ;}
int  MPI_split_pass_xyzE_particle_push_r (Particle_in_Cell_MPI *  pthis ,Field3D_MPI *  fieldE ,Field3D_MPI *  fieldB ,Field3D_MPI *  FoutJ ,double *  Mass0 ,double *  Charge0 ,double  Deltat ,int  N_l ,int  N_M ,int  push_J ){
	Field3D_MPI  MPI_fieldE = 	( pthis )->MPI_fieldE ;
	Field3D_MPI  MPI_fieldB = 	( pthis )->MPI_fieldB ;
	Field3D_MPI  MPI_fieldB1 = 	( pthis )->MPI_fieldB1 ;
	Field3D_MPI  MPI_FoutJ = 	( pthis )->MPI_FoutJ ;
	Field3D_MPI  MPI_LFoutJ = 	( pthis )->MPI_LFoutJ ;
	Field3D_MPI  MPI_fieldEtmp = 	( pthis )->MPI_fieldEtmp ;
	Field3D_MPI  MPI_fieldEtmp1 = 	( pthis )->MPI_fieldEtmp1 ;
	Field3D_MPI  MPI_fieldEtmp2 = 	( pthis )->MPI_fieldEtmp2 ;
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
	int  o_N_l = 	( pthis )->o_N_l ;
	int  o_N_M = 	( pthis )->o_N_M ;
	double *  o_pmass = 	( pthis )->o_pmass ;
	double *  o_pcharge = 	( pthis )->o_pcharge ;
	int *  o_particle_type = 	( pthis )->o_particle_type ;
	long  i = 0 ;
	int  num_spec = 	( MPI_fieldE ).num_spec ;
	int  num_runtime = 	( MPI_fieldE ).num_runtime ;
	for (i=0 ; 	(  i < 	(  num_runtime * num_spec ) ) ; i++)
	{
	int  cur_spec = 	(  i / num_runtime ) ;
	if (  	(  (o_particle_type)[cur_spec] == 1 )  ){  
			One_Particle_Collection_split_pass_xyzE_particle_push_r ( 	(  	( MPI_fieldE ).particles + i ) , 	(  	( fieldE )->data + 	(  i % num_runtime ) ) , 	(  	( fieldB )->data + 	(  i % num_runtime ) ) , 	(  	( FoutJ )->data + 	(  i % num_runtime ) ) , (Mass0)[	(  i / num_runtime )] , (Charge0)[	(  i / num_runtime )] , Deltat , N_l , N_M , push_J , cur_spec , num_spec );

	}else{
		0;

	 }
}	return  0 ;}
int  One_Particle_Collection_split_pass_xyzE_particle (One_Particle_Collection *  pthis ,Field3D_Seq *  fieldE ,Field3D_Seq *  fieldB ,Field3D_Seq *  FoutJ ,double  Mass0_lst_fix ,double  Charge0_lst_fix ,double  Deltat ,int  N_l ,int  N_M ,int  push_J ,int  spec ,int  num_spec ){
	Field3D_Seq *  pfield = 	( pthis )->pfield ;
	Field3D_Seq *  pfieldE = 	( pthis )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( pthis )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( pthis )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( pthis )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( pthis )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( pthis )->pFoutEN ;
	void * *  sort_kernel = 	( pthis )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( pthis )->geo_rel_1st_kernel ;
	void * *  implicit_kernel = 	( pthis )->implicit_kernel ;
	void * *  rel_1st_kernel = 	( pthis )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( pthis )->krook_collision_test_kernel ;
	void * *  nonrel_test_kernel = 	( pthis )->nonrel_test_kernel ;
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
	void *  split_pass_x_nopush_kernel = 	( pthis )->split_pass_x_nopush_kernel ;
	void *  split_pass_y_nopush_kernel = 	( pthis )->split_pass_y_nopush_kernel ;
	void *  split_pass_z_nopush_kernel = 	( pthis )->split_pass_z_nopush_kernel ;
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
	void *  split_pass_x_vlo_nopush_kernel = 	( pthis )->split_pass_x_vlo_nopush_kernel ;
	void *  split_pass_y_vlo_nopush_kernel = 	( pthis )->split_pass_y_vlo_nopush_kernel ;
	void *  split_pass_z_vlo_nopush_kernel = 	( pthis )->split_pass_z_vlo_nopush_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( pthis )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( pthis )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( pthis )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_x_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_y_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_nopush_small_grids_kernel = 	( pthis )->split_pass_z_vlo_sg2_nopush_small_grids_kernel ;
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
	void * *  dmbihamt_kernels = 	( pfield )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pfield )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pfield )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( pfield )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( pfield )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pfield )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pfield )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( pfield )->yee_setfix_kernels ;
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
	void *  blas_mulxy_numele3_kernel = 	( pfield )->blas_mulxy_numele3_kernel ;
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
			c_One_Particle_Collection_split_pass_xyzE_particle ( pthis , fieldE , fieldB , FoutJ , Mass0_lst_fix , Charge0_lst_fix , Deltat , N_l , N_M , push_J , spec , num_spec );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_One_Particle_Collection_split_pass_xyzE_particle ( pthis , fieldE , fieldB , FoutJ , Mass0_lst_fix , Charge0_lst_fix , Deltat , N_l , N_M , push_J , spec , num_spec );

	}else{
		0;

	 }

	 }
	return  0 ;}
int  MPI_split_pass_xyzE_particle (Particle_in_Cell_MPI *  pthis ,Field3D_MPI *  fieldE ,Field3D_MPI *  fieldB ,Field3D_MPI *  FoutJ ,double *  Mass0 ,double *  Charge0 ,double  Deltat ,int  N_l ,int  N_M ,int  push_J ){
	Field3D_MPI  MPI_fieldE = 	( pthis )->MPI_fieldE ;
	Field3D_MPI  MPI_fieldB = 	( pthis )->MPI_fieldB ;
	Field3D_MPI  MPI_fieldB1 = 	( pthis )->MPI_fieldB1 ;
	Field3D_MPI  MPI_FoutJ = 	( pthis )->MPI_FoutJ ;
	Field3D_MPI  MPI_LFoutJ = 	( pthis )->MPI_LFoutJ ;
	Field3D_MPI  MPI_fieldEtmp = 	( pthis )->MPI_fieldEtmp ;
	Field3D_MPI  MPI_fieldEtmp1 = 	( pthis )->MPI_fieldEtmp1 ;
	Field3D_MPI  MPI_fieldEtmp2 = 	( pthis )->MPI_fieldEtmp2 ;
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
	int  o_N_l = 	( pthis )->o_N_l ;
	int  o_N_M = 	( pthis )->o_N_M ;
	double *  o_pmass = 	( pthis )->o_pmass ;
	double *  o_pcharge = 	( pthis )->o_pcharge ;
	int *  o_particle_type = 	( pthis )->o_particle_type ;
	long  i = 0 ;
	int  num_spec = 	( MPI_fieldE ).num_spec ;
	int  num_runtime = 	( MPI_fieldE ).num_runtime ;
	for (i=0 ; 	(  i < 	(  num_runtime * num_spec ) ) ; i++)
	{
	int  cur_spec = 	(  i / num_runtime ) ;
	if (  	(  (o_particle_type)[cur_spec] == 1 )  ){  
			One_Particle_Collection_split_pass_xyzE_particle ( 	(  	( MPI_fieldE ).particles + i ) , 	(  	( fieldE )->data + 	(  i % num_runtime ) ) , 	(  	( fieldB )->data + 	(  i % num_runtime ) ) , 	(  	( FoutJ )->data + 	(  i % num_runtime ) ) , (Mass0)[	(  i / num_runtime )] , (Charge0)[	(  i / num_runtime )] , Deltat , N_l , N_M , push_J , cur_spec , num_spec );

	}else{
		0;

	 }
}	return  0 ;}
