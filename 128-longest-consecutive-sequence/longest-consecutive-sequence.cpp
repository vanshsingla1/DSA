class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(int i=0; i<n; i++) {
            st.insert(nums[i]);
        }
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