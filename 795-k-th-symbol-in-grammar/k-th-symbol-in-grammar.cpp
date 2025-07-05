class Solution {
public:
    int kthGrammar(int n, int k) {
        if(k == 1)
        return 0;
        // n -> operations size
        int len = 1;
        int newk = -1;
        for(int i=1; i<n; i++) {
            len *= 2;
            if(len >= k) {
                newk = k-(len/2);
                break;
            }
        }
        int resp = kthGrammar(n,newk);
        if(resp == 0)
        return 1;
        else 
        return 0;
    }
};