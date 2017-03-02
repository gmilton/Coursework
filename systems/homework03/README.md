Homework 03
===========

Activity 1: Caesar Cipher
-------------------------

1.) How you parsed the command line arguments.   
I started with an if statement. If there is a command line argument, if it is `-h` then my program calls the function `usage` I created to display the help message. For any other command line argument, `ROTATION` is set to the `$1 % 26`.   Otherwise, `ROTATION` is set to 13 at the beginning so if no argument is given it stays that way.   

2.) How you constructed the source set.   
My source set consists of `$lower$upper`, which is all of the lowercase letters, followed by all the uppercase ones.   

3.) How you constructed the target set 
I made four sets: `1-$ROTATION` of lower case letters, `1-$ROTATION` of upper case, the rest of lower case letters after `$ROTATION`, and the rest of uppercase letters. My target set is set up so it's `$SET3$SET1$SET4$SET2`, which is the lower case letters after the shift, the beginning of the lowercase letters, the uppercase letters after the shift, the beginning of the uppercase alphabet.   

4.) How you used both of these sets to perform the encryption.   

After I made the sets, I just used `tr SOURCE TARGET` so in my code it's `tr $lower$upper $SET3$SET1$SET4$SET2`.   

Activity 2: Broification
------------------------

1.) How you parsed the command line arguments.   
I have a while loop that runs while `$# -gt 0`, so while there are command line arguments still. Within that I have a switch case. I have cases for `-d` where I set `DELIM` to `$2` and `shift`, `-W` where I set the `WHITESPACE` variable to 1 and `shift`, and `-h` where I call the function `usage`. After the switch case I `shift` again.   

2.) How you removed comments.   
I removed comments by setting the default `DELIM` to `#`. Then I use `sed "s|$DELIM.*$||"` to replace everything after the delimiter with nothing.   

3.) How you removed empty lines.   
I removed empty lines with `sed '/^\s*$/d'`.   

4.) How the command line options affected your operations above.   
If the user entered something for `DELIM`, it was changed to that. Also I have a variable `WHITESPACE`. By default, it is 0. If the `-W` flag is used, it is set to 1. Then I have an if statement. If `$WHITESPACE -eq 0` then I call the commands to remove after the delimiter, remove empty lines, and remove trailing spaces. If `$WHITESPACE -eq 1` then I only have the commands to remove after the delimiter and trailing spaces.   

Activity 3: Zip Codes
---------------------

1.) How you parsed the command line arguments.   
I have a while loop that runs while `$# -gt 0`, so while there are command line arguments still. Within that I have a switch case. I have cases for `-c` where I shift and `CITY` is set to the first argument of the command line followed by `/`, `-f` where I shift and `FORMAT` is set to the first command line argument, `-s` where I shift and `STATE` is set to the first command line argument and then piped through 'sed 's| |%20|g' to deal with states with two words, and `-h` which calls the `usage` function. After the switch case I `shift` to read the next flag. 

2.) How you extracted the zip codes.   
`curl -s http://www.zipcodestogo.com/$STATE/ | grep -E 'http://www.zipcodestogo.com/[A-Z]' | grep -Eo '[0-9]{5}' | sort | uniq` for just the state.   
`curl -s http://www.zipcodestogo.com/$STATE/ | grep -E "http://www.zipcodestogo.com/$CITY" | grep -Eo '[0-9]{5}' | sort | uniq` for the city and state.   

3.) How you filtered by STATE and CITY.   
I used if statements to decide when to extract using `STATE` and `CITY` names or not. I filtered by state by using `"$STATE"` in the URL I curled. I filtered the `CITY` by using `$CITY` in the string I grepped.   

4.) How you handled the `text` and `csv` `FORMAT` options.   
I made format a variable and set it to `"text"` as default. If the `-f` flag is called `FORMAT` is set to the second command line argument. Then I have if statements that decide what is done based on the `FORMAT`. If `csv` is the `FORMAT` then `paste -s -d ','` is added to the end of the pipeline to display it correctly. 



