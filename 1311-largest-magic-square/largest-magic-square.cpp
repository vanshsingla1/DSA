class Solution {
public:
    bool valid(vector<vector<int>>& grid, int j, int i, int count,int top,int bottom) {
        // check for column sum and both diagonals
        vector<int> colsum(i-j+1,0);
        int idx = 0;
        for(int x = j; x <= i; x++) {
            // check for col sum
            int sum = 0;
            for(int y = top; y <= bottom; y++) {
                sum += grid[y][x];
            }
            colsum[idx] = sum;
            idx++;
        }
        for(int k=1; k<colsum.size(); k++) {
            if(colsum[k-1] != colsum[k])
            return false;
        }
        int rowSum = 0;
    for (int x = j; x <= i; x++)
        rowSum += grid[top][x];

    if (colsum[0] != rowSum)
        return false;
        // check for diagonals
        int diagonal1 = 0, diagonal2 = 0;
        int r = top, c1 = j, c2 = i;

        for (int k = 0; k < count; k++) {
            diagonal1 += grid[r][c1];
            diagonal2 += grid[r][c2];
            r++;
            c1++;
            c2--;
        }
        if (diagonal1 != rowSum)
        return false;
        
        return diagonal1 == diagonal2;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        // time consuming
        int m = grid.size();
        int n = grid[0].size();
        int side = 1;
        // check row wise sum
        for(int j=0; j<n; j++){
            vector<vector<int>> prefix(m, vector<int> (n,0)); // j -> whole column
            for(int i=0; i<m; i++) {
                prefix[i][j] = grid[i][j];
            } // prefix intialization
            // now traverse for further columns
            for(int i=j+1; i<n; i++) {
                int count = 0;
                prefix[0][i] = prefix[0][i-1] + grid[0][i];
                for(int k=1; k<m; k++) {
                    prefix[k][i] = prefix[k][i-1] + grid[k][i];
                    if(prefix[k][i] == prefix[k-1][i])
                    count++;
                    else
                    count = 0;
                    if(count == i-j && (k-count) >= 0) {
                        // check is it a valid sq 
                        if(valid(grid,j,i,count+1,k-count,k)) {
                            side = max(side,count+1);
                        }
                    }
                }
            }
        }
        return side;
    }
};