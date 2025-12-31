class Solution {
public:
    void fun(vector<int> &nums,int target,vector<int> &sol,int i,vector<vector<int>> &res) {
        if(target == 0) {
            res.push_back(sol);
            return;
        }
        if(target < 0 || i >= nums.size()) {
            return;
        }
        // take
        sol.push_back(nums[i]);
        fun(nums,target-nums[i],sol,i+1,res);
        sol.pop_back();
        // skip
        int j = i+1;
        while(j < nums.size() && nums[j] == nums[i]) {
            j++;
        }
        fun(nums,target,sol,j,res);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        // each number is used only once
        // unlike in combination sum 4, each number can be used unlimimtedly
        int n = nums.size();
        vector<vector<int>> res;
        int minn = *min_element(nums.begin(),nums.end());
        if(minn > target) {
            return res;
        }
        sort(nums.begin(), nums.end());
        vector<int> sol;
        fun(nums,target,sol,0,res);
        return res;
    }
};