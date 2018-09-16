export CPATH=$CPATH:`pwd`
for dirs in smallmpi c_ openmp_
do
	(cd $dirs ;make -j8;)
done
make -j8
