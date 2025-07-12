class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        //similiar to Longest Increasing Subsequence + Sorting
        sort(pairs.begin(),pairs.end());
        int n = pairs.size();
        vector<int> dp(n,1);
        int res = 1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i],dp[j]+1);
                    res = max(res,dp[i]);
                }
            }
        }
        return res;
    }
};