

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 4;
int num[N];
int isSolve = 0;

void dfs(int index, int currentNum, int arr[]){
	if (currentNum == 24){
		isSolve = 1;
		return;
	}
	if (isSolve || currentNum > 24 || index >= 4)
		return;
	for (int operFlag = 0; operFlag < 4; operFlag++){
		switch (operFlag){
		case 0:
			dfs(index + 1, currentNum + arr[index], arr);
			break;
		case 1:
			dfs(index + 1, currentNum - arr[index], arr);
			break;
		case 2:
			dfs(index + 1, currentNum*arr[index], arr);
			break;
		case 3:
			dfs(index + 1, currentNum / arr[index], arr);
			break;
		}
		if (isSolve)
			return;
	}
}
int main(){
	while (cin >> num[0] >> num[1] >> num[2] >> num[3]){
		isSolve = 0;

		sort(num, num + 4);

		do{
			dfs(1, num[0], num);
			if (isSolve)
				break;
		} while (next_permutation(num, num + 4));
		if (isSolve)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}
