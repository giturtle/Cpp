
#include <iostream>
#include <stdio.h>
using namespace std;

//引用
void testRef(){
  int a = 10;
  int &ra = a;
  int& aa = ra;

  //printf("%p\n".&a);
  //printf("%p\n".&ra);
  cout << &a << endl;
  cout << &ra << endl;
  cout << &aa << endl;
}
int main(){
  testRef();
  return 0;
}

//1. 引用在定义时必须初始化
//2. 一个变量可以有多个引用
//3. 引用一旦引用一个实体，再不能引用其他实体
void TestRef(){
  int a = 10;
  int& ra = a;
  int& raa = a;
  printf("%p %p %p\n",&a,&ra,&raa);
}
int main(){
  TestRef();
  return 0;
}


//常引用
void Test(){
  int a = 10;//相当于const int a = 10;
  const int& ra = a;
  const int& b = 10;
  double d = 12.3;
  const int& rd = d;
}


//做参数
void Swap(int& left,int& right){
  int temp = left;
  left = right;
  right = temp;
}
//做返回值
int& TestReff(int& a){
  a += 10;
  return a;
}
int& Add(int a,int b){
  static int c = a + b;
  return c;
}
int main(){
  int& ret = Add(1,2);
  //Add(3,4);
  cout << ret << endl;
  return 0;
}
//如果函数返回时，离开函数作用域后，其栈上空间已经还给系统，
//因此不能用栈上的空间作为引用类型返回。
//如果以引用类型返回，返回值的生命周期必须不受函数的限制(即比函数生命周期长)。




/*传值、传引用效率比较*/
//1. 参数传递
#include <time.h>
struct A{
  int a[10000];
};
void TestFunc1(A a){}
void TestFunc2(A& a){}
void TestRefAndValue(){
  A a;
  //参数函数传值
  unsigned int begin1 = clock();
  for(unsigned int i = 0;i < 10000;++i){
    TestFunc1(a);
  }
  unsigned int end1 = clock();

  //参数传引用
  unsigned int begin2 = clock();
  for(unsigned int i = 0;i < 10000;++i){
    TestFunc2(a);
  }
  unsigned int end2 = clock();

  cout << "TestFunc1(int*) time:" << end1 - begin1 << endl;
  cout << "TestFunc2(int&) time:" << end2 - begin2 << endl;
}
int main(){
  for(int i = 0;i < 10;++i){
    TestRefAndValue();
  }
  return 0;
}

//2. 作为返回值
A a;
A TestFunc1(){
  return a;
}
A& TestFunc2(){
  return a;
}
void TestReturnByRefOrValue(){
  //以值为函数的返回值类型
  unsigned int begin1 = clock();
  for(unsigned int i = 0;i < 10000;++i){
    TestFunc1();
  }
  unsigned int end1 = clock();

  //以引用做为函数的返回值类型
  unsigned int begin2 = clock();
  for(unsigned int i = 0;i < 10000;++i){
    TestFunc2();
  }
  unsigned int end2 = clock();

  cout << "TestFunc1 time:" << end1 - begin1 << endl;
  cout << "TestFunc2 time:" << end2 - begin2 << endl;
}
int main(){
  for(int i = 0;i < 10;++i){
    TestReturnByRefOrValue();
  }
  return 0;
}
//通过上述代码的比较，发现传值和指针在作为传参以及返回值类型上效率相差很大。



/*引用与指针的区别*/
//在语法概念上引用就是一个别名，没有独立空间，和其引用的实体共用同一块空间
//在此层实现上实际是有空间的，引用与指针都是按照指针方式来实现的,可以通过反汇编代码查看
int main(){
  int a = 10;
  int& ra = a;
  ra = 20;

  int *pa = &a;
  *pa = 20;

  cout << "&a = " << &a << endl;
  cout << "&ra = " << &ra << endl;//二者地址相同，共用同一块内存空间,但在底层上是有空间的
  return 0;
}
//引用与指针的不同点
//1. 引用在定义时必须初始化，指针没有要求
//2. 引用在初始化时引用一个实体后，就不能再引用其他实体，而指针可以在任何时候指向任何一个同类型实体
//3. 没有NULL引用，但有NULL指针
//4. 在sizeof中含义不同：引用结果为引用类型的大小，但指针始终是地址空间所占字节个数(32位平台下占4个字节)
//5. 引用自加即引用的实体增加1，指针自加即指针向后偏移一个类型的大小
//6. 有多级指针，但是没有多级引用
//7. 访问实体方式不同，指针需要显式解引用，引用编译器自己处理
//8. 引用比指针使用起来
//
//


//内联函数
//以inline修饰的函数叫做内联函数，编译时C++编译器会在调用内联函数的地方展开，没有函数压栈的开销，内联函数提升程序运行的效率。
//非内联函数的反汇编代码会在main函数中call这个函数（的地址）

//1. 在release模式下，查看编译器生成的汇编代码中是否存在call Add
//2. 在debug模式下,需要对编译器进行设置,否则不会展开(因为debug模式下,编译器默认不会对代码进行
//优化
//
//1. inline是一种以空间换时间的做法，省去调用函数额开销。所以代码很长或者有循环/递归的函数不适宜使用作为内联函数。
//2. inline对于编译器而言只是一个建议，编译器会自动优化，如果定义为inline的函数体内有循环/递归等等，编译器优化时会忽略掉内联。
//3. inline不建议声明和定义分离，分离会导致链接错误。因为inline被展开，就没有函数地址了，链接就会找不到。
//
