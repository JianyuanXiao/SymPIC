(defmacro many-define lst
  (cons 'begin (map (lambda (x) (cons 'define x)) lst))
  )

(many-define
  (REAL_DX 2.8e-5) ;grid size in m
  (REAL_MU0 (* 4 m_pi 1e-7)) ;magnetic permeability in the vacuum
  (REAL_NE 2.5e20) ;reference electron number of density in m^-3
  (REAL_ME 9.1e-31) ;mass of the electron in kg
  (REAL_E 1.6e-19) ;charge of the electron in C
  (REAL_C 299792458.) ;the speed of light in the vacuum in m/s
  (DT 0.5) ;time step in REAL_DX/REAL_C
  (DELTAT DT) ;set DELTAT=DT
  (REAL_DT (* REAL_C DT)) ;real time step in s
  (E (* REAL_E (sqrt (/ REAL_MU0 REAL_ME REAL_DX)))) ; normalized charge in the simulation
  (CONST_E_DENSITY (* REAL_NE REAL_DX REAL_DX REAL_DX)) ; normalized number of density in the simulation
  (EI_SCALE 5) ;n_e/n_i
  (NPG0 200) ;reference number of sampling points of electron in one grid cell
  (NPG1 (/ NPG0 EI_SCALE)) ;reference number of sampling points of ion in one grid cell
  (NPM0 (/ CONST_E_DENSITY NPG0)) ;number of electron per sampling point
  (NPM1 (/ CONST_E_DENSITY NPG1)) ;number of ion per sampling point

  (DAMP_RATIO 0) ;
  (XMAX 1)  ;number of grids in one compute unit in the x direction
  (YMAX 32) ;number of grids in one compute unit in the y direction
  (ZMAX 1)  ;number of grids in one compute unit in the z direction
  (NUM_PROCESS 4) ;number of MPI processes used
  (NUM_RUNTIME 1) ;number of runtimes used 
  (NUM_MAX_RUNTIME 4) ;the maximum number of runtimes
  ;following are Hilbert space filling curve parameters
  (NUM_N_HILBERT 4) ;4th-order Hilbert space filling curve
  (NUM_N_HILBERT_DIMENSION 1) ;one-dimensional space filling is used
  (HILBERT_DIR 1) ;the expansion direction of the space filling curve is y
  (NUM_TIMESTEP 2048) ;total number of time step
  ;(NUM_TIMESTEP 200000)
  (NUM_DUMP_TIMESTEP 4) ;outputing fields per 4 time steps
  ;(NUM_DUMP_TIMESTEP 400)
  (NUM_SPEC 1) ;number of species of charged particle
  (USE_KGM 0) ;KGM mode 
  (USE_DM 0) ;DM mode
  (USE_TORI 0)
  (TORI_X0 128)
  (TORI_SOLVE_ERR 1e-13)

  (USE_LHCD_INPUT 0) 
  (USE_ECRH_INPUT 0) 
  (ECRH_AMPX 0)
  (ECRH_AMPY 0)
  (ECRH_AMPZ 0)
  (ECRH_KY 1)
  (ECRH_KZ 0)
  (ECRH_LOC_X0 636)
  (ECRH_LOC_Y0 0)
  (ECRH_LOC_Y1 32)
  (ECRH_LOC_Z0 0)
  (ECRH_LOC_Z1 1)
  (ECRH_FREQ 0.39) 
  (GET_VAR ;to dynamicly load symbol bindings in the program
    (lambda (s) 
      (define s1 (string->symbol s))
      (if (symbol-binded? s1)
	(eval (string->symbol s))
	(begin 
	  (write-string (multi-concat "Warning: symbol " s1 " is unbounded\n" ) current-error-port)
	  0
	  ))))
  (M_0 1) ;normalized mass for the 0th species
  (M_1 3672) ;normalized mass for the 1st species
  (E_0 -1) ;reference charge of the 0th species
  (E_1 1) ;reference charge of the 1st species
  (USE_CHECKPOINT 0) ;use checkpoint or not
  (NUM_CHECKPOINT_TIMESTEP 10000) ;output checkpoint per 10000 time step
  (X_NUMT (arithmetic-shift 1 NUM_N_HILBERT))

  (CAL_FUN_ONE_PARA ;for dynamicly load one parameter functions
    (lambda (s x)
      (define s1 (string->symbol s))
      (if (symbol-binded? s1)
	((eval (string->symbol s)) x)
	(begin 
	  (write-string (multi-concat "Warning: symbol " s1 " is unbounded\n" ) current-error-port)
	  (car 0)
	  )))
    )
  (get_thread_complexity 
    (lambda (x)
      (define x (integer-floor x))
      (define idx (* (+ 0.5 (remainder x X_NUMT)) XMAX))
      (define idy (* (+ 0.5 (quotient x X_NUMT)) YMAX))
      (* 1000 (+ (GET_INIT_DENSITY_DIST 0 idx idy 0) 0.001))
       ;0.04
      ))
  (USE_CALC_WEIGHT 0) ;
  (USE_AVER_OUTPUT 0) ;out put averaged field or not
  (USE_BORIS_YEE 0) ;use the Boris-Yee scheme or not
  (USE_NP_BOUNDARY 0) ;use complex boundary condition or not
  (USE_NON_UNI_CACHE_DIST 0)
  (GET_NON_UNI_CACHE_DIST (lambda x 0))
  (USE_ABC_DIR 0) ;set the Mur absorbing boundary direction(s), 1 for x, 2 for y, 3 for x+y, 4 for z, ...
  (USE_PEC_DIR 0) ;set the PEC boundary direction(s)
  (USE_FILTER 0) ;use the electromagnetic filter or not
  (USE_PROFILE 0) ;output the timing or not
  (USE_INIT_EB0 0) ;use the initial electromagnetic fields or not
  (USE_INIT_V0 0) ;use the initial averaged velocity or not
  (USE_NON_UNI_DENSITY 0) ;use the non uniform density or not
  (USE_NON_UNI_TEMPERATURE 0) ;use the non uniform temperature or not
  (GET_INIT_TEMPERATURE_DIST (lambda x 0)) ;set the initial temperature dist
  (USE_INIT_EXT_EB 1) ;use external electromagnetic fields or not
  ;(GET_DEV_TYPE  (lambda (x) (+ x 1)))
  (GET_DEV_TYPE  (lambda (x r) 0)) ;set the type of computing environment, here 0 for the pure C runtime
  (GET_DEV_ID  (lambda (x r) 0)) ;set the id of the compute device, used in OpenCL or CUDA to choose different GPU
  (GET_NPM (lambda (i) 100))
  (GET_INIT_FILTER_E (lambda x 1)) 
  (GET_INIT_FILTER_B (lambda x 1))
  (USE_REL 0) ;
  (KROOK_MU_FREQ 0) ;
  (USE_DAMP_DIR 0) 
  (GET_NUM_LOCAL_THREAD_FROM_GLOBAL_TID (lambda x x))
  (GET_MASS ;get the mass of sampling point of species i
    (lambda (i) 
      (case i
	(0 (* M_0 NPM0))
	(1 (* M_1 NPM1))
	(else 1)
	)
      ))
  (GET_CHARGE ;get the charge of sampling point of species i
    (lambda (i) 
      (case i
	(0 (* E_0 E NPM0))
	(1 (* E_1 E NPM1))
	(else 0)
	)
      ))
  (GET_GRID_CACHE_LEN ;set the one-grid cache size for species i
    (lambda (i) 
      (case i
	(0 240)
	(1 8)
	(else 0)
	) )
    
    )
  (GET_CU_CACHE_LEN ;set the compute unit cache size for species i
    (lambda (i) 22240))
  (GET_INIT_LOAD ;get the initial reference number sampling point per grid for species i
    (lambda (i) 
      (case i
	(0 NPG0)
	(1 NPG1)
	(else NPG0)
	)))
  (GET_INIT_DENSITY_DIST ;if USE_NON_UNI_DENSITY is not 0, then use this function to get density dist for species i
    (lambda (i z y x)
      (set! x (- x 0.5))
      (set! y (- y 0.5))
      (define xmid (* 0.5 (arithmetic-shift 1 NUM_N_HILBERT) XMAX))
      (define ymid (* 0.5 (arithmetic-shift 1 NUM_N_HILBERT) YMAX))
      (define xcur (* (- x xmid) (- x xmid)))
      (define ycur (* (- y ymid) (- y ymid)))
      ;(define ycur 0)
      (define rcur (sqrt (+ xcur ycur)))
      (define rmin 0.1)
      (define ans (cond
	((< rcur rmin) 0.15)
	(else 
	  (define sxar (pow (/ 9.5 2) 2))
	  (* 0.15 (exp (- (* sxar (- rcur rmin) (- rcur rmin)))))
	  )
	))
      ;(write (list x y z ans) current-error-port) (newline current-error-port)
      ans
      ))
  (GET_INIT_VT (lambda (i) (case i (0 0.07) (1 0.0008) (else 0)))) ;get the reference thermal speed for species i
  (GET_INIT_E (lambda (z y x l) 0)) ;use this function to get the external electric field
  (GET_INIT_FILTER_KROOK (lambda x 0))
  ;following two function are used to obtain normalized electromagnetic fields from real electromagnetic fields in SI units
  (gen_simulate_B 
    (lambda (x)
      (runc "x/(E*REAL_C/REAL_DX*REAL_ME/REAL_E)")
      ))
  (gen_simulate_E 
    (lambda (x)
      (runc "x/(E*REAL_C*REAL_C/REAL_DX*REAL_ME/REAL_E)")
      ))
  (Bvec (vector (gen_simulate_B 4.6) 0 0)) ;the external magnetic field is Bx=4.6T,By=Bz=0
  (GET_INIT_B ;obtain the external magnetic field
    (lambda (z y x l) 
      ;(write (list x y z l) current-error-port) (newline current-error-port)
      (vector-ref Bvec l)
      )
    )
  (GET_INIT_E0 ;obtain the initial electric field distribution
    (lambda (z y x) 
      0
      ))
  (GET_INIT_B0 (lambda x 0)) ;obtain the initial magnetic field distribution
  ;use following 3 functions to obtain the averaged velocity in x,y and z directions
  (GET_INIT_V0_x (lambda x 0)) 
  (GET_INIT_V0_y (lambda x 0))
  (GET_INIT_V0_z (lambda x 0))

  )

