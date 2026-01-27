class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});  // added reversed edges for each node
        }
        // dijkstra algorithm
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int >>> pq;  
        vector<int> dist(n,INT_MAX);
        dist[0] = 0;
        pq.push({0,0}); // {dist node}
        while(!pq.empty()) {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if(d > dist[node]) continue;
            for(auto next : adj[node]) {
                int nextnode = next.first;
                int w = next.second;
                if(d + w < dist[nextnode]) {
                    dist[nextnode] = d + w;
                    pq.push({d+w,nextnode});
                }
            }
        }
        if(dist[n-1] != INT_MAX) return dist[n-1];
        else return -1;
    }
};