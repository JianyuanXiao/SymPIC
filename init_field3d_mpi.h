
#include "pubdefs.h"
void  init_Field3D_MPI_from_new_num_ele (Field3D_MPI *  pthis ,Field3D_MPI *  f ,int  new_num_ele )
;
void  init_Field3D_MPI_from (Field3D_MPI *  pthis ,Field3D_MPI *  f )
;
void  reinit_Field3D_MPI (Field3D_MPI *  pthis ,int  new_num_ele )
;
int  init_Field3D_MPI_ALL (Field3D_MPI *  pthis ,Field3D_Seq *  sample_field ,long  n_hilbert ,int  ndim ,int  adjoint_type ,long *  tids ,int64_t *  local_tid_array ,int *  cd_types ,int *  dev_nums ,long  num_runtime ,PS_MPI_Comm  comm ,long  cur_rank ,long  num_mpi_process )
;
int  command_flush_Field3D_MPI (Field3D_MPI *  pthis )
;
int  delete_Field3D_MPI (Field3D_MPI *  pthis )
;
void  init_external_field3d_E_2d_extend_rand (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat ,double  random_rate )
;
void  init_external_field3d_E_2d_extend (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat )
;
void  init_external_field3d_E (Field3D_MPI *  pthis )
;
void  init_external_field3d_B_2d_extend_rand (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat ,double  random_rate )
;
void  init_external_field3d_B_2d_extend (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat )
;
void  init_external_field3d_B (Field3D_MPI *  pthis )
;
void  init_external_field3d_E0_2d_extend_rand (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat ,double  random_rate )
;
void  init_external_field3d_E0_2d_extend (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat )
;
void  init_external_field3d_E0 (Field3D_MPI *  pthis )
;
void  init_external_field3d_B0_2d_extend_rand (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat ,double  random_rate )
;
void  init_external_field3d_B0_2d_extend (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat )
;
void  init_external_field3d_B0 (Field3D_MPI *  pthis )
;
void  init_external_field3d_FILTER_E_2d_extend_rand (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat ,double  random_rate )
;
void  init_external_field3d_FILTER_E_2d_extend (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat )
;
void  init_external_field3d_FILTER_E (Field3D_MPI *  pthis )
;
void  init_external_field3d_FILTER_B_2d_extend_rand (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat ,double  random_rate )
;
void  init_external_field3d_FILTER_B_2d_extend (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat )
;
void  init_external_field3d_FILTER_B (Field3D_MPI *  pthis )
;
void  init_external_field3d_FILTER_KROOK_2d_extend_rand (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat ,double  random_rate )
;
void  init_external_field3d_FILTER_KROOK_2d_extend (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat )
;
void  init_external_field3d_FILTER_KROOK (Field3D_MPI *  pthis )
;
void  init_external_field3d_DENSITY_DIST_2d_extend_rand (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat ,double  random_rate )
;
void  init_external_field3d_DENSITY_DIST_2d_extend (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat )
;
void  init_external_field3d_DENSITY_DIST (Field3D_MPI *  pthis )
;
void  init_external_field3d_without_ss_KGM_2d_extend_rand (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat ,double  random_rate )
;
void  init_external_field3d_without_ss_KGM_2d_extend (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat )
;
void  init_external_field3d_without_ss_KGM (Field3D_MPI *  pthis )
;
void  init_external_field3d_without_ss_DM_2d_extend_rand (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat ,double  random_rate )
;
void  init_external_field3d_without_ss_DM_2d_extend (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat )
;
void  init_external_field3d_without_ss_DM (Field3D_MPI *  pthis )
;
void  init_external_field3d_without_ss_DMf_2d_extend_rand (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat ,double  random_rate )
;
void  init_external_field3d_without_ss_DMf_2d_extend (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat )
;
void  init_external_field3d_without_ss_DMf (Field3D_MPI *  pthis )
;
void  init_external_field3d_without_ss_EXT_FLUID_RHO_S_VX0_2d_extend_rand (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat ,double  random_rate )
;
void  init_external_field3d_without_ss_EXT_FLUID_RHO_S_VX0_2d_extend (Field3D_MPI *  pthis ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat )
;
void  init_external_field3d_without_ss_EXT_FLUID_RHO_S_VX0 (Field3D_MPI *  pthis )
;
void  init_dm_dual_phi_global (Field3D_MPI *  psi1 ,Field3D_MPI *  psi2 ,double  amp_ext ,double  sgm_pz ,int  num_p ,double  dm_m ,double  dz ,double  zmax )
;
void  init_hydro_alpha_beta (Field3D_MPI *  pthis ,double  alp ,double  bet )
;
void  init_hydro_rho_s_vx (Field3D_MPI *  pthis ,double  rho0 ,double  drho0 ,double  s ,double  vx ,double  vy ,double  vz )
;
void  init_dm_phi_global_rand (Field3D_MPI *  pthis ,double  phi_r1 ,double  sgm )
;
void  init_dm_phi_global (Field3D_MPI *  pthis ,double  dm_m ,double  pz_r ,double  pz_i ,double  dm_z_offset ,double  lmd ,double  a ,double  b ,double  sgm_p ,double  dz ,double  t0 ,double  phi34v ,double  phi ,double  amp_ext )
;
void  init_dm_A0_global (Field3D_MPI *  pthis ,double  ampEy ,double  dt )
;
void  init_dm_A1_global (Field3D_MPI *  pthis ,double  ampx ,double  ampEz ,double  dt )
;
void  init_hydro_ext_s0 (Field3D_MPI *  pthis ,double  dsdx ,int  dir )
;
void  init_hydro_ext_A0y (Field3D_MPI *  pthis ,double  B0 )
;
void  init_kgm_assemble (Field3D_MPI *  pthis ,double  ampx ,double  ampEy ,double  dt ,double  sgm ,double  frq ,double  kgm_ass_e_loc0 )
;
void  init_kgm_global (Field3D_MPI *  pthis ,double  phi_r0 ,double  m0 ,double  e0 ,double  ampx ,double  ampEy ,double  dt ,double  sgm ,double  frq ,double  kgm_mid ,double  kgm_len_a0 ,double  kgm_sgm_dens ,double  use_sper ,double  xmid ,double  ymid ,double  zmid )
;
int  set_ecrh_fields (Field3D_MPI *  pthis ,double  tomega ,double  ampx ,double  ampy ,double  ampz ,double  ky ,double  kz ,double  ikt ,long  x0 ,double  y0 ,double  y1 ,double  z0 ,double  z1 ,double  ecrh_square_num ,double  phi0 )
;
int  set_lhcd_fields (Field3D_MPI *  pthis ,double  tomega ,double  k ,long  location ,double  ampx ,double  ampy )
;
int  test_set_mainland (Field3D_MPI *  pthis ,double  val )
;
