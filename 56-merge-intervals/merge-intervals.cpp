class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        // sort intervals, if they are not in the sorting order
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++) {
            if(i == 0) {
                res.push_back({nums[i][0],nums[i][1]});
            }
            else if(res.back()[1] >= nums[i][0]) {
                res.back()[1] = max(nums[i][1],res.back()[1]);
            }
            else {
                res.push_back({nums[i][0],nums[i][1]});
            }
        }
        return res;
    }
};