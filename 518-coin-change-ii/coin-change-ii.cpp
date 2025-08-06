class Solution {
public:
    int fun(int w, vector<int>& arr) {
        int n = arr.size();
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long> (w+1,0));
        for(int i=0; i<n+1; i++) {
            dp[i][0] = 1;
        }
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<w+1; j++) {
                if(arr[i-1] <= j) {
                    dp[i][j] = dp[i][j-arr[i-1]] + dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[n][w] == -1)
        return -1;
        else
        return dp[n][w];
    }
    int change(int amount, vector<int>& coins) {
        // unbounded + subset sum problem
        return fun(amount,coins);
    }
};