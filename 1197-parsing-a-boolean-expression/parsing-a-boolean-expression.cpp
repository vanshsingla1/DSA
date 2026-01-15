class Solution {
public:
    char parse(vector<char> &temp,char op) {
        if(op == '&') {
            for(int i=0; i<temp.size(); i++) {
                if(temp[i] == 'f')
                return 'f';
            }
            return 't';
        }
        else if(op == '|') {
            for(int i=0; i<temp.size(); i++) {
                if(temp[i] == 't')
                return 't';
            }
            return 'f';
        }
        else {
            // ! not
            if(temp[0] == 't') 
            return 'f';
            else
            return 't';
        }
    }
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(int i=0; i<expression.size(); i++) {
            if(expression[i] == ',')
            continue;
            vector<char> temp;
            bool flag = true;
            while(!st.empty() && st.top() != '(' && expression[i] == ')') {
                temp.push_back(st.top());
                st.pop();
                flag = false;
            }
            if(!st.empty() && !temp.empty()) {
                st.pop();
                if(st.top() != '(') {
                    char ch = parse(temp,st.top());
                    st.push(ch);
                }
            }
            if(flag) {
                st.push(expression[i]);
            }
        }
        if(st.top() == 't') {
            return true;
        }
        else {
            return false;
        }
    }
};