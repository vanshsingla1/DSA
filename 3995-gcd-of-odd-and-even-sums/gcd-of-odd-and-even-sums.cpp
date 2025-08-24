class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // gcd(n*n, n*n+n) = n * gcd(n,n+1)
        //  gcd of two consecutive numbers is always 1
        // so ans is n
        return n;
    }
};