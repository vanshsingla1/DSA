class Solution {
public:
    vector<vector<int>> res;
    void twoSum(vector<int> &nums,int target,int index) {
        int n = nums.size();
        if(n < 2) {
            return;
        }
        int i = index;
        int j = n-1;
        while(i < j) {
            if(nums[i] + nums[j] > target) {
                j--;
            }
            else if(nums[i] + nums[j] < target) {
                i++;
            }
            else {
                // nums[i] + nums[j] == target
                while(i < j && nums[i] == nums[i+1]) {
                    i++;
                }
                while(j > i && nums[j] == nums[j-1]) {
                    j--;
                }
                res.push_back({-target,nums[i],nums[j]});
                i++; j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) {
            return {};
        }
        sort(nums.begin(),nums.end());
        // vector<vector<int>> res;
        for(int i=0; i<n-1; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            twoSum(nums,target,i+1);
        }
        return res;
    }
};