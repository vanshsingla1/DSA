class Solution {
public:
    int fun(vector<int>& prices,int k,vector<vector<vector<int>>> &dp,int i,int buy,int nsell,int n) {
        // similiar to knapsack
        if(i == n)
        return 0;
        if(dp[i][buy][nsell] != -1)
        return dp[i][buy][nsell];
        if(buy) {
            if(nsell < k) {
                dp[i][buy][nsell] = max(-prices[i]+fun(prices,k,dp,i+1,0,nsell,n),0+fun(prices,k,dp,i+1,1,nsell,n));
            }
            else {
                dp[i][buy][nsell] = fun(prices,k,dp,i+1,1,nsell,n);
            }
        }
        else {
                dp[i][buy][nsell] = max(prices[i]+fun(prices,k,dp,i+1,1,nsell+1,n),0+fun(prices,k,dp,i+1,0,nsell,n));
        }
        return dp[i][buy][nsell];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (k+1,-1)));
        // 1-> buy
        // 0-> sell
        return fun(prices,k,dp,0,1,0,n); // i buy nsell
    }
};