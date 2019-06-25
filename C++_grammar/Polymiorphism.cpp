


#include <iostream>
using namespace std;


//虚函数的重写/覆盖
/*
 * 派生类中有一个跟基类完全相同的虚函数
 * (即派生类虚函数与基类虚函数的返回值类型、
 * 函数名字、参数列表完全相同)，
 * 称子类的虚函数重写了基类的虚函数
 */
class Person {
public:
	virtual void BuyTicket() {
		cout << "Full Ticket" << endl;
	}
};

class Student : public Person {
	virtual void BuyTicket() {
		cout << "Half Ticket" << endl;
	}
};

//注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时
//	虽然也可以构成重写(因为继承后基类的虚函数被继承下来了
//	在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议这样使用

void Func(Person& p) {
	p.BuyTicket();
}
int main() {
	Person ps;
	Student st;
	Func(ps);
	Func(st);
	system("pause");
	return 0;
}



//虚函数重写的两个例外：
//1. 协变(基类与派生类虚函数返回值类型不同)
//派生类重写基类虚函数时，与基类虚函数返回值类型不同。
//即基类虚函数返回基类对象的指针或者引用，
//派生类虚函数返回派生类对象的指针或者引用时，称为协变
class A {};
class B : public A {};

class Person {
public:
	virtual A* f() { return new A; }
};

class Student : public Person {
public:
	virtual B* f() { return new B; }
};


//2. 析构函数的重写(基类与派生类析构函数的名字不同)
//如果基类的析构函数为虚函数，此时派生类析构函数只要定义，无论是否加virtual关键字，都与基类的
//析构函数构成重写，虽然基类与派生类析构函数名字不同。虽然函数名不相同，看起来违背了重写的规
//则，其实不然，这里可以理解为编译器对析构函数的名称做了特殊处理，编译后析构函数的名称统一处
//理成destructor

class Person {
public:
	virtual ~Person() { cout << "~Person()" << endl; }
};

class Student : public Person {
public:
	virtual ~Student() { cout << "~Student()" << endl; }
};

// 只有派生类Student的析构函数重写了Person的析构函数，
//下面的delete对象调用析构函数，才能构成多态，
//才能保证p1和p2指向的对象正确的调用析构函数。
int main(){
	Person* p1 = new Person;
	Person* p2 = new Student;
	delete p1;
	delete p2;
	return 0;
}


// C++11 override 和 final
//从上面可以看出，C++对函数重写的要求比较严格，但是有些情况下由于疏忽，可能会导致函数名字母次序
//写反而无法构成重载，而这种错误在编译期间是不会报出的，只有在程序运行时没有得到预期结果才来
//debug会得不偿失，因此：C++11提供了override和final两个关键字，可以帮助用户检测是否重写。

//1. final：修饰虚函数，表示该虚函数不能再被继承

class Car{
public:
	virtual void Drive() final {}
};

class Benz :public Car{
public:
	virtual void Drive() { cout << "Benz-舒适" << endl; }
	//无法重写final函数Car::Drive
};


//2. override: 检查派生类虚函数是否重写了基类某个虚函数，如果没有重写编译报错。
class Car {
public:
	virtual void Drive() {}
};

class Benz :public Car {
public:
	virtual void Drive() override { cout << "Benz-舒适" << endl; }
};

