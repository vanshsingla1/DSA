class Solution {
public:
    int fun(int i,int rem ,vector<int> &nums,vector<vector<int>> &dp) {
        if(i >= nums.size()) {
            if(rem == 0) {
                return 0;
            }
            else {
                return INT_MIN;
            }
        }
        if(dp[i][rem] != -1) {
            return dp[i][rem];
        }
        int take = nums[i] + fun(i+1,(rem+nums[i])%3,nums,dp);
        int skip = fun(i+1,(rem),nums,dp);

        return dp[i][rem] = max(take, skip);
    }
    int maxSumDivThree(vector<int>& nums) {
        // dp
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3,-1));
        return fun(0,0,nums,dp);
    }
};