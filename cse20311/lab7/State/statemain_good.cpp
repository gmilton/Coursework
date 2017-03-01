// Lab 7
// statemain.cpp
// Grace Milton
// simple driver to test the State class
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#include "state.h"

void menu(void);
void displayall(vector<State> &);

int main()
{
   ifstream ifs;
   string filename;
   string abbr, name, capital, pop_s, yr_s, rep_s;
   int pop, yr, rep, choice;
   vector<State> states;
   State st;

   cout << "enter data file name: ";
   cin >> filename;
   ifs.open(filename);
   if(!ifs) {
      cout << "bad file name: " << filename << endl;
      return 1;
   }

   char c = ifs.peek();
   while(c != EOF) {
      getline(ifs, abbr, ',');
      getline(ifs, name, ',');
      getline(ifs, capital, ',');
      getline(ifs, pop_s, ',');
      getline(ifs, yr_s, ',');
      getline(ifs, rep_s, '\n');
      pop = stoi(pop_s);
      yr = stoi(yr_s);
      rep = stoi(rep_s);
      st = State(abbr, name, capital, pop, yr, rep);
      states.push_back(st);
      c = ifs.peek();
   }
   
   menu();
   cin >> choice;
   
   while (choice !=6) {
      switch(choice) {
         case 1:
            displayall(states);
            menu();
            cin >> choice;
            break;
         case 2:
            break;
         case 3:
            break;
         case 4:
            break;
         case 5:
            break;
         case 6:
            break;
         default:
            break;
      }
   }
   
   return 0;
   
}

void menu(void)
{
   cout << "Welcome to the U.S. States Database!" << endl;
   cout << "	1: Display all states with all information" << endl;
   cout << "	2: Display single state with all information" << endl;
   cout << "	3: Display all states founded in certain year" << endl;
   cout << "	4: Display states with at least ""n"" population" << endl;
   cout << "	5: Display states in order of year founded" << endl;
   cout << "	6: Quit" << endl;
   cout << "Enter you choice: ";
}

void displayall(vector<State> &s)
{
   for(auto it = s.begin(); it != s.end(); ++it)
   {
      it->printall();
      cout << endl;
   }
}
