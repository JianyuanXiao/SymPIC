
#include "local_header.h"
int  c_pscmc_mem_init (c_pscmc_env *  pe ,c_pscmc_mem *  pm ,int  type ,size_t  len )
;
int  c_pscmc_flush (c_pscmc_env *  pe )
;
void *  c_pscmc_get_h_data (c_pscmc_mem *  pm ,void * *  h_data )
;
int  c_pscmc_get_env_len (size_t *  l )
;
int  c_pscmc_get_local_len ()
;
int  c_pscmc_mem_destroy (c_pscmc_mem *  pm )
;
int  c_pscmc_get_num_compute_units (c_pscmc_env *  pe )
;
int  c_pscmc_mem_sync_d2h (c_pscmc_mem *  pm )
;
int  c_pscmc_mem_sync_h2d (c_pscmc_mem *  pm )
;
int  c_pscmc_env_init (c_pscmc_env *  pe ,int  dev_num ,void *  fv )
;
size_t  c_pscmc_mem_get_num (c_pscmc_mem *  pm )
;
