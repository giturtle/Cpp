

//https://www.nowcoder.com/questionTerminal/286af664b17243deb745f69138f8a800?toCommentId=305677


#include<iostream>
#include<string>
using namespace std;
int main(){
    string s,str;
    while(getline(cin,s)){
        getline(cin,str);
        bool flag = false;
        int size = (int)s.size();
        for(int i = 0;i < size;++i){
            string compare;
            if(s[i] == '"'){
                i++;
                while(i < size && s[i] != '"'){
                    compare += s[i];
                    i++;
                }
                if(compare == str){
                    flag = true;
                    break;
                }
            }
            
            else if (s[i] != ','){
                while(i < size && s[i] != ','){
                    compare += s[i];
                    i++;
                }
                if(compare == str){
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
            cout << "Ignore" << endl;
        else
            cout << "Important!" << endl;
    }
    return 0;
}
