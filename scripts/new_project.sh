SRCDIR='src'
INCLUDEDIR='includes'

echo "Create new project in current directory?"
read LINE
declare -a ARGS=("y" "Y" "yes" "Yes" "YES")
if [[ ! " ${ARGS[@]} " =~ " ${LINE} " ]]; then
	echo "Aborting..."
	exit
fi


mkdir -p $SRCDIR
mkdir -p $INCLUDEDIR
touch ${SRCDIR}/main.c
bash ~/work/tools/scripts/headerfiles.sh header > ${INCLUDEDIR}/header.h
cp ~/work/tools/scripts/examples/Makefile .
cp ~/work/tools/scripts/examples/run.sh .