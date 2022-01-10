#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

//
// Упражнение 1
//
void ex1() 
{
	string name;
	cout << "What is your name? ";
	getline(cin, name);
	cout << "Hello, " << name << "!\n";
}

//
// Упражнение 2
//
void ex2() 
{	
	string name;	
	double x;
	double a, b;
	cout << "Введите свое имя ";
	cout << "\nВведите a и b: \n";
	cin >> a;
	cin >> name;
	cin >> b;
	x = a / b;
	//cout.precision(3);
	cout << "\nx = " << x << endl;
	cout << "Привет, " << name << "!\n";
	//cout << sizeof(a / b) << ends << " " << sizeof(x) << endl;
}

//
// Упражнение 3
//
void ex3()
{
	double a, p, P;
	cout << "Введите периметр:\n";
	cin >> P;
	a = P / 3; // Длинна сторон
	p = P / 2; // Полупериметр
	double S = sqrt(p * pow((p - a), 3)); // Площадь	
	cout.precision(2);
	cout << left 
		<< setw(20)
		<< "Сторона "
		<< "Площадь\n";
	cout << left
		<< setw(20)
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
	cout << "Введите количество вершин:\n";
	cin >> n;
	int* arrayX = new int[n]; // Массив Х в куче
	int* arrayY = new int[n]; // Массив Y в куче
	
	for (size_t i = 0; i < n; i++) // Запрос и добавление координат в массивы
	{
		int x, y;
		cout << "Введите координаты вершины " << i + 1 << "\n" << "x = ";
		cin >> arrayX[i];
		cout << "y = ";
		cin >> arrayY[i];
	}

	int sum1 = 0, sum2 = 0;
	for (size_t i = 0; i < n; i++) // Расчет контрольных сумм
	{

		if (i+1 == n)
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

	cout << "Площадь " << n << "-угольника равна " << S << "\n"; // Вывод результата
}


int main()
{
	system("chcp 1251");
	//ex1();
	//ex2();
	//ex3();
	controlEx();
	return 0;
}

