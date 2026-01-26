class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> neg(n,false); // stores negative indices
        vector<int> pos; // stores positive indices
        for(int i=0; i<n; i++) {
            // mark the index -1, where nums[i] < 0
            if(nums[i] < 0) neg[i] = true;
            else {
                pos.push_back(i);
            }
        }
        int size = pos.size();
        if(size == 0) return nums;
        vector<int> temp(size);
        // left rotation only for pos vector
        k %= size;
        for(int i=0; i<size; i++) {
            int idx = (i+k) % size;
            temp[i] = nums[pos[idx]];
        }
        int j = 0;
        for(int i=0; i<n; i++) {
            if (neg[i]) continue;
            else nums[i] = temp[j++];
        }
        return nums;
    }
};