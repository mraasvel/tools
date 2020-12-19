# **USAGE:**
# Will execute git push or pull automatically in all directories listed in the array DIRS
# bash $(PATH)/git.sh push or ./git.sh pull
# argument = push or pull.

declare -a DIRS

# ARRAY OF PATHNAMES TO GIT
# DIRS[x]=PATHNAME (no spaces)
# Add new directories here.
DIRS[0]=~/work/codam/codam-core
DIRS[1]=~/work/codam/practice
DIRS[2]=~/work/tools/
DIRS[3]=~/work/codam/miniRT
DIRS[4]=~/work/other/vectors
DIRS[5]=~/work/other/adventofcode2020

# COLOR CODES: [1;33m = yellow, [1;31m = red etc
COLOR="\033[1;33m"
END_COLOR="\033[0;0m"

# function to add all new and updated files in target directory, commit them, and push them to the default remote branch
# Only adds hidden files if they were already added manually before, then it pushes the updated versions.
git_push()
{
	DIR=$1
	git -C $1 add $1/*
	git -C $1 commit -a -m "automatic push"
	if [ $? == 0 ]
	then
		git -C $1 push
		echo -e "$COLOR""Push Successfull.""$END_COLOR"
	else
		echo -e "$COLOR""Nothing to commit.""$END_COLOR"
	fi
}

# If first param = 'pull', execute git pull in all DIRS
# else if first param = 'push', execute git add/push/commit in all DIRS
if [[ "$1" = "pull" ]]; then
	for i in ${DIRS[*]}
	do
		echo -e "$COLOR""git pull in $i:""$END_COLOR"
		git -C $i pull
		echo
	done
elif [[ "$1" = "push" ]]; then
	for i in ${DIRS[*]}
	do
		echo -e "$COLOR""git add/commit/push in $i:""$END_COLOR"
		git_push $i
		echo
	done
fi
