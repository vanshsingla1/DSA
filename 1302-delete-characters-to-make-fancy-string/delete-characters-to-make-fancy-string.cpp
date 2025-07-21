class Solution {
public:
    string makeFancyString(string s) {
        string res;
        int count = 0;
        char last = '#';
        for(char c : s) {
            if(c == last) {
                count++;
            }
            else {
                count = 1;
                last = c;
            }

            if(count <= 2)
            res += c;
        }
        return res;
    }
};