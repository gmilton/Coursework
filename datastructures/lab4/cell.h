// Grace Milton
// CSE 20312 Lab 04
// cell.h
//
// Interface for the Cell class for sudoku

#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <vector>
using namespace std;

class Cell {

  public:
     Cell(); // constructor
     int getValue();
     int getNumPossibles();
     int getPossible(int);
     void setValue(int);
     void clearPossibles();
     void addPossible(int);
     void deletePossible(int);

  private:
     int value;
     vector<int> possibles; // Possible values for sudoku cell

};

#endif
