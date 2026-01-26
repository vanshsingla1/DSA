class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        // no sliding window, start from back
        int n = nums.size();
        for(int i=n-1; i>=1; i--) {
            if(nums[i-1] >= nums[i]) {
                return i;
            }
        }
        return 0;
    }
};