class Solution {
public:
    void dfs(vector<vector<pair<int,int>>> &adj, vector<int> &visited, int src, int &minn) {
        visited[src] = 1;
        for(auto p : adj[src]) {
            int node = p.first;
            int wt = p.second;
            minn = min(wt,minn);
            if(!visited[node]) {
                dfs(adj,visited,node,minn);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        // dijkstra - NOT APPLICABLE
        // create a vector which stores the result of the weight of edges though which src can reach des
        // then find the smallest among them
        // DFS OR BFS
        // create adj list
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge : roads) {
            int u = edge[0]-1;
            int v = edge[1]-1;
            int wt = edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        int minn = INT_MAX;
        vector<int> visited(n,0);
        dfs(adj,visited,0,minn);
        return minn;
    }
};