class Solution {
public:
    string longestPalindrome(string s) {
        // bottom up - blueprint
        int n = s.length();
        int maxlen = 0;
        string res;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                // single length substrings
                if (i == j) {
                    dp[i][j] = true;
                    if (1 > maxlen) {
                        maxlen = 1;
                        res = s.substr(i, 1);
                    }
                }
                // 2 lenth string
                else if (j == i + 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = true;
                        if (2 > maxlen) {
                            maxlen = 2;
                            res = s.substr(i, 2);
                        }
                    } else {
                        dp[i][j] = false;
                    }
                }
                // string > 2 length
                else {
                    if (s[i] == s[j] && dp[i+1][j-1]) {
                        dp[i][j] = true;
                        if (len > maxlen) {
                            maxlen = len;
                            res = s.substr(i, len);
                        }
                    } else
                        dp[i][j] = false;
                }
            }
        }
        return res;
    }
};