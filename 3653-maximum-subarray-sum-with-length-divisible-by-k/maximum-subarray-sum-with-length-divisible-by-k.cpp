class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        // kadane's algorithm + prefix sum , brute force didn't worked
        // in kadane's algorithm we simply find the maximum subarray sum but in this case we should also take care 
        // of length of subarray, take sum only if len % k == 0 allows
        int n = nums.size();
        vector<long long> prefix(n,0);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        long long maxsum = LLONG_MIN;
        for(int start=0; start<k; start++) {
            int i = start;
            long long sum = 0;
            while(i < n && i+k-1 < n) {
                int j = i+k-1;
                long long subsum = prefix[j] - ((i>0) ? prefix[i-1] : 0);
                sum = max(subsum,sum+subsum);
                maxsum = max(maxsum,sum);
                i = i+k;
            }
        }
        return maxsum;
    }
};