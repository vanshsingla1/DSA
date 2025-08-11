class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // use bottom up -> tle in recursion + memo also
        int n = arr.size();
        unordered_map<int,int> mp;
        int res = 1;
        for(int i=0; i<n; i++) {
            if(mp.find(arr[i]-difference) != mp.end()) {
                mp[arr[i]] = mp[arr[i]-difference] + 1;
            }
            else {
                mp[arr[i]] = 1;
            }
            res = max(res,mp[arr[i]]);
        }
        return res;
    }
};