#include <iostream>
#include <iomanip>
using namespace std;

int main() {

float principal;
float irate;
float payment;
float balance;
int month = 1;
float interest;
float total = 0;
int width1; // declare spacing before payment
int width2; // declare spacing before balance

cout << "What is the prinicipal (in dollars)? ";
cin >> principal;

while (principal < 0){
	cout << "What is the principal (in dollars)? ";
	cin >> principal;
}

cout << "What is the interest rate (in decimal form)? ";
cin >> irate;

while (irate < 0){
	cout << "What is the interest rate (in decimal form)? ";
	cin >> irate;
	}
	
cout << "What is the desired monthly payment (in dollars)? ";
cin >> payment;

while (payment < 0) {
	cout << "What is the desired monthly payment (in dollars)? ";
	cin >> payment;
	}
	
balance = principal;

interest = irate*balance/12;
if (payment < interest){
	cout << "Desired payment is too small." << endl;
	return 0;
}

cout << "Month" << setw(16) << "Payment" << setw(15) << "Interest" << 
setw(13) << "Balance" << endl;

while (balance > 0) {
	interest = irate*balance/12;
	if (balance < payment){
		payment = balance + interest;
	}
	balance = balance - payment + interest;
	if (balance < 0){
		balance = 0; /* sets balance equal to zero for infinitesimal 
		negative numbers that result in answer being $-0.00 when 
		precision is decreased */
	}
	if (month < 10) {
		width1 = 14;
		} else if (month < 100 && month >= 10){
			width1 = 13;
		} else if (month < 1000 && month >= 100){
			width1 = 12;
	}
if (interest >= 1000) {
		width2 = 7;
	} else if (interest >= 100 && interest < 1000) {
		width2 = 8;
	} else if (interest >= 10 && interest <100) {
		width2 = 9;
	} else if (interest <10) {
		width2 = 10;
	}
	/*if (month < 10){*/
		cout << month << setw(width1) << fixed << "$" << 
		setprecision(2) << payment << setw(8) << fixed << "$" << setprecision(2) << interest << setw(width2) << 
		fixed << "$" << setprecision(2) << balance << endl;
	/*}else if(month < 100 && month >= 10){
		cout << month << setw(13) << fixed << "$" << setprecision(2) << 
		payment << setw(8) << fixed << "$" << setprecision(2) << 
		interest << setw(8) << fixed << "$" << setprecision(2) << 
		balance << endl;
	}else if (month < 1000 && month >= 100){
		cout << month << setw(12) << fixed << "$" << setprecision(2) << 
		payment << setw(8) << fixed << "$" << setprecision(2) << 
		interest << setw(8) << fixed << "$" << setprecision(2) << 
		balance << endl;
	}*/
	month = month + 1;
	total = total + payment;
}
int years;
int months = month - 1;
years = (month - 1)/12;
months = (months%12);
cout << "You paid a total of $" << total << " over " << years << " years and " << setprecision(0) << months << " months." << endl;
return 0;

}
