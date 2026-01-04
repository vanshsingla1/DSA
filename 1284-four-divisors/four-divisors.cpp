class Solution {
public:
    bool isPrime(int x) {
        if (x < 2)
            return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            int r = round(cbrt(num));
            if (r * r * r == num && isPrime(r)) {
                sum += 1 + r + r * r + num;
                continue;
            }
            for (int d = 2; d * d <= num; d++) {
                if (num % d == 0) {
                    int other = num / d;
                    if (d != other && isPrime(d) && isPrime(other)) {
                        sum += 1 + d + other + num;
                    }
                    break;
                }
            }
        }
        return sum;
    }
};