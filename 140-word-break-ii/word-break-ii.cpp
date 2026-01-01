class Solution {
public:
    void fun(string s,vector<string> &dict,vector<string> &res,string temp,vector<string> &vec) {
        if(s == temp) {
            string str = "";
            for(auto it : vec) {
                str += it;
                str += " ";
            }
            str.pop_back();
            res.push_back(str);
            return;
        }
        for (int i = 0; i < dict.size(); i++) {
            if (temp.length() + dict[i].size() <= s.length()) {
                if (s.substr(temp.length(), dict[i].size()) != dict[i]) {
                    continue;
                }
                temp += dict[i];
                vec.push_back(dict[i]);
                fun(s, dict,res, temp, vec);
                temp.erase(temp.size() - dict[i].size());
                vec.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        if(s.empty()) {
            return res;
        }
        string temp;
        vector<string> vec;
        fun(s,wordDict,res,temp,vec);
        return res;
    }
};