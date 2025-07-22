class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        //sliding window
        int n = nums.size();
        unordered_set<int>st;
        int left = 0;
        int right = 0;
        int sum = 0;
        int maxSum = INT_MIN;
        while(right < n) {
            while(st.count(nums[right])) {
                st.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
            st.insert(nums[right]);
            sum += nums[right];
            maxSum = max(sum,maxSum);
            right++;
        }
        return maxSum;
    }
};