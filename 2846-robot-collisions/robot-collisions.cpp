class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // based on aesteroid collision
        vector<int> order(positions.size());
        for(int i = 0; i < positions.size(); i++) {
            order[i] = i;
        }

        sort(order.begin(), order.end(),
             [&](int a, int b) {
                 return positions[a] < positions[b];
             });

        stack<int> st;
        for(int i=0; i<order.size(); i++) {
            int j = order[i];
            bool flag = true;
            while(!st.empty() && directions[j] == 'L' && directions[st.top()] == 'R') {
                if(healths[st.top()] < healths[j]) {
                    // remove st.top()
                    healths[st.top()] = -1;
                    healths[j]--;
                    st.pop();
                }
                else if(healths[st.top()] > healths[j]) {
                    // remove val
                    healths[j] = -1;
                    healths[st.top()]--;
                    flag = false;
                    break;
                }
                else {
                    // both are equal -> remove both
                    healths[j] = -1;
                    healths[st.top()] = -1;
                    st.pop();
                    flag = false;
                    break;
                }
            }
            if(flag) {
                st.push(j);
            }
        }
        vector<int> res;
        for(auto val : healths) {
            if(val != -1) {
                res.push_back(val);
            }
        }
        return res;
    }
};