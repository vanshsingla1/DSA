class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        // set
        unordered_set<int> st(friends.begin(),friends.end());
        vector<int> res;
        for(int i=0; i<order.size(); i++) {
            if(st.contains(order[i])) {
                res.push_back(order[i]);
            }
        }
        return res;
    }
};