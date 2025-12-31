class Solution {
public:
    void fun(vector<int> &nums,vector<vector<int>> &res,int target,vector<int> &sol,int i,int k) {
        if(target == 0 && sol.size() == k) {
            res.push_back(sol);
            return;
        }
        if(target < 0 || i >= nums.size()) {
            return;
        }
        // take
        sol.push_back(nums[i]);
        fun(nums,res,target-nums[i],sol,i+1,k);
        sol.pop_back();

        // skip
        fun(nums,res,target,sol,i+1,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        // each number is used only once
        // k numbers such that their sum = n
        vector<int> nums(10);
        for(int i=1; i<=9; i++) {
            nums[i] = i;
        }
        vector<vector<int>> res;
        vector<int> sol;
        if(k > n) {
            return res;
        }
        fun(nums,res,n,sol,1,k);
        return res;
    }
};