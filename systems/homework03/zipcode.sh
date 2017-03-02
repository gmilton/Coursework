#!/bin/sh

DEFAULT=1
STATE="Indiana"
FORMAT="text"

usage() {

   echo "Usage:  $(basename $0) 
   
	-c	CITY	Which city to search
	-f	FORMAT	Which format (text, csv)
	-s	STATE	Which state to search (Indiana)

If not CITY is specified, then all the zip codes for the STATE are displayed."

   exit 1

}

while [ $# -gt 0 ]; do
   case $1 in
      -c) shift
          CITY="$1/"
          DEFAULT=0
          ;;
      -f) shift
          FORMAT=$1
          DEFAULT=0
          ;;
      -s) shift
          STATE=`echo $1 | sed 's| |%20|g'`
          DEFAULT=0
          ;;
      -h) usage 1;;
   esac
   shift
done

if [ "$FORMAT" = "text" ]; then
   if [ $DEFAULT -eq 1 ]; then
      curl -s http://www.zipcodestogo.com/$STATE/ | grep -E 'http://www.zipcodestogo.com/[A-Z]' | grep -Eo '[0-9]{5}' | sort | uniq
   else
      curl -s http://www.zipcodestogo.com/$STATE/ | grep -E "http://www.zipcodestogo.com/$CITY" | grep -Eo '[0-9]{5}' | sort | uniq 
   fi
elif [ "$FORMAT" = "csv" ]; then
   if [ $DEFAULT -eq 1 ]; then
      curl -s http://www.zipcodestogo.com/$STATE/ | grep -E 'http://www.zipcodestogo.com/[A-Z]' | grep -Eo '[0-9]{5}' | sort | uniq | paste -s -d ','
   else
      curl -s http://www.zipcodestogo.com/$STATE/ | grep -E "http://www.zipcodestogo.com/$CITY" | grep -Eo '[0-9]{5}' | sort | uniq | paste -s -d ','
   fi
fi
