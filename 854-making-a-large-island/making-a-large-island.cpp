class Solution {
public:
    int find(int i, vector<int> &parent) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i], parent);
    }

    void dounion(int x, int y, vector<int> &parent, vector<int> &rank, vector<int> &size) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);
        if (x_parent == y_parent) {
            return;
        }
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        }
        else if (rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
        else {
            // both ranks are equal
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
            rank[y_parent]++;
        }
    }

    void dfs(vector<vector<int>>& grid, vector<int> &parent, vector<int> &rank, vector<int> &size,
             int i, int j, vector<vector<int>> &visited) {
        visited[i][j] = 1;
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        int n = grid.size();
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                // union krdo
                int x = i * n + j;
                int y = nx * n + ny;
                int x_parent = find(x, parent);
                int y_parent = find(y, parent);
                if (x_parent != y_parent) {
                    dounion(x, y, parent, rank, size);
                }
                if (!visited[nx][ny]) {
                    dfs(grid, parent, rank, size, nx, ny, visited);
                }
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        // dfs + dsu
        // make groups (dsu by size)w
        int n = grid.size();            // matrix is n x n
        int total = n * n;
        // vector<int> index(size,0);
        vector<int> parent(total, 0);
        vector<int> rank(total, 0);
        vector<int> size(total, 1);
        vector<vector<int>> visited(n, vector<int>(n, 0));
        for (int i = 0; i < total; i++) {
            parent[i] = i;
            // index[i] = i;
        }
        // 2d index into single index as (i*n+j)
        // now create groups of all ones which are connected as an island
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // this cell is not being added into the group of 1's
                if (grid[i][j] == 1 && !visited[i][j]) {
                    dfs(grid, parent, rank, size, i, j, visited);
                }
            }
        }

        // If no zero exists, the largest island is whole grid
        bool hasZero = false;
        for (int i = 0; i < n && !hasZero; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0) { hasZero = true; break; }
        if (!hasZero) return total;

        // now move to zeros 
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        
        
        int maxsize = 0;
        int count = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = i * n + j;
                if (grid[i][j] == 0) {
                    unordered_set<int> st;
                    count = 1; 
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                            int y = nx * n + ny;
                            int y_parent = find(y, parent);
                            if (!st.count(y_parent)) {
                                count += size[y_parent];
                                st.insert(y_parent);
                            }
                        }
                    }
                    maxsize = max(maxsize, count);
                }
            }
        }
        return maxsize;
    }
};
