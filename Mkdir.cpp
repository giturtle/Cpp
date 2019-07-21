


// 43 mkdir

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
 
int main(){
    int num;
    while(cin >> num){
        vector<string> vs(num);
        vector<bool> flag(num,true);
        
        for(int i = 0;i < num;++i)    cin >> vs[i];
        
        sort(vs.begin(), vs.end());    //字典序排布
        
        for(int i = 0;i < vs.size() - 1;++i){
			//1、两串相同
            if(vs[i] == vs[i+1])    flag[i] = false;
            
			// 2、前串是后串的子串，而且后串后一位是 '/'
            else if(
                vs[i].size() < vs[i+1].size()\
               && vs[i] == vs[i+1].substr(0,vs[i].size())\
               && vs[i+1][vs[i].size()] == '/'
              ){
                flag[i] = false;
            }
        }
        for(int i = 0;i < vs.size();++i){
            if(flag[i])
                cout << "mkdir -p " << vs[i] << endl;
        }          
        cout << endl;
    }
    return 0;
}
