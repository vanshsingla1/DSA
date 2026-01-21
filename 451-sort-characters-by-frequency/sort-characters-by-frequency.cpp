class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0; i<s.length(); i++)
        {
            mp[s[i]]++;
        }
        vector<pair<int,char>>v;
        for(auto &it:mp)
        {
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(), [](pair<int,char>& a,pair<int,char>& b)
        {
            return a.first>b.first;
        });
        string str;
        for(auto &it: v)
        {
           str.append(it.first,it.second);// Appended frequency times the character
        }
        return str;
    }
};