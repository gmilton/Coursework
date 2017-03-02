#!/bin/sh

TROLL=/afs/nd.edu/user15/pbui/pub/bin

trap endgame 1 2 15

endgame()
{
  echo For crying out loud! | $TROLL/cowsay -f tux
  exit 1
}

echo Hello gmilton, what question do you have for me today? | $TROLL/cowsay -f tux

read -p "Question? " QUESTION

while [ -z "$QUESTION" ] 
do
   read -p "Question? " QUESTION
done

SAYING=$(shuf -i 1-20 | head --lines=1) 
case $SAYING in
	1)
		SAYING="It is certain"
		;;
	2)
		SAYING="It is decidedly so"
		;;
	3)
		SAYING="Without a doubt"
		;;
	4)
		SAYING="Yes, definitely"
		;;
	5)
		SAYING="You may rely on it"
		;;
	6)
		SAYING="As I see it, yes"
		;;
	7)
		SAYING="Most likely"
		;;
	8)
		SAYING="Outlook good"
		;;
	9)
		SAYING="Yes"
		;;
	10)
		SAYING="Signs point to yes"
		;;
	11)
		SAYING="Reply hazy try again"
		;;
	12)
		SAYING="Ask again later"
		;;
	13)
		SAYING="Better not tell you now"
		;;
	14)
		SAYING="Cannot predict now"
		;;
	15)
		SAYING="Concentrate and ask again"
		;;
	16)
		SAYING="Don't count on it"
		;;
	17)
		SAYING="My reply is no"
		;;
	18)
		SAYING="My sources say no"
		;;
	19)
		SAYING="Outlook not so good"
		;;
	20)
		SAYING="Very doubtful"
		;;
esac

echo $SAYING | $TROLL/cowsay -f tux
