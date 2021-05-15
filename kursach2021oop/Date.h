#pragma once

struct Date
{
public:
	int day;
	int month;
	int year;

	Date();
	Date(int _day, int _month, int _year);

	void operator ()(int _day, int _month, int _year);
	void operator =(const Date& other);
	bool operator >(const Date& right);
	bool operator <(const Date& right);
	bool operator >=(const Date& right);
	bool operator <=(const Date& right);
	bool operator ==(const Date& right);
};