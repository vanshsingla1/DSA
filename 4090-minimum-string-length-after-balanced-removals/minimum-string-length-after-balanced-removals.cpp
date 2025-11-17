class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n = s.length();
        int a = 0;
        int b = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == 'a') {
                a++;
            }
            else {
                b++;
            }
        }
        return n-2*min(a,b);
    }
};