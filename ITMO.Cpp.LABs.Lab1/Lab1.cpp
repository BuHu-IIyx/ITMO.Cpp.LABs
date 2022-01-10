#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

//
// ���������� 1
//
void ex1() 
{
	string name;
	cout << "What is your name? ";
	getline(cin, name);
	cout << "Hello, " << name << "!\n";
}

//
// ���������� 2
//
void ex2() 
{	
	string name;	
	double x;
	double a, b;
	cout << "������� ���� ��� ";
	cout << "\n������� a � b: \n";
	cin >> a;
	cin >> name;
	cin >> b;
	x = a / b;
	//cout.precision(3);
	cout << "\nx = " << x << endl;
	cout << "������, " << name << "!\n";
	//cout << sizeof(a / b) << ends << " " << sizeof(x) << endl;
}

//
// ���������� 3
//
void ex3()
{
	double a, p, P;
	cout << "������� ��������:\n";
	cin >> P;
	a = P / 3; // ������ ������
	p = P / 2; // ������������
	double S = sqrt(p * pow((p - a), 3)); // �������	
	cout.precision(2);
	cout << left 
		<< setw(20)
		<< "������� "
		<< "�������\n";
	cout << left
		<< setw(20)
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
	cout << "������� ���������� ������:\n";
	cin >> n;
	int* arrayX = new int[n]; // ������ � � ����
	int* arrayY = new int[n]; // ������ Y � ����
	
	for (size_t i = 0; i < n; i++) // ������ � ���������� ��������� � �������
	{
		int x, y;
		cout << "������� ���������� ������� " << i + 1 << "\n" << "x = ";
		cin >> arrayX[i];
		cout << "y = ";
		cin >> arrayY[i];
	}

	int sum1 = 0, sum2 = 0;
	for (size_t i = 0; i < n; i++) // ������ ����������� ����
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
	double S = abs((double)(sum1 - sum2) / 2); // ���������� �������

	cout << "������� " << n << "-��������� ����� " << S << "\n"; // ����� ����������
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

