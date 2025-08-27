class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        // very very tough, do again
        int m = matrix.size();
        int n = matrix[0].size();
        // har ek row da preifx sum find kro
        for(int i=0; i<m; i++) {
            for(int j=1; j<n; j++) {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        // now (leetcode 560) variation lgao
        int count = 0;
        for(int col = 0; col<n; col++) {
            for(int j = col; j<n; j++) {
                unordered_map<int,int> mp;
                mp.insert({0,1});
                int sum = 0;
                for(int i=0; i<m; i++) {
                    sum += matrix[i][j] -  (col > 0 ? matrix[i][col-1] : 0);
                    if(mp.find(sum-target) != mp.end()) {
                        count += mp[sum-target];
                    }
                    mp[sum]++;
                }
            }
        }
        return count;
    }
};