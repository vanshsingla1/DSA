class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<vector<int>>res;
        for(int i=0; i<n; i++)
        {
           if(res.empty())
           res.push_back(arr[i]);
           else if(arr[i][0]>res.back()[1])
           {
            res.push_back(arr[i]);
           }
           else
           res.back()[1] = max(res.back()[1],arr[i][1]);
        }
        return res;
    }
};