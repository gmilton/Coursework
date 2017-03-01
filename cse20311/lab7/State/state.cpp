// Lab 7
// state.cpp
// Grace Milton
// class implementation for State

#include <iostream>
#include "state.h"   // need to include the class interface (prototype)
using namespace std;

State::State() { }

State::State(string ab, string nm, string cap, int pop, int yr, int r) 
{ abbr = ab; name = nm; capital = cap; population = pop; year = yr; reps = r; }

State::~State() { }  // nothing to be done (yet)

// Returns abbreviation
string State::getAbbr() 
{ return abbr; }

// Returns state name
string State::getName()
{ return name; }

// Returns capital
string State::getCapital()
{ return capital; }

// Returns population
int State::getPopulation()
{ return population; }

// Returns year founded
int State::getYear()
{ return year; }

// Returns number of representatives
int State::getReps()
{ return reps; }

// Sets abbreviation
void State::setAbbr(string ab) 
{ abbr = ab; }

// Sets state name
void State::setName(string nm)
{ name = nm; }

// Sets capital
void State::setCapital(string cap)
{ capital = cap; }

// Sets population
void State::setPopulation(int pop)
{ population = pop; }

// Sets year founded
void State::setYear(int yr)
{ year = yr; }

// Sets number of representatives
void State::setReps(int r)
{ reps = r; }

// Prints all info about state
void State::printall() { 
	cout << name << " (" << abbr << ")" << endl;
	cout << "Capital: " << capital << endl;
	cout << "Population: " << population << endl;
	cout << "Year of statehood: " << year << endl;
	cout << "Number of representatives in Congress: " << reps << endl;
}

// Prints year founded and state name
void State::printyear() {
   cout << year << ": " << name << endl;
}

// Prints state name and population
void State::printpopulation() {
   cout << name << endl;
   cout << "Population: " << population << endl;
}

// Prints state name, population, number of reps, and population per reps
void State::printdensity() {
   cout << name << endl;
   cout << "Population: " << population << endl;
   cout << "Number of representatives in Congress: " << reps << endl;
   cout << "There are about " << population / reps << " people per representative in " << 
   name << "." << endl;
}

