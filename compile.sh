export CPATH=$CPATH:`pwd`:`pwd`/cgapsio
export LIBRARY_PATH=$LIBRARY_PATH:`pwd`
for dirs in smallmpi c_ openmp_
do
	(cd $dirs ;make -j8;)
done
make -j8
