class Solution {
public:
    int isSubsetSum(vector<int>& arr, int w) {
        // code here
        int n = arr.size();
        vector<vector<int>>t(n+1,vector<int>(w+1,0));
        //initialisation
        for(int i = 0; i < n+1; i++)
        {
            t[i][0] = 1;
        }
        //two choices - either put or leave
        for(int i=1; i<n+1; i++)
        {
            for(int j=0; j<w+1; j++)
            {
                if(arr[i-1]<=j)
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
                else
                t[i][j] = t[i-1][j];
            }
        }
        return t[n][w];
    }
    int findTargetSumWays(vector<int>& arr, int target) {
        int sum = 0;
        for(int i=0; i<arr.size(); i++)
        {
            sum += arr[i];
        }
        if ((sum + target) % 2 != 0 || sum < abs(target)) 
        return 0;
        return isSubsetSum(arr,(sum+target)/2);
    }
};