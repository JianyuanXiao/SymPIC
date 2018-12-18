
#include "pubdefs.h"
int  init_parallel_file_particle_for_mpi_fields_V0 (Field3D_MPI *  pthis ,Gaps_IO_DataFile *  gid_grid ,Gaps_IO_DataFile *  gid_cu ,long *  pgcache ,long *  pcucache ,char *  pName_grid ,char *  pName_cu ,long  numt ,int  ro )
;
int  dump_particle_parallel_file_for_mpi_fields_V0 (Field3D_MPI *  pthis ,Gaps_IO_DataFile *  gid_grid ,Gaps_IO_DataFile *  gid_cu ,long *  pgcache ,long *  pcucache ,long  numt )
;
int  read_particle_parallel_file_for_mpi_fields_V0 (Field3D_MPI *  pthis ,Gaps_IO_DataFile *  gid_grid ,Gaps_IO_DataFile *  gid_cu ,long *  pgcache ,long *  pcucache ,long  numt )
;
int  init_parallel_file_for_mpi_fields_V0 (Field3D_MPI *  pthis ,Gaps_IO_DataFile *  gid ,char *  pName ,int64_t  time_step )
;
int  init_parallel_file_for_mpi_fields (Field3D_MPI *  pthis ,Gaps_IO_DataFile *  gid ,char *  pName ,int64_t  time_step ,int  version )
;
int  read_parallel_file_for_mpi_fields (Field3D_MPI *  pthis ,Gaps_IO_DataFile *  gid ,int64_t  timestep )
;
int  write_parallel_file_for_mpi_fields (Field3D_MPI *  pthis ,Gaps_IO_DataFile *  gid ,int64_t  timestep )
;
int  mpi_field_2_outfile (Field3D_MPI *  pthis ,char *  fname )
;
int  mpi_field_write_to_file (Field3D_MPI *  pthis ,Gaps_IO_DataFile *  pgid ,long  num_timestep )
;
