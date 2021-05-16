#pragma once
#include <string>

struct Date
{
public:
	unsigned year = 0;
	unsigned month = 1;
	unsigned day = 1;
	unsigned hour = 0;
	unsigned minutes = 0;


	Date();
	Date(unsigned _year, unsigned _month, unsigned _day, unsigned _hour, unsigned _minutes);
	Date(unsigned _day, unsigned _month, unsigned _year);

	std::string getDateString();
	void operator ()(unsigned _year, unsigned _month, unsigned _day, unsigned _hour, unsigned _minutes);
	void operator ()(unsigned _year, unsigned _month, unsigned _day);
	void operator =(const Date& other);
	bool operator >(const Date& right);
	bool operator <(const Date& right);
	bool operator >=(const Date& right);
	bool operator <=(const Date& right);
	bool operator ==(const Date& right);
};
