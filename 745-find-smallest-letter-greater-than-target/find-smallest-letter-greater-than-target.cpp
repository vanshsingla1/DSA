class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // letters -> non-decreasing order
        // atleast two different characters in letters
        // only single character target , find the smallest character in letters that is lexicographically greater than target
        int n = letters.size();
        priority_queue<char,vector<char>,greater<char>> pq;
        for(int i=0; i<n; i++) {
            if(letters[i] > target) pq.push(letters[i]);
        }
        if(!pq.empty()) return pq.top();
        else return letters[0];
    }
};