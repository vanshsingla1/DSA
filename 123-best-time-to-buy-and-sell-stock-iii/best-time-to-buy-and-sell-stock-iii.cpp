class Solution {
public:
    int fun(vector<int>& prices,vector<vector<vector<int>>> &dp,int n,int i,int buy,int nsell) {
        if(i == n)
        return 0;
        if(dp[i][buy][nsell] != -1)
        return dp[i][buy][nsell];

        if(buy) {
            // buy ,not buy
            if(nsell < 2) {
                dp[i][buy][nsell] = max(-prices[i]+fun(prices,dp,n,i+1,0,nsell),0+fun(prices,dp,n,i+1,1,nsell));
            }
            else {
                dp[i][buy][nsell] = fun(prices,dp,n,i+1,1,nsell);
            }
        }
        else {
            // sell, not sell
            dp[i][buy][nsell] = max(prices[i]+fun(prices,dp,n,i+1,1,nsell+1),0+fun(prices,dp,n,i+1,0,nsell));
        }
        return dp[i][buy][nsell];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int>(3,-1)));
        // 0-> sell
        // 1-> buy
        return fun(prices,dp,n,0,1,0); // i buy nsell
    }
};