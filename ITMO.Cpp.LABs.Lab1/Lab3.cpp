#include "Header.h"
#include <iostream>
#include <string>

namespace Lab3
{
	void privet(std::string);
	void privet(std::string, int);
	std::string privet2(std::string);
	long double firBinSearch(double, int);

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

	}

	//
	// Контрольное задание
	//
}