class Solution {
public:
    const int MOD = 1e9+7;
    bool check(string &row0, string &row1) {
        for(int k=0; k<3; k++) {
            if(row0[k] == row1[k]) return false;
        }
        return true;
    }
    int fun(int n,int i,vector<string> &rows,vector<vector<int>> &dp) {
        if(n == 0) return 1;
        if(dp[n][i] != -1) return dp[n][i];
        int res = 0;
        for(int j=0; j<12; j++) {
            if(i != j) {
                if(check(rows[i],rows[j])) {
                    res = (res + fun(n-1,j,rows,dp))%MOD;
                }
            }
        }
        return dp[n][i] = res;
    }
    int numOfWays(int n) {
        vector<string> rows = {"RGR","RGB","RBG","RBR","GRB","GRG","GBR","GBG","BRG","BRB","BGR","BGB"};
        int res = 0;
        vector<vector<int>> dp(n+1, vector<int> (12,-1));
        for(int i=0; i<12; i++) {
            res = (res + fun(n-1,i,rows,dp))%MOD; // we already picked 1 row, we want result for n-1 rows
        }
        return res;
    }
};