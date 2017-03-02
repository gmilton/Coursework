// Grace Milton
// CSE 20312 Lab 02 Part 3
// blackjack.h
//
// Interface for the CardDeck class with functions for Blackjack

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include <vector>
using namespace std;

class BlackJack {

 public:
     BlackJack(int = 52, int = 0, int = 0); // non-default constructor 
     ~BlackJack(); // deconstructor

     int getSize(); // Returns size of deck
     void shuffle(); // Shuffles deck
     void deal(vector<int> &); // Deals card
     void play();
     void printHand(vector<int> &);

  private:
     int *deck;
     int size;
     int card;
     int playerWins;
     int dealerWins;
     vector<int> playerHand;
     vector<int> dealerHand;

};

#endif
