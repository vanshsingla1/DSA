class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    count++;
                    checkIslands(grid,i,j,n,m,visited);
                }
            }
        }
        return count;
    }
    bool valid(vector<vector<char>>& grid, int i, int j, int n, int m,vector<vector<int>>& visited)
    {
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]=='1' && !visited[i][j])
            {
                return true;
            }
        return false;
    }

    void checkIslands(vector<vector<char>>& grid,int i,int j,int n,int m,vector<vector<int>>& visited)
    {
        
        visited[i][j]=1;
      //  grid[i][j]='0';
        if(valid(grid,i+1,j,n,m,visited)) //Down
        {
            checkIslands(grid,i+1,j,n,m,visited);
        }
        if(valid(grid,i-1,j,n,m,visited)) //Up
        {
            checkIslands(grid,i-1,j,n,m,visited);
        }
        if(valid(grid,i,j-1,n,m,visited)) //Left
        {
            checkIslands(grid,i,j-1,n,m,visited);
        }
        if(valid(grid,i,j+1,n,m,visited)) //Right
        {
            checkIslands(grid,i,j+1,n,m,visited);
        }
    }
};