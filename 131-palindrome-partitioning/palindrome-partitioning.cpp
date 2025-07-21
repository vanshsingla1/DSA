class Solution {
public:
    bool isPalindrome(string s,int i,int j) {
        if(i > j)
        return true;
        if(s[i] != s[j])
        return false;
        return isPalindrome(s,i+1,j-1);
    }
    void fun(string s,vector<string> path,vector<vector<string>> &res,int idx) {
        if(idx >= s.size()) {
            res.push_back(path);
            return;
        }
        for(int i=idx; i<s.size(); i++) {
            if(isPalindrome(s,idx,i)) {
                path.push_back(s.substr(idx,i-idx+1));
                fun(s,path,res,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> res;
        vector<string> path;
        fun(s,path,res,0); 
        return res;
    }
};