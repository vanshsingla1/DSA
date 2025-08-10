class Solution {
public:
    const int MOD = 1e9+7;
    long long fun(vector<int>& arr, int i, int j, int fuel,int n,vector<vector<long long>> &dp) {
        if(fuel < 0)
        return 0;
        long long count = 0;
        if(i == j)
        count = 1;
        if(dp[i][fuel] != -1)
        return dp[i][fuel];
        for(int k = 0; k<n; k++) {
            if(k != i) {
                count += (fun(arr,k,j,fuel-abs(arr[k]-arr[i]),n,dp)%MOD);
            }
        }
        return dp[i][fuel] = count%MOD;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<long long>> dp(n+1,vector<long long> (fuel+1,-1));
        return fun(locations,start,finish,fuel,n,dp);
    }
};