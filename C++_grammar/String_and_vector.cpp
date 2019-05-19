void test_string1()
{
	std::string s1;
	cout << s1 << endl;
	cout << s1.c_str() << endl;

	std::string s2("hello, wrold");
	cout << s2 << endl;
	cout << s2.c_str() << endl;

	std::string s3(100, 'x');
	cout << s3 << endl;

	std::string s4(s3);
	cout << s4 << endl;

	std::string s5(s2, 2, 7);
	cout << s5 << endl;
}

void test_string2()
{
	std::string s("hello");
	s.push_back(' ');
	s.append("world");
	cout << s << endl;

	std::string w("world");
	s += '-';
	s += "change ";
	s += w;
	cout << s << endl;
}

void test_string3()
{
	/*std::string s("hello");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.max_size() << endl;

	s += "xxxxxxxxxxxxxxxxxxx";
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.clear();
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;*/

	//std::string s("hello");
	//s.resize(13);
	//s.resize(20, 'a');
	//cout << s << endl;
	//cout << s.c_str() << endl;

	//cout << s.size() << endl;
	//cout << s.capacity() << endl;

	//std::string s("hello");
	//s.reserve(10);
	//s.reserve(20);

	//cout << s << endl;
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;

	std::string s;
	s.reserve(1000);
	//s.resize(1000);
	size_t sz = s.capacity();
	cout << "capacity changed: " << sz << '\n';
	cout << "making s grow:\n";
	for (int i = 0; i < 1000; ++i)
	{
		s += 'c';
		//s[i] = 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

int StrToInt(const std::string& s);

void test_string4()
{
	std::string s1("hello");
	std::string s2(s1);
	std::string s3 = s1;
	std::string s4("world");
	cout << s2 << endl;

	s1 = s4;
	cout << s1 << endl;

	s1[4] = 'x';
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << " ";
		cout << s1.at(i) << " ";

	}
	cout << endl;

	//std::vector<int>::iterator
	// 正向迭代器
	// [)
	std::string::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		++(*it1);
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;

	std::string::reverse_iterator rit1 = s1.rbegin();
	while (rit1 != s1.rend())
	{
		cout << *rit1 << " ";
		++rit1;
	}
	cout << endl;

	const std::string s5("122333");
	std::string::const_iterator it5 = s5.begin();
	while (it5 != s5.end())
	{
		//(*it5)++;
		cout << *it5 << " ";
		it5++;
	}
	cout << endl;

	// C++11
	for (const auto& ch : s5)
	{
		cout << ch << " ";
	}
	cout << endl;

	for (auto& ch : s4)
	{
		ch = 'x';
	}
	cout << s4 << endl;
}

void test_string5()
{
	std::string s1("world");
	s1.insert(s1.begin(), ' ');
	s1.insert(0, "hello");
	cout << s1 << endl;

	//std::string::iterator it1 = s1.begin();
	/*auto it1 = s1.begin();
	while (it1 != s1.end())
	{
	if (*it1 == ' ')
	{
	s1.erase(it1);
	}
	++it1;
	}
	cout << s1 << endl;*/

	/*auto pos = std::find(s1.begin(), s1.end(), ' ');
	if (pos != s1.end())
		s1.erase(pos);
	cout << s1 << endl;*/

	std::string file1("string.cpp.gz");
	size_t pos = file1.rfind('.');
	std::string suffix = file1.substr(pos, 5);
	cout << suffix << endl;

	//std::string url1("http://www.cplusplus.com/reference/string/string/find/");
	std::string url1("https://tower.im/teams/c7c7881c3dd841bebb1565bb6d939333/projects/");
	size_t start = url1.find("://");
	start += 3;
	size_t finish = url1.find('/', start);
	std::string address = url1.substr(start, finish-start);
	cout << address << endl;
}

void test_string6()
{
	std::string str1;
	std::cin >> str1;
	cout << str1 << endl;

	std::string str2;
	std::cin >> str2;
	cout << str2 << endl;

	cout << (str1 < str2) << endl;
	cout << (str1 == str2) << endl;

	cout << str1 + "1111" << endl;
	cout << "1111" + str1 << endl;
}

//int main()
//{
//	test_string6();
//
//	return 0;
//}


#include<iostream>
#include<string>
using namespace std;

//int main()
//{
//	string s;
//	while (getline(cin, s))
//	{
//		cout << s << endl;
//		size_t pos = s.rfind(' ');
//		if (pos != string::npos)
//			cout << s.size() - pos - 1 << endl;
//		else
//			cout << s.size() << endl;
//	}
//
//	return 0;
//}

#include <vector>

//template<class T>
//class vector
//{
//private:
//	T* _array;
//	size_t _size;
//	size_t _capacity;
//};

void test_vector1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	for (auto e: v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector2()
{
	//size_t sz;
	//std::vector<int> foo;
	//foo.resize(100);
	//sz = foo.capacity();
	//std::cout << "making foo grow:\n";
	//for (int i = 0; i < 100; ++i) {
	//	//foo.push_back(i);
	//	if (sz != foo.capacity()) {
	//		sz = foo.capacity();
	//		std::cout << "capacity changed: " << sz << '\n';
	//	}
	//}

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	v.insert(v.begin(), 0);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	auto pos = find(v.begin(), v.end(), 2);
	if (pos != v.end())
	{
		v.insert(pos, 20);
	}
	
	pos = find(v.begin(), v.end(), 2);
	v.erase(pos);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.clear();
	//v.~vector();
	{
		vector<int> tmp;
		tmp.swap(v); // swap(tmp, v);
	}
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

int main()
{
	test_vector2();
}
