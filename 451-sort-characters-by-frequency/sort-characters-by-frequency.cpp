class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;
        for(char c : s) {
            mp[c]++;
        }
        for(auto it : mp) {
            pq.push({it.second,it.first});
        }
        // now pop elements from pq and push into string
        string res;
        while(!pq.empty()) {
            int count = pq.top().first;
            while(count != 0) {
                res += pq.top().second;
                count--;
            }
            pq.pop();
        }
        return res;
    }
};