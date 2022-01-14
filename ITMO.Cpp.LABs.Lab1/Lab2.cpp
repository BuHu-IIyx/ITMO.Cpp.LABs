#include "Header.h"
#include <iostream>
#include <math.h>

namespace Lab2
{
	//
	// Упражнение 1
	//
	int ex1()
	{
		int x, y;
		std::cout << "Введите координаты точки\n" << "x = ";
		std::cin >> x;
		std::cout << "y = ";
		std::cin >> y;
		if (x * x + y * y < 9 && y > 0)
			std::cout << "внутри";
		else if (x * x + y * y > 9 || y < 0)
			std::cout << "снаружи";
		else
			std::cout << "на границе";
		return 0;
	}

	//
	// Упражнение 2
	//
	int ex2()
	{
		double x, x1, x2, y;
		std::cout << "x1 = ";
		std::cin >> x1;
		std::cout << "x2 = ";
		std::cin >> x2;
		std::cout << "\tx\tsin(x)\n";
		x = x1;
		do
		{
			y = sin(x);
			std::cout << "\t" << x << "\t" << y << std::endl;
			x = x + 0.01;
		} 
		while (x <= x2);
		return 0;
	}

	//
	// Контрольное задание 1
	//
	int controlEx1()
	{
		int year;
		std::cout << "Введите год: ";
		std::cin >> year;
		if (year % 4 == 0 && year % 100 != 0)
			std::cout << "Год високосный!";
		else if (year % 400 == 0)
			std::cout << "Год високосный!";
		else
			std::cout << "Год НЕвисокосный!";
		return 0;
	}

	//
	// Контрольное задание 2
	//
	int controlEx2()
	{
		int x1, x2, x3;
		std::cout << "Введите 3 числа: ";
		std::cin >> x1;
		std::cin >> x2;
		std::cin >> x3;
		if (x1 > x2 && x1 > x3)
			std::cout << x1;
		else if (x2 > x1 && x2 > x3)
			std::cout << x2;
		else
			std::cout << x3;
		return 0;
	}
	
	//
	// Контрольное задание 3
	//
	int controlEx3()
	{
		char flag = 'Y';
		while (flag == 'Y' || flag == 'y')
		{
			double cost;
			std::cout << "Введите сумму, которую необходимо выдать: ";
			std::cin >> cost;
			double nominal[15]{ 5000, 2000, 1000, 500, 200, 100, 50, 10, 5, 2, 1, 0.5, 0.1, 0.05, 0.01 };

			for (double x : nominal)
			{
				if (cost == 0)
					break;
				else if (cost < x)
					continue;
				else
				{
					int quantity = cost / x;
					cost = cost - (quantity * x);
					std::cout << x << ": " << quantity << "руб.\n";
				}
			}			
			std::cout << "Введите 'Y', чтоб повторить: \n";
			std::cin >> flag;
		}		
		return 0;
	}

	//
	// Контрольное задание 4
	//
	int controlEx4()
	{
		srand(time(0));
		int a = rand() % 10 - 5, 
			b = rand() % 10 - 5, 
			x, y;
		bool flag = true;
		int score = 0;
		int count = 0;
		std::cout << a << b;
		while (flag)
		{			
			std::cout << "Введите координаты выстрела:\nx = ";
			std::cin >> x;
			std::cout << "y = ";
			std::cin >> y;
			int shot;
			if (checkInRound(a, b, x, y, 1))
				shot = 10;
			else if (checkInRound(a, b, x, y, 2))
				shot = 5;
			else if (checkInRound(a, b, x, y, 3))
				shot = 1;
			else
				shot = 0;
			if (shot == 0)
				std::cout << "Промах\n";
			else
				std::cout << "Попадение на " << shot << "\n";
			count += 1;
			score += shot;
			if (score >= 30 || count > 15)
				break;
		}
		std::cout << score << " очков набрано за " << count << " выстрелов.\nУровень игры: ";
		if (count < 6)
			std::cout << "Снайпер!";
		else if (count < 12)
			std::cout << "Стрелок!";
		else
			std::cout << "Новичок!";
		return 0;
	}

	bool checkInRound(int a, int b, int x, int y, int R) // Проверка на нахожение точки внутри окружности
	{
		if (pow((x - a), 2) + pow((y - b), 2) < pow(R, 2))
			return true;
		else
			return false;
	}
}