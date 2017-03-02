// Grace Milton
// CSE 20312 Lab 02 Part 2
// human.cpp
//
// Implementation for Human class

#include "cccitizen.h"
#include "human.h"
#include <string>
#include <iostream>
using namespace std;

// constructor
Human::Human(string l, string f, int c, string j, string a) : CCCitizen(l, f, c)
{

   job = j;
   affiliation = a;

}

void Human::setJob(string j) // Sets job
{ job = j; }

void Human::setAffiliation(string a) // Sets affiliation (e.g, Team Flash)
{ affiliation = a; }

string Human::getJob() // Returns job
{ return job; }

string Human::getAffiliation() // Returns affiliation
{ return affiliation; }

void Human::print() // Print's character information
{

   cout <<"--------------------------" << endl;

   // Determines number of zeros printed based on size of number
   if (getCitizenNum() < 10)
      cout << endl << "Central City Citizen #000" << getCitizenNum() << endl;
   else if (citizenNum >= 10 && citizenNum < 100)
      cout << endl << "Central City Citizen #00" << getCitizenNum() << endl;
   else if (citizenNum >= 100 && citizenNum < 1000)
      cout << endl << "Central City Citizen #0" << getCitizenNum() << endl;
   else 
      cout << endl << "Central City Citizen #" << getCitizenNum() << endl;

   cout << "Name: " << getLast() << ", " << getFirst() << endl;
   cout << "Job: " << job << endl;
   cout << "Affiliation: " << affiliation << endl << endl;

}
