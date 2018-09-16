
#include "pubdefs.h"
void  init_Field3D_MPI_from_new_num_ele (Field3D_MPI *  pthis ,Field3D_MPI *  f ,int  new_num_ele )
;
void  init_Field3D_MPI_from (Field3D_MPI *  pthis ,Field3D_MPI *  f )
;
void  reinit_Field3D_MPI (Field3D_MPI *  pthis ,int  new_num_ele )
;
int  init_Field3D_MPI_ALL (Field3D_MPI *  pthis ,Field3D_Seq *  sample_field ,long  n_hilbert ,int  ndim ,int  adjoint_type ,long *  tids ,long *  local_tid_array ,int *  cd_types ,int *  dev_nums ,long  num_runtime ,PS_MPI_Comm  comm ,long  cur_rank ,long  num_mpi_process )
;
int  command_flush_Field3D_MPI (Field3D_MPI *  pthis )
;
int  delete_Field3D_MPI (Field3D_MPI *  pthis )
;
void  init_external_field3d_E (Field3D_MPI *  pthis )
;
void  init_external_field3d_B (Field3D_MPI *  pthis )
;
void  init_external_field3d_E0 (Field3D_MPI *  pthis )
;
void  init_external_field3d_B0 (Field3D_MPI *  pthis )
;
void  init_external_field3d_FILTER_E (Field3D_MPI *  pthis )
;
void  init_external_field3d_FILTER_B (Field3D_MPI *  pthis )
;
void  init_external_field3d_FILTER_KROOK (Field3D_MPI *  pthis )
;
void  init_dm_phi_global (Field3D_MPI *  pthis ,double  phi_r1 ,double  phi_r2 ,double  phi_r3 ,double  phi_r4 ,double  phi_i1 ,double  phi_i2 ,double  phi_i3 ,double  phi_i4 ,double  sgm ,double  frq )
;
void  init_dm_A0_global (Field3D_MPI *  pthis ,double  ampEy ,double  dt )
;
void  init_dm_A1_global (Field3D_MPI *  pthis ,double  ampx ,double  ampEy ,double  dt )
;
void  init_kgm_assemble (Field3D_MPI *  pthis ,double  ampx ,double  ampEy ,double  dt ,double  sgm ,double  frq ,double  kgm_ass_e_loc0 )
;
void  init_kgm_global (Field3D_MPI *  pthis ,double  phi_r0 ,double  m0 ,double  e0 ,double  ampx ,double  ampEy ,double  dt ,double  sgm ,double  frq ,double  kgm_mid ,double  kgm_len_a0 ,double  kgm_sgm_dens ,double  use_sper ,double  xmid ,double  ymid ,double  zmid )
;
int  set_ecrh_fields (Field3D_MPI *  pthis ,double  tomega ,double  ampx ,double  ampy ,double  ampz ,double  ky ,double  kz ,double  ikt ,long  x0 ,double  y0 ,double  y1 ,double  z0 ,double  z1 )
;
int  set_lhcd_fields (Field3D_MPI *  pthis ,double  tomega ,double  k ,long  location ,double  ampx ,double  ampy )
;
int  test_set_mainland (Field3D_MPI *  pthis ,double  val )
;
