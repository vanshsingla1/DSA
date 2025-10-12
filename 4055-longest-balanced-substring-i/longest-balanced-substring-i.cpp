class Solution {
public:
    bool fun(unordered_map<char,int> &mp) {
        int minn = INT_MAX;
        int maxx = INT_MIN;
        for(auto it : mp) {
            minn = min(minn,it.second);
            maxx = max(maxx,it.second);
        }
        return (minn == maxx);
    }
    int longestBalanced(string s) {
        int n = s.size();
        int res = 0;
        for(int i=0; i<n; i++) {
            unordered_map<char,int> mp;
            for(int j=i; j<n; j++) {
                mp[s[j]]++;
                if(fun(mp)) {
                    int len = j-i+1;
                    res = max(res,len);
                }
            }
        }
        return res;
    }
};