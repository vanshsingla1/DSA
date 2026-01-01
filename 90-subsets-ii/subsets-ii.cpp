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

        // handle duplicates
        int j = i+1;
        while(j < nums.size() && nums[j] == nums[i]) {
            j++;
        }
        // skip
        fun(nums,res,temp,j);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        if(nums.empty()) {
            return res;
        }
        sort(nums.begin(),nums.end());
        fun(nums,res,temp,0);
        return res;
    }
};