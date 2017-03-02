#!/bin/sh

usage() {

   echo "Usage: caesar.sh [rotation]"
   echo
   echo "This program will read from stdin and rotate (shift right) the text by the specified rotation.  If none is specified, then the default value is 13."

}

ROTATION=13
lower=abcdefghijklmnopqrstuvwxyz
upper=ABCDEFGHIJKLMNOPQRSTUVWXYZ

if test $# -gt 0; then
   if [ "$1" = "-h" ]; then
      usage
      exit 1
   else
      ROTATION=`expr $1 % 26` 
   fi
fi

SET1=$(echo $lower | cut -c 1-$ROTATION) #n-z
SET2=$(echo $upper | cut -c 1-$ROTATION) #N-Z
ROTATION=`expr $ROTATION + 1`
SET3=$(echo $lower | cut -c $ROTATION-26) #a-m
SET4=$(echo $upper | cut -c $ROTATION-26) #A-M
tr $lower$upper $SET3$SET1$SET4$SET2

