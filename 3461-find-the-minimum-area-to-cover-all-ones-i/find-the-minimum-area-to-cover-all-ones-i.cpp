class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();   

        int p1, p2;
        int c1, c2;

        for (int i=0; i<m; i++){
            bool flag = false;
            for (int j=0; j<n; j++){
                if(grid[i][j]==1){
                    p1=i;
                    flag = true;
                    break;
                }
            }
            if(flag) {
                break;
            }
        }

        for (int i=m-1; i>=0; i--){
            bool flag = false;
            for (int j=0; j<n; j++){  
                if(grid[i][j]==1){
                    p2=i;
                    flag = true;
                    break;
                }
            }
            if(flag) {
                break;
            }
        }
        if(p1 > p2)
        return 0;
        for (int i=0; i<n; i++){
            bool flag = false;
            for (int j=0; j<m; j++){
                if(grid[j][i]==1){   // ✅ swap indices (check col properly)
                    c1=i;
                    flag = true;
                    break;
                }
            }
            if(flag) {
                break;
            }
        }

        for (int i=n-1; i>=0; i--){   // ✅ loop over cols
        bool flag = false;
            for (int j=m-1; j>=0; j--){
                if(grid[j][i]==1){
                    c2=i;   // ✅ fix: c2 not p2
                    flag = true;
                    break;
                }
            }
            if(flag) {
                break;
            }
        }
        if(c1 > c2)
        return 0;
        return abs(p2 - p1 + 1) * abs(c2 - c1 + 1);
    }
};