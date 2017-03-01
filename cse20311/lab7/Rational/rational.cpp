// Lab 7
// rational.cpp
// Grace Milton
// class implementation for Circle

#include <iostream>
#include "rational.h"   // need to include the class interface (prototype)
using namespace std;

Rational::Rational() 
{ numer = 10; denom = 3; }

Rational::Rational(int n, int d) 
{ numer = n; denom = d; }

Rational::~Rational() { }  // nothing to be done (yet)

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

Rational Rational::add(Rational x) 
{ 
   Rational z;
   z.numer = numer * x.getDenom() + denom * x.getNumer();
   z.denom = denom * x.getDenom();
   return z;
}

Rational Rational::subtract(Rational x) 
{
   Rational z;
   z.numer = numer * x.getDenom() - denom * x.getNumer();
   z.denom = denom * x.getDenom();
   return z;
}

Rational Rational::multiply(Rational x)
{
   Rational z;
   z.numer = numer * x.getNumer();
   z.denom = denom * x.getDenom();
   return z;
}

Rational Rational::divide(Rational x)
{
   Rational z;
   z.numer = numer * x.getDenom();
   z.denom = denom * x.getNumer();
   return z;
}
