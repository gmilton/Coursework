#include <iostream>
using namespace std;

int main() {
  
   int ntouchdowns;
   int nextra;  
   int nfieldgoals;
   int nsafeties;
   int score;
   
   cout << "Number of touchdowns the Irish scored: ";
   cin >> ntouchdowns; // number of touchdowns
   cout	<< "Number of extra points: ";
   cin >> nextra; // number of extra points
   cout	<< "Number of field goals: ";
   cin >> nfieldgoals; // number of field goals
   cout << "Number of safeties: ";
   cin >> nsafeties; // number of safeties
   
   int wtouchdown = 6;
   int wextra = 1;
   int wfieldgoal = 3;
   int wsafety = 2;
   score = wtouchdown*ntouchdowns + wextra*nextra + wfieldgoal*nfieldgoals + wsafety*nsafeties;
   cout << "Total number of points scored by the Irish: " << score << endl;
   
   return 0;
   }
   
   


