class Solution {
public:
    const int MOD = 1e9+7;
    long long fun(const string &s,int k,int i,int n,vector<long long> &dp) {
        if(i >= n)
        return 1;
        if(s[i] == '0')
        return 0;
        if(dp[i] != -1)
        return dp[i];
        long long res = 0;
        long long num = 0;
        for(int j=i; j<n; j++) {
            num = num*10 + s[j]-'0';
            if(num > k) break; // stop building num, if num > k
            if(num <= k) {
                res = (res + fun(s,k,j+1,n,dp))%MOD;
            }
        }
        return dp[i] = res;
    }
    int numberOfArrays(string s, int k) {
        // recursion + memo
        int n = s.length();
        vector<long long> dp(n+1,-1);
        return fun(s,k,0,n,dp);
    }
};