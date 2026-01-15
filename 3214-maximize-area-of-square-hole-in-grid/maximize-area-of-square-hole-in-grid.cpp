class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // description not good
        // to increase width, remove consecutive bars same goes with height
        //  res = min(width, height)
        // width = no. of consecutive bars removed + 1
        int width = 1;
        int currwidth = 1;
        int height = 1;
        int currheight = 1;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        for(int i=1; i<hBars.size(); i++) {
            if(hBars[i] == hBars[i-1]+1) {
                currwidth++;
            }
            else {
                currwidth = 1;
            }
            width = max(width, currwidth);
        }
        for(int i=1; i<vBars.size(); i++) {
            if(vBars[i] == vBars[i-1]+1) {
                currheight++;
            }
            else {
                currheight = 1;
            }
            height = max(height, currheight);
        }
        int side = min(height,width)+1;
        return (side) * (side);
    }
};