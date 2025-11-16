class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int a = nums[0];
        int b = nums[n-1];
        int c = nums[n-2];
        return (b+c-a);
    }
};