class Solution {
public:
    int fun(string s1, string s2,int i,int j,vector<vector<int>> &dp) {
        if(i == s1.length())
        return s2.length()-j;//insert
        else if(j == s2.length())
        return s1.length()-i;//delete

        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) {
            return dp[i][j] = fun(s1,s2,i+1,j+1,dp); // no oepration is performed
        }
        else {
            return dp[i][j] = 1+min({fun(s1,s2,i,j+1,dp),fun(s1,s2,i+1,j,dp),fun(s1,s2,i+1,j+1,dp)});
        }
        return -1;
    }
    int minDistance(string word1, string word2) {
        if(word2.length() == 0)
        return word1.length();
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        return fun(word1,word2,0,0,dp);
    }
};