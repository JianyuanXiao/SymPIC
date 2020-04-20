
#include "pubdefs.h"
size_t  fwrite_multi_proc (char *  ptr ,size_t  size ,size_t  nmemb ,FILE *  stream ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
size_t  fread_multi_proc (char *  ptr ,size_t  size ,size_t  nmemb ,FILE *  stream ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
long  load_int (FILE *  fp ,int *  p_data ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
long  save_int (FILE *  fp ,int *  p_data ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
long  load_long (FILE *  fp ,long *  p_data ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
long  save_long (FILE *  fp ,long *  p_data ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
long  load_float (FILE *  fp ,float *  p_data ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
long  save_float (FILE *  fp ,float *  p_data ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
long  load_double (FILE *  fp ,double *  p_data ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
long  save_double (FILE *  fp ,double *  p_data ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
long  load_Particle_in_Cell_MPI (FILE *  fp ,Particle_in_Cell_MPI *  datas ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
long  save_Particle_in_Cell_MPI (FILE *  fp ,Particle_in_Cell_MPI *  datas ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
long  load_Field3D_MPI_ALL (FILE *  fp ,Field3D_MPI_ALL *  datas ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
long  save_Field3D_MPI_ALL (FILE *  fp ,Field3D_MPI_ALL *  datas ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
long  load_Field3D_MPI (FILE *  fp ,Field3D_MPI *  datas ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
long  save_Field3D_MPI (FILE *  fp ,Field3D_MPI *  datas ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
long  load_Field3D_Seq (FILE *  fp ,Field3D_Seq *  datas ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
long  save_Field3D_Seq (FILE *  fp ,Field3D_Seq *  datas ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
long  load_One_Particle_Collection (FILE *  fp ,One_Particle_Collection *  datas ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
long  save_One_Particle_Collection (FILE *  fp ,One_Particle_Collection *  datas ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
int  save_state_from_fp (FILE *  fp ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
int  load_state_from_fp (FILE *  fp ,int  cur_proc ,int  num_one_group ,int  num_max_proc )
;
FILE *  load_identity_state_and_alloc_file_pointer (int  mpi_rank ,int  num_one_group )
;
FILE *  save_identity_state_and_alloc_file_pointer (int  mpi_rank ,int  num_one_group )
;
