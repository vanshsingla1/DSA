class Solution {
public:
    void fun(vector<vector<int>>& image, int i, int j, int color,
             vector<vector<int>>& visited,int prevcolor) {
        visited[i][j] = 1; // visited
        image[i][j] = color;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx >= 0 && nx < image.size() && ny >= 0 &&
                ny < image[0].size() && !visited[nx][ny] && image[nx][ny] == prevcolor) {
                fun(image, nx, ny, color, visited, prevcolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int prevcolor = image[sr][sc];
        fun(image, sr, sc, color, visited,prevcolor);
        return image;
    }
};