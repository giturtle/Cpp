#pragma once
#include <set>

void test_set()
{
	// 查找在不在
	// 排序+去重
	set<int> s;
	s.insert(4);
	s.insert(2);
	s.insert(5);
	s.insert(8);
	s.insert(4);
	s.insert(8);

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//auto it = s.begin();
	//while (it != s.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	auto pos = s.find(40); // O(logN)
	//auto pos = std::find(s.begin(), s.end(), 4); // O(N)
	if (pos != s.end())
		s.erase(pos);

	s.erase(40);
	s.erase(4);

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

#include <map>
#include <string>

//template<class K, class V>
//struct pair
//{
//	K first;
//	V second;
//};

//template<class K, class V>
//inline pair<K, V> make_pair(const K& k, const V& v)
//{
//	return pair<K, V>(k, v);
//}

void test_map()
{
	map<string, string> dict;
	dict.insert(pair<string, string>("sort", "排序"));
	dict.insert(pair<string, string>("string", "字符串"));
	dict.insert(pair<string, string>("insert", "插入"));
	dict.insert(make_pair("make", "制造"));
	dict.insert(make_pair("make", "xxx"));
	cout << dict["make"] << endl;
	dict["make"] = "xxx";

	dict["left"] = "左边";
	dict["left"] = "剩余";




	map<string, string>::iterator dit = dict.begin();
	while (dit != dict.end())
	{
		//cout << (*dit).first << ":" << (*dit).second << endl;
		//dit->first = "xxx";
		dit->second = "yyy";
		cout << dit->first << ":" << dit->second << endl;
		++dit;
	}

	for (const auto& e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}
}
