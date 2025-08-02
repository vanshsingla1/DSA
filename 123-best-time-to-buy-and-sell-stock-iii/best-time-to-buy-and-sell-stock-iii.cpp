class Solution {
public:
    int fun(vector<int>& prices, vector<vector<int>>& dp, int i, int trans,
            int n) {
        if (i == n || trans == 4)
            return 0;

        if (dp[i][trans] != -1)
            return dp[i][trans];
        if (trans % 2 == 0) {
            dp[i][trans] =
                max(-prices[i] + fun(prices, dp, i + 1, trans + 1, n),
                    0 + fun(prices, dp, i + 1, trans, n));
        } else
            dp[i][trans] = max(prices[i] + fun(prices, dp, i + 1, trans + 1, n),
                               0 + fun(prices, dp, i + 1, trans, n));

        return dp[i][trans];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        // trans = B S B S (0,1,2,3) even-> Buy, odd-> Sell
        return fun(prices, dp, 0, 0, n); // i, trans
    }
};