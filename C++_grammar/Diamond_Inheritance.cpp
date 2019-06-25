
//菱形继承的二义性和数据冗余

class Person
{
public :
 string _name ; // 姓名
};
class Student : public Person
{
protected :
 int _num ; //学号
};
class Teacher : public Person
{
protected :
 int _id ; // 职工编号
};
class Assistant : public Student, public Teacher
{
protected :
 string _majorCourse ; // 主修课程
};
void Test ()
{
 // 这样会有二义性无法明确知道访问的是哪一个
 Assistant a ;
 a._name = "peter";

 // 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
 a.Student::_name = "xxx";
 a.Teacher::_name = "yyy";
}



//虚拟继承可以解决菱形继承的二义性和数据冗余的问题。如上面的继承关系，在Student和Teacher的继承
//Person时使用虚拟继承，即可解决问题。需要注意的是，虚拟继承不要在其他地方去使用。
class Person
{
public :
 string _name ; // 姓名
};
class Student : virtual public Person
{
protected :
 int _num ; //学号
};
class Teacher : virtual public Person
{
protected :
 int _id ; // 职工编号
};
class Assistant : public Student, public Teacher
{
protected :
 string _majorCourse ; // 主修课程
};
void Test ()
{
 Assistant a ;
 a._name = "peter";
}



//虚拟继承解决数据冗余和二义性的原理
class A
{
public:
 int _a;
};
// class B : public A
class B : virtual public A
{
public:
 int _b;
};
// class C : public A
class C : virtual public A
{
public:
 int _c;
};
class D : public B, public C
{
public:
 int _d;
};
int main()
{
 D d;
 d.B::_a = 1;
 d.C::_a = 2;
 d._b = 3;
 d._c = 4;
 d._d = 5;
 return 0;
}






//菱形继承的内存对象成员模型：这里可以看到数据冗余

//菱形虚拟继承的内存对象成员模型：这里可以分析出D对象中将A放到的了对象组成的最下面，这个A
//同时属于B和C，那么B和C如何去找到公共的A呢？这里是通过了B和C的两个指针，指向的一张表。这两个指
//针叫虚基表指针，这两个表叫虚基表。虚基表中存的偏移量。通过偏移量可以找到下面的A。




