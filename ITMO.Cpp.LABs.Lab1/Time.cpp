#include "Time.h"
#include <string>
#include <iostream>
#include <fstream>

using std::endl;
using std::cout;
using std::cin;
using std::string;
Time::Time()
{
	Time::hours = 0;
	Time::minutes = 0;
	Time::seconds = 0;
}
Time::Time(double h)
{
	Time::hours = (int)h;
	double tempMin = (h - hours) * 60;
	Time::minutes = (int)(tempMin);
	Time::seconds = (int)((tempMin-minutes) * 60);
}
Time::Time(int hours, int minutes, int seconds)
{
	if (hours < 0 || minutes < 0 || seconds < 0)
	{
		throw ExInit();
	}
	Time::hours = hours;
	Time::minutes = minutes;
	Time::seconds = seconds;
	while (Time::seconds > 60)
	{
		Time::minutes += 1;
		Time::seconds -= 60;
	}
	while (Time::minutes > 60)
	{
		Time::hours += 1;
		Time::minutes -= 60;
	}
}
string Time::getTime()
{	
	return std::to_string(Time::hours) + ":" + std::to_string(Time::minutes)
		+ ":" + std::to_string(Time::seconds);
}
double Time::getHours() const
{
	return Time::hours + Time::minutes / 60. + Time::seconds / 3600.;
}
Time Time::addTime(const Time& time) const
{
	Time resTime (
		Time::hours + time.hours,
		Time::minutes + time.minutes,
		Time::seconds + time.seconds );

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
Time Time::addTime(Time& time1, Time& time2)
{
	Time resTime(
		time1.hours + time2.hours,
		time1.minutes + time2.minutes,
		time1.seconds + time2.seconds);
	return resTime;
}
Time Time::subTime(const Time& time) const
{
	Time resTime(
		Time::hours + time.hours,
		Time::minutes + time.minutes,
		Time::seconds + time.seconds);

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
Time::ExInit::ExInit() { Time::ExInit::message = "Время, не может быть отрицательным."; };

Time Time::operator+(const Time& t2) const
{

	return Time::addTime(t2);
}

Time Time::operator+(double& d) const
{
	return Time::addTime(Time(d));
}

bool Time::operator>(const Time& t2) const
{
	if (Time::getHours() > t2.getHours())
		return true;
	else
		return false;
}
bool Time::operator<(const Time& t2) const
{
	return !Time::operator>(t2);
}
bool Time::operator==(const Time& t2) const
{
	if (Time::getHours() == t2.getHours())
		return true;
	else
		return false;
}
Time Time::operator-(const Time&) const
{
	return Time();
}
bool Time::operator!=(const Time& t2) const
{
	return !Time::operator==(t2);
}
double operator+(const double& hours, const Time& time)
{
	return hours + time.getHours();
}
double operator+(const Time& time, const double& hours)
{
	return hours + time;
}

//int Time::convertToSec()
//{
//	return Time::hours * 3600 + Time::minutes * 60 + Time::seconds;
//}
//Time& Time::secToTime(int seconds)
//{
//	int h = seconds / 3600;
//	seconds = seconds % 3600;
//	int m = seconds / 60;
//	seconds = seconds % 60;
//	int s = seconds;
//	Time resTime(h, m, s);
//	return resTime;
//}


