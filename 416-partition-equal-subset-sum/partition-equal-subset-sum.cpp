class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int w) {
        // code here
        int n = arr.size();
        vector<vector<bool>>t(n+1,vector<bool>(w+1,false));
        //initialisation
        for(int i = 0; i < n+1; i++)
        {
            t[i][0] = true;
        }
        //two choices - either put or leave
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<w+1; j++)
            {
                if(arr[i-1]<=j)
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                else
                t[i][j] = t[i-1][j];
            }
        }
        return t[n][w];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
        }
        if(sum%2!=0)
        return false;
        else
        return isSubsetSum(nums,sum/2);
    }
};