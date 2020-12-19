# Program to copy libs to directory from where you called this
#
#

DIR=~/work/tools/

declare -a LIBDIRS
declare -a LIBS
declare -a HEADERS

LIBDIRS[0]=~/work/tools/libft/
LIBS[0]=${LIBDIRS[0]}'libft.a'
HEADERS[0]=${LIBDIRS[0]}'libft.h'

LIBDIRS[1]=~/work/tools/vectorC/
LIBS[1]=${LIBDIRS[1]}'libvect.a'
HEADERS[1]=${LIBDIRS[1]}'libvect.h'

# LIBDIRS[2]=~/work/tools/ft_printf/
# LIBS[2]=${LIBDIRS[2]}'libftprintf.a'
# HEADERS[2]=${LIBDIRS[2]}'ft_printf.h'

if [[ $1 == "re" ]]
then
	CMD='make re -C'
	echo $1
else
	CMD='make -C'
fi

for i in $(seq 0 $(expr "${#LIBDIRS[@]}" - 1))
do
	$CMD ${LIBDIRS[$i]}
	cp ${LIBS[$i]} .
	cp ${HEADERS[$i]} .
done
