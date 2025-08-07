class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int x : nums){
            auto it = lower_bound(res.begin(),res.end(),x);
            if(it == res.end())
            res.push_back(x);
            else
            *it = x;
        }
        return res.size();
    }
};