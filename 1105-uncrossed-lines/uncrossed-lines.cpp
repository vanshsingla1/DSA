class Solution {
public:
    int longestCommonSubsequence(const vector<int>& a, const vector<int>& b) {
        int m = a.size(), n = b.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // top down approach - Memoized
        for (int i = 1; i <= m; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        return longestCommonSubsequence(nums1,nums2);
    }
};