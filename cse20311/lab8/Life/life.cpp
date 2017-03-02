// Lab 8
// life.cpp
// Grace Milton

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
#include "lifeboard.h"

int main(int argc, char *argv[])
{
   Lifeboard myboard;
   char choice;
   int x, y;
   ifstream ifs;
   string choice_s, x_s, y_s;

   // Initializes Lifeboard
   myboard.initialize();
   // Displays Lifeboard
   myboard.display();

   // Switch case based on number of inputs in command line
   switch (argc) {
      // One argument = Interactive Mode
      case 1:
         // Prompts user for choice
         cout << "Enter choice: ";
         cin >> choice;
         // Runs while choice is not q
         while (choice != 'q') {
            switch (choice) {
               case 'a': // Add live cell
                  // Prompts user for x y coordinates of cell
                  cout << "Coordinates for cell to be added: ";
                  cin >> x >> y;
                  myboard.add(x,y); // Adds cell
                  myboard.display(); // Displays board
                  // Prompts user for next choice
                  cout << "Enter choice: ";
                  cin >> choice;
                  break;
               case 'r': // Remove live cell
                  // Prompts user for x y coordinates of cell
                  cout << "Coordinates for cell to be removed: ";
                  cin >> x >> y;
                  myboard.remove(x,y); // Removes live cell
                  myboard.display(); // Displays board
                  // Prompts user for next choice
                  cout << "Enter choice: ";
                  cin >> choice;
                  break;
               case 'n': // Advances board to next stage based on rules of game
                  myboard.advance(); // Advances board
                  myboard.display(); // Displays board
                  // Prompts user for next choice
                  cout << "Enter choice: ";
                  cin >> choice;
                  break;
               case 'q': // Quits program
                  break;
               case 'p': // Plays game continuously
                  myboard.continuous(myboard); 
                  break;
               default: // Displays error message if invalid input
                  cout << "ERROR INVALID INPUT" << endl;
                  // Prompts user for valid choice
                  cout << "Enter choice: ";
                  cin >> choice;
                  break;
            }
         }
         cout << "Goodbye!" << endl;
         break;
      // Two arguments = Batch Mode; second argument = name of file to be opened
      case 2:
         ifs.open(argv[1]); // Opens file with same name as second argument
         // Makes sure file is valid
         if(!ifs) {
            cout << "inavlid argument: " << argv[1] << endl;
            return 1;
         }
         // Gets first choice as string
         getline(ifs, choice_s, ' ');
         // Converts string to char
         choice = choice_s[0];
         // Collects and carries out commands until 'p' is read
         while(choice != 'p') {
            // Gets x coordinate as string
            getline(ifs, x_s, ' ');
            // Gets y coordinate as string
            getline(ifs, y_s, '\n');
            // Converts strings to ints
            x = stoi(x_s);
            y = stoi(y_s);
            switch (choice) {
               case 'a': // Adds live cell
                  myboard.add(x,y);
                  myboard.display();
                  break;
               case 'r': // Removes live cell
                  myboard.remove(x,y);
                  myboard.display();
                  break;
               default: // Displays error if necessary
                  cout << "ERROR" << endl;
                  break;
            }
            // Gets next choice as string
            getline(ifs, choice_s, ' ');
            // Converts string to char
            choice = choice_s[0];
         }
         // Plays game continously once file is completely read
         myboard.continuous(myboard);
         break;
      default: // Displays error if incorrect number of arguments
         cout << "Too many arguments." << endl; 
         break;
      
   } 

   return 0;

}  
