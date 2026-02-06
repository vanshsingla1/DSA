class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int maxx = INT_MIN;
        sort(nums.begin(),nums.end());
        while(j < n) {
            while(j<n && (long long) nums[j] <= (long long) nums[i]*k) {
                j++;
            }
            maxx = max(maxx,j-i);
            i++;
        }
        return n-maxx;
    }
};