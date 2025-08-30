class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // DAG
        // where indegree == 0, store in the res vector
        vector<int> res;
        // create an adj list
        vector<vector<int>> adj(n);
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            // adj[v].push_back(u); DAG
        }
        vector<int> indegree(n,0);
        for(int i=0; i<n; i++) {
            for(auto v : adj[i]) {
                indegree[v]++;
            }
        }
        // now store the index which has indegree == 0
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                res.push_back(i);
            } 
        }
        return res;
    }
};