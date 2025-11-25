class Solution {
public:
    int fun(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<bool>>& visited,int count_0,int count) {
        if(i >= m || i < 0 || j >= n || j < 0) {
            return 0;
        }
        if(grid[i][j] == -1) {
            return 0;
        }
        if(visited[i][j] == true) {
            return 0;
        }
        if(grid[i][j] == 2 && count_0 == count) {
            return 1;
        }
        visited[i][j] = true;
        // traverse
        int down = fun(i+1,j,m,n,grid,visited,count_0,count+1);
        int up = fun(i-1,j,m,n,grid,visited,count_0,count+1);
        int right = fun(i,j+1,m,n,grid,visited,count_0,count+1);
        int left = fun(i,j-1,m,n,grid,visited,count_0,count+1);

        visited[i][j] = false;
        return (down+up+right+left);
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        // we need to ensure that all 0 marked cells are visited
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        int count_0 = 0;
        int si,sj = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != -1) {
                    count_0++;
                }
                if(grid[i][j] == 1) {
                    si = i;
                    sj = j;
                }
            }
        }
        return fun(si,sj,m,n,grid,visited,count_0,1);
    }
};