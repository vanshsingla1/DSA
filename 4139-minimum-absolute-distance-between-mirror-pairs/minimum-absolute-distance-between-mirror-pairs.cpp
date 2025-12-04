class Solution {
public:
    int reverseInt(int n) {
        int r = 0;
        while (n > 0) {
            r = r * 10 + (n % 10);
            n /= 10;
        }
        return r;
    }

    // remove only leading zeros (if any)
    int removezeros(int num) {
        string s = to_string(num);
        int i = 0;
        while (i < s.length() && s[i] == '0') i++;

        if (i == s.length()) return 0;
        return stoi(s.substr(i));
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int mindiff = INT_MAX;

        // Step 1: clean numbers
        for (int i = 0; i < n; i++) {
            nums[i] = removezeros(nums[i]);
        }

        unordered_map<int, int> mp;  
        for (int i = n - 1; i >= 0; i--) {

            int rev = reverseInt(nums[i]);

            if (mp.count(rev)) {
                mindiff = min(mindiff, mp[rev] - i);
            }
            mp[nums[i]] = i;
        }

        return (mindiff == INT_MAX ? -1 : mindiff);
    }
};
