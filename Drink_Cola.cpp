


#include <iostream>
using namespace std;
int main(){
    int empty;
    while(cin >> empty){
        int total = 0;

        while (empty >= 3){
            int tempZ = empty / 3;			//直接兑换汽水数
            total += tempZ;					//喝汽水
            
            int tempY = empty % 3;			//兑换后剩下的空瓶
            empty = tempY + tempZ;			//兑换后剩下的总空瓶数

            if (empty == 2){
                total++;
                break;
            }
        }
        cout << total << endl;
    }
    return 0;
}
