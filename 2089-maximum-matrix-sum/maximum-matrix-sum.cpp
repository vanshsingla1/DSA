class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int count = 0;
        int minn_neg = INT_MAX;
        long long sum = 0;
        bool zero = false;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0) {
                    zero = true;
                    continue;
                }
                if(matrix[i][j] < 0) {
                    count++;
                }
                minn_neg = min(abs(matrix[i][j]),minn_neg);
                sum += abs(matrix[i][j]);
            }
        }
        if(count%2 == 0 || zero) {
            return sum;
        }
        else {
            return sum-2*minn_neg;
        }
    }
};