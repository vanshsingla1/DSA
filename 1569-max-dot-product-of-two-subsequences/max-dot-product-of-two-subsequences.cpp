class Solution {
public:
    int fun(vector<int>& nums1, vector<int>& nums2,int i,int j,vector<vector<int>> &dp) {
        if(i >= nums1.size() || j >= nums2.size()) {
            return -1e9;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        // now try all possibilities and return the max dot product
        int a = nums1[i] * nums2[j];
        int b = nums1[i] * nums2[j] + fun(nums1,nums2,i+1,j+1,dp);
        int c = fun(nums1,nums2,i,j+1,dp);
        int d = fun(nums1,nums2,i+1,j,dp);
        return dp[i][j] = max({a,b,c,d});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // answer may be negative also
        // recursion + dp
        vector<vector<int>> dp(nums1.size(), vector<int> (nums2.size(),-1));
        return fun(nums1,nums2,0,0,dp);
    }
};