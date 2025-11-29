class Solution {
public:
    long long dfs(int src, vector<int>& visited, vector<int>& values, int k, vector<vector<int>>& adj, int& count) {
        if (visited[src] == 1) {
            return 0;
        }
        visited[src] = 1;
        long long sum = 0;
        for (auto node : adj[src]) {
            sum += dfs(node, visited, values, k, adj, count);
        }
        sum += values[src];
        if (sum % k == 0) {
            count++;
            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        // dfs
        // if one component is divisible then other is also divisible by k
        // create adj list
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // now take 0 as root node as do dfs
        int count = 0;
        vector<int> visited(n, 0);
        dfs(0, visited, values, k, adj, count);
        return count;
    }
};