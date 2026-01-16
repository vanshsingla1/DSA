class Solution {
public:
    string removeOccurrences(string s, string part) {
        string st;
        int len = part.length();
        int end = part.back();
        for(char ch : s) {
            st += ch;
            if(ch == end && st.size() >= len) {
                if(st.substr(st.size()-len) == part) {
                    st.erase(st.size()-len);
                }
            }
        }
        return st;
    }
};