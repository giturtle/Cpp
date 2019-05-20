
class A
{
public:
	A(int a = 0)
	{
		_a = a;
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

private:
	int _a;
};

//int main()
//{
//	// 基本类型、内置类型
//	// 动态申请单个对象
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//	free(p1);
//	delete p2;
//
//	// 动态申请N个对象
//	int* p3 = (int*)malloc(sizeof(int)*10);
//	int* p4 = new int[10];
//	free(p3);
//	delete[] p4;
//
//	////////////////////////////////////////////////////////
//	// 自定义类型
//	A* p5 = (A*)malloc(sizeof(A)); // 开空间
//	A* p6 = new A(100); // 开空间+调构造函数初始化
//
//	free(p5);  // 释放空间
//	delete p6; // 析构函数 + 释放空间
//
//	A* p7 = (A*)malloc(sizeof(A)*10); // 开空间
//	A* p8 = new A[10]; // 开空间+调构造函数初始化
//
//	free(p7);	  // 释放空间
//	delete[] p8; // 析构函数 + 释放空间
//
//	return 0;
//}
