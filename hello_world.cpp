//现在有一个四位数（0000 ~ 9999），设计程序将千位、百位、十位、个位数分别输出
//2014 --> 千位数是2，百位数是0……
#include <iostream>
using namespace std;
int main() {
	int num;
	cout << "请输入一个千位数：" << endl;
	cin >> num;
	cout << num << "的千位数是：" << num / 1000 % 10 << endl;
	cout << num << "的百位数是：" << num / 100 % 10 << endl;
	cout << num << "的十位数是：" << num / 10 % 10 << endl;
	cout << num << "的个位数是：" << num % 10 << endl;
	system("pause");
	return 0;
}


//两个运算符的表达式
#include <iostream>
using namespace std;
int main() {
	float a, b, c, temp;
	char oper1, oper2;
	cout << "请输入表达式(如1+2*3)：" << endl;
	cin >> a >> oper1 >> b >> oper2 >> c;
	switch (oper1) {
	case '+': {
		switch (oper2) {
		case '+': cout << a << oper1 << b << oper2 << c << '=' << a + b + c << endl; break;
		case '-': cout << a << oper1 << b << oper2 << c << '=' << a + b - c << endl; break;
		case '*': cout << a << oper1 << b << oper2 << c << '=' << a + (b * c) << endl; break;
		case '/': if (c != 0) { cout << a << oper1 << b << oper2 << c << '=' << a + (b * c) << endl; break; }
				  else { cout << "输入错误！" << endl; break; }
			break;
		}
		break;
	}
	case '-': {
		switch (oper2) {
		case '+': cout << a << oper1 << b << oper2 << c << '=' << a - b + c << endl; break;
		case '-': cout << a << oper1 << b << oper2 << c << '=' << a - b - c << endl; break;
		case '*': cout << a << oper1 << b << oper2 << c << '=' << a - (b * c) << endl; break;
		case '/': if (c != 0) { cout << a << oper1 << b << oper2 << c << '=' << a - (b / c) << endl; break; }
				  else {cout << "输入错误！" << endl; break;}
			break;
		}
		break;
	}
	case '*': {
		temp = a * b;
		switch (oper2) {
		case '+': cout << a << oper1 << b << oper2 << c << '=' << temp + c << endl; break;
		case '-': cout << a << oper1 << b << oper2 << c << '=' << temp - c << endl; break;
		case '*': cout << a << oper1 << b << oper2 << c << '=' << temp * c << endl; break;
		case '/': if (c != 0) { cout << a << oper1 << b << oper2 << c << '=' << temp / c << endl; break; }
				  else { cout << "输入错误！" << endl; break; }
			break;
		}
		break;
	}
	case '/': {
		if (b != 0) {
			temp = a / b;
		}
		else {
			cout << "输入错误！" << endl; break;
		}
		switch (oper2) {
		case '+': cout << a << oper1 << b << oper2 << c << '=' << temp + c << endl; break;
		case '-': cout << a << oper1 << b << oper2 << c << '=' << temp - c << endl; break;
		case '*': cout << a << oper1 << b << oper2 << c << '=' << temp * c << endl; break;
		case '/': if (b != 0 && c != 0) { cout << a << oper1 << b << oper2 << c << '=' << temp / c << endl; break; }
				  else { cout << "输入错误！" << endl; break; }
			break;
		}
		break;
	}
	}
	system("pause");
	return 0;
}
//可以多包含一个 <cstdlib>头文件，和exit(1);搭配  替换掉函数内层的break;语句直接跳出
#include <cstdlib>
//每个case语句中内容就如下所示。
//但界面转瞬即逝，无法正常显示内容，system("pause");没有作用
case '+': {
	switch (oper2) {
	case '+': cout << a << oper1 << b << oper2 << c << '=' << a + b + c << endl; exit(1);
	case '-': cout << a << oper1 << b << oper2 << c << '=' << a + b - c << endl; exit(1);
	case '*': cout << a << oper1 << b << oper2 << c << '=' << a + (b * c) << endl; exit(1);
	case '/': if (c != 0) { cout << a << oper1 << b << oper2 << c << '=' << a + (b * c) << endl; exit(1); }
			  else { cout << "输入错误！" << endl; exit(1); }
	}
}


//输入表达式
#include <iostream>
using namespace std;
int main() {
	float a, b;
	char oper;
	cout << "请输入一个表达式(如1+2)：" << endl;
	cin >> a >> oper >> b;
	//①
	if (oper == '+') {
		cout << a << oper << b << '=' << a + b << endl;
	}
	else if (oper == '-') {
		cout << a << oper << b << '=' << a - b << endl;
	}
	else if (oper == '*') {
		cout << a << oper << b << '=' << a * b << endl;
	}
	else if (oper == '/' && b != 0) {
		cout << a << oper << b << '=' << a / b << endl;
	}
	else {
		cout << "输入错误!" << endl;
	}
	////等同于②
	//switch (oper) {
	//case '+': cout << a << oper << b << '=' << a + b << endl; break;
	//case '-': cout << a << oper << b << '=' << a - b << endl; break;
	//case '*': cout << a << oper << b << '=' << a * b << endl; break;
	//case '/': if (b != 0) { cout << a << oper << b << '=' << a / b << endl; break; }
	//		  else {cout << "输入错误!" << endl; break; }
	//default: cout << "输入错误!" << endl;
	//}
	system("pause");
	return 0;
}



#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cout << "请输入ax^2 + bx + c = 0的三个系数a,b,c：" << endl;
	cin >> a >> b >> c;
	if (a == 0) {
		cout << "非一元二次方程！" << endl;
	}
	else if (b*b - 4 * a*c >= 0) {
		cout << "有实数解！" << endl;
	}
	else
		cout << "无实数解！" << endl;
	system("pause");
	return 0;
}


#include <iostream>
using namespace std;
int main() {
	cout << 0 && !2 + 5 || 1 && !(2 + !0);
	cout << (1 || 0) && 0;
	system("pause");
	return 0;
}



#include <iostream>
using namespace std;
int main() {
	int mark;
	cout << "请输入成绩(0 ~ 100):" << endl;
	cin >> mark;
	if (mark >= 90 && mark <= 100) cout << "优秀" << endl;
	else if (mark >= 80 && mark < 90) cout << "良好" << endl;
	else if (mark >= 70 && mark < 80) cout << "及格" << endl;
	else if (mark >= 60 && mark < 70) cout << "及格" << endl;
	else if (mark < 0 || mark > 100) cout << "输入错误！" << endl;
	else cout << "不及格" << endl;
	system("pause");
	return 0;
}


//简单的猜数字小游戏
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	srand((unsigned int)time(NULL));
	int num = rand() % 5 + 1, input;
	cout << "请在 1 ~ 6中随便猜一个数字" << endl;
	cin >> input;
	if (input == num) {
		cout << "猜对了！" << endl;
		system("pause");
		return 0;
	}
	cout << "猜错了，还有2次机会！"<<endl << "请输入：" << endl;
	cin >> input;
	if (input == num) {
		cout << "猜对了！" << endl;
		system("pause");
		return 0;
	}
	cout << "猜错了，还有1次机会！" << endl << "请输入：" << endl;
	cin >> input;
	if (input == num) {
		cout << "猜对了！" << endl;
		system("pause");
		return 0;
	}
	cout << "挑战失败！答案是:" << num << endl;
	system("pause");
	return 0;
}


#include <iostream>
using namespace std;
int main() {
	int a, b;
	cout << "请输入两个数："<<endl;
	cin >> a >> b;
	if (a > b) {
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	cout << "这两个数从小到大输出为:";
	cout << a << " " << b << endl;
	system("pause");
	return 0;
}
