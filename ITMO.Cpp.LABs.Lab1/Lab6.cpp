#include "Header.h"
#include <iostream>
#include <fstream>
using std::endl;
using std::cout;
using std::cin;

namespace Lab6
{
	//
	// Упражнение 1
	//
	int ex1()
	{
		double sum = 0;
		int const n = 100;
		double nums[n];
		for (int i = 0; i < n; i++)
		{
			nums[i] = (rand() % 100);
		}
		std::ofstream out("test", std::ios::out | std::ios::binary);
		if (!out)
		{
			cout << "Файл открыть невозможно\n";
			return 1;
		}
		out.write((char*)nums, sizeof(nums));
		out.close();		
		std::ifstream in("test", std::ios::in | std::ios::binary);
		if (!in)
		{
			cout << "Файл открыть невозможно";
			return 1;
		}
		in.read((char*)&nums, sizeof(nums));
		int k = sizeof(nums) / sizeof(double);
		for (int i = 0; i < k; i++)
		{
			sum = sum + nums[i];
			cout << nums[i] << ' ';
		}
		cout << "\nsum = " << sum << endl;
		in.close();
		return 0;
	}
	//
	// Контрольное задание 1
	//
	int controlEx1()
	{
		
		std::ofstream fout("Lab5Ex1.txt");
		if (!fout)
		{
			cout << "Файл открыть невозможно\n";
			return 1;
		}
		char buffer[255];
		cout << "Введите текст (для выхода введите пустую строку):\n";
		do
		{
			buffer[0] = '\0';
			cin.getline(buffer, 255);
			fout << buffer << "\n";			
			if (buffer[0] == '\0')
				break;
			else
				continue;

		} while (true);
			
		fout.close();
		return 0;
	}
	//
	// Контрольное задание 2
	//
	int controlEx2()
	{
		std::ofstream out("Lab5Ex2", std::ios::out | std::ios::binary);
		if (!out)
		{
			cout << "Файл открыть невозможно\n";
			return 1;
		}
		const int N = 10;
		int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
		out.write((char*)a, sizeof(a));
		int min = 0; // для записи минимального значения
		int buf = 0; // для обмена значениями
		for (int i = 0; i < N; i++)
		{
			min = i; // номер текущей ячейки, как ячейки с минимальным значением
			// в цикле найдем реальный номер ячейки с минимальным значением
			for (int j = i + 1; j < N; j++)
				min = (a[j] < a[min]) ? j : min;
			// перестановка этого элемента, поменяв его местами с текущим
			if (i != min)
			{
				buf = a[i];
				a[i] = a[min];
				a[min] = buf;
			}
		}
		out << "\n";
		out.write((char*)a, sizeof(a));
		out.close();
		return 0;
	}
}