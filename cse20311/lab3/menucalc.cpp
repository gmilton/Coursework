// Lab 3
// menucalc.cpp
// Author: Grace Milton

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double addition(double, double);
double subtraction(double, double);
double multiplication(double, double);
double division(double, double);

int main () {

	int choice;
	double n1;
	double n2;
	double answer;

	cout << "What would you like to do?" << endl;
	cout << "          1 for addition" << endl;
	cout << "          2 for subtraction" << endl;
	cout << "          3 for multiplication" << endl;
	cout << "          4 for division" << endl;
	cout << "          5 to quit" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice != 5)
	{
		cout << "Enter two numbers: ";
		cin >> n1 >> n2;
		cout << "Inputs: " << setprecision(6) << fixed << n1 << ", " << 
		setprecision(6) << fixed << n2 << endl;
	}
	
	while (choice != 5)
	{
		if (choice == 1)
		{
			answer = addition(n1, n2);
			cout << "(" << setprecision(6) << fixed << n1 << ") + (" << 
			setprecision(6) << fixed << n2 << ") = " << 
			setprecision(6) << fixed << answer << endl;
		}
		else if (choice == 2)
		{
			answer = subtraction(n1, n2);
			cout << "(" << setprecision(6) << fixed << n1 << ") - (" << 
			setprecision(6) << fixed << n2 << ") = " << 
			setprecision(6) << fixed << answer << 
			endl;
		}
		else if (choice == 3)
		{
			answer = multiplication(n1, n2);
			cout << "(" << setprecision(6) << fixed << n1 << ") * (" << 
			setprecision(6) << fixed << n2 << ") = " << setprecision(6) << 
			fixed << answer << endl;
		}
		else if (choice == 4)
		{
			answer = division(n1, n2);
			if (n2 != 0)
			{
				cout << "(" << setprecision(6) << fixed << n1 << ") / (" 
				<< setprecision(6) << fixed << n2 << ") = " << 
				setprecision(6) << fixed << answer << endl;
			}
		}
	
		cout << "What would you like to do?" << endl;
		cout << "          1 for addition" << endl;
		cout << "          2 for subtraction" << endl;
		cout << "          3 for multiplication" << endl;
		cout << "          4 for division" << endl;
		cout << "          5 to quit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 5)
		{
			break;
		}
		else
		{
			cout << "Enter two numbers: ";
			cin >> n1 >> n2;
			cout << "Inputs: " << n1 << ", " << n2 << endl;
		}
	}
	
	cout << "Thank you!\n";
	
	return 0;

}

double addition(double a, double b)
{
	double c;
	c = a + b;
	return c;
}

double subtraction(double a, double b)
{
	double c;
	c = a - b;
	return c;
}

double multiplication(double a, double b)
{
	double c;
	c = a * b;
	return c;
}

double division(double a, double b)
{
	double c;
	
	if (b == 0)
	{
		cout << "Undefined!" << endl;
	}
	else
	{
	c = a / b;
	}
	
	return c;
}
