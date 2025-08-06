class Solution {
public:
    int fun(vector<int>& arr, int n,vector<int> &dp) {
        if(n == 0)
        return 0;
        if(dp[n] != -1)
        return dp[n];
        int minn = INT_MAX;
        for(int i=0; i<arr.size(); i++) {
            if(n-arr[i] >= 0) {
                int res = fun(arr,n-arr[i],dp);
                if (res != INT_MAX)
                minn = min(minn, 1 + res);
            }
        }
        return dp[n] = minn;
    }
    int coinChange(vector<int>& coins, int amount) {
        // brute force -> o(3^n)
        //recursive ?
        // yes
        int n = coins.size();
        vector<int> dp(amount+1,-1);
        int res = fun(coins,amount,dp);
        if(res == INT_MAX) return -1;
        else return res;
    }
};