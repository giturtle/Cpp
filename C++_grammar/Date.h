#pragma once

#include <iostream>
#include <assert.h>
using std::cout;
using std::endl;

class Date
{
public:
	//函数常用，变成内联
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

	Date(int year, int month, int day)
	{
		if (year >= 1900
			&& month > 0 && month < 13
			&& day > 0 && day <= GetMonthDay(year, month)
		){
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

	// 作业中：实现一下拷贝赋值 + 析构  熟悉他们的用法，这里是不需要写的

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}


	//日期类的运算符重载
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	Date& operator++();		// 前置++
	Date operator++(int);	// 后置++
	//函数重载是为了相同函数名可以在一起使用
	//运算符重载是为了自定义类型可以向内置类型一样使用运算符，上面情况：运算符重载可以构成了函数重载
	
	Date operator--();		// 前置--
	Date operator--(int);	// 后置--

	Date operator+(int day) const;
	Date operator-(int day) const;

	Date& operator+=(int day);
	Date& operator-=(int day);

	int operator-(const Date&d);
private:
	int _year;
	int _month;
	int _day;
};
