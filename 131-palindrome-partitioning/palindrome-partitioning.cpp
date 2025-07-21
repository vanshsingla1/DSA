class Solution {
public:
    vector<vector<int>> dp;
    int isPalindrome(string s,int i,int j) {
        if(i > j)
        return 1;
        if(dp[i][j] != -1)
        return dp[i][j];
        if(s[i] != s[j])
        return dp[i][j] = 0;
        return dp[i][j] = isPalindrome(s,i+1,j-1);
    }
    void fun(string s,vector<string> path,vector<vector<string>> &res,int idx) {
        if(idx >= s.size()) {
            res.push_back(path);
            return;
        }
        for(int i=idx; i<s.size(); i++) {
            if(isPalindrome(s,idx,i)) {
                path.push_back(s.substr(idx,i-idx+1));
                fun(s,path,res,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> res;
        vector<string> path;
        dp = vector<vector<int>>(n,vector<int>(n,-1));
        fun(s,path,res,0); 
        return res;
    }
};