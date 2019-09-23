export STDLIB=../stdlib.scm
export OMP_NUM_THREADS=2
mpirun -n 2 ../sympic x_ebw_openmp.ss
