class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>v(n);
        for(int i=0; i<n; i++)
        {
            v[i].push_back(1);
            for(int j=0; j<i-1; j++)
            {
                v[i].push_back(v[i-1][j]+v[i-1][j+1]);
            }
            if(i>0)
            v[i].push_back(1);
        }
        return v;
    }
};