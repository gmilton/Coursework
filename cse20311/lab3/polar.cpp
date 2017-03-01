// Lab 3
// polar.cpp
// Author: Grace Milton

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double radius(double x, double y);
double angle(double x, double y);
double quadrant(double x, double y);

int main()
{
	double x;
	double y;
	double r;
	double theta;
	double quad;
	
	cout << "Enter x-coordinate: ";
	cin >> x;
	cout << "Enter y-coordinate: ";
	cin >> y;

	r = radius(x,y);
	theta = angle(x,y);
	
	cout << "The polar coordinates are: (" << r << "," << theta << 
	")\n";
	
	quad = quadrant(x,y);
	
	if (quad == 7)
	{
		cout << "The point is at the origin." << endl;
	}
	else if (quad == 5)
	{
		cout << "The point is on the x-axis." << endl;
	}
	else if (quad == 6)
	{
		cout << "The point is on the y-axis." << endl;
	}
	else 
	{
		cout << "The point is in quadrant " << quad << "." << endl;
	}
	return 0;
}

double radius(double x, double y)
{
	double r;
	r  = sqrt(pow(x,2)+pow(y,2));
	return r;
}

double angle(double x, double y) // Returns z in radians.
{
	double z;
	z = atan2(y,x);
	return z;
}

double quadrant(double x, double y)
{
	double quad;
	
	if (x == 0 && y == 0)
	{
		quad = 7;
	}
	else if (x > 0)
	{
		if (y > 0)
		{
			quad = 1;
		}
		else if (y < 0)
		{
			quad = 4;
		}
		else if (y == 0)
		{
			quad = 5;
		}
	}
	else if (x == 0 && (y > 0 || y < 0))
	{
			quad = 6;
	}
	else if (x < 0)
	{
		if (y > 0)
		{
			quad = 2;
		}
		else if (y < 0)
		{
			quad = 3;
		}
		else if (y == 0)
		{
			quad = 5;
		}
	}
	return quad;
}
