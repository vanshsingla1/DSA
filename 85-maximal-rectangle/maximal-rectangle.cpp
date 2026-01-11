class Solution {
public:
    int maximalRectangle(vector<vector<char>>& grid) {
        // visit again
        // visit again
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> matrix(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = grid[i][j] - '0';
            }
        }

        int res = 0;
        vector<int> prev = matrix[0];
        for (int i = 0; i < rows; i++) {
            if (i > 0) {
                for (int j = 0; j < cols; j++) {
                    if (matrix[i][j] == 1)
                        prev[j]++;
                    else
                        prev[j] = 0;
                }
            }
            vector<int> temp = prev;
            stack<int> stk;
            int n = temp.size();

            vector<int> NSR(n); // next shortest right
            vector<int> NSL(n); // next shortest left

            for (int k = n - 1; k >= 0; k--) {
                while (!stk.empty() && temp[stk.top()] >= temp[k]) {
                    stk.pop();
                }
                if (!stk.empty()) {
                    NSR[k] = stk.top();
                } else {
                    NSR[k] = n;
                }
                stk.push(k);
            }
            while(!stk.empty()) stk.pop();
            for (int k = 0; k < n; k++) {
                while (!stk.empty() && temp[stk.top()] >= temp[k]) {
                    stk.pop();
                }
                if (!stk.empty()) {
                    NSL[k] = stk.top();
                } else {
                    NSL[k] = -1;
                }
                stk.push(k);
            }
            for(int j=0; j<cols; j++){
                res = max(res, (NSR[j]-NSL[j]-1) * prev[j]);
            }
        }
        return res;
    }
};