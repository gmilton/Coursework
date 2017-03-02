// Grace Milton
// CSE 20312 Lab 02 Part 2
// metahuman.h
//
// Interface for the Metahuman class

#ifndef METAHUMAN_H
#define METAHUMAN_H

#include "cccitizen.h"
#include <string>

// Derived Metahuman class; inherits from CCCitizen
class Metahuman : public CCCitizen {
  public:
     Metahuman(string = "???", string = "???", int = 0, string = "Unknown", string = "Unknown", string = "???"); // constructor
     virtual void print();

     void setPowers(string);
     void setMorals(string);
     void setAlias(string);
     string getPowers();
     string getMorals();
     string getAlias();

  private:
    string powers;
    string morals;
    string alias;

};

#endif
