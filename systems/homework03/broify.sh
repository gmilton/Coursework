#!/bin/sh

DELIM='#'
WHITESPACE=0
usage() {

   echo "Usage: " $(basename $0) 
   echo
   echo "-d DELIM	Use this as the comment delimiter."
   echo "-W		Don't strip any empty lines."

   exit 1

}

while [ $# -gt 0 ]; do
   case $1 in
      -d) DELIM=$2
          shift;;
      -W) WHITESPACE=1
          shift;;
      -h) usage 1;;
   esac
   shift
done


if [ $WHITESPACE -eq 0 ]; then
   sed "s|$DELIM.*$||" | sed '/^\s*$/d' | sed 's/[ \t]*$//'
elif [ $WHITESPACE -eq 1 ]; then
   sed "s|$DELIM.*$||" | sed 's/[ \t]*$//'
fi
