class Solution {
public:
    void fun(string digits, unordered_map<int,vector<char>> &adj,vector<string> &res,int i,string path) {
        if(i == digits.length()) {
            if (!path.empty())
            res.push_back(path);
            return;
        }
        for(auto it : adj[digits[i]-'0']) {
            path += it;
            fun(digits,adj,res,i+1,path);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        unordered_map<int,vector<char>> adj;
        adj[2] = {'a','b','c'};
        adj[3] = {'d','e','f'};
        adj[4] = {'g','h','i'};
        adj[5] = {'j','k','l'};
        adj[6] = {'m','n','o'};
        adj[7] = {'p','q','r','s'};
        adj[8] = {'t','u','v'};
        adj[9] = {'w','x','y','z'};
        vector<string> res;
        string path;
        if (digits.empty()) 
        return res;
        fun(digits,adj,res,0,path);
        return res;
    }
};