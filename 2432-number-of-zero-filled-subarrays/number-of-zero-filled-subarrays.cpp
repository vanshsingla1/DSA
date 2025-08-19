class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // sliding window - O(n)
        int n = nums.size();
        int left = 0;
        int right = 0;
        long long count = 0;
        
        while(left < n) {
            if(nums[left] == 0) {
                right = left;
                while(right < n && nums[right] == 0) {
                    right++;
                }
                long long windowSize = right - left;
                count += (windowSize * (windowSize + 1)) / 2;
                left = right; 
            } else {
                left++;
            }
        }
        return count;
    }
};