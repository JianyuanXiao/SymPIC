(optload "x_ebw.ss") ; load x_ebw.ss
(define NUM_PROCESS 2) ;using 2 MPI processes
(define (GET_DEV_TYPE x r) 1) ;set the type of computing environment to 1, which is OpenMP
