// Grace Milton
// CSE 20312 Lab 02 Part 2
// cccitizen.cpp
//
// Implementation for CCCitizen class

#include "cccitizen.h"
#include <iostream>
using namespace std;

CCCitizen::CCCitizen(string l, string f, int c) // constructor
{ setName(l, f); citizenNum = c; }

void CCCitizen::setName(string lval, string fval) // Sets name
{ last = lval; first = fval; }

string CCCitizen::getLast() // Returns last name
{ return last; }

string CCCitizen::getFirst() // Returns first name
{ return first; }

int CCCitizen::getCitizenNum() // Returns number
{ return citizenNum; }

void CCCitizen::print() // Prints character information
{

   cout <<"--------------------------" << endl;

   // Determines how many zeros are printed based on size of number
   if (citizenNum < 10)
      cout << endl << "Central City Citizen #000" << citizenNum << endl;
   else if (citizenNum >= 10 && citizenNum < 100)
      cout << endl << "Central City Citizen #00" << citizenNum << endl;
   else if (citizenNum >= 100 && citizenNum < 1000)
      cout << endl << "Central City Citizen #0" << citizenNum << endl;
   else
      cout << endl << "Central City Citizen #" << citizenNum << endl;

   cout << "Name: " << last << ", " << first << endl << endl;

}
