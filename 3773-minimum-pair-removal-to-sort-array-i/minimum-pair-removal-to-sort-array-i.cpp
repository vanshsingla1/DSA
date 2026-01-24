class Solution {
public:
    int fun(vector<int>& nums) {
        int idx = -1;
        int sum = 0;
        int minsum = INT_MAX;
        for (int i = 0; i < nums.size() - 1; i++) {
            sum = nums[i] + nums[i + 1];
            if (sum < minsum) {
                minsum = sum;
                idx = i;
            }
        }
        return idx;
    }
    int minimumPairRemoval(vector<int>& nums) {
        // no need to worry about time complexity
        int n = nums.size();
        int count = 0;
        while (!is_sorted(begin(nums), end(nums))) {
            // find the pair with min index sum
            // traverse the whole array
            int idx = fun(nums);
            // replace nums[i] at idx index with the sum, and remove the next
            // idx

            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(begin(nums) + idx + 1);
            count++;
        }
        return count;
    }
};