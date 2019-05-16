#include "Date.h"

//bool Date::operator>(const Date& d) const
//bool Date::operator>=(const Date& d) const
//bool Date::operator<(const Date& d) const
//bool Date::operator<=(const Date& d) const
//bool Date::operator==(const Date& d) const
//bool Date::operator!=(const Date& d) const


//声明和定义分离要注意：类域Date::operator....
// ++d
Date& Date::operator++()	// 前置++，前置不会创建对象
{
	*this += 1;
	return *this;
}

// d++
Date Date::operator++(int) // 后置++，对值不处理，拷贝构造1个返回1个
{
	Date ret(*this);	//保存++之前的值，拷贝构造
	*this += 1;
	return ret;
}
//带参数是为了区分，构成函数重载
//
//Date Date::operator--();		// 前置--
//Date Date::operator--(int);	// 后置--

Date Date::operator+(int day) const
{
	Date ret = *this;
	ret += day;	//ret调用+=可以，this不可以
	//+= 代码复用
	return ret;
}


//Date Date::operator-(int day) const;


//最简单的 +=，效率低，因为创建了对象1. 代码中 2. 返回时 总共多创建了2个对象
/*
Date& Date::operator+=(int day){
	*this = *this + day;
	return *this;
}	
*/
	
Date& Date::operator+=(int day){	//没有创建对象
	if (day < 0)
		return *this -= -day;	//复用 -= 操作符

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}

	return *this;
}


//Date& Date::operator-=(int day);

//int Date::operator-(const Date&d);
