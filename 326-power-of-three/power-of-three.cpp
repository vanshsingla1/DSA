class Solution {
public:
    bool isPowerOfThree(int n) {
        // 3^x == n
        // x*log(3) = log(n)
        // x = log(n)/log(3)
        // if x is an int then return true otherwise false
        if(n <= 0)
        return false;
        double x = log10(n)/log10(3);
        return x == (int)x;
    }
};