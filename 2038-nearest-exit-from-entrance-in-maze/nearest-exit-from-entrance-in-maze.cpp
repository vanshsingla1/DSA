class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        // easy
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, int>> q;
        int count = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = 1;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (visited[nx][ny] || maze[nx][ny] != '.') continue;
                    if (nx == 0 || ny == 0 || nx == m - 1 || ny == n - 1) {
                        return count + 1;
                    }
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            count++;
        }
        return -1;
    }
};