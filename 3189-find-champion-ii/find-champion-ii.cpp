class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // if there is only one node having indegree == 0 then ans is the index of element
        // but if there more than one nodes whose indegree == 0 then ans is -1
        vector<int> indegree(n,0);
        // create adj list
        vector<vector<int>> adj(n);
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        // calculate the indegree
        for(int i=0; i<n; i++) {
            for(int v : adj[i]) {
                indegree[v]++;
            }
        }
        int count = 0;
        int index = 0;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                count++;
                index = i;
            }
        }
        if(count == 1) {
            return index;
        }
        else {
            return -1;
        }
    }
};