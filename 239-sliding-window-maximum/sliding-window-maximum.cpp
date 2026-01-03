class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;
        vector<int> res;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            // remove the elements which are not in window of size k
            while(!deq.empty() && deq.front() <= i-k) {
                deq.pop_front();
            }
            // now monotonically sequence
            while(!deq.empty() && nums[deq.back()] < nums[i]) {
                deq.pop_back();
            }
            deq.push_back(i);
            if(i >= k-1) {
                res.push_back(nums[deq.front()]);
            }
        }
        return res;
    }
};