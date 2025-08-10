class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int toprow = x;
        int bottomrow = x+k-1;
        int startcol = y;
        int endcol = y+k-1;
        while(toprow < bottomrow) {
            for(int i=startcol; i<=endcol; i++) {
                swap(grid[toprow][i],grid[bottomrow][i]);
            }
            toprow++;
            bottomrow--;
        }
        return grid;  
    }
};