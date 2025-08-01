class Solution {
public:
    int fun(vector<int>& prices, int n, vector<vector<vector<int>>>& dp, int i, int buy, int nsell) {
        if (i == n)
            return 0;

        if (dp[i][buy][nsell] != -1)
            return dp[i][buy][nsell];

        int profit = 0;

        if (buy) {
            if (nsell < 2) {
                profit = max(
                    -prices[i] + fun(prices, n, dp, i + 1, 0, nsell),
                    fun(prices, n, dp, i + 1, 1, nsell)
                );
            } else {
                profit = fun(prices, n, dp, i + 1, 1, nsell);
            }
        } else {
            profit = max(
                prices[i] + fun(prices, n, dp, i + 1, 1, nsell + 1),
                fun(prices, n, dp, i + 1, 0, nsell)
            );
        }

        return dp[i][buy][nsell] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return fun(prices, n, dp, 0, 1, 0);
    }
};
