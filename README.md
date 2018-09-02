# SymPIC
The symplectic structure preserving particle-in-cell (PIC) code is 
designed for long-term simulations of the Vlasov-Maxwell system. It 
exactly preserves the symplectic two-form associated with the discrete 
Hamiltonian Vlasov-Maxwell equation and in most cases numeric errors 
invariants such as the total energy and momentum will be bounded within a 
small value.

This is a precompiled x86-64 binary MPI implemention of the explicit 
2nd-order non-canonical symplectic PIC scheme introduced in Ref. [1]. 
Source code will be opened in the future.

To compile the program, just use make.

To run the example, 

cd example

STDLIB=../stdlib.scm mpirun -n 4 ../sympic x_ebw.ss

three files (tmpEB tmpEN and tmpJ) will be generated. We can use the 
matplotlib to show the spectrum of the X and EBW.

execfile("../cgapsio/pygapsio.py")

Ey_field=reshape(GAPS_IO_Load("tmpEB"),[512,2,512,3])[:,0,:,1]

contour(abs(fftn(Ey_field))[:60,:256])


[1] Physics of Plasmas 22, 112504 (2015); https://doi.org/10.1063/1.4935904
