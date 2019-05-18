#include "Date.h"

int Date::operator-(const Date&d) const
{
	Date maxdate(*this);
	Date mindate(d);
	int flag = 1;
	if (*this < d)
	{
		maxdate = d;
		mindate = *this;
		flag = -1;
	}

	int days = 0;
	while (mindate != maxdate)
	{
		mindate += 1;
		++days;
	}

	return days * flag;
}

// ++d
Date& Date::operator++()	// 前置++
{
	*this += 1;
	return *this;
}

// d++
Date Date::operator++(int) // 后置++
{
	Date ret(*this);
	*this += 1;
	return ret;
}

//
Date& Date::operator--()		// 前置--
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int) // 后置--
{
	Date tmp(*this);
	*this -= 1;

	return tmp;
}

Date Date::operator+(int day) const
{
	Date ret = *this;
	ret += day;
	return ret;
}

Date& Date::operator+=(int day)
{
	if (day < 0)
		return *this -= -day;

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

Date& Date::operator-=(int days)
{
	if (days < 0)
	{
		return *this += -days;
	}

	_day -= days;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_month = 12;
			--_year;
		}
		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

Date Date::operator-(int day) const
{
	Date ret(*this);
	ret -= day;

	return ret;
}

bool Date::operator>(const Date& d) const
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}

	return false;
}

bool Date::operator>=(const Date& d) const
{
	return *this > d || *this == d;
}

bool Date::operator<(const Date& d) const
{
	return !(*this >= d);
}

bool Date::operator<=(const Date& d) const
{
	return !(*this > d);
}

bool Date::operator==(const Date& d) const
{
	return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}
