class Solution {
public:
    vector<vector<int>> dp;
    void isPalindrome(string s) {
        int n = s.length();
        for(int len=1; len<=n; len++) {
            for(int i=0; i+len-1<n; i++) {
                int j = i+len-1;
                if(i == j)
                dp[i][j]=1;
                else if(i+1 == j) {
                    if(s[i]==s[j])
                    dp[i][j]=1;
                    else
                    dp[i][j]=0;
                }
                else {
                    if(s[i]==s[j] && dp[i+1][j-1])
                    dp[i][j]=1;
                    else
                    dp[i][j]=0;
                }
            }
        }
    }
    void fun(string s,vector<string> path,vector<vector<string>> &res,int idx) {
        if(idx == s.length()) {
            res.push_back(path);
            return;
        }
        for(int j=idx; j<s.length(); j++) {
            if(dp[idx][j]) {
                path.push_back(s.substr(idx,j-idx+1));
                fun(s,path,res,j+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        dp = vector<vector<int>>(n,vector<int>(n,-1));
        vector<string> path;
        vector<vector<string>> res;
        isPalindrome(s); // pre computed dp
        fun(s,path,res,0);
        return res;
    }
};