#include "Header.h"
#include <iomanip>
#include <iostream>
#include <string>

int main()
{	
	void printName(int, int);
	system("chcp 1251");
	//Lab1::ex1();
	//Lab1::ex2();
	//Lab1::ex3();
	//Lab1::controlEx();
	//Lab2::ex1();
	//Lab2::ex2();
	//Lab2::controlEx1();
	//Lab2::controlEx2();
	//Lab2::controlEx3();
	//Lab2::controlEx4();
	//Lab3::ex1();
	//Lab3::ex2();
	//Lab3::ex3();
	//Lab3::ex4();
	printName(3, 1);
	Lab3::controlEx1();
	printName(3, 2);
	Lab3::controlEx2();
	printName(3, 3);
	Lab3::controlEx3();
	printName(3, 4);
	Lab3::controlEx4();
	printName(3, 5);
	Lab3::controlEx5();
	//Lab4::ex1();
	//Lab4::ex2();
	printName(4, 1);
	Lab4::controlEx1();
	printName(4, 2);
	Lab4::controlEx2();
	return 0;
}

void printName(int lab, int ex, std::string name)
{
	std::cout << "\n--------------------"
		<< "\nПрактическое занятие " << lab
		<< "\nУпражнение " << ex
		<< "\n--------------------" << std::endl;
}