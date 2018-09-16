#include <omp.h> 
#include <math.h>
void  openmp_yee_local_scmc_kernel (double *  inout ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  xyzx = 	(  idx % xb ) ;
	long  xyzy = 	(  	(  idx / xb ) % yb ) ;
	long  xyzz = 	(  idx / 	(  xb * yb ) ) ;
}
void  openmp_sync_ovlp_o2m_scmc_kernel (double *  vecmain ,double *  vecovlp ,int  ovlpindex ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / ylen ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
	{
	long  j = 0 ;
	int  xlo = 	(  ovlpindex % 3 ) ;
	int  ylo = 	(  	(  ovlpindex / 3 ) % 3 ) ;
	int  zlo = 	(  	(  ovlpindex / 3 ) / 3 ) ;
	int  field_xmi = ovlp ;
	int  field_ymi = ovlp ;
	int  field_zmi = ovlp ;
	long  field_xma = 	(  xb - ovlp ) ;
	long  field_yma = 	(  yb - ovlp ) ;
	long  field_zma = 	(  zb - ovlp ) ;
	if (  	(  xlo == 0 )  ){  
		(field_xmi = 0);
(field_xma = 	(  ovlp + 0 ));

	}else{
			if (  	(  xlo == 2 )  ){  
		(field_xmi = 	(  xb - 	(  ovlp + 0 ) ));
(field_xma = 	(  xb - 0 ));

	}else{
		0;

	 }

	 }
	if (  	(  ylo == 0 )  ){  
		(field_ymi = 0);
(field_yma = 	(  ovlp + 0 ));

	}else{
			if (  	(  ylo == 2 )  ){  
		(field_ymi = 	(  yb - 	(  ovlp + 0 ) ));
(field_yma = 	(  yb - 0 ));

	}else{
		0;

	 }

	 }
	if (  	(  zlo == 0 )  ){  
		(field_zmi = 0);
(field_zma = 	(  ovlp + 0 ));

	}else{
			if (  	(  zlo == 2 )  ){  
		(field_zmi = 	(  zb - 	(  ovlp + 0 ) ));
(field_zma = 	(  zb - 0 ));

	}else{
		0;

	 }

	 }
	long  ovlpxma = 	(  field_xma - field_xmi ) ;
	long  ovlpyma = 	(  field_yma - field_ymi ) ;
	long  ovlpzma = 	(  field_zma - field_zmi ) ;
	long  ovlpalllen = 	(  ovlpxma * 	(  ovlpyma * 	(  ovlpzma * num_ele ) ) ) ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ovlpzma ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < ovlpyma ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < ovlpxma ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  lxyzx = 	(  xyzx + field_xmi ) ;
	long  lxyzy = 	(  xyzy + field_ymi ) ;
	long  lxyzz = 	(  xyzz + field_zmi ) ;
	if (  0  ){  
			if (  	(  	(  lxyzx < ovlp ) || 	(  lxyzx >= 	(  xb - ovlp ) ) )  ){  
		(lxyzx = ovlp);

	}else{
		0;

	 }
	if (  	(  	(  lxyzy < ovlp ) || 	(  lxyzy >= 	(  yb - ovlp ) ) )  ){  
		(lxyzy = ovlp);

	}else{
		0;

	 }
	if (  	(  	(  lxyzz < ovlp ) || 	(  lxyzz >= 	(  zb - ovlp ) ) )  ){  
		(lxyzz = ovlp);

	}else{
		0;

	 }

	}else{
		0;

	 }
{
	long  g = 0 ;
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < num_ele ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
((vecmain)[	(  	(  i * blk_all_len ) + 	(  realidx + 	(  num_ele * 	(  lxyzx + 	(  xb * 	(  lxyzy + 	(  yb * lxyzz ) ) ) ) ) ) )] = (vecovlp)[	(  	(  i * ovlpalllen ) + 	(  realidx + 	(  num_ele * 	(  xyzx + 	(  ovlpxma * 	(  xyzy + 	(  ovlpyma * xyzz ) ) ) ) ) ) )]);
}}}}}}}}}}
void  openmp_sync_ovlp_m2o_scmc_kernel (double *  vecmain ,double *  vecovlp ,int  ovlpindex ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / ylen ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
	{
	long  j = 0 ;
	int  xlo = 	(  ovlpindex % 3 ) ;
	int  ylo = 	(  	(  ovlpindex / 3 ) % 3 ) ;
	int  zlo = 	(  	(  ovlpindex / 3 ) / 3 ) ;
	int  field_xmi = ovlp ;
	int  field_ymi = ovlp ;
	int  field_zmi = ovlp ;
	long  field_xma = 	(  xb - ovlp ) ;
	long  field_yma = 	(  yb - ovlp ) ;
	long  field_zma = 	(  zb - ovlp ) ;
	if (  	(  xlo == 0 )  ){  
		(field_xmi = ovlp);
(field_xma = 	(  ovlp + ovlp ));

	}else{
			if (  	(  xlo == 2 )  ){  
		(field_xmi = 	(  xb - 	(  ovlp + ovlp ) ));
(field_xma = 	(  xb - ovlp ));

	}else{
		0;

	 }

	 }
	if (  	(  ylo == 0 )  ){  
		(field_ymi = ovlp);
(field_yma = 	(  ovlp + ovlp ));

	}else{
			if (  	(  ylo == 2 )  ){  
		(field_ymi = 	(  yb - 	(  ovlp + ovlp ) ));
(field_yma = 	(  yb - ovlp ));

	}else{
		0;

	 }

	 }
	if (  	(  zlo == 0 )  ){  
		(field_zmi = ovlp);
(field_zma = 	(  ovlp + ovlp ));

	}else{
			if (  	(  zlo == 2 )  ){  
		(field_zmi = 	(  zb - 	(  ovlp + ovlp ) ));
(field_zma = 	(  zb - ovlp ));

	}else{
		0;

	 }

	 }
	long  ovlpxma = 	(  field_xma - field_xmi ) ;
	long  ovlpyma = 	(  field_yma - field_ymi ) ;
	long  ovlpzma = 	(  field_zma - field_zmi ) ;
	long  ovlpalllen = 	(  ovlpxma * 	(  ovlpyma * 	(  ovlpzma * num_ele ) ) ) ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ovlpzma ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < ovlpyma ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < ovlpxma ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  lxyzx = 	(  xyzx + field_xmi ) ;
	long  lxyzy = 	(  xyzy + field_ymi ) ;
	long  lxyzz = 	(  xyzz + field_zmi ) ;
	if (  1  ){  
			if (  	(  	(  lxyzx < ovlp ) || 	(  lxyzx >= 	(  xb - ovlp ) ) )  ){  
		(lxyzx = ovlp);

	}else{
		0;

	 }
	if (  	(  	(  lxyzy < ovlp ) || 	(  lxyzy >= 	(  yb - ovlp ) ) )  ){  
		(lxyzy = ovlp);

	}else{
		0;

	 }
	if (  	(  	(  lxyzz < ovlp ) || 	(  lxyzz >= 	(  zb - ovlp ) ) )  ){  
		(lxyzz = ovlp);

	}else{
		0;

	 }

	}else{
		0;

	 }
{
	long  g = 0 ;
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < num_ele ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
((vecovlp)[	(  	(  i * ovlpalllen ) + 	(  realidx + 	(  num_ele * 	(  xyzx + 	(  ovlpxma * 	(  xyzy + 	(  ovlpyma * xyzz ) ) ) ) ) ) )] = (vecmain)[	(  	(  i * blk_all_len ) + 	(  realidx + 	(  num_ele * 	(  lxyzx + 	(  xb * 	(  lxyzy + 	(  yb * lxyzz ) ) ) ) ) ) )]);
}}}}}}}}}}
void  openmp_merge_ovlp_o2m_scmc_kernel (double *  vecmain ,double *  vecovlp ,int  ovlpindex ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / ylen ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
	{
	long  j = 0 ;
	int  xlo = 	(  ovlpindex % 3 ) ;
	int  ylo = 	(  	(  ovlpindex / 3 ) % 3 ) ;
	int  zlo = 	(  	(  ovlpindex / 3 ) / 3 ) ;
	int  field_xmi = ovlp ;
	int  field_ymi = ovlp ;
	int  field_zmi = ovlp ;
	long  field_xma = 	(  xb - ovlp ) ;
	long  field_yma = 	(  yb - ovlp ) ;
	long  field_zma = 	(  zb - ovlp ) ;
	if (  	(  xlo == 0 )  ){  
		(field_xmi = ovlp);
(field_xma = 	(  ovlp + ovlp ));

	}else{
			if (  	(  xlo == 2 )  ){  
		(field_xmi = 	(  xb - 	(  ovlp + ovlp ) ));
(field_xma = 	(  xb - ovlp ));

	}else{
		0;

	 }

	 }
	if (  	(  ylo == 0 )  ){  
		(field_ymi = ovlp);
(field_yma = 	(  ovlp + ovlp ));

	}else{
			if (  	(  ylo == 2 )  ){  
		(field_ymi = 	(  yb - 	(  ovlp + ovlp ) ));
(field_yma = 	(  yb - ovlp ));

	}else{
		0;

	 }

	 }
	if (  	(  zlo == 0 )  ){  
		(field_zmi = ovlp);
(field_zma = 	(  ovlp + ovlp ));

	}else{
			if (  	(  zlo == 2 )  ){  
		(field_zmi = 	(  zb - 	(  ovlp + ovlp ) ));
(field_zma = 	(  zb - ovlp ));

	}else{
		0;

	 }

	 }
	long  ovlpxma = 	(  field_xma - field_xmi ) ;
	long  ovlpyma = 	(  field_yma - field_ymi ) ;
	long  ovlpzma = 	(  field_zma - field_zmi ) ;
	long  ovlpalllen = 	(  ovlpxma * 	(  ovlpyma * 	(  ovlpzma * num_ele ) ) ) ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ovlpzma ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < ovlpyma ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < ovlpxma ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  lxyzx = 	(  xyzx + field_xmi ) ;
	long  lxyzy = 	(  xyzy + field_ymi ) ;
	long  lxyzz = 	(  xyzz + field_zmi ) ;
	if (  1  ){  
			if (  	(  	(  lxyzx < ovlp ) || 	(  lxyzx >= 	(  xb - ovlp ) ) )  ){  
		(lxyzx = ovlp);

	}else{
		0;

	 }
	if (  	(  	(  lxyzy < ovlp ) || 	(  lxyzy >= 	(  yb - ovlp ) ) )  ){  
		(lxyzy = ovlp);

	}else{
		0;

	 }
	if (  	(  	(  lxyzz < ovlp ) || 	(  lxyzz >= 	(  zb - ovlp ) ) )  ){  
		(lxyzz = ovlp);

	}else{
		0;

	 }

	}else{
		0;

	 }
{
	long  g = 0 ;
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < num_ele ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
((vecmain)[	(  	(  i * blk_all_len ) + 	(  realidx + 	(  num_ele * 	(  lxyzx + 	(  xb * 	(  lxyzy + 	(  yb * lxyzz ) ) ) ) ) ) )] = 	(  (vecmain)[	(  	(  i * blk_all_len ) + 	(  realidx + 	(  num_ele * 	(  lxyzx + 	(  xb * 	(  lxyzy + 	(  yb * lxyzz ) ) ) ) ) ) )] + (vecovlp)[	(  	(  i * ovlpalllen ) + 	(  realidx + 	(  num_ele * 	(  xyzx + 	(  ovlpxma * 	(  xyzy + 	(  ovlpyma * xyzz ) ) ) ) ) ) )] ));
}}}}}}}}}}
void  openmp_merge_ovlp_m2o_scmc_kernel (double *  vecmain ,double *  vecovlp ,int  ovlpindex ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  scmc_internal_g_idy ,long  scmc_internal_g_ylen ){
	const long  idx = 0 ;
	const long  idy = scmc_internal_g_idy ;
	const long  xlen = 1 ;
	const long  ylen = scmc_internal_g_ylen ;
	const long  global_idx = 	(  idx + 	(  idy * xlen ) ) ;
	long  i = 0 ;
	long  local_ynum = 	(  	(  	(  numvec - 1 ) / ylen ) + 1 ) ;
	long  local_ymin = 	(  idy * local_ynum ) ;
	long  local_ymax = 	(  	(  1 + idy ) * local_ynum ) ;
	long  xb = xblock ;
	long  yb = yblock ;
	long  zb = zblock ;
	long  blk_all_len = 	(  xb * 	(  yb * 	(  zb * num_ele ) ) ) ;
	if (  	(  local_ymax >= numvec )  ){  
		(local_ymax = numvec);

	}else{
		0;

	 }
	for ((i = local_ymin) ; 	(  i < local_ymax ) ; i++)
	{
	long  j = 0 ;
	int  xlo = 	(  ovlpindex % 3 ) ;
	int  ylo = 	(  	(  ovlpindex / 3 ) % 3 ) ;
	int  zlo = 	(  	(  ovlpindex / 3 ) / 3 ) ;
	int  field_xmi = ovlp ;
	int  field_ymi = ovlp ;
	int  field_zmi = ovlp ;
	long  field_xma = 	(  xb - ovlp ) ;
	long  field_yma = 	(  yb - ovlp ) ;
	long  field_zma = 	(  zb - ovlp ) ;
	if (  	(  xlo == 0 )  ){  
		(field_xmi = 0);
(field_xma = 	(  ovlp + 0 ));

	}else{
			if (  	(  xlo == 2 )  ){  
		(field_xmi = 	(  xb - 	(  ovlp + 0 ) ));
(field_xma = 	(  xb - 0 ));

	}else{
		0;

	 }

	 }
	if (  	(  ylo == 0 )  ){  
		(field_ymi = 0);
(field_yma = 	(  ovlp + 0 ));

	}else{
			if (  	(  ylo == 2 )  ){  
		(field_ymi = 	(  yb - 	(  ovlp + 0 ) ));
(field_yma = 	(  yb - 0 ));

	}else{
		0;

	 }

	 }
	if (  	(  zlo == 0 )  ){  
		(field_zmi = 0);
(field_zma = 	(  ovlp + 0 ));

	}else{
			if (  	(  zlo == 2 )  ){  
		(field_zmi = 	(  zb - 	(  ovlp + 0 ) ));
(field_zma = 	(  zb - 0 ));

	}else{
		0;

	 }

	 }
	long  ovlpxma = 	(  field_xma - field_xmi ) ;
	long  ovlpyma = 	(  field_yma - field_ymi ) ;
	long  ovlpzma = 	(  field_zma - field_zmi ) ;
	long  ovlpalllen = 	(  ovlpxma * 	(  ovlpyma * 	(  ovlpzma * num_ele ) ) ) ;
{
	long  xyzz ;
	for ((xyzz = 0) ; 	(  xyzz < ovlpzma ) ; (xyzz = 	(  xyzz + 1 )))
	{
{
	long  xyzy ;
	for ((xyzy = 0) ; 	(  xyzy < ovlpyma ) ; (xyzy = 	(  xyzy + 1 )))
	{
{
	long  xyzx ;
	for ((xyzx = 0) ; 	(  xyzx < ovlpxma ) ; (xyzx = 	(  xyzx + 1 )))
	{
	long  lxyzx = 	(  xyzx + field_xmi ) ;
	long  lxyzy = 	(  xyzy + field_ymi ) ;
	long  lxyzz = 	(  xyzz + field_zmi ) ;
	if (  0  ){  
			if (  	(  	(  lxyzx < ovlp ) || 	(  lxyzx >= 	(  xb - ovlp ) ) )  ){  
		(lxyzx = ovlp);

	}else{
		0;

	 }
	if (  	(  	(  lxyzy < ovlp ) || 	(  lxyzy >= 	(  yb - ovlp ) ) )  ){  
		(lxyzy = ovlp);

	}else{
		0;

	 }
	if (  	(  	(  lxyzz < ovlp ) || 	(  lxyzz >= 	(  zb - ovlp ) ) )  ){  
		(lxyzz = ovlp);

	}else{
		0;

	 }

	}else{
		0;

	 }
{
	long  g = 0 ;
	for (g=0 ; 	(  	(  idx + 	(  g * xlen ) ) < num_ele ) ; g++)
	{
	long  realidx = 	(  idx + 	(  g * xlen ) ) ;
((vecovlp)[	(  	(  i * ovlpalllen ) + 	(  realidx + 	(  num_ele * 	(  xyzx + 	(  ovlpxma * 	(  xyzy + 	(  ovlpyma * xyzz ) ) ) ) ) ) )] = (vecmain)[	(  	(  i * blk_all_len ) + 	(  realidx + 	(  num_ele * 	(  lxyzx + 	(  xb * 	(  lxyzy + 	(  yb * lxyzz ) ) ) ) ) ) )]);
}}}}}}}}}}
