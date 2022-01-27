#include "Student.h"
#include <string>
#include <iostream>
#include <fstream>

using std::endl;
using std::cout;
using std::cin;
using std::string;

Student::Student(string name, string last_name)
{
	Student::set_name(name);
	Student::set_last_name(last_name);
}
Student::Student(string name, string last_name, IdCard* id)
{
	Student::set_name(name);
	Student::set_last_name(last_name);
	Student::setIdCard(id);
}

void Student::set_name(string student_name)
{
	Student::name = student_name;
}
// Получение имени студента
string Student::get_name()
{
	return Student::name;
}
// Установка фамилии студента
void Student::set_last_name(string student_last_name)
{
	Student::last_name = student_last_name;
}
// Получение фамилии студента
string Student::get_last_name()
{
	return Student::last_name;
}
// Установка промежуточных оценок
void Student::set_scores(int student_scores[])
{
	for (int i = 0; i < 5; ++i) {
		if (student_scores[i] > 5)
			throw ExScore("в функции set_scores()", student_scores[i]);			
		Student::scores[i] = student_scores[i];
	}
}
// Установка среднего балла
void Student::set_average_score(double ball)
{
	Student::average_score = ball;
}
// Получение среднего балла
double Student::get_average_score()
{
	return Student::average_score;
}
// Запись данных о студенте в файл
void Student::save()
{
	std::ofstream fout("students.txt", std::ios::app);
	fout << Student::get_name() << " "
		<< Student::get_last_name() << " ";
	string scores;
	for (int i = 0; i < 5; i++) {
		scores += std::to_string(Student::scores[i]) + " ";
	}
	fout << scores;
	fout << endl;
	fout.close();
}
// Деструктор Student
Student::~Student()
{
	Student::save();
}

Student::ExScore::ExScore(string Or, int sc)
{
	origin = Or; //строка с именем виновника ошибки
	iValue = sc; //сохраненное неправильное значение 
};

void Student::setIdCard(IdCard* c)
{
	iCard = c;
}
IdCard Student::getIdCard()
{
	return *iCard;
}

