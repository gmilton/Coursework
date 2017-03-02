// Lab 10
// animate.cpp
// Grace Milton
// Creates a game where a user can make a ball jump over blocks by pressing 'w'. Ball increases speed as game progresses. Sun and moon revolve in background.
#include "gfx.h"
#include <unistd.h>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void spokes(int x, int y, int r, double theta); // Creates rotating spokes in ball
void block(int xb, int yb, int w, int yground); // Creates blocks
void sun(bool day, double thetas, int yground); // Creates sun or moon

int main()
{
   int wd = 500, ht = 500, yground = 4*ht/5; // dimensions of window
   int r = 20, xc = r+1, yc = yground-r-1; // dimensions of ball
   int count = 0, reached = 0, daycount = 0; // counts
   double vx0 = 20, vx = vx0, vy = 0, vb = -15; // velocities
   double a = 9.8; // gravity
   double deltat = 0.5, elapsedtime = 0, horizon = 0; // times
   double theta = 0, thetas = 0; // angles
   bool loop = true, jump = false, fall = false, dead = false, obstacles = false, day = true, newblock = true;
   char c, choice;
   int wb = 20, hb = 30, xb = wd - wb/2, yb = yground - hb/2; // dimensions of blocks
   int bcolor_r = 153, bcolor_g = 51, bcolor_b = 255; // colors of blocks
   srand(time(NULL));

   // Opens window
   gfx_open(wd,ht,"Rotating Animation");   
   gfx_clear_color(153,204,255);
   gfx_clear();
   
   // Displays instructions to the user on terminal
   cout << "'w' to jump" << endl;
   cout << "'r' to restart" << endl;
   cout << "'q' to quit" << endl;
   cout << "Blocks reached:" << endl;  
 
   while(loop) {
      c = gfx_event_waiting();
      // Sets color of background based on day or night
      if (day) {
         gfx_clear_color(153,204,255);
      }
      else {
         gfx_clear_color(0,0,102);
      }
      gfx_clear();
      // Makes bottom fifth of screen green for grass
      gfx_color(76,153,0);
      for(int i = yground; i < ht; i++) {
         gfx_line(0,i,wd-1,i);
      }
      sun(day,thetas, yground); // Creates sun or moon
      gfx_color(255,102,102);
      gfx_circle(xc,yc,r); // Creates ball
      spokes(xc,yc,r, theta); // Adds spokes inside ball for rotational motion
      theta = sqrt(vx0*vx0)*elapsedtime/r; // Calculates angle for spokes
      thetas = -7.5*horizon/100; // Calculates angle of path of sun/moon
      if (thetas <= -3.7) { // Resets sun/moon once it sets below horizon
         horizon = 0;
         daycount++; // Tracks whether sun or moon should be next
      }
      if (daycount % 2 == 0) { // Sets day to true for sun
         day = true;
      }
      else { // Sets day to false for moon
         day = false;
      }
      // Creates blocks when it's time for them
      if (obstacles) {
         gfx_color(bcolor_r,bcolor_g,bcolor_b);
         block(xb, yb, wd, yground);
         xb = xb + vb*deltat;
         if (xb <= wb/2) { // Resets block when it reaches left boundary and randomly assigns it a color
            bcolor_r = rand() % 255 + 1;
            bcolor_g = rand() % 255 + 1;
            bcolor_b = rand() % 255 + 1;
            xb = wd - wb/2;
         }
         vb = vb - 0.01; // Increases velocity of block over time simulating increase in velocity of ball
         vx0 = vb; // Keeps velocity of circular motion of spokes related to velocity of "ball"
      }
      gfx_flush();
      usleep(80000);
      xc = xc + vx*deltat;
      // Ball jumps when user presses 'w'
      if(jump) {
         vy = -20; // Creates y-component of velocity
         yc = yc + vy*deltat + 0.5*a*deltat*deltat; // Accounts for gravity
         count = count + 1;
         if (count == 7) { // Stops ball when it gets high enough
            jump = false; 
            fall = true;
            count = 0;
         }
      }
      // Returns ball to initial height
      if (fall) {
         vy = 20; // Reverses velocity
         yc = yc + vy*deltat + 0.5*a*deltat*deltat; // Accounts for gravity
         if (yc > (yground-r-1)) { // Returns ball to ground
            yc = (yground-r-1);
            fall = false;
         }
      }
      // Acknowledges new block created
      if (xb > wd/2) {
          newblock = true;
      }
      else if (newblock && xb <= wd/2) { // Counts block as reached when it reaches midpoint
         reached++;
         cout << reached << endl; // Displays number of blocks reached
         newblock = false;
      }
      // Ball moves straight down until off screen when considered "dead"
      if (dead) {
         yc = yc + vy*deltat;
         if (yc >= 500 + r) {
            vy = 0;
         }
      }
      elapsedtime = elapsedtime + deltat; // Tracks total time for theta
      horizon = horizon + deltat; // Tracks when sun/moon reaches horizon
      // Determines if point on ball is inside block
      if (obstacles) {
         for(int i = 0; i <= 2*3.14159; i = i + 1) {
            if((xc + r*cos(i)) >= (xb - wb/2) && (xc + r*cos(i)) <= (xb + wb/2) && (yc + r*sin(i)) >= (yb - hb/2)) {
               vb = 0;
               vx = 0;
               vy = 15;
               dead = true;        
            }
         }
      }
      // Keeps ball at midpoint of screen and begins blocks
      if (xc >= 0.5*wd) {
         vx = 0;
         obstacles = true;
      }
      if(c == 1) {
         choice = gfx_wait();
         switch (choice) {
            case 'w': // Ball jumps when 'w' is pressed
               jump = true;
               break;
            case 'r': // Restart when 'r' is pressed
               xc = r+1;
               yc = yground-r-1;
               count = 0;
               vx0 = 20;
               vx = vx0;
               vy = 0;
               deltat = 0.5;
               theta = 0;
               thetas = 0;
               elapsedtime = 0;
               vb = -15;
               dead = false;
               obstacles = false;
               newblock = true;
               horizon = 0;
               daycount = 0;
               xb = wd - wb/2;
               yb = yground - hb/2;
               reached = 0;
               system("clear");
               cout << "'w' to jump" << endl;
               cout << "'r' to restart" << endl;
               cout << "'q' to quit" << endl;
               cout << "Blocks reached:" << endl;
               break;
            case 'q': // Quits when 'q' is pressed
               loop = false;
               break;
         }
      }     
   }


   return 0;
}

// Adds spokes to ball
void spokes(int x, int y, int r, double theta)
{
   int x1, x2, x3, y1, y2, y3;
   double pi = 3.14159;   
   // Sets points
   x1 = x + r*cos(theta);
   x2 = x + r*cos(theta+2*pi/3);
   x3 = x + r*cos(theta+4*pi/3);
   y1 = y + r*sin(theta);
   y2 = y + r*sin(theta+2*pi/3);
   y3 = y + r*sin(theta+4*pi/3);
   //Draws line from center to each point
   gfx_line(x,y,x1,y1);
   gfx_line(x,y,x2,y2);
   gfx_line(x,y,x3,y3);
}

// Creates block
void block(int x, int y, int w, int yground)
{ 
   int wd = 20, ht = 30;
   int left = x-wd/2, right = x + wd/2, top = yground - ht, bottom = yground;
   
   for(int i = top; i <= bottom; i++) {
      gfx_line(left,i,right,i);
   }
}

// Creates sun if day and moon if not
void sun(bool day, double theta, int yground)
{
   double r = 250.0, rs = 30.0, rm = 20.0;
   int x = 250, y = 250, xc, yc;

   xc = x + r*cos(theta);
   yc = y + r*sin(theta);
   
   if (day) {
      if (yc + rs < yground) {
         gfx_color(255,255,0);
         gfx_circle(xc,yc,rs);
      }
   }
   else {
      if (yc + rm < yground) {
         gfx_color(255,255,255);
         gfx_circle(xc,yc,rm);
      }
   }
}
