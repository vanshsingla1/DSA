class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int> &visited,vector<vector<int>>& res,vector<int> &path,int src,int des) {
        visited[src] = 1;
        path.push_back(src);
        if(src == des) {
            res.push_back(path);
            visited[src] = 0;
            path.pop_back();
            return;
        }
        for(auto node : adj[src]) {
            if(!visited[node]) {
                dfs(adj,visited,res,path,node,des);
            }
        }
        visited[src] = 0;
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // backtrackg + dfs -> constraints are very small -> yes backtracking is possible
        // create adj list
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            for(auto v : graph[i]) {
                adj[i].push_back(v);
            }
        }
        // adj list is created, now backtrack it
        vector<int> visited(n,0);
        vector<vector<int>> res;
        vector<int> path;
        dfs(adj,visited,res,path,0,n-1);
        return res;
    }
};