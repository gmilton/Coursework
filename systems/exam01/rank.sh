#!/bin/sh

DESCEND=0
NUM=5

usage() {

   echo "Usage: $(basename $0) [-n N -D]
	
	-n N	Returns N items (default is 5).
	-D	Rank in descending order."

   exit $1

}

while [ $# -gt 0 ]; do
   case $1 in
      -n) shift
          NUM=$1
          ;;
      -D) DESCEND=1
          ;;
      -h) usage 0
          ;;
      *) usage 1
         ;;
   esac
   shift
done

if [ $DESCEND -eq 1 ]; then
   sort -rV | head -n $NUM
else
   sort -V | head -n $NUM
fi
