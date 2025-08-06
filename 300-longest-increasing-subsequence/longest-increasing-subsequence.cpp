class Solution {
public:
    int fun(vector<int>& nums, int n, int i, int prev,vector<vector<int>> &dp) {
        if (i >= n)
            return 0;
        if (prev != -1 && dp[i][prev] != -1)
        return dp[i][prev];
        int take = 0;
        int skip = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + fun(nums, n, i + 1, i,dp);
        }
        // skip
        skip = fun(nums, n, i + 1, prev,dp);
        if(prev != -1)
        dp[i][prev] = max(take,skip);
        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        // recursion
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return fun(nums, n, 0, -1,dp);
    }
};