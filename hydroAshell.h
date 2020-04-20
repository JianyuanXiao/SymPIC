
#include "pubdefs.h"
int  Field3D_Seq_hydro_push_vA (Field3D_Seq *  pthis ,Field3D_Seq *  alpha_beta_new ,Field3D_Seq *  alpha_beta ,Field3D_Seq *  rho_s_vx ,Field3D_Seq *  vA ,Field3D_Seq *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  MPI_hydro_push_vA (Field3D_MPI *  pthis ,Field3D_MPI *  alpha_beta_new ,Field3D_MPI *  alpha_beta ,Field3D_MPI *  rho_s_vx ,Field3D_MPI *  vA ,Field3D_MPI *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  Field3D_Seq_hydro_push_jac_alpha_beta (Field3D_Seq *  pthis ,Field3D_Seq *  alpha_beta_new ,Field3D_Seq *  alpha_beta ,Field3D_Seq *  rho_s_vx ,Field3D_Seq *  vA ,Field3D_Seq *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  MPI_hydro_push_jac_alpha_beta (Field3D_MPI *  pthis ,Field3D_MPI *  alpha_beta_new ,Field3D_MPI *  alpha_beta ,Field3D_MPI *  rho_s_vx ,Field3D_MPI *  vA ,Field3D_MPI *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  Field3D_Seq_hydro_push_alpha_beta (Field3D_Seq *  pthis ,Field3D_Seq *  alpha_beta_new ,Field3D_Seq *  alpha_beta ,Field3D_Seq *  rho_s_vx ,Field3D_Seq *  vA ,Field3D_Seq *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  MPI_hydro_push_alpha_beta (Field3D_MPI *  pthis ,Field3D_MPI *  alpha_beta_new ,Field3D_MPI *  alpha_beta ,Field3D_MPI *  rho_s_vx ,Field3D_MPI *  vA ,Field3D_MPI *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  Field3D_Seq_hydro_push_vx (Field3D_Seq *  pthis ,Field3D_Seq *  alpha_beta_new ,Field3D_Seq *  alpha_beta ,Field3D_Seq *  rho_s_vx ,Field3D_Seq *  vA ,Field3D_Seq *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  MPI_hydro_push_vx (Field3D_MPI *  pthis ,Field3D_MPI *  alpha_beta_new ,Field3D_MPI *  alpha_beta ,Field3D_MPI *  rho_s_vx ,Field3D_MPI *  vA ,Field3D_MPI *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  Field3D_Seq_hydro_push_rho_s (Field3D_Seq *  pthis ,Field3D_Seq *  alpha_beta_new ,Field3D_Seq *  alpha_beta ,Field3D_Seq *  rho_s_vx ,Field3D_Seq *  vA ,Field3D_Seq *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  MPI_hydro_push_rho_s (Field3D_MPI *  pthis ,Field3D_MPI *  alpha_beta_new ,Field3D_MPI *  alpha_beta ,Field3D_MPI *  rho_s_vx ,Field3D_MPI *  vA ,Field3D_MPI *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  c_alloc_Field3D_Seq_hydroAonly (Field3D_Seq *  pthis ,int  is_init_kernels )
;
int  c_Field3D_Seq_hydro_push_vA (Field3D_Seq *  pthis ,Field3D_Seq *  alpha_beta_new ,Field3D_Seq *  alpha_beta ,Field3D_Seq *  rho_s_vx ,Field3D_Seq *  vA ,Field3D_Seq *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  c_Field3D_Seq_hydro_push_jac_alpha_beta (Field3D_Seq *  pthis ,Field3D_Seq *  alpha_beta_new ,Field3D_Seq *  alpha_beta ,Field3D_Seq *  rho_s_vx ,Field3D_Seq *  vA ,Field3D_Seq *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  c_Field3D_Seq_hydro_push_alpha_beta (Field3D_Seq *  pthis ,Field3D_Seq *  alpha_beta_new ,Field3D_Seq *  alpha_beta ,Field3D_Seq *  rho_s_vx ,Field3D_Seq *  vA ,Field3D_Seq *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  c_Field3D_Seq_hydro_push_vx (Field3D_Seq *  pthis ,Field3D_Seq *  alpha_beta_new ,Field3D_Seq *  alpha_beta ,Field3D_Seq *  rho_s_vx ,Field3D_Seq *  vA ,Field3D_Seq *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  c_Field3D_Seq_hydro_push_rho_s (Field3D_Seq *  pthis ,Field3D_Seq *  alpha_beta_new ,Field3D_Seq *  alpha_beta ,Field3D_Seq *  rho_s_vx ,Field3D_Seq *  vA ,Field3D_Seq *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  openmp_alloc_Field3D_Seq_hydroAonly (Field3D_Seq *  pthis ,int  is_init_kernels )
;
int  openmp_Field3D_Seq_hydro_push_vA (Field3D_Seq *  pthis ,Field3D_Seq *  alpha_beta_new ,Field3D_Seq *  alpha_beta ,Field3D_Seq *  rho_s_vx ,Field3D_Seq *  vA ,Field3D_Seq *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  openmp_Field3D_Seq_hydro_push_jac_alpha_beta (Field3D_Seq *  pthis ,Field3D_Seq *  alpha_beta_new ,Field3D_Seq *  alpha_beta ,Field3D_Seq *  rho_s_vx ,Field3D_Seq *  vA ,Field3D_Seq *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  openmp_Field3D_Seq_hydro_push_alpha_beta (Field3D_Seq *  pthis ,Field3D_Seq *  alpha_beta_new ,Field3D_Seq *  alpha_beta ,Field3D_Seq *  rho_s_vx ,Field3D_Seq *  vA ,Field3D_Seq *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  openmp_Field3D_Seq_hydro_push_vx (Field3D_Seq *  pthis ,Field3D_Seq *  alpha_beta_new ,Field3D_Seq *  alpha_beta ,Field3D_Seq *  rho_s_vx ,Field3D_Seq *  vA ,Field3D_Seq *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  openmp_Field3D_Seq_hydro_push_rho_s (Field3D_Seq *  pthis ,Field3D_Seq *  alpha_beta_new ,Field3D_Seq *  alpha_beta ,Field3D_Seq *  rho_s_vx ,Field3D_Seq *  vA ,Field3D_Seq *  vAzero ,double  DT ,double  DZ ,double  DY ,double  DX ,double  U0 ,double  QM0 )
;
int  alloc_Field3D_Seq_hydroAonly (Field3D_Seq *  pthis ,int  is_init_kernels )
;
