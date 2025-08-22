class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i = 0;
        int j = m - 1;
        while (i <= j) {
            bool flag1 = false;
            bool flag2 = false;
            for (int k = 0; k < n; k++) {
                if (grid[i][k] == 1) {
                    flag1 = true;
                    break;
                }
            }
            for (int k = 0; k < n; k++) {
                if (grid[j][k] == 1) {
                    flag2 = true;
                    break;
                }
            }

            if (flag1 && flag2)
                break;
            if (!flag1)
                i++;
            if (!flag2)
                j--;
        }

        if (i > j)
            return 0;

        int maxHeight = j - i + 1;

        
        i = 0;
        j = n - 1;
        while (i <= j) {
            bool flag1 = false;
            bool flag2 = false;
            for (int k = 0; k < m; k++) {
                if (grid[k][i] == 1) {
                    flag1 = true;
                    break;
                }
            }
            for (int k = 0; k < m; k++) {
                if (grid[k][j] == 1) {
                    flag2 = true;
                    break;
                }
            }

            if (flag1 && flag2)
                break;
            if (!flag1)
                i++;
            if (!flag2)
                j--;
        }

        if (i > j)
            return 0;

        int maxWeight = j - i + 1;
        return maxHeight * maxWeight;
    }
};
