namespace hashbucket{		//哈希桶
	template<class T>
	struct HashNode{
		HashNode<T>* _next;	//使用单向链表，正好符合哈希结构只有正向迭代器，无反向迭代器rbegin()...
		T _v;
		
		HashNode(const T& t)
			:_v(t)
			, _next(nullptr)
		{}
	};

	template<class K, class T, class KeyOfValue, class HF>
	class HashTable;		//前置声明，防止编译发现未定义的类型而无法通过

	template<class K, class T, class KeyOfValue, class HF>
	struct __HTIterator{
		typedef HashNode<T> Node;
		typedef __HTIterator<K, T, KeyOfValue, HF> Self;
		Node* _node;
		HashTable<K, T, KeyOfValue, HF>* _pht;

		__HTIterator(Node* node, HashTable<K, T, KeyOfValue, HF>* pht)
			:_node(node)
			, _pht(pht)
		{}

		T& operator*(){
			return _node->_v;
		}

		T* operator->(){
			return &(operator*());
		}

		// ++it
		Self& operator++(){
			if (_node->_next){
				_node = _node->_next;
			}
			else{
				KeyOfValue kov;
				size_t index = _pht->HashFunc(kov(_node->_v), _pht->_table.size());
				++index;
				while (index < _pht->_table.size()){
					if (_pht->_table[index]){
						_node = _pht->_table[index];
						break;
					}
					else{
						++index;
					}
				}

				// 所有桶走完了，置为nullptr表示end()的位置
				if (index == _pht->_table.size()){
					_node = nullptr;
				}
			}

			return *this;
		}

		bool operator!= (const Self& s){
			return _node != s._node;
		}
	};

	template<class K, class T, class KeyOfValue, class HF>
	class HashTable{
		typedef HashNode<T> Node;

		//friend struct __HTIterator<K, T, KeyOfValue, HF>;
		template<class K, class T, class KeyOfValue, class HF>
		friend struct __HTIterator;
	public:
		typedef __HTIterator<K, T, KeyOfValue, HF> iterator;
		iterator begin(){
			if (_num == 0){
				return end();
			}

			for (size_t i = 0; i < _table.size(); ++i){
				if (_table[i] != nullptr){
					return iterator(_table[i], this);
				}
			}

			return end();
		}

		iterator end(){
			return iterator(nullptr, this);
		}

		pair<iterator, bool> Insert(const T& v){
			KeyOfValue kov;
			// 增容 load factor == 1
			if (_table.size() == _num){
				size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
				vector<Node*> newtable;
				newtable.resize(newsize);

				// 挪动旧表数据到新表计算新的位置
				for (size_t i = 0; i < _table.size(); ++i){
					Node* cur = _table[i];
					while (cur){
						Node* next = cur->_next;

						size_t index = HashFunc(kov(cur->_v), newtable.size());
						cur->_next = newtable[index];
						newtable[index] = cur;

						cur = next;
					}

					_table[i] = nullptr;
				}

				newtable.swap(_table);
			}

			size_t index = HashFunc(kov(v), _table.size());
			Node* cur = _table[index];
			while (cur){
				if (kov(cur->_v) == kov(v)){
					return make_pair(iterator(cur, this), false);
				}

				cur = cur->_next;
			}

			// 头插
			Node* newnode = new Node(v);
			newnode->_next = _table[index];
			_table[index] = newnode;
			++_num;

			return make_pair(iterator(newnode, this), true);
		}

		iterator Find(const K& k){
			KeyOfValue kov;
			size_t index = HashFunc(k, _table.size());
			Node* cur = _table[index];
			while (cur){
				if (kov(cur->_v) == k){
					return iterator(cur, this);
				}

				cur = cur->_next;
			}

			return end();
		}

		bool Erase(const K& k){
			KeyOfValue kov;
			size_t index = HashFunc(k, _table.size());
			Node* prev = nullptr;
			Node* cur = _table[index];

			while (cur){
				if (kov(cur->_v) == k){
					if (prev == nullptr){
						_table[index] = cur->_next;
					}
					else{
						prev->_next = cur->_next;
					}

					delete cur;
					return true;
				}

				prev = cur;
				cur = cur->_next;
			}
		}

		size_t HashFunc(const K& k, size_t n){
			HF hf;
			return hf(k) % n;
		}

	private:
		vector<Node*> _table;	//桶式结构
		size_t _num = 0;
	};
}
