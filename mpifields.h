
#include "pubdefs.h"
size_t  get_pscmc_type_len (int  num )
;
int  set_Field3D_Seq (Field3D_Seq *  pthis ,void *  pe ,double  delta_x ,double  delta_y ,double  delta_z ,long  xlen ,long  ylen ,long  zlen ,long  numvec ,int  ovlp ,int  num_ele ,int  CD_type ,long  x_num_thread_block ,long  y_num_thread_block ,long  z_num_thread_block ,long  global_pid )
;
int  c_delete_Field3D_Seq (Field3D_Seq *  pthis )
;
int  c_command_flush (Field3D_Seq *  pthis )
;
int  c_alloc_Field3D_Seq (Field3D_Seq *  pthis ,int  is_init_kernels )
;
int  c_Field3D_Seq_ovlp_merge_ovlp_m2o (Field3D_Seq *  pthis ,int  is_sync_layer )
;
int  c_Field3D_Seq_ovlp_merge_ovlp_o2m (Field3D_Seq *  pthis ,int  is_sync_layer )
;
int  c_Field3D_Seq_ovlp_sync_ovlp_m2o (Field3D_Seq *  pthis ,int  is_sync_layer )
;
int  c_Field3D_Seq_ovlp_sync_ovlp_o2m (Field3D_Seq *  pthis ,int  is_sync_layer )
;
int  c_Field3D_Seq_dm_1st_eqn_right (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  phi_1 ,Field3D_Seq *  A1 ,Field3D_Seq *  A2 ,Field3D_Seq *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  c_Field3D_Seq_dm_1st_eqn_core (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  phi_1 ,Field3D_Seq *  A1 ,Field3D_Seq *  A2 ,Field3D_Seq *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  c_Field3D_Seq_dm_1st_eqn_fdtd (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  phi_1 ,Field3D_Seq *  A1 ,Field3D_Seq *  A2 ,Field3D_Seq *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  c_Field3D_Seq_GEO_YEE_CURL_L (Field3D_Seq *  pthis ,Field3D_Seq *  inB0 ,double  x0 ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  DT )
;
int  c_Field3D_Seq_RECT_YEE_CURL_L (Field3D_Seq *  pthis ,Field3D_Seq *  inB0 ,double  DELTA_Z ,double  DELTA_Y ,double  DELTA_X ,double  DT )
;
int  c_Field3D_Seq_kgm_eqn_core (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT ,double  M ,double  Q ,double  DX ,double  GEXT ,double  rfz0 ,int  swap_input )
;
int  c_Field3D_Seq_kgm_calc_rho (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT ,double  M ,double  Q ,double  DX ,double  refz0 ,double  q ,double  dtodx ,int  mode ,int  swap_input )
;
int  c_Field3D_Seq_PML_FDTD_CURL_BWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,Field3D_Seq *  outPMLEB ,Field3D_Seq *  inPMLEB ,double  DT ,double  M ,double  Q ,double  DX ,double  DY ,double  DZ ,int  abc_dir ,int  level ,int  pml_m ,double  max_sigma ,long  allxmax ,long  allymax ,long  allzmax )
;
int  c_Field3D_Seq_PML_FDTD_CURL_FWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,Field3D_Seq *  outPMLEB ,Field3D_Seq *  inPMLEB ,double  DT ,double  M ,double  Q ,double  DX ,double  DY ,double  DZ ,int  abc_dir ,int  level ,int  pml_m ,double  max_sigma ,long  allxmax ,long  allymax ,long  allzmax )
;
int  c_Field3D_Seq_merge_current (Field3D_Seq *  pthis ,Field3D_Seq *  inEB )
;
int  c_Field3D_Seq_merge_current_2 (Field3D_Seq *  pthis ,Field3D_Seq *  inEB )
;
int  c_Field3D_Seq_Yee_FDTD_Div_FWD_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  c_Field3D_Seq_Yee_FDTD_Div_FWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  c_Field3D_Seq_Yee_FDTD_Div_BWD_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  c_Field3D_Seq_Yee_FDTD_Div_BWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  c_Field3D_Seq_Yee_FDTD_Curl_FWD_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  c_Field3D_Seq_Yee_FDTD_Curl_FWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  c_Field3D_Seq_Yee_FDTD_Curl_BWD_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  c_Field3D_Seq_Yee_FDTD_Curl_BWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  c_Field3D_Seq_Yee_FDTD_Grad_FWD_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  c_Field3D_Seq_Yee_FDTD_Grad_FWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  c_Field3D_Seq_Yee_FDTD_Grad_BWD_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  c_Field3D_Seq_Yee_FDTD_Grad_BWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  c_Field3D_Seq_Yee_FDTD_Curl_B_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  c_Field3D_Seq_Yee_FDTD_Curl_B (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  c_Field3D_Seq_Yee_FDTD_Curl_E_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  c_Field3D_Seq_Yee_FDTD_Curl_E (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  openmp_delete_Field3D_Seq (Field3D_Seq *  pthis )
;
int  openmp_command_flush (Field3D_Seq *  pthis )
;
int  openmp_alloc_Field3D_Seq (Field3D_Seq *  pthis ,int  is_init_kernels )
;
int  openmp_Field3D_Seq_ovlp_merge_ovlp_m2o (Field3D_Seq *  pthis ,int  is_sync_layer )
;
int  openmp_Field3D_Seq_ovlp_merge_ovlp_o2m (Field3D_Seq *  pthis ,int  is_sync_layer )
;
int  openmp_Field3D_Seq_ovlp_sync_ovlp_m2o (Field3D_Seq *  pthis ,int  is_sync_layer )
;
int  openmp_Field3D_Seq_ovlp_sync_ovlp_o2m (Field3D_Seq *  pthis ,int  is_sync_layer )
;
int  openmp_Field3D_Seq_dm_1st_eqn_right (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  phi_1 ,Field3D_Seq *  A1 ,Field3D_Seq *  A2 ,Field3D_Seq *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  openmp_Field3D_Seq_dm_1st_eqn_core (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  phi_1 ,Field3D_Seq *  A1 ,Field3D_Seq *  A2 ,Field3D_Seq *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  openmp_Field3D_Seq_dm_1st_eqn_fdtd (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  phi_1 ,Field3D_Seq *  A1 ,Field3D_Seq *  A2 ,Field3D_Seq *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  openmp_Field3D_Seq_GEO_YEE_CURL_L (Field3D_Seq *  pthis ,Field3D_Seq *  inB0 ,double  x0 ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  DT )
;
int  openmp_Field3D_Seq_RECT_YEE_CURL_L (Field3D_Seq *  pthis ,Field3D_Seq *  inB0 ,double  DELTA_Z ,double  DELTA_Y ,double  DELTA_X ,double  DT )
;
int  openmp_Field3D_Seq_kgm_eqn_core (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT ,double  M ,double  Q ,double  DX ,double  GEXT ,double  rfz0 ,int  swap_input )
;
int  openmp_Field3D_Seq_kgm_calc_rho (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT ,double  M ,double  Q ,double  DX ,double  refz0 ,double  q ,double  dtodx ,int  mode ,int  swap_input )
;
int  openmp_Field3D_Seq_PML_FDTD_CURL_BWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,Field3D_Seq *  outPMLEB ,Field3D_Seq *  inPMLEB ,double  DT ,double  M ,double  Q ,double  DX ,double  DY ,double  DZ ,int  abc_dir ,int  level ,int  pml_m ,double  max_sigma ,long  allxmax ,long  allymax ,long  allzmax )
;
int  openmp_Field3D_Seq_PML_FDTD_CURL_FWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,Field3D_Seq *  outPMLEB ,Field3D_Seq *  inPMLEB ,double  DT ,double  M ,double  Q ,double  DX ,double  DY ,double  DZ ,int  abc_dir ,int  level ,int  pml_m ,double  max_sigma ,long  allxmax ,long  allymax ,long  allzmax )
;
int  openmp_Field3D_Seq_merge_current (Field3D_Seq *  pthis ,Field3D_Seq *  inEB )
;
int  openmp_Field3D_Seq_merge_current_2 (Field3D_Seq *  pthis ,Field3D_Seq *  inEB )
;
int  openmp_Field3D_Seq_Yee_FDTD_Div_FWD_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  openmp_Field3D_Seq_Yee_FDTD_Div_FWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  openmp_Field3D_Seq_Yee_FDTD_Div_BWD_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  openmp_Field3D_Seq_Yee_FDTD_Div_BWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  openmp_Field3D_Seq_Yee_FDTD_Curl_FWD_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  openmp_Field3D_Seq_Yee_FDTD_Curl_FWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  openmp_Field3D_Seq_Yee_FDTD_Curl_BWD_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  openmp_Field3D_Seq_Yee_FDTD_Curl_BWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  openmp_Field3D_Seq_Yee_FDTD_Grad_FWD_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  openmp_Field3D_Seq_Yee_FDTD_Grad_FWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  openmp_Field3D_Seq_Yee_FDTD_Grad_BWD_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  openmp_Field3D_Seq_Yee_FDTD_Grad_BWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  openmp_Field3D_Seq_Yee_FDTD_Curl_B_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  openmp_Field3D_Seq_Yee_FDTD_Curl_B (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  openmp_Field3D_Seq_Yee_FDTD_Curl_E_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  openmp_Field3D_Seq_Yee_FDTD_Curl_E (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  command_flush_Field3D_Seq (Field3D_Seq *  pthis )
;
int  alloc_Field3D_Seq (Field3D_Seq *  pthis ,int  is_init_kernels )
;
int  delete_Field3D_Seq (Field3D_Seq *  pthis )
;
int  Field3D_Seq_ovlp_merge_ovlp_m2o (Field3D_Seq *  pthis ,int  is_sync_layer )
;
int  Field3D_Seq_ovlp_merge_ovlp_o2m (Field3D_Seq *  pthis ,int  is_sync_layer )
;
int  Field3D_Seq_ovlp_sync_ovlp_m2o (Field3D_Seq *  pthis ,int  is_sync_layer )
;
int  Field3D_Seq_ovlp_sync_ovlp_o2m (Field3D_Seq *  pthis ,int  is_sync_layer )
;
int  Field3D_Seq_kgm_eqn_core (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT ,double  M ,double  Q ,double  DX ,double  GEXT ,double  rfz0 ,int  swap_input )
;
int  Field3D_Seq_kgm_calc_rho (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT ,double  M ,double  Q ,double  DX ,double  refz0 ,double  q ,double  dtodx ,int  mode ,int  swap_input )
;
int  Field3D_Seq_PML_FDTD_CURL_BWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,Field3D_Seq *  outPMLEB ,Field3D_Seq *  inPMLEB ,double  DT ,double  M ,double  Q ,double  DX ,double  DY ,double  DZ ,int  abc_dir ,int  level ,int  pml_m ,double  max_sigma ,long  allxmax ,long  allymax ,long  allzmax )
;
int  Field3D_Seq_PML_FDTD_CURL_FWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,Field3D_Seq *  outPMLEB ,Field3D_Seq *  inPMLEB ,double  DT ,double  M ,double  Q ,double  DX ,double  DY ,double  DZ ,int  abc_dir ,int  level ,int  pml_m ,double  max_sigma ,long  allxmax ,long  allymax ,long  allzmax )
;
int  Field3D_Seq_merge_current (Field3D_Seq *  pthis ,Field3D_Seq *  inEB )
;
int  Field3D_Seq_merge_current_2 (Field3D_Seq *  pthis ,Field3D_Seq *  inEB )
;
int  Field3D_Seq_Yee_FDTD_Div_FWD_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  Field3D_Seq_Yee_FDTD_Div_FWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  Field3D_Seq_Yee_FDTD_Div_BWD_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  Field3D_Seq_Yee_FDTD_Div_BWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  Field3D_Seq_Yee_FDTD_Curl_FWD_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  Field3D_Seq_Yee_FDTD_Curl_FWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  Field3D_Seq_Yee_FDTD_Curl_BWD_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  Field3D_Seq_Yee_FDTD_Curl_BWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  Field3D_Seq_Yee_FDTD_Grad_FWD_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  Field3D_Seq_Yee_FDTD_Grad_FWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  Field3D_Seq_Yee_FDTD_Grad_BWD_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  Field3D_Seq_Yee_FDTD_Grad_BWD (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  Field3D_Seq_Yee_FDTD_Curl_B_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  Field3D_Seq_Yee_FDTD_Curl_B (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  Field3D_Seq_Yee_FDTD_Curl_E_4th (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  Field3D_Seq_Yee_FDTD_Curl_E (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  DT )
;
int  Field3D_Seq_dm_1st_eqn_right (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  phi_1 ,Field3D_Seq *  A1 ,Field3D_Seq *  A2 ,Field3D_Seq *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  MPI_dm_1st_eqn_right (Field3D_MPI *  pthis ,Field3D_MPI *  phi_in ,Field3D_MPI *  phi_1 ,Field3D_MPI *  A1 ,Field3D_MPI *  A2 ,Field3D_MPI *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  Field3D_Seq_dm_1st_eqn_core (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  phi_1 ,Field3D_Seq *  A1 ,Field3D_Seq *  A2 ,Field3D_Seq *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  MPI_dm_1st_eqn_core (Field3D_MPI *  pthis ,Field3D_MPI *  phi_in ,Field3D_MPI *  phi_1 ,Field3D_MPI *  A1 ,Field3D_MPI *  A2 ,Field3D_MPI *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  Field3D_Seq_dm_1st_eqn_fdtd (Field3D_Seq *  pthis ,Field3D_Seq *  phi_in ,Field3D_Seq *  phi_1 ,Field3D_Seq *  A1 ,Field3D_Seq *  A2 ,Field3D_Seq *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  MPI_dm_1st_eqn_fdtd (Field3D_MPI *  pthis ,Field3D_MPI *  phi_in ,Field3D_MPI *  phi_1 ,Field3D_MPI *  A1 ,Field3D_MPI *  A2 ,Field3D_MPI *  A3 ,double  DM_A ,double  Q ,double  M ,double  DT )
;
int  Field3D_Seq_GEO_YEE_CURL_L (Field3D_Seq *  pthis ,Field3D_Seq *  inB0 ,double  x0 ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  DT )
;
int  MPI_GEO_YEE_CURL_L (Field3D_MPI *  pthis ,Field3D_MPI *  inB0 ,double  x0 ,double  DELTA_X ,double  DELTA_Y ,double  DELTA_Z ,double  DT )
;
int  Field3D_Seq_RECT_YEE_CURL_L (Field3D_Seq *  pthis ,Field3D_Seq *  inB0 ,double  DELTA_Z ,double  DELTA_Y ,double  DELTA_X ,double  DT )
;
int  MPI_RECT_YEE_CURL_L (Field3D_MPI *  pthis ,Field3D_MPI *  inB0 ,double  DELTA_Z ,double  DELTA_Y ,double  DELTA_X ,double  DT )
;
int  Field3D_Seq_yee_abc_ (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_abc_ (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_abc_ (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_pec_ (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_pec_ (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_pec_ (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_damp_ (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_damp_ (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_damp_ (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_abc_x (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_abc_x (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_abc_x (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_pec_x (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_pec_x (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_pec_x (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_damp_x (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_damp_x (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_damp_x (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_abc_y (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_abc_y (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_abc_y (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_pec_y (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_pec_y (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_pec_y (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_damp_y (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_damp_y (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_damp_y (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_abc_z (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_abc_z (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_abc_z (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_pec_z (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_pec_z (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_pec_z (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_damp_z (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_damp_z (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_damp_z (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_abc_xy (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_abc_xy (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_abc_xy (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_pec_xy (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_pec_xy (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_pec_xy (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_damp_xy (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_damp_xy (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_damp_xy (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_abc_xz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_abc_xz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_abc_xz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_pec_xz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_pec_xz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_pec_xz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_damp_xz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_damp_xz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_damp_xz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_abc_yz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_abc_yz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_abc_yz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_pec_yz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_pec_yz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_pec_yz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_damp_yz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_damp_yz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_damp_yz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_abc_xyz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_abc_xyz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_abc_xyz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_pec_xyz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_pec_xyz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_pec_xyz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_Seq_yee_damp_xyz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  c_Field3D_Seq_yee_damp_xyz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  openmp_Field3D_Seq_yee_damp_xyz (Field3D_Seq *  pthis ,Field3D_Seq *  inEB ,double  damp_vars ,double  deltat )
;
int  Field3D_MPI_yee_abc_ (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_pec_ (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_damp_ (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_abc_x (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_pec_x (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_damp_x (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_abc_y (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_pec_y (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_damp_y (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_abc_z (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_pec_z (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_damp_z (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_abc_xy (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_pec_xy (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_damp_xy (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_abc_xz (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_pec_xz (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_damp_xz (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_abc_yz (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_pec_yz (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_damp_yz (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_abc_xyz (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_pec_xyz (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
int  Field3D_MPI_yee_damp_xyz (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  deltat )
;
