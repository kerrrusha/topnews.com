#include "Date.h"
#include <tuple>
#include <stdexcept>
#include <string>
using namespace std;

Date::Date()
{
	day = 1;
	month = 1;
	year = 0;
	hour = 0;
	minutes = 0;
}
Date::Date(unsigned _year, unsigned _month, unsigned _day, unsigned _hour, unsigned _minutes)
{
	try
	{
		if (_day < 1 || _day > 31 || _month < 1 || _month > 12 || _hour > 24 || _hour < 0 || _minutes > 60 || _minutes < 0)
			throw invalid_argument("Incorrect date format");
		day = _day;
		month = _month;
		year = _year;
		hour = _hour;
		minutes = _minutes;
	}
	catch (invalid_argument e)
	{
		day = 1;
		month = 1;
		year = 0;
		hour = 0;
		minutes = 0;
	}
}
Date::Date(unsigned _day, unsigned _month, unsigned _year)
{
	try
	{
		if (_day < 1 || _day > 31 || _month < 1 || _month > 12)
			throw invalid_argument("Incorrect date format");
		day = _day;
		month = _month;
		year = _year;
		hour = 0;
		minutes = 0;
	}
	catch (invalid_argument e)
	{
		day = 1;
		month = 1;
		year = 0;
		hour = 0;
		minutes = 0;
	}
}

string Date::getDateString()
{
	string result = "";

	if (day < 10)
		result += ("0" + to_string(day) + ".");
	else
		result += (to_string(day) + ".");

	if (month < 10)
		result += ("0" + to_string(month) + ".");
	else
		result += (to_string(month) + ".");

	result += (to_string(year) + " ");

	if (hour < 10)
		result += ("0" + to_string(hour) + ":");
	else
		result += (to_string(hour) + ":");

	if (minutes < 10)
		result += ("0" + to_string(minutes));
	else
		result += to_string(minutes);

	return result;
}
void Date::operator ()(unsigned _year, unsigned _month, unsigned _day, unsigned _hour = 0, unsigned _minutes = 0)
{
	if (_day < 1 || _day > 31 || _month < 1 || _month > 12 || _hour > 24 || _hour < 0 || _minutes > 60 || _minutes < 0)
		return;

	day = _day;
	month = _month;
	year = _year;
	hour = _hour;
	minutes = _minutes;
}
void Date::operator ()(unsigned _day, unsigned _month, unsigned _year)
{
	if (_day < 1 || _day > 31 || _month < 1 || _month > 12)
		return;

	day = _day;
	month = _month;
	year = _year;
}
void Date::operator =(const Date& other)
{
	try
	{
		if (other.day < 1 || other.day > 31 || other.month < 1 || other.month > 12 || other.hour > 24 || other.hour < 0 || other.minutes > 60 || other.minutes < 0)
			throw invalid_argument("Incorrect date format");
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
		this->hour = other.hour;
		this->minutes = other.minutes;
	}
	catch (invalid_argument e)
	{}
}
bool Date::operator >(const Date& right)
{
	return tie(this->year, this->month, this->day, this->hour, this->minutes) > tie(right.year, right.month, right.day, right.hour, right.minutes);
}
bool Date::operator <(const Date& right)
{
	return tie(this->year, this->month, this->day, this->hour, this->minutes) < tie(right.year, right.month, right.day, right.hour, right.minutes);
}
bool Date::operator >=(const Date& right)
{
	return tie(this->year, this->month, this->day, this->hour, this->minutes) >= tie(right.year, right.month, right.day, right.hour, right.minutes);
}
bool Date::operator <=(const Date& right)
{
	return tie(this->year, this->month, this->day, this->hour, this->minutes) <= tie(right.year, right.month, right.day, right.hour, right.minutes);
}
bool Date::operator ==(const Date& right)
{
	return tie(this->year, this->month, this->day, this->hour, this->minutes) == tie(right.year, right.month, right.day, right.hour, right.minutes);
}
