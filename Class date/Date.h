#pragma once

#include <iostream>
#include <assert.h>
using std::cout;
using std::endl;

class Date
{
public:
	inline int GetMonthDay(int year, int month) const
	{
		static int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((month == 2) 
			&& ((year % 4 == 0 && year % 100 != 0)|| (year % 400 == 0)))
		{
			return 29;
		}

		return monthArray[month];
	}

	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year >= 1900
			&& month > 0 && month < 13
			&& day > 0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			//assert(false);
			cout << "非法日期" << endl;
		}
	}

	// d2(d1)
	//Date(const Date& d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}

	//Date& Date::operator=(const Date& d)
	//{
	//	_year = d._year;              // this->_year = d._year;
	//	_month = d._month;
	//	_day = d._day;

	//	return *this;
	//}

	// 作业中：实现一下拷贝赋值 + 析构  熟悉他们的用法

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	Date& operator++();		// 前置++
	Date operator++(int);	// 后置++

	Date& operator--();		// 前置--
	Date operator--(int);	// 后置--

	Date operator+(int day) const;
	Date operator-(int day) const;

	Date& operator+=(int day); // 不写
	Date& operator-=(int day);

	int operator-(const Date&d) const;
private:
	int _year;
	int _month;
	int _day;
};
