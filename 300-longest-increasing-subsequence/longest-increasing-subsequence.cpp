class Solution {
public:
    int LIS(vector<int> &nums,int i,int prev,vector<vector<int>> &dp) {
        if(i >= nums.size())
        return 0;
        if (prev != -1 && dp[i][prev] != -1)
        return dp[i][prev];
        int take = 0;
        //take only, upcomming element is strictly greater than prev
        if(prev == -1 || nums[prev] < nums[i])
        take = 1 + LIS(nums,i+1,i,dp);
        
        int skip = LIS(nums,i+1,prev,dp);
        if(prev != -1)
        dp[i][prev] = max(take,skip);
        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return LIS(nums,0,-1,dp);
    }
};