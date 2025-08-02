class Solution {
public:
    int fun(vector<int>& prices,vector<vector<int>> &dp,int n,int i,int buy) {
        if(i >= n)
        return 0;
        if(dp[i][buy] != -1)
        return dp[i][buy];
        if(buy) {
            dp[i][buy] = max(-prices[i]+fun(prices,dp,n,i+1,0),0+fun(prices,dp,n,i+1,1));
        }
        else {
            dp[i][buy] = max(prices[i]+fun(prices,dp,n,i+2,1),0+fun(prices,dp,n,i+1,0));
        }
        return dp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        // 1->buy
        // 0->sell
        return fun(prices,dp,n,0,1);
    }
};