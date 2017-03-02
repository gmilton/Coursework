// Grace Milton
// CSE 20312 Lab 01
// c4col.cpp
//
// Implementation for C4Col class (columns for connect four board)

#include <iostream>
using namespace std;
#include "c4col.h"

C4Col::C4Col() // default constructor 
{
   
   numDiscs = 0; 
   maxDiscs = 6;
   Discs = new char[maxDiscs];  
   for (int i = 0; i < maxDiscs; i++) // Initializes column to empty
      Discs[i] = ' ';

}

C4Col::~C4Col() // deconstructor
{ delete [] Discs; }

C4Col::C4Col(const C4Col &copy) : maxDiscs(copy.maxDiscs) // copy constructor
{

  Discs = new char[maxDiscs];

  for (int i = 0; i < maxDiscs; i++)
     Discs[i] = copy.Discs[i];

}

int C4Col::isFull() // Checks to see if column is full
{
   if (numDiscs==maxDiscs) 
      return 1;
   else
      return 2;
}

char C4Col::getDisc(int i) // Returns value of disc in column
{ 
   if (i >= 0 && i <= 5) 
      return Discs[i]; 
   else
      cout << "ERROR: INVALID PARAMETER" << endl;
}

int C4Col::getMaxDiscs() // Returns max number of discs
{ return maxDiscs; }

void C4Col::addDisc(char newDisc) // Adds new disc to column
{ 
   if (numDiscs < maxDiscs)
      Discs[numDiscs++] = newDisc; 
   else // Displays error message if full
      cout << "Column is full! Please choose another." << endl;
}
