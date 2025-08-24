class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if(nums.size()%k != 0) {
            return false;
        }
        int ngroups = nums.size()/k;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        for(auto it : mp) {
            if(it.second > ngroups) {
                return false;
            }
        }
        return true;
    }
};