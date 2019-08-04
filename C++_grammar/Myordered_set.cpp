


#pragma once
#include "Hash.h"

using hashbucket::HashTable;

template<class K, class HF = HashFunc<K>>
class MyUnorderedSet{
	struct SetKeyOfValue{
		const K& operator()(const K& k){
			return k;
		}
	};
public:
	typedef typename HashTable<K, K, SetKeyOfValue, HF>::iterator iterator;
	pair<iterator, bool> Insert(const K& k){
		return _ht.Insert(k);
	}

	iterator Find(const K& key){
		return _ht.Find(key);
	}

	bool Erase(const K& key){
		return _ht.Erase(key);
	}

	iterator begin(){
		return _ht.begin();
	}

	iterator end(){
		return _ht.end();
	}
private:
	HashTable<K, K, SetKeyOfValue, HF> _ht;
};

void TestUnorderedSet(){
	MyUnorderedSet<int> s;
	s.Insert(3);
	s.Insert(2);
	s.Insert(3);
	s.Insert(9);
	s.Insert(13);
	MyUnorderedSet<int>::iterator it = s.begin();
	while (it != s.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;


	MyUnorderedSet<string> strSet;
	strSet.Insert("sort");
	strSet.Insert("insert");
	strSet.Insert("string");

	for (const auto& e : strSet){
		cout << e << endl;
	}
}
