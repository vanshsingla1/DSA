class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            long long v = nums[i];
            if (v < 0) v = -v;
            a[i] = v;
        }

        sort(a.begin(), a.end());

        long long minus = 0;
        long long add = 0;
        for (int i = 0; i < n; ++i) {
            long long sq = a[i] * a[i];
            if (i < n/2) 
            minus += sq;
            else add += sq;
        }
        return add - minus;
    }
};
