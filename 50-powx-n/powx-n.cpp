class Solution {
public:
    double doPow(double a,long long b) {
        if(b == 0)
        return 1;

        if(b%2 == 0) {
            double t = doPow(a,b/2);
            return (t*t);
        }
        else {
            double t = doPow(a,(b-1)/2);
            return (a*t*t);
        }
    }
    double myPow(double a, int b) {
        long long exp = b; // to safly handle INT_MIN
        if(exp < 0) {
            //b is negative
            a = 1/a;
            exp = -exp;
        }
        return doPow(a,exp);
    }
};