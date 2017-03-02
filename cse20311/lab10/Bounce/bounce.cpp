// Lab 10
// bounce.cpp
// Grace Milton
#include <cstdlib>
#include <cmath>
#include <unistd.h>
#include <time.h>
#include "gfx.h"

int main() 
{
   double xc = 250, yc = 250, vx = 6, vy = 8, deltat = 0.5;
   int r = 20, wd = 500, ht = 500, c, click;
   bool loop = true; 
   srand(time(NULL));  
   char choice;
   
   // opens new window
   gfx_open(wd,ht,"Bouncing Ball");

   // runs while 'q' not pressed
   while(loop) {   
      c = gfx_event_waiting(); // waits for event
      gfx_clear(); // clears screen
      gfx_color(255,255,255); // makes circle white
      gfx_circle(xc,yc,r); // creates circle
      gfx_flush();
      usleep(80000); 
      // moves circle based on velocity
      xc = xc + vx*deltat; 
      yc = yc + vy*deltat;
      if (xc <= r) { // checks left boundary
        xc = r + 1;
        vx = -vx;
      }
      if (xc >= wd - r) { // checks right boundary
         xc = wd - r - 1;
         vx = -vx;
      }
      if (yc <= r) { // checks top boundary
         yc = r + 1;
         vy = -vy;
      }
      if (yc >= ht - r) { // checks bottom boundary
         yc = ht - r - 1;
         vy = -vy;
      }
      // enters if event occurs
      if (c == 1) {
         choice = gfx_wait();
         switch(choice) {
            case 'q': // quits if 'q' is pressed
               loop = false;
               break;
            default:
               click = int(choice);
               if(click == 1) { // starts new ball if mouse clicked
                  xc = gfx_xpos();
                  yc = gfx_ypos();
                  vx = rand() % 40 - 20;
                  vy = rand() % 40 - 20;
               }
               break;
         }  
      }
   }

   return 0;
}
