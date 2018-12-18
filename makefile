CC=mpicc
SCC=scc


NVCC=nvcc
BRCC=
CXX=mpicc
CFLAG= -fopenmp -O2 -ffast-math
CPPFLAG=
NVCCF= -arch=sm_20
CXXFLAG= -O2 -lm c_yeefdtd.a openmp_yeefdtd.a -fopenmp libsmallmpi.a cfgcst.c -lcscheme -lcgapsio -lm -I../common/
SWMSCC=sw5cc
SWMSCCFLAG=-slave -ffast-math -O3
SWMHCC=sw5cc
SWMHCCFLAG=-host
LOCALPROG=sympic
sources= space_filling_curve.o init_adjoint_relation.o split_shell.o init_field3d_mpi.o genrand.o init_particle.o sort_particle.o checkpoint.o run_particle.o pass_xyzzyx.o mpifields.o call_curl_kernel.o blas_shell.o field_sync_h2d_d2h.o sync_fields.o smalllib.o mpi_fieldio.o seqfields.o main.o
$(LOCALPROG)	:$(sources)
	$(CXX)   $(sources) -o $(LOCALPROG) $(CXXFLAG)


space_filling_curve.o: space_filling_curve.c 
	$(CC) $(CPPFLAG) -E space_filling_curve.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>space_filling_curvemid.c
	$(CC) -c space_filling_curvemid.c $(CFLAG) -g -o space_filling_curve.o


init_adjoint_relation.o: init_adjoint_relation.c libsmallmpi.h local_header.h cfgcst.h c_/c_pscmc_inc.h openmp_/openmp_pscmc_inc.h c_/yeefdtd.kernel_inc.h c_/mergefields.kernel_inc.h c_/miniblas.kernel_inc.h c_/general_partial_sort.kernel_inc.h c_/move_back.kernel_inc.h c_/particle_iter.kernel_inc.h c_/mur_abc.kernel_inc.h c_/dm.kernel_inc.h c_/geo_yeefdtd_rect.kernel_inc.h c_/geo_yeefdtd.kernel_inc.h c_/geo_particle_iter_mass.kernel_inc.h c_/geo_particle_iter.kernel_inc.h c_/rel_particle_iter.kernel_inc.h c_yeefdtd.h openmp_/yeefdtd.kernel_inc.h openmp_/mergefields.kernel_inc.h openmp_/miniblas.kernel_inc.h openmp_/general_partial_sort.kernel_inc.h openmp_/move_back.kernel_inc.h openmp_/particle_iter.kernel_inc.h openmp_/mur_abc.kernel_inc.h openmp_/dm.kernel_inc.h openmp_/geo_yeefdtd_rect.kernel_inc.h openmp_/geo_yeefdtd.kernel_inc.h openmp_/geo_particle_iter_mass.kernel_inc.h openmp_/geo_particle_iter.kernel_inc.h openmp_/rel_particle_iter.kernel_inc.h openmp_yeefdtd.h space_filling_curve.h pubdefs.h 
	$(CC) $(CPPFLAG) -E init_adjoint_relation.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>init_adjoint_relationmid.c
	$(CC) -c init_adjoint_relationmid.c $(CFLAG) -g -o init_adjoint_relation.o


split_shell.o: split_shell.c libsmallmpi.h local_header.h c_/c_pscmc_inc.h openmp_/openmp_pscmc_inc.h c_/yeefdtd.kernel_inc.h c_/mergefields.kernel_inc.h c_/miniblas.kernel_inc.h c_/general_partial_sort.kernel_inc.h c_/move_back.kernel_inc.h c_/particle_iter.kernel_inc.h c_/mur_abc.kernel_inc.h c_/dm.kernel_inc.h c_/geo_yeefdtd_rect.kernel_inc.h c_/geo_yeefdtd.kernel_inc.h c_/geo_particle_iter_mass.kernel_inc.h c_/geo_particle_iter.kernel_inc.h c_/rel_particle_iter.kernel_inc.h c_yeefdtd.h openmp_/yeefdtd.kernel_inc.h openmp_/mergefields.kernel_inc.h openmp_/miniblas.kernel_inc.h openmp_/general_partial_sort.kernel_inc.h openmp_/move_back.kernel_inc.h openmp_/particle_iter.kernel_inc.h openmp_/mur_abc.kernel_inc.h openmp_/dm.kernel_inc.h openmp_/geo_yeefdtd_rect.kernel_inc.h openmp_/geo_yeefdtd.kernel_inc.h openmp_/geo_particle_iter_mass.kernel_inc.h openmp_/geo_particle_iter.kernel_inc.h openmp_/rel_particle_iter.kernel_inc.h openmp_yeefdtd.h blas_shell.h pubdefs.h run_particle.h mpi_fieldio.h cfgcst.h call_curl_kernel.h mpifields.h split_shell.h 
	$(CC) $(CPPFLAG) -E split_shell.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>split_shellmid.c
	$(CC) -c split_shellmid.c $(CFLAG) -g -o split_shell.o


init_field3d_mpi.o: init_field3d_mpi.c libsmallmpi.h local_header.h c_/c_pscmc_inc.h openmp_/openmp_pscmc_inc.h c_/yeefdtd.kernel_inc.h c_/mergefields.kernel_inc.h c_/miniblas.kernel_inc.h c_/general_partial_sort.kernel_inc.h c_/move_back.kernel_inc.h c_/particle_iter.kernel_inc.h c_/mur_abc.kernel_inc.h c_/dm.kernel_inc.h c_/geo_yeefdtd_rect.kernel_inc.h c_/geo_yeefdtd.kernel_inc.h c_/geo_particle_iter_mass.kernel_inc.h c_/geo_particle_iter.kernel_inc.h c_/rel_particle_iter.kernel_inc.h c_yeefdtd.h openmp_/yeefdtd.kernel_inc.h openmp_/mergefields.kernel_inc.h openmp_/miniblas.kernel_inc.h openmp_/general_partial_sort.kernel_inc.h openmp_/move_back.kernel_inc.h openmp_/particle_iter.kernel_inc.h openmp_/mur_abc.kernel_inc.h openmp_/dm.kernel_inc.h openmp_/geo_yeefdtd_rect.kernel_inc.h openmp_/geo_yeefdtd.kernel_inc.h openmp_/geo_particle_iter_mass.kernel_inc.h openmp_/geo_particle_iter.kernel_inc.h openmp_/rel_particle_iter.kernel_inc.h openmp_yeefdtd.h space_filling_curve.h pubdefs.h init_adjoint_relation.h init_field3d_mpi.h mpifields.h cfgcst.h genrand.h 
	$(CC) $(CPPFLAG) -E init_field3d_mpi.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>init_field3d_mpimid.c
	$(CC) -c init_field3d_mpimid.c $(CFLAG) -g -o init_field3d_mpi.o


genrand.o: genrand.c 
	$(CC) $(CPPFLAG) -E genrand.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>genrandmid.c
	$(CC) -c genrandmid.c $(CFLAG) -g -o genrand.o


init_particle.o: init_particle.c libsmallmpi.h local_header.h genrand.h pubdefs.h cfgcst.h init_field3d_mpi.h sync_fields.h c_/c_pscmc_inc.h openmp_/openmp_pscmc_inc.h c_/yeefdtd.kernel_inc.h c_/mergefields.kernel_inc.h c_/miniblas.kernel_inc.h c_/general_partial_sort.kernel_inc.h c_/move_back.kernel_inc.h c_/particle_iter.kernel_inc.h c_/mur_abc.kernel_inc.h c_/dm.kernel_inc.h c_/geo_yeefdtd_rect.kernel_inc.h c_/geo_yeefdtd.kernel_inc.h c_/geo_particle_iter_mass.kernel_inc.h c_/geo_particle_iter.kernel_inc.h c_/rel_particle_iter.kernel_inc.h c_yeefdtd.h openmp_/yeefdtd.kernel_inc.h openmp_/mergefields.kernel_inc.h openmp_/miniblas.kernel_inc.h openmp_/general_partial_sort.kernel_inc.h openmp_/move_back.kernel_inc.h openmp_/particle_iter.kernel_inc.h openmp_/mur_abc.kernel_inc.h openmp_/dm.kernel_inc.h openmp_/geo_yeefdtd_rect.kernel_inc.h openmp_/geo_yeefdtd.kernel_inc.h openmp_/geo_particle_iter_mass.kernel_inc.h openmp_/geo_particle_iter.kernel_inc.h openmp_/rel_particle_iter.kernel_inc.h openmp_yeefdtd.h 
	$(CC) $(CPPFLAG) -E init_particle.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>init_particlemid.c
	$(CC) -c init_particlemid.c $(CFLAG) -g -o init_particle.o


sort_particle.o: sort_particle.c libsmallmpi.h local_header.h c_/c_pscmc_inc.h openmp_/openmp_pscmc_inc.h c_/yeefdtd.kernel_inc.h c_/mergefields.kernel_inc.h c_/miniblas.kernel_inc.h c_/general_partial_sort.kernel_inc.h c_/move_back.kernel_inc.h c_/particle_iter.kernel_inc.h c_/mur_abc.kernel_inc.h c_/dm.kernel_inc.h c_/geo_yeefdtd_rect.kernel_inc.h c_/geo_yeefdtd.kernel_inc.h c_/geo_particle_iter_mass.kernel_inc.h c_/geo_particle_iter.kernel_inc.h c_/rel_particle_iter.kernel_inc.h c_yeefdtd.h openmp_/yeefdtd.kernel_inc.h openmp_/mergefields.kernel_inc.h openmp_/miniblas.kernel_inc.h openmp_/general_partial_sort.kernel_inc.h openmp_/move_back.kernel_inc.h openmp_/particle_iter.kernel_inc.h openmp_/mur_abc.kernel_inc.h openmp_/dm.kernel_inc.h openmp_/geo_yeefdtd_rect.kernel_inc.h openmp_/geo_yeefdtd.kernel_inc.h openmp_/geo_particle_iter_mass.kernel_inc.h openmp_/geo_particle_iter.kernel_inc.h openmp_/rel_particle_iter.kernel_inc.h openmp_yeefdtd.h 
	$(CC) $(CPPFLAG) -E sort_particle.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>sort_particlemid.c
	$(CC) -c sort_particlemid.c $(CFLAG) -g -o sort_particle.o


checkpoint.o: checkpoint.c libsmallmpi.h local_header.h c_/c_pscmc_inc.h openmp_/openmp_pscmc_inc.h c_/yeefdtd.kernel_inc.h c_/mergefields.kernel_inc.h c_/miniblas.kernel_inc.h c_/general_partial_sort.kernel_inc.h c_/move_back.kernel_inc.h c_/particle_iter.kernel_inc.h c_/mur_abc.kernel_inc.h c_/dm.kernel_inc.h c_/geo_yeefdtd_rect.kernel_inc.h c_/geo_yeefdtd.kernel_inc.h c_/geo_particle_iter_mass.kernel_inc.h c_/geo_particle_iter.kernel_inc.h c_/rel_particle_iter.kernel_inc.h c_yeefdtd.h openmp_/yeefdtd.kernel_inc.h openmp_/mergefields.kernel_inc.h openmp_/miniblas.kernel_inc.h openmp_/general_partial_sort.kernel_inc.h openmp_/move_back.kernel_inc.h openmp_/particle_iter.kernel_inc.h openmp_/mur_abc.kernel_inc.h openmp_/dm.kernel_inc.h openmp_/geo_yeefdtd_rect.kernel_inc.h openmp_/geo_yeefdtd.kernel_inc.h openmp_/geo_particle_iter_mass.kernel_inc.h openmp_/geo_particle_iter.kernel_inc.h openmp_/rel_particle_iter.kernel_inc.h openmp_yeefdtd.h space_filling_curve.h pubdefs.h mpifields.h init_field3d_mpi.h mpi_fieldio.h call_curl_kernel.h init_particle.h sort_particle.h init_adjoint_relation.h split_shell.h cfgcst.h checkpoint.h 
	$(CC) $(CPPFLAG) -E checkpoint.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>checkpointmid.c
	$(CC) -c checkpointmid.c $(CFLAG) -g -o checkpoint.o


run_particle.o: run_particle.c libsmallmpi.h local_header.h c_/c_pscmc_inc.h openmp_/openmp_pscmc_inc.h c_/yeefdtd.kernel_inc.h c_/mergefields.kernel_inc.h c_/miniblas.kernel_inc.h c_/general_partial_sort.kernel_inc.h c_/move_back.kernel_inc.h c_/particle_iter.kernel_inc.h c_/mur_abc.kernel_inc.h c_/dm.kernel_inc.h c_/geo_yeefdtd_rect.kernel_inc.h c_/geo_yeefdtd.kernel_inc.h c_/geo_particle_iter_mass.kernel_inc.h c_/geo_particle_iter.kernel_inc.h c_/rel_particle_iter.kernel_inc.h c_yeefdtd.h openmp_/yeefdtd.kernel_inc.h openmp_/mergefields.kernel_inc.h openmp_/miniblas.kernel_inc.h openmp_/general_partial_sort.kernel_inc.h openmp_/move_back.kernel_inc.h openmp_/particle_iter.kernel_inc.h openmp_/mur_abc.kernel_inc.h openmp_/dm.kernel_inc.h openmp_/geo_yeefdtd_rect.kernel_inc.h openmp_/geo_yeefdtd.kernel_inc.h openmp_/geo_particle_iter_mass.kernel_inc.h openmp_/geo_particle_iter.kernel_inc.h openmp_/rel_particle_iter.kernel_inc.h openmp_yeefdtd.h blas_shell.h pubdefs.h mpi_fieldio.h cfgcst.h call_curl_kernel.h run_particle.h sync_fields.h 
	$(CC) $(CPPFLAG) -E run_particle.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>run_particlemid.c
	$(CC) -c run_particlemid.c $(CFLAG) -g -o run_particle.o


pass_xyzzyx.o: pass_xyzzyx.c cfgcst.h libsmallmpi.h local_header.h blas_shell.h pubdefs.h mpi_fieldio.h run_particle.h sync_fields.h 
	$(CC) $(CPPFLAG) -E pass_xyzzyx.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>pass_xyzzyxmid.c
	$(CC) -c pass_xyzzyxmid.c $(CFLAG) -g -o pass_xyzzyx.o


mpifields.o: mpifields.c libsmallmpi.h local_header.h c_/c_pscmc_inc.h openmp_/openmp_pscmc_inc.h c_/yeefdtd.kernel_inc.h c_/mergefields.kernel_inc.h c_/miniblas.kernel_inc.h c_/general_partial_sort.kernel_inc.h c_/move_back.kernel_inc.h c_/particle_iter.kernel_inc.h c_/mur_abc.kernel_inc.h c_/dm.kernel_inc.h c_/geo_yeefdtd_rect.kernel_inc.h c_/geo_yeefdtd.kernel_inc.h c_/geo_particle_iter_mass.kernel_inc.h c_/geo_particle_iter.kernel_inc.h c_/rel_particle_iter.kernel_inc.h c_yeefdtd.h openmp_/yeefdtd.kernel_inc.h openmp_/mergefields.kernel_inc.h openmp_/miniblas.kernel_inc.h openmp_/general_partial_sort.kernel_inc.h openmp_/move_back.kernel_inc.h openmp_/particle_iter.kernel_inc.h openmp_/mur_abc.kernel_inc.h openmp_/dm.kernel_inc.h openmp_/geo_yeefdtd_rect.kernel_inc.h openmp_/geo_yeefdtd.kernel_inc.h openmp_/geo_particle_iter_mass.kernel_inc.h openmp_/geo_particle_iter.kernel_inc.h openmp_/rel_particle_iter.kernel_inc.h openmp_yeefdtd.h space_filling_curve.h pubdefs.h mpifields.h 
	$(CC) $(CPPFLAG) -E mpifields.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>mpifieldsmid.c
	$(CC) -c mpifieldsmid.c $(CFLAG) -g -o mpifields.o


call_curl_kernel.o: call_curl_kernel.c libsmallmpi.h local_header.h c_/c_pscmc_inc.h openmp_/openmp_pscmc_inc.h c_/yeefdtd.kernel_inc.h c_/mergefields.kernel_inc.h c_/miniblas.kernel_inc.h c_/general_partial_sort.kernel_inc.h c_/move_back.kernel_inc.h c_/particle_iter.kernel_inc.h c_/mur_abc.kernel_inc.h c_/dm.kernel_inc.h c_/geo_yeefdtd_rect.kernel_inc.h c_/geo_yeefdtd.kernel_inc.h c_/geo_particle_iter_mass.kernel_inc.h c_/geo_particle_iter.kernel_inc.h c_/rel_particle_iter.kernel_inc.h c_yeefdtd.h openmp_/yeefdtd.kernel_inc.h openmp_/mergefields.kernel_inc.h openmp_/miniblas.kernel_inc.h openmp_/general_partial_sort.kernel_inc.h openmp_/move_back.kernel_inc.h openmp_/particle_iter.kernel_inc.h openmp_/mur_abc.kernel_inc.h openmp_/dm.kernel_inc.h openmp_/geo_yeefdtd_rect.kernel_inc.h openmp_/geo_yeefdtd.kernel_inc.h openmp_/geo_particle_iter_mass.kernel_inc.h openmp_/geo_particle_iter.kernel_inc.h openmp_/rel_particle_iter.kernel_inc.h openmp_yeefdtd.h space_filling_curve.h pubdefs.h mpifields.h 
	$(CC) $(CPPFLAG) -E call_curl_kernel.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>call_curl_kernelmid.c
	$(CC) -c call_curl_kernelmid.c $(CFLAG) -g -o call_curl_kernel.o


blas_shell.o: blas_shell.c libsmallmpi.h local_header.h c_/c_pscmc_inc.h openmp_/openmp_pscmc_inc.h c_/yeefdtd.kernel_inc.h c_/mergefields.kernel_inc.h c_/miniblas.kernel_inc.h c_/general_partial_sort.kernel_inc.h c_/move_back.kernel_inc.h c_/particle_iter.kernel_inc.h c_/mur_abc.kernel_inc.h c_/dm.kernel_inc.h c_/geo_yeefdtd_rect.kernel_inc.h c_/geo_yeefdtd.kernel_inc.h c_/geo_particle_iter_mass.kernel_inc.h c_/geo_particle_iter.kernel_inc.h c_/rel_particle_iter.kernel_inc.h c_yeefdtd.h openmp_/yeefdtd.kernel_inc.h openmp_/mergefields.kernel_inc.h openmp_/miniblas.kernel_inc.h openmp_/general_partial_sort.kernel_inc.h openmp_/move_back.kernel_inc.h openmp_/particle_iter.kernel_inc.h openmp_/mur_abc.kernel_inc.h openmp_/dm.kernel_inc.h openmp_/geo_yeefdtd_rect.kernel_inc.h openmp_/geo_yeefdtd.kernel_inc.h openmp_/geo_particle_iter_mass.kernel_inc.h openmp_/geo_particle_iter.kernel_inc.h openmp_/rel_particle_iter.kernel_inc.h openmp_yeefdtd.h space_filling_curve.h pubdefs.h mpifields.h 
	$(CC) $(CPPFLAG) -E blas_shell.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>blas_shellmid.c
	$(CC) -c blas_shellmid.c $(CFLAG) -g -o blas_shell.o


field_sync_h2d_d2h.o: field_sync_h2d_d2h.c libsmallmpi.h local_header.h 
	$(CC) $(CPPFLAG) -E field_sync_h2d_d2h.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>field_sync_h2d_d2hmid.c
	$(CC) -c field_sync_h2d_d2hmid.c $(CFLAG) -g -o field_sync_h2d_d2h.o


sync_fields.o: sync_fields.c libsmallmpi.h local_header.h c_/c_pscmc_inc.h openmp_/openmp_pscmc_inc.h c_/yeefdtd.kernel_inc.h c_/mergefields.kernel_inc.h c_/miniblas.kernel_inc.h c_/general_partial_sort.kernel_inc.h c_/move_back.kernel_inc.h c_/particle_iter.kernel_inc.h c_/mur_abc.kernel_inc.h c_/dm.kernel_inc.h c_/geo_yeefdtd_rect.kernel_inc.h c_/geo_yeefdtd.kernel_inc.h c_/geo_particle_iter_mass.kernel_inc.h c_/geo_particle_iter.kernel_inc.h c_/rel_particle_iter.kernel_inc.h c_yeefdtd.h openmp_/yeefdtd.kernel_inc.h openmp_/mergefields.kernel_inc.h openmp_/miniblas.kernel_inc.h openmp_/general_partial_sort.kernel_inc.h openmp_/move_back.kernel_inc.h openmp_/particle_iter.kernel_inc.h openmp_/mur_abc.kernel_inc.h openmp_/dm.kernel_inc.h openmp_/geo_yeefdtd_rect.kernel_inc.h openmp_/geo_yeefdtd.kernel_inc.h openmp_/geo_particle_iter_mass.kernel_inc.h openmp_/geo_particle_iter.kernel_inc.h openmp_/rel_particle_iter.kernel_inc.h openmp_yeefdtd.h mpifields.h pubdefs.h 
	$(CC) $(CPPFLAG) -E sync_fields.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>sync_fieldsmid.c
	$(CC) -c sync_fieldsmid.c $(CFLAG) -g -o sync_fields.o


smalllib.o: smalllib.c libsmallmpi.h local_header.h 
	$(CC) $(CPPFLAG) -E smalllib.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>smalllibmid.c
	$(CC) -c smalllibmid.c $(CFLAG) -g -o smalllib.o


mpi_fieldio.o: mpi_fieldio.c libsmallmpi.h local_header.h c_/c_pscmc_inc.h openmp_/openmp_pscmc_inc.h c_/yeefdtd.kernel_inc.h c_/mergefields.kernel_inc.h c_/miniblas.kernel_inc.h c_/general_partial_sort.kernel_inc.h c_/move_back.kernel_inc.h c_/particle_iter.kernel_inc.h c_/mur_abc.kernel_inc.h c_/dm.kernel_inc.h c_/geo_yeefdtd_rect.kernel_inc.h c_/geo_yeefdtd.kernel_inc.h c_/geo_particle_iter_mass.kernel_inc.h c_/geo_particle_iter.kernel_inc.h c_/rel_particle_iter.kernel_inc.h c_yeefdtd.h openmp_/yeefdtd.kernel_inc.h openmp_/mergefields.kernel_inc.h openmp_/miniblas.kernel_inc.h openmp_/general_partial_sort.kernel_inc.h openmp_/move_back.kernel_inc.h openmp_/particle_iter.kernel_inc.h openmp_/mur_abc.kernel_inc.h openmp_/dm.kernel_inc.h openmp_/geo_yeefdtd_rect.kernel_inc.h openmp_/geo_yeefdtd.kernel_inc.h openmp_/geo_particle_iter_mass.kernel_inc.h openmp_/geo_particle_iter.kernel_inc.h openmp_/rel_particle_iter.kernel_inc.h openmp_yeefdtd.h space_filling_curve.h pubdefs.h 
	$(CC) $(CPPFLAG) -E mpi_fieldio.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>mpi_fieldiomid.c
	$(CC) -c mpi_fieldiomid.c $(CFLAG) -g -o mpi_fieldio.o


seqfields.o: seqfields.c libsmallmpi.h local_header.h c_/c_pscmc_inc.h openmp_/openmp_pscmc_inc.h c_/yeefdtd.kernel_inc.h c_/mergefields.kernel_inc.h c_/miniblas.kernel_inc.h c_/general_partial_sort.kernel_inc.h c_/move_back.kernel_inc.h c_/particle_iter.kernel_inc.h c_/mur_abc.kernel_inc.h c_/dm.kernel_inc.h c_/geo_yeefdtd_rect.kernel_inc.h c_/geo_yeefdtd.kernel_inc.h c_/geo_particle_iter_mass.kernel_inc.h c_/geo_particle_iter.kernel_inc.h c_/rel_particle_iter.kernel_inc.h c_yeefdtd.h openmp_/yeefdtd.kernel_inc.h openmp_/mergefields.kernel_inc.h openmp_/miniblas.kernel_inc.h openmp_/general_partial_sort.kernel_inc.h openmp_/move_back.kernel_inc.h openmp_/particle_iter.kernel_inc.h openmp_/mur_abc.kernel_inc.h openmp_/dm.kernel_inc.h openmp_/geo_yeefdtd_rect.kernel_inc.h openmp_/geo_yeefdtd.kernel_inc.h openmp_/geo_particle_iter_mass.kernel_inc.h openmp_/geo_particle_iter.kernel_inc.h openmp_/rel_particle_iter.kernel_inc.h openmp_yeefdtd.h seqfields.h pubdefs.h 
	$(CC) $(CPPFLAG) -E seqfields.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>seqfieldsmid.c
	$(CC) -c seqfieldsmid.c $(CFLAG) -g -o seqfields.o


main.o: main.c libsmallmpi.h local_header.h c_/c_pscmc_inc.h openmp_/openmp_pscmc_inc.h c_/yeefdtd.kernel_inc.h c_/mergefields.kernel_inc.h c_/miniblas.kernel_inc.h c_/general_partial_sort.kernel_inc.h c_/move_back.kernel_inc.h c_/particle_iter.kernel_inc.h c_/mur_abc.kernel_inc.h c_/dm.kernel_inc.h c_/geo_yeefdtd_rect.kernel_inc.h c_/geo_yeefdtd.kernel_inc.h c_/geo_particle_iter_mass.kernel_inc.h c_/geo_particle_iter.kernel_inc.h c_/rel_particle_iter.kernel_inc.h c_yeefdtd.h openmp_/yeefdtd.kernel_inc.h openmp_/mergefields.kernel_inc.h openmp_/miniblas.kernel_inc.h openmp_/general_partial_sort.kernel_inc.h openmp_/move_back.kernel_inc.h openmp_/particle_iter.kernel_inc.h openmp_/mur_abc.kernel_inc.h openmp_/dm.kernel_inc.h openmp_/geo_yeefdtd_rect.kernel_inc.h openmp_/geo_yeefdtd.kernel_inc.h openmp_/geo_particle_iter_mass.kernel_inc.h openmp_/geo_particle_iter.kernel_inc.h openmp_/rel_particle_iter.kernel_inc.h openmp_yeefdtd.h space_filling_curve.h pubdefs.h mpifields.h init_field3d_mpi.h mpi_fieldio.h call_curl_kernel.h init_particle.h run_particle.h pass_xyzzyx.h sort_particle.h seqfields.h init_adjoint_relation.h split_shell.h blas_shell.h cfgcst.h checkpoint.h 
	$(CC) $(CPPFLAG) -E main.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>mainmid.c
	$(CC) -c mainmid.c $(CFLAG) -g -o main.o
.PHONY:clean
clean	:
	-rm $(LOCALPROG) $(sources)  space_filling_curve.c space_filling_curve.c.def.ss space_filling_curvemid.c init_adjoint_relation.c init_adjoint_relation.c.def.ss init_adjoint_relationmid.c split_shell.c split_shell.c.def.ss split_shellmid.c init_field3d_mpi.c init_field3d_mpi.c.def.ss init_field3d_mpimid.c genrand.c genrand.c.def.ss genrandmid.c init_particle.c init_particle.c.def.ss init_particlemid.c sort_particle.c sort_particle.c.def.ss sort_particlemid.c checkpoint.c checkpoint.c.def.ss checkpointmid.c run_particle.c run_particle.c.def.ss run_particlemid.c pass_xyzzyx.c pass_xyzzyx.c.def.ss pass_xyzzyxmid.c mpifields.c mpifields.c.def.ss mpifieldsmid.c call_curl_kernel.c call_curl_kernel.c.def.ss call_curl_kernelmid.c blas_shell.c blas_shell.c.def.ss blas_shellmid.c field_sync_h2d_d2h.c field_sync_h2d_d2h.c.def.ss field_sync_h2d_d2hmid.c sync_fields.c sync_fields.c.def.ss sync_fieldsmid.c smalllib.c smalllib.c.def.ss smalllibmid.c mpi_fieldio.c mpi_fieldio.c.def.ss mpi_fieldiomid.c seqfields.c seqfields.c.def.ss seqfieldsmid.c main.c main.c.def.ss mainmid.c
