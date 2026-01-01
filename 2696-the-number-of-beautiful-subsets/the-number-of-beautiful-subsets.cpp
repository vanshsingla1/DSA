class Solution {
public:
    int res = 0;
    void fun(vector<int>& nums, int k, unordered_map<int, int>& mp, int i) {
        if (i >= nums.size()) {
            res++;
            return;
        }
        // take or skip
        if (!mp.count(nums[i] + k) && !mp.count(nums[i] - k)) {
            mp[nums[i]]++;
            fun(nums, k, mp, i + 1);
            mp[nums[i]]--;
            if (mp[nums[i]] == 0)
                mp.erase(nums[i]);
        }
        fun(nums, k, mp, i + 1);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        if (nums.empty()) {
            return res;
        }
        unordered_map<int, int> mp;
        fun(nums, k, mp, 0);
        return res-1; // dont include empty set, there is only one empty set present
    }
};