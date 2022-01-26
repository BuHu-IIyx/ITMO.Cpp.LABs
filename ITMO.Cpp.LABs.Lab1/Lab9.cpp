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
	// Упражнение 1
	//	
	class DivideByZeroError
	{
	public:
		DivideByZeroError() : message("Деление на нуль") { }
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
		cout << "Введите два целых числа для расчета их частного:\n";
		int number1, number2;
		cin >> number1;
		cin >> number2;
		try
		{
			float result = quotient(number1, number2);
			cout << "Частное равно " << result << endl;
		}
		catch (DivideByZeroError& error)
		{
			cout << "ОШИБКА: ";
			error.printMessage();
			return 1; // завершение программы при ошибке
		}
		return 0; // нормальное завершение программ
	}
	//
	// Упражнение 2
	//	
	int ex2()
	{
		cout << "Введите число для расчета частного:\n";
		int number1;
		cin >> number1;
		for (int i = -10; i < 10; i++)
		{
			try
			{
				float result = quotient(number1, i);
				cout << "Частное равно " << result << endl;
			}
			catch (DivideByZeroError& error)
			{
				cout << "ОШИБКА: ";
				error.printMessage();
			}
		}
		return 0; // нормальное завершение программ
	}
	//
	// Упражнение 3
	//	
	int ex3()
	{
		// Создание объекта класса Student
		string name;
		string last_name;
		int scores[5];
		// Ввод имени с клавиатуры
		cout << "Name: ";
		getline(cin, name);
		// Ввод фамилии
		cout << "Last name: ";
		getline(cin, last_name);
		// Сумма всех оценок
		int sum = 0;
		// Ввод промежуточных оценок
		for (int i = 0; i < 5; ++i) {
			cout << "Score " << i + 1 << ": ";
			cin >> scores[i];
			// суммирование
			sum += scores[i];
		}
		Student* student02 = new Student(name, last_name);
		try 
		{
			// Сохранение промежуточных оценок в объект класса Student
			student02->set_scores(scores);
		}
		catch(Student::ExScore& ex)
		{
			cout << "\nОшибка инициализации " << ex.origin;
			cout << "\nВведенное значение оценки " << ex.iValue <<
				" является недопустимым" << endl;
		}		
		// Считаем средний балл
		double average_score = sum / 5.0;
		// Сохранение среднего балла в объект класса Student
		student02->set_average_score(average_score);

		cout << "Average ball for " << student02->get_name() << " "
			<< student02->get_last_name() << " is "
			<< student02->get_average_score() << endl;
		delete student02;
		return 0;
	}
	//
	// Контрольное задание 1
	//
	int controlEx1()
	{
		double a, b, c;
		cout << "Введите длинны 3-х сторон: ";
		cin >> a >> b >> c;
		Triangle* triangle;
		try 
		{
			triangle = new Triangle(a, b, c);			
		}
		catch (Triangle::ExInit& ex)
		{
			cout << "\nОшибка инициализации: " << ex.message << endl;
			return -1;
		}
		cout << "Площадь треугольника равна " << triangle->getArea() << endl;
		return 0;
	}
	//
	// Контрольное задание 2
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
			cout << "\nОшибка инициализации: " << ex.message << endl;
			return -1;
		}
		return 0;
	}
}