class Solution {
public:
    int minimumCost(vector<int>& nums) {
        // find first 3 smalles indices
        // always include nums[0]
        int cost = nums[0];
        // find other two smalles elements
        sort(nums.begin()+1,nums.end()); // exlude 1st element
        return cost+nums[1]+nums[2];
    }
};