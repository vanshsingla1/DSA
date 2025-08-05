class Solution {
public:
    int fun(int n,vector<int> &dp) {
        if(n <= 1)
        return 1;
        if(dp[n] != -1)
        return dp[n];
        int count = 0;
        for(int i=1; i<=n; i++) {
            count += fun(i-1,dp) * fun(n-i,dp);
        }
        return dp[n] = count;
    }
    int numTrees(int n) {
        // Catalan numbers
        // pattern exactly matches with catalan numbers
        // n = 3 -> c0c2 + c1c1 + c2c0
        vector<int> dp(n+1,-1);
        return fun(n,dp);
    }
};