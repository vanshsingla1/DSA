class Solution {
public:
    string largestEven(string s) {
        // start from back, delete 1's only until 2 is found, return that number
        for(int i=s.length()-1; i>=0; i--) {
            if(s[i] != '2') {
                s.erase(i,1);
            }
            else {
                break;
            }
        }
        return s;
    }
};