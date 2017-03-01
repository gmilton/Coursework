// gcdmain.cpp
// Author: Grace Milton

#include <iostream>
using namespace std;

int getgcd(int, int);

int main()
{

	int x;
	int y;
	int z;

	cout << "Enter two numbers: ";
	cin >> x;
	cin >> y;

	z = getgcd(x,y);

	cout << "The greatest common denominator is: " << z << endl;

}

int getgcd(int a, int b)
{
	int c;
	while ( a != 0 )
	{
		c = a; 
		a = b%a;  
		b = c;
	}
	return b;
}
