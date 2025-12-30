class Solution {
public:
    bool check(int x,int y,int ex,int ey,vector<vector<int>>& grid) {
        // first check the frequency of each element
        vector<int> freq(10);
        for(int i=x; i<=ex; i++) {
            for(int j=y; j<=ey; j++) {
                if(grid[i][j] < 1 || grid[i][j] > 9) {
                    return false;
                }
                freq[grid[i][j]]++;
                if(freq[grid[i][j]] > 1) {
                    return false;
                }
            }
        }
        int targetsum = grid[x][y] + grid[x][y+1] + grid[x][y+2];
        // now check sum of each row , column, diagonal
        // rows
        for(int i=x; i<=ex; i++) {
            int sum = 0;
            for(int j=y; j<=ey; j++) {
                sum += grid[i][j];
            }
            if(sum != targetsum) {
                return false;
            }
        }
        // column
        for (int j = y; j <= ey; j++) {
            int sum = 0;
            for (int i = x; i <= ex; i++) {
                sum += grid[i][j];
            }
            if (sum != targetsum) return false;
        }
        // diagonal
        if (grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2] != targetsum) {
            return false;
        }
        if (grid[x][y+2] + grid[x+1][y+1] + grid[x+2][y] != targetsum) {
            return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        // distinct numbers from 1 to 9 
        // such that each row, column, and both diagonals all have the same sum.
        int m = grid.size();
        int n = grid[0].size();
        if(m < 3 || n < 3) {
            return 0;
        }
        // i have to extract squares of 3*3 size
        // k = 3
        int count = 0;
        int k = 3;
        for(int i=0; i+k-1 < m; i++) {
            for(int j=0; j+k-1 < n; j++) {
                int ei = i+k-1;
                int ej = j+k-1;
                if(check(i,j,ei,ej,grid)) {
                    count++;
                }
            }
        }
        return count;
    }
};
