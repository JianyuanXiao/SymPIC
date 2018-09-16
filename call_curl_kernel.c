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
#include "mpifields.h"
int  MPI_Yee_FDTD_Curl_E (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ){
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
	sync_ovlp_mpi_field ( inEB );
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  data0 = data ;
	Field3D_Seq *  data = 	( inEB )->data ;
	long  num_runtime = 	( inEB )->num_runtime ;
	PS_MPI_Comm  comm = 	( inEB )->comm ;
	long  cur_rank = 	( inEB )->cur_rank ;
	long  num_mpi_process = 	( inEB )->num_mpi_process ;
	long *  sync_layer_len = 	( inEB )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( inEB )->rqst ;
	One_Particle_Collection *  particles = 	( inEB )->particles ;
	int  num_spec = 	( inEB )->num_spec ;
	double  damp_vars = 	( inEB )->damp_vars ;
	Field3D_Seq_Yee_FDTD_Curl_E ( 	(  data0 + i ) , 	(  data + i ) , DT );
}	return  0 ;}
int  MPI_Yee_FDTD_Curl_B (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ){
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
	sync_ovlp_mpi_field ( inEB );
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  data0 = data ;
	Field3D_Seq *  data = 	( inEB )->data ;
	long  num_runtime = 	( inEB )->num_runtime ;
	PS_MPI_Comm  comm = 	( inEB )->comm ;
	long  cur_rank = 	( inEB )->cur_rank ;
	long  num_mpi_process = 	( inEB )->num_mpi_process ;
	long *  sync_layer_len = 	( inEB )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( inEB )->rqst ;
	One_Particle_Collection *  particles = 	( inEB )->particles ;
	int  num_spec = 	( inEB )->num_spec ;
	double  damp_vars = 	( inEB )->damp_vars ;
	Field3D_Seq_Yee_FDTD_Curl_B ( 	(  data0 + i ) , 	(  data + i ) , DT );
}	return  0 ;}
int  MPI_Yee_FDTD_Curl_E_4th (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ){
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
	sync_ovlp_mpi_field ( inEB );
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  data0 = data ;
	Field3D_Seq *  data = 	( inEB )->data ;
	long  num_runtime = 	( inEB )->num_runtime ;
	PS_MPI_Comm  comm = 	( inEB )->comm ;
	long  cur_rank = 	( inEB )->cur_rank ;
	long  num_mpi_process = 	( inEB )->num_mpi_process ;
	long *  sync_layer_len = 	( inEB )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( inEB )->rqst ;
	One_Particle_Collection *  particles = 	( inEB )->particles ;
	int  num_spec = 	( inEB )->num_spec ;
	double  damp_vars = 	( inEB )->damp_vars ;
	Field3D_Seq_Yee_FDTD_Curl_E_4th ( 	(  data0 + i ) , 	(  data + i ) , DT );
}	return  0 ;}
int  MPI_Yee_FDTD_Curl_B_4th (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ){
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
	sync_ovlp_mpi_field ( inEB );
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  data0 = data ;
	Field3D_Seq *  data = 	( inEB )->data ;
	long  num_runtime = 	( inEB )->num_runtime ;
	PS_MPI_Comm  comm = 	( inEB )->comm ;
	long  cur_rank = 	( inEB )->cur_rank ;
	long  num_mpi_process = 	( inEB )->num_mpi_process ;
	long *  sync_layer_len = 	( inEB )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( inEB )->rqst ;
	One_Particle_Collection *  particles = 	( inEB )->particles ;
	int  num_spec = 	( inEB )->num_spec ;
	double  damp_vars = 	( inEB )->damp_vars ;
	Field3D_Seq_Yee_FDTD_Curl_B_4th ( 	(  data0 + i ) , 	(  data + i ) , DT );
}	return  0 ;}
int  MPI_Yee_FDTD_Grad_FWD (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ){
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
	sync_ovlp_mpi_field ( inEB );
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  data0 = data ;
	Field3D_Seq *  data = 	( inEB )->data ;
	long  num_runtime = 	( inEB )->num_runtime ;
	PS_MPI_Comm  comm = 	( inEB )->comm ;
	long  cur_rank = 	( inEB )->cur_rank ;
	long  num_mpi_process = 	( inEB )->num_mpi_process ;
	long *  sync_layer_len = 	( inEB )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( inEB )->rqst ;
	One_Particle_Collection *  particles = 	( inEB )->particles ;
	int  num_spec = 	( inEB )->num_spec ;
	double  damp_vars = 	( inEB )->damp_vars ;
	Field3D_Seq_Yee_FDTD_Grad_FWD ( 	(  data0 + i ) , 	(  data + i ) , DT );
}	return  0 ;}
int  MPI_Yee_FDTD_Grad_BWD (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ){
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
	sync_ovlp_mpi_field ( inEB );
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  data0 = data ;
	Field3D_Seq *  data = 	( inEB )->data ;
	long  num_runtime = 	( inEB )->num_runtime ;
	PS_MPI_Comm  comm = 	( inEB )->comm ;
	long  cur_rank = 	( inEB )->cur_rank ;
	long  num_mpi_process = 	( inEB )->num_mpi_process ;
	long *  sync_layer_len = 	( inEB )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( inEB )->rqst ;
	One_Particle_Collection *  particles = 	( inEB )->particles ;
	int  num_spec = 	( inEB )->num_spec ;
	double  damp_vars = 	( inEB )->damp_vars ;
	Field3D_Seq_Yee_FDTD_Grad_BWD ( 	(  data0 + i ) , 	(  data + i ) , DT );
}	return  0 ;}
int  MPI_Yee_FDTD_Grad_FWD_4th (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ){
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
	sync_ovlp_mpi_field ( inEB );
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  data0 = data ;
	Field3D_Seq *  data = 	( inEB )->data ;
	long  num_runtime = 	( inEB )->num_runtime ;
	PS_MPI_Comm  comm = 	( inEB )->comm ;
	long  cur_rank = 	( inEB )->cur_rank ;
	long  num_mpi_process = 	( inEB )->num_mpi_process ;
	long *  sync_layer_len = 	( inEB )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( inEB )->rqst ;
	One_Particle_Collection *  particles = 	( inEB )->particles ;
	int  num_spec = 	( inEB )->num_spec ;
	double  damp_vars = 	( inEB )->damp_vars ;
	Field3D_Seq_Yee_FDTD_Grad_FWD_4th ( 	(  data0 + i ) , 	(  data + i ) , DT );
}	return  0 ;}
int  MPI_Yee_FDTD_Grad_BWD_4th (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ){
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
	sync_ovlp_mpi_field ( inEB );
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  data0 = data ;
	Field3D_Seq *  data = 	( inEB )->data ;
	long  num_runtime = 	( inEB )->num_runtime ;
	PS_MPI_Comm  comm = 	( inEB )->comm ;
	long  cur_rank = 	( inEB )->cur_rank ;
	long  num_mpi_process = 	( inEB )->num_mpi_process ;
	long *  sync_layer_len = 	( inEB )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( inEB )->rqst ;
	One_Particle_Collection *  particles = 	( inEB )->particles ;
	int  num_spec = 	( inEB )->num_spec ;
	double  damp_vars = 	( inEB )->damp_vars ;
	Field3D_Seq_Yee_FDTD_Grad_BWD_4th ( 	(  data0 + i ) , 	(  data + i ) , DT );
}	return  0 ;}
int  MPI_Yee_FDTD_Curl_FWD (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ){
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
	sync_ovlp_mpi_field ( inEB );
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  data0 = data ;
	Field3D_Seq *  data = 	( inEB )->data ;
	long  num_runtime = 	( inEB )->num_runtime ;
	PS_MPI_Comm  comm = 	( inEB )->comm ;
	long  cur_rank = 	( inEB )->cur_rank ;
	long  num_mpi_process = 	( inEB )->num_mpi_process ;
	long *  sync_layer_len = 	( inEB )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( inEB )->rqst ;
	One_Particle_Collection *  particles = 	( inEB )->particles ;
	int  num_spec = 	( inEB )->num_spec ;
	double  damp_vars = 	( inEB )->damp_vars ;
	Field3D_Seq_Yee_FDTD_Curl_FWD ( 	(  data0 + i ) , 	(  data + i ) , DT );
}	return  0 ;}
int  MPI_Yee_FDTD_Curl_BWD (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ){
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
	sync_ovlp_mpi_field ( inEB );
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  data0 = data ;
	Field3D_Seq *  data = 	( inEB )->data ;
	long  num_runtime = 	( inEB )->num_runtime ;
	PS_MPI_Comm  comm = 	( inEB )->comm ;
	long  cur_rank = 	( inEB )->cur_rank ;
	long  num_mpi_process = 	( inEB )->num_mpi_process ;
	long *  sync_layer_len = 	( inEB )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( inEB )->rqst ;
	One_Particle_Collection *  particles = 	( inEB )->particles ;
	int  num_spec = 	( inEB )->num_spec ;
	double  damp_vars = 	( inEB )->damp_vars ;
	Field3D_Seq_Yee_FDTD_Curl_BWD ( 	(  data0 + i ) , 	(  data + i ) , DT );
}	return  0 ;}
int  MPI_Yee_FDTD_Curl_FWD_4th (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ){
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
	sync_ovlp_mpi_field ( inEB );
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  data0 = data ;
	Field3D_Seq *  data = 	( inEB )->data ;
	long  num_runtime = 	( inEB )->num_runtime ;
	PS_MPI_Comm  comm = 	( inEB )->comm ;
	long  cur_rank = 	( inEB )->cur_rank ;
	long  num_mpi_process = 	( inEB )->num_mpi_process ;
	long *  sync_layer_len = 	( inEB )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( inEB )->rqst ;
	One_Particle_Collection *  particles = 	( inEB )->particles ;
	int  num_spec = 	( inEB )->num_spec ;
	double  damp_vars = 	( inEB )->damp_vars ;
	Field3D_Seq_Yee_FDTD_Curl_FWD_4th ( 	(  data0 + i ) , 	(  data + i ) , DT );
}	return  0 ;}
int  MPI_Yee_FDTD_Curl_BWD_4th (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ){
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
	sync_ovlp_mpi_field ( inEB );
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  data0 = data ;
	Field3D_Seq *  data = 	( inEB )->data ;
	long  num_runtime = 	( inEB )->num_runtime ;
	PS_MPI_Comm  comm = 	( inEB )->comm ;
	long  cur_rank = 	( inEB )->cur_rank ;
	long  num_mpi_process = 	( inEB )->num_mpi_process ;
	long *  sync_layer_len = 	( inEB )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( inEB )->rqst ;
	One_Particle_Collection *  particles = 	( inEB )->particles ;
	int  num_spec = 	( inEB )->num_spec ;
	double  damp_vars = 	( inEB )->damp_vars ;
	Field3D_Seq_Yee_FDTD_Curl_BWD_4th ( 	(  data0 + i ) , 	(  data + i ) , DT );
}	return  0 ;}
int  MPI_Yee_FDTD_Div_FWD (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ){
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
	sync_ovlp_mpi_field ( inEB );
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  data0 = data ;
	Field3D_Seq *  data = 	( inEB )->data ;
	long  num_runtime = 	( inEB )->num_runtime ;
	PS_MPI_Comm  comm = 	( inEB )->comm ;
	long  cur_rank = 	( inEB )->cur_rank ;
	long  num_mpi_process = 	( inEB )->num_mpi_process ;
	long *  sync_layer_len = 	( inEB )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( inEB )->rqst ;
	One_Particle_Collection *  particles = 	( inEB )->particles ;
	int  num_spec = 	( inEB )->num_spec ;
	double  damp_vars = 	( inEB )->damp_vars ;
	Field3D_Seq_Yee_FDTD_Div_FWD ( 	(  data0 + i ) , 	(  data + i ) , DT );
}	return  0 ;}
int  MPI_Yee_FDTD_Div_BWD (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ){
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
	sync_ovlp_mpi_field ( inEB );
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  data0 = data ;
	Field3D_Seq *  data = 	( inEB )->data ;
	long  num_runtime = 	( inEB )->num_runtime ;
	PS_MPI_Comm  comm = 	( inEB )->comm ;
	long  cur_rank = 	( inEB )->cur_rank ;
	long  num_mpi_process = 	( inEB )->num_mpi_process ;
	long *  sync_layer_len = 	( inEB )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( inEB )->rqst ;
	One_Particle_Collection *  particles = 	( inEB )->particles ;
	int  num_spec = 	( inEB )->num_spec ;
	double  damp_vars = 	( inEB )->damp_vars ;
	Field3D_Seq_Yee_FDTD_Div_BWD ( 	(  data0 + i ) , 	(  data + i ) , DT );
}	return  0 ;}
int  MPI_Yee_FDTD_Div_FWD_4th (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ){
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
	sync_ovlp_mpi_field ( inEB );
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  data0 = data ;
	Field3D_Seq *  data = 	( inEB )->data ;
	long  num_runtime = 	( inEB )->num_runtime ;
	PS_MPI_Comm  comm = 	( inEB )->comm ;
	long  cur_rank = 	( inEB )->cur_rank ;
	long  num_mpi_process = 	( inEB )->num_mpi_process ;
	long *  sync_layer_len = 	( inEB )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( inEB )->rqst ;
	One_Particle_Collection *  particles = 	( inEB )->particles ;
	int  num_spec = 	( inEB )->num_spec ;
	double  damp_vars = 	( inEB )->damp_vars ;
	Field3D_Seq_Yee_FDTD_Div_FWD_4th ( 	(  data0 + i ) , 	(  data + i ) , DT );
}	return  0 ;}
int  MPI_Yee_FDTD_Div_BWD_4th (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ){
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
	sync_ovlp_mpi_field ( inEB );
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  data0 = data ;
	Field3D_Seq *  data = 	( inEB )->data ;
	long  num_runtime = 	( inEB )->num_runtime ;
	PS_MPI_Comm  comm = 	( inEB )->comm ;
	long  cur_rank = 	( inEB )->cur_rank ;
	long  num_mpi_process = 	( inEB )->num_mpi_process ;
	long *  sync_layer_len = 	( inEB )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( inEB )->rqst ;
	One_Particle_Collection *  particles = 	( inEB )->particles ;
	int  num_spec = 	( inEB )->num_spec ;
	double  damp_vars = 	( inEB )->damp_vars ;
	Field3D_Seq_Yee_FDTD_Div_BWD_4th ( 	(  data0 + i ) , 	(  data + i ) , DT );
}	return  0 ;}
int  MPI_merge_current (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ){
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
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  data0 = data ;
	Field3D_Seq *  data = 	( inEB )->data ;
	long  num_runtime = 	( inEB )->num_runtime ;
	PS_MPI_Comm  comm = 	( inEB )->comm ;
	long  cur_rank = 	( inEB )->cur_rank ;
	long  num_mpi_process = 	( inEB )->num_mpi_process ;
	long *  sync_layer_len = 	( inEB )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( inEB )->rqst ;
	One_Particle_Collection *  particles = 	( inEB )->particles ;
	int  num_spec = 	( inEB )->num_spec ;
	double  damp_vars = 	( inEB )->damp_vars ;
	Field3D_Seq_merge_current ( 	(  data0 + i ) , 	(  data + i ) );
}	return  0 ;}
int  MPI_Yee_FDTD_MUR_ABC (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ,int  use_abc ,int  use_pec ,int  use_damp ){
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
	sync_ovlp_mpi_field ( inEB );
	if (  	(  use_abc == 0 )  ){  
			Field3D_MPI_yee_abc_ ( pthis , inEB , DT );

	}else{
			if (  	(  use_abc == 1 )  ){  
			Field3D_MPI_yee_abc_x ( pthis , inEB , DT );

	}else{
			if (  	(  use_abc == 2 )  ){  
			Field3D_MPI_yee_abc_y ( pthis , inEB , DT );

	}else{
			if (  	(  use_abc == 3 )  ){  
			Field3D_MPI_yee_abc_xy ( pthis , inEB , DT );

	}else{
			if (  	(  use_abc == 4 )  ){  
			Field3D_MPI_yee_abc_z ( pthis , inEB , DT );

	}else{
			if (  	(  use_abc == 5 )  ){  
			Field3D_MPI_yee_abc_xz ( pthis , inEB , DT );

	}else{
			if (  	(  use_abc == 6 )  ){  
			Field3D_MPI_yee_abc_yz ( pthis , inEB , DT );

	}else{
			if (  	(  use_abc == 7 )  ){  
			Field3D_MPI_yee_abc_xyz ( pthis , inEB , DT );

	}else{
		0;

	 }

	 }

	 }

	 }

	 }

	 }

	 }

	 }
	if (  	(  use_pec == 0 )  ){  
			Field3D_MPI_yee_pec_ ( pthis , inEB , DT );

	}else{
			if (  	(  use_pec == 1 )  ){  
			Field3D_MPI_yee_pec_x ( pthis , inEB , DT );

	}else{
			if (  	(  use_pec == 2 )  ){  
			Field3D_MPI_yee_pec_y ( pthis , inEB , DT );

	}else{
			if (  	(  use_pec == 3 )  ){  
			Field3D_MPI_yee_pec_xy ( pthis , inEB , DT );

	}else{
			if (  	(  use_pec == 4 )  ){  
			Field3D_MPI_yee_pec_z ( pthis , inEB , DT );

	}else{
			if (  	(  use_pec == 5 )  ){  
			Field3D_MPI_yee_pec_xz ( pthis , inEB , DT );

	}else{
			if (  	(  use_pec == 6 )  ){  
			Field3D_MPI_yee_pec_yz ( pthis , inEB , DT );

	}else{
			if (  	(  use_pec == 7 )  ){  
			Field3D_MPI_yee_pec_xyz ( pthis , inEB , DT );

	}else{
		0;

	 }

	 }

	 }

	 }

	 }

	 }

	 }

	 }
	if (  	(  use_damp == 0 )  ){  
			Field3D_MPI_yee_damp_ ( pthis , inEB , DT );

	}else{
			if (  	(  use_damp == 1 )  ){  
			Field3D_MPI_yee_damp_x ( pthis , inEB , DT );

	}else{
			if (  	(  use_damp == 2 )  ){  
			Field3D_MPI_yee_damp_y ( pthis , inEB , DT );

	}else{
			if (  	(  use_damp == 3 )  ){  
			Field3D_MPI_yee_damp_xy ( pthis , inEB , DT );

	}else{
			if (  	(  use_damp == 4 )  ){  
			Field3D_MPI_yee_damp_z ( pthis , inEB , DT );

	}else{
			if (  	(  use_damp == 5 )  ){  
			Field3D_MPI_yee_damp_xz ( pthis , inEB , DT );

	}else{
			if (  	(  use_damp == 6 )  ){  
			Field3D_MPI_yee_damp_yz ( pthis , inEB , DT );

	}else{
			if (  	(  use_damp == 7 )  ){  
			Field3D_MPI_yee_damp_xyz ( pthis , inEB , DT );

	}else{
		0;

	 }

	 }

	 }

	 }

	 }

	 }

	 }

	 }
	return  0 ;}
int  MPI_kgm_eqn_core (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ,double  m ,double  Q ,double  DX ,double  extg ,double  refz0 ){
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
	sync_ovlp_mpi_field ( inEB );
	for (i=0 ; 	(  i < num_runtime ) ; i++)
	{
	Field3D_Seq *  data0 = data ;
	Field3D_Seq *  data = 	( inEB )->data ;
	long  num_runtime = 	( inEB )->num_runtime ;
	PS_MPI_Comm  comm = 	( inEB )->comm ;
	long  cur_rank = 	( inEB )->cur_rank ;
	long  num_mpi_process = 	( inEB )->num_mpi_process ;
	long *  sync_layer_len = 	( inEB )->sync_layer_len ;
	PS_MPI_Request * *  rqst = 	( inEB )->rqst ;
	One_Particle_Collection *  particles = 	( inEB )->particles ;
	int  num_spec = 	( inEB )->num_spec ;
	double  damp_vars = 	( inEB )->damp_vars ;
	Field3D_Seq_kgm_eqn_core ( 	(  data0 + i ) , 	(  data + i ) , DT , m , Q , DX , extg , refz0 );
}	return  0 ;}
