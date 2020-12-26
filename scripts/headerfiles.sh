DIR=~/work/tools/scripts/examples

if [ $# -ne 0 ]
then
	for i in $@
	do
		filename=$(basename -- "$i")
		filename="${filename%.*}"
		val=${filename^^}
		# sed "s/HEADER/$val/g ; s/header/$filename/g" "$DIR/header.h"
		sed "s/HEADER/$val/g" "$DIR/header.h"
	done
fi
