export CPATH=$CPATH:`pwd`:`pwd`/cgapsio/
export LIBRARY_PATH=$LIBRARY_PATH:`pwd`:`pwd`/cgapsio/
for dirs in cgapsio smallmpi c_ openmp_
do
	(cd $dirs ;make -j8;)
done
make -j8
