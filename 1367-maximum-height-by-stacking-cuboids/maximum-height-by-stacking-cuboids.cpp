class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        // lis
        int n = cuboids.size();
        // generate all permutations, and check (width*length)i <= (width*length)j  && (height)i <= (height)j
        // calculate the height and store it in maxHeight
        // how dp??
        for(auto &v: cuboids) {
            sort(v.begin(),v.end());
        }
        sort(cuboids.begin(),cuboids.end());
        // Now reverse acc to decreasing order of height
        // reverse(cuboids.begin(),cuboids.end());
        int res = INT_MIN;
        vector<int> dp(n,0);
        for(int i=0; i<n; i++) {
            dp[i] = cuboids[i][2];
            for(int j=0; j<i; j++) {
                if(cuboids[i][2] >= cuboids[j][2] && cuboids[i][1] >= cuboids[j][1] && cuboids[i][0] >= cuboids[j][0])  {
                    dp[i] = max(dp[i],dp[j]+cuboids[i][2]);
                }
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};