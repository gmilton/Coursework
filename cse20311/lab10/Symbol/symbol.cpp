// Lab 10
// symbol.cpp
// Grace Milton
#include "gfx.h"
#include <cmath>
using namespace std;

// prototypes for different shapes
void square(int x, int y);
void triangle(int x, int y);
void circle(int x, int y);
void polygon(int x, int y, char choice);

int main()
{
   int x, y;
   char choice;
   bool run = true;

   gfx_open(500, 500, "Symbolic Typewriter"); // Opens window
   gfx_clear(); // Clears window
   
   // Runs while choice is not 'q'
   while(run) {
      choice = gfx_wait(); // Waits for event
      x = gfx_xpos(); // Gets x position of event
      y = gfx_ypos(); // Gets y position
      switch (choice) {
         case 1: // creates square when mouse button 1 clicked
            square(x,y);
            break;
         case 't': // creates triangle if 't' pressed
            triangle(x,y);
            break;
         case 'c': // creates circle if 'c' pressed
            circle(x,y);
            break;
         case '3': // creates polygon of n sides if 3-9 is pressed
         case '4':
         case '5':
         case '6':
         case '7':
         case '8':
         case '9':
            polygon(x,y,choice);
            break;
         case 'q':   // quits when 'q' is pressed
            run = false;
            break;
      }
   }
      

   return 0;
}

// Creates blue square
void square(int x,int y)
{
   // Makes blue
   gfx_color(0, 0, 255);

   // Draws four lines
   gfx_line(x-13,y+13,x+13,y+13);
   gfx_line(x-13,y-13,x+13,y-13);
   gfx_line(x-13,y-13,x-13,y+13);
   gfx_line(x+13,y-13,x+13,y+13);
}

// Creates green triangle
void triangle(int x, int y)
{  
   // Makes green
   gfx_color(0, 255, 0);

   // Draws three lines
   gfx_line(x-13,y-13,x+13,y-13);
   gfx_line(x-13,y-13,x,y+13);
   gfx_line(x,y+13,x+13,y-13);
}

// Creates white circle
void circle(int x, int y)
{
   // Makes white
   gfx_color(255, 255, 255);

   // Draws circle
   gfx_circle(x,y,13);
}

// Creates polygon of n sides
void polygon(int x, int y, char nsides)
{
   double r = 13.0, x1 = x + r, y1 = y, x2, y2, n = nsides - '0';

   // Runs through and adds a line to the polygon for number of sides chosen
   for (int i = 1; i <= n; i++) {
      x2 = x + r*cos((i*2.0*3.14159)/n); // Sets x coordinate of destination
      y2 = y + r*sin((i*2.0*3.14159)/n); // Sets y coordinate of destination
      gfx_color(148, 0, 211); // Makes purple
      gfx_line(x1,y1,x2,y2); // Draws line
      
      // Makes current destination source of next line
      x1 = x2;
      y1 = y2;
   } 
}
