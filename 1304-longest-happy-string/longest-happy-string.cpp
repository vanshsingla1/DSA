class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a > 0) pq.push({a,'a'});
        if(b > 0) pq.push({b,'b'});
        if(c > 0) pq.push({c,'c'});
        
        string res;
        while(!pq.empty()) {
            int currcount = pq.top().first;
            char c = pq.top().second;
            pq.pop();
            if(res.size() >= 2 && res[res.length()-1] == c && res[res.length()-2] == c) {
                if(pq.empty()) break;
                int nextcount = pq.top().first;
                char nextchar = pq.top().second;
                pq.pop();
                res.push_back(nextchar);
                nextcount--;
                if(nextcount > 0) pq.push({nextcount,nextchar});
            }
            else {
                currcount--;
                res.push_back(c);
            }
            if(currcount > 0) pq.push({currcount,c});
        }
        return res;
    }
};