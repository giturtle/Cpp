
//题目ID：36898-参数解析
//链接：https://www.nowcoder.com/practice/668603dc307e4ef4bb07bcd0615ea677?tpId=37&&tqId=21297&rp=1&ru =/activity/oj&qru=/ta/huawei/question-ranking

//思路：通过以空格和双引号为间隔，统计参数个数。对于双引号，通过添加flag，保证双引号中的空格被输出。 
#include <iostream>
#include <string>
using namespace std;
int main(){
  string str;
  while (getline(cin, str)){
    int count = 0;
    //首先计算参数数量
    for (int i = 0; i < str.size(); i++){
      if (str[i] == ' ')
      count++;
      //如果是双引号，向后遍历，直到下一个双引号结束
      if (str[i] == '"'){
      do{
       i++;
      } while (str[i] != '"');
      }
    }
    
    //以空格计算个数，空格数量比参数个数少1
    cout << count + 1 << endl;
    
    //用flag表示是否包含双引号，0表示有双引号
    //双引号中的空格要打印出来
    //用异或改变flag的值，两个双引号可以使flag复原
    int flag = 1;
    for (int i = 0; i < str.size(); i++){
      //有双引号，flag通过异或变为0，下一次再遇到双引号，flag置为1
      if (str[i] == '"')
        flag ^= 1;
      //双引号和普通空格不打印
      if (str[i] != ' ' && str[i] != '"')
        cout << str[i];
      //双引号中的空格要打印
      if (str[i] == ' ' && (!flag))
        cout << str[i];
      //遇到双引号之外的空格就换行
      if (str[i] == ' ' && flag)
      cout << endl;
    }
  cout << endl;
  }
  return 0;
}
