#include "DotTriangle.h"
DotTriangle::DotTriangle(Dot& a, Dot& b, Dot& c)
{
	DotTriangle::a = a;
	DotTriangle::b = b;
	DotTriangle::c = c;
	triangle = new Triangle(a.distanceTo(b), b.distanceTo(c), c.distanceTo(a));
}
//DotTriangle::DotTriangle(Dot* a, Dot* b, Dot* c)
//{
//	DotTriangle::pa = a;
//	DotTriangle::pb = b;
//	DotTriangle::pc = c;
//	triangle = new Triangle(a.distanceTo(b), b.distanceTo(c), c.distanceTo(a));
//}