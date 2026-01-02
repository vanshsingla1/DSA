class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] == nums[1]) {
            return nums[0];
        }
        if(nums[0] == nums[2] || nums[1] == nums[2]) {
            return nums[2];
        }
        // moore voting 
        int count = 1;
        int element = nums[3];
        for(int i=4; i<nums.size(); i++) {
            if(count == 0) {
                count++;
                element = nums[i];
            }
            else if(nums[i] != element) {
                count--;
            }
            else {
                count++;
            }
        }
        return element;
    }
};