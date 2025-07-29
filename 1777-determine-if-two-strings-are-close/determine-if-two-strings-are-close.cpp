class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length())
        return false;
        int n = word1.length();
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        for(int i=0; i<n; i++) {
            v1[word1[i]-'a']++;
            v2[word2[i]-'a']++;
        }
        for(int i=0; i<26; i++) {
            if((v1[i] == 0) != (v2[i] == 0))
            return false;
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return v1 == v2;
    }
};