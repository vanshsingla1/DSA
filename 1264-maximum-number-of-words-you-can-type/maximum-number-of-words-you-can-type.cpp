class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // store in vector for o(N) time complexity
        vector<int> broken(26,0);
        for(char c : brokenLetters) {
            broken[c-'a'] = 1;
        }
        int count = 0;
        bool flag = true;
        for(int i=0; i<=text.size(); i++) {
            if(i < text.size() && text[i] != ' ') {
                if(broken[text[i]-'a']) {
                    flag = false;
                }
            }
            else {
                if(flag) {
                    count++;
                }
                flag = true;
            }
        }
        return count;
    }
};