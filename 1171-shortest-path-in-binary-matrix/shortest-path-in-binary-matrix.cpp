class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0] != 0 || grid[m-1][n-1] != 0) 
        return -1;
        // 8 directionoally
        vector<int> dx = {-1,1,0,0,1,1,-1,-1};
        vector<int> dy = {0,0,-1,1,1,-1,-1,1}; // all 8 directions are covered
        // tuple<int,int,int>
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({1,0,0});
        grid[0][0] = 1;
        while(!pq.empty()) {
            auto [dist,x,y] = pq.top();
            pq.pop();
            if(x == m-1 && y == n-1) {
                return dist;
            }
            for(int i=0; i<8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    grid[nx][ny] = dist+1;
                    pq.push({dist+1,nx,ny});
                }
            }
        }
        return -1;
    }
};