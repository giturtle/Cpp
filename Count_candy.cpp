

//https://www.nowcoder.com/practice/02d8d42b197646a5bbd0a98785bb3a34?tpId=85&&tqId=29857&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking


#include<iostream>
using namespace std;
int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int A=(a+c)/2;
  int C=(d-b)/2;
  int B1=(c-a)/2;
  int B2=(b+d)/2;
  if(B1!=B2)
  cout<<"No";
  else
  cout<<A<<" "<<B1<<" "<<C;
  return 0;
}
