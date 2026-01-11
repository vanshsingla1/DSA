class Solution {
public:
    string removeKdigits(string num, int k) {
        // montonically increasing stack
        // if the upcomming element is smaller than st.top() remove st.top()
        // we have to keep the num minimum
        stack<char> st;
        int count = 0;
        for(int i=0; i<num.length(); i++) {
            while(!st.empty() && st.top() > num[i] && count < k) {
                st.pop();
                count++;
            }
            if(st.empty() && num[i] == '0') {
                continue;
            }
            else {
                st.push(num[i]);
            }
        }
        
        string res;
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        // remove digits from end
        while(count < k && !res.empty()) {
            res.pop_back();
            count++;
        }
        if(res.empty()) {
            return "0";
        }
        return res;
    }
};