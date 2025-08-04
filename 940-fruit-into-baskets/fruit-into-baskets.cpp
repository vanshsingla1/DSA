class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int left = 0;
        int maxlen = 0;
        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
            while(mp.size() > 2) {
                mp[nums[left]]--;
                if(mp[nums[left]] == 0)
                mp.erase(nums[left]);
                left++;
            }
            maxlen = max(maxlen,i-left+1);
        }
        return maxlen;
    }
};