
#include "pubdefs.h"
int  c_blas_sum_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y )
;
int  openmp_blas_sum_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y )
;
int  blas_sum_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y )
;
double  blas_sum_Field3D_MPI (Field3D_MPI *  pthis ,Field3D_MPI *  y )
;
int  c_blas_dot_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,Field3D_Seq *  x )
;
int  openmp_blas_dot_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,Field3D_Seq *  x )
;
int  blas_dot_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,Field3D_Seq *  x )
;
double  blas_dot_Field3D_MPI (Field3D_MPI *  pthis ,Field3D_MPI *  y ,Field3D_MPI *  x )
;
int  c_blas_findmax_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y )
;
int  openmp_blas_findmax_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y )
;
int  blas_findmax_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y )
;
double  blas_findmax_Field3D_MPI (Field3D_MPI *  pthis ,Field3D_MPI *  y )
;
int  c_blas_mulxy_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,Field3D_Seq *  x )
;
int  openmp_blas_mulxy_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,Field3D_Seq *  x )
;
int  blas_mulxy_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,Field3D_Seq *  x )
;
int  blas_mulxy_Field3D_MPI (Field3D_MPI *  pthis ,Field3D_MPI *  y ,Field3D_MPI *  x )
;
int  c_blas_axpby_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,double  a ,Field3D_Seq *  x ,double  b )
;
int  openmp_blas_axpby_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,double  a ,Field3D_Seq *  x ,double  b )
;
int  blas_axpby_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,double  a ,Field3D_Seq *  x ,double  b )
;
int  blas_axpby_Field3D_MPI (Field3D_MPI *  pthis ,Field3D_MPI *  y ,double  a ,Field3D_MPI *  x ,double  b )
;
int  c_blas_axpy_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,double  a ,Field3D_Seq *  x )
;
int  openmp_blas_axpy_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,double  a ,Field3D_Seq *  x )
;
int  blas_axpy_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,double  a ,Field3D_Seq *  x )
;
int  blas_axpy_Field3D_MPI (Field3D_MPI *  pthis ,Field3D_MPI *  y ,double  a ,Field3D_MPI *  x )
;
int  c_blas_yisax_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,double  a ,Field3D_Seq *  x )
;
int  openmp_blas_yisax_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,double  a ,Field3D_Seq *  x )
;
int  blas_yisax_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,double  a ,Field3D_Seq *  x )
;
int  blas_yisax_Field3D_MPI (Field3D_MPI *  pthis ,Field3D_MPI *  y ,double  a ,Field3D_MPI *  x )
;
int  c_blas_invy_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y )
;
int  openmp_blas_invy_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y )
;
int  blas_invy_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y )
;
int  blas_invy_Field3D_MPI (Field3D_MPI *  pthis ,Field3D_MPI *  y )
;
int  c_blas_get_ITG_Potential_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,Field3D_Seq *  x ,Field3D_Seq *  u ,double  minus_over_q_e )
;
int  openmp_blas_get_ITG_Potential_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,Field3D_Seq *  x ,Field3D_Seq *  u ,double  minus_over_q_e )
;
int  blas_get_ITG_Potential_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,Field3D_Seq *  x ,Field3D_Seq *  u ,double  minus_over_q_e )
;
int  blas_get_ITG_Potential_Field3D_MPI (Field3D_MPI *  pthis ,Field3D_MPI *  y ,Field3D_MPI *  x ,Field3D_MPI *  u ,double  minus_over_q_e )
;
int  c_blas_yisconst_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,double  a )
;
int  openmp_blas_yisconst_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,double  a )
;
int  blas_yisconst_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,double  a )
;
int  blas_yisconst_Field3D_MPI (Field3D_MPI *  pthis ,Field3D_MPI *  y ,double  a )
;
int  c_blas_yiszero_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y )
;
int  openmp_blas_yiszero_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y )
;
int  blas_yiszero_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y )
;
int  blas_yiszero_Field3D_MPI (Field3D_MPI *  pthis ,Field3D_MPI *  y )
;
int  c_blas_mulxy_numele3_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,Field3D_Seq *  x )
;
int  openmp_blas_mulxy_numele3_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,Field3D_Seq *  x )
;
int  blas_mulxy_numele3_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y ,Field3D_Seq *  x )
;
int  blas_mulxy_numele3_Field3D_MPI (Field3D_MPI *  pthis ,Field3D_MPI *  y ,Field3D_MPI *  x )
;
int  c_blas_yiszero_synced_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y )
;
int  openmp_blas_yiszero_synced_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y )
;
int  blas_yiszero_synced_Field3D_Seq (Field3D_Seq *  pthis ,Field3D_Seq *  y )
;
int  blas_yiszero_synced_Field3D_MPI (Field3D_MPI *  pthis ,Field3D_MPI *  y )
;
int  mpi_init_bicg (bicg_space *  pthis ,linear_operator_mpi  A ,Field3D_MPI *  x ,int  zmax ,double  solve_err ,void *  fv )
;
int  mpi_simple_bicgstab (bicg_space *  pthis ,Field3D_MPI *  x ,Field3D_MPI *  b )
;
