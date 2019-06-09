

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    char ss[512];
    string s;
    string s1,s2;
    int i,j,len1,len2,lmax;
    while(cin>>s1>>s2){
        len1 = s1.length();
        len2 = s2.length();
        reverse(s1.begin() , s1.end());
        reverse(s2.begin() , s2.end());

        lmax = len1 > len2 ? len1 : len2;

        int temp = 0;
        int sum[512];
        int k = 0,j;
        for(i = 0; i < lmax; i++){
            int a = 0,b = 0;
            if(i < len1)
                a = s1[i] - '0';
            else
                a = 0;
            if(i < len2)
                b = s2[i] - '0';
            else
                b = 0;
            int result = a + b + temp;
            temp = result > 9 ? 1 : 0;
            sum[k++] = result % 10;
        }
        if(temp > 0){
            sum[k] = 1;
            for(j = k; j >= 0; j--)
                cout << sum[j];
        }
        else{
            for(j = k - 1; j >= 0; j--)
                cout << sum[j];
        }
        cout << endl;
    }
    return 0;
}
