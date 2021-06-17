SRCDIR='src'
INCLUDEDIR='includes'

AskQuestion() {
	echo $1
	read LINE
	declare -a ARGS=("y" "Y" "yes" "Yes" "YES")
	if [[ ! " ${ARGS[@]} " =~ " ${LINE} " ]]; then
		echo "Aborting..."
		exit
	fi
}

AskQuestion "Create new project in current directory?"

echo "Options:"
echo "	[0] - C"
echo "	[1] - C++"

read LINE
if [[ "$LINE" == "0" ]]; then
	MAKEFILE='Makefile_c'
	MAIN='main.c'
elif [[ "$LINE" == "1" ]]; then
	MAKEFILE='Makefile_cpp'
	MAIN='main.cpp'
else
	echo "Invalid option"
	exit
fi


mkdir -p $SRCDIR
mkdir -p $INCLUDEDIR
touch ${SRCDIR}/$MAIN
cp ~/work/tools/scripts/examples/$MAKEFILE ./Makefile
cp ~/work/tools/scripts/examples/run.sh .
