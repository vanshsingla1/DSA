class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Patience Sort
        vector<int> res;
        for(int x : nums) {
            auto it = lower_bound(res.begin(),res.end(),x);
            if(it == res.end()) {
                //not found
                res.push_back(x);
            }
            else
            *it = x; // replace with the smallest value
        }
        return res.size();
    }
};