// Grace Milton
// CSE 20312 Lab 02 Part 1
// carddeck.h
//
// Interface for the CardDeck class

#include <iostream>
using namespace std;

#ifndef CARDDECK_H
#define CARDDECK_H

class CardDeck {

  friend ostream &operator<<(ostream &, CardDeck &); // overloaded output operator

  public:
     CardDeck(int = 52); // non-default constructor 
     ~CardDeck(); // deconstructor

     int getSize(); // Returns size of deck
     void shuffle(); // Shuffles deck

  private:
     int *deck;
     int size;

};

#endif
