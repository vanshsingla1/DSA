class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        // O(N) time complexity
        if (mat.empty() || mat[0].empty()) 
        return res;

        int x = 0;
        int y = 0;
        int count = 0;
        int m = mat.size();
        int n = mat[0].size();
        int size = m * n;
        bool flag = true;
        // when boundary condition , increement in column
        // from top to bottom x++, y--
        // from bottom to top x--, y++
        // or use flag or level order traversal

        while (count < size) {
            res.push_back(mat[x][y]);
            count++;

            if (flag) {
                if (y == n - 1) {
                    x++;
                    flag = false;
                } else if (x == 0) {
                    y++;
                    flag = false;
                } else {
                    x--;
                    y++;
                }
            } else {
                if (x == m - 1) {
                    y++;
                    flag = true;
                } else if (y == 0) {
                    x++;
                    flag = true;
                } else {
                    x++;
                    y--;
                }
            }
        }
        return res;
    }
};
