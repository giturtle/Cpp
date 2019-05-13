


#include<iostream>
using namespace std;


//  < 构造函数 + 析构函数 >

//成员变量不是属于类的，而是属于对象的

//无参构造函数并非真正无参，本质是不用传参就可以调用的函数

//默认构造函数：无参或全缺省（不能同时存在）因为会产生二义性~

//建议使用全缺省的构造函数，因为：
//1. 既可以作为默认构造函数
//2. 又可以正常要传参初始化的函数

//析构函数先倒着析构 相当于栈 等于销毁栈帧。

//不能析构/释放两次的原因：OS中有许多线程，一个线程释放了地址空间后
//可能紧接着其他线程申请到了这部分内存，如果再去释放，
//就释放了别的线程的地址空间

//栈和栈：数据结构/虚拟地址空间分段：相同点都满足后进先出(空间建立栈帧就是利用栈的特点)

class A
{
public:
	void PrintA() // void PrintA(A *this)
	{
		cout << _a << endl;
		//相当于cout << this->_a << endl;
	}
	void Show() // void Show(A* this)此函数中没有解引用这个this指针
	{
		cout << this << endl;
		cout << "Show()" << endl;
	}
private:
	int _a;
};

int main()
{
	A* p = NULL;
	p->PrintA(); //p->PrintA(p);
}

//int main()
//{
//	A* p = NULL;
//	p->Show(); // p->Show(p);
//}



class Date
{
public:
	Date()	//不常用
	{
		cout << "Date()" << endl;
		_year = 1900;
		_month = 1;
		_day = 1;
	}

	Date(int year, int month, int day)	//不常用
	{
		cout << "Date()" << endl;
		_year = year;
		_month = month;
		_day = day;
	}
	Date(int year = 1900, int month = 1, int day = 1)  //常用
	{
		cout << "Date()" << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;  // 基本类型->不做处理

	A _a;	// 自定义类型->初始化==等价于：调用A的构造函数
};


class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}

	~A()	//因为析构函数的规定，导致它无法重载
	{
		cout << "~A()" << endl;
	}
};




// C++把变量分为：1. 内置类型 / 2. 基本类型 / 3. 自定义类型
//默认构造函数对基本类型：不作处理，但会对自定义类型进行处理
//如果没有写自定义类型的构造函数，那么就按照系统默认构造函数执行

int main()
{
	Date d1;
	Date d2;
	Date d3(2019, 5, 12);
	Date d4(2020);
	//Date d5();  //× 编译器规定，不认为创建了第五个对象
	d1.Print();
	d2.Print();
	d3.Print();
	d4.Print();
	//d5.Print();
}

class Time
{
public:
	Time(int hour)
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	//Date(int year = 1900, int month = 1, int day = 1)
	//{
	//	cout << "Date()" << endl;
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;  // 基本类型->不做处理

	Time _t;
};

int main()
{
	Date d1;
}

class Date
{
public:
	//Date(int year = 1900, int month = 1, int day = 1)
	//{
	//	cout << "Date()" << endl;
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}

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

	A _a;
};

class SeqList
{
public:
	SeqList(size_t N = 10)
	{
		_array = (int*)malloc(N * sizeof(int));
		_capacity = N;
		_size = 0;
	}

	~SeqList()
	{
		free(_array);
		_array = nullptr;
		_size = _capacity = 0;
	}

private:
	int* _array;
	size_t _size;
	size_t _capacity;
};

int main()
{
	SeqList s1;
	SeqList s2;
}


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

	// Date copy(d1);
	//Date(const Date& d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}

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
