#include "DotTriangle.h"
DotTriangle::DotTriangle(Dot& a, Dot& b, Dot& c)
{
	DotTriangle::a = a;
	DotTriangle::b = b;
	DotTriangle::c = c;
	DotTriangle::triangle = new Triangle(a.distanceTo(b), b.distanceTo(c), c.distanceTo(a));
}
double DotTriangle::getLength(char side)
{
	switch (side)
	{
	case 'A':
		return DotTriangle::triangle->a;
	case 'B':
		return DotTriangle::triangle->b;
	case 'C':
		return DotTriangle::triangle->c;
	default:
		break;
	}
}

double DotTriangle::getPerimeter()
{
	return triangle->getPerimeter();
}
double DotTriangle::getArea()
{
	return triangle->getArea();
}

//DotTriangle::DotTriangle(Dot* a, Dot* b, Dot* c)
//{
//	DotTriangle::pa = a;
//	DotTriangle::pb = b;
//	DotTriangle::pc = c;
//	triangle = new Triangle(a.distanceTo(b), b.distanceTo(c), c.distanceTo(a));
//}