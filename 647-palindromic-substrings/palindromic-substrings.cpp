class Solution {
public:
    
    int countSubstrings(string s) {
        //bottom up
        int n = s.length();
        int count = 0;
        vector<vector<bool>> dp(n,vector<bool>(n,false)); 
        for(int len=1; len<=n; len++) {
            for(int i=0; i+len-1<n; i++) {
                int j = i+len-1;
                if(i == j)
                dp[i][j] = true;// stings of length 1
                else if(i+1 == j) {
                    if(s[i] == s[j])
                    dp[i][j] = true; // strings of length 2
                    else
                    dp[i][j] = false;
                }
                else {
                    if(s[i] == s[j] && dp[i+1][j-1])
                    dp[i][j] = true;
                    else
                    dp[i][j] = false;
                }
                if(dp[i][j])
                count++;
            }
        }
        return count;
    }
};