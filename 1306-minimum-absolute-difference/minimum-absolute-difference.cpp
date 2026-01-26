class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        int minDif = INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=0; i<n-1; i++) {
            minDif = min(minDif, arr[i+1]-arr[i]);
        }
        vector<vector<int>> res;
        for(int i=0; i<n-1; i++) {
            vector<int> temp;
            if(arr[i+1]-arr[i] == minDif) {
                temp.push_back(arr[i]);
                temp.push_back(arr[i+1]);
            }
            if(!temp.empty())
            res.push_back(temp);
        }
        return res;
    }
};