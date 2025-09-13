class Solution {
public:
    string sortVowels(string s) {
        int n = s.length();
        //  vowels -> 'a', 'e', 'i', 'o', and 'u'
        vector<char> vowels;
        for(int i=0; i<n; i++) {
            char c = s[i];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                vowels.push_back(c);
            }
        }
        sort(vowels.begin(),vowels.end());
        int m = vowels.size();
        int j=0;
        for(int i=0; i<n; i++) {
            char c = s[i];
            if(j < m) {
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                    s[i] = vowels[j];
                    j++;
                }
            }
        }
        return s;
    }
};