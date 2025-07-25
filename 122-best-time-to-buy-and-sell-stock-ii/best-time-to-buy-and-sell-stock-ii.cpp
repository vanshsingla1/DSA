class Solution {
public:
    int fun(vector<int> &prices,int n,int i,int buy,vector<vector<int>> &dp) {
        if(i == n)
        return 0;
        int profit = 0;
        if(dp[i][buy] != -1)
        return dp[i][buy];
        if(buy) {
            //buy
            dp[i][1] = profit = max(-prices[i]+fun(prices,n,i+1,0,dp),0+fun(prices,n,i+1,1,dp)); // buy, not buy
        }
        else {
            dp[i][0] = profit = max(prices[i]+fun(prices,n,i+1,1,dp),0+fun(prices,n,i+1,0,dp));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        //recursion + memo
        int n = prices.size();
        // 1-> buy
        // 0-> sell
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return fun(prices,n,0,1,dp);
    }
};