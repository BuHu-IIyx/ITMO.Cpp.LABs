#include <iostream>
#include <string>
#include "Student.h"
#include "Triangle.h"
#include "Time.h"
using std::endl;
using std::cout;
using std::cin;
using std::string;

namespace Lab9
{
	//
	// ���������� 1
	//	
	class DivideByZeroError
	{
	public:
		DivideByZeroError() : message("������� �� ����") { }
		void printMessage() const { cout << message << endl; }
	private:
		string message;
	};

	float quotient(int numl, int num2)
	{
		if (num2 == 0)
			throw DivideByZeroError();
		return (float)numl / num2;
	}

	int ex1()
	{
		cout << "������� ��� ����� ����� ��� ������� �� ��������:\n";
		int number1, number2;
		cin >> number1;
		cin >> number2;
		try
		{
			float result = quotient(number1, number2);
			cout << "������� ����� " << result << endl;
		}
		catch (DivideByZeroError& error)
		{
			cout << "������: ";
			error.printMessage();
			return 1; // ���������� ��������� ��� ������
		}
		return 0; // ���������� ���������� ��������
	}
	//
	// ���������� 2
	//	
	int ex2()
	{
		cout << "������� ����� ��� ������� ��������:\n";
		int number1;
		cin >> number1;
		for (int i = -10; i < 10; i++)
		{
			try
			{
				float result = quotient(number1, i);
				cout << "������� ����� " << result << endl;
			}
			catch (DivideByZeroError& error)
			{
				cout << "������: ";
				error.printMessage();
			}
		}
		return 0; // ���������� ���������� ��������
	}
	//
	// ���������� 3
	//	
	int ex3()
	{
		// �������� ������� ������ Student
		string name;
		string last_name;
		int scores[5];
		// ���� ����� � ����������
		cout << "Name: ";
		getline(cin, name);
		// ���� �������
		cout << "Last name: ";
		getline(cin, last_name);
		// ����� ���� ������
		int sum = 0;
		// ���� ������������� ������
		for (int i = 0; i < 5; ++i) {
			cout << "Score " << i + 1 << ": ";
			cin >> scores[i];
			// ������������
			sum += scores[i];
		}
		Student* student02 = new Student(name, last_name);
		try 
		{
			// ���������� ������������� ������ � ������ ������ Student
			student02->set_scores(scores);
		}
		catch(Student::ExScore& ex)
		{
			cout << "\n������ ������������� " << ex.origin;
			cout << "\n��������� �������� ������ " << ex.iValue <<
				" �������� ������������" << endl;
		}		
		// ������� ������� ����
		double average_score = sum / 5.0;
		// ���������� �������� ����� � ������ ������ Student
		student02->set_average_score(average_score);

		cout << "Average ball for " << student02->get_name() << " "
			<< student02->get_last_name() << " is "
			<< student02->get_average_score() << endl;
		delete student02;
		return 0;
	}
	//
	// ����������� ������� 1
	//
	int controlEx1()
	{
		double a, b, c;
		cout << "������� ������ 3-� ������: ";
		cin >> a >> b >> c;
		Triangle* triangle;
		try 
		{
			triangle = new Triangle(a, b, c);			
		}
		catch (Triangle::ExInit& ex)
		{
			cout << "\n������ �������������: " << ex.message << endl;
			return -1;
		}
		cout << "������� ������������ ����� " << triangle->getArea() << endl;
		return 0;
	}
	//
	// ����������� ������� 2
	//
	int controlEx2()
	{
		try 
		{
			Time time1{ 4, 20, 55 };
			Time time2{ -2, 55, 32 };
			Time aTime = aTime.addTime(time1, time2);
			cout << aTime.getTime();
		}
		catch(Time::ExInit& ex)
		{
			cout << "\n������ �������������: " << ex.message << endl;
			return -1;
		}
		return 0;
	}
}