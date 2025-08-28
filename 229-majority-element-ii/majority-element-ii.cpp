class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Nice qn
        // for n/3, we can have upto 2 majority elemens
        int n = nums.size();
        vector<int> res;
        int maj1 = -1;
        int maj2 = -1;
        int count1 = 0;
        int count2 = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == maj1) {
                count1++;
            }
            else if(nums[i] == maj2) {
                count2++;
            }
            else if(count1 == 0) {
                count1 = 1;
                maj1 = nums[i];
            }
            else if(count2 == 0) {
                count2 = 1;
                maj2 = nums[i];
            }
            else {
                count1--;
                count2--;
            }
        }
        // verification , are the elements are in actually majority elements
        int res1 = 0;
        int res2 = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == maj1) {
                res1++;
            }
            else if(nums[i] == maj2) {
                res2++;
            }
        }
        if(res1 > n/3) {
            res.push_back(maj1);
        }
        if(res2 > n/3) {
            res.push_back(maj2);
        }
        return res;
    }
};