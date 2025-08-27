class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> mp;
        mp.insert({0,1}); // edge case, add 0 intially with count 1
        // prefixSum count
        int presum = 0;
        int count = 0;
        for(int i=0; i<n; i++) {
            presum += nums[i];
            if(mp.find(presum-target) != mp.end()) {
                // mil gyaa
                count += mp[presum-target];
            }
            mp[presum]++;
        }
        return count;
    }
};