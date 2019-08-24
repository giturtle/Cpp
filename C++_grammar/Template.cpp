


//函数模板

template<class T1, class T2, ...>
返回值类型 函数名(参数列表) {
   // 函数主体逻辑
}

/*Swap*/
template<class T>
void Swap(T& left, T& right){
	T temp = left;
	left = right;
	right = temp;
}
template<class T>
T Add(const T& left, const T& right){
	return left + right;
}
int main(){
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;
	Add(a1, a2);
	Add(d1, d2);
	return 0;
}

// 专门处理 int 类型的加法函数
int Add(int left, int right){			//函数1
	return left + right;
}

// 通用类型的加法函数
template<class T>						
T Add(T left, T right){					//函数2
	return left + right;
}
void Test(){
	Add(1, 2); 		// 与非模板函数1匹配，编译器不需要特化
	Add<int>(1, 2); // 使用模板2推演，调用编译器特化的Add版本函数
}
void Test2(){
	Add(1, 2); 		// 与非函数模板1类型完全匹配，不需要函数模板实例化
	Add(1, 2.0); 	// 模板函数可以生成更加匹配的版本2，编译器根据实参生成更加匹配的Add函数
}




//类模板
template<class T1, class T2, ...>
class 类模板名{
	// 类内成员定义
}; 

/*Vector*/
template<class T>
class Vector{
public :
	Vector(size_t capacity = 10)
	 : _pData(new T[capacity])
	 , _size(0)
	 , _capacity(capacity)
	{}

	// 使用析构函数演示：在类中声明，在类外定义。请看下一代码块。
	~Vector();
	
	void PushBack(const T& data){
		// _CheckCapacity();
		_pData[_size++] = data;
	}
	
	void PopBack(){
		--_size;
	}
	
	size_t Size(){
		return _size;
	}
	
	T& operator[](size_t pos){
		assert(pos < _size);
		return _pData[pos];
	}

private:
	T* _pData;
	size_t _size;
	size_t _capacity;
};


/*Use*/
// Vector：类名
// Vector<int>：类型
int main(){
	Vector<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	Vector<double> s2;
	s2.PushBack(1.0);
	s2.PushBack(2.0);
	s2.PushBack(3.0);
	for(size_t i = 0; i < s1.Size(); ++i){
		cout << s1[i] << " ";
	}
	cout<<endl;
	for(size_t i = 0; i < s2.Size(); ++i){
		cout << s2[i] << " ";
	}
	cout<<endl;
}
