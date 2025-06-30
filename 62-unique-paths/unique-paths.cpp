class Solution {
public:
    int count(int i,int j,vector<vector<int>>&dp) {
        if(i==0 && j==0) {
            dp[i][j] = 1;
            return dp[i][j];
        }
        if(i<0 || j<0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int left = count(i,j-1,dp);//left side
        int up = count(i-1,j,dp);//right side
        return (dp[i][j] = left+up);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return count(m-1,n-1,dp);
    }
};