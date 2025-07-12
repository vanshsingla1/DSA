class Solution {
public:
    bool isPredecessor(string a, string b) {
        int m = a.length();
        int n = b.length();
        if(n-m != 1)
        return false;
        int i=0;
        int j=0;
        while(i<m && j<n) {
            if(a[i] == b[j]) {
                i++;
                j++;
            }
            else
            j++;
        }
        return i == m;
    }
    static bool comp(string &a, string &b) {
        return a.length() < b.length();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n,1);
        int res = 1;
        //sort on the basis of length
        sort(words.begin(),words.end(),comp);
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if((words[i].length() > words[j].length()) && isPredecessor(words[j],words[i])) {
                    dp[i] = max(dp[i],dp[j]+1);
                    res = max(res,dp[i]);
                }
            }
        }
        return res;
    }
};