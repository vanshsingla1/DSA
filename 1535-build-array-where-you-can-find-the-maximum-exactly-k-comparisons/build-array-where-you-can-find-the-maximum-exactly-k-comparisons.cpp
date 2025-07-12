class Solution {
public:
    const int MOD = 1e9+7;
    long long dp[51][51][102];
    long long possible_arrays(int idx,int len, int maxx,int n,int k,int m) {
        if(idx == n) {
            if(len == k)
            return 1;
            else 
            return 0;
        }
        if (dp[idx][len][maxx+1] != -1) 
        return dp[idx][len][maxx+1];

        long long res = 0;
        for(int i=1; i<=m; i++) {
            if(i > maxx) {
                res = res + possible_arrays(idx+1,len+1,i,n,k,m) % MOD;
            }
            else
            res = res + possible_arrays(idx+1,len,maxx,n,k,m) % MOD;
        }
        return dp[idx][len][maxx+1] = res % MOD;
    }
    int numOfArrays(int n, int m, int k) {
        // draw tree
        // m is the upper limit for values of arr[i]
        memset(dp, -1, sizeof(dp));
        return possible_arrays(0,0,-1,n,k,m);
    }
};