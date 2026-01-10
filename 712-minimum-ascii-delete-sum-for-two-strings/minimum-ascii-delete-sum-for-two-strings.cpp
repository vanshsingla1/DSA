class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // use bottom up dp to avoid MLE
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m+1, vector<int> (n+1,0));
        for(int i=m-1; i >= 0; i--) {
            for(int j=n-1; j >= 0; j--) {
                if(s1[i] == s2[j]) {
                    dp[i][j] = s1[i] + dp[i+1][j+1];
                }
                else {
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        int ascii1 = 0, ascii2 = 0;
        for(char c : s1) ascii1 += c;
        for(char c : s2) ascii2 += c;
        return (ascii1 + ascii2 - 2*dp[0][0]);
    }
};