

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void findMaxCommonStr(string s1,string s2){
    if(s1.length() > s2.length())
            swap(s1 , s2);    //s1用于保存较短的子串
    int len1 = s1.length();
    int len2 = s2.length();
    int maxLen = 0,start = 0;
    vector<vector<int>> vv(len1 + 1,vector<int>(len2 + 1,0));
    for(int i = 1;i <= len1;++i){
        for(int j = 1;j <= len2;++j){
            if(s1[i - 1] == s2[j - 1]){
                vv[i][j] = vv[i - 1][j - 1] + 1;
                if(vv[i][j] > maxLen){
                    maxLen = vv[i][j];
                    start = i - maxLen;    //记录最长公共子串的起始位置
                }
            }
        }
    }
   cout<< s1.substr(start,maxLen) <<endl;
}
int main(){
   string s1,s2;
   while(cin >> s1 >> s2){
       findMaxCommonStr(s1,s2);
   }
   return 0;
}
