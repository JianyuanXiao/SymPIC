
#include "pubdefs.h"
int  init_dist_particle_nogrid_opc (One_Particle_Collection *  pthis ,int  tgrid_load ,double  VT ,int  fluid_dim )
;
int  init_dist_particle_nogrid_fmpi (Field3D_MPI *  pthis ,int  fluid_dim )
;
int  init_implicit_particle (One_Particle_Collection *  pthis )
;
int  init_implicit_particle_mpi (Field3D_MPI *  pthis )
;
int  c_One_Particle_Collection_split_pass_xyzE_particle_push_r (One_Particle_Collection *  pthis ,Field3D_Seq *  fieldE ,Field3D_Seq *  fieldB ,Field3D_Seq *  FoutJ ,double  Mass0_lst_fix ,double  Charge0_lst_fix ,double  Deltat ,int  N_l ,int  N_M ,int  push_J ,int  SPEC ,int  NUM_SPEC )
;
int  c_One_Particle_Collection_split_pass_xyzE_particle (One_Particle_Collection *  pthis ,Field3D_Seq *  fieldE ,Field3D_Seq *  fieldB ,Field3D_Seq *  FoutJ ,double  Mass0_lst_fix ,double  Charge0_lst_fix ,double  Deltat ,int  N_l ,int  N_M ,int  push_J ,int  SPEC ,int  NUM_SPEC )
;
int  openmp_One_Particle_Collection_split_pass_xyzE_particle_push_r (One_Particle_Collection *  pthis ,Field3D_Seq *  fieldE ,Field3D_Seq *  fieldB ,Field3D_Seq *  FoutJ ,double  Mass0_lst_fix ,double  Charge0_lst_fix ,double  Deltat ,int  N_l ,int  N_M ,int  push_J ,int  SPEC ,int  NUM_SPEC )
;
int  openmp_One_Particle_Collection_split_pass_xyzE_particle (One_Particle_Collection *  pthis ,Field3D_Seq *  fieldE ,Field3D_Seq *  fieldB ,Field3D_Seq *  FoutJ ,double  Mass0_lst_fix ,double  Charge0_lst_fix ,double  Deltat ,int  N_l ,int  N_M ,int  push_J ,int  SPEC ,int  NUM_SPEC )
;
int  One_Particle_Collection_split_pass_xyzE_particle_push_r (One_Particle_Collection *  pthis ,Field3D_Seq *  fieldE ,Field3D_Seq *  fieldB ,Field3D_Seq *  FoutJ ,double  Mass0_lst_fix ,double  Charge0_lst_fix ,double  Deltat ,int  N_l ,int  N_M ,int  push_J ,int  spec ,int  num_spec )
;
int  MPI_split_pass_xyzE_particle_push_r (Particle_in_Cell_MPI *  pthis ,Field3D_MPI *  fieldE ,Field3D_MPI *  fieldB ,Field3D_MPI *  FoutJ ,double *  Mass0 ,double *  Charge0 ,double  Deltat ,int  N_l ,int  N_M ,int  push_J )
;
int  One_Particle_Collection_split_pass_xyzE_particle (One_Particle_Collection *  pthis ,Field3D_Seq *  fieldE ,Field3D_Seq *  fieldB ,Field3D_Seq *  FoutJ ,double  Mass0_lst_fix ,double  Charge0_lst_fix ,double  Deltat ,int  N_l ,int  N_M ,int  push_J ,int  spec ,int  num_spec )
;
int  MPI_split_pass_xyzE_particle (Particle_in_Cell_MPI *  pthis ,Field3D_MPI *  fieldE ,Field3D_MPI *  fieldB ,Field3D_MPI *  FoutJ ,double *  Mass0 ,double *  Charge0 ,double  Deltat ,int  N_l ,int  N_M ,int  push_J )
;
