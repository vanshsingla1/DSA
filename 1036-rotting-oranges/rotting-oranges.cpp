class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // my code only, some corrections from chatGPT
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    visited[i][j] = 1;
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0; // no fresh oranges -> 0 minutes

        int minutes = 0;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        // BFS level-by-level; each level = 1 minute
        while (!q.empty()) {
            int sz = q.size();
            bool infectedThisLevel = false;
            for (int t = 0; t < sz; t++) {
                auto [x, y] = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n
                        && !visited[nx][ny] && grid[nx][ny] == 1) {
                        visited[nx][ny] = 1;
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                        infectedThisLevel = true;
                    }
                }
            }
            if (infectedThisLevel) minutes++;
        }

        return (fresh == 0) ? minutes : -1;
    }
};
