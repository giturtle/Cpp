//构造函数

class Date{
  public:
  void SetDate(int year, int month, int day){
    _year = year;
    _month = month;
    _day = day;
  }

  void Display(){
    cout <<_year<< "-" <<_month << "-"<< _day <<endl;
  }
  private:
  int _year;
  int _month;
  int _day;
};

int main(){
  Date d1,d2;
  d1.SetDate(2018,5,1);
  d1.Display();

  Date d2;
  d2.SetDate(2018,7,1);
  d2.Display();
  return 0;
}



//特性：
//1. 函数名与类名相同。
//2. 无返回值。
//3. 对象实例化时编译器自动调用对应的构造函数。
//4. 构造函数可以重载。

class Date{ 
  public :
  // 1.无参构造函数
  Date (){}

  // 2.带参构造函数
  Date (int year, int month , int day ){
    _year = year ;
    _month = month ;
    _day = day ;
  }
  private :
  int _year ;
  int _month ;
  int _day ;
};
void TestDate(){
  Date d1; // 调用无参构造函数
  Date d2 (2015, 1, 1); // 调用带参的构造函数

  // 注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
  // 以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象
  Date d3();
}

