class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // (k * (k-1)) / 2
        unordered_map<int,int> mp;
        for(auto num : nums) {
            mp[num]++;
        }
        int count = 0;
        for(auto it : mp) {
            if(it.second >= 2)
            count += ((it.second) * (it.second-1))/2;
        }
        return count;
    }
};