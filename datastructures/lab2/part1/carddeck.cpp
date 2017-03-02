// Grace Milton
// CSE 20312 Lab 02 Part 1
// carddeck.cpp
//
// Implementation for CardDeck class

#include <iostream>
#include <cstdlib>
using namespace std;
#include "carddeck.h"


CardDeck::CardDeck(int c) // non-default constructor
{ 

   size = c; 
   deck = new int[size];
   for (int i = 0; i < size; i++) // Initializes deck with integers 0-size
      deck[i] = i;

}

CardDeck::~CardDeck() // deconstructor
{ delete [] deck; }

int CardDeck::getSize() // Returns size of deck
{ return size; }

void CardDeck::shuffle() // Shuffles deck
{ 
  
   int temp, j;

   // Knuth's algorithm
   for (int i = size - 1; i > 0; i--) 
   {
      j = rand() % i; 
      temp = deck[j];
      deck[j] = deck[i];
      deck[i] = temp;
   }

}

ostream& operator<< (ostream &s, CardDeck &c) // overloaded output operator
{

   s << c.deck[0]; // Displays first card in deck
   for (int i = 1; i < c.size; i++)
      s << ", " << c.deck[i]; // Displays rest of deck
   s << endl; // End-of-line character

   return s;

}
