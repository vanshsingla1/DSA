class Solution {
public:
    int fun(vector<int>& prices, vector<vector<int>>& dp, int i, int trans,
            int n,int k) {
        if (i == n || trans == k*2)
            return 0;

        if (dp[i][trans] != -1)
            return dp[i][trans];
        if (trans % 2 == 0) {
            dp[i][trans] =
                max(-prices[i] + fun(prices, dp, i + 1, trans + 1, n,k),
                    0 + fun(prices, dp, i + 1, trans, n,k));
        } else
            dp[i][trans] = max(prices[i] + fun(prices, dp, i + 1, trans + 1, n,k),
                               0 + fun(prices, dp, i + 1, trans, n,k));

        return dp[i][trans];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(k*2, -1));
        // trans = B S B S (0,1,2,3,...) even-> Buy, odd-> Sell
        return fun(prices, dp, 0, 0, n,k); // i, trans
    }
};