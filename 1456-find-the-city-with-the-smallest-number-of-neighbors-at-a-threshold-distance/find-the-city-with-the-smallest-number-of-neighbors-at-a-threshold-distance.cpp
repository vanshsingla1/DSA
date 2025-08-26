class Solution {
public:
    int dijkstra(vector<vector<pair<int,int>>> &adj,int src,int threshold,int n) {
        // dijkstra
        vector<int> res(n,INT_MAX);
        res[src] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        while(!pq.empty()) {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            for(auto next : adj[node]) {
                int dist = next.second;
                int nextnode = next.first;
                if(d + dist < res[nextnode]) {
                    res[nextnode] = d + dist;
                    pq.push({d+dist,nextnode});
                }
            }
        }
        int count = 0;
        for(int i=0; i<n; i++) {
            if(i != src && res[i] <= threshold) {
                count++;
            }
        }
        return count;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // dfs nhi lga skde, because i need shortest path, by choosing dfs, i can
        // miss the shorter paths which i needs to explore
        // so apply dijkstra algorithm
        // create adj list
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int> res(n);
        for(int i=0; i<n; i++) {
            res[i] = dijkstra(adj,i,distanceThreshold,n);
        }
        // find the greatest node which contains smallest value
        int smallest = res[0];
        int node = -1;
        for(int i=0; i<n; i++) {
            if(smallest >= res[i]) {
                smallest = res[i];
                node = i;
            }
        }
        return node;
    }
};