CC=mpicc
SCC=scc


NVCC=nvcc
BRCC=
CXX=mpicc
CFLAG= -O3 -ffast-math -march=skylake
CPPFLAG=
NVCCF=
CXXFLAG= -lm -O2 -I../common/
SWMSCC=sw5cc
SWMSCCFLAG=-ffast-math -O3
SWMHCC=sw5cc
SWMHCCFLAG=
LOCALPROG=comp
sources= hydro_A.kernel.o hydro_A.kernel_runtime.o implicit_particle_mover.kernel.o implicit_particle_mover.kernel_runtime.o type3_georel.kernel.o type3_georel.kernel_runtime.o inner_split_pass.kernel.o inner_split_pass.kernel_runtime.o geo_particle_iter_mass.kernel.o geo_particle_iter_mass.kernel_runtime.o geo_particle_iter.kernel.o geo_particle_iter.kernel_runtime.o rel_particle_iter.kernel.o rel_particle_iter.kernel_runtime.o yeefdtd.kernel.o yeefdtd.kernel_runtime.o mergefields.kernel.o mergefields.kernel_runtime.o miniblas.kernel.o miniblas.kernel_runtime.o general_partial_sort.kernel.o general_partial_sort.kernel_runtime.o move_back.kernel.o move_back.kernel_runtime.o particle_iter.kernel.o particle_iter.kernel_runtime.o mur_abc.kernel.o mur_abc.kernel_runtime.o dmbihamt.kernel.o dmbihamt.kernel_runtime.o dm.kernel.o dm.kernel_runtime.o geo_yeefdtd_rect.kernel.o geo_yeefdtd_rect.kernel_runtime.o geo_yeefdtd.kernel.o geo_yeefdtd.kernel_runtime.o c_pscmc.o main.o
ASLIB=../c_yeefdtd.a
SHAREDLIB=
sources_a=hydro_A.kernel.o hydro_A.kernel_runtime.o implicit_particle_mover.kernel.o implicit_particle_mover.kernel_runtime.o type3_georel.kernel.o type3_georel.kernel_runtime.o inner_split_pass.kernel.o inner_split_pass.kernel_runtime.o geo_particle_iter_mass.kernel.o geo_particle_iter_mass.kernel_runtime.o geo_particle_iter.kernel.o geo_particle_iter.kernel_runtime.o rel_particle_iter.kernel.o rel_particle_iter.kernel_runtime.o yeefdtd.kernel.o yeefdtd.kernel_runtime.o mergefields.kernel.o mergefields.kernel_runtime.o miniblas.kernel.o miniblas.kernel_runtime.o general_partial_sort.kernel.o general_partial_sort.kernel_runtime.o move_back.kernel.o move_back.kernel_runtime.o particle_iter.kernel.o particle_iter.kernel_runtime.o mur_abc.kernel.o mur_abc.kernel_runtime.o dmbihamt.kernel.o dmbihamt.kernel_runtime.o dm.kernel.o dm.kernel_runtime.o geo_yeefdtd_rect.kernel.o geo_yeefdtd_rect.kernel_runtime.o geo_yeefdtd.kernel.o geo_yeefdtd.kernel_runtime.o c_pscmc.o
sources_h=$(sources_a:.o=.h)
ARFLAG=rcs
ASHEADER=$(ASLIB:.a=.h)
all	:$(LOCALPROG) $(ASLIB) $(ASHEADER) $(SHAREDLIB)
$(ASLIB)	:$(sources_a)
	$(AR)	$(ARFLAG) $(ASLIB) $(sources_a)
$(SHAREDLIB)	:$(sources_a)
	$(CXX)	-shared -o $(SHAREDLIB) $(sources_a)
$(ASHEADER)	:$(sources_h)
	cat $(sources_h) > $(ASHEADER)
$(LOCALPROG)	:$(sources)
	$(CXX)   $(sources) -o $(LOCALPROG) $(CXXFLAG)




hydro_A.kernel_inc.h:	hydro_A.kernel.c
	touch hydro_A.kernel_inc.h
hydro_A.kernel.o: hydro_A.kernel.c 
	$(CC) -c hydro_A.kernel.c $(CFLAG) -g -o hydro_A.kernel.o


hydro_A.kernel_runtime.o: hydro_A.kernel_runtime.c local_header.h c_pscmc_inc.h hydro_A.kernel_inc.h 
	$(CC) $(CPPFLAG) -E hydro_A.kernel_runtime.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>hydro_A.kernel_runtimemid.c
	$(CC) -c hydro_A.kernel_runtimemid.c $(CFLAG) -g -o hydro_A.kernel_runtime.o




implicit_particle_mover.kernel_inc.h:	implicit_particle_mover.kernel.c
	touch implicit_particle_mover.kernel_inc.h
implicit_particle_mover.kernel.o: implicit_particle_mover.kernel.c 
	$(CC) -c implicit_particle_mover.kernel.c $(CFLAG) -g -o implicit_particle_mover.kernel.o


implicit_particle_mover.kernel_runtime.o: implicit_particle_mover.kernel_runtime.c local_header.h c_pscmc_inc.h implicit_particle_mover.kernel_inc.h 
	$(CC) $(CPPFLAG) -E implicit_particle_mover.kernel_runtime.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>implicit_particle_mover.kernel_runtimemid.c
	$(CC) -c implicit_particle_mover.kernel_runtimemid.c $(CFLAG) -g -o implicit_particle_mover.kernel_runtime.o




type3_georel.kernel_inc.h:	type3_georel.kernel.c
	touch type3_georel.kernel_inc.h
type3_georel.kernel.o: type3_georel.kernel.c 
	$(CC) -c type3_georel.kernel.c $(CFLAG) -g -o type3_georel.kernel.o


type3_georel.kernel_runtime.o: type3_georel.kernel_runtime.c local_header.h c_pscmc_inc.h type3_georel.kernel_inc.h 
	$(CC) $(CPPFLAG) -E type3_georel.kernel_runtime.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>type3_georel.kernel_runtimemid.c
	$(CC) -c type3_georel.kernel_runtimemid.c $(CFLAG) -g -o type3_georel.kernel_runtime.o




inner_split_pass.kernel_inc.h:	inner_split_pass.kernel.c
	touch inner_split_pass.kernel_inc.h
inner_split_pass.kernel.o: inner_split_pass.kernel.c 
	$(CC) -c inner_split_pass.kernel.c $(CFLAG) -g -o inner_split_pass.kernel.o


inner_split_pass.kernel_runtime.o: inner_split_pass.kernel_runtime.c local_header.h c_pscmc_inc.h inner_split_pass.kernel_inc.h 
	$(CC) $(CPPFLAG) -E inner_split_pass.kernel_runtime.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>inner_split_pass.kernel_runtimemid.c
	$(CC) -c inner_split_pass.kernel_runtimemid.c $(CFLAG) -g -o inner_split_pass.kernel_runtime.o




geo_particle_iter_mass.kernel_inc.h:	geo_particle_iter_mass.kernel.c
	touch geo_particle_iter_mass.kernel_inc.h
geo_particle_iter_mass.kernel.o: geo_particle_iter_mass.kernel.c 
	$(CC) -c geo_particle_iter_mass.kernel.c $(CFLAG) -g -o geo_particle_iter_mass.kernel.o


geo_particle_iter_mass.kernel_runtime.o: geo_particle_iter_mass.kernel_runtime.c local_header.h c_pscmc_inc.h geo_particle_iter_mass.kernel_inc.h 
	$(CC) $(CPPFLAG) -E geo_particle_iter_mass.kernel_runtime.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>geo_particle_iter_mass.kernel_runtimemid.c
	$(CC) -c geo_particle_iter_mass.kernel_runtimemid.c $(CFLAG) -g -o geo_particle_iter_mass.kernel_runtime.o




geo_particle_iter.kernel_inc.h:	geo_particle_iter.kernel.c
	touch geo_particle_iter.kernel_inc.h
geo_particle_iter.kernel.o: geo_particle_iter.kernel.c 
	$(CC) -c geo_particle_iter.kernel.c $(CFLAG) -g -o geo_particle_iter.kernel.o


geo_particle_iter.kernel_runtime.o: geo_particle_iter.kernel_runtime.c local_header.h c_pscmc_inc.h geo_particle_iter.kernel_inc.h 
	$(CC) $(CPPFLAG) -E geo_particle_iter.kernel_runtime.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>geo_particle_iter.kernel_runtimemid.c
	$(CC) -c geo_particle_iter.kernel_runtimemid.c $(CFLAG) -g -o geo_particle_iter.kernel_runtime.o




rel_particle_iter.kernel_inc.h:	rel_particle_iter.kernel.c
	touch rel_particle_iter.kernel_inc.h
rel_particle_iter.kernel.o: rel_particle_iter.kernel.c 
	$(CC) -c rel_particle_iter.kernel.c $(CFLAG) -g -o rel_particle_iter.kernel.o


rel_particle_iter.kernel_runtime.o: rel_particle_iter.kernel_runtime.c local_header.h c_pscmc_inc.h rel_particle_iter.kernel_inc.h 
	$(CC) $(CPPFLAG) -E rel_particle_iter.kernel_runtime.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>rel_particle_iter.kernel_runtimemid.c
	$(CC) -c rel_particle_iter.kernel_runtimemid.c $(CFLAG) -g -o rel_particle_iter.kernel_runtime.o




yeefdtd.kernel_inc.h:	yeefdtd.kernel.c
	touch yeefdtd.kernel_inc.h
yeefdtd.kernel.o: yeefdtd.kernel.c 
	$(CC) -c yeefdtd.kernel.c $(CFLAG) -g -o yeefdtd.kernel.o


yeefdtd.kernel_runtime.o: yeefdtd.kernel_runtime.c local_header.h c_pscmc_inc.h yeefdtd.kernel_inc.h 
	$(CC) $(CPPFLAG) -E yeefdtd.kernel_runtime.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>yeefdtd.kernel_runtimemid.c
	$(CC) -c yeefdtd.kernel_runtimemid.c $(CFLAG) -g -o yeefdtd.kernel_runtime.o




mergefields.kernel_inc.h:	mergefields.kernel.c
	touch mergefields.kernel_inc.h
mergefields.kernel.o: mergefields.kernel.c 
	$(CC) -c mergefields.kernel.c $(CFLAG) -g -o mergefields.kernel.o


mergefields.kernel_runtime.o: mergefields.kernel_runtime.c local_header.h c_pscmc_inc.h mergefields.kernel_inc.h 
	$(CC) $(CPPFLAG) -E mergefields.kernel_runtime.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>mergefields.kernel_runtimemid.c
	$(CC) -c mergefields.kernel_runtimemid.c $(CFLAG) -g -o mergefields.kernel_runtime.o




miniblas.kernel_inc.h:	miniblas.kernel.c
	touch miniblas.kernel_inc.h
miniblas.kernel.o: miniblas.kernel.c 
	$(CC) -c miniblas.kernel.c $(CFLAG) -g -o miniblas.kernel.o


miniblas.kernel_runtime.o: miniblas.kernel_runtime.c local_header.h c_pscmc_inc.h miniblas.kernel_inc.h 
	$(CC) $(CPPFLAG) -E miniblas.kernel_runtime.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>miniblas.kernel_runtimemid.c
	$(CC) -c miniblas.kernel_runtimemid.c $(CFLAG) -g -o miniblas.kernel_runtime.o




general_partial_sort.kernel_inc.h:	general_partial_sort.kernel.c
	touch general_partial_sort.kernel_inc.h
general_partial_sort.kernel.o: general_partial_sort.kernel.c 
	$(CC) -c general_partial_sort.kernel.c $(CFLAG) -g -o general_partial_sort.kernel.o


general_partial_sort.kernel_runtime.o: general_partial_sort.kernel_runtime.c local_header.h c_pscmc_inc.h general_partial_sort.kernel_inc.h 
	$(CC) $(CPPFLAG) -E general_partial_sort.kernel_runtime.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>general_partial_sort.kernel_runtimemid.c
	$(CC) -c general_partial_sort.kernel_runtimemid.c $(CFLAG) -g -o general_partial_sort.kernel_runtime.o




move_back.kernel_inc.h:	move_back.kernel.c
	touch move_back.kernel_inc.h
move_back.kernel.o: move_back.kernel.c 
	$(CC) -c move_back.kernel.c $(CFLAG) -g -o move_back.kernel.o


move_back.kernel_runtime.o: move_back.kernel_runtime.c local_header.h c_pscmc_inc.h move_back.kernel_inc.h 
	$(CC) $(CPPFLAG) -E move_back.kernel_runtime.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>move_back.kernel_runtimemid.c
	$(CC) -c move_back.kernel_runtimemid.c $(CFLAG) -g -o move_back.kernel_runtime.o




particle_iter.kernel_inc.h:	particle_iter.kernel.c
	touch particle_iter.kernel_inc.h
particle_iter.kernel.o: particle_iter.kernel.c 
	$(CC) -c particle_iter.kernel.c $(CFLAG) -g -o particle_iter.kernel.o


particle_iter.kernel_runtime.o: particle_iter.kernel_runtime.c local_header.h c_pscmc_inc.h particle_iter.kernel_inc.h 
	$(CC) $(CPPFLAG) -E particle_iter.kernel_runtime.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>particle_iter.kernel_runtimemid.c
	$(CC) -c particle_iter.kernel_runtimemid.c $(CFLAG) -g -o particle_iter.kernel_runtime.o




mur_abc.kernel_inc.h:	mur_abc.kernel.c
	touch mur_abc.kernel_inc.h
mur_abc.kernel.o: mur_abc.kernel.c 
	$(CC) -c mur_abc.kernel.c $(CFLAG) -g -o mur_abc.kernel.o


mur_abc.kernel_runtime.o: mur_abc.kernel_runtime.c local_header.h c_pscmc_inc.h mur_abc.kernel_inc.h 
	$(CC) $(CPPFLAG) -E mur_abc.kernel_runtime.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>mur_abc.kernel_runtimemid.c
	$(CC) -c mur_abc.kernel_runtimemid.c $(CFLAG) -g -o mur_abc.kernel_runtime.o




dmbihamt.kernel_inc.h:	dmbihamt.kernel.c
	touch dmbihamt.kernel_inc.h
dmbihamt.kernel.o: dmbihamt.kernel.c 
	$(CC) -c dmbihamt.kernel.c $(CFLAG) -g -o dmbihamt.kernel.o


dmbihamt.kernel_runtime.o: dmbihamt.kernel_runtime.c local_header.h c_pscmc_inc.h dmbihamt.kernel_inc.h 
	$(CC) $(CPPFLAG) -E dmbihamt.kernel_runtime.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>dmbihamt.kernel_runtimemid.c
	$(CC) -c dmbihamt.kernel_runtimemid.c $(CFLAG) -g -o dmbihamt.kernel_runtime.o




dm.kernel_inc.h:	dm.kernel.c
	touch dm.kernel_inc.h
dm.kernel.o: dm.kernel.c 
	$(CC) -c dm.kernel.c $(CFLAG) -g -o dm.kernel.o


dm.kernel_runtime.o: dm.kernel_runtime.c local_header.h c_pscmc_inc.h dm.kernel_inc.h 
	$(CC) $(CPPFLAG) -E dm.kernel_runtime.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>dm.kernel_runtimemid.c
	$(CC) -c dm.kernel_runtimemid.c $(CFLAG) -g -o dm.kernel_runtime.o




geo_yeefdtd_rect.kernel_inc.h:	geo_yeefdtd_rect.kernel.c
	touch geo_yeefdtd_rect.kernel_inc.h
geo_yeefdtd_rect.kernel.o: geo_yeefdtd_rect.kernel.c 
	$(CC) -c geo_yeefdtd_rect.kernel.c $(CFLAG) -g -o geo_yeefdtd_rect.kernel.o


geo_yeefdtd_rect.kernel_runtime.o: geo_yeefdtd_rect.kernel_runtime.c local_header.h c_pscmc_inc.h geo_yeefdtd_rect.kernel_inc.h 
	$(CC) $(CPPFLAG) -E geo_yeefdtd_rect.kernel_runtime.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>geo_yeefdtd_rect.kernel_runtimemid.c
	$(CC) -c geo_yeefdtd_rect.kernel_runtimemid.c $(CFLAG) -g -o geo_yeefdtd_rect.kernel_runtime.o




geo_yeefdtd.kernel_inc.h:	geo_yeefdtd.kernel.c
	touch geo_yeefdtd.kernel_inc.h
geo_yeefdtd.kernel.o: geo_yeefdtd.kernel.c 
	$(CC) -c geo_yeefdtd.kernel.c $(CFLAG) -g -o geo_yeefdtd.kernel.o


geo_yeefdtd.kernel_runtime.o: geo_yeefdtd.kernel_runtime.c local_header.h c_pscmc_inc.h geo_yeefdtd.kernel_inc.h 
	$(CC) $(CPPFLAG) -E geo_yeefdtd.kernel_runtime.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>geo_yeefdtd.kernel_runtimemid.c
	$(CC) -c geo_yeefdtd.kernel_runtimemid.c $(CFLAG) -g -o geo_yeefdtd.kernel_runtime.o
c_pscmc.o: c_pscmc.c local_header.h 
	$(CC) $(CPPFLAG) -E c_pscmc.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>c_pscmcmid.c
	$(CC) -c c_pscmcmid.c $(CFLAG) -g -o c_pscmc.o
main.o: main.c 
	$(CC) $(CPPFLAG) -E main.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>mainmid.c
	$(CC) -c mainmid.c $(CFLAG) -g -o main.o
.PHONY:clean
clean	:
	-rm $(LOCALPROG) $(sources)  hydro_A.kernel.c hydro_A.kernel.c.def.ss hydro_A.kernel_runtime.scmc hydro_A.kernel_runtime.c hydro_A.kernel_runtime.c.def.ss hydro_A.kernel_runtimemid.c implicit_particle_mover.kernel.c implicit_particle_mover.kernel.c.def.ss implicit_particle_mover.kernel_runtime.scmc implicit_particle_mover.kernel_runtime.c implicit_particle_mover.kernel_runtime.c.def.ss implicit_particle_mover.kernel_runtimemid.c type3_georel.kernel.c type3_georel.kernel.c.def.ss type3_georel.kernel_runtime.scmc type3_georel.kernel_runtime.c type3_georel.kernel_runtime.c.def.ss type3_georel.kernel_runtimemid.c inner_split_pass.kernel.c inner_split_pass.kernel.c.def.ss inner_split_pass.kernel_runtime.scmc inner_split_pass.kernel_runtime.c inner_split_pass.kernel_runtime.c.def.ss inner_split_pass.kernel_runtimemid.c geo_particle_iter_mass.kernel.c geo_particle_iter_mass.kernel.c.def.ss geo_particle_iter_mass.kernel_runtime.scmc geo_particle_iter_mass.kernel_runtime.c geo_particle_iter_mass.kernel_runtime.c.def.ss geo_particle_iter_mass.kernel_runtimemid.c geo_particle_iter.kernel.c geo_particle_iter.kernel.c.def.ss geo_particle_iter.kernel_runtime.scmc geo_particle_iter.kernel_runtime.c geo_particle_iter.kernel_runtime.c.def.ss geo_particle_iter.kernel_runtimemid.c rel_particle_iter.kernel.c rel_particle_iter.kernel.c.def.ss rel_particle_iter.kernel_runtime.scmc rel_particle_iter.kernel_runtime.c rel_particle_iter.kernel_runtime.c.def.ss rel_particle_iter.kernel_runtimemid.c yeefdtd.kernel.c yeefdtd.kernel.c.def.ss yeefdtd.kernel_runtime.scmc yeefdtd.kernel_runtime.c yeefdtd.kernel_runtime.c.def.ss yeefdtd.kernel_runtimemid.c mergefields.kernel.c mergefields.kernel.c.def.ss mergefields.kernel_runtime.scmc mergefields.kernel_runtime.c mergefields.kernel_runtime.c.def.ss mergefields.kernel_runtimemid.c miniblas.kernel.c miniblas.kernel.c.def.ss miniblas.kernel_runtime.scmc miniblas.kernel_runtime.c miniblas.kernel_runtime.c.def.ss miniblas.kernel_runtimemid.c general_partial_sort.kernel.c general_partial_sort.kernel.c.def.ss general_partial_sort.kernel_runtime.scmc general_partial_sort.kernel_runtime.c general_partial_sort.kernel_runtime.c.def.ss general_partial_sort.kernel_runtimemid.c move_back.kernel.c move_back.kernel.c.def.ss move_back.kernel_runtime.scmc move_back.kernel_runtime.c move_back.kernel_runtime.c.def.ss move_back.kernel_runtimemid.c particle_iter.kernel.c particle_iter.kernel.c.def.ss particle_iter.kernel_runtime.scmc particle_iter.kernel_runtime.c particle_iter.kernel_runtime.c.def.ss particle_iter.kernel_runtimemid.c mur_abc.kernel.c mur_abc.kernel.c.def.ss mur_abc.kernel_runtime.scmc mur_abc.kernel_runtime.c mur_abc.kernel_runtime.c.def.ss mur_abc.kernel_runtimemid.c dmbihamt.kernel.c dmbihamt.kernel.c.def.ss dmbihamt.kernel_runtime.scmc dmbihamt.kernel_runtime.c dmbihamt.kernel_runtime.c.def.ss dmbihamt.kernel_runtimemid.c dm.kernel.c dm.kernel.c.def.ss dm.kernel_runtime.scmc dm.kernel_runtime.c dm.kernel_runtime.c.def.ss dm.kernel_runtimemid.c geo_yeefdtd_rect.kernel.c geo_yeefdtd_rect.kernel.c.def.ss geo_yeefdtd_rect.kernel_runtime.scmc geo_yeefdtd_rect.kernel_runtime.c geo_yeefdtd_rect.kernel_runtime.c.def.ss geo_yeefdtd_rect.kernel_runtimemid.c geo_yeefdtd.kernel.c geo_yeefdtd.kernel.c.def.ss geo_yeefdtd.kernel_runtime.scmc geo_yeefdtd.kernel_runtime.c geo_yeefdtd.kernel_runtime.c.def.ss geo_yeefdtd.kernel_runtimemid.c c_pscmcmid.c mainmid.c
