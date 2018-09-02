all	:sympic
smallmpi	:
	$(MAKE) -C $@
cgapsio	:
	$(MAKE) -C $@
libsmallmpi.a	:smallmpi
cgapsio/libcgapsio.a	:cgapsio
sympic	:cgapsio/libcgapsio.a libsmallmpi.a cfgcst.c libcscheme.a  c_yeefdtd.a
	mpicc -fopenmp -O2 -lm -o sympic libsympic.a libsmallmpi.a cfgcst.c libcscheme.a  c_yeefdtd.a cgapsio/libcgapsio.a
.PHONY	:all smallmpi cgapsio
