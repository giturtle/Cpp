


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





Q：为什么是父类对象指针或者引用才能调用虚函数？
A：因为只有父类的对象才既能指向父类对象，又能指向子类对象。

去掉父类虚函数virtual关键字：隐藏/重定义
去掉子类虚函数virtual关键字：重写/覆盖

析构函数建议定义为虚函数，子类的虚构函数重写了父类的析构函数
场景：(此时不显式定义为虚函数)
	//Person* p = new Person;没问题,会先调用Person的构造再调用析构
	Person* p = new Student;	//子类对象赋给父类指针
	delete p;	//delete分为析构+释放空间(p->destructor() + operator free(p);)
		//想要调用Student的析构函数，如果只调用了Person的析构函数，
		//如果此时Student析构函数在释放某些资源，就会造成内存泄漏
		
		//此时调用的是父类的析构函数
	
	如果不构成多态，就与 对象的类型 有关。
	但希望查看这个指针指向的是父类还是子类
		如果new出来的对象是父类的，就调用父类的
		如果是子类的，就是一个多态行为，加上virtual构成重写就可以
		(定义为虚函数之后)：
		~Student()
		~Person()
总结为：如果父类的指针指向了一个new出来的子类对象，
		如果不构成多态，那么析构函数的调用是有问题的，可能会出现内存泄漏
		
		
重载：
	1. 同一作用域
	2. 函数名相同，参数不同
重写(覆盖):
	1. 一个在基类，一个在派生类的两个虚函数
	2. 函数名，参数，返回值完全相同(协变例外)
	3. (析构函数的细节)
重定义(隐藏)：
	1. 一个在基类，一个在派生类的函数
	2. 两个同名函数不构成重写就是隐藏
	
	
override是放在子类在编译期间强制进行检查，是否进行重写
纯虚函数是放在父类，强制子类必须重写，不重写无法实例化对象

抽象类一般就是：现实没有具体实体的事物，抽象的概念
多态有可能是在 < 多个子类之间 > 展开的

实现继承：为了复用
接口继承：为了多态

	【Effective C++ 高性能服务器编程】
	
虚函数的地址放在了虚函数表中，为了实现多态。
这个虚函数表指针是在对象构造函数阶段初始化的。

对象中没有存虚表，而只存了虚表的指针，同类型对象共享同一个虚表
派生类其实是把父类的虚表拷贝过来，对重写的虚函数用子类的虚函数的地址进行覆盖
	所以虚函数的重写也叫覆盖
对象中头4/8个字节只存<虚表指针>，虚函数是存在<代码段>的，虚表是存在<代码段>的。

typedef void(*V_FUNC)();
void PrintVTable(V_FUNC* vft[]){
	for(size_t i = 0;vft[i] != nullptr;++I){
		printf("vftable[%d] : %p->",i,vtf[i]);	//第i个虚函数的地址
		V_FUNC f = vft[i];
		f();
	}
	cout << std::endl;
}
int main(){
	Base b;		//父类
	Derive d;	//子类
	
	PrintVTable((V_FUNC*)*(int*)&b);
	PrintVTable((V_FUNC*)*(int*)&d);
	
	return 0;
}

多态的原理：虚函数表

