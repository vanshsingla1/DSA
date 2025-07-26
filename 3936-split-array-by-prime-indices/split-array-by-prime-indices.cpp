class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long>prime(n+1,1);
        prime[0] = 0; // not a prime number
        prime[1] = 0; // not a prime number
        for(long long i=2; i<n; i++) {
            if(!prime[i])
            continue;
            for(long long j=i*i; j<n; j+=i) {
                prime[j] = 0;
            }
        }
        long long psum = 0; // prime sum
        long long nsum = 0; // not prime sum
        for(int i=0; i<n; i++) {
            if(prime[i]) {
                //prime
                psum += nums[i];
            }
            else
            nsum += nums[i];
        }
        return abs(psum-nsum);
    }
};