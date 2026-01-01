class Solution {
public:
    void fun(vector<int> &digits,vector<int> &res,int i,int carry) {
        if(i < 0) {
            return;
        }
        if(carry == 0) {
            res.push_back(digits[i]);
        }
        else {
            if(digits[i]+1 == 10 && i == 0) {
                res.push_back(0);
                res.push_back(1);
                carry = 0;
            }
            else if(digits[i]+1 == 10) {
                res.push_back(0);
                carry = 1;
            }
            else {
                res.push_back(digits[i]+1);
                carry = 0;
            }
            
        }
        fun(digits,res,i-1,carry);
    }
    vector<int> plusOne(vector<int>& digits) {
        // stoi wouldn't work here if integers are large
        // out of range error
        // recursion 
        vector<int> res;
        if(digits.empty()) {
            return res;
        }
        int n = digits.size();
        fun(digits,res,n-1,1);
        reverse(res.begin(),res.end());
        return res;
    }
};