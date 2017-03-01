// Lab 7
// rationalmain.cpp
// Grace Milton
// simple driver to test the rational class
#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
   Rational a(3,8), b(2,1), c, s, m, p, z;

   cout << "*** display a and b ***\n";
   a.print();
   b.print();
   cout << "*** display c ***\n";
   c.print();  // c was instantiated with the default constructor

   // 'mathematically' add a and b
   cout << "*** compute s as the math sum of a and b, and display s ***\n";
   s = a.add(b);
   s.print();
 
   // displays numer of a
   cout << "*** display numerator of a ***\n";
   cout << a.getNumer() << endl;
   
   // displays denom of b
   cout << "*** display denominator of b ***\n";
   cout << b.getDenom() << endl;   

   // sets numer of a
   cout << "*** set numerator of a to 9 and display a ***\n";
   a.setNumer(9);
   a.print();

   // sets denom of b
   cout << "*** set denominator of b to 10 and display b ***\n";
   b.setDenom(10);
   b.print();
   
   // 'mathematically' subract b from a
   cout << "*** compute m as a minus b and display m ***\n";
   m = a.subtract(b);
   m.print();

   // 'mathematically' multiply a and b
   cout << "*** compute p as product of a and b and display p ***\n";
   p = a.multiply(b);
   p.print();   

   // 'mathematically' divide b by a
   cout << "*** compute z as b divided by a and display z\n";
   z = b.divide(a);
   z.print();

   return 0;
}
