#include <iostream>
#include  <cmath>
using namespace std;


int main() {

   float k = 8.99*pow(10,9); // declare and define electric constant k (N*m^2/C^2)
   float q1; // declare charge 1 (C)
   float q2; // declare charge 2 (C)
   float r; // declare distance (m)
   float Felectric; // declare electric force (N)
   
   cout << "What is the value of the first charge (in Coulombs)? ";
   cin >> q1;
   cout << "What is the value of the second charge (in Coulombs)? ";
   cin >> q2;
   cout << "What is the distance between the two charges (in meters)? ";
   cin >> r;
   Felectric = k*q1*q2/powf(r,2);
   cout << "The electric force between charge 1 and charge 2 is " << Felectric << " Newtons." << endl;

   return 0;
}
