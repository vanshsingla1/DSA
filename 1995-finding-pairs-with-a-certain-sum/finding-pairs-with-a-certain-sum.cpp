class FindSumPairs {
public:
    vector<int> n1;
    vector<int> n2;
    unordered_map<int,int> mp1;
    unordered_map<int,int> mp2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2; //intialized
        for(int n : n1) {
            mp1[n]++;
        }
        for(int n : n2) {
            mp2[n]++;
        }
    }
    
    void add(int index, int val) {
        //add in nums2
        mp2[n2[index]]--;
        n2[index] += val;
        mp2[n2[index]]++;
    }
    
    int count(int tot) {
        //count i,j s/t nums1[i]+nums2[j] == value
        int res = 0;
        for(auto it : mp1) {
            int num = it.first;
            int cnt = it.second;
            res += cnt * mp2[tot-num];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */