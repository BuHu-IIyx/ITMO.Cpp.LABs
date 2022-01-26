#include "Header.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <tuple>
#include <vector>
using std::endl;
using std::cout;
using std::cin;
using std::string;

namespace Lab7
{
	//
	// Упражнение 1-2
	//
	struct Distance
	{
		int feet;
		double inches;

		void ShowDist()
		{
			cout << this->feet << "\'- " << this->inches << "\"\n";
		}
	};
	Distance AddDist(const Distance&, const Distance&);
	Distance InputDist();

	int ex1_2()
	{
		Distance d1 = InputDist();
		Distance d2 = { 1, 6.25 };
		Distance d3 = AddDist(d1, d2);
		d1.ShowDist();
		d2.ShowDist();
		d3.ShowDist();
		return 0;
	}
	Distance AddDist(const Distance& d1, const Distance& d2)
	{
		Distance d;
		d.feet = d1.feet + d2.feet;
		d.inches = d1.inches + d2.inches;
		if (d.inches >= 12.0)
		{
			d.inches -= 12.0;
			d.feet++;
		}
		return d;
	}
	Distance InputDist()
	{
		Distance d;
		cout << "\nВведите число футов: ";
		cin >> d.feet;
		cout << "Введите число дюймов: ";
		cin >> d.inches;
		return d;
	}
	//
	// Упражнение 3
	//
	int ex3()
	{
		int n;
		cout << "Введите размер массива расстояний ";
		cin >> n;
		Distance* masDist = new Distance[n];
		for (int i = 0; i < n; i++)
		{
			masDist[i] = InputDist();
		}
		for (int i = 0; i < n; i++)
		{
			masDist[i].ShowDist();
		}
		Distance sum{ 0, 0 };
		for (int i = 0; i < n; i++)
		{
			sum = AddDist(sum, masDist[i]);
		}
		cout << "Сумма равна = ";
		sum.ShowDist();
		delete[] masDist;
		return 0;
	}
	//
	// Упражнение 4-5
	//
	using Tuple = std::tuple<string, int, double>;
	void printTupleOfThree(std::tuple<string, int, double>);
	Tuple funtup(string, int, double);

	int ex4_5()
	{
		std::vector<string> v1{ "one", "two", "three", "four", "five", "six" };
		std::vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
		std::vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
		auto t0 = make_tuple(v1[0], v2[0], v3[0]);
		printTupleOfThree(t0);
		auto t1 = funtup(v1[1], v2[1], v3[1]);
		printTupleOfThree(t1);
		return 0;
	}

	void printTupleOfThree(std::tuple<string, int, double> t)
	{
		cout << "("
			<< std::get<0>(t) << ", "
			<< std::get<1>(t) << ", "
			<< std::get<2>(t) << ")" << endl;
	}
	Tuple funtup(string s, int a, double d)
	{
		s.append("!");
		return make_tuple(s, a, d * 10);
	}
	//
	// Контрольное задание 1
	//
	struct OldTime
	{
		int hours;
		int minutes;
		int seconds;
		string getTime()
		{
			return std::to_string(this->hours) + "ч. " + std::to_string(this->minutes)
				+ "мин. " + std::to_string(this->seconds) + "сек.";
		}
		OldTime& addTime(OldTime& time)
		{
			OldTime resTime
			{
				this->hours + time.hours,
				this->minutes + time.minutes,
				this->seconds + time.seconds
			};
			if (resTime.seconds > 60)
			{
				resTime.minutes += resTime.seconds / 60;
				resTime.seconds = resTime.seconds % 60;
			}
			if (resTime.minutes > 60)
			{
				resTime.hours += resTime.minutes / 60;
				resTime.minutes = resTime.minutes % 60;
			}
			return resTime;
		}
		OldTime& subTime(OldTime& time)
		{
			OldTime resTime
			{
				this->hours - time.hours,
				this->minutes - time.minutes,
				this->seconds - time.seconds
			};
			if (resTime.seconds < 0)
			{
				resTime.minutes -= 1;
				resTime.seconds += 60;
			}
			if (resTime.minutes < 0)
			{
				resTime.hours -= 1;
				resTime.minutes += 60;
			}
			return resTime;
		}
	};

	int controlEx1()
	{
		OldTime time1{ 4, 20, 55 };
		OldTime time2{ 2, 55, 32 };
		OldTime aTime = time1.addTime(time2);
		OldTime sTime = time1.subTime(time2);
		cout << aTime.getTime();
		cout << sTime.getTime();
		return 0;
	}
	//
	// Контрольное задание 2
	//	
	struct resSqExpreshion
	{
		double x1, x2;
		string getRes()
		{
			return "x1 = " + std::to_string(this->x1) + "\nx2 = " + std::to_string(this->x2);
		}
	};
	struct sourceData { double a, b, c; };
	sourceData getSourceData();
	resSqExpreshion Myroot(double, double, double);

	int controlEx2()
	{
		sourceData returnData = getSourceData();
		resSqExpreshion result;
		result = Myroot(returnData.a, returnData.b, returnData.c);
		if (result.x1 == NULL)
		{
			cout << "У данного уравнения корней нет.";
		}
		else
		{
			cout << result.getRes();
		}
		return 0;
	}
	sourceData getSourceData()
	{
		double a, b, c;
		std::cout << "Введите коэффиценты a, b, c для квадратного уравнения ax2+bx+c=0" << std::endl;
		std::cout << "a = ";
		std::cin >> a;
		std::cout << "b = ";
		std::cin >> b;
		std::cout << "c = ";
		std::cin >> c;
		sourceData returnData{ a, b, c };
		return returnData;
	}
	resSqExpreshion Myroot(double a, double b, double c)
	{
		resSqExpreshion result;
		double D = b * b - 4 * a * c;
		if (D > 0)
		{
			result.x1 = ((-1) * b + sqrt(D)) / (2 * a);
			result.x2 = ((-1) * b - sqrt(D)) / (2 * a);
		}
		else if (D == 0)
		{
			result.x1 = (-1) * b / (2 * a);
			result.x2 = result.x1;
		}
		else
		{
			result.x1 = NULL;
			result.x2 = result.x1;
		}
		return result;
	}
	//
	// Контрольное задание 3
	//
	using resultTuple = std::tuple<double, double, int>;
	resultTuple Myroot1(double, double, double);
	string getResultTuple(resultTuple&);

	int controlEx3()
	{
		sourceData returnData = getSourceData();
		resultTuple result;
		result = Myroot1(returnData.a, returnData.b, returnData.c);
		cout << getResultTuple(result);
		return 0;
	}
	resultTuple Myroot1(double a, double b, double c)
	{
		double x1, x2;
		int d;
		double D = b * b - 4 * a * c;
		if (D > 0)
		{
			x1 = ((-1) * b + sqrt(D)) / (2 * a);
			x2 = ((-1) * b - sqrt(D)) / (2 * a);
			d = 1;
		}
		else if (D == 0)
		{
			x1 = (-1) * b / (2 * a);
			x2 = x1;
			d = 0;
		}
		else
		{
			x1 = NULL;
			x2 = x1;
			d = -1;
		}
		return std::make_tuple(x1, x2, d);
	}
	string getResultTuple(resultTuple& tup)
	{
		string result;
		if (std::get<2>(tup) < 0)
		{
			result = "У данного уравнения корней нет.";
		}
		else if (std::get<2>(tup) == 0)
		{
			result = "x1 = x2 = " + std::to_string(std::get<0>(tup));
		}
		else
		{
			result = "x1 = " + std::to_string(std::get<0>(tup)) + "\nx2 = " + std::to_string(std::get<1>(tup));
		}
		return result;
	}
}