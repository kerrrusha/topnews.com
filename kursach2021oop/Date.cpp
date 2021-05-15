#include "Date.h"
#include <tuple>
#include <stdexcept>
using namespace std;

Date::Date()
{
	day = 1;
	month = 1;
	year = 0;
}
Date::Date(int _day, int _month, int _year)
{
	try
	{
		if (_day < 1 || _day > 31 || _month < 1 || _month > 12)
			throw invalid_argument("Incorrect date format");
		day = _day;
		month = _month;
		year = _year;
	}
	catch (invalid_argument e)
	{
		day = 1;
		month = 1;
		year = 0;
	}
}

void Date::operator ()(int _day, int _month, int _year)
{
	day = _day;
	month = _month;
	year = _year;
}
void Date::operator =(const Date& other)
{
	try
	{
		if (other.day < 1 || other.day > 31 || other.month < 1 || other.month > 12)
			throw invalid_argument("Incorrect date format");
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
	}
	catch (invalid_argument e)
	{

	}
}
bool Date::operator >(const Date& right)
{
	return tie(this->year, this->month, this->day) > tie(right.year, right.month, right.day);
}
bool Date::operator <(const Date& right)
{
	return tie(this->year, this->month, this->day) < tie(right.year, right.month, right.day);
}
bool Date::operator >=(const Date& right)
{
	return tie(this->year, this->month, this->day) >= tie(right.year, right.month, right.day);
}
bool Date::operator <=(const Date& right)
{
	return tie(this->year, this->month, this->day) <= tie(right.year, right.month, right.day);
}
bool Date::operator ==(const Date& right)
{
	return tie(this->year, this->month, this->day) == tie(right.year, right.month, right.day);
}