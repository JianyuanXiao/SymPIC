
#include "pubdefs.h"
long  load_int (FILE *  fp ,int *  p_data )
;
long  save_int (FILE *  fp ,int *  p_data )
;
long  load_long (FILE *  fp ,long *  p_data )
;
long  save_long (FILE *  fp ,long *  p_data )
;
long  load_float (FILE *  fp ,float *  p_data )
;
long  save_float (FILE *  fp ,float *  p_data )
;
long  load_double (FILE *  fp ,double *  p_data )
;
long  save_double (FILE *  fp ,double *  p_data )
;
long  load_Particle_in_Cell_MPI (FILE *  fp ,Particle_in_Cell_MPI *  datas )
;
long  save_Particle_in_Cell_MPI (FILE *  fp ,Particle_in_Cell_MPI *  datas )
;
long  load_Field3D_MPI_ALL (FILE *  fp ,Field3D_MPI_ALL *  datas )
;
long  save_Field3D_MPI_ALL (FILE *  fp ,Field3D_MPI_ALL *  datas )
;
long  load_Field3D_MPI (FILE *  fp ,Field3D_MPI *  datas )
;
long  save_Field3D_MPI (FILE *  fp ,Field3D_MPI *  datas )
;
long  load_Field3D_Seq (FILE *  fp ,Field3D_Seq *  datas )
;
long  save_Field3D_Seq (FILE *  fp ,Field3D_Seq *  datas )
;
long  load_One_Particle_Collection (FILE *  fp ,One_Particle_Collection *  datas )
;
long  save_One_Particle_Collection (FILE *  fp ,One_Particle_Collection *  datas )
;
int  save_state_from_fp (FILE *  fp )
;
int  load_state_from_fp (FILE *  fp )
;
FILE *  load_identity_state_and_alloc_file_pointer (int  mpi_rank )
;
FILE *  save_identity_state_and_alloc_file_pointer (int  mpi_rank )
;
