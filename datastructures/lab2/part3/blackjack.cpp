// Grace Milton
// CSE 20312 Lab 02 Part 3
// blackjack.cpp
//
// Implementation for CardDeck class with blackjack functions

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
#include "blackjack.h"


BlackJack::BlackJack(int c, int p, int d) // non-default constructor
{ 

   size = c;
   card = 0; 
   playerWins = p;
   dealerWins = d;
   deck = new int[size];
   for (int i = 0; i < size; i++) // Initializes deck with integers 0-size
      deck[i] = i;

}

BlackJack::~BlackJack() // deconstructor
{ delete [] deck; }

int BlackJack::getSize() // Returns size of deck
{ return size; }

void BlackJack::shuffle() // Shuffles deck
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

void BlackJack::deal(vector<int> &h) // Deals card to hand and increments card
{ h.push_back(deck[card++]); }

void BlackJack::play() // Plays blackjack
{

   int dealerScore = 0, playerScore = 0;
   char play = 'p'; 
   bool bust = false, firstDeal = true, dealerStands = false, badPlay = true;

   while (play != 's' && bust == false) { // Player not standing & no busts
      if (firstDeal == true) // First deal of game
      {   
         for (int i = 0; i < size; i++) // Initializes deck to correct range
            deck[i] = deck[i] % 13 + 2;
         // Deal 1st 2 cards to dealer and player
         for (int i = 1; i <= 2; i++) 
         {
            deal(playerHand);
            deal(dealerHand);
         }         
         // Sums player's and dealer's hands
         for (int i = 0; i < 2; i++)
         {
            if (playerHand[i] < 11) // Sum player's cards
               playerScore += playerHand[i];
            else if (playerHand[i] == 14) // Aces worth 11
               playerScore += 11;
            else // Face cards worth 10
               playerScore += 10;
            if (dealerHand[i] < 11) // Sums dealer's
               dealerScore += dealerHand[i];
            else if (dealerHand[i] == 14)
               dealerScore += 11;
            else
               dealerScore += 10;  
         }
         // Displays player's hand
         cout << endl << "Player's hand: ";
         printHand(playerHand);
         cout << endl;
         // Display dealer's hand
         cout << "Dealer's hand: ";
         printHand(dealerHand);
         cout << endl;
         // Account for being dealt 2 Aces at start
         if (playerScore > 21)
         {
            bust = true;
            cout << endl << "Player busts!" << endl;
         }
         else if (dealerScore > 21)
         {
            bust = true;
            cout << endl << "Dealer busts!" << endl;
         }
         firstDeal = false; // No longer first deal
      }
      // Asks player for their move
      cout << "Hit (h) or stand (s)? ";
      cin >> play;      
      do 
      {
         switch (play) {
            case 'h': // Hit
               deal(playerHand); // Adds next card to hand
               // Sums hand
               if (deck[card-1] < 11)
                  playerScore += deck[card-1];
               else if (deck[card-1] == 14)
                  playerScore += 11;
               else
                  playerScore += 10;
               // Displays new hand
               cout << endl;
               cout << "Player hits." << endl;
               cout << "Player's hand: ";
               printHand(playerHand);
               cout << endl;
               if (playerScore > 21) // Busts
               {       
                  bust = true;
                  cout << "Player busts." << endl;
               }
               badPlay = false;
               break;
            case 's': // Stand
               // Displays new hand
               cout << endl;
               cout << "Player stands." << endl;
               cout << "Player's hand: ";
               printHand(playerHand);
               cout << endl;
               badPlay = false;
               break;
            default: // Displays error message
               badPlay = true;
               cout << "Please enter valid choice." << endl;
               cout << "Hit (h) or stand (s)? ";
               cin >> play;
               break;
         }
      } while (badPlay == true && bust == false);
      do { // Dealer's turn
         if (dealerScore < 17 && bust == false) // Dealer can only hit on < 17
         {
            deal(dealerHand); // Adds new card to hand
            // Sums hand
            if (deck[card-1] < 11)
               dealerScore += deck[card-1];
            else if (deck[card-1] == 14)
               dealerScore += 11;
            else
               dealerScore += 10;
            cout << endl;
            cout << "Dealer hits." << endl;
            cout << "Dealer's hand: ";
            printHand(dealerHand);
            cout << endl;
         }
         else if (dealerStands == false) // Only display hand once on stand 
         {
            dealerStands = true;
            cout << endl;
            cout << "Dealer stands." << endl;
            cout << "Dealer's hand: ";
            printHand(dealerHand);
            cout << endl;         
         }
         if (dealerScore > 21) // Busts
         {
            bust = true;
            cout << "Dealer busts." << endl;
         }
      } while (play == 's' && bust == false && dealerStands == false);
      // ^ while player stands, dealer can still hit and no one busted
      if ((play == 's' && dealerScore >= 17) || bust == true) // When game over
      {
         // Decides who wins
         if (dealerScore == 21)
         {
            dealerWins++;
            cout << endl << "Dealer wins!" << endl;
         }
         else if (bust == true && playerScore > 21)
         {
            dealerWins++;
            cout << endl << "Dealer wins!" << endl;
         }
         else if (bust == true && dealerScore > 21)
         {
            playerWins++;
            cout << endl << "Player wins!" << endl;
         }
         else if (dealerScore >= playerScore)
         {
            dealerWins++;
            cout << endl << "Dealer wins!" << endl;
         }
         else if (playerScore > dealerScore)
         {
            playerWins++;
            cout << endl << "Player wins!" << endl;
         }
         // Continue playing?
         while (play != 'y' && play != 'n')
         {
            cout << endl;
            // Tally of won games
            cout << "Dealer Wins: " << dealerWins << endl;
            cout << "Player Wins: " << playerWins << endl;
            cout << "Continue playing (y/n)? ";
            cin >> play;
            switch (play)
            {
               case 'y': // Continue
                  // Reset variables
                  playerScore = 0;
                  dealerScore = 0;
                  bust = false;
                  firstDeal = true;
                  dealerStands = false;
                  playerHand.clear(); // Clear hands
                  dealerHand.clear();
                  if (card >= 36) // Shuffle if <= 15 cards
                  {
                     shuffle();
                     card = 0;
                  }
                  break;
               case 'n': // Quit
                  cout << "Thanks for playing!" << endl;
                  break;
               default: // Displays error message
                  cout << "Please enter valid response (y/n)." << endl;
                  break;
            }
            if (play == 'n') { break; }
         }
         if (play == 'n') { break; }
      }  
      if (play == 'n') { break; }
   }
}

void BlackJack::printHand(vector<int> &h) // Prints hand
{

   for (int i = 0; i < h.size(); i++)
   {
      switch (h[i]) {
         case 11: // Jack instead of 11
            cout << "J ";
            break;
         case 12: // Queen instead of 12
            cout << "Q ";
            break;
         case 13: // KIng instead of 13
            cout << "K ";
            break;
         case 14: // Ace instead of 14
            cout << "A ";
            break;
         default: // Normal number for rest
            cout << h[i] << ' ';
            break;
      }
   }

}
