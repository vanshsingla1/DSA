class Solution {
public:
    int fun(vector<int> &nums,int target,vector<int> &dp) {
        if(target == 0) {
            return 1;
        }
        if(target < 0) {
            return 0;
        }
        if(dp[target] != -1) {
            return dp[target];
        }
        int res = 0;
        for(auto it : nums) {
            res += fun(nums,target-it,dp);
        }
        return dp[target] = res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        // dp
        int n = nums.size();
        int minn = *min_element(nums.begin(),nums.end());
        if(minn > target) { // edge case
            return 0;
        }
        vector<int> dp(target+1,-1);
        // take or skip wala funda
        return fun(nums,target,dp);
    }
};