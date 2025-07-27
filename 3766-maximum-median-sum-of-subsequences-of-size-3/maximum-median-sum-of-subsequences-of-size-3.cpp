class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        // sliding window?
        // dp? -> o(N^2)
        // sort?
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = n-2;
        long long sum = 0;
        while(i<j) {
            sum += nums[j];
            i++;
            j=j-2;
        }
        return sum;
    }
};