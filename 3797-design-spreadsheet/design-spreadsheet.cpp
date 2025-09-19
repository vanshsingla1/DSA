class Spreadsheet {
public:
    unordered_map<string,int> mp; 
    Spreadsheet(int rows) {
        // intialization
       
    }
    
    void setCell(string cell, int value) {
        mp[cell] = value;
    }
    
    void resetCell(string cell) {
        mp[cell] = 0;
    }
    
    int getValue(string s) {
        s = s.substr(1);
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '+') {
                string s1 = s.substr(0,i);
                string s2 = s.substr(i+1);
                int left = s1[0] >= 'A' && s1[0] <= 'Z' ? mp[s1] : stoi(s1);
                int right = s2[0] >= 'A' && s2[0] <= 'Z' ? mp[s2] : stoi(s2);
                return left + right;
            }
        }
        return 0;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */