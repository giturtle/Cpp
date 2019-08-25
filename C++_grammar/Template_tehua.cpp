

template<class T, size_t N = 10>
class Array{
public:
	T& operator[](size_t index){
		return _array[index];
	}
	
	const T& operator[](size_t index) const{
		return _array[index];
	}
	
	size_t Size() const{
		return _size;
	}
	
	bool Empty() const{
		return _size == 0;
	}

private:
	T _array[N];		//非类型形参的使用
	size_t _size;
}；


template<class T>
bool IsEqual(T& left, T& right){
	return left == right;
}


int main(){
	char p1[] = "giturtle";
	char p2[] = "giturtle";
	if(IsEqual(p1, p2))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}


template<>
bool IsEqual<char*>(char*& left, char*& right){
	if(strcmp(left, right) > 0)		//字典序比较
		return true;
	return false;
}

bool IsEqual(char* left, char* right){
	if(strcmp(left, right) > 0)
		return true;
	return false;
}


//全特化
template<class T1, class T2>
class Data{
public:
	Data() {cout<<"Data<T1, T2>" <<endl;}
private:
	T1 _d1;
	T2 _d2;
};

template<>
class Data<int, char>{
public:
	Data() {cout<<"Data<int, char>" <<endl;}
	private:
	int _d1;
	char _d2;
};

int main(){
	Data<int, int> d1;
	Data<int, char> d2;
	
	return 0;
} 


//偏特化
template<class T1, class T2>
class Data{
public:
	Data() {cout<<"Data<T1, T2>" <<endl;}
private:
	T1 _d1;
	T2 _d2;
};


//1. 部分特化
//特化第二个参数为 int 类型
template <class T1>
class Data<T1, int>{
public:
	Data() {cout<<"Data<T1, int>" <<endl;}
private:
	T1 _d1;
	int _d2;		//偏特化
}; 


//2. 参数更进一步限制
//两个参数偏特化为指针类型
template <typename T1, typename T2>
class Data <T1*, T2*>{
public:
	Data() {cout<<"Data<T1*, T2*>" <<endl;}
private:
	T1 _d1;
	T2 _d2;
};

//两个参数偏特化为引用类型
template <typename T1, typename T2>
class Data <T1&, T2&>{
public:
	Data(const T1& d1, const T2& d2)
	 : _d1(d1)
	 , _d2(d2)
	{
		cout<<"Data<T1&, T2&>" <<endl;
	}
private:
	const T1 & _d1;
	const T2 & _d2;
};

void test2 (){
	Data<double , int> d1; 		// 调用特化的 int 版本
	Data<int , double> d2;	    // 调用 基础 的模板
	Data<int *, int*> d3; 		// 调用特化的 指针 版本
	Data<int&, int&> d4(1, 2);  // 调用特化的 引用 版本
}
