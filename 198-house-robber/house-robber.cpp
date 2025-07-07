class Solution {
public:
    int dorob(vector<int>& nums,vector<int>& DP,int N)
    {
        // if(N==0)// if n==0 then it is the last element of 0th based indexing 
        // {
        //     // DP[0]=nums[0];
        //     // return DP[0];
        //      if(DP[N]!=-1)
        // return DP[N];
        // int x = dorob(nums,DP,N-2) + nums[N];// To Pick the elements including and upto Nth Element and to find the maxm element utpo Nth element
        // int y = dorob(nums,DP,N-1);// TO pick the elements excluding the Nth element and to find the maxm element utpo Nth element
        // DP[N] = max(x,y);
        // return DP[N];
        // }
        if(N<0)// if n<0 then we have to check the condition and return from the loop to avoid infinite looping
        {
            return 0;
        }
        
        if(DP[N]!=-1)
        return DP[N];
        int x = dorob(nums,DP,N-2) + nums[N];// To Pick the elements including and upto Nth Element and to find the maxm element utpo Nth element
        int y = dorob(nums,DP,N-1);// TO pick the elements excluding the Nth element and to find the maxm element utpo Nth element
        DP[N] = max(x,y);
        return DP[N];
    }
    int rob(vector<int>& nums) 
    {
          int n = nums.size();
          vector<int>DP(n,-1);
          int res = dorob(nums,DP,n-1);
          return res;
    }
};