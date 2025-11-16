class Solution {
public:
    const int MOD = 1e9+7;

    int numSub(string s) {
        int n = s.length();
        long long res = 0;

        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                i++;
                continue;
            }

            long long len = 0;
            while (i < n && s[i] == '1') {
                len++;
                i++;
            }

            long long add = (len * (len + 1) / 2) % MOD;
            res = (res + add) % MOD;
        }

        return (int)res;
    }
};
