class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int MOD = 1e9+7;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>> maxdp(m,vector<long long>(n));
        vector<vector<long long>> mindp(m,vector<long long>(n));
        maxdp[0][0] = grid[0][0];
        mindp[0][0] = grid[0][0];
        for(int i=1; i<m; i++) {
            maxdp[i][0] = mindp[i][0] = grid[i][0] * maxdp[i-1][0];
        }
        for(int j=1; j<n; j++) {
            maxdp[0][j] = mindp[0][j] = grid[0][j] * maxdp[0][j-1];
        }
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                maxdp[i][j] = max((max(grid[i][j] * mindp[i-1][j],grid[i][j] * mindp[i][j-1])),(max(grid[i][j] * maxdp[i-1][j],grid[i][j] * maxdp[i][j-1])));
                mindp[i][j] = min((min(grid[i][j] * maxdp[i-1][j],grid[i][j] * maxdp[i][j-1])),(min(grid[i][j] * mindp[i-1][j],grid[i][j] * mindp[i][j-1])));
            }
        }
        if(maxdp[m-1][n-1] < 0)
        return -1;
        else
        return maxdp[m-1][n-1]%MOD;
    }
};