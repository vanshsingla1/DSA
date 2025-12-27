class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // n children's standing in a queue
        // i have to select k children from these n childrens in k turns
        // in each turn select only one child
        // happiness value of each child which is not selected till now decreases by 1
        // return maximum sum of happiness values of selected childrens 
        sort(happiness.rbegin(),happiness.rend());
        int n = happiness.size();
        int count = 0;
        long long happ = 0;
        int minus = 0;
        int i = 0;
        while(count < k && i < n) {
            if(happiness[i] - minus >= 0) {
                happ += happiness[i] - minus;
            }
            count++;
            minus++;
            i++;
        }
        return happ; 
    }
};