class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.length();
        // calculate prefix and suffix upto each element
        if (n < 2) return false;
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0] = s[0]-'a'+1;
        suffix[n-1] = s[n-1];
        for(int i=1; i<n; i++) {
            // prefix calculation
            prefix[i] = s[i]-'a'+1 + prefix[i-1];
        }
        for(int i=n-2; i>=0; i--) {
            // suffix calculation
            suffix[i] = s[i]-'a'+1 + suffix[i+1];
        }
        for(int i=0; i<n; i++) {
            if(prefix[i] == suffix[i]-s[i]) {
                return true;
            }
        }
        return false;
    }
};