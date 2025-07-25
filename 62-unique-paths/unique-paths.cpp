class Solution {
public:
    int fun(int m,int n,int i,int j,vector<vector<int>> &dp) {
        if(i == m-1 && j == n-1) {
            return 1;
            dp[i][j] = 1;
        }
        if(i >= m || j>=n)
        return 0;
        if(dp[i][j] != -1)
        return dp[i][j];
        return dp[i][j] = fun(m,n,i+1,j,dp) + fun(m,n,i,j+1,dp);
    }
    int uniquePaths(int m, int n) {
        //right or down
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return fun(m,n,0,0,dp);
    }
};