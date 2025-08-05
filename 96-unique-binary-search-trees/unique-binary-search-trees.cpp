class Solution {
public:
    int numTrees(int n) {
        // Catalan numbers
        // pattern exactly matches with catalan numbers
        // n = 3 -> c0c2 + c1c1 + c2c0
        if(n <= 1)
        return 1;
        int count = 0;
        for(int i=1; i<=n; i++) {
            count += numTrees(i-1) * numTrees(n-i);
        }
        return count;
    }
};