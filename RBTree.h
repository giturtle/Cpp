

#pragma once

enum Colour{
	RED,
	BLACK,
};

template<class T>
struct RBtreeNode{
	RBtreeNode<T>* _left;
	RBtreeNode<T>* _right;
	RBtreeNode<T>* _parent;

	T _val;
	Colour	   _col;

	RBtreeNode(const T& val)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _val(val)
		, _col(RED)
	{}
};

template<class K, class T, class KeyOfValue>
class RBTree{
	typedef RBtreeNode<T> Node;
public:
	bool Insert(const T& val){
		// 插入节点
		if (_root == nullptr){
			_root = new Node(val);
			_root->_col = BLACK;
			return true;
		}

		KeyOfValue kov;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur){
			if (kov(cur->_val) < kov(val)){
				parent = cur;
				cur = cur->_right;
			}
			else if (kov(cur->_val) > kov(val)){
				parent = cur;
				cur = cur->_left;
			}
			else{
				return false;
			}
		}

		cur = new Node(val);
		cur->_col = RED;
		if (kov(parent->_val) < kov(val)){
			parent->_right = cur;
			cur->_parent = parent;
		}
		else{
			parent->_left = cur;
			cur->_parent = parent;
		}

		while (parent && parent->_col == RED){
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left){
				Node* uncle = grandfather->_right;
				// 1.
				if (uncle && uncle->_col == RED){
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else{
					if (cur == parent->_right){
						RotateL(parent);
						swap(parent, cur);
					}

					RotateR(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;

					break;
				}
			}
			else{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED){
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else{
					if (cur == parent->_left){
						RotateR(parent);
						swap(parent, cur);
					}

					RotateL(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
					break;
				}
			}
		}

		_root->_col = BLACK;

		return true;
	}

	void RotateL(Node* parent){
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* pNode = parent->_parent;
		parent->_parent = subR;

		if (parent == _root){
			_root = subR;
			_root->_parent = nullptr;
		}
		else{
			if (pNode->_left == parent)
				pNode->_left = subR;
			else
				pNode->_right = subR;

			subR->_parent = pNode;
		}

	}

	void RotateR(Node* parent){
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;

		Node* pNode = parent->_parent;
		parent->_parent = subL;

		if (pNode == nullptr){
			_root = subL;
			_root->_parent = nullptr;
		}
		else{
			if (pNode->_left == parent){
				pNode->_left = subL;
			}
			else{
				pNode->_right = subL;
			}

			subL->_parent = pNode;
		}

	}

	bool IsValidRBTree(){
		Node* pRoot = _root;
		// 空树也是红黑树
		if (nullptr == pRoot)
			return true;

		// 检测根节点是否满足情况
		if (BLACK != pRoot->_col){
			cout << "违反红黑树性质二：根节点必须为黑色" << endl;
			return false;
		}

		// 获取任意一条路径中黑色节点的个数
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur){
			if (BLACK == pCur->_col)
				blackCount++;

			pCur = pCur->_left;
		}

		// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

	bool _IsValidRBTree(Node* pRoot, size_t k, const size_t blackCount){
		//走到null之后，判断k和black是否相等
		if (nullptr == pRoot){
			if (k != blackCount){
				cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
				return false;
			}
			return true;
		}

		// 统计黑色节点的个数
		if (BLACK == pRoot->_col)
			k++;

		// 检测当前节点与其双亲是否都为红色
		Node* pParent = pRoot->_parent;
		if (pParent && RED == pParent->_col && RED == pRoot->_col){
			cout << "违反性质三：没有连在一起的红色节点" << endl;
			return false;
		}

		return _IsValidRBTree(pRoot->_left, k, blackCount) &&
			_IsValidRBTree(pRoot->_right, k, blackCount);
	}

	void InOrder(){
		_InOrder(_root);
		cout << endl;
	}

	void _InOrder(Node* root){
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->val.first << " ";
		_InOrder(root->_right);
	}

private:
	Node* _root = nullptr;
};

//void TestRBtree()
//{
//	RBTree<int, int> t;
//	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14, };
//	for (auto e : a)
//	{
//		t.Insert(make_pair(e, e));
//	}
//
//	t.InOrder();
//	cout << t.IsValidRBTree() << endl;
//}
