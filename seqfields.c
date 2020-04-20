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
#include "seqfields.h"
#include <stdio.h>
int  build_Field_compute_unit_from_seq_field (Field3D_Seq *  pthis ,Field3D_Seq *  input_E ){
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
	void * *  dmbihamt_kernels = 	( pthis )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( pthis )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( pthis )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( pthis )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( pthis )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( pthis )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( pthis )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( pthis )->yee_setfix_kernels ;
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
	void *  blas_mulxy_numele3_kernel = 	( pthis )->blas_mulxy_numele3_kernel ;
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
	int  num_cu = ((	(  0 == 	( input_E )->CD_type ))?(	c_blas_sum_get_num_compute_units ( NULL )):(((	(  1 == 	( input_E )->CD_type ))?(	openmp_blas_sum_get_num_compute_units ( NULL )):(0)))) ;
	int  new_num_ele = 	(  num_cu * 	( input_E )->num_ele ) ;
	fprintf ( stderr , "newnumele=%d numcu=%d\n" , new_num_ele , num_cu );
((pthis)[0] = (input_E)[0]);
(	( pthis )->num_ele = new_num_ele);
	return  0 ;}
int  build_Field_compute_unit_from_mpi_field (Field3D_MPI *  pthis ,Field3D_MPI *  input_E ){
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
((pthis)[0] = (input_E)[0]);
(	( pthis )->data = 	malloc ( 	(  sizeof(Field3D_Seq ) * 	( input_E )->num_runtime ) ));
{
	long  i ;
	for ((i = 0) ; 	(  i < 	( input_E )->num_runtime ) ; (i = 	(  i + 1 )))
	{
	build_Field_compute_unit_from_seq_field ( 	(  pthis->data + i ) , 	(  input_E->data + i ) );
}}}
