// Grace Milton
// CSE 20312 Lab 04
// cell.cpp
//
// Implementation for Cell class for sudoku

#include <iostream>
#include <vector>
using namespace std;
#include "cell.h"

// Constructor
Cell::Cell()
{

   value = 0; // Sets each cell to empty
   for (int i = 0; i < 9; i++)
      addPossible(i+1); // Sets possibles to 1-9

}

// Returns value for cell
int Cell::getValue()
{ return value; }

// Returns number of possibles
int Cell::getNumPossibles()
{ return possibles.size(); }

// Returns possible value given a place in the vector
int Cell::getPossible(int i)
{ return possibles.at(i); }

// Sets value
void Cell::setValue(int v)
{ value = v; }

// Clears all possibilities for a cell
void Cell::clearPossibles()
{ possibles.clear(); }

// Adds possibility for cell
void Cell::addPossible(int p)
{ possibles.push_back(p); }

// Erases possibility for a cell at a certain position in vector
void Cell::deletePossible(int p)
{ possibles.erase(possibles.begin()+p); }
