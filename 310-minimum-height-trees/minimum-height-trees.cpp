class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        if(n == 2) return {0,1};
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        // do bfs traversal, start from leaf nodes and reach till the circle's center
        // at most 2 leaf nodes can be present
        queue<int> q;
        for(int i=0; i<n; i++) {
            // push the leaf nodes whose indegree = 1
            if(indegree[i] == 1) {
                q.push(i);
            }
        }
        while(n > 2) {
            int size = q.size();
            n -= size;
            for(int i=0; i<size; i++) {
                int node = q.front(); q.pop();
                for(auto &next : adj[node]) {
                    indegree[next]--;
                    if(indegree[next] == 1) {
                        q.push(next);
                    }
                }
            }
        }
        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};