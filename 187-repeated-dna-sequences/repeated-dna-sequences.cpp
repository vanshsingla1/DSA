class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int k = 10; // exactly k length
        vector<string> res;
        unordered_map<string, int> mp;
        string path = "";
        int n = s.length();
        if (n == 0)
            return res;
        if (n < k)
            return res;
        int left = 0;
        int right = 0;
        int count = 0;
        while (left <= n - k) {
            while (count < k) {
                path += s[right];
                right++;
                count++;
            }
            mp[path]++;
            path = "";
            left++;
            right = left;
            count = 0;
        }
        for (auto it : mp) {
            if (it.second > 1) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};