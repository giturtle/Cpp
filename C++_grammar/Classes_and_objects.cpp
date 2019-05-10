

//class类的引入

struct Student{
  void SetStudentInfo(const char* name, const char* gender, int age){
    strcpy(_name, name);
    strcpy(_gender, gender);
    _age = age;
  }

  void PrintStudentInfo(){
    cout<<_name<<" "<<_gender<<" "<<_age<<endl;
  }

  char _name[20];
  char _gender[3];
  int _age;
};

int main(){
  Student s;
  s.SetStudentInfo("Peter", "男", 18);
  return 0;
}



//类的作用域
class Person{
  public:
  void PrintPersonInfo();
  private:
  char _name[20];
  char _gender[3];
  int _age;
};

// 这里需要指定PrintPersonInfo是属于Person这个类域
void Person::PrintPersonInfo(){
  cout<<_name<<" "_gender<<" "<<_age<<endl;
}


//this指针
class Date{
  public :
  void Display (){
    cout <<_year<< "-" <<_month << "-"<< _day <<endl;
  }

  void SetDate(int year , int month , int day){
    _year = year;
    _month = month;
    _day = day;
  }
  private :
  int _year ; // 年
  int _month ; // 月
  int _day ; // 日
};

int main(){
 Date d1, d2;
 d1.SetDate(2018,5,1);
 d2.SetDate(2018,7,1);
 d1.Display();
 d2.Display();
 return 0;
}


//案例
class A{
  public:
  void PrintA(){
   cout<<_a<<endl;
  }

  void Show(){
   cout<<"Show()"<<endl;
  }
  private:
  int _a;
};
int main(){
 Date* p = NULL;
 p->PrintA();
 p->Show();
}
