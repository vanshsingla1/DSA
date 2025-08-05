class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        // fruits -> quantity
        // baskets -> capacity of each baasket
        // each basket can hold only one type of fruit
        int count = 0; // if the fruit can't be placed in any of the basket
        for(int i=0; i<n; i++) {
            bool flag = true;
            for(int j=0; j<n; j++) {
                if(fruits[i] <= baskets[j]) {
                    baskets[j] = 0;
                    flag = false;
                    break;
                }
            }
            if(flag != false)
            count++;
        }
        return count;
    }
};