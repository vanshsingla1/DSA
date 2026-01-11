class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                string temp;
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                st.pop(); // remove '('
                for(auto c : temp) {
                    st.push(c);
                }
            } else {
                st.push(s[i]);
            }
        }
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};