class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int count = 0;
        for(int i=0; i<s.length(); i++) {
            // bool flag = true;
            if(!st.empty() && st.top() > s[i]) {
                st.pop();
                count++;
                // flag = false;
            }
            else {
                st.push(s[i]);
            }
        }
        return count;
    }
};