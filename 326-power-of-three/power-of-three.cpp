class Solution {
public:
    bool fun(int n) {
        if(n == 1)
        return true;
        if (n < 1 || n % 3 != 0) 
        return false;
        return fun(n/3);
    }
    bool isPowerOfThree(int n) {
        if(n == 1)
        return true;
        return fun(n);
    }
};