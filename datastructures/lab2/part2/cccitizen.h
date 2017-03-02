// Grace Milton
// CSE 20312 Lab 02 Part 2
// cccitizen.h
//
// Interface for CCCitizen (AKA Central City Citizen)

#ifndef CCCITIZEN_H
#define CCCITIZEN_H

#include <string>
using namespace std;

class CCCitizen {

  public:
     CCCitizen(string = "???", string = "???", int = 0); // constructor
     virtual void print();

     void setName(string, string);
     string getLast();
     string getFirst();
     int getCitizenNum();

  protected:
     string last;
     string first;
     int citizenNum;

};

#endif
