class Solution {
public:
    int shortestSubarray(vector<int>& nums, int target) {
        // only difference b/w leetcode 862 and leetcode 209 is negative numbers
        // in this qn negative numbers are also present
        int n = nums.size();
        vector<long long> prefix(n+1,0);
        for(int i=1; i<=n; i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        deque<int> deq; // as we need to pop from front
        int minn = INT_MAX;
        for(int i=0; i<=n; i++) {
            //check if prefix sum is >= target , start removing from front
            while(!deq.empty() && prefix[deq.back()] > prefix[i]) {
                deq.pop_back();
            }
            while(!deq.empty() && prefix[i]-prefix[deq.front()] >= target) {
                minn = min(minn,i-deq.front());
                deq.pop_front();
            }
            deq.push_back(i);
        }
        if(minn == INT_MAX) return -1;
        else return minn;
    }
};