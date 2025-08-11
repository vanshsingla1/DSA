class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& visited,int i,int j) {
        visited[i][j] = 1;
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        for(int k=0; k<4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx >= 0 && nx<board.size() && ny>=0 && ny<board[0].size() && board[nx][ny] == 'O' && !visited[nx][ny]) {
                dfs(board,visited,nx,ny);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        // now if any 0 is on the boundary then mark it visited = 1 and its adjacent neighours also
        // traverse 1st and last row
        for(int j=0; j<n; j++) {
            if(board[0][j] == 'O' && !visited[0][j]) {
                dfs(board,visited,0,j);
            }
            if(board[m-1][j] == 'O' && !visited[m-1][j]) {
                dfs(board,visited,m-1,j);
            }
        }
        // traverse 1st and last col
        for(int i=0; i<m; i++) {
            if(board[i][0] == 'O' && !visited[i][0]) {
                dfs(board,visited,i,0);
            }
            if(board[i][n-1] == 'O' && !visited[i][n-1]) {
                dfs(board,visited,i,n-1);
            }
        }
        // now traverse all the directions and check if not visited and baord = '0' then board = 'X'
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        } 
    }
};