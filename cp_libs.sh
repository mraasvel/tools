DIR=~/work/tools/

if [[ $1 == "re" ]]
then
	CMD='make re -C'
	echo $1
else
	CMD='make -C'
fi

echo $dir
$CMD $DIR'libft'
$CMD $DIR'vectorC'

cp $DIR'libft/libft.a' $DIR
cp $DIR'vectorC/libvect.a' $DIR
cp $DIR'vectorC/libvect.h' .
cp $DIR'libft/libft.h' .

mv $DIR'libft.a' .
mv $DIR'libvect.a' .

# cp $DIR/cp_libs.sh .