
#include "pubdefs.h"
int  print_max (Field3D_MPI *  in )
;
double  wclk_now ()
;
double  gen_sts_dt (int  j ,int  nt ,double  nv )
;
double  TEMPERATURE_DIST_global_procedure (long  cursp ,double  z ,double  y ,double  x ,long  l )
;
double  DENSITY_DIST_global_procedure (long  cursp ,double  z ,double  y ,double  x )
;
double  V0_x_global_procedure (long  cursp ,double  z ,double  y ,double  x )
;
double  V0_y_global_procedure (long  cursp ,double  z ,double  y ,double  x )
;
double  V0_z_global_procedure (long  cursp ,double  z ,double  y ,double  x )
;
int  dm_bicg_fun (Field3D_MPI *  out ,Field3D_MPI *  in ,dm_fv *  fv )
;
int  cayley_dm_new_fun_all (Field3D_MPI *  out ,Field3D_MPI *  in ,dm_fv *  fv ,double  lftrht )
;
int  cayley_dm_new_fun (Field3D_MPI *  out ,Field3D_MPI *  in ,dm_fv *  fv )
;
int  cayley_dm_new_fun_right (Field3D_MPI *  out ,Field3D_MPI *  in ,dm_fv *  fv )
;
void  high_order_split_pic (void *  ppis ,double  dt ,int  l )
;
int  main (int  argc ,char * *  argv )
;
