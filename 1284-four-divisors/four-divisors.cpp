class Solution {
public:
    int factors(int num) {
        int count = 0;
        int sum = 0;
        for(int i=1; i <= num; i++) {
            if(count > 4) {
                return 0;
            }
            if(num%i == 0) {
                sum += i;
                count++;
            }
        }
        return sum;
    }
    int sumFourDivisors(vector<int>& nums) {
        // Rules :
        // 1 no. should not be a prime no
        // 2 no. should not be a perfect sq
        // then calculate factors and check 
        int maxx = *max_element(nums.begin(),nums.end());
        vector<bool> prime(maxx+1,true);
        for(int i=2; i*i <= maxx; i++) {
            if(prime[i] == true) {
                for(int j = i*i; j<=maxx; j += i) {
                    prime[j] = false;
                }
            }
        }
        // now traverse for the nums
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            if(prime[nums[i]]) {
                continue;
            }
            else if((int)sqrt(nums[i]) * (int)sqrt(nums[i]) == nums[i]) {
                continue;
            }
            else {
                // check the factors
                count += factors(nums[i]);
            }
        }
        return count;
    }
};