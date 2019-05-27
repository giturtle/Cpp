#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string s;
	getline(cin, s);

	//1. 整体反转逻辑
	reverse(s.begin(), s.end());
	//2. 单词反转逻辑
	auto start = s.begin();
	while (start != s.end()){
		auto end = start;
		while (end != s.end() && *end != ' ')
			end++;
		reverse(start, end);
		
		if (end != s.end()){
			start = end + 1;
		}
		else{
			start = end;
		}
	}
	cout << s << endl;
	return 0;
}
