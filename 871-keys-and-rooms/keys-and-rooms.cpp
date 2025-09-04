class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<int> &visited,int src) {
        visited[src] = 1;
        for(auto next : adj[src]) {
            if(!visited[next]) {
                dfs(adj,visited,next);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n,0);
        // create adj list
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            for(auto edge : rooms[i]) {
                adj[i].push_back(edge);
            }
        }
        // now traverse and perform dfs and mark the visited
        dfs(adj,visited,0);
        // now check if ever edge is visited return true otherwise false
        for(int i=0; i<n; i++) {
            if(visited[i] == 0) {
                return false;
            }
        }
        return true;
    }
};