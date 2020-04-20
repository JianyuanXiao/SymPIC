
#include "pubdefs.h"
int  one_step_calc_current (Field3D_MPI *  pthis ,Field3D_MPI *  x ,Particle_in_Cell_MPI *  fv )
;
int  Jacobi_x (Field3D_MPI *  pthis ,Field3D_MPI *  dx ,Particle_in_Cell_MPI * *  fv )
;
int  init_jfnk_newton_space (jfnk_newton_space *  pthis ,Field3D_MPI *  x ,linear_operator_mpi  oscc ,double  newton_solve_err ,double  solve_err ,int  zmax ,int  newton_zmax ,double  epsl ,void *  fv )
;
int  jfnk_newton_simple_mpi (jfnk_newton_space *  pthis ,Field3D_MPI *  inx )
;
int  jfnk_newton_init_parameters (jfnk_newton_space *  pthis ,int  N_l ,int  N_M ,double *  pmass ,double *  pcharge )
;
