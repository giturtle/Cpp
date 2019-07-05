

// 使用RAII思想设计的SmartPtr类
template<class T>
class SmartPtr {
public:
 SmartPtr(T* ptr = nullptr)
 : _ptr(ptr)
 {}
 ~SmartPtr()
 {
 if(_ptr)
 delete _ptr;
 }
private:
 T* _ptr;
};
void MergeSort(int* a, int n)
{
 int* tmp = (int*)malloc(sizeof(int)*n);
 // 讲tmp指针委托给了sp对象，用时老师的话说给tmp指针找了一个可怕的女朋友！天天管着我，直到我go die
 SmartPtr<int> sp(tmp);
 // _MergeSort(a, 0, n - 1, tmp);


 // 这里假设处理了一些其他逻辑
 vector<int> v(1000000000, 10);
 // ...
}
int main()
{
 try {
 int a[5] = { 4, 5, 2, 3, 1 };
 MergeSort(a, 5);
 }
 catch(const exception& e)
 {
 cout<<e.what()<<endl;
 }
 return 0;
}










template<class T>
class SmartPtr {
public:
 SmartPtr(T* ptr = nullptr)
 : _ptr(ptr)
 {}
 ~SmartPtr()
 {
 if(_ptr)
 delete _ptr;
 }

 T& operator*() {return *_ptr;}
 T* operator->() {return _ptr;}
private:
 T* _ptr;
};
struct Date
{
 int _year;
 int _month;
 int _day;
};
int main()
{
 SmartPtr<int> sp1(new int);
 *sp1 = 10
 cout<<*sp1<<endl;

 SmartPtr<int> sparray(new Date);
 // 需要注意的是这里应该是sparray.operator->()->_year = 2018;
 // 本来应该是sparray->->_year这里语法上为了可读性，省略了一个->
 sparray->_year = 2018;
 sparray->_month = 1;
 sparray->_day = 1;
}








/*
 * auto_ptr
 *
 */
 // C++库中的智能指针都定义在memory这个头文件中
#include <memory>
class Date
{
public:
 Date() { cout << "Date()" << endl;}
 ~Date(){ cout << "~Date()" << endl;}
 int _year;
 int _month;
 int _day;
};
int main()
{
 auto_ptr<Date> ap(new Date);
 auto_ptr<Date> copy(ap);
 // auto_ptr的问题：当对象拷贝或者赋值后，前面的对象就悬空了
 // C++98中设计的auto_ptr问题是非常明显的，所以实际中很多公司明确规定了不能使用auto_ptr
 ap->_year = 2018;
 return 0;
}
// 模拟实现一份简答的AutoPtr,了解原理
template<class T>
class AutoPtr
{
public:
 AutoPtr(T* ptr = NULL)
 : _ptr(ptr)
 {}

 ~AutoPtr()
 {
 if(_ptr)
 delete _ptr;
 }

 // 一旦发生拷贝，就将ap中资源转移到当前对象中，然后另ap与其所管理资源断开联系，
 // 这样就解决了一块空间被多个对象使用而造成程序奔溃问题
 AutoPtr(AutoPtr<T>& ap)
 : _ptr(ap._ptr)
 {
 ap._ptr = NULL;
 }

 AutoPtr<T>& operator=(AutoPtr<T>& ap)
 {
 // 检测是否为自己给自己赋值
 if(this != &ap)
 {
 // 释放当前对象中资源
 if(_ptr)
 delete _ptr;

 // 转移ap中资源到当前对象中
 _ptr = ap._ptr;
 ap._ptr = NULL;
 }

 return *this;
 }

 T& operator*() {return *_ptr;}
  T* operator->() { return _ptr;}
private:
 T* _ptr;
};
int main()
{
 AutoPtr<Date> ap(new Date);

 // 现在再从实现原理层来分析会发现，这里拷贝后把ap对象的指针赋空了，导致ap对象悬空
 // 通过ap对象访问资源时就会出现问题。
 AutoPtr<Date> copy(ap);
 ap->_year = 2018;
 return 0;
}
