class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // Prim's algorithm
        int n = points.size();
        vector<int> visited(n,0);
        // pair<int,int>   {dist, index}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()) {
            auto [d,node] = pq.top();
            pq.pop();
            if(visited[node]) continue;
            visited[node] = 1;
            sum += d;
            for(int i=0; i<n; i++) {
                if(!visited[i]) {
                    int dist = abs(points[i][0] - points[node][0]) + abs(points[i][1] - points[node][1]);
                    pq.push({dist,i});
                }
            }
        }
        return sum;
    }
};