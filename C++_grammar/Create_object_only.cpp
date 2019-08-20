

//请设计一个类，该类只能在堆上创建对象

class HeapOnly{
public:
	static HeapOnly* CreateObject(){
		return new HeapOnly;		//只能通过new操作符来创建对象
	}
private:
	HeapOnly() {}
	HeapOnly(const HeapOnly&) = delete;
};




//请设计一个类，该类只能在栈上创建对象
class StackOnly{
public:
	static StackOnly CreateObject(){
		return StackOnly();
	}
private:
	StackOnly() {}
};



class StackOnly{
public:
	StackOnly() {}
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};
