
//https://www.nowcoder.com/cts/16754304/summary?id=079D6DF3AAD70A2B#4/{%22uid%22%3A%22079D6DF3AAD70A2B%22%2C%22type%22%3A%224%22%2C%22index%22%3A1}

#include <iostream>
#include <math.h>
using namespace std;
int main(){
    string s = "";
    string tables = "0123456789ABCDEF";
    
    int num,i;
    cin >> num >> i;
    
    
    if(num == 0){
        s = "0";
    }
    while(num != 0){
        if(num < 0){
            num *= (-1);
            cout << "-";
        }
        s = tables[num%i] + s;
        num /= i;
    }
    
    /*
    int ret = 0;
    int flag = 0;
    while(num != 0){
        if(flag == 0){
            ret = num % i;
            num /= i;
             flag = 1;
            continue;
        }
        ret = (ret * 10) + (num % i);
        num /= i;
    }
    cout << ret << endl;
    */
    cout << s.c_str() << endl;
    return 0;
}
