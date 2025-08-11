class Solution {
public:
    const int MOD = 1e9+7;
    long long fun(int steps, int arrLen, int i,int j,vector<vector<long long>> &dp) {
        if(i >= arrLen || i<0)
        return 0; // out pf bounds
        if(j == steps) 
        return (i == 0) ? 1 : 0;
        if(dp[i][j] != -1)
        return dp[i][j];
        long long right = fun(steps,arrLen,i+1,j+1,dp)%MOD;
        long long left = fun(steps,arrLen,i-1,j+1,dp)%MOD;
        long long stay = fun(steps,arrLen,i,j+1,dp)%MOD;
        return dp[i][j] = (right+left+stay)%MOD;
    }
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen,steps); //because if arrLen = 1000, and steps = 5, then we cant traverse the whole array 
        vector<vector<long long>> dp(arrLen,vector<long long> (steps,-1));
        return fun(steps,arrLen,0,0,dp);
    }
};