class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        queue<int>q;
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        for(auto edge : relations) {
            int u  = edge[0]-1;
            int v = edge[1]-1;
            adj[u].push_back(v);
        }
        for(int i=0; i<n; i++) {
            for(auto v : adj[i]) {
                indegree[v]++;
            }
        }
        int maxTime = INT_MIN;
        vector<int> finish(n,0);
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                finish[i] = time[i];
            }
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            maxTime = max(maxTime,finish[u]);
            for(auto v : adj[u]) {
                indegree[v]--;
                finish[v] = max(finish[v],time[v]+finish[u]);
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return maxTime;
    }
};