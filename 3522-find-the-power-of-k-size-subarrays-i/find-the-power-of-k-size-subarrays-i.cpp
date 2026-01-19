class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        deque<int> deq;
        vector<int> res;
        int n = nums.size();
        bool flag = false;
        for(int i=0; i<n; i++) {
            // remove elements which are not in range
            while(!deq.empty() && deq.front() <= i-k) {
                deq.pop_front();
            }
            // monotonically increasing sequence
            while(!deq.empty() && nums[deq.back()] > nums[i]) { // checking sorted or not 
                // push -1
                flag = true;
                deq.pop_back();
            }
            if(!deq.empty()) {
                if(nums[i]-nums[deq.back()] != 1) { // handling gap
                deq.pop_back();
                flag = true;
                }
            }
            deq.push_back(i);
            if(i >= k-1) {
                if(flag) {
                    res.push_back(-1);
                    flag = false;
                }
                else {
                    if(deq.size() == k) {
                        res.push_back(nums[deq.back()]);
                    }
                    else
                    res.push_back(-1);
                }
            }
        }
        return res;
    }
};