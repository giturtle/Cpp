
//[https://www.nowcoder.com/practice/f8538f9ae3f1484fb137789dec6eedb9?tpId=37&&tqId=21283&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking]

#include <iostream>
#include <algorithm>

using namespace std;

bool isPrime(int n){
    for(size_t i = 2;i <= sqrt(n);++i){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    int num;
    while(cin >> num){
        int mid = num / 2;
        for(int i = mid;i != 0;--i){
            if(isPrime(i) && isPrime(num - i)){
                cout << i << endl;
                cout << num - i << endl;
                break;
            }
        }
    }
    return 0;
}
