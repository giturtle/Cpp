

//https://www.nowcoder.com/practice/5a304c109a544aef9b583dce23f5f5db?tpId=85&&tqId=29858&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking



#include <iostream>
#include <vector>
using namespace std;

int main(){
    int num;
    cin >> num;
    vector<int> v(num);
    for(size_t i = 0;i < v.size();++i){
        cin >> v[i];
    }
    int ret = v[0];
    int sum1 = 0,sum2 = 0;
    for(int i = 0;i < v.size();++i){
        sum2 = sum1 >= 0 ? sum1 + v[i] : v[i];
        if(sum2 > ret)
            ret = sum2;
        if(sum2 < 0)
            sum2 = 0;
        sum1 = sum2;
    }
    cout << ret << endl;
}
