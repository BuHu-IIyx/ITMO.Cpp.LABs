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
	// Упражнение 1
	//	
	class Item
	{
	private:
		string title;
		double price;
	public:
		virtual void getdata()
		{
			cout << "\nВведите заголовок : ";
			cin >> title;
			cout << "Введите цену : ";
			cin >> price;
		}
		virtual void putdata()
		{
			cout << "\nЗаголовок: " << title;
			cout << "\nЦена:" << price;
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
			cout << "Введите число страниц : ";
			cin >> pages;
		}
		void putdata()
		{
			Item::putdata();
			cout << "\nСтраниц: " << pages;
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
			cout << "Введите время звучания : ";
			cin >> time;
		}
		void putdata()
		{
			Item::putdata();
			cout << "\nВремя звучания : " << time;
		}
	};
	int ex1()
	{
		Item* pubArr[100];
		int n = 0;
		char choice;
		do
		{
			cout << "\nВводить данные для книги или звукового файла(b / a) ? ";
			cin >> choice;
			if (choice == 'b')
				pubArr[n] = new Paperbook;
			else
				pubArr[n] = new AudioBook;
			pubArr[n++]->getdata();
			cout << "Продолжать((у / n) ? ";
			cin >> choice;
		} while (choice == 'y');
		for (int j = 0; j < n; j++) //цикл по всем объектам
			pubArr[j]->putdata(); //вывести данные о публикации
		cout << endl;
		return 0;
	}
	//
	// Контрольное задание 1
	//
	int controlEx1()
	{
		std::vector<Human*> humanVector;

	// Данные по умолчанию
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
		humanVector.push_back(new StudentN("Петров", "Иван", "Алексеевич", scores));
		unsigned int teacher_work_time = 40;
		humanVector.push_back(new Teacher("Сергеев", "Дмитрий", "Сергеевич", teacher_work_time));
	// Пользовательский ввод
		char flag;
		do
		{
			cout << "Внести студента или преподавателя? (s, t)";
			cin >> flag;
			if (flag == 's' || flag == 'S' || flag == 'ы' || flag == 'Ы')
				humanVector.push_back(new StudentN);
			else
				humanVector.push_back(new Teacher);
			cout << "Продолжать (у / n) ? ";
			cin >> flag;
		} while (flag == 'y' || flag == 'Y' || flag == 'н' || flag == 'Н');
		cout << "\n\n\n\n";
		// Вывод результата
		for (auto* human : humanVector)
			human->printData();
		return 0;
	}

}
