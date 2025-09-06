class Solution {
public:
    static bool comp(vector<int> &p1, vector<int> &p2) {
        if(p1[0] == p2[0]) {
            return p1[1] > p2[1];
        }
        return p1[0] < p2[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        // brute force
        int n = points.size();
        int count = 0;
        sort(begin(points),end(points),comp);
        for(int i=0; i<n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int maxy = INT_MIN;
            for(int j=i+1; j<n; j++) {
                
                int x2 = points[j][0];
                int y2 = points[j][1];
                // check the condition that x2 >= x1 && y2 <= y1
                if(y2 > y1) {
                    continue;
                }
                if(y2 > maxy) {
                    count++;
                    maxy = y2;
                }
            }
        }
        return count;
    }
};