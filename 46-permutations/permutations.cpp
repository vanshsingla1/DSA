class Solution {
public:
    void fun(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp,
             unordered_set<int>& st) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (st.find(i) == st.end()) {
                st.insert(i);
                temp.push_back(nums[i]);
                fun(nums, res, temp, st);
                temp.pop_back();
                st.erase(i);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(nums.empty())
        return res;
        vector<int> temp;
        unordered_set<int> st;
        fun(nums, res, temp, st);
        return res;
    }
};