

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string,int> m;
        vector<string> ret;
		string temp;
        
        //将合并后字符串中所有单词放入 map 容器
        string C = A + " " + B + " ";
        for(int i = 0;i < C.size();++i){
            if(C[i] != ' ') temp += C[i];
            else {
                m[temp]++;
                temp.clear();
            }
        }
        
        //进行处理 <key,value>
        for(auto i = m.begin();i != m.end();++i){
            if(i->second == 1){
                ret.push_back(i->first);
            }
        }
        return ret;
    }
};
