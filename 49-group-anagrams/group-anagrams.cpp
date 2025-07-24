class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        if(n == 0)
        return res;
        unordered_map<string, vector<string>>mp;
        for(auto str : strs) {
            string temp = str;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(str);
        }
        for(auto it : mp) {
            res.push_back(it.second);
        }
        return res;
    }
};