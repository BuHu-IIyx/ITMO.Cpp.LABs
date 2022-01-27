#include "Triangle.h"
#include <cmath>
#include <iostream>

Triangle::Triangle(double a, double b, double c)
{
	if (a > b + c || b > a + c || c > a + b)
	{
		throw ExInit();
	}
	Triangle::a = a;
	Triangle::b = b;
	Triangle::c = c;
}
double Triangle::getPerimeter()
{
	return a + b + c;
}
double Triangle::getArea()
{
	double hPerimeter = getPerimeter() / 2;
	double area = sqrt(hPerimeter * (hPerimeter - a) * (hPerimeter - b) * (hPerimeter - c));
	return area;
}
