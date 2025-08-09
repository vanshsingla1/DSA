class Solution {
public:
    int MOD = 1e9+7;
    int fun(vector<vector<int>>& grid,int i,int j,vector<vector<long long>> &dp) {
        if(dp[i][j] != -1)
        return dp[i][j];
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,1,-1};
        long long paths = 1;
        for(int k=0; k<4; k++) {
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx >= 0 && nx<grid.size() && ny>= 0 && ny<grid[0].size() && grid[nx][ny] > grid[i][j]) {
                paths += fun(grid,nx,ny,dp)%MOD;
            }
        }
        // can't traverse more in the given directions
        return dp[i][j] = paths;
    }
    int countPaths(vector<vector<int>>& grid) {
        // recursion
        // similar qn in nutanix
        int m = grid.size();
        int n = grid[0].size();
        long long paths = 0;
        vector<vector<long long>> dp(m+1,vector<long long>(n+1,-1));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                paths = (paths + fun(grid,i,j,dp))%MOD;
            }
        }
        return paths;
    }
};