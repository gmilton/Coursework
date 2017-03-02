// Lab 8
// lifeboard.cpp
// Grace Milton

#include <iostream>
#include <unistd.h>
#include <cstdlib>
using namespace std;
#include "lifeboard.h"

Lifeboard::Lifeboard()
{
   currBoard[size1][size2];
   tempBoard[size1][size2]; 
}

Lifeboard::~Lifeboard() { }

// Makes every cell in board dead
void Lifeboard::initialize()
{
   for (int i = 0; i < size1; i++) {
      for (int j = 0; j < size2; j++) {
         currBoard[i][j] = ' ';
         tempBoard[i][j] = ' ';
      }
   }
}

// Displays board
void Lifeboard::display()
{
   cout << " "; // Adds extra space so borders are lined up correctly
   for (int k = 0; k < size1; k++) { cout << "-"; } // Creates top border
   cout << endl;
   for (int i = 0; i < size1; i++) {
      cout << "|"; // Creates left border
      for (int j = 0; j < size2; j++) {
         cout << currBoard[i][j];
      }
      cout << "|" << endl; // Creates right border
   }
   // Creates bottom border
   cout << " ";
   for (int m = 0; m < size1; m++) { cout << "-"; }
   cout << endl;
}

// Sets cell to live
void Lifeboard::add(int x, int y)
{ currBoard[y][x] = 'X'; }

// Sets cell to dead
void Lifeboard::remove(int x, int y)
{ currBoard[y][x] = ' '; }

// Advances board to next stage according to rules of game
void Lifeboard::advance()
{ 
   int nAlive, nDead;
   char live = 'X', dead = ' ';
   for (int y = 0; y < size1; y++) {
      for (int x = 0; x < size2; x++) {
         tempBoard[y][x] = currBoard[y][x]; // Goes through board and sets tempBoard = currBoard
         // Checks that board is in boundaries and checks if neighbors are alive or dead
         for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
               if ((x+i) < 40 && (x+i) >= 0 && (y+j) < 40 && (y+j) >= 0) {
                  (currBoard[y+j][x+i]) == live ? (nAlive++) : (nDead++);
               }
            }
         }
         // Accounts for current cell that was counted among neighbors
         (currBoard[y][x] == live) ? (nAlive--) : (nDead--);
         // Kills cells with less than 2 or greater than 3 live neighbors
         if (nAlive < 2 || nAlive > 3) { tempBoard[y][x] = ' '; }
         // Regenerates cells with exactly 3 live neighbors
         if (nAlive == 3) { tempBoard[y][x] = 'X'; } 
         // Resets values for next loop
         nAlive = 0;
         nDead = 0; 
      }
   }
   // Sets current board = temporary board
   for (int k = 0; k < size1; k++) {
      for (int z = 0; z < size2; z++) {
         currBoard[k][z] = tempBoard[k][z];
      }
   }
}

// Continuosuly displays and advances board
void Lifeboard::continuous(Lifeboard &L)
{ 
   while(1) {
      L.display(); 
      L.advance(); 
      usleep(200000); // Pauses for 0.2 seconds between each advance 
      system("clear"); // Clears screen
   }
}
