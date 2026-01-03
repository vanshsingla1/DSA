class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        // next larger element to the right
        // instead of st.top(), push the difference between indexes 
        // and instead of -1 push 0
        stack<int> st; // indexed based
        vector<int> res;
        int n = nums.size();
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if(st.empty()) {
                res.push_back(0);
            }
            else {
                res.push_back(abs(i-st.top()));
            }
            st.push(i);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};