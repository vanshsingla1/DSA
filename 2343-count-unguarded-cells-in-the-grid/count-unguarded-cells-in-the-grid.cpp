class Solution {
public:
    void fun(int i,int j,vector<vector<int>> &visited,char d) {
        if(i < 0 || i >= visited.size() || j < 0 || j >= visited[i].size() || visited[i][j] == 1 || visited[i][j] == 2) {
            return;
        }
        visited[i][j] = 3;
        if(d == 'U') {
            fun(i-1,j,visited,'U');
        }
        if(d == 'D') {
            fun(i+1,j,visited,'D');
        }
        if(d == 'L') {
            fun(i,j-1,visited,'L');
        }
        if(d == 'R') {
            fun(i,j+1,visited,'R');
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> visited(m, vector<int> (n,0));
        // mark 1 -> guards
        // mark 2 -> walls
        // mark 3 -> guarded/ rechable
        for(auto guard : guards) { // fill guards position
            visited[guard[0]][guard[1]] = 1;
        }
        // mark walls position
        for(auto wall : walls) {
            visited[wall[0]][wall[1]] = 2;
        }
        // now traverse in all the 4 directions
        for(auto guard : guards) {
            fun(guard[0]-1,guard[1],visited,'U');
            fun(guard[0]+1,guard[1],visited,'D');
            fun(guard[0],guard[1]-1,visited,'L');
            fun(guard[0],guard[1]+1,visited,'R');
        }
        int count = 0;
        // now count the reqd ans
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(visited[i][j] == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};