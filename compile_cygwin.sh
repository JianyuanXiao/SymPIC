export CPATH=$CPATH:`pwd`:`pwd`/cgapsio/
export LIBRARY_PATH=$LIBRARY_PATH:`pwd`:`pwd`/cgapsio/
for dirs in cgapsio smallmpi c_ openmp_
do
	(cd $dirs ;make -j8;)
done
make -j8
cp libcscheme-cygwin.a libcscheme.a
cp makefile_cygwin makefile
rm sympic
export OMPI_CC=clang
make
