//This file is generated from cfgcst.sch
extern long XMAX ;
extern long YMAX ;
extern long ZMAX ;
extern long NUM_PROCESS ;
extern long NUM_RUNTIME ;
extern long NUM_MAX_RUNTIME ;
extern long NUM_N_HILBERT ;
extern long NUM_N_HILBERT_DIMENSION ;
extern int HILBERT_DIR ;
extern long NUM_TIMESTEP ;
extern double DELTAT ;
extern long NUM_DUMP_TIMESTEP ;
extern long NUM_SPEC ;
extern long USE_NP_BOUNDARY ;
extern long USE_NON_UNI_DENSITY ;
extern long USE_NON_UNI_TEMPERATURE ;
extern long USE_INIT_EXT_EB ;
extern long USE_INIT_EB0 ;
extern long USE_FILTER ;
extern int USE_CHECKPOINT ;
extern int USE_INIT_V0 ;
extern int USE_KGM ;
extern double (* CAL_FUN_ONE_PARA_inner_procedure) (char* arg0, double arg1);
double call_CAL_FUN_ONE_PARA ( char* arg0, double arg1 );
#ifdef CSCHEME_HEAD
extern element * CAL_FUN_ONE_PARA ;
#endif
extern int USE_TORI ;
extern int USE_PROFILE ;
extern int USE_DM ;
extern int USE_LHCD_INPUT ;
extern long NUM_CHECKPOINT_TIMESTEP ;
extern long USE_NON_UNI_CACHE_DIST ;
extern long (* GET_DEV_TYPE_inner_procedure) (long arg0, long arg1);
long call_GET_DEV_TYPE ( long arg0, long arg1 );
#ifdef CSCHEME_HEAD
extern element * GET_DEV_TYPE ;
#endif
extern long (* GET_DEV_ID_inner_procedure) (long arg0, long arg1);
long call_GET_DEV_ID ( long arg0, long arg1 );
#ifdef CSCHEME_HEAD
extern element * GET_DEV_ID ;
#endif
extern long (* GET_NUM_LOCAL_THREAD_FROM_GLOBAL_TID_inner_procedure) (long arg0);
long call_GET_NUM_LOCAL_THREAD_FROM_GLOBAL_TID ( long arg0 );
#ifdef CSCHEME_HEAD
extern element * GET_NUM_LOCAL_THREAD_FROM_GLOBAL_TID ;
#endif
extern double (* GET_MASS_inner_procedure) (long arg0);
double call_GET_MASS ( long arg0 );
#ifdef CSCHEME_HEAD
extern element * GET_MASS ;
#endif
extern double (* GET_NPM_inner_procedure) (long arg0);
double call_GET_NPM ( long arg0 );
#ifdef CSCHEME_HEAD
extern element * GET_NPM ;
#endif
extern double (* GET_CHARGE_inner_procedure) (long arg0);
double call_GET_CHARGE ( long arg0 );
#ifdef CSCHEME_HEAD
extern element * GET_CHARGE ;
#endif
extern long (* GET_GRID_CACHE_LEN_inner_procedure) (long arg0);
long call_GET_GRID_CACHE_LEN ( long arg0 );
#ifdef CSCHEME_HEAD
extern element * GET_GRID_CACHE_LEN ;
#endif
extern long (* GET_CU_CACHE_LEN_inner_procedure) (long arg0);
long call_GET_CU_CACHE_LEN ( long arg0 );
#ifdef CSCHEME_HEAD
extern element * GET_CU_CACHE_LEN ;
#endif
extern long (* GET_INIT_LOAD_inner_procedure) (long arg0);
long call_GET_INIT_LOAD ( long arg0 );
#ifdef CSCHEME_HEAD
extern element * GET_INIT_LOAD ;
#endif
extern double (* GET_NON_UNI_CACHE_DIST_inner_procedure) (long arg0, long arg1);
double call_GET_NON_UNI_CACHE_DIST ( long arg0, long arg1 );
#ifdef CSCHEME_HEAD
extern element * GET_NON_UNI_CACHE_DIST ;
#endif
extern double (* GET_INIT_DENSITY_DIST_inner_procedure) (long arg0, double arg1, double arg2, double arg3);
double call_GET_INIT_DENSITY_DIST ( long arg0, double arg1, double arg2, double arg3 );
#ifdef CSCHEME_HEAD
extern element * GET_INIT_DENSITY_DIST ;
#endif
extern double (* GET_INIT_TEMPERATURE_DIST_inner_procedure) (long arg0, double arg1, double arg2, double arg3, long arg4);
double call_GET_INIT_TEMPERATURE_DIST ( long arg0, double arg1, double arg2, double arg3, long arg4 );
#ifdef CSCHEME_HEAD
extern element * GET_INIT_TEMPERATURE_DIST ;
#endif
extern double (* GET_INIT_E_inner_procedure) (double arg0, double arg1, double arg2, long arg3);
double call_GET_INIT_E ( double arg0, double arg1, double arg2, long arg3 );
#ifdef CSCHEME_HEAD
extern element * GET_INIT_E ;
#endif
extern double (* GET_INIT_B_inner_procedure) (double arg0, double arg1, double arg2, long arg3);
double call_GET_INIT_B ( double arg0, double arg1, double arg2, long arg3 );
#ifdef CSCHEME_HEAD
extern element * GET_INIT_B ;
#endif
extern double (* GET_INIT_E0_inner_procedure) (double arg0, double arg1, double arg2, long arg3);
double call_GET_INIT_E0 ( double arg0, double arg1, double arg2, long arg3 );
#ifdef CSCHEME_HEAD
extern element * GET_INIT_E0 ;
#endif
extern double (* GET_INIT_B0_inner_procedure) (double arg0, double arg1, double arg2, long arg3);
double call_GET_INIT_B0 ( double arg0, double arg1, double arg2, long arg3 );
#ifdef CSCHEME_HEAD
extern element * GET_INIT_B0 ;
#endif
extern double (* GET_INIT_VT_inner_procedure) (long arg0);
double call_GET_INIT_VT ( long arg0 );
#ifdef CSCHEME_HEAD
extern element * GET_INIT_VT ;
#endif
extern double (* GET_INIT_V0_x_inner_procedure) (long arg0, double arg1, double arg2, double arg3);
double call_GET_INIT_V0_x ( long arg0, double arg1, double arg2, double arg3 );
#ifdef CSCHEME_HEAD
extern element * GET_INIT_V0_x ;
#endif
extern double (* GET_INIT_V0_y_inner_procedure) (long arg0, double arg1, double arg2, double arg3);
double call_GET_INIT_V0_y ( long arg0, double arg1, double arg2, double arg3 );
#ifdef CSCHEME_HEAD
extern element * GET_INIT_V0_y ;
#endif
extern double (* GET_INIT_V0_z_inner_procedure) (long arg0, double arg1, double arg2, double arg3);
double call_GET_INIT_V0_z ( long arg0, double arg1, double arg2, double arg3 );
#ifdef CSCHEME_HEAD
extern element * GET_INIT_V0_z ;
#endif
extern double (* GET_INIT_FILTER_E_inner_procedure) (double arg0, double arg1, double arg2, long arg3);
double call_GET_INIT_FILTER_E ( double arg0, double arg1, double arg2, long arg3 );
#ifdef CSCHEME_HEAD
extern element * GET_INIT_FILTER_E ;
#endif
extern double (* GET_INIT_FILTER_KROOK_inner_procedure) (double arg0, double arg1, double arg2, long arg3);
double call_GET_INIT_FILTER_KROOK ( double arg0, double arg1, double arg2, long arg3 );
#ifdef CSCHEME_HEAD
extern element * GET_INIT_FILTER_KROOK ;
#endif
extern double (* GET_INIT_FILTER_B_inner_procedure) (double arg0, double arg1, double arg2, long arg3);
double call_GET_INIT_FILTER_B ( double arg0, double arg1, double arg2, long arg3 );
#ifdef CSCHEME_HEAD
extern element * GET_INIT_FILTER_B ;
#endif
extern double (* GET_VAR_inner_procedure) (char* arg0);
double call_GET_VAR ( char* arg0 );
#ifdef CSCHEME_HEAD
extern element * GET_VAR ;
#endif
