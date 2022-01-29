#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include "Header.h"
#include "StudentN.h"
#include "Teacher.h"
using std::endl;
using std::cout;
using std::cin;
using std::string;

namespace Lab13
{
	//
	// ���������� 1
	//	
	class Item
	{
	private:
		string title;
		double price;
	public:
		virtual void getdata()
		{
			cout << "\n������� ��������� : ";
			cin >> title;
			cout << "������� ���� : ";
			cin >> price;
		}
		virtual void putdata()
		{
			cout << "\n���������: " << title;
			cout << "\n����:" << price;
		}
	};
	class Paperbook : public Item
	{
	private:
		int pages;
	public:
		void getdata()
		{
			Item::getdata();
			cout << "������� ����� ������� : ";
			cin >> pages;
		}
		void putdata()
		{
			Item::putdata();
			cout << "\n�������: " << pages;
		}
	};
	class AudioBook : public Item
	{
	private:
		double time;
	public:
		void getdata()
		{
			Item::getdata();
			cout << "������� ����� �������� : ";
			cin >> time;
		}
		void putdata()
		{
			Item::putdata();
			cout << "\n����� �������� : " << time;
		}
	};
	int ex1()
	{
		Item* pubArr[100];
		int n = 0;
		char choice;
		do
		{
			cout << "\n������� ������ ��� ����� ��� ��������� �����(b / a) ? ";
			cin >> choice;
			if (choice == 'b')
				pubArr[n] = new Paperbook;
			else
				pubArr[n] = new AudioBook;
			pubArr[n++]->getdata();
			cout << "����������((� / n) ? ";
			cin >> choice;
		} while (choice == 'y');
		for (int j = 0; j < n; j++) //���� �� ���� ��������
			pubArr[j]->putdata(); //������� ������ � ����������
		cout << endl;
		return 0;
	}
	//
	// ����������� ������� 1
	//
	int controlEx1()
	{
		std::vector<Human*> humanVector;

	// ������ �� ���������
		std::vector<int> scores;
		scores.push_back(5);
		scores.push_back(3);
		scores.push_back(4);
		scores.push_back(4);
		scores.push_back(5);
		scores.push_back(3);
		scores.push_back(3);
		scores.push_back(3);
		scores.push_back(3);
		humanVector.push_back(new StudentN("������", "����", "����������", scores));
		unsigned int teacher_work_time = 40;
		humanVector.push_back(new Teacher("�������", "�������", "���������", teacher_work_time));
	// ���������������� ����
		char flag;
		do
		{
			cout << "������ �������� ��� �������������? (s, t)";
			cin >> flag;
			if (flag == 's' || flag == 'S' || flag == '�' || flag == '�')
				humanVector.push_back(new StudentN);
			else
				humanVector.push_back(new Teacher);
			cout << "���������� (� / n) ? ";
			cin >> flag;
		} while (flag == 'y' || flag == 'Y' || flag == '�' || flag == '�');
		cout << "\n\n\n\n";
		// ����� ����������
		for (auto* human : humanVector)
			human->printData();
		return 0;
	}

}
