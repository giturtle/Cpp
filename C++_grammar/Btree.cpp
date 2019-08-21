

#pragma once
#include <iostream>


//B-树的简单实现

template<class K,size_t M = 1024>
struct BTreeNode{
  K _key[M];
  BTreeNode<K,M>* _sub[M+1];    //空间多给一个方便分裂
  BTreeNode<K,M>* _parent = nullptr;
  size_t _keysize;
};

template<class K,size_t M = 2014>
class BTree{
  typedef BTreeNode<K,M> Node;

public:
  bool Insert(const K& k){
    //树为空的插入
    if(_root == nullptr){
      _root = new Node;
      _root->_key[0] = k;
      _root->keysize = 1;
      return true;
    }
    //树不为空的插入：往叶子结点中插入
    Node* parent = nullptr;
    Node* cur = _root;
    while(cur){
      size_t i = 0;
      for(;i < cur->keysize;++i){
        if(cur->_key[i] < k){   //在右边
          ++i;
        }
        else if(cur->_key[i] > k){  //在左子树
          break;  //break下次循环会在找到的左子树的0号下标开始查找
        }
        else{   //相等
          return false; //有了就不插入了
        }
      }
      parent = cur;
      cur = cur->_sub[i];
    }
    //cur走到空了,parent指向了要插入结点的父亲
    Node* node = parent;
    K key = k;
    Node* sub = nullptr;

    //node key sub
    while(1){
      //向cur插入k
      InsertKey(node,key,sub);

      if(node->_keysize < M){    //结点没有满
        return true;
      }

      //满了，分裂：找到原中位数，后半段拷贝过去
      Node* splite_Node;
      size_t mid = M / 2;
      //[0,mid-1] mid [mid+1,M-1]

      size_t j = 0;
      for(size_t i = mid - 1;i < M;++i){
        splite_Node->_key[j] = node->_key[i];
        splite_Node->_sub[j] = node->_sub[i];
        ++j;
        splite_Node->_keysize++;
      }
      node->_keysize -= splite_Node->_keysize; 
      node->_keysize--; //mid要提到父亲节点中去

      if(node == _root){  //如果分裂的是根，则产生一个新的根
        _root = new Node;
        _root->key[0] = node->key[mid];

        _root->sub[0] = node;
        _root->sub[1] = splite_Node;
        _root->_keysize = 1;
        return true;
      }
      else{
        key = node->_key[mid];
        node = node->_parent;
        sub = splite_Node;
      }
    }
  }

private:
  Node* _root;
};
