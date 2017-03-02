#!/usr/bin/env python2.7

import atexit
import os
import re
import shutil
import sys
import tempfile

import requests
os.environ['PATH'] = '~ccl/software/external/imagemagick/bin:' + os.environ['PATH']

# Global variables

REVERSE     = False
DELAY       = 20
STEPSIZE    = 5

# Functions

def usage(status=0):
    print '''Usage: {} [ -r -d DELAY -s STEPSIZE ] netid1 netid2 target
    -r          Blend forward and backward
    -d DELAY    GIF delay between frames (default: {})
    -s STEPSIZE Blending percentage increment (default: {})'''.format(
        os.path.basename(sys.argv[0]), DELAY, STEPSIZE
    )
    sys.exit(status)

def cleanup():
   shutil.rmtree(tempdir)
   print "Cleaning up workspace:",tempdir 
# Parse command line options

args = sys.argv[1:]

while len(args) and args[0].startswith('-') and len(args[0]) > 1:
   arg = args.pop(0)
   if arg == '-r':
      REVERSE = True
   elif arg == '-d':
      arg = args.pop(0)
      DELAY = int(arg)
   elif arg == '-s':
      arg = args.pop(0)
      STEPSIZE = int(arg)
   elif arg == '-h':
      usage(0)
   else:
      usage(1)

if len(args) != 3:
    usage(1)

netid1 = args[0]
netid2 = args[1]
target = args[2]
url_begin = 'https://engineering.nd.edu/profiles/'
# Main execution

# Create workspace
tempdir = tempfile.mkdtemp(prefix='temp')
print "Using workspace:",tempdir

# Register cleanup
atexit.register(cleanup);

# Extract portrait URLs
profile1 = requests.get(url_begin+netid1)
profile2 = requests.get(url_begin+netid2)
if profile1.status_code == 200 and profile2.status_code == 200:
   link1 = url_begin + re.findall('\w*[\w\.-]+/@@images/[\w\.-]+', profile1.text)[0]
   print "Searching portrait for",netid1+"...",link1
   link2 = url_begin + re.findall('\w*[\w\.-]+/@@images/[\w\.-]+', profile2.text)[0]
   print "Searching portrait for",netid2+"...",link2
else:
   print "Could not match netid to webpage... exiting program"
   sys.exit(1)

# Download portraits
image1_status = requests.get(link1)
image2_status = requests.get(link2)
if image1_status.status_code == 200 and image2_status.status_code == 200:
   image1_content = requests.get(link1).content
   image2_content = requests.get(link2).content
   image1 = tempdir+'/'+netid1+'.jpg'
   with open(image1, 'wb') as handler:
      handler.write(image1_content)
   print "Downloading", link1, "to", image1+"... Success!"
   image2 = tempdir+'/'+netid2+'.jpg'
   with open(image2, 'wb') as handler:
      handler.write(image2_content)
   print "Downloading", link2, "to", image2+"... Success!"
else:
   print "Could not download image... exiting program"
   sys.exit(1)

# Generate blended composite images
GIFLIST = ""
for i in xrange(0, 100+STEPSIZE, STEPSIZE):
   j = "{0:03}".format(i)
   image_mix = tempdir+'/'+j+target
   print "Generating", image_mix+"... Success!"
   os.system("composite -blend %s %s %s %s"% (i, image1, image2, image_mix))
   GIFLIST += image_mix + " "

if REVERSE == True:
   for i in xrange(100, 0-STEPSIZE, -STEPSIZE):
      j = "{0:03}".format(i)
      image_mix = tempdir+'/'+j+target
      GIFLIST += image_mix + " "

# Generate final animation
os.system("convert -loop 0 -delay %s %s %s"% (DELAY, GIFLIST, target))
print "Generating", target+"... Success!"
