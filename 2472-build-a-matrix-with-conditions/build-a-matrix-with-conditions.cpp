class Solution {
public:
    bool dfs(vector<vector<int>> &adj,vector<int> &visited,int src,stack<int> &st) {
        visited[src] = 1;
        for(auto node : adj[src]) {
            if (visited[node] == 1) return false; // cycle found
            if(!visited[node]) {
                if(!dfs(adj,visited,node,st)) {
                    return false;
                }
            }
        }
        visited[src] = 2;
        st.push(src);
        return true;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> grid(k,vector<int> (k,0));
        
        vector<vector<int>> adj1(k);
        vector<vector<int>> adj2(k);

        vector<int> visited1(k,0);
        vector<int> visited2(k,0);

        for(auto edge : rowConditions) {
            int u = edge[0]-1;
            int v = edge[1]-1;
            adj1[u].push_back(v);
        }
        for(auto edge : colConditions) {
            int u = edge[0]-1;
            int v = edge[1]-1;
            adj2[u].push_back(v);
        }
        // now perform topological sort
        stack<int> st1;
        stack<int> st2;
        vector<int> res1;
        vector<int> res2;

        for(int i=0; i<k; i++) {
            if(!visited1[i]) {
                if(!dfs(adj1,visited1,i,st1)) {
                    return {};
                }
            }
        }
        for(int i=0; i<k; i++) {
            if(!visited2[i]) {
                if(!dfs(adj2,visited2,i,st2)) {
                    return {};
                }
            }
        }
        // push the values into vector from stack
        while(!st1.empty()) {
            res1.push_back(st1.top());
            st1.pop();
        }
        while(!st2.empty()) {
            res2.push_back(st2.top());
            st2.pop();
        }
        // fill the grid
        for(int i=0; i<k; i++) {
            for(int j=0; j<k; j++) {
                if(res1[i] == res2[j]) {
                    grid[i][j] = res1[i]+1;
                }
            }
        }
        return grid;
    }
};