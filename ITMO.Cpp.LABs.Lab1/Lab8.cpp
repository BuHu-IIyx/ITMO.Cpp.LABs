#include <iostream>
#include <string>
#include "student.h"
#include "Time.h"
using std::endl;
using std::cout;
using std::cin;
using std::string;


namespace Lab8
{
	//
	// ���������� 1
	//	
	int ex1()
	{
		// �������� ������� ������ Student
		
		string name;
		string last_name;
		int scores[5];
		// ���� ����� � ����������
		cout << "Name: ";
		getline(cin, name);
		// ���� �������
		cout << "Last name: ";
		getline(cin, last_name);
		// ����� ���� ������
		int sum = 0;
		// ���� ������������� ������
		for (int i = 0; i < 5; ++i) {
			cout << "Score " << i + 1 << ": ";
			cin >> scores[i];
			// ������������
			sum += scores[i];
		}
		Student* student02 = new Student(name, last_name);
		// ���������� ������������� ������ � ������ ������ Student
		student02->set_scores(scores);
		// ������� ������� ����
		double average_score = sum / 5.0;
		// ���������� �������� ����� � ������ ������ Student
		student02->set_average_score(average_score);

		cout << "Average ball for " << student02->get_name() << " "
			<< student02->get_last_name() << " is "
			<< student02->get_average_score() << endl;
		delete student02;
		return 0;
	}
	//
	// ����������� ������� 1
	//
	int controlEx1()
	{
		Time time1{ 4, 20, 55 };
		Time time2{ 2, 55, 32 };
		Time aTime = aTime.addTime(time1, time2);
		cout << aTime.getTime();
		return 0;
	}
}