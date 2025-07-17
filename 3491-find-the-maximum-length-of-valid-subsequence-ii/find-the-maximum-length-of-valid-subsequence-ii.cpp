class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        //lis variant
        //check 3201 leetcode
        int n = nums.size();
        vector<vector<int>> dp(k,vector<int>(n,1));
        //dp0 for even, 0th row
        //dp1 for odd, 1st row
        int maxx = 1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                int mod = (nums[i]+nums[j]) % k;
                dp[mod][i] = max(dp[mod][i],dp[mod][j]+1); // even will be saved into even, odd will be saved into odd
                maxx = max(maxx,dp[mod][i]);
            }
        }
        return maxx;
    }
};