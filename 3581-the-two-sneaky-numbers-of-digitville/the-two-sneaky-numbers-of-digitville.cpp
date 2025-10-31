class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int,int> mp;
        for(int i : nums) {
            mp[i]++;
            if(mp[i] == 2) {
                res.push_back(i);
            }
        }
        return res;
    }
};