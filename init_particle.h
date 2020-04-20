
#include "pubdefs.h"
void  user_defined_particle_distribution (double *  xyzvx ,long  xyzx ,long  xyzy ,long  xyzz ,int  cur_sp ,long  l ,long  grid_load ,long  external_para );
;
extern long  srand_seed;long  find_vec_id (long  id ,long *  adj_ids ,long  numvec )
;
int  init_particle (One_Particle_Collection *  pthis ,Field3D_Seq *  pfield ,double  Mass ,double  Charge ,double  Number_particle_per_marker ,long  grid_cache_len ,long  cu_cache_length )
;
int  delete_particle (One_Particle_Collection *  pthis )
;
int  init_particle_mpi (Field3D_MPI *  pthis ,int  num_spec ,double *  Mass ,double *  Charge ,double *  Number_particle_per_marker ,long *  grid_cache_len ,long *  cu_cache_length )
;
int  generate_random_particle_mpi (Field3D_MPI *  pthis )
;
int  delete_particle_mpi (Field3D_MPI *  pthis )
;
int  generate_random_self_particle (One_Particle_Collection *  pthis )
;
int  init_maxwell_dist_particle_opc (One_Particle_Collection *  pthis ,int  tgrid_load ,double  VT ,int  use_lost_cone ,double  mu0 ,double  delta )
;
int  init_maxwell_dist_particle_fmpi (Field3D_MPI *  pthis )
;
int  init_user_defined_particle_opc (One_Particle_Collection *  pthis ,int  tgrid_load ,int  cur_sp ,double  vt ,int  external_para )
;
int  init_user_defined_particle_fmpi (Field3D_MPI *  pthis )
;
int  init_non_uni_particle_opc (One_Particle_Collection *  pthis ,int  tgrid_load ,int  cur_sp ,double  VT ,double  vmax )
;
int  init_non_uni_particle_fmpi (Field3D_MPI *  pthis ,double  vmax )
;
int  init_single_particle_opc (One_Particle_Collection *  pthis ,int  tgrid_load )
;
int  init_single_particle_fmpi (Field3D_MPI *  pthis )
;
void  init_global_particles (Particle_in_Cell_MPI *  pthis ,Field3D_MPI *  fE ,Field3D_MPI *  fEN ,int  use_small_num_grids ,int  pml_abc_dir ,int  pml_level ,double  pml_sigma_max ,double  deltat ,int  num_spec ,long *  allxyzmax ,double *  massp ,double *  chargep ,double *  npm ,long *  grid_cache_len ,long *  cu_cache_len ,int *  particle_types ,int  reduce_dim ,double  r_x_rat ,double  r_y_rat ,double  r_z_rat ,double  random_rate )
;
