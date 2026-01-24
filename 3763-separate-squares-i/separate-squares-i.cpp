class Solution {
public:
    //  double funhigher(vector<vector<int>>& squares, long double k) {
    //     double area = 0.0;
    //     for (auto square : squares) {
    //          double height =
    //             max(( double)0.0,
    //                 min(( double)square[1] + square[2] - k,
    //                     ( double)square[2]));
    //         area += ( double)square[2] * height;
    //     }
    //     return area;
    // }

     double funlower(vector<vector<int>>& squares,  double k) {
         double area = 0.0; // width * height
        for (auto& square : squares) {
             double y_start = square[1];
             double side = square[2];
             double height = max((double)0.0, min(k - y_start, side));
            area += side * height;
        }
        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        // find max(y1,y2,y3,....)
         double maxy = 0.0;
         double miny = 1e18;
         double totalarea = 0.0;
        for (auto& square : squares) {
            maxy = max(maxy, ( double)square[1] + square[2]);
            miny = min(miny, ( double)square[1]);
            totalarea += ( double)square[2] * square[2];
        }

         double low = miny;
         double high = maxy;
         double k = 0.0;
         double areal = 0.0;

        while (high-low > 1e-5) {
            k = (low + high) / 2.0;
            // calculate areal and areah
            areal = funlower(squares, k); // calculates the area lower k
            // areah = funhigher(squares, k);    no need

            if (areal * 2.0 >= totalarea)
                high = k;
            else
                low = k;
        }
        return (double)k;
    }
};