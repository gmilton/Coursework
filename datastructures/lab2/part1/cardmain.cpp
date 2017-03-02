// Grace Milton
// CSE 20312 Lab 02 Part 1
// cardmain.cpp
//
// Driver for CardDeck class
// Prints a deck of 10 cards, shuffles, then prints again

#include <iostream>
#include <cstdlib>
#include<time.h>
using namespace std;
#include "carddeck.h"

int main() {
   
   CardDeck myDeck(10); // Instantiates deck of size 10
   srand(time(NULL)); // Sets seed for rand

   cout << myDeck; // Displays unshuffled deck
   myDeck.shuffle(); // Shuffles deck
   cout << myDeck; // Displays shuffled deck

   return 0;

}
