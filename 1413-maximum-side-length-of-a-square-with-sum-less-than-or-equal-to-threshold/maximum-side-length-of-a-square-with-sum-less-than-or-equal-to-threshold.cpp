class Solution {
public:
    int fun(vector<vector<int>>& grid, int j, int i, int top, int bottom,
            int threshold) {
        // check 1st and last column sum and last row , first row also
        int sum = 0;
        // left column
        for (int x = top; x <= bottom; x++) {
            sum += grid[x][j];
            if (sum > threshold)
                return -1;
        }
        // right column
        for (int x = top; x <= bottom; x++) {
            sum += grid[x][i];
            if (sum > threshold)
                return -1;
        }
        // top row
        for (int x = j + 1; x < i; x++) {
            sum += grid[top][x];
            if (sum > threshold)
                return -1;
        }
        // bottom row
        for (int x = j + 1; x < i; x++) {
            sum += grid[bottom][x];
            if (sum > threshold)
                return -1;
        }
        return bottom - top + 1;
    }
    int maxSideLength(vector<vector<int>>& grid, int threshold) {
        int m = grid.size();
        int n = grid[0].size();
        int maxside = 0;
        // only 1x1 square
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] <= threshold) {
                    maxside = 1;
                    break;
                }
            }
        }
        // check row wise sum
        for (int j = 0; j < n; j++) {
            vector<vector<int>> prefix(m,
                                       vector<int>(n, 0)); // j -> whole column
            for (int i = 0; i < m; i++) {
                prefix[i][j] = grid[i][j];
            } // prefix intialization
            // now traverse for further columns
            for (int i = j + 1; i < n; i++) {
                prefix[0][i] = prefix[0][i - 1] + grid[0][i];
                int total = prefix[0][i] - (j > 0 ? prefix[0][j - 1] : 0);
                for (int k = 1; k < m; k++) {
                    int side = i - j + 1;
                    int top = k - side + 1;
                    prefix[k][i] = prefix[k][i - 1] + grid[k][i];
                    
                    total += prefix[k][i] - (j > 0 ? prefix[k][j - 1] : 0);
                    if (top > 0) {
                        total -= prefix[top - 1][i] -(j > 0 ? prefix[top - 1][j - 1] : 0);
                    }
                    if (top < 0) continue;
                    int res = -1;
                    if (total <= threshold) {
                        res = fun(grid, j, i, top, k, threshold);
                    }
                    if (res != -1) {
                        maxside = max(maxside, res);
                    }
                }
            }
        }
        return maxside;
    }
};