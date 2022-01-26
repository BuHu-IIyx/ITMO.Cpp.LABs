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
Time::Time(int hours, int minutes, int seconds)
{
	Time::hours = hours;
	Time::minutes = minutes;
	Time::seconds = seconds;
	if (Time::seconds > 60)
	{
		Time::minutes += 1;
		Time::seconds -= 60;
	}
	if (Time::minutes > 60)
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
Time& Time::addTime(Time& time)
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
Time& Time::addTime(Time& time1, Time& time2)
{
	Time resTime(
		time1.hours + time2.hours,
		time1.minutes + time2.minutes,
		time1.seconds + time2.seconds);
	return resTime;
}
Time& Time::subTime(Time& time)
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