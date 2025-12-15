class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long res = 0;
        long long len = 1;
        for (int i = 1; i < n; i++) {
            if(prices[i] == prices[i-1]-1) {
                len++;
            }
            else {
                res += len * (len+1)/2;
                len = 1;
            }
        }
        res += len * (len+1)/2;
        return res;
    }
};