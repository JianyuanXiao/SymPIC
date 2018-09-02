CC=mpicc
CFLAGS=-O2 -I./
all: libcgapsio.a gapsio1to0
gapsio1to0:	libcgapsio.a main.o
	$(CC) $(CFLAGS) -o gapsio1to0 main.o libcgapsio.a
libcgapsio.a:	c_gapsio.o
	$(AR) rcs libcgapsio.a c_gapsio.o
c_gapsio.o:	c_gapsio.c
	$(CC) $(CFLAGS) -c c_gapsio.c
main.o:	main.c
	$(CC) $(CFLAGS) -c main.c
