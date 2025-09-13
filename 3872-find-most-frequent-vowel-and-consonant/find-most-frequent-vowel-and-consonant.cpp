class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.length();
        unordered_map<char,int> vowel;
        unordered_map<char,int> consonant;
        for(int i=0; i<n; i++) {
            char c = s[i];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowel[c]++;
            }
            else {
                consonant[c]++;
            }
        }
        int max1 = 0;
        int max2 = 0;
        for(auto it : vowel) {
            max1 = max(max1,it.second);
        }
        for(auto it : consonant) {
            max2 = max(max2,it.second);
        }
        return (max1+max2);
    }
};