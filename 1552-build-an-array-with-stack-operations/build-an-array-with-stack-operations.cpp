class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int stream = 1;
        int i = 0;
        vector<string> res;
        while(i < target.size() && stream <= n) {
            res.push_back("Push");
            if(stream == target[i]) {
                i++;
            }
            else {
                res.push_back("Pop");
            }
            stream++;
        }
        return res;
    }
};