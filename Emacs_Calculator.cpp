

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
