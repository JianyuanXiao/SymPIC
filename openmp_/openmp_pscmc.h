
#include "local_header.h"
int  openmp_pscmc_mem_init (openmp_pscmc_env *  pe ,openmp_pscmc_mem *  pm ,int  type ,size_t  len )
;
int  openmp_pscmc_get_local_len ()
;
int  openmp_pscmc_get_env_len (size_t *  l )
;
int  openmp_pscmc_flush (openmp_pscmc_env *  pe )
;
void *  openmp_pscmc_get_h_data (openmp_pscmc_mem *  pm ,void * *  h_data )
;
int  openmp_pscmc_mem_destroy (openmp_pscmc_mem *  pm )
;
int  openmp_pscmc_mem_sync_d2h (openmp_pscmc_mem *  pm )
;
int  openmp_pscmc_mem_sync_h2d (openmp_pscmc_mem *  pm )
;
int  openmp_pscmc_env_init (openmp_pscmc_env *  pe ,int  dev_num ,void *  fv )
;
size_t  openmp_pscmc_mem_get_num (openmp_pscmc_mem *  pm )
;
