// Lab 4
// ndfootball.cpp
// Author: Grace Milton
#include <iostream>
#include <iomanip>
#include <cmath>
#include "nd_data.h"
using namespace std;

void record(int);
void minloss(int nlosses, int nyears);
void minwin(int nwins, int nyears);

int main()
{

	int choice;
	int year;
	int nlosses;
	int nwins;
	int nyears;
	int count1 = 0;
	int count2 = 0;
	
	nyears = sizeof(wins)/sizeof(int);	// Calculates number of years in array.
	
	cout << "1: display the record for the given year." << endl;
	cout << "2: display years with at least ""n"" losses." << endl;
	cout << "3: display years with at least ""n"" wins." << endl;
	cout << "4: display years with a losing record." << endl;
	cout << "5: display years with a winning record." << endl;
	cout << "6: exit" << endl;
	cout << "Enter your choice: ";
	
	cin >> choice;
	
	while (choice < 1 || choice > 6) // Rejects invalid inputs
	{
		cout << "Please enter a number from 1-6: " << endl;
		cin >> choice;
	}
	
	while (choice != 6)
	{
		if  (choice == 1)
		{
			cout << "Enter the year: ";
			cin >> year;
			while (year < 1900 || year > 2015)	// Rejects years outside range.
			{
				cout << "Please enter a year from 1900-2015: ";
				cin >> year;
			}
			record(year);
		}
		else if (choice == 2)
		{
			cout << "Enter minimum number of losses: ";
			cin >> nlosses;
			while (nlosses < 0)	// Rejects negative number of losses.
			{
				cout << "Enter valid minimum number of losses: ";
				cin >> nlosses;
			}
			minloss(nlosses, nyears);
		}
		else if (choice == 3)
		{
			cout << "Enter minimum number of wins: ";
			cin >> nwins;
			while (nwins < 0)	// Rejects negative number of wins.
			{
				cout << "Enter valid minimum number of wins: ";
				cin >> nwins;
			}
			minwin(nwins, nyears);
		}
		else if (choice == 4)
		{
			cout << "Years with losing record: " << endl;
			cout << setw(8);
			for (int k = 0; k < nyears; k++)	/* Finds years with more losses 
			than wins */
			{
				if (losses[k] > wins[k])
				{
					cout << (k + 1900) << " ";
					count1 += 1;
				}
				if (count1 == 10) // Creates new line when > 10 years
				{
					cout << endl;
					cout << setw(8);
					count1 = 0;
				}
			}
			cout << endl;
		}
		else if (choice == 5)
		{
			cout << "Years with winning record: " << endl;
			cout << setw(8);
			for (int m = 0; m < nyears; m++) /* Finds years with more wins than 
			losses */
			{
				if (wins[m] > losses[m])
				{
					cout << (m + 1900) << " ";
					count2 += 1;
				}
				if (count2 == 10)	// Creates new line when > 10 years
				{
					cout << endl;
					cout << setw(8);
					count2 = 0;
				}
			}
			cout << endl;
		}
		cout << endl;
		cout << "1: display the record for the given year." << endl;
		cout << "2: display the years with at least ""n"" losses." << 
		endl;
		cout << "3: display the years with at least ""n"" wins." << 
		endl;
		cout << "4: display the years  with a losing record." << endl;
		cout << "5: display the years with a winning record." << endl;
		cout << "6: exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
	}
	
	cout << "Goodbye!" << endl;
	return 0;
}

void record(int year)	// Finds record for year
{
	cout << "Wins: " << wins[year-1900] << ", Losses: " << 
	losses[year-1900] << endl;
}

void minloss(int nlosses, int nyears) /* Finds year with minimum of "nlosses" 
losses */
{
	int count = 0;
	cout << "Years with at least " << nlosses << " losses: " << endl;
	cout << setw(8);
	for  (int i = 0; i < nyears; i++)
	{
		if (losses[i] >= nlosses)
		{
			cout << (i + 1900) << " ";
			count += 1;
		}
		if (count == 10) // Creates new line if > 10 lines
		{
			cout << endl;
			cout << setw(8);
			count = 0;
		}
	}
	cout << endl;
}

void minwin(int nwins, int nyears) // Finds years with minimum of "nwins" wins
{
	int count = 0;
	cout << "Years with at least " << nwins << " wins: " << endl;
	cout << setw(8);
	for (int j = 0; j < nyears; j++)
	{
		if (wins[j] >= nwins)
		{
			cout << (j + 1900) << " ";
			count += 1;
		}
		if (count == 10)	// Creates new line if > 10 years.
		{
			cout << endl;
			cout << setw(8);
			count = 0;
		}
	}
	cout << endl;
}
