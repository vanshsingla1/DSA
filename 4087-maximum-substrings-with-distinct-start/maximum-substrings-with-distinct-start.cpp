class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<int> st(s.begin(),s.end());
        return st.size();
    }
};