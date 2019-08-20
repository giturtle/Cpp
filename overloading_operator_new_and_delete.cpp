

struct ListNode{
	ListNode* _next;
	ListNode* _prev;
	int _data;

	//重载类专属 operator new/ operator delete
	void* operator new(size_t n){
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		cout << "memory pool allocate" << endl;
		return p;
	}
	void operator delete(void* p){
		allocator<ListNode>().deallocate((ListNode*)p, 1);
		cout << "memory pool deallocate" << endl;
	}
};
class List{
public:
	List(){
		_head = new ListNode;
		_head->_next = _head;
		_head->_prev = _head;
	}
	~List(){
		ListNode* cur = _head->_next;
		while (cur != _head){
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
	}
private:
	ListNode* _head;
};

int main(){
	List l;
	return 0;
}
