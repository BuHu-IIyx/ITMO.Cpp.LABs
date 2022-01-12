#include "Header.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

namespace Lab1 
{
	//
	// Упражнение 1
	//
	void ex1()
	{
		std::string name;
		std::cout << "What is your name? ";
		std::getline(std::cin, name);
		std::cout << "Hello, " << name << "!\n";
	}

	//
	// Упражнение 2
	//
	void ex2()
	{
		std::string name;
		double x;
		double a, b;
		std::cout << "Введите свое имя ";
		std::cout << "\nВведите a и b: \n";
		std::cin >> a;
		std::cin >> name;
		std::cin >> b;
		x = a / b;
		//cout.precision(3);
		std::cout << "\nx = " << x << std::endl;
		std::cout << "Привет, " << name << "!\n";
		//cout << sizeof(a / b) << ends << " " << sizeof(x) << endl;
	}

	//
	// Упражнение 3
	//
	void ex3()
	{
		double a, p, P;
		std::cout << "Введите периметр:\n";
		std::cin >> P;
		a = P / 3; // Длинна сторон
		p = P / 2; // Полупериметр
		double S = sqrt(p * pow((p - a), 3)); // Площадь	
		std::cout.precision(2);
		std::cout << std::left
				<< std::setw(20)
				<< "Сторона "
				<< "Площадь\n";
		std::cout << std::left
				<< std::setw(20)
				<< a
				<< " "
				<< S;
	}

	//
	// Контрольное задание
	//
	void controlEx()
	{
		int n;
		std::cout << "Введите количество вершин:\n";
		std::cin >> n;
		int* arrayX = new int[n]; // Массив Х в куче
		int* arrayY = new int[n]; // Массив Y в куче

		for (size_t i = 0; i < n; i++) // Запрос и добавление координат в массивы
		{
			int x, y;
			std::cout << "Введите координаты вершины " << i + 1 << "\n" << "x = ";
			std::cin >> arrayX[i];
			std::cout << "y = ";
			std::cin >> arrayY[i];
		}

		int sum1 = 0, sum2 = 0;
		for (size_t i = 0; i < n; i++) // Расчет контрольных сумм
		{

			if (i + 1 == n)
			{
				sum1 = sum1 + (arrayX[i] * arrayY[0]);
				sum2 = sum2 + (arrayY[i] * arrayX[0]);
			}
			else
			{
				sum1 = sum1 + (arrayX[i] * arrayY[i + 1]);
				sum2 = sum2 + (arrayY[i] * arrayX[i + 1]);
			}
		}
		double S = abs((double)(sum1 - sum2) / 2); // Вычисление площади

		std::cout << "Площадь " << n << "-угольника равна " << S << "\n"; // Вывод результата
	}
}