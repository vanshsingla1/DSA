class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.length() < k) {
            // size is less than k
            //inc the size of word, and appends the characters to the last
            string temp = word;
            for(int i=0; i<word.length(); i++) {
                char c;
                if(word[i] == 'z')
                c = 'a';
                else
                c = word[i]+1;

                temp += c;
            }
            word = temp;
        }
        return word[k-1];
    }
};