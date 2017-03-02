// Grace Milton
// CSE 20312 Lab 02 Part 2
// metahuman.cpp
//
// Implementation for Metahuman class

#include "cccitizen.h"
#include "metahuman.h"
#include <string>
#include <iostream>
using namespace std;

// constructor
Metahuman::Metahuman(string l, string f, int c, string p, string m, string a) : CCCitizen(l, f, c) 
{ 

   powers = p;
   morals = m;
   alias = a;

}

void Metahuman::setPowers(string p) // Sets powers
{ powers = p; }

void Metahuman::setMorals(string m) // Sets morals (e.g., Good, Evil)
{ morals = m; }

void Metahuman::setAlias(string a) // Sets alias
{ alias = a; }

string Metahuman::getPowers() // Returns powers
{ return powers; }

string Metahuman::getMorals() // Returns morals
{ return morals; }

string Metahuman::getAlias() // Returns alias
{ return alias; }

void Metahuman::print() // Prints character information
{

    cout <<"--------------------------" << endl;
    cout << endl << "Alias: " << alias << endl;
    cout << "Power(s): " << powers << endl;
    cout << "Morals: " << morals << endl;
    cout << "Secret Identity: " << getFirst() << " " << getLast() << "??? (possible)" << endl << endl; 

}
