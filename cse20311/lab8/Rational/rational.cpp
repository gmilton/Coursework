// Lab 8
// rational.cpp
// Grace Milton
// class implementation for Rational
// rational.cpp from Lab 7 with overloaded operators

#include <iostream>
#include <cmath>
#include <fstream>
#include "rational.h"   // need to include the class interface (prototype)
using namespace std;

Rational::Rational() 
{ setRational(10,3); }

Rational::Rational(int n, int d) 
{ setRational(n,d); }

Rational::~Rational() { }  // nothing to be done (yet)

void Rational::setRational(int n, int d) {
   setNumer(n);
   setDenom(d);
}

int Rational::getNumer() 
{ return numer; }

int Rational::getDenom()
{ return denom; }

void Rational::setNumer(int n) 
{ numer = n; }

void Rational::setDenom(int d)
{ denom = d; }

void Rational::print()
{ cout << numer << " / " << denom << endl; }

Rational Rational::operator+(Rational x) {
   Rational z;
   z.numer = numer * x.denom + x.numer * denom;
   z.denom = denom * x.denom;
   return z;
}

Rational Rational::operator-(Rational x) {
   Rational z;
   z.numer = numer * x.denom - x.numer * denom;
   z.denom = denom * x.denom;
   return z;
}

Rational Rational::operator*(Rational x) {
   Rational z;
   z.numer = numer * x.numer;
   z.denom = denom * x.denom;
   return z;
}

Rational Rational::operator/(Rational x) {
   Rational z;
   z.numer = numer * x.denom;
   z.denom = denom * x.numer;
   return z;
}

// overloaded output operator
ostream& operator<< (ostream &s, Rational &r)
{
   // Accounts for sign of rational
   char sign;
   char nsign = (r.numer>=0) ? '+' : '-';
   char dsign = (r.denom>=0) ? '+' : '-';
   if (nsign == dsign) { sign = '+'; }
   else { sign = '-'; }

   s << sign << " " << fabs(r.numer) << " / " << fabs(r.denom);
   return s;
}

// overloaded input operator
istream& operator>> (istream &s, Rational &r)
{
   double x, y;
   
   cout << "Enter the numerator and denominator: ";
   s >> x >> y;
   r.setRational(x, y);
   
   return s;
} 
