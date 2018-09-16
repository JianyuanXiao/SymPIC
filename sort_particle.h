
#include "pubdefs.h"
int  c_call_particle_sort_single_x (One_Particle_Collection *  pthis )
;
int  c_call_particle_sort_single_y (One_Particle_Collection *  pthis )
;
int  c_call_particle_sort_single_z (One_Particle_Collection *  pthis )
;
int  c_call_particle_sort_single_x_vlo (One_Particle_Collection *  pthis )
;
int  c_call_particle_sort_single_y_vlo (One_Particle_Collection *  pthis )
;
int  c_call_particle_sort_single_z_vlo (One_Particle_Collection *  pthis )
;
int  openmp_call_particle_sort_single_x (One_Particle_Collection *  pthis )
;
int  openmp_call_particle_sort_single_y (One_Particle_Collection *  pthis )
;
int  openmp_call_particle_sort_single_z (One_Particle_Collection *  pthis )
;
int  openmp_call_particle_sort_single_x_vlo (One_Particle_Collection *  pthis )
;
int  openmp_call_particle_sort_single_y_vlo (One_Particle_Collection *  pthis )
;
int  openmp_call_particle_sort_single_z_vlo (One_Particle_Collection *  pthis )
;
int  c_call_move_back_kernel_single (One_Particle_Collection *  pthis )
;
int  openmp_call_move_back_kernel_single (One_Particle_Collection *  pthis )
;
int  call_particle_sort_single (One_Particle_Collection *  pthis ,int  dir ,int  use_vlo )
;
int  dump_particles_mpi (One_Particle_Collection *  pthis ,FILE *  of )
;
int  print_particles_mpi (One_Particle_Collection *  pthis ,int  dir )
;
int  swap_particle_sort_host_l (Field3D_MPI *  pthis ,int  dir )
;
int  swap_particle_sort_host_r (Field3D_MPI *  pthis ,int  dir )
;
void  dump_particles (Field3D_MPI *  pthis ,FILE *  fp )
;
int  call_particle_sort_mpi (Field3D_MPI *  pthis ,int  dir ,int  use_vlo )
;
