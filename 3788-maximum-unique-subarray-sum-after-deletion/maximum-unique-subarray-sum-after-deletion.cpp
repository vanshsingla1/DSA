class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        //check max element, if max element is less than zero then it is self the answer otherwise
        //sum of unique values greater than zero is the answer
        int maxx = INT_MIN;
        for(int i=0; i<n; i++) {
            maxx = max(nums[i],maxx);
        }
        if(maxx < 0)
        return maxx;
        unordered_set<int>st;
        int sum = 0;
        for(int i=0; i<n; i++) {
            if(!st.contains(nums[i])) {
                st.insert(nums[i]);
                if(nums[i] > 0)
                sum += nums[i];
            }
        }
        return sum;
    }
};