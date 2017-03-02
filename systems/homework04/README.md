Homework 04
===========

Activity 1: Blend Profiles
--------------------------

1.) How you parsed command line arguments.   

I parsed the command line arguments by setting a variable `args` to `sys.argv[1:]`. Then I ran through a loop `while len(args) and args[0].startswith('-') and len(args[0]) > 1`. After this I shifted arguments using `args.pop(0)`. Then I have an if/else statement for each different flag. If a flag reads in the next argument as a value, I shift again using `args.pop(0)` and set the appropriate variable to `arg`.   

2.) How you managed the temporary workspace.   

I manage the temporary workspace by creating a temporary directory using `tempfile.mkdtemp(prefix='temp')`. This created a temporary directory beginning with 'temp'. I then added the pictures for each netid to this directory and eventually the separate images for the gif. I removed it at the end of the program with `atexit.register(cleanup)` where `cleanup` was a function I defined that called `shutil.rmtree(tempdir)` and displayed a message.   

3.) How you extracted the portrait URLS.   

First I used `request.get()` for two variables profile1 and profile 2 to get to the profile for each person. The url I used in `request.get()` was `url_begin+netid1` or `url_begin+netid2` where `url_begin = https://engineering.nd.edu/profiles/`. Then, I made sure these were valid by checking if the `status_code == 200` for each profile. If it was, I found each link by having `url_begin + re.findall('\w*[\w\.-]+/@@images/[\w\.-]+', profile1.text)[0]`, which found the rest of the link for the image. If it found both links, I displayed a message. Otherwise I displayed an error message and exited early using `sys.exit(1)`.   

4.) How you downloaded the portrait images.   

First, I defined two variables `image1_status` and `image2_status` to `requests.get(link1)` and `requests.get(link2)`, which is the actual content of each image. If these are then valid, I get the content of each image. I add each image to the temporary directory and use handler to give it the correct content. If it isn't valid it exits the program.   

5.) How you generated the blended composite images.   

I created an array `GIFLIST` to hold all the intermediary images for the gif. Then I run through the range 0 - 100 with `STEPSIZE` as the increment. I use composite blend to create each of the intermediary images and add it to the temporary directory. Then I add it the `GIFLIST`. If `REVERSE == True`, I then add all of the images to `GIFLIST` again in the reverse order.   

6.) How you generated the final animation.   

I generates the final animation using `os.system("convert -loop 0 -delay %s %s %s"% (DELAY, GIFLIST, target))`.   

7.) How you checked for failure of different operations and exited early.   

As I've mentioned already, at different points I checked if the profiles were valid and if they actually had images by comparing their `status_code` to 200. If they weren't valid, I displayed an error message and used `sys.exit(1)`.    

Activity 2: Grep Reddit
-----------------------

1.) How you parsed command line arguments.   

I set `args = sys.argv[1:]`. Then I ran through a while loop while `len(args) and args[0].startswith('-') and len(args[0]) > 1`. I shifted to the correct command line argument with `args.pop(0)`, then ran through an if statement with the correct flags. For `-f` and `-n` I used `args.pop(0)` again before defining `FIELD` and `LIMIT`.   

2.) How you fetched the JSON data and iterated over the articles.   

I fetched the JSON data using `requests.get(url, headers=headers)`, where `url = 'https://www.reddit.com/r/%s/.json'%(SUBREDDIT)`. I then iterated over the articles using a for loop under the condition `articles in dictionary['data']['children']`.   

3.) How you filtered each article based on the `FIELD` and `REGEX`.   

In the previously mentioned for loop, i have an if statement saying `re.search(REGEX, articles['data']['{}'.format(FIELD)])`. This searches for `REGEX` in the `FIELD` field.   

4.) How you generated the shortened URL.   

I generated the shortened URL by defining parameter `p = { 'format': 'json', 'url': link }`, then `short = requests.get('http://is.gd/create.php', params=p).json()`, then `print '    Short: ', short["shorturl"]`.   

 
