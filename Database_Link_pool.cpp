#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
    int num;
    while(cin >> num){
        set<string> sc;
        string key,type;
        int maxSize = 0;
        for(int i = 0;i < num;++i){
            cin >> key >> type;
            if(type == "connect") sc.insert(key);
            if(type == "disconnect") sc.erase(key);
            int size = sc.size();     //保存最大元素情况的容量
            maxSize = max(maxSize, size);
            
        }
        cout << maxSize << endl;
    }
    
    return 0;
}
