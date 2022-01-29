#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "Time.h"

using std::endl;
using std::cout;
using std::cin;
using std::string;

namespace Lab11
{
	//
	// Упражнение 1
	//	
	class Distance
	{
	private:
		int feet;
		float inches;
		const float MTF;
	public:
		// конструктор по умолчанию
		Distance() : feet(0), inches(0.0), MTF(3.280833F) { }
		// конструктор с одним параметром
		Distance(float meters) : MTF(3.280833F)
		{
			float fltfeet = MTF * meters; // перевод в футы
			feet = int(fltfeet); // число полных футов
			inches = 12 * (fltfeet - feet); // остаток - это дюймы
		}
		// конструктор с двумя параметрами
		Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F) { }
		
		void getdist()
		{
			cout << "\nВведите число футов : ";
			cin >> feet;
			cout << "\nВведите число дюймов : ";
			cin >> inches;
		}
		void showdist()
		{
			cout << feet << "\' - " << inches << "\"\n";
		}
		Distance operator+ (const Distance&) const;
		Distance operator- (const Distance&) const;
		operator float() const
		{
			float fracfeet = inches / 12;
			fracfeet += static_cast<float>(feet);
			return fracfeet / MTF;
		};
		friend std::ostream& operator<< (std::ostream& out, const Distance& dist);
	};

	Distance Distance::operator+ (const Distance& d2) const
	{
		int f = feet + d2.feet;
		float i = inches + d2.inches;
		while (i >= 12.0)
		{
			i -= 12.0;
			f++;
		} 
		return Distance(f, i);
	}
	Distance Distance::operator- (const Distance& d2) const
	{
		int f = feet - d2.feet;
		float i = inches - d2.inches;
		while (i < 0.)
		{
			i += 12.0;
			f--;
		}
		if (f < 0. || i < 0.)
		{
			return Distance(0, 0.);
		}
		return Distance(f, i);
	}
	std::ostream& operator<< (std::ostream& out, const Distance& dist)
	{
		out << dist.feet << "\' - " << dist.inches << "\"\n";
		return out;
	}


	int ex1()
	{
		Distance dist1, dist2, dist3, dist4;
		dist1.getdist();
		dist2.getdist();/*
		dist3 = dist1 + dist2;
		dist4 = dist1 - dist2;*/
		cout << "\ndist1 = " << dist1;
		cout << "\ndist2 = " << dist2;
		cout << "\ndist3 = " << dist3;
		cout << "\ndist4 = " << dist4;
		return 0;
	}
	//
	// Упражнение 1
	//	
	struct StudentGrade
	{
		string name;
		char grade;
	};
	class GradeMap
	{
	private:
		std::vector<StudentGrade> m_map;
	public:
		GradeMap()
		{ }
		char& operator[](const string& name);
	};
	char& GradeMap::operator[](const string& name)
	{
		// Найдём ли мы имя ученика в векторе
		for (auto& ref : m_map)
		{
			// Если нашли, то возвращаем ссылку на его оценку
			if (ref.name == name)
				return ref.grade;
		}
		// Не нашли - создаём новый StudentGrade для нового ученика
		StudentGrade temp{ name, ' ' };
		// Помещаем его в конец вектора
		m_map.push_back(temp);
		// И возвращаем ссылку на его оценку
		return m_map.back().grade;
	}
	int ex4()
	{
		GradeMap grades;
		grades["John"] = 'A';
		grades["Martin"] = 'B';
		cout << "John has a grade of " << grades["John"] << endl;
		cout << "Martin has a grade of " << grades["Martin"] << endl;
		cout << "New name and grade?" << endl;
		string name;
		char grade;
		cin >> name >> grade;
		grades[name] = grade;
		std::cout << name << " has a grade of " << grades[name] << endl;
		return 0;
	}
	//
	// Контрольное задание 1
	//
	int controlEx1()
	{
		Time time1{ 4, 20, 55 };
		Time time2{ 2.12 };
		Time time3{ 2.12 };
		Time aTime = time1 + time2;
		double timeH = time2 + 0.5;
		cout << timeH << endl;
		double timeH1 = 2.5 + time2;
		cout << timeH1 << endl;
		cout << time1.getTime() << endl;
		cout << time2.getTime() << endl;
		cout << aTime.getTime() << endl;
		cout << (time1 > time2) << endl;
		cout << (time1 < time2) << endl;
		cout << (time1 == time2) << endl;
		cout << (time2 == time3) << endl;
		return 0;
	}
	//
	// Контрольное задание 2
	//
	class Point
	{
	private:
		double x;
		double y;
	public:
		Point(double x, double y)
		{
			this->x = x;
			this->y = y;
		}
		double distToZero()
		{
			return sqrt(x * x + y * y);
		}			
		bool operator< (Point& p2)
		{
			if (distToZero() < p2.distToZero())
				return true;
			else
				return false;
		}
		string getPoint()
		{
			return "{ " + std::to_string(x) + ", " + std::to_string(y) + " }";
		}
		friend std::ostream& operator<< (std::ostream&, Point&);		
	};
	std::ostream& operator<< (std::ostream& out, Point& p)
	{
		out << "{ " << p.x << ", " << p.y << " }";
		return out;
	}
	int controlEx2()
	{
		std::vector<Point> v;
		v.push_back(Point(1, 2));
		v.push_back(Point(10, 12));
		v.push_back(Point(21, 7));
		v.push_back(Point(4, 8));
		std::sort(v.begin(), v.end()); // требуется перегрузка оператора < для
		// класса Point
		for (auto& point : v)
			cout << point.distToZero() << point << '\n'; // требуется перегрузка оператора << для 
			// класса Point
		return 0;
	}
}