
class Person{
  public:
   void Print(){
     cout << "name:" << _name << endl;
     cout << "age:" << _age << endl;
   }
  protected:
   string _name = "peter"; // 姓名
   int _age = 18; // 年龄
};

// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了Student和
//Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。
//调用Print可以看到成员函数的复用。

class Student : public Person{
  protected:
   int _stuid; // 学号
};

class Teacher : public Person{
  protected:
   int _jobid; // 工号
  };
int main(){
   Student s;
   Teacher t;
   s.Print();
   t.Print();
   return 0;
}


//区别
class Person{
  public :
   void Print ()
   {
   cout<<_name <<endl;
   }
  protected :
   string _name ; // 姓名
  private :
   int _age ; // 年龄
};

//class Student : protected Person
//class Student : private Person
class Student : public Person{
  protected :
   int _stunum ; // 学号
};




class Person{
  protected :
   string _name; // 姓名
   string _sex; // 性别
   int _age; // 年龄
};
class Student : public Person{
    public :
     int _No ; // 学号
};
void Test (){
   Student sobj ;
   // 1.子类对象可以赋值给父类对象/指针/引用
   Person pobj = sobj ;
   Person* pp = &sobj;
   Person& rp = sobj;

   //2.基类对象不能赋值给派生类对象
   sobj = pobj;

   // 3.基类的指针可以通过强制类型转换赋值给派生类的指针
   pp = &sobj
   Student* ps1 = (Student*)pp; // 这种情况转换时可以的。
   ps1->_No = 10;

   pp = &pobj;
   Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
   ps2->_No = 10;
}



//继承的作用域
// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
class Person{
  protected :
   string _name = "小李子"; // 姓名
   int _num = 111; // 身份证号
};
class Student : public Person{
public:
   void Print(){
     cout<<" 姓名:"<<_name<< endl;
     cout<<" 身份证号:"<<Person::_num<< endl;
     cout<<" 学号:"<<_num<<endl;
   }
  protected:
   int _num = 999; // 学号
};
void Test(){
   Student s1;
   s1.Print();
};


//重载与隐藏

// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
class A{
public:
   void fun(){
    cout << "func()" << endl;
   }
};
class B : public A{
public:
 void fun(int i){
   A::fun();
   cout << "func(int i)->" <<i<<endl;
 }
};
void Test(){
 B b;
 b.fun(10);
};





//6个默认成员函数，“默认”的意思就是指我们不写，编译器会变我们自动生成一个，那么在派生类中，这几个成员函数是如何生成的呢？
//1. 派生类的构造函数必须调用基类的构造函数初始化基类的那一部分成员。
//    如果基类没有默认的构造函数，则必须在派生类构造函数的初始化列表阶段显示调用。
//2. 派生类的拷贝构造函数必须调用基类的拷贝构造完成基类的拷贝初始化。
//3. 派生类的operator=必须要调用基类的operator=完成基类的复制。
//4. 派生类的析构函数会在被调用完成后自动调用基类的析构函数清理基类成员。因为这样才能保证派生类
//    对象先清理派生类成员再清理基类成员的顺序。
//5. 派生类对象初始化先调用基类构造再调派生类构造。
//6. 派生类对象析构清理先调用派生类析构再调基类的析构

//派生类默认函数
class Person{
  public :
 Person(const char* name = "peter")
 : _name(name )
 {
 cout<<"Person()" <<endl;
 }

 Person(const Person& p)
 : _name(p._name)
 {
 cout<<"Person(const Person& p)" <<endl;
 }

 Person& operator=(const Person& p )
 {
 cout<<"Person operator=(const Person& p)"<< endl;
 if (this != &p)
 _name = p ._name;

 return *this ;
 }

 ~Person()
 {
 cout<<"~Person()" <<endl;
 }
protected :
 string _name ; // 姓名
};
class Student : public Person
{
public :
 Student(const char* name, int num)
 : Person(name )
 , _num(num )
 {
 cout<<"Student()" <<endl;
 }

 Student(const Student& s)
 : Person(s)
 , _num(s ._num)
 {
 cout<<"Student(const Student& s)" <<endl ;
 }

 Student& operator = (const Student& s )
 {
 cout<<"Student& operator= (const Student& s)"<< endl;
 if (this != &s)
 {
 Person::operator =(s);
 num = s ._num;
 }
 return *this ;
 }

 ~Student()
 {
 cout<<"~Student()" <<endl;
 }
protected :
 int _num ; //学号
};
void Test ()
{
 Student s1 ("jack", 18);
 Student s2 (s1);
 Student s3 ("rose", 17);
 s1 = s3 ;
}
