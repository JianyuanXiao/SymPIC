# SymPIC
The symplectic structure preserving particle-in-cell (PIC) code is 
designed for long-term simulations of the Vlasov-Maxwell system. It 
exactly preserves the symplectic two-form associated with the discrete 
Hamiltonian Vlasov-Maxwell equation and in most cases numeric errors 
of invariants such as the total energy and momentum will be bounded within
a small value during the whole simulation.

This is a precompiled x86-64 binary MPI implemention of the parallel 
explicit 2nd-order charge conservative non-canonical symplectic PIC 
scheme introduced in Ref. [1] and the 1st-order relativistic charge 
conservative symplectic PIC scheme in Ref. [2]. Source code will be 
opened in the near future.

To build the program, just use make.

Configuration files are executable scheme (a dialect of lisp) codes. To run
the example, 

cd example

STDLIB=../stdlib.scm mpirun -n 4 ../sympic x_ebw.ss

three files (tmpEB tmpEN and tmpJ) will be generated. These files are in 
the GAPS-IO format. We can use the matplotlib (ipython) to show the 
spectrum of the extraordinary and electron Bernstein wave.

execfile("../cgapsio/pygapsio.py")

Ey_field=reshape(GAPS_IO_Load("tmpEB"),[512,2,512,3])[:,0,:,1]

contour(abs(fftn(Ey_field))[:60,:256])

There is also a GUI based on Tkinter(python2) for generating and 
modifying the configuration files, it is located at gui/gui.py


[1] Physics of Plasmas 22, 112504 (2015); https://doi.org/10.1063/1.4935904

[2] Plasma Science and Technology 20, 110501 (2018); https://iopscience.iop.org/article/10.1088/2058-6272/aac3d1
