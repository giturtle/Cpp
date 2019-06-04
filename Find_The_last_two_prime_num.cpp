
//https://www.nowcoder.com/practice/f8538f9ae3f1484fb137789dec6eedb9?tpId=37&&tqId=21283&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//本题首先需要判断素数，素数表示除过1和本身，不能被其它数整除。通过循环遍历来判断一个数是否为素数。最近的两个素数应该从最中间的位置开始向两边查找。



#include<iostream>
#include<algorithm>
using namespace std;
//判断素数
bool isPrime(int num){
  int tmp = sqrt(num);
  //只遍历到开方出，不能被开方左边的数整除，则一定不能被开方右边的数整除
  for (int i = 2; i <= tmp; i++){
    if (num %i == 0)
    return false;
  }
  return true;
}

int main(){
  int num;
  int half;
  int i;
  while (cin >> num)
  {
    half = num / 2;
    //从中间向两边找
    for (i = half; i > 0; i--){
      if (isPrime(i) && isPrime(num - i))
        break;
    }
    cout << i << endl << num - i << endl;
  }
  return 0;
}
