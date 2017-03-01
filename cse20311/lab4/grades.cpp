// Lab 4
// grades.cpp
// Author: Grace Milton

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   int grades[50];
   int sum = 0;
   int a, count = 0;
   double b;
   double average;
   double standev;

   cin >> a;
   
   while (a != -1) // Defines array. 
   {
      grades[count] = a;
      count++;
      cin >> a;
   }

   for (int k = 0; k < count; k++) // Sums array
   {
      sum += grades[k];
   }
   
   average = sum/(double)count;
   
   for (int m = 0; m < count; m++) // Calculates numerator for standard deviation.
   {
      b += pow((grades[m] - average),2);
   }

   standev = sqrt(b/(count));

   cout << "The average grade is: " << average << endl;
   cout << "The standard deviation is: " << standev << endl;
  
   return 0;
}

