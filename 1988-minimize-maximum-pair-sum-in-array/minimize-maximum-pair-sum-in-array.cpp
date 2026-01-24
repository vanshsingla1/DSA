class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = n-1;
        int maxsum = -1;
        while(i < j) {
            maxsum = max(maxsum,nums[i]+nums[j]);
            i++;
            j--;
        }
        return maxsum;
    }
};