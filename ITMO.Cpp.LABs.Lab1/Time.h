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
	Time(double);
	Time(int, int, int);	
	string getTime();
	double getHours() const;
	Time addTime(const Time&) const;
	Time subTime(const Time&) const;
	Time addTime(Time& time1, Time& time2);
	Time operator+ (const Time&) const;
	Time operator+ (double&) const;
	friend double operator+ (const double&, const Time&);
	friend double operator+ (const Time&, const double&);
	Time operator- (const Time&) const;
	bool operator> (const Time&) const;
	bool operator< (const Time&) const;
	bool operator== (const Time&) const;
	bool operator!= (const Time&) const;
	
	class ExInit
	{
	public:
		string message;
		ExInit();
		~ExInit() {};
	};
};

