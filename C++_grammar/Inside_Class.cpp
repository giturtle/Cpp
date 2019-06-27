#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


class Date {
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	ostream& operator<<(ostream& _cout) {
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}

private:
	int _year;
	int _month;
	int _day;
};
int main(){
	Date d(2017, 12, 24);
	d << cout;
	return 0;
}






class Date{
	friend ostream& operator<<(ostream& _cout, const Date& d);	//声明友元函数
	friend istream& operator>>(istream& _cin, const Date& d);
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

private:
	int _year;
	int _month;
	int _day;
};

// 重载operator<<
ostream& operator<<(ostream& _cout, const Date& d){
	_cout << d._year << "-" << d._month << "-" << d._day;

	return _cout;
}

// 重载operator>>
istream& operator>>(istream& _cin, const Date& d){
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;

	return _cin;
}
int main(){
	Date d(2017, 12, 24);
	cin >> d;
	cout << d << endl;
	return 0;
}




class Date; // 前置声明
class Time{
	friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
public:
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	void SetTimeOfDate(int hour, int minute, int second){
		// 直接访问时间类私有的成员变量
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};




//内部类
class A{
private:
	static int k;
	int h;
public:
	class B{
	public:
		void foo(const A& a){
			cout << k << endl;			//合法
			cout << a.h << endl;		//合法
		}
	};
};

int A::k = 1;

int main(){
	A::B b;
	b.foo(A());		//A类的匿名对象

	return 0;
}

