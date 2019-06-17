
//https://www.nowcoder.com/practice/9d1559511b3849deaa71b576fa7009dc?tpId=85&&tqId=29842&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking



#include <iostream>
#include <string>
using namespace std;

bool IsPalindrome(const string& s){
    size_t begin = 0;
    size_t end = s.size()-1;
    while(begin < end){
        if(s[begin] != s[end]){
            return false;
        }
        ++begin;
        --end;
    }
    return true;
}

int main(){
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    size_t count = 0;
    
    for(size_t i = 0; i <= str1.size(); ++i){
        // 将字符串2插入到字符串1的每个位置，再判断是否是回文
        string str = str1;
        str.insert(i, str2);
        if(IsPalindrome(str)){
            ++count;
        }
    }
    cout<<count<<endl;    
    return 0;
}
