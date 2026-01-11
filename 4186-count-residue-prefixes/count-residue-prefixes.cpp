class Solution {
public:
    int residuePrefixes(string s) {
        unordered_set<char> st;
        string prefix = "";
        int count = 0;

        for(int i = 0; i < s.length(); i++) {
            st.insert(s[i]);
            prefix += s[i];

            int distinct = st.size();
            int len = prefix.length();

            if(distinct == len % 3) {
                count++;
            }
        }
        return count;
    }
};
