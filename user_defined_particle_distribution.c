#include <math.h>
#include <stdio.h>
#include "genrand.h"
void  user_defined_particle_distribution (double *  xyzvs ,long  xyzx ,long  xyzy ,long  xyzz ,int  cur_sp ,long  l ,long  grid_load ,long  external_para ){
	double  L = 33 ;
	double  NPG = grid_load ;
	double  omgp = 1.90399554763017786e-01 ;
	double  A = 1.00000000000000002e-02 ;
	double  M = 9 ;
	double  vdrift = 1.00000000000000002e-02 ;
	double  x_p0 = 	(  	(  l / NPG ) + xyzx ) ;
	if (  	(  cur_sp == 0 )  ){  
		((xyzvs)[0] = 	(  	(  x_p0 - 	floor ( x_p0 ) ) + 	(  	(  A * 	(  L * 	cos ( 	(  	(  2 * 	(  M_PI * 	(  M * x_p0 ) ) ) / L ) ) ) ) / 	(  2 * 	(  M_PI * M ) ) ) ));

	}else{
		((xyzvs)[0] = 	(  x_p0 - 	floor ( x_p0 ) ));

	 }
((xyzvs)[1] = 5.00000000000000000e-01);
((xyzvs)[2] = 5.00000000000000000e-01);
	if (  	(  cur_sp == 0 )  ){  
		((xyzvs)[3] = 	(  vdrift + 	(  	(  A * 	(  L * 	(  omgp * 	sin ( 	(  	(  2 * 	(  M_PI * 	(  M * 	(  xyzx + (xyzvs)[0] ) ) ) ) / L ) ) ) ) ) / 	(  2 * 	(  M_PI * M ) ) ) ));

	}else{
		((xyzvs)[3] = 0);

	 }
((xyzvs)[4] = 0);
((xyzvs)[5] = 0);
}
