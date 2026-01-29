class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // perform  Floyd-Warshall algorithm , precompute all the minimum distances reqd
        const long long INF = 1e18;
        vector<vector<long long>> dist(26,vector<long long> (26,INF));
        // initialization
        for(int i=0; i<26; i++) {
            dist[i][i] = 0;
        }
        int n = original.size();
        for(int i=0; i<n; i++) {
            int u = original[i]-'a';
            int v = changed[i]-'a';
            dist[u][v] = min(dist[u][v],(long long)cost[i]);
        }
        // apply floyd warshall
        for(int k=0; k<26; k++) {
            for(int i=0; i<26; i++) {
                for(int j=0; j<26; j++) {
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
        // transition from source to target
        long long minCost = 0;
        for(int i=0; i<source.length(); i++) {
            int u = source[i]-'a';
            int v = target[i]-'a';
            if(u == v) continue;
            if(dist[u][v] == INF) return -1;
            minCost += dist[u][v];
        }
        return minCost;
    }
};