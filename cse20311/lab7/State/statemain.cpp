// Lab 7
// statemain.cpp
// Grace Milton
// simple driver to test the State class
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#include "state.h" // includes prototype

void menu(void);
void displayall(vector<State> &);
void displayone(vector<State> &);
void singleyear(vector<State> &);
void minpopulation(vector<State> &);
void poprepdens(vector<State> &);

int main()
{
   ifstream ifs;
   string filename;
   string abbr, name, capital, pop_s, yr_s, rep_s;
   int pop, yr, rep, choice;
   vector<State> states;
   State st;

   // Enter file name
   cout << "enter data file name: "; 
   cin >> filename;
   // Makes sure file is valid
   ifs.open(filename);
   if(!ifs) {
      cout << "bad file name: " << filename << endl;
      return 1;
   }
   
   // Reads in information from file
   char c = ifs.peek();
   while(c != EOF) {
      getline(ifs, abbr, ',');
      getline(ifs, name, ',');
      getline(ifs, capital, ',');
      getline(ifs, pop_s, ',');
      getline(ifs, yr_s, ',');
      getline(ifs, rep_s, '\n');
      // Convert integers read in as strings to integers
      pop = stoi(pop_s);
      yr = stoi(yr_s);
      rep = stoi(rep_s);
      st = State(abbr, name, capital, pop, yr, rep);
      states.push_back(st);
      c = ifs.peek();
   }
   
   // Display menu
   menu();
   cin >> choice;
   
   // Runs program while user doesn't choose to quit
   while (choice !=6) {
      switch(choice) {
         case 1: // Choice 1: Display all states with all info
            displayall(states);
            menu();
            cin >> choice;
            break;
         case 2: // Choice 2: Display single state with all info
            displayone(states);
            menu();
            cin >> choice;
            break;
         case 3: // Choice 3: Display all states founded in certain year
            singleyear(states);
            menu();
            cin >> choice;
            break;
         case 4: // Choice 4: Display all states with at least n population
            minpopulation(states);
            menu();
            cin >> choice;
            break;
         case 5: // Choice 5: Display density of population/number of representatives
            poprepdens(states);
            menu();
            cin >> choice;
            break;
         case 6: // Choice 6: Quit
            break;
         default: // Response to invalid choice
            cout << "ERROR INVALID CHOICE" << endl;
            menu();
            cin >> choice;
            break;
      }
   }
   
   cout << "Thank you!" << endl;
   
   return 0;
   
}

// Displays menu
void menu(void)
{
   cout << endl;
   cout << "Welcome to the U.S. States Database!" << endl;
   cout << "	1: Display all states with all information" << endl;
   cout << "	2: Display single state with all information" << endl;
   cout << "	3: Display all states founded in certain year" << endl;
   cout << "	4: Display states with at least n population" << endl;
   cout << "	5: Display population per density of certain state" << endl;
   cout << "	6: Quit" << endl;
   cout << "Enter you choice: ";
}

// Displays all states with all info
void displayall(vector<State> &s)
{
   // Runs through all states
   for(auto it = s.begin(); it != s.end(); ++it)
   {
      // Displays all info for each state
      it->printall();
      cout << endl;
   }
}

// Display all info for certain state
void displayone(vector<State> &s)
{
   bool match = false;
   string onestate;
   // Prompts user for state abbreviation
   cout << "Enter abbreviation of state: ";
   cin >> onestate;
   // Runs through all states
   for(auto it = s.begin(); it != s.end(); ++it)
   {
      // Finds state with matching abbreviation
      if(onestate == it->getAbbr()) {
         match = true;
         cout << endl;
         // Prints all info for one state
         it->printall();
         cout << endl;
         // Breaks out of for loop when match found
         break;
      }
   }
   // Responds with message for incorrect or lowercase abbreviation
   if (match != true) {
      cout << "Please enter valid state abbreviation in uppercase letters." << endl;
   }
}

// Displays all states founded in certain year
void singleyear(vector<State> &s)
{
   bool match = false;
   int oneyear;
   // Prompts user for year
   cout << "Enter year: ";
   cin >> oneyear;
   // Runs through all states
   for(auto it = s.begin(); it != s.end(); ++it)
   {
      // compares given year to year each state was founded
      if (oneyear == it->getYear()) {
         match = true;
         cout << endl;
         // Displays year and state name if match
         it->printyear();
      }
   }
   // Responds with message if no states founded in given year
   if (match != true) {
      cout << "No states joined the Union in " << oneyear << "." << endl;
   }
}

// Displays states with at least n population
void minpopulation(vector<State> &s)
{
   bool match = false;
   int minpop;
   // Prompts user for population
   cout << "Enter population: ";
   cin >> minpop;
   // Runs through all states
   for (auto it = s.begin(); it != s.end(); ++it)
   {
      // Compares population of states to given population
      if (minpop <= it->getPopulation())
      {
         match = true;
         cout << endl;
         // Displays state name and population if match
         it->printpopulation();
      }
   }
   // If no matches found displays message
   if(match !=true) {
      cout << "No state has population greater than or equal to " << minpop << endl;
   }
}

// Displays density of population/number of representatives for given state
void poprepdens(vector<State> &s)
{
   string statename;
   bool match = false;
   // Prompts user for state
   cout << "Enter abbreviation of state: ";
   cin >> statename;
   // Runs through all states
   for(auto it = s.begin(); it != s.end(); ++it) {
      // Compares given abbreviation with state abbreviations
      if (statename == it->getAbbr()) {
         match = true;
         cout << endl;
         // Displays name, pop, number of reps, and pop per number of reps
         it->printdensity();
         // Exits loop when matching state found
         break;
      }
   }
   // Displays message if incorrect or lowercase abbreviation given
   if (match != true) {
      cout << "Please enter valid state abbreviation in uppercase letters." << endl;
   }
}
