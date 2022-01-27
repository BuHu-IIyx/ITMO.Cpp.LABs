#include "IdCard.h"
#include "Student.h"
#include <iostream>
#include <string>
using std::endl;
using std::cout;
using std::cin;
using std::string;

namespace Lab10
{
	//
	// ���������� 1
	//	
	int ex1()
	{
		IdCard idc(123, "�������");
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
		Student* student02 = new Student(name, last_name, &idc);
		try
		{
			// ���������� ������������� ������ � ������ ������ Student
			student02->set_scores(scores);
		}
		catch (Student::ExScore& ex)
		{
			cout << "\n������ ������������� " << ex.origin;
			cout << "\n��������� �������� ������ " << ex.iValue <<
				" �������� ������������" << endl;
		}
		// ������� ������� ����
		double average_score = sum / 5.0;
		// ���������� �������� ����� � ������ ������ Student
		student02->set_average_score(average_score);

		cout << "Average ball for " << student02->get_name() << " "
			<< student02->get_last_name() << " is "
			<< student02->get_average_score() << endl;
		cout << "IdCard: " << student02->getIdCard().getNumber() << endl;
		cout << "Category: " << student02->getIdCard().getCategory() << endl;
		delete student02;
		return 0;
	}
	//
	// ����������� ������� 1
	//
	int controlEx1()
	{

	}
}