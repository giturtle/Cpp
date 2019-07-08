


#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

// RAII不等价于智能指针
// RAII解决问题的实现思想
// 智能指针是RAII思想的一种实现

// 1.RAII
// 2.像指针一样
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		cout << "delete:" <<_ptr << endl;
		delete _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	T* get()
	{
		return _ptr;
	}
private:
	T* _ptr;
};

void Div(double a, double b)
{
	if (b == 0)
	{
		invalid_argument err("除数等于0");
		throw err;
	}
	else
	{
		cout << a / b << endl;
	}
}

struct A
{
	int _a1;
	int _a2;
};

void Func()
{
	SmartPtr<int> sp(new int); // 托管
	/*int* p = sp.get();
	*p = 10;
	cout << *p << endl;
	*/
	*sp = 10;
	sp.operator*() = 20;
	cout << *sp << endl;

	SmartPtr<A> spa(new A);
	cout << spa->_a1 << endl;
	cout << spa.operator->()->_a1 << endl;
	cout << spa->_a2 << endl;

	double x1, x2;
	cin >> x1 >> x2;
	Div(x1, x2);
}


//int main()
//{
//	try{
//		Func();
//	}
//	catch (exception& e)
//	{
//		e.what();
//	}
//
//	return 0;
//}

// 智能指针的深浅拷贝
//int main()
//{
//	SmartPtr<int> sp1(new int);
//	SmartPtr<int> sp2(sp1);
//
//	int* p1 = new int;
//	int* p2 = p1;
//
//	return 0;
//}

namespace my
{
	// 管理权转移
	// 严禁使用auto_ptr，因为他是一个带有缺陷的设计
	template<class T>
	class auto_ptr		// C++98
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~auto_ptr()
		{
			cout << "delete:" << _ptr << endl;

			delete _ptr;
		}

		// 管理权转移
		// my::auto_ptr<int> ap2(ap1); 
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		// ap1 = ap3
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
					delete _ptr;

				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}

			return *this;
		}


		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	void test_auto_ptr()
	{
		my::auto_ptr<int> ap1(new int);
		my::auto_ptr<int> ap2(ap1);
		my::auto_ptr<int> ap3(ap2);
		//*ap1 = 10;
		//*ap2 = 20;

		ap1 = ap3;
	}

	// 简单粗暴、不让拷贝
	template<class T>
	class unique_ptr		// C++11
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			cout << "delete:" << _ptr << endl;

			delete _ptr;
		}

		// C++98
		// 只声明，不实现，声明成私有 

		// C++11
		unique_ptr(const unique_ptr<T>& ap) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& ap) = delete;

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	void test_unique_ptr()
	{
		my::unique_ptr<int> ap1(new int);
		//my::unique_ptr<int> ap2(ap1);
	}

	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new std::mutex)
		{}

		// sp2(sp1)
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmtx(sp._pmtx)
		{
			AddRefCount();
		}

		void AddRefCount()
		{
			// 加锁或者使用加1的原子操作
			//_pmtx->lock();
			++(*_pcount);
			//_pmtx->unlock();
		}

		void Release()
		{
			//_pmtx->lock();
			bool lastone = false;
			if (--(*_pcount) == 0)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				delete _pcount;
				//delete _pmtx;
				lastone = true;

				_pcount = nullptr;
				_ptr = nullptr;
			}

			//_pmtx->unlock();
			if (lastone == true)
			{
				delete _pmtx;
			}
		}

		// sp1 = sp3
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			//if (this != &sp)
			if (_ptr != sp._ptr)
			{
				Release();

				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_pmtx = sp._pmtx;

				AddRefCount();
			}

			return *this;
		}

		int get_count()
		{
			return *_pcount;
		}

		~shared_ptr()
		{
			Release();
		}
	private:
		T* _ptr;
		int* _pcount;

		std::mutex* _pmtx;
	};

	//void test_shared_ptr()
	//{
	//	/*my::shared_ptr<int> ap1(new int);
	//	cout << ap1.get_count() << endl;

	//	{
	//		my::shared_ptr<int> ap2(ap1);
	//		cout << ap1.get_count() << endl;
	//	}

	//	cout << ap1.get_count() << endl;*/

	//	my::shared_ptr<int> ap1(new int(1));
	//	my::shared_ptr<int> ap2(ap1);
	//	ap1 = ap2;

	//	my::shared_ptr<int> ap3(new int(3));

	//	ap1 = ap3;
	//}

	struct Date
	{
		int _year;
		int _month;
		int _day;

		~Date()
		{
			cout << "~Date()" << endl;
		}
	};

	void SharePtrFunc(my::shared_ptr<Date>& sp, size_t n)
	{
		//cout << sp.get_count() << endl;
		for (size_t i = 0; i < n; ++i)
		{
			// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
			my::shared_ptr<Date> copy(sp);

			// 这里智能指针访问管理的资源，不是线程安全的。所以我们看看这些值两个线程++了2n次，但是最终看到的结果，并一定是加了2n
	/*		copy->_year++;
			copy->_month++;
			copy->_day++;*/
		}
	}

	void test_shared_ptr()
	{
		my::shared_ptr<Date> p(new Date);
		cout << p.get_count() << endl;

		const size_t n = 100000;
		std::thread t1(SharePtrFunc, p, n);
		std::thread t2(SharePtrFunc, p, n);

		t1.join();
		t2.join();

		cout << p.get_count() << endl;

		//cout << p->_year << endl;
		//cout << p->_month << endl;
		//cout << p->_day << endl;
	}
}

void test_auto_ptr()
{
	std::auto_ptr<int> ap1(new int);
	std::auto_ptr<int> ap2(ap1);
	*ap1 = 10;
}

int main()
{
	//my::test_auto_ptr();
	//::test_auto_ptr();

	//my::test_unique_ptr();

	my::test_shared_ptr();


	return 0;
}
