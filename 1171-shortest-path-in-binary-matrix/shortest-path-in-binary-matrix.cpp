class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // shortest path -> dijkstra 
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;
        vector<vector<int>> dist(m,vector<int> (n,INT_MAX));
        dist[0][0] = 0;
        vector<int> dx = {-1,1,0,0,1,1,-1,-1};
        vector<int> dy = {0,0,1,-1,1,-1,1,-1};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        // pair<int,pair<int,int>> p
        pq.push({0,{0,0}}); // dist x y
        while(!pq.empty()) {
            int d = pq.top().first;
            pair<int,int> node = pq.top().second;
            int x = node.first;
            int y = node.second;
            pq.pop();
            // if(d > dist[x][y]) continue;
            for(int i=0; i<8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    if(dist[nx][ny] > d+1) {
                        pq.push({d+1,{nx,ny}});
                    dist[nx][ny] = d+1;
                    }
                }
            }
        }
        return dist[m-1][n-1] == INT_MAX ? -1 : dist[m-1][n-1] + 1;
    }
};