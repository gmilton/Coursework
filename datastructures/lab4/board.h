// Grace Milton
// CSE 20312 Lab 04
// board.h
//
// Interface for Board class for sudoku

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
using namespace std;
#include "cell.h"

class Board {

  friend ostream &operator<<(ostream &, const Board &); // overload output

  public:
     Board(); // constructor
     ~Board(); // deconstructor
     void initialize(int a[]);  
     int singlePoss(int, int); // single possibility
     void singletonRow(int row);
     void singletonCol(int col);
     void singletonBlock(int, int);
     void adjustPossibles(int, int);
     void play(); // Solves sudoku

  private:
     Cell board[9][9];
     int numRows = 9;
     int numCols = 9;

};

#endif
