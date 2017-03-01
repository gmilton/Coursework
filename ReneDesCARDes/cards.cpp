#include <iostream>
using namespace std;
#include "cards.h"

Cards::Cards() 
{ suit = 1; kind = 1; }

Cards::~Cards() { }

int Cards::getSuit()
{ return suit; }

char Cards::getKind() 
{ return kind; }

void Cards::setSuit(int s) 
{ suit = s; }

void Cards::setKind(char k) 
{ kind = k; }

void drawCard() 
{
   for (int i = 0; i <= 11; i++) {
      cout << "-";
   }
   cout << endl;
   cout << "|";
   for (int i = 0; i <= 11; i++) {
      cout << " ";
   }
   cout << "|" << endl;
   cout << "|";
   for (int i = 0; i <= 5; i++) {
      cout << " ";
   }
   cout << kind;
   for (int i = 0; i <= 5; i++) {
      cout << " ";
   }
   cout << "|";
   switch (suit) {
      case 1: // clubs
         for (int i = 0; i <= 3; i++) {
            cout << " ";
         }
         cout << "CLUBS";
         for (int i = 0; i <= 3; i++) {
            cout << " ";
         }
         cout << "|" << endl;
         break; 
      case 2: // diamonds
         for (int i = 0; i <= 1; i++) {
            cout << " ";
         }
         cout << "DIAMONDS";
         for (int i = 0; i <= 2; i++) {
            cout << " ";
         }
         cout << "|" << endl;
         break;
      case 3: // hearts
         for (int i = 0; i <= 2; i++) {
            cout << " ";
         }
         cout << "HEARTS";
         for (int i = 0; i <= 3; i++) {
            cout << " ";
         }
         cout << "|" << endl;
         break;
      case 4: // spades
         for (int i = 0; i <= 2; i++) {
            cout << " ";
         }
         cout << "SPADES";
         for (int i = 0; i <= 3; i++) {
            cout << " ";
         }
         cout << "|" << endl;
         break;
   }
   cout << "|";
   for (int i = 0; i <= 11; i++) {
      cout << " ";
   }
   cout << "|" << endl;
   for (int i = 0; i <= 11; i++) {
      cout << "-";
   }
   cout << endl; 
}
