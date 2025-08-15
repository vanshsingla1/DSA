class Solution {
public:
    bool dfs(vector<vector<int>> &adj,vector<int> &color,int currcolor,int src) {
        color[src] = currcolor;
        for(auto node : adj[src]) {
            if(color[node] == color[src])
            return false;
            if(color[node] == -1) {
                if(!dfs(adj,color,1-currcolor,node))
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // adj list bnao
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
            }
        }
        // color vector bnao
        int currcolor = 0;
        vector<int> color(n,-1);
        for(int i=0; i<n; i++) {
            if(color[i] == -1) {
                if(!dfs(adj,color,currcolor,i))
                return false;
            }
        }
        return true;
    }
};