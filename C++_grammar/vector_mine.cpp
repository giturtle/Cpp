


#include <assert.h>

template<class T>
class Vector{
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endofstorage(nullptr)
	{}

	//Vector(const Vector<T>& v)
	//{
	//	_start = new T[v.Capacity()];
	//	memcpy(_start, v._start, v.Size()*sizeof(T));
	//	_finish = _start + v.Size();
	//	_endofstorage = _start + v.Capacity();
	//}

	Vector(const Vector<T>& v)
		:_start(nullptr)
		, _finish(nullptr)
		, _endofstorage(nullptr)
	{
		//Reserve(v.Capacity());
		Reserve(v.Size());
		for (size_t i = 0; i < v.Size(); ++i){
			this->PushBack(v[i]);
		}
	}

	// v1 = v2
	Vector<T>& operator=(Vector<T> v){
		this->Swap(v);
		return *this;
	}

	// 
	void Swap(Vector<T>& v){
		std::swap(_start, v._start);
		std::swap(_finish, v._finish);
		std::swap(_endofstorage, v._endofstorage);
	}

	~Vector(){
		if (_start){
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}
	}

	iterator begin(){
		return _start;
	}

	iterator end(){
		return _finish;
	}

	const_iterator begin() const{
		return _start;
	}

	const_iterator end() const{
		return _finish;
	}

	void Reserve(size_t n){
		if (n > Capacity()){
			size_t size = Size();
			// 开新空间
			T* newarray = new T[n];
			if (_start)
				memcpy(newarray, _start, sizeof(T)*Size());

			// T的 operator=
		/*	for (size_t i = 0; i < size; ++i)
			{
				newarray[i] = _start[i];
			}*/

			// 释放旧空间
			delete[] _start;

			// 赋值
			_start = newarray;
			_finish = _start + size;
			_endofstorage = _start + n;
		}
	}

	void Resize(size_t n, const T& val = T()){
		if (n <= Size()){
			_finish = _start + n;
		}
		else{
			Reserve(n);

			while (_finish != _start + n){
				*_finish = val;
				++_finish;
			}
		}
	}

	void PushBack(const T& x){
		if (_finish == _endofstorage){
			size_t newcapacity = Capacity() == 0 ? 4 : Capacity() * 2;
			Reserve(newcapacity);
		}

		*_finish = x;
		++_finish;
	}

	void PopBack(){
		assert(_finish > _start);

		--_finish;
	}

	void Insert(iterator pos, const T& x){
		assert(pos < _finish);

		if (_finish == _endofstorage){
			size_t n = pos - _start;
			size_t newcapacity = Capacity() == 0 ? 4 : Capacity() * 2;
			Reserve(newcapacity);
			pos = _start + n;
		}

		iterator end = _finish-1;
		while (end >= pos){
			*(end + 1) = *end;
			--end;
		}

		*pos = x;
		++_finish;

		//pos = pos + 1;
	}

	iterator Erase(iterator pos){
		assert(pos < _finish);

		iterator it = pos;
		while (it < _finish-1){
			*it = *(it + 1);
			++it;
		}

		--_finish;

		return pos;
	}

	size_t Size() const{
		return _finish - _start;
	}

	size_t Capacity() const{
		return _endofstorage - _start;
	}

	T& operator[](size_t pos){
		assert(pos < Size());
		return _start[pos];
	}

	const T& operator[](size_t pos) const{
		assert(pos < Size());
		return _start[pos];
	}


private:
	iterator _start;
	iterator _finish;
	iterator _endofstorage;
};
