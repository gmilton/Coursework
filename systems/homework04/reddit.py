#!/usr/bin/env python2.7

import requests
import os
import sys
import re

# Global Variables

FIELD = "title"
LIMIT = 10
SUBREDDIT = "linux"
REGEX = ""
headers  = {'user-agent': 'reddit-{}'.format(os.environ['USER'])}

# Usage function

def usage(status=0):
   print '''Usage: {} [ -f FIELD -s SUBREDDIT ] regex
   -f	FIELD		Which field to search (default: title)
   -n	LIMIT		Limit number of articles to report (default: 10)
   -s	SUBREDDIT	Which subreddit to search (default: linux)'''.format(os.path.basename(sys.argv[0]))
   sys.exit(status)

# Parse command line options

args = sys.argv[1:]
while len(args) and args[0].startswith('-') and len(args[0]) > 1:
   arg = args.pop(0)
   if arg == '-f':
      arg = args.pop(0)
      FIELD = arg
   elif arg == '-n':
      arg = args.pop(0)
      LIMIT = int(arg)
   elif arg == '-s':
      arg = args.pop(0)
      SUBREDDIT = arg
   elif arg == '-h':
      usage(0)
   else:
      usage(1)

if len(args) == 1:
   REGEX = args[0]

# Main execution

url = 'https://www.reddit.com/r/%s/.json'%(SUBREDDIT)
r = requests.get(url, headers=headers)
dictionary = r.json()

count = 0
for articles in dictionary['data']['children']: 
   if FIELD not in articles['data'].keys():
      print "Invalid field:", FIELD
      sys.exit(1) 
   if re.search(REGEX, articles['data']['{}'.format(FIELD)]):
      print "{:2}".format(count+1)+".",'Title: ',articles['data']['title']
      print '    Author:',articles['data']['author']
      link = 'https://www.reddit.com'+articles['data']['permalink']
      print '    Link:  ', link
      p = { 'format': 'json', 'url': link}
      short = requests.get('http://is.gd/create.php', params=p).json()
      print '    Short: ', short["shorturl"]
      print ''
      count = count + 1
      if count == LIMIT:
         break
