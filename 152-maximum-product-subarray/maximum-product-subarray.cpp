class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //Kadnane's Algo
        int n = nums.size();
        int prod1 = nums[0];
        int prod2 = nums[0];
        int mp = nums[0];// maxm product
        int temp;
        for(int i=1; i<n; i++)
        {
            temp = max({nums[i],nums[i]*prod1,nums[i]*prod2});
            prod2 = min({nums[i],nums[i]*prod1,nums[i]*prod2});
            prod1 = temp;
            mp = max(mp,prod1);
        }
        return mp;
    }
};