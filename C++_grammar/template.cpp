#include <iostream>
//using namespace std;
using std::cout;
using std::endl;

// 专门处理int的加法函数
int Add(int left, int right)
{
	return left + right;
}

// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}

//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}

//int main()
//{
//	Add(1, 2);
//	Add(1, 2.0);
//
//	return 0;
//}

// C
//typedef int DataType;
//struct SeqList
//{
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//
//void SeqListPushBack(SeqList* ps, DataType x);
//void SeqListPopBack(SeqList* ps);
//
//// C++
//class SeqList
//{
//public:
//	void PushBack(DataType x);
//	void PopBack();
//
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};

struct Node
{};

#include <assert.h>

// C++泛型

// 类名：SeqList
// 类型：SeqList<T>
template<class T>
class SeqList
{
public:
	SeqList()
	{
		_array = new T[10];
		_size = 0;
		_capacity = 10;
	}

	SeqList(const SeqList<T>& s);
	SeqList<T>& operator=(const SeqList<T>& s);

	~SeqList();

	void PushBack(const T& x)
	{
		if (_size >= _capacity)
		{
			// 增容
		}

		_array[_size] = x;
		++_size;
	}

	void PopBack()
	{
		if (_size > 0)
		{
			--_size;
		}
	}

	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}

	const T& operator[](size_t index) const
	{
		assert(index < _size);
		return _array[index];
	}

	size_t Size() const
	{
		return _size;
	}

	void Print() const
	{
		for (size_t i = 0; i < _size; ++i)
		{
			cout << _array[i] << " ";
		}
		cout << endl;
	}
private:
	T* _array;
	size_t _size;
	size_t _capacity;
};

// 类外面定义成员的写法
template<class T>
SeqList<T>::~SeqList()
{
	delete[] _array;
}

//int main()
//{
//	SeqList<Node*> s2; // Node*
//
//
//	SeqList<int> s1; // int
//	s1.PushBack(1);
//	s1.PushBack(2);
//	s1.PushBack(3);
//	s1.PushBack(4);
//
//	for (size_t i = 0; i < s1.Size(); ++i)
//	{
//		if (s1[i] % 2 == 0)
//		{
//			s1[i] *= 2;
//		}
//	}
//
//	//s1.Print();
//	for (size_t i = 0; i < s1.Size(); ++i)
//	{
//		cout << s1[i] << " ";
//		cout << s1.operator[](i) << " ";
//
//	}
//	cout << endl;
//
//	return 0;
//}
