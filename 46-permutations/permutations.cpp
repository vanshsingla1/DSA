class Solution {
public:
//Space Optimized - swapping
    void dopermute(int n,vector<int>& nums,vector<int>& temp,vector<vector<int>>&res)
    {
        if(n == nums.size())
        {
            res.push_back(temp);
            return;
        }
        for(int i=n; i<nums.size(); i++)
        {
            swap(nums[i],nums[n]);
            temp.push_back(nums[n]);
            dopermute(n+1,nums,temp,res);
            temp.pop_back();
            swap(nums[i],nums[n]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        if(nums.empty())
        return res;
        vector<int>temp;
        dopermute(0,nums,temp,res);
        return res;
    }
};