class Solution {
public:
    bool fun(int n) {
        if(n == 1)
        return true;
        if(n <= 0 || n&2 != 0)
        return false;
        return fun(n/2);
    }
    bool isPowerOfTwo(int n) {
        // w/o loops and recursion
        return fun(n);
    }
};