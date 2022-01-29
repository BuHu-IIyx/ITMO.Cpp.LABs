#pragma once
#include <iostream>
#include <string>
#include <sstream>
using std::endl;
using std::cout;
using std::cin;
using std::string;

class Human
{
private:
	std::string name; // имя
	std::string last_name; // фамилия
	std::string second_name; // отчество
public:
	Human() {}
	// Конструктор класса human
	Human(std::string last_name, std::string name, std::string
		second_name)
	{
		this->last_name = last_name;
		this->name = name;
		this->second_name = second_name;
	}
	virtual void setData()
	{
		cout << "\nВведите имя : ";
		cin >> name;
		cout << "Введите фамилию : ";
		cin >> last_name;
		cout << "Введите отчество : ";
		cin >> second_name;
	}
	virtual void printData()
	{
		cout << get_full_name() << " | ";
	}
	// Получение ФИО человека
	std::string get_full_name()
	{
		std::ostringstream full_name;
		full_name << this->last_name << " "
			<< this->name << " "
			<< this->second_name;		
		return full_name.str();
	}
};

