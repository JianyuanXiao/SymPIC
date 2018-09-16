#include <stdlib.h>
#include <stdio.h>
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
#include <math.h>
#include "blas_shell.h"
#include "run_particle.h"
#include <cgapsio.h>
#include "mpi_fieldio.h"
#include "cfgcst.h"
#include "call_curl_kernel.h"
#include "mpifields.h"
#include "split_shell.h"
double  wclk_now ();
int  split_1st_all_passes (Particle_in_Cell_MPI *  pthis ,double  dt0 ,int  use_vlo ){
	Field3D_MPI  MPI_fieldE = 	( pthis )->MPI_fieldE ;
	Field3D_MPI  MPI_fieldB = 	( pthis )->MPI_fieldB ;
	Field3D_MPI  MPI_fieldB1 = 	( pthis )->MPI_fieldB1 ;
	Field3D_MPI  MPI_FoutJ = 	( pthis )->MPI_FoutJ ;
	Field3D_MPI  MPI_LFoutJ = 	( pthis )->MPI_LFoutJ ;
	Field3D_MPI  MPI_fieldEtmp = 	( pthis )->MPI_fieldEtmp ;
	Field3D_MPI *  pMPI_FoutJ = 	( pthis )->pMPI_FoutJ ;
	Field3D_MPI *  pMPI_FoutEN = 	( pthis )->pMPI_FoutEN ;
	Field3D_MPI  MPI_fieldE_ext = 	( pthis )->MPI_fieldE_ext ;
	Field3D_MPI  MPI_fieldB_ext = 	( pthis )->MPI_fieldB_ext ;
	Field3D_MPI  MPI_fieldE_filter = 	( pthis )->MPI_fieldE_filter ;
	Field3D_MPI  MPI_fieldB_filter = 	( pthis )->MPI_fieldB_filter ;
	Field3D_MPI *  pB0 = 	( pthis )->pB0 ;
	Field3D_MPI *  pB1 = 	( pthis )->pB1 ;
	int  use_small_grid = 	( pthis )->use_small_grid ;
	double  dt = 	( pthis )->dt ;
	Field3D_MPI *  pMPI_fieldE = 	& ( MPI_fieldE ) ;
	Field3D_MPI *  pMPI_fieldB = 	& ( MPI_fieldB ) ;
	split_pass_xyz_zyx_mpi_shell ( pthis , dt0 , 1 , 1 , use_vlo );
	pass_GeqB ( pthis , dt0 );
	sync_ovlp_mpi_field ( pMPI_fieldE );
	split_pass_E_particle_mpi ( pthis , dt0 );
	MPI_Yee_FDTD_Curl_E ( pMPI_fieldB , pMPI_fieldE , dt0 );
	return  0 ;}
int  pass_GeqB (Particle_in_Cell_MPI *  pthis ,double  deltat ){
	Field3D_MPI  MPI_fieldE = 	( pthis )->MPI_fieldE ;
	Field3D_MPI  MPI_fieldB = 	( pthis )->MPI_fieldB ;
	Field3D_MPI  MPI_fieldB1 = 	( pthis )->MPI_fieldB1 ;
	Field3D_MPI  MPI_FoutJ = 	( pthis )->MPI_FoutJ ;
	Field3D_MPI  MPI_LFoutJ = 	( pthis )->MPI_LFoutJ ;
	Field3D_MPI  MPI_fieldEtmp = 	( pthis )->MPI_fieldEtmp ;
	Field3D_MPI *  pMPI_FoutJ = 	( pthis )->pMPI_FoutJ ;
	Field3D_MPI *  pMPI_FoutEN = 	( pthis )->pMPI_FoutEN ;
	Field3D_MPI  MPI_fieldE_ext = 	( pthis )->MPI_fieldE_ext ;
	Field3D_MPI  MPI_fieldB_ext = 	( pthis )->MPI_fieldB_ext ;
	Field3D_MPI  MPI_fieldE_filter = 	( pthis )->MPI_fieldE_filter ;
	Field3D_MPI  MPI_fieldB_filter = 	( pthis )->MPI_fieldB_filter ;
	Field3D_MPI *  pB0 = 	( pthis )->pB0 ;
	Field3D_MPI *  pB1 = 	( pthis )->pB1 ;
	int  use_small_grid = 	( pthis )->use_small_grid ;
	double  dt = 	( pthis )->dt ;
	Field3D_MPI *  pMPI_fieldE = 	& ( MPI_fieldE ) ;
	Field3D_MPI *  pMPI_fieldB = 	& ( MPI_fieldB ) ;
	Field3D_MPI *  pMPI_fieldEtmp = 	& ( MPI_fieldEtmp ) ;
	void *  pe = 	( pMPI_fieldE->data )->pe ;
	long  xlen = 	( pMPI_fieldE->data )->xlen ;
	long  ylen = 	( pMPI_fieldE->data )->ylen ;
	long  zlen = 	( pMPI_fieldE->data )->zlen ;
	long  xblock = 	( pMPI_fieldE->data )->xblock ;
	long  yblock = 	( pMPI_fieldE->data )->yblock ;
	long  zblock = 	( pMPI_fieldE->data )->zblock ;
	long  numvec = 	( pMPI_fieldE->data )->numvec ;
	long  x_num_thread_block = 	( pMPI_fieldE->data )->x_num_thread_block ;
	long  y_num_thread_block = 	( pMPI_fieldE->data )->y_num_thread_block ;
	long  z_num_thread_block = 	( pMPI_fieldE->data )->z_num_thread_block ;
	int  ovlp = 	( pMPI_fieldE->data )->ovlp ;
	int  num_ele = 	( pMPI_fieldE->data )->num_ele ;
	int  CD_type = 	( pMPI_fieldE->data )->CD_type ;
	void * *  sync_layer_pscmc = 	( pMPI_fieldE->data )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( pMPI_fieldE->data )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( pMPI_fieldE->data )->sync_kernels ;
	void * *  fdtd_kernels = 	( pMPI_fieldE->data )->fdtd_kernels ;
	void * *  dm_kernels = 	( pMPI_fieldE->data )->dm_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pMPI_fieldE->data )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pMPI_fieldE->data )->geo_yeefdtd_rect_kernels ;
	void * *  yee_abc_kernels = 	( pMPI_fieldE->data )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pMPI_fieldE->data )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pMPI_fieldE->data )->yee_damp_kernels ;
	void *  rdcd = 	( pMPI_fieldE->data )->rdcd ;
	double *  rdcd_host = 	( pMPI_fieldE->data )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( pMPI_fieldE->data )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( pMPI_fieldE->data )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( pMPI_fieldE->data )->cur_rankz_pscmc ;
	void *  xoffset = 	( pMPI_fieldE->data )->xoffset ;
	void *  yoffset = 	( pMPI_fieldE->data )->yoffset ;
	void *  zoffset = 	( pMPI_fieldE->data )->zoffset ;
	long *  global_x_offset = 	( pMPI_fieldE->data )->global_x_offset ;
	long *  global_y_offset = 	( pMPI_fieldE->data )->global_y_offset ;
	long *  global_z_offset = 	( pMPI_fieldE->data )->global_z_offset ;
	long *  global_id = 	( pMPI_fieldE->data )->global_id ;
	long  global_pid = 	( pMPI_fieldE->data )->global_pid ;
	long *  adj_ids = 	( pMPI_fieldE->data )->adj_ids ;
	long *  adj_processes = 	( pMPI_fieldE->data )->adj_processes ;
	long *  adj_local_tid = 	( pMPI_fieldE->data )->adj_local_tid ;
	void *  main_data = 	( pMPI_fieldE->data )->main_data ;
	double  delta_x = 	( pMPI_fieldE->data )->delta_x ;
	double  delta_y = 	( pMPI_fieldE->data )->delta_y ;
	double  delta_z = 	( pMPI_fieldE->data )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( pMPI_fieldE->data )->blas_yiszero_synced_kernel ;
	void *  blas_yiszero_kernel = 	( pMPI_fieldE->data )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( pMPI_fieldE->data )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( pMPI_fieldE->data )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( pMPI_fieldE->data )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( pMPI_fieldE->data )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( pMPI_fieldE->data )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( pMPI_fieldE->data )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( pMPI_fieldE->data )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( pMPI_fieldE->data )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( pMPI_fieldE->data )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( pMPI_fieldE->data )->blas_sum_kernel ;
	if (  USE_NP_BOUNDARY  ){  
			double  G_USE_ABC_DIR = 	call_GET_VAR ( "USE_ABC_DIR" ) ;
	double  G_USE_PEC_DIR = 	call_GET_VAR ( "USE_PEC_DIR" ) ;
	double  G_USE_DAMP_DIR = 	call_GET_VAR ( "USE_DAMP_DIR" ) ;
	blas_yisax_Field3D_MPI ( pMPI_fieldEtmp , pMPI_fieldEtmp , 1.00000000000000000e+00 , pMPI_fieldE );
	MPI_RECT_YEE_CURL_L ( pMPI_fieldE , pMPI_fieldB , delta_z , delta_y , delta_x , deltat );
	MPI_Yee_FDTD_MUR_ABC ( pMPI_fieldE , pMPI_fieldEtmp , deltat , G_USE_ABC_DIR , G_USE_PEC_DIR , G_USE_DAMP_DIR );

	}else{
			MPI_RECT_YEE_CURL_L ( pMPI_fieldE , pMPI_fieldB , delta_z , delta_y , delta_x , deltat );

	 }
	return  0 ;}
int  FDTD_2_4th_ALL_passes (Particle_in_Cell_MPI *  pthis ,double  dt0 ){
	Field3D_MPI  MPI_fieldE = 	( pthis )->MPI_fieldE ;
	Field3D_MPI  MPI_fieldB = 	( pthis )->MPI_fieldB ;
	Field3D_MPI  MPI_fieldB1 = 	( pthis )->MPI_fieldB1 ;
	Field3D_MPI  MPI_FoutJ = 	( pthis )->MPI_FoutJ ;
	Field3D_MPI  MPI_LFoutJ = 	( pthis )->MPI_LFoutJ ;
	Field3D_MPI  MPI_fieldEtmp = 	( pthis )->MPI_fieldEtmp ;
	Field3D_MPI *  pMPI_FoutJ = 	( pthis )->pMPI_FoutJ ;
	Field3D_MPI *  pMPI_FoutEN = 	( pthis )->pMPI_FoutEN ;
	Field3D_MPI  MPI_fieldE_ext = 	( pthis )->MPI_fieldE_ext ;
	Field3D_MPI  MPI_fieldB_ext = 	( pthis )->MPI_fieldB_ext ;
	Field3D_MPI  MPI_fieldE_filter = 	( pthis )->MPI_fieldE_filter ;
	Field3D_MPI  MPI_fieldB_filter = 	( pthis )->MPI_fieldB_filter ;
	Field3D_MPI *  pB0 = 	( pthis )->pB0 ;
	Field3D_MPI *  pB1 = 	( pthis )->pB1 ;
	int  use_small_grid = 	( pthis )->use_small_grid ;
	double  dt = 	( pthis )->dt ;
(dt0 = 	(  dt0 / 2 ));
	Field3D_MPI *  pMPI_fieldE = 	& ( MPI_fieldE ) ;
	Field3D_MPI *  pMPI_fieldB = 	& ( MPI_fieldB ) ;
	MPI_Yee_FDTD_Curl_B_4th ( pMPI_fieldE , pMPI_fieldB , dt0 );
	MPI_Yee_FDTD_Curl_E_4th ( pMPI_fieldB , pMPI_fieldE , 	(  dt0 * 2 ) );
	MPI_Yee_FDTD_Curl_B_4th ( pMPI_fieldE , pMPI_fieldB , dt0 );
	return  0 ;}
int  FDTD_2_2th_ALL_passes (Particle_in_Cell_MPI *  pthis ,double  dt0 ){
	Field3D_MPI  MPI_fieldE = 	( pthis )->MPI_fieldE ;
	Field3D_MPI  MPI_fieldB = 	( pthis )->MPI_fieldB ;
	Field3D_MPI  MPI_fieldB1 = 	( pthis )->MPI_fieldB1 ;
	Field3D_MPI  MPI_FoutJ = 	( pthis )->MPI_FoutJ ;
	Field3D_MPI  MPI_LFoutJ = 	( pthis )->MPI_LFoutJ ;
	Field3D_MPI  MPI_fieldEtmp = 	( pthis )->MPI_fieldEtmp ;
	Field3D_MPI *  pMPI_FoutJ = 	( pthis )->pMPI_FoutJ ;
	Field3D_MPI *  pMPI_FoutEN = 	( pthis )->pMPI_FoutEN ;
	Field3D_MPI  MPI_fieldE_ext = 	( pthis )->MPI_fieldE_ext ;
	Field3D_MPI  MPI_fieldB_ext = 	( pthis )->MPI_fieldB_ext ;
	Field3D_MPI  MPI_fieldE_filter = 	( pthis )->MPI_fieldE_filter ;
	Field3D_MPI  MPI_fieldB_filter = 	( pthis )->MPI_fieldB_filter ;
	Field3D_MPI *  pB0 = 	( pthis )->pB0 ;
	Field3D_MPI *  pB1 = 	( pthis )->pB1 ;
	int  use_small_grid = 	( pthis )->use_small_grid ;
	double  dt = 	( pthis )->dt ;
	Field3D_MPI *  pMPI_fieldE = 	& ( MPI_fieldE ) ;
	Field3D_MPI *  pMPI_fieldB = 	& ( MPI_fieldB ) ;
	MPI_Yee_FDTD_Curl_B ( pMPI_fieldE , pMPI_fieldB , dt0 );
	MPI_Yee_FDTD_Curl_E ( pMPI_fieldB , pMPI_fieldE , dt0 );
	return  0 ;}
int  ITG_split_2nd_all_passes (Particle_in_Cell_MPI *  pthis ,double  dt0 ,double  moqe ,double  ne0 ,int  use_vlo ){
	Field3D_MPI  MPI_fieldE = 	( pthis )->MPI_fieldE ;
	Field3D_MPI  MPI_fieldB = 	( pthis )->MPI_fieldB ;
	Field3D_MPI  MPI_fieldB1 = 	( pthis )->MPI_fieldB1 ;
	Field3D_MPI  MPI_FoutJ = 	( pthis )->MPI_FoutJ ;
	Field3D_MPI  MPI_LFoutJ = 	( pthis )->MPI_LFoutJ ;
	Field3D_MPI  MPI_fieldEtmp = 	( pthis )->MPI_fieldEtmp ;
	Field3D_MPI *  pMPI_FoutJ = 	( pthis )->pMPI_FoutJ ;
	Field3D_MPI *  pMPI_FoutEN = 	( pthis )->pMPI_FoutEN ;
	Field3D_MPI  MPI_fieldE_ext = 	( pthis )->MPI_fieldE_ext ;
	Field3D_MPI  MPI_fieldB_ext = 	( pthis )->MPI_fieldB_ext ;
	Field3D_MPI  MPI_fieldE_filter = 	( pthis )->MPI_fieldE_filter ;
	Field3D_MPI  MPI_fieldB_filter = 	( pthis )->MPI_fieldB_filter ;
	Field3D_MPI *  pB0 = 	( pthis )->pB0 ;
	Field3D_MPI *  pB1 = 	( pthis )->pB1 ;
	int  use_small_grid = 	( pthis )->use_small_grid ;
	double  dt = 	( pthis )->dt ;
(dt0 = 	(  dt0 / 2 ));
	Field3D_MPI *  pMPI_fieldE = 	& ( MPI_fieldE ) ;
	Field3D_MPI *  pMPI_fieldB = 	& ( MPI_fieldB ) ;
	blas_yisconst_Field3D_MPI ( pMPI_fieldB , pMPI_fieldB , 0 );
	split_pass_xyz_zyx_mpi_shell ( pthis , dt0 , 1 , 0 , use_vlo );
	split_pass_xyz_zyx_mpi_shell ( pthis , dt0 , 0 , 0 , use_vlo );
	blas_yiszero_synced_Field3D_MPI ( pMPI_FoutJ , pMPI_FoutJ );
	calculate_rho_mpi ( pthis , 0 );
	merge_ovlp_mpi_field ( pMPI_FoutJ );
	blas_yisconst_Field3D_MPI ( pMPI_fieldB , pMPI_fieldB , ne0 );
	blas_get_ITG_Potential_Field3D_MPI ( pMPI_FoutJ , pMPI_FoutJ , 	& ( pthis->MPI_fieldE_ext ) , pMPI_fieldB , moqe );
	sync_ovlp_mpi_field ( pMPI_FoutJ );
	MPI_Yee_FDTD_Grad_FWD ( pMPI_fieldE , pMPI_FoutJ , 0 );
	sync_ovlp_mpi_field ( pMPI_fieldE );
	if (  0  ){  
			fprintf ( stderr , "mass=%e, chg=%e\n" , 	( 	( pthis->MPI_fieldE ).particles )->Mass , 	( 	( pthis->MPI_fieldE ).particles )->Charge );
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	sync_main_data_d2h ( pMPI_fieldE );
	init_parallel_file_for_mpi_fields ( pMPI_FoutJ , pgid , "tmpJ1" , -1 , 0 );
	mpi_field_write_to_file ( pMPI_FoutJ , pgid , 0 );
	mpi_field_write_to_file ( pMPI_fieldE , pgid , 1 );
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	exit ( 0 );

	}else{
		0;

	 }
	if (  use_vlo  ){  
			split_pass_E_particle_vlo_mpi ( pthis , 	(  dt0 * 2 ) );

	}else{
			split_pass_E_particle_mpi ( pthis , 	(  dt0 * 2 ) );

	 }
	return  0 ;}
int  split_2nd_all_passes (Particle_in_Cell_MPI *  pthis ,double  dt0 ,int  use_vlo ){
	Field3D_MPI  MPI_fieldE = 	( pthis )->MPI_fieldE ;
	Field3D_MPI  MPI_fieldB = 	( pthis )->MPI_fieldB ;
	Field3D_MPI  MPI_fieldB1 = 	( pthis )->MPI_fieldB1 ;
	Field3D_MPI  MPI_FoutJ = 	( pthis )->MPI_FoutJ ;
	Field3D_MPI  MPI_LFoutJ = 	( pthis )->MPI_LFoutJ ;
	Field3D_MPI  MPI_fieldEtmp = 	( pthis )->MPI_fieldEtmp ;
	Field3D_MPI *  pMPI_FoutJ = 	( pthis )->pMPI_FoutJ ;
	Field3D_MPI *  pMPI_FoutEN = 	( pthis )->pMPI_FoutEN ;
	Field3D_MPI  MPI_fieldE_ext = 	( pthis )->MPI_fieldE_ext ;
	Field3D_MPI  MPI_fieldB_ext = 	( pthis )->MPI_fieldB_ext ;
	Field3D_MPI  MPI_fieldE_filter = 	( pthis )->MPI_fieldE_filter ;
	Field3D_MPI  MPI_fieldB_filter = 	( pthis )->MPI_fieldB_filter ;
	Field3D_MPI *  pB0 = 	( pthis )->pB0 ;
	Field3D_MPI *  pB1 = 	( pthis )->pB1 ;
	int  use_small_grid = 	( pthis )->use_small_grid ;
	double  dt = 	( pthis )->dt ;
(dt0 = 	(  dt0 / 2 ));
	Field3D_MPI *  pMPI_fieldE = 	& ( MPI_fieldE ) ;
	Field3D_MPI *  pMPI_fieldB = 	& ( MPI_fieldB ) ;
	double  curt_profile_only = 	wclk_now (  ) ;
	pass_GeqB ( pthis , dt0 );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "GeqB" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	split_pass_xyz_zyx_mpi_shell ( pthis , dt0 , 1 , 1 , use_vlo );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "XYZ" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	sync_ovlp_mpi_field ( pMPI_fieldE );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "Sync E" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	if (  use_vlo  ){  
			split_pass_E_particle_vlo_mpi ( pthis , 	(  dt0 * 2 ) );

	}else{
			split_pass_E_particle_mpi ( pthis , 	(  dt0 * 2 ) );

	 }
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "PassE" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	MPI_Yee_FDTD_Curl_E ( pMPI_fieldB , pMPI_fieldE , 	(  dt0 * 2 ) );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "CurlE" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	split_pass_xyz_zyx_mpi_shell ( pthis , dt0 , 0 , 1 , use_vlo );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "ZYX" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	pass_GeqB ( pthis , dt0 );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "GeqB" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	return  0 ;}
