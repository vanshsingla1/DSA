class Solution {
public:
    int dorob(vector<int>& nums) {
        // Bottom - up
        int n = nums.size();
        
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n,-1);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2; i<n; i++) {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        //using bottom-up
        if(nums.size() == 1)
        return nums[0];
        vector<int> nums1;
        vector<int> nums2;
        for(int i=0; i<nums.size(); i++) {
            if(i != 0)
            nums1.push_back(nums[i]);
            if(i != nums.size()-1)
            nums2.push_back(nums[i]);
        }
        int res1 = dorob(nums1);
        int res2 = dorob(nums2);
        return max(res1,res2);
    }
};