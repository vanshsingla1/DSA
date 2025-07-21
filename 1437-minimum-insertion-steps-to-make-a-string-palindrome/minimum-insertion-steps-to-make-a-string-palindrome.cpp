class Solution {
public:
    int minInsertions(string s) {
        //bottom up
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int len=2; len<=n; len++) {
            for(int i=0; i+len-1<n; i++) {
                int j = i+len-1;
                if(s[i] == s[j])
                dp[i][j] = dp[i+1][j-1];
                else
                dp[i][j] = 1+min(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};