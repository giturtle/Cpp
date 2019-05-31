#include <iostream>
using namespace std;
int main(){
  int N, f, l = 0,r = 0,f0 = 0,f1 = 1;
  cin >> N;
  while(1){
    f = f0 + f1;
    f0 = f1;
    f1 = f;
    //找到比N小且距离N最近的数，求出距离
    if(f < N)
      l = N-f;
    else
    {
      //找到比N大且距离N最近的数，求出距离
      r = f - N;
      break;
    }
  }
  //取最小距离
  cout << min(l,r) << endl;
  return 0;
}
