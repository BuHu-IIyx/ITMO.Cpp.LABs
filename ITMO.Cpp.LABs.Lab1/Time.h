#pragma once
#include <string>
using std::string;

class Time
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	Time();
	Time(int, int, int);	
	string getTime();
	Time addTime(Time&);
	Time subTime(Time&);
	Time addTime(Time& time1, Time& time2);
	class ExInit
	{
	public:
		string message = "Время, не может быть отрицательным.";
		ExInit() {};
	};
	/*int convertToSec();
	Time& secToTime(int)*/
};

