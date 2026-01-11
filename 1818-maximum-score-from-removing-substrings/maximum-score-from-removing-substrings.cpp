class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // two pointer
        // can be done by stack also
        if(x < y) { // ab should have higher score
            swap(x,y);
            reverse(s.begin(),s.end());
        }
        int acount = 0;
        int bcount = 0;
        int count = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == 'a')
            acount++;
            else if(s[i] == 'b') {
                if(acount > 0) {
                    acount--;
                    count += x;
                }
                else {
                    bcount++;
                }
            }
            else {
                count += min(acount,bcount)*y;
                acount=0;
                bcount=0;
            }
        }
        count += min(acount,bcount)*y; // for last element
        return count;
    }
};