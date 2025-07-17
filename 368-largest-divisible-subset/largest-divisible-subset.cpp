class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
        return {};
        sort(nums.begin(),nums.end());
        vector<set<int>> dp(n);
        int idx = 0;
        int count = 0;
        for(int i=0; i<n; i++) {
            dp[i].insert(nums[i]);
            for(int j=0; j<i; j++) {
                if(nums[i] % nums[j] == 0 && dp[j].size() + 1 > dp[i].size()) {
                    dp[i] = dp[j];
                    dp[i].insert(nums[i]);
                }
            }
            if(dp[i].size() > count) {
                count = dp[i].size();
                idx = i;
            } 
        }
        //now return the idx vector
        return vector<int>(dp[idx].begin(),dp[idx].end());
    }
};