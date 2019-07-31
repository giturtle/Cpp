

//https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> dict;
        vector<int> ret;
        for(auto e : nums1){
            dict[e]++;
        }
        for(auto e : nums2){
            if(dict.count(e)){
                ret.push_back(e);
                dict[e]--;
                if(dict[e] == 0)    
                    dict.erase(e);
            }
        }
        return ret;
    }
};






//https://leetcode-cn.com/problems/intersection-of-two-arrays/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        
        set<int> s1;
        for(auto e:nums1){
           s1.insert(e);
        }
        
        set<int> s2;
        for(auto e:nums2){
           s2.insert(e);
        }
        
        for(auto e:s1){
            if(s2.find(e) != s2.end())	//s1和s2都共有此元素
                ret.push_back(e);
        }
        return ret;
    }
};
