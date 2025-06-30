class Solution {
public:
    int count(int m,int n,vector<vector<int>>&dp,vector<vector<int>>grid) {
       //tabulation becoz in memoization tle is comming
       for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(i==0 && j==0) {
                dp[i][j] = grid[i][j];
                continue;
            }
            int up = 0;
            int left = 0;
            if(i > 0)
            up = dp[i-1][j];
            else
            up = INT_MAX;
            if(j > 0)
            left = dp[i][j-1];
            else
            left = INT_MAX;
            dp[i][j] = min(left,up) + grid[i][j];
        }
    }
    return dp[m-1][n-1];
}
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return count(m,n,dp,grid);
    }
};