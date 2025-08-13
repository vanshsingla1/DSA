class Solution {
public:
    bool topoSort(int V, vector<vector<int>>& edges) {
        queue<int>q;
        vector<int>indegree(V,0);
        vector<vector<int>>adj(V);
        int count = 0;
        //converted it into adj list
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if(u == v) // self loop ->cycle
            return true;
            adj[v].push_back(u);
        }
        //calculate indegree of each element
        for(int i=0; i<V; i++) {
            for(auto v : adj[i]) {
                indegree[v]++;
            }
        }
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0)
            q.push(i);
        }
        //BFS
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            count++;
            for(auto v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0)
                q.push(v);
            }
        }
        return count != V; // return true if there's a cycle
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        bool resp = topoSort(numCourses,prerequisites);
        if(resp == false)
        return true;
        else
        return false;
    }
};