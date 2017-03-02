// Grace Milton
// CSE 20312 Lab 01
// c4col.h
//
// Interface for the C4Col class (columns for the connect four board)

#include <iostream>
using namespace std;

#ifndef C4COL_H
#define C4COL_H

class C4Col {

   public:
      C4Col(); // default constructor
      ~C4Col(); // deconstructor
      C4Col(const C4Col &); // copy constructor     
 
      // member functions
      int isFull();
      char getDisc(int);
      int getMaxDiscs();
      void addDisc(char);

   private:
      char *Discs;
      int numDiscs; // number of discs in a column
      int maxDiscs; // max number of discs in a column

};

#endif
