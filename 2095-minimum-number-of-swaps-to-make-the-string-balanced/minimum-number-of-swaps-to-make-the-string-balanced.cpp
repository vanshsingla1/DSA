class Solution {
public:
    int minSwaps(string s) {
        stack<int> st;
        for(int i=0; i<s.length(); i++) {
            if(!st.empty() && st.top() == '[' && s[i] == ']') {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }
        return ((st.size()/2)+1)/2;
    }
};