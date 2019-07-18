

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
	string str;
	while (getline(cin, str)){
		vector<string>svec;
		svec.clear();
		string temp = "";
		for (int i = 0; i < str.size(); ++i){
			if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
				temp += str[i];
			else{
				if (temp.size() > 0){
					svec.push_back(temp);
					temp = "";
				}
			}
		}
		if (temp.size() > 0)
			svec.push_back(temp);
		for (int i = svec.size() - 1; i > 0; --i)
			cout << svec[i] << ' ';
		cout << svec[0] << endl;
	}
	return 0;
}
