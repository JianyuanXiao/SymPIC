# SymPIC
The symplectic structure preserving particle-in-cell (PIC) code is 
designed for long-term simulations of the Vlasov-Maxwell system. It 
exactly preserves the symplectic two-form associated with the discrete 
Hamiltonian Vlasov-Maxwell equation and in most cases numeric errors 
of invariants such as the total energy and momentum will be bounded within
a small value during the whole simulation.

This is an MPI and OpenMP hybrid implemention of the parallel explicit 
2nd-order charge conservative non-canonical symplectic PIC scheme introduced 
in Ref. [1] and the 1st-order relativistic charge conservative symplectic 
PIC scheme in Ref. [2]. We also put the recently developed charge conservative 
symplectic PIC schemes in the cylindrical mesh [3] here. Most c files are generated 
by a scheme-like lisp dialect PSCMC (https://github.com/JianyuanXiao/PSCMC) designed 
for multi-platform parallel programmings. Source code is located at https://github.com/JianyuanXiao/SymPIC_PSCMC.

When using this code for research purpose, the citation of [1-3] are suggested.

In this program, uthash.h (http://troydhanson.github.com/uthash/) is 
used.

To build the program, a workable mpicc is required. For example in the 
Debian system, we may use the following command to install openmpi:
```bash
sudo apt-get install libopenmpi-dev openmpi-bin
```
Then use the following command to build the whole program

```bash
./compile.sh
```

Currently we have only tested the clang5.0/6.0, gcc-7.3.1 and icc-11 compiler.

Configuration files are executable scheme (a dialect of lisp) codes. To run
the example, 

```bash
cd example
export STDLIB=../stdlib.scm
mpirun -n 4 ../sympic x_ebw.ss
```

Note that this operation requires the number of MPI processes equals to 4. To modify
it you may edit the x_ebw.ss file and change the NUM_PROCESS parameter. We may also
use the MPI-OpenMP hybrid runtime:

```
cd example
export STDLIB=../stdlib.scm
export OMP_NUM_THREADS=2
mpirun -n 2 ../sympic x_ebw_openmp.ss
```

After it exits, three files (tmpEB tmpEN and tmpJ) will be generated. 
These files are in the GAPS-IO format. We can use the matplotlib (ipython) to 
show the spectrum of the extraordinary and electron Bernstein wave.

```python
execfile("../cgapsio/pygapsio.py")
Ey_field=reshape(GAPS_IO_Load("tmpEB"),[512,2,512,3])[:,0,:,1]
contour(abs(fftn(Ey_field))[:60,:256])
```

The tmpEB file stores the electromagnetic fields, its shape
is 2Nt * Nz * Ny * Nx * 3, where for 0, 2, 4, ... time step the 
electric field is stored, and for 1, 3, 5, ... time step the 
magnetic field is stored. The tmpEN file stores some particle
informations, currently its shape is Nt * Nz * Ny * Nx * (7NUM_SPEC), 
where 7 components are 

\sum_{p \in grid} [m_i vx_p^2/2,m_i vy_p^2/2,m_i vz_p^2/2, vx_p, vy_p, vz_p, 1].

There is also a GUI based on Tkinter(python2) for generating and 
modifying the configuration files, it is located at gui/gui.py

```bash
cd gui
export STDLIB=../stdlib.scm
python2 gui.py
```

The manual is also available at http://staff.ustc.edu.cn/~xiaojy/sympic_doc.html


[1] Physics of Plasmas 22, 112504 (2015); https://aip.scitation.org/doi/abs/10.1063/1.4935904

[2] Plasma Science and Technology 20, 110501 (2018); https://iopscience.iop.org/article/10.1088/2058-6272/aac3d1

[3] Plasma Sci. Technol. 23 055102 (2021); https://iopscience.iop.org/article/10.1088/2058-6272/abf125/meta
