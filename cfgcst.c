//This file is generated from cfgcst.sc
#include <stdio.h>
#include <stdlib.h>
#include <uthash.h>
#include <string.h>
#include <cscheme.h>
 long XMAX ;
 long YMAX ;
 long ZMAX ;
 long NUM_PROCESS ;
 long NUM_RUNTIME ;
 long NUM_MAX_RUNTIME ;
 long NUM_N_HILBERT ;
 long NUM_N_HILBERT_DIMENSION ;
 int HILBERT_DIR ;
 long NUM_TIMESTEP ;
 double DELTAT ;
 long NUM_DUMP_TIMESTEP ;
 long NUM_SPEC ;
 long USE_NP_BOUNDARY ;
 long USE_NON_UNI_DENSITY ;
 long USE_NON_UNI_TEMPERATURE ;
 long USE_INIT_EXT_EB ;
 long USE_INIT_EB0 ;
 long USE_FILTER ;
 int USE_CHECKPOINT ;
 int USE_INIT_V0 ;
 int USE_KGM ;
 double (* CAL_FUN_ONE_PARA_inner_procedure) (char* arg0, double arg1);
double call_CAL_FUN_ONE_PARA ( char* arg0, double arg1 );
#ifdef CSCHEME_HEAD
 element * CAL_FUN_ONE_PARA ;
#endif
 int USE_TORI ;
 int USE_PROFILE ;
 int USE_DM ;
 int USE_LHCD_INPUT ;
 long NUM_CHECKPOINT_TIMESTEP ;
 long USE_NON_UNI_CACHE_DIST ;
 long (* GET_DEV_TYPE_inner_procedure) (long arg0, long arg1);
long call_GET_DEV_TYPE ( long arg0, long arg1 );
#ifdef CSCHEME_HEAD
 element * GET_DEV_TYPE ;
#endif
 long (* GET_DEV_ID_inner_procedure) (long arg0, long arg1);
long call_GET_DEV_ID ( long arg0, long arg1 );
#ifdef CSCHEME_HEAD
 element * GET_DEV_ID ;
#endif
 long (* GET_NUM_LOCAL_THREAD_FROM_GLOBAL_TID_inner_procedure) (long arg0);
long call_GET_NUM_LOCAL_THREAD_FROM_GLOBAL_TID ( long arg0 );
#ifdef CSCHEME_HEAD
 element * GET_NUM_LOCAL_THREAD_FROM_GLOBAL_TID ;
#endif
 double (* GET_MASS_inner_procedure) (long arg0);
double call_GET_MASS ( long arg0 );
#ifdef CSCHEME_HEAD
 element * GET_MASS ;
#endif
 double (* GET_NPM_inner_procedure) (long arg0);
double call_GET_NPM ( long arg0 );
#ifdef CSCHEME_HEAD
 element * GET_NPM ;
#endif
 double (* GET_CHARGE_inner_procedure) (long arg0);
double call_GET_CHARGE ( long arg0 );
#ifdef CSCHEME_HEAD
 element * GET_CHARGE ;
#endif
 long (* GET_GRID_CACHE_LEN_inner_procedure) (long arg0);
long call_GET_GRID_CACHE_LEN ( long arg0 );
#ifdef CSCHEME_HEAD
 element * GET_GRID_CACHE_LEN ;
#endif
 long (* GET_CU_CACHE_LEN_inner_procedure) (long arg0);
long call_GET_CU_CACHE_LEN ( long arg0 );
#ifdef CSCHEME_HEAD
 element * GET_CU_CACHE_LEN ;
#endif
 long (* GET_INIT_LOAD_inner_procedure) (long arg0);
long call_GET_INIT_LOAD ( long arg0 );
#ifdef CSCHEME_HEAD
 element * GET_INIT_LOAD ;
#endif
 double (* GET_NON_UNI_CACHE_DIST_inner_procedure) (long arg0, long arg1);
double call_GET_NON_UNI_CACHE_DIST ( long arg0, long arg1 );
#ifdef CSCHEME_HEAD
 element * GET_NON_UNI_CACHE_DIST ;
#endif
 double (* GET_INIT_DENSITY_DIST_inner_procedure) (long arg0, double arg1, double arg2, double arg3);
double call_GET_INIT_DENSITY_DIST ( long arg0, double arg1, double arg2, double arg3 );
#ifdef CSCHEME_HEAD
 element * GET_INIT_DENSITY_DIST ;
#endif
 double (* GET_INIT_TEMPERATURE_DIST_inner_procedure) (long arg0, double arg1, double arg2, double arg3, long arg4);
double call_GET_INIT_TEMPERATURE_DIST ( long arg0, double arg1, double arg2, double arg3, long arg4 );
#ifdef CSCHEME_HEAD
 element * GET_INIT_TEMPERATURE_DIST ;
#endif
 double (* GET_INIT_E_inner_procedure) (double arg0, double arg1, double arg2, long arg3);
double call_GET_INIT_E ( double arg0, double arg1, double arg2, long arg3 );
#ifdef CSCHEME_HEAD
 element * GET_INIT_E ;
#endif
 double (* GET_INIT_B_inner_procedure) (double arg0, double arg1, double arg2, long arg3);
double call_GET_INIT_B ( double arg0, double arg1, double arg2, long arg3 );
#ifdef CSCHEME_HEAD
 element * GET_INIT_B ;
#endif
 double (* GET_INIT_E0_inner_procedure) (double arg0, double arg1, double arg2, long arg3);
double call_GET_INIT_E0 ( double arg0, double arg1, double arg2, long arg3 );
#ifdef CSCHEME_HEAD
 element * GET_INIT_E0 ;
#endif
 double (* GET_INIT_B0_inner_procedure) (double arg0, double arg1, double arg2, long arg3);
double call_GET_INIT_B0 ( double arg0, double arg1, double arg2, long arg3 );
#ifdef CSCHEME_HEAD
 element * GET_INIT_B0 ;
#endif
 double (* GET_INIT_VT_inner_procedure) (long arg0);
double call_GET_INIT_VT ( long arg0 );
#ifdef CSCHEME_HEAD
 element * GET_INIT_VT ;
#endif
 double (* GET_INIT_V0_x_inner_procedure) (long arg0, double arg1, double arg2, double arg3);
double call_GET_INIT_V0_x ( long arg0, double arg1, double arg2, double arg3 );
#ifdef CSCHEME_HEAD
 element * GET_INIT_V0_x ;
#endif
 double (* GET_INIT_V0_y_inner_procedure) (long arg0, double arg1, double arg2, double arg3);
double call_GET_INIT_V0_y ( long arg0, double arg1, double arg2, double arg3 );
#ifdef CSCHEME_HEAD
 element * GET_INIT_V0_y ;
#endif
 double (* GET_INIT_V0_z_inner_procedure) (long arg0, double arg1, double arg2, double arg3);
double call_GET_INIT_V0_z ( long arg0, double arg1, double arg2, double arg3 );
#ifdef CSCHEME_HEAD
 element * GET_INIT_V0_z ;
#endif
 double (* GET_INIT_FILTER_E_inner_procedure) (double arg0, double arg1, double arg2, long arg3);
double call_GET_INIT_FILTER_E ( double arg0, double arg1, double arg2, long arg3 );
#ifdef CSCHEME_HEAD
 element * GET_INIT_FILTER_E ;
#endif
 double (* GET_INIT_FILTER_KROOK_inner_procedure) (double arg0, double arg1, double arg2, long arg3);
double call_GET_INIT_FILTER_KROOK ( double arg0, double arg1, double arg2, long arg3 );
#ifdef CSCHEME_HEAD
 element * GET_INIT_FILTER_KROOK ;
#endif
 double (* GET_INIT_FILTER_B_inner_procedure) (double arg0, double arg1, double arg2, long arg3);
double call_GET_INIT_FILTER_B ( double arg0, double arg1, double arg2, long arg3 );
#ifdef CSCHEME_HEAD
 element * GET_INIT_FILTER_B ;
#endif
 double (* GET_VAR_inner_procedure) (char* arg0);
double call_GET_VAR ( char* arg0 );
#ifdef CSCHEME_HEAD
 element * GET_VAR ;
#endif
extern element * global_environment;
extern element * quote_symbol;
extern element * empty_list_process;
element * makesymbol (char *);
element * find_var_in_env (element *, element * ,int);
element * cons(element * a,element * b);
element * makechar(char c);
element * makestring(char * str);
element * makeint(long i);
element * makefloat(double i);
element * eval(element * input,element * env);
element * external_apply( element * proc, element * args){
	element * final_arg = cons( cons (quote_symbol, cons (proc,empty_list_process)) , args);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	return ret;
}


int get_constants (){
 {
   element * tmpele = find_var_in_env (makesymbol ("XMAX") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  XMAX = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  XMAX = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  XMAX = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"XMAX Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("YMAX") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  YMAX = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  YMAX = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  YMAX = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"YMAX Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("ZMAX") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  ZMAX = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  ZMAX = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  ZMAX = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"ZMAX Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("NUM_PROCESS") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  NUM_PROCESS = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  NUM_PROCESS = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  NUM_PROCESS = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"NUM_PROCESS Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("NUM_RUNTIME") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  NUM_RUNTIME = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  NUM_RUNTIME = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  NUM_RUNTIME = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"NUM_RUNTIME Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("NUM_MAX_RUNTIME") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  NUM_MAX_RUNTIME = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  NUM_MAX_RUNTIME = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  NUM_MAX_RUNTIME = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"NUM_MAX_RUNTIME Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("NUM_N_HILBERT") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  NUM_N_HILBERT = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  NUM_N_HILBERT = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  NUM_N_HILBERT = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"NUM_N_HILBERT Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("NUM_N_HILBERT_DIMENSION") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  NUM_N_HILBERT_DIMENSION = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  NUM_N_HILBERT_DIMENSION = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  NUM_N_HILBERT_DIMENSION = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"NUM_N_HILBERT_DIMENSION Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("HILBERT_DIR") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  HILBERT_DIR = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  HILBERT_DIR = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  HILBERT_DIR = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"HILBERT_DIR Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("NUM_TIMESTEP") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  NUM_TIMESTEP = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  NUM_TIMESTEP = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  NUM_TIMESTEP = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"NUM_TIMESTEP Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("DELTAT") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  DELTAT = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  DELTAT = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  DELTAT = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"DELTAT Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("NUM_DUMP_TIMESTEP") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  NUM_DUMP_TIMESTEP = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  NUM_DUMP_TIMESTEP = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  NUM_DUMP_TIMESTEP = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"NUM_DUMP_TIMESTEP Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("NUM_SPEC") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  NUM_SPEC = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  NUM_SPEC = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  NUM_SPEC = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"NUM_SPEC Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("USE_NP_BOUNDARY") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  USE_NP_BOUNDARY = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  USE_NP_BOUNDARY = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  USE_NP_BOUNDARY = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"USE_NP_BOUNDARY Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("USE_NON_UNI_DENSITY") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  USE_NON_UNI_DENSITY = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  USE_NON_UNI_DENSITY = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  USE_NON_UNI_DENSITY = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"USE_NON_UNI_DENSITY Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("USE_NON_UNI_TEMPERATURE") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  USE_NON_UNI_TEMPERATURE = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  USE_NON_UNI_TEMPERATURE = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  USE_NON_UNI_TEMPERATURE = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"USE_NON_UNI_TEMPERATURE Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("USE_INIT_EXT_EB") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  USE_INIT_EXT_EB = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  USE_INIT_EXT_EB = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  USE_INIT_EXT_EB = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"USE_INIT_EXT_EB Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("USE_INIT_EB0") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  USE_INIT_EB0 = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  USE_INIT_EB0 = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  USE_INIT_EB0 = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"USE_INIT_EB0 Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("USE_FILTER") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  USE_FILTER = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  USE_FILTER = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  USE_FILTER = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"USE_FILTER Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("USE_CHECKPOINT") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  USE_CHECKPOINT = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  USE_CHECKPOINT = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  USE_CHECKPOINT = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"USE_CHECKPOINT Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("USE_INIT_V0") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  USE_INIT_V0 = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  USE_INIT_V0 = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  USE_INIT_V0 = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"USE_INIT_V0 Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("USE_KGM") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  USE_KGM = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  USE_KGM = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  USE_KGM = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"USE_KGM Type Error: %d" ,tmpele -> type );
 }

 }
{
	CAL_FUN_ONE_PARA_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("CAL_FUN_ONE_PARA") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  CAL_FUN_ONE_PARA = tmpele;
  } else {
    fprintf (stderr,"CAL_FUN_ONE_PARA Type Error: %d" ,tmpele -> type );
}

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("USE_TORI") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  USE_TORI = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  USE_TORI = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  USE_TORI = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"USE_TORI Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("USE_PROFILE") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  USE_PROFILE = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  USE_PROFILE = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  USE_PROFILE = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"USE_PROFILE Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("USE_DM") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  USE_DM = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  USE_DM = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  USE_DM = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"USE_DM Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("USE_LHCD_INPUT") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  USE_LHCD_INPUT = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  USE_LHCD_INPUT = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  USE_LHCD_INPUT = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"USE_LHCD_INPUT Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("NUM_CHECKPOINT_TIMESTEP") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  NUM_CHECKPOINT_TIMESTEP = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  NUM_CHECKPOINT_TIMESTEP = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  NUM_CHECKPOINT_TIMESTEP = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"NUM_CHECKPOINT_TIMESTEP Type Error: %d" ,tmpele -> type );
 }

 }
 {
   element * tmpele = find_var_in_env (makesymbol ("USE_NON_UNI_CACHE_DIST") , global_environment , 0);
    if ( tmpele -> type== INTNUM) {
  USE_NON_UNI_CACHE_DIST = tmpele->data.intnum;
 }else if ( tmpele -> type == FLOATNUM ) {
  USE_NON_UNI_CACHE_DIST = tmpele->data.floatnum;
 }else if ( tmpele -> type == CHAR ){
  USE_NON_UNI_CACHE_DIST = tmpele->data.char_var;
 }  else {
    fprintf (stderr,"USE_NON_UNI_CACHE_DIST Type Error: %d" ,tmpele -> type );
 }

 }
{
	GET_DEV_TYPE_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_DEV_TYPE") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_DEV_TYPE = tmpele;
  } else {
    fprintf (stderr,"GET_DEV_TYPE Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_DEV_ID_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_DEV_ID") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_DEV_ID = tmpele;
  } else {
    fprintf (stderr,"GET_DEV_ID Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_NUM_LOCAL_THREAD_FROM_GLOBAL_TID_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_NUM_LOCAL_THREAD_FROM_GLOBAL_TID") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_NUM_LOCAL_THREAD_FROM_GLOBAL_TID = tmpele;
  } else {
    fprintf (stderr,"GET_NUM_LOCAL_THREAD_FROM_GLOBAL_TID Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_MASS_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_MASS") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_MASS = tmpele;
  } else {
    fprintf (stderr,"GET_MASS Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_NPM_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_NPM") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_NPM = tmpele;
  } else {
    fprintf (stderr,"GET_NPM Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_CHARGE_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_CHARGE") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_CHARGE = tmpele;
  } else {
    fprintf (stderr,"GET_CHARGE Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_GRID_CACHE_LEN_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_GRID_CACHE_LEN") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_GRID_CACHE_LEN = tmpele;
  } else {
    fprintf (stderr,"GET_GRID_CACHE_LEN Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_CU_CACHE_LEN_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_CU_CACHE_LEN") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_CU_CACHE_LEN = tmpele;
  } else {
    fprintf (stderr,"GET_CU_CACHE_LEN Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_INIT_LOAD_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_INIT_LOAD") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_INIT_LOAD = tmpele;
  } else {
    fprintf (stderr,"GET_INIT_LOAD Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_NON_UNI_CACHE_DIST_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_NON_UNI_CACHE_DIST") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_NON_UNI_CACHE_DIST = tmpele;
  } else {
    fprintf (stderr,"GET_NON_UNI_CACHE_DIST Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_INIT_DENSITY_DIST_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_INIT_DENSITY_DIST") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_INIT_DENSITY_DIST = tmpele;
  } else {
    fprintf (stderr,"GET_INIT_DENSITY_DIST Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_INIT_TEMPERATURE_DIST_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_INIT_TEMPERATURE_DIST") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_INIT_TEMPERATURE_DIST = tmpele;
  } else {
    fprintf (stderr,"GET_INIT_TEMPERATURE_DIST Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_INIT_E_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_INIT_E") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_INIT_E = tmpele;
  } else {
    fprintf (stderr,"GET_INIT_E Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_INIT_B_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_INIT_B") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_INIT_B = tmpele;
  } else {
    fprintf (stderr,"GET_INIT_B Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_INIT_E0_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_INIT_E0") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_INIT_E0 = tmpele;
  } else {
    fprintf (stderr,"GET_INIT_E0 Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_INIT_B0_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_INIT_B0") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_INIT_B0 = tmpele;
  } else {
    fprintf (stderr,"GET_INIT_B0 Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_INIT_VT_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_INIT_VT") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_INIT_VT = tmpele;
  } else {
    fprintf (stderr,"GET_INIT_VT Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_INIT_V0_x_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_INIT_V0_x") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_INIT_V0_x = tmpele;
  } else {
    fprintf (stderr,"GET_INIT_V0_x Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_INIT_V0_y_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_INIT_V0_y") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_INIT_V0_y = tmpele;
  } else {
    fprintf (stderr,"GET_INIT_V0_y Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_INIT_V0_z_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_INIT_V0_z") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_INIT_V0_z = tmpele;
  } else {
    fprintf (stderr,"GET_INIT_V0_z Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_INIT_FILTER_E_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_INIT_FILTER_E") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_INIT_FILTER_E = tmpele;
  } else {
    fprintf (stderr,"GET_INIT_FILTER_E Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_INIT_FILTER_KROOK_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_INIT_FILTER_KROOK") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_INIT_FILTER_KROOK = tmpele;
  } else {
    fprintf (stderr,"GET_INIT_FILTER_KROOK Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_INIT_FILTER_B_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_INIT_FILTER_B") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_INIT_FILTER_B = tmpele;
  } else {
    fprintf (stderr,"GET_INIT_FILTER_B Type Error: %d" ,tmpele -> type );
}

 }
{
	GET_VAR_inner_procedure = NULL;
}
 {
   element * tmpele = find_var_in_env (makesymbol ("GET_VAR") , global_environment , 0);
     if ( tmpele -> type == LAMBDA_PROC ) {
  GET_VAR = tmpele;
  } else {
    fprintf (stderr,"GET_VAR Type Error: %d" ,tmpele -> type );
}

 }
	return 0;
}
double call_CAL_FUN_ONE_PARA ( char* arg0, double arg1) {
	if (CAL_FUN_ONE_PARA_inner_procedure) 
	{
		return CAL_FUN_ONE_PARA_inner_procedure (arg0,  arg1);
	}
	
	element * arglst= cons( makestring(arg0) , cons( makefloat(arg1) , empty_list_process)) ;
	element * fun_var = find_var_in_env (makesymbol ("CAL_FUN_ONE_PARA"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	double ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
long call_GET_DEV_TYPE ( long arg0, long arg1) {
	if (GET_DEV_TYPE_inner_procedure) 
	{
		return GET_DEV_TYPE_inner_procedure (arg0,  arg1);
	}
	
	element * arglst= cons( makeint(arg0) , cons( makeint(arg1) , empty_list_process)) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_DEV_TYPE"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	long ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
long call_GET_DEV_ID ( long arg0, long arg1) {
	if (GET_DEV_ID_inner_procedure) 
	{
		return GET_DEV_ID_inner_procedure (arg0,  arg1);
	}
	
	element * arglst= cons( makeint(arg0) , cons( makeint(arg1) , empty_list_process)) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_DEV_ID"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	long ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
long call_GET_NUM_LOCAL_THREAD_FROM_GLOBAL_TID ( long arg0) {
	if (GET_NUM_LOCAL_THREAD_FROM_GLOBAL_TID_inner_procedure) 
	{
		return GET_NUM_LOCAL_THREAD_FROM_GLOBAL_TID_inner_procedure ( arg0);
	}
	
	element * arglst= cons( makeint(arg0) , empty_list_process) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_NUM_LOCAL_THREAD_FROM_GLOBAL_TID"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	long ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
double call_GET_MASS ( long arg0) {
	if (GET_MASS_inner_procedure) 
	{
		return GET_MASS_inner_procedure ( arg0);
	}
	
	element * arglst= cons( makeint(arg0) , empty_list_process) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_MASS"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	double ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
double call_GET_NPM ( long arg0) {
	if (GET_NPM_inner_procedure) 
	{
		return GET_NPM_inner_procedure ( arg0);
	}
	
	element * arglst= cons( makeint(arg0) , empty_list_process) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_NPM"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	double ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
double call_GET_CHARGE ( long arg0) {
	if (GET_CHARGE_inner_procedure) 
	{
		return GET_CHARGE_inner_procedure ( arg0);
	}
	
	element * arglst= cons( makeint(arg0) , empty_list_process) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_CHARGE"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	double ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
long call_GET_GRID_CACHE_LEN ( long arg0) {
	if (GET_GRID_CACHE_LEN_inner_procedure) 
	{
		return GET_GRID_CACHE_LEN_inner_procedure ( arg0);
	}
	
	element * arglst= cons( makeint(arg0) , empty_list_process) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_GRID_CACHE_LEN"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	long ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
long call_GET_CU_CACHE_LEN ( long arg0) {
	if (GET_CU_CACHE_LEN_inner_procedure) 
	{
		return GET_CU_CACHE_LEN_inner_procedure ( arg0);
	}
	
	element * arglst= cons( makeint(arg0) , empty_list_process) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_CU_CACHE_LEN"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	long ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
long call_GET_INIT_LOAD ( long arg0) {
	if (GET_INIT_LOAD_inner_procedure) 
	{
		return GET_INIT_LOAD_inner_procedure ( arg0);
	}
	
	element * arglst= cons( makeint(arg0) , empty_list_process) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_INIT_LOAD"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	long ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
double call_GET_NON_UNI_CACHE_DIST ( long arg0, long arg1) {
	if (GET_NON_UNI_CACHE_DIST_inner_procedure) 
	{
		return GET_NON_UNI_CACHE_DIST_inner_procedure (arg0,  arg1);
	}
	
	element * arglst= cons( makeint(arg0) , cons( makeint(arg1) , empty_list_process)) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_NON_UNI_CACHE_DIST"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	double ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
double call_GET_INIT_DENSITY_DIST ( long arg0, double arg1, double arg2, double arg3) {
	if (GET_INIT_DENSITY_DIST_inner_procedure) 
	{
		return GET_INIT_DENSITY_DIST_inner_procedure (arg0, arg1, arg2,  arg3);
	}
	
	element * arglst= cons( makeint(arg0) , cons( makefloat(arg1) , cons( makefloat(arg2) , cons( makefloat(arg3) , empty_list_process)))) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_INIT_DENSITY_DIST"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	double ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
double call_GET_INIT_TEMPERATURE_DIST ( long arg0, double arg1, double arg2, double arg3, long arg4) {
	if (GET_INIT_TEMPERATURE_DIST_inner_procedure) 
	{
		return GET_INIT_TEMPERATURE_DIST_inner_procedure (arg0, arg1, arg2, arg3,  arg4);
	}
	
	element * arglst= cons( makeint(arg0) , cons( makefloat(arg1) , cons( makefloat(arg2) , cons( makefloat(arg3) , cons( makeint(arg4) , empty_list_process))))) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_INIT_TEMPERATURE_DIST"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	double ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
double call_GET_INIT_E ( double arg0, double arg1, double arg2, long arg3) {
	if (GET_INIT_E_inner_procedure) 
	{
		return GET_INIT_E_inner_procedure (arg0, arg1, arg2,  arg3);
	}
	
	element * arglst= cons( makefloat(arg0) , cons( makefloat(arg1) , cons( makefloat(arg2) , cons( makeint(arg3) , empty_list_process)))) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_INIT_E"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	double ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
double call_GET_INIT_B ( double arg0, double arg1, double arg2, long arg3) {
	if (GET_INIT_B_inner_procedure) 
	{
		return GET_INIT_B_inner_procedure (arg0, arg1, arg2,  arg3);
	}
	
	element * arglst= cons( makefloat(arg0) , cons( makefloat(arg1) , cons( makefloat(arg2) , cons( makeint(arg3) , empty_list_process)))) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_INIT_B"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	double ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
double call_GET_INIT_E0 ( double arg0, double arg1, double arg2, long arg3) {
	if (GET_INIT_E0_inner_procedure) 
	{
		return GET_INIT_E0_inner_procedure (arg0, arg1, arg2,  arg3);
	}
	
	element * arglst= cons( makefloat(arg0) , cons( makefloat(arg1) , cons( makefloat(arg2) , cons( makeint(arg3) , empty_list_process)))) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_INIT_E0"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	double ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
double call_GET_INIT_B0 ( double arg0, double arg1, double arg2, long arg3) {
	if (GET_INIT_B0_inner_procedure) 
	{
		return GET_INIT_B0_inner_procedure (arg0, arg1, arg2,  arg3);
	}
	
	element * arglst= cons( makefloat(arg0) , cons( makefloat(arg1) , cons( makefloat(arg2) , cons( makeint(arg3) , empty_list_process)))) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_INIT_B0"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	double ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
double call_GET_INIT_VT ( long arg0) {
	if (GET_INIT_VT_inner_procedure) 
	{
		return GET_INIT_VT_inner_procedure ( arg0);
	}
	
	element * arglst= cons( makeint(arg0) , empty_list_process) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_INIT_VT"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	double ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
double call_GET_INIT_V0_x ( long arg0, double arg1, double arg2, double arg3) {
	if (GET_INIT_V0_x_inner_procedure) 
	{
		return GET_INIT_V0_x_inner_procedure (arg0, arg1, arg2,  arg3);
	}
	
	element * arglst= cons( makeint(arg0) , cons( makefloat(arg1) , cons( makefloat(arg2) , cons( makefloat(arg3) , empty_list_process)))) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_INIT_V0_x"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	double ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
double call_GET_INIT_V0_y ( long arg0, double arg1, double arg2, double arg3) {
	if (GET_INIT_V0_y_inner_procedure) 
	{
		return GET_INIT_V0_y_inner_procedure (arg0, arg1, arg2,  arg3);
	}
	
	element * arglst= cons( makeint(arg0) , cons( makefloat(arg1) , cons( makefloat(arg2) , cons( makefloat(arg3) , empty_list_process)))) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_INIT_V0_y"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	double ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
double call_GET_INIT_V0_z ( long arg0, double arg1, double arg2, double arg3) {
	if (GET_INIT_V0_z_inner_procedure) 
	{
		return GET_INIT_V0_z_inner_procedure (arg0, arg1, arg2,  arg3);
	}
	
	element * arglst= cons( makeint(arg0) , cons( makefloat(arg1) , cons( makefloat(arg2) , cons( makefloat(arg3) , empty_list_process)))) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_INIT_V0_z"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	double ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
double call_GET_INIT_FILTER_E ( double arg0, double arg1, double arg2, long arg3) {
	if (GET_INIT_FILTER_E_inner_procedure) 
	{
		return GET_INIT_FILTER_E_inner_procedure (arg0, arg1, arg2,  arg3);
	}
	
	element * arglst= cons( makefloat(arg0) , cons( makefloat(arg1) , cons( makefloat(arg2) , cons( makeint(arg3) , empty_list_process)))) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_INIT_FILTER_E"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	double ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
double call_GET_INIT_FILTER_KROOK ( double arg0, double arg1, double arg2, long arg3) {
	if (GET_INIT_FILTER_KROOK_inner_procedure) 
	{
		return GET_INIT_FILTER_KROOK_inner_procedure (arg0, arg1, arg2,  arg3);
	}
	
	element * arglst= cons( makefloat(arg0) , cons( makefloat(arg1) , cons( makefloat(arg2) , cons( makeint(arg3) , empty_list_process)))) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_INIT_FILTER_KROOK"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	double ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
double call_GET_INIT_FILTER_B ( double arg0, double arg1, double arg2, long arg3) {
	if (GET_INIT_FILTER_B_inner_procedure) 
	{
		return GET_INIT_FILTER_B_inner_procedure (arg0, arg1, arg2,  arg3);
	}
	
	element * arglst= cons( makefloat(arg0) , cons( makefloat(arg1) , cons( makefloat(arg2) , cons( makeint(arg3) , empty_list_process)))) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_INIT_FILTER_B"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	double ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
double call_GET_VAR ( char* arg0) {
	if (GET_VAR_inner_procedure) 
	{
		return GET_VAR_inner_procedure ( arg0);
	}
	
	element * arglst= cons( makestring(arg0) , empty_list_process) ;
	element * fun_var = find_var_in_env (makesymbol ("GET_VAR"), global_environment, 0);
	element * final_arg = cons (cons (quote_symbol, cons (fun_var, empty_list_process)), arglst);
	push_gc_stack (& final_arg);
	element * ret=eval(final_arg, global_environment);
	pop_gc_stack();
	double ans ;
	 if ( ret -> type== INTNUM) {
  ans = ret->data.intnum;
 }else if ( ret -> type == FLOATNUM ) {
  ans = ret->data.floatnum;
 }else if ( ret -> type == CHAR ){
  ans = ret->data.char_var;
 }  else {
    fprintf (stderr,"ans Type Error: %d" ,ret -> type );
 }

	return ans;
}
