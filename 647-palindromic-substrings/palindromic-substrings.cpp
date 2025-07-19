class Solution {
public:
    int isPalindrome(string s,int i,int j,vector<vector<int>> &dp) {
        if(i > j) {
            // dp[i][j] = 1;
            return 1;
        }

        if(dp[i][j] != -1)
        return dp[i][j];

        if(s[i] != s[j]) 
        return dp[i][j] = 0;

        else {
            return dp[i][j] = isPalindrome(s,i+1,j-1,dp);
        }
    }
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        vector<vector<int>> dp(n,vector<int>(n,-1)); // 0 false 1 true
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(isPalindrome(s,i,j,dp))
                count++;
            }
        }
        return count;
    }
};