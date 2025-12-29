class Solution {
public:
    void fun(vector<vector<int>> &res,vector<int> &sol,int k,vector<int> &nums,int i) {
        if(sol.size() == k) {
            res.push_back(sol);
            return;
        }
        if(i > nums.size()-1) {
            return;
        }
        // take
        sol.push_back(nums[i]);
        fun(res,sol,k,nums,i+1);
        sol.pop_back();
        // skip
        fun(res,sol,k,nums,i+1);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n+1);
        for(int i=1; i<=n; i++) {
            nums[i] = i;
        }
        vector<vector<int>> res;
        vector<int> sol;
        fun(res,sol,k,nums,1);
        return res;
    }
};