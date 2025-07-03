class Solution {
public:
    char kthCharacter(int k) {
        int shift = __builtin_popcount(k-1);// counts number of set-bits
        return 'a'+shift;
    }
};