#pragma once
#include "Human.h"
#include <iostream>
#include <string>
using std::endl;
using std::cout;
using std::cin;
using std::string;

class Teacher :
    public Human
{
private:
    // Учебные часы
    unsigned int work_time;
    // Конструктор класса teacher
public:
    Teacher() { setData(); }
    Teacher(std::string last_name, std::string name, std::string second_name, unsigned int work_time) 
        : Human(last_name, name, second_name) 
    {
        this->work_time = work_time;
    }
    void setData()
    {
        Human::setData();
        cout << "Количество часов: ";
        cin >> work_time;

    }
    void printData()
    {
        cout << "Преподаватель: ";
        Human::printData();
        cout << "Количество часов: " << work_time << endl;
    }
    // Получение количества учебных часов
    unsigned int get_work_time()
    {
        return this->work_time;
    }
};

