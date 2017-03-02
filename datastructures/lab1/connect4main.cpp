// Grace Milton
// connect4main.cpp
//
// Driver for connect four

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
#include "c4board.h" // class definition for C4Board

int main() {

   C4Board c4; // Instantiates board
   char method;
   srand(time(NULL)); // Sets random seed 

   // Menu to choose mode
   cout << "Select a method of play:" << endl;
   cout << "	p: 2 Player" << endl;
   cout << "	c: Computer AI" << endl;
   cout << "Enter choice: ";
   cin >> method;
   switch (method) {
      case 'c': // AI
         c4.setAI(true);
	 break;
      case 'p': // 2 Player
         c4.setAI(false);
         break;
      default: // Defaults to 2 Player
         cout << "Oops! You entered an invalid method. Defaulting to 2 Player." << endl;
         c4.setAI(false);
         break;
   }

   c4.play(); // Plays game

}
   
