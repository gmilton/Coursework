// Lab 4
// primes.cpp
// Author: Grace Milton

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main ()
{
	int primes[1000];
	int count = 0;

	for (int i = 0; i < 1000; i++)	// Initializes all elements in array as 1.
	{
    	primes[i] = 1;
	} 

	for (int j = 2; j < sqrt(1000); j++)	/* Sets multiples of numbers as not 
	prime.*/
	{
    	for (int k = 2*j; k <= 1000; k = j+k)
      	{
      		primes[k] = 0;
      	}
    }  
 
	for (int m = 2; m < 1000; m++) // Outputs prime numbers
	{
    	if (primes[m] == 1)
    	{
        	cout << setw(5) << m << " ";
        	count += 1;
        }
        if (count == 10)	// Sets new line every 10 numbers outputted
        {
         	cout << endl;
         	count = 0;
        }
	}
   
   cout << endl;
   return 0;
}
