#include <stdio.h>
#include <stdlib.h>
#include "cfgcst.h"
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
#include <math.h>
#include <cgapsio.h>
#include "blas_shell.h"
#include <cgapsio.h>
#include "mpi_fieldio.h"
#include "run_particle.h"
#include "sync_fields.h"
double  wclk_now ();
	FILE *  parfp = NULL ;
int  split_pass_xyz_zyx_mpi_shell (Particle_in_Cell_MPI *  pthis ,double  dt0 ,int  xyzzyx ,int  merge_J ,int  use_vlo ){
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
	double  curt_profile_only = 	wclk_now (  ) ;
	blas_yiszero_synced_Field3D_MPI ( pMPI_FoutJ , pMPI_FoutJ );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "set J zero" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	if (  	(  use_small_grid == 1 )  ){  
			blas_yiszero_Field3D_MPI ( 	& ( pthis->MPI_LFoutJ ) , 	& ( pthis->MPI_LFoutJ ) );

	}else{
			if (  	(  use_small_grid == 2 )  ){  
			blas_yiszero_synced_Field3D_MPI ( 	& ( pthis->MPI_LFoutJ ) , 	& ( pthis->MPI_LFoutJ ) );

	}else{
		0;

	 }

	 }
	if (  	(  USE_FILTER == 3 )  ){  
			blas_yisax_Field3D_MPI ( 	& ( pthis->MPI_fieldEtmp1 ) , 	& ( pthis->MPI_fieldEtmp1 ) , 1 , 	& ( pthis->MPI_fieldE ) );
	blas_yisax_Field3D_MPI ( 	& ( pthis->MPI_fieldBtmp1 ) , 	& ( pthis->MPI_fieldBtmp1 ) , 1 , 	& ( pthis->MPI_fieldB ) );

	}else{
		0;

	 }
	if (  	(  USE_FILTER == 1 )  ){  
			blas_mulxy_Field3D_MPI ( 	& ( pthis->MPI_fieldE ) , 	& ( pthis->MPI_fieldE ) , 	& ( pthis->MPI_fieldE_filter ) );
	sync_ovlp_mpi_field ( 	& ( pthis->MPI_fieldE ) );
	blas_mulxy_Field3D_MPI ( 	& ( pthis->MPI_fieldB ) , 	& ( pthis->MPI_fieldB ) , 	& ( pthis->MPI_fieldB_filter ) );
	sync_ovlp_mpi_field ( 	& ( pthis->MPI_fieldB ) );

	}else{
		0;

	 }
	if (  	(  USE_FILTER == 3 )  ){  
			blas_axpy_Field3D_MPI ( 	& ( pthis->MPI_fieldEtmp1 ) , 	& ( pthis->MPI_fieldEtmp1 ) , -1 , 	& ( pthis->MPI_fieldE ) );
	blas_axpy_Field3D_MPI ( 	& ( pthis->MPI_fieldBtmp1 ) , 	& ( pthis->MPI_fieldBtmp1 ) , -1 , 	& ( pthis->MPI_fieldB ) );

	}else{
		0;

	 }
	if (  USE_INIT_EXT_EB  ){  
			blas_axpy_Field3D_MPI ( 	& ( MPI_fieldB ) , 	& ( MPI_fieldB ) , 1.00000000000000000e+00 , 	& ( MPI_fieldB_ext ) );

	}else{
		0;

	 }
	sync_ovlp_mpi_field ( 	& ( MPI_fieldB ) );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "sync EB" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	if (  xyzzyx  ){  
			if (  1  ){  
			split_pass_x_mpi_multi_runtime ( pthis , dt0 , use_vlo );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "Pass X" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	call_particle_sort_mpi ( pthis , 0 , use_vlo );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "Sort X" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	split_pass_y_mpi_multi_runtime ( pthis , dt0 , use_vlo );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "Pass Y" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	call_particle_sort_mpi ( pthis , 1 , use_vlo );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "Sort Y" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	split_pass_z_mpi_multi_runtime ( pthis , dt0 , use_vlo );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "Pass Z" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	call_particle_sort_mpi ( pthis , 2 , use_vlo );
	if (  USE_PROFILE  ){  
			PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	double  cur_time = 	wclk_now (  ) ;
	PS_MPI_Barrier ( PS_MPI_COMM_WORLD );
	int  rank ;
	PS_MPI_Comm_rank ( PS_MPI_COMM_WORLD , 	& ( rank ) );
	if (  	(  rank == 0 )  ){  
			fprintf ( stderr , "%s: %fs\n" , "Sort Z" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	if (  	(  use_small_grid && merge_J )  ){  
			if (  	(  use_small_grid == 1 )  ){  
			MPI_merge_current ( pMPI_FoutJ , 	& ( pthis->MPI_LFoutJ ) );

	}else{
			if (  	(  use_small_grid == 2 )  ){  
			MPI_merge_current_2 ( pMPI_FoutJ , 	& ( pthis->MPI_LFoutJ ) );

	}else{
		0;

	 }

	 }

	}else{
		0;

	 }

	}else{
			fprintf ( stderr , "beg dump\n" );
	FILE *  fp ;
(fp = 	fopen ( "dbg00" , "wb" ));
	dump_particles ( 	& ( pthis->MPI_fieldE ) , fp );
	fclose ( fp );
	split_pass_x_mpi_multi_runtime ( pthis , dt0 , use_vlo );
(fp = 	fopen ( "dbg01" , "wb" ));
	dump_particles ( 	& ( pthis->MPI_fieldE ) , fp );
	fclose ( fp );
	fprintf ( stderr , "aft spl dump\n" );
	call_particle_sort_mpi ( pthis , 0 , use_vlo );
	fprintf ( stderr , "aft splx\n" );
(fp = 	fopen ( "dbg01a" , "wb" ));
	dump_particles ( 	& ( pthis->MPI_fieldE ) , fp );
	fclose ( fp );
	split_pass_y_mpi_multi_runtime ( pthis , dt0 , use_vlo );
	call_particle_sort_mpi ( pthis , 1 , use_vlo );
	fprintf ( stderr , "aft sply\n" );
(fp = 	fopen ( "dbg02a" , "wb" ));
	dump_particles ( 	& ( pthis->MPI_fieldE ) , fp );
	fclose ( fp );
	split_pass_z_mpi_multi_runtime ( pthis , dt0 , use_vlo );
	call_particle_sort_mpi ( pthis , 2 , use_vlo );
	fprintf ( stderr , "aft splz\n" );
(fp = 	fopen ( "dbg03a" , "wb" ));
	dump_particles ( 	& ( pthis->MPI_fieldE ) , fp );
	fclose ( fp );
	Gaps_IO_DataFile  gid ;
	Gaps_IO_DataFile *  pgid = 	& ( gid ) ;
	if (  	(  use_small_grid && merge_J )  ){  
			if (  	(  use_small_grid == 1 )  ){  
			MPI_merge_current ( pMPI_FoutJ , 	& ( pthis->MPI_LFoutJ ) );

	}else{
			if (  	(  use_small_grid == 2 )  ){  
			MPI_merge_current_2 ( pMPI_FoutJ , 	& ( pthis->MPI_LFoutJ ) );

	}else{
		
	 }

	 }
	sync_main_data_d2h ( pMPI_FoutJ );
	sync_main_data_d2h ( 	& ( pthis->MPI_LFoutJ ) );
	init_parallel_file_for_mpi_fields ( pMPI_FoutJ , pgid , "tmpJ1" , -1 , 0 , 0 );
	mpi_field_write_to_file ( pMPI_FoutJ , pgid , 0 );
	init_parallel_file_for_mpi_fields ( 	& ( pthis->MPI_LFoutJ ) , pgid , "tmpJdbg" , -1 , 0 , 0 );
	mpi_field_write_to_file ( 	& ( pthis->MPI_LFoutJ ) , pgid , 0 );
	fprintf ( stderr , "end dump\n" );

	}else{
		0;

	 }

	 }

	}else{
			split_pass_z_mpi_multi_runtime ( pthis , dt0 , use_vlo );
	call_particle_sort_mpi ( pthis , 2 , use_vlo );
	split_pass_y_mpi_multi_runtime ( pthis , dt0 , use_vlo );
	call_particle_sort_mpi ( pthis , 1 , use_vlo );
	split_pass_x_mpi_multi_runtime ( pthis , dt0 , use_vlo );
	call_particle_sort_mpi ( pthis , 0 , use_vlo );
	if (  	(  use_small_grid && merge_J )  ){  
			if (  	(  use_small_grid == 1 )  ){  
			MPI_merge_current ( pMPI_FoutJ , 	& ( pthis->MPI_LFoutJ ) );

	}else{
			if (  	(  use_small_grid == 2 )  ){  
			MPI_merge_current_2 ( pMPI_FoutJ , 	& ( pthis->MPI_LFoutJ ) );

	}else{
		0;

	 }

	 }

	}else{
		0;

	 }

	 }
	if (  merge_J  ){  
			merge_ovlp_mpi_field ( pMPI_FoutJ );

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
			fprintf ( stderr , "%s: %fs\n" , "merge J" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	if (  USE_INIT_EXT_EB  ){  
			blas_axpy_Field3D_MPI ( 	& ( MPI_fieldB ) , 	& ( MPI_fieldB ) , -1.00000000000000000e+00 , 	& ( MPI_fieldB_ext ) );

	}else{
		0;

	 }
	if (  	(  USE_FILTER == 3 )  ){  
			blas_axpy_Field3D_MPI ( 	& ( pthis->MPI_fieldE ) , 	& ( pthis->MPI_fieldE ) , 1 , 	& ( pthis->MPI_fieldEtmp1 ) );
	blas_axpy_Field3D_MPI ( 	& ( pthis->MPI_fieldB ) , 	& ( pthis->MPI_fieldB ) , 1 , 	& ( pthis->MPI_fieldBtmp1 ) );

	}else{
		0;

	 }
	if (  	(  USE_FILTER == 1 )  ){  
			blas_mulxy_Field3D_MPI ( pMPI_FoutJ , pMPI_FoutJ , 	& ( pthis->MPI_fieldE_filter ) );

	}else{
		0;

	 }
	if (  merge_J  ){  
			blas_axpy_Field3D_MPI ( 	& ( MPI_fieldE ) , 	& ( MPI_fieldE ) , -1 , pMPI_FoutJ );

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
			fprintf ( stderr , "%s: %fs\n" , "E=E-J" , 	(  cur_time - curt_profile_only ) );

	}else{
		0;

	 }
(curt_profile_only = cur_time);

	}else{
		0;

	 }
	return  0 ;}
