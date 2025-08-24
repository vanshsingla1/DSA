class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // o(n)
        // silidng window?
        // we have to delete 0 only as we want maximum 1's
        int n = nums.size();
        int left = 0;
        int right = 0;
        bool flag = false;
        int count = 0;
        int maxCount = 0;
        bool allone = true;
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                allone = false;
            }
        }
        if(allone == true) {
            return nums.size()-1;
        }
        while(left < n) {
            if(right < n && nums[right] == 1) {
                while(right < n && nums[right] == 1) {
                    right++;
                    count++;
                    maxCount = max(maxCount,count);
                }
            }
            else {
                if(flag == false) {
                    // can skip the zero
                    left = right+1;
                    right++;
                    flag = true;
                }
                else {
                    // reset the previous zero
                    right = left;
                    count = 0;
                    flag = false;
                }
            }
        }
        return maxCount;
    }
};