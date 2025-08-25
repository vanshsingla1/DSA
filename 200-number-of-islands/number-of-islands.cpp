class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>> &visited,int i,int j) {
        visited[i][j] = 1;
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        for(int k=0; k<4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && !visited[nx][ny] && grid[nx][ny] == '1') {
                dfs(grid,visited,nx,ny);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int count = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    dfs(grid,visited,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};