#!/bin/sh

if (($# >= 1)); then
   for arg in "$@"
   do
      case $arg in
         *.tgz)
                tar -xvzf $arg
                ;;
         *.tar.gz)
		tar -xvzf $arg
		;;
         *.tbz)
		tar -xjvf $arg 
		;;
         *.tar.bz2)
		tar -xjvf $arg
		;;
         *.txz)
		tar -xJvf $arg
		;;
         *.tar.xz)
		tar -xJvf $arg
		;;
         *.zip)
		unzip -c $arg
		;;
         *.jar)
		unzip -c $arg
		;;
	*)
		echo INCORRECT FILE TYPE
                exit 2
		;;
      esac
   done
else
   echo "Usage: extract.sh archive1 archive2..."
   exit 1
fi
