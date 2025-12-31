class Solution {
public:
    void fun(vector<int> &nums,int target,vector<vector<int>> &res,vector<int> &sol,int i) {
        if(target == 0) {
            res.push_back(sol);
            return;
        }
        if(target < 0 || i >= nums.size()) {
            return;
        }
        // take
        sol.push_back(nums[i]);
        fun(nums,target-nums[i],res,sol,i);
        sol.pop_back();
        // skip
        fun(nums,target,res,sol,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> sol;
        int minn = *min_element(nums.begin(),nums.end());
        if(minn > target) {
            return res;
        }
        fun(nums,target,res,sol,0);
        return res;
    }
};