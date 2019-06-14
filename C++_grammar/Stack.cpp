#pragma once

template<class T, class Container = deque<int>>
class Stack{
public:
	void Push(const T& x)
	{
		_con.push_back(x);
	}

	void Pop()
	{
		_con.pop_back();
	}

	size_t Size() const
	{
		return _con.size();
	}

	bool Empty() const
	{
		return _con.empty();
	}

	T& Top()
	{
		return _con.back();
	}

	const T& Top() const
	{
		return _con.back();
	}

private:
	Container _con;
};

void TestStack()
{
	//Stack<int, vector<int>> s;
	//Stack<int, list<int>> s;
	//Stack<int> s;
	Stack<int, deque<int>> s;

	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);

	while (!s.Empty())
	{
		cout << s.Top() << endl;
		s.Pop();
	}
}
