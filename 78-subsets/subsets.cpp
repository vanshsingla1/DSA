class Solution {
public:
    void fun(vector<int> &nums,vector<vector<int>> &res,vector<int> &temp,int i) {
        if(i >= nums.size()) {
            res.push_back(temp);
            return;
        }
        // take or skip
        // take 
        temp.push_back(nums[i]);
        fun(nums,res,temp,i+1);
        temp.pop_back();
        // skip
        fun(nums,res,temp,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) {
            return res;
        }
        vector<int> temp;
        fun(nums,res,temp,0);
        return res;
    }
};