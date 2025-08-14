class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        int count = 1;
        char ch = '0' - 1;
        for (int i = 1; i < n; i++) {
            if (num[i] == num[i - 1]) {
                count++;
                if (count == 3) {
                    ch = max(ch, num[i]);
                }
            } else {
                count = 1;
            }
        }
        if(ch < '0')
        return "";
        else 
        return string(3,ch);
    }
};