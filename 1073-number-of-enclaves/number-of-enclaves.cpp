class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>> &visited,int i,int j) {
        visited[i][j] = 1;
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,1,-1};
        for(int k=0; k<4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(grid,visited,nx,ny);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        // traverse 1st and last row
        for(int j=0; j<n; j++) {
            if(grid[0][j] == 1 && !visited[0][j]) {
                dfs(grid,visited,0,j);
            }
            if(grid[m-1][j] == 1 && !visited[m-1][j]) {
                dfs(grid,visited,m-1,j);
            }
        }
        // traverse 1st and last col
        for(int i=0; i<m; i++) {
            if(grid[i][0] == 1 && !visited[i][0]) {
                dfs(grid,visited,i,0);
            }
            if(grid[i][n-1] == 1 && !visited[i][n-1]) {
                dfs(grid,visited,i,n-1);
            }
        }
        // now traverse whole grid and count one
        int count = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};