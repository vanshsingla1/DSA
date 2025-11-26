class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int small = nums[0];
        int large = nums[n - 1];

        vector<int> sol;

        unordered_set<int> numSet(nums.begin(), nums.end());

        for (int i = small; i <= large; i++) {
            if (numSet.find(i) == numSet.end()) {
                sol.push_back(i);
            }
        }

        return sol;
    }
};