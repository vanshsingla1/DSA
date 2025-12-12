class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        // Increase or decrease x by 1, and simultaneously increase or decrease num by 1. , perform operations at most t times
        return (num + t*2);
    }
};