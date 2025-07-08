class Solution {
public:
    typedef long long ll;
    long long maxAlternatingSum(vector<int>& nums) {
        //PLZ EXPLORE IT ONCE, DIDNT'T UNDERSTOOD TOO MUCH
        int n = nums.size();
        vector<vector<ll>> dp(n+1,vector<ll> (2,0));
        //even - 0, odd - 1
        for(int i=1; i<n+1; i++) {
            //even
            dp[i][0] = max(dp[i-1][1]-nums[i-1],dp[i-1][0]);
            //odd
            dp[i][1] = max(dp[i-1][0]+nums[i-1],dp[i-1][1]);
        }
        return max(dp[n][0],dp[n][1]);
    }
};