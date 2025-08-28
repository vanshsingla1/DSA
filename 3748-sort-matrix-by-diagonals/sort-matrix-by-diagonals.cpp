class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        // Jai Mata Di
        // n * n sq matrix
        // level order traversal using queue
        // how to do indexing
        // create visited array
        // when level = n || res.size() == n ---> middle diagonal started
        // start from {0,n-1}
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n,0));
        queue<pair<int,int>> q;
        q.push({0,n-1});
        visited[0][n-1] = 1; // visited
        vector<vector<int>> res(n, vector<int> (n,-1));
        int level = 0;
        // res[0][n-1] = grid[0][n-1];
        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;
            vector<pair<int,int>> p;
            while(size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                p.push_back({x,y});
                temp.push_back(grid[x][y]);
                if(x >= 0 && x < n && y-1 >= 0 && y-1 < n && !visited[x][y-1]) {
                    q.push({x,y-1});
                    // temp.push_back(grid[x][y-1]);
                    visited[x][y-1] = 1;
                }
                if(x+1 >= 0 && x+1 < n && y >= 0 && y < n && !visited[x+1][y]) {
                    q.push({x+1,y});
                    // temp.push_back(grid[x+1][y]);
                    visited[x+1][y] = 1;
                }
            }
            // now push elements in res
            if(level < n-1) {
                // sort in increasing order
                sort(temp.begin(),temp.end());
            }
            else {
                // decreasing order
                sort(temp.begin(),temp.end(),greater<int>());
            }
            for(int i=0; i<p.size(); i++) {
                res[p[i].first][p[i].second] = temp[i];
            }
            level++;
        }
        return res; 
    }
};