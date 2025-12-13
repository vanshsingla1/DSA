class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();
        
        // Buckets for each category in the specified order
        // 0 = electronics, 1 = grocery, 2 = pharmacy, 3 = restaurant
        vector<vector<string>> buckets(4);
        
        for (int i = 0; i < n; i++) {
            // 1) code non‑empty & only alnum/_  
            const string &s = code[i];
            if (s.empty()) continue;
            bool ok = true;
            for (char ch : s) {
                if (!(isalnum(ch) || ch == '_')) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            
            // 2) must be active
            if (!isActive[i]) continue;
            
            // 3) assign to the right bucket
            const string &b = businessLine[i];
            if      (b == "electronics") buckets[0].push_back(s);
            else if (b == "grocery")     buckets[1].push_back(s);
            else if (b == "pharmacy")    buckets[2].push_back(s);
            else if (b == "restaurant")  buckets[3].push_back(s);
            else continue;  // skip any other categories
        }
        
        // 4) sort each bucket lexicographically
        for (auto &vec : buckets) {
            sort(vec.begin(), vec.end());
        }
        
        // 5) concatenate in the specified order
        vector<string> res;
        for (auto &vec : buckets) {
            res.insert(res.end(), vec.begin(), vec.end());
        }
        return res;
    }
};
