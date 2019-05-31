


class Singleton{
public:
	static Singleton* GetInstance(){		//获取对象（每次获取同一个对象（唯一实例）），静态的全局只有一个
		//通常返回这个实例的指针或者引用
		static Singleton sinst;	//在类里面调用构造函数，创建一个静态成员对象
		return &sinst;
	}
private:
	Singleton(){}	//私有 构造函数
	Singleton(const Singleton&);//防拷贝
	//或者这种写法Singleton(const Singleton&) = delete; 删除函数，无论公有私有都无法调用
	
	static Singleton _sinst;	//静态（全局的）它属于整个类
	//虽然在类里面不能定义这个类的成员变量，但他是静态的，相当于在类外面定义一样
};	

Singleton Singleton::sinst;	//真正的定义在这里

int main(){
	cout << Singleton::GetInstance() <<endl;
	cout << Singleton::GetInstance() <<endl;
	cout << Singleton::GetInstance() <<endl;
}




//懒汉模式
//不再是一个实例对象，而是指向实例对象的一个指针
class Singleton{
public:
	//线程安全：与单核、多核无关。
	//如果多个线程同时去调用GetInstance()，两个线程获取到同一个对象
	static Singleton* GetInstance(){
		if(_spinst == nullptr){	//表示第一次调用,第二次不会进if逻辑，每次处理的同一个实例对象
			_spinst = new Singleton;
		}
		return _spinst;
	}
private:
	Singleton(){}	//私有 构造函数
	Singleton(const Singleton&);//防拷贝
	//...成员
	
	static Singleton* _spinst;	
};	
Singleton* Singleton::spinst = nullptr;
