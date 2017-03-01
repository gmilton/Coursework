// class implementation for Circle

#include "circle.h"   // need to include the class interface (prototype)

Circle::Circle() 
{ radius = 1; }

Circle::Circle(float r) 
{ radius = r; }

Circle::~Circle() { }  // nothing to be done (yet)

float Circle::getRadius() 
{ return radius; }

void Circle::setRadius(float r) 
{ radius = r; }

float Circle::circumference() 
{ return 2*3.14159*(radius); }

float Circle::area() 
{ return 3.14159*(radius*radius); }

