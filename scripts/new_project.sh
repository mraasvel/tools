SRCDIR='src'
INCLUDEDIR='includes'

mkdir -p $SRCDIR
mkdir -p $INCLUDEDIR
touch ${SRCDIR}/main.c
bash ~/work/tools/scripts/headerfiles.sh header > ${INCLUDEDIR}/header.h
cp ~/work/tools/scripts/examples/Makefile .
cp ~/work/tools/scripts/examples/run.sh .