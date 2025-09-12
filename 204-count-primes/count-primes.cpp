class Solution {
public:
    int countPrimes(int n) {
        // sieve of eratosthenes
        if (n <= 2) return 0;
        vector<int> prime(n, 1);
        prime[0] = 0;
        prime[1] = 0; // not a prime number
        int count = 0;
        for (int i = 2; (long long)i * i < n; ++i) {
            if (!prime[i]) continue;
            for (long long j = 1LL * i * i; j < n; j += i) {
                prime[(int)j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            if (prime[i] == 1) {
                count++;
            }
        }
        return count;
    }
};
