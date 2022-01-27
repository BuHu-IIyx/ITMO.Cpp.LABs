#pragma once
#include <string>
class Triangle
{
public:
	double a;
	double b;
	double c;
	Triangle(double, double, double);
	double getPerimeter();
	double getArea();

	class ExInit
	{
	public:
		std::string message = "Одна из сторон имеет длину большую, чем	сумма двух других сторон";
		ExInit(){ }
	};	
};

