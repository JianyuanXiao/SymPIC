#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
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
#include "init_field3d_mpi.h"
#include <cgapsio.h>
#include "mpi_fieldio.h"
#include "call_curl_kernel.h"
#include "init_particle.h"
#include "run_particle.h"
#include "pass_xyzzyx.h"
#include "sort_particle.h"
#include "init_adjoint_relation.h"
#include "split_shell.h"
#include "blas_shell.h"
#include "cfgcst.h"
typedef Field3D_MPI  Field3D_MPI_ALL ;
#include "checkpoint.h"
#include <sys/time.h>
double  wclk_now (){
	struct timeval  tv1 ;
	struct timezone  tz1 ;
	gettimeofday ( 	& ( tv1 ) , 	& ( tz1 ) );
	double  time_start1 = 	(  ((double )tv1.tv_sec) + 	(  9.99999999999999955e-07 * ((double )tv1.tv_usec) ) ) ;
	return  time_start1 ;}
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
} dm_fv;int  dm_bicg_fun (Field3D_MPI *  out ,Field3D_MPI *  in ,dm_fv *  fv ){
	sync_ovlp_mpi_field ( in );
	MPI_dm_1st_eqn_core ( out , in , fv->pF0 , fv->pA0 , fv->pA1 , fv->pA2 , fv->DM_A , fv->Q , fv->M , fv->DT );
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
}	long  n = NUM_PROCESS ;
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
	double  M_DELTA_X = 	call_GET_VAR ( "DELTA_X" ) ;
	double  M_DELTA_Y = 	call_GET_VAR ( "DELTA_Y" ) ;
	double  M_DELTA_Z = 	call_GET_VAR ( "DELTA_Z" ) ;
	double  M_USE_VLO = 	call_GET_VAR ( "USE_VLO" ) ;
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
	srand ( 	(  rank + 	(  1 + ((M_USE_TIME_AS_RANDOM_SEED)?(	time ( NULL )):(0)) ) ) );
	long   tids  [	(  num_runtime * n )];	long *  local_tid_array = 	malloc ( 	(  sizeof(long ) * numt ) ) ;
	Field3D_MPI  testfield ;
	Field3D_MPI *  ptestfield = 	& ( testfield ) ;
	Field3D_MPI  testfieldB ;
	Field3D_MPI *  ptestfieldB = 	& ( testfieldB ) ;
	Field3D_MPI  testfieldSPEC ;
	Field3D_MPI *  ptestfieldSPEC = 	& ( testfieldSPEC ) ;
	Field3D_Seq  fstest ;
	Field3D_Seq  fstestSPEC ;
	Field3D_Seq *  pfstestSPEC = 	& ( fstestSPEC ) ;
	Field3D_Seq *  pfstest = 	& ( fstest ) ;
	int   cd_types  [NUM_MAX_RUNTIME];	int   dev_ids  [NUM_MAX_RUNTIME];	double  G_GAPSIO_VERSION = 	call_GET_VAR ( "GAPSIO_VERSION" ) ;
{
	long  i = 0 ;
	for (i=0 ; i<NUM_RUNTIME ; i++)
	{
((cd_types)[i] = 	call_GET_DEV_TYPE ( i , rank ));
((dev_ids)[i] = 	call_GET_DEV_ID ( i , rank ));
}}	fprintf ( stderr , "rank %d init, pid=%d\n" , rank , 	getpid (  ) );
	memset ( pfstest , 0 , sizeof(Field3D_Seq ) );
	long  fieldlen = 3 ;
	if (  USE_KGM  ){  
		(fieldlen = 10);

	}else{
		0;

	 }
	if (  	(  NUM_N_HILBERT_DIMENSION == 1 )  ){  
			long   lengs  [3];{
	long  i ;
	for ((i = 0) ; 	(  i < 3 ) ; (i = 	(  i + 1 )))
	{
((lengs)[i] = ((	(  i == HILBERT_DIR ))?(len_hilbert):(1)));
}}	set_Field3D_Seq ( pfstest , NULL , M_DELTA_X , M_DELTA_Y , M_DELTA_Z , XMAX , YMAX , ZMAX , 2 , 2 , fieldlen , 0 , (lengs)[0] , (lengs)[1] , (lengs)[2] , rank );

	}else{
			if (  	(  NUM_N_HILBERT_DIMENSION == 2 )  ){  
			long   lengs  [3];{
	long  i ;
	for ((i = 0) ; 	(  i < 3 ) ; (i = 	(  i + 1 )))
	{
((lengs)[i] = ((	(  i == HILBERT_DIR ))?(1):(len_hilbert)));
}}	set_Field3D_Seq ( pfstest , NULL , M_DELTA_X , M_DELTA_Y , M_DELTA_Z , XMAX , YMAX , ZMAX , 2 , 2 , fieldlen , 0 , (lengs)[0] , (lengs)[1] , (lengs)[2] , rank );

	}else{
			if (  	(  NUM_N_HILBERT_DIMENSION == 3 )  ){  
			set_Field3D_Seq ( pfstest , NULL , M_DELTA_X , M_DELTA_Y , M_DELTA_Z , XMAX , YMAX , ZMAX , 2 , 2 , fieldlen , 0 , len_hilbert , len_hilbert , len_hilbert , rank );

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
	double  M_KGM_DX = 	call_GET_VAR ( "KGM_DX" ) ;
	double  M_KGM_REFZ0 = 	call_GET_VAR ( "KGM_REFZ0" ) ;
	double  M_KGM_EXTG = 	call_GET_VAR ( "KGM_EXTG" ) ;
	double  M_KGM_INIT_SPER = 	call_GET_VAR ( "KGM_INIT_SPER" ) ;
	double  M_KGM_XMID = 	call_GET_VAR ( "KGM_XMID" ) ;
	double  M_KGM_YMID = 	call_GET_VAR ( "KGM_YMID" ) ;
	double  M_KGM_ZMID = 	call_GET_VAR ( "KGM_ZMID" ) ;
	Field3D_MPI  F0 ;
	Field3D_MPI *  pF0 = 	& ( F0 ) ;
	Field3D_MPI  F1 ;
	Field3D_MPI *  pF1 = 	& ( F1 ) ;
	init_Field3D_MPI_from ( pF0 , ptestfield );
	init_Field3D_MPI_from ( pF1 , ptestfield );
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

	 }
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	long  tsave = 0 ;
	init_parallel_file_for_mpi_fields ( ptestfield , pgid , "tmpKGM" , ((tsave)?(tsave):(-1)) , G_GAPSIO_VERSION );
{
	long  t ;
	for ((t = 0) ; 	(  t < NUM_TIMESTEP ) ; (t = 	(  t + 1 )))
	{
	MPI_kgm_eqn_core ( pF1 , pF0 , M_KGM_DT , M_KGM_M0 , M_KGM_Q0 , M_KGM_DX , M_KGM_EXTG , M_KGM_REFZ0 );
	if (  	(  0 && 	(  rank == 0 ) )  ){  
			fprintf ( stdout , "%d\n" , t );
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
	MPI_Yee_FDTD_MUR_ABC ( pF1 , pF0 , M_KGM_DT , G_USE_ABC_DIR , G_USE_PEC_DIR , G_USE_DAMP_DIR );

	}else{
		0;

	 }
	long  rdmd = 	(  	(  M_KGM_ASSEMBLE == 0 ) * ((long )	(  NUM_DUMP_TIMESTEP * 	(  	(  	rand (  ) * 1.00000000000000000e+00 ) / RAND_MAX ) )) ) ;
	if (  	(  0 == 	(  	(  t + rdmd ) % NUM_DUMP_TIMESTEP ) )  ){  
			mpi_field_write_to_file ( pF0 , pgid , tsave );
(tsave = 	(  tsave + 1 ));
	fprintf ( stderr , "%d done\n" , t );

	}else{
		0;

	 }
	void *  tmp = pF0 ;
(pF0 = pF1);
(pF1 = tmp);
}}
	}else{
			if (  	(  USE_DM == 1 )  ){  
			double  M_DM_M0 = 	call_GET_VAR ( "DM_M0" ) ;
	double  M_DM_Q0 = 	call_GET_VAR ( "DM_Q0" ) ;
	double  M_DM_DT = 	call_GET_VAR ( "DM_DT" ) ;
	double  M_DM_PHI0 = 	call_GET_VAR ( "DM_PHI0" ) ;
	double  M_DM_AMPX = 	call_GET_VAR ( "DM_AMPX" ) ;
	double  M_DM_SGM = 	call_GET_VAR ( "DM_SGM" ) ;
	double  M_DM_EY = 	call_GET_VAR ( "DM_EY" ) ;
	double  M_DM_FRQ = 	call_GET_VAR ( "DM_FRQ" ) ;
	double  M_DM_SOLVE_ERR = 	call_GET_VAR ( "DM_SOLVE_ERR" ) ;
	double  M_DM_A = 	call_GET_VAR ( "DM_A" ) ;
	Field3D_MPI  F0 ;
	Field3D_MPI *  pF0 = 	& ( F0 ) ;
	Field3D_MPI  F1 ;
	Field3D_MPI *  pF1 = 	& ( F1 ) ;
	Field3D_MPI  b_AF0 ;
	Field3D_MPI *  pb_AF0 = 	& ( b_AF0 ) ;
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
(	( pfstest )->num_ele = 3);
	init_Field3D_MPI_ALL ( ptestfield , pfstest , n_hilbert , NUM_N_HILBERT_DIMENSION , 0 , tids , local_tid_array , cd_types , dev_ids , num_runtime , PS_MPI_COMM_WORLD , rank , n );
	init_Field3D_MPI_from ( pA0 , ptestfield );
	init_Field3D_MPI_from ( pA1 , ptestfield );
	init_Field3D_MPI_from ( pA2 , ptestfield );
	bicg_space  bs ;
	bicg_space *  pbs = 	& ( bs ) ;
	dm_fv  fv ;
	dm_fv *  pfv = 	& ( fv ) ;
	mpi_init_bicg ( pbs , dm_bicg_fun , pF0 , 1000 , M_DM_SOLVE_ERR , pfv );
(	( pfv )->Q = M_DM_Q0);
(	( pfv )->M = M_DM_M0);
(	( pfv )->DT = M_DM_DT);
(	( pfv )->DM_A = M_DM_A);
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	Gaps_IO_DataFile  gad ;
	Gaps_IO_DataFile *  pgad = 	& ( gad ) ;
	long  tsave = 0 ;
	init_parallel_file_for_mpi_fields ( pF0 , pgid , "tmpDM" , ((tsave)?(tsave):(-1)) , G_GAPSIO_VERSION );
	init_parallel_file_for_mpi_fields ( pA0 , pgad , "tmpA" , ((tsave)?(tsave):(-1)) , G_GAPSIO_VERSION );
	init_dm_phi_global ( pF0 , M_DM_PHI0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , M_DM_SGM , M_DM_FRQ );
	init_dm_A0_global ( pA0 , 0 , 0 );
	init_dm_A1_global ( pA1 , M_DM_AMPX , M_DM_EY , M_DM_DT );
{
	long  t ;
	for ((t = 0) ; 	(  t < NUM_TIMESTEP ) ; (t = 	(  t + 1 )))
	{
(	( pfv )->pA0 = pA0);
(	( pfv )->pA1 = pA1);
(	( pfv )->pA2 = pA2);
(	( pfv )->pF0 = pF0);
	sync_ovlp_mpi_field ( pF0 );
	sync_ovlp_mpi_field ( pA0 );
	sync_ovlp_mpi_field ( pA1 );
	MPI_dm_1st_eqn_right ( pb_AF0 , pF1 , pF0 , pA0 , pA1 , pA2 , M_DM_A , M_DM_Q0 , M_DM_M0 , M_DM_DT );
	sync_ovlp_mpi_field ( pb_AF0 );
	mpi_simple_bicgstab ( pbs , pF1 , pb_AF0 );
	MPI_dm_1st_eqn_fdtd ( pb_AF0 , pF1 , pF0 , pA0 , pA1 , pA2 , M_DM_A , M_DM_Q0 , M_DM_M0 , M_DM_DT );
	if (  	(  0 == 	(  t % NUM_DUMP_TIMESTEP ) )  ){  
			mpi_field_write_to_file ( pF0 , pgid , tsave );
	mpi_field_write_to_file ( pA0 , pgad , tsave );
(tsave = 	(  tsave + 1 ));
	fprintf ( stderr , "%d done\n" , t );

	}else{
		0;

	 }
	void *  ftmp ;
(ftmp = pF0);
(pF0 = pF1);
(pF1 = ftmp);
(ftmp = pA0);
(pA0 = pA1);
(pA1 = pA2);
(pA2 = ftmp);
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
	double  M_USE_SMALL_NUM_GRIDS = 	call_GET_VAR ( "USE_SMALL_NUM_GRIDS" ) ;
	double  M_USE_INIT_PARTICLE_FILE = 	call_GET_VAR ( "USE_INIT_PARTICLE_FILE" ) ;
	double  M_USE_DUMP_PARTICLE_FILE = 	call_GET_VAR ( "USE_DUMP_PARTICLE_FILE" ) ;
	double  M_USE_ITG_MODE = 	call_GET_VAR ( "USE_ITG_MODE" ) ;
	double  M_ITG_CONST_NE0 = 	call_GET_VAR ( "ITG_CONST_NE0" ) ;
	init_global_particles ( ppis , ptestfield , ptestfieldSPEC , M_USE_SMALL_NUM_GRIDS , DELTAT , NUM_SPEC , pmass , pchg , pnpm , pgcache , pcucache );
	if (  M_USE_ITG_MODE  ){  
			blas_yisax_Field3D_MPI ( 	& ( ppis->MPI_fieldE_ext ) , 	& ( ppis->MPI_fieldE_ext ) , -1 , 	& ( ppis->MPI_fieldE_ext ) );

	}else{
		0;

	 }
	if (  0  ){  
			init_single_particle_fmpi ( 	& ( 	( ppis )->MPI_fieldE ) );

	}else{
			if (  M_USE_INIT_PARTICLE_FILE  ){  
			Gaps_IO_DataFile  gid_grid ;
	Gaps_IO_DataFile *  pgid_grid = 	& ( gid_grid ) ;
	Gaps_IO_DataFile  gid_cu ;
	Gaps_IO_DataFile *  pgid_cu = 	& ( gid_cu ) ;
	init_parallel_file_particle_for_mpi_fields_V0 ( 	& ( 	( ppis )->MPI_fieldE ) , pgid_grid , pgid_cu , pgcache , pcucache , "GRID_PARTICLE_file" , "CU_PARTICLE_file" , 1 );
	fprintf ( stderr , "rank=%d, Loading particles ...\n" , rank );
	read_particle_parallel_file_for_mpi_fields_V0 ( 	& ( 	( ppis )->MPI_fieldE ) , pgid_grid , pgid_cu , pgcache , pcucache );
	GAPS_IO_DeleteDataInfo ( pgid_cu );
	GAPS_IO_DeleteDataInfo ( pgid_grid );

	}else{
			if (  USE_NON_UNI_DENSITY  ){  
			init_non_uni_particle_fmpi ( 	& ( 	( ppis )->MPI_fieldE ) );

	}else{
			init_maxwell_dist_particle_fmpi ( 	& ( 	( ppis )->MPI_fieldE ) );

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
	init_Field3D_MPI_from ( paver_E , ptestfield );
	init_Field3D_MPI_from ( paver_B , ptestfield );
	init_Field3D_MPI_from ( paver_J , ptestfield );
	init_Field3D_MPI_from ( pext_krook , ptestfield );
	init_Field3D_MPI_from ( paver_EN , ptestfieldSPEC );
	blas_yiszero_Field3D_MPI ( paver_E , paver_E );
	blas_yiszero_Field3D_MPI ( paver_B , paver_B );
	blas_yiszero_Field3D_MPI ( paver_J , paver_J );
	blas_yiszero_Field3D_MPI ( paver_EN , paver_EN );
	double  G_CHECKPOINT_TIME = 	call_GET_VAR ( "CHECKPOINT_TIME" ) ;
	double  G_CHECKPOINT_NUM_SAVE = 	call_GET_VAR ( "CHECKPOINT_NUM_SAVE" ) ;
	double  G_USE_KROOK_FIELD = 	call_GET_VAR ( "USE_KROOK_FIELD" ) ;
	double  G_KROOK_MU_FREQ = 	call_GET_VAR ( "KROOK_MU_FREQ" ) ;
	double  G_USE_BORIS_YEE = 	call_GET_VAR ( "USE_BORIS_YEE" ) ;
	double  G_KROOK_SPEED_LIMIT = 	call_GET_VAR ( "KROOK_SPEED_LIMIT" ) ;
	double  M_USE_AVER_OUTPUT = 	call_GET_VAR ( "USE_AVER_OUTPUT" ) ;
	double  M_USE_1ST = 	call_GET_VAR ( "USE_1ST" ) ;
	if (  	(  G_KROOK_MU_FREQ || G_USE_KROOK_FIELD )  ){  
			init_external_field3d_FILTER_KROOK ( pext_krook );

	}else{
		0;

	 }
{
	test_set_mainland ( 	& ( ppis->MPI_FoutJ ) , 0.00000000000000000e+00 );
	sync_main_data_h2d ( 	& ( ppis->MPI_FoutJ ) );
	long  t = 0 ;
	long  tsave = 0 ;
	if (  G_CHECKPOINT_TIME  ){  
		(t = G_CHECKPOINT_TIME);

	}else{
		0;

	 }
	if (  G_CHECKPOINT_NUM_SAVE  ){  
		(tsave = G_CHECKPOINT_NUM_SAVE);

	}else{
		0;

	 }
	if (  USE_CHECKPOINT  ){  
			fprintf ( stderr , "rank=%d, Loading...\n" , rank );
	FILE *  fp = 	load_identity_state_and_alloc_file_pointer ( rank ) ;
	if (  fp  ){  
			load_long ( fp , 	& ( t ) );
	load_long ( fp , 	& ( tsave ) );
	load_Particle_in_Cell_MPI ( fp , ppis );
	if (  M_USE_AVER_OUTPUT  ){  
			load_Field3D_MPI ( fp , paver_E );
	load_Field3D_MPI ( fp , paver_B );
	load_Field3D_MPI ( fp , paver_J );
	load_Field3D_MPI ( fp , paver_EN );

	}else{
		0;

	 }
	fclose ( fp );

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
}
	}else{
		0;

	 }
{
	long  newtsave = ((tsave)?(tsave):(-1)) ;
	init_parallel_file_for_mpi_fields ( ptestfield , pgid , "tmpEB" , newtsave , G_GAPSIO_VERSION );
	init_parallel_file_for_mpi_fields ( ptestfield , pgidj , "tmpJ" , newtsave , G_GAPSIO_VERSION );
	init_parallel_file_for_mpi_fields ( ptestfieldSPEC , pgide , "tmpEN" , newtsave , G_GAPSIO_VERSION );
}	double  tbeg = 	wclk_now (  ) ;
	double  tend = tbeg ;
	double  G_USE_ECRH_INPUT = 	call_GET_VAR ( "USE_ECRH_INPUT" ) ;
	double  G_USE_REL = 	call_GET_VAR ( "USE_REL" ) ;
	double  G_NUM_HIGH_ORDER_L = 	call_GET_VAR ( "NUM_HIGH_ORDER_L" ) ;
	double  curt_profile_only = 	wclk_now (  ) ;
	for (0 ; t<NUM_TIMESTEP ; t++)
	{
	if (  	(  USE_CHECKPOINT && 	(  0 == 	(  t % NUM_CHECKPOINT_TIMESTEP ) ) )  ){  
			fprintf ( stderr , "rank=%d, Saving...\n" , rank );
	FILE *  fp = 	save_identity_state_and_alloc_file_pointer ( rank ) ;
	save_long ( fp , 	& ( t ) );
	save_long ( fp , 	& ( tsave ) );
	save_Particle_in_Cell_MPI ( fp , ppis );
	if (  M_USE_AVER_OUTPUT  ){  
			save_Field3D_MPI ( fp , paver_E );
	save_Field3D_MPI ( fp , paver_B );
	save_Field3D_MPI ( fp , paver_J );
	save_Field3D_MPI ( fp , paver_EN );

	}else{
		0;

	 }
	fclose ( fp );
	if (  M_USE_DUMP_PARTICLE_FILE  ){  
			Gaps_IO_DataFile  gid_grid ;
	Gaps_IO_DataFile *  pgid_grid = 	& ( gid_grid ) ;
	Gaps_IO_DataFile  gid_cu ;
	Gaps_IO_DataFile *  pgid_cu = 	& ( gid_cu ) ;
	init_parallel_file_particle_for_mpi_fields_V0 ( 	& ( 	( ppis )->MPI_fieldE ) , pgid_grid , pgid_cu , pgcache , pcucache , "tmpGRID_PARTICLE_file" , "tmpCU_PARTICLE_file" , 0 );
	dump_particle_parallel_file_for_mpi_fields_V0 ( 	& ( 	( ppis )->MPI_fieldE ) , pgid_grid , pgid_cu , pgcache , pcucache );
	fprintf ( stderr , "rank=%d, Saving particles ...\n" , rank );
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
	set_ecrh_fields ( 	& ( ppis->MPI_fieldE ) , 	(  t * 	(  E_ECRH_FREQ * DELTAT ) ) , E_ECRH_AMPX , E_ECRH_AMPY , E_ECRH_AMPZ , E_ECRH_KY , E_ECRH_KZ , E_ECRH_IKT , E_ECRH_LOC_X0 , E_ECRH_LOC_Y0 , E_ECRH_LOC_Y1 , E_ECRH_LOC_Z0 , E_ECRH_LOC_Z1 );

	}else{
		0;

	 }
	if (  	(  USE_TORI || G_USE_REL )  ){  
			blas_yisax_Field3D_MPI ( 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_fieldB1 ) , 1.00000000000000000e+00 , 	& ( ppis->MPI_fieldB ) );
	MPI_Yee_FDTD_Curl_E ( 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_fieldE ) , DELTAT );
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
	if (  USE_INIT_EXT_EB  ){  
			blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldE ) , 1 , 	& ( ppis->MPI_fieldE_ext ) );
	blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB ) , 1 , 	& ( ppis->MPI_fieldB_ext ) );
	blas_axpy_Field3D_MPI ( 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_fieldB1 ) , 1 , 	& ( ppis->MPI_fieldB_ext ) );

	}else{
		0;

	 }
	double  T_TORI_X0 = 	call_GET_VAR ( "TORI_X0" ) ;
	double  T_TORI_SOLVE_ERR = 	call_GET_VAR ( "TORI_SOLVE_ERR" ) ;
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
	blas_yiszero_synced_Field3D_MPI ( 	& ( ppis->MPI_FoutJ ) , 	& ( ppis->MPI_FoutJ ) );
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
	if (  0  ){  
		(fp = 	fopen ( "dbg00" , "wb" ));
	dump_particles ( 	& ( ppis->MPI_fieldE ) , fp );
	fclose ( fp );

	}else{
		0;

	 }
	if (  USE_TORI  ){  
			if (  M_USE_SMALL_NUM_GRIDS  ){  
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
			MPI_geo_rel_1st_fwd ( ppis , 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_FoutJ ) , pmass , pchg , DELTAT , T_TORI_X0 , T_TORI_SOLVE_ERR );

	 }

	}else{
			if (  M_USE_SMALL_NUM_GRIDS  ){  
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
			MPI_relng_1st ( ppis , 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB1 ) , 	& ( ppis->MPI_FoutJ ) , pmass , pchg , DELTAT , T_TORI_X0 , T_TORI_SOLVE_ERR );

	 }

	 }
	if (  0  ){  
		(fp = 	fopen ( "dbg01" , "wb" ));
	dump_particles ( 	& ( ppis->MPI_fieldE ) , fp );
	fclose ( fp );
	exit ( 0 );

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
			fprintf ( stderr , "%s: %fs\n" , "merge_current/relng/geo_rel" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	merge_ovlp_mpi_field ( 	& ( ppis->MPI_FoutJ ) );
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
	call_particle_sort_mpi ( ppis , 0 , 0 );
	call_particle_sort_mpi ( ppis , 1 , 0 );
	call_particle_sort_mpi ( ppis , 2 , 0 );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "sort particle" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

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
			MPI_RECT_YEE_CURL_L ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldB1 ) , M_DELTA_Z , M_DELTA_Y , M_DELTA_X , DELTAT );

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
	if (  USE_FILTER  ){  
			blas_mulxy_Field3D_MPI ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldE_filter ) );
	sync_ovlp_mpi_field ( 	& ( ppis->MPI_fieldE ) );
	blas_mulxy_Field3D_MPI ( 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB_filter ) );
	sync_ovlp_mpi_field ( 	& ( ppis->MPI_fieldB ) );

	}else{
		0;

	 }
	MPI_Yee_FDTD_MUR_ABC ( pMPI_fieldE , pMPI_fieldEtmp , DELTAT , G_USE_ABC_DIR , G_USE_PEC_DIR , G_USE_DAMP_DIR );
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
			MPI_RECT_YEE_CURL_L ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldB1 ) , M_DELTA_Z , M_DELTA_Y , M_DELTA_X , DELTAT );

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
			ITG_split_2nd_all_passes ( ppis , DELTAT , 	(  1.00000000000000000e+00 / (pchg)[0] ) , M_ITG_CONST_NE0 , M_USE_VLO );

	}else{
			split_2nd_all_passes ( ppis , DELTAT , M_USE_VLO );

	 }

	 }
	if (  USE_FILTER  ){  
			blas_mulxy_Field3D_MPI ( 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldE ) , 	& ( ppis->MPI_fieldE_filter ) );
	sync_ovlp_mpi_field ( 	& ( ppis->MPI_fieldE ) );
	blas_mulxy_Field3D_MPI ( 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB ) , 	& ( ppis->MPI_fieldB_filter ) );
	sync_ovlp_mpi_field ( 	& ( ppis->MPI_fieldB ) );

	}else{
		0;

	 }

	 }

	 }

	 }
	if (  G_KROOK_MU_FREQ  ){  
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
	if (  	(  rank == 0 )  ){  
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
}
	 }

	 }
	long  i = 0 ;
	sync_main_data_d2h ( ptestfield );
	PS_MPI_Finalize (  );
	return  0 ;}
