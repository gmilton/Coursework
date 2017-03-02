// Grace Milton
// CSE 20312 Lab 04
// sudoku.cpp
//
// Main driver for sudoku (Cell and Board classes)

#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <stdio.h>
using namespace std;
#include "cell.h"
#include "board.h"

int main() {

   Board sudoku;
   string filename;
   int values[81];
   char c;
   int i = 0;
   ifstream ifs;

   // Initializes array to zero
   for (int i = 0; i < 81; i++)
      values[i] = 0;

   // Prompts user for file
   cout << "Please input filename: ";
   cin >> filename;
   ifs.open(filename);
   if (!ifs) // Returns error message if invalid file
   {
      cout << "error opening file " << filename << endl;
      return 1;
   }

   c = ifs.get(); // Gets first character in file
   while (!ifs.eof())
   {
      if (!isspace(c)) // If not space
         values[i++] = c - 48; // Turns into int and places in array
      c = ifs.get(); // Gets next character
   }

   sudoku.initialize(values); // Initializes board w/ values from array
   
   // Displays initial board
   cout << "Problem:" << endl;
   cout << sudoku;
   cout << endl;

   sudoku.play(); // solves
   
   // Displays solution
   cout << "Solution:" << endl;
   cout << sudoku;
   cout << endl;

   return 0;

}
