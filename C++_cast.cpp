


int main(){
	int i = 1;
	double d = i;	// 隐式类型转换
	printf("%d, %.2f\n", i, d);

	int* p = &i;
	int address = (int)p;	// 显示的强制类型转换
	printf("%x, %d\n", p, address);
}



class A{
public:
	virtual void f() {}
};
class B : public A
{};
void fun(A* pa){
	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);

	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}
int main(){
	A a;
	B b;
	fun(&a);
	fun(&b);
	system("pause");
	return 0;
}




int main() {
	const int a = 21;
	int* modifier = const_cast<int*>(&a);
	*modifier = 7;
	cout << *modifier << endl;
	return 0;
}





int main() {
	int i;
	const char* ptr = "1";
	i = reinterpret_cast<char>(ptr);
	std::cout << i << std::endl;
	system("pause");
	return 0;
}



int main(){
	double d = 88.48;
	int a = static_cast<int>(d);
	cout << a << endl;
	return 0;
}


//typedef void(*FUNC)();
//int DoSomething(int i){
//	cout << "DoSomething" << endl;
//	return 0;
//}
//void Test(){
//	// reinterpret_cast可以编译器以FUNC的定义方式去看待DoSomething函数
//	// 所以非常的BUG，下面转换函数指针的代码是不可移植的，所以不建议这样用
//	// C++不保证所有的函数指针都被一样的使用，所以这样用有时会产生不确定的结果
//
//	FUNC f = reinterpret_cast<FUNC>(DoSomething);
//	f();
//}
//int main() {
//	volatile const int constant = 21;
//	int* modifier = const_cast<int*>(&constant);
//	*modifier = 7;
//	cout << *modifier << endl;
//	*modifier = 8;
//	cout << *modifier << endl;
//	system("pause");
//	return 0;
//}
