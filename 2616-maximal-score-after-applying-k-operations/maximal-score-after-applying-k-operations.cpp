class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq; // max heap
        for(auto num : nums) {
            pq.push(num);
        }
        int count = 0;
        long long score = 0;
        while(count < k) {
            int val = pq.top();
            pq.pop();
            score += val;
            pq.push(ceil(val/3.0));
            count++;
        }
        return score;
    }
};