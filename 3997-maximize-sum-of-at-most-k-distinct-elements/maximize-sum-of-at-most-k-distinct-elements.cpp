class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int>st(nums.begin(),nums.end());
        vector<int> result(st.begin(),st.end());
        reverse(result.begin(),result.end());
        vector<int> res;
        int take = min(k, (int)result.size());
        for (int i = 0; i < take; ++i) {
            res.push_back(result[i]);
        }
        return res;
    }
};