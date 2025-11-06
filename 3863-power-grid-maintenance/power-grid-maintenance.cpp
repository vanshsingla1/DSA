class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        // 1) Build the graph exactly as before
        vector<vector<int>> adj(c+1);
        for (auto& edge : connections) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 2) PRECOMPUTE COMPONENTS with a simple DFS/BFS
        vector<int> comp(c+1, 0);
        int cid = 0;
        queue<int> q;
        for (int i = 1; i <= c; ++i) {
            if (comp[i] == 0) {
                ++cid;
                comp[i] = cid;
                q.push(i);
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    for (int v : adj[u]) {
                        if (comp[v] == 0) {
                            comp[v] = cid;
                            q.push(v);
                        }
                    }
                }
            }
        }

        // 3) For each component, keep a sorted set of its online nodes
        vector<bool> online(c+1, true);
        online[0] = false;  // unused
        vector<set<int>> compOnline(cid+1);
        for (int i = 1; i <= c; ++i) {
            compOnline[comp[i]].insert(i);
        }

        // 4) Process queries exactly in your original style
        vector<int> res;
        res.reserve(queries.size());

        for (auto& query : queries) {
            int type = query[0], node = query[1];
            if (type == 2) {
                // go offline: remove from its component’s set
                if (online[node]) {
                    online[node] = false;
                    compOnline[comp[node]].erase(node);
                }
            }
            else if (type == 1) {
                // query
                if (online[node]) {
                    // itself is online
                    res.push_back(node);
                }
                else {
                    // pick the smallest online in its component
                    auto &st = compOnline[comp[node]];
                    res.push_back(st.empty() ? -1 : *st.begin());
                }
            }
            else {
                // unexpected type
                res.push_back(-1);
            }
        }

        return res;
    }
};
