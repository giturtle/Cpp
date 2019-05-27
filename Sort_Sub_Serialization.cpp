#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for(int i = 0; i < n; ++i)
		cin>>v[i];
		
	int ret = 1;
	for(int i = 1; i < n-1; ++i){	//找出波峰波谷
		if((v[i-1] < v[i] && v[i] > v[i+1])
		|| (v[i-1] > v[i] && v[i] < v[i+1])){
			ret++;
		
		if(i != n-3)	// 这里对应处理的就是上面情况二描述的问题
			i++;
		}
	}
	cout<<ret<<endl;
}
