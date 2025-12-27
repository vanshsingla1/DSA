class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        // n,m
        sort(capacity.rbegin(),capacity.rend());
        int sum = 0;
        for(int i=0; i<apple.size(); i++) {
            sum += apple[i];
        }
        int count = 0;
        int currsum = 0;
        for(int i=0; i<capacity.size(); i++) {
            if(currsum >= sum) {
                break;
            }
            count++;
            currsum += capacity[i];
        }
        return count;
    }
};