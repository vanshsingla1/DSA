class Solution {
public:
    bool dfs(vector<vector<int>> &adj, vector<int> &visited, int src, stack<int> &st) {
        visited[src] = 1; // visiting
        for (auto node : adj[src]) {
            if (visited[node] == 0) {
                if (!dfs(adj, visited, node, st)) return false; // cycle detected
            }
            else if (visited[node] == 1) {
                return false; // cycle found
            }
        }
        visited[src] = 2; // fully processed
        st.push(src);
        return true;
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u); // v -> u, since v must come before u
        }

        vector<int> visited(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                if (!dfs(adj, visited, i, st)) {
                    return {};
                }
            }
        }
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
