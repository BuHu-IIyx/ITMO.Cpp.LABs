#include "Header.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

namespace Lab1 
{
	//
	// ���������� 1
	//
	void ex1()
	{
		std::string name;
		std::cout << "What is your name? ";
		std::getline(std::cin, name);
		std::cout << "Hello, " << name << "!\n";
	}

	//
	// ���������� 2
	//
	void ex2()
	{
		std::string name;
		double x;
		double a, b;
		std::cout << "������� ���� ��� ";
		std::cout << "\n������� a � b: \n";
		std::cin >> a;
		std::cin >> name;
		std::cin >> b;
		x = a / b;
		//cout.precision(3);
		std::cout << "\nx = " << x << std::endl;
		std::cout << "������, " << name << "!\n";
		//cout << sizeof(a / b) << ends << " " << sizeof(x) << endl;
	}

	//
	// ���������� 3
	//
	void ex3()
	{
		double a, p, P;
		std::cout << "������� ��������:\n";
		std::cin >> P;
		a = P / 3; // ������ ������
		p = P / 2; // ������������
		double S = sqrt(p * pow((p - a), 3)); // �������	
		std::cout.precision(2);
		std::cout << std::left
				<< std::setw(20)
				<< "������� "
				<< "�������\n";
		std::cout << std::left
				<< std::setw(20)
				<< a
				<< " "
				<< S;
	}

	//
	// ����������� �������
	//
	void controlEx()
	{
		int n;
		std::cout << "������� ���������� ������:\n";
		std::cin >> n;
		int* arrayX = new int[n]; // ������ � � ����
		int* arrayY = new int[n]; // ������ Y � ����

		for (size_t i = 0; i < n; i++) // ������ � ���������� ��������� � �������
		{
			int x, y;
			std::cout << "������� ���������� ������� " << i + 1 << "\n" << "x = ";
			std::cin >> arrayX[i];
			std::cout << "y = ";
			std::cin >> arrayY[i];
		}

		int sum1 = 0, sum2 = 0;
		for (size_t i = 0; i < n; i++) // ������ ����������� ����
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
		double S = abs((double)(sum1 - sum2) / 2); // ���������� �������

		std::cout << "������� " << n << "-��������� ����� " << S << "\n"; // ����� ����������
	}
}