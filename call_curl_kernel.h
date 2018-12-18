
#include "pubdefs.h"
int  MPI_Yee_FDTD_Curl_E (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT )
;
int  MPI_Yee_FDTD_Curl_B (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT )
;
int  MPI_Yee_FDTD_Curl_E_4th (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT )
;
int  MPI_Yee_FDTD_Curl_B_4th (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT )
;
int  MPI_Yee_FDTD_Grad_FWD (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT )
;
int  MPI_Yee_FDTD_Grad_BWD (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT )
;
int  MPI_Yee_FDTD_Grad_FWD_4th (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT )
;
int  MPI_Yee_FDTD_Grad_BWD_4th (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT )
;
int  MPI_Yee_FDTD_Curl_FWD (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT )
;
int  MPI_Yee_FDTD_Curl_BWD (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT )
;
int  MPI_Yee_FDTD_Curl_FWD_4th (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT )
;
int  MPI_Yee_FDTD_Curl_BWD_4th (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT )
;
int  MPI_Yee_FDTD_Div_FWD (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT )
;
int  MPI_Yee_FDTD_Div_BWD (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT )
;
int  MPI_Yee_FDTD_Div_FWD_4th (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT )
;
int  MPI_Yee_FDTD_Div_BWD_4th (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT )
;
int  MPI_merge_current_2 (Field3D_MPI *  pthis ,Field3D_MPI *  inEB )
;
int  MPI_merge_current (Field3D_MPI *  pthis ,Field3D_MPI *  inEB )
;
int  MPI_Yee_FDTD_MUR_ABC (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ,int  use_abc ,int  use_pec ,int  use_damp )
;
int  MPI_PML_FDTD_CURL_FWD (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,Field3D_MPI *  outPMLEB ,Field3D_MPI *  inPMLEB ,double  DT ,double  m ,double  q ,double  DX ,double  DY ,double  DZ ,int  abc_dir ,int  level ,int  pml_m ,double  max_sigma ,long  allxmax ,long  allymax ,long  allzmax )
;
int  MPI_PML_FDTD_CURL_BWD (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,Field3D_MPI *  outPMLEB ,Field3D_MPI *  inPMLEB ,double  DT ,double  m ,double  q ,double  DX ,double  DY ,double  DZ ,int  abc_dir ,int  level ,int  pml_m ,double  max_sigma ,long  allxmax ,long  allymax ,long  allzmax )
;
int  MPI_kgm_calc_rho (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ,double  m ,double  Q ,double  DX ,double  refz0 ,double  q ,double  dtodx ,int  mode ,int  swap_input )
;
int  MPI_kgm_eqn_core (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ,double  m ,double  Q ,double  DX ,double  extg ,double  refz0 ,int  swap_input )
;
