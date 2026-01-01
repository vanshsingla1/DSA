class Solution {
public:
    bool isPalindrome(string s,int i,int j) {
        if(i > j)
        return true;
        if(s[i] != s[j])
        return false;
        return isPalindrome(s,i+1,j-1);
    }
    void fun(string s,vector<vector<string>> &res,vector<string> &temp,int i) {
        if(i >= s.size()) {
            res.push_back(temp);
            return;
        }
        for(int j=i; j<s.size(); j++) {
            if(isPalindrome(s,i,j)) {
                temp.push_back(s.substr(i,j-i+1));
                fun(s,res,temp,j+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s.empty()) {
            return res;
        }
        vector<string> temp;
        fun(s,res,temp,0);
        return res;
    }
};