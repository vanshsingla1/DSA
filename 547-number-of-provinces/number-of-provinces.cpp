class Solution {
public:
    void bfs(vector<vector<int>> &adj,vector<int> &visited,int src) {
        visited[src] = 1;
        queue<int> q;
        q.push(src);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto edge : adj[node]) {
                if(!visited[edge]) {
                    q.push(edge);
                    visited[edge] = 1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // convert 2d vector into adj list
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1 && (i != j)) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(n,0);
        int count = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                bfs(adj,visited,i);
                count++;
            }
        }
        return count;
    }
};