CC=mpicc
SCC=scc


NVCC=nvcc
BRCC=
CXX=mpicc
CFLAG= -O3 -ffast-math
CPPFLAG=
NVCCF=
CXXFLAG= -lm -O2 -I../common/
SWMSCC=sw5cc
SWMSCCFLAG=-slave -ffast-math -O3
SWMHCC=sw5cc
SWMHCCFLAG=-host
LOCALPROG=comp
sources= small_mpi.o main.o
ASLIB=../libsmallmpi.a
SHAREDLIB=
sources_a=small_mpi.o main.o
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


small_mpi.o: small_mpi.c 
	$(CC) $(CPPFLAG) -E small_mpi.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>small_mpimid.c
	$(CC) -c small_mpimid.c $(CFLAG) -g -o small_mpi.o
main.o: main.c 
	$(CC) $(CPPFLAG) -E main.c |sed '/^\# /d' |sed '/^\ \{0,\}$$/d'>mainmid.c
	$(CC) -c mainmid.c $(CFLAG) -g -o main.o
.PHONY:clean
clean	:
	-rm $(LOCALPROG) $(sources)  small_mpi.c small_mpi.c.def.ss small_mpimid.c mainmid.c
