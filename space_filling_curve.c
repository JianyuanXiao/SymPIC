#include <stdio.h>
	static size_t  cid ;
int  hilbert_curve_3d_core (long *  modifiedid ,long *  ori_id ,long  xlen ,long  ylen ,long  s ,long  x ,long  y ,long  z ,long  dx ,long  dy ,long  dz ,long  dx2 ,long  dy2 ,long  dz2 ,long  dx3 ,long  dy3 ,long  dz3 ){
	if (  	(  s == 1 )  ){  
			long  rid = 	(  x + 	(  xlen * 	(  y + 	(  ylen * z ) ) ) ) ;
((modifiedid)[rid] = cid);
((ori_id)[cid] = rid);
(cid = 	(  cid + 1 ));

	}else{
		(s = 	(  s / 2 ));
	if (  	(  dx < 0 )  ){  
		(x = 	(  x - 	(  s * dx ) ));

	}else{
		0;

	 }
	if (  	(  dy < 0 )  ){  
		(y = 	(  y - 	(  s * dy ) ));

	}else{
		0;

	 }
	if (  	(  dz < 0 )  ){  
		(z = 	(  z - 	(  s * dz ) ));

	}else{
		0;

	 }
	if (  	(  dx2 < 0 )  ){  
		(x = 	(  x - 	(  s * dx2 ) ));

	}else{
		0;

	 }
	if (  	(  dy2 < 0 )  ){  
		(y = 	(  y - 	(  s * dy2 ) ));

	}else{
		0;

	 }
	if (  	(  dz2 < 0 )  ){  
		(z = 	(  z - 	(  s * dz2 ) ));

	}else{
		0;

	 }
	if (  	(  dx3 < 0 )  ){  
		(x = 	(  x - 	(  s * dx3 ) ));

	}else{
		0;

	 }
	if (  	(  dy3 < 0 )  ){  
		(y = 	(  y - 	(  s * dy3 ) ));

	}else{
		0;

	 }
	if (  	(  dz3 < 0 )  ){  
		(z = 	(  z - 	(  s * dz3 ) ));

	}else{
		0;

	 }
	hilbert_curve_3d_core ( modifiedid , ori_id , xlen , ylen , s , x , y , z , dx2 , dy2 , dz2 , dx3 , dy3 , dz3 , dx , dy , dz );
	hilbert_curve_3d_core ( modifiedid , ori_id , xlen , ylen , s , 	(  x + 	(  s * dx ) ) , 	(  y + 	(  s * dy ) ) , 	(  z + 	(  s * dz ) ) , dx3 , dy3 , dz3 , dx , dy , dz , dx2 , dy2 , dz2 );
	hilbert_curve_3d_core ( modifiedid , ori_id , xlen , ylen , s , 	(  x + 	(  s * 	(  dx + dx2 ) ) ) , 	(  y + 	(  s * 	(  dy + dy2 ) ) ) , 	(  z + 	(  s * 	(  dz + dz2 ) ) ) , dx3 , dy3 , dz3 , dx , dy , dz , dx2 , dy2 , dz2 );
	hilbert_curve_3d_core ( modifiedid , ori_id , xlen , ylen , s , 	(  x + 	(  s * dx2 ) ) , 	(  y + 	(  s * dy2 ) ) , 	(  z + 	(  s * dz2 ) ) , 	- ( dx ) , 	- ( dy ) , 	- ( dz ) , 	- ( dx2 ) , 	- ( dy2 ) , 	- ( dz2 ) , dx3 , dy3 , dz3 );
	hilbert_curve_3d_core ( modifiedid , ori_id , xlen , ylen , s , 	(  x + 	(  s * 	(  dx2 + dx3 ) ) ) , 	(  y + 	(  s * 	(  dy2 + dy3 ) ) ) , 	(  z + 	(  s * 	(  dz2 + dz3 ) ) ) , 	- ( dx ) , 	- ( dy ) , 	- ( dz ) , 	- ( dx2 ) , 	- ( dy2 ) , 	- ( dz2 ) , dx3 , dy3 , dz3 );
	hilbert_curve_3d_core ( modifiedid , ori_id , xlen , ylen , s , 	(  x + 	(  s * 	(  dx + 	(  dx2 + dx3 ) ) ) ) , 	(  y + 	(  s * 	(  dy + 	(  dy2 + dy3 ) ) ) ) , 	(  z + 	(  s * 	(  dz + 	(  dz2 + dz3 ) ) ) ) , 	- ( dx3 ) , 	- ( dy3 ) , 	- ( dz3 ) , dx , dy , dz , 	- ( dx2 ) , 	- ( dy2 ) , 	- ( dz2 ) );
	hilbert_curve_3d_core ( modifiedid , ori_id , xlen , ylen , s , 	(  x + 	(  s * 	(  dx + dx3 ) ) ) , 	(  y + 	(  s * 	(  dy + dy3 ) ) ) , 	(  z + 	(  s * 	(  dz + dz3 ) ) ) , 	- ( dx3 ) , 	- ( dy3 ) , 	- ( dz3 ) , dx , dy , dz , 	- ( dx2 ) , 	- ( dy2 ) , 	- ( dz2 ) );
	hilbert_curve_3d_core ( modifiedid , ori_id , xlen , ylen , s , 	(  x + 	(  s * dx3 ) ) , 	(  y + 	(  s * dy3 ) ) , 	(  z + 	(  s * dz3 ) ) , dx2 , dy2 , dz2 , 	- ( dx3 ) , 	- ( dy3 ) , 	- ( dz3 ) , 	- ( dx ) , 	- ( dy ) , 	- ( dz ) );

	 }
	return  0 ;}
int  hilbert_curve_2d_core (long *  modifiedid ,long *  ori_id ,int  n ,long  x ,long  y ,long  xi ,long  xj ,long  yi ,long  yj ,long  xlen ){
	if (  	(  n == 0 )  ){  
			long  realx = 	(  	(  	(  x + 	(  	(  xi + xj ) / 2 ) ) - 1 ) / 2 ) ;
	long  realy = 	(  	(  	(  y + 	(  	(  yi + yj ) / 2 ) ) - 1 ) / 2 ) ;
	long  rid = 	(  realx + 	(  xlen * realy ) ) ;
((modifiedid)[rid] = cid);
((ori_id)[cid] = rid);
cid++;

	}else{
		(n = 	(  n - 1 ));
(x = 	(  x * 2 ));
(y = 	(  y * 2 ));
	hilbert_curve_2d_core ( modifiedid , ori_id , n , x , y , yi , yj , xi , xj , xlen );
	hilbert_curve_2d_core ( modifiedid , ori_id , n , 	(  x + xi ) , 	(  y + xj ) , xi , xj , yi , yj , xlen );
	hilbert_curve_2d_core ( modifiedid , ori_id , n , 	(  	(  x + xi ) + yi ) , 	(  y + 	(  xj + yj ) ) , xi , xj , yi , yj , xlen );
	hilbert_curve_2d_core ( modifiedid , ori_id , n , 	(  x + 	(  xi + 	(  2 * yi ) ) ) , 	(  y + 	(  xj + 	(  2 * yj ) ) ) , 	- ( yi ) , 	- ( yj ) , 	- ( xi ) , 	- ( xj ) , xlen );

	 }
	return  0 ;}
int  hilbert_curve_3d (long *  modifiedid ,long *  ori_id ,int  n ,size_t  xlen ,size_t  ylen ){
(cid = 0);
	return  	hilbert_curve_3d_core ( modifiedid , ori_id , 	(  1 << n ) , xlen , ylen , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 1 ) ;}
int  hilbert_curve_2d (long *  modifiedid ,long *  ori_id ,int  n ,size_t  xlen ){
(cid = 0);
	return  	hilbert_curve_2d_core ( modifiedid , ori_id , n , 0 , 0 , 2 , 0 , 0 , 2 , xlen ) ;}
int  sp_fill_curve_1d (long *  modifiedid ,long *  ori_id ,int  m ){
{
	long  i ;
	for ((i = 0) ; 	(  i < m ) ; (i = 	(  i + 1 )))
	{
((modifiedid)[i] = i);
((ori_id)[i] = i);
}}	return  0 ;}
