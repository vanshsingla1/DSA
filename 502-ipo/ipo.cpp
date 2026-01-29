class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // design the best way to maximize its total capital after finishing at most k distinct projects.
        // try by greedy + max heap
        // sort in ascending order acc to capital and profit and keep an eye on k
        int n = profits.size();
        vector<pair<int,int>> p;
        for(int i=0; i<n; i++) {
            p.push_back({capital[i],profits[i]});
        }
        sort(p.begin(),p.end());
        for(int i=0; i<n; i++) {
            profits[i] = p[i].second;
            capital[i] = p[i].first;
        }
        // now count for k operations
        int cnt = 0;
        int i = 0;
        priority_queue<int> pq;
        while(cnt < k) {
            while(w >= capital[i] && i < n) {
                pq.push(profits[i]);
                i++;
            }
            if(pq.empty()) break;
            w += pq.top(); pq.pop();
            cnt++;
        }
        return w;
    }
};