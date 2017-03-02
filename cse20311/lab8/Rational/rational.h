// Lab 8
// rational.h
// Grace Milton
// rational.h from Lab 7 but with overloaded operators

#include <iostream>
using namespace std;

class Rational {
// Overloads >> and <<
friend ostream& operator<< (ostream &, Rational &);
friend istream& operator>> (istream &, Rational &);
  public:
    Rational();
    Rational(int, int);
    ~Rational();

    void setRational(int, int);

    int getNumer(); // Gets numerator
    int getDenom(); // Gets denominator
    void setNumer(int); // Sets numerator
    void setDenom(int); // Sets denominator
    void print(); // Prints rational number

    // Overloads +, -, *, and /
    Rational operator+(Rational);
    Rational operator-(Rational);
    Rational operator*(Rational);
    Rational operator/(Rational);

  private:
    int numer;
    int denom;
};
