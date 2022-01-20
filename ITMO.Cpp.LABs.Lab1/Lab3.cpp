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
	// ���������� 1
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
	// ���������� 2
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
	void privet(std::string name, int k) // ������������� �������
	{
		std::cout << name << ", hello! You input " << k << std::endl;
	}

	//
	// ���������� 3
	//
	int ex3()
	{		
		double a;
		int n;
		std::string text = "������� ����� � � ������� �����, ������� ���������� ��������� ����� ������:\n";
		while (true)
		{
			std::cout << text;
			std::cin >> a >> n;
			if (a < 1 || a > 1000)
			{
				text = "����� �� ����� ���� ������ 1 � ������ 1000.\n ��������� ����:\n";
				continue;
			}
			else if (n > 10)
			{
				text = "������� �� ����� ���� ������ 10.\n ��������� ����:\n";
				continue;
			}
			else
			{
				break;
			}
		}
		std::cout << "��������� = " << firBinSearch(a, n) << std::endl;

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
	// ���������� 4
	//
	int ex4()
	{
		int n, m;
		std::cout << "������� 2 �����: ";
		std::cin >> n >> m;		
		std::cout << "����� �����: " << addNumbers(n) << std::endl;
		std::cout << "����� ��������: " << gcd(n, m);
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
	// ����������� ������� 1
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
		std::cout << "������� ������������: " << area << std::endl;
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
		std::cout << "������� �����: " << areaFiveAngle(fiveAngle) << std::endl;
		return 0;
	};

	//
	// ����������� ������� 2
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
		std::cout << "������� �����: ";
		std::cin >> a;
		std::cout << "������ ���������: " << cubicRoot1(a) << std::endl;
		std::cout << "������ ���������: " << cubicRoot2(a) << std::endl;
		return 0;
	}

	//
	// ����������� ������� 3
	//
	double areaTriang(int a)
	{
		double p = (3. * a) / 2.;
		double S = sqrt(p * pow((p - a), 3)); // �������
		return S;
	}
	double areaTriang(int a, int b, int c)
	{
		double p = (a + b + c) / 2.;
		double S = sqrt(p * (p - a) * (p - b) * (p - c)); // �������
		return S;
	}
	int controlEx3()
	{
		char check;
		std::cout << "����������� ��������������? (Y/N)";
		std::cin >> check;
		int a, b, c;
		double S;
		if (check == 'Y')
		{
			std::cout << "������� ������ �������: ";
			std::cin >> a;
			S = areaTriang(a);
		}
		else
		{
			std::cout << "������� ������ 3-� ������: ";
			std::cin >> a >> b >> c;
			S = areaTriang(a, b, c);
		}
		std::cout << "������� �����: " << S << std::endl;
		return 0;
	}
	//
	// ����������� ������� 4
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
		std::cout << "������� �����: ";
		std::cin >> n;
		std::cout << "����� �����: " << rowSum(n) << std::endl;
		return 0;
	}

	//
	// ����������� ������� 5
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
		std::cout << "������� �����: ";
		std::cin >> num;
		std::cout << "� �������� ����: " << encod2(num) << std::endl;
		return 0;
	}	
}