// Grace Milton
// CSE 20312 Lab 02 Part 2
// human.h
//
// Interface for Human class

#ifndef HUMAN_H
#define HUMAN_H

#include "cccitizen.h"
#include <string>

// Derived Human class; inherits from CCCitizen
class Human : public CCCitizen {
  public:
     Human(string = "", string = "", int = 0, string = "Unknown", string = "None");
     virtual void print();

     void setJob(string);
     void setAffiliation(string);
     string getJob();
     string getAffiliation();

  private:
     string job;
     string affiliation;

};

#endif 
