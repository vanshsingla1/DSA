class Solution {
public:
    int findClosest(int x, int y, int z) {
        // z -> does not move
        // same speed
        // less time -> less distance
        if(abs(x-z) < abs(y-z)) {
            return 1;
        } 
        else if(abs(x-z) > abs(y-z)) {
            return 2;
        }
        else {
            return 0;
        }
    }
};