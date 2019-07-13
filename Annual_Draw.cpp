


//年会抽奖
#include <iostream>
#include <vector>
using namespace std;

const long long maxn = 22;
 
long long d[maxn], cont[maxn];
double p[maxn];
void init(){
    cont[1] = 1;
    for(int i = 2; i <= maxn; i++)
        cont[i] = i * cont[i-1]; //所有的组合可能
    d[1] = 0, d[2] = 1;
    for(int i = 3; i <= maxn; i++)
        d[i] = (i-1)*(d[i-1]+d[i-2]);
    for(int i = 1; i <= maxn; i++)
        p[i] = (double)d[i]/cont[i] * 100;
}
 
int main(){
    init();
    int n;
    while(cin >> n)
        printf("%.2f%%\n", p[n]);
    return 0;
}
