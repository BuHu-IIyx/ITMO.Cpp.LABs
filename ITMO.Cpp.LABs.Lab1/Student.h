#pragma once
#include <string>
#include "IdCard.h"
using std::string;
class Student
{
public:
	// ����������� ������ Student
	Student(string, string);
	// ����������� ������ Student LAB 10
	Student(string, string, IdCard*);
	// ��������� ����� ��������
	void set_name(string);
	// ��������� ����� ��������
	string get_name();
	// ��������� ������� ��������
	void set_last_name(string);
	// ��������� ������� ��������
	string get_last_name();
	// ��������� ������������� ������
	void set_scores(int[]);
	// ��������� �������� �����
	void set_average_score(double);
	// ��������� �������� �����
	double get_average_score();
	// ��������� ID card
	void setIdCard(IdCard* c);
	// ��������� ID card
	IdCard getIdCard();
	// ������ ������ � �������� � ����
	void save();
	// ���������� ������ Student
	~Student();
	class ExScore
	{
	public:
		string origin; //��� ����� �������
		int iValue; //��� �������� ���������� ��������
		ExScore(string, int);
	};
private:
	// ������������� ������
	int scores[5];
	// ������� ����
	double average_score;
	// ���
	string name;
	// �������
	string last_name;
	// Id card
	IdCard* iCard;
};

