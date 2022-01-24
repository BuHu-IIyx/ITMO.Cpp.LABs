#include <iostream>
#include <string>
#include "student.h"
using std::endl;
using std::cout;
using std::cin;
using std::string;


namespace Lab8
{
	//
	// ”пражнение 1
	//	
	int ex1()
	{
		// —оздание объекта класса Student
		
		string name;
		string last_name;
		int scores[5];
		// ¬вод имени с клавиатуры
		cout << "Name: ";
		getline(cin, name);
		// ¬вод фамилии
		cout << "Last name: ";
		getline(cin, last_name);
		// —умма всех оценок
		int sum = 0;
		// ¬вод промежуточных оценок
		for (int i = 0; i < 5; ++i) {
			cout << "Score " << i + 1 << ": ";
			cin >> scores[i];
			// суммирование
			sum += scores[i];
		}
		Student* student02 = new Student(name, last_name);
		// —охранение промежуточных оценок в объект класса Student
		student02->set_scores(scores);
		// —читаем средний балл
		double average_score = sum / 5.0;
		// —охранение среднего балла в объект класса Student
		student02->set_average_score(average_score);

		cout << "Average ball for " << student02->get_name() << " "
			<< student02->get_last_name() << " is "
			<< student02->get_average_score() << endl;
		delete student02;
		return 0;
	}

}