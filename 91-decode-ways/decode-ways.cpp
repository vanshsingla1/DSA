class Solution {
public:
    int fun(string s, int i, int n,vector<int> &dp) {
        if (i >= n)
            return 1;
        if (s[i] == '0')
            return 0;
        if(dp[i] != -1)
        return dp[i];
        int res1 = 0;
        int res2 = 0;
        res1 = fun(s, i + 1, n,dp);
        if (i + 1 < n) {
            if (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6') {
                res2 = fun(s, i + 2, n,dp);
            }
        }
        return dp[i] = res1 + res2;
    }
    int numDecodings(string s) {
        int n = s.length();
        // no need to store the res, we want only count,in how many ways a
        // message can be decoded
        vector<int> dp(n+1,-1);
        return fun(s,0,n,dp);
    }
};