#include "IdCard.h"
#include "Student.h"
#include <iostream>
#include <string>
#include "Dot.h"
#include "DotTriangle.h"
using std::endl;
using std::cout;
using std::cin;
using std::string;

namespace Lab10
{
	//
	// Упражнение 1
	//	
	int ex1()
	{
		IdCard idc(123, "Базовый");
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
		Student* student02 = new Student(name, last_name, &idc);
		try
		{
			// Сохранение промежуточных оценок в объект класса Student
			student02->set_scores(scores);
		}
		catch (Student::ExScore& ex)
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
		cout << "IdCard: " << student02->getIdCard().getNumber() << endl;
		cout << "Category: " << student02->getIdCard().getCategory() << endl;
		delete student02;
		return 0;
	}
	//
	// Контрольное задание 1
	//
	int controlEx1()
	{
		/*int x, y;
		std::cout << "Введите координаты вершины A\n" << "x = ";
		std::cin >> x;
		std::cout << "y = ";
		std::cin >> y;
		Dot pointA (x, y);
		std::cout << "Введите координаты вершины B\n" << "x = ";
		std::cin >> x;
		std::cout << "y = ";
		std::cin >> y;
		Dot pointB (x, y);
		std::cout << "Введите координаты вершины C\n" << "x = ";
		std::cin >> x;
		std::cout << "y = ";
		std::cin >> y;
		Dot pointC (x, y);*/

		Dot pointA = { 3, 4 };
		Dot pointB = { 5, 11 };
		Dot pointC = { 12, 8 };

		DotTriangle triangle (pointA, pointB, pointC);
		cout << "Сторона А: " << triangle.getLength('A') << endl;
		cout << "Сторона B: " << triangle.getLength('B') << endl;
		cout << "Сторона C: " << triangle.getLength('C') << endl;
		cout << "Периметр равен: " << triangle.getPerimeter() << endl;
		cout << "Площадь равна: " << triangle.getArea() << endl;
		return 0;
	}
}