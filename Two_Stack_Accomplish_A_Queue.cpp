

template<typename T>class Queue
{
public:
	Queue();
	~Queue();
	void PushBack(const T& node);	//appendTail
	T pop();
private:
	stack<T> stack1;
	stack<T> stack2;
};
template<typename T>
void Queue<T>::PushBack(const T& element) {
	stack1.push(element);	//栈1入栈
}
template<typename T>
T Queue<T>::pop() {
	if (stack2.size() <= 0) {
		while (stack1.size() > 0) {
			T &data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	if (stack2.size() == 0)
		throw new exception("queue is empty");
	T head = stack2.top();
	stack2.pop();

	return head;
}
