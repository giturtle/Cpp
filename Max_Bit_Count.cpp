
//链接：[https://www.nowcoder.com/practice/4b1658fd8ffb4217bc3b7e85a38cfaf2?tpId=37&&tqId=21309&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking](https://www.nowcoder.com/practice/4b1658fd8ffb4217bc3b7e85a38cfaf2?

#include <iostream>

using namespace std;

int main(){
    int num;
    while(cin >> num){
        int count = 0;
        int Max = 0;
        while(num){
            if(num & 1){       //num % 2
                count++;
                Max = max(count,Max);
            }
            else{
                count = 0;
            }
            num >>= 1;
        }
        cout << Max << endl;
    }
    return 0;
}
