class Solution {
public:
    const int INF = 1e9;
    int fun(vector<int> &arr,int n,int i,int target,vector<vector<int>> &dp) {
        if(target == 0) {
            return 0;
        }
        if(i >= n)
        return INF;
        if(dp[i][target] != -1)
        return dp[i][target];
        if(arr[i] <= target) {
            // take or not take
            return dp[i][target] = min(1+fun(arr,n,i,target-arr[i],dp),fun(arr,n,i+1,target,dp));
        }
        else
        return dp[i][target] = fun(arr,n,i+1,target,dp);
    }
    int numSquares(int n) {
        int i = 1;
        vector<int> arr;
        while(i*i <= n) {
            arr.push_back(i*i);
            i++;
        }
        reverse(arr.begin(),arr.end());
        vector<vector<int>> dp(arr.size()+1,vector<int>(n+1,-1));
        int res = fun(arr,arr.size(),0,n,dp);
        return res >= INF ? -1 : res;
    }
};