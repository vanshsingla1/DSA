class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        vector<pair<vector<int>,vector<int>>> rect;
        for(int i=0; i<bottomLeft.size(); i++) {
            rect.push_back({bottomLeft[i],topRight[i]});
        }
        // sort acc to bottomLeft
        sort(rect.begin(),rect.end(), [&] (auto &a, auto &b) {
            if(a.first[0] == b.first[0]) 
            return a.first[1] < b.first[1];
            return a.first[0] < b.first[0];
        });
        for(int i = 0; i < rect.size(); i++) {
            bottomLeft[i] = rect[i].first;
            topRight[i]  = rect[i].second;
        }
        int currheight = 0;
        int currwidth = 0;
        long long side = 0;
        int currside = 0;
        // now iterate and find the common region
        for(int i=0; i<bottomLeft.size(); i++) {
            for(int j=i+1; j<bottomLeft.size(); j++) {
                int currwidth = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]);
                int currheight = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]);
                if(currwidth > 0 && currheight > 0) {
                    currside = min(currwidth, currheight);
                    side = max(side, 1LL * currside);
                    currside = 0;
                }
            }
        }
        // if(side == 0) {
        //     return -1;
        // }
        return side*side;
    }
};