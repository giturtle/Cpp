

#include <iostream>
#include <string>
#include <vector>
using namespace std;

double Division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
		throw "Division by zero condition!";
	else
		return ((double)a / (double)b);
}

void Func()
{
	int* p = new int[10];
	
	int len, time;
	cin >> len >> time;
	Division(len, time);

	delete[] p;
}
//
//int main()
//{
//	try {
//		Func();
//	}
//	catch (int err)
//	{
//		cout << __LINE__ << err << endl;
//	}
//	catch (const string& err)
//	{
//		cout << __LINE__ << err << endl;
//	}
//	catch (const char* err)
//	{
//		cout << __LINE__ << err << endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	try{
//		vector<int> v(10, 5);
//		//v.at(10);
//		//v[10];
//		v.reserve(1000000000);
//	}
//	catch (const std::exception& e) // 这里捕获父类对象就可以
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "Unkown Exception" << endl;
//	}
//
//	return 0;
//}
