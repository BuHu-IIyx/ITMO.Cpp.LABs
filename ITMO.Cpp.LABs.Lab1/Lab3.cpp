#include "Header.h"
#include <iostream>
#include <string>

namespace Lab3
{
	void privet(std::string);
	void privet(std::string, int);
	std::string privet2(std::string);
	long double firBinSearch(double, int);
	int addNumbers(int);
	int gcd(int, int);

	//
	// Упражнение 1
	//
	int ex1()
	{
		std::string name;
		std::cout << "What is your name?" << std::endl;
		std::cin >> name;
		privet(name);
		std::cout << privet2(name);
		return 0;
	}

	void privet(std::string name)
	{
		std::cout << name << ", hello!" << std::endl;
	}

	std::string privet2(std::string name)
	{
		return name + ", hello!\n";
	}

	//
	// Упражнение 2
	//
	int ex2()
	{
		int k;
		std::string name;
		std::cout << "What is your name?" << std::endl;
		std::cin >> name;
		std::cout << "Input number:" << std::endl;
		std::cin >> k;
		privet(name);
		privet(name, k);
		return 0;
	}
	void privet(std::string name, int k) // Перегруженная функция
	{
		std::cout << name << ", hello! You input " << k << std::endl;
	}

	//
	// Упражнение 3
	//
	int ex3()
	{		
		double a;
		int n;
		std::string text = "Введите число и и степень корня, которую необходимо вычислить через пробел:\n";
		while (true)
		{
			std::cout << text;
			std::cin >> a >> n;
			if (a < 1 || a > 1000)
			{
				text = "Число не может быть меньше 1 и больше 1000.\n Повторите ввод:\n";
				continue;
			}
			else if (n > 10)
			{
				text = "Степень не может быть больше 10.\n Повторите ввод:\n";
				continue;
			}
			else
			{
				break;
			}
		}
		std::cout << "Результат = " << firBinSearch(a, n) << std::endl;

		return 0;
	}

	long double firBinSearch(double a, int n)
	{
		double L = 0;
		double R = a;
		while (R - L > 1e-10)
		{
			double M = (L + R) / 2;
			if (pow(M, n) < a)
				L = M;
			else
				R = M;
		}
		return R;
	}

	//
	// Упражнение 4
	//
	int ex4()
	{
		int n, m;
		std::cout << "Введите 2 числа: ";
		std::cin >> n >> m;		
		std::cout << "Сумма чисел: " << addNumbers(n) << std::endl;
		std::cout << "Общий делитель: " << gcd(n, m);
		return 0;
	}
	
	int addNumbers(int n)
	{
		if (n == 1)
			return 1;
		else
			return (n + addNumbers(n - 1));
	}

	int gcd(int m, int n)
	{
		if (n == 0) 
			return m;
		return gcd(n, m % n);
	}

	//
	// Контрольное задание 1
	//
	struct POINT
	{
		int x;
		int y;
	};

	struct TRIANGLE
	{
		POINT a;
		POINT b;
		POINT c;
	};

	struct FIVEANGLE
	{
		POINT a;
		POINT b;
		POINT c;
		POINT d;
		POINT e;
	};

	double lengthSide(POINT& a, POINT& b)
	{
		double L = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
		return L;
	};

	double halfPerimeter(TRIANGLE& triangle)
	{
		double P = lengthSide(triangle.a, triangle.b) +
			lengthSide(triangle.b, triangle.c) + lengthSide(triangle.c, triangle.a);
		return P/2;
	};

	double areaTriangle(TRIANGLE& triangle)
	{
		double hPerimeter = halfPerimeter(triangle);
		double sideA = lengthSide(triangle.a, triangle.b);
		double sideB = lengthSide(triangle.b, triangle.c);
		double sideC = lengthSide(triangle.c, triangle.a);
		double area = sqrt(hPerimeter * (hPerimeter - sideA) * (hPerimeter - sideB) * (hPerimeter - sideC));
		std::cout << "Площадь треугольника: " << area << std::endl;
		return area;
	};

	double areaFiveAngle(FIVEANGLE& fiveAngle)
	{
		TRIANGLE triangle1 = { fiveAngle.a, fiveAngle.b, fiveAngle.c };
		TRIANGLE triangle2 = { fiveAngle.c, fiveAngle.d, fiveAngle.e };
		TRIANGLE triangle3 = { fiveAngle.e, fiveAngle.a, fiveAngle.c };
		double area = areaTriangle(triangle1) + areaTriangle(triangle2) + areaTriangle(triangle3);
		return area;
	};

	int controlEx1()
	{
		POINT pointA = { 3, 4 };
		POINT pointB = { 5, 11 };
		POINT pointC = { 12, 8 };
		POINT pointD = { 11, 3 };
		POINT pointE = { 5, 3 };
		FIVEANGLE fiveAngle = { pointA, pointB, pointC, pointD, pointE };
		std::cout << "Площадь равна: " << areaFiveAngle(fiveAngle) << std::endl;
		return 0;
	};

	//
	// Контрольное задание 2
	//
	double cubicRoot1(double a)
	{
		return pow(a, (1. / 3.));
	}

	double cubicRoot2(double a)
	{
		double x = a;
		double x1 = 0;
		while (abs(x - x1) > 0.00001)
		{
			x1 = x;
			x = ((a / pow(x1, 2)) + 2 * x1) / 3;
		}
		return x;
	}

	int controlEx2()
	{
		double a;
		std::cout << "Введите число: ";
		std::cin >> a;
		std::cout << "Первый результат: " << cubicRoot1(a) << std::endl;
		std::cout << "Второй результат: " << cubicRoot2(a) << std::endl;
		return 0;
	}

	//
	// Контрольное задание 3
	//
	double areaTriang(int a)
	{
		double p = (3. * a) / 2.;
		double S = sqrt(p * pow((p - a), 3)); // Площадь
		return S;
	}
	double areaTriang(int a, int b, int c)
	{
		double p = (a + b + c) / 2.;
		double S = sqrt(p * (p - a) * (p - b) * (p - c)); // Площадь
		return S;
	}
	int controlEx3()
	{
		char check;
		std::cout << "Треугольник равносторонний? (Y/N)";
		std::cin >> check;
		int a, b, c;
		double S;
		if (check == 'Y')
		{
			std::cout << "Введите длинну стороны: ";
			std::cin >> a;
			S = areaTriang(a);
		}
		else
		{
			std::cout << "Введите длинны 3-х сторон: ";
			std::cin >> a >> b >> c;
			S = areaTriang(a, b, c);
		}
		std::cout << "Площадь равна: " << S << std::endl;
		return 0;
	}
	//
	// Контрольное задание 4
	//
	int rowSum(int n)
	{
		if (n <= 0)
		{
			return 0;
		}
		else
			return (5 * n + rowSum(n - 1));
	}
	int controlEx4()
	{
		int n;
		std::cout << "Введите число: ";
		std::cin >> n;
		std::cout << "Сумма равна: " << rowSum(n) << std::endl;
		return 0;
	}

	//
	// Контрольное задание 5
	//
	int encod2(int num)
	{
		if (num < 2)
			return num;
		else
			return (10 * encod2(num / 2) + num % 2);
	}

	int controlEx5()
	{
		int num;
		std::cout << "Введите число: ";
		std::cin >> num;
		std::cout << "В двоичном коде: " << encod2(num) << std::endl;
		return 0;
	}	
}