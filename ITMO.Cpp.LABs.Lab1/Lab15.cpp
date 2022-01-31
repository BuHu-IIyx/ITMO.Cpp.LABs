#include <iostream>
#include <string>
#include <map>
#include "Header.h"
using std::endl;
using std::cout;
using std::cin;
using std::string;

namespace Lab15
{
	//
	// ����������� ������� 1
	//
	
	int controlEx1()
	{
		std::map <string, char> StudentGrade;
		std::map <string, char>::iterator studentIter;
		typedef std::pair <string, char> sPair;

		while (true)
		{
			string name;
			char grade, flag;
			cout << "������� ��� ��������: ";
			cin >> name;
			cout << "������� ������ �������� " << name << ": ";
			cin >> grade;
			StudentGrade.insert(sPair(name, grade));
			cout << "������ ��� ���� ������ (y,n)?";
			cin >> flag;
			if (flag == 'y' || flag == 'Y' || flag == '�' || flag == '�')
				continue;
			else
			{
				break;
			}
		}
		for (auto i:StudentGrade)
		{
			cout << i.first << ": " << i.second << endl;
		}
		return 0;
	}
}