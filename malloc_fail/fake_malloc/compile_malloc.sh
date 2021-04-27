SDIR=src
IDIR=includes

FLAGS='-g -fsanitize=address'
SRC_FILES="${SDIR}/*.c fake_malloc.c"

for i in {1..10}
do
	# Have to define it while compiling into .c files instead of .o files
	msg="gcc -D MALLOC_FAIL=$i ${SRC_FILES} ${FLAGS} -o a.out -I${IDIR}"
	echo $msg
	$msg
	./a.out
done
