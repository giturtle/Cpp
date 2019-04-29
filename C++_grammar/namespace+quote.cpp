

#include <iostream>
using namespace std;

//命名空间
namespace Lu {
	int a;
	int Add(int left, int right) {
		return left + right;
	}
}

namespace lu_2 {
	int a;
	int b;
	namespace Lu_3 {
		int a;
		int c;
		int Sub(int a, int b) {
			return a - b;
		}
	}
}


//命名空间的使用
//1. 加命名空间名称、及作用域限定符
namespace Lu_4 {
	int a = 10;
	int add(int a, int b) {
		return a + b;
	}
}
int main() {
	printf("%d\n", Lu_4::a);
	system("pause");
	return 0;
}


2. 使用using将命名空间中成员引入，局部放出，首选！避免重名冲突
using Lu_4::a;
int main() {
	a = 20;
	std::cin >> a;
	std::cout << a << std::endl;
	std::cout << Lu_4::add(3, 4) << std::endl;
	system("pause");
	return 0;
}

3. 使用using namespace 命名空间名称引入
using namespace std;
using namespace Lu_4;
int main() {
	cout << Lu_4::a << endl;
	cout << a << endl;
	system("pause");
	return 0;
}



//输入、输出
//早期标准库将所有功能在全局域中实现，声明在.h后缀的头文件中，使用时只需包含对应头文件即可，
//后来将其实现在std命名空间下，为了和C头文件区分，也为了正确使用命名空间，规定C++头文件不带.h；旧
//编译器(vc 6.0)中还支持<iostream.h>格式，后续编译器已不支持，因此推荐使用<iostream>+std的方式。
using namespace std;
int main(){
	int a;
	double b;
	char c;
	cin >> a >> b >> c;
	cout << a << ' ' << b << c << endl;
	system("pause");
	return 0;
}




//缺省参数
//1. 半缺省参数必须从右往左依次来给出，不能间隔着给
//2. 缺省参数不能在函数声明和定义中同时出现
//如果生命与定义位置同时出现，恰巧两个位置提供的值不同，那编译器就无法确定到底该用那个缺省

void TestFunc(int a = 0) {
	cout << a << endl;
}
int main(){
	TestFunc();     // 没有传参时，使用参数的默认值
	TestFunc(10);   // 传参时，使用指定的实参
	system("pause");
	return 0;
}


//1. 全缺省函数
void test1(int a = 10, int b = 20, int c = 30) {
	cout << a << b << c << endl;
}


//2. 半缺省函数
void test2(int a, int b = 10, int c = 20) {
	cout << a << b << c << endl;
}

void test3(int a , int b = 10, int c = 20) {
	cout << a << b << c << endl;
}
int main() {
	test3(2,2);
	system("pause");
	return 0;
}




//函数重载
extern "C" int Add(int left,int right) {
	return left + right;
}
double Add(double left, int right) {
	return left + right;
}
long Add(long left, long right = 10) {
	return left + right;
}
int main() {
	//cout << Add(10);	//函数重载支持缺省
	//cout << Add(10, 20) << endl;
	//cout << Add(10.3, 20) << endl;
	//cout << Add(10, 20.3) << endl;
	printf("%d\n",Add(1, 2));
	system("pause");
	return 0;	
}




//引用
//1. 引用在定义时必须初始化
//2. 一个变量可以有多个引用
//3. 引用一旦引用一个实体，再不能引用其他实体
void TestRef(){
	int a = 10;
	int& ra = a; //引用类型必须和引用实体是同种类型的
	printf("%p\n", &a);
	printf("%p\n", &ra);
}

void TestRef(){
	int a = 10;
	// int& ra;   // 该条语句编译时会出错
	int& ra = a;
	int& rra = a;
	printf("%p %p %p\n", &a, &ra, &rra);
}

