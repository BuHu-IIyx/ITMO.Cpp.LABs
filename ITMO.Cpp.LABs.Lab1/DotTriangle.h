#pragma once
#include "Dot.h"
#include "Triangle.h"
#include <vector>
class DotTriangle
{
private:
	Dot a;
	Dot b;
	Dot c;
	//Dot* pa;
	//Dot* pb;
	//Dot* pc;
	Triangle* triangle;
public:
	DotTriangle(Dot&, Dot&, Dot&);
	/*DotTriangle(Dot*, Dot*, Dot*);*/
	std::vector<double> lengthSides()
	{		
		return { a.distanceTo(b), b.distanceTo(c), c.distanceTo(a)};
	}
};

