

//实现一个**通用的拷贝函数**？

1. **memcpy**

template<class T>
void Copy(T* dst, const T* src, size_t size){
	memcpy(dst, src, sizeof(T)*size);
}

//上述代码虽然对于任意类型的空间都可以进行拷贝，但是如果拷贝自定义类型对象就可能会出错，因为自定义类型对象有可能会涉及到深拷贝(比如`string`)，而`memcpy`属于==浅拷贝==。如果对象中涉及到资源管理，就只能用赋值。

2. **赋值方式拷贝**

template<class T>
void Copy(T* dst, const T* src, size_t size){
	for(size_t i = 0; i < size; ++i){
		dst[i] = src[i];
	}
}

//用循环赋值的方式虽然可以，但是代码的**效率比较低**，而`C/C++`程序最大的优势就是效率高。那能否将另种方式的优势结合起来？遇到内置类型就用`memcpy`拷贝，遇到自定义类型就用循环赋值方式来做？可以，设定一个`flag`即可。

3. **增加bool类型区分自定义与内置类型**

template<class T>
void Copy(T* dst, const T* src, size_t size, bool flag){
	if(flag)
		memcpy(dst, src, sizeof(T)*size);
	else{
		for(size_t i = 0; i < size; ++i)
		dst[i] = src[i];
	}
}

//通过多增加一个参数，就可将两种拷贝的优势体现结合起来。
//但缺陷是：用户需要根据所拷贝元素的类型去传递第三个参数，那**出错的可能性就增加**。那能否让函数**自动去识别**所拷贝类型是内置类型或者自定义类型呢？

4. **使用函数区分内置于自定义类型**
//因为内置类型的个数是确定的，可以将所有内置类型集合在一起，如果能够将所拷贝对象的类型确定下来，在内置类型集合中查找其是否存在即可确定所拷贝类型是否为内置类型。

bool IsPODType(const char* strType){
	const char* arrType[] = {"char", "short", "int", "long", "long long", "float","double", "long double"};
	for(size_t i = 0; i < sizeof(array)/sizeof(array[0]); ++i){
		if(0 == strcmp(strType, arrType[i]))
			return true;
	}
	return false;
}

template<class T>
void Copy(T* dst, const T* src, size_t size){
	if(IsPODType(typeid(T).name()))
		memcpy(dst, src, sizeof(T)*size);
	else{
		for(size_t i = 0; i < size; ++i)
		dst[i] = src[i];
	}
}

//通过`typeid`来确认所拷贝对象的实际类型，然后再在内置类型集合中枚举其是否出现过，既可确认所拷贝元素的类型为内置类型或者自定义类型。
//但缺陷是：枚举需要将所有类型遍历一遍，每次比较都是字符串的比较，效率比较低。

5. ==类型萃取==
//为了将内置类型与自定义类型区分开，给出以下两个类分别代表内置类型与自定义类型。

// 代表内置类型
struct TrueType{
	static bool Get(){
		return true ;
	}
};

// 代表自定义类型
struct FalseType{
	static bool Get(){
		return false ;
	}
};

//给出以下类模板，将来用户可以按照任意类型实例化该类模板。

template<class T>
struct TypeTraits{
	typedef FalseType IsPODType;
};

//对上述的类模板进行以下方式的实例化：


// 所有内置类型都需要特化一下：
template<>
struct TypeTraits<char>{
	typedef TrueType IsPODType;
};

template<>
struct TypeTraits<short>{
	typedef TrueType IsPODType;
};

template<>
struct TypeTraits<int>{
	typedef TrueType IsPODType;
};

template<>
struct TypeTraits<long>{
	typedef TrueType IsPODType;
};

//通过对TypeTraits类模板重写改写方式四中的Copy函数模板，来确认所拷贝对象的实际类型。

/*
T为int：TypeTraits<int>已经特化过，程序运行时就会使用已经特化过的TypeTraits<int>, 该类中的
 IsPODType刚好为类TrueType，而TrueType中Get函数返回true，内置类型使用memcpy方式拷贝

T为string：TypeTraits<string>没有特化过，程序运行时使用TypeTraits类模板, 该类模板中的IsPODType
刚好为类FalseType，而FalseType中Get函数返回true，自定义类型使用赋值方式拷贝
*/
template<class T>
void Copy(T* dst, const T* src, size_t size){
	if(TypeTraits<T>::IsPODType::Get())
		memcpy(dst, src, sizeof(T)*size);
	else{
		for(size_t i = 0; i < size; ++i)
		dst[i] = src[i];
	}
}
int main(){
	int a1[] = {1,2,3,4,5,6,7,8,9,0};
	int a2[10];
	Copy(a2, a1, 10);
	
	string s1[] = {"1111", "2222", "3333", "4444"};
	string s2[4];
	Copy(s2, s1, 4);
	return 0;
}
