class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // weights x and y with x <= y
        // If x == y, both stones are destroyed, and
        // If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
        priority_queue<int> pq;
        for(auto stone : stones) {
            pq.push(stone);
        }
        while(pq.size() > 1) {
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();
            if(y != x)  pq.push(y-x);
            else pq.push(0);
        }
        return pq.top();
    }
};