class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (int pile : piles) {
            pq.push(pile);
        }
        while (k--) {
            int curr = pq.top();
            pq.pop();

            int remaining = curr - curr / 2; 
            pq.push(remaining);
        }
        int res = 0;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};
