
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
int  MPI_merge_current (Field3D_MPI *  pthis ,Field3D_MPI *  inEB )
;
int  MPI_Yee_FDTD_MUR_ABC (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ,int  use_abc ,int  use_pec ,int  use_damp )
;
int  MPI_kgm_eqn_core (Field3D_MPI *  pthis ,Field3D_MPI *  inEB ,double  DT ,double  m ,double  Q ,double  DX ,double  extg ,double  refz0 )
;
