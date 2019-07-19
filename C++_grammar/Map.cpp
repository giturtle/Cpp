

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	map<string, string> m;
	m.insert(pair<string,string>("peach", "桃子"));
	m.insert(make_pair("banana", "香蕉")); 
	m["apple"] = "苹果";
	m["pear"] = "梨子";
	m["pear"] = "梨";
	cout << m.size() << endl;
	for (auto& e : m) {
		//e.first = "NULL";	//key不能修改
		e.second = "NULL";
	}
	for (auto& e : m) {
		cout << e.first << e.second << endl;
	}

	auto ret = m.insert(make_pair("peach", "桃色"));
	if (ret.second)
		cout << "<peach, 桃色>不在map中, 已经插入" << endl;
	else
		cout << "键值为peach的元素已经存在：" 
		<< ret.first->first 
		<< "--->" 
		<<ret.first->second
		<< " 插入失败" << endl;
	
	m.erase("apple");
	for (auto& e : m) {
		cout << e.first << e.second << endl;
	}
	if (1 == m.count("apple"))
		cout << "apple还在" << endl;
	else
		cout << "apple被吃了" << endl;
	system("pause");
	return 0;
}
