class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int m = dimensions.size();
        int n = dimensions[0].size();
        long long diagonal = 0;
        long long maxdiagonal = 0;
        int maxarea = 0;
        for(int i=0; i<m; i++) {
            int length = dimensions[i][0];
            int breadth = dimensions[i][1];
            diagonal = (1LL*length*length + 1LL*breadth*breadth);
            if(diagonal > maxdiagonal) {
                maxdiagonal = diagonal;
                maxarea = length * breadth;
            }
            else if(maxdiagonal == diagonal) {
                maxarea = max(maxarea, length*breadth);
            }
        }
        return maxarea;
    }
};
