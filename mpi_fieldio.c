#include <stdio.h>
#include <stdint.h>
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
#include "space_filling_curve.h"
#include <cgapsio.h>
int  init_parallel_file_particle_for_mpi_fields_V0 (Field3D_MPI *  pthis ,Gaps_IO_DataFile *  gid_grid ,Gaps_IO_DataFile *  gid_cu ,long *  pgcache ,long *  pcucache ,char *  pName_grid ,char *  pName_cu ,long  numt ,int  ro ){
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
	int64_t   pdimarr_grid  [4];	int64_t   pdimarr_cu  [4];{
	void *  pe = 	( data )->pe ;
	long  xlen = 	( data )->xlen ;
	long  ylen = 	( data )->ylen ;
	long  zlen = 	( data )->zlen ;
	long  xblock = 	( data )->xblock ;
	long  yblock = 	( data )->yblock ;
	long  zblock = 	( data )->zblock ;
	long  numvec = 	( data )->numvec ;
	long  x_num_thread_block = 	( data )->x_num_thread_block ;
	long  y_num_thread_block = 	( data )->y_num_thread_block ;
	long  z_num_thread_block = 	( data )->z_num_thread_block ;
	int  ovlp = 	( data )->ovlp ;
	int  num_ele = 	( data )->num_ele ;
	int  CD_type = 	( data )->CD_type ;
	void * *  sync_layer_pscmc = 	( data )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( data )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( data )->sync_kernels ;
	void * *  fdtd_kernels = 	( data )->fdtd_kernels ;
	void * *  dm_kernels = 	( data )->dm_kernels ;
	void * *  dmbihamt_kernels = 	( data )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( data )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( data )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( data )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( data )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( data )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( data )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( data )->yee_setfix_kernels ;
	void *  rdcd = 	( data )->rdcd ;
	double *  rdcd_host = 	( data )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( data )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( data )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( data )->cur_rankz_pscmc ;
	void *  xoffset = 	( data )->xoffset ;
	void *  yoffset = 	( data )->yoffset ;
	void *  zoffset = 	( data )->zoffset ;
	long *  global_x_offset = 	( data )->global_x_offset ;
	long *  global_y_offset = 	( data )->global_y_offset ;
	long *  global_z_offset = 	( data )->global_z_offset ;
	long *  global_id = 	( data )->global_id ;
	long  global_pid = 	( data )->global_pid ;
	long *  adj_ids = 	( data )->adj_ids ;
	long *  adj_processes = 	( data )->adj_processes ;
	long *  adj_local_tid = 	( data )->adj_local_tid ;
	void *  main_data = 	( data )->main_data ;
	double  delta_x = 	( data )->delta_x ;
	double  delta_y = 	( data )->delta_y ;
	double  delta_z = 	( data )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( data )->blas_yiszero_synced_kernel ;
	void *  blas_mulxy_numele3_kernel = 	( data )->blas_mulxy_numele3_kernel ;
	void *  blas_yiszero_kernel = 	( data )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( data )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( data )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( data )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( data )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( data )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( data )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( data )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( data )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( data )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( data )->blas_sum_kernel ;
{
	Field3D_Seq *  pfield = 	( particles )->pfield ;
	Field3D_Seq *  pfieldE = 	( particles )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( particles )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( particles )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( particles )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( particles )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( particles )->pFoutEN ;
	void * *  sort_kernel = 	( particles )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( particles )->geo_rel_1st_kernel ;
	void * *  implicit_kernel = 	( particles )->implicit_kernel ;
	void * *  rel_1st_kernel = 	( particles )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( particles )->krook_collision_test_kernel ;
	void * *  nonrel_test_kernel = 	( particles )->nonrel_test_kernel ;
	void * *  boris_yee_kernel = 	( particles )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( particles )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( particles )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( particles )->move_back_kernel_kernel ;
	double  Mass = 	( particles )->Mass ;
	double  Charge = 	( particles )->Charge ;
	double  Number_particle_per_marker = 	( particles )->Number_particle_per_marker ;
	long  grid_cache_len = 	( particles )->grid_cache_len ;
	long  cu_cache_length = 	( particles )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( particles )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( particles )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( particles )->split_pass_z_kernel ;
	void *  split_pass_x_nopush_kernel = 	( particles )->split_pass_x_nopush_kernel ;
	void *  split_pass_y_nopush_kernel = 	( particles )->split_pass_y_nopush_kernel ;
	void *  split_pass_z_nopush_kernel = 	( particles )->split_pass_z_nopush_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( particles )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( particles )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( particles )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( particles )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( particles )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( particles )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( particles )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( particles )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( particles )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( particles )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_nopush_kernel = 	( particles )->split_pass_x_vlo_nopush_kernel ;
	void *  split_pass_y_vlo_nopush_kernel = 	( particles )->split_pass_y_vlo_nopush_kernel ;
	void *  split_pass_z_vlo_nopush_kernel = 	( particles )->split_pass_z_vlo_nopush_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( particles )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( particles )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( particles )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( particles )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( particles )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( particles )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_nopush_small_grids_kernel = 	( particles )->split_pass_x_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_nopush_small_grids_kernel = 	( particles )->split_pass_y_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_nopush_small_grids_kernel = 	( particles )->split_pass_z_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( particles )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( particles )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( particles )->calculate_rho_kernel ;
	void *  inoutput = 	( particles )->inoutput ;
	void *  xyzw = 	( particles )->xyzw ;
	void *  cu_cache = 	( particles )->cu_cache ;
	void *  cu_xyzw = 	( particles )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( particles )->adjoint_vec_pids ;
	long  gcl = 0 ;
	long  ccl = 0 ;
{
	long  g ;
	for ((g = 0) ; 	(  g < num_spec ) ; (g = 	(  g + 1 )))
	{
(gcl = 	(  gcl + (pgcache)[g] ));
(ccl = 	(  ccl + (pcucache)[g] ));
}}((pdimarr_grid)[0] = 	(  num_spec + 	(  gcl * 6 ) ));
((pdimarr_cu)[0] = 	(  num_spec + 	(  ccl * 6 ) ));
}((pdimarr_grid)[1] = 	(  xlen * x_num_thread_block ));
((pdimarr_grid)[2] = 	(  ylen * y_num_thread_block ));
((pdimarr_grid)[3] = 	(  zlen * z_num_thread_block ));
((pdimarr_cu)[1] = x_num_thread_block);
((pdimarr_cu)[2] = y_num_thread_block);
((pdimarr_cu)[3] = z_num_thread_block);
}	GAPS_IO_InitDataInfo ( gid_grid , GAPS_IO_FLOAT64 , 4 , pdimarr_grid );
	GAPS_IO_InitDataInfo ( gid_cu , GAPS_IO_FLOAT64 , 4 , pdimarr_cu );
	if (  ro  ){  
			GAPS_IO_InitIFile ( gid_grid , pName_grid );
	GAPS_IO_InitIFile ( gid_cu , pName_cu );

	}else{
			GAPS_IO_InitOFile_with_TimeStep ( gid_grid , pName_grid , -1 );
	GAPS_IO_InitOFile_with_TimeStep ( gid_cu , pName_cu , -1 );
	GAPS_IO_TruncateFile ( gid_grid , 	(  numt + 1 ) , -1 );
	GAPS_IO_TruncateFile ( gid_cu , 	(  numt + 1 ) , -1 );
	GAPS_IO_FileFlush ( gid_grid );
	GAPS_IO_FileFlush ( gid_cu );

	 }
	PS_MPI_Barrier ( comm );
	return  0 ;}
int  dump_particle_parallel_file_for_mpi_fields_V0 (Field3D_MPI *  pthis ,Gaps_IO_DataFile *  gid_grid ,Gaps_IO_DataFile *  gid_cu ,long *  pgcache ,long *  pcucache ,long  numt ,int  use_non_nui_cache ){
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
	long  reduce_dim = 0 ;
	double  r_x_rat = 1.00000000000000000e+00 ;
	double  r_y_rat = 1.00000000000000000e+00 ;
	double  r_z_rat = 1.00000000000000000e+00 ;
	int  reduce_x = 	(  reduce_dim == 1 ) ;
	int  reduce_y = 	(  reduce_dim == 2 ) ;
	int  reduce_z = 	(  reduce_dim == 3 ) ;
	long  g_offset = 0 ;
	long  c_offset = 0 ;
	int64_t *  pdimarr_cu = 	( gid_cu )->pdimarray ;
	int64_t *  pdimarr_grid = 	( gid_grid )->pdimarray ;
	int64_t  cu_one_cache_len = 	(  	(  	(  (pdimarr_cu)[0] / num_spec ) - 1 ) / 6 ) ;
	int64_t  grid_one_cache_len = 	(  	(  	(  (pdimarr_grid)[0] / num_spec ) - 1 ) / 6 ) ;
	double  r_r_r = ((	(  reduce_dim == 1 ))?(r_x_rat):(((	(  reduce_dim == 2 ))?(r_y_rat):(((	(  reduce_dim == 3 ))?(r_z_rat):(0)))))) ;
{
	long  i ;
	for ((i = 0) ; 	(  i < num_spec ) ; (i = 	(  i + 1 )))
	{
{
	long  j ;
	for ((j = 0) ; 	(  j < num_runtime ) ; (j = 	(  j + 1 )))
	{
	void *  pe = 	( 	(  data + j ) )->pe ;
	long  xlen = 	( 	(  data + j ) )->xlen ;
	long  ylen = 	( 	(  data + j ) )->ylen ;
	long  zlen = 	( 	(  data + j ) )->zlen ;
	long  xblock = 	( 	(  data + j ) )->xblock ;
	long  yblock = 	( 	(  data + j ) )->yblock ;
	long  zblock = 	( 	(  data + j ) )->zblock ;
	long  numvec = 	( 	(  data + j ) )->numvec ;
	long  x_num_thread_block = 	( 	(  data + j ) )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	(  data + j ) )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	(  data + j ) )->z_num_thread_block ;
	int  ovlp = 	( 	(  data + j ) )->ovlp ;
	int  num_ele = 	( 	(  data + j ) )->num_ele ;
	int  CD_type = 	( 	(  data + j ) )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	(  data + j ) )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	(  data + j ) )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	(  data + j ) )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	(  data + j ) )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	(  data + j ) )->dm_kernels ;
	void * *  dmbihamt_kernels = 	( 	(  data + j ) )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  data + j ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  data + j ) )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( 	(  data + j ) )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( 	(  data + j ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  data + j ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  data + j ) )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( 	(  data + j ) )->yee_setfix_kernels ;
	void *  rdcd = 	( 	(  data + j ) )->rdcd ;
	double *  rdcd_host = 	( 	(  data + j ) )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	(  data + j ) )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	(  data + j ) )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	(  data + j ) )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	(  data + j ) )->xoffset ;
	void *  yoffset = 	( 	(  data + j ) )->yoffset ;
	void *  zoffset = 	( 	(  data + j ) )->zoffset ;
	long *  global_x_offset = 	( 	(  data + j ) )->global_x_offset ;
	long *  global_y_offset = 	( 	(  data + j ) )->global_y_offset ;
	long *  global_z_offset = 	( 	(  data + j ) )->global_z_offset ;
	long *  global_id = 	( 	(  data + j ) )->global_id ;
	long  global_pid = 	( 	(  data + j ) )->global_pid ;
	long *  adj_ids = 	( 	(  data + j ) )->adj_ids ;
	long *  adj_processes = 	( 	(  data + j ) )->adj_processes ;
	long *  adj_local_tid = 	( 	(  data + j ) )->adj_local_tid ;
	void *  main_data = 	( 	(  data + j ) )->main_data ;
	double  delta_x = 	( 	(  data + j ) )->delta_x ;
	double  delta_y = 	( 	(  data + j ) )->delta_y ;
	double  delta_z = 	( 	(  data + j ) )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	(  data + j ) )->blas_yiszero_synced_kernel ;
	void *  blas_mulxy_numele3_kernel = 	( 	(  data + j ) )->blas_mulxy_numele3_kernel ;
	void *  blas_yiszero_kernel = 	( 	(  data + j ) )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	(  data + j ) )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	(  data + j ) )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	(  data + j ) )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	(  data + j ) )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	(  data + j ) )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	(  data + j ) )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	(  data + j ) )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	(  data + j ) )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	(  data + j ) )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	(  data + j ) )->blas_sum_kernel ;
	Field3D_Seq *  pfield = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->pfield ;
	Field3D_Seq *  pfieldE = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->pFoutEN ;
	void * *  sort_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->geo_rel_1st_kernel ;
	void * *  implicit_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->implicit_kernel ;
	void * *  rel_1st_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->krook_collision_test_kernel ;
	void * *  nonrel_test_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->nonrel_test_kernel ;
	void * *  boris_yee_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->move_back_kernel_kernel ;
	double  Mass = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->Mass ;
	double  Charge = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->Charge ;
	double  Number_particle_per_marker = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->Number_particle_per_marker ;
	long  grid_cache_len = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->grid_cache_len ;
	long  cu_cache_length = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_z_kernel ;
	void *  split_pass_x_nopush_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_x_nopush_kernel ;
	void *  split_pass_y_nopush_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_y_nopush_kernel ;
	void *  split_pass_z_nopush_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_z_nopush_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_nopush_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_x_vlo_nopush_kernel ;
	void *  split_pass_y_vlo_nopush_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_y_vlo_nopush_kernel ;
	void *  split_pass_z_vlo_nopush_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_z_vlo_nopush_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_nopush_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_x_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_nopush_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_y_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_nopush_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_z_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->calculate_rho_kernel ;
	void *  inoutput = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->inoutput ;
	void *  xyzw = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->xyzw ;
	void *  cu_cache = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->cu_cache ;
	void *  cu_xyzw = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->adjoint_vec_pids ;
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
	double *  host_data = (((double * * )inoutput))[0] ;
	int *  xyzw_data = (((int * * )xyzw))[0] ;
	double *  cu_host_data = (((double * * )cu_cache))[0] ;
	int *  cu_xyzw_data = (((int * * )cu_xyzw))[0] ;
	long  alllenoff = 	(  xlen * 	(  ylen * zlen ) ) ;
{
	long  cur_pcid ;
	for ((cur_pcid = 0) ; 	(  cur_pcid < numvec ) ; (cur_pcid = 	(  cur_pcid + 1 )))
	{
	long  ofx = (global_x_offset)[cur_pcid] ;
	long  ofy = (global_y_offset)[cur_pcid] ;
	long  ofz = (global_z_offset)[cur_pcid] ;
	double *  grid_r_0 = 	(  host_data + 	(  cur_pcid * 	(  alllenoff * 	(  6 * grid_cache_len ) ) ) ) ;
	int *  xyzw_0 = 	(  xyzw_data + 	(  cur_pcid * 	(  alllenoff * 4 ) ) ) ;
{
	double *  cu_r_0 = 	(  cu_host_data + 	(  cur_pcid * 	(  6 * cu_cache_length ) ) ) ;
	int *  cu_xyzw_0 = 	(  cu_xyzw_data + 	(  cur_pcid * 4 ) ) ;
	long  ox = 	(  ofx / xlen ) ;
	long  oy = 	(  ofy / ylen ) ;
	long  oz = 	(  ofz / zlen ) ;
	long  offset_len = 	(  	(  (pdimarr_cu)[0] * 	(  ((reduce_x)?(0):(ox)) + 	(  ((reduce_x)?(1):((pdimarr_cu)[1])) * 	(  ((reduce_y)?(0):(oy)) + 	(  ((reduce_y)?(1):((pdimarr_cu)[2])) * ((reduce_z)?(0):(oz)) ) ) ) ) ) + c_offset ) ;
	double  num_load = (cu_xyzw_0)[0] ;
	GAPS_IO_DataSeek ( gid_cu , numt , offset_len );
	GAPS_IO_FWrite ( gid_cu , 	& ( num_load ) , 1 );
	GAPS_IO_FWrite ( gid_cu , cu_r_0 , 	(  6 * (cu_xyzw_0)[0] ) );
}{
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
	long  ox = 	(  ofx + xyzx ) ;
	long  oy = 	(  ofy + xyzy ) ;
	long  oz = 	(  ofz + xyzz ) ;
	long  offset_len = 	(  	(  (pdimarr_grid)[0] * 	(  ((reduce_x)?(0):(ox)) + 	(  ((reduce_x)?(1):((pdimarr_grid)[1])) * 	(  ((reduce_y)?(0):(oy)) + 	(  ((reduce_y)?(1):((pdimarr_grid)[2])) * ((reduce_z)?(0):(oz)) ) ) ) ) ) + g_offset ) ;
	int64_t  offset_xyzlen = ((	(  reduce_dim == 1 ))?(xyzx):(((	(  reduce_dim == 2 ))?(xyzy):(((	(  reduce_dim == 3 ))?(xyzz):(0)))))) ;
	GAPS_IO_DataSeek ( gid_grid , numt , offset_len );
	double  num_load = (grid_xyzw)[0] ;
	GAPS_IO_FWrite ( gid_grid , 	& ( num_load ) , 1 );
	GAPS_IO_FWrite ( gid_grid , grid_r , 	(  6 * (grid_xyzw)[0] ) );
}}}}}}}}}}(g_offset = 	(  g_offset + 	(  	(  6 * ((use_non_nui_cache)?((pgcache)[i]):(grid_one_cache_len)) ) + 1 ) ));
(c_offset = 	(  c_offset + 	(  	(  6 * ((use_non_nui_cache)?((pcucache)[i]):(cu_one_cache_len)) ) + 1 ) ));
}}	return  0 ;}
int  read_particle_parallel_file_for_mpi_fields_V0 (Field3D_MPI *  pthis ,Gaps_IO_DataFile *  gid_grid ,Gaps_IO_DataFile *  gid_cu ,long *  pgcache ,long *  pcucache ,long  numt ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat ,int  use_non_nui_cache ){
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
(r_x_rat = 	(  1.00000000000000000e+00 / r_x_rat ));
(r_y_rat = 	(  1.00000000000000000e+00 / r_y_rat ));
(r_z_rat = 	(  1.00000000000000000e+00 / r_z_rat ));
	int  reduce_x = 	(  reduce_dim == 1 ) ;
	int  reduce_y = 	(  reduce_dim == 2 ) ;
	int  reduce_z = 	(  reduce_dim == 3 ) ;
	long  g_offset = 0 ;
	long  c_offset = 0 ;
	int64_t *  pdimarr_cu = 	( gid_cu )->pdimarray ;
	int64_t *  pdimarr_grid = 	( gid_grid )->pdimarray ;
	int64_t  cu_one_cache_len = 	(  	(  	(  (pdimarr_cu)[0] / num_spec ) - 1 ) / 6 ) ;
	int64_t  grid_one_cache_len = 	(  	(  	(  (pdimarr_grid)[0] / num_spec ) - 1 ) / 6 ) ;
	double  r_r_r = ((	(  reduce_dim == 1 ))?(r_x_rat):(((	(  reduce_dim == 2 ))?(r_y_rat):(((	(  reduce_dim == 3 ))?(r_z_rat):(0)))))) ;
{
	long  i ;
	for ((i = 0) ; 	(  i < num_spec ) ; (i = 	(  i + 1 )))
	{
{
	long  j ;
	for ((j = 0) ; 	(  j < num_runtime ) ; (j = 	(  j + 1 )))
	{
	void *  pe = 	( 	(  data + j ) )->pe ;
	long  xlen = 	( 	(  data + j ) )->xlen ;
	long  ylen = 	( 	(  data + j ) )->ylen ;
	long  zlen = 	( 	(  data + j ) )->zlen ;
	long  xblock = 	( 	(  data + j ) )->xblock ;
	long  yblock = 	( 	(  data + j ) )->yblock ;
	long  zblock = 	( 	(  data + j ) )->zblock ;
	long  numvec = 	( 	(  data + j ) )->numvec ;
	long  x_num_thread_block = 	( 	(  data + j ) )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	(  data + j ) )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	(  data + j ) )->z_num_thread_block ;
	int  ovlp = 	( 	(  data + j ) )->ovlp ;
	int  num_ele = 	( 	(  data + j ) )->num_ele ;
	int  CD_type = 	( 	(  data + j ) )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	(  data + j ) )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	(  data + j ) )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	(  data + j ) )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	(  data + j ) )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	(  data + j ) )->dm_kernels ;
	void * *  dmbihamt_kernels = 	( 	(  data + j ) )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  data + j ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  data + j ) )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( 	(  data + j ) )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( 	(  data + j ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  data + j ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  data + j ) )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( 	(  data + j ) )->yee_setfix_kernels ;
	void *  rdcd = 	( 	(  data + j ) )->rdcd ;
	double *  rdcd_host = 	( 	(  data + j ) )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	(  data + j ) )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	(  data + j ) )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	(  data + j ) )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	(  data + j ) )->xoffset ;
	void *  yoffset = 	( 	(  data + j ) )->yoffset ;
	void *  zoffset = 	( 	(  data + j ) )->zoffset ;
	long *  global_x_offset = 	( 	(  data + j ) )->global_x_offset ;
	long *  global_y_offset = 	( 	(  data + j ) )->global_y_offset ;
	long *  global_z_offset = 	( 	(  data + j ) )->global_z_offset ;
	long *  global_id = 	( 	(  data + j ) )->global_id ;
	long  global_pid = 	( 	(  data + j ) )->global_pid ;
	long *  adj_ids = 	( 	(  data + j ) )->adj_ids ;
	long *  adj_processes = 	( 	(  data + j ) )->adj_processes ;
	long *  adj_local_tid = 	( 	(  data + j ) )->adj_local_tid ;
	void *  main_data = 	( 	(  data + j ) )->main_data ;
	double  delta_x = 	( 	(  data + j ) )->delta_x ;
	double  delta_y = 	( 	(  data + j ) )->delta_y ;
	double  delta_z = 	( 	(  data + j ) )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	(  data + j ) )->blas_yiszero_synced_kernel ;
	void *  blas_mulxy_numele3_kernel = 	( 	(  data + j ) )->blas_mulxy_numele3_kernel ;
	void *  blas_yiszero_kernel = 	( 	(  data + j ) )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	(  data + j ) )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	(  data + j ) )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	(  data + j ) )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	(  data + j ) )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	(  data + j ) )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	(  data + j ) )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	(  data + j ) )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	(  data + j ) )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	(  data + j ) )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	(  data + j ) )->blas_sum_kernel ;
	Field3D_Seq *  pfield = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->pfield ;
	Field3D_Seq *  pfieldE = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->pfieldE ;
	Field3D_Seq *  pfieldB = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->pfieldB ;
	Field3D_Seq *  pfieldB1 = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->pfieldB1 ;
	Field3D_Seq *  pFoutJ = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->pFoutJ ;
	Field3D_Seq *  pLFoutJ = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->pLFoutJ ;
	Field3D_Seq *  pFoutEN = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->pFoutEN ;
	void * *  sort_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->sort_kernel ;
	void * *  geo_rel_1st_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->geo_rel_1st_kernel ;
	void * *  implicit_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->implicit_kernel ;
	void * *  rel_1st_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->rel_1st_kernel ;
	void * *  krook_collision_test_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->krook_collision_test_kernel ;
	void * *  nonrel_test_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->nonrel_test_kernel ;
	void * *  boris_yee_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->boris_yee_kernel ;
	void *  cu_swap_l_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->cu_swap_l_kernel ;
	void *  cu_swap_r_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->cu_swap_r_kernel ;
	void *  move_back_kernel_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->move_back_kernel_kernel ;
	double  Mass = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->Mass ;
	double  Charge = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->Charge ;
	double  Number_particle_per_marker = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->Number_particle_per_marker ;
	long  grid_cache_len = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->grid_cache_len ;
	long  cu_cache_length = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->cu_cache_length ;
	void *  split_pass_x_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_x_kernel ;
	void *  split_pass_y_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_y_kernel ;
	void *  split_pass_z_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_z_kernel ;
	void *  split_pass_x_nopush_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_x_nopush_kernel ;
	void *  split_pass_y_nopush_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_y_nopush_kernel ;
	void *  split_pass_z_nopush_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_z_nopush_kernel ;
	void *  split_pass_x_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_x_small_grids_kernel ;
	void *  split_pass_y_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_y_small_grids_kernel ;
	void *  split_pass_z_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_z_small_grids_kernel ;
	void *  split_pass_x_sg2_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_x_sg2_small_grids_kernel ;
	void *  split_pass_y_sg2_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_y_sg2_small_grids_kernel ;
	void *  split_pass_z_sg2_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_z_sg2_small_grids_kernel ;
	void *  split_pass_E_particle_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_E_particle_kernel ;
	void *  split_pass_x_vlo_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_x_vlo_kernel ;
	void *  split_pass_y_vlo_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_y_vlo_kernel ;
	void *  split_pass_z_vlo_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_z_vlo_kernel ;
	void *  split_pass_x_vlo_nopush_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_x_vlo_nopush_kernel ;
	void *  split_pass_y_vlo_nopush_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_y_vlo_nopush_kernel ;
	void *  split_pass_z_vlo_nopush_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_z_vlo_nopush_kernel ;
	void *  split_pass_x_vlo_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_x_vlo_small_grids_kernel ;
	void *  split_pass_y_vlo_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_y_vlo_small_grids_kernel ;
	void *  split_pass_z_vlo_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_z_vlo_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_x_vlo_sg2_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_y_vlo_sg2_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_z_vlo_sg2_small_grids_kernel ;
	void *  split_pass_x_vlo_sg2_nopush_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_x_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_y_vlo_sg2_nopush_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_y_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_z_vlo_sg2_nopush_small_grids_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_z_vlo_sg2_nopush_small_grids_kernel ;
	void *  split_pass_E_particle_vlo_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->split_pass_E_particle_vlo_kernel ;
	void *  dump_ene_num_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->dump_ene_num_kernel ;
	void *  calculate_rho_kernel = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->calculate_rho_kernel ;
	void *  inoutput = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->inoutput ;
	void *  xyzw = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->xyzw ;
	void *  cu_cache = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->cu_cache ;
	void *  cu_xyzw = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->cu_xyzw ;
	void *  adjoint_vec_pids = 	( 	(  particles + 	(  j + 	(  num_runtime * i ) ) ) )->adjoint_vec_pids ;
	double *  host_data = (((double * * )inoutput))[0] ;
	int *  xyzw_data = (((int * * )xyzw))[0] ;
	double *  cu_host_data = (((double * * )cu_cache))[0] ;
	int *  cu_xyzw_data = (((int * * )cu_xyzw))[0] ;
	long  alllenoff = 	(  xlen * 	(  ylen * zlen ) ) ;
{
	long  cur_pcid ;
	for ((cur_pcid = 0) ; 	(  cur_pcid < numvec ) ; (cur_pcid = 	(  cur_pcid + 1 )))
	{
	long  ofx = (global_x_offset)[cur_pcid] ;
	long  ofy = (global_y_offset)[cur_pcid] ;
	long  ofz = (global_z_offset)[cur_pcid] ;
	double *  grid_r_0 = 	(  host_data + 	(  cur_pcid * 	(  alllenoff * 	(  6 * grid_cache_len ) ) ) ) ;
	int *  xyzw_0 = 	(  xyzw_data + 	(  cur_pcid * 	(  alllenoff * 4 ) ) ) ;
{
	double *  cu_r_0 = 	(  cu_host_data + 	(  cur_pcid * 	(  6 * cu_cache_length ) ) ) ;
	int *  cu_xyzw_0 = 	(  cu_xyzw_data + 	(  cur_pcid * 4 ) ) ;
	long  ox = 	(  ofx / xlen ) ;
	long  oy = 	(  ofy / ylen ) ;
	long  oz = 	(  ofz / zlen ) ;
	long  offset_len = 	(  	(  (pdimarr_cu)[0] * 	(  ((reduce_x)?(0):(ox)) + 	(  ((reduce_x)?(1):((pdimarr_cu)[1])) * 	(  ((reduce_y)?(0):(oy)) + 	(  ((reduce_y)?(1):((pdimarr_cu)[2])) * ((reduce_z)?(0):(oz)) ) ) ) ) ) + c_offset ) ;
	double  num_load = (cu_xyzw_0)[0] ;
	GAPS_IO_DataSeek ( gid_cu , numt , offset_len );
	GAPS_IO_FRead ( gid_cu , 	& ( num_load ) , 1 );
((cu_xyzw_0)[0] = 	(  num_load * ((reduce_dim)?((pdimarr_grid)[reduce_dim]):(1)) ));
	assert ( 	(  num_load <= cu_cache_length ) );
	GAPS_IO_FRead ( gid_cu , cu_r_0 , 	(  6 * (cu_xyzw_0)[0] ) );
{
	long  g ;
	for ((g = 0) ; 	(  g < ((reduce_dim)?(num_load):(0)) ) ; (g = 	(  g + 1 )))
	{
((cu_r_0)[	(  reduce_dim + 	(  2 + 	(  g * 6 ) ) )] = 	(  r_r_r * (cu_r_0)[	(  reduce_dim + 	(  2 + 	(  g * 6 ) ) )] ));
}}{
	long  rd ;
	for ((rd = 1) ; 	(  rd < ((reduce_dim)?((pdimarr_grid)[reduce_dim]):(1)) ) ; (rd = 	(  rd + 1 )))
	{
{
	long  g ;
	for ((g = 0) ; 	(  g < num_load ) ; (g = 	(  g + 1 )))
	{
{
	long  s ;
	for ((s = 0) ; 	(  s < 6 ) ; (s = 	(  s + 1 )))
	{
((cu_r_0)[	(  s + 	(  	(  g * 6 ) + 	(  rd * 	(  ((int )num_load) * 6 ) ) ) )] = (cu_r_0)[	(  s + 	(  g * 6 ) )]);
}}((cu_r_0)[	(  	(  reduce_dim - 1 ) + 	(  	(  g * 6 ) + 	(  rd * 	(  ((int )num_load) * 6 ) ) ) )] = 	(  (cu_r_0)[	(  	(  reduce_dim - 1 ) + 	(  	(  g * 6 ) + 	(  rd * 	(  ((int )num_load) * 6 ) ) ) )] + rd ));
}}}}}{
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
	long  ox = 	(  ofx + xyzx ) ;
	long  oy = 	(  ofy + xyzy ) ;
	long  oz = 	(  ofz + xyzz ) ;
	long  offset_len = 	(  	(  (pdimarr_grid)[0] * 	(  ((reduce_x)?(0):(ox)) + 	(  ((reduce_x)?(1):((pdimarr_grid)[1])) * 	(  ((reduce_y)?(0):(oy)) + 	(  ((reduce_y)?(1):((pdimarr_grid)[2])) * ((reduce_z)?(0):(oz)) ) ) ) ) ) + g_offset ) ;
	int64_t  offset_xyzlen = ((	(  reduce_dim == 1 ))?(xyzx):(((	(  reduce_dim == 2 ))?(xyzy):(((	(  reduce_dim == 3 ))?(xyzz):(0)))))) ;
	GAPS_IO_DataSeek ( gid_grid , numt , offset_len );
	double  num_load = (grid_xyzw)[0] ;
	GAPS_IO_FRead ( gid_grid , 	& ( num_load ) , 1 );
((grid_xyzw)[0] = num_load);
	assert ( 	(  num_load <= grid_cache_len ) );
	GAPS_IO_FRead ( gid_grid , grid_r , 	(  6 * (grid_xyzw)[0] ) );
{
	long  g ;
	for ((g = 0) ; 	(  g < ((reduce_dim)?(num_load):(0)) ) ; (g = 	(  g + 1 )))
	{
((grid_r)[	(  	(  g * 6 ) + 	(  reduce_dim + 2 ) )] = 	(  r_r_r * (grid_r)[	(  reduce_dim + 	(  2 + 	(  g * 6 ) ) )] ));
((grid_r)[	(  	(  g * 6 ) + 	(  reduce_dim + -1 ) )] = 	(  (grid_r)[	(  	(  g * 6 ) + 	(  reduce_dim + -1 ) )] + offset_xyzlen ));
}}}}}}}}}}	if (  	(  0 == CD_type )  ){  
			c_pscmc_mem_sync_h2d ( cu_cache );

	}else{
			if (  	(  1 == CD_type )  ){  
			openmp_pscmc_mem_sync_h2d ( cu_cache );

	}else{
		0;

	 }

	 }
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
}}(g_offset = 	(  g_offset + 	(  	(  6 * ((use_non_nui_cache)?((pgcache)[i]):(grid_one_cache_len)) ) + 1 ) ));
(c_offset = 	(  c_offset + 	(  	(  6 * ((use_non_nui_cache)?((pcucache)[i]):(cu_one_cache_len)) ) + 1 ) ));
}}	return  0 ;}
int  init_parallel_file_for_mpi_fields_V0 (Field3D_MPI *  pthis ,Gaps_IO_DataFile *  gid ,char *  pName ,int64_t  time_step ){
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
	int64_t   pdimarr  [4];{
	void *  pe = 	( data )->pe ;
	long  xlen = 	( data )->xlen ;
	long  ylen = 	( data )->ylen ;
	long  zlen = 	( data )->zlen ;
	long  xblock = 	( data )->xblock ;
	long  yblock = 	( data )->yblock ;
	long  zblock = 	( data )->zblock ;
	long  numvec = 	( data )->numvec ;
	long  x_num_thread_block = 	( data )->x_num_thread_block ;
	long  y_num_thread_block = 	( data )->y_num_thread_block ;
	long  z_num_thread_block = 	( data )->z_num_thread_block ;
	int  ovlp = 	( data )->ovlp ;
	int  num_ele = 	( data )->num_ele ;
	int  CD_type = 	( data )->CD_type ;
	void * *  sync_layer_pscmc = 	( data )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( data )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( data )->sync_kernels ;
	void * *  fdtd_kernels = 	( data )->fdtd_kernels ;
	void * *  dm_kernels = 	( data )->dm_kernels ;
	void * *  dmbihamt_kernels = 	( data )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( data )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( data )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( data )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( data )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( data )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( data )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( data )->yee_setfix_kernels ;
	void *  rdcd = 	( data )->rdcd ;
	double *  rdcd_host = 	( data )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( data )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( data )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( data )->cur_rankz_pscmc ;
	void *  xoffset = 	( data )->xoffset ;
	void *  yoffset = 	( data )->yoffset ;
	void *  zoffset = 	( data )->zoffset ;
	long *  global_x_offset = 	( data )->global_x_offset ;
	long *  global_y_offset = 	( data )->global_y_offset ;
	long *  global_z_offset = 	( data )->global_z_offset ;
	long *  global_id = 	( data )->global_id ;
	long  global_pid = 	( data )->global_pid ;
	long *  adj_ids = 	( data )->adj_ids ;
	long *  adj_processes = 	( data )->adj_processes ;
	long *  adj_local_tid = 	( data )->adj_local_tid ;
	void *  main_data = 	( data )->main_data ;
	double  delta_x = 	( data )->delta_x ;
	double  delta_y = 	( data )->delta_y ;
	double  delta_z = 	( data )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( data )->blas_yiszero_synced_kernel ;
	void *  blas_mulxy_numele3_kernel = 	( data )->blas_mulxy_numele3_kernel ;
	void *  blas_yiszero_kernel = 	( data )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( data )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( data )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( data )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( data )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( data )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( data )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( data )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( data )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( data )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( data )->blas_sum_kernel ;
((pdimarr)[0] = num_ele);
((pdimarr)[1] = 	(  xlen * x_num_thread_block ));
((pdimarr)[2] = 	(  ylen * y_num_thread_block ));
((pdimarr)[3] = 	(  zlen * z_num_thread_block ));
}	GAPS_IO_InitDataInfo ( gid , GAPS_IO_FLOAT64 , 4 , pdimarr );
	GAPS_IO_InitOFile_with_TimeStep ( gid , pName , time_step );
	GAPS_IO_FileFlush ( gid );
	PS_MPI_Barrier ( comm );
	return  0 ;}
int  init_parallel_file_for_mpi_fields (Field3D_MPI *  pthis ,Gaps_IO_DataFile *  gid ,char *  pName ,int64_t  time_step ,int  version ,int  num_reduce_proc ){
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
	int64_t   pdimarr  [4];	int64_t   pblkarr  [4];	if (  	(  version == 0 )  ){  
		{
	void *  pe = 	( data )->pe ;
	long  xlen = 	( data )->xlen ;
	long  ylen = 	( data )->ylen ;
	long  zlen = 	( data )->zlen ;
	long  xblock = 	( data )->xblock ;
	long  yblock = 	( data )->yblock ;
	long  zblock = 	( data )->zblock ;
	long  numvec = 	( data )->numvec ;
	long  x_num_thread_block = 	( data )->x_num_thread_block ;
	long  y_num_thread_block = 	( data )->y_num_thread_block ;
	long  z_num_thread_block = 	( data )->z_num_thread_block ;
	int  ovlp = 	( data )->ovlp ;
	int  num_ele = 	( data )->num_ele ;
	int  CD_type = 	( data )->CD_type ;
	void * *  sync_layer_pscmc = 	( data )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( data )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( data )->sync_kernels ;
	void * *  fdtd_kernels = 	( data )->fdtd_kernels ;
	void * *  dm_kernels = 	( data )->dm_kernels ;
	void * *  dmbihamt_kernels = 	( data )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( data )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( data )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( data )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( data )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( data )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( data )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( data )->yee_setfix_kernels ;
	void *  rdcd = 	( data )->rdcd ;
	double *  rdcd_host = 	( data )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( data )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( data )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( data )->cur_rankz_pscmc ;
	void *  xoffset = 	( data )->xoffset ;
	void *  yoffset = 	( data )->yoffset ;
	void *  zoffset = 	( data )->zoffset ;
	long *  global_x_offset = 	( data )->global_x_offset ;
	long *  global_y_offset = 	( data )->global_y_offset ;
	long *  global_z_offset = 	( data )->global_z_offset ;
	long *  global_id = 	( data )->global_id ;
	long  global_pid = 	( data )->global_pid ;
	long *  adj_ids = 	( data )->adj_ids ;
	long *  adj_processes = 	( data )->adj_processes ;
	long *  adj_local_tid = 	( data )->adj_local_tid ;
	void *  main_data = 	( data )->main_data ;
	double  delta_x = 	( data )->delta_x ;
	double  delta_y = 	( data )->delta_y ;
	double  delta_z = 	( data )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( data )->blas_yiszero_synced_kernel ;
	void *  blas_mulxy_numele3_kernel = 	( data )->blas_mulxy_numele3_kernel ;
	void *  blas_yiszero_kernel = 	( data )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( data )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( data )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( data )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( data )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( data )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( data )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( data )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( data )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( data )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( data )->blas_sum_kernel ;
((pdimarr)[0] = num_ele);
((pdimarr)[1] = 	(  xlen * x_num_thread_block ));
((pdimarr)[2] = 	(  ylen * y_num_thread_block ));
((pdimarr)[3] = 	(  zlen * z_num_thread_block ));
	GAPS_IO_InitDataInfo ( gid , GAPS_IO_FLOAT64 , 4 , pdimarr );
}
	}else{
		{
	void *  pe = 	( data )->pe ;
	long  xlen = 	( data )->xlen ;
	long  ylen = 	( data )->ylen ;
	long  zlen = 	( data )->zlen ;
	long  xblock = 	( data )->xblock ;
	long  yblock = 	( data )->yblock ;
	long  zblock = 	( data )->zblock ;
	long  numvec = 	( data )->numvec ;
	long  x_num_thread_block = 	( data )->x_num_thread_block ;
	long  y_num_thread_block = 	( data )->y_num_thread_block ;
	long  z_num_thread_block = 	( data )->z_num_thread_block ;
	int  ovlp = 	( data )->ovlp ;
	int  num_ele = 	( data )->num_ele ;
	int  CD_type = 	( data )->CD_type ;
	void * *  sync_layer_pscmc = 	( data )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( data )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( data )->sync_kernels ;
	void * *  fdtd_kernels = 	( data )->fdtd_kernels ;
	void * *  dm_kernels = 	( data )->dm_kernels ;
	void * *  dmbihamt_kernels = 	( data )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( data )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( data )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( data )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( data )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( data )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( data )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( data )->yee_setfix_kernels ;
	void *  rdcd = 	( data )->rdcd ;
	double *  rdcd_host = 	( data )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( data )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( data )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( data )->cur_rankz_pscmc ;
	void *  xoffset = 	( data )->xoffset ;
	void *  yoffset = 	( data )->yoffset ;
	void *  zoffset = 	( data )->zoffset ;
	long *  global_x_offset = 	( data )->global_x_offset ;
	long *  global_y_offset = 	( data )->global_y_offset ;
	long *  global_z_offset = 	( data )->global_z_offset ;
	long *  global_id = 	( data )->global_id ;
	long  global_pid = 	( data )->global_pid ;
	long *  adj_ids = 	( data )->adj_ids ;
	long *  adj_processes = 	( data )->adj_processes ;
	long *  adj_local_tid = 	( data )->adj_local_tid ;
	void *  main_data = 	( data )->main_data ;
	double  delta_x = 	( data )->delta_x ;
	double  delta_y = 	( data )->delta_y ;
	double  delta_z = 	( data )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( data )->blas_yiszero_synced_kernel ;
	void *  blas_mulxy_numele3_kernel = 	( data )->blas_mulxy_numele3_kernel ;
	void *  blas_yiszero_kernel = 	( data )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( data )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( data )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( data )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( data )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( data )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( data )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( data )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( data )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( data )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( data )->blas_sum_kernel ;
((pdimarr)[0] = num_ele);
((pdimarr)[1] = xlen);
((pdimarr)[2] = ylen);
((pdimarr)[3] = zlen);
((pblkarr)[0] = 1);
((pblkarr)[1] = x_num_thread_block);
((pblkarr)[2] = y_num_thread_block);
((pblkarr)[3] = z_num_thread_block);
	if (  	(  version == 1 )  ){  
			GAPS_IO_InitDataInfoV1 ( gid , GAPS_IO_FLOAT64 , 4 , pdimarr , pblkarr );

	}else{
			if (  	(  version == 2 )  ){  
			int64_t *  plocations = 	malloc ( 	(  sizeof(int64_t ) * numvec ) ) ;
{
	long  i ;
	for ((i = 0) ; 	(  i < numvec ) ; (i = 	(  i + 1 )))
	{
((plocations)[i] = 	(  	(  (global_x_offset)[i] / xlen ) + 	(  x_num_thread_block * 	(  	(  (global_y_offset)[i] / ylen ) + 	(  y_num_thread_block * 	(  (global_z_offset)[i] / zlen ) ) ) ) ));
}}	GAPS_IO_InitDataInfoV2 ( gid , "" , GAPS_IO_FLOAT64 , 4 , pdimarr , pblkarr , plocations , numvec , 0 );
	if (  num_reduce_proc  ){  
			GAPS_IO_SetNumReduceProc ( gid , num_reduce_proc );

	}else{
		0;

	 }
	free ( plocations );

	}else{
		0;

	 }

	 }
}
	 }
	if (  	(  version >= 2 )  ){  
			GAPS_IO_InitOFile_with_TimeStepV2 ( gid , pName , 	( gid )->prefix , time_step );

	}else{
			GAPS_IO_InitOFile_with_TimeStep ( gid , pName , time_step );

	 }
	GAPS_IO_FileFlush ( gid );
	PS_MPI_Barrier ( comm );
	return  0 ;}
int  read_parallel_file_for_mpi_fields (Field3D_MPI *  pthis ,Gaps_IO_DataFile *  gid ,int64_t  timestep ){
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
	void * *  dmbihamt_kernels = 	( 	(  data + i ) )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  data + i ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  data + i ) )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( 	(  data + i ) )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( 	(  data + i ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  data + i ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  data + i ) )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( 	(  data + i ) )->yee_setfix_kernels ;
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
	void *  blas_mulxy_numele3_kernel = 	( 	(  data + i ) )->blas_mulxy_numele3_kernel ;
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
	double *  odata = (((double * * )main_data))[0] ;
	size_t  oneblocklen = 	(  xblock * 	(  yblock * 	(  zblock * num_ele ) ) ) ;
	size_t  realoneblklen = 	(  xlen * 	(  ylen * 	(  zlen * num_ele ) ) ) ;
	double *  write_buffer = 	malloc ( 	(  sizeof(double ) * realoneblklen ) ) ;
	long  vid = 0 ;
	for (vid=0 ; 	(  vid < numvec ) ; vid++)
	{
	if (  	(  	( gid )->version == 0 )  ){  
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
	int64_t  offsetlen = 	(  num_ele * 	(  (global_x_offset)[vid] + 	(  0 + 	(  xlen * 	(  x_num_thread_block * 	(  xyzy + 	(  (global_y_offset)[vid] + 	(  ylen * 	(  y_num_thread_block * 	(  xyzz + (global_z_offset)[vid] ) ) ) ) ) ) ) ) ) ) ;
	GAPS_IO_DataSeek ( gid , timestep , offsetlen );
	GAPS_IO_FRead ( gid , 	(  odata + 	(  	(  oneblocklen * vid ) + 	(  num_ele * 	(  ovlp + 	(  xblock * 	(  xyzy + 	(  ovlp + 	(  yblock * 	(  ovlp + xyzz ) ) ) ) ) ) ) ) ) , 	(  num_ele * xlen ) );
}}}}}}
	}else{
			int64_t  offsetlen = 	(  realoneblklen * ((	(  	( gid )->version == 1 ))?(	(  	(  (global_x_offset)[vid] / xlen ) + 	(  x_num_thread_block * 	(  	(  (global_y_offset)[vid] / ylen ) + 	(  y_num_thread_block * 	(  (global_z_offset)[vid] / zlen ) ) ) ) )):(vid)) ) ;
	GAPS_IO_DataSeek ( gid , timestep , offsetlen );
	GAPS_IO_FRead ( gid , write_buffer , realoneblklen );
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
{
	long  l ;
	for ((l = 0) ; 	(  l < num_ele ) ; (l = 	(  l + 1 )))
	{
((write_buffer)[	(  l + 	(  num_ele * 	(  xyzx + 	(  xlen * 	(  xyzy + 	(  ylen * xyzz ) ) ) ) ) )] = (odata)[	(  	(  oneblocklen * vid ) + 	(  l + 	(  num_ele * 	(  xyzx + 	(  ovlp + 	(  xblock * 	(  xyzy + 	(  ovlp + 	(  yblock * 	(  ovlp + xyzz ) ) ) ) ) ) ) ) ) )]);
}}}}}}}}
	 }
}	free ( write_buffer );
}	return  0 ;}
int  write_parallel_file_for_mpi_fields (Field3D_MPI *  pthis ,Gaps_IO_DataFile *  gid ,int64_t  timestep ){
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
	void * *  dmbihamt_kernels = 	( 	(  data + i ) )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	(  data + i ) )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	(  data + i ) )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( 	(  data + i ) )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( 	(  data + i ) )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	(  data + i ) )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	(  data + i ) )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( 	(  data + i ) )->yee_setfix_kernels ;
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
	void *  blas_mulxy_numele3_kernel = 	( 	(  data + i ) )->blas_mulxy_numele3_kernel ;
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
	double *  odata = (((double * * )main_data))[0] ;
	size_t  oneblocklen = 	(  xblock * 	(  yblock * 	(  zblock * num_ele ) ) ) ;
	size_t  realoneblklen = 	(  xlen * 	(  ylen * 	(  zlen * num_ele ) ) ) ;
	double *  write_buffer = 	malloc ( 	(  sizeof(double ) * realoneblklen ) ) ;
	long  vid = 0 ;
	if (  	(  	( gid )->version == 2 )  ){  
			GAPS_IO_DataSeek ( gid , timestep , 0 );
	if (  	(  	(  cur_rank != 	( gid )->send_to_proc ) && 	( gid )->num_reduce_proc )  ){  
			MPI_Send ( 	& ( numvec ) , 1 , PS_MPI_LONG , 	( gid )->send_to_proc , cur_rank , PS_MPI_COMM_WORLD );

	}else{
		0;

	 }

	}else{
		0;

	 }
	for (vid=0 ; 	(  vid < numvec ) ; vid++)
	{
	if (  	(  	( gid )->version == 0 )  ){  
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
	int64_t  offsetlen = 	(  num_ele * 	(  (global_x_offset)[vid] + 	(  0 + 	(  xlen * 	(  x_num_thread_block * 	(  xyzy + 	(  (global_y_offset)[vid] + 	(  ylen * 	(  y_num_thread_block * 	(  xyzz + (global_z_offset)[vid] ) ) ) ) ) ) ) ) ) ) ;
	GAPS_IO_DataSeek ( gid , timestep , offsetlen );
	GAPS_IO_FWrite ( gid , 	(  odata + 	(  	(  oneblocklen * vid ) + 	(  num_ele * 	(  ovlp + 	(  xblock * 	(  xyzy + 	(  ovlp + 	(  yblock * 	(  ovlp + xyzz ) ) ) ) ) ) ) ) ) , 	(  num_ele * xlen ) );
}}}}}}
	}else{
			int64_t  offsetlen = ((	(  	( gid )->version == 1 ))?(	(  realoneblklen * 	(  	(  (global_x_offset)[vid] / xlen ) + 	(  x_num_thread_block * 	(  	(  (global_y_offset)[vid] / ylen ) + 	(  y_num_thread_block * 	(  (global_z_offset)[vid] / zlen ) ) ) ) ) )):(	(  realoneblklen * vid ))) ;
	if (  	(  	( gid )->version == 1 )  ){  
			GAPS_IO_DataSeek ( gid , timestep , offsetlen );

	}else{
		0;

	 }
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
{
	long  l ;
	for ((l = 0) ; 	(  l < num_ele ) ; (l = 	(  l + 1 )))
	{
((write_buffer)[	(  l + 	(  num_ele * 	(  xyzx + 	(  xlen * 	(  xyzy + 	(  ylen * xyzz ) ) ) ) ) )] = (odata)[	(  	(  oneblocklen * vid ) + 	(  l + 	(  num_ele * 	(  xyzx + 	(  ovlp + 	(  xblock * 	(  xyzy + 	(  ovlp + 	(  yblock * 	(  ovlp + xyzz ) ) ) ) ) ) ) ) ) )]);
}}}}}}}}	GAPS_IO_FWrite ( gid , write_buffer , realoneblklen );
	if (  	(  	(  	( gid )->version == 2 ) && 	( gid )->num_reduce_proc )  ){  
			int  cur_rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( cur_rank ) );
	if (  	(  	( gid )->cur_rank != 	( gid )->send_to_proc )  ){  
			PS_MPI_Send ( write_buffer , realoneblklen , PS_MPI_DOUBLE , 	( gid )->send_to_proc , cur_rank , PS_MPI_COMM_WORLD );

	}else{
		0;

	 }

	}else{
		0;

	 }

	 }
}	if (  	(  	(  	( gid )->version == 2 ) && 	( gid )->num_reduce_proc )  ){  
			int  cur_rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( cur_rank ) );
	if (  	(  	( gid )->cur_rank != 	( gid )->send_to_proc )  ){  
		0;

	}else{
		{
	int  cur_rank = 	( gid )->cur_rank ;
	int  num_reduce_proc = 	( gid )->num_reduce_proc ;
	int  real_rank = 	( gid )->real_rank ;
{
	long  n ;
	for ((n = 	(  cur_rank + 1 )) ; 	(  n < 	(  num_reduce_proc * 	(  real_rank + 1 ) ) ) ; (n = 	(  n + 1 )))
	{
	int  num_proc ;
	PS_MPI_Comm_size ( PS_MPI_COMM_WORLD , 	& ( num_proc ) );
	if (  	(  n >= num_proc )  ){  
		break;

	}else{
		0;

	 }
	long  remote_numvec ;
	MPI_Status  s1 ;
	PS_MPI_Recv ( 	& ( remote_numvec ) , 1 , PS_MPI_LONG , n , n , PS_MPI_COMM_WORLD , 	& ( s1 ) );
{
	long  g ;
	for ((g = 0) ; 	(  g < remote_numvec ) ; (g = 	(  g + 1 )))
	{
	PS_MPI_Recv ( write_buffer , realoneblklen , PS_MPI_DOUBLE , n , n , PS_MPI_COMM_WORLD , 	& ( s1 ) );
	GAPS_IO_FWrite ( gid , write_buffer , realoneblklen );
}}}}}
	 }

	}else{
		0;

	 }
	free ( write_buffer );
}	return  0 ;}
int  mpi_field_2_outfile (Field3D_MPI *  pthis ,char *  fname ){
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
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	init_parallel_file_for_mpi_fields ( pthis , pgid , fname , -1 , 0 , 0 );
	GAPS_IO_TruncateFile ( pgid , 1 , -1 );
	PS_MPI_Barrier ( comm );
	write_parallel_file_for_mpi_fields ( pthis , pgid , 0 );
	GAPS_IO_DeleteDataInfo ( pgid );
	return  0 ;}
int  mpi_field_write_to_file (Field3D_MPI *  pthis ,Gaps_IO_DataFile *  pgid ,long  num_timestep ){
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
	int64_t  res ;
	PS_MPI_Barrier ( comm );
	GAPS_IO_TruncateFile ( pgid , 	(  num_timestep + 1 ) , -1 );
	PS_MPI_Barrier ( comm );
	GAPS_IO_DataSeek ( pgid , num_timestep , 0 );
	write_parallel_file_for_mpi_fields ( pthis , pgid , num_timestep );
	return  0 ;}
