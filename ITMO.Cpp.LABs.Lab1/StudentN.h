#pragma once
#include "Human.h"
#include <iostream>
#include <string>
#include <vector>
using std::endl;
using std::cout;
using std::cin;
using std::string;

class StudentN :
    public Human
{
private:
    // Оценки студента
    std::vector<int> scores;
public:
    StudentN() { setData(); }
    // Конструктор класса Student
    StudentN(std::string last_name, std::string name, std::string second_name, std::vector<int> scores) :
        Human(last_name, name, second_name) 
    {
        this->scores = scores;
    }
    void setData()
    {
        Human::setData();
        while (true)
        {
            int temp;
            char flag = 'n';
            cout << "Введите оценку: ";
            cin >> temp;
            scores.push_back(temp);
            cout << "Ввести еще одну оценку (y,n)?";
            cin >> flag;
            if (flag == 'y' || flag == 'Y' || flag == 'н' || flag == 'Н')
                continue;
            else
            {
                break;
            }
        }
    }
    void printData()
    {
        cout << "Студент: ";
        Human::printData();
        cout << "Средний балл: " << get_average_score() << endl;
    }
    // Получение среднего балла студента    
    float get_average_score()
    {
        // Общее количество оценок
        unsigned int count_scores = this->scores.size();
        // Сумма всех оценок студента
        unsigned int sum_scores = 0;
        // Средний балл
        float average_score;
        for (unsigned int i = 0; i < count_scores; ++i) {
            sum_scores += this->scores[i];
        }
        average_score = (float)sum_scores / (float)count_scores;
        return average_score;
    }
};

