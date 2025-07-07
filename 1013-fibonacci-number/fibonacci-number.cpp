class Solution {
public:
    int FIBBO(vector<int>&DP,int n)
    {
        if(DP[n]!=-1)
        return DP[n];
        if(n==0 || n==1)
        {
            DP[n]=n;
            return DP[n];
        }
        int x=FIBBO(DP,n-1);
        int y=FIBBO(DP,n-2);
        int sum=x+y;
        DP[n]=sum;
        return DP[n];
    }
    int fib(int n) {
        vector<int>DP(n+1,-1);
        return FIBBO(DP,n);
    }
};