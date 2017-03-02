Homework 02
===========

Activity 1: Saving the World
----------------------------

1.) How you checked and handled having no arguments.   
   
I used a case structure so the program knew how to act for the different file types. The last case is under the condition `*`, which acts as the default case. So anytime a file is entered different from the allowed file types, it displays a message "INCORRECT FILE TYPE".   
   
2.) How you determined which command to use for each argument.   
   
I determined which command to use for each argument by using the hints. I figured tar would be used for the first three and unzip would be used for the last one. Then I looked at the descriptions of these commands and found the different flags. I decided on `-x` because that's the command to extract. `-z`, `-j`, and `-J` all corresponded to the types of files. `-f` is for ARCHIVE. I settled on `-v` because I wanted to list the files processed and that's the flag to do so. I had to use unzip for the last file type. I decided on the `-c` because that was the flag to extract files to stdout.   
      
3.) What was the most challenging aspect of writing this script and how you overcame this issue.   
   
The most challenging aspect of writing this script was just figuring out where to start. I had to use the hints because being good at Unix just isn't coming the most naturally to me. Also deciding which flags to use. That was just trial and error for a while. I had to really search through and read a lot of the help page on each command to figure those out.   
   
Activity 2: Predicting the Future
---------------------------------

1.) How you displayed random messages to the user.   
   
I started by setting a variable `SAYING` to be a random number by using `shuf -i 1-20 | head --lines=1` which shuffles 20 number and chooses the first one. I then made a switch case where `$SAYING` was the argument with 20 different cases. In each case I set `SAYING` to a different saying. Then after the switch case I echoed `$SAYING` to `cowsay`.   
   
2.) How you handled signals.   
   
I started with `trap endgame 1 2 15`. `endgame` is what I called my function that displayed a message and exited out of the program after the certain kill commands were sent. 1, 2 and 15 represent the signal for the commands we were supposed to handle.   
   
3.) How you read input from the user.   
   
First, I just have `read -p "Question? " QUESTION`. Then I have a while loop running under the condition `[ -z "$QUESTION" ]`. This runs only when the line is empty. In it, it calls `read -p "Question? " QUESTION` again.   
   
4.) What was the most challenging aspect of writing this script and how you overcame this issue.   
   
The most challenging part of this script for me was getting `shuf -i 1-20 | head --lines=1` to work for the random number. Some reason I could not get it to work for the life of me. I worked on it for like over an hour. I tried so many things but it kept telling me head or -i was not a command or it wasn't reading the value right. I looked it the book online, I looked up how to use `shuf` and `head`. Eventually, I realized that I needed to have `SAYING=$(shuf -i 1-20 | head --lines=1)` instead of just `SAYING=shuf -i 1-20 | head --lines=1`.    
   
Activity 3: Meeting the Oracle
------------------------------

1.) My first step was to scan `xavier.h4x0r.space` for a HTTP port:   
`nc -z xavier.h4x0r.space 9000-9999`   

Connection to xavier.h4x0r.space 9097 port [tcp/*] succeeded!   
Connection to xavier.h4x0r.space 9111 port [tcp/*] succeeded!   
Connection to xavier.h4x0r.space 9876 port [tcp/sd] succeeded!   
  
2.) Then, I tried to access the HTTP servers. The third one gave me the correct reponse:   
`curl http://xavier.h4x0r.space:9876`   
   
```
 ________________________________________    
/ Halt! Who goes there?                  \   
|                                        |   
| If you seek the ORACLE, you must come  |   
| back and _request_ the DOORMAN at      |   
| /{NETID}/{PASSCODE}!                   |   
|                                        |   
| To retrieve your PASSCODE you must     |   
| first _find_ your LOCKBOX which is     |   
| located somewhere in                   |   
| ~pbui/pub/oracle/lockboxes.            |   
|                                        |   
| Once the LOCKBOX has been located, you |   
| must use your hacking skills to        |   
| _bruteforce_ the LOCKBOX program until |   
| it reveals the passcode!               |   
|                                        |   
\ Good luck!                             /   
 ----------------------------------------    
  \   
   \          .   
       ___   //   
     {~._.~}//    
      ( Y )K/     
     ()~*~()      
     (_)-(_)      
     Luke       
     Sywalker   
     koala   
```
   
3.) So then I attempted to find my lockbox:   
   
`find ~pbui/pub/oracle/lockboxes -name gmilton.lockbox`    
   
/afs/nd.edu/user15/pbui/pub/oracle/lockboxes/5aabdb3e/120f1418/8bdd201e/23de23ea/gmilton.lockbox   
   
4.) I changed to this directory and bruteforced the lockbox to find the passcode:   
   
`cd /afs/nd.edu/user15/pbui/pub/oracle/lockboxes/5aabdb3e/120f1418/8bdd201e/23de23ea/`   
``for i in `strings gmilton.lockbox`; do  gmilton.lockbox $i; done``   
   
9f721cc658f6887553266159d50f4c86   
   
5.) I now have the passcode and I want to request the doorman:   
   
`curl http://xavier.h4x0r.space:9876/gmilton/9f721cc658f6887553266159d50f4c86`   
```   
 _________________________________________    
/ Ah yes, gmilton... I've been waiting    \   
| for you.                                |   
|                                         |   
| The ORACLE looks forward to talking to  |   
| you, but you must authenticate yourself |   
| with our agent, BOBBIT, who will give   |   
| you a message for the ORACLE.           |   
|                                         |   
| He can be found hidden in plain sight   |   
| on Slack. Simply send him a direct      |   
| message in the form "!verify netid      |   
| passcode". Be sure to use your NETID    |   
| and the PASSCODE you retrieved from the |   
| LOCKBOX.                                |   
|                                         |   
| Once you have the message from BOBBIT,  |   
| proceed to port 9111 and deliver the    |   
| message to the ORACLE.                  |   
|                                         |   
| Hurry! The ORACLE is wise, but she is   |   
\ not patient!                            /   
 -----------------------------------------    
     \   
      \   
          oO)-.                       .-(Oo   
         /__  _\                     /_  __\   
         \  \(  |     ()~()         |  )/  /   
          \__|\ |    (-___-)        | /|__/   
          '  '--'    ==`-'==        '--'  '         
```     
6.)  Then I had to send a message to Bobbit on Slack:
   
!verify gmilton 9f721cc658f6887553266159d50f4c86   

@gmilton: Greetings gmilton! Please tell the ORACLE the following MESSAGE: dHp2eWdiYT0xNDg2MTQyOTc3   
   
7.) Next I had to find the Oracle:   
   
`nc xavier.h4x0r.space 9111`

```
 ________________________ 
< Hello, who may you be? >
 ------------------------ 
     \
      \
        ,__, |    | 
        (oo)\|    |___
        (__)\|    |   )\_
             |    |_w |  \
             |    |  ||   *

             Cower....
NAME? gmilton
 ___________________________________ 
/ Hmm... gmilton?                   \
|                                   |
| That name sounds familiar... what |
\ message do you have for me?       /
 ----------------------------------- 
     \
      \
        ,__, |    | 
        (oo)\|    |___
        (__)\|    |   )\_
             |    |_w |  \
             |    |  ||   *

             Cower....
MESSAGE? dHp2eWdiYT0xNDg2MTQyOTc3
 _______________________________________ 
/ Ah yes... gmilton!                    \
|                                       |
| You're smarter than I thought. I can  |
| see why the instructor likes you.     |
|                                       |
| You met BOBBIT about 3 minutes ago... |
\ What took you so long?                /
 --------------------------------------- 
     \
      \
        ,__, |    | 
        (oo)\|    |___
        (__)\|    |   )\_
             |    |_w |  \
             |    |  ||   *

             Cower....
REASON? because you're the worst
 ______________________________________ 
/ Hmm... Sorry, kid. You got the gift, \
| but it looks like you're waiting for |
| something.                           |
|                                      |
| Your next life, maybe. Who knows?    |
\ That's the way these things go.      /
 -------------------------------------- 
     \
      \
        ,__, |    | 
        (oo)\|    |___
        (__)\|    |   )\_
             |    |_w |  \
             |    |  ||   *

             Cower....

Congratulations gmilton! You have reached the end of this journey.

I hope you learned something from the ORACLE :] 
```   
