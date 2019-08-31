


#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
	string str;
	cin >> str;
	int Max = 0;
	unordered_map<string, int> Map;
	int index = 0;
	int gap = 1;
	while (gap <= (int)str.size()) {
		while ((str[index] != '\0')){
			if ((str[index + gap - 1]) == '\0') {
				break;
			}
			Map[str.substr(index, gap)]++;
			++index;
		}
		index = 0;
		++gap;
	}
	auto mit = Map.begin();
	while (mit != Map.end()) {
		Max = max(mit->second, Max);
		++mit;
	}
	cout << Max << endl;
	return 0;
}
