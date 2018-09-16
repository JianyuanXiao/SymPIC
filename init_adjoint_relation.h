
#include "pubdefs.h"
int  init_complexity_tid (unsigned long  num_proc ,unsigned long  num_thread ,size_t *  ori_vec ,long *  num_thread_array ,long *  local_tid_array )
;
int  init_uniform_tid (unsigned long  num_proc ,unsigned long  num_thread ,long *  num_thread_array ,long *  local_tid_array )
;
long  get_cur_tid (long  pid ,long  num_thread ,long  num_proc ,long *  num_thread_array )
;
long  get_cur_num_tid (long  pid ,long  num_thread ,long  num_proc ,long *  num_thread_array )
;
long  find_the_proc_id (long  tid ,unsigned long  num_proc ,long *  num_thread_array )
;
int  init_adjoint_relations (Field3D_Seq *  pthis ,long  n ,long  ndim ,long  adj_type ,long  num_proc ,long *  ovvec ,long *  ori_vec ,long *  num_thread_array ,long *  local_tid_array )
;
