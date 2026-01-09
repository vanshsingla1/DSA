class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto val : asteroids) {
            bool flag = true;
            while(!st.empty() && val < 0 && st.top() > 0) {
                if(st.top() < abs(val)) {
                    // remove st.top()
                    st.pop();
                }
                else if(st.top() > abs(val)) {
                    // remove val
                    flag = false;
                    break;
                }
                else {
                    // both are equal -> remove both
                    st.pop();
                    flag = false;
                    break;
                }
            }
            if(flag) {
                st.push(val);
            }
        }
        
        vector<int> res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};