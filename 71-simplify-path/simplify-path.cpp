class Solution {
public:
    string simplifyPath(string path) {
        vector<string> res;
        string s = "";
        for(int i=0; i<path.length(); i++) {
            if(path[i] == '/') {
                if(!s.empty()) {
                    res.push_back(s);
                    s = "";
                }
                else continue;
            }
            else {
                s += path[i];
            }
        }
        if(!s.empty()) res.push_back(s);

        // now perform stack operations
        stack<string> st;
        for(int i=0; i<res.size(); i++) {
            if(res[i] == "..") {
                // pop
                if(!st.empty()) {
                    st.pop();
                }
            }
            else if(res[i] == ".") {
                continue;
            }
            else {
                st.push(res[i]);
            }
        }
        string finalres = "";
        vector<string> temp;
        while(!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());

        finalres = "/";
        for(int i=0; i<temp.size(); i++) {
            finalres += temp[i];
            if(i != temp.size()-1) finalres += "/";
        }
        return finalres;
    }
};
