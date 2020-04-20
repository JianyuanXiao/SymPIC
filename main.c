#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <time.h>
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
#include "mpifields.h"
#include "dmshell.h"
#include "hydroAshell.h"
#include "init_field3d_mpi.h"
#include <cgapsio.h>
#include "mpi_fieldio.h"
#include "call_curl_kernel.h"
#include "init_particle.h"
#include "run_particle.h"
#include "pass_xyzzyx.h"
#include "sort_particle.h"
#include "seqfields.h"
#include "init_adjoint_relation.h"
#include "init_implicit_particle.h"
#include "split_shell.h"
#include "blas_shell.h"
#include "nonlinear_jfnk.h"
#include "cfgcst.h"
typedef Field3D_MPI  Field3D_MPI_ALL ;
#include "checkpoint.h"
#include <sys/time.h>
int  print_max (Field3D_MPI *  in ){
	double  tmp0 = 	blas_sum_Field3D_MPI ( in , in ) ;
	fprintf ( stderr , "ext max=%e\n" , tmp0 );
	return  0 ;}
double  wclk_now (){
	struct timeval  tv1 ;
	struct timezone  tz1 ;
	gettimeofday ( 	& ( tv1 ) , 	& ( tz1 ) );
	double  time_start1 = 	(  ((double )tv1.tv_sec) + 	(  9.99999999999999955e-07 * ((double )tv1.tv_usec) ) ) ;
	return  time_start1 ;}
double  gen_sts_dt (int  j ,int  nt ,double  nv ){
	return  	(  1 / 	(  	(  	(  	(  	(  -1 * 1 ) + nv ) * 	cos ( 	(  	(  	(  	(  	(  2 * j ) - 1.00000000000000000e+00 ) / nt ) * M_PI ) / 2 ) ) ) + 1 ) + nv ) ) ;}
	Gaps_IO_DataFile *  pTEMPERATURE_DIST_gid_global_var = NULL ;
	double   TEMPERATURE_DIST_gid_cache_var  [64];	long  TEMPERATURE_DIST_gid_cache_pos = -1 ;
double  TEMPERATURE_DIST_global_procedure (long  cursp ,double  z ,double  y ,double  x ,long  l ){
	if (  pTEMPERATURE_DIST_gid_global_var  ){  
			long *  pdimarray = 	( pTEMPERATURE_DIST_gid_global_var )->pdimarray ;
	long  current_cache_pos = 	(  ((long )l) + 	(  (pdimarray)[0] * 	(  ((long )x) + 	(  (pdimarray)[1] * 	(  ((long )y) + 	(  (pdimarray)[2] * 	(  ((long )z) + 	(  (pdimarray)[3] * 	(  ((long )cursp) + 	(  (pdimarray)[4] * 0 ) ) ) ) ) ) ) ) ) ) ;
	long  offset_pos = 	(  current_cache_pos - TEMPERATURE_DIST_gid_cache_pos ) ;
	if (  	(  	(  TEMPERATURE_DIST_gid_cache_pos == -1 ) || 	(  	(  offset_pos < 0 ) || 	(  offset_pos >= 64 ) ) )  ){  
			GAPS_IO_DataSeek ( pTEMPERATURE_DIST_gid_global_var , 0 , current_cache_pos );
	GAPS_IO_FRead ( pTEMPERATURE_DIST_gid_global_var , TEMPERATURE_DIST_gid_cache_var , 64 );
(TEMPERATURE_DIST_gid_cache_pos = current_cache_pos);
	return  (TEMPERATURE_DIST_gid_cache_var)[0] ;
	}else{
			return  (TEMPERATURE_DIST_gid_cache_var)[offset_pos] ;
	 }

	}else{
			return  0 ;
	 }
}
	Gaps_IO_DataFile *  pDENSITY_DIST_gid_global_var = NULL ;
	double   DENSITY_DIST_gid_cache_var  [64];	long  DENSITY_DIST_gid_cache_pos = -1 ;
double  DENSITY_DIST_global_procedure (long  cursp ,double  z ,double  y ,double  x ){
	if (  pDENSITY_DIST_gid_global_var  ){  
			long *  pdimarray = 	( pDENSITY_DIST_gid_global_var )->pdimarray ;
	long  current_cache_pos = 	(  ((long )x) + 	(  (pdimarray)[0] * 	(  ((long )y) + 	(  (pdimarray)[1] * 	(  ((long )z) + 	(  (pdimarray)[2] * 	(  ((long )cursp) + 	(  (pdimarray)[3] * 0 ) ) ) ) ) ) ) ) ;
	long  offset_pos = 	(  current_cache_pos - DENSITY_DIST_gid_cache_pos ) ;
	if (  	(  	(  DENSITY_DIST_gid_cache_pos == -1 ) || 	(  	(  offset_pos < 0 ) || 	(  offset_pos >= 64 ) ) )  ){  
			GAPS_IO_DataSeek ( pDENSITY_DIST_gid_global_var , 0 , current_cache_pos );
	GAPS_IO_FRead ( pDENSITY_DIST_gid_global_var , DENSITY_DIST_gid_cache_var , 64 );
(DENSITY_DIST_gid_cache_pos = current_cache_pos);
	return  (DENSITY_DIST_gid_cache_var)[0] ;
	}else{
			return  (DENSITY_DIST_gid_cache_var)[offset_pos] ;
	 }

	}else{
			return  0 ;
	 }
}
	Gaps_IO_DataFile *  pV0_x_gid_global_var = NULL ;
	double   V0_x_gid_cache_var  [64];	long  V0_x_gid_cache_pos = -1 ;
double  V0_x_global_procedure (long  cursp ,double  z ,double  y ,double  x ){
	if (  pV0_x_gid_global_var  ){  
			long *  pdimarray = 	( pV0_x_gid_global_var )->pdimarray ;
	long  current_cache_pos = 	(  ((long )x) + 	(  (pdimarray)[0] * 	(  ((long )y) + 	(  (pdimarray)[1] * 	(  ((long )z) + 	(  (pdimarray)[2] * 	(  ((long )cursp) + 	(  (pdimarray)[3] * 0 ) ) ) ) ) ) ) ) ;
	long  offset_pos = 	(  current_cache_pos - V0_x_gid_cache_pos ) ;
	if (  	(  	(  V0_x_gid_cache_pos == -1 ) || 	(  	(  offset_pos < 0 ) || 	(  offset_pos >= 64 ) ) )  ){  
			GAPS_IO_DataSeek ( pV0_x_gid_global_var , 0 , current_cache_pos );
	GAPS_IO_FRead ( pV0_x_gid_global_var , V0_x_gid_cache_var , 64 );
(V0_x_gid_cache_pos = current_cache_pos);
	return  (V0_x_gid_cache_var)[0] ;
	}else{
			return  (V0_x_gid_cache_var)[offset_pos] ;
	 }

	}else{
			return  0 ;
	 }
}
	Gaps_IO_DataFile *  pV0_y_gid_global_var = NULL ;
	double   V0_y_gid_cache_var  [64];	long  V0_y_gid_cache_pos = -1 ;
double  V0_y_global_procedure (long  cursp ,double  z ,double  y ,double  x ){
	if (  pV0_y_gid_global_var  ){  
			long *  pdimarray = 	( pV0_y_gid_global_var )->pdimarray ;
	long  current_cache_pos = 	(  ((long )x) + 	(  (pdimarray)[0] * 	(  ((long )y) + 	(  (pdimarray)[1] * 	(  ((long )z) + 	(  (pdimarray)[2] * 	(  ((long )cursp) + 	(  (pdimarray)[3] * 0 ) ) ) ) ) ) ) ) ;
	long  offset_pos = 	(  current_cache_pos - V0_y_gid_cache_pos ) ;
	if (  	(  	(  V0_y_gid_cache_pos == -1 ) || 	(  	(  offset_pos < 0 ) || 	(  offset_pos >= 64 ) ) )  ){  
			GAPS_IO_DataSeek ( pV0_y_gid_global_var , 0 , current_cache_pos );
	GAPS_IO_FRead ( pV0_y_gid_global_var , V0_y_gid_cache_var , 64 );
(V0_y_gid_cache_pos = current_cache_pos);
	return  (V0_y_gid_cache_var)[0] ;
	}else{
			return  (V0_y_gid_cache_var)[offset_pos] ;
	 }

	}else{
			return  0 ;
	 }
}
	Gaps_IO_DataFile *  pV0_z_gid_global_var = NULL ;
	double   V0_z_gid_cache_var  [64];	long  V0_z_gid_cache_pos = -1 ;
double  V0_z_global_procedure (long  cursp ,double  z ,double  y ,double  x ){
	if (  pV0_z_gid_global_var  ){  
			long *  pdimarray = 	( pV0_z_gid_global_var )->pdimarray ;
	long  current_cache_pos = 	(  ((long )x) + 	(  (pdimarray)[0] * 	(  ((long )y) + 	(  (pdimarray)[1] * 	(  ((long )z) + 	(  (pdimarray)[2] * 	(  ((long )cursp) + 	(  (pdimarray)[3] * 0 ) ) ) ) ) ) ) ) ;
	long  offset_pos = 	(  current_cache_pos - V0_z_gid_cache_pos ) ;
	if (  	(  	(  V0_z_gid_cache_pos == -1 ) || 	(  	(  offset_pos < 0 ) || 	(  offset_pos >= 64 ) ) )  ){  
			GAPS_IO_DataSeek ( pV0_z_gid_global_var , 0 , current_cache_pos );
	GAPS_IO_FRead ( pV0_z_gid_global_var , V0_z_gid_cache_var , 64 );
(V0_z_gid_cache_pos = current_cache_pos);
	return  (V0_z_gid_cache_var)[0] ;
	}else{
			return  (V0_z_gid_cache_var)[offset_pos] ;
	 }

	}else{
			return  0 ;
	 }
}
typedef struct { 	Field3D_MPI *  pA0 ;
	Field3D_MPI *  pA1 ;
	Field3D_MPI *  pA2 ;
	Field3D_MPI *  pF0 ;
	double  Q ;
	double  M ;
	double  DT ;
	double  DM_A ;
	double  DX ;
	double  DY ;
	double  DZ ;
} dm_fv;typedef struct { 	Field3D_MPI *  palpha_beta1 ;
	Field3D_MPI *  prho_s_vx ;
	Field3D_MPI *  pvA1 ;
	double  dt ;
	double  dx ;
	double  dy ;
	double  dz ;
	double  u0 ;
	double  qm0 ;
} hydro_fv;int  hydro_bicg_fun (Field3D_MPI *  out ,Field3D_MPI *  in ,hydro_fv *  fv ){
	sync_ovlp_mpi_field ( in );
	MPI_hydro_push_jac_alpha_beta ( out , in , fv->palpha_beta1 , fv->prho_s_vx , fv->pvA1 , fv->pvA1 , fv->dt , fv->dx , fv->dy , fv->dz , fv->u0 , fv->qm0 );
	if (  0  ){  
		{
	void *  pe = 	( out->data )->pe ;
	long  xlen = 	( out->data )->xlen ;
	long  ylen = 	( out->data )->ylen ;
	long  zlen = 	( out->data )->zlen ;
	long  xblock = 	( out->data )->xblock ;
	long  yblock = 	( out->data )->yblock ;
	long  zblock = 	( out->data )->zblock ;
	long  numvec = 	( out->data )->numvec ;
	long  x_num_thread_block = 	( out->data )->x_num_thread_block ;
	long  y_num_thread_block = 	( out->data )->y_num_thread_block ;
	long  z_num_thread_block = 	( out->data )->z_num_thread_block ;
	int  ovlp = 	( out->data )->ovlp ;
	int  num_ele = 	( out->data )->num_ele ;
	int  CD_type = 	( out->data )->CD_type ;
	void * *  sync_layer_pscmc = 	( out->data )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( out->data )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( out->data )->sync_kernels ;
	void * *  fdtd_kernels = 	( out->data )->fdtd_kernels ;
	void * *  dm_kernels = 	( out->data )->dm_kernels ;
	void * *  dmbihamt_kernels = 	( out->data )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( out->data )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( out->data )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( out->data )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( out->data )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( out->data )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( out->data )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( out->data )->yee_setfix_kernels ;
	void *  rdcd = 	( out->data )->rdcd ;
	double *  rdcd_host = 	( out->data )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( out->data )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( out->data )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( out->data )->cur_rankz_pscmc ;
	void *  xoffset = 	( out->data )->xoffset ;
	void *  yoffset = 	( out->data )->yoffset ;
	void *  zoffset = 	( out->data )->zoffset ;
	long *  global_x_offset = 	( out->data )->global_x_offset ;
	long *  global_y_offset = 	( out->data )->global_y_offset ;
	long *  global_z_offset = 	( out->data )->global_z_offset ;
	long *  global_id = 	( out->data )->global_id ;
	long  global_pid = 	( out->data )->global_pid ;
	long *  adj_ids = 	( out->data )->adj_ids ;
	long *  adj_processes = 	( out->data )->adj_processes ;
	long *  adj_local_tid = 	( out->data )->adj_local_tid ;
	void *  main_data = 	( out->data )->main_data ;
	double  delta_x = 	( out->data )->delta_x ;
	double  delta_y = 	( out->data )->delta_y ;
	double  delta_z = 	( out->data )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( out->data )->blas_yiszero_synced_kernel ;
	void *  blas_mulxy_numele3_kernel = 	( out->data )->blas_mulxy_numele3_kernel ;
	void *  blas_yiszero_kernel = 	( out->data )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( out->data )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( out->data )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( out->data )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( out->data )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( out->data )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( out->data )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( out->data )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( out->data )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( out->data )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( out->data )->blas_sum_kernel ;
{
	long  i ;
	for ((i = 0) ; 	(  i < 8 ) ; (i = 	(  i + 1 )))
	{
	fprintf ( stderr , "out%d=%e loc=0x%lx\n" , i , ((((double * * )	( out->data )->main_data))[0])[	(  	(  0 * 	(  	( out->data )->xblock * 	(  	( out->data )->yblock * 	(  	( out->data )->zblock * 	( out->data )->num_ele ) ) ) ) + 	(  0 + 	(  	( out->data )->num_ele * 	(  	(  i + 	( out->data )->ovlp ) + 	(  	( out->data )->xblock * 	(  	(  0 + 	( out->data )->ovlp ) + 	(  	( out->data )->yblock * 	(  0 + 	( out->data )->ovlp ) ) ) ) ) ) ) )] , 	& ( ((((double * * )	( out->data )->main_data))[0])[	(  	(  0 * 	(  	( out->data )->xblock * 	(  	( out->data )->yblock * 	(  	( out->data )->zblock * 	( out->data )->num_ele ) ) ) ) + 	(  0 + 	(  	( out->data )->num_ele * 	(  	(  i + 	( out->data )->ovlp ) + 	(  	( out->data )->xblock * 	(  	(  0 + 	( out->data )->ovlp ) + 	(  	( out->data )->yblock * 	(  0 + 	( out->data )->ovlp ) ) ) ) ) ) ) )] ) );
	fprintf ( stderr , "out%d=%e loc=0x%lx\n" , i , ((((double * * )	( out->data )->main_data))[0])[	(  	(  0 * 	(  	( out->data )->xblock * 	(  	( out->data )->yblock * 	(  	( out->data )->zblock * 	( out->data )->num_ele ) ) ) ) + 	(  1 + 	(  	( out->data )->num_ele * 	(  	(  i + 	( out->data )->ovlp ) + 	(  	( out->data )->xblock * 	(  	(  0 + 	( out->data )->ovlp ) + 	(  	( out->data )->yblock * 	(  0 + 	( out->data )->ovlp ) ) ) ) ) ) ) )] , 	& ( ((((double * * )	( out->data )->main_data))[0])[	(  	(  0 * 	(  	( out->data )->xblock * 	(  	( out->data )->yblock * 	(  	( out->data )->zblock * 	( out->data )->num_ele ) ) ) ) + 	(  1 + 	(  	( out->data )->num_ele * 	(  	(  i + 	( out->data )->ovlp ) + 	(  	( out->data )->xblock * 	(  	(  0 + 	( out->data )->ovlp ) + 	(  	( out->data )->yblock * 	(  0 + 	( out->data )->ovlp ) ) ) ) ) ) ) )] ) );
}}}
	}else{
		0;

	 }
	return  0 ;}
int  dm_bicg_fun (Field3D_MPI *  out ,Field3D_MPI *  in ,dm_fv *  fv ){
	sync_ovlp_mpi_field ( in );
	MPI_dm_1st_eqn_core ( out , in , fv->pF0 , fv->pA0 , fv->pA1 , fv->pA2 , fv->DM_A , fv->Q , fv->M , fv->DT );
	return  0 ;}
int  cayley_dm_new_fun_all (Field3D_MPI *  out ,Field3D_MPI *  in ,dm_fv *  fv ,double  lftrht ){
	sync_ovlp_mpi_field ( in );
	MPI_dm_cayley_eqn_core ( out , in , 	( fv )->pA0 , 	( fv )->pA1 , 	( fv )->DT , 	( fv )->DZ , 	( fv )->DY , 	( fv )->DX , 	( fv )->DM_A , 	( fv )->Q , 	( fv )->M );
	blas_axpby_Field3D_MPI ( out , out , 1 , in , 	(  lftrht * fv->DT ) );
	return  0 ;}
int  cayley_dm_new_fun (Field3D_MPI *  out ,Field3D_MPI *  in ,dm_fv *  fv ){
	return  	cayley_dm_new_fun_all ( out , in , fv , -5.00000000000000000e-01 ) ;}
int  cayley_dm_new_fun_right (Field3D_MPI *  out ,Field3D_MPI *  in ,dm_fv *  fv ){
	cayley_dm_new_fun_all ( out , in , fv , 5.00000000000000000e-01 );
	return  0 ;}
void  high_order_split_pic (void *  ppis ,double  dt ,int  l ){
	if (  	(  l < 0 )  ){  
			FDTD_2_2th_ALL_passes ( ppis , dt );

	}else{
			if (  	(  l == 0 )  ){  
			FDTD_2_4th_ALL_passes ( ppis , dt );

	}else{
			double  al = 	(  1.00000000000000000e+00 / 	(  2 - 	pow ( 2 , 	(  l / 3.00000000000000000e+00 ) ) ) ) ;
	double  bl = 	(  1 - 	(  2 * al ) ) ;
	double  adt = 	(  al * dt ) ;
	double  bdt = 	(  bl * dt ) ;
	high_order_split_pic ( ppis , adt , 	(  l - 1 ) );
	high_order_split_pic ( ppis , bdt , 	(  l - 1 ) );
	high_order_split_pic ( ppis , adt , 	(  l - 1 ) );

	 }

	 }
}
	long  srand_seed = 0 ;
int  main (int  argc ,char * *  argv ){
	main_proc ( argc , argv );
	get_constants (  );
	PS_MPI_Init ( 	& ( argc ) , 	& ( argv ) );
{
	char *  nm = "V0_z_file" ;
	FILE *  fp = 	fopen ( nm , "r" ) ;
	if (  fp  ){  
			fprintf ( stderr , "found %s for input\n" , nm );
(pV0_z_gid_global_var = 	malloc ( 	(  sizeof(Gaps_IO_DataFile ) * 1 ) ));
	GAPS_IO_InitIFile ( pV0_z_gid_global_var , nm );
	assert ( 	(  	( pV0_z_gid_global_var )->version == 0 ) );
	assert ( 	(  	( pV0_z_gid_global_var )->dim == 4 ) );
(GET_INIT_V0_z_inner_procedure = V0_z_global_procedure);

	}else{
		0;

	 }
}{
	char *  nm = "V0_y_file" ;
	FILE *  fp = 	fopen ( nm , "r" ) ;
	if (  fp  ){  
			fprintf ( stderr , "found %s for input\n" , nm );
(pV0_y_gid_global_var = 	malloc ( 	(  sizeof(Gaps_IO_DataFile ) * 1 ) ));
	GAPS_IO_InitIFile ( pV0_y_gid_global_var , nm );
	assert ( 	(  	( pV0_y_gid_global_var )->version == 0 ) );
	assert ( 	(  	( pV0_y_gid_global_var )->dim == 4 ) );
(GET_INIT_V0_y_inner_procedure = V0_y_global_procedure);

	}else{
		0;

	 }
}{
	char *  nm = "V0_x_file" ;
	FILE *  fp = 	fopen ( nm , "r" ) ;
	if (  fp  ){  
			fprintf ( stderr , "found %s for input\n" , nm );
(pV0_x_gid_global_var = 	malloc ( 	(  sizeof(Gaps_IO_DataFile ) * 1 ) ));
	GAPS_IO_InitIFile ( pV0_x_gid_global_var , nm );
	assert ( 	(  	( pV0_x_gid_global_var )->version == 0 ) );
	assert ( 	(  	( pV0_x_gid_global_var )->dim == 4 ) );
(GET_INIT_V0_x_inner_procedure = V0_x_global_procedure);

	}else{
		0;

	 }
}{
	char *  nm = "DENSITY_DIST_file" ;
	FILE *  fp = 	fopen ( nm , "r" ) ;
	if (  fp  ){  
			fprintf ( stderr , "found %s for input\n" , nm );
(pDENSITY_DIST_gid_global_var = 	malloc ( 	(  sizeof(Gaps_IO_DataFile ) * 1 ) ));
	GAPS_IO_InitIFile ( pDENSITY_DIST_gid_global_var , nm );
	assert ( 	(  	( pDENSITY_DIST_gid_global_var )->version == 0 ) );
	assert ( 	(  	( pDENSITY_DIST_gid_global_var )->dim == 4 ) );
(GET_INIT_DENSITY_DIST_inner_procedure = DENSITY_DIST_global_procedure);

	}else{
		0;

	 }
}{
	char *  nm = "TEMPERATURE_DIST_file" ;
	FILE *  fp = 	fopen ( nm , "r" ) ;
	if (  fp  ){  
			fprintf ( stderr , "found %s for input\n" , nm );
(pTEMPERATURE_DIST_gid_global_var = 	malloc ( 	(  sizeof(Gaps_IO_DataFile ) * 1 ) ));
	GAPS_IO_InitIFile ( pTEMPERATURE_DIST_gid_global_var , nm );
	assert ( 	(  	( pTEMPERATURE_DIST_gid_global_var )->version == 0 ) );
	assert ( 	(  	( pTEMPERATURE_DIST_gid_global_var )->dim == 5 ) );
(GET_INIT_TEMPERATURE_DIST_inner_procedure = TEMPERATURE_DIST_global_procedure);

	}else{
		0;

	 }
}	int  n = NUM_PROCESS ;
	if (  	(  NUM_PROCESS == 0 )  ){  
			PS_MPI_Comm_size ( PS_MPI_COMM_WORLD , 	& ( n ) );
(NUM_PROCESS = n);

	}else{
		0;

	 }
	long  num_runtime = NUM_RUNTIME ;
	long  n_hilbert = NUM_N_HILBERT ;
	long  len_hilbert = 	(  1 << n_hilbert ) ;
	long  numt = 1 ;
{
	long  g ;
	for ((g = 0) ; 	(  g < NUM_N_HILBERT_DIMENSION ) ; (g = 	(  g + 1 )))
	{
(numt = 	(  numt * len_hilbert ));
}}	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	assert ( 	(  rank < n ) );
	double  M_USE_TIME_AS_RANDOM_SEED = 	call_GET_VAR ( "USE_TIME_AS_RANDOM_SEED" ) ;
	double  M_RAND_SEED = 	call_GET_VAR ( "RAND_SEED" ) ;
	double  M_DELTA_X = 	call_GET_VAR ( "DELTA_X" ) ;
	double  M_DELTA_Y = 	call_GET_VAR ( "DELTA_Y" ) ;
	double  M_DELTA_Z = 	call_GET_VAR ( "DELTA_Z" ) ;
	double  M_USE_VLO = 	call_GET_VAR ( "USE_VLO" ) ;
	double  M_DISABLE_TS_LOG = 	call_GET_VAR ( "DISABLE_TS_LOG" ) ;
	double  M_USE_NO_CURRENT = 	call_GET_VAR ( "USE_NO_CURRENT" ) ;
	double  M_USE_REDUCE_DIM = 	call_GET_VAR ( "USE_REDUCE_DIM" ) ;
	double  M_USE_NOT_REDUCE_DIM_PARTICLE = 	call_GET_VAR ( "USE_NOT_REDUCE_DIM_PARTICLE" ) ;
	double  M_REDUCE_DIM_X_RAT = 	call_GET_VAR ( "REDUCE_DIM_X_RAT" ) ;
	double  M_REDUCE_DIM_Y_RAT = 	call_GET_VAR ( "REDUCE_DIM_Y_RAT" ) ;
	double  M_REDUCE_DIM_Z_RAT = 	call_GET_VAR ( "REDUCE_DIM_Z_RAT" ) ;
	double  M_REDUCE_DIM_RANDOM_RATE = 	call_GET_VAR ( "REDUCE_DIM_RANDOM_RATE" ) ;
	double  M_USE_SAME_RANDOM_SEED = 	call_GET_VAR ( "USE_SAME_RANDOM_SEED" ) ;
	double  M_USE_HYDRO_DEBUG = 	call_GET_VAR ( "USE_HYDRO_DEBUG" ) ;
	double   dims_rat_xyz  [6];((dims_rat_xyz)[0] = M_REDUCE_DIM_X_RAT);
((dims_rat_xyz)[1] = M_REDUCE_DIM_Y_RAT);
((dims_rat_xyz)[2] = M_REDUCE_DIM_Z_RAT);
((dims_rat_xyz)[3] = M_REDUCE_DIM_X_RAT);
((dims_rat_xyz)[4] = M_REDUCE_DIM_Y_RAT);
((dims_rat_xyz)[5] = M_REDUCE_DIM_Z_RAT);
	int  reduce_dim = M_USE_REDUCE_DIM ;
	double  ONE_FORM_REDUCE_DIM_X_RAT = M_REDUCE_DIM_X_RAT ;
	double  ONE_FORM_REDUCE_DIM_Y_RAT = M_REDUCE_DIM_Y_RAT ;
	double  ONE_FORM_REDUCE_DIM_Z_RAT = M_REDUCE_DIM_Z_RAT ;
	double  TWO_FORM_REDUCE_DIM_X_RAT = 	(  M_REDUCE_DIM_Y_RAT * M_REDUCE_DIM_Z_RAT ) ;
	double  TWO_FORM_REDUCE_DIM_Y_RAT = 	(  M_REDUCE_DIM_X_RAT * M_REDUCE_DIM_Z_RAT ) ;
	double  TWO_FORM_REDUCE_DIM_Z_RAT = 	(  M_REDUCE_DIM_X_RAT * M_REDUCE_DIM_Y_RAT ) ;
	if (  	(  M_DELTA_X == 0 )  ){  
		(M_DELTA_X = 1);

	}else{
		0;

	 }
	if (  	(  M_DELTA_Y == 0 )  ){  
		(M_DELTA_Y = 1);

	}else{
		0;

	 }
	if (  	(  M_DELTA_Z == 0 )  ){  
		(M_DELTA_Z = 1);

	}else{
		0;

	 }
(srand_seed = 	(  rank + 1 ));
	long  local_seed = 	(  rank + 	(  1 + ((M_USE_TIME_AS_RANDOM_SEED)?(	time ( NULL )):(M_RAND_SEED)) ) ) ;
	if (  	(  ! M_USE_SAME_RANDOM_SEED )  ){  
			srand ( srand_seed );

	}else{
		(srand_seed = local_seed);

	 }
	long   tids  [	(  num_runtime * n )];	int64_t *  local_tid_array = 	malloc ( 	(  sizeof(int64_t ) * numt ) ) ;
	Field3D_MPI  testfield ;
	Field3D_MPI *  ptestfield = 	& ( testfield ) ;
	Field3D_MPI  testfieldSPEC ;
	Field3D_MPI *  ptestfieldSPEC = 	& ( testfieldSPEC ) ;
	Field3D_Seq  fstest ;
	Field3D_Seq  fstestSPEC ;
	Field3D_Seq *  pfstestSPEC = 	& ( fstestSPEC ) ;
	Field3D_Seq *  pfstest = 	& ( fstest ) ;
	int   cd_types  [NUM_MAX_RUNTIME];	int   dev_ids  [NUM_MAX_RUNTIME];	double  G_GAPSIO_VERSION = 	call_GET_VAR ( "GAPSIO_VERSION" ) ;
	double  G_GAPSIO_NUM_REDUCEWRITE = 	call_GET_VAR ( "GAPSIO_NUM_REDUCEWRITE" ) ;
	double  G_OVERLAP_LEN = 	call_GET_VAR ( "OVERLAP_LEN" ) ;
	double  G_USE_G_E = 	call_GET_VAR ( "USE_G_E" ) ;
	double  G_USE_PML_ABC_DIR = 	call_GET_VAR ( "USE_PML_ABC_DIR" ) ;
	double  G_PML_LEVEL = 	call_GET_VAR ( "PML_LEVEL" ) ;
	double  G_PML_SIGMA_MAX = 	call_GET_VAR ( "PML_SIGMA_MAX" ) ;
	if (  	(  G_GAPSIO_VERSION < 2 )  ){  
		(G_GAPSIO_NUM_REDUCEWRITE = 0);

	}else{
		0;

	 }
{
	long  i = 0 ;
	for (i=0 ; i<NUM_RUNTIME ; i++)
	{
((cd_types)[i] = 	call_GET_DEV_TYPE ( i , rank ));
((dev_ids)[i] = 	call_GET_DEV_ID ( i , rank ));
}}	fprintf ( stderr , "rank %d init, pid=%d\n" , rank , 	getpid (  ) );
	memset ( pfstest , 0 , sizeof(Field3D_Seq ) );
	long  fieldlen = 3 ;
	int  overlap_len = 2 ;
	if (  USE_KGM  ){  
		(fieldlen = 10);
(overlap_len = 1);

	}else{
		0;

	 }
	if (  	(  G_OVERLAP_LEN != 0 )  ){  
		(overlap_len = G_OVERLAP_LEN);

	}else{
		0;

	 }
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "overlap=%d\n" , overlap_len );

	}else{
		0;

	 }
	long   allxyzmax  [3];	if (  	(  NUM_N_HILBERT_DIMENSION == 1 )  ){  
			long   lengs  [3];{
	long  i ;
	for ((i = 0) ; 	(  i < 3 ) ; (i = 	(  i + 1 )))
	{
((lengs)[i] = ((	(  i == HILBERT_DIR ))?(len_hilbert):(1)));
}}((allxyzmax)[0] = 	(  (lengs)[0] * XMAX ));
((allxyzmax)[1] = 	(  (lengs)[1] * YMAX ));
((allxyzmax)[2] = 	(  (lengs)[2] * ZMAX ));
	set_Field3D_Seq ( pfstest , NULL , M_DELTA_X , M_DELTA_Y , M_DELTA_Z , XMAX , YMAX , ZMAX , 2 , overlap_len , fieldlen , 0 , (lengs)[0] , (lengs)[1] , (lengs)[2] , rank );

	}else{
			if (  	(  NUM_N_HILBERT_DIMENSION == 2 )  ){  
			long   lengs  [3];{
	long  i ;
	for ((i = 0) ; 	(  i < 3 ) ; (i = 	(  i + 1 )))
	{
((lengs)[i] = ((	(  i == HILBERT_DIR ))?(1):(len_hilbert)));
}}((allxyzmax)[0] = 	(  (lengs)[0] * XMAX ));
((allxyzmax)[1] = 	(  (lengs)[1] * YMAX ));
((allxyzmax)[2] = 	(  (lengs)[2] * ZMAX ));
	set_Field3D_Seq ( pfstest , NULL , M_DELTA_X , M_DELTA_Y , M_DELTA_Z , XMAX , YMAX , ZMAX , 2 , overlap_len , fieldlen , 0 , (lengs)[0] , (lengs)[1] , (lengs)[2] , rank );

	}else{
			if (  	(  NUM_N_HILBERT_DIMENSION == 3 )  ){  
			set_Field3D_Seq ( pfstest , NULL , M_DELTA_X , M_DELTA_Y , M_DELTA_Z , XMAX , YMAX , ZMAX , 2 , overlap_len , fieldlen , 0 , len_hilbert , len_hilbert , len_hilbert , rank );
((allxyzmax)[0] = 	(  len_hilbert * XMAX ));
((allxyzmax)[1] = 	(  len_hilbert * YMAX ));
((allxyzmax)[2] = 	(  len_hilbert * ZMAX ));

	}else{
		0;

	 }

	 }

	 }
(fstestSPEC = fstest);
(	( pfstestSPEC )->num_ele = 	(  7 * NUM_SPEC ));
	init_Field3D_MPI_ALL ( ptestfield , pfstest , n_hilbert , NUM_N_HILBERT_DIMENSION , 0 , tids , local_tid_array , cd_types , dev_ids , num_runtime , PS_MPI_COMM_WORLD , rank , n );
	init_Field3D_MPI_from_new_num_ele ( ptestfieldSPEC , ptestfield , 	(  7 * NUM_SPEC ) );
	if (  	(  USE_KGM == 1 )  ){  
			double  M_KGM_M0 = 	call_GET_VAR ( "KGM_M0" ) ;
	double  M_KGM_Q0 = 	call_GET_VAR ( "KGM_Q0" ) ;
	double  M_KGM_DT = 	call_GET_VAR ( "KGM_DT" ) ;
	double  M_KGM_PHI0 = 	call_GET_VAR ( "KGM_PHI0" ) ;
	double  M_KGM_AMPX = 	call_GET_VAR ( "KGM_AMPX" ) ;
	double  M_KGM_SGM = 	call_GET_VAR ( "KGM_SGM" ) ;
	double  M_KGM_EY = 	call_GET_VAR ( "KGM_EY" ) ;
	double  M_KGM_FRQ = 	call_GET_VAR ( "KGM_FRQ" ) ;
	double  M_KGM_ASSEMBLE = 	call_GET_VAR ( "KGM_ASSEMBLE" ) ;
	double  M_KGM_ASSEMBLE_TIME = 	call_GET_VAR ( "KGM_ASSEMBLE_TIME" ) ;
	double  M_KGM_MID_LOC = 	call_GET_VAR ( "KGM_MID_LOC" ) ;
	double  M_KGM_LEN_A0 = 	call_GET_VAR ( "KGM_LEN_A0" ) ;
	double  M_KGM_SGM_DENS = 	call_GET_VAR ( "KGM_SGM_DENS" ) ;
	double  M_KGM_ASS_E_LOC0 = 	call_GET_VAR ( "KGM_ASS_E_LOC0" ) ;
	double  M_KGM_G_BEG = 	call_GET_VAR ( "KGM_G_BEG" ) ;
	double  M_KGM_DX = 	call_GET_VAR ( "KGM_DX" ) ;
	double  M_KGM_REFZ0 = 	call_GET_VAR ( "KGM_REFZ0" ) ;
	double  M_KGM_EXTG = 	call_GET_VAR ( "KGM_EXTG" ) ;
	double  M_KGM_INIT_SPER = 	call_GET_VAR ( "KGM_INIT_SPER" ) ;
	double  M_KGM_XMID = 	call_GET_VAR ( "KGM_XMID" ) ;
	double  M_KGM_YMID = 	call_GET_VAR ( "KGM_YMID" ) ;
	double  M_KGM_ZMID = 	call_GET_VAR ( "KGM_ZMID" ) ;
	double  M_KGM_AVRHO_DUMP_TIMESTEP = 	call_GET_VAR ( "KGM_AVRHO_DUMP_TIMESTEP" ) ;
	Field3D_MPI  F0 ;
	Field3D_MPI *  pF0 = 	& ( F0 ) ;
	Field3D_MPI  F1 ;
	Field3D_MPI *  pF1 = 	& ( F1 ) ;
	Field3D_MPI  F2 ;
	Field3D_MPI *  pF2 = 	& ( F2 ) ;
	Field3D_MPI  extA0 ;
	Field3D_MPI *  pextA0 = 	& ( extA0 ) ;
	Field3D_MPI  extA1 ;
	Field3D_MPI *  pextA1 = 	& ( extA1 ) ;
	Field3D_MPI  extAtmp ;
	Field3D_MPI *  pextAtmp = 	& ( extAtmp ) ;
	Field3D_MPI  filter_A ;
	Field3D_MPI *  pfilter_A = 	& ( filter_A ) ;
	init_Field3D_MPI_from ( pF0 , ptestfield );
	init_Field3D_MPI_from ( pF1 , ptestfield );
	init_Field3D_MPI_from_new_num_ele ( pextA0 , ptestfield , 3 );
	init_Field3D_MPI_from_new_num_ele ( pextA1 , ptestfield , 3 );
	init_Field3D_MPI_from_new_num_ele ( pextAtmp , ptestfield , 3 );
	init_Field3D_MPI_from_new_num_ele ( pF2 , pF0 , 1 );
	blas_yiszero_Field3D_MPI ( pF0 , pF0 );
	sync_ovlp_mpi_field ( pF0 );
	blas_yiszero_Field3D_MPI ( pF1 , pF1 );
	sync_ovlp_mpi_field ( pF1 );
	if (  M_KGM_ASSEMBLE  ){  
			Gaps_IO_DataFile  ipigs ;
	Gaps_IO_DataFile *  pipigs = 	& ( ipigs ) ;
	GAPS_IO_InitIFile ( pipigs , "tmpKGM_ASSEMBLE" );
	long  tread = M_KGM_ASSEMBLE_TIME ;
	read_parallel_file_for_mpi_fields ( pF0 , pipigs , tread );
	init_kgm_assemble ( pF0 , M_KGM_AMPX , 	(  M_KGM_EY * M_KGM_DX ) , 	(  M_KGM_DT / M_KGM_DX ) , M_KGM_SGM , M_KGM_FRQ , M_KGM_ASS_E_LOC0 );

	}else{
			init_kgm_global ( pF0 , M_KGM_PHI0 , M_KGM_M0 , M_KGM_Q0 , M_KGM_AMPX , M_KGM_EY , M_KGM_DT , M_KGM_SGM , M_KGM_FRQ , M_KGM_MID_LOC , M_KGM_LEN_A0 , M_KGM_SGM_DENS , M_KGM_INIT_SPER , M_KGM_XMID , M_KGM_YMID , M_KGM_ZMID );
	init_external_field3d_without_ss_KGM ( pF0 );

	 }
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	Gaps_IO_DataFile  agid ;
	Gaps_IO_DataFile *  pagid = 	& ( agid ) ;
	long  tsave = 0 ;
	long  tsave_rho = 0 ;
	init_parallel_file_for_mpi_fields ( ptestfield , pgid , "tmpKGM" , ((tsave)?(tsave):(-1)) , G_GAPSIO_VERSION , G_GAPSIO_NUM_REDUCEWRITE );
	if (  USE_INIT_EXT_EB  ){  
			init_external_field3d_E_2d_extend ( pextA0 , M_USE_REDUCE_DIM , ONE_FORM_REDUCE_DIM_X_RAT , ONE_FORM_REDUCE_DIM_Y_RAT , ONE_FORM_REDUCE_DIM_Z_RAT );
	init_external_field3d_B_2d_extend ( pextA1 , M_USE_REDUCE_DIM , TWO_FORM_REDUCE_DIM_X_RAT , TWO_FORM_REDUCE_DIM_Y_RAT , TWO_FORM_REDUCE_DIM_Z_RAT );
	sync_ovlp_mpi_field ( pextA0 );
	sync_ovlp_mpi_field ( pextA1 );

	}else{
			blas_yiszero_synced_Field3D_MPI ( pextA0 , pextA0 );
	blas_yiszero_synced_Field3D_MPI ( pextA1 , pextA1 );

	 }
	if (  USE_FILTER  ){  
			init_Field3D_MPI_from_new_num_ele ( pfilter_A , pF0 , 3 );
	init_external_field3d_FILTER_B ( pfilter_A );

	}else{
		0;

	 }
	if (  M_KGM_AVRHO_DUMP_TIMESTEP  ){  
			init_parallel_file_for_mpi_fields ( pF2 , pagid , "tmpRHO" , ((tsave)?(tsave):(-1)) , G_GAPSIO_VERSION , G_GAPSIO_NUM_REDUCEWRITE );

	}else{
		0;

	 }
{
	long  t ;
	for ((t = 0) ; 	(  t < NUM_TIMESTEP ) ; (t = 	(  t + 1 )))
	{
	MPI_kgm_eqn_core ( pF1 , pF0 , pextA0 , pextA1 , M_KGM_DT , M_KGM_M0 , M_KGM_Q0 , M_KGM_DX , M_KGM_EXTG , M_KGM_REFZ0 , M_KGM_G_BEG , 	(  t && 1 ) );
	if (  USE_FILTER  ){  
			blas_mulxy_numele3_Field3D_MPI ( pF1 , pF1 , pfilter_A );

	}else{
		0;

	 }
	if (  	(  rank == 0 )  ){  
			fprintf ( stdout , "%d\n" , t );

	}else{
		0;

	 }
	if (  	(  0 && 	(  rank == 0 ) )  ){  
			sync_main_data_d2h ( pF1 );
(((((double * * )	( pF1->data )->main_data))[0])[	(  	(  0 * 	(  	( pF1->data )->xblock * 	(  	( pF1->data )->yblock * 	(  	( pF1->data )->zblock * 	( pF1->data )->num_ele ) ) ) ) + 	(  0 + 	(  	( pF1->data )->num_ele * 	(  	(  4 + 	( pF1->data )->ovlp ) + 	(  	( pF1->data )->xblock * 	(  	(  0 + 	( pF1->data )->ovlp ) + 	(  	( pF1->data )->yblock * 	(  0 + 	( pF1->data )->ovlp ) ) ) ) ) ) ) )] = 	(  ((((double * * )	( pF1->data )->main_data))[0])[	(  	(  0 * 	(  	( pF1->data )->xblock * 	(  	( pF1->data )->yblock * 	(  	( pF1->data )->zblock * 	( pF1->data )->num_ele ) ) ) ) + 	(  0 + 	(  	( pF1->data )->num_ele * 	(  	(  4 + 	( pF1->data )->ovlp ) + 	(  	( pF1->data )->xblock * 	(  	(  0 + 	( pF1->data )->ovlp ) + 	(  	( pF1->data )->yblock * 	(  0 + 	( pF1->data )->ovlp ) ) ) ) ) ) ) )] + 	(  M_KGM_AMPX * 	sin ( 	(  t * DELTAT ) ) ) ));
	sync_main_data_h2d ( pF1 );

	}else{
		0;

	 }
	if (  USE_NP_BOUNDARY  ){  
			double  G_USE_ABC_DIR = 	call_GET_VAR ( "USE_ABC_DIR" ) ;
	double  G_USE_PEC_DIR = 	call_GET_VAR ( "USE_PEC_DIR" ) ;
	double  G_USE_DAMP_DIR = 	call_GET_VAR ( "USE_DAMP_DIR" ) ;
	MPI_Yee_FDTD_MUR_ABC ( pF1 , pF0 , M_KGM_DT , G_USE_ABC_DIR , G_USE_PEC_DIR , G_USE_DAMP_DIR , 0 );

	}else{
		0;

	 }
	long  rdmd = 	(  	(  M_KGM_ASSEMBLE == 1 ) * ((long )	(  NUM_DUMP_TIMESTEP * 	(  	(  	rand (  ) * 1.00000000000000000e+00 ) / RAND_MAX ) )) ) ;
	if (  	(  ((int )M_KGM_AVRHO_DUMP_TIMESTEP) && 	(  0 == 	(  t % ((int )M_KGM_AVRHO_DUMP_TIMESTEP) ) ) )  ){  
			MPI_kgm_calc_rho ( pF2 , pF1 , M_KGM_DT , M_KGM_M0 , M_KGM_Q0 , M_KGM_DX , M_KGM_REFZ0 , 1.00000000000000006e-01 , 2.99999999999999989e-01 , 0 , 0 );
	mpi_field_write_to_file ( pF2 , pagid , tsave_rho );
(tsave_rho = 	(  tsave_rho + 1 ));
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%d rho done\n" , tsave_rho );

	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  0 == 	(  	(  t + rdmd ) % NUM_DUMP_TIMESTEP ) )  ){  
			mpi_field_write_to_file ( pF1 , pgid , tsave );
(tsave = 	(  tsave + 1 ));
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%d done\n" , t );

	}else{
		0;

	 }

	}else{
		0;

	 }
	void *  tmp = pF0 ;
(pF0 = pF1);
(pF1 = tmp);
}}
	}else{
			if (  	(  M_USE_HYDRO_DEBUG == 1 )  ){  
			double  M_HYDRO_QM0 = 	call_GET_VAR ( "HYDRO_QM0" ) ;
	double  M_HYDRO_U0 = 	call_GET_VAR ( "HYDRO_U0" ) ;
	double  M_HYDRO_RHO0 = 	call_GET_VAR ( "HYDRO_RHO0" ) ;
	double  M_HYDRO_DRHO0 = 	call_GET_VAR ( "HYDRO_DRHO0" ) ;
	double  M_HYDRO_B0 = 	call_GET_VAR ( "HYDRO_B0" ) ;
	double  M_HYDRO_S0 = 	call_GET_VAR ( "HYDRO_S0" ) ;
	double  M_HYDRO_BICGSTAB_ERR = 	call_GET_VAR ( "HYDRO_BICGSTAB_ERR" ) ;
	double  M_HYDRO_SOLVE_ERR = 	call_GET_VAR ( "HYDRO_SOLVE_ERR" ) ;
	Field3D_MPI  rho_s_vx0 ;
	Field3D_MPI *  prho_s_vx0 = 	& ( rho_s_vx0 ) ;
	Field3D_MPI  ext_rho_s_vx ;
	Field3D_MPI *  pext_rho_s_vx = 	& ( ext_rho_s_vx ) ;
	Field3D_MPI  rho_s_vx1 ;
	Field3D_MPI *  prho_s_vx1 = 	& ( rho_s_vx1 ) ;
	Field3D_MPI  alpha_beta0 ;
	Field3D_MPI *  palpha_beta0 = 	& ( alpha_beta0 ) ;
	Field3D_MPI  alpha_beta1 ;
	Field3D_MPI *  palpha_beta1 = 	& ( alpha_beta1 ) ;
	Field3D_MPI  rest_alpha_beta ;
	Field3D_MPI *  prest_alpha_beta = 	& ( rest_alpha_beta ) ;
	Field3D_MPI  v_alpha_beta ;
	Field3D_MPI *  pv_alpha_beta = 	& ( v_alpha_beta ) ;
	Field3D_MPI  vA0 ;
	Field3D_MPI *  pvA0 = 	& ( vA0 ) ;
	Field3D_MPI  vA1 ;
	Field3D_MPI *  pvA1 = 	& ( vA1 ) ;
	Field3D_MPI  vA2 ;
	Field3D_MPI *  pvA2 = 	& ( vA2 ) ;
	Field3D_MPI  vAext ;
	Field3D_MPI *  pvAext = 	& ( vAext ) ;
(	( pfstest )->num_ele = 5);
	init_Field3D_MPI_ALL ( prho_s_vx0 , pfstest , n_hilbert , NUM_N_HILBERT_DIMENSION , 0 , tids , local_tid_array , cd_types , dev_ids , num_runtime , PS_MPI_COMM_WORLD , rank , n );
	init_Field3D_MPI_from ( prho_s_vx1 , prho_s_vx0 );
	init_Field3D_MPI_from ( pext_rho_s_vx , prho_s_vx0 );
	init_Field3D_MPI_from_new_num_ele ( palpha_beta0 , prho_s_vx0 , 2 );
	init_Field3D_MPI_from ( palpha_beta1 , palpha_beta0 );
	init_Field3D_MPI_from ( prest_alpha_beta , palpha_beta0 );
	init_Field3D_MPI_from ( pv_alpha_beta , palpha_beta0 );
	init_Field3D_MPI_from_new_num_ele ( pvA0 , prho_s_vx0 , 3 );
	init_Field3D_MPI_from ( pvA1 , pvA0 );
	init_Field3D_MPI_from ( pvA2 , pvA0 );
	init_Field3D_MPI_from ( pvAext , pvA0 );
	init_hydro_alpha_beta ( palpha_beta0 , 1.00000000000000002e-02 , 1.00000000000000002e-02 );
	init_hydro_rho_s_vx ( prho_s_vx0 , M_HYDRO_RHO0 , M_HYDRO_DRHO0 , M_HYDRO_S0 , 0 , 0 , 0 );
	blas_yiszero_synced_Field3D_MPI ( pvA0 , pvA0 );
	blas_yiszero_synced_Field3D_MPI ( pvA1 , pvA1 );
	blas_yiszero_synced_Field3D_MPI ( pvA2 , pvA2 );
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	Gaps_IO_DataFile  gaid ;
	Gaps_IO_DataFile *  pgaid = 	& ( gaid ) ;
	Gaps_IO_DataFile  grid ;
	Gaps_IO_DataFile *  pgrid = 	& ( grid ) ;
	init_parallel_file_for_mpi_fields ( prho_s_vx1 , pgrid , "tmpRHOSV" , -1 , G_GAPSIO_VERSION , G_GAPSIO_NUM_REDUCEWRITE );
	init_parallel_file_for_mpi_fields ( pvA0 , pgaid , "tmpA" , -1 , G_GAPSIO_VERSION , G_GAPSIO_NUM_REDUCEWRITE );
	init_parallel_file_for_mpi_fields ( palpha_beta0 , pgid , "tmpALPHABETA" , -1 , G_GAPSIO_VERSION , G_GAPSIO_NUM_REDUCEWRITE );
{
	bicg_space  bs ;
	bicg_space *  pbs = 	& ( bs ) ;
	hydro_fv  fv ;
	hydro_fv *  pfv = 	& ( fv ) ;
(	( pfv )->palpha_beta1 = palpha_beta1);
(	( pfv )->prho_s_vx = prho_s_vx1);
(	( pfv )->pvA1 = pvA1);
(	( pfv )->dt = DELTAT);
(	( pfv )->dx = M_DELTA_X);
(	( pfv )->dy = M_DELTA_Y);
(	( pfv )->dz = M_DELTA_Z);
(	( pfv )->u0 = M_HYDRO_U0);
(	( pfv )->qm0 = M_HYDRO_QM0);
	mpi_init_bicg ( pbs , hydro_bicg_fun , palpha_beta1 , 1000 , M_HYDRO_BICGSTAB_ERR , pfv );
	init_hydro_ext_s0 ( pext_rho_s_vx , 1 , 1 );
	init_hydro_ext_A0y ( pvAext , M_HYDRO_B0 );
{
	long  t ;
	for ((t = 0) ; 	(  t < NUM_TIMESTEP ) ; (t = 	(  t + 1 )))
	{
	sync_ovlp_mpi_field ( prho_s_vx0 );
	MPI_hydro_push_rho_s ( prho_s_vx1 , palpha_beta0 , palpha_beta0 , prho_s_vx0 , pvA1 , pvA1 , DELTAT , M_DELTA_X , M_DELTA_Y , M_DELTA_Z , M_HYDRO_U0 , M_HYDRO_QM0 );
	blas_yisax_Field3D_MPI ( palpha_beta1 , palpha_beta1 , 1 , palpha_beta0 );
	sync_ovlp_mpi_field ( palpha_beta0 );
	sync_ovlp_mpi_field ( palpha_beta1 );
	sync_ovlp_mpi_field ( prho_s_vx1 );
{
	long  z ;
	for ((z = 0) ; 	(  z < 100 ) ; (z = 	(  z + 1 )))
	{
	sync_ovlp_mpi_field ( palpha_beta1 );
	MPI_hydro_push_alpha_beta ( prest_alpha_beta , palpha_beta0 , palpha_beta1 , prho_s_vx1 , pvA1 , pvA1 , DELTAT , M_DELTA_X , M_DELTA_Y , M_DELTA_Z , M_HYDRO_U0 , M_HYDRO_QM0 );
	if (  0  ){  
		{
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	Gaps_IO_DataFile  grid ;
	Gaps_IO_DataFile *  pgrid = 	& ( grid ) ;
	init_parallel_file_for_mpi_fields ( prho_s_vx1 , pgrid , "tmpRHO_dbg" , -1 , G_GAPSIO_VERSION , G_GAPSIO_NUM_REDUCEWRITE );
	init_parallel_file_for_mpi_fields ( prest_alpha_beta , pgid , "tmpField_dbg" , -1 , G_GAPSIO_VERSION , G_GAPSIO_NUM_REDUCEWRITE );
	mpi_field_write_to_file ( prho_s_vx1 , pgrid , 0 );
	mpi_field_write_to_file ( prho_s_vx0 , pgrid , 1 );
	mpi_field_write_to_file ( prest_alpha_beta , pgid , 0 );
	mpi_field_write_to_file ( palpha_beta1 , pgid , 1 );
	mpi_field_write_to_file ( palpha_beta0 , pgid , 2 );
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	PS_MPI_Finalize (  );
	return  0 ;}
	}else{
		0;

	 }
	double  newton_err = 	blas_findmax_Field3D_MPI ( prest_alpha_beta , prest_alpha_beta ) ;
	if (  	(  newton_err < M_HYDRO_SOLVE_ERR )  ){  
		break;

	}else{
		0;

	 }
	mpi_simple_bicgstab ( pbs , pv_alpha_beta , prest_alpha_beta );
	blas_axpy_Field3D_MPI ( palpha_beta1 , palpha_beta1 , -1 , pv_alpha_beta );
}}	sync_ovlp_mpi_field ( palpha_beta1 );
	MPI_hydro_push_vx ( prho_s_vx1 , palpha_beta1 , palpha_beta1 , prho_s_vx1 , pvA1 , pvA1 , DELTAT , M_DELTA_X , M_DELTA_Y , M_DELTA_Z , M_HYDRO_U0 , M_HYDRO_QM0 );
	MPI_hydro_push_vA ( pvA2 , palpha_beta1 , palpha_beta1 , prho_s_vx1 , pvA1 , pvA0 , DELTAT , M_DELTA_X , M_DELTA_Y , M_DELTA_Z , M_HYDRO_U0 , M_HYDRO_QM0 );
	fprintf ( stderr , "t=%d done\n" , t );
	if (  	(  0 == 	(  t % NUM_DUMP_TIMESTEP ) )  ){  
			long  ts = 	(  t / NUM_DUMP_TIMESTEP ) ;
	mpi_field_write_to_file ( prho_s_vx1 , pgrid , ts );
	mpi_field_write_to_file ( palpha_beta1 , pgid , ts );
	mpi_field_write_to_file ( pvA1 , pgaid , 	(  ts * 2 ) );
	mpi_field_write_to_file ( pvA2 , pgaid , 	(  	(  ts * 2 ) + 1 ) );

	}else{
		0;

	 }
	if (  0  ){  
		{
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	Gaps_IO_DataFile  grid ;
	Gaps_IO_DataFile *  pgrid = 	& ( grid ) ;
	fprintf ( stderr , "OK here\n" );
	init_parallel_file_for_mpi_fields ( prho_s_vx1 , pgrid , "tmpRHO_dbg" , -1 , G_GAPSIO_VERSION , G_GAPSIO_NUM_REDUCEWRITE );
	fprintf ( stderr , "OK aft init rho\n" );
	init_parallel_file_for_mpi_fields ( prest_alpha_beta , pgid , "tmpField_dbg" , -1 , G_GAPSIO_VERSION , G_GAPSIO_NUM_REDUCEWRITE );
	mpi_field_write_to_file ( prho_s_vx1 , pgrid , 0 );
	mpi_field_write_to_file ( prho_s_vx0 , pgrid , 1 );
	mpi_field_write_to_file ( prest_alpha_beta , pgid , 0 );
	mpi_field_write_to_file ( palpha_beta1 , pgid , 1 );
	mpi_field_write_to_file ( palpha_beta0 , pgid , 2 );
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	PS_MPI_Finalize (  );
	return  0 ;}
	}else{
		0;

	 }
{
	blas_yisax_Field3D_MPI ( pvA0 , pvA0 , 1 , pvA1 );
	blas_yisax_Field3D_MPI ( pvA1 , pvA1 , 1 , pvA2 );
	blas_yisax_Field3D_MPI ( palpha_beta0 , palpha_beta0 , 1 , palpha_beta1 );
	blas_yisax_Field3D_MPI ( prho_s_vx0 , prho_s_vx0 , 1 , prho_s_vx1 );
}}}}
	}else{
			if (  	(  USE_DM == 1 )  ){  
			double  M_DM_M0 = 	call_GET_VAR ( "DM_M0" ) ;
	double  M_DM_Q0 = 	call_GET_VAR ( "DM_Q0" ) ;
	double  M_DM_LAMBDA = 	call_GET_VAR ( "DM_LAMBDA" ) ;
	double  M_DM_DT = 	call_GET_VAR ( "DM_DT" ) ;
	double  M_DM_PHI0 = 	call_GET_VAR ( "DM_PHI0" ) ;
	double  M_DM_PZ_I = 	call_GET_VAR ( "DM_PZ_I" ) ;
	double  M_DM_PZ_R = 	call_GET_VAR ( "DM_PZ_R" ) ;
	double  M_DM_Z_OFFSET = 	call_GET_VAR ( "DM_Z_OFFSET" ) ;
	double  M_DM_AMPX = 	call_GET_VAR ( "DM_AMPX" ) ;
	double  M_DM_SGM = 	call_GET_VAR ( "DM_SGM" ) ;
	double  M_DM_EY = 	call_GET_VAR ( "DM_EY" ) ;
	double  M_DM_YZ = 	call_GET_VAR ( "DM_YZ" ) ;
	double  M_DM_FRQ = 	call_GET_VAR ( "DM_FRQ" ) ;
	double  M_DM_SOLVE_ERR = 	call_GET_VAR ( "DM_SOLVE_ERR" ) ;
	double  M_DM_A = 	call_GET_VAR ( "DM_A" ) ;
	double  M_DM_PHI34V = 	call_GET_VAR ( "DM_PHI34V" ) ;
	double  M_DM_PZ_R_GAUSS_RAND = 	call_GET_VAR ( "DM_PZ_R_GAUSS_RAND" ) ;
	double  M_DM_USE_DISP_INIT_CONDITION = 	call_GET_VAR ( "DM_USE_DISP_INIT_CONDITION" ) ;
	double  M_DM_DISP_RAND_AMP = 	call_GET_VAR ( "DM_DISP_RAND_AMP" ) ;
	double  M_DM_DUAL_FIELD = 	call_GET_VAR ( "DM_DUAL_FIELD" ) ;
	double  M_DM_AMP_PSI = 	call_GET_VAR ( "DM_AMP_PSI" ) ;
	double  M_DM_NUMP = 	call_GET_VAR ( "DM_NUMP" ) ;
	if (  	(  M_DM_LAMBDA == 0 )  ){  
		(M_DM_LAMBDA = 1);

	}else{
		0;

	 }
	Field3D_MPI  F0 ;
	Field3D_MPI *  pF0 = 	& ( F0 ) ;
	Field3D_MPI  F1 ;
	Field3D_MPI *  pF1 = 	& ( F1 ) ;
	Field3D_MPI  Ff0 ;
	Field3D_MPI *  pFf0 = 	& ( Ff0 ) ;
	Field3D_MPI  Ff1 ;
	Field3D_MPI *  pFf1 = 	& ( Ff1 ) ;
	Field3D_MPI  b_AF0 ;
	Field3D_MPI *  pb_AF0 = 	& ( b_AF0 ) ;
	Field3D_MPI  b_AFf0 ;
	Field3D_MPI *  pb_AFf0 = 	& ( b_AFf0 ) ;
	Field3D_MPI  A0 ;
	Field3D_MPI *  pA0 = 	& ( A0 ) ;
	Field3D_MPI  A1 ;
	Field3D_MPI *  pA1 = 	& ( A1 ) ;
	Field3D_MPI  A2 ;
	Field3D_MPI *  pA2 = 	& ( A2 ) ;
(	( pfstest )->num_ele = 8);
	init_Field3D_MPI_ALL ( pb_AF0 , pfstest , n_hilbert , NUM_N_HILBERT_DIMENSION , 0 , tids , local_tid_array , cd_types , dev_ids , num_runtime , PS_MPI_COMM_WORLD , rank , n );
	init_Field3D_MPI_from ( pF0 , pb_AF0 );
	init_Field3D_MPI_from ( pF1 , pb_AF0 );
	if (  M_DM_DUAL_FIELD  ){  
			init_Field3D_MPI_from ( pb_AFf0 , pb_AF0 );
	init_Field3D_MPI_from ( pFf0 , pb_AF0 );
	init_Field3D_MPI_from ( pFf1 , pb_AF0 );

	}else{
		0;

	 }
(	( pfstest )->num_ele = 3);
	init_Field3D_MPI_ALL ( ptestfield , pfstest , n_hilbert , NUM_N_HILBERT_DIMENSION , 0 , tids , local_tid_array , cd_types , dev_ids , num_runtime , PS_MPI_COMM_WORLD , rank , n );
	init_Field3D_MPI_from ( pA0 , ptestfield );
	init_Field3D_MPI_from ( pA1 , ptestfield );
	init_Field3D_MPI_from ( pA2 , ptestfield );
	bicg_space  bs ;
	bicg_space *  pbs = 	& ( bs ) ;
	bicg_space  bsf ;
	bicg_space *  pbsf = 	& ( bsf ) ;
	dm_fv  fv ;
	dm_fv *  pfv = 	& ( fv ) ;
(	( pfv )->Q = M_DM_Q0);
(	( pfv )->M = M_DM_M0);
(	( pfv )->DT = M_DM_DT);
(	( pfv )->DM_A = M_DM_A);
(	( pfv )->DX = M_DELTA_X);
(	( pfv )->DY = M_DELTA_Y);
(	( pfv )->DZ = M_DELTA_Z);
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	Gaps_IO_DataFile  ghd ;
	Gaps_IO_DataFile *  pghd = 	& ( ghd ) ;
	Gaps_IO_DataFile  gad ;
	Gaps_IO_DataFile *  pgad = 	& ( gad ) ;
	long  tsave = 0 ;
	init_parallel_file_for_mpi_fields ( pF0 , pgid , "tmpDM" , ((tsave)?(tsave):(-1)) , G_GAPSIO_VERSION , G_GAPSIO_NUM_REDUCEWRITE );
	init_parallel_file_for_mpi_fields ( pA0 , pghd , "tmpH" , ((tsave)?(tsave):(-1)) , G_GAPSIO_VERSION , G_GAPSIO_NUM_REDUCEWRITE );
	init_parallel_file_for_mpi_fields ( pA0 , pgad , "tmpA" , ((tsave)?(tsave):(-1)) , G_GAPSIO_VERSION , G_GAPSIO_NUM_REDUCEWRITE );
	double  gauss_rand_tmp = 	maxwell_dist ( 0 , 1 ) ;
	if (  M_DM_USE_DISP_INIT_CONDITION  ){  
			init_dm_phi_global_rand ( pF0 , M_DM_PHI0 , M_DM_DISP_RAND_AMP );

	}else{
			init_dm_phi_global ( pF0 , M_DM_M0 , 	(  M_DM_PZ_R * ((M_DM_PZ_R_GAUSS_RAND)?(gauss_rand_tmp):(1)) ) , M_DM_PZ_I , M_DM_Z_OFFSET , M_DM_LAMBDA , M_DM_A , 	sqrt ( 	(  1 - 	(  M_DM_A * M_DM_A ) ) ) , 1 , M_DELTA_Z , 0 , M_DM_PHI34V , 0 , M_DM_AMP_PSI );

	 }
	if (  M_DM_DUAL_FIELD  ){  
			if (  M_DM_USE_DISP_INIT_CONDITION  ){  
			init_dm_phi_global_rand ( pFf0 , M_DM_PHI0 , M_DM_DISP_RAND_AMP );

	}else{
			init_dm_dual_phi_global ( pF0 , pFf0 , M_DM_AMP_PSI , M_DM_SGM , M_DM_NUMP , M_DM_M0 , M_DELTA_Z , (allxyzmax)[2] );

	 }
	init_external_field3d_without_ss_DMf ( pFf0 );

	}else{
		0;

	 }
	init_external_field3d_without_ss_DM ( pF0 );
	int  use_old_unstable_alg = 0 ;
	init_dm_A0_global ( pA0 , 0 , 0 );
	init_dm_A1_global ( pA1 , M_DM_AMPX , ((use_old_unstable_alg)?(M_DM_EY):(M_DM_YZ)) , ((use_old_unstable_alg)?(M_DM_DT):(1)) );
	if (  use_old_unstable_alg  ){  
			mpi_init_bicg ( pbs , dm_bicg_fun , pF0 , 1000 , M_DM_SOLVE_ERR , pfv );

	}else{
			mpi_init_bicg ( pbs , cayley_dm_new_fun , pF0 , 1000 , M_DM_SOLVE_ERR , pfv );
	if (  M_DM_DUAL_FIELD  ){  
			mpi_init_bicg ( pbsf , cayley_dm_new_fun , pFf0 , 1000 , M_DM_SOLVE_ERR , pfv );

	}else{
		0;

	 }

	 }
	double  beg_time_dm = 	wclk_now (  ) ;
	double  beg_time_dm_lst = beg_time_dm ;
{
	long  t ;
	for ((t = 0) ; 	(  t < NUM_TIMESTEP ) ; (t = 	(  t + 1 )))
	{
(	( pfv )->pA0 = pA0);
(	( pfv )->pA1 = pA1);
(	( pfv )->pA2 = pA2);
(	( pfv )->pF0 = pF0);
	sync_ovlp_mpi_field ( pF0 );
	if (  M_DM_DUAL_FIELD  ){  
			sync_ovlp_mpi_field ( pFf0 );

	}else{
		0;

	 }
	sync_ovlp_mpi_field ( pA0 );
	sync_ovlp_mpi_field ( pA1 );
	if (  	(  0 == 	(  t % NUM_DUMP_TIMESTEP ) )  ){  
			if (  M_DM_DUAL_FIELD  ){  
			mpi_field_write_to_file ( pF0 , pgid , 	(  2 * tsave ) );
	mpi_field_write_to_file ( pFf0 , pgid , 	(  1 + 	(  2 * tsave ) ) );
	MPI_dm_calc_hamt_dual ( pFf0 , pF0 , pA0 , pA2 , M_DM_DT , M_DELTA_Z , M_DELTA_Y , M_DELTA_X , M_DM_A , M_DM_Q0 , M_DM_M0 );

	}else{
			mpi_field_write_to_file ( pF0 , pgid , tsave );
	MPI_dm_calc_hamt ( pb_AF0 , pF0 , pA0 , pA2 , M_DM_DT , M_DELTA_Z , M_DELTA_Y , M_DELTA_X , M_DM_A , M_DM_Q0 , M_DM_M0 );

	 }
	mpi_field_write_to_file ( pA2 , pghd , tsave );
	mpi_field_write_to_file ( pA0 , pgad , 	(  tsave * 2 ) );
	mpi_field_write_to_file ( pA1 , pgad , 	(  	(  tsave * 2 ) + 1 ) );
(tsave = 	(  tsave + 1 ));
	double  tnow = 	wclk_now (  ) ;
	double  tall = 	(  tnow - beg_time_dm ) ;
	double  tonestep = 	(  tnow - beg_time_dm_lst ) ;
	fprintf ( stderr , "%d done, ips=%f, ipsall=%f\n" , t , 	(  NUM_DUMP_TIMESTEP / tonestep ) , 	(  t / tall ) );
(beg_time_dm_lst = tnow);

	}else{
		0;

	 }
	if (  use_old_unstable_alg  ){  
			MPI_dm_1st_eqn_right ( pb_AF0 , pF1 , pF0 , pA0 , pA1 , pA2 , M_DM_A , M_DM_Q0 , M_DM_M0 , M_DM_DT );
	sync_ovlp_mpi_field ( pb_AF0 );
	mpi_simple_bicgstab ( pbs , pF1 , pb_AF0 );
	MPI_dm_1st_eqn_fdtd ( pb_AF0 , pF1 , pF0 , pA0 , pA1 , pA2 , M_DM_A , M_DM_Q0 , M_DM_M0 , M_DM_DT );

	}else{
			cayley_dm_new_fun_right ( pb_AF0 , pF0 , pfv );
	sync_ovlp_mpi_field ( pb_AF0 );
	mpi_simple_bicgstab ( pbs , pF1 , pb_AF0 );
	blas_axpby_Field3D_MPI ( pF0 , pF0 , 5.00000000000000000e-01 , pF1 , 5.00000000000000000e-01 );
	if (  M_DM_DUAL_FIELD  ){  
		(	( pfv )->pF0 = pFf0);
	cayley_dm_new_fun_right ( pb_AFf0 , pFf0 , pfv );
	sync_ovlp_mpi_field ( pb_AFf0 );
	mpi_simple_bicgstab ( pbsf , pFf1 , pb_AFf0 );
	blas_axpby_Field3D_MPI ( pFf0 , pFf0 , 5.00000000000000000e-01 , pFf1 , 5.00000000000000000e-01 );
	MPI_dm_bihamt_dual_psi_eqn_J ( pFf0 , pF0 , pA0 , pA2 , M_DM_DT , M_DELTA_Z , M_DELTA_Y , M_DELTA_X , M_DM_A , M_DM_Q0 , M_DM_M0 );

	}else{
			MPI_dm_cayley_eqn_J ( pF0 , pF0 , pA0 , pA2 , M_DM_DT , M_DELTA_Z , M_DELTA_Y , M_DELTA_X , M_DM_A , M_DM_Q0 , M_DM_M0 );

	 }
	blas_axpy_Field3D_MPI ( pA1 , pA1 , M_DM_DT , pA2 );
	MPI_dm_exact_eqn_m ( pF0 , pF1 , pA0 , pA2 , M_DM_DT , M_DELTA_Z , M_DELTA_Y , M_DELTA_X , M_DM_A , M_DM_Q0 , M_DM_M0 );
	blas_yisax_Field3D_MPI ( pF1 , pF1 , 1 , pF0 );
	if (  M_DM_DUAL_FIELD  ){  
			MPI_dm_exact_eqn_m ( pFf0 , pFf1 , pA0 , pA2 , M_DM_DT , M_DELTA_Z , M_DELTA_Y , M_DELTA_X , M_DM_A , M_DM_Q0 , M_DM_M0 );
	blas_yisax_Field3D_MPI ( pFf1 , pFf1 , 1 , pFf0 );

	}else{
		0;

	 }
	blas_axpy_Field3D_MPI ( pA0 , pA0 , M_DM_DT , pA1 );
	sync_ovlp_mpi_field ( pA0 );
	MPI_dm_bihamt_eqn_dydt ( pF0 , pF1 , pA0 , pA1 , M_DM_DT , M_DELTA_Z , M_DELTA_Y , M_DELTA_X , M_DM_A , M_DM_Q0 , M_DM_M0 );

	 }
	void *  ftmp ;
	if (  use_old_unstable_alg  ){  
		(ftmp = pF0);
(pF0 = pF1);
(pF1 = ftmp);
(ftmp = pA0);
(pA0 = pA1);
(pA1 = pA2);
(pA2 = ftmp);

	}else{
		0;

	 }
}}
	}else{
			double *  pnpm = 	malloc ( 	(  sizeof(double ) * NUM_SPEC ) ) ;
{
	long  i ;
	for ((i = 0) ; 	(  i < NUM_SPEC ) ; (i = 	(  i + 1 )))
	{
((pnpm)[i] = 	call_GET_NPM ( i ));
}}	double *  pchg = 	malloc ( 	(  sizeof(double ) * NUM_SPEC ) ) ;
{
	long  i ;
	for ((i = 0) ; 	(  i < NUM_SPEC ) ; (i = 	(  i + 1 )))
	{
((pchg)[i] = 	call_GET_CHARGE ( i ));
}}	double *  pmass = 	malloc ( 	(  sizeof(double ) * NUM_SPEC ) ) ;
{
	long  i ;
	for ((i = 0) ; 	(  i < NUM_SPEC ) ; (i = 	(  i + 1 )))
	{
((pmass)[i] = 	call_GET_MASS ( i ));
}}	long *  pgcache = 	malloc ( 	(  sizeof(long ) * NUM_SPEC ) ) ;
{
	long  i ;
	for ((i = 0) ; 	(  i < NUM_SPEC ) ; (i = 	(  i + 1 )))
	{
((pgcache)[i] = 	call_GET_GRID_CACHE_LEN ( i ));
}}	long *  pcucache = 	malloc ( 	(  sizeof(long ) * NUM_SPEC ) ) ;
{
	long  i ;
	for ((i = 0) ; 	(  i < NUM_SPEC ) ; (i = 	(  i + 1 )))
	{
((pcucache)[i] = 	call_GET_CU_CACHE_LEN ( i ));
}}	Particle_in_Cell_MPI  pis ;
	Particle_in_Cell_MPI *  ppis = 	& ( pis ) ;
	double  M_USE_TYPE3_KERNEL = 	call_GET_VAR ( "USE_TYPE3_KERNEL" ) ;
	double  M_USE_SMALL_NUM_GRIDS = 	call_GET_VAR ( "USE_SMALL_NUM_GRIDS" ) ;
	double  M_USE_USER_DEFINED_PARTICLE_DISTRIBUTION = 	call_GET_VAR ( "USE_USER_DEFINED_PARTICLE_DISTRIBUTION" ) ;
	double  M_USE_INIT_PARTICLE_FILE = 	call_GET_VAR ( "USE_INIT_PARTICLE_FILE" ) ;
	double  M_USE_DUMP_PARTICLE_FILE = 	call_GET_VAR ( "USE_DUMP_PARTICLE_FILE" ) ;
	double  M_USE_ITG_MODE = 	call_GET_VAR ( "USE_ITG_MODE" ) ;
	double  M_ITG_ENE_CONS = 	call_GET_VAR ( "ITG_ENE_CONS" ) ;
	double  M_ITG_CONST_NE0 = 	call_GET_VAR ( "ITG_CONST_NE0" ) ;
	double  M_USE_SMALL_TIMESTEP_MODE = 	call_GET_VAR ( "USE_SMALL_TIMESTEP_MODE" ) ;
	double  M_USE_MULTI_STEP = 	call_GET_VAR ( "USE_MULTI_STEP" ) ;
	double  M_ITG_GC = 	call_GET_VAR ( "ITG_GC" ) ;
	double  M_USE_DEBUG = 	call_GET_VAR ( "USE_DEBUG" ) ;
	double  M_NUM_MULTI_STEP_SORT = 	call_GET_VAR ( "NUM_MULTI_STEP_SORT" ) ;
	int  num_multi_step_sort = ((	(  M_NUM_MULTI_STEP_SORT == 0 ))?(1):(M_NUM_MULTI_STEP_SORT)) ;
	assert ( 	(  num_multi_step_sort > 0 ) );
	double  M_ITG_B0 ;
	double  M_ITG_MIN_R0 ;
	double  M_ITG_MAJ_R0 ;
	double  M_ITG_Q0 ;
	double  M_ITG_ZMID ;
	double  G_USE_NON_UNI_IO_FOR_EACH_SPEC = 	call_GET_VAR ( "USE_NON_UNI_IO_FOR_EACH_SPEC" ) ;
	if (  	(  	(  M_USE_ITG_MODE != 0 ) && 	(  USE_TORI != 0 ) )  ){  
		(M_ITG_B0 = 	call_GET_VAR ( "ITG_B0" ));
(M_ITG_MIN_R0 = 	call_GET_VAR ( "ITG_MIN_R0" ));
(M_ITG_MAJ_R0 = 	call_GET_VAR ( "ITG_MAJ_R0" ));
(M_ITG_Q0 = 	call_GET_VAR ( "ITG_Q0" ));
(M_ITG_ZMID = 	call_GET_VAR ( "ITG_ZMID" ));

	}else{
		0;

	 }
	double  T_TORI_X0 ;
	double  T_TORI_SOLVE_ERR ;
	if (  USE_TORI  ){  
		(T_TORI_X0 = 	call_GET_VAR ( "TORI_X0" ));
(T_TORI_SOLVE_ERR = 	call_GET_VAR ( "TORI_SOLVE_ERR" ));

	}else{
		0;

	 }
	int *  p_particle_type = 	malloc ( 	(  sizeof(int ) * NUM_SPEC ) ) ;
{
	long  i ;
	for ((i = 0) ; 	(  i < NUM_SPEC ) ; (i = 	(  i + 1 )))
	{
	if (  M_USE_SMALL_TIMESTEP_MODE  ){  
		((p_particle_type)[i] = 	call_CAL_FUN_ONE_PARA ( "GET_PARTICLE_TYPE" , i ));

	}else{
		((p_particle_type)[i] = 0);

	 }
}}	init_global_particles ( ppis , ptestfield , ptestfieldSPEC , M_USE_SMALL_NUM_GRIDS , G_USE_PML_ABC_DIR , G_PML_LEVEL , G_PML_SIGMA_MAX , DELTAT , NUM_SPEC , allxyzmax , pmass , pchg , pnpm , pgcache , pcucache , p_particle_type , M_USE_REDUCE_DIM , M_REDUCE_DIM_X_RAT , M_REDUCE_DIM_Y_RAT , M_REDUCE_DIM_Z_RAT , M_REDUCE_DIM_RANDOM_RATE );
	if (  	(  M_USE_ITG_MODE && USE_TORI )  ){  
			sync_ovlp_mpi_field ( 	& ( 	( ppis )->MPI_fieldB_ext ) );

	}else{
		0;

	 }
	if (  M_USE_DEBUG  ){  
			fprintf ( stderr , "dumping debug field\n" );
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	init_parallel_file_for_mpi_fields ( ptestfield , pgid , "tmpField_dbg" , -1 , G_GAPSIO_VERSION , G_GAPSIO_NUM_REDUCEWRITE );
	mpi_field_write_to_file ( 	& ( 	( ppis )->MPI_fieldE ) , pgid , 0 );
	mpi_field_write_to_file ( 	& ( 	( ppis )->MPI_fieldB ) , pgid , 1 );
	mpi_field_write_to_file ( 	& ( 	( ppis )->MPI_fieldE_ext ) , pgid , 2 );
	mpi_field_write_to_file ( 	& ( 	( ppis )->MPI_fieldB_ext ) , pgid , 3 );

	}else{
		0;

	 }
	jfnk_newton_space  jns ;
	if (  M_USE_SMALL_TIMESTEP_MODE  ){  
			init_implicit_particle_mpi ( ppis );
	init_jfnk_newton_space ( 	& ( jns ) , 	& ( ppis->MPI_fieldE ) , one_step_calc_current , 9.99999999999999980e-13 , 1.00000000000000008e-05 , 4 , 4 , 9.99999999999999955e-07 , ppis );
	jfnk_newton_init_parameters ( 	& ( jns ) , 1 , 1 , pmass , pchg );
	if (  USE_INIT_EB0  ){  
			blas_yisax_Field3D_MPI ( 	& ( ppis->MPI_fieldEtmp1 ) , 	& ( ppis->MPI_fieldEtmp1 ) , 1 , 	& ( ppis->MPI_fieldE ) );
	blas_yisax_Field3D_MPI ( 	& ( ppis->MPI_fieldBtmp1 ) , 	& ( ppis->MPI_fieldBtmp1 ) , 1 , 	& ( ppis->MPI_fieldB ) );

	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  M_USE_ITG_MODE  ){  
			blas_yisax_Field3D_MPI ( 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_fieldB1 ) , -1 , 	& ( ppis->MPI_fieldE ) );

	}else{
		0;

	 }
	if (  0  ){  
			init_single_particle_fmpi ( 	& ( 	( ppis )->MPI_fieldE ) );

	}else{
			if (  M_USE_USER_DEFINED_PARTICLE_DISTRIBUTION  ){  
			init_user_defined_particle_fmpi ( 	& ( 	( ppis )->MPI_fieldE ) );
	call_particle_sort_mpi ( ppis , 0 , 0 );
	call_particle_sort_mpi ( ppis , 1 , 0 );
	call_particle_sort_mpi ( ppis , 2 , 0 );

	}else{
			if (  M_USE_INIT_PARTICLE_FILE  ){  
			Gaps_IO_DataFile  gid_grid ;
	Gaps_IO_DataFile *  pgid_grid = 	& ( gid_grid ) ;
	Gaps_IO_DataFile  gid_cu ;
	Gaps_IO_DataFile *  pgid_cu = 	& ( gid_cu ) ;
	init_parallel_file_particle_for_mpi_fields_V0 ( 	& ( 	( ppis )->MPI_fieldE ) , pgid_grid , pgid_cu , pgcache , pcucache , "GRID_PARTICLE_file" , "CU_PARTICLE_file" , 0 , 1 );
	fprintf ( stderr , "rank=%d, Loading particles ...\n" , rank );
	if (  	(  M_USE_REDUCE_DIM && 	(  ! M_USE_NOT_REDUCE_DIM_PARTICLE ) )  ){  
			read_particle_parallel_file_for_mpi_fields_V0 ( 	& ( 	( ppis )->MPI_fieldE ) , pgid_grid , pgid_cu , pgcache , pcucache , 0 , M_USE_REDUCE_DIM , M_REDUCE_DIM_X_RAT , M_REDUCE_DIM_Y_RAT , M_REDUCE_DIM_Z_RAT , G_USE_NON_UNI_IO_FOR_EACH_SPEC );

	}else{
			read_particle_parallel_file_for_mpi_fields_V0 ( 	& ( 	( ppis )->MPI_fieldE ) , pgid_grid , pgid_cu , pgcache , pcucache , 0 , 0 , 1 , 1 , 1 , G_USE_NON_UNI_IO_FOR_EACH_SPEC );

	 }
	GAPS_IO_DeleteDataInfo ( pgid_cu );
	GAPS_IO_DeleteDataInfo ( pgid_grid );

	}else{
			if (  USE_NON_UNI_DENSITY  ){  
			double  M_INIT_VMAX = 	call_GET_VAR ( "INIT_VMAX" ) ;
	if (  	(  M_INIT_VMAX == 0 )  ){  
		(M_INIT_VMAX = 1);

	}else{
		0;

	 }
	init_non_uni_particle_fmpi ( 	& ( 	( ppis )->MPI_fieldE ) , M_INIT_VMAX );

	}else{
			init_maxwell_dist_particle_fmpi ( 	& ( 	( ppis )->MPI_fieldE ) );
	init_dist_particle_nogrid_fmpi ( 	& ( 	( ppis )->MPI_fieldE ) , 1 );

	 }

	 }

	 }

	 }
	char   fname1  [100];	sprintf ( fname1 , "dbg1%d" , rank );
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	Gaps_IO_DataFile  gidj ;
	Gaps_IO_DataFile *  pgidj = 	& ( gidj ) ;
	Gaps_IO_DataFile  gide ;
	Gaps_IO_DataFile *  pgide = 	& ( gide ) ;
	Field3D_MPI  aver_E ;
	Field3D_MPI *  paver_E = 	& ( aver_E ) ;
	Field3D_MPI  aver_B ;
	Field3D_MPI *  paver_B = 	& ( aver_B ) ;
	Field3D_MPI  aver_J ;
	Field3D_MPI *  paver_J = 	& ( aver_J ) ;
	Field3D_MPI  aver_EN ;
	Field3D_MPI *  paver_EN = 	& ( aver_EN ) ;
	Field3D_MPI  ext_krook ;
	Field3D_MPI *  pext_krook = 	& ( ext_krook ) ;
	Field3D_MPI  ext_rho_dist ;
	Field3D_MPI *  pext_rho_dist = 	& ( ext_rho_dist ) ;
	init_Field3D_MPI_from ( paver_E , ptestfield );
	init_Field3D_MPI_from ( paver_B , ptestfield );
	init_Field3D_MPI_from ( paver_J , ptestfield );
	init_Field3D_MPI_from ( pext_rho_dist , ptestfield );
	init_Field3D_MPI_from_new_num_ele ( pext_krook , ptestfield , 6 );
	init_Field3D_MPI_from ( paver_EN , ptestfieldSPEC );
	blas_yiszero_Field3D_MPI ( paver_E , paver_E );
	blas_yiszero_Field3D_MPI ( paver_B , paver_B );
	blas_yiszero_Field3D_MPI ( paver_J , paver_J );
	blas_yiszero_Field3D_MPI ( paver_EN , paver_EN );
	double  G_CHECKPOINT_TIME = 	call_GET_VAR ( "CHECKPOINT_TIME" ) ;
	double  G_CHECKPOINT_NUM_SAVE = 	call_GET_VAR ( "CHECKPOINT_NUM_SAVE" ) ;
	double  G_CHECKPOINT_NUM_REDUCEWRITE = 	call_GET_VAR ( "CHECKPOINT_NUM_REDUCEWRITE" ) ;
	double  G_USE_KROOK_FIELD = 	call_GET_VAR ( "USE_KROOK_FIELD" ) ;
	double  G_KROOK_MU_FREQ = 	call_GET_VAR ( "KROOK_MU_FREQ" ) ;
	double  G_USE_BORIS_YEE = 	call_GET_VAR ( "USE_BORIS_YEE" ) ;
	double  G_KROOK_SPEED_LIMIT = 	call_GET_VAR ( "KROOK_SPEED_LIMIT" ) ;
	double  G_STS_N = 	call_GET_VAR ( "STS_N" ) ;
	if (  	(  G_CHECKPOINT_NUM_REDUCEWRITE == 0 )  ){  
		(G_CHECKPOINT_NUM_REDUCEWRITE = 1);

	}else{
		0;

	 }
	int  cur_proc = rank ;
	int  num_max_proc ;
	PS_MPI_Comm_size ( PS_MPI_COMM_WORLD , 	& ( num_max_proc ) );
	int  num_one_group = G_CHECKPOINT_NUM_REDUCEWRITE ;
	double  M_USE_AVER_OUTPUT = 	call_GET_VAR ( "USE_AVER_OUTPUT" ) ;
	double  M_USE_1ST = 	call_GET_VAR ( "USE_1ST" ) ;
	double  M_USE_OUTPUT_PERFORMANCE = 	call_GET_VAR ( "USE_OUTPUT_PERFORMANCE" ) ;
	if (  	(  G_KROOK_MU_FREQ || G_USE_KROOK_FIELD )  ){  
			init_external_field3d_FILTER_KROOK_2d_extend ( pext_krook , reduce_dim , 1 , 1 , 1 );

	}else{
		0;

	 }
	double  sts_nv = 1.00000000000000008e-05 ;
	if (  G_STS_N  ){  
			double  G_STS_NV = 	call_GET_VAR ( "STS_NV" ) ;
(sts_nv = G_STS_NV);

	}else{
		0;

	 }
{
	test_set_mainland ( 	& ( ppis->MPI_FoutJ ) , 0.00000000000000000e+00 );
	sync_main_data_h2d ( 	& ( ppis->MPI_FoutJ ) );
	long  t = 0 ;
	long  tsave = 0 ;
	int  current_check = 0 ;
	if (  USE_CHECKPOINT  ){  
			fprintf ( stderr , "rank=%d, Loading...\n" , rank );
	FILE *  fp = 	load_identity_state_and_alloc_file_pointer ( rank , num_one_group ) ;
	int  ifexistfp = fp ;
	PS_MPI_Bcast ( 	& ( ifexistfp ) , 1 , PS_MPI_INT , 0 , PS_MPI_COMM_WORLD );
	if (  ifexistfp  ){  
			load_long ( fp , 	& ( t ) , cur_proc , num_one_group , num_max_proc );
	load_long ( fp , 	& ( tsave ) , cur_proc , num_one_group , num_max_proc );
	load_Particle_in_Cell_MPI ( fp , ppis , cur_proc , num_one_group , num_max_proc );
	if (  M_USE_AVER_OUTPUT  ){  
			load_Field3D_MPI ( fp , paver_E , cur_proc , num_one_group , num_max_proc );
	load_Field3D_MPI ( fp , paver_B , cur_proc , num_one_group , num_max_proc );
	load_Field3D_MPI ( fp , paver_J , cur_proc , num_one_group , num_max_proc );
	load_Field3D_MPI ( fp , paver_EN , cur_proc , num_one_group , num_max_proc );

	}else{
		0;

	 }
	if (  fp  ){  
			fclose ( fp );

	}else{
		0;

	 }
(current_check = 1);

	}else{
			if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "Warning: unable to locate the saved checkpoints, will creating new one\n" );

	}else{
		0;

	 }

	 }
	fprintf ( stderr , "rank=%d, Done\n" , rank );
{
	long  tn_new ;
	if (  	(  rank == 0 )  ){  
			PS_MPI_Bcast ( 	& ( t ) , 1 , PS_MPI_LONG_LONG , 0 , PS_MPI_COMM_WORLD );

	}else{
			PS_MPI_Bcast ( 	& ( tn_new ) , 1 , PS_MPI_LONG_LONG , 0 , PS_MPI_COMM_WORLD );
	if (  	(  t != tn_new )  ){  
			fprintf ( stderr , "Error: the checkpoints are not saved in the same time step! rank=%d t=%ld, t should be %ld" , rank , t , tn_new );
	PS_MPI_Abort ( PS_MPI_COMM_WORLD , -1 );

	}else{
		0;

	 }

	 }
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
}	if (  G_CHECKPOINT_TIME  ){  
		(t = G_CHECKPOINT_TIME);

	}else{
		0;

	 }
	if (  G_CHECKPOINT_NUM_SAVE  ){  
		(tsave = G_CHECKPOINT_NUM_SAVE);

	}else{
		0;

	 }

	}else{
		0;

	 }
{
	long  newtsave = ((tsave)?(tsave):(-1)) ;
	fprintf ( stderr , "tsave=%d\n" , tsave );
	init_parallel_file_for_mpi_fields ( ptestfield , pgid , "tmpEB" , newtsave , G_GAPSIO_VERSION , G_GAPSIO_NUM_REDUCEWRITE );
	init_parallel_file_for_mpi_fields ( ptestfield , pgidj , "tmpJ" , newtsave , G_GAPSIO_VERSION , G_GAPSIO_NUM_REDUCEWRITE );
	init_parallel_file_for_mpi_fields ( ptestfieldSPEC , pgide , "tmpEN" , newtsave , G_GAPSIO_VERSION , G_GAPSIO_NUM_REDUCEWRITE );
}	double  tbeg = 	wclk_now (  ) ;
	double  tend = tbeg ;
	double  G_USE_ECRH_INPUT = 	call_GET_VAR ( "USE_ECRH_INPUT" ) ;
	double  G_USE_REL = 	call_GET_VAR ( "USE_REL" ) ;
	double  G_NUM_HIGH_ORDER_L = 	call_GET_VAR ( "NUM_HIGH_ORDER_L" ) ;
	double  G_USE_MULTIPLE_PARTICLE_DUMP = 	call_GET_VAR ( "USE_MULTIPLE_PARTICLE_DUMP" ) ;
	double  G_USE_FIXB_DIR = 	call_GET_VAR ( "USE_FIXB_DIR" ) ;
	double  G_USE_CALC_EQ_B = 	call_GET_VAR ( "USE_CALC_EQ_B" ) ;
	if (  G_USE_REL  ){  
		(T_TORI_X0 = 	call_GET_VAR ( "TORI_X0" ));
(T_TORI_SOLVE_ERR = 	call_GET_VAR ( "TORI_SOLVE_ERR" ));

	}else{
		0;

	 }
	double  curt_profile_only = 	wclk_now (  ) ;
	if (  M_USE_ITG_MODE  ){  
			init_external_field3d_DENSITY_DIST ( pext_rho_dist );

	}else{
		0;

	 }
	int  ext_field_set = 0 ;
	long  t0 = t ;
	for (0 ; t<NUM_TIMESTEP ; t++)
	{
	if (  	(  USE_CHECKPOINT && 	(  0 == 	(  t % NUM_CHECKPOINT_TIMESTEP ) ) )  ){  
			fprintf ( stderr , "rank=%d, Saving...\n" , rank );
	if (  	(  ! current_check )  ){  
			FILE *  fp = 	save_identity_state_and_alloc_file_pointer ( rank , num_one_group ) ;
	save_long ( fp , 	& ( t ) , cur_proc , num_one_group , num_max_proc );
	save_long ( fp , 	& ( tsave ) , cur_proc , num_one_group , num_max_proc );
	save_Particle_in_Cell_MPI ( fp , ppis , cur_proc , num_one_group , num_max_proc );
	if (  M_USE_AVER_OUTPUT  ){  
			save_Field3D_MPI ( fp , paver_E , cur_proc , num_one_group , num_max_proc );
	save_Field3D_MPI ( fp , paver_B , cur_proc , num_one_group , num_max_proc );
	save_Field3D_MPI ( fp , paver_J , cur_proc , num_one_group , num_max_proc );
	save_Field3D_MPI ( fp , paver_EN , cur_proc , num_one_group , num_max_proc );

	}else{
		0;

	 }
	if (  fp  ){  
			fclose ( fp );

	}else{
		0;

	 }

	}else{
		(current_check = 0);

	 }
	if (  M_USE_DUMP_PARTICLE_FILE  ){  
			long  numdump = 	(  t / NUM_CHECKPOINT_TIMESTEP ) ;
	if (  	(  ! ((int )G_USE_MULTIPLE_PARTICLE_DUMP) )  ){  
		(numdump = 0);

	}else{
		0;

	 }
	Gaps_IO_DataFile  gid_grid ;
	Gaps_IO_DataFile *  pgid_grid = 	& ( gid_grid ) ;
	Gaps_IO_DataFile  gid_cu ;
	Gaps_IO_DataFile *  pgid_cu = 	& ( gid_cu ) ;
	init_parallel_file_particle_for_mpi_fields_V0 ( 	& ( 	( ppis )->MPI_fieldE ) , pgid_grid , pgid_cu , pgcache , pcucache , "tmpGRID_PARTICLE_file" , "tmpCU_PARTICLE_file" , numdump , ((numdump)?(0):(0)) );
{
	int  msg = 0 ;
	MPI_Status  st ;
	if (  	(  rank != 0 )  ){  
			PS_MPI_Recv ( 	& ( msg ) , 1 , PS_MPI_INT , 	(  rank - 1 ) , 	(  rank - 1 ) , PS_MPI_COMM_WORLD , 	& ( st ) );

	}else{
		0;

	 }
	dump_particle_parallel_file_for_mpi_fields_V0 ( 	& ( 	( ppis )->MPI_fieldE ) , pgid_grid , pgid_cu , pgcache , pcucache , numdump , G_USE_NON_UNI_IO_FOR_EACH_SPEC );
	if (  	(  rank != 	(  NUM_PROCESS - 1 ) )  ){  
			PS_MPI_Send ( 	& ( msg ) , 1 , PS_MPI_INT , 	(  rank + 1 ) , rank , PS_MPI_COMM_WORLD );

	}else{
		0;

	 }
}	fprintf ( stderr , "rank=%d, Saving particles ...\n" , rank );
	GAPS_IO_DeleteDataInfo ( pgid_cu );
	GAPS_IO_DeleteDataInfo ( pgid_grid );
	if (  	(  rank == 0 )  ){  
			FILE *  fp = 	fopen ( "CHECKPOINT_TIME.ss" , "wb" ) ;
	fprintf ( fp , "(define CHECKPOINT_TIME %d)\n" , t );
	fprintf ( fp , "(define CHECKPOINT_NUM_SAVE %d)\n" , tsave );
	fclose ( fp );

	}else{
		0;

	 }

	}else{
		0;

	 }
	fprintf ( stderr , "rank=%d, Done\n" , rank );

	}else{
		0;

	 }
	if (  	(  0 && 	(  rank == 0 ) )  ){  
			fprintf ( stdout , "%d\n" , t );
	sync_main_data_d2h ( 	& ( ppis->MPI_fieldE ) );
(((((double * * )	( ppis->MPI_fieldE.data )->main_data))[0])[	(  	(  0 * 	(  	( ppis->MPI_fieldE.data )->xblock * 	(  	( ppis->MPI_fieldE.data )->yblock * 	(  	( ppis->MPI_fieldE.data )->zblock * 	( ppis->MPI_fieldE.data )->num_ele ) ) ) ) + 	(  0 + 	(  	( ppis->MPI_fieldE.data )->num_ele * 	(  	(  7 + 	( ppis->MPI_fieldE.data )->ovlp ) + 	(  	( ppis->MPI_fieldE.data )->xblock * 	(  	(  7 + 	( ppis->MPI_fieldE.data )->ovlp ) + 	(  	( ppis->MPI_fieldE.data )->yblock * 	(  0 + 	( ppis->MPI_fieldE.data )->ovlp ) ) ) ) ) ) ) )] = 	(  ((((double * * )	( ppis->MPI_fieldE.data )->main_data))[0])[	(  	(  0 * 	(  	( ppis->MPI_fieldE.data )->xblock * 	(  	( ppis->MPI_fieldE.data )->yblock * 	(  	( ppis->MPI_fieldE.data )->zblock * 	( ppis->MPI_fieldE.data )->num_ele ) ) ) ) + 	(  0 + 	(  	( ppis->MPI_fieldE.data )->num_ele * 	(  	(  7 + 	( ppis->MPI_fieldE.data )->ovlp ) + 	(  	( ppis->MPI_fieldE.data )->xblock * 	(  	(  7 + 	( ppis->MPI_fieldE.data )->ovlp ) + 	(  	( ppis->MPI_fieldE.data )->yblock * 	(  0 + 	( ppis->MPI_fieldE.data )->ovlp ) ) ) ) ) ) ) )] + 	sin ( 	(  t * DELTAT ) ) ));
	sync_main_data_h2d ( 	& ( ppis->MPI_fieldE ) );

	}else{
		0;

	 }
	if (  M_USE_AVER_OUTPUT  ){  
			blas_axpby_Field3D_MPI ( paver_E , paver_E , 	(  1.00000000000000000e+00 / NUM_DUMP_TIMESTEP ) , 	& ( ppis->MPI_fieldE ) , 1.00000000000000000e+00 );
	blas_axpby_Field3D_MPI ( paver_B , paver_B , 	(  1.00000000000000000e+00 / NUM_DUMP_TIMESTEP ) , 	& ( ppis->MPI_fieldB ) , 1.00000000000000000e+00 );
	blas_axpby_Field3D_MPI ( paver_J , paver_J , 	(  1.00000000000000000e+00 / NUM_DUMP_TIMESTEP ) , ppis->pMPI_FoutJ , 1.00000000000000000e+00 );
	blas_yiszero_Field3D_MPI ( ptestfieldSPEC , ptestfieldSPEC );
	dump_ene_num_mpi ( ppis , 0 );
	sync_main_data_d2h ( ptestfieldSPEC );
	blas_axpby_Field3D_MPI ( paver_EN , paver_EN , 	(  1.00000000000000000e+00 / NUM_DUMP_TIMESTEP ) , ptestfieldSPEC , 1.00000000000000000e+00 );

	}else{
		0;

	 }
	if (  	(  0 == 	(  t % NUM_DUMP_TIMESTEP ) )  ){  
			if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "outputing..." );

	}else{
		0;

	 }
	if (  M_USE_OUTPUT_PERFORMANCE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );

	}else{
		0;

	 }
	double  tbeg = 	wclk_now (  ) ;
	if (  M_USE_AVER_OUTPUT  ){  
			sync_main_data_d2h ( paver_E );
	sync_main_data_d2h ( paver_B );
	sync_main_data_d2h ( paver_J );
	sync_main_data_d2h ( paver_EN );
	mpi_field_write_to_file ( paver_E , pgid , 	(  tsave * 2 ) );
	mpi_field_write_to_file ( paver_B , pgid , 	(  	(  tsave * 2 ) + 1 ) );
	mpi_field_write_to_file ( paver_J , pgidj , tsave );
	mpi_field_write_to_file ( paver_EN , pgide , tsave );
	blas_yiszero_Field3D_MPI ( paver_E , paver_E );
	blas_yiszero_Field3D_MPI ( paver_B , paver_B );
	blas_yiszero_Field3D_MPI ( paver_J , paver_J );
	blas_yiszero_Field3D_MPI ( paver_EN , paver_EN );

	}else{
			sync_main_data_d2h ( 	& ( ppis->MPI_fieldB ) );
	sync_main_data_d2h ( 	& ( ppis->MPI_fieldE ) );
	sync_main_data_d2h ( ppis->pMPI_FoutJ );
	mpi_field_write_to_file ( 	& ( ppis->MPI_fieldE ) , pgid , 	(  tsave * 2 ) );
	mpi_field_write_to_file ( 	& ( ppis->MPI_fieldB ) , pgid , 	(  	(  tsave * 2 ) + 1 ) );
	mpi_field_write_to_file ( ppis->pMPI_FoutJ , pgidj , tsave );
	blas_yiszero_Field3D_MPI ( ptestfieldSPEC , ptestfieldSPEC );
	dump_ene_num_mpi ( ppis , 0 );
	sync_main_data_d2h ( ptestfieldSPEC );
	mpi_field_write_to_file ( ptestfieldSPEC , pgide , tsave );

	 }
	GAPS_IO_FileFlush ( pgid );
	GAPS_IO_FileFlush ( pgidj );
	GAPS_IO_FileFlush ( pgide );
	if (  M_USE_OUTPUT_PERFORMANCE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );

	}else{
		0;

	 }
(tbeg = 	(  	wclk_now (  ) - tbeg ));
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "done, time used=%fs\n" , tbeg );

	}else{
		0;

	 }
(tsave = 	(  tsave + 1 ));

	}else{
		0;

	 }
	if (  USE_LHCD_INPUT  ){  
			double  L_LHCD_FREQ = 	call_GET_VAR ( "LHCD_FREQ" ) ;
	double  L_LHCD_K = 	call_GET_VAR ( "LHCD_K" ) ;
	double  L_LHCD_SOURCE_LOCATION = 	call_GET_VAR ( "LHCD_SOURCE_LOCATION" ) ;
	double  L_LHCD_AMPX = 	call_GET_VAR ( "LHCD_AMPX" ) ;
	double  L_LHCD_AMPY = 	call_GET_VAR ( "LHCD_AMPY" ) ;
	set_lhcd_fields ( 	& ( ppis->MPI_fieldE ) , 	(  t * 	(  L_LHCD_FREQ * DELTAT ) ) , L_LHCD_K , L_LHCD_SOURCE_LOCATION , L_LHCD_AMPX , L_LHCD_AMPY );

	}else{
		0;

	 }
	if (  ((int )G_USE_ECRH_INPUT)  ){  
			double  E_ECRH_FREQ = 	call_GET_VAR ( "ECRH_FREQ" ) ;
	double  E_ECRH_AMPX = 	call_GET_VAR ( "ECRH_AMPX" ) ;
	double  E_ECRH_AMPY = 	call_GET_VAR ( "ECRH_AMPY" ) ;
	double  E_ECRH_AMPZ = 	call_GET_VAR ( "ECRH_AMPZ" ) ;
	double  E_ECRH_KY = 	call_GET_VAR ( "ECRH_KY" ) ;
	double  E_ECRH_KZ = 	call_GET_VAR ( "ECRH_KZ" ) ;
	double  E_ECRH_LOC_X0 = 	call_GET_VAR ( "ECRH_LOC_X0" ) ;
	double  E_ECRH_LOC_Y0 = 	call_GET_VAR ( "ECRH_LOC_Y0" ) ;
	double  E_ECRH_LOC_Y1 = 	call_GET_VAR ( "ECRH_LOC_Y1" ) ;
	double  E_ECRH_LOC_Z0 = 	call_GET_VAR ( "ECRH_LOC_Z0" ) ;
	double  E_ECRH_LOC_Z1 = 	call_GET_VAR ( "ECRH_LOC_Z1" ) ;
	double  E_ECRH_IKT = 	call_GET_VAR ( "ECRH_IKT" ) ;
	double  E_ECRH_SQUARE_NUM = 	call_GET_VAR ( "ECRH_SQUARE_NUM" ) ;
	double  E_ECRH_PHASE_0 = 	call_GET_VAR ( "ECRH_PHASE_0" ) ;
	set_ecrh_fields ( ((M_USE_ITG_MODE)?(	& ( ppis->MPI_fieldE_ext )):(	& ( ppis->MPI_fieldE ))) , 	(  t * 	(  E_ECRH_FREQ * DELTAT ) ) , E_ECRH_AMPX , E_ECRH_AMPY , E_ECRH_AMPZ , E_ECRH_KY , E_ECRH_KZ , E_ECRH_IKT , E_ECRH_LOC_X0 , E_ECRH_LOC_Y0 , E_ECRH_LOC_Y1 , E_ECRH_LOC_Z0 , E_ECRH_LOC_Z1 , E_ECRH_SQUARE_NUM , E_ECRH_PHASE_0 );

	}else{
		0;

	 }
{
	double  outter_dt = DELTAT ;
	int  sts_n = G_STS_N ;
	if (  	(  sts_n == 0 )  ){  
		(sts_n = 1);

	}else{
		0;

	 }
	double  total_dt = 0 ;
{
	long  i ;
	for ((i = 0) ; 	(  i < sts_n ) ; (i = 	(  i + 1 )))
	{
(total_dt = 	(  total_dt + 	gen_sts_dt ( 	(  i + 1 ) , sts_n , sts_nv ) ));
}}	double  sts_basic_dt = 	(  outter_dt / total_dt ) ;
{
	long  i ;
	for ((i = 0) ; 	(  i < sts_n ) ; (i = 	(  i + 1 )))
	{
	double  DELTAT = 	(  sts_basic_dt * 	gen_sts_dt ( 	(  i + 1 ) , sts_n , sts_nv ) ) ;
	if (  	(  	(  USE_TORI || G_USE_REL ) && 	(  ! M_USE_ITG_MODE ) )  ){  
			if (  M_USE_NO_CURRENT  ){  
			if (  	(  USE_INIT_EXT_EB && 	(  ! ext_field_set ) )  ){  
		(ext_field_set = 	(  ext_field_set + 1 ));
	blas_yisax_Field3D_MPI ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldE ) , 1 , 	& ( ppis->MPI_fieldE_ext ) );
	blas_yisax_Field3D_MPI ( 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB ) , 1 , 	& ( ppis->MPI_fieldB_ext ) );
	blas_yisax_Field3D_MPI ( 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_fieldB1 ) , 1 , 	& ( ppis->MPI_fieldB_ext ) );
	sync_ovlp_mpi_field ( 	& ( ppis->MPI_fieldE ) );
	sync_ovlp_mpi_field ( 	& ( ppis->MPI_fieldB ) );
	sync_ovlp_mpi_field ( 	& ( ppis->MPI_fieldB1 ) );

	}else{
		0;

	 }

	}else{
			blas_yisax_Field3D_MPI ( 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_fieldB1 ) , 1.00000000000000000e+00 , 	& ( ppis->MPI_fieldB ) );
	if (  G_USE_PML_ABC_DIR  ){  
			Field3D_MPI  MPI_fieldE = 	( ppis )->MPI_fieldE ;
	Field3D_MPI  MPI_fieldB = 	( ppis )->MPI_fieldB ;
	Field3D_MPI  MPI_fieldB1 = 	( ppis )->MPI_fieldB1 ;
	Field3D_MPI  MPI_FoutJ = 	( ppis )->MPI_FoutJ ;
	Field3D_MPI  MPI_LFoutJ = 	( ppis )->MPI_LFoutJ ;
	Field3D_MPI  MPI_fieldEtmp = 	( ppis )->MPI_fieldEtmp ;
	Field3D_MPI  MPI_fieldEtmp1 = 	( ppis )->MPI_fieldEtmp1 ;
	Field3D_MPI  MPI_fieldEtmp2 = 	( ppis )->MPI_fieldEtmp2 ;
	Field3D_MPI  MPI_fieldBtmp1 = 	( ppis )->MPI_fieldBtmp1 ;
	Field3D_MPI  MPI_fieldPMLB = 	( ppis )->MPI_fieldPMLB ;
	Field3D_MPI  MPI_fieldPMLE = 	( ppis )->MPI_fieldPMLE ;
	Field3D_MPI *  pMPI_FoutJ = 	( ppis )->pMPI_FoutJ ;
	Field3D_MPI *  pMPI_FoutEN = 	( ppis )->pMPI_FoutEN ;
	Field3D_MPI  MPI_fieldE_ext = 	( ppis )->MPI_fieldE_ext ;
	Field3D_MPI  MPI_fieldB_ext = 	( ppis )->MPI_fieldB_ext ;
	Field3D_MPI  MPI_fieldE_filter = 	( ppis )->MPI_fieldE_filter ;
	Field3D_MPI  MPI_fieldB_filter = 	( ppis )->MPI_fieldB_filter ;
	Field3D_MPI *  pB0 = 	( ppis )->pB0 ;
	Field3D_MPI *  pB1 = 	( ppis )->pB1 ;
	int  use_pml_abc_dir = 	( ppis )->use_pml_abc_dir ;
	int  use_pml_level = 	( ppis )->use_pml_level ;
	int  use_small_grid = 	( ppis )->use_small_grid ;
	long  allxmax = 	( ppis )->allxmax ;
	long  allymax = 	( ppis )->allymax ;
	long  allzmax = 	( ppis )->allzmax ;
	double  use_pml_sigma_max = 	( ppis )->use_pml_sigma_max ;
	double  dt = 	( ppis )->dt ;
	int  o_N_l = 	( ppis )->o_N_l ;
	int  o_N_M = 	( ppis )->o_N_M ;
	double *  o_pmass = 	( ppis )->o_pmass ;
	double *  o_pcharge = 	( ppis )->o_pcharge ;
	int *  o_particle_type = 	( ppis )->o_particle_type ;
	void *  pe = 	( 	( MPI_fieldE ).data )->pe ;
	long  xlen = 	( 	( MPI_fieldE ).data )->xlen ;
	long  ylen = 	( 	( MPI_fieldE ).data )->ylen ;
	long  zlen = 	( 	( MPI_fieldE ).data )->zlen ;
	long  xblock = 	( 	( MPI_fieldE ).data )->xblock ;
	long  yblock = 	( 	( MPI_fieldE ).data )->yblock ;
	long  zblock = 	( 	( MPI_fieldE ).data )->zblock ;
	long  numvec = 	( 	( MPI_fieldE ).data )->numvec ;
	long  x_num_thread_block = 	( 	( MPI_fieldE ).data )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	( MPI_fieldE ).data )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	( MPI_fieldE ).data )->z_num_thread_block ;
	int  ovlp = 	( 	( MPI_fieldE ).data )->ovlp ;
	int  num_ele = 	( 	( MPI_fieldE ).data )->num_ele ;
	int  CD_type = 	( 	( MPI_fieldE ).data )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	( MPI_fieldE ).data )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	( MPI_fieldE ).data )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	( MPI_fieldE ).data )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	( MPI_fieldE ).data )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	( MPI_fieldE ).data )->dm_kernels ;
	void * *  dmbihamt_kernels = 	( 	( MPI_fieldE ).data )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	( MPI_fieldE ).data )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	( MPI_fieldE ).data )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( 	( MPI_fieldE ).data )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( 	( MPI_fieldE ).data )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	( MPI_fieldE ).data )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	( MPI_fieldE ).data )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( 	( MPI_fieldE ).data )->yee_setfix_kernels ;
	void *  rdcd = 	( 	( MPI_fieldE ).data )->rdcd ;
	double *  rdcd_host = 	( 	( MPI_fieldE ).data )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	( MPI_fieldE ).data )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	( MPI_fieldE ).data )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	( MPI_fieldE ).data )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	( MPI_fieldE ).data )->xoffset ;
	void *  yoffset = 	( 	( MPI_fieldE ).data )->yoffset ;
	void *  zoffset = 	( 	( MPI_fieldE ).data )->zoffset ;
	long *  global_x_offset = 	( 	( MPI_fieldE ).data )->global_x_offset ;
	long *  global_y_offset = 	( 	( MPI_fieldE ).data )->global_y_offset ;
	long *  global_z_offset = 	( 	( MPI_fieldE ).data )->global_z_offset ;
	long *  global_id = 	( 	( MPI_fieldE ).data )->global_id ;
	long  global_pid = 	( 	( MPI_fieldE ).data )->global_pid ;
	long *  adj_ids = 	( 	( MPI_fieldE ).data )->adj_ids ;
	long *  adj_processes = 	( 	( MPI_fieldE ).data )->adj_processes ;
	long *  adj_local_tid = 	( 	( MPI_fieldE ).data )->adj_local_tid ;
	void *  main_data = 	( 	( MPI_fieldE ).data )->main_data ;
	double  delta_x = 	( 	( MPI_fieldE ).data )->delta_x ;
	double  delta_y = 	( 	( MPI_fieldE ).data )->delta_y ;
	double  delta_z = 	( 	( MPI_fieldE ).data )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	( MPI_fieldE ).data )->blas_yiszero_synced_kernel ;
	void *  blas_mulxy_numele3_kernel = 	( 	( MPI_fieldE ).data )->blas_mulxy_numele3_kernel ;
	void *  blas_yiszero_kernel = 	( 	( MPI_fieldE ).data )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	( MPI_fieldE ).data )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	( MPI_fieldE ).data )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	( MPI_fieldE ).data )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	( MPI_fieldE ).data )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	( MPI_fieldE ).data )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	( MPI_fieldE ).data )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	( MPI_fieldE ).data )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	( MPI_fieldE ).data )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	( MPI_fieldE ).data )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	( MPI_fieldE ).data )->blas_sum_kernel ;
	sync_ovlp_mpi_field ( 	& ( ppis->MPI_fieldPMLE ) );
	MPI_PML_FDTD_CURL_FWD ( 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldPMLB ) , 	& ( ppis->MPI_fieldPMLE ) , DELTAT , 0 , 0 , delta_x , delta_y , delta_z , G_USE_PML_ABC_DIR , G_PML_LEVEL , 3 , G_PML_SIGMA_MAX , allxmax , allymax , allzmax );

	}else{
			MPI_YEE_CURL_R ( 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_fieldE ) , DELTAT );

	 }
	if (  G_USE_FIXB_DIR  ){  
			MPI_Yee_FDTD_MUR_ABC ( 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_fieldB ) , DELTAT , 0 , 0 , 0 , G_USE_FIXB_DIR );

	}else{
		0;

	 }
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "CURLE" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	if (  	(  USE_FILTER == 2 )  ){  
			blas_yisax_Field3D_MPI ( 	& ( ppis->MPI_fieldEtmp1 ) , 	& ( ppis->MPI_fieldEtmp1 ) , 1 , 	& ( ppis->MPI_fieldE ) );
	blas_yisax_Field3D_MPI ( 	& ( ppis->MPI_fieldBtmp1 ) , 	& ( ppis->MPI_fieldBtmp1 ) , 1 , 	& ( ppis->MPI_fieldB ) );

	}else{
		0;

	 }
	if (  USE_FILTER  ){  
			blas_mulxy_Field3D_MPI ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldE_filter ) );
	blas_mulxy_Field3D_MPI ( 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB_filter ) );
	if (  	(  USE_FILTER == 2 )  ){  
			blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldEtmp1 ) , 	& ( ppis->MPI_fieldEtmp1 ) , -1 , 	& ( ppis->MPI_fieldE ) );
	blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldBtmp1 ) , 	& ( ppis->MPI_fieldBtmp1 ) , -1 , 	& ( ppis->MPI_fieldB ) );

	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  USE_INIT_EXT_EB  ){  
			blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldE ) , 1 , 	& ( ppis->MPI_fieldE_ext ) );
	blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB ) , 1 , 	& ( ppis->MPI_fieldB_ext ) );
	blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_fieldB1 ) , 1 , 	& ( ppis->MPI_fieldB_ext ) );

	}else{
		0;

	 }
	double  tnow ;
	sync_ovlp_mpi_field ( 	& ( ppis->MPI_fieldE ) );
	sync_ovlp_mpi_field ( 	& ( ppis->MPI_fieldB ) );
	sync_ovlp_mpi_field ( 	& ( ppis->MPI_fieldB1 ) );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "sync E, B, B1" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	if (  	(  ! G_USE_CALC_EQ_B )  ){  
			blas_yiszero_synced_Field3D_MPI ( 	& ( ppis->MPI_FoutJ ) , 	& ( ppis->MPI_FoutJ ) );

	}else{
		0;

	 }
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "sync FoutJ" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	FILE *  fp ;

	 }
	if (  USE_TORI  ){  
			if (  	(  ! 	(  G_USE_CALC_EQ_B && 	(  t > t0 ) ) )  ){  
			if (  	(  ! G_USE_REL )  ){  
			Field3D_MPI  MPI_fieldE = 	( ppis )->MPI_fieldE ;
	Field3D_MPI  MPI_fieldB = 	( ppis )->MPI_fieldB ;
	Field3D_MPI  MPI_fieldB1 = 	( ppis )->MPI_fieldB1 ;
	Field3D_MPI  MPI_FoutJ = 	( ppis )->MPI_FoutJ ;
	Field3D_MPI  MPI_LFoutJ = 	( ppis )->MPI_LFoutJ ;
	Field3D_MPI  MPI_fieldEtmp = 	( ppis )->MPI_fieldEtmp ;
	Field3D_MPI  MPI_fieldEtmp1 = 	( ppis )->MPI_fieldEtmp1 ;
	Field3D_MPI  MPI_fieldEtmp2 = 	( ppis )->MPI_fieldEtmp2 ;
	Field3D_MPI  MPI_fieldBtmp1 = 	( ppis )->MPI_fieldBtmp1 ;
	Field3D_MPI  MPI_fieldPMLB = 	( ppis )->MPI_fieldPMLB ;
	Field3D_MPI  MPI_fieldPMLE = 	( ppis )->MPI_fieldPMLE ;
	Field3D_MPI *  pMPI_FoutJ = 	( ppis )->pMPI_FoutJ ;
	Field3D_MPI *  pMPI_FoutEN = 	( ppis )->pMPI_FoutEN ;
	Field3D_MPI  MPI_fieldE_ext = 	( ppis )->MPI_fieldE_ext ;
	Field3D_MPI  MPI_fieldB_ext = 	( ppis )->MPI_fieldB_ext ;
	Field3D_MPI  MPI_fieldE_filter = 	( ppis )->MPI_fieldE_filter ;
	Field3D_MPI  MPI_fieldB_filter = 	( ppis )->MPI_fieldB_filter ;
	Field3D_MPI *  pB0 = 	( ppis )->pB0 ;
	Field3D_MPI *  pB1 = 	( ppis )->pB1 ;
	int  use_pml_abc_dir = 	( ppis )->use_pml_abc_dir ;
	int  use_pml_level = 	( ppis )->use_pml_level ;
	int  use_small_grid = 	( ppis )->use_small_grid ;
	long  allxmax = 	( ppis )->allxmax ;
	long  allymax = 	( ppis )->allymax ;
	long  allzmax = 	( ppis )->allzmax ;
	double  use_pml_sigma_max = 	( ppis )->use_pml_sigma_max ;
	double  dt = 	( ppis )->dt ;
	int  o_N_l = 	( ppis )->o_N_l ;
	int  o_N_M = 	( ppis )->o_N_M ;
	double *  o_pmass = 	( ppis )->o_pmass ;
	double *  o_pcharge = 	( ppis )->o_pcharge ;
	int *  o_particle_type = 	( ppis )->o_particle_type ;
	Field3D_MPI *  pMPI_fieldE = 	& ( MPI_fieldE ) ;
	Field3D_MPI *  pMPI_fieldB = 	& ( MPI_fieldB ) ;
	double  curt = 	wclk_now (  ) ;
	if (  M_USE_VLO  ){  
			MPI_geo_nr_Bfield_pushJ_vlo ( ppis , pMPI_fieldE , pMPI_fieldB , 	& ( MPI_fieldB1 ) , pMPI_FoutJ , pmass , pchg , 	(  5.00000000000000000e-01 * DELTAT ) , T_TORI_X0 , 0 , 0 , 0 , 0 , 0 );

	}else{
			MPI_geo_nr_Bfield_pushJ ( ppis , pMPI_fieldE , pMPI_fieldB , 	& ( MPI_fieldB1 ) , pMPI_FoutJ , pmass , pchg , 	(  5.00000000000000000e-01 * DELTAT ) , T_TORI_X0 , 0 , 0 , 0 , 0 , 0 );

	 }

	}else{
			if (  	(  M_USE_SMALL_NUM_GRIDS == 1 )  ){  
			double  curt = 	wclk_now (  ) ;
	blas_yiszero_Field3D_MPI ( 	& ( ppis->MPI_LFoutJ ) , 	& ( ppis->MPI_LFoutJ ) );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "sync ovlp" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	MPI_geo_rel_1st_fwd_small_grids ( ppis , 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_LFoutJ ) , pmass , pchg , DELTAT , T_TORI_X0 , T_TORI_SOLVE_ERR );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "geo_rel_sg" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	MPI_merge_current ( 	& ( ppis->MPI_FoutJ ) , 	& ( ppis->MPI_LFoutJ ) );

	}else{
			if (  	(  M_USE_SMALL_NUM_GRIDS == 2 )  ){  
			double  curt = 	wclk_now (  ) ;
	blas_yiszero_synced_Field3D_MPI ( 	& ( ppis->MPI_LFoutJ ) , 	& ( ppis->MPI_LFoutJ ) );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "sync ovlp" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	MPI_geo_rel_1st_fwd_sg2_small_grids ( ppis , 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_LFoutJ ) , pmass , pchg , DELTAT , T_TORI_X0 , T_TORI_SOLVE_ERR );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "geo_rel" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	MPI_merge_current_2 ( 	& ( ppis->MPI_FoutJ ) , 	& ( ppis->MPI_LFoutJ ) );

	}else{
			MPI_geo_rel_1st_fwd ( ppis , 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_FoutJ ) , pmass , pchg , DELTAT , T_TORI_X0 , T_TORI_SOLVE_ERR );

	 }

	 }

	 }

	}else{
		0;

	 }

	}else{
			if (  	(  M_USE_SMALL_NUM_GRIDS == 1 )  ){  
			blas_yiszero_Field3D_MPI ( 	& ( ppis->MPI_LFoutJ ) , 	& ( ppis->MPI_LFoutJ ) );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "sync ovlp" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	MPI_relng_1st_small_grids ( ppis , 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_LFoutJ ) , pmass , pchg , DELTAT , T_TORI_X0 , T_TORI_SOLVE_ERR );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "geo_rel" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	MPI_merge_current ( 	& ( ppis->MPI_FoutJ ) , 	& ( ppis->MPI_LFoutJ ) );

	}else{
			if (  	(  M_USE_SMALL_NUM_GRIDS == 2 )  ){  
			blas_yiszero_synced_Field3D_MPI ( 	& ( ppis->MPI_LFoutJ ) , 	& ( ppis->MPI_LFoutJ ) );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "sync ovlp" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	MPI_relng_1st_sg2_small_grids ( ppis , 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_LFoutJ ) , pmass , pchg , DELTAT , T_TORI_X0 , T_TORI_SOLVE_ERR );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "geo_rel" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	MPI_merge_current_2 ( 	& ( ppis->MPI_FoutJ ) , 	& ( ppis->MPI_LFoutJ ) );

	}else{
			if (  M_USE_TYPE3_KERNEL  ){  
			MPI_relng_1st_goto ( ppis , 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_FoutJ ) , pmass , pchg , DELTAT , 	(  t * T_TORI_X0 ) , T_TORI_SOLVE_ERR );

	}else{
			MPI_relng_1st ( ppis , 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_FoutJ ) , pmass , pchg , DELTAT , 	(  t * T_TORI_X0 ) , T_TORI_SOLVE_ERR );

	 }

	 }

	 }

	 }
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "merge_current/relng/geo_rel" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	if (  	(  	(  t % num_multi_step_sort ) == 0 )  ){  
			call_particle_sort_mpi ( ppis , 0 , 0 );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "sort x particle" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	call_particle_sort_mpi ( ppis , 1 , 0 );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "sort y particle" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	call_particle_sort_mpi ( ppis , 2 , 0 );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "sort z particle" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }

	}else{
		0;

	 }
	if (  	(  ! M_USE_NO_CURRENT )  ){  
			if (  	(  ! 	(  G_USE_CALC_EQ_B && 	(  t > t0 ) ) )  ){  
			merge_ovlp_mpi_field ( 	& ( ppis->MPI_FoutJ ) );

	}else{
		0;

	 }
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "merge ovlp" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	if (  USE_INIT_EXT_EB  ){  
			blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldE ) , -1 , 	& ( ppis->MPI_fieldE_ext ) );
	blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB ) , -1 , 	& ( ppis->MPI_fieldB_ext ) );
	blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_fieldB1 ) , -1 , 	& ( ppis->MPI_fieldB_ext ) );

	}else{
		0;

	 }
	if (  	(  USE_FILTER == 2 )  ){  
			blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldE ) , 1 , 	& ( ppis->MPI_fieldEtmp1 ) );
	blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB ) , 1 , 	& ( ppis->MPI_fieldBtmp1 ) );

	}else{
		0;

	 }
	blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldE ) , -1 , 	& ( ppis->MPI_FoutJ ) );
	if (  USE_NP_BOUNDARY  ){  
			Field3D_MPI *  pMPI_fieldE = 	& ( ppis->MPI_fieldE ) ;
	Field3D_MPI *  pMPI_fieldB = 	& ( ppis->MPI_fieldB ) ;
	Field3D_MPI *  pMPI_fieldEtmp = 	& ( ppis->MPI_fieldEtmp ) ;
	double  G_USE_ABC_DIR = 	call_GET_VAR ( "USE_ABC_DIR" ) ;
	double  G_USE_PEC_DIR = 	call_GET_VAR ( "USE_PEC_DIR" ) ;
	double  G_USE_DAMP_DIR = 	call_GET_VAR ( "USE_DAMP_DIR" ) ;
	if (  0  ){  
			sync_main_data_d2h ( pMPI_fieldE );
(((((double * * )	( pMPI_fieldE->data )->main_data))[0])[	(  	(  0 * 	(  	( pMPI_fieldE->data )->xblock * 	(  	( pMPI_fieldE->data )->yblock * 	(  	( pMPI_fieldE->data )->zblock * 	( pMPI_fieldE->data )->num_ele ) ) ) ) + 	(  0 + 	(  	( pMPI_fieldE->data )->num_ele * 	(  	(  63 + 	( pMPI_fieldE->data )->ovlp ) + 	(  	( pMPI_fieldE->data )->xblock * 	(  	(  0 + 	( pMPI_fieldE->data )->ovlp ) + 	(  	( pMPI_fieldE->data )->yblock * 	(  63 + 	( pMPI_fieldE->data )->ovlp ) ) ) ) ) ) ) )] = 	(  ((((double * * )	( pMPI_fieldE->data )->main_data))[0])[	(  	(  0 * 	(  	( pMPI_fieldE->data )->xblock * 	(  	( pMPI_fieldE->data )->yblock * 	(  	( pMPI_fieldE->data )->zblock * 	( pMPI_fieldE->data )->num_ele ) ) ) ) + 	(  0 + 	(  	( pMPI_fieldE->data )->num_ele * 	(  	(  63 + 	( pMPI_fieldE->data )->ovlp ) + 	(  	( pMPI_fieldE->data )->xblock * 	(  	(  0 + 	( pMPI_fieldE->data )->ovlp ) + 	(  	( pMPI_fieldE->data )->yblock * 	(  63 + 	( pMPI_fieldE->data )->ovlp ) ) ) ) ) ) ) )] + 	sin ( 	(  t * DELTAT ) ) ));
(((((double * * )	( pMPI_fieldE->data )->main_data))[0])[	(  	(  0 * 	(  	( pMPI_fieldE->data )->xblock * 	(  	( pMPI_fieldE->data )->yblock * 	(  	( pMPI_fieldE->data )->zblock * 	( pMPI_fieldE->data )->num_ele ) ) ) ) + 	(  2 + 	(  	( pMPI_fieldE->data )->num_ele * 	(  	(  63 + 	( pMPI_fieldE->data )->ovlp ) + 	(  	( pMPI_fieldE->data )->xblock * 	(  	(  0 + 	( pMPI_fieldE->data )->ovlp ) + 	(  	( pMPI_fieldE->data )->yblock * 	(  63 + 	( pMPI_fieldE->data )->ovlp ) ) ) ) ) ) ) )] = 	(  ((((double * * )	( pMPI_fieldE->data )->main_data))[0])[	(  	(  0 * 	(  	( pMPI_fieldE->data )->xblock * 	(  	( pMPI_fieldE->data )->yblock * 	(  	( pMPI_fieldE->data )->zblock * 	( pMPI_fieldE->data )->num_ele ) ) ) ) + 	(  2 + 	(  	( pMPI_fieldE->data )->num_ele * 	(  	(  63 + 	( pMPI_fieldE->data )->ovlp ) + 	(  	( pMPI_fieldE->data )->xblock * 	(  	(  0 + 	( pMPI_fieldE->data )->ovlp ) + 	(  	( pMPI_fieldE->data )->yblock * 	(  63 + 	( pMPI_fieldE->data )->ovlp ) ) ) ) ) ) ) )] + 	sin ( 	(  t * DELTAT ) ) ));
	sync_main_data_h2d ( pMPI_fieldE );

	}else{
		0;

	 }
	blas_yisax_Field3D_MPI ( pMPI_fieldEtmp , pMPI_fieldEtmp , 1.00000000000000000e+00 , pMPI_fieldE );
	if (  USE_TORI  ){  
			MPI_GEO_YEE_CURL_L ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldB1 ) , T_TORI_X0 , M_DELTA_X , M_DELTA_Y , M_DELTA_Z , DELTAT );

	}else{
			if (  G_USE_PML_ABC_DIR  ){  
			Field3D_MPI  MPI_fieldE = 	( ppis )->MPI_fieldE ;
	Field3D_MPI  MPI_fieldB = 	( ppis )->MPI_fieldB ;
	Field3D_MPI  MPI_fieldB1 = 	( ppis )->MPI_fieldB1 ;
	Field3D_MPI  MPI_FoutJ = 	( ppis )->MPI_FoutJ ;
	Field3D_MPI  MPI_LFoutJ = 	( ppis )->MPI_LFoutJ ;
	Field3D_MPI  MPI_fieldEtmp = 	( ppis )->MPI_fieldEtmp ;
	Field3D_MPI  MPI_fieldEtmp1 = 	( ppis )->MPI_fieldEtmp1 ;
	Field3D_MPI  MPI_fieldEtmp2 = 	( ppis )->MPI_fieldEtmp2 ;
	Field3D_MPI  MPI_fieldBtmp1 = 	( ppis )->MPI_fieldBtmp1 ;
	Field3D_MPI  MPI_fieldPMLB = 	( ppis )->MPI_fieldPMLB ;
	Field3D_MPI  MPI_fieldPMLE = 	( ppis )->MPI_fieldPMLE ;
	Field3D_MPI *  pMPI_FoutJ = 	( ppis )->pMPI_FoutJ ;
	Field3D_MPI *  pMPI_FoutEN = 	( ppis )->pMPI_FoutEN ;
	Field3D_MPI  MPI_fieldE_ext = 	( ppis )->MPI_fieldE_ext ;
	Field3D_MPI  MPI_fieldB_ext = 	( ppis )->MPI_fieldB_ext ;
	Field3D_MPI  MPI_fieldE_filter = 	( ppis )->MPI_fieldE_filter ;
	Field3D_MPI  MPI_fieldB_filter = 	( ppis )->MPI_fieldB_filter ;
	Field3D_MPI *  pB0 = 	( ppis )->pB0 ;
	Field3D_MPI *  pB1 = 	( ppis )->pB1 ;
	int  use_pml_abc_dir = 	( ppis )->use_pml_abc_dir ;
	int  use_pml_level = 	( ppis )->use_pml_level ;
	int  use_small_grid = 	( ppis )->use_small_grid ;
	long  allxmax = 	( ppis )->allxmax ;
	long  allymax = 	( ppis )->allymax ;
	long  allzmax = 	( ppis )->allzmax ;
	double  use_pml_sigma_max = 	( ppis )->use_pml_sigma_max ;
	double  dt = 	( ppis )->dt ;
	int  o_N_l = 	( ppis )->o_N_l ;
	int  o_N_M = 	( ppis )->o_N_M ;
	double *  o_pmass = 	( ppis )->o_pmass ;
	double *  o_pcharge = 	( ppis )->o_pcharge ;
	int *  o_particle_type = 	( ppis )->o_particle_type ;
	void *  pe = 	( 	( MPI_fieldE ).data )->pe ;
	long  xlen = 	( 	( MPI_fieldE ).data )->xlen ;
	long  ylen = 	( 	( MPI_fieldE ).data )->ylen ;
	long  zlen = 	( 	( MPI_fieldE ).data )->zlen ;
	long  xblock = 	( 	( MPI_fieldE ).data )->xblock ;
	long  yblock = 	( 	( MPI_fieldE ).data )->yblock ;
	long  zblock = 	( 	( MPI_fieldE ).data )->zblock ;
	long  numvec = 	( 	( MPI_fieldE ).data )->numvec ;
	long  x_num_thread_block = 	( 	( MPI_fieldE ).data )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	( MPI_fieldE ).data )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	( MPI_fieldE ).data )->z_num_thread_block ;
	int  ovlp = 	( 	( MPI_fieldE ).data )->ovlp ;
	int  num_ele = 	( 	( MPI_fieldE ).data )->num_ele ;
	int  CD_type = 	( 	( MPI_fieldE ).data )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	( MPI_fieldE ).data )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	( MPI_fieldE ).data )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	( MPI_fieldE ).data )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	( MPI_fieldE ).data )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	( MPI_fieldE ).data )->dm_kernels ;
	void * *  dmbihamt_kernels = 	( 	( MPI_fieldE ).data )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	( MPI_fieldE ).data )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	( MPI_fieldE ).data )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( 	( MPI_fieldE ).data )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( 	( MPI_fieldE ).data )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	( MPI_fieldE ).data )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	( MPI_fieldE ).data )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( 	( MPI_fieldE ).data )->yee_setfix_kernels ;
	void *  rdcd = 	( 	( MPI_fieldE ).data )->rdcd ;
	double *  rdcd_host = 	( 	( MPI_fieldE ).data )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	( MPI_fieldE ).data )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	( MPI_fieldE ).data )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	( MPI_fieldE ).data )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	( MPI_fieldE ).data )->xoffset ;
	void *  yoffset = 	( 	( MPI_fieldE ).data )->yoffset ;
	void *  zoffset = 	( 	( MPI_fieldE ).data )->zoffset ;
	long *  global_x_offset = 	( 	( MPI_fieldE ).data )->global_x_offset ;
	long *  global_y_offset = 	( 	( MPI_fieldE ).data )->global_y_offset ;
	long *  global_z_offset = 	( 	( MPI_fieldE ).data )->global_z_offset ;
	long *  global_id = 	( 	( MPI_fieldE ).data )->global_id ;
	long  global_pid = 	( 	( MPI_fieldE ).data )->global_pid ;
	long *  adj_ids = 	( 	( MPI_fieldE ).data )->adj_ids ;
	long *  adj_processes = 	( 	( MPI_fieldE ).data )->adj_processes ;
	long *  adj_local_tid = 	( 	( MPI_fieldE ).data )->adj_local_tid ;
	void *  main_data = 	( 	( MPI_fieldE ).data )->main_data ;
	double  delta_x = 	( 	( MPI_fieldE ).data )->delta_x ;
	double  delta_y = 	( 	( MPI_fieldE ).data )->delta_y ;
	double  delta_z = 	( 	( MPI_fieldE ).data )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	( MPI_fieldE ).data )->blas_yiszero_synced_kernel ;
	void *  blas_mulxy_numele3_kernel = 	( 	( MPI_fieldE ).data )->blas_mulxy_numele3_kernel ;
	void *  blas_yiszero_kernel = 	( 	( MPI_fieldE ).data )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	( MPI_fieldE ).data )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	( MPI_fieldE ).data )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	( MPI_fieldE ).data )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	( MPI_fieldE ).data )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	( MPI_fieldE ).data )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	( MPI_fieldE ).data )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	( MPI_fieldE ).data )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	( MPI_fieldE ).data )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	( MPI_fieldE ).data )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	( MPI_fieldE ).data )->blas_sum_kernel ;
	sync_ovlp_mpi_field ( 	& ( ppis->MPI_fieldPMLB ) );
	MPI_PML_FDTD_CURL_BWD ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_fieldPMLE ) , 	& ( ppis->MPI_fieldPMLB ) , DELTAT , 0 , 0 , delta_x , delta_y , delta_z , G_USE_PML_ABC_DIR , G_PML_LEVEL , 3 , G_PML_SIGMA_MAX , allxmax , allymax , allzmax );

	}else{
			MPI_RECT_YEE_CURL_L ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldB1 ) , M_DELTA_Z , M_DELTA_Y , M_DELTA_X , DELTAT );

	 }

	 }
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "CURLB" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	MPI_Yee_FDTD_MUR_ABC ( pMPI_fieldE , pMPI_fieldEtmp , DELTAT , G_USE_ABC_DIR , G_USE_PEC_DIR , G_USE_DAMP_DIR , 0 );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "MURABC" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }

	}else{
			if (  USE_TORI  ){  
			MPI_GEO_YEE_CURL_L ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldB1 ) , T_TORI_X0 , M_DELTA_X , M_DELTA_Y , M_DELTA_Z , DELTAT );

	}else{
			if (  G_USE_PML_ABC_DIR  ){  
			Field3D_MPI  MPI_fieldE = 	( ppis )->MPI_fieldE ;
	Field3D_MPI  MPI_fieldB = 	( ppis )->MPI_fieldB ;
	Field3D_MPI  MPI_fieldB1 = 	( ppis )->MPI_fieldB1 ;
	Field3D_MPI  MPI_FoutJ = 	( ppis )->MPI_FoutJ ;
	Field3D_MPI  MPI_LFoutJ = 	( ppis )->MPI_LFoutJ ;
	Field3D_MPI  MPI_fieldEtmp = 	( ppis )->MPI_fieldEtmp ;
	Field3D_MPI  MPI_fieldEtmp1 = 	( ppis )->MPI_fieldEtmp1 ;
	Field3D_MPI  MPI_fieldEtmp2 = 	( ppis )->MPI_fieldEtmp2 ;
	Field3D_MPI  MPI_fieldBtmp1 = 	( ppis )->MPI_fieldBtmp1 ;
	Field3D_MPI  MPI_fieldPMLB = 	( ppis )->MPI_fieldPMLB ;
	Field3D_MPI  MPI_fieldPMLE = 	( ppis )->MPI_fieldPMLE ;
	Field3D_MPI *  pMPI_FoutJ = 	( ppis )->pMPI_FoutJ ;
	Field3D_MPI *  pMPI_FoutEN = 	( ppis )->pMPI_FoutEN ;
	Field3D_MPI  MPI_fieldE_ext = 	( ppis )->MPI_fieldE_ext ;
	Field3D_MPI  MPI_fieldB_ext = 	( ppis )->MPI_fieldB_ext ;
	Field3D_MPI  MPI_fieldE_filter = 	( ppis )->MPI_fieldE_filter ;
	Field3D_MPI  MPI_fieldB_filter = 	( ppis )->MPI_fieldB_filter ;
	Field3D_MPI *  pB0 = 	( ppis )->pB0 ;
	Field3D_MPI *  pB1 = 	( ppis )->pB1 ;
	int  use_pml_abc_dir = 	( ppis )->use_pml_abc_dir ;
	int  use_pml_level = 	( ppis )->use_pml_level ;
	int  use_small_grid = 	( ppis )->use_small_grid ;
	long  allxmax = 	( ppis )->allxmax ;
	long  allymax = 	( ppis )->allymax ;
	long  allzmax = 	( ppis )->allzmax ;
	double  use_pml_sigma_max = 	( ppis )->use_pml_sigma_max ;
	double  dt = 	( ppis )->dt ;
	int  o_N_l = 	( ppis )->o_N_l ;
	int  o_N_M = 	( ppis )->o_N_M ;
	double *  o_pmass = 	( ppis )->o_pmass ;
	double *  o_pcharge = 	( ppis )->o_pcharge ;
	int *  o_particle_type = 	( ppis )->o_particle_type ;
	void *  pe = 	( 	( MPI_fieldE ).data )->pe ;
	long  xlen = 	( 	( MPI_fieldE ).data )->xlen ;
	long  ylen = 	( 	( MPI_fieldE ).data )->ylen ;
	long  zlen = 	( 	( MPI_fieldE ).data )->zlen ;
	long  xblock = 	( 	( MPI_fieldE ).data )->xblock ;
	long  yblock = 	( 	( MPI_fieldE ).data )->yblock ;
	long  zblock = 	( 	( MPI_fieldE ).data )->zblock ;
	long  numvec = 	( 	( MPI_fieldE ).data )->numvec ;
	long  x_num_thread_block = 	( 	( MPI_fieldE ).data )->x_num_thread_block ;
	long  y_num_thread_block = 	( 	( MPI_fieldE ).data )->y_num_thread_block ;
	long  z_num_thread_block = 	( 	( MPI_fieldE ).data )->z_num_thread_block ;
	int  ovlp = 	( 	( MPI_fieldE ).data )->ovlp ;
	int  num_ele = 	( 	( MPI_fieldE ).data )->num_ele ;
	int  CD_type = 	( 	( MPI_fieldE ).data )->CD_type ;
	void * *  sync_layer_pscmc = 	( 	( MPI_fieldE ).data )->sync_layer_pscmc ;
	void * *  swap_layer_pscmc = 	( 	( MPI_fieldE ).data )->swap_layer_pscmc ;
	void * *  sync_kernels = 	( 	( MPI_fieldE ).data )->sync_kernels ;
	void * *  fdtd_kernels = 	( 	( MPI_fieldE ).data )->fdtd_kernels ;
	void * *  dm_kernels = 	( 	( MPI_fieldE ).data )->dm_kernels ;
	void * *  dmbihamt_kernels = 	( 	( MPI_fieldE ).data )->dmbihamt_kernels ;
	void * *  geo_yeefdtd_kernels = 	( 	( MPI_fieldE ).data )->geo_yeefdtd_kernels ;
	void * *  geo_yeefdtd_rect_kernels = 	( 	( MPI_fieldE ).data )->geo_yeefdtd_rect_kernels ;
	void * *  hydroA_kernels = 	( 	( MPI_fieldE ).data )->hydroA_kernels ;
	void * *  yee_abc_kernels = 	( 	( MPI_fieldE ).data )->yee_abc_kernels ;
	void * *  yee_pec_kernels = 	( 	( MPI_fieldE ).data )->yee_pec_kernels ;
	void * *  yee_damp_kernels = 	( 	( MPI_fieldE ).data )->yee_damp_kernels ;
	void * *  yee_setfix_kernels = 	( 	( MPI_fieldE ).data )->yee_setfix_kernels ;
	void *  rdcd = 	( 	( MPI_fieldE ).data )->rdcd ;
	double *  rdcd_host = 	( 	( MPI_fieldE ).data )->rdcd_host ;
	void *  cur_rankx_pscmc = 	( 	( MPI_fieldE ).data )->cur_rankx_pscmc ;
	void *  cur_ranky_pscmc = 	( 	( MPI_fieldE ).data )->cur_ranky_pscmc ;
	void *  cur_rankz_pscmc = 	( 	( MPI_fieldE ).data )->cur_rankz_pscmc ;
	void *  xoffset = 	( 	( MPI_fieldE ).data )->xoffset ;
	void *  yoffset = 	( 	( MPI_fieldE ).data )->yoffset ;
	void *  zoffset = 	( 	( MPI_fieldE ).data )->zoffset ;
	long *  global_x_offset = 	( 	( MPI_fieldE ).data )->global_x_offset ;
	long *  global_y_offset = 	( 	( MPI_fieldE ).data )->global_y_offset ;
	long *  global_z_offset = 	( 	( MPI_fieldE ).data )->global_z_offset ;
	long *  global_id = 	( 	( MPI_fieldE ).data )->global_id ;
	long  global_pid = 	( 	( MPI_fieldE ).data )->global_pid ;
	long *  adj_ids = 	( 	( MPI_fieldE ).data )->adj_ids ;
	long *  adj_processes = 	( 	( MPI_fieldE ).data )->adj_processes ;
	long *  adj_local_tid = 	( 	( MPI_fieldE ).data )->adj_local_tid ;
	void *  main_data = 	( 	( MPI_fieldE ).data )->main_data ;
	double  delta_x = 	( 	( MPI_fieldE ).data )->delta_x ;
	double  delta_y = 	( 	( MPI_fieldE ).data )->delta_y ;
	double  delta_z = 	( 	( MPI_fieldE ).data )->delta_z ;
	void *  blas_yiszero_synced_kernel = 	( 	( MPI_fieldE ).data )->blas_yiszero_synced_kernel ;
	void *  blas_mulxy_numele3_kernel = 	( 	( MPI_fieldE ).data )->blas_mulxy_numele3_kernel ;
	void *  blas_yiszero_kernel = 	( 	( MPI_fieldE ).data )->blas_yiszero_kernel ;
	void *  blas_yisconst_kernel = 	( 	( MPI_fieldE ).data )->blas_yisconst_kernel ;
	void *  blas_get_ITG_Potential_kernel = 	( 	( MPI_fieldE ).data )->blas_get_ITG_Potential_kernel ;
	void *  blas_invy_kernel = 	( 	( MPI_fieldE ).data )->blas_invy_kernel ;
	void *  blas_axpby_kernel = 	( 	( MPI_fieldE ).data )->blas_axpby_kernel ;
	void *  blas_axpy_kernel = 	( 	( MPI_fieldE ).data )->blas_axpy_kernel ;
	void *  blas_yisax_kernel = 	( 	( MPI_fieldE ).data )->blas_yisax_kernel ;
	void *  blas_mulxy_kernel = 	( 	( MPI_fieldE ).data )->blas_mulxy_kernel ;
	void *  blas_findmax_kernel = 	( 	( MPI_fieldE ).data )->blas_findmax_kernel ;
	void *  blas_dot_kernel = 	( 	( MPI_fieldE ).data )->blas_dot_kernel ;
	void *  blas_sum_kernel = 	( 	( MPI_fieldE ).data )->blas_sum_kernel ;
	sync_ovlp_mpi_field ( 	& ( ppis->MPI_fieldPMLB ) );
	MPI_PML_FDTD_CURL_BWD ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_fieldPMLE ) , 	& ( ppis->MPI_fieldPMLB ) , DELTAT , 0 , 0 , delta_x , delta_y , delta_z , G_USE_PML_ABC_DIR , G_PML_LEVEL , 3 , G_PML_SIGMA_MAX , allxmax , allymax , allzmax );

	}else{
			MPI_RECT_YEE_CURL_L ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldB1 ) , M_DELTA_Z , M_DELTA_Y , M_DELTA_X , DELTAT );

	 }

	 }
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "CURLB" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }

	 }
	blas_yisax_Field3D_MPI ( 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB ) , 1 , 	& ( ppis->MPI_fieldB1 ) );

	}else{
		0;

	 }

	}else{
			if (  G_USE_BORIS_YEE  ){  
			sync_ovlp_mpi_field ( 	& ( ppis->MPI_fieldE ) );
	MPI_Yee_FDTD_Curl_E ( 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldE ) , 	(  DELTAT / 2 ) );
	blas_yiszero_Field3D_MPI ( 	& ( ppis->MPI_FoutJ ) , 	& ( ppis->MPI_FoutJ ) );
	sync_ovlp_mpi_field ( 	& ( ppis->MPI_FoutJ ) );
	if (  USE_INIT_EXT_EB  ){  
			blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldE ) , 1 , 	& ( ppis->MPI_fieldE_ext ) );
	blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB ) , 1 , 	& ( ppis->MPI_fieldB_ext ) );
	blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_fieldB1 ) , 1 , 	& ( ppis->MPI_fieldB_ext ) );

	}else{
		0;

	 }
	sync_ovlp_mpi_field ( 	& ( ppis->MPI_fieldE ) );
	sync_ovlp_mpi_field ( 	& ( ppis->MPI_fieldB ) );
	MPI_boris_yee ( ppis , 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_FoutJ ) , pmass , pchg , DELTAT );
	if (  USE_INIT_EXT_EB  ){  
			blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldE ) , -1 , 	& ( ppis->MPI_fieldE_ext ) );
	blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB ) , -1 , 	& ( ppis->MPI_fieldB_ext ) );
	blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_fieldB1 ) , -1 , 	& ( ppis->MPI_fieldB_ext ) );

	}else{
		0;

	 }
	merge_ovlp_mpi_field ( 	& ( ppis->MPI_FoutJ ) );
	MPI_Yee_FDTD_Curl_E ( 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldE ) , 	(  DELTAT / 2 ) );
	call_particle_sort_mpi ( ppis , 0 , 0 );
	call_particle_sort_mpi ( ppis , 1 , 0 );
	call_particle_sort_mpi ( ppis , 2 , 0 );
	sync_ovlp_mpi_field ( 	& ( ppis->MPI_fieldB ) );
	pass_GeqB ( ppis , DELTAT );
	blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldE ) , 	- ( DELTAT ) , 	& ( ppis->MPI_FoutJ ) );

	}else{
			if (  G_NUM_HIGH_ORDER_L  ){  
			high_order_split_pic ( ppis , DELTAT , G_NUM_HIGH_ORDER_L );

	}else{
			if (  M_USE_1ST  ){  
			split_1st_all_passes ( ppis , DELTAT , M_USE_VLO );

	}else{
			if (  M_USE_ITG_MODE  ){  
			if (  USE_TORI  ){  
			Field3D_MPI  MPI_fieldE = 	( ppis )->MPI_fieldE ;
	Field3D_MPI  MPI_fieldB = 	( ppis )->MPI_fieldB ;
	Field3D_MPI  MPI_fieldB1 = 	( ppis )->MPI_fieldB1 ;
	Field3D_MPI  MPI_FoutJ = 	( ppis )->MPI_FoutJ ;
	Field3D_MPI  MPI_LFoutJ = 	( ppis )->MPI_LFoutJ ;
	Field3D_MPI  MPI_fieldEtmp = 	( ppis )->MPI_fieldEtmp ;
	Field3D_MPI  MPI_fieldEtmp1 = 	( ppis )->MPI_fieldEtmp1 ;
	Field3D_MPI  MPI_fieldEtmp2 = 	( ppis )->MPI_fieldEtmp2 ;
	Field3D_MPI  MPI_fieldBtmp1 = 	( ppis )->MPI_fieldBtmp1 ;
	Field3D_MPI  MPI_fieldPMLB = 	( ppis )->MPI_fieldPMLB ;
	Field3D_MPI  MPI_fieldPMLE = 	( ppis )->MPI_fieldPMLE ;
	Field3D_MPI *  pMPI_FoutJ = 	( ppis )->pMPI_FoutJ ;
	Field3D_MPI *  pMPI_FoutEN = 	( ppis )->pMPI_FoutEN ;
	Field3D_MPI  MPI_fieldE_ext = 	( ppis )->MPI_fieldE_ext ;
	Field3D_MPI  MPI_fieldB_ext = 	( ppis )->MPI_fieldB_ext ;
	Field3D_MPI  MPI_fieldE_filter = 	( ppis )->MPI_fieldE_filter ;
	Field3D_MPI  MPI_fieldB_filter = 	( ppis )->MPI_fieldB_filter ;
	Field3D_MPI *  pB0 = 	( ppis )->pB0 ;
	Field3D_MPI *  pB1 = 	( ppis )->pB1 ;
	int  use_pml_abc_dir = 	( ppis )->use_pml_abc_dir ;
	int  use_pml_level = 	( ppis )->use_pml_level ;
	int  use_small_grid = 	( ppis )->use_small_grid ;
	long  allxmax = 	( ppis )->allxmax ;
	long  allymax = 	( ppis )->allymax ;
	long  allzmax = 	( ppis )->allzmax ;
	double  use_pml_sigma_max = 	( ppis )->use_pml_sigma_max ;
	double  dt = 	( ppis )->dt ;
	int  o_N_l = 	( ppis )->o_N_l ;
	int  o_N_M = 	( ppis )->o_N_M ;
	double *  o_pmass = 	( ppis )->o_pmass ;
	double *  o_pcharge = 	( ppis )->o_pcharge ;
	int *  o_particle_type = 	( ppis )->o_particle_type ;
	Field3D_MPI *  pMPI_fieldE = 	& ( MPI_fieldE ) ;
	Field3D_MPI *  pMPI_fieldB = 	& ( MPI_fieldB ) ;
	if (  1  ){  
			blas_yiszero_synced_Field3D_MPI ( pMPI_FoutJ , pMPI_FoutJ );
	calculate_rho_mpi ( ppis , 0 );
	merge_ovlp_mpi_field ( pMPI_FoutJ );
	if (  USE_NON_UNI_DENSITY  ){  
			blas_yisax_Field3D_MPI ( pMPI_fieldE , pMPI_fieldE , M_ITG_CONST_NE0 , pext_rho_dist );

	}else{
			blas_yisconst_Field3D_MPI ( pMPI_fieldE , pMPI_fieldE , M_ITG_CONST_NE0 );

	 }
	blas_yisax_Field3D_MPI ( pMPI_fieldB , pMPI_fieldB , 1 , pMPI_FoutJ );
	blas_get_ITG_Potential_Field3D_MPI ( pMPI_FoutJ , pMPI_FoutJ , 	& ( MPI_fieldB1 ) , pMPI_fieldE , 	(  1.00000000000000000e+00 / (pchg)[0] ) );
	sync_ovlp_mpi_field ( pMPI_FoutJ );
	MPI_Yee_FDTD_Grad_FWD ( pMPI_fieldE , pMPI_FoutJ , 0 );
	if (  USE_INIT_EXT_EB  ){  
			blas_axpy_Field3D_MPI ( 	& ( MPI_fieldE ) , 	& ( MPI_fieldE ) , 1.00000000000000000e+00 , 	& ( MPI_fieldE_ext ) );

	}else{
		0;

	 }
	sync_ovlp_mpi_field ( pMPI_fieldE );

	}else{
			blas_yiszero_synced_Field3D_MPI ( pMPI_fieldE , pMPI_fieldE );

	 }
	if (  0  ){  
			if (  M_USE_VLO  ){  
			MPI_geo_nr_vlo ( ppis , pMPI_fieldE , pMPI_fieldB , 	& ( MPI_fieldB1 ) , pMPI_FoutJ , pmass , pchg , DELTAT , T_TORI_X0 , M_ITG_MAJ_R0 , M_ITG_MIN_R0 , M_ITG_Q0 , M_ITG_B0 , M_ITG_ZMID );

	}else{
			MPI_geo_nr ( ppis , pMPI_fieldE , pMPI_fieldB , 	& ( MPI_fieldB1 ) , pMPI_FoutJ , pmass , pchg , DELTAT , T_TORI_X0 , M_ITG_MAJ_R0 , M_ITG_MIN_R0 , M_ITG_Q0 , M_ITG_B0 , M_ITG_ZMID );

	 }

	}else{
		0;

	 }
	if (  M_USE_VLO  ){  
			MPI_geo_nr_Bfield_pushJ_vlo ( ppis , pMPI_fieldE , 	& ( MPI_fieldB_ext ) , 	& ( MPI_fieldB_ext ) , pMPI_FoutJ , pmass , pchg , 	(  5.00000000000000000e-01 * DELTAT ) , T_TORI_X0 , M_ITG_MAJ_R0 , M_ITG_MIN_R0 , M_ITG_Q0 , M_ITG_B0 , M_ITG_ZMID );

	}else{
			MPI_geo_nr_Bfield_pushJ ( ppis , pMPI_fieldE , 	& ( MPI_fieldB_ext ) , 	& ( MPI_fieldB_ext ) , pMPI_FoutJ , pmass , pchg , 	(  5.00000000000000000e-01 * DELTAT ) , T_TORI_X0 , M_ITG_MAJ_R0 , M_ITG_MIN_R0 , M_ITG_Q0 , M_ITG_B0 , M_ITG_ZMID );

	 }
	call_particle_sort_mpi ( ppis , 0 , 0 );
	call_particle_sort_mpi ( ppis , 1 , 0 );
	call_particle_sort_mpi ( ppis , 2 , 0 );
	if (  USE_INIT_EXT_EB  ){  
			blas_axpy_Field3D_MPI ( 	& ( MPI_fieldE ) , 	& ( MPI_fieldE ) , -1.00000000000000000e+00 , 	& ( MPI_fieldE_ext ) );

	}else{
		0;

	 }

	}else{
			if (  M_ITG_ENE_CONS  ){  
			ITG_split_2nd_all_passes_enecons ( ppis , pext_rho_dist , DELTAT , 	(  1.00000000000000000e+00 / (pchg)[0] ) , M_ITG_CONST_NE0 , M_USE_VLO , M_ITG_GC );

	}else{
			ITG_split_2nd_all_passes ( ppis , pext_rho_dist , DELTAT , 	(  1.00000000000000000e+00 / (pchg)[0] ) , M_ITG_CONST_NE0 , M_USE_VLO , M_ITG_GC );

	 }

	 }

	}else{
			if (  M_USE_SMALL_TIMESTEP_MODE  ){  
			blas_yiszero_Field3D_MPI ( 	& ( ppis->MPI_fieldE_filter ) , 	& ( ppis->MPI_fieldE_filter ) );
	jfnk_newton_simple_mpi ( 	& ( jns ) , 	& ( ppis->MPI_fieldE_filter ) );

	}else{
			if (  M_USE_MULTI_STEP  ){  
			split_2nd_all_passes_multi_step ( ppis , DELTAT , M_USE_VLO , G_USE_G_E , 2 , 1 , pmass , pchg );

	}else{
			split_2nd_all_passes ( ppis , DELTAT , M_USE_VLO , G_USE_G_E );

	 }

	 }

	 }

	 }

	 }

	 }

	 }
}}}	if (  G_KROOK_MU_FREQ  ){  
			MPI_krook_collision_test ( ppis , pext_krook , 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_FoutJ ) , pmass , pchg , DELTAT , G_KROOK_MU_FREQ );

	}else{
		0;

	 }
	if (  G_USE_KROOK_FIELD  ){  
			MPI_krook_collision_test ( ppis , pext_krook , 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_FoutJ ) , pmass , pchg , DELTAT , 0 );

	}else{
		0;

	 }
	if (  G_KROOK_SPEED_LIMIT  ){  
			MPI_krook_collision_remove_small_speed ( ppis , pext_krook , 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_FoutJ ) , pmass , pchg , DELTAT , G_KROOK_SPEED_LIMIT );

	}else{
		0;

	 }
	if (  	(  	(  rank == 0 ) && 	(  M_DISABLE_TS_LOG == 0 ) )  ){  
		{
	double  tnow = 	wclk_now (  ) ;
	double  tused = 	(  tnow - tend ) ;
(tend = tnow);
	fprintf ( stderr , "step=%d time used=%fs, ips=%f, allips=%f\n" , t , tused , 	(  1 / tused ) , 	(  	(  t + 1 ) / 	(  tend - tbeg ) ) );
}
	}else{
		0;

	 }
}	GAPS_IO_DeleteDataInfo ( pgid );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "task complete: " );
{
	long  i ;
	for ((i = 0) ; 	(  i < argc ) ; (i = 	(  i + 1 )))
	{
	fprintf ( stderr , "%s " , (argv)[i] );
}}	fprintf ( stderr , "\n" );

	}else{
		0;

	 }
}
	 }

	 }

	 }
	long  i = 0 ;
	sync_main_data_d2h ( ptestfield );
	PS_MPI_Finalize (  );
	return  0 ;}
