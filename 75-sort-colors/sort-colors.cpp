class Solution {
public:
    void sortColors(vector<int>& nums) {
        // most optimal approach
        int i = 0;
        int j = 0;
        int k = nums.size()-1;
        while(j <= k) {
            if(nums[j] == 2) {
                swap(nums[j],nums[k]);
                k--;
            }
            else if(nums[j] == 0) {
                swap(nums[j],nums[i]);
                i++; j++;
            }
            else {
                // nums[j] == 1
                j++;
            }
        }
    }
};