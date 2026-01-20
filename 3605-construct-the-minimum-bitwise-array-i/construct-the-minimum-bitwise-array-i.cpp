class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i=0; i<n; i++) {
            bool flag = false;
            for(int x=0; x<nums[i]; x++) {
                if((x | (x+1)) == nums[i]) {
                    res.push_back(x);
                    flag = true; break;
                }
            }
            if(!flag) res.push_back(-1);
        }
        return res;
    }
};