class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> st(nums.begin(),nums.end());
        int val = 0;
        int count = 0;
        int maxcount = 0;
        for(auto it = st.begin(); it != st.end(); it++) {
            if(it == st.begin()) {
                count = 1;
                maxcount = max(maxcount, count);
            }
            else {
                if(*it-val == 1) {
                    count++;
                }
                else {
                    count = 1;
                }
                maxcount = max(maxcount, count);
            }
            val = *it;
        }
        return maxcount;
    }
};