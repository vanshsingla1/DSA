class Solution {
public:
    bool res = false;
    void fun(int i,int j,int m,int n,vector<vector<bool>> &visited,vector<vector<char>>& board,string word,string temp,int k) {
        if(res) {
            return; // stop early
        }
        if(i >= m || i < 0 || j >= n || j < 0) {
            return ;
        }
        if(visited[i][j] == true) {
            return;
        }
        if(board[i][j] != word[k]) {
            return;
        }
        if(k == word.size()-1) {
            res = true;
            return;
        }
        // traverse in all 4 directions
        visited[i][j] = true;
        fun(i+1,j,m,n,visited,board,word,temp+board[i][j],k+1);
        fun(i,j+1,m,n,visited,board,word,temp+board[i][j],k+1);
        fun(i-1,j,m,n,visited,board,word,temp+board[i][j],k+1);
        fun(i,j-1,m,n,visited,board,word,temp+board[i][j],k+1);

        visited[i][j] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        // we need to generate all combinations -> backtracking
        // mark visited true then mark it as false
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                fun(i, j, m, n, visited, board, word, "",0);
                if(res) {
                    return true;
                }
            }
        }
        return false;
    }
};