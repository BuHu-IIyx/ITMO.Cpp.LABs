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
    // ������ ��������
    std::vector<int> scores;
public:
    StudentN() { setData(); }
    // ����������� ������ Student
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
            cout << "������� ������: ";
            cin >> temp;
            scores.push_back(temp);
            cout << "������ ��� ���� ������ (y,n)?";
            cin >> flag;
            if (flag == 'y' || flag == 'Y' || flag == '�' || flag == '�')
                continue;
            else
            {
                break;
            }
        }
    }
    void printData()
    {
        cout << "�������: ";
        Human::printData();
        cout << "������� ����: " << get_average_score() << endl;
    }
    // ��������� �������� ����� ��������    
    float get_average_score()
    {
        // ����� ���������� ������
        unsigned int count_scores = this->scores.size();
        // ����� ���� ������ ��������
        unsigned int sum_scores = 0;
        // ������� ����
        float average_score;
        for (unsigned int i = 0; i < count_scores; ++i) {
            sum_scores += this->scores[i];
        }
        average_score = (float)sum_scores / (float)count_scores;
        return average_score;
    }
};

