class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        // keep 2 min heaps
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        int i = 0;
        int j = n - 1;
        // push all the elements
        while (i < candidates) {
            pq1.push(costs[i]);
            i++;
        }
        while (j >= n - candidates && j >= i) {
            pq2.push(costs[j]);
            j--;
        }
        long long cost = 0;
        for (int idx = 0; idx < k; idx++) {
            int minn1 = pq1.empty() ? INT_MAX : pq1.top();
            int minn2 = pq2.empty() ? INT_MAX : pq2.top();
            if (minn1 <= minn2) {
                cost += minn1;
                pq1.pop();
                if (i <= j) {
                    pq1.push(costs[i]);
                    i++;
                }
            } else if (minn1 > minn2) {
                cost += minn2;
                pq2.pop();
                if (i <= j) {
                    pq2.push(costs[j]);
                    j--;
                }
            }
        }
        return cost;
    }
};