class Solution {
public:
    int possibleStringCount(string word) {
        //type a specific string on computer
        // multiple times a characer is typed
        // she may have done this at most once
        //return the number of strings that alice has assumed to be the output
        if(!word.size())
        return 0;
        int count = 1;//word is always a valid string which is printed on screen
        for(int i = 0; i<word.size()-1; i++) {
            if(word[i] == word[i+1])
            count++;
        }
        return count;
    }
};