



// 直接暴力计算，默认所有蛋糕的位置标记成1,不能放的地方标记成0
// 1 1 0 0 1 1
// 1 1 0 0 1 1
// 0 0 1 1 0 0
// 0 0 1 1 0 0

#include<iostream>
#include<vector>
using namespace std;
int main(){
  int w,h,res = 0;
  cin >> w >> h;
  vector<vector<int>> a;
  a.resize(w);
  for(auto& e : a)
    e.resize(h, 1);
  for(int i=0;i<w;i++){
    for(int j=0;j<h;j++){
      if(a[i][j]==1){
        res++;
        // 标记不能放蛋糕的位置
        if((i+2)<w)
          a[i+2][j] = 0;
        if((j+2)<h)
          a[i][j+2] = 0;
      }
    }
  }
  cout << res;
  return 0;
}
