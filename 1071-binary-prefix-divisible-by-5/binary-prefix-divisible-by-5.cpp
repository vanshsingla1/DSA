class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int prefix = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            prefix = ((prefix << 1) + nums[i]) % 5;
            res.push_back(prefix == 0);
        }
        return res;
    }
};