// Grace Milton
// CSE 20312 Lab 04
// board.cpp
//
// Implementation for Board class for sudoku

#include <iostream>
#include <vector>
using namespace std;
#include "board.h"

// Constructor
Board::Board() { }

// Deconstructor
Board::~Board() { }

// Initializes Board to values read in from file
void Board::initialize(int a[])
{

   int i = 0;

   for (int y = 0; y < numRows; y++)
   {
      for (int x = 0; x < numCols; x++)
      {
         board[y][x].setValue(a[i++]); // Sets board value to value in array
         if (board[y][x].getValue() != 0) // Checks for non-zero value
         {
            board[y][x].clearPossibles(); // Clears possibilities for that cell
            board[y][x].addPossible(board[y][x].getValue()); // Makes its only possibility its value
         }
      }
   }

}

// Returns value if it is the only possibility for a cell
int Board::singlePoss(int r, int c)
{

   if (board[r][c].getNumPossibles() == 1)
      return board[r][c].getPossible(0);
   else
      return 0; // Otherwise returns 0

}

// Performs singleton operation on a single row
// If a value is a possibility for only one cell, it becomes the only possibility for that cell
void Board::singletonRow(int r0)
{	

   int x;
   int count[10];
   bool match = false;

   // Initializes freq array for values to 0
   for (int i = 0; i < 10; i++)
      count[i] = 0;

   // Counts the frequency of each possibility 
   for (int c = 0; c < numCols; c++) // Runs through every column
   {
      for (int i = 0; i < board[r0][c].getNumPossibles(); i++) // Runs through all possibilities for a given cell
      {
         x = board[r0][c].getPossible(i);
         count[x]++;         
      }
   }

   for (int j = 1; j < 10; j++) // For 1-9
   {
      if (count[j] == 1) // If a possibility appeared once
      {
         for (int c = 0; c < numCols; c++) // For each column
         {
            for (int i = 0; i < board[r0][c].getNumPossibles(); i++) // For all the possibilities of each cell
            {
               if (board[r0][c].getPossible(i) == j && board[r0][c].getValue() == 0) // If value = 0 and it matches the given possibility
               {
                  board[r0][c].clearPossibles(); // Clear possibilities
                  board[r0][c].addPossible(j); // Make given poss only poss
                  match = true; // match found
               }
               if (match == true) { break; }
            }
            if (match == true) { break; }
         }
      }
   }
 
}

// Performs singleton operation of column
void Board::singletonCol(int c0)
{

   int x;
   int count[10];
   bool match = false;

   // Initializes freq array to 0
   for (int i = 0; i < 10; i++)
      count[i] = 0;

   // Sets freq array (same as singletonRow but change rows)
   for (int r = 0; r < numRows; r++) // For each row
   {
      for (int i = 0; i < board[r][c0].getNumPossibles(); i++)
      {
         x = board[r][c0].getPossible(i);
         count[x]++;
      }
   }
   for (int j = 1; j < 10; j++)
   {
      if (count[j] == 1)
      {
         for (int r = 0; r < numRows; r++) // For each row
         {
            for (int i = 0; i < board[r][c0].getNumPossibles(); i++)
            {
               if (board[r][c0].getPossible(i) == j && board[r][c0].getValue() == 0)
               {
                  board[r][c0].clearPossibles();
                  board[r][c0].addPossible(j);
                  match = true;
               }
               if (match == true) { break; }
            }
            if (match == true) { break; }
         }
      }
   }

}

// Performs singleton operation for 3x3 block
void Board::singletonBlock(int r0, int c0)
{

   int x, r, c, rmin, rmax, cmin, cmax;
   int count[10];
   bool match = false;

   // Initializes freq array
   for (int i = 0; i < 10; i++)
      count[i] = 0;
   
   // Take modulus of row and col to see where cell falls in block
   r = r0 % 3;
   c = c0 % 3;

   switch(r) // Set boundaries for row
   {
      case 0: // top
         rmin = 0;
         rmax = 2;
         break;
      case 1: // middle
         rmin = -1;
         rmax = 1;
         break;
      case 2: // bottom
         rmin = -2;
         rmax = 0;
         break;
   }

   switch(c) // Set boundaries for column
   {
      case 0: // left
         cmin = 0;
         cmax = 2;
         break;
      case 1: // middle
         cmin = -1;
         cmax = 1;
         break;
      case 2: // right
         cmin = -2;
         cmax = 0;
         break;
   }

   // Sets freq array
   for (int i = rmin; i <= rmax; i++)
   {  
      for (int j = cmin; j <= cmax; j++)
      { 
         for (int k = 0; k < board[r0+i][c0+j].getNumPossibles(); k++)
         {     
            x = board[r0+i][c0+j].getPossible(k);
            count[x]++;
         }
      }
   }
   for (int z = 1; z < 10; z++)
   {  
      if (count[z] == 1)
      {  
         for (int i = rmin; i <= rmax; i++)
         {
            for (int j = cmin; j <= cmax; j++)
            {
               for (int k = 0; k < board[r0+i][c0+j].getNumPossibles(); k++)
               {  
                  if (board[r0+i][c0+j].getPossible(k) == z && board[r0+i][c0+j].getValue() == 0)
                  {  
                     board[r0+i][c0+j].clearPossibles(); // Clear possibilities
                     board[r0+i][c0+j].addPossible(z); // Set possibility to value
                     match = true;
                  }
                  if (match == true) { break; }
               }
               if (match == true) { break; }
            }
            if (match == true) { break; }
         }
      }
   }

}

// Adjusts possibilities as new values are added
void Board::adjustPossibles(int r0, int c0)
{

   int v, r, c, rmin, rmax, cmin, cmax;

   // Takes modulus to find place in mini-grid
   r = r0 % 3;
   c = c0 % 3;

   switch(r) // Set boundaries for row
   {  
      case 0: // top
         rmin = 0;
         rmax = 2;
         break;
      case 1: // middle
         rmin = -1;
         rmax = 1;
         break;
      case 2: // bottom
         rmin = -2;
         rmax = 0;
         break;
   }

   switch(c) // Set boundaries for column
   {  
      case 0: // left
         cmin = 0;
         cmax = 2;
         break;
      case 1: // middle
         cmin = -1;
         cmax = 1;
         break;
      case 2: // right
         cmin = -2;
         cmax = 0;
         break;
   }

   // Checks each row
   for (int c = 0; c < numCols; c++)
   {
      if (board[r0][c].getValue() != 0 && c != c0) // Find non-zero values
      {
         v = board[r0][c].getValue();
         for (int i = 0; i < board[r0][c0].getNumPossibles(); i++)
         {
            if (board[r0][c0].getPossible(i) == v) 
            {	
		board[r0][c0].deletePossible(i); // Deletes possibility if it equals given non-zero value
            }
         }
      }
   }

   // Checks each column
   for (int r = 0; r < numRows; r++)
   {
      if (board[r][c0].getValue() != 0 && r != r0) // Finds non-zero value
      {
         v = board[r][c0].getValue();
         for (int i = 0; i < board[r0][c0].getNumPossibles(); i++)
         {
            if (board[r0][c0].getPossible(i) == v) 
            { 
               board[r0][c0].deletePossible(i); // Deletes possibility
            }
         }
      }
   }

   // Checks mini-grids (blocks)
   for (int r = rmin; r <= rmax; r++)
   {
      for (int c = cmin; c <= cmax; c++)
      {
         if (board[r0+r][c0+c].getValue() != 0 && (r != 0 || c != 0)) // Finds non-zero
         {
            v = board[r0+r][c0+c].getValue();
            for (int i = 0; i < board[r0][c0].getNumPossibles(); i++)
            {
               if (board[r0][c0].getPossible(i) == v)
               {
                  board[r0][c0].deletePossible(i); // Deletes possibility from other cells
               }
            }
         }
      }
   }

}

// Solves sudoku puzzle
void Board::play() 
{

   int a;
   bool done = false;

   // Runs through puzzle until no zeros
   while (done == false)
   {
      done = true;
      for (int y = 0; y < numRows; y++)
      {
         for (int x = 0; x < numCols; x++)
         {
            adjustPossibles(y, x);
            a = board[y][x].getValue();
            if (a == 0) // If cell value = 0
            { 
               done = false;
               singletonRow(y);
               singletonCol(x);
               singletonBlock(y, x);
               a = singlePoss(y,x);
               board[y][x].setValue(a); 
               adjustPossibles(y, x);
            }  
         } 
      }
   }

}

// Overloaded output operator
ostream &operator<<(ostream &s, const Board &b)
{ 
   for (int y = 0; y < 9; y++)
   {
      if (y % 3 == 0)
      {
         s << " ";
         for (int i = 0; i < 23; i++)
            s << "-";
         s << endl;
      }
      for (int x = 0; x < 9; x++)
      {
         if (x % 3 == 0)
            s << "| ";
         Cell c = b.board[y][x];
         s << c.getValue() << " ";
      }
      s << "|" << endl;
   }
   s << " ";
   for (int i = 0; i < 23; i++)
      s << "-";
   s << endl;

   return s;

}
