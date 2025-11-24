class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string res;
        int sum = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] != '0') {
                res += s[i];
                sum += s[i] - '0';
            }
        }
        if(res.empty()) 
        return 0;
        return sum * stoll(res);
    }
};