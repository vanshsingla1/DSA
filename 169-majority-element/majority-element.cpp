class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        // here we have to assume that majority element exists in the array
        // otherwise we need to check whether its actually present or not
        int element = nums[0];
        int count = 1;
        for(int i=1; i<n; i++) {
            if(count == 0) {
                count = 1;
                element = nums[i];
            }
            else if(nums[i] != element) {
                count--;
            }
            else {
                // nums[i] == element
                count++;
            }
        }
        // check whether elemtent actually exists or not (no need here because test cases are generated accordingly)
        // int res = 0;
        // for(int i=0; i<n; i++) {
        //     if(nums[i] == element) {
        //         res++;
        //     }
        // }
        // if(res > n/2) {
        //     // yes
        // }
        // else {
        //     no
        // }
        return element;
    }
};