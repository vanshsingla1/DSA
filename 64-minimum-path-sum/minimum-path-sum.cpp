class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        // intialisation of dp
        dp[0][0] = grid[0][0];
        // now fill the values for dp table
        // first row
        for(int i=1; i<n; i++) {
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }
        // first row
        for(int i=1; i<m; i++) {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(i-1 >= 0 && j-1>= 0) {
                    dp[i][j] = grid[i][j] + min(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};