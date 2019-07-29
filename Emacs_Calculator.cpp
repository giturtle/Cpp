

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




#include <bits/stdc++.h>
using namespace std; 
 
int atoi(string& s) {
    int tmp = 0;
    for(int i = 0; i < s.size(); ++i) {
        tmp *= 10;
        tmp += (s[i] - '0');
    }
    return tmp;
}
 
int main(){
    int n;
    while(cin >> n) {
        vector<string> v(n);
        stack<int> st;
        for(int i = 0; i < n; ++i) {
            cin >> v[i];
            if(v[i] != "+" && v[i] != "-" && v[i] != "*" && v[i] != "/") {
                st.push(atoi(v[i]));
            }
            else {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                if (v[i] == "+") 
                    st.push(left + right);
                else if (v[i] == "-")
                    st.push(left - right); 
                else if (v[i] == "*")
                    st.push(left * right);
                else if (v[i] == "/") {
                    if (right != 0)
                        st.push(left / right); 
                    else
                        return 0;
                }
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}
