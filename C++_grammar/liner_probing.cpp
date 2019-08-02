

enum State {
	EMPTY,		//此位置为 空
	EXIST,		//此位置为 已有元素 
	DELETE		//此位置为 已经删除
};
template<class K, class V>
class HashTable{
	struct Elem{
		pair<K, V> _val;
		State _state;
	};
public:
	HashTable(size_t capacity = 3)
		: _ht(capacity), 
		_size(0)
	{
		for (size_t i = 0; i < capacity; ++i)
			_ht[i]._state = EMPTY;
	}
	bool Insert(const pair<K, V>& val){
		// 检测哈希表底层空间是否充足
		// _CheckCapacity();
		size_t hashAddr = HashFunc(key);
		// size_t startAddr = hashAddr;
		while (_ht[hashAddr]._state != EMPTY){
			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val.first == key)
				return false;
			hashAddr++;
			if (hashAddr == _ht.capacity())
				hashAddr = 0;
			/*
				// 转一圈也没有找到，注意：动态哈希表该种情况可以不用考虑，哈希表中元素个数到达
			   一定的数量，哈希冲突概率会增大，需要扩容来降低哈希冲突，因此哈希表中元素是不会存满的
				if(hashAddr == startAddr)
				return false;
			*/
		}

		// 插入元素
		_ht[hashAddr]._state = EXIST;
		_ht[hashAddr]._val = val;
		_size++;
		return true;
	}
	int Find(const K& key){
		size_t hashAddr = HashFunc(key);
		while (_ht[hashAddr]._state != EMPTY){
			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val.first == key)
				return hashAddr;

			hashAddr++;
		}
		return hashAddr;
	}
	bool Erase(const K& key){
		int index = Find(key);
		if (index != -1){
			_ht[index]._state = DELETE;
			_size--;
			return true;
		}
		return false;
	}
private:
	size_t HashFunc(const K& key){
		return key % _ht.capacity();		//除留余数法，闭散列的核心，也是局限性所在
									//因为必须给定一个整型家族的key值，如果传入字符串就无法判断
	}
private:
	vector<Elem> _ht;
	size_t _size;
};
