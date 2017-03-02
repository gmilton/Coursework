// Grace Milton
// CSE 20312 Lab 02 Part 3
// main.cpp
//
// Driver for CardDeck class with blackjack functions
// Plays blackjack with one player and dealer

#include <iostream>
#include <cstdlib>
#include<time.h>
using namespace std;
#include "blackjack.h"

int main() {
   
   BlackJack myDeck; // Instantiates deck
   srand(time(NULL)); // Sets seed for rand

   myDeck.shuffle(); // Shuffles deck
   myDeck.play(); // Plays blackjack

}
