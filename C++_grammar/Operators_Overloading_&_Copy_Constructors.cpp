//运算符的重载
//现在全局找，再在局部找。只有自定义类型才会触发，默认类型不会，没有触发则报错
//写作成员函数是为了访问成员变量，这就牵扯到了this指针

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		cout << "Date()" << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	// d1.operator==(&d1, d2);

	//this一定是左边操作数
	bool operator==(const Date& d) // bool operator==(Date* this, const Date& d)
	//如果不加引用，会引起“无穷递归“，本质因为拷贝构造是传值，所以要加上引用。
	//如果不修改d，就要加上const修饰，提高效率
	{
		return _year == d._year	//this->_year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator<(const Date& d)
	{
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month < d._month)
			{
				return true;
			}
			else if (_month == d._month)
			{
				if (_day < d._day)
				{
					return true;
				}
			}
		}

		return false;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	~Date()
	{
		cout << "~Date()" << endl;
	}

private:
	int _year;
	int _month;
	int _day;  // 基本类型->不做处理
};

int main()
{
	Date d1(2019, 5, 12);
	Date d2(2019, 5, 13);

	d1 == d2;
	d1.operator==(d2);	//三者等效	//运算符重载
	//d1.operator==(&d1, d2);		//传递this指针

}

bool DateIsEquel(const Date& d1, const Date& d2)
{
	//return true;
}

bool DateIsLess(const Date& d1, const Date& d2)
{
	//return true;
}

bool operator==(const Date& d1, const Date& d2)
{
	return d1._year == d2._year
		&& d1._month == d2._month
		&& d1._day == d2._day;
}

bool operator<(const Date& d1, const Date& d2)
{
	return true;
}


//int main()
{
	Date d1(2019, 5, 12);
	Date d2(2019, 5, 13);

	d1 == d2; // operator==(d1, d2);
	//operator==(d1, d2);		//二者等效
	//d1 < d2;
	//DateIsLess(d1, d2);
}






//<  拷贝(复制)构造函数  >拷贝构造是构造函数的一种重载

//浅拷贝：字节序拷贝(传值拷贝)Date copy(d1);相当于memcpy(&coopy,&d1,sizeof(Date));
//深拷贝：顺序表等的拷贝，或者权限访问的问题(延伸：引用计数的写时拷贝)



int main()
{
	Date d1(2019, 5, 13);
	Date copy(d1); // 拷贝构造函数
	copy.Print();
	d1.Print();

	SeqList s1(10);
	SeqList	s2(s1);
}



