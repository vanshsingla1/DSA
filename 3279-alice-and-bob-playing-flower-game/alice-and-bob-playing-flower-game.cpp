class Solution {
public:
    long long flowerGame(int n, int m) {
        // i want that (i+j)%2 == 1
        // for this one number should be odd and other should be even
        // so all possile pairs are (odd i * even j) + (even i * odd j)
        long long oddi = 0;
        long long eveni = 0;
        long long oddj = 0;
        long long evenj = 0;
        for(int i=1; i<=n; i++) {
            if(i%2 == 1) {
                oddi++;
            }
            else {
                eveni++;
            }
        }
        for(int j=1; j<=m; j++) {
            if(j%2 == 1) {
                oddj++;
            }
            else {
                evenj++;
            }
        }
        return (oddi * evenj + oddj * eveni);
    }
};