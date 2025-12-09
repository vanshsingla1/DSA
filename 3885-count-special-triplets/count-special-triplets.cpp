class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        // i < j < k
        // nums[i] == nums[j] * 2
        // nums[k] == nums[j] * 2
        // return total number of triplets
        // 2 1 2 , 6 3 6, 0 0 0, 8 4 8, 4 2 4
        // O(N)
        int n = nums.size();
        unordered_map<long long,long long> right;
        unordered_map<long long, long long> left;
        long long count = 0;
        const int MOD = 1e9+7;
        for(int i=0; i<n; i++) {
            right[nums[i]]++;
        }
        for(int i=0; i<n; i++) {
            right[nums[i]]--;
            int target = 2*nums[i];
            if(left.count(target) && right.count(target)) {
                count += (left[target] * right[target])%MOD;
            }
            left[nums[i]]++;
        }
        return count%MOD;
    }
};