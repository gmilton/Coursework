// Grace Milton
// CSE 20312 Lab 01
// c4board.cpp
//
// Implementation for C4Board class (connect four board)

#include <iostream>
#include <cstdlib>
using namespace std;
#include "c4board.h"

C4Board::C4Board() // default constructor
{ 
   numCols = 7; 
   board = new C4Col[numCols];
}

C4Board::~C4Board() // deconstructor
{ delete [] board; }

C4Board::C4Board(const C4Board &copy) : numCols(copy.numCols) // copy constructor 
{

  board = new C4Col[numCols];
  for ( int i = 0; i < numCols; i++ )
    board[i] = copy.board[i];

}

void C4Board::display() // Displays board
{ 
   cout << "  1  2  3  4  5  6  7" << endl; // Displays column numbers above board
   for (int i = board[0].getMaxDiscs() - 1; i >= 0; i--) 
   {
      cout << "|";
      for (int j = 0; j < numCols; j++) 
         cout << board[j].getDisc(i) << " |";
      cout << endl;
   }
}

void C4Board::play() // Plays game
{ 
   int move = numCols, turn = 0, player = 1, full, gameover;

   while (move != -1) { // Runs while move does not equal -1
      cout << endl;
      display(); // Displays board
      if (AI != true) { // 2 Player mode
         cout << "Player " << player << ", choose a column to place a piece, or -1 to end game: "; // Prompts player for column
         cin >> move;
      } 
      else if (AI == true && player == 1) { // Computer Mode
         cout << "Player 1, choose a column to place a piece, or -1 to end game: "; // Prompts player for column
         cin >> move;
      }
      else if (AI == true && player == 2) { // Computer chooses column
         move = rand() % 6 + 1;
         while (board[move-1].isFull() == 1)
            move = rand() % 6 + 1; 
         cout << "Computer chose column " << move << "." << endl;
      }
      if (move >= 1 && move <= numCols) { // Adds disc if column valid
         full = board[move-1].isFull(); // Checks if column full
         if (player == 1)
            board[move-1].addDisc('X'); // Adds piece for player 1
         else
            board[move-1].addDisc('O'); // Adds piece for player 2
         if (full != 1) { // Continues to next turn only if valid and not full column
            turn++; // Increments turn
            player = (turn % 2) + 1; // Switches player
            gameover = findWinner(); // Determines if the game has been won
         }
      }
      else if (move == -1) { // Displays message if player ends game
         cout << "Thanks for playing!" << endl;
      }
      else { // Prompts user for valid column number
         cout << "Please enter valid column number." << endl;
      }
      if (gameover > 0) { break; } // Exits while loop if game has been one
      if (turn >= 42) { break; } // Exits while loop if board is full
   }
   if (gameover > 0) { // Displays message if game is won
      cout << endl;
      display();
      if (AI != true) // End message for 2 Player Mode
         cout << "Player " << gameover <<" won! Thanks for playing!" << endl;  
      else if (AI == true) { // End messages for Computer Mode
         if (gameover == 1)
            cout << "Player 1 won! Thanks for playing!" << endl;
         else if (gameover == 2)
            cout << "The computer won! Thanks for playing!" << endl;
      }
   }
   else if (move != -1) { // Displays message is board is filled with no winner
      cout << endl;
      display();
      cout << "It's a tie!" << endl;
   }
}

void C4Board::setAI(bool b) // Sets AI based on mode user chooses
{ AI = b; }

int C4Board::findWinner() // Determines if player has won
{

   int won = 0; // Represents winner: 0 for no winner, 1 for player 1, 2 for player 2
   int hWin1 = 0, hWin2 = 0; // Track if there is a horizontal row of 4 for each player
   int vWin1 = 0, vWin2 = 0; // Track if there is a vertical row of 4 for each player
   int lWin1 = 0, lWin2 = 0; // Track if there is a left-slanted diagonal of 4 for each player
   int rWin1 = 0, rWin2 = 0; // Track if there is a right-slanted diagonal of 4 for each player

   for (int i = 0; i <= board[0].getMaxDiscs() - 1; i++) // Runs through all the rows of the board
   {
      for (int j = 0; j < numCols; j++) // Runs through all the columns
      {
         for (int k = 1; k <= 3; k++) // Represents neighbors 1-3 spaces away from disc 
         {
            if (j + 3 < numCols) // Only checks in bounds 
            { 
               // Increments counter for horizontal win for player 1
               if (board[j].getDisc(i) == 'X') 
               {
                  if (board[j+k].getDisc(i) == 'X') 
                  { 
                     hWin1++; 
                  }
               }
               // Increments counter for horizontal win for player 2
               else if (board[j].getDisc(i) == 'O') 
               {
                  if (board[j+k].getDisc(i) == 'O') 
                  {
                     hWin2++;
                  }
               }
               if (i - 3 >= 0) // Only checks in bounds 
               {
                  // Increments counter for left-slanted diagonal win for player 1
                  if (board[j].getDisc(i) == 'X')
                  {
                     if (board[j+k].getDisc(i-k) == 'X')
                     {
                        lWin1++;
                     }
                  }
                  // Increments counter for left-slanted diagonal win for player 2
                  else if (board[j].getDisc(i) == 'O')
                  {
                     if (board[j+k].getDisc(i-k) == 'O')
                     {
                        lWin2++;
                     }
                  }
               }
            }
            if (i - 3 >= 0 && j - 3 >= 0) // Only checks in bounds
            {  
               // Increments counter for right-slanted diagonal win for player 1 
               if (board[j].getDisc(i) == 'X')
               {  
                  if (board[j-k].getDisc(i-k) == 'X')
                  {  
                     rWin1++;
                  }
               }
               // Increments counter for right-slanted diagonal win for player 2
               else if (board[j].getDisc(i) == 'O')
               {  
                  if (board[j-k].getDisc(i-k) == 'O')
                  {
                     rWin2++;
                  }
               }
            }
            if (i + 3 < board[0].getMaxDiscs() - 1) // Only checks in bounds 
            {
               // Increments counter for vertical win for player 1
               if (board[j].getDisc(i) == 'X')
               {
                  if (board[j].getDisc(i+k) == 'X')
                  {
                     vWin1++;
                  }
               }
               // Increments counter for vertical win for player 2
               else if (board[j].getDisc(i) == 'O')
               {
                  if (board[j].getDisc(i+k) == 'O')
                  {
                     vWin2++;
                  }
               }
            }
         }
         if (hWin1 == 3 | vWin1 == 3 | lWin1 == 3 | rWin1 == 3) { won = 1; break; } // Sets player 1 as winner and breaks if win in any direction
         else if (hWin2 == 3 | vWin2 == 3 | lWin2 == 3 | rWin2 == 3) { won = 2; break; } // Sets player 2 as winner and breaks if win in any direction
        
         // Resets all counters for next disc
         hWin1 = 0;
         hWin2 = 0;
         lWin1 = 0;
         lWin2 = 0;
         rWin1 = 0;
         rWin2 = 0;
         vWin1 = 0;
         vWin2 = 0;
      }
      if ( won > 0) { break; } // Exits loop if winner
   }

   return won; // Returns value for player that won or 0 for no winner
 
}
