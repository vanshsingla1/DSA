class Solution {
public:
    void fun(double l, double h, vector<vector<int>>& squares, double target, double& result){
        while(h-l > 1e-5){
            double mid = l + (h-l)/2.0;
            double sum = 0.0;
            for(const auto&  vec : squares){
                int x1 = vec[0], y1 = vec[1], side = vec[2];
                if(y1 >= mid) continue;
                double y2 = min((double)(y1+side), mid);
                sum += side * (y2-y1);
            }

            if(sum >= target){
                result = mid;
                h = mid;
            } else{
                l = mid;
            }
        }
    }
    double separateSquares(vector<vector<int>>& squares) {
        double totalSum = 0.0;
        double h=0.0;
        for(const auto& vec : squares){
            totalSum += ((double)vec[2]*vec[2]);
            h =  max(h, (double)vec[1]+vec[2]);
        }
        double target = totalSum/2.0;
        double result=h; 
        fun(0.0, h, squares, target, result);
        return result;
    }
};