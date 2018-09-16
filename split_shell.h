
#include "pubdefs.h"
double  wclk_now ();
;
int  split_1st_all_passes (Particle_in_Cell_MPI *  pthis ,double  dt0 ,int  use_vlo )
;
int  pass_GeqB (Particle_in_Cell_MPI *  pthis ,double  deltat )
;
int  FDTD_2_4th_ALL_passes (Particle_in_Cell_MPI *  pthis ,double  dt0 )
;
int  FDTD_2_2th_ALL_passes (Particle_in_Cell_MPI *  pthis ,double  dt0 )
;
int  ITG_split_2nd_all_passes (Particle_in_Cell_MPI *  pthis ,double  dt0 ,double  moqe ,double  ne0 ,int  use_vlo )
;
int  split_2nd_all_passes (Particle_in_Cell_MPI *  pthis ,double  dt0 ,int  use_vlo )
;
