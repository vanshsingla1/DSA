class Solution {
public:
    const int MOD = 1e9+7;
    int fun(int n,int i,int x,vector<vector<int>> &dp) {
        if(n == 0)
        return 1;
        if(n < 0 || i>n)
        return 0;
        if(dp[n][i] != -1)
        return dp[n][i];
        int take = 0;
        int skip = 0;
        int diff = pow(i,x);
        if(diff > n) {
            return 0;
        }
            // take not-take
            take = fun(n-diff,i+1,x,dp)%MOD;
            skip = fun(n,i+1,x,dp)%MOD;
        
        return dp[n][i] = (take+skip)%MOD;
    }
    int numberOfWays(int n, int x) {
        // recursion + memo
        if(n == 0)
        return 1;
        vector<vector<int>> dp(301, vector<int>(301, -1));
        return fun(n,1,x,dp);
    }
};