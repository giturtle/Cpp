
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
