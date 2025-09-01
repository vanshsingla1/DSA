class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // whole game is to assign the numbers
        // 0 -> 2 - 2 ( how many edges)
        // 1 -> 3 - 4
        // 2 -> 4 - 5
        // 3 -> 2 - 3
        // 4 -> 1 - 1 in the first test case assign the max number to the node which has maximum edges
        vector<int> degree(n,0);
        for(auto edge : roads) {
            int u = edge[0];
            int v = edge[1];
            degree[u]++;
            degree[v]++;
        }
        // assign the highest number to highest degree
        vector<pair<long long, int>> nodes;
        for (int i = 0; i < n; i++) {
            nodes.push_back({degree[i], i});
        }
        sort(nodes.begin(), nodes.end());
        // assign the value
        vector<long long> value(n, 0);
        long long assign = 1;
        for (auto &p : nodes) {
            value[p.second] = assign++;
        }
        // calculate total importance
        long long total = 0;
        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            total += value[u] + value[v];
        }
        return total;
    }
};