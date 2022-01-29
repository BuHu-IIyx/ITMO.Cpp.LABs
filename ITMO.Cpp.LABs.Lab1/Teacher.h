#pragma once
#include "Human.h"
#include <string>

class Teacher :
    public Human
{
private:
    // ������� ����
    unsigned int work_time;
    // ����������� ������ teacher
public:
    Teacher(std::string last_name, std::string name, std::string second_name, unsigned int work_time) 
        : Human(last_name, name, second_name) 
    {
        this->work_time = work_time;
    }
    // ��������� ���������� ������� �����
    unsigned int get_work_time()
    {
        return this->work_time;
    }
};

