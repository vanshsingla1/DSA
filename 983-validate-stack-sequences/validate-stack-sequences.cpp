class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int idx = 0;
        // now push elements acc to pop
        for(auto pop : popped) {
            // check if stack is empty or not
            if(!st.empty()) {
                if(pop == st.top()) {
                    st.pop();
                }
                else {
                    // element is not found, traverse untill last, if loop ends then return false
                    while (idx < pushed.size() && pushed[idx] != pop) {
                    st.push(pushed[idx]);
                    idx++;
                }
                    // now check if loop ends and pop not found -> return false
                    if(idx == pushed.size()) {
                        return false;
                    }
                    idx++;
                }
            }
            else {
                // stack is empty
                while (idx < pushed.size() && pushed[idx] != pop) {
                    st.push(pushed[idx]);
                    idx++;
                }
                idx++;
            }
        }
        return true;
    }
};