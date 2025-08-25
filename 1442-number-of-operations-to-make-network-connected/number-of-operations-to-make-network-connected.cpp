class Solution {
public:
    int find(int i,vector<int> &parent) {
        if(i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i],parent);
    }
    void dounion(int x,int y,vector<int> &parent,vector<int> &rank) {
        int x_parent = find(x,parent);
        int y_parent = find(y,parent);
        if(x_parent == y_parent) {
            return;
        }
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if(rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            // both ranks are equal
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        // dsu or can be done by dfs
        if(connections.size() < n-1) {
            return -1;
        }
        vector<int> parent(n,0);
        vector<int> rank(n,0);
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
        for(auto edge : connections) {
            int u = edge[0];
            int v = edge[1];
            dounion(u,v,parent,rank);
        }
        int count = 0;
        for(int i=0; i<n; i++) {
            if(i == parent[i]) {
                count++;
            }
        }
        return count-1;
    }
};