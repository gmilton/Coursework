// Grace Milton
// CSE 20312 Lab 01
// c4board.h
//
// Interface for the C4Board class (connect four board)

#include <iostream>
using namespace std;
#include "c4col.h"

#ifndef C4BOARD_H
#define C4BOARD_H

class C4Board {

   public:
      C4Board(); // default constructor
      ~C4Board(); // deconstructor
      C4Board(const C4Board &); // copy constructor

      // method functions
      void display(); // displays board
      void play(); // plays game
      void setAI(bool); // Sets AI to true or false

   private:
      C4Col *board;
      int numCols; // number of columns in board
      int findWinner(); // finds when a player has won
      bool AI;

};

#endif
