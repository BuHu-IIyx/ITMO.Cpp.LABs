#include <iostream>
#include <vector>
#include "Human.h"
#include "StudentN.h"
#include "Teacher.h"

namespace Lab12
{
	//
	// Упражнение 1
	//	
	int ex1()
	{
		//// Оценки студента
		//std::vector<int> scores;
		//// Добавление оценок студента в вектор
		//scores.push_back(5);
		//scores.push_back(3);
		//scores.push_back(4);
		//scores.push_back(4);
		//scores.push_back(5);
		//scores.push_back(3);
		//scores.push_back(3);
		//scores.push_back(3);
		//scores.push_back(3);
		//StudentN* stud = new StudentN("Петров", "Иван", "Алексеевич", scores);

		//std::cout << stud->get_full_name() << std::endl;
		//std::cout << "Средний балл : " << stud->get_average_score() << std::endl;

		unsigned int teacher_work_time = 40;
		Teacher* tch = 
			new Teacher("Сергеев", "Дмитрий", "Сергеевич", teacher_work_time);

		std::cout << tch->get_full_name() << std::endl;
		std::cout << "Количество часов: " << tch->get_work_time() << std::endl;

		return 0;
	}
}