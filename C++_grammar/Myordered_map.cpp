#pragma once
#include "Hash.h"

using hashbucket::HashTable;

template<class K, class V, class HF = HashFunc<K>>
class MyUnorderedMap{
	struct MapKeyOfValue{
		const K& operator()(const pair<K, V>& kv){
			return kv.first;
		}
	};
public:
	typedef typename HashTable<K, pair<K, V>, MapKeyOfValue, HF>::iterator iterator;
	pair<iterator, bool> Insert(const pair<K, V>& kv){
		return _ht.Insert(kv);
	}

	V& operator[](const K& k){
		pair<iterator, bool> ret = Insert(make_pair(k, V()));
		return ret.first->second;
	}

	const V& operator[](const K& k) const{
		pair<iterator, bool> ret = Insert(make_pair(k, V()));
		return ret.first->second;
	}

	iterator begin(){
		return _ht.begin();
	}

	iterator end(){
		return _ht.end();
	}

private:
	HashTable<K, pair<K, V>, MapKeyOfValue, HF> _ht;
};

void TestUnorderedMap(){
	MyUnorderedMap<string, string> dict;
	dict.Insert(make_pair("sort", "排序"));
	dict.Insert(make_pair("left", "左边"));
	dict["left"] = "剩余";
	MyUnorderedMap<string, string>::iterator it = dict.begin();
	while (it != dict.end()){
		cout << it->first << ":" << it->second << endl;
		++it;
	}
}
