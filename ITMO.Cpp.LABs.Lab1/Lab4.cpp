#include "Header.h"
#include <iostream>
#include <string>

namespace Lab4 
{
	//
	// Упражнение 1
	//
	void fum_value(double, double, double);
	void fum_ptr(double, double*, double*);
	void fum_ref(double, double&, double&);
	void print(double, double);

	int ex1()
	{
		double k = 2.5;
		double xv = 10;
		double yv = 10;
		print(xv, yv);
		fum_value(k, xv, yv); // Передача в функцию обычного параметра 
		print(xv, yv);
		fum_ptr(k, &xv, &yv); // Передача в функцию параметра указателя 
		print(xv, yv);
		fum_ref(k, xv, yv); // Передача в функцию параметра ссылки 
		print(xv, yv);
		return 0;
	}
	void fum_value(double k, double x, double y)
	{
		x = x + k;
		y = y + k;
	}
	void fum_ptr(double k, double* x, double* y)
	{
		*x = *x + k;
		*y = *y + k;
	}
	void fum_ref(double k, double& x, double& y)
	{
		x = x + k;
		y = y + k;
	}
	void print(double x, double y)
	{
		std::cout << "x = " << x << "; y = " << y << std::endl;
	}

	//
	// Упражнение 2
	//
	void swap(int*, int*);
	void swap(int&, int&);
	void print(int, int);

	int ex2()
	{
		int x = 5, y = 10;
		print(x, y);
		swap(&x, &y);
		print(x, y);
		swap(x, y);
		print(x, y);
		return 0;
	}

	void swap(int* x, int* y)
	{
		int temp;
		temp = *x;
		*x = *y;
		*y = temp;
	}
	void swap(int& x, int& y)
	{
		int temp;
		temp = x;
		x = y;
		y = temp;
	}
	void print(int x, int y)
	{
		std::cout << "x = " << x << "; y = " << y << std::endl;
	}

	//
	// Контрольное задание 1
	//
	int Myroot(double, double, double, double&, double&);
	int controlEx1()
	{
		int result;
		double a, b, c, x1, x2;
		std::cout << "Введите коэффиценты a, b, c для квадратного уравнения ax2+bx+c=0" << std::endl;
		std::cout << "a = ";
		std::cin >> a;
		std::cout << "b = ";
		std::cin >> b;
		std::cout << "c = ";
		std::cin >> c;
		result = Myroot(a, b, c, x1, x2);
		switch (result)
		{
		case 1:
			std::cout << "x1 = " << x1 << "\nx2 = " << x2 << std::endl;
			break;
		case 0:
			std::cout << "x1 = x2 = " << x1 << std::endl;
			break;
		case (-1):
			std::cout << "У данного уравнения корней нет.";
			break;
		default:
			std::cout << "Что-то пошло не по плану.";
			break;
		}
		return 0;
	}
	int Myroot(double a, double b, double c, double& x1, double& x2)
	{
		double D = b * b - 4 * a * c;
		if (D > 0)
		{
			x1 = ((-1) * b + sqrt (D)) / (2 * a);
			x2 = ((-1) * b - sqrt(D)) / (2 * a);;
			return 1;
		}
		else if (D == 0)
		{
			x1 = (- 1)* b / (2 * a);
			x2 = x1;
			return 0;
		}
		else
			return -1;
	}

	//
	// Контрольное задание 2
	//
	bool Input(int&, int&);
	int controlEx2()
	{
		int a, b;
		if(!Input(a,b))
		{
			std::cerr << "error";
			return 1;
		}
		int s = a + b;
		return 0;
	}
	bool Input(int& a, int& b)
	{
		double tA, tB;
		std::cout << "Введите два числа: " << std::endl;
		std::cin >> tA >> tB;
		if (tA - (int)tA != 0 || tA - (int)tA != 0)
			return false;
		else if (tA < 0 || tB < 0)
			return false;
		else
		{
			a = tA;
			b = tB;
			return true;
		}
	}
}