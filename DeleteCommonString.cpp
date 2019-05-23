//链接：https://www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212?tpId=85&&tqId=29868&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

//本题如果使用传统的暴力查找方式，如判断第一个串的字符是否在第二个串中，在再挪动字符删除这个字符
//的方式，效率为O(N^2)，效率太低，很难让人满意。
//1. 将第二个字符串的字符都映射到一个hashtable数组中，用来判断一个字符在这个字符串。
//2. 判断一个字符在第二个字符串，不要使用删除，这样效率太低，因为每次删除都伴随数据挪动。这里可
//以考虑使用将不在字符添加到一个新字符串，最后返回新新字符串


#include<iostream>
#include<string>
using namespace std;
int main(){
  // 注意这里不能使用cin接收，因为cin遇到空格就结束了。
  // oj中IO输入字符串最好使用getline。
  string str1,str2;
  //cin>>str1;
  //cin>>str2;
  getline(cin, str1);
  getline(cin, str2);
  // 使用哈希映射思想先str2统计字符出现的次数
  int hashtable[256] = {0};
  for(size_t i = 0; i < str2.size(); ++i){
    hashtable[str2[i]]++;
  }
  // 遍历str1，str1[i]映射hashtable对应位置为0，则表示这个字符在
  // str2中没有出现过，则将他+=到ret。注意这里最好不要str1.erases(i)
  // 因为边遍历，边erase，容易出错。
  string ret;
  for(size_t i = 0; i < str1.size(); ++i){
    if(hashtable[str1[i]] == 0)
    ret += str1[i];
  }
  cout<<ret<<endl;
  return 0;
}
