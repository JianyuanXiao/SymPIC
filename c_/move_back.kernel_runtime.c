#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "c_pscmc_inc.h"
#include "move_back.kernel_inc.h"
int  c_move_back_kernel_init (c_pscmc_env *  pe ,c_move_back_kernel_struct *  kerstr ){
	return  0 ;}
void  c_move_back_kernel_get_struct_len (size_t *  len ){
((len)[0] = sizeof(c_move_back_kernel_struct ));
}
int  c_move_back_kernel_get_xlen (){
	return  IDX_OPT_MAX ;}
int  c_move_back_kernel_get_num_compute_units (c_move_back_kernel_struct *  kerstr ){
	return  1 ;}
int  c_move_back_kernel_exec (c_move_back_kernel_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){
{
	int  yid ;
	int  numt = 1 ;
	int  tid = 0 ;
	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 ) ) / numt ) ;
	int  ymin = 	(  tid * ysingle ) ;
	int  ymax = 	(  	(  1 + tid ) * ysingle ) ;
	for ((yid = ymin) ; 	(  	(  yid < ymax ) && 	(  yid < scmc_internal_g_ylen ) ) ; (yid = 	(  yid + 1 )))
	{
	c_move_back_kernel_scmc_kernel ( 	( kerstr )->inoutput , 	( kerstr )->xyzw , 	( kerstr )->cu_cache , 	( kerstr )->cu_xyzw , (	( kerstr )->XLEN)[0] , (	( kerstr )->YLEN)[0] , (	( kerstr )->ZLEN)[0] , (	( kerstr )->grid_cache_len)[0] , (	( kerstr )->cu_cache_length)[0] , yid , scmc_internal_g_ylen );
}}	return  0 ;}
int  c_move_back_kernel_scmc_set_parameter_inoutput (c_move_back_kernel_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->inoutput = pm->d_data);
}
int  c_move_back_kernel_scmc_set_parameter_xyzw (c_move_back_kernel_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->xyzw = pm->d_data);
}
int  c_move_back_kernel_scmc_set_parameter_cu_cache (c_move_back_kernel_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache = pm->d_data);
}
int  c_move_back_kernel_scmc_set_parameter_cu_xyzw (c_move_back_kernel_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw = pm->d_data);
}
int  c_move_back_kernel_scmc_set_parameter_XLEN (c_move_back_kernel_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->XLEN = pm->d_data);
}
int  c_move_back_kernel_scmc_set_parameter_YLEN (c_move_back_kernel_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->YLEN = pm->d_data);
}
int  c_move_back_kernel_scmc_set_parameter_ZLEN (c_move_back_kernel_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->ZLEN = pm->d_data);
}
int  c_move_back_kernel_scmc_set_parameter_grid_cache_len (c_move_back_kernel_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len = pm->d_data);
}
int  c_move_back_kernel_scmc_set_parameter_cu_cache_length (c_move_back_kernel_struct *  kerstr ,c_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length = pm->d_data);
}
