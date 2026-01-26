class Solution {
public:
    bool fun(int a,int b,int c) {
        // check are a,b,c a pythagorean triplet ?
        vector<long long> temp;
        temp.push_back(a);
        temp.push_back(b);
        temp.push_back(c);
        sort(temp.begin(),temp.end());
        if(temp[2]*temp[2] == temp[0]*temp[0] + temp[1]*temp[1]) return true;
        return false;
    }
    void dfs(vector<vector<int>> &adj,int src,int d,vector<int> &dist,vector<bool> &visited) {
        visited[src] = true;
        for(auto nextnode : adj[src]) {
            if(!visited[nextnode]) {
                dist[nextnode] = d + 1;
                dfs(adj,nextnode,d+1,dist,visited);
            }
        }
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        // run dfs from each node x,y,z to all the nodes and calculate the distances
        // then check the pythagorean triplet is valid or not
        // initially make adj list
        vector<vector<int>> adj(n);
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // dfs call from x as a root
        vector<int> dx(n,0);
        vector<bool> visited_x(n,false);
        dx[x] = 0;
        visited_x[x] = true;
        dfs(adj,x,0,dx,visited_x);
        // dfs call from y as a root
        vector<int> dy(n,0);
        vector<bool> visited_y(n,false);
        dy[y] = 0;
        visited_y[y] = true;
        dfs(adj,y,0,dy,visited_y);
        // dfs call from x as a root
        vector<int> dz(n,0);
        vector<bool> visited_z(n,false);
        dz[z] = 0;
        visited_z[z] = true;
        dfs(adj,z,0,dz,visited_z);

        // now count the no. of pythagorean triplets
        int count = 0;
        for(int i=0; i<n; i++) {
            if(fun(dx[i],dy[i],dz[i])) {
                count++;
            }
        }
        return count;
    }
};