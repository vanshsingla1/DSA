class Solution {
public:
    unordered_map<string, int> dp;
    bool fun(string s, vector<string>& dict, string temp) {
        if (s == temp) {
            return true;
        }
        if (dp.count(temp)) {
            return dp[temp];
        }
        for (int i = 0; i < dict.size(); i++) {
            if (temp.length() + dict[i].size() <= s.length()) {
                if (s.substr(temp.length(), dict[i].size()) != dict[i]) {
                    continue;
                }
                temp += dict[i];
                if(fun(s, dict, temp)) {
                    dp[temp] = 1;
                    return true;
                }
                temp.erase(temp.size() - dict[i].size());
            }
        }
        dp[temp] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) {
            return false;
        }
        string temp;
        return fun(s, wordDict, temp);
    }
};