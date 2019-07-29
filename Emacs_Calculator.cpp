

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0)
            continue;
        vector<string> s(n);
        stack<int> st;
        for(int i = 0;i < n;++i){
            cin >> s[i];
        }
        
        for(int i = 0;i < n;++i){
            if(s[i][0] >= '0' && s[i][0] <= '9'){
                st.push(atoi(s[i].data()));
                //string().data():
                //返回指向数组的指针，该数组包含与构成字符串对象值的字符相同的字符序列。
            }
            else{
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                switch(s[i][0]){
                    case '+':st.push(b + a);break;
                    case '-':st.push(b - a);break;
                    case '*':st.push(a * b);break;
                    case '/':{
                        //if(a == 0)  TODO
                        st.push(b / a);break;
                    }
                }
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}

