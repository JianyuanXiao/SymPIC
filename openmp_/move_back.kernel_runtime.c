#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "openmp_pscmc_inc.h"
#include "move_back.kernel_inc.h"
int  openmp_move_back_kernel_init (openmp_pscmc_env *  pe ,openmp_move_back_kernel_struct *  kerstr ){
	return  0 ;}
void  openmp_move_back_kernel_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_move_back_kernel_struct ));
}
int  openmp_move_back_kernel_get_xlen (){
	return  IDX_OPT_MAX ;}
int  openmp_move_back_kernel_exec (openmp_move_back_kernel_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

#pragma omp parallel
{
	int  xid ;
	int  yid ;
	int  numt = 	omp_get_num_threads (  ) ;
	int  tid = 	omp_get_thread_num (  ) ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = tid) ; 	(  yid < scmc_internal_g_ylen ) ; (yid = 	(  yid + numt )))
	{
	for ((xid = 0) ; 	(  xid < scmc_internal_g_xlen ) ; (xid = 	(  xid + 1 )))
	{
	openmp_move_back_kernel_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , yid , scmc_internal_g_ylen );
}}}	return  0 ;}
int  openmp_move_back_kernel_scmc_set_parameter_inoutput (openmp_move_back_kernel_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  openmp_move_back_kernel_scmc_set_parameter_xyzw (openmp_move_back_kernel_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  openmp_move_back_kernel_scmc_set_parameter_cu_cache (openmp_move_back_kernel_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  openmp_move_back_kernel_scmc_set_parameter_cu_xyzw (openmp_move_back_kernel_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  openmp_move_back_kernel_scmc_set_parameter_XLEN (openmp_move_back_kernel_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  openmp_move_back_kernel_scmc_set_parameter_YLEN (openmp_move_back_kernel_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  openmp_move_back_kernel_scmc_set_parameter_ZLEN (openmp_move_back_kernel_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  openmp_move_back_kernel_scmc_set_parameter_grid_cache_len (openmp_move_back_kernel_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  openmp_move_back_kernel_scmc_set_parameter_cu_cache_length (openmp_move_back_kernel_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
