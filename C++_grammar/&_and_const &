

//取地址及const取地址操作符重载
//这两个默认成员函数一般不用重新定义 ，编译器默认会生成

class Date
{
public:
	Date* operator&()
	{
		return this;
	}

	const Date* operator&() const
	{
		return this;
	}

private:
	int _year;
	int _month;
	int _day;
};



//将const修饰的类成员函数称之为const成员函数，const修饰类成员函数，实际修饰该成员函数隐含的this 指针，表明在该成员函数中不能对类的任何成员进行修改

#include<iostream>

using std::cout;
using std::endl;

class Date
{
public:

	void print()
	{
		cout << "print()" << endl;
	}

	void print() const
	{
		cout << "print() const" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	d1.print();

	const Date d2;
	d2.print();
}
