class Solution {
public:
    int fun(int n,vector<int> &dp) {
        if(n == 1)
        return 1;
        if(dp[n] != -1)
        return dp[n];
        int res = INT_MIN;
        for(int i=1; i<n; i++) {
            int prod = i * max(n-i,fun(n-i,dp));
            res = max(prod,res);
        } 
        return dp[n] = res;
    }
    int integerBreak(int n) {
        if(n == 2)
        return 1;
        vector<int> dp(n+1,-1);
        return fun(n,dp);
    }
};