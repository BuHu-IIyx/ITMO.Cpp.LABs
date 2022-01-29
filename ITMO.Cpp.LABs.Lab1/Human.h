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
	std::string name; // ���
	std::string last_name; // �������
	std::string second_name; // ��������
public:
	Human() {}
	// ����������� ������ human
	Human(std::string last_name, std::string name, std::string
		second_name)
	{
		this->last_name = last_name;
		this->name = name;
		this->second_name = second_name;
	}
	virtual void setData()
	{
		cout << "\n������� ��� : ";
		cin >> name;
		cout << "������� ������� : ";
		cin >> last_name;
		cout << "������� �������� : ";
		cin >> second_name;
	}
	virtual void printData()
	{
		cout << get_full_name() << " | ";
	}
	// ��������� ��� ��������
	std::string get_full_name()
	{
		std::ostringstream full_name;
		full_name << this->last_name << " "
			<< this->name << " "
			<< this->second_name;		
		return full_name.str();
	}
};

