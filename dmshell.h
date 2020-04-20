
#include "pubdefs.h"
int  Field3D_Seq_dm_1st_eqn_right (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  phi_1 ,Field3D_Seq *  A1 ,Field3D_Seq *  A2 ,Field3D_Seq *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  MPI_dm_1st_eqn_right (Field3D_MPI *  pthis ,Field3D_MPI *  phi_in ,Field3D_MPI *  phi_1 ,Field3D_MPI *  A1 ,Field3D_MPI *  A2 ,Field3D_MPI *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  Field3D_Seq_dm_1st_eqn_core (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  phi_1 ,Field3D_Seq *  A1 ,Field3D_Seq *  A2 ,Field3D_Seq *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  MPI_dm_1st_eqn_core (Field3D_MPI *  pthis ,Field3D_MPI *  phi_in ,Field3D_MPI *  phi_1 ,Field3D_MPI *  A1 ,Field3D_MPI *  A2 ,Field3D_MPI *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  Field3D_Seq_dm_1st_eqn_fdtd (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  phi_1 ,Field3D_Seq *  A1 ,Field3D_Seq *  A2 ,Field3D_Seq *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  MPI_dm_1st_eqn_fdtd (Field3D_MPI *  pthis ,Field3D_MPI *  phi_in ,Field3D_MPI *  phi_1 ,Field3D_MPI *  A1 ,Field3D_MPI *  A2 ,Field3D_MPI *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  Field3D_Seq_dm_calc_hamt_dual (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  MPI_dm_calc_hamt_dual (Field3D_MPI *  pthis ,Field3D_MPI *  phi_in ,Field3D_MPI *  A1 ,Field3D_MPI *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  Field3D_Seq_dm_cayley_eqn_core (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  MPI_dm_cayley_eqn_core (Field3D_MPI *  pthis ,Field3D_MPI *  phi_in ,Field3D_MPI *  A1 ,Field3D_MPI *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  Field3D_Seq_dm_exact_eqn_m (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  MPI_dm_exact_eqn_m (Field3D_MPI *  pthis ,Field3D_MPI *  phi_in ,Field3D_MPI *  A1 ,Field3D_MPI *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  Field3D_Seq_dm_calc_hamt (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  MPI_dm_calc_hamt (Field3D_MPI *  pthis ,Field3D_MPI *  phi_in ,Field3D_MPI *  A1 ,Field3D_MPI *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  Field3D_Seq_dm_cayley_eqn_J (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  MPI_dm_cayley_eqn_J (Field3D_MPI *  pthis ,Field3D_MPI *  phi_in ,Field3D_MPI *  A1 ,Field3D_MPI *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  Field3D_Seq_dm_bihamt_eqn_dydt (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  MPI_dm_bihamt_eqn_dydt (Field3D_MPI *  pthis ,Field3D_MPI *  phi_in ,Field3D_MPI *  A1 ,Field3D_MPI *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  Field3D_Seq_dm_bihamt_dual_psi_eqn_J (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  MPI_dm_bihamt_dual_psi_eqn_J (Field3D_MPI *  pthis ,Field3D_MPI *  phi_in ,Field3D_MPI *  A1 ,Field3D_MPI *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  c_alloc_Field3D_Seq_dmonly (Field3D_Seq *  pthis ,int  is_init_kernels )
;
int  c_Field3D_Seq_dm_1st_eqn_right (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  phi_1 ,Field3D_Seq *  A1 ,Field3D_Seq *  A2 ,Field3D_Seq *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  c_Field3D_Seq_dm_1st_eqn_core (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  phi_1 ,Field3D_Seq *  A1 ,Field3D_Seq *  A2 ,Field3D_Seq *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  c_Field3D_Seq_dm_1st_eqn_fdtd (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  phi_1 ,Field3D_Seq *  A1 ,Field3D_Seq *  A2 ,Field3D_Seq *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  c_Field3D_Seq_dm_calc_hamt_dual (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  c_Field3D_Seq_dm_cayley_eqn_core (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  c_Field3D_Seq_dm_exact_eqn_m (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  c_Field3D_Seq_dm_calc_hamt (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  c_Field3D_Seq_dm_cayley_eqn_J (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  c_Field3D_Seq_dm_bihamt_eqn_dydt (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  c_Field3D_Seq_dm_bihamt_dual_psi_eqn_J (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  openmp_alloc_Field3D_Seq_dmonly (Field3D_Seq *  pthis ,int  is_init_kernels )
;
int  openmp_Field3D_Seq_dm_1st_eqn_right (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  phi_1 ,Field3D_Seq *  A1 ,Field3D_Seq *  A2 ,Field3D_Seq *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  openmp_Field3D_Seq_dm_1st_eqn_core (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  phi_1 ,Field3D_Seq *  A1 ,Field3D_Seq *  A2 ,Field3D_Seq *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  openmp_Field3D_Seq_dm_1st_eqn_fdtd (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  phi_1 ,Field3D_Seq *  A1 ,Field3D_Seq *  A2 ,Field3D_Seq *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  openmp_Field3D_Seq_dm_calc_hamt_dual (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  openmp_Field3D_Seq_dm_cayley_eqn_core (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  openmp_Field3D_Seq_dm_exact_eqn_m (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  openmp_Field3D_Seq_dm_calc_hamt (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  openmp_Field3D_Seq_dm_cayley_eqn_J (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  openmp_Field3D_Seq_dm_bihamt_eqn_dydt (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  openmp_Field3D_Seq_dm_bihamt_dual_psi_eqn_J (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  A1 ,Field3D_Seq *  Y1 ,double  DT ,double  DZ ,double  DY ,double  DX ,double  DM_A ,double  Q ,double  M )
;
int  alloc_Field3D_Seq_dmonly (Field3D_Seq *  pthis ,int  is_init_kernels )
;
